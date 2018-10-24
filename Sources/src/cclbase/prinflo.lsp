
;;;; Float printing.

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

;;;
;;;  Written by Bill Maddox
;;;    (part of Public Domain CMU Common Lisp code)
;;;
;;;
;;;
;;; FLONUM-TO-STRING (and its subsidiary function FLOAT-STRING) does most of 
;;; the work for all printing of floating point numbers in the printer and in
;;; FORMAT.  It converts a floating point number to a string in a free or 
;;; fixed format with no exponent.  The interpretation of the arguments is as 
;;; follows:
;;;
;;;     X        - The floating point number to convert, which must not be
;;;                negative.
;;;     WIDTH    - The preferred field width, used to determine the number
;;;                of fraction digits to produce if the FDIGITS parameter
;;;                is unspecified or NIL.  If the non-fraction digits and the
;;;                decimal point alone exceed this width, no fraction digits
;;;                will be produced unless a non-NIL value of FDIGITS has been
;;;                specified.  Field overflow is not considerd an error at this
;;;                level.
;;;     FDIGITS  - The number of fractional digits to produce. Insignificant
;;;                trailing zeroes may be introduced as needed.  May be
;;;                unspecified or NIL, in which case as many digits as possible
;;;                are generated, subject to the constraint that there are no
;;;                trailing zeroes.
;;;     SCALE    - If this parameter is specified or non-NIL, then the number
;;;                printed is (* x (expt 10 scale)).  This scaling is exact,
;;;                and cannot lose precision.
;;;     FMIN     - This parameter, if specified or non-NIL, is the minimum
;;;                number of fraction digits which will be produced, regardless
;;;                of the value of WIDTH or FDIGITS.  This feature is used by
;;;                the ~E format directive to prevent complete loss of
;;;                significance in the printed value due to a bogus choice of
;;;                scale factor.
;;;
;;; Most of the optional arguments are for the benefit for FORMAT and are not
;;; used by the printer.
;;;
;;; Returns:
;;; (VALUES DIGIT-STRING DIGIT-LENGTH LEADING-POINT TRAILING-POINT DECPNT)
;;; where the results have the following interpretation:
;;;
;;;     DIGIT-STRING    - The decimal representation of X, with decimal point.
;;;     DIGIT-LENGTH    - The length of the string DIGIT-STRING.
;;;     LEADING-POINT   - True if the first character of DIGIT-STRING is the
;;;                       decimal point.
;;;     TRAILING-POINT  - True if the last character of DIGIT-STRING is the
;;;                       decimal point.
;;;     POINT-POS       - The position of the digit preceding the decimal
;;;                       point.  Zero indicates point before first digit.
;;;
;;; WARNING: For efficiency, there is a single string object *digit-string*
;;; which is modified destructively and returned as the value of
;;; FLONUM-TO-STRING.  Thus the returned value is not valid across multiple 
;;; calls.
;;;
;;; NOTE:  FLONUM-TO-STRING goes to a lot of trouble to guarantee accuracy.
;;; Specifically, the decimal number printed is the closest possible 
;;; approximation to the true value of the binary number to be printed from 
;;; among all decimal representations  with the same number of digits.  In
;;; free-format output, i.e. with the number of digits unconstrained, it is 
;;; guaranteed that all the information is preserved, so that a properly-
;;; rounding reader can reconstruct the original binary number, bit-for-bit, 
;;; from its printed decimal representation. Furthermore, only as many digits
;;; as necessary to satisfy this condition will be printed.
;;;
;;;
;;; FLOAT-STRING actually generates the digits for positive numbers.  The
;;; algorithm is essentially that of algorithm Dragon4 in "How to Print 
;;; Floating-Point Numbers Accurately" by Steele and White.  The current 
;;; (draft) version of this paper may be found in [CMUC]<steele>tradix.press.
;;; DO NOT EVEN THINK OF ATTEMPTING TO UNDERSTAND THIS CODE WITHOUT READING 
;;; THE PAPER!

