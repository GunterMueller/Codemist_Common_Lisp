
;;;; Printing functions

;;;
;;; This code may be used and modified, and redistributed in binary
;;; or source form, subject to the "CCL Public License", which should
;;; accompany it. This license is a variant on the BSD license, and thus
;;; permits use of code derived from this in either open and commercial
;;; projects: but it does require that updates to this code be made
;;; available back to the originators of the package. Note that as with
;;; any BSD-style licenses the terms here are not compatible with the GNU
;;; public license, and so GPL code should not be combined with the material
;;; here in any way.
;;;
;;; Parts of the Lisp code here are or have been derived from the Spice
;;; Common Lisp code-base, that was placed in the Public Domain. Thus
;;; public domain versions of some of these files may also be available.
;;; The versions here will have been selected, customised and arranged
;;; for use with CCL. "Thank you very much, Spice People".
;;;

(defvar *print-escape* t "prin1/princ control flag")

(defvar *print-pretty* nil "prettyprinter control flag")

(defvar *print-circle* nil "printer control re re-entrant structures")

(defvar *print-base* 10 "base for output of numbers")

(defvar *print-radix* nil
   "flag that can make radix of printed numbers explicit")

(defvar *print-case* nil
   "case-fold option for output. See manual for values to give this variable")

(defvar *print-gensym* t "Control over display of gensyms")

(defvar *print-level* nil "recursion depth limit for printing")

(defvar *print-length* nil "list length limit in printing")

(defvar *print-array* t "Display array contents if non-nil")



;;; Macros used by this package

