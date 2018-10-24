;; We only need this in ccl
;;

(defmacro |trappedSpadEval| (form) 
  `(let ((trapval (errorset ',form t lisp::*backtrace)))
      (if (consp trapval) (car trapval)
        '|restart|)))

(DEFUN |runspad| NIL  
  (PROG (|mode|) 
	(RETURN 
	 (SEQ 
	  (PROGN 
	   (SPADLET |mode| (QUOTE |restart|)) 
	   (DO 
	    NIL 
	    ((NULL (BOOT-EQUAL |mode| (QUOTE |restart|))) NIL) 
	    (SEQ 
	     (EXIT 
	      (PROGN 
	       (|resetStackLimits|) 
	       (CATCH |$quitTag|  
		      (CATCH  (QUOTE |coerceFailure|) 
			      (SPADLET |mode| 
				       (CATCH (QUOTE |top_level|) 
					      (|trappedSpadEval| (|ncTopLevel|))))))))))))))) 


