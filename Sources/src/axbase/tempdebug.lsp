(in-package 'BOOT)
#+:CCL
(defun break (&rest ignore) (lisp-break ignore) )

#+:CCL
(defun lisp-break (&rest ignore)
  (prog (prompt ifile ofile u v)
    (setq ifile (rds *debug-io*))
    (setq ofile (wrs *debug-io*))
    (setq prompt (setpchar "Break loop (:? for help)> "))
top (setq u (read))
    (cond
      ((equal u ':x) (go exit))
      ((equal u ':q)
        (progn (lisp::enable-backtrace nil) 
               (princ "Backtrace now disabled")
               (terpri)))
      ((equal u ':v)
        (progn (lisp::enable-backtrace t)
               (princ "Backtrace now enabled")
               (terpri)))
      ((equal u #\eof)
       (go exit))
      ((equal u ':?)
        (progn
           (princ ":Q   disables backtrace")
           (terpri)
           (princ ":V   enables backtrace")
           (terpri)
           (princ ":X   exits from break loop")
           (terpri)
           (princ "else enter LISP expressions for evaluation")
           (terpri)))
     (t (progn
           (setq v (errorset u nil nil))
           (if (listp v) (progn (princ "=> ") (prinl (car v)) (terpri))))) )
     (go top)
exit (rds ifile)
     (wrs ofile)
     (setpchar prompt)
     (return nil)))

(defun lisp-break-from-axiom (&rest ignore) 
    (boot::|handleLispBreakLoop| boot::|$BreakMode|))
#+:CCL (setq lisp:*break-loop* 'boot::lisp-break-from-axiom)


