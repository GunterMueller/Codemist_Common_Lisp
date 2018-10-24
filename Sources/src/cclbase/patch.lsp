;;
;; These are unreasonably slow and will not deal with things other than
;; simple 1-dimensional bit-arrays.
;;

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


(defun bit-and (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logand (getv-bit v1 i) (getv-bit v2 i))))
   v3)

(defun bit-andc1 (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logand (lognot (getv-bit v1 i)) (getv-bit v2 i))))
   v3)

(defun bit-andc2 (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logand (getv-bit v1 i) (lognot (getv-bit v2 i)))))
   v3)

(defun bit-eqv (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logeqv (getv-bit v1 i) (getv-bit v2 i))))
   v3)

(defun bit-ior (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logor (getv-bit v1 i) (getv-bit v2 i))))
   v3)

(defun bit-nand (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (lognot (logand (getv-bit v1 i) (getv-bit v2 i)))))
   v3)

(defun bit-nor (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (lognot (logor (getv-bit v1 i) (getv-bit v2 i)))))
   v3)

(defun bit-not (v1 &optional (v2 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v2 i (lognot (getv-bit v1 i))))
   v2)

(defun bit-orc1 (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logor (lognot (getv-bit v1 i)) (getv-bit v2 i))))
   v3)

(defun bit-orc2 (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logor (getv-bit v1 i) (lognot (getv-bit v2 i)))))
   v3)

(defun bit-xor (v1 v2 &optional (v3 (make-simple-bitvector (length v1))))
   (dotimes (i (length v1))
     (putv-bit v3 i (logneqv (getv-bit v1 i) (getv-bit v2 i))))
   v3)

