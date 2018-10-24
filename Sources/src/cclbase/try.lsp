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


(setq vmlisp::optionlist nil)

(defun boot::boot (&optional     ;; package system should do this for me!!!
              (*boot-input-file* nil)
              (*boot-output-file* nil))  (boot *boot-input-file*
                                               *boot-output-file*))

;; position with keyword args not working properly
(defun STRPOSL (chars cvec pos negflag)
    (setq cvec (string cvec))
    (do ((i pos (1+ i)))
	((>= i (length cvec)) nil)
	(if (position (char cvec i) chars)
	    (if (not negflag) (return i))
	  (if negflag (return i)))
     ))

;;(defun |trappedSpadEval| (x) x) ;; macro read too late?

(defun probe-file (x) (and (filep x) x))
(defun compiled-function-p (x) (and (symbolp x) (symbol-function x)))
(defun functionp (x)
  (or (and (symbolp x) (symbol-function x)) (and (consp x) (eq (car x) 'funarg))))
(defun |functionp| (x) (functionp x))
(defun fboundp (x) (functionp x))

(defun VMREAD (&optional (st *standard-input*) (eofval *read-place-holder*))
  (let ((val (read st)))
    (if (eq val $eof$) eofval val)))

(setq boot::$spadroot "/homes/axiom/somewhere")

(defun |nsubst| (a b c)
   (cond
      ((equal c b) a)
      ((atom c) c)
      (t 
         (rplaca c (|nsubst| a b (car c)))
         (rplacd c (|nsubst| a b (cdr c)))
	 c) ))

;;skip test for is-console
(defun |sayBrightlyNT| (x &optional (S *standard-output*))
  (COND ((NULL X) NIL)
	(|$sayBrightlyStream| (sayBrightlyNT1 X |$sayBrightlyStream|))
        (t (sayBrightlyNT1 X S)) ))

(setq pi 3.1415926535897931D0)

;; following turns off byte code compiler
;;(setq *comp nil)

;; fixes until there is a package reader
(defun specfnsf::|BesselI| (x y) (|BesselI| x y))
(defun specfnsf::|BesselJ| (x y) (|BesselJ| x y))
(defun specfnsf::|lnrgamma| (x) (|lnrgamma| x))
(defun specfnsf::|lncgamma| (x) (|lncgamma| x))
(defun specfnsf::|rgamma| (x) (|rgamma| x))
(defun specfnsf::|cgamma| (x) (|cgamma| x))
(defun specfnsf::|chebf01| (a z) (|chebf01| a z))
(defun specfnsf::|rPsi| (n x) (|rPsi| n x))
(defun specfnsf::|cPsi| (n z) (|cPsi| n z))

(defun spadcomp::|intloop| () (|intloop|))
(defun boot::|resetStackLimits| () ())
(defun boot::|serverReadLine| (st) (|serverReadLine| st))
(setq *standard-input* nil)
(setq boot::|$currentLine| nil)
(defun boot::expand-tabs (s) (expand-tabs s))
(defun boot::|processSynonyms| () (|processSynonyms|))
(defun boot::|doSystemCommand| (s) (|doSystemCommand| s))
(defun boot::|packageTran| (x) (|packageTran| x))
(defun boot::|processInteractive| (a b) (|processInteractive| a b))
(defun boot::|leaveScratchpad| () (bye))
(defun boot::|zeroOneTran| (x) (|zeroOneTran| x))
(defun boot::make-float (a b c d) (make-float a b c d))
(defun boot::|sayKeyedMsg| (a b) (|sayKeyedMsg| a b))
(defun boot::|spadThrow| () (|spadThrow|))
(define-function 'vmlisp::make-input-filename #'make-input-filename)
(define-function 'spadcomp::|SpadInterpretFile| #'|SpadInterpretFile|)

;; following are defvar and package problems from intint.lisp
(setq |$intCoerceFailure| '|coerceFailure|)
(setq |$intTopLevel| '|top_level|)
(setq |$intSpadReader| 'SPAD_READER)
(setq |$intRestart| '|restart|)
(defun boot::|sayKeyedMsg| (a b) (|sayKeyedMsg| a b))
(defun boot::|packageTran| (key) (|packageTran| key))
(defun boot::|spadThrow| () (|spadThrow|))

(defun |intSetQuiet| ()
  (setq boot::|$QuietCommand| T)
  (setq |$QuietCommand| t))

(defun |intUnsetQuiet| ()
  (setq boot::|$QuietCommand| NIL)
  (setq |$QuietCommand| nil))

(defun |setCurrentLine| (s)
  (setq |$currentLine|
	(cond ((null |$currentLine|) s)
	      ((stringp |$currentLine|)
	       (cons |$currentLine|
			 (if (stringp s) (cons s nil) s)))
	      (t (rplacd (last |$currentLine|)
			 (if (stringp s) (cons s nil) s))
		 |$currentLine|))))

(defun |intnplisp| (s)
 (setq |$currentLine| s)
 (boot::|nplisp| |$currentLine|))

(defun boot::|nplisp| (x) (|nplisp| x))

(defun msubst (a b c) (subst a b c)) ;; implies :test #'equal
(defun |zeroOneTran| (sex) (subst '|$EmtpyMode| '|?| sex))
	
(setq $current-directory "")
(setq |$defaultMsgDatabaseName| "s2-us.msgs")
(setq *default-pathname-defaults* "")
(defun si::getenv (x) (getenv x))
(setq $spadroot (getenv "AXIOM"))
(setq boot::$spadroot $spadroot)

;;following redef to cover up spadcomp version in redefs
(defun |sayMSG| (X)
  (if (NULL X) NIL (sayBrightly1 X |$algebraOutputStream|)))

(setq $filetype-table 
  '((LISPLIB . |LILIB|)
    (SPADLIB . |slib|)
    (HISTORY . |hist|)
    (HELPSPAD . |help|)
    (INPUT . |input|)
    (SPAD . |spad|)
    (BOOT . |boot|)
    (LISP . |lsp|)
    (META . |meta|)
    (OUTPUT . |splog|)
    (ERRORLIB . |erlib|)
    (DATABASE . |DAASE|)
    (SPADDATA . |sdata|)
    (SPADFORT . |sfort|)
    (SPADFORM . |sform|)
    (SPADTEX . |stex|)
    (SPADOUT . |spout|)))

(defun |addConsDB| (x) x) ;; redef from util.lisp
(|resetWorkspaceVariables|) ;; from util.lisp
(|initHist|)
(|initNewWorld|)

;
; ACN can not find mention of the garbade collector or how to control
; it in CLTL, but can implement more or less whatever you want! Let me know.
;

(defun GCMSG (x) (verbos x)) ;; should turn on and off gc msgs


;; following turns off ccl read prompts
(setpchar nil)

;; SpadInterpretStream in int-top.boot was wrongly resetting InteractiveMode
;; saved by the fact that the symbols are in SPADCOMP package

;(interpopen)
(defun gbc (&rest foo) nil)

(resethashtables)
;;(set-autoload 'fn '(mod1 mod2 ... modn))
;; fn is a function, modi are load modules

(defun |systemDependentMkAutoload| (modname funcname)
   (unless (or (symbol-function funcname)
	       (memq funcname '(|Record| |Mapping| |Union|)))
       (set-autoload funcname (list modname))))

(|start| :fin)
;(resethashtables)

;; library files should put on loaded prop.
(defun |loadLib| (x)
  (unless (or (get x '|infovec|) (memq x '(|Record| |Mapping| |Union|)))
      (if (setq x (getdatabase x 'object)) 
	  (load-module (pathname-name x)))))

(load-module 'SYMBOL) ;; convers up bogus def in unlisp.lisp

;; cover up redef in redefs.clisp
(DEFUN |pathname| (|p|) (COND ((NULL |p|) |p|) ((PATHNAMEP |p|) |p|) ((NULL (PAIRP |p|)) (PATHNAME |p|)) ((QUOTE T) (COND ((> (|#| |p|) 2) (SPADLET |p| (CONS (ELT |p| 0) (CONS (ELT |p| 1) NIL))))) (APPLY (FUNCTION MAKE-FILENAME) |p|))))
(defun pathname (x) x)

;; patched to avoid calling format which doesn't work yet
;; uses (list-to-string (explode n))
(DEFUN |normalizeStatAndStringify| (|t|) (PROG (K M) (RETURN (COND ((RNUMP |t|) (SPADLET |t| (|roundStat| |t|)) (COND ((BOOT-EQUAL |t| 0.0) (MAKESTRING "0")) ((QUOTE T) (list-to-string (explode |t|))))) ((INTP |t|) (SPADLET K 1024) (SPADLET M (TIMES K K)) (COND ((> |t| (TIMES 9 M)) (CONCAT (STRINGIMAGE (QUOTIENT (PLUS |t| (TIMES 512 K)) M)) (MAKESTRING "M"))) ((> |t| (TIMES 9 K)) (CONCAT (STRINGIMAGE (QUOTIENT (PLUS |t| 512) K)) (MAKESTRING "K"))) ((QUOTE T) (STRINGIMAGE |t|)))) ((QUOTE T) (STRINGIMAGE |t|))))))

;; patches for package reader problem
(defun |ncINTERPFILE| (file echo)
  (let ((|$EchoLines| echo) (|$ReadingFile| t))
    (declare (special |$EchoLines|))
    (declare (special |$ReadingFile|))
    (spadcomp::|SpadInterpretFile| file)) )

(defun bpiname (x) 
   (if (symbolp x)
     (intern (symbol-name (symbol-function x)) "BOOT")
    nil))

;; instead of opening console stream for reading
(defun |queryUserKeyedMsg| (key args)
  (|sayKeyedMsg| key args)
  (read-line nil))

;;symEqual in pf2sex.boot can be called with numbers
(defun |symEqual| (sym str)
  (and (or (symbolp sym) (stringp sym)) (equal (string sym) str)))


;; following redefines bad def in varini.cli
(setq |$timerTicksPerSecond| INTERNAL-TIME-UNITS-PER-SECOND)
(defun bye (&optional (rc 0)) (stop rc))
(defun obey (s) (system s)) ;; until built with new vmlisp

(defun reclaim () (gc))
(setq *print-array* nil)
;; undefined function temp def for BREAK
(defun break (&rest foo) (|spadThrow|))
(defun gentemp (&optional (prefix "T") (p *package*))
    (do ((a (gensym prefix) (gensym prefix)))
         ()
       (multiple-value-bind (b found) (intern a p)
         (when (null found) (return-from gentemp b)))))
(defun use-fast-links (&rest foo) foo)
;; following needed until compile accepts atoms
;(defun compile-defun (name body) (eval body) (compile (list name)))
(defun string (s) ;; needs to handle character codes
   (cond ((stringp s) s)
         ((symbolp s) (symbol-name s))
         ((characterp s) (make-string 1 :initial-element s))
         ((fixp s) (make-string 1 :initial-element (code-char s)))
         ((error "Invalid arg to STRING."))))

;; need to add special declarations
(defun |makeInternalMapMinivectorName| (name)
   (setq name (INTERN (STRCONC (STRING name) ";MV")))
   (proclaim (list 'special name))
   name)

(defun |mkCacheName| (name)
   (setq name (INTERNL (STRING name) ";AL"))
   (proclaim (list 'special name))
   name)

(defun FLOAT (x) (* x 1.0l0))

(defun |makeSF| (mantissa exponent)
   (scale-float (float mantissa) exponent))

;; following to overcome problems with package reader for foam

(defun process-import-entry (entry) (foam::process-import-entry entry))
(defun foam::asharp-file-init-name (filename) (asharp-file-init-name filename))
(defun foam::asharp-global-name (a b c) (asharp-global-name a b c))

(defun lisp::delete (&rest foo) (apply #'delete foo))

(defun si::getenv (x) (getenv x))

;; asharp support without closures
(defun set-file-getter (filename)
  (when (not (equal (pathname-type filename) "o"))
	(let ((getter-name (file-getter-name filename))
	      (lispfile
	       (concatenate 'string (directory-namestring filename)
			    (pathname-name filename) ".lsp")))
	  (load lispfile)
	  (|CCall| (eval getter-name)))))

(defun asharpMkAutoLoadFunctor (file cname asharp-name cosig)
  (let ((func (getconstructor (eval (file-getter-name file)) asharp-name)))
    (setf (symbol-function cname)
	  (if (vectorp (car func))
	      `(lambda () ',func)
	    `(lambda (&rest args)
	       (apply ',(|ClosFun| func)
		      (nconc
		        (mapcar #'wrapDomArgs args ',(cdr cosig))

			(list ',(|ClosEnv| func)))))))))

(defun asharpMkAutoLoadCategory (file cname asharp-name cosig)
  (asharpMkAutoLoadFunctor file cname asharp-name cosig)
  (let ((packname (INTERN (STRCONC cname '"&")))
	(func (getconstructor (eval (file-getter-name file)) asharp-name)))
    (setf (symbol-function packname)
	  (if (vectorp (car func))
	      `(lambda (self)
		 (|CCall| ',(elt (car func) 5) ',(cdr func)
		  (wrapDomArgs self t))) ;; constant category
	`(lambda (self &rest args)
	    (let ((precat
		   (apply ',(|ClosFun| func)
			  (nconc
			   (mapcar #'wrapDomArgs args ',(cdr cosig))
			   ',(list (|ClosEnv| func))))))
	      (|CCall| (elt (car precat) 5) (cdr precat) (wrapDomArgs self t))))))))

(setq |G-axiom| (list #'identity))

(set-file-getter "runtime.lsp")
(set-file-getter "lang.lsp")
(set-file-getter "axlit.lsp")
(set-file-getter "minimach.lsp")
(set-file-getter "axextend.lsp")

;; FIXP checks in interop.boot need to be changed to
;; INTEGERP unless we can restrict type codes to fixnums.
