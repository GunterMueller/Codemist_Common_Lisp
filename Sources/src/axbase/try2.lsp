(in-package "VMLISP")

(setq optionlist nil)

(setq sortgreaterp #'ggreaterp)

(in-package "BOOT")

(defun readtablep (u) nil)

(defun |getEnv| (x) (getenv x))

(in-package "VMLISP")

(defun VMREAD (&optional (st *standard-input*) (eofval *read-place-holder*))
  (let ((val (read st)))
    (if (eq val $eof$) eofval val)))

(in-package "VMLISP")

;; position with keyword args not working properly
(defun STRPOSL (chars cvec pos negflag)
    (setq cvec (string cvec))
    (do ((i pos (1+ i)))
	((>= i (length cvec)) nil)
	(if (position (char cvec i) chars)
	    (if (not negflag) (return i))
	  (if negflag (return i)))
     ))

(in-package "BOOT")

(defun |functionp| (x) (functionp x))

(in-package "VMLISP")

(defun |nsubst| (a b c)
   (cond
      ((equal c b) a)
      ((atom c) c)
      (t
         (rplaca c (|nsubst| a b (car c)))
         (rplacd c (|nsubst| a b (cdr c)))
	 c) ))

(in-package "BOOT")

;;skip test for is-console
(defun |sayBrightlyNT| (x &optional (S *standard-output*))
  (COND ((NULL X) NIL)
	(|$sayBrightlyStream| (sayBrightlyNT1 X |$sayBrightlyStream|))
        (t (sayBrightlyNT1 X S)) ))

;;;; following are defvar and package problems from intint.lisp
;;(setq |$intCoerceFailure| '|coerceFailure|)
;;(setq |$intTopLevel| '|top_level|)
;;(setq |$intSpadReader| 'SPAD_READER)
;;(setq |$intRestart| '|restart|)

(in-package "VMLISP")

(defun msubst (a b c) (subst a b c)) ;; implies :test #'equal

(in-package "BOOT")

(defun |zeroOneTran| (sex) (subst '|$EmptyMode| '|?| sex))
	
(in-package "VMLISP")

(setq $current-directory "")
(setq |$defaultMsgDatabaseName| "s2-us.msgs")

(in-package "VMLISP")

(setq $spadroot (getenv "AXIOM"))

(in-package "BOOT")
;;following redef to cover up spadcomp version in redefs
(defun |sayMSG| (X)
  (if (NULL X) NIL (sayBrightly1 X |$algebraOutputStream|)))

;; (in-package "VMLISP")

;; (setq $filetype-table
;;   '((LISPLIB . |LILIB|)
;;     (SPADLIB . |slib|)
;;     (HISTORY . |hist|)
;;     (HELPSPAD . |help|)
;;     (INPUT . |input|)
;;     (SPAD . |spad|)
;;     (BOOT . |boot|)
;;     (LISP . |lsp|)
;;     (META . |meta|)
;;     (OUTPUT . |splog|)
;;     (ERRORLIB . |erlib|)
;;     (DATABASE . |DAASE|)
;;     (SPADDATA . |sdata|)
;;     (SPADFORT . |sfort|)
;;     (SPADFORM . |sform|)
;;     (SPADTEX . |stex|)
;;     (SPADOUT . |spout|)))

(in-package "BOOT")
(defun |addConsDB| (x) x) ;; redef from util.lisp

(in-package "VMLISP")
(defun GCMSG (x) x) ;; should turn on and off gc msgs

(in-package "BOOT")

(defun |unloadOneConstructor| (cnam modnam) 
    (remd cnam)
    (lisp::set-autoload cnam (list modnam)))

(defun lisp::prettyprint (x &optional (stream *standard-output*))
   (PROGN (SUPERPRINM X (POSN)) (TERPRI) NIL))

;;(defun boot::print-full (expr &optional (stream *standard-output*))
;;   (let ((*print-pretty* nil) (*print-circle* t) (*print-array* t) *print-level*
;; *print-length*)
;;     (print expr stream)
;;     (terpri stream)))

(defun |systemDependentMkAutoload| (modname funcname)
 (if (fboundp funcname) "next"
     (let ((asharpName (getdatabase funcname 'asharp?) ))
          (if asharpName
            (let ((kind  (getdatabase funcname 'constructorkind))
                  (cosig (getdatabase funcname 'cosig))
                  (file  (getdatabase funcname 'object)) )
                 (set-lib-file-getter file funcname) 
                 (if (equal kind 'category)
                     (asharpMkAutoLoadCategory file funcname asharpName cosig)
                     (asharpMkAutoLoadFunctor  file funcname asharpName cosig)))
            (lisp::set-autoload funcname (list (getdatabase funcname 'abbreviation)))))))

(defun |setAutoLoadProperty| (funcname) (remprop funcname 'loaded))

;; library files should put on loaded prop.
(defun |loadLib| (x)
  (unless (or (get x '|infovec|) (memq x '(|Record| |Mapping| |Union|)))
      (if (setq x (getdatabase x 'object))
	  (load-module (pathname-name x)))))

(defun |loadLibNoUpdate| (x y z) (|loadLib| x))

;; cover up redef in redefs.clisp
(DEFUN |pathname| (|p|) (COND ((NULL |p|) |p|) ((PATHNAMEP |p|) |p|) ((NULL (PAIRP |p|)) (PATHNAME |p|)) ((QUOTE T) (COND ((> (|#| |p|) 2) (SPADLET |p| (CONS (ELT |p| 0) (CONS (ELT |p| 1) NIL))))) (PATHNAME (APPLY (FUNCTION MAKE-FILENAME) |p|)))))

(in-package "BOOT")
;; patches for package reader problem
(defun |ncINTERPFILE| (file echo)
  (let ((|$EchoLines| echo) (|$ReadingFile| t))
    (declare (special |$EchoLines|))
    (declare (special |$ReadingFile|))
    (|SpadInterpretFile| file)) )

(in-package "VMLISP")
(defun bpiname (x)
   (if (symbolp x)
     (let ((func (symbol-function x)))
       (if (symbolp func)
	   (intern (symbol-name func) "BOOT")
	 nil))
    nil))

(in-package "BOOT")
;; instead of opening console stream for reading
(defun |queryUserKeyedMsg| (key args)
  (|sayKeyedMsg| key args)
  (read-line nil))

;;symEqual in pf2sex.boot can be called with numbers
(defun |symEqual| (sym str)
;  (and (or (symbolp sym) (stringp sym)) (equal (string sym) str)))
  (and (symbolp sym) (string= (symbol-name sym) str)))

(in-package "VMLISP")
(defun reclaim () (gc))

;; (setq *index-filename* "index.KAF")

(in-package "VMLISP")
;; FIXP checks in interop.boot need to be changed to
;; INTEGERP unless we can restrict type codes to fixnums.

(defun string-equal-test (u v) (and (stringp u) (stringp v) (string-equal u v)))

(defun |member| (item sequence)
   (cond ((symbolp item) (memq item sequence))
	 ((stringp item) (member item sequence :test #'string-equal-test))
	 ((and (atom item) (not (arrayp item))) (member item sequence))
	 (T (member item sequence :test #'equalp))))

(in-package "BOOT")
;; I believe this should be much faster
(defun |subCopy| (|t| SL) (sublis SL |t|)) ;; could probably use :test #'eq
;;check deepSubCopy ??

(in-package "VMLISP")
;;problems with output streams?
;; following is from extras.lsp
(defun prettyprint (x &optional (stream *standard-output*))
   (PROGN (SUPERPRINM X (POSN)) (TERPRI) NIL))

(defun divide (x y) (multiple-value-list (truncate x y)))
;; bug in compilation of multiple-value-call

(in-package "BOOT")
(defun divide2 (x y) (apply #'cons (divide x y)))

(defun |directoryp| (fn) (if (directoryp fn) 1 -1) )

(defun |writeablep| (s) (if (file-writeablep s) 1 0))

(in-package "VMLISP")
(defun makedir (fname) (create-directory fname))

(defun $FILEP (&rest filearg) (make-filename filearg))

(defun $ERASE (&rest filearg)
   (setq filearg (make-filename filearg))
   (if (probe-file filearg) (delete-file filearg))   )

