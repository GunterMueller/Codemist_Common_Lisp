;; These macros are all from parsing.lisp.  They need to be defined before
;; useby e.g. util.lisp.

(in-package "BOOT")

(defmacro IOStreams-Set (input output) `(setq in-stream ,input out-stream ,output))

(defmacro IOStreams-Clear (&optional (in t) (out t))
  `(progn (and (streamp in-stream) (close in-stream))
          (and (streamp out-stream) (close out-stream))
          (setq File-Closed nil)
          (IOStreams-Set ,in ,out)))

(defmacro Line-Clear (line)
  `(let ((l ,line))
     (setf (Line-Buffer l) (make-string 0)
           (Line-Current-Char l) #\Return
           (Line-Current-Index l) 1
           (Line-Last-Index l) 0
           (Line-Number l) 0)))

(defmacro stack-/-empty (stack) `(> (stack-size ,stack) 0))

(defmacro reduce-stack-clear () `(stack-load nil reduce-stack))

(defmacro pop-stack-1 () '(reduction-value (Pop-Reduction)))

(defmacro pop-stack-2 ()
  `(let* ((top (Pop-Reduction)) (next (Pop-Reduction)))
     (stack-push top Reduce-Stack)
     (reduction-value next)))

(defmacro pop-stack-3 ()
  `(let* ((top (Pop-Reduction)) (next (Pop-Reduction)) (nnext (Pop-Reduction)))
     (stack-push next Reduce-Stack)
     (stack-push top Reduce-Stack)
     (reduction-value nnext)))

(defmacro pop-stack-4 ()
  `(let* ((top (Pop-Reduction))
          (next (Pop-Reduction))
          (nnext (Pop-Reduction))
          (nnnext (Pop-Reduction)))
     (stack-push nnext Reduce-Stack)
     (stack-push next Reduce-Stack)
     (stack-push top Reduce-Stack)
     (reduction-value nnnext)))

(defmacro nth-stack (x)
  `(reduction-value (nth (1- ,x) (stack-store Reduce-Stack))))

(defmacro Star (lab prod)

"Succeeds if there are one or more of PROD, stacking as one unit
the sub-reductions of PROD and labelling them with LAB.
E.G., (Star IDs (parse-id)) with A B C will stack (3 IDs (A B C)),
where (parse-id) would stack (1 ID (A)) when applied once."

  `(prog ((oldstacksize (stack-size reduce-stack)))
         (if (not ,prod) ;(progn (format t "~&Star failed for ~A.~%" ',lab) (return nil)))
             (return nil))
    loop (if (not ,prod)
             (let* ((newstacksize (stack-size reduce-stack))
                    (number-of-new-reductions (- newstacksize oldstacksize)))
;              (format t "~&Starring ~A with ~D new reductions.~%"
;                      ',lab number-of-new-reductions)
               (if (> number-of-new-reductions 0)
                   (return (do ((i 0 (1+ i)) (accum nil))
                               ((= i number-of-new-reductions)
                                (Push-Reduction ',lab accum)
;                               (format t "~&Star accumulated ~D reductions.~%"
;                                       (length accum))
                                (return t))
                             (push (pop-stack-1) accum)))
                   (return t)))
             (go loop))))

(defmacro Bang (lab prod)

"If the execution of prod does not result in an increase in the size of
the stack, then stack a NIL. Return the value of prod."

  `(progn (setf (stack-updated reduce-stack) nil)
;         (format t "~&Banging ~A~:[~; and I think the stack is updated!~].~%" ',lab
;                 (stack-updated reduce-stack))
          (let* ((prodvalue ,prod)
                 (updated (stack-updated reduce-stack)))
;           (format t "~&Bang thinks that ~A ~:[didn't do anything~;did something~].~&"
;                   ',lab prodvalue)
            (if updated
                (progn ; (format t "~&Banged ~A and I think the stack is updated!~%" ',lab)
                       prodvalue)
                (progn (push-reduction ',lab nil)
                       ; (format t "~&Banged ~A.~%" ',lab)
                       prodvalue)))))

(defmacro must (dothis &optional (this-is nil) (in-rule nil))
  `(or ,dothis (meta-syntax-error ,this-is ,in-rule)))

(defmacro sequence (subrules &optional (actions nil))
  `(and ,(pop subrules) . ,(append (mapcar #'(lambda (x) (list 'must x)) subrules)
                         (if actions `((progn . ,(append actions '(t))))))))

(defmacro current-line-print () '(Line-Print Current-Line))

(defmacro current-line-show ()
  `(if (line-past-end-p current-line)
       (format t "~&The current line is empty.~%")
       (progn (format t "~&The current line is:~%~%")
              (current-line-print))))

(defmacro current-line-clear () `(Line-Clear Current-Line))

(defmacro test-lexing ()
  '(with-open-file (in-stream "lisp>meta.meta" :direction :input)
    (with-open-file (out-stream "lisp>foo.pars" :direction :output :if-exists :supersede)
      (loop (let ((z (advance-token)))
              (if z (Token-Print z out-stream) (return nil)))))))

(defmacro Defun-Parse-Token (token)
  `(defun ,(intern (concatenate 'string "PARSE-" (string token))) ()
     (let* ((tok (match-current-token ',token))
            (symbol (if tok (token-symbol tok))))
       (if tok (progn (Push-Reduction
                        ',(intern (concatenate 'string (string token)
                                               "-TOKEN"))
                        (copy-tree symbol))
                      (advance-token)
                      t)))))

(defmacro token-stack-clear ()
  `(progn (setq valid-tokens 0)
          (token-install nil nil current-token nil)
          (token-install nil nil next-token nil)
          (token-install nil nil prior-token nil)))

(defmacro tracemeta (&rest l) `(trmeta ',l))

