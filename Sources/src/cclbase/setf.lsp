
;;;; SETF and friends.

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


;;; Note: The expansions for SETF and friends sometimes create needless
;;; LET-bindings of argument values.  The compiler will remove most of
;;; these spurious bindings, so SETF doesn't worry too much about creating
;;; them.
;;; The inverse for a generalized-variable reference function is stored in
;;; one of two ways:
;;;
;;; A SETF-INVERSE property corresponds to the short form of DEFSETF.  It is
;;; the name of a function takes the same args as the reference form, plus a
;;; new-value arg at the end.
;;;
;;; A SETF-METHOD-EXPANDER property is created by the long form of DEFSETF or
;;; by DEFINE-SETF-METHOD.  It is a function that is called on the reference
;;; form and that produces five values: a list of temporary variables, a list
;;; of value forms, a list of the single store-value form, a storing
;;; function, and an accessing function.

;;; The following specials are used for communication during argument-list
;;; parsing for a macro or macro-like form.

(defvar ~arg-count)
(defvar ~min-args)
(defvar ~restp)
(defvar ~let-list)
(defvar ~keyword-tests)

(defvar *in-the-compiler* nil)

(defun get-setf-method (form)
   "Returns five values needed by the SETF machinery: a list of temporary
     variables, a list of values with which to fill them, the temporary for
     the new value in a list, the setting function, and the accessing
     function."
   (let
      (temp)
      (cond
         ((symbolp form)
            (let
               ((new-var (gensym)))
               (values nil nil (list new-var) `(setq ,form ,new-var) form)))
         ((atom form)
            (error (format nil "~S illegal atomic form for GET-SETF-METHOD." form)))
         ((setq temp (get (car form) 'setf-inverse))
            (let
               ((new-var (gensym)) (vars nil) (vals nil))
               (dolist (x (cdr form)) (push (gensym) vars) (push x vals))
               (setq vals (nreverse vals))
               (values vars vals (list new-var) `(,temp ,@vars ,new-var)
                  `(,(car form) ,@vars))))
         ((setq temp (get (car form) 'setf-method-expander))
            (funcall temp form))
         ((and (boundp '*in-the-compiler*) *in-the-compiler*)
            (if
;; Used to be compiler-macroexpand-1 on this line
               (eq (setq temp (macroexpand-1 form)) form)
               (error (format nil
                              "~S is not a known location specifier for SETF."
                              (car form)))
               (get-setf-method temp)))
         (t (if
               (eq (setq temp (macroexpand-1 form)) form)
               (error (format nil
                              "~S is not a known location specifier for SETF."
                              (car form)))
               (get-setf-method temp)))) ))


(defun get-setf-method-multiple-value (form)
   "Like Get-Setf-Method, but may return multiple new-value variables."
   (get-setf-method form))


(defmacro define-setf-method (access-fn lambda-list &body body)
   "Syntax like DEFMACRO, but creates a Setf-Method generator.  The body
     must be a form that returns the five magical values."
   (prog ((local-decs nil)
         (doc nil) (arg-test nil) (~arg-count 0) (~min-args 0) (~restp nil)
         (~let-list nil) (~keyword-tests nil))
      (cond
         ((not (symbolp access-fn))
            (error (format nil
            "~S -- Access-function name not a symbol in DEFINE-SETF-METHOD."
               access-fn))))
      ;; Check for local declarations and documentation string.
loop1 (cond
         ((atom body) (setq body '(nil)))
         ((and (not (atom (car body))) (eq (caar body) 'declare))
            (setq local-decs (append local-decs (cdar body)))
            (setq body (cdr body))
            (go loop1))
         ((and (stringp (car body)) (not (null (cdr body))))
            (setq doc (car body))
            (setq body (cdr body))
            (go loop1)))
      ;; Analyze the lambda list.
      (analyze1 lambda-list '(cdr ~lambda-list) access-fn '~lambda-list)
      (setq arg-test
         (cond
            ((and (zerop ~min-args) ~restp) nil)
            ((zerop ~min-args) `(> (length ~lambda-list) ,(1+ ~arg-count)))
            (~restp `(< (length ~lambda-list) ,(1+ ~min-args)))
            ((= ~min-args ~arg-count)
               `(not (= (length ~lambda-list) ,(1+ ~min-args))))
            (t `(or
                  (> (length ~lambda-list) ,(1+ ~arg-count))
                  (< (length ~lambda-list) ,(1+ ~min-args)))) ))
      ;; Now build the body of the macro.
      (when (null lambda-list) (push '(ignore ~lambda-list) local-decs))
      (setq body
         `(let*
            ,(nreverse ~let-list)
            ,@(and local-decs (list (cons 'declare local-decs)))
            ,@~keyword-tests
            ,@body))
      (and
         arg-test
         (setq body
            `(cond
               (,arg-test
                  (error (format nil
                     "Setf expander for ~S cannot be called with ~S args."
                     ',access-fn
                     (1- (length ~lambda-list)))))
               (t ,body))))
      (return
         `(eval-when
            (load compile eval)
            (remprop ',access-fn 'setf-inverse)
            (put
               ',access-fn
               'setf-method-expander
               #'(lambda (~lambda-list) ,body))
            ,@(if doc `((put ',access-fn :setf-documentation ',doc)))
            ',access-fn))))


(eval-when
   (compile load eval)
   (defun defsetter (fn rest)
      (let
         ((arglist (car rest))
            (new-var (car (cadr rest)))
            (body (cddr rest))
            (local-decs nil)
            (~arg-count 0)
            (~min-args 0)
            (~restp nil)
            (~let-list nil)
            (~keyword-tests nil))
         ;; Check for local declarations and documentation string.
         (tagbody
            loop2
            (cond
               ((atom body) (setq body '(nil)))
               ((and (not (atom (car body))) (eq (caar body) 'declare))
                  (setq local-decs (append local-decs (cdar body)))
                  (setq body (cdr body))
                  (go loop2))
               ((and (stringp (car body)) (not (null (cdr body))))
                  (setq body (cdr body))
                  (go loop2))))
         ;; Analyze the defmacro argument list.
         (analyze1 arglist '(cdr ~access-arglist) fn '~access-arglist)
         ;; Now build the body of the transform.
         (when (null arglist) (push '(ignore ~access-arglist) local-decs))
         (setq body
            `(let*
               ,(nreverse ~let-list)
               ,@(and local-decs (list (cons 'declare local-decs)))
               ,@~keyword-tests
               ,@body))
         `(lambda (~access-arglist ,new-var) ,body))))


; End of Eval-When.

(defmacro defsetf (access-fn &rest rest)
   "Associates a SETF update function or macro with the specified access
     function or macro.  The format is complex.  See the manual for
     details."
   (cond
      ((not (listp (car rest)))
         `(eval-when
            (load compile eval)
            (remprop ',access-fn 'setf-method-expander)
            ; SKH 4/17/84
            (put ',access-fn 'setf-inverse ',(car rest))
            ,@(if
               (and (car rest) (stringp (cadr rest)))
               `((eval-when
                   (load eval)
                   (put ',access-fn :setf-documentation ,(cadr rest)))) )
            ',access-fn))
      ((and (listp (car rest)) (cdr rest) (listp (cadr rest)))
         (if
            (not (= (length (cadr rest)) 1))
            (cerror
               "Ignore the extra items in the list."
               "Only one new-value variable allowed in DEFSETF."))
         (let*
            ((doc
                (do
                   ((x (cddr rest) (cdr x)))
                   ((or (atom x) (atom (cdr x))) nil)
                   (cond
                      ((stringp (car x)) (return (car x)))
                      ((and (listp (car x)) (eq (caar x) 'declaration)))
                      (t (return nil)))) )
               (setting-form-generator (defsetter access-fn rest)))
            `(eval-when
               (load compile eval)
               (remprop ',access-fn 'setf-inverse)
               ;SKH 4/17/84
               (put
                  ',access-fn
                  'setf-method-expander
                  #'(lambda (access-form)
                     (do*
                        ((args (cdr access-form) (cdr args))
                           (dummies nil (cons (gensym) dummies))
                           (newval-var (gensym))
                           (new-access-form nil))
                        ((atom args)
                           (setq new-access-form
                              (cons (car access-form) dummies))
                           (values
                              dummies
                              (cdr access-form)
                              (list newval-var)
                              (funcall
                                 (function ,setting-form-generator)
                                 new-access-form
                                 newval-var)
                              new-access-form)))) )
               ,@(if
                  doc
                  `((eval-when
                      (load eval)
                      (put ',access-fn :setf-documentation ',doc)))
                  `((eval-when
                      (load eval)
                      ;SKH 4/17/84
                      (remprop ',access-fn :setf-documentation))))
               ',access-fn)))
      (t (error (format nil "Ill-formed DEFSETF for ~S." access-fn)))))


(defmacro setf (&rest args)
   "Takes pairs of arguments like SETQ.  The first is a place and the second
     is the value that is supposed to go into that place.  Returns the last
     value.  The place argument may be any of the access forms for which SETF
     knows a corresponding setting form."
   (let
      ((temp (length args)))
      (cond
         ((= temp 2)
            (cond
               ((atom (car args)) `(setq ,(car args) ,(cadr args)))
               ((setq temp (get (caar args) 'setf-inverse))
                  `(,temp ,@(cdar args) ,(cadr args)))
               (t (multiple-value-bind
                     (dummies vals newval setter getter)
                     (get-setf-method (car args))
                     (declare (ignore getter))
                     (do*
                        ((d dummies (cdr d)) (v vals (cdr v)) (let-list nil))
                        ((null d)
                           (setq let-list
                              ;;; Next form munged and put back SKH 5/26
                              (nreverse
                                 (cons
                                    (list (car newval) (cadr args))
                                    let-list)))
                           `(let* ,let-list ,setter))
                        (setq let-list
                           (cons (list (car d) (car v)) let-list)))) )))
         ((oddp temp) (error "Odd number of args to SETF."))
         (t (do
               ((a args (cddr a)) (l nil))
               ((null a) `(progn ,@(nreverse l)))
               (setq l (cons (list 'setf (car a) (cadr a)) l)))) )))


(defmacro psetf (&rest args)
   "This is to SETF as PSETQ is to SETQ.  Args are alternating place
     expressions and values to go into those places.  All of the subforms and
     values are determined, left to right, and only then are the locations
     updated.  Returns NIL."
   (do
      ((a args (cddr a)) (let-list nil) (setf-list nil))
      ((atom a) `(let* ,(nreverse let-list) ,@(nreverse setf-list) nil))
      (if (atom (cdr a)) (error "Odd number of args to PSETF."))
      (multiple-value-bind
         (dummies vals newval setter getter)
         (get-setf-method (car a))
         (declare (ignore getter))
         (do*
            ((d dummies (cdr d)) (v vals (cdr v)))
            ((null d))
            (push (list (car d) (car v)) let-list))
         (push (list (car newval) (cadr a)) let-list)
         (push setter setf-list))))


(defmacro shiftf (&rest args)
   "One or more SETF-style place expressions, followed by a single
     value expression.  Evaluates all of the expressions in turn, then
     assigns the value of each expression to the place on its left,
     returning the value of the leftmost."
   (if (< (length args) 2) (error "Too few argument forms to a SHIFTF."))
   (let
      ((leftmost (gensym)))
      (do
         ((a args (cdr a))
            (let-list nil)
            (setf-list nil)
            (next-var leftmost))
         ((atom (cdr a))
            (push (list next-var (car a)) let-list)
            `(let* ,(nreverse let-list) ,@(nreverse setf-list) ,leftmost))
         (multiple-value-bind
            (dummies vals newval setter getter)
            (get-setf-method (car a))
            (do*
               ((d dummies (cdr d)) (v vals (cdr v)))
               ((null d))
               (push (list (car d) (car v)) let-list))
            (push (list next-var getter) let-list)
            (push setter setf-list)
            (setq next-var (car newval)))) ))


(defmacro rotatef (&rest args)
   "Takes any number of SETF-style place expressions.  Evaluates all of the
     expressions in turn, then assigns to each place the value of the form to
     its right.  The rightmost form gets the value of the leftmost.
     Returns NIL."
   (cond
      ((null args) nil)
      ((null (cdr args)) `(progn ,(car args) nil))
      (t (do
            ((a args (cdr a))
               (let-list nil)
               (setf-list nil)
               (next-var nil)
               (fix-me nil))
            ((atom a)
               (rplaca fix-me next-var)
               `(let* ,(nreverse let-list) ,@(nreverse setf-list) nil))
            (multiple-value-bind
               (dummies vals newval setter getter)
               (get-setf-method (car a))
               (do
                  ((d dummies (cdr d)) (v vals (cdr v)))
                  ((null d))
                  (push (list (car d) (car v)) let-list))
               (push (list next-var getter) let-list)
               ;; We don't know the newval variable for the last form yet,
               ;; so fake it for the first getter and fix it at the end.
               (unless fix-me (setq fix-me (car let-list)))
               (push setter setf-list)
               (setq next-var (car newval)))) )))


(defmacro define-modify-macro (name
      lambda-list
      function
      &optional
      doc-string)
   "Creates a new read-modify-write macro like PUSH or INCF."
   (let
      ((other-args nil) (rest-arg nil))
      ;; Parse out the variable names and rest arg from the lambda list.
      (do
         ((ll lambda-list (cdr ll)) (arg nil))
         ((null ll))
         (setq arg (car ll))
         (cond
            ((eq arg '&optional))
            ((eq arg '&rest)
               (if
                  (symbolp (cadr ll))
                  (setq rest-arg (cadr ll))
                  (error (format nil "Non-symbol &rest arg in definition of ~S." name)))
               (if
                  (null (cddr ll))
                  (return nil)
                  (error
                     "Illegal stuff after &rest arg in Define-Modify-Macro.")))
            ((memq arg '(&key &allow-other-keys &aux))
               (error (format nil
                            "~S not allowed in Define-Modify-Macro lambda list."
                            arg)))
            ((symbolp arg) (push arg other-args))
            ((and (listp arg) (symbolp (car arg)))
               (push (car arg) other-args))
            (t (error
                  "Illegal stuff in lambda list of Define-Modify-Macro."))))
      (setq other-args (nreverse other-args))
      `(defmacro ,name (~reference ,@lambda-list)
         ,doc-string
         (multiple-value-bind
            (dummies vals newval setter getter)
            (get-setf-method ~reference)
            (do
               ((d dummies (cdr d))
                  (v vals (cdr v))
                  (let-list nil (cons (list (car d) (car v)) let-list)))
               ((null d)
                  (push
                     (list
                        (car newval)
                        ,(if
                           rest-arg
                           `(list* ',function getter ,@other-args ,rest-arg)
                           `(list ',function getter ,@other-args)))
                     let-list)
                  `(let* ,(nreverse let-list) ,setter)))) )))


(defmacro push (obj place)
   "Takes an object and a location holding a list.  Conses the object onto
     the list, returning the modified list."
   (if
      (symbolp place)
      `(setq ,place (cons ,obj ,place))
      (multiple-value-bind
         (dummies vals newval setter getter)
         (get-setf-method place)
         (do*
            ((d dummies (cdr d)) (v vals (cdr v)) (let-list nil))
            ((null d)
               (push (list (car newval) `(cons ,obj ,getter)) let-list)
               `(let* ,(nreverse let-list) ,setter))
            (push (list (car d) (car v)) let-list)))) )


(defmacro pushnew (obj place &rest keys)
   "Takes an object and a location holding a list.  If the object is
     already in the list, does nothing. Else, conses the object onto the
     list. Returns NIL. If there is a :TEST keyword, this is used for the
     comparison."
   (if
      (symbolp place)
      `(setq ,place (adjoin ,obj ,place ,@keys))
      (multiple-value-bind
         (dummies vals newval setter getter)
         (get-setf-method place)
         (do*
            ((d dummies (cdr d)) (v vals (cdr v)) (let-list nil))
            ((null d)
               (push
                  (list (car newval) `(adjoin ,obj ,getter ,@keys))
                  let-list)
               `(let* ,(nreverse let-list) ,setter))
            (push (list (car d) (car v)) let-list)))) )


(defmacro pop (place)
   "The argument is a location holding a list.  Pops one item off the front
     of the list and returns it."
   (if
      (symbolp place)
      `(prog1 (car ,place) (setq ,place (cdr ,place)))
      (multiple-value-bind
         (dummies vals newval setter getter)
         (get-setf-method place)
         (do*
            ((d dummies (cdr d)) (v vals (cdr v)) (let-list nil))
            ((null d)
               (push (list (car newval) getter) let-list)
               `(let*
                  ,(nreverse let-list)
                  (prog1
                     (car ,(car newval))
                     (setq ,(car newval) (cdr ,(car newval)))
                     ,setter)))
            (push (list (car d) (car v)) let-list)))) )


(define-modify-macro
   incf
   (&optional (delta 1))
   +
   "The first argument is some location holding a number.  This number is
     incremented by the second argument, DELTA, which defaults to 1.")


(define-modify-macro
   decf
   (&optional (delta 1))
   -
   "The first argument is some location holding a number.  This number is
     decremented by the second argument, DELTA, which defaults to 1.")


;?  #|
;?  (defmacro putf (place indicator value)
;?    "Place may be any place expression acceptable to SETF, and is expected
;?    to hold a property list or ().  This list is destructively altered so
;?    that (GETF place indicator) will find the specified newvalue.  Returns
;?    the new value."
;?    (multiple-value-bind (dummies vals newval setter getter)
;?           (get-setf-method place)
;?      (do* ((d dummies (cdr d))
;?     (v vals (cdr v))
;?     (let-list nil)
;?     (ind-temp (gensym))
;?     (val-temp (gensym)))
;?    ((null d)
;?     (push (list (car newval) getter) let-list)
;?     (push (list ind-temp indicator) let-list)
;?     (push (list val-temp value) let-list)
;?     `(let* ,(nreverse let-list)
;?        (setq ,(car newval)
;?       (~primitive putf ,(car newval) ,ind-temp ,val-temp))
;?        ,setter
;?        ,val-temp))
;?        (push (list (car d) (car v)) let-list))))
;?  |#

(defmacro remf (place indicator)
   "Place may be any place expression acceptable to SETF, and is expected
     to hold a property list or ().  This list is destructively altered to
     remove the property specified by the indicator.  Returns T if such a
     property was present, NIL if not."
   (multiple-value-bind
      (dummies vals newval setter getter)
      (get-setf-method place)
      (do*
         ((d dummies (cdr d))
            (v vals (cdr v))
            (let-list nil)
            (ind-temp (gensym))
            (local1 (gensym))
            (local2 (gensym)))
         ((null d)
            (push (list (car newval) getter) let-list)
            (push (list ind-temp indicator) let-list)
            `(let*
               ,(nreverse let-list)
               (do
                  ((,local1 ,(car newval) (cddr ,local1))
                     (,local2 nil ,local1))
                  ((atom ,local1) nil)
                  (cond
                     ((atom (cdr ,local1))
                        (error "Odd-length property list in REMF."))
                     ((eq (car ,local1) ,ind-temp)
                        (cond
                           (,local2
                              (rplacd (cdr ,local2) (cddr ,local1))
                              (return t))
                           (t (setq ,(car newval) (cddr ,(car newval)))
                              ,setter
                              (return t)))) ))) )
         (push (list (car d) (car v)) let-list))))


;;; The built-in DEFSETFs.

(defsetf car $rplaca)
(defsetf cdr $rplacd)
(defsetf caar (x) (v) `($rplaca (car ,x) ,v))
(defsetf cadr (x) (v) `($rplaca (cdr ,x) ,v))
(defsetf cdar (x) (v) `($rplacd (car ,x) ,v))
(defsetf cddr (x) (v) `($rplacd (cdr ,x) ,v))
(defsetf caaar (x) (v) `($rplaca (caar ,x) ,v))
(defsetf cadar (x) (v) `($rplaca (cdar ,x) ,v))
(defsetf cdaar (x) (v) `($rplacd (caar ,x) ,v))
(defsetf cddar (x) (v) `($rplacd (cdar ,x) ,v))
(defsetf caadr (x) (v) `($rplaca (cadr ,x) ,v))
(defsetf caddr (x) (v) `($rplaca (cddr ,x) ,v))
(defsetf cdadr (x) (v) `($rplacd (cadr ,x) ,v))
(defsetf cdddr (x) (v) `($rplacd (cddr ,x) ,v))
(defsetf caaaar (x) (v) `($rplaca (caaar ,x) ,v))
(defsetf cadaar (x) (v) `($rplaca (cdaar ,x) ,v))
(defsetf cdaaar (x) (v) `($rplacd (caaar ,x) ,v))
(defsetf cddaar (x) (v) `($rplacd (cdaar ,x) ,v))
(defsetf caadar (x) (v) `($rplaca (cadar ,x) ,v))
(defsetf caddar (x) (v) `($rplaca (cddar ,x) ,v))
(defsetf cdadar (x) (v) `($rplacd (cadar ,x) ,v))
(defsetf cdddar (x) (v) `($rplacd (cddar ,x) ,v))
(defsetf caaadr (x) (v) `($rplaca (caadr ,x) ,v))
(defsetf cadadr (x) (v) `($rplaca (cdadr ,x) ,v))
(defsetf cdaadr (x) (v) `($rplacd (caadr ,x) ,v))
(defsetf cddadr (x) (v) `($rplacd (cdadr ,x) ,v))
(defsetf caaddr (x) (v) `($rplaca (caddr ,x) ,v))
(defsetf cadddr (x) (v) `($rplaca (cdddr ,x) ,v))
(defsetf cdaddr (x) (v) `($rplacd (caddr ,x) ,v))
(defsetf cddddr (x) (v) `($rplacd (cdddr ,x) ,v))
(defsetf first $rplaca)
(defsetf second (x) (v) `($rplaca (cdr ,x) ,v))
(defsetf third (x) (v) `($rplaca (cddr ,x) ,v))
(defsetf fourth (x) (v) `($rplaca (cdddr ,x) ,v))
(defsetf fifth (x) (v) `($rplaca (cddddr ,x) ,v))
(defsetf sixth (x) (v) `($rplaca (cdr (cddddr ,x)) ,v))
(defsetf seventh (x) (v) `($rplaca (cddr (cddddr ,x)) ,v))
(defsetf eighth (x) (v) `($rplaca (cdddr (cddddr ,x)) ,v))
(defsetf ninth (x) (v) `($rplaca (cddddr (cddddr ,x)) ,v))
(defsetf tenth (x) (v) `($rplaca (cdr (cddddr (cddddr ,x))) ,v))
(defsetf rest $rplacd)
(defsetf elt setelt)
(defsetf aref aset)
(defsetf char charset)
(defsetf bit bitset)
(defsetf sbit sbitset)
(defsetf symbol-value set)
(defsetf symbol-function symbol-set-definition)
(defsetf symbol-plist symbol-set-plist)
(defsetf symbol-env symbol-set-env)
(defsetf documentation set-documentation)
(defsetf nth setnth)
(defsetf svref putv)
(defsetf getv-bit putv-bit)
(defsetf schar putv-char)
(defsetf fill-pointer set-fill-pointer)

(define-setf-method
   getf
   (place prop &optional default)
   (multiple-value-bind
      (temps values stores set get)
      (get-setf-method place)
      (let
         ((newval (gensym)) (ptemp (gensym)))
         (values
            `(,@temps ,(car stores) ,ptemp ,@(cond (default)))
            `(,@values ,get ,prop ,@(cond (default)))
            `(,newval)
            `(progn
               (Setq ,(car stores)
                  (~~~~~primitive putf ,(car stores) ,ptemp ,newval))
               ,set
               ,newval)
            `(getf ,(car stores) ,ptemp ,@(cond (default)))) )))

(define-setf-method
   get
   (symbol prop &optional default)
   "Get turns into put. Don't put in the default unless it really is
    supplied and non-nil, so that we can transform into the get
    instruction whenever possible."
   (let
      ((symbol-temp (gensym))
         (prop-temp (gensym))
         (def-temp (gensym))
         (newval (gensym)))
      (values
         `(,symbol-temp ,prop-temp ,@(if default `(,def-temp)))
         `(,symbol ,prop ,@(if default `(,default)))
         (list newval)
         `(put ,symbol-temp ,prop-temp ,newval)
         `(get ,symbol-temp ,prop-temp ,@(if default `(,def-temp)))) ))

(defsetf
   macro-function
   (symbol)
   (def)
   `(put ',symbol 'cl-macro ',def))

(defsetf gethash (k h &optional default) (v) `(puthash ,k ,h ,v))

(defsetf
   subseq
   (sequence start &optional (end nil))
   (v)
   `(progn (replace ,sequence ,v :start1 ,start :end1 ,end) ,v))

;;; Evil hack invented by the gnomes of Vassar Street.  The function
;;; arg must be constant.  Get a setf method for this function, pretending
;;; that the final (list) arg to apply is just a normal arg.  If the
;;; setting and access forms produced in this way reference this arg at
;;; the end, then just splice the APPLY back onto the front and the right
;;; thing happens.
(define-setf-method
   apply
   (function &rest args)
   (if
      (and
         (listp function)
         (= (length function) 2)
         (eq (first function) 'function)
         (symbolp (second function)))
      (setq function (second function))
      (error
      "Setf of Apply is only defined for function args of form #'symbol."))
   (multiple-value-bind
      (dummies vals newval setter getter)
      (get-setf-method (cons function args))
      ;; Make sure the place is one that we can handle.
      (unless
         (and
            (eq (car (last args)) (car (last vals)))
            (eq (car (last getter)) (car (last dummies)))
            (eq (car (last setter)) (car (last dummies))))
         (error (format nil
                        "Apply of ~S not understood as a location for Setf."
                        function)))
      (values
         dummies
         vals
         newval
         `(apply (function ,(car setter)) ,@(cdr setter))
         `(apply (function ,(car getter)) ,@(cdr setter)))) )

(define-setf-method
   ldb
   (bytespec place)
   "The first argument is a byte specifier.  The second is any place form
     acceptable to SETF.  Replaces the specified byte of the number in this
     place with bits from the low-order end of the new value."
   (multiple-value-bind
      (dummies vals newval setter getter)
      (get-setf-method place)
      (let
         ((btemp (gensym)) (gnuval (gensym)))
         (values
            (cons btemp dummies)
            (cons bytespec vals)
            (list gnuval)
            `(let
               ((,(car newval) (dpb ,gnuval ,btemp ,getter)))
               ,setter
               ,gnuval)
            `(ldb ,btemp ,getter)))) )

(define-setf-method
   mask-field
   (bytespec place)
   "The first argument is a byte specifier.  The second is any place form
     acceptable to SETF.  Replaces the specified byte of the number in this
     place with bits from the corresponding position in the new value."
   (multiple-value-bind
      (dummies vals newval setter getter)
      (get-setf-method place)
      (let
         ((btemp (gensym)) (gnuval (gensym)))
         (values
            (cons btemp dummies)
            (cons bytespec vals)
            (list gnuval)
            `(let
               ((,(car newval) (deposit-field ,gnuval ,btemp ,getter)))
               ,setter
               ,gnuval)
            `(mask-field ,btemp ,getter)))) )

(define-setf-method
   char-bit
   (place bit-name)
   "The first argument is any place form acceptable to SETF.  Replaces the
     specified bit of the character in this place with the new value."
   (multiple-value-bind
      (dummies vals newval setter getter)
      (get-setf-method place)
      (let
         ((btemp (gensym)) (gnuval (gensym)))
         (values
            `(,@dummies ,btemp)
            `(,@vals ,bit-name)
            (list gnuval)
            `(let
               ((,(car newval) (set-char-bit ,getter ,btemp ,gnuval)))
               ,setter
               ,gnuval)
            `(char-bit ,getter ,btemp)))) )

(define-setf-method
   the
   (type place)
   (multiple-value-bind
      (dummies vals newval setter getter)
      (get-setf-method place)
      (values
         dummies
         vals
         newval
         (subst `(the ,type ,(car newval)) (car newval) setter)
         `(the ,type ,getter))))



