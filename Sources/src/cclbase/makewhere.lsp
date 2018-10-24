
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


(clear_source_database)
(load "../cclbase/compat.lsp")

(load "../cclbase/exports.lsp")    ; defines what must be visible to end-user

(load "../cclbase/basic.lsp")      ; VERY basic things

(load "../cclbase/defmacro.lsp")   ; defun and defmacro

(load "../cclbase/funcs1.lsp")     ; misc useful functions

(load "../cclbase/nag_funs.lsp")   ; functions supplied by NAG for AXIOM

(load "../cclbase/extras.lsp")

(load "../cclbase/compiler.lsp")

(load "../cclbase/setf.lsp")       ; generalized variables

(load "../cclbase/arrays.lsp")     ; arrays, matrices etc.

(load "../cclbase/sequence.lsp")

(load "../cclbase/sort.lsp")

(load "../cclbase/string.lsp")

(load "../cclbase/defstruc.lsp")

(load "../cclbase/package.lsp")

(load "../cclbase/pathname.lsp")

(load "../cclbase/stream.lsp")     ; part of IO module

(load "../cclbase/print.lsp")

(defun set-syntax-from-char (a b) nil)

(load "../cclbase/prinflo.lsp")

(load "../cclbase/format.lsp")

(load "../cclbase/ccomp.lsp")
(save_source_database "../axbase/whereisA.lsp")
