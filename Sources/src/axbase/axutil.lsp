;; CCLAXIOM_FUNC should be set to CALL-SATURN

;; Morally, this file exports the following functions:
;; axiom-get-command,
;; axiom-cmd-*
;; axiom-set-return-code

;; Lispified aoexport.h

(setq $First-saturn-call t)

(setq *expr* nil)

(defun call-saturn ()
  (let* ((cmd (axiom-get-command))
         (exprtype (axiom-cmd-expr-type cmd))
	 (local? (equal (axiom-cmd-extra2 cmd) "local"))
	 (filename (axiom-cmd-file-name cmd))
	 (frame (axiom-cmd-extra1 cmd)))
    (setq *expr* (axiom-cmd-expression cmd))
    (when $First-saturn-call
	  (reroot (getenv "AXIOM"))
	  (restart0)
	  (setq $First-saturn-call nil))
     (if local?
         (progn
	  (print (car (errorset '(eval (read-from-string *expr*)) t *backtrace)))
	  (terpri))
       (set-ax-return-code (|saturnToAxiom| filename frame *expr*)))))

(defun axiom-lisp-expression-type (n)
  (cond ((= n 1) 'axiom)
	((= n 2) 'boot)
	((= n 3) 'lisp)))

(defun axiom-return-failure-code (sym)
  (cond ((eq sym 'success) 		0)
	((eq sym 'success-no-output)	1)
	((eq sym 'interupt) 		16)
	((eq sym 'bad-file) 		17)
	((eq sym 'uninitialized) 	18)
	((eq sym 'no-handler)	 	19)
	((eq sym 'bad-argument) 	20)
	((eq sym 'internal-error) 	21)
	(t (error "bad command return type"))))

;; Cmd -> Sym
(defun axiom-cmd-expr-type (cmd)
  (axiom-lisp-expression-type (first cmd)))

;; Cmd -> String
(defun axiom-cmd-file-name (cmd)
  (second cmd))

(defun axiom-cmd-expression (cmd)
  (third cmd))

(defun axiom-cmd-extra1 (cmd)
  (fourth cmd))

(defun axiom-cmd-extra2 (cmd)
  (fifth cmd))

;; Symbol -> ()

(defun axiom-set-return-code (code)
  (set-ax-return-code (axiom-return-failure-code code)))

;; These functions wrap the (admittedly unpleasant) get-ax-char
;; interface to the saturn system.
;;

;; () -> Cmd
(defun axiom-get-command ()
  (let* ((cmd (+ (get-ax-char 0) (* 256 (get-ax-char 1))))
	 (file-and-end (get-ax-string 2))
	 (cmd-and-end  (get-ax-string (cdr file-and-end)))
	 (extra1-and-end  (get-ax-string (cdr cmd-and-end)))
	 (extra2-and-end  (get-ax-string (cdr extra1-and-end))))
    (list cmd
	  (car file-and-end)
	  (car cmd-and-end)
	  (car extra1-and-end)
	  (car extra2-and-end))))
	
(defun get-ax-string (n)
  (get-ax-list n nil))

(defun get-ax-list (n lst)
  (let ((c (get-ax-char n)))
    (if (= 0 c)
	(cons (list-to-string (nreverse lst)) (+ n 1))
      (get-ax-list (+ n 1)
		   (cons (code-char c)
			 lst)))))

;;; Sample i/face function.
(defun ax-command ()
  (let ((cmd (get-ax-cmd)))
    (print "In lisp:")
    (print (elt cmd 0))
    (print (elt cmd 1))
    (print (elt cmd 2))
    (print (elt cmd 3))))


