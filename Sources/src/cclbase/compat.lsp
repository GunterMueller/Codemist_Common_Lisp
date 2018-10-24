;; Basic compatibility things that must be loaded at the very start
;; of the process of building a CCL image


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

(setq *package* (find-package 'lisp))

(setq *cl-symbols* 
   #(:nicknames :use and or not nil :named-character
     *read-default-float-format* short-float single-float 
     double-float long-float bit pathname *print-array*
     *read-base* :initial-element format
    ))

(extern '*cl-symbols*)

(extern '@cclbase)

(make-special '*read-default-float-format*)
(setq *read-default-float-format* 'single-float) ;; supposed to be default

(make-special '*print-array*)
(setq *print-array* nil)

(make-special '*read-base*)
(setq *read-base* 10)

(verbos 3)

(make-package 'c)
(make-package 's)
(make-package 'system :nicknames '(sys))
(make-package 'user)

(de load (x) (rdf x nil))        ; provisional version

;; end of compat.lsp
