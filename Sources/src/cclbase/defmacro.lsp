
;;;; DEFMACRO

;;; This code comes from the Spice Lisp project, where the relevant
;;; source code was marked as having been placed in the public domain.
;;; Adjustments have been made to fit in with the needs of Codemist
;;; Common Lisp, and the adjustments are Copyright (C) Codemist Ltd, 1989-94.
;;; To the Spice Lisp people:  "Thank you very much".

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


;; The next line enables recording of what keyword-driven functions are most
;; commonly used. NB the PUSH macro is not yet available at this stage in the
;; bootstrap process. Uncomment the line and then at the end of a run
;; call (display-keywords) to print and reset statistics on keyword use.

;---- (setq *features* (cons :report-keywords *features*))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; fully-macroexpand can be used to expand a form and all sub-forms. At one
;; stage I always did this for interpreted code, but now I expect almost all
;; code to be compiled so I prefer not to expand other than during compilation

(defun fully-macroexpand (a env)
; macroexpand a form and all of its subforms
   (setq a (macroexpand a env))
   (if (atom a) a
     (let ((fn (car a)))
        (if (symbolp fn)
            (let ((helper (get fn 'fully-macroexpand)))
               (if helper
                   (funcall helper a env)
                   (cons fn (fully-macroexpand-list (cdr a) env))))
            (fully-macroexpand-list a env)))))

(defun fully-macroexpand-list (l env)
; expand a list of forms
   (do ((r nil))
       ((null l) (nreverse r))
       (push (fully-macroexpand (pop l) env) r)))

(defun fully-macroexpand-letvars (l env)
; expand a list of atoms or lists of forms (as for the decls in (let ...))
   (do ((r nil))
       ((null l) (nreverse r))
       (let ((w (pop l)))
          (if (atom w)
              (push w r)
              (push (fully-macroexpand-list w env) r)))))

(defun fully-macroexpand-fletvars (l env)
; expand a list of (name bvl body...) structures
   (do ((r nil))
       ((null l) (nreverse r))
       (let ((w (pop l)))
          (push (list* (car w) (cadr w) (fully-macroexpand-list (cddr w) env)) r))))

(defun fully-macroexpand-tagged (l env)
; Used for macroexpansion of things of the form (fn xx ...) where
; xx is left unexpanded, but the following body must be expanded
; e.g. (eval-when ...), (the ...)
    (list2* (car l) (cadr l) (fully-macroexpand-list (cddr l) env)))

(defun macroexpand-let (a env)
    (list2* (car a)
            (fully-macroexpand-letvars (cadr a) env)
            (fully-macroexpand-list (cddr a) env)))

(defun macroexpand-flet (a env)
    (list2* (car a)
            (fully-macroexpand-fletvars (cadr a) env)
            (fully-macroexpand-list (cddr a) env)))

;; Forcible macro expansion of macrolets is an amazing and delicate
;; activity - the treatment given here is based on an idea in
;; "Common Lisp - the reference" (by Franz Inc), which uses eval on a
;; constructed macrolet to create local bindings, then invokes
;; a macro so that the lexical environment that macrolet creates can
;; be captured.

;; After bootstrapping this will say
;;      (defmacro macrolet-helper (&whole a &env env) ...)
(dm macrolet-helper (a &optional env)
    `',(list2* 'let nil (fully-macroexpand-list (cdr a) env)))

(defun macroexpand-macrolet (a env)
    (eval `(macrolet ,(cadr a)
                     (macrolet-helper ,@(cddr a)))))

;; Well the above is quite short, but I think it is remarkably opaque!

;;
;; Here are all the special forms that need special treatment during
;; exhaustive macro expansion.
;;

(put 'block 'fully-macroexpand #'fully-macroexpand-tagged)

(put 'compiler-let 'fully-macroexpand #'macroexpand-let)

(put 'declare 'fully-macroexpand #'(lambda (a env) a))

(put 'eval-when 'fully-macroexpand #'fully-macroexpand-tagged)

(put 'flet 'fully-macroexpand #'macroexpand-flet)

(put 'function 'fully-macroexpand #'(lambda (a env) a))

(put 'go 'fully-macroexpand #'(lambda (a env) a))

(put 'labels 'fully-macroexpand #'macroexpand-flet)

(put 'let 'fully-macroexpand #'macroexpand-let)

(put 'let* 'fully-macroexpand #'macroexpand-let)

(put 'macrolet 'fully-macroexpand #'macroexpand-macrolet)

(put 'quote 'fully-macroexpand #'(lambda (a env) a))

(put 'the 'fully-macroexpand #'fully-macroexpand-tagged)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; The following specials are used for communication during argument-list
;;; parsing for a macro or macro-like form.

(make-special '~arg-count)
(make-special '~min-args)
(make-special '~restp)
(make-special '~let-list)
(make-special '~env-var)
(make-special '~keyword-tests)
(make-special '~name)

;;; The following is an ugly way of getting an optional arg passed in to
;;; Analyze1.  Bootstrapping problems force me to do this.
(make-special '*default-default*)
(setq *default-default* nil)

(make-special '*key-finder*)
(setq *key-finder* 'find-keyword)

;;; ANALYZE-ARGLIST is implemented as a finite-state machine that steps
;;; through the legal parts of an arglist in order: required, optional,
;;; rest, key, and aux.  The results are accumulated in a set of special
;;; variables: ~let-list, ~arg-count, ~min-args, ~restp and ~keyword-tests.

(defun analyze-arglist (arglist path errloc whole)
   "For use by macros and macro-like forms that must parse some form
     according to a lambda-like argument list, ARGLIST.  The result is
     a list of variable-value pairs suitable for inclusion in a LET* form.
     PATH is an access expression for getting to the object to be parsed.
     ERRLOC is the name of the function being worked on, for use in error
     messages.  WHOLE is the form to supply if there is an &whole in the
     arglist, or NIL if &whole is illegal."
   (let
      ((~arg-count 0)
         (~min-args 0)
         (~restp nil)
         (~let-list nil)
         (~env-var nil)
         (~keyword-tests nil))
      (analyze1 arglist path errloc whole)
      (nreverse ~let-list)))


;;; ANALYZE1 is called by ANALYZE-ARGLIST to do the work for required and
;;; optional args.  It calls other functions if &rest, &key, or &aux are
;;; encountered.  Uses ~arg-count, ~min-args, ~restp, ~env-var and ~let-list.
(defun analyze1 (arglist path errloc whole)
   (do
      ((args arglist (cdr args)) (optionalp nil) (envp nil) a temp)
      ((atom args)
         (cond
            ((null args) nil)
            ;; Varlist is dotted, treat as &rest arg and exit.
            (t (push (list args path) ~let-list) (setq ~restp t))))
      (setq a (car args))
      (cond
         ((eq a '&whole)
            (cond
               ((and whole (cdr args) (symbolp (cadr args)))
                  (push (list (cadr args) whole) ~let-list)
                  (setq ~restp t)
                  (setq args (cdr args)))
               (t (error (format nil
                          "Illegal or ill-formed &whole arg in ~S." errloc)))))
         ((eq a '&environment)
            (cond
               ((and (null envp) (cdr args) (symbolp (cadr args)))
                  (setq ~env-var (cadr args))
                  (setq envp t)
                  (setq args (cdr args)))
               (t (error (format nil
                          "Illegal or ill-formed &environment arg in ~S."
                          errloc)))))
         ((eq a '&optional)
            (and
               optionalp
               (cerror
                  "Ignore it."
                  "Redundant &optional flag in varlist of ~S."
                  errloc))
            (setq optionalp t))
         ((or (eq a '&rest) (eq a '&body))
            (return (analyze-rest (cdr args) path errloc whole envp)))
         ((eq a '&key)
            ;; Create a rest-arg, then do keyword analysis.
            (setq temp (gensym))
            (setq ~restp t)
            (push (list temp path) ~let-list)
            (return (analyze-key (cdr args) temp errloc envp)))
         ((eq a '&allow-other-keys)
            (cerror
               "Ignore it."
               "Stray &ALLOW-OTHER-KEYS in arglist of ~S."
               errloc))
         ((eq a '&aux) (return (analyze-aux (cdr args) errloc)))
         ((not optionalp)
            (setq ~min-args (1+ ~min-args))
            (setq ~arg-count (1+ ~arg-count))
            (cond
               ((symbolp a) (push `(,a (car ,path)) ~let-list))
               ((atom a)
                  (cerror
                     "Ignore this item."
                     "Non-symbol variable name in ~S."
                     errloc))
               (t (let
                     ((~min-args 0) (~arg-count 0) (~restp nil))
                     (analyze1 a `(car ,path) errloc nil))))
            (setq path `(cdr ,path)))
         ;; It's an optional arg.
         (t (setq ~arg-count (1+ ~arg-count))
            (cond
               ((symbolp a)
                  ;; Just a symbol.  Bind to car of path or default.
                  (push
                     `(,a (cond (,path (car ,path)) (t ,*default-default*)))
                     ~let-list))
               ((atom a)
                  (cerror
                     "Ignore this item."
                     "Non-symbol variable name in ~S."
                     errloc))
               ((symbolp (car a))
                  ;; Car of list is a symbol.  Bind to car of path or
                  ;; to default value.
                  (push
                     `(,(car a)
                        (cond
                           (,path (car ,path))
                           (t ,(cond
                                 ((> (length a) 1) (cadr a))
                                 (t *default-default*)))) )
                     ~let-list)
                  ;; Handle supplied-p variable, if any.
                  (and
                     (> (length a) 2)
                     (push `(,(caddr a) (not (null ,path))) ~let-list)))
               ;; Then destructure arg against contents of this gensym.
               (t (setq temp (gensym))
                  (push
                     `(,temp
                        (cond
                           (,path (car ,path))
                           (t ,(cond
                                 ((cddr a) (cadr a))
                                 (t *default-default*)))) )
                     ~let-list)
                  (let
                     ((~min-args 0) (~arg-count 0) (~restp nil))
                     (analyze1 (car a) temp errloc nil))
                  ;; Handle supplied-p variable if any.
                  (and
                     (> (length a) 2)
                     (push `(,(caddr a) (not (null ,path))) ~let-list))))
            (setq path `(cdr ,path)))) ))


;;; This deals with the portion of the arglist following any &rest flag.
(defun analyze-rest (arglist path errloc whole envp)
   (cond
      ((or (atom arglist) (not (symbolp (car arglist))))
         (error (format nil "Bad &rest or &body arg in ~S." errloc))))
   (push (list (car arglist) path) ~let-list)
   (setq ~restp t)
   (prog ((rest-arg (car arglist)) (more (cdr arglist)))
try-again
      (cond
         ((null more) nil)
         ((atom more)
            (cerror
               "Ignore the illegal terminator."
               "Dotted arglist terminator after &rest arg in ~S."
               errloc))
         ((eq (car more) '&key) (analyze-key (cdr more) rest-arg errloc envp))
         ((eq (car more) '&aux) (analyze-aux (cdr more) errloc))
         ((eq (car more) '&allow-other-keys)
            (cerror
               "Ignore it."
               "Stray &ALLOW-OTHER-KEYS in arglist of ~S."
               errloc))
         ((eq (car more) '&environment)
            (cond
               ((and (null envp) (cdr more) (symbolp (cadr more)))
                  (setq ~env-var (cadr more))
                  (setq envp t)
                  (setq more (cdr more)))
               (t (error (format nil
                                 "Illegal or ill-formed &environment arg in ~S."
                                 errloc)))))
         ((eq (cadr more) '&whole)
            (cond
               ((and whole (cdr more) (symbolp (cadr more)))
                  (push (list (cadr more) whole) ~let-list)
                  (setq more (cddr more))
                  (go try-again))
               (t (error (format nil
                                 "Ill-formed or illegal &whole arg in ~S."
                                 errloc))))) )))


;;; Analyze stuff following &aux.
(defun analyze-aux (arglist errloc)
   (do
      ((args arglist (cdr args)))
      ((null args))
      (cond
         ((atom args)
            (cerror
               "Ignore the illegal terminator."
               "Dotted arglist after &AUX in ~S."
               errloc)
            (return nil))
         ((atom (car args)) (push (list (car args) nil) ~let-list))
         (t (push (list (caar args) (cadar args)) ~let-list)))) )


(make-special 'key-uses)
(setq key-uses nil)

#+:report-keywords
(defun report-keywords (name args)
   (when (not (memq name key-uses)) (setq key-uses (cons name key-uses)))
   (prog (w)
      (setq w (get name 'key-uses))
  top (cond ((null w) (go new))
            ((equal (caar w) args)
               (rplacd (car w) (+ 1 (cdar w)))
               (return nil)))
      (setq w (cdr w))
      (go top)
  new (setq w (cons (cons args 1) (get name 'key-uses)))
      (put name 'key-uses w)
      (return nil)))

(defun display-keywords ()
  (let ((s (linelength 1000)))
   (terpri)
   (dolist (name key-uses)
     (dolist (v (get name 'key-uses))
        (when (< (cdr v) 100000) (princ " "))  ; to right-align the number
        (when (< (cdr v) 10000) (princ " "))
        (when (< (cdr v) 1000) (princ " "))
        (when (< (cdr v) 100) (princ " "))
        (when (< (cdr v) 10) (princ " "))
        (prin (cdr v)) 
        (ttab 12) (prin name) (princ " ")
        (ttab 45) (prin (car v)) (terpri)))
   (terpri)
   (linelength s)
   (reset-keywords)))

(defun reset-keywords ()
   (dolist (name key-uses) (put name 'key-uses nil))
   (setq key-uses nil))

;;; Handle analysis of keywords, perhaps with destructuring over the keyword
;;; variable.  Assumes the remainder of the calling form has already been
;;; bound to the variable passed in as RESTVAR.
(defun analyze-key (arglist restvar errloc envp)
   (let
      ((temp (gensym)) (check-keywords t) (keywords-seen nil))
#+:report-keywords
      (push `(,(gensym) (report-keywords ',~name ,restvar)) ~let-list)
      (push temp ~let-list)
      (do
         ((args arglist (cdr args)) a k sp-var temp1)
         ((atom args)
            (cond
               ((null args) nil)
               (t (cerror
                     "Ignore the illegal terminator."
                     "Dotted arglist after &key in ~S."
                     errloc))))
         (setq a (car args))
         (cond
            ((eq a '&allow-other-keys) (setq check-keywords nil))
            ((eq a '&aux) (return (analyze-aux (cdr args) errloc)))
            ((eq a '&environment)
               (cond
                  ((and (null envp) (cdr args) (symbolp (cadr args)))
                     (setq ~env-var (cadr args))
                     (setq envp t)
                     (setq args (cdr args)))
                  (t (error (format nil
                                 "Illegal or ill-formed &environment arg in ~S."
                                 errloc)))))
            ;; Just a top-level variable.  Make matching keyword.
            ((symbolp a)
               (setq k (make-keyword a))
               (push
                  `(,a
                     (cond
                        ((setq ,temp (,*key-finder* ',k ,restvar))
                           (car ,temp))
                        (t nil)))
                  ~let-list)
               (push k keywords-seen))
            ;; Filter out error that might choke defmacro.
            ((atom a)
               (cerror
                  "Ignore this item."
                  "~S -- non-symbol variable name in arglist of ~S."
                  a
                  errloc))
            ;; Deal with the common case: (var [init [svar]])
            ((symbolp (car a))
               (setq k (make-keyword (car a)))
               ;; Deal with supplied-p variable, if any.
               (cond
                  ((and (cddr a) (symbolp (caddr a)))
                     (setq sp-var (caddr a))
                     (push (list sp-var nil) ~let-list))
                  (t (setq sp-var nil)))
               (push
                  `(,(car a)
                     (cond
                        ((setq ,temp (,*key-finder* ',k ,restvar))
                           ,@(and sp-var `((setq ,sp-var t)))
                           (car ,temp))
                        (t ,(cadr a))))
                  ~let-list)
               (push k keywords-seen))
            ;; Filter out more error cases that might kill defmacro.
            ((or (atom (car a)) (not (keywordp (caar a))) (atom (cdar a)))
               (cerror
                  "Ignore this item."
                  "~S -- ill-formed keyword arg in ~S."
                  (car a)
                  errloc))
            ;; Next case is ((:key var) [init [supplied-p]]).
            ((symbolp (cadar a))
               (setq k (caar a))
               ;; Deal with supplied-p variable, if any.
               (cond
                  ((and (cddr a) (symbolp (caddr a)))
                     (setq sp-var (caddr a))
                     (push (list sp-var nil) ~let-list))
                  (t (setq sp-var nil)))
               (push
                  `(,(cadar a)
                     (cond
                        ((setq ,temp (,*key-finder* ',k ,restvar))
                           ,@(and sp-var `((setq ,sp-var t)))
                           (car ,temp))
                        (t ,(cadr a))))
                  ~let-list)
               (push k keywords-seen))
            ;; Same case, but must destructure the "variable".
            (t (setq k (caar a))
               (setq temp1 (gensym))
               (cond
                  ((and (cddr a) (symbolp (caddr a)))
                     (setq sp-var (caddr a))
                     (push (list sp-var nil) ~let-list))
                  (t (setq sp-var nil)))
               (push
                  `(,temp1
                     (cond
                        ((setq ,temp (,*key-finder* ',k ,restvar))
                           ,@(and sp-var `((setq ,sp-var t)))
                           (car ,temp))
                        (t ,(cadr a))))
                  ~let-list)
               (push k keywords-seen)
               (let
                  ((~min-args 0) (~arg-count 0) (~restp nil))
                  (analyze1 (cadar a) temp1 errloc nil)))) )
      (and
         check-keywords
         (push `(keyword-test ,restvar ',keywords-seen) ~keyword-tests))))


;;; Functions that must be around when the macros produced by DEFMACRO are
;;; expanded.
(defun make-keyword (s)
   "Takes a non-keyword symbol S and returns the corresponding keyword."
   (intern (symbol-name s) *keyword-package*))


(defun find-keyword (keyword keylist)
   "If keyword is present in the keylist, return a list of its argument.
     Else, return NIL."
   (do
      ((l keylist (cddr l)))
      ((atom l) nil)
      (cond
         ((atom (cdr l))
            (cerror
               "Stick a NIL on the end and go on."
               "Unpaired item in keyword portion of macro call.")
            (rplacd l (list nil))
            (return nil))
         ((eq (car l) keyword) (return (list (cadr l)))) )))


(defun keyword-test (keylist legal)
   "Check whether all keywords in a form are legal.  KEYLIST is the portion
     of the calling form containing keywords.  LEGAL is the list of legal
     keywords.  If the keyword :allow-other-keyws is present in KEYLIST,
     just return without complaining about anything."
   (cond
      ((memq ':allow-other-keys keylist) nil)
      (t (do
            ((kl keylist (cddr kl)))
            ((atom kl) nil)
            (cond
               ((memq (car kl) legal))
               (t (cerror
                     "Ignore it."
                     "~S illegal or unknown keyword."
                     (car kl)))) ))) )

(defun defun-key-aux (name arglist body rargs)
   (cond
     ((null arglist) (cons (reverse rargs) body))
     ((eqcar arglist '&rest)
        (let* ((restv (cadr arglist))
               (newlets (analyze-arglist (cddr arglist) restv name nil)))
           (when (eqcar (cddr arglist) '&key)
               (setq newlets
                   (subst (cadar newlets) (caar newlets) (cdr newlets))))
           (cons (reverse (cons restv (cons '&rest rargs)))
                 (list (cons 'let* (cons newlets body))))))
     ((eqcar arglist '&key)
        (defun-key-aux name (cons '&rest (cons (gensym) arglist)) body rargs))
     ((eqcar arglist '&aux)
        (cons (reverse rargs)
              (list (cons 'let* (cons (cdr arglist) body)))))
     (t (defun-key-aux name (cdr arglist) body (cons (car arglist) rargs)))))

(defun expand-definer (form defunp)
   (cond
      ((< (length form) 4)
         (error (format nil "~S -- Function or Macro too short to be legal."
                        form))))
   (prog ((name (cadr form))
          (~name (cadr form))    ; for keyword trace scheme
          (arglist (caddr form))
          (body (cdddr form))
          (local-decs nil)
          (doc nil) (arg-test nil) (~arg-count 0) (~min-args 0) (~restp nil)
          (~env-var nil)
          (~let-list nil) (~keyword-tests nil))
      (cond
         ((not (symbolp name))
            (error (format nil "~S -- Function- or Macro-name not a symbol."
                           name))))

;;
;; Here I USED to macroexpand things, but that causes trouble for debugging
;; and prevents the compiler for doing its own different expansion. But
;; expanding things here was a way of speeding up interpreted code...
;;
;;    (setq body (fully-macroexpand-list body nil))
;;
      ;; Check for local declarations and documentation string.
loop3 (cond
         ((atom body) (setq body '(nil)))
         ((and (not (atom (car body))) (eq (caar body) 'declare))
            (setq local-decs (append local-decs (cdar body)))
            (setq body (cdr body))
            (go loop3))
         ((and (stringp (car body)) (not (null (cdr body))))
            (setq doc (list (car body)))
            (setq body (cdr body))
            (go loop3)))
      ;; The interpreter can deal with ALL options in defun - however
      ;; the compiler does not understand &key or &aux, so I need to
      ;; detect those cases here.  Also I fully macroexpand the body
      ;; and tidy up declarations and documentation.
      (when defunp
         (let ((newbody `((block ,name ,@body))))
            (when local-decs (push (cons 'declare local-decs) newbody))
            (setq newbody (defun-key-aux name arglist newbody nil))
            (setq arglist (car newbody))
            (setq newbody (cdr newbody))
            (return (if doc
               `(progn
                   (put ',name :function-documentation ',doc)
                   (de ,name ,arglist ,@newbody))
               `(de ,name ,arglist ,@newbody)))))
      ;; (defmacro fff (&whole x) ...) drops down to the lower level code
      (when (and (= (length arglist) 2)
                 (eq (car arglist) '&whole))
            (return (if doc
               `(progn
                   (put ',name :function-documentation ',doc)
                   (dm ,name (,(cadr arglist)
                                     &optional ~macroenvironment~)
                              ,@(and local-decs (list (cons 'declare local-decs)))
                              (block ,name ,@body)))
               `(dm ,name (,(cadr arglist)
                                  &optional ~macroenvironment~)
                           ,@(and local-decs (list (cons 'declare local-decs)))
                           (block ,name ,@body)))))

      ;; Analyze the argument list.
      (analyze1 arglist '(cdr ~macroarg~) name '~macroarg~)
      (when (null ~env-var) (setq ~env-var '~macroenvironment~))

      (let ((minn ~min-args)
            (maxx ~arg-count))
         (setq minn (1+ minn) maxx (1+ maxx))
         (setq arg-test
             (cond
                ((and (= 0 ~min-args) ~restp) nil)
                ((= 0 ~min-args) `(> (length ~macroarg~) ,maxx))
                (~restp `(< (length ~macroarg~) ,minn))
                ((= ~min-args ~arg-count)
                   `(not (= (length ~macroarg~) ,minn)))
                (t `(or
                      (> (length ~macroarg~) ,maxx)
                      (< (length ~macroarg~) ,minn))) )))
      ;; Now build the body of the macro.
      (when (null arglist) (push '(ignore ~macroarg~) local-decs))
      (setq body
         `(let*
            ,(nreverse ~let-list)
            ,@(and local-decs (list (cons 'declare local-decs)))
            (block ,name
               ,@~keyword-tests
               ,@body)))
      (and arg-test
         (setq body
            `(cond
               (,arg-test
                  (error
                    (format nil
                     "Macro ~S cannot be called with ~S args."
                     ',name
                     (1- (length ~macroarg~)))))
               (t ,body))))
      (return (if doc
                  `(progn
                     (put ',name :function-documentation ',doc)
                     (dm ,name (~macroarg~ &optional ,~env-var)
                                     ,body))
                  `(dm ,name (~macroarg~ &optional ,~env-var)
                                    ,body)))))


(defun no-special-flags (bvl)
;; This test permits &optional and &rest args to be passed down to the
;; lower level de.
   (cond
      ((null bvl) t)
      ((memq (car bvl) '(&key &aux)) nil)
      (t (no-special-flags (cdr bvl)))))


;;; The DEFMACRO and DEFUN definitions themselves.

(dm defmacro (form &optional env)
   ;; (defmacro defmacro (&whole form) ...)
   "Syntax like a DEFUN, but creates a macro.  See manual for details."
   (expand-definer form nil))

(put 'defmacro
     :function-documentation
     "Syntax like a DEFUN, but creates a macro.  See manual for details.")


(defmacro defun (&whole form)
   "Creates a function definition.  See manual for details."
   (expand-definer form t))

(defmacro deftype (name lambda-list &rest body)
   `(eval-when (compile load eval)
               (put 'name 'deftype '(lambda ,lambda-list ,@body))
               'name)))

;; end of defmacro.lsp

