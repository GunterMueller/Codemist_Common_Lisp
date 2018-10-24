;;;
;;; The very first set of definitions that I load into Lisp at the start
;;; of a bootstrap process.
;;;

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


(setq *echo nil)
(setpchar "> ")

(make-special '*package*)
(make-special '*readtable*)
(if (not (boundp '*readtable*)) (setq *readtable* nil))

(symbol-set-env 'logand 1)
(symbol-set-env 'logxor 6)
(symbol-set-env 'logior 7)
(symbol-set-env 'logor 7)    ; Standard Lisp comaptibilty name!
(symbol-set-env 'logeqv 9)

;;
;; The following priority order came from measurements of compiling the
;; compiler - the following property-list indicators where the most heavily
;; used (in addition s!:opcode was highly rated, above even these. However
;; I expect the names of byte opcodes will never have long property lists
;; so I will leave the usual mechanism in place for them).
;;

(symbol-make-fastget 's::tidy_fn            30)
(symbol-make-fastget 's::compfn             29)
(symbol-make-fastget 's::newname            28)
(symbol-make-fastget 's::compilermacro      27)

(de rplacw (a b) (progn (rplaca a (car b)) (rplacd a (cdr b))))

(de last (l)
   (if (atom l) nil
       (if (atom (cdr l)) l
           (last (cdr l)))))

(de lastcar (l)
   (if (atom l) nil
       (if (atom (cdr l)) (car l)
           (lastcar (cdr l)))))

(de expand-cond (l)
   (if (endp l)
       nil
       (if (null (cdar l))
           `(or ,(caar l) ,(expand-cond (cdr l)))
           (if (eq (caar l) t)
               (cons 'progn (cdar l))
               `(if ,(caar l)
                    (progn ,@(cdar l))
                    ,(expand-cond (cdr l)))))))

(dm cond (u &optional env) (expand-cond (cdr u)))

(dm when (u &optional env)
   `(if ,(cadr u) (progn ,@(cddr u)) nil))

(dm unless (u &optional env)
   `(if (not ,(cadr u)) (progn ,@(cddr u)) nil))

(de expand-and (u)
   (if (endp u)
       nil
       (if (endp (cdr u))
           (car u)
           `(if ,(car u) ,(expand-and (cdr u)) nil))))

(de mapcar~ (fn l)
  (if (null l) nil
      (cons (funcall fn (car l)) (mapcar~ fn (cdr l)))))

(de expand-or (u)
   (if (endp u)
       t
       (if (endp (cdr u))
           (car u)
           (let ((g (gensym)))
              `(let ((,g ,(car u)))
                 (if ,g ,g ,(expand-or (cdr u))))))))

(dm and (u &optional env) (expand-and (cdr u)))

(dm or (u &optional env) (expand-or (cdr u)))

(de copy (a)
   (if (atom a)
       a
       (cons (copy (car a)) (copy (cdr a)))))

(de length-one-p (x)
   (if (atom x) nil (atom (cdr x))))

;; (de stringp (u)
;;    (if (simple-string-p u) t
;;        (if (arrayp u)
;;           (if (eq (svref u 0) 'string-char)
;;               (length-one-p (svref u 1))
;;               nil)
;;           nil)))

(de make-psetq-vars (u)
   (if (endp u)
       nil
       (if (endp (cdr u))
           (error "odd number of items in psetq")
           (cons (gensym) (make-psetq-vars (cddr u))))))

(de make-psetq-bindings (vars u)
   (if (endp u)
       nil
       (cons
          (list (car vars) (cadr u))
          (make-psetq-bindings (cdr vars) (cddr u)))))

(de make-psetq-assignments (vars u)
   (if (endp u)
       nil
       (cons
          (list 'setq (car u) (car vars))
          (make-psetq-assignments (cdr vars) (cddr u)))))

(dm psetq (x &optional env)
   (let ((vars (make-psetq-vars (cdr x))))
      `(let* ,(make-psetq-bindings vars (cdr x))
         ,@(make-psetq-assignments vars (cdr x)))))

;;; (do ((v i s) ..)
;;;     (end result ...)
;;;     declaration*
;;;     body)

;; By CLTL-1 I needed to macroexpand in case that uncovered a declaration
;; but CLTL-2 says that I do not need to, and that makes me happy since
;; over-eager macroexpansion gets in the way of the compiler.

(de find-declarations (l)
;; written in basic Lisp to help bootstrap the world.  Returns a list
;; of (documentation declarations body)
   (block nil
      (let ((doc nil)
            (decl nil)
            (w))
         (tagbody
    loop    (if (endp l) (return-from nil (list doc (nreverse decl) nil)))
;;          (setq w (macroexpand (car l)))
            (setq w (car l))
            (setq l (cdr l))
            (if (stringp w)
                (if (endp l) nil
                    (progn (if (null doc) (setq doc w)))
                           (go loop))
                (if (atom w) nil
                    (if (eq (car w) 'declare)
                        (progn (setq decl (cons w decl))
                               (go loop)))))
            (return-from nil (list doc (nreverse decl) (cons w l)))))))

(de do-bindings (u)
   (if (endp u)
       nil
       (if (atom (car u))
           (cons (car u) (do-bindings (cdr u)))
           (if (endp (cdar u))
               (cons (list (caar u) nil) (do-bindings (cdr u)))
               (cons (list (caar u) (cadar u)) (do-bindings (cdr u)))))))

(de do-endtest (u)
   (if (endp u)
       nil
       (car u)))

(de do-result (u)
   (if (endp u)
       nil
       (cdr u)))

(de do-updates (u)
   (if (endp u)
       nil
       (let ((v (car u))
             (x (do-updates (cdr u))))
          (if (or (atom v)
                  (endp (cdr v))
                  (endp (cddr v)))
              x
              (cons (car v) (cons (caddr v) x))))))


(de expand-do (u letter setter)
   (let* ((bindings (do-bindings (car u)))
          (result (do-result (cadr u)))
          (updates (do-updates (car u)))
          (doc-dec-body (find-declarations (cddr u)))
          (endtest (do-endtest (cadr u)))
          (upd (if updates (list (cons setter updates)) nil))
          (res (if (endp result)
                   nil
                   (if (endp (cdr result))
                       (car result)
                       (cons 'progn result))))
          (x (if (null endtest) nil
                 `((if ,endtest (return ,res)))))
          (g (gensym)))
      (if bindings
         `(block nil
            (,letter ,bindings
               ,@(cadr doc-dec-body)
               (tagbody
            ,g    ,@x
                  ,@(caddr doc-dec-body)
                  ,@upd
                  (go ,g))))
         `(block nil
               ,@(cadr doc-dec-body)
               (tagbody
            ,g    ,@x
                  ,@(caddr doc-dec-body)
                  ,@upd
                  (go ,g))))))

(dm do (u &optional env) (expand-do (cdr u) 'let 'psetq))

(dm do* (u &optional env) (expand-do (cdr u) 'let* 'setq))

(dm prog (u &optional env)
   (setq u (cdr u))
   (let ((bvl (car u))
         (doc-dec-body (find-declarations (cdr u))))
     `(block nil
        (let ,(car u)
             ,@(cadr doc-dec-body)
             (tagbody ,@(caddr doc-dec-body))))))

(dm prog* (u &optional env)
   (setq u (cdr u))
   (let ((bvl (car u))
         (doc-dec-body (find-declarations (cdr u))))
     `(block nil
        (let* ,(car u)
              ,@(cadr doc-dec-body)
              (tagbody ,@(caddr doc-dec-body))))))

(dm push (u &optional env)   ;; temp version until setf package has been loaded
   `(setq ,(caddr u) (cons ,(cadr u) ,(caddr u))))

(dm prog1 (u &optional env)
   (let ((g (gensym)))
     `(let ((,g ,(cadr u)))
           ,@(cddr u)
           ,g)))

(dm prog2 (u &optional env)
   `(progn ,(cadr u) (prog1 ,@(cddr u))))

(dm pop (u &optional env)
   `(prog1 (car ,(cadr u))
           (setq ,(cadr u) (cdr ,(cadr u)))))

(dm defun (a &optional env)
;; Bootstrap version here - soon to be replaced.
   `(de ,@(cdr a)))
