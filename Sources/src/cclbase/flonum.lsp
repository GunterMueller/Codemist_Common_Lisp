
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



(defun flonum-to-string (x &optional spaceleft fdig k fmin)
   (let (str len lpoint tpoint pointplace)
      (values str len lpoint tpoint pointplace))


         (multiple-value-bind
            (str len lpoint tpoint)
            (flonum-to-string (abs number) spaceleft d k)
         ;;if caller specifically requested no fraction digits, suppress the
            ;;optional trailing zero
            (when (and d (zerop d)) (setq tpoint nil))
            (when
               w
               (decf spaceleft len)
               ;;optional leading zero
               (when
                  lpoint
                  (if
                     (or (> spaceleft 0) tpoint)
                     ;force at least one digit
                     (decf spaceleft)
                     (setq lpoint nil)))
               ;;optional trailing zero
               (when
                  tpoint
                  (if (> spaceleft 0) (decf spaceleft) (setq tpoint nil))))




               (multiple-value-bind
                  (fstr flen lpoint tpoint)
                  (flonum-to-string num spaceleft fdig k fmin)
                  (when
                     w
                     (decf spaceleft flen)
                     (when tpoint (decf spaceleft))
                     (when
                        lpoint
                        (if
                           (> spaceleft 0)
                           (decf spaceleft)
                           (setq lpoint nil))))



         (multiple-value-bind
            (str len)
            (flonum-to-string (abs number))
            (let
               ((q (if (= len 1) 1 (\1- len))))
               (setq d (max q (min n 7)))) ))



         (multiple-value-bind
            (str ignore ignore ignore pointplace)
            (flonum-to-string number nil d nil)
            (when colon (write-string signstr))
            (dotimes (i spaceleft) (write-char pad))
            (unless colon (write-string signstr))
            (dotimes (i (- n pointplace)) (write-char #\0))
            (write-string str)))) )



