
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


;;;;;;;; (defun tyi () (%tyi))
(defun tyiq () (%tyiq))
(defun tyipeek () (%tyipeek))  ; placeholders

;;;; Read routines


(proclaim '(special syntax-table))

(progn
   ;; The table here looks ugly if displayed (it contains all possible
   ;; character objects, many of which are not really printable), so
   ;; I hide its creation within a PROGN.
   (defvar character-table
      (let ((v (make-array 257)))
         (dotimes (i 257 v) (putv v i (char-code (1- i))))))
   nil)


(defconstant $numbersyntax 257)

(defconstant $readmacro 259)

(defconstant $splicemacro 260)

(defconstant $preadmacro 261)

(defconstant $psplicemacro 262)

(defconstant $escapechar 263)

(defmacro character (n)
   `(svref character-table (1+ ,n)))

(proclaim '(special *rdr-stacked-tokens* *token-type* *eof-status*))

(setq *rdr-stacked-tokens* nil)

(defmacro syntaxbitp (char flagname)
   (let ((mask (&syntax-mask-value flagname)))
      `(not (= 0 (logand (svref syntax-table (1+ ,char)) ,mask)))))

(defun &syntax-mask-value (flagname)
   (cond
      ((atom flagname) (get flagname 'read-syntax-bit))
      ((equal (car flagname) 'or)
         (eval
            (cons
               'logor
               (mapcar (function &syntax-mask-value) (cdr flagname)))))
      ((equal (car flagname) 'and)
         (eval
            (cons
               'logand
               (mapcar (function syntax-mask-value) (cdr flagname)))))
      (t (error (format nil 
                 "~S is an illegal tag in SYNTAX-MASK-VALUE " flagname))))) )

(defun setsyntax (char class data)
   (cond
      ((stringp char) (setsyntax (%explodec char) class data))
      ((not (atom char))
         (dolist (c char char) (setsyntax c class data)))
      (t (let (code mask indicator)
            (cond
               ((equal class 'macro) (setq class 'read-macro))
               ((equal class 'splice) (setq class 'splice-macro)))
            (setq code (1+ (char-code char)))
            (cond
               ((and (equal class 'escape) data)
                  (putv syntax-table $escapechar (1- code))))
            (cond
               ((or
                   (and
                      (equal class 'read-macro)
                      (setq indicator
                         (svref syntax-table $readmacro)))
                   (and
                      (equal class 'splice-macro)
                      (setq indicator
                         (svref syntax-table $splicemacro))))
                  (cond
                     ((null data) (remprop char indicator))
                     (t (progn
                           (cond
                              ((eqcar data 'function)
                                 (setq data (cadr data))))
                           (put char indicator data)
                           (cond
                              ((and
                                  *comp
                                  (symbol-function 'comprop)
                                  (eqcar data 'lambda))
                                 (comprop (list char) indicator)))) ))) )
            (setq mask (get class 'read-syntax-bit))
            (if (null mask)
                (error (format nil "Class=~S  illegal in SETSYNTAX" class)))
            (cond
               ((null data)
                  (putv
                     syntax-table
                     code
                     (logand
                        (svref syntax-table code)
                        (logxor mask -1))) )
               (t (putv
                     syntax-table
                     code
                     (logor (svref syntax-table code) mask))))
            char))) )

(defun getsyntax (char class)
   (prog (code mask indicator)
      (cond ((stringp char) (setq char (car (%explodec char)))) )
      (cond
         ((equal class 'macro) (setq class 'read-macro))
         ((equal class 'splice) (setq class 'splice-macro)))
      (setq code (1+ (char-code char)))
      (setq mask (get class 'read-syntax-bit))
      (if (null mask)
          (error (format nil "Class=~S illegal in GETSYNTAX" class)))
      (cond
         ((and
             (equal class 'escape)
             (not (= 0 (logand mask (svref syntax-table code)))) )
            (return (svref syntax-table $escapechar))))
      (cond
         ((or
             (and
                (equal class 'read-macro)
                (setq indicator (svref syntax-table $readmacro)))
             (and
                (equal class 'splice-macro)
                (setq indicator (svref syntax-table $splicemacro))))
            (progn
               (cond
                  ((= 0 (logand mask (svref syntax-table code)))
                     (return nil))
                  (t (return (get char indicator)))) )))
      (cond
         ((= 0 (logand mask (svref syntax-table code)))
            (return nil))
         (t (return t)))) )

(defun copy-syntax-table (s)
   (let ((v1 (mkvect $escapechar)) g)
      (dotimes (i (1+ $escapechar)) (putv v1 i (svref s i)))
      (do ((i 258 (1+ i)))
          ((> i $psplicemacro))
         (putv v1 i (gensym))
         (do ((j -1 (1+ j)))
             ((> j 255))
            (setq g (get (character j) (svref s i)))
            (if g (put (character j) (svref v1 i) g))))
      v1))

(defun &numeric-syntax-class (l val)
   (dolist (c (%explodecn l))
      (putv
         syntax-table
         (1+ c)
         (logor (logand -8 (svref syntax-table c)) val))))

(put 'read-macro 'read-syntax-bit 8)
(put 'splice-macro 'read-syntax-bit 8)
(put 'break-character 'read-syntax-bit 16)
(put 'ignore 'read-syntax-bit 32)
(put 'digit 'read-syntax-bit 64)
(put 'escape 'read-syntax-bit 128)
(put 'lower-case 'read-syntax-bit 256)
(put 'letter 'read-syntax-bit 512)
(put 'may-start-number 'read-syntax-bit 1024)
(put 'upper-case 'read-syntax-bit 2048)

;;; (defconstant t 't)

(defconstant lpar '\()

(defconstant rpar '\))

(defconstant period '\.)

(defconstant blank '\ )

(defconstant tab (char-code 9))

(defconstant $cr$ (char-code 13))

(defconstant $ff$ (char-code 12))

(defconstant $eol$ (char-code 10))

(defconstant $eof$ (char-code -1))

(defconstant comma '\,)

(defconstant quotemark '\')

(defconstant dollar '$)


(proclaim '(special *raise* *lower*))

(setq *raise* nil)

(setq *lower* t)

(defmacro &case-adjust (ch)
   `(cond
      ((and *raise* (syntaxbitp ,ch lower-case))
         (setq ,ch (char-upcase ,ch)))
      ((and *lower* (syntaxbitp ,ch upper-case))
         (setq ,ch (char-downcase ,ch)))) )

(proclaim '(special *echo* *rdr-inside-pretty-read*))

(defun read-token nil
   (cond
      ((atom *rdr-stacked-tokens*) (&genuine-read-token))
      (t (let ((temp (pop *rdr-stacked-tokens*)))
            (cond
               ((equal temp 'shadow-of-right-superpar)
                     (setq temp '\})
                     (setq *token-type* 'break-character))
               (t (setq *token-type* 'result-of-read-macro)))
            temp))) )

(defun &genuine-read-token nil
   (cond
      (*rdr-inside-pretty-read* (&pp-read-token))
      (t (prog (ch w is-number)
            (cond
               ((not (= *eof-status* 0))
                  (error "Attempt to read token beyond EOF")))
            (setq ch (tyi))
            (while (syntaxbitp ch ignore) (setq ch (tyi)))
            (cond
               ((syntaxbitp ch escape) (setq ch (tyi)))
               ((and
                   (syntaxbitp ch may-start-number)
                   (syntaxbitp (tyipeek) digit))
                  (setq is-number
                     (svref syntax-table $numbersyntax)))
               ((syntaxbitp ch (or break-character read-macro))
                  (progn
                     (setq *token-type* 'break-character)
                     (cond
                        ((char= ch #\eof)
                           (setq *eof-status* 'read-token)))
                     (return (character ch))))
               (t (progn
                     (&case-adjust ch)
                     (setq is-number
                        (svref syntax-table $numbersyntax)))) )
            (%clearbuff)
      loop  (%packbyte ch)
            (cond
               (is-number
                  (progn
                     (setq is-number
                        (svref
                           is-number
                           (logand
                              7
                              (svref syntax-table (1+ ch)))) )
                     (cond
                        ((equal is-number 'end) (setq is-number nil)))) ))
            (setq ch (tyipeek))
            (cond
               ((and
                   is-number
                   (progn
                      (setq w
                         (svref
                            is-number
                            (logand
                               7
                               (svref syntax-table (1+ ch)))) )
                      (cond ((or (equal w nil) (equal w 'end)) nil) (t t))))
                  (go continue-reading-number)))
            (cond
               ((syntaxbitp ch (or break-character read-macro))
                  (cond
                     ((and is-number (svref is-number 0))
                        (progn
                           (setq *token-type* 'number)
                           (setq *eof-status* 0)
                           (return (%numob))))
                     (t (progn
                           (setq *token-type* 'symbol)
                           (setq *eof-status* 0)
                           (return (%mkatom)))) )))
      continue-reading-number
            (tyi)
            (cond
               ((syntaxbitp ch escape)
                  (progn (setq ch (tyi)) (setq is-number nil)))
               (t (&case-adjust ch)))
            (go loop)))) )

(proclaim '(special *pp-no-blank-flag*))

(defun *pp-tyi* nil
   (let (c)
      (cond
         ((not (= *eof-status* 0))
            (error "Attempt to read character beyond EOF")))
      (setq c (tyiq))
      (cond
         ((char= c #\eof) (setq *eof-status* 'tyi))
         (t (&pp-putch nil c)))
      (setq *pp-no-blank-flag* t)
      c))

(defun &pp-peek-token nil
   (if
      (not (atom *rdr-stacked-tokens*))
      (progn
         (setq *token-type* 'result-of-read-macro)
         (car *rdr-stacked-tokens*))
      (let ((ch (tyiq)) is-number)
         (while (syntaxbitp ch ignore) (setq ch (tyiq)))
         (cond
            ((syntaxbitp ch escape) (setq *token-type* 'escape))
            ((and
                (syntaxbitp ch may-start-number)
                (syntaxbitp (tyipeek) digit))
               (setq *token-type* 'symbol))
            ((syntaxbitp ch (or break-character read-macro))
               (progn
                  (cond
                     ((char= ch #\eof)
                        (setq *eof-status* 'read-token)))
                  (setq *token-type* 'break-character)))
            (t (setq *token-type* 'symbol)))
         ch)))

(defun &pp-finish-token (ch)
   (cond
      ((equal *token-type* 'result-of-read-macro)
         (progn
            (setq *rdr-stacked-tokens* (cdr *rdr-stacked-tokens*))
            (cond
               ((equal ch 'shadow-of-right-superpar)
                  (progn
                     (setq ch '\})
                     (setq *token-type* 'break-character))))
            ch))
      (t (prog (is-number)
            (cond
               (*pp-no-blank-flag* (setq *pp-no-blank-flag* nil))
               (t (&pp-putblank)))
            (cond
               ((equal *token-type* 'symbol)
                  (progn
                     (&pp-putch nil ch)
                     (&case-adjust ch)
                     (setq is-number
                        (svref syntax-table $numbersyntax))))
               ((equal *token-type* 'escape)
                  (progn (&pp-putch nil ch) (setq ch (&pp-putch nil (tyiq)))) )
               (t (return (character ch))))
            (%clearbuff)
      loop  (%packbyte ch)
            (cond
               (is-number
                  (progn
                     (setq is-number
                        (svref
                           is-number
                           (logand
                              7
                              (svref syntax-table (1+ ch)))) )
                     (cond
                        ((equal is-number 'end) (setq is-number nil)))) ))
            (setq ch (tyipeek))
            (cond
               ((not
                   (and
                      (char= ch #\.)
                      is-number
                      (svref is-number 3)))
                  (cond
                     ((syntaxbitp ch (or break-character read-macro))
                        (cond
                           ((and is-number (svref is-number 0))
                              (progn
                                 (setq *token-type* 'number)
                                 (setq *eof-status* 0)
                                 (return (%numob))))
                           (t (progn
                                 (setq *token-type* 'symbol)
                                 (setq *eof-status* 0)
                                 (return (%mkatom)))) ))) ))
            (&pp-putch nil (tyiq))
            (cond
               ((syntaxbitp ch escape)
                  (progn
                     (setq ch (&pp-putch nil (tyiq)))
                     (setq is-number nil)))
               (t (&case-adjust ch)))
            (go loop)))) )

(defun &pp-read-token nil
   (let* ((a (&pp-peek-token))
          (b (&pp-finish-token a)))
      (cond ((equal a 'shadow-of-right-superpar) (setq a '\})))
      (cond ((equal *token-type* 'break-character) (&pp-putch nil a)))
      b))

(proclaim '(special tyi tyipeek *pp-tyi* *pp-indent-level*))

(setq *echo* nil)

(setq *rdr-inside-pretty-read* nil)

(defun read nil
   (if *rdr-inside-pretty-read*
      (&pp-read)
      (let (u)
         (cond
            ((not (= *eof-status* 0)) (error "Attempt to read beyond EOF")))
         (loop
            (cond
               ((not (equal *echo* 'pretty)) (setq u (&genuine-read)))
               (t (let ((tyi (function *pp-tyi*))
                        (*pp-indent-level* 3)
                        (*rdr-inside-pretty-read* t)
                        (*pp-stack* (list (&pp-newframe 0)))
                        (*pp-bufferi* 0)
                        (*pp-buffero* 0)
                        (*pp-buffer* nil)
                        (*pp-bn* 0)
                        (*pp-initialblanks* 0)
                        (*pp-lmar* 0)
                        (*pp-rmar* (- (%linelength nil) 3))
                        (*pp-pendingrpars* nil)
                        (*pp-indentlevel* 0)
                        (*pp-indblanks* 0)
                        (*pp-rparcount* 0)
                        (*pp-output-stream* *standard-output*))
                     (setq *pp-no-blank-flag* t)
                     (fresh-line)
                     (cond
                        ((< *pp-rmar* 25)
                           (error (format nil 
                        "Linelength of ~A too short for *ECHO=PRETTY reading"
                              (+ *pp-rmar* 3))))
                        ((> *pp-rmar* 250) (setq *pp-rmar* 250)))
                     (setq *pp-buffer*
                        (if (endp *pp-buffer-list*)
                           (make-array 256)
                           (pop *pp-buffer-list*)))
                     (setq u (&pp-read))
                     (&pp-overflow 'none)
                     (push *pp-buffer* *pp-buffer-list*)
                     (terpri))))
            (cond
               ((equal *token-type* 'break-character)
                  (progn
                     (cond
                        ((or (equal u rpar) (equal u '\})) nil)
                        ((equal u $eof$)
                           (setq *eof-status* 'read)
                           (return-from nil))
                        (t (setq *eof-status* 0) (return-from nil)))) )
               (t (setq *eof-status* 0) (return-from nil))))
         u)))

(defun &genuine-read nil
   (prog (fn l)
loop  (setq l (read-token))
      (cond
         ((equal *token-type* 'break-character)
            (cond
               ((setq fn (get l (svref syntax-table $readmacro)))
                  (progn
                     (setq l (&call-read-macro fn l))
                     (setq *token-type* 'result-of-read-macro)
                     (return l)))
               ((setq fn (get l (svref syntax-table $splicemacro)))
                  (progn
                     (setq l (&call-read-macro fn l))
                     (setq *rdr-stacked-tokens*
                        (append l *rdr-stacked-tokens*))
                     (go loop)))) ))
      (return l)))

(proclaim '(special *rdr-readerrors*))

(setq *rdr-readerrors* nil)

(defun &call-read-macro (read-macro-function l)
   (prog (u)
      (setq u (%errorset (list read-macro-function) nil))
      (cond
         ((atom u)
            (progn
               (cond
                  ((not (equal *echo* 'pretty))
                     (progn
                        (terpri)
                        (write-literal-string "***** READMACRO FAILED")))
                  (t (progn
                        (&pp-putblank)
                        (dolist (c (%explodecn "<<READMACRO FAILED>>"))
                           (&pp-putch nil c))
                        (&pp-putblank))))
               (setq *rdr-readerrors*
                  (cons (cons u *emsg*) *rdr-readerrors*))
               (return nil)))
         (t (return (car u)))) ))

(defun &pp-read nil
   (prog (l)
loop  (setq l (&pp-finish-token (&pp-peek-token)))
      (cond
         ((equal *token-type* 'break-character)
            (progn
               (setq l (&pp-read-macro-expand l))
               (cond ((atom l) (go loop)) (t (return (car l)))) )))
      (return l)))

(defun &pp-read-macro-expand (l)
   (prog (fn fn1)
      (cond
         ((setq fn (get l (svref syntax-table $readmacro)))
            (progn
               (cond
                  ((setq fn1
                      (get l (svref syntax-table $preadmacro)))
                     (progn
                        (setq *pp-no-blank-flag* t)
                        (setq l (&call-read-macro fn1 l))
                        (setq *token-type* 'result-of-read-macro)
                        (return (list l)))) )
               (&pp-putch nil (char-code l))
               (setq *pp-no-blank-flag* t)
               (setq l (&call-read-macro fn l))
               (setq *token-type* 'result-of-read-macro)
               (return (list l))))
         ((setq fn (get l (svref syntax-table $splicemacro)))
            (progn
               (cond
                  ((setq fn1
                      (get l (svref syntax-table $psplicemacro)))
                     (progn
                        (setq *pp-no-blank-flag* t)
                        (setq l (&call-read-macro fn1 l))
                        (setq *rdr-stacked-tokens*
                           (append l *rdr-stacked-tokens*))
                        (return nil))))
               (&pp-putch nil (char-code l))
               (setq *pp-no-blank-flag* t)
               (setq l (&call-read-macro fn l))
               (setq *rdr-stacked-tokens*
                  (append l *rdr-stacked-tokens*))
               (return nil)))
         (t (progn (&pp-putch nil (char-code l)) (return (list l)))) )))

(defun &read-bracketed-list nil (&read-bracketed-list-1 nil))

(defun &read-superbracketed-list nil (&read-bracketed-list-1 t))

(defun &read-bracketed-list-1 (superparp)
   (prog (l item w fn)
loop  (setq item (read-token))
      (cond
         ((equal *token-type* 'break-character)
            (cond
               ((equal item lpar) (setq item (&read-bracketed-list)))
               ((or (equal item rpar) (equal item $eof$))
                  (progn (setq *eof-status* 0) (go unwind)))
               ((equal item '\})
                  (progn
                     (cond
                        ((not superparp)
                           (setq *rdr-stacked-tokens*
                              (cons
                                 'shadow-of-right-superpar
                                 *rdr-stacked-tokens*))))
                     (setq *eof-status* 0)
                     (go unwind)))
               ((equal item period)
                  (progn
                     (setq w (read))
                     (setq item (read-token))
                     (cond
                        ((and
                            (equal *token-type* 'break-character)
                            (equal item '\}))
                           (progn
                              (cond
                                 ((not superparp)
                                    (setq *rdr-stacked-tokens*
                                       (cons
                                          'shadow-of-right-superpar
                                          *rdr-stacked-tokens*)))) ))
                        ((not
                            (and
                               (equal *token-type* 'break-character)
                               (equal item rpar)))
                           (error "Bad syntax in dot notation")))
                     (go unwind)))
               ((setq fn (get item (svref syntax-table $readmacro)))
                  (setq item (&call-read-macro fn item)))
               ((setq fn
                   (get item (svref syntax-table $splicemacro)))
                  (progn
                     (setq item (&call-read-macro fn item))
                     (setq *rdr-stacked-tokens*
                        (append item *rdr-stacked-tokens*))
                     (go loop)))) ))
      (setq l (cons item l))
      (go loop)
unwind(while l
         (progn
            (setq item l)
            (setq l (cdr l))
            (rplacd item w)
            (setq w item)))
      (return w)))

(defun &pp-read-list nil (&pp-read-list-1 nil))

(defun &pp-read-superlist nil (&pp-read-list-1 t))

(defun &pp-read-list-1 (superparp)
   (prog (l item w cx)
      (setq *pp-stack*
         (cons (&pp-newframe *pp-indent-level*) *pp-stack*))
      (&pp-putch nil (cons 'lpar (&pp-top)))
      ((lambda (*pp-indent-level*)
          (prog nil
             (setq *pp-no-blank-flag* t)
       newstart
             (setq item (&pp-peek-token))
             (cond
                ((equal *token-type* 'break-character)
                   (cond
                      ((char= item #\lpar)
                         (setq item (&pp-read-list)))
                      ((or
                          (char= item #\rpar)
                          (char= item #\eof))
                         (progn
                            (setq *eof-status* 0)
                            (setq *pp-indent-level*
                               (+ *pp-indent-level* 2))
                            (go unwind)))
                      ((char= item #\})
                         (progn
                            (cond
                               ((not superparp)
                                  (setq *rdr-stacked-tokens*
                                     (cons
                                        'shadow-of-right-superpar
                                        *rdr-stacked-tokens*))))
                            (setq *eof-status* 0)
                            (setq *pp-indent-level*
                               (+ *pp-indent-level* 2))
                            (go unwind)))
                      (t (progn
                            (setq item
                               (&pp-read-macro-expand
                                  (&pp-finish-token item)))
                            (cond
                               ((atom item) (go newstart))
                               (t (setq item (car item)))) ))) )
                ((and
                    (equal *token-type* 'result-of-read-macro)
                    (equal item 'shadow-of-right-superpar))
                   (progn
                      (cond
                         (superparp
                            (setq *rdr-stacked-tokens*
                               (cdr *rdr-stacked-tokens*))))
                      (setq *eof-status* 0)
                      (setq *pp-indent-level*
                         (+ *pp-indent-level* 2))
                      (go unwind)))
                (t (setq item (&pp-finish-token item))))
             (setq *pp-indent-level* (+ *pp-indent-level* 2))
             (cond ((symbolp item) (setq cx (get item ':pp-format))))
             (setq l (list item))
             (setq *pp-no-blank-flag* nil)
       loop  (setq item (&pp-peek-token))
             (cond
                ((equal *token-type* 'break-character)
                   (cond
                      ((char= item #\lpar)
                         (progn
                            (setq cx (&pp-list-separation cx))
                            (setq item (&pp-read-list))))
                      ((char= item #\})
                         (progn
                            (cond
                               ((not superparp)
                                  (setq *rdr-stacked-tokens*
                                     (cons
                                        'shadow-of-right-superpar
                                        *rdr-stacked-tokens*))))
                            (setq *eof-status* 0)
                            (go unwind)))
                      ((or
                          (char= item #\rpar)
                          (char= item #\eof))
                         (progn (setq *eof-status* 0) (go unwind)))
                      ((char= item #\.)
                         (progn
                            (setq cx (&pp-list-separation cx))
                            (&pp-putch nil #\.)
                            (setq *pp-no-blank-flag* nil)
                            (setq w (read))
                            (setq item (&pp-peek-token))
                            (cond
                               ((and
                                   (equal *token-type* 'break-character)
                                   (char= item #\}))
                                  (progn
                                     (cond
                                        ((not superparp)
                                           (setq *rdr-stacked-tokens*
                                              (cons
                                              'shadow-of-right-superpar
                                           *rdr-stacked-tokens*)))) ))
                               ((and
                                   (equal
                                      *token-type*
                                      'result-of-read-macro)
                                   (equal
                                      item
                                      'shadow-of-right-superpar))
                                  (progn
                                     (cond
                                        (superparp
                                           (setq *rdr-stacked-tokens*
                                              (cdr
                                           *rdr-stacked-tokens*)))) ))
                               ((not
                                   (and
                                      (equal
                                         *token-type*
                                         'break-character)
                                      (char= item #\rpar)))
                                  (error "Bad syntax in dot notation")))
                            (go unwind)))
                      (t (progn
                            (setq cx (&pp-list-separation cx))
                            (setq item
                               (&pp-read-macro-expand
                                  (&pp-finish-token item)))
                            (cond
                               ((atom item) (go loop))
                               (t (setq item (car item)))) ))) )
                ((and
                    (equal *token-type* 'result-of-read-macro)
                    (equal item 'shadow-of-right-superpar))
                   (progn
                      (cond
                         (superparp
                            (setq *rdr-stacked-tokens*
                               (cdr *rdr-stacked-tokens*))))
                      (setq *eof-status* 0)
                      (go unwind)))
                ((equal *token-type* 'result-of-read-macro)
                   (setq item (&pp-finish-token item)))
                (t (progn
                      (setq cx (&pp-list-separation cx))
                      (setq item (&pp-finish-token item)))) )
             (setq l (cons item l))
             (go loop)
       unwind(&pp-putch nil
                (cons 'rpar (- *pp-indent-level* 6)))
             (cond
                ((and
                    (equal (&pp-indenting (&pp-top)) 'indent)
                    (not (null (&pp-blanklist (&pp-top)))) )
                   (&pp-overflow (car (&pp-blanklist (&pp-top)))) )
                (t (&pp-end-list (&pp-top))))
             (setq *pp-stack* (cdr *pp-stack*))
             (setq *pp-no-blank-flag* nil)
             (while l
                (progn
                   (setq item l)
                   (setq l (cdr l))
                   (rplacd item w)
                   (setq w item)))) )
         (1+ *pp-indent-level*))
      (return w)))

(defun &pp-list-separation (cx)
   (cond
      ((equal cx 'prog)
         (progn
            (cond
               ((equal *pp-no-blank-flag* nil)
                  (&pp-putch nil #\space)))
            (setq *pp-no-blank-flag* t)
            'prog1))
      ((equal cx 'prog1)
         (progn
            (cond
               ((not *pp-no-blank-flag*)
                  (progn
                     (&pp-putblank)
                     (&pp-overflow *pp-bufferi*))))
            (setq *pp-no-blank-flag* t)
            (cond
               ((equal *token-type* 'symbol)
                  (progn
                     (setq *pp-lmar*
                        (setq *pp-initialblanks*
                           (max (- *pp-lmar* 6) 0)))
                     'prog2))
               (t cx))))
      ((equal cx 'prog2)
         (cond
            ((equal *token-type* 'symbol)
               (&pp-list-separation 'prog1))
            (t (progn
                  (cond
                     ((>
                         (+ *pp-lmar* *pp-bn*)
                         (- *pp-indent-level* 3))
                        (progn
                           (cond
                              ((not *pp-no-blank-flag*)
                                 (progn
                                    (&pp-putblank)
                                    (&pp-overflow *pp-bufferi*)))) ))
                     (t (do ((i (+ *pp-lmar* *pp-bn*) (1+ i)))
                            ((> i (- *pp-indent-level* 4)))
                           (&pp-putch nil #\space))))
                  (setq *pp-no-blank-flag* t)
                  'prog1))))
      (*pp-no-blank-flag* cx)
      (t (progn
            (setq *pp-no-blank-flag* t)
            (cond
               ((numberp cx)
                  (progn
                     (&pp-putch nil #\space)
                     (cond ((= cx 1) nil) (t (1- cx)))) )
               (t (progn (&pp-putblank) cx)))) )))

(defun comment-read-macro-function nil
   (prog (ch)
l1    (setq ch (tyi))
      (cond
         ((or (char= ch #\newline) (char= ch #\eof))
            (progn (setq *pp-no-blank-flag* t) (return nil))))
      (go l1)))

(defun &mkstring1 (parts)
   (cond ((null parts) (%mkstring)) (t (%stringconcat parts (%mkstring)))) )

(defun string-read-macro-function nil
   (prog (ch counter parts)
      (%clearbuff)
      (setq counter 200)
l1    (setq ch (tyi))
      (cond
         ((char= ch #\")
            (progn
               (setq *pp-no-blank-flag* nil)
               (return (&mkstring1 parts))))
         ((char= ch #\eof)
            (progn
               (setq *eof-status* 0)
               (error "String terminated at EOF")
               (setq *pp-no-blank-flag* nil)
               (return (&mkstring1 parts)))) )
      (cond
         ((= (setq counter (1- counter)) 0)
            (progn
               (setq parts (&mkstring1 parts))
               (%clearbuff)
               (setq counter 199))))
      (%packbyte ch)
      (go l1)))

(defun quote-read-macro-function nil (list 'quote (read)))

(progn
   (setq syntax-table (mkvect $escapechar))
   (dotimes (i 257) (putv syntax-table i 0))
   (do ((i 258 (1+ i)))
       ((> i $psplicemacro))
      (putv syntax-table i (gensym))
   (&numeric-syntax-class "0123456789" 1)
   (&numeric-syntax-class "+-" 2)
   (&numeric-syntax-class "." 3)
   (&numeric-syntax-class "Ee" 4)
   (putv
      syntax-table
      $numbersyntax
      (let ((start (mkvect 4))
            (leadingsign (mkvect 4))
            (integerbody (mkvect 4))
            (decimal (mkvect 4))
            (exponentmark (mkvect 4))
            (signedexponent (mkvect 4))
            (exponentbody (mkvect 4))
            (exit 0)
            (dig 1)
            (sign 2)
            (dot 3)
            (e 4))
         (putv start dig integerbody)
         (putv start sign leadingsign)
         (putv start dot decimal)
         (putv leadingsign dig integerbody)
         (putv integerbody exit 'end)
         (putv integerbody dig integerbody)
         (putv integerbody dot decimal)
         (putv integerbody e exponentmark)
         (putv decimal exit 'end)
         (putv decimal dig decimal)
         (putv decimal e exponentmark)
         (putv exponentmark dig exponentbody)
         (putv exponentmark sign signedexponent)
         (putv signedexponent dig exponentbody)
         (putv exponentbody exit 'end)
         (putv exponentbody dig exponentbody)
         start))
   (setsyntax (list $eol$ $cr$ $ff$ blank tab) 'ignore t)
   (setsyntax (list $eol$ $ff$ blank tab $eof$) 'break-character t)
   (setsyntax "(.){}" 'break-character t)
   (setsyntax '\\ 'escape t)
   (setsyntax "0123456789" 'digit t)
   (setsyntax "+-." 'may-start-number t)
   (setsyntax "abcdefghijklmnopqrstuvwxyz" 'lower-case t)
   (setsyntax "ABCDEFGHIJKLMNOPQRSTUVWXYZ" 'upper-case t)
   (setsyntax "abcdefghijklmnopqrstuvwxyz" 'letter t)
   (setsyntax "ABCDEFGHIJKLMNOPQRSTUVWXYZ" 'letter t)
   (setsyntax lpar 'read-macro '&read-bracketed-list)
   (setsyntax '\{ 'read-macro '&read-superbracketed-list)
   (setsyntax '\' 'read-macro 'quote-read-macro-function)
   (setsyntax '\; 'splice-macro 'comment-read-macro-function)
   (setsyntax '\" 'read-macro 'string-read-macro-function)
   (put lpar (svref syntax-table $preadmacro) '&pp-read-list)
   (put '\{ (svref syntax-table $preadmacro) '&pp-read-superlist)
   'tables-set-up)

(defun readch nil
   (let (ch)
      (cond
         ((not (= *eof-status* 0))
            (error "Attempt to read character past EOF")))
      (setq ch (tyi))
      (cond ((char= ch #\eof) (setq *eof-status* 'readch)))
      (&case-adjust ch)
      (character ch)))

(defun &unquote-constructor (x)
   (cond
      ((atom x)
         (cond
            ((or (null x) (numberp x) (stringp x) (equal x t)) x)
            (t (mkquote x))))
      ((equal (car x) '\,-marker) (cadr x))
      ((or (equal (car x) '\,@-marker) (equal (car x) '\,\.-marker))
         (error "Illegal use of ,@ marker"))
      ((eqcar (car x) '\,@-marker)
         (list 'append (cadar x) (&unquote-constructor (cdr x))))
      ((eqcar (car x) '\,\.-marker)
         (list 'nconc (cadar x) (&unquote-constructor (cdr x))))
      ((&contains-no-\, x) (mkquote x))
      (t (list
            'cons
            (&unquote-constructor (car x))
            (&unquote-constructor (cdr x)))) ))

(defun &contains-no-\, (x)
   (cond
      ((atom x) t)
      ((or
          (equal (car x) '\,-marker)
          (equal (car x) '\,@-marker)
          (equal (car x) '\,\.-marker))
         nil)
      (t (and (&contains-no-\, (car x)) (&contains-no-\, (cdr x)))) ))

(defun &backquote-read-macro-function nil (&unquote-constructor (read)))

(defun &comma-read-macro-function nil
   (cond
      ((char= (tyipeek) #\@)
         (progn (tyi) (list '\,@-marker (read))))
      ((char= (tyipeek) #\.)
         (progn (tyi) (list '\,\.-marker (read))))
      (t (list '\,-marker (read)))) )

(setsyntax "`" 'read-macro '&backquote-read-macro-function)

(setsyntax "," 'read-macro '&comma-read-macro-function)

(defconstant tab-internal-code 9)
(defconstant newline-internal-code 10)
(defconstant formfeed-internal-code 12)
(defconstant space-internal-code 32)
(defconstant lpar-internal-code (char-code '\())
(defconstant rpar-internal-code (char-code '\)))

(defun sharp-readmacro-function ()
   (let ((ch (tyipeek)) ch1)
      (cond
         ((eq ch quote-internal-code)
             (tyi)
             (list 'function (read)))
         ((eq ch (char-code '\\))
         ;; the treatment of #\ is slightly odd - if the following character
         ;; is a letter a symbol is read.
             (tyi)
             (setq ch1 (tyipeek))
             (if (syntaxbitp ch1 letter)
                 (setq ch (read))
                 (setq ch nil ch1 (tyi) pp-no-blank-flag nil))
             (cond ((eq ch 'space) space-internal-code)
                   ((eq ch 'newline) newline-internal-code)
                   ((eq ch 'form) formfeed-internal-code)
                   ((eq ch 'tab) tab-internal-code)
                   ((eq ch 'lpar) lpar-internal-code)
                   ((eq ch 'rpar) rpar-internal-code)
                   ((eq ch 'eof) -1)
                   (t ch1)))
         ((eq ch lpar-internal-code)
             (list-to-vector (read)))
         (t (error (format nil "Unknown # readmacro option ~S~%" (character ch)))))))

(setsyntax '\# 'macro 'sharp-readmacro-function)

(proclaim '(special *rdr-pseudo-file*))

(defun *rdr-tyi-pseudo-file* nil
   (cond
      ((atom *rdr-pseudo-file*) #\eof)
      (t (let (u)
            (cond
               ((not (numberp (car *rdr-pseudo-file*)))
                  (setq *rdr-pseudo-file*
                     (append
                        (%explodecn (car *rdr-pseudo-file*))
                        (cdr *rdr-pseudo-file*)))) )
            (setq u (car *rdr-pseudo-file*))
            (setq *rdr-pseudo-file* (cdr *rdr-pseudo-file*))
            u))) )

(defun *rdr-tyipeek-pseudo-file* nil
   (cond
      ((atom *rdr-pseudo-file*) #\eof)
      (t    (cond
               ((not (numberp (car *rdr-pseudo-file*)))
                  (setq *rdr-pseudo-file*
                     (append
                        (%explodecn (car *rdr-pseudo-file*))
                        (cdr *rdr-pseudo-file*)))) )
            (car *rdr-pseudo-file*))) ))

(proclaim '(special *rdr-tyi-pseudo-file* *rdr-tyipeek-pseudo-file*))

(defun compress (*rdr-pseudo-file*)
   (prog (*rdr-readerrors*
         *echo*
         *rdr-inside-pretty-read*
         *rdr-stacked-tokens*
         *token-type*
         *eof-status*
         tyi
         tyipeek
         v)
      (setq tyi *rdr-tyi-pseudo-file*)
      (setq tyipeek *rdr-tyipeek-pseudo-file*)
      (setq *eof-status* 0)
      (setq v (%errorset '(read) nil nil))
      (cond
         ((atom v) (error (format nil "compress ~S ~S" *emsg* *rdr-readerrors*)))
         ((not (atom *rdr-pseudo-file*))
            (error (format nil "compress had ~S left over" *rdr-pseudo-file*))))
      (return (car v))))

(defvar *prarg* 0 "Input echo")

(defvar *prval* 1 "Display results")

(defvar *prmsg* 1 "Print prompts")

(defun prarg (n)
   (let ((old *prarg*))
      (setq *prarg*
         (cond
            ((numberp n) n)
            ((equal n nil) 0)
            ((equal n 'pretty) 2)
            ((equal n 'expanded) 3)
            (t 1)))
      old))

(defun prval (n)
   (let ((old *prval*))
      (setq *prval*
         (cond
            ((numberp n) n)
            ((equal n nil) 0)
            ((equal n 'pretty) 2)
            (t 1)))
      old))

(defun prmsg (n)
   (let ((old *prmsg*))
      (setq *prmsg* (cond ((numberp n) n) ((equal n nil) 0) (t 1)))
      old))

(proclaim '(special *backgag*))

(setq *backgag* 5)

(defun backgag (n)
   (let ((old *backgag*))
      (setbtr
         (setq *backgag*
            (cond
               ((numberp n) n)
               ((equal n nil) 0)
               ((equal n 'header) 1)
               ((equal n 'brief) 2)
               ((equal n 'pretty) 6)
               ((equal n 'loop) 7)
               (t 5))))
      old))

(defun supervisor nil
   (let ((u nil))
      (princ "*** Codemist Common Lisp Image loaded ***")
      (terpri)
      (while (atom u) (setq u (%errorset '(&supervisor) nil nil)))
      (car u)))

;; (proclaim '(special - + ++ +++ * ** ***))

(defun &supervisor nil
   (prog (u v *rdr-readerrors* error-count)
loop  (cond
         ((and
             (> *prmsg* 0)
             (> *prarg* 0)
             (> *prval* 0))
            (terpri)))
      (cond
         ((and (> *prmsg* 0) (> *prarg* 0))
            (fresh-line)
            (princ "Input:")))
      (setq *rdr-readerrors* nil)
      (setq v *echo*)
      (cond
         ((= *prarg* 3) (setq *echo* nil))
         ((= *prarg* 2) (setq *echo* 'pretty))
         ((= *prarg* 0) (setq *echo* nil))
         (t (setq *echo* t)))
      (setq *eof-status* 0)
      (setq u (%errorset '(read) t nil))
      (setq *echo* v)
      (cond
         (*rdr-readerrors*
            (progn
               (terpri)
               (dolist (x *rdr-readerrors*)
                  (format t "***** Error code ~S  ~S~%" (car x) (cdr x)))
               (setq *rdr-readerrors* nil))))
      (cond ((atom u) (go loop)))
      (setq u (car u))
      (cond
         ((equal u $eof$)
            (progn
               (format t "~%*** End of file detected~%")
               (setq *eof-status* 0)
               (return nil)))
         ((equal u 'fin) (return nil)))
;;      (setq +++ ++)
;;      (setq ++ +)
;;      (setq + -)
;;      (setq - u)
      (cond
         ((and
             (> *prmsg* 0)
             (or (> *prarg* 0) (> *prval* 0)))
            (terpri)))
      (cond ((= *prarg* 3) (pprint u)))
      (setq u (%errorset u *backgag* *backgag*))
      (cond
         ((atom u) (terpri))
         (t (progn
;;               (setq *** **)
;;               (setq ** *)
;;               (setq *
                    (setq u (car u))
;;                                   )
               (cond
                  ((> *prval* 0)
                     (progn
                        (fresh-line)
                        (cond
                           ((> *prmsg* 0)
                                 (princ "Value: ")))
                        (cond
                           ((= *prval* 2)
                              (%errorset
                                 (list 'pprint (list 'quote u))
                                 *backgag*
                                 *backgag*))
                           (t (%errorset
                                 (list 'prin1 (list 'quote u))
                                 *backgag*
                                 *backgag*)))
                        (terpri)))))))
      (go loop)))

(proclaim '(special stop))

(defun rdf (infile outfile)
   (let ((inf (open infile :direction :input))
         outf oldi oldo (stop (function (lambda () (throw '&stop 'stop)))))
      (cond ((not (equal outfile nil))
              (setq outf (open outfile :direction :output))))
      (setq oldi (rds inf))
      (setq oldo (wrs outf))
      (catch '&stop (supervisor))
      (fresh-line)
      (princ "*** End of RDF")
      (terpri)
      (cond ((not (equal inf oldi)) (%close inf)))
      (cond ((not (equal outf oldo)) (%close outf)))
      (rds oldi)
      (wrs oldo)
      nil))

(proclaim '(special *rdr-genuine-tyi* *rdr-genuine-tyipeek*))

(setq *rdr-genuine-tyi* tyi *rdr-genuine-tyipeek* tyipeek)

(defun break-loop-function nil
   (prog (*rdr-stacked-tokens*
         *token-type*
         *eof-status*
         *rdr-inside-pretty-read*
;;; Note the exploitation of special bindings on functions here.... Yuk!
         *pp-no-blank-flag* tyi tyipeek *rdr-readerrors* *echo*
         *pp-buffer* msg msg1 k)
      (setq tyi *rdr-genuine-tyi*)
      (setq tyipeek *rdr-genuine-tyipeek*)
      (setq *pp-no-blank-flag* t)
      (setq *eof-status* 0)
      (setq *pp-buffer* (mkvect 255))
top   (cond ((not msg) (princ "Lisp break> ")))
      (setq k (tyipeek))
      (cond
         ((syntaxbitp k upper-case)
            (setq k (char-downcase k))))
      (setq msg nil)
      (cond
         ((char= k #\lpar) (setq k '\.))
         (t (progn (tyi) (setq k (character k)))) )
      (cond
         ((equal k '\.)
            (progn
               (setq k (%errorset '(read) 1 0))
               (cond
                  ((not (atom k))
                     (progn
                        (setq k (%errorset (car k) 1 0))
                        (cond
                           ((not (atom k))
                              (progn
                                 (fresh-line)
                                 (princ "=> ")
                                 (%errorset
                                    (list 'prin1 (mkquote (car k)))
                                    1
                                    0)
                                 (terpri)))) ))) ))
         ((equal k 'q) (progn (setbtr 0) (error 'quit)))
         ((equal k 'a) (return nil))
         ((equal k 'c) (progn (terpri) (return t)))
         ((equal k blank) (setq msg t))
         ((or (not msg1) (not (equal k $eol$)))
            (progn
               (setq msg1 t)
               (fresh-line)
               (princ
               "Q to quit, A to abort, C to continue, or . <expression>")
               (terpri))))
      (go top)))

(proclaim '(special break-loop))

(setq break-loop 'break-loop-function)

(defun embed (name newdef)
   (let ((u (gts name)))
      (while (eqcar u 'trace:) (setq u (cdr u)))
      (cond ((eqcar u 'fasl) (progn (eval u) (setq u (gts name)))) )
      (put name ':stackeddef (cons u (get name ':stackeddef)))
      (setq u (subst u name newdef))
      (set name u)
      (list name 'embedded)))

(defun unembed (name)
   (let ((u (get name ':stackeddef)))
      (cond ((null u) (&cmperr (list name "NOT EMBEDDED"))))
      (set name (car u))
      (setq u (cdr u))
      (cond
         ((null u) (remprop name ':stackeddef))
         (t (put name ':stackeddef u)))
      (list name 'unembedded)))



