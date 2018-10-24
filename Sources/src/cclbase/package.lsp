
;;; Completion of the package system

;; make-package, in-package, shadow, shadowing-import, export,
;; unexport, use-package, unuse-package, import
;;    all the above imply (eval-when (compile load eval) ..)

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



(defun package-name (v) (elt v 8))
(defun package-nicknames (v) (elt v 9))
(defun packagep (v) (and (structp v) (eq (getv v 0) 'package)))
(defun package-shadowing-symbols (v) (getv v 12))
(defun package-use-list (v) (getv v 10))
(defun package-used-by-list (v) (getv v 11))

;;- (defun package-print (p stream depth)
;;-    (format stream "#<Package: ~S>" (package-name p)))

(defun symbol-to-string (x)
;; input is a symbol or string: output is a simple string
   (cond
      ((symbolp x) (symbol-name x))
      ((simple-string-p x) x)
      ((stringp x) (string-to-simple-string* x))
      (t (error (format nil "string or symbol needed but ~S found" x)))))

;; CLTL-2 says that in-package can only take one argument, and that is
;; not evaluated but must be a symbol or a string. To help with a migration
;; from CLTL-1 I also support an argument of the form (quote xx) where xx is
;; a string or a symbol. I also raise an error if the named package does not
;; exist, although I imagine that I could change the call to error into one
;; to make-package easily enough.

(defmacro in-package (name &rest ignored)
   (when (eqcar name 'quote) (setq name (cadr name)))
   `(eval-when (compile load eval)
       (let ((p (find-package ',name)))
          (if p 
              (setq *package* p)
              (error (format nil "Package ~S not found" ',name))))))

;; package-name, package-nicknames, package-use-list package-used-by-list

(defun rename-package (p new-name &optional (new-nicknames nil))
   (putv p 8 new-name)
   (putv p 9 new-nicknames)
   p)

;; list-all-packages, intern, find-symbol

(defun export (syms &optional (p *package*) &aux p1)
   (when (atom syms) (setq syms (list syms)))
   (setq p1 (find-package p))
   (when (null p1) (error (format nil "Package ~S not found" p)))
   (dolist (s syms)
      (dolist (q (package-used-by-list p1))
         (multiple-value-bind 
            (x found)
            (find-symbol s q)
            (when (and found 
                       (not (eq x s))
                       (not (member x (package-shadowing-symbols q)
                                    :test #'eq)))
               (princ "+++ Symbol ") (prin x)
               (princ " made shadowing in package ") (prin q)
               (terpri)
               (shadow x q)
            )
         )
      )
   )
   (dolist (s syms) (extern s p1)))

(defun unexport (syms &optional (package *package*))
   (setq package (find-package package))
   (when (null package) (setq package *package*))
   (error "unimplemented"))

(defun import (syms &optional (package *package*))
   (setq package (find-package package))
   (when (null package) (setq package *package*))
   (if (not (atom syms))
      (dolist (s syms) (import s package))
      (multiple-value-bind (s found) (find-symbol syms package)
         (if found
            (when (not (eq s syms))
               (error (format nil "Name clash on importing ~S into package ~S"
                              syms package)))
            (import* syms package))))
   t)

(defun shadowing-import (syms &optional (package *package*))
   (setq package (find-package package))
   (when (null package) (setq package *package*))
   (if (not (atom syms))
      (dolist (s syms) (shadowing-import s package))
      (multiple-value-bind (s found) (find-symbol syms package)
         (when (and found (eq s syms)) (return-from shadowing-import t))
         (when (or (eq found :internal) (eq found :external))
            (remob s package))
         (import* syms package)
         (putv package 12 (cons syms (package-shadowing-symbols package)))))
   t)

(defun shadow (syms &optional (package *package*))
   (setq package (find-package package))
   (when (null package) (setq package *package*))
   (if (not (atom syms))
      (dolist (s syms) (shadow s package))
;; syms is now a single symbol or a string.
      (multiple-value-bind (s found) (intern syms package)
         (if (or (null found) (eq found :inherited))
            (let ((newsym (make-symbol s)))
               (import* newsym package)
               (putv package 12 
                  (cons newsym (package-shadowing-symbols package))))
            (putv package 12
                  (cons found (package-shadowing-symbols package))))))
   t)

(defun unuse-package (p &optional (package *package*))
   (setq package (find-package package))
   (when (null package) (setq package *package*))
   (error "unimplemented"))

(defun package-externs (v)
  (let ((w (getv v 5)))
    (if (atom w) (list w) w)))

(defun package-interns (v)
  (let ((w (getv v 1)))
    (if (atom w) (list w) w)))

(defun find-all-symbols (string)
   (setq string (symbol-to-string string))
   (let ((r nil))
      (dolist (p (list-all-packages))
         (dolist (b (append (package-externs p) (package-interns p)))
            (let* ((s (length b)))
               (dotimes (i s)
                  (let ((x (svref b i)))
                     (when (and (symbolp x)
                                (not (member x r :test #'eq))
                                (string= string (symbol-name x)))
                           (push x r)))))))
      r))

(defun do-syms-1 (v p body sel)
   (let ((b (gensym))
         (s (gensym))
         (i (gensym)))
      `(dolist (,b (,sel ,p))
         (let ((,s (length ,b)))
           (dotimes (,i ,s)
             (setq ,v (svref ,b ,i))
             (when (symbolp ,v) (tagbody ,@body)))))))

(defun do-syms (vpr body ints)
   (let* ((i (gensym))
          (w (gensym))
          (v (pop vpr))
          (p (if (endp vpr) '*package* (pop vpr)))
          (r (if (endp vpr) nil (pop vpr))))
      `(let ((,v))
          ,(do-syms-1 v p body 'package-externs)
          ,@(if ints (list (do-syms-1 v p body 'package-interns)) nil)
          (setq ,v nil)
          ,r)))

(defmacro do-symbols (vpr &body body)
   (do-syms vpr body t))

(defmacro do-external-symbols (vpr &body body)
   (do-syms vpr body nil))

(defmacro do-all-symbols (vpr &body body)
   (let* ((g (gensym))
          (v (pop vpr))
          (r (if (endp vpr) nil (pop vpr))))
      `(dolist (,g (list-all-packages) ,r)
          (do-symbols (,v ,g) ,@body))))

;; I have a function called use-package* built into CCL, but it is only
;; for the two-argument case, and it does not do any checking for name
;; conflicts. So the code here will do all the checking and then call the
;; simple function.  Note that I forcibly resolve conflicts by making the
;; symbol in the parent package a shadowing one. Note that if the symbol
;; was already available in the parent package by inheritance this will
;; put it directly there.

;; Must be defined AFTER do-external-symbols is, otherwise compilation gets
;; messed up!

(defun use-package (to-use &optional (package *package*))
   (if 
      (null to-use) 
      t
      (let ((p (find-package package)))
         (when (null p)
             (error (format nil "Package ~S not found" package)))
         (when (atom to-use) (setq to-use (list to-use)))
         (dolist (n to-use)
            (let ((np (find-package n)))
               (when (null np) (error (format nil "Package ~S not found" n)))
               (do-external-symbols (x np)
                  (multiple-value-bind 
                     (r found)
                     (find-symbol x p)
                     (when (and found 
                                (not (eq r x)) 
                                (not (member r (package-shadowing-symbols p)
                                             :test #'eq)))
                         (princ "+++ Symbol ") (prin r)
                         (princ " make shadowing in ") (prin p) (terpri)
                         (shadow r p)
                     )
                  )
               )
            )
         )
         (use-package* to-use package)
      )
   )
)

(defvar *modules* nil)

(defun provide (name)
   (let ((s (symbol-to-string name)))
      (unless (member s *modules* :test #'string=)
              (push s *modules*))
      nil))

(defun require (name &optional pathname)
   (error "unimplemented"))


