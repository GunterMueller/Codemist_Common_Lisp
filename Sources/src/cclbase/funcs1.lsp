
;;; Functions that are defined as soon as the real versions of DEFUN and
;;; DEFMACRO are in place

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


(defun putd (a type b)
  (progn
     (cond
	((eqcar b 'funarg) (setq b (cons 'lambda (cddr b)))))
     (cond
	((getd a) (progn
	   (terpri) (princ "+++ ") (prin a) (princ " redefined") (terpri))))
     (cond
	((eq type 'expr) (symbol-set-definition a b))
	((and (eq type 'macro) (eqcar b 'lambda))
            (eval (list* 'defmacro a (cons '&whole (cadr b)) (cddr b))))
        (t (error (format nil "Bad type ~S in putd" type))))
     a))

(defun putc (a b c)
   (put a b c))

(defun s::oblist0 (v r)
   (prog (n a)
      (setq n (sub1 (length v)))
top   (cond ((minusp n) (return r)))
      (setq a (getv v n))
      (cond
	 ((and (symbolp a)
; I list things that have a function value of some sort or that have
; a non-empty property-list.  Symbols that have been mentioned but which do
; not have properties or values are missed out since they are dull and
; seeing them listed is probably not very helpful.  People may disagree
; about that... if so it would be very easy to remove the tests here and
; end up listing everything
	       (or (symbol-function a)
		   (macro-function a)
		   (special-form-p a)
		   (fluidp a)
		   (globalp a)
		   (not (null (plist a)))))
	  (setq r (cons a r))))
      (setq n (sub1 n))
      (go top)))

(defun s::oblist1 (v r)
   (cond
      ((null v) r)
      ((simple-vector-p v) (s::oblist0 v r))
; This allows for segmented object-vectors
      (t (s::oblist0 (car v) (s::oblist1 (cdr v) r)))))

(defun oblist ()
   (sort (s::oblist1 (getv *package* 1)
            (s::oblist1 (getv *package* 5) nil))
	 (function orderp)))

(defmacro return (&optional u)
   `(return-from nil ,u))

(defmacro locally (&rest x)
   `(let () ,@x))

(defun remove (a b)
   ;; Full version has many keywords & possibly different default :test
   (cond
      ((endp b) nil)
      ((equal a (car b)) (cdr b))
      (t (cons (car b) (remove a (cdr b)))) ))

(defun butlast (l &optional (n 1))
  (let ((r (reverse l)))
    (dotimes (i n) (setq r (if (null r) nil (cdr r))))
    (nreverse r)))

(defun setdiff (u v)
   (if (endp v)
       u
       (setdiff (remove (car v) u) (cdr v))))

(defun xn (a b)
   (cond
      ((null a) nil)
      ((member** (car a) b) (cons (car a) (xn (cdr a) (remove (car a) b))))
      (t (xn (cdr a) b))))

(defun deleq (u v)
   (cond
      ((null v) nil)
      ((eq u (car v)) (cdr v))
      (t (cons (car v) (deleq u (cdr v)))) ))

(defmacro loop (&rest u)
   (let ((lab (gensym)))
      `(block nil
         (tagbody
     ,lab   (progn ,@u)   ;; progn is so that atoms are not labels
            (go ,lab)))))

(defmacro dolist (&rest u)
   (let ((g (gensym)))
      `(do ((,g
             ,(cadr (car u))
             (cdr ,g)))
            ((endp ,g) ,@(cddr (car u)))
            (let ((,(car (car u)) (car ,g)))
               ,@(cdr u)))))

(defmacro dotimes (&rest u)
   `(do ((,(car (car u))
          0
          (\1+ ,(car (car u)))))
         ((>= ,(car (car u)) ,(cadr (car u))) ,@(cddr (car u)))
         ,@(cdr u)))

(defmacro while (&rest u)
   `(loop
      (if (not ,(car u)) (return nil))
      ,@(cdr u)))

