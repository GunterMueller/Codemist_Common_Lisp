(in-package "LISP")
(defun probe-file (x) (and (filep x) x))
(defun compiled-function-p (x) (and (symbolp x) (symbol-function x)))
(defun functionp (x)
  (or (and (symbolp x) (symbol-function x)) (and (consp x) (eq (car x) 'funarg))))

(setq *default-pathname-defaults* "")

(defun bye (&optional (rc 0)) (stop rc))

(setq *print-array* nil)
;; undefined function temp def for BREAK
;(defun break (&rest foo) (|spadThrow|))
;; following version needed for the browser
(defun gentemp (&rest foo) (intern (gensym)))
(defun warn (&rest foo) nil)

(defun use-fast-links (&rest foo) foo)

(defun rassoc (a b) (find a b :key #'cdr))

(defun finish-output (&optional (st *standard-output*))
  (force-output st))

(export '(peek-char read-char read-line read-from-string nth logbitp
          integer-length nreconc probe-file parse-integer compiled-function-p
          functionp fboundp bye gentemp symbol-plist warn
          use-fast-links rassoc finish-output *print-array* 
          *default-pathname-defaults*))

;; Missing exports from CCL:
(export '(fill-vector))
