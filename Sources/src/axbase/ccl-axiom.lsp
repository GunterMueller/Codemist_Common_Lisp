;; for debugging, uncomment this
;;(load "tempdebug.lsp")
(in-package "BOOT")

#+:slow
(setq *use-u-files* NIL)
#-:slow
(setq *use-u-files* t)

(when *use-u-files* (load_source_database "cclwhereis3.lsp"))


(load "cclinterp/patches.lisp")

;; This is a defvar in patches.lisp. but can be made more specific here.
#+:saturn (setq |$saturn| 't)
#-:saturn (setq |$saturn| nil)

;; Needed until COERCE works properly MCD
(DEFUN |lispType| (|u|)
  (COND
    ((LISTP |u|) (|lispType| (CAR |u|)))
    ((BOOT-EQUAL |u| (QUOTE |real|)) (QUOTE SHORT-FLOAT))
    ((BOOT-EQUAL |u| (QUOTE |double|)) (QUOTE DOUBLE-FLOAT))
    ((BOOT-EQUAL |u| (QUOTE |double precision|)) (QUOTE DOUBLE-FLOAT))
    ((BOOT-EQUAL |u| (QUOTE |integer|)) (QUOTE INTEGER))
    ((BOOT-EQUAL |u| (QUOTE |logical|)) (QUOTE BOOLEAN))
    ((BOOT-EQUAL |u| (QUOTE |character|)) (QUOTE CHARACTER))
    ((BOOT-EQUAL |u| (QUOTE |complex|)) (QUOTE SHORT-FLOAT))
    ((BOOT-EQUAL |u| (QUOTE |double complex|)) (QUOTE DOUBLE-FLOAT))
    ('T (|error| (CONS (MAKESTRING "Unrecognised Fortran type: ") (LIST |u|))))
  )
)

(in-package "LISP")
;; following are inits needed by fasl reader
(setq documentation nil)
(setq struct-documentation nil)
(setq function-documentation nil)

(setq *pwrds nil) ;; prevents printing of specials in functions

(in-package "FOAM")
;;following from foam_l.lsp patch around problem with (format nil "~G"
(defun |formatSFloat| (x) (format nil "~E" x))
(defun |formatDFloat| (x) (format nil "~E" x))
(defun |printSFloat| (cs x) (format cs "~E" x))
(defun |printDFloat| (cs x) (format cs "~E" x))

;; This redef can be removed if axiomxl 1.1.8 or later is used.
;;(defun foam::|fiStrHash| (x) 
;;  (boot::|hashString| (subseq x 0 (- (length x) 1))))

(in-package "BOOT")
(load "try2.lsp") ;; Fix-ups for AXIOM interpreter packages

(in-package "BOOT")

#+:saturn (load "axutil.lsp")

;; Cover up definition in daase.lisp
(defun initial-getdatabase () (print "initial-getdatabase called"))

(initroot (system::getenv "AXIOM"))
(|resetWorkspaceVariables|) ;; from util.lisp
(|initHist|)
(|initNewWorld|)
(resethashtables)

(print "loading A# stuff ...")
(setq foam-user::|G-axiom| (list #'identity))


;;following cannot autoload due to fasl bugs
(load "cclinterp/parsing.lisp")

(load "trap.lsp")
(setq |$BreakMode| '|resume|)
(defun myrestart () (progn (restart) (load nil :print t)))

;; MCD autoload stuff
(load "autoload.lsp")

#-:saturn (verbos 2) 
#+:saturn (verbos 0)

(mapstore 0) ;; reset counters
;; PAB: Load the saturn decoder...
#+:saturn (setq |$standard| nil)
#+:saturn (load "saturn.clisp")

;; instead of sending to $algebraOutputStream
#+:saturn (defun |sayMSG| (x) (if x (saybrightly1 x *standard-output*)))


#+:saturn (in-package "BOOT")
#+:saturn (defun VMLISP::call-saturn () (BOOT::call-saturn))


(when *use-u-files* 
      (save_source_database "cclwhereis.lsp")
      (clear_source_database)

#-:slow
(progn
    (let ((*print-array* t))
         (defun c::install (a b c) (c::install1 a b c))
         (defun c::install1 (rootname realname env)
           ;; call this function c::install1 in the debugging case...
            (let* ((n (length env))
                   (v (mkvect n)))
               (dotimes (i n) (putv v i (pop env)))
               (symbol-set-env rootname v)
               (princ "!!!Defining ") (prin realname) (princ " from ")
               (prin rootname) (terpri)
               (lisp::symbol-protect realname nil)
               (symbol-set-definition realname rootname)
               (lisp::symbol-protect realname t)))
         (verbos t)
	 (load "u01.lsp")
	 (load "u02.lsp")
	 (load "u03.lsp")
	 (load "u04.lsp")
	 (load "u05.lsp")
	 (load "u06.lsp")
	 (load "u07.lsp")
	 (load "u08.lsp")
	 (load "u09.lsp")
	 (load "u10.lsp")
	 (load "u11.lsp")
	 (load "u12.lsp")
	 ))
)
(display-keywords)
(mapstore 0) ;; reset counters

(print "about to start ... ")

(CATCH '|top_level| (|start| :fin))
;; swift and unsubtle hacks for A# types.
#-:saturn
(progn (|abbreviationsSpad2Cmd| '(|domain|  |IVCOO4| |IVCoordinate4|))
       (|abbreviationsSpad2Cmd| '(|domain|  |IVNCON| |IVNodeConnection|))
       (|abbreviationsSpad2Cmd| '(|domain|  |INTER| |Interval|))
       (|abbreviationsSpad2Cmd| '(|domain|  |IVREND| |InventorRenderPackage|))
       (|abbreviationsSpad2Cmd| '(|domain|  |IVVPORT| |InventorViewPort|)))

#+:saturn
(progn (|abbreviationsSpad2Cmd| '(|domain|  |VIEW2D| |TwoDimensionalViewport|))
       (|abbreviationsSpad2Cmd| '(|domain|  |VIEW3D| |ThreeDimensionalViewport|))
       (|abbreviationsSpad2Cmd| '(|package| |NAGD01| |NagIntegrationPackage|))
       (|abbreviationsSpad2Cmd| '(|package| |NAGS|   |NagSpecialFunctionsPackage|)))

#-:saturn (preserve 'myrestart)
#+:saturn (preserve)
