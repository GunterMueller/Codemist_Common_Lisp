
;;; Array and vector support

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


(defun make-array (dimensions &key
      (element-type t)
      (initial-element nil ivp)
      (initial-contents nil icp)
      (adjustable nil)
      (fill-pointer nil)
      (displaced-to nil disp)
      (displaced-index-offset 0)
      (confuse-compiler nil)
      &aux v rep size (onedim nil))
;(format t "make-array ~s ~s ~s ~s ~s ~s ~s~%"
;  dimensions element-type initial-element initial-contents adjustable
;  fill-pointer displaced-to)
   (if (integerp dimensions)
       (setq dimensions (list dimensions) onedim t)
       (when (= (length dimensions) 1) (setq onedim t)))

   (when (or (and ivp icp) (and ivp disp) (and icp disp))
       (error "Array can only have initial contents specified one way"))

   (when (and onedim
              (not adjustable)
              (null fill-pointer)
              (not disp))
;; Here I can make a simple vector, which is the sort of structure
;; that the underlying system really works in terms of.
      (cond
         ((or (eq element-type 'string-char)
              (eq element-type 'character))
            (setq v (make-simple-string (car dimensions)))
            (when ivp
               (dotimes (i (car dimensions)) (putv-char v i initial-element)))
            (when icp (array-init v dimensions initial-contents))
            (return-from make-array v))
         ((eq element-type 'bit)
            (setq v (make-simple-bitvector (car dimensions)))
            (when ivp
               (dotimes (i (car dimensions)) (putv-bit v i initial-element)))
            (when icp (array-init v dimensions initial-contents))
            (return-from make-array v))
         ((> (car dimensions) 32768) nil) ;; promote to non-simple
         (t (setq v (make-simple-vector (car dimensions)))
            (when ivp
               (dotimes (i (car dimensions)) (putv v i initial-element)))
            (when icp (array-init v dimensions initial-contents))
            (return-from make-array v))))

   (setq size 1)
   (dolist (n dimensions)
      (unless (and (integerp n) (<= 0 n array-dimension-limit))
         (error (format nil "Array dimension ~S is illegal" n)))
      (setq size (* size n)))

   (when (> size array-total-size-limit) ;; never really happens
      (error (format nil "Array ~S would be too large" dimensions)))

   (when (and fill-pointer (not onedim))
       (error "Only one-dimensional arrays are allowed fill-pointers"))

;; Get a simple vector to represent the object..
   (cond
      (disp (setq rep disp)
             (format t "~%!!! created displaced vector - dodgy!!!~%")
                   ) ; More needs doing here... indeed rather a lot!
                     ; In particular I may have "fun" if the vector displaced
                     ; to is itself complicated, or of a different type...
      (t (cond
            ((or (eq element-type 'string-char)
                 (eq element-type 'character))
               (setq rep (make-simple-string size)))
            ((eq element-type 'bit)
               (setq rep (make-simple-bitvector size)))
;; For GENERAL arrays that are not craeted using displaced-to I will support
;; cases where the total amount of data is more than would fit into a single
;; page in the CCL storage management regime. I do this by making the
;; representation of such an array a structure-object that has components
;; that are 8192-long general vector, these making up space for the data I
;; really want. Element zero of the structure holds the nominal upper bound
;; for the array size. I pad out the representation to a whole number of 8192
;; chunks. There will (at least to start with) be various things that I will
;; not support with over-large vectors of this sort:
;;      strings and bit-vectors (only general vectors will be handled)
;;      hash-value computation for such arrays under the EQUALP test. In fact
;;         an attempt to do that can crash the system to start with.
;;      EQUALP (and the Standard Lisp EQUAL) tests may crash
;;      big vectors that should have been created as SIMPLE by make-array
;;         will come back as non-simple. In consequence use of optimised code
;;         that tries to rely on simplicity can fail.
            ((> size 32768)
               (let ((chunks (floor (+ size 8191) 8192)) (v1))
                  (setq rep (make-simple-vector (1+ chunks)))
                  (putv rep 0 size)
                  (dotimes (i chunks)
                     (setq v1 (make-simple-vector 8192))
                     (when ivp
                        (dotimes (j 8192) (putv v1 j initial-element)))
                     (putv rep (1+ i) v1))
                  (setq ivp nil)
                  (when icp
                      (format t
                          "~%Initial contents for big array not supported~%")
                      (setq icp nil))
                  (setq rep (convert-to-struct rep))))
            (t (setq rep (make-simple-vector size))))
         (when ivp
             (dotimes (i size) (putvec rep i initial-element)))))

   (setq v (make-simple-vector 6))
   (putv v 0 element-type)
   (putv v 1 dimensions)
   (putv v 2 rep)
   (putv v 3 displaced-index-offset)
   (putv v 4 adjustable)
   (putv v 5 fill-pointer)

   (when icp (array-init rep dimensions initial-contents))

   (convert-to-array v))    



;; make-array-1 is used by the compiler when make-array has been called
;; without any of those ugly keyword arguments.

(defun make-array-1 (dimensions &aux v size)
  (if  (integerp dimensions)
      (if (<= dimensions 32768)
	  (return-from make-array-1 (make-simple-vector dimensions))
	(return-from make-array-1 (make-array (list dimensions)
					      :confuse-compiler t)))
    (when (and (= (length dimensions) 1)
	       (<= (car dimensions) 32768))
          (return-from make-array-1 (make-simple-vector (car dimensions)))))

   (setq size 1)
   (dolist (n dimensions)
      (unless (and (integerp n) (<= 0 n array-dimension-limit))
         (error (format nil "Array dimension ~S is illegal" n)))
      (setq size (* size n)))

   (when (> size 32768)   ;; cop out to the general slower case
      (return-from make-array-1 (make-array dimensions :confuse-compiler t)))

   (setq v (make-simple-vector 6))
   (putv v 0 t)
   (putv v 1 dimensions)
   (putv v 2 (make-simple-vector size))
   (putv v 3 0)
   (putv v 4 nil)
   (putv v 5 nil)

   (convert-to-array v))    

(defun array-element-type (v)
   (cond
      ((stringp v) 'character)
      ((simple-bit-vector-p v) 'bit)
      ((simple-vector-p v) t)
      (t (getv v 0))))


(defvar ~vector~)
(defvar ~posn~)

;; Warning - array-init does not cope with segmented-representation
;; general arrays (> 32768 elements). But who would want to create
;; one of those initialised elementwise anyway?  Well one answer is that
;; ADJUST-ARRAY uses that facility, so beware - adjusting an array where
;; either the ole or new is huge will give trouble. This can then happen
;; via VECTOR-PUSH-EXTEND.

(defun array-init (~vector~ dims cont)
   (when (and (simple-string-p ~vector~) (stringp cont))
         (setq cont (explodecn cont)))
   (let ((~posn~ 0))
      (array-init1 dims cont)))

(defun array-init1 (dims cont)
   (cond
      ((null dims) (putvec ~vector~ ~posn~ cont) (incf ~posn~))
      (t (dolist (w cont) (array-init1 (cdr dims) w)))))

;; (defun putvec (v n x)
;;    (cond
;;       ((simple-string-p v) (putv-char v n x))
;;       ((simple-bit-vector-p v) (putv-bit v n x))
;;       (t (putv v n x))))

(defun array-dimensions (a)
   (if (complex-arrayp a)
       (getv a 1)
       (list (1+ (upbv a)))))

(defun adjustable-array-p (a) 
   (and (complex-arrayp a) (getv a 4)))

(defun array-has-fill-pointer-p (a) 
   (and (complex-arrayp a) (getv a 5)))

(defun fill-pointer (a) (getv a 5))

(defun set-fill-pointer (a b) (putv a 5 b))

(defun vector-push (newelem a)
   (unless (complex-arrayp a) (error "not an array in vector-push"))
   (let ((dims (getv a 1))
         (fp  (getv a 5)))
      (unless fp (error "not an fill-pointer array in vector-push"))
      (setq dims (car dims))  ; must be 1-dimensional if it has fill ptr
      (if (= fp dims) nil   ; array is full up
          (progn (aset a fp newelem)
                 (putv a 5 (1+ fp))
                 fp))))

(defun vector-push-extend (newelem a &optional (extn 16))
   (unless (complex-arrayp a) (error "not an array in vector-push-extend"))
   (let ((dims (getv a 1))
         (fp  (getv a 5)))
      (unless fp (error "not an fill-pointer array in vector-push-extend"))
      (setq dims (car dims))  ; must be 1-dimensional if it has fill ptr
      (when (= fp dims) (setq a (adjust-array a (+ fp extn))))
      (aset a fp newelem)
      (putv a 5 (1+ fp))
      fp))

(defun vector-pop (a)
   (unless (complex-arrayp a) (error "not an array in vector-pop"))
   (let ((dims (getv a 1))
         (fp  (getv a 5)))
      (unless fp (error "not an fill-pointer array in vector-pop"))
      (setq dims (car dims))  ; must be 1-dimensional if it has fill ptr
      (when (= 0 fp) (error "empty array to vector-pop"))
      (putv a 5 (setq fp (1- fp)))
      (aref a fp)))

;; (defun aref (v n1 &rest r)
;;   (if (null r)
;;       (cond
;;          ((simple-vector-p v) (getv v n1))
;;          ((simple-string-p v) (schar v n1))
;;          ((simple-bit-vector-p v) (getv-bit v n1))
;;          ((structp v) (getv v n1))
;;          (t (general-aref v n1 r)))
;;       (general-aref v n1 r)))

;; (defun aset (v n1 x &rest r)
;;   (if (null r)
;;      (cond
;;         ((simple-vector-p v) (putv v n1 x))
;;         ((simple-string-p v) (putv-char v n1 x))
;;         ((simple-bit-vector-p v) (putv-bit v n1 x))
;;         ((structp v) (putv v n1 x))
;;         (t (general-aset v n1 x r)))
;;      (general-aset v n1 x r)))

;; (defun general-aref (v n1 r)
;;    (when (not (complex-arrayp v)) (error "aref ~s ~s" v (cons n1 r)))
;; ;  (format t "~%general-aref(~A, ~A :: ~A)~%" v n1 r)
;;    (do ((dd (cdr (getv v 1)) (cdr dd)))
;;        ((null r))
;;        (setq n1 (+ (* n1 (car dd)) (pop r))))
;; ;  (format t "dims = ~A, computed index = ~A~%" (getv v 1) n1)
;;;;;;;; Well it is even worst than this because of the possibility of
;;;;;;;; having a big array represented in segments.
;;    (aref (getv v 2) (+ (getv v 3) n1)))

;; (defun general-aset (v n1 x r)
;;    (when (not (complex-arrayp v)) (error "aref ~s ~s" v 
;;                  (reverse (cdr (reverse (cons n1 (cons x r)))))))
;; ;  (format t "~%general-aset(~A, ~A ~A ~A)~%" v n1 x r)
;;    (setq r (cons x r))
;;    (do ((dd (cdr (getv v 1)) (cdr dd)))
;;        ((null (cdr r)))
;;        (setq n1 (+ (* n1 (car dd)) (pop r))))
;; ;  (format t "dims = ~A, computed index = ~A~%" (getv v 1) n1)
;;;;;;;; Well it is even worst than this because of the possibility of
;;;;;;;; having a big array represented in segments.
;;    (aset (getv v 2) (+ (getv v 3) n1) (car r)))

;; (defun vectorp (x)
;;     (or (simple-vector-p x)
;;         (simple-string-p x)
;;         (simple-bit-vector-p x)
;;         (and (complex-arrayp x) (length-one-p (svref x 1)))))

;; (defun char (s n) 
;;    (cond
;;       ((simple-string-p s) (schar s n))
;;       (t (aref s n))))

;; (defun charset (s n c)
;;    (cond
;;       ((simple-string-p s) (putv-char s n c))
;;       (t (aset s n c))))

;; (defun make-string (len &key (initial-element #\ ))
;;    (let ((s (make-simple-string len)))
;;       (dotimes (i len) (charset s i initial-element))
;;       s))

;; (defun list-to-vector (old)
;;    (let* ((len (length old))
;;           (new (make-simple-vector len)))
;;       (dotimes (i len new) (putv new i (car old)) (setq old (cdr old)))))

(defun copy-vector (old)
;; At present this only copies simple general vectors...
   (let* ((len (vector-bound old))
          (new (make-simple-vector len)))
      (dotimes (i len new) (putv new i (svref old i)))))

;; (defun vector (&rest args)
;; ;; Note that a vector made this way can have at most 50 elements...
;;    (let* ((l (length args))
;;           (g (make-simple-vector l)))
;;       (dotimes (i l g)
;;           (putv g i (car args))
;;           (setq args (cdr args)))))

(defun adjust-array (array dims &rest r &key 
                     (element-type t)
                     (initial-element nil iep)
                     (initial-contents nil icp)
                     (fill-pointer nil)
                     (displaced-to nil disp)
                     (displaced-index-offset 0))
   (when (not (adjustable-array-p array)) (error "adjust-array"))
   (let ((new (apply #'make-array dims 
                     :element-type (getv array 0)
                     :initial-contents (getv array 2)
                     :adjustable t
                     r)))
      (putv array 1 (getv new 1))
      (putv array 2 (getv new 2))
      array))

;; For the order in which the following occur, see the C file "errors.h"
;; Note that this file must be changed whenever extra error codes are
;; added to "errors.h"

(defconstant *error-messages* (vector
    "Attempt to take CAR of the atom ~S."
    "Attempt to take CDR of the atom ~S."
    "No free store left."
    "No free store left."
    "Undefined function ~S."
    "Function ~S can not be called with ~A arguments."
    "Unbound lexical variable ~S."
    "Attempt to RPLAC on the atom ~S."
    "Bad argument for an arithmetic function: ~S."
    "Attempt to redefined the special-form name ~S."
    "Bad argument value: ~S."
    "Invalid DECLARE item: ~S."
    "Unable to interpret ~S as a function."
    "Reference to unset special variable ~S."
    "Ignoring the excess values."           ;; continuation message
    "Too many arguments provided."
    "Bad function object: ~S."
    "*macroexpand-hook* seems to be bad: ~S."
    "block/return tag not found: ~S."
    "tagbody/go tag not found: ~S."
    "function called with more than expected number of args."
    "function called with insufficient args."
    "syntax error in lambda-list: ~S."
    "bad use of keyword arguments: ~S."
    ))