(defmacro write-literal-string (s)
   ;; Used for printing fixed strings. Expands into a call for
   ;; long strings or several ~tyo calls for short messages
   (if (> (length s) 3)
       `(write-string-subroutine ,s ,(length s))
       (let ((w nil))
          (dotimes (i (length s))
             (push `(~tyo ,(char s i)) w))
          (cons 'progn (nreverse w)))))

(defmacro sub-write-decimal (object)
   ;; Warning - this macro needs a side-effect free argument
   `(progn
      (when (< ,object 0) (~tyo #\-) (setf ,object (- 0 ,object)))
      (sub-write-based ,object 10)
      (if *print-radix* (~tyo #\.))))

(defmacro char-dodgyp (c)
   ;; This is used to see when escape characters are needed inside || marks
   `(or (char= c #\\) (char= c #\|)))

(defmacro add-item (object &aux (g (gensym)))
   ;; yields true if object has been seen before, nil if this was first time
   ;; N.B. memq, atsoc are Codemist Lisp things, to be removed later
   `(if (memq ,object print-objects)
        (let ((,g (atsoc ,object print-index)))
             (unless ,g
                (push (cons ,object 0) print-index))
             t)
        (progn
           (push ,object print-objects)
           nil)))

(defmacro tail-printed-already (object)
   `(atsoc ,object print-index))

(defmacro printed-already (object &aux (g (gensym)))
   `(and *print-circle*
      (let ((,g (atsoc ,object print-index)))
         (cond
            ((null ,g) nil)
            ((= (cdr ,g) 0) (~tyo #\#)
                            (sub-write-based
                               (setf (cdr ,g) (incf print-objects))
                               10)
                            (~tyo #\=)
                            nil)
            (t (~tyo #\#)
               (sub-write-based (cdr ,g) 10)
               (~tyo #\#)
               t)))))



(proclaim '(special print-objects print-index))

;;;; Prettyprint package

;;;
;;; This package prints list structures in an indented format that
;;; is intended to make them legible. There are a number of special
;;; cases recognized, but in general the intent of the algorithm
;;; is that given a list (R1 R2 R3 ...), PPRINT checks if
;;; the list will fit directly on the current line and if so
;;; prints it as:
;;;        (R1 R2 R3 ...)
;;; if not it prints it as:
;;;        (R1
;;;           R2
;;;           R3
;;;           ... )
;;; where each sublist is similarly treated.
;;;
;;;                       A. C. Norman.  July 1978
;;;
;;;      modified January 1986 to follow Common Lisp conventions.  ACN


;;;
;;; Flag:
;;;   *PP-QUOTES          If TRUE, (QUOTE x) gets displayed as 'x.
;;;                       default is TRUE;
;;;
;;; Variable:
;;;   *PP-ON-ONE-LINE     If *PP-ON-ONE-LINE expressions can be fitted onto
;;;                       a single line they will be printed that way.
;;;                       this is a parameter used to control the
;;;                       formatting of long thin lists. default
;;;                       value is 5;
;;;


(defvar *pp-quotes* t
   ;; I should really introduce some general arrangement of print-macros
   ;; with (quote x) being just a special case, and I suspect that these
   ;; macros should work for all printing, not just prettyprinting.
   "True to make prettyprinter display (quote x) as 'x.")

(defvar *pp-on-one-line* 5
   "Control over prettyprinting lots of small items on one line")


;; From here down the functions are not intended for direct use;

(defvar *pp-buffer-list* nil
   "A stack of buffers for use with the prettyprinter")

(proclaim '(special
       *pp-output-stream*
       *pp-stack*
       *pp-buffer*
       *pp-bufferi*
       *pp-buffero*
       *pp-bn*
       *pp-lmar*
       *pp-rmar*
       *pp-initialblanks*
       *pp-pendingrpars*
       *pp-indentlevel*
       *pp-indblanks*
       *pp-rparcount*))


(defun sub-write-pretty (x down)
   (let* ((width (linelength nil))
          (save  (linelength 500))) 
   (let* ((*pp-output-stream* *standard-output*)
          ;; Output printed during prettyprinting goes via &pp-putch
          (*standard-output* (make-function-stream '&pp-putch))
          ;; To reduce GC overhead I keep a freelist of vectors for use
          ;; as buffers here. If an error occurs during prettyprinting
          ;; space may not be returned to this freelist, but then global
          ;; garbage collection will tidy things up.
          (*pp-buffer* (if (endp *pp-buffer-list*)
                           (make-array 256)
                           (pop *pp-buffer-list*)))
          (*pp-bufferi* 0)
          (*pp-buffero* 0)
          (*pp-bn* 0)
          (*pp-initialblanks* 0)
          (*pp-lmar* 0)
          (*pp-rmar* (- width 5))
          (*pp-pendingrpars* nil)
          *pp-stack*
          (*pp-indentlevel* 0)
          (*pp-indblanks* 0)
          (*pp-rparcount* 0))
      (cond
         ((< *pp-rmar* 25)
            (error "A line of length ~A is too short for prettyprinting"
                   (+ *pp-rmar* 5)))
         ((> *pp-rmar* 250) (setq *pp-rmar* 250)))
      (linelength 500)
      (fresh-line *pp-output-stream*)
      (&pp-print-indented x 3 down)
      (&pp-overflow 'none)
      (push *pp-buffer* *pp-buffer-list*))
   (linelength save)))

;; access functions for a stack entry;

(defmacro &pp-top nil `(car *pp-stack*))

(defmacro &pp-depth (frm) `(car ,frm))

(defmacro &pp-indenting (frm) `(cadr ,frm))

(defmacro &pp-blankcount (frm) `(caddr ,frm))

(defmacro &pp-blanklist (frm) `(cdddr ,frm))

(defmacro &pp-setindenting (frm val) `(rplaca (cdr ,frm) ,val))

(defmacro &pp-setblankcount (frm val) `(rplaca (cddr ,frm) ,val))

(defmacro &pp-setblanklist (frm val) `(rplacd (cddr ,frm) ,val))

(defmacro &pp-newframe (n) `(list ,n nil 0))

(defmacro &pp-blankp (char) `(numberp (car ,char)))


(defun &pp-print-indented (x n down)
   "Print list X with indentation level N"
   (cond
      ((not (consp x))
         (if
;; What about arrays that are not vectors??  structs??
            (and (vectorp x)
                 (not (or (stringp x) (simple-bit-vector-p x))))
            (&pp-print-vector x n down)
            ;; This will never generate #S output for structures
            ;; since the vector test comes first. When I change that it
            ;; will be necessary to do something rather cunning so that
            ;; printing of structures merges in smoothly with this code.
            (sub-write-1 x down)))  ; NB used &pp-putch
      ((printed-already x) nil)     ; *print-circle* interface
      ;; &pp-has-helper does the printing and returns T if there is a
      ;; print-macro available for this form. Otherwise it return NIL
      ((&pp-has-helper x n down) nil)
      ((and (integerp *print-level*) (> down *print-level*))
          (&pp-putch #\#))
      (t (prog (cx
                (along 2)
                (length-limit (if (integerp *print-length*)
                                  *print-length*
                                  most-positive-fixnum)))
            (when
               (> (* 4 n) (* 3 *pp-rmar*))
            ;; list is too deep for sanity
                     (&pp-overflow 'all)
                     (setq n (/ n 8))
                     (when
                        (> *pp-initialblanks* n)
                              (setq *pp-lmar*
                                 (+
                                    (-
                                       *pp-lmar*
                                       *pp-initialblanks*)
                                    n))
                              (setq *pp-initialblanks* n)))
            (setq *pp-stack* (cons (&pp-newframe n) *pp-stack*))
            (&pp-putch (cons 'lpar (&pp-top)))
            (setq cx (car x))
            (setq down (1+ down))
            (&pp-print-indented cx (1+ n) down)
            (if
               (and (symbolp cx) (not (atom (cdr x))))
                  (setq cx (get cx ':pp-format))
               (setq cx nil))
            (if (and (equal cx 2) (atom (cddr x))) (setq cx nil))
            (when
               (equal cx 'prog)
                     (&pp-putch #\ )
                     (&pp-print-indented
                        (car (setq x (cdr x)))
                        (+ n 3)
                        down)
                     (incf along))
;; CX now controls the formatting of what follows:
;;    NIL      default action
;;    <number> first few blanks are non-indenting
;;    PROG     display atoms as labels;
            (setq x (cdr x))
            (if (tail-printed-already x) (go out))
      scan  (cond ((not (consp x)) (go out)))
            (cond
               ((equal cx 'prog)
                     (&pp-putblank)
                     (&pp-overflow *pp-bufferi*) ;force format for prog;
                     (when
                        (atom (car x))
                              (setq *pp-lmar*
                                 (setq *pp-initialblanks*
                                    (max (- *pp-lmar* 6) 0)))
                              (&pp-print-indented
                                 (car x)
                                 (- n 3)
                                 down)
                              ;; print the label;
                              (setq x (cdr x))
                              (if (tail-printed-already x) (go out))
                              (if
                                 (and (not (atom x)) (atom (car x)))
                                    (go scan))
                              (if
                                 (>
                                     (+ *pp-lmar* *pp-bn*)
                                     n)
                                    (&pp-putblank)
                                 (dotimes
                                       (i (- n 1 *pp-lmar* *pp-bn*))
                                       (&pp-putch #\ )))
                              (if (atom x) (go out))))
               ((numberp cx)
                     (setq cx (1- cx))
                     (if (= cx 0) (setq cx nil))
                     (&pp-putch #\ ))
               (t (&pp-putblank)))
            (&pp-print-indented (car x) (+ n 3) down)
            (setq x (cdr x))
            (unless (tail-printed-already x) (go scan))
      out   (unless
               (null x)
                     (&pp-putblank)
                     (&pp-putch #\.)
                     (&pp-putch #\ )
                     (&pp-print-indented x (+ n 5) down))
            (&pp-putch (cons 'rpar (- n 3)))
            (if
               (and
                   (equal (&pp-indenting (&pp-top)) 'indent)
                   (not (null (&pp-blanklist (&pp-top)))) )
                  (&pp-overflow (car (&pp-blanklist (&pp-top))))
               (&pp-end-list (&pp-top)))
            (setq *pp-stack* (cdr *pp-stack*)))) ))

(defun &pp-has-helper (x n down)
   "Test to see if the function has a helper function associated"
   (let ((w nil))
      (if (symbolp (car x)) (setq w (get (car x) ':pprint)))
      (if w (funcall w x n down) nil)))

(defun &pp-print-vector (x n down)
;; Use #( ... ) notation.
   (cond
      ((not *print-array*)
         (write-literal-string "#<Array of length ")
         (sub-write-integer (length x))
         (&pp-putch #\>))
      ((and (integerp *print-level*) (> down *print-level*))
         (&pp-putch #\#))
      (t (let ((bound (length x))
               len1)
          (if (and (integerp *print-length*)
                   (> bound *print-length*))
              (setq len1 *print-length*)
              (setq len1 bound))
          (setq *pp-stack* (cons (&pp-newframe n) *pp-stack*))
          (&pp-putch #\#)
          (&pp-putch (cons 'lpar (&pp-top)))
          (unless (zerop len1) (&pp-print-indented (aref x 0) (+ n 3) down))
          (dotimes (i (1- len1))
                (&pp-putblank)
                (&pp-print-indented (aref x (1+ i)) (+ n 3) down))
          (unless (= len1 bound)
                  (write-literal-string " ..."))
          (&pp-putch (cons 'rpar (- n 3)))
          (&pp-end-list (&pp-top))
          (setq *pp-stack* (cdr *pp-stack*))))))

(defun &pp-putblank nil
   "When I have printed a ')' I want to mark all of the blanks
    within the parentheses as being unindented, ordinary blank
    characters. It is however possible that I may get a buffer
    overflow while printing a string of )))))))))), and so this
    marking should be delayed until I get round to printing
    a further blank (which will be a candidate for a place to
    split lines). This delay is dealt with by the list
    *PP-PENDINGRPARS* which holds a list of levels that, when
    convenient, can be tidied up and closed out"
   (if (null *pp-stack*)
       nil
       (progn
         (dolist (stackframe *pp-pendingrpars*)
               (unless
                  (equal (&pp-indenting stackframe) 'indent)
                     (dolist (b (&pp-blanklist stackframe))
                           (putv *pp-buffer* b #\ )
                           (setq *pp-indblanks*
                              (1- *pp-indblanks*))))
               (&pp-setblanklist stackframe t))
         (setq *pp-pendingrpars* nil)
         ;; Now print the 'blank';
         (&pp-putch (&pp-top))
         (&pp-setblankcount
            (&pp-top)
            (1+ (&pp-blankcount (&pp-top))))
         (&pp-setblanklist
            (&pp-top)
            (cons *pp-bufferi* (&pp-blanklist (&pp-top))))
         (setq *pp-indblanks* (1+ *pp-indblanks*)))))

(defun &pp-end-list (l)
   "fix up the blanks in a complete list so that they
    will not be turned into indentations"
   (setq *pp-pendingrpars* (cons l *pp-pendingrpars*)))

(defun &pp-quotep (x)
   (and
      *pp-quotes*
      (not (atom x))
      (equal (car x) 'quote)
      (not (atom (cdr x)))
      (null (cddr x))))

(defun &pp-print-quote (x n down)
   (cond
      ((&pp-quotep x)
            (&pp-putch #\')
            (&pp-print-indented (cadr x) (1+ n) down)
            t)
      (t nil)))

;;; property ppformat drives the prettyprinter -
;;; PROG     : special for prog only
;;; 1        :    (FN A1
;;;                  A2
;;;                  ... )
;;; 2        :    (FN A1 A2
;;;                  A3
;;;                  ... )

(put 'quote ':pprint '&pp-print-quote)

(put 'prog ':pp-format 'prog)
(put 'lambda ':pp-format 1)
(put 'setq ':pp-format 1)
(put 'set ':pp-format 1)
(put 'setf ':pp-format 1)
(put 'catch ':pp-format 1)
(put 'do ':pp-format 1)
(put 'do* ':pp-format 1)
(put 'dolist ':pp-format 1)
(put 'dotimes ':pp-format 1)
(put 'let ':pp-format 1)
(put 'let* ':pp-format 1)
(put 'if ':pp-format 1)
(put 'unless ':pp-format 1)
(put 'when ':pp-format 1)
(put 't ':pp-format 1)
(put 'defun ':pp-format 2)
(put 'defmacro ':pp-format 2)
(put 'setsyntax ':pp-format 2)

;;; Now for the routines that buffer things on a character by character
;;; basis, and deal with buffer overflow;

(defun &pp-putch (c)
   (prog nil
      (cond
         ((atom c)
               (setq *pp-rparcount* 0)
               (when
                  (equal c #.newline-char)
                        (&pp-putblank)
                        (&pp-overflow *pp-bufferi*)
                        (return c)))
         ((&pp-blankp c) (setq *pp-rparcount* 0) (go nocheck))
         ((equal (car c) 'rpar)
               (setq *pp-rparcount* (1+ *pp-rparcount*))
               (when
                  (> *pp-rparcount* 4)
                        ;; format for a long string of rpars is:
                        ;;    )))) ))) ))) ))) )))   ;
                        (&pp-putch #\ )
                        (setq *pp-rparcount* 2)))
         (t (setq *pp-rparcount* 0)))
      (loop
         (if (< (+ *pp-lmar* *pp-bn*) *pp-rmar*) (return))
         (&pp-overflow 'more))
nocheck
      (setq *pp-bufferi* (logand (1+ *pp-bufferi*) 255))
      (putv *pp-buffer* *pp-bufferi* c)
      (setq *pp-bn* (1+ *pp-bn*))
      (return c)))

(defun &pp-overflow (flg)
   "The current buffer holds so much information that it will
    not all fit on a line. Try to do something about it;
    FLG is one of:
      'NONE       do not force more indentation
      'MORE       force one level more indentation
       <a pointer into the buffer>
                  prints up to and including that character, which
                  should be a blank"
   (prog (c blankstoskip (*standard-output* *pp-output-stream*))
      (when
         (and
             (= *pp-indblanks* 0)
             (> *pp-initialblanks* 3)
             (equal flg 'more))
               (setq *pp-initialblanks*
                  (- *pp-initialblanks* 3))
               (setq *pp-lmar* (- *pp-lmar* 3))
               (return 'moved-left))
fblank(cond
         ((= *pp-bn* 0)
               ;; no blank found - can do no more for now;
               ;; If FLG='MORE I am in trouble and so have to print
               ;; a continuation mark. In the other cases I can just exit
               (unless (equal flg 'more) (return 'empty))
               (when
                  (atom (svref *pp-buffer* *pp-buffero*))
;; Continuation mark not needed if last char printed was
;; special (e.g. LPAR or RPAR)
                     (~tyo #\%) (~tyo #\+))
               (terpri)
               (setq *pp-lmar* 0)
               (return 'continued))
         (t
               (dotimes (i *pp-initialblanks*) (~tyo #\ ))
               (setq *pp-initialblanks* 0)))
      (setq *pp-buffero* (logand (1+ *pp-buffero*) 255))
      (setq *pp-bn* (1- *pp-bn*))
      (setq *pp-lmar* (1+ *pp-lmar*))
      (setq c (svref *pp-buffer* *pp-buffero*))
      (cond
         ((atom c) (~tyo c) (go fblank))
         ((&pp-blankp c)
            (cond
               ((not (atom blankstoskip))
                     (~tyo #\ )
                     (setq *pp-indblanks* (1- *pp-indblanks*))
                     (when
;; BLANKSTOSKIP = (STACK-FRAME . SKIP-COUNT);
                        (eq c (car blankstoskip))
                              (rplacd
                                 blankstoskip
                                 (1- (cdr blankstoskip)))
                              (if
                                 (= (cdr blankstoskip) 0)
                                    (setq blankstoskip t)))
                     (go fblank))
               (t (go blankfound))))
         ((or (equal (car c) 'lpar) (equal (car c) 'lsquare))
               (~tyo (get (car c) '&pp-char))
               (if (equal flg 'none) (go fblank))
;; Now I want to flag this level for indentation;
               (setq c (cdr c)) ; the stack frame
               (unless  (null (&pp-blanklist c)) (go fblank))
               (when
                  (> (&pp-depth c) *pp-indentlevel*)
;; New indentation
;; This level has not emitted any blanks yet
                        (setq *pp-indentlevel* (&pp-depth c))
                        (&pp-setindenting c 'indent))
               (go fblank))
         ((or (equal (car c) 'rpar) (equal (car c) 'rsquare))
               (if
                  (< (cdr c) *pp-indentlevel*)
                     (setq *pp-indentlevel* (cdr c)))
               (~tyo (get (car c) '&pp-char))
               (go fblank))
         (t (error 0 (list c "Unknown tag in pp-overflow"))))
blankfound
      (if
         (eqcar (&pp-blanklist c) *pp-buffero*)
            (&pp-setblanklist c nil))
;; At least one entry on blanklist ought to be valid, so if I
;; print the last blank I must kill blanklist totally
      (setq *pp-indblanks* (1- *pp-indblanks*))
;; Check if next level represents new indentation;
      (when
         (> (&pp-depth c) *pp-indentlevel*)
               (when
                  (equal flg 'none)
                     (~tyo #\ ) (go fblank))
;; Here I increase the indentation level by one;
               (cond
                  (blankstoskip (setq blankstoskip nil))
                  (t    (setq *pp-indentlevel* (&pp-depth c))
                        (&pp-setindenting c 'indent))))
;; otherwise I was indenting at that level anyway;
      (when
         (> (&pp-blankcount c) (1- *pp-on-one-line*))
               (setq blankstoskip
                  (cons c (- (&pp-blankcount c) 2)))
               (&pp-setindenting c 'thin)
               (&pp-setblankcount c 1)
               (setq *pp-indentlevel* (1- (&pp-depth c)))
               (~tyo #\ )
               (go fblank))
      (&pp-setblankcount c (1- (&pp-blankcount c)))
      (terpri)
      (setq *pp-lmar* (setq *pp-initialblanks* (&pp-depth c)))
      (if (equal *pp-buffero* flg) (return 'to-flg))
      (if (or blankstoskip (not (equal flg 'more))) (go fblank))
;; Keep going unless call was of type 'MORE'
      (return 'more)))

(defvar char-lpar #\()

(defvar char-rpar #\))

(setf (get 'lpar '&pp-char) char-lpar)

(setf (get 'rpar '&pp-char) char-rpar)



(defun write-string-subroutine (s n)
   (dotimes (i n) (~tyo (char s i))))

;; (defun sub-write-based (object base)
;;    ;; This uses a lot of stack when printing big numbers,
;;    ;; especially if in binary. It might make sense to clump digits
;;    ;; together into word-sized chunks then print them... ?
;;    (if (>= object base)
;;        (multiple-value-bind (q r) (truncate object base)
;;           (sub-write-based q base)
;;           (setq object r)))
;;    (~tyo (char "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" object)))
;; New algorithm (JHD 15.8.96) is binary-chop based

(defun sub-write-based (object base) 
   (let ((l nil) (xbase base) (count 1))
      (while (<= xbase object)
         (setq l (cons (cons xbase count) l))
         ;; l is a list of (base**(2**n) . 2**n)
         (setq count (+ count count))
         (setq xbase (* xbase xbase)))
      (sub-write-based-inner object l)))

(defun sub-write-based-inner (object l)
   (while (and l (< object (caar l)))
      (setq l (cdr l)))
   (if l 
      (multiple-value-bind (q r) (truncate object (caar l))
         (if (null (setq l (cdr l)))
            (progn
               (~tyo (char "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" q))
               (~tyo (char "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" r)))
            (progn
               (sub-write-based-inner q l)
               (sub-write-based-leading r l))))
      (~tyo (char "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" object))))

(defun sub-write-based-leading (object l)
   (while (and l (< object (caar l)))
      (dotimes (i (cdar l))
         (~tyo #\0)) 
      (setq l (cdr l)))
   (if l
      (multiple-value-bind (q r) (truncate object (caar l))
         (if (null (setq l (cdr l)))
            (progn
               (~tyo (char "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" q))
               (~tyo (char "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" r)))
            (progn
               (sub-write-based-leading q l)
               (sub-write-based-leading r l))))
      (~tyo (char "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" object))))


(defun sub-write-integer (object)
   (cond
      ((= *print-base* 10) (sub-write-decimal object))
      ((and (integerp *print-base*)
            (<= 2 *print-base* 36))
         (when *print-radix*
            (~tyo #\#)
            (cond
               ((= *print-base* 16) (~tyo #\x))
               ((= *print-base* 8) (~tyo #\o))
               ((= *print-base* 2) (~tyo #\b))
               (t (sub-write-decimal *print-base*) (~tyo #\r))))
         (when (< object 0) (~tyo #\-) (setq object (- 0 object)))
         (sub-write-based object *print-base*))
      (t (sub-write-decimal object)))
   object)

(defun sub-write-float (object) 
;   (write-literal-string "#<fp number>") object)
    (dolist (ch (explodecn object)) (~tyo (code-char ch))))

(defun sub-write-symbol (object)
;; This needs to do things about the package in which the given symbol
;; belongs.
   (let* ((pname (symbol-name object))
          (len (length pname))
          (escape-needed nil)
          (home nil))
      (cond
         ((keywordp object) (~tyo #\:))
         ((null (setq home (symbol-package object))) (~tyo #\#) (~tyo #\:))
         ((null *print-escape*) nil)
         (t (multiple-value-bind (s found) (find-symbol object)
            (when (not found)
               (multiple-value-bind (s1 found1)
                  (find-symbol object home)
                  (sub-write-symbol (intern (package-name home)))
                  (~tyo #\:)
                  (when (eq found1 :internal) (~tyo #\:)))))))
      (if *print-escape*
        (let ((c))
          (when (and (not (= len 0)) (digit (char pname 0)))
             (setq escape-needed t))
          (dotimes (i len)
             ;; This is a coarse approximation to the test that will be needed
             ;; but it should do for now.
             (setq c (char pname i))
             (unless (or (and (alpha-char-p c) (upper-case-p c))
                         (digit c))
                (setq escape-needed t)
                (return)))))
      (if escape-needed (~tyo #\|))
      (case *print-case*
        (:upcase
           (dotimes (i len)
              (let ((c (char pname i)))
                 (if (and *print-escape* (char-dodgyp c)) (~tyo #\\))
                 (~tyo (char-upcase c)))))
        (:downcase
           (dotimes (i len)
              (let ((c (char pname i)))
                 (if (and *print-escape* (char-dodgyp c)) (~tyo #\\))
                 (~tyo (char-downcase c)))))
        (:capitalize
           (setq pname (string-capitalize pname))
           (dotimes (i len)
              (let ((c (char pname i)))
                 (if (and *print-escape* (char-dodgyp c)) (~tyo #\\))
                 (~tyo c))))
        (t
           (dotimes (i len)
              (let ((c (char pname i)))
                 (if (and *print-escape* (char-dodgyp c)) (~tyo #\\))
                 (~tyo c)))))
      (if escape-needed (~tyo #\|))
      object))

(defun sub-write-string (object)
   (if *print-escape* (~tyo #\"))
   (dotimes (i (length object))
      (let ((c (char object i)))
         (if (and *print-escape* (or (char= c #\") (char= c #\\))) (~tyo #\\))
         (~tyo c)))
   (if *print-escape* (~tyo #\"))
   object)

(defun sub-write-vector (object down)
   (if (not *print-array*)
       (progn
          (write-literal-string "#<Array of length ")
          (sub-write-integer (length object))
          (~tyo #\>)
          object)
       (if (and (integerp *print-level*) (> down *print-level*))
           (~tyo #\#)
           (let* ((len (length object))
                  len1
                  (sep char-lpar)
                  (down1 (1+ down)))
              (~tyo #\#)
              (if (and (integerp *print-length*)
                       (> len *print-length*))
                  (setq len1 *print-length*)
                  (setq len1 len))
              (dotimes (i len1)
                 (~tyo sep)
                 (sub-write-1 (aref object i) down1)
                 (setq sep #\ ))
              (when (= len1 0) (~tyo sep))
              (unless (= len len1)
                 (write-literal-string " ..."))
              (~tyo char-rpar)
              object))))

(defun scan-vector (object down)
   (if (not *print-array*)
       (unless (and (integerp *print-level*) (> down *print-level*))
           (let* ((len (length object))
                  len1
                  (down1 (1+ down)))
              (if (and (integerp *print-length*)
                       (> len *print-length*))
                  (setq len1 *print-length*)
                  (setq len1 len))
              (dotimes (i len1)
                 (print-scan (aref object i) down1))))))

(defun scan-unknown (x)
   nil)

(defun sub-write-unknown (object)
   ;; code-pointers etc - at present this uses Codemist Lisp facilities
   (dolist (c (exploden object)) (~tyo c)) )
   

(defun structurep (v)
   "Test if an object is a structure defined by defstruct. Note that this
    can only recognize things defined without the defstruct :type option"
   (prog nil
      (let (name lisp-type definition)
         (if (structp v)
             (setq name (svref v 0))
             (return nil))
         (setq definition (get name :structure-definition))
         (unless definition (return nil))
         (unless (eq 'simple-vector (dd-lisp-type definition)) (return nil))
         (unless (= (length v) (dd-length definition)) (return nil))
         (return definition))))

(defun sub-write (object)
;; general print function, always sending results to *standard-output*
;; and honouring all the miscelaneous print format control flags
   (let ((print-objects nil)
         (print-index nil))
      (if *print-circle* (print-scan object 1))
      (setq print-objects 0)
      (if *print-pretty*
          (sub-write-pretty object 1)
          (sub-write-1 object 1))
      object))

(defun print-scan (object down)
;; scan the given object, calling add-item for all composite objects found
   (if (not (consp object))
       (if (or (numberp object) (and (not (gensymp object)) (symbolp object)) (characterp object)) nil
               (unless (add-item object)
                  (if (stringp object) nil
                      (if (structurep object)
                          (scan-vector object down)
;; arrays need treatment here - also special for bitvecs needed
                          (if (vectorp object)
                              (scan-vector object down)
                              (scan-unknown object))))))
       (unless (add-item object)
          (unless (and (integerp *print-level*) (> down *print-level*))
              (let ((along 1)
                    (down1 (1+ down))
                    (length-limit
                       (if (integerp *print-length*)
                           *print-length*
                           most-positive-fixnum)))
                 (loop
                    (if (not (consp object)) (return))
                    (when (> along length-limit)
                          (setq object nil)
                          (return))
                    (print-scan (car object) down1)
                    (setq object (cdr object)
                          along (1+ along))
                     (when (add-item object) (setq object nil) (return)))
                 (unless (null object)
                    (print-scan object down)))))))

(defun sub-write-1 (object down)
   (if (not (consp object))
       (if (numberp object)
           (if (integerp object)
               (sub-write-integer object)
               (sub-write-float object))
           (if (characterp object)
               (~tyo object)
               (if (and (not (gensymp object)) (symbolp object))
                   (sub-write-symbol object)
               (unless (printed-already object)
               (if (symbolp object)
                   (sub-write-symbol object)
                      (if (stringp object)
                          (sub-write-string object)
                          (let ((w (structurep object)))
                             (if w
                                 (if (setq w (dd-print-function w))
                                     (funcall w object *standard-output* down)
                                     (sub-write-vector object down))
;; arrays? bitvectors?
                                 (if (vectorp object)
                                     (sub-write-vector object down)
                                     (sub-write-unknown object))))))))))
       (unless (printed-already object)
          (if (and (integerp *print-level*) (> down *print-level*))
              (~tyo #\#)
              (let ((sep char-lpar)
                    (along 1)
                    (down1 (1+ down))
                    (length-limit
                       (if (integerp *print-length*)
                           *print-length*
                           most-positive-fixnum)))
                 (loop
                    (if (not (consp object)) (return))
                    (when (> along length-limit)
                          (write-literal-string " ...")
                          (setq object nil)
                          (return))
                    (~tyo sep)
                    (sub-write-1 (car object) down1)
                    (setq sep #\    ; #\space
                          object (cdr object)
                          along (1+ along))
                    (when (tail-printed-already object)
                          (return)))
                 (unless (null object)
                    (write-literal-string " . ")
                    (sub-write-1 object down))
                 (~tyo char-rpar))))))

;;; fairly normal entrypoints into the print package

(defun write-byte (ch stream)
   (if (null stream) (error "Invalid item used as stream (~S)" stream))
   (~tyo ch)
   ch)

(defun write-char (ch &optional (stream nil))
   (if (null stream)
       (progn
          (unless (streamp *standard-output*)
             (error "Invalid item used as stream (~S)"
                    *standard-output*))
          (~tyo ch))
       (let ((*standard-output* stream))
          (unless (streamp *standard-output*)
             (error "Invalid item used as stream (~S)"
                    *standard-output*))
          (~tyo ch)))
   ch)

(defun terpri (&optional (stream nil))
   (if (null stream)
       (progn
          (unless (streamp *standard-output*)
             (error "Invalid item used as stream (~S)"
                    *standard-output*))
          (~tyo #.newline-char))
       (let ((*standard-output* stream))
          (unless (streamp *standard-output*)
             (error "Invalid item used as stream (~S)"
                    *standard-output*))
          (~tyo #.newline-char)))
   nil)

(defun fresh-line (&optional (stream nil))
   (if (null stream)
       (progn
          ;; charpos validates *standard-output* as a stream
          (unless (= (charpos) 0) (~tyo #.newline-char))
          t)
       (let ((*standard-output* stream))
          (unless (= (charpos) 0) (~tyo #.newline-char))
          t)))

(defun write-string (s &optional (stream nil) &key (start 0) (end (length s)))
   (if (null stream)
       (progn
          (unless (streamp *standard-output*)
             (error "Invalid item used as stream (~S)"
                    *standard-output*))
          (do ((i start (1+ i)))
              ((>= i end))
              (~tyo (char s i))))
       (let ((*standard-output* stream))
          (unless (streamp *standard-output*)
             (error "Invalid item used as stream (~S)"
                    *standard-output*))
          (do ((i start (1+ i)))
              ((>= i end))
              (~tyo (char s i)))))
   s)

(defun write-line (s &optional (stream nil) &key (start 0) (end (length s)))
   (if (null stream)
       (progn
          (unless (streamp *standard-output*)
             (error "Invalid item used as stream (~S)"
                    *standard-output*))
          (do ((i start (1+ i)))
              ((>= i end) (~tyo #.newline-char))
              (~tyo (char s i))))
       (let ((*standard-output* stream))
          (unless (streamp *standard-output*)
             (error "Invalid item used as stream (~S)"
                    *standard-output*))
          (do ((i start (1+ i)))
              ((>= i end) (~tyo #.newline-char))
              (~tyo (char s i)))))
   s)

(defun write-line-2 (s &optional (stream nil))
 (let ((end (length s)))
   (if (null stream)
       (progn
          (unless (streamp *standard-output*)
             (error "Invalid item used as stream (~S)"
                    *standard-output*))
          (do ((i 0 (1+ i)))
              ((>= i end) (~tyo #.newline-char))
              (~tyo (char s i))))
       (let ((*standard-output* stream))
          (unless (streamp *standard-output*)
             (error "Invalid item used as stream (~S)"
                    *standard-output*))
          (do ((i 0 (1+ i)))
              ((>= i end) (~tyo #.newline-char))
              (~tyo (char s i)))))
   s))

(defun prin1 (object &optional (stream nil))
   (let ((*print-escape* t))
      (if (null stream)
          (progn
             (unless (streamp *standard-output*)
                (error "Invalid item used as stream (~S)"
                       *standard-output*))
             (sub-write object))
          (let ((*standard-output* stream))
             (unless (streamp *standard-output*)
                (error "Invalid item used as stream (~S)"
                       *standard-output*))
             (sub-write object)))
      object))

(defun princ (object &optional (stream nil))
   (let ((*print-escape* nil))
      (if (null stream)
          (progn
             (unless (streamp *standard-output*)
                (error "Invalid item used as stream (~S)"
                       *standard-output*))
             (sub-write object))
          (let ((*standard-output* stream))
             (unless (streamp *standard-output*)
                (error "Invalid item used as stream (~S)"
                       *standard-output*))
             (sub-write object)))
      object))

(defun print (object &optional (stream nil))
   (let ((*print-escape* t))
      (if (null stream)
          (progn
             (unless (streamp *standard-output*)
                (error "Invalid item used as stream (~S)"
                       *standard-output*))
             (~tyo #.newline-char)
             (sub-write object)
             (~tyo #\ ))
          (let ((*standard-output* stream))
             (unless (streamp *standard-output*)
                (error "Invalid item used as stream (~S)"
                       *standard-output*))
             (~tyo #.newline-char)
             (sub-write object)
             (~tyo #\ )))
      object))

(defun pprint (object &optional (stream nil))
   (let ((*print-escape* t) (*print-pretty* t))
      (if (null stream)
          (progn
             (unless (streamp *standard-output*)
                (error "Invalid item used as stream (~S)"
                       *standard-output*))
             (~tyo #.newline-char)
             (sub-write object))
          (let ((*standard-output* stream))
             (unless (streamp *standard-output*)
                (error "Invalid item used as stream (~S)"
                       *standard-output*))
             (~tyo #.newline-char)
             (sub-write object))))
   (values))


;; output that goes to a string

(defun prin1-to-string (object)
   (let ((*print-escape* t)
         (*standard-output* (make-string-output-stream)))
      (sub-write object)
      (get-output-stream-string *standard-output*)))

(defun princ-to-string (object)
   (let ((*print-escape* nil)
         (*standard-output* (make-string-output-stream)))
      (sub-write object)
      (get-output-stream-string *standard-output*)))



;;; These functions seem rather nasty to me, but here they are. They allow
;;; one to reset all or any of the output control flags

(defun write (object &key
                     ((:stream *standard-output*) *standard-output*)
                     ((:escape *print-escape*)    *print-escape*)
                     ((:radix  *print-radix*)     *print-radix*)
                     ((:base   *print-base*)      *print-base*)
                     ((:circle *print-circle*)    *print-circle*)
                     ((:pretty *print-pretty*)    *print-pretty*)
                     ((:level  *print-level*)     *print-level*)
                     ((:length *print-length*)    *print-length*)
                     ((:case   *print-case*)      *print-case*)
                     ((:gensym *print-gensym*)    *print-gensym*)
                     ((:array  *print-array*)     *print-array*))
   (unless (streamp *standard-output*)
      (error "Invalid item used as stream (~S)" *standard-output*))
   (sub-write object)
   object)


(defun write-1 (object)
   (unless (streamp *standard-output*)
      (error "Invalid item used as stream (~S)" *standard-output*))
   (sub-write object)
   object)


(defun write-to-string (object &key
                               ((:escape *print-escape*) *print-escape*)
                               ((:radix  *print-radix*)  *print-radix*)
                               ((:base   *print-base*)   *print-base*)
                               ((:circle *print-circle*) *print-circle*)
                               ((:pretty *print-pretty*) *print-pretty*)
                               ((:level  *print-level*)  *print-level*)
                               ((:length *print-length*) *print-length*)
                               ((:case   *print-case*)   *print-case*)
                               ((:gensym *print-gensym*) *print-gensym*)
                               ((:array  *print-array*)  *print-array*)
                               &aux
                               (*standard-output*
                                  (make-string-output-stream)))
   (sub-write object)
   (get-output-stream-string *standard-output*))

(defun write-to-string-1 (object)
  (let
      ((*standard-output* (make-string-output-stream)))
    (sub-write object)
    (get-output-stream-string *standard-output*)))


;;; End of print package.

