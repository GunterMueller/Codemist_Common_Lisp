;;
;; This starts with a cold-start Lisp (ccl -z) and loads a pile of
;; jolly things to produce a complete enough system to support development
;; of a compiler etc.
;;

;;;
;;; This code may be used and modified, and redistributed in binary
;;; or source form, subject to the "CCL Public License", which should
;;; accompany it. This license is a variant on the BSD license, and thus
;;; permits use of code derived from this in either open and commercial
;;; projects: but it does require that updates to this code be made
;;; available back to the originators of the package.
;;; Before merging other code in with this or linking this code
;;; with other packages or libraries please check that the license terms
;;; of the other material are compatible with those of this.
;;;
;;; Parts of the Lisp code here are or have been derived from the Spice
;;; Common Lisp code-base, that was placed in the Public Domain. Thus
;;; public domain versions of some of these files may also be available.
;;; The versions here will have been selected, customised and arranged
;;; for use with CCL. "Thank you very much, Spice People".
;;;



;; The variable *cl-symbols* holds a vector that provides CCL with
;; access to a variety of symbols.  This vector MUST be set up very
;; early and any corruption of it can cause system-damage to CCL.
;; Care must be taken with the CCL implementation that the things present
;; here end up in the correct packages!

(rdf "$CCLBASE/compat.lsp")

(load "$CCLBASE/exports.lsp")    ; defines what must be visible to end-user

(load "$CCLBASE/basic.lsp")      ; VERY basic things

(load "$CCLBASE/defmacro.lsp")   ; defun and defmacro

(load "$CCLBASE/defmacro.lsp")   ; load it twice for reasons of bootstrapping

(load "$CCLBASE/funcs1.lsp")     ; misc useful functions

(load "$CCLBASE/nag_funs.lsp")   ; functions supplied by NAG for AXIOM

(load "$CCLBASE/extras.lsp")
(load "$CCLBASE/compiler.lsp")

;; (if (member :debug *features*) (trace-all t)) ; desparation!

(setq *comp t)

(compile '(
    s::improve s::literal_order s::comval s::outopcode0
    s::plant_basic_block s::remlose s::islocal
    s::is_lose_and_exit s::comatom s::destination_label
    s::record_literal s::resolve_labels s::expand_jump
    s::outopcode1lit stable-sortip s::iseasy s::outjump
    s::add_pending s::comcall s::resolve_literals))

(let ((*package* (find-package 's)))
     (compile (oblist)))

(compile-all)

(load "$CCLBASE/setf.lsp")       ; generalized variables

(load "$CCLBASE/arrays.lsp")     ; arrays, matrices etc.

(load "$CCLBASE/sequence.lsp")

(load "$CCLBASE/sort.lsp")

(load "$CCLBASE/string.lsp")

(load "$CCLBASE/defstruc.lsp")

(load "$CCLBASE/package.lsp")

(load "$CCLBASE/pathname.lsp")

(load "$CCLBASE/stream.lsp")     ; part of IO module

(load "$CCLBASE/print.lsp")

;; read.lsp needs to go here?

(defun set-syntax-from-char (a b) nil)

(load "$CCLBASE/prinflo.lsp")

(load "$CCLBASE/format.lsp")

;; Now do it all over again to get FASL modules built.

(faslout 'common)

(load "$CCLBASE/compat.lsp")

(load "$CCLBASE/exports.lsp")    ; defines what must be visible to end-user

(load "$CCLBASE/basic.lsp")      ; VERY basic things

(load "$CCLBASE/defmacro.lsp")   ; defun and defmacro

(load "$CCLBASE/funcs1.lsp")     ; misc useful functions

(load "$CCLBASE/nag_funs.lsp")   ; functions supplied by NAG for AXIOM

(load "$CCLBASE/extras.lsp")

(load "$CCLBASE/compiler.lsp")

(load "$CCLBASE/setf.lsp")       ; generalized variables

(load "$CCLBASE/arrays.lsp")     ; arrays, matrices etc.

(load "$CCLBASE/sequence.lsp")

(load "$CCLBASE/sort.lsp")

(load "$CCLBASE/string.lsp")

(load "$CCLBASE/defstruc.lsp")

(load "$CCLBASE/package.lsp")

(load "$CCLBASE/pathname.lsp")

(load "$CCLBASE/stream.lsp")     ; part of IO module

(load "$CCLBASE/print.lsp")

;; read.lsp needs to go here?

(defun set-syntax-from-char (a b) nil)

(load "$CCLBASE/prinflo.lsp")

(load "$CCLBASE/format.lsp")

(faslend)

(faslout 'ccomp)

(load "$CCLBASE/ccomp.lsp")

(faslend)

;; I restart CCL to get a fresh clean version, then just load in the
;; parts I really need

(restart-csl nil)

(load-module 'common)

(setq *comp t)

(in-package user)

(preserve)         ; save definitions on a file "ccl.img" or wherever