(defvar *digits* "0123456789")

(defvar *digit-string*
  (make-array 50 :element-type 'base-char :fill-pointer 0 :adjustable t
	      :initial-element #\?)) ; ### Hack around make-array bug.

(defun flonum-to-string (x &optional width fdigits scale fmin)
  (cond ((zerop x)
	 ;;zero is a special case which float-string cannot handle
	 (if fdigits
	     (let ((s (make-string (1+ fdigits) :initial-element #\0)))
	       (setf (schar s 0) #\.)
	       (values s (length s) t (zerop fdigits) 0))
	     (values "." 1 t t 0)))
	(t
	 (setf (fill-pointer *digit-string*) 0)
	 (multiple-value-bind (sig exp)
			      (integer-decode-float x)
	   (let* ((precision (float-precision x))
		  (digits (float-digits x))
		  (fudge (- digits precision))
		  (width (if width (max width 1) nil)))
	   (float-string (ash sig (- fudge)) (+ exp fudge) precision width
			 fdigits scale fmin))))))


(defun float-string (fraction exponent precision width fdigits scale fmin)
  (let ((r fraction) (s 1) (m- 1) (m+ 1) (k 0)
	(digits 0) (decpnt 0) (cutoff nil) (roundup nil) u low high)
    ;;Represent fraction as r/s, error bounds as m+/s and m-/s.
    ;;Rational arithmetic avoids loss of precision in subsequent calculations.
    (cond ((> exponent 0)
	   (setq r (ash fraction exponent))
	   (setq m- (ash 1 exponent))	   
	   (setq m+ m-))                   
	  ((< exponent 0)
	   (setq s (ash 1 (- exponent)))))
    ;;adjust the error bounds m+ and m- for unequal gaps
    (when (= fraction (ash 1 precision))
      (setq m+ (ash m+ 1))
      (setq r (ash r 1))
      (setq s (ash s 1)))
    ;;scale value by requested amount, and update error bounds
    (when scale
      (if (minusp scale)
	  (let ((scale-factor (expt 10 (- scale))))
	    (setq s (* s scale-factor)))
	  (let ((scale-factor (expt 10 scale)))
	    (setq r (* r scale-factor))
	    (setq m+ (* m+ scale-factor))
	    (setq m- (* m- scale-factor)))))
    ;;scale r and s and compute initial k, the base 10 logarithm of r
    (do ()
        ((>= r (ceiling s 10)))
      (decf k)
      (setq r (* r 10))
      (setq m- (* m- 10))
      (setq m+ (* m+ 10)))
    (do ()(nil)
      (do ()
	  ((< (+ (ash r 1) m+) (ash s 1)))
	(setq s (* s 10))
	(incf k))
      ;;determine number of fraction digits to generate
      (cond (fdigits
	     ;;use specified number of fraction digits
	     (setq cutoff (- fdigits))
	     ;;don't allow less than fmin fraction digits
	     (if (and fmin (> cutoff (- fmin))) (setq cutoff (- fmin))))
	    (width
	     ;;use as many fraction digits as width will permit
             ;;but force at least fmin digits even if width will be exceeded
	     (if (< k 0)
		 (setq cutoff (- 1 width))
		 (setq cutoff (1+ (- k width))))
	     (if (and fmin (> cutoff (- fmin))) (setq cutoff (- fmin)))))
      ;;If we decided to cut off digit generation before precision has
      ;;been exhausted, rounding the last digit may cause a carry propagation.
      ;;We can prevent this, preserving left-to-right digit generation, with
      ;;a few magical adjustments to m- and m+.  Of course, correct rounding
      ;;is also preserved.
      (when (or fdigits width)
	(let ((a (- cutoff k))
	      (y s))
	  (if (>= a 0)
	      (dotimes (i a) (setq y (* y 10)))
	      (dotimes (i (- a)) (setq y (ceiling y 10))))
	  (setq m- (max y m-))
	  (setq m+ (max y m+))
	  (when (= m+ y) (setq roundup t))))
      (when (< (+ (ash r 1) m+) (ash s 1)) (return)))
    ;;zero-fill before fraction if no integer part
    (when (< k 0)
      (setq decpnt digits)
      (vector-push-extend #\. *digit-string*)
      (dotimes (i (- k))
	(incf digits) (vector-push-extend #\0 *digit-string*)))
    ;;generate the significant digits
    (do ()(nil)
      (decf k)
      (when (= k -1)
	(vector-push-extend #\. *digit-string*)
	(setq decpnt digits))
      (multiple-value-setq (u r) (truncate (* r 10) s))
      (setq m- (* m- 10))
      (setq m+ (* m+ 10))
      (setq low (< (ash r 1) m-))
      (if roundup
	  (setq high (>= (ash r 1) (- (ash s 1) m+)))
	  (setq high (> (ash r 1) (- (ash s 1) m+))))
      ;;stop when either precision is exhausted or we have printed as many
      ;;fraction digits as permitted
      (when (or low high (and cutoff (<= k cutoff))) (return))
      (vector-push-extend (char *digits* u) *digit-string*)
      (incf digits))
    ;;if cutoff occured before first digit, then no digits generated at all
    (when (or (not cutoff) (>= k cutoff))
      ;;last digit may need rounding
      (vector-push-extend (char *digits*
				(cond ((and low (not high)) u)
				      ((and high (not low)) (1+ u))
				      (t (if (<= (ash r 1) s) u (1+ u)))))
			  *digit-string*)
      (incf digits))
    ;;zero-fill after integer part if no fraction
    (when (>= k 0)
      (dotimes (i k) (incf digits) (vector-push-extend #\0 *digit-string*))
      (vector-push-extend #\. *digit-string*)
      (setq decpnt digits))
    ;;add trailing zeroes to pad fraction if fdigits specified
    (when fdigits
      (dotimes (i (- fdigits (- digits decpnt)))
	(incf digits)
	(vector-push-extend #\0 *digit-string*)))
    ;;all done
    (values *digit-string* (1+ digits) (= decpnt 0) (= decpnt digits) decpnt)))

;;; SCALE-EXPONENT  --  Internal
;;;
;;;    Given a non-negative floating point number, SCALE-EXPONENT returns a new
;;; floating point number Z in the range (0.1, 1.0] and and exponent E such
;;; that Z * 10^E is (approximately) equal to the original number.  There may
;;; be some loss of precision due the floating point representation.  The
;;; scaling is always done with long float arithmetic, which helps printing of
;;; lesser precisions as well as avoiding generic arithmetic.
;;;
;;;    When computing our initial scale factor using EXPT, we pull out part of
;;; the computation to avoid over/under flow.  When denormalized, we must pull
;;; out a large factor, since there is more negative exponent range than
;;; positive range.
;;;
(defun scale-exponent (original-x)
  (let* ((x (coerce original-x 'long-float)))
    (if (float-infinity-p x) (values x 0)
    (multiple-value-bind (sig exponent)
			 (decode-float x)
      (declare (ignore sig))
      (if (= x 0.0l0)
	  (values (float 0.0l0 original-x) 1)
	  (let* ((ex (round (* exponent (log 2l0 10))))
		 (x (if (minusp ex)
			(if (float-denormalized-p x)
			    (* x 1.0l16 (expt 10.0l0 (- (- ex) 16)))
			    (* x 10.0l0 (expt 10.0l0 (- (- ex) 1))))
			(/ x 10.0l0 (expt 10.0l0 (1- ex))))))
	    (do ((d 10.0l0 (* d 10.0l0))
		 (y x (/ x d))
		 (ex ex (1+ ex)))
		((< y 1.0l0)
		 (do ((m 10.0l0 (* m 10.0l0))
		      (z y (* y m))
		      (ex ex (1- ex)))
		     ((>= z 0.1l0)
		      (values (float z original-x) ex)))))))))))

