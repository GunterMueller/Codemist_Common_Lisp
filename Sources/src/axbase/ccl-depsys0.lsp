;;
;; This starts to build bits of Axiom on top of CCL.
;;

(push :oldboot *features*)

(load "try1.lsp") ;; Fix-ups for the Lisp package

(in-package "LISP")
(setq *echo nil)
(setq *read-default-float-format* 'double-float)

(load "cclinterp/sys-pkg.lisp")

(in-package "VMLISP")
;; new divide of divide in ccl yields a dotted pair
(defun divide (x y) (multiple-value-list (truncate x y)))
(defvar boot::|$SessionManager| 'boot-session-manager)
(defvar boot::|$EndOfOutput| 'boot-end-of-output)

(load "parsing_macros.lisp") ;; For macro defs used by util.
(load "cclinterp/util.lisp")

;; start of OBJS
(load "cclinterp/vmlisp.lisp")
(load "cclinterp/hash.lisp")
(load "cclinterp/bootfuns.lisp")
(load "cclinterp/macros.lisp")
(load "cclinterp/spad.lisp")
(load "cclinterp/spaderror.lisp")
(load "cclinterp/unlisp.lisp")
(load "cclinterp/setq.lisp")
(load "cclinterp/bits.lisp")
(load "cclinterp/cfuns.lisp")
(load "cclinterp/comp.lisp")
(load "cclinterp/debug.lisp")
(load "cclinterp/fname.lisp")
(load "cclinterp/ggreater.lisp")
(load "cclinterp/nci.lisp")
(load "cclinterp/newaux.lisp")
(load "cclinterp/nlib.lisp")
(load "cclinterp/property.lisp")
(load "cclinterp/sfsfun-l.lisp")
(load "cclinterp/sockio.lisp")
(load "cclinterp/union.lisp")
;; end of OBJS

;; Objects from autoload metaparser sector
(load "cclinterp/parsing.lisp")
(load "cclinterp/bootlex.lisp")
(load "cclinterp/def.lisp")
(load "cclinterp/fnewmeta.lisp")
(load "cclinterp/metalex.lisp")
(load "cclinterp/metameta.lisp")
(load "cclinterp/postprop.lisp")
(load "cclinterp/preparse.lisp")

; end
; THE CLISP FILES we need
(load "cclinterp/postpar.clisp")
(load "cclinterp/g-boot.clisp")
(load "cclinterp/g-util.clisp")
(load "cclinterp/clam.clisp")
(load "cclinterp/slam.clisp")


(copy-module 'ccomp)

(preserve)


