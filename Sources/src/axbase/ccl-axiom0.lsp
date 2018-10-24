;;
;; This starts to build bits of Axiom on top of CCL.
;;

(clear_source_database)
(load_source_database "whereisA.lsp")

(load "try1.lsp") ;; Fix-ups for the Lisp package

(in-package "LISP")
(setq *echo nil)
(setq *read-default-float-format* 'double-float)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; First a bunch of patch-ups and fixes
(defun probe-file (x) (and (filep x) x))

;; (defvar internal-time-units-per-second 1000)
;; (defun get-internal-run-time () (time*))
;; also (gctime)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(load "cclinterp/sys-pkg.lisp")

(in-package "VMLISP")
;; new divide of divide in ccl yields a dotted pair
(defun divide (x y) (multiple-value-list (truncate x y)))
;; comment out def of READLINE in compat.boot for CCL?

(defvar boot::|$SessionManager| 'boot-session-manager)
(defvar boot::|$EndOfOutput| 'boot-end-of-output)

(load "parsing_macros.lisp") ;; For macro defs used by util.
(load "cclinterp/util.lisp")

;; start of OBJS

(load "cclinterp/vmlisp.lisp")
(load "cclinterp/hash.lisp")
(load "cclinterp/bootfuns.lisp")
;;(load "bootfuns.lisp")
(load "cclinterp/macros.lisp")
(load "cclinterp/spad.lisp")
(load "cclinterp/spaderror.lisp")
(load "cclinterp/unlisp.lisp")
(load "cclinterp/setq.lisp")
(load "cclinterp/astr.clisp")
(load "cclinterp/bits.lisp")
(load "cclinterp/alql.clisp")
(load "cclinterp/buildom.clisp")
(load "cclinterp/cattable.clisp")
(load "cclinterp/cformat.clisp")
(load "cclinterp/cfuns.lisp")
(load "cclinterp/clam.clisp")
(load "cclinterp/clammed.clisp")
(load "cclinterp/comp.lisp")
(load "cclinterp/compat.clisp")
(load "cclinterp/compress.clisp")
(load "cclinterp/cparse.clisp")
(load "cclinterp/cstream.clisp")
(load "cclinterp/database.clisp")
(load "cclinterp/debug.lisp")
(load "cclinterp/dq.clisp")
(load "cclinterp/fname.lisp")
(load "cclinterp/format.clisp")
(load "cclinterp/g-boot.clisp")
(load "cclinterp/g-cndata.clisp")
(load "cclinterp/g-error.clisp")
(load "cclinterp/g-opt.clisp")
(load "cclinterp/g-timer.clisp")
(load "cclinterp/g-util.clisp")
(load "cclinterp/ggreater.lisp")
(load "cclinterp/hypertex.clisp")
(load "cclinterp/i-analy.clisp")
(load "cclinterp/i-code.clisp")
(load "cclinterp/i-coerce.clisp")
(load "cclinterp/i-coerfn.clisp")
(load "cclinterp/i-eval.clisp")
(load "cclinterp/i-funsel.clisp")
(load "cclinterp/i-hist.clisp")
(load "cclinterp/i-intern.clisp")
(load "cclinterp/i-map.clisp")
(load "cclinterp/i-output.clisp")
(load "cclinterp/i-resolv.clisp")
(load "cclinterp/i-spec1.clisp")
(load "cclinterp/i-spec2.clisp")
(load "cclinterp/i-syscmd.clisp")
(load "cclinterp/msg.clisp")
(load "cclinterp/msgdb.clisp")
(load "cclinterp/i-toplev.clisp")
(load "cclinterp/i-util.clisp")
(load "cclinterp/incl.clisp")
(load "cclinterp/int-top.clisp")
(load "cclinterp/intfile.clisp")
(load "cclinterp/lisplib.clisp")
(load "cclinterp/macex.clisp")
(load "cclinterp/match.clisp")
(load "cclinterp/nci.lisp")
(load "cclinterp/newaux.lisp")
(load "cclinterp/newfort.clisp")
(load "cclinterp/nlib.lisp")
(load "cclinterp/nrunfast.clisp")
(load "cclinterp/nrungo.clisp")
(load "cclinterp/nrunopt.clisp")
(load "cclinterp/nruntime.clisp")
(load "cclinterp/osyscmd.clisp")
(load "cclinterp/packtran.clisp")
(load "cclinterp/pathname.clisp")
(load "cclinterp/pf2sex.clisp")
(load "cclinterp/pile.clisp")
(load "cclinterp/posit.clisp")
(load "cclinterp/property.lisp")
(load "cclinterp/ptrees.clisp")
(load "cclinterp/ptrop.clisp")
(load "cclinterp/record.clisp")
;; (load "redefs.clisp") ;; kill redef of |char|
(load "cclinterp/rulesets.clisp")
(load "cclinterp/scan.clisp")
(load "cclinterp/serror.clisp")
(load "cclinterp/server.clisp")
(load "cclinterp/setvars.clisp")
(load "cclinterp/sfsfun.clisp")
(load "cclinterp/sfsfun-l.lisp")
(load "cclinterp/simpbool.clisp")
(load "cclinterp/slam.clisp")
(load "cclinterp/sockio.lisp")
(load "cclinterp/template.clisp")
(load "cclinterp/termrw.clisp")
(load "cclinterp/trace.clisp")
(load "cclinterp/union.lisp")
(load "cclinterp/undo.clisp")
(load "cclinterp/fortcall.clisp")
(load "cclinterp/topics.clisp")
;; end of OBJS

;; start of ASCOMP
(load "cclinterp/hashcode.clisp")
(load "cclinterp/as.clisp")

(load "compiler/lib/foam_l.lsp")
(load "compiler/lib/axext_l.lsp")
;; end of ASCOMP

;; start of INOBJS
(load "cclinterp/varini.clisp")
(load "cclinterp/parini.clisp")
(load "cclinterp/setvart.clisp")
(load "cclinterp/intint.lisp")
(load "cclinterp/xrun.clisp")
(load "cclinterp/interop.clisp")
(load "cclinterp/daase.lisp") 
;; (load "cclinterp/patches.lisp") ;; Moved to axiom.lsp because of FLEX
;; end of INOBJS

(push :oldboot *features*)

(save_source_database "cclwhereis0.lsp")

(copy-module 'ccomp)

(preserve)