(defun endp-test-list (l)
   (if (endp l)
       nil
       (cons `(endp ,(car l)) (endp-test-list (cdr l)))))

(defun map-expander (fnargs carp op)
   (let (fn args vars avars moveon w
         (l1 (gensym)) (l2 (gensym)) (r (gensym))
         (s (gensym)) (hold (gensym))
         notandvars (funcall-needed t))
      (if (endp fnargs) (error "Bad arguments to map function"))
      (setq fn (car fnargs))
;; If I go (mapxx (function aaa) ...) or (mapxx (quote aaa) ...) I will
;; optimise the function call a bit, where aaa is either a symbol or a lambda-
;; expression.
      (when (and (or (eqcar fn 'function)
                     (eqcar fn 'quote))
                 (or (symbolp (cadr fn))
                     (eqcar (cadr fn) 'lambda)))
            (setq fn (cadr fn) funcall-needed nil))
      (setq w (setq args (cdr fnargs)))
      (do ()
          ((null w))
          (setq vars (cons (gensym) vars))
          (setq w (cdr w)))
      (setq avars vars)
      (if carp
          (progn
            (do ()
                ((null avars))
                (setq w (cons (list 'car (car avars)) w))
                (setq avars (cdr avars)))
            (setq avars (reverse w))))
      (setq fn (cons fn avars))
      (when funcall-needed (setq fn (cons 'funcall fn)))
      (setq w vars)
      (do ()
          ((null w))
          (setq moveon
             (cons (list 'setq (car w) (list 'cdr (car w))) moveon))
          (setq w (cdr w)))
      (setq notandvars (if (endp vars)
                           ''t
                           (if (endp (cdr vars))
                               `(endp ,(car vars))
                               (cons 'or (endp-test-list vars)))))
      (cond
         ((equal op nil)
            `((lambda ,vars
                 (let (,hold) (block nil
                    (tagbody
                       (setq ,hold ,(car vars))
                ,l1    (if ,notandvars
                           (return ,hold))
                       ,fn
                       ,@moveon
                       (go ,l1)))))
                ,@args))
         ((equal op 'cons)
            `((lambda ,vars
                 (let (,r) (block nil
                    (tagbody
                ,l1    (if ,notandvars
                           (return (nreverse ,r)))
                       (setq ,r (cons ,fn ,r))
                       ,@moveon
                       (go ,l1)))))
                ,@args))
         ((equal op 'nconc)
            `((lambda ,vars
                 (let (,r ,s) (block nil
                    (tagbody
                       (setq ,r (setq ,s (list nil)))
                ,l1    (if ,notandvars
                           (return (cdr ,r)))
                       (rplacd ,s ,fn)
                ,l2    (cond
                          ((not (endp (cdr ,s)))
                             (setq ,s (cdr ,s))
                             (go ,l2)))
                       ,@moveon
                       (go ,l1)))))
                ,@args))
         (t (error "Bad call to map function expander")))))

(defmacro mapl (&rest l) (map-expander l nil nil))

(defmacro mapc (&rest l) (map-expander l t nil))

(defmacro maplist (&rest l) (map-expander l nil 'cons))

(defmacro mapcar (&rest l) (map-expander l t 'cons))

(defmacro mapcon (&rest l) (map-expander l nil 'nconc))

(defmacro mapcan (&rest l) (map-expander l t 'nconc))

(defmacro defvar (name &optional (value nil valp) (documentation nil docp))
    `(progn (eval-when (compile load eval) (make-special ',name))
            ,@(if valp `((unless (boundp ',name) (setq ,name ,value))) nil)
            ,@(if docp `((put ',name :documentation ,documentation)) nil)
            ',name))

(defmacro defparameter (name value &optional (documentation nil docp))
    `(progn (eval-when (compile load eval) (make-special ',name))
            (setq ,name ,value)
            ,@(if docp `((put ',name :documentation ,documentation)) nil)
            ',name))

(defmacro defconstant (name value &optional (documentation nil docp))
    `(progn (eval-when (compile load eval) (make-special ',name))
            (setq ,name ,value)
            (put ',name :constant t)
            ,@(if docp `((put ',name :documentation ,documentation)) nil)
            ',name))

(defun %proclaim (decls)
;; The only things that proclaim pays attention to are (special ...)
;; declarations.
    (when (eqcar decls 'special)
        (dolist (v (cdr decls)) (make-special v)))
    decls)

;; The following behaviour is WRONG by CLTL-2, which would want proclaim
;; to be ignored while compiling and treated as a regular ordinary
;; function. That is why I print a verbose message in the dodgy case.

(defmacro proclaim (a)
   `(progn
       (eval-when (compile) 
             (terpri) (princ "+++++ ") (prin (list 'proclaim ',a))
             (princ " obeyed at compile time") (terpri)
             (%proclaim ,a))
       (eval-when (load eval) (%proclaim ,a))
    ))

(defvar *load-print* nil)
(defvar *load-verbose* t)

(defun load (x &key (verbose *load-verbose*) (print *load-print*)
                    (if-does-not-exist nil does-not-p))
   (let ((*readtable* *readtable*)
         (*package* *package*))
      (rdf x print verbose (or (null does-not-p) if-does-not-exist))))

(defconstant most-positive-fixnum  134217727 "#x07ffffff")
(defconstant most-negative-fixnum -134217728 "-#x08000000")

;; The following two constants are a bit of a bad joke! The size arrays I
;; support in CCL depend on the type of contents. For bit-vectors I can
;; probably handle around 2000000 bits. For characters around 256K chars.
;; For simple general vectors the limit is just under 64K, but make-array
;; will create larger such vectors as non-simple 1-D arrays and the limit
;; then is several million.

(defconstant array-dimension-limit  10000000)
(defconstant array-total-size-limit 10000000)

(defconstant multiple-values-limit 50)
(defconstant lambda-parameters-limit 50)
(defconstant call-arguments-limit 50)
(defconstant lambda-list-keywords '(&optional &rest &key &allow-other-keys
                                    &aux &body &whole &environment))

(defconstant char-code-limit 256)
(defconstant char-font-limit 256)
(defconstant char-bits-limit 16)
(defconstant char-control-bit 1)
(defconstant char-meta-bit    2)
(defconstant char-super-bit   4)
(defconstant char-hyper-bit   8)

(defconstant space-char   (special-char 0))
(defconstant newline-char (special-char 1))
(defconstant eof-char     (special-char 8))
(defconstant $eof$        (special-char 8))

(defun char-name (c)
   (cond
      ((char= c '#.(special-char 0)) "Space")
      ((char= c '#.(special-char 1)) "Newline")
      ((char= c '#.(special-char 2)) "Backspace")
      ((char= c '#.(special-char 3)) "Tab")
      ((char= c '#.(special-char 4)) "Linefeed")
      ((char= c '#.(special-char 5)) "Page")
      ((char= c '#.(special-char 6)) "Return")
      ((char= c '#.(special-char 7)) "Rubout")
      ((char= c '#.(special-char 8)) "EOF")
      ((graphic-char-p c) nil)
      ((not (string-char-p c)) nil)
      ;; Use a numeric name for all the things I do not otherwise
      ;; understand what to do with.  E.g. #\Char4
      (t (format nil "Char~A" (char-code c)))))

 (put :Space       :named-character '#.(special-char 0))
 (put :Newline     :named-character '#.(special-char 1))
 (put :Backspace   :named-character '#.(special-char 2))
 (put :Tab         :named-character '#.(special-char 3))
 (put :Linefeed    :named-character '#.(special-char 4))
 (put :Page        :named-character '#.(special-char 5))
 (put :Return      :named-character '#.(special-char 6))
 (put :Rubout      :named-character '#.(special-char 7))
 (put :EOF         :named-character '#.(special-char 8))


(defun standard-char-p (x)
   (and (characterp x)
        (= 0 (char-bits x) (char-font x))))

(defun string-char-p (x)
   (and (characterp x)
        (= 0 (char-bits x) (char-font x))))

(defun alphanumericp (x)
   (or (alpha-char-p x) (not (null (digit-char-p x)))))

(defun bit-of-bits-name (name)
   (cond
     ((eq name :control) 1)
     ((eq name :meta)    2)
     ((eq name :super)   4)
     ((eq name :hyper)   8)
     (t (error (format nil "Bad bit name for character function: ~S" name)))))

(defun char-bit (char name)
   (not (= 0 (logand (bit-of_bits-name name) (char-bits char)))))

(defun set-char-bit (char name newval)
   (let ((b (char-bits char))
         (f (char-font char))
         (x (bit-of-bits-name name)))
      (if newval (setq b (logior b x))
                 (setq b (logand b (lognot x))))
      (make-char char b f)))

;; (defun character (x)
;;    (cond
;;       ((characterp x) x)
;;       ((stringp x) (char x 0))
;;       ((numberp x) (int-char x))
;;       ((symbolp x) (char (symbol-name x) 0))
;;       (t (error "unable to coerce to a character"))))

;(defun identity (thing)
;   "Returns what was passed to it.  Default for :key options."
;   thing)

(defun member (a l &key (test #'eql) (test-not nil tnp) (key nil))
   (when (null key) (setq key #'identity))
   (loop
      (when (endp l) (return-from member nil))
      (when (if tnp (not (funcall test-not a (funcall key (car l))))
                    (funcall test a (funcall key (car l))))
            (return-from member l))
      (setq l (cdr l))))

(defun assoc (a l &key (test #'eql) (test-not nil tnp) (key nil))
; what an abominable way of making an important function run slowly!
   (when (null key) (setq key #'identity))
   (loop
      (when (endp l) (return-from assoc nil))
      (when (not (atom (car l)))
         (when (if tnp (not (funcall test-not a (funcall key (caar l))))
                       (funcall test a (funcall key (caar l))))
               (return-from assoc (car l))))
      (setq l (cdr l))))

(defun member-1 (a l test key)
  (cond
    ((null l) nil)
    ((funcall test a (funcall key (car l))) l)
    (t (member-1 a (cdr l) test key))))

(defun set-difference-1 (a b test key)
  (cond
    ((null a) a)
    ((member-1 (car a) b test key) (set-difference-1 (cdr a) b test key))
    (t (cons (car a) (set-difference-1 (cdr a) b test key)))))

(defun member-2 (a l test key)
  (cond
    ((null l) nil)
    ((not (funcall test a (funcall key (car l)))) l)
    (t (member-2 a (cdr l) test key))))

(defun set-difference-2 (a b test key)
  (cond
    ((null a) a)
    ((member-2 (car a) b test key) (set-difference-2 (cdr a) b test key))
    (t (cons (car a) (set-difference-2 (cdr a) b test key)))))

(defun set-difference (l1 l2 &key (test #'eql) (test-not nil tnp) (key nil))
   (when (null key) (setq key #'identity))
   (if tnp (set-difference-2 l1 l2 test key)
           (set-difference-1 l1 l2 test key)))

;(defun append-aux (a b)
;   (if (endp a)
;       b
;       (cons (car a) (append-aux (cdr a) b))))
;
;(defun append-lists (l)
;   (if (endp l)
;       nil
;       (if (endp (cdr l))
;           (car l)
;           (append-aux (car l) (append-lists (cdr l))))))
;
;(defun append (&rest a)
;   (append-lists a))

(defun values-list (l)
   (apply #'values l))

(defmacro multiple-value-list (u)
    `(multiple-value-call #'list ,u))

(defmacro multiple-value-setq (vars val)
   (if (endp vars)
       `(values ,val)
       (let ((w (gensym)))
          `(let ((,w (multiple-value-list ,val)))
               ,@(mapcar #'(lambda (v) (list 'setq v (list 'pop w))) vars)
               ,(car vars)))))

(defmacro multiple-value-bind (vars val &body body)
   (let ((w (gensym)))
      `(let* ((,w (multiple-value-list ,val))
              ,@(mapcar #'(lambda (v)
                             (list v
                                (list 'prog1 (list 'car w)
                                   (list 'setq w (list 'cdr w)))))
                        vars))
             ,@body)))

(defun rest    (x) (cdr x))
(defun first   (x) (car x))
(defun second  (x) (cadr x))
(defun third   (x) (caddr x))
(defun fourth  (x) (cadddr x))
(defun fifth   (x) (cadddr (cdr x)))
(defun sixth   (x) (cadddr (cddr x)))
(defun seventh (x) (cadddr (cdddr x)))
(defun eighth  (x) (cadddr (cddddr x)))
(defun ninth   (x) (cadddr (cddddr (cdr x))))
(defun tenth   (x) (cadddr (cddddr (cddr x))))

(defun list-length (l)
   (do ((i 0 (1+ i)))
       ((endp l) i)
       (setq l (cdr l))))

;; recursive definition
;;(defun nthcdr (n l)
;;   (if (= n 0) l
;;       (nthcdr (\1- n) (cdr l))))
(defun nthcdr (n x) (dotimes (i n) (setq x (cdr x))) x)


(defun $rplaca (a b) (rplaca a b) b)

(defun $rplacd (a b) (rplacd a b) b)

(defun set-documentation (a d) (put a :documentation d))

;; recursive definition
;;(defun setnth (n l v)
;;  (if (= n 0) ($rplaca l v) (setnth (\1- n) (cdr l) v)))

(defun setnth (n l c) 
  (if (< n 0)
  c
  (progn 
     (dotimes (i n) (setq l (cdr l))) 
     (if (endp l) c ($rplaca l c)))))

(defun case-expander (g body default-value)
   (if (null body)
       `((t ,@default-value))
       (if (member (caar body) '(t otherwise))
          (case-expander g (cdr body) (cdar body))
          (if (atom (caar body))
             `(((equal ,g ',(caar body)) ,@(cdar body))
                 ,@(case-expander g (cdr body) default-value))
             `(((member ,g ',(caar body)) ,@(cdar body))
                 ,@(case-expander g (cdr body) default-value))))))

(defmacro case (item &body body)
   (let ((g (gensym)))
     `(let ((,g ,item))
        (cond ,@(case-expander g body '(nil))))))

(defun make-list (n &key (initial-element nil))
   (make-list-1 n initial-element))

(defun make-list-1 (n x)
;; non recursive
    (let ((result nil))
         (dotimes (i n)  (setq result (cons x result)))
         result))

(defun copy-list (a)
;; this was the recursive definition
;;   (if (null a)
;;       nil
;;       (cons (car a) (copy-list (cdr a)))))
   (let ((result nil) (tail nil))
        (if (null a)
           nil
	   (progn 
              (setq result (cons (car a) ()))
              (setq a (cdr a))
              (setq tail result)
              (while a 
                     (rplacd tail (cons (car a) ()))
                     (setq a (cdr a))
                     (setq tail (cdr tail)))
              result))))


(defun copy-alist (a)
   (if (null a)
       nil
       (cons
          (if (consp (car a)) (cons (caar a) (cdar a)) (car a))
          (copy-alist (cdr a)))))

(defun copy-tree (a)
   (if (consp a)
       (cons (copy-tree (car a)) (copy-tree (cdr a)))
       a))

(defun type-of (x)
   (cond
      ((null x) 'null)
      ((integerp x) 'integer)
      ((floatp x) 'float)
      ((complexp x) 'complex)
      ((rationalp x) 'rational)
      ((numberp x) 'number)
      ((simple-string-p x) 'simple-string)
      ((simple-vector-p x) 'simple-vector)
      ((simple-bit-vector-p x) 'simple-bit-vector)
      ((structp x) (svref x 0))
      ((complex-arrayp x)
         (let ((tt (svref x 0))      ; element type
               (dd (svref x 1)))     ; list of dimensions
            (cond
               ((and (not (atom dd)) (atom (cdr dd)))
                  (cond
                     ((eq tt 'string-char) 'string)
                     ((eq tt 'bit) 'bit-vector)
                     (t (list 'vector tt))))
               (t (list 'array tt dd)))))
      ((symbolp x) 'symbol)
      ((consp x) 'cons)
      (t (error (format nil "Unknown object type to TYPE-OF ~S" x)))))

(defun typep (x type)
;; This looks a mess...
   (cond
      ((eq type t) t)
      ((null type) nil)
      ((eqcar type 'or) (typep1 x (cdr type)))
      ((simple-string-p x)
         (member type '(simple-string string simple-vector vector)))
      ((null x)
         (member type '(null list symbol)))
      ((symbolp x)
         (eq type 't))
      ((consp x)
         (member type '(list pair)))
      ((simple-vector-p x)
         (member type '(simple-vector vector)))
      ((integerp x)
         (member type '(integer number)))
      ((complexp x)
         (member type '(complex number)))
      ((rationalp x)
         (member type '(ratio rational number)))
      ((floatp x)
         (cond
            ((short-floatp x) (member type '(short-float float number)))
            ((single-floatp x) (member type '(single-float float number)))
            ((double-floatp x) (member type '(double-float float number)))
            (t (member type '(long-float float number)))))
      (t (error (format nil "Unknown object for typep ~S ~S~~" x type)))))

(defun typep1 (x l)
   (cond
      ((null l) nil)
      ((typep x (car l)) t)
      (t (typep1 x (cdr l)))))

(defun typecase-expander (g body default-value)
   (if (null body)
       `((t ,@default-value))
       (if (member (caar body) '(t otherwise))
          (typecase-expander g (cdr body) (cdar body))
          `(((typep ,g ',(caar body)) ,@(cdar body))
              ,@(typecase-expander g (cdr body) default-value))))))

(defmacro typecase (item &body body)
   (let ((g (gensym)))
     `(let ((,g ,item))
        (cond ,@(typecase-expander g body '(nil))))))

(defun make-hash-table (&key (test 'eql) (size 10)  (rehash-size 1.5)
                             (rehash-threshold nil))
   (let ((flavour))
     (cond
       ((or (eq test 'equalp) (equal test #'equalp)) (setq flavour 4))
       ((or (eq test 'equals) (equal test #'equals)) (setq flavour 3))
       ((or (eq test 'equal) (equal test #'equal)) (setq flavour 2))
       ((or (eq test 'eql) (equal test #'eql)) (setq flavour 1))
       ((or (eq test 'eq) (equal test #'eq)) (setq flavour 0))
       ((atom test) (error "bad :test arg to make-hash-table" test)))
;; Note that as extensions to Common Lisp I support a test "equals", and
;; also that if the test is specified as a pair of functions they are
;; used in a way where test = (cons #'sxhash #'equal) would be roughly
;; equivalent to test = 'equal.
     (mkhash size flavour rehash-size)))

;; with-hash-table-iterator

(defun hash-table-count (h) (getv h 1))

(defun hash-table-rehash-size (h) (getv h 2))

(defun hash-table-rehash-threshold (h) 0.6)

(defun hash-table-test (h)
   (let ((flavour (getv h 0)))
     (cond ((equal flavour 0) 'eq)
           ((equal flavour 1) 'eql)
           ((equal flavour 2) 'equal)
           ((equal flavour 3) 'equals)
           ((equal flavour 4) 'equalp)
           (t flavour))))

;;
;; These are unreasonably slow and will not deal with things other than
;; simple 1-dimensional bit-arrays.
;;

(defun bit-and (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logand (getv-bit v1 i) (getv-bit v2 i))))
   v3)

(defun bit-andc1 (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logand (lognot (getv-bit v1 i)) (getv-bit v2 i))))
   v3)

(defun bit-andc2 (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logand (getv-bit v1 i) (lognot (getv-bit v2 i)))))
   v3)

(defun bit-eqv (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logeqv (getv-bit v1 i) (getv-bit v2 i))))
   v3)

(defun bit-ior (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logior (getv-bit v1 i) (getv-bit v2 i))))
   v3)

(defun bit-nand (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (lognot (logand (getv-bit v1 i) (getv-bit v2 i)))))
   v3)

(defun bit-nor (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (lognot (logior (getv-bit v1 i) (getv-bit v2 i)))))
   v3)

(defun bit-not (v1 &optional (v2 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v2 i (lognot (getv-bit v1 i))))
   v2)

(defun bit-orc1 (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logior (lognot (getv-bit v1 i)) (getv-bit v2 i))))
   v3)

(defun bit-orc2 (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logior (getv-bit v1 i) (lognot (getv-bit v2 i)))))
   v3)

(defun bit-xor (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logxor (getv-bit v1 i) (getv-bit v2 i))))
   v3)

(defun fboundp (x) (not (null (getd x))))

(defmacro time (&rest x)
   `(let ((a (time*))
          (b (gctime)))
       (multiple-value-prog1
          (progn ,@x)
          (let ((a1 (time*))
                (b1 (gctime)))
;; The rules say that this should print to *trace-output* but I just print to
;; whatever stream is current. Tough luck for now!
             (terpri)
             (princ "Time: ") (princ (- a1 a))
             (princ " + ")
             (princ (- b1 b))
             (princ " milliseconds") (terpri)))))

;;
;;

(defun nth (n list) (car (nthcdr n list)))

(defun logbitp (index num)
  (> (logand num (ash 1 index)) 0))

(defun nreconc (x y) (nconc (nreverse x) y))

 ;;following needs to support keyword arg
(defun parse-integer (s &key junk-allowed) (read-from-string s))


;; missing common lisp version of nsubst

(defun nsubst (a b c)
   ;; Full version has many keyword arguments
   (cond
      ((eql c b) a)
      ((atom c) c)
      (t 
         (rplaca c (nsubst a b (car c)))
         (rplacd c (nsubst a b (cdr c)))
	 c) ))


; The full version of this would need :test, :test-not and :key args.
(defun adjoin (item list &key (test #'eql))
  (if (member item list :test test) list (cons item list)))

(defvar internal-time-units-per-second 1000)

(defun get-internal-run-time () (time*))

(defun get-universal-time () (+ 2208988800 (datestamp)))

(defun sort-2 (l pred) (stable-sortip (append l nil) pred)) ;; temporary

(defvar *compile-verbose* t)
(defvar *compile-print*   t)

(defun compile-file (file &key (output-file nil)
                     (verbose *compile-verbose*) (print *compile-print*))
   (s::compile-file* file output-file verbose print))

;; end of funcs1.lsp
