
;;; Operations on strings

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



;; (defun string (x)
;;   (cond
;;      ((stringp x) x)
;;      ((symbolp x) (symbol-name x))
;;      ((string-char-p x) (make-string 1 :initial-element x))
;;      (t (error "String expected, but found ~S" x))))

(defun string-compare (s1 s2 fn start1 end1 start2 end2)
   (let ((l1) (l2))
      (setq s1 (string s1))
      (setq s2 (string s2))
      (setq l1 (length s1) l2 (length s2))
      (when (null end1) (setq end1 l1))
      (when (null end2) (setq end2 l2))
      (unless (and (<= 0 start1 end1 l1) (<= 0 start2 end2 l2))
          (error "Bad start/end parameters for string comparison"))
      (unless (= (- end1 start1) (- end2 start2))
              (return-from string-compare nil))
      (loop
          (when (>= start1 end1) (return-from string-compare t))
          (unless (funcall fn (char s1 start1) (char s2 start2))
             (return-from string-compare nil))
          (setq start1 (1+ start1) start2 (1+ start2)))))

(defun string-compare1 (s1 s2 fn1 fn2 fn3 start1 end1 start2 end2)
;; scan (sub-) strings until fn2 shows up a difference.  If that happens
;; use fn1 to see what to return.  If the strings are equal as tested by fn2
;; then use fn3 to decide what to do.
   (let ((l1) (l2) (c1) (c2))
      (setq s1 (string s1))
      (setq s2 (string s2))
      (setq l1 (length s1) l2 (length s2))
      (when (null end1) (setq end1 l1))
      (when (null end2) (setq end2 l2))
      (unless (and (<= 0 start1 end1 l1) (<= 0 start2 end2 l2))
          (error "Bad start/end parameters for string comparison"))
      (loop
          (when (>= start1 end1)
                (return-from string-compare1
                   (if (>= start2 end2) ; Both strings exhausted
                       (funcall fn3 0 start1)
                       (funcall fn3 -1 start1))))
          (when (>= start2 end2)
             (return-from string-compare1 (funcall fn3 1 start1)))
          (setq c1 (char s1 start1) c2 (char s2 start2))
          (unless (funcall fn2 c1 c2)
             (return-from string-compare1
                 (if (funcall fn1 c1 c2) start1 nil)))
          (setq start1 (1+ start1) start2 (1+ start2)))))

(defun always-true (a b) t)

(defun string-compare-helper> (n v)
   (if (> n 0) v nil))

(defun string-compare-helper/= (n v)
   (if (= n 0) nil v))

(defun string-compare-helper< (n v)
   (if (< n 0) v nil))

(defun string-compare-helper>= (n v)
   (if (< n 0) nil v))

(defun string-compare-helper<= (n v)
   (if (> n 0) nil v))

;; In the case that the following are called WITHOUT the messy keyword
;; arguments the compiler converts calls into ones to internal code
;; that does the simple thing faster.

(defun string= (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare s1 s2 #'char=
      start1 end1 start2 end2))

(defun string/= (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare1 s1 s2 #'always-true #'char= #'string-compare-helper/=
      start1 end1 start2 end2))

(defun string< (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare1 s1 s2 #'char< #'char= #'string-compare-helper<
      start1 end1 start2 end2))

(defun string> (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare1 s1 s2 #'char> #'char= #'string-compare-helper>
      start1 end1 start2 end2))

(defun string>= (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare1 s1 s2 #'char>= #'char= #'string-compare-helper>=
      start1 end1 start2 end2))

(defun string<= (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare1 s1 s2 #'char<= #'char= #'string-compare-helper<=
      start1 end1 start2 end2))

(defun string-equal (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare s1 s2 #'char-equal
      start1 end1 start2 end2))

(defun string-not-equal (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare1 s1 s2 #'always-true #'char-equal #'string-compare-helper/=
      start1 end1 start2 end2)))

(defun string-lessp (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare1 s1 s2 #'char-lessp #'char-equal #'string-compare-helper<
      start1 end1 start2 end2))

(defun string-greaterp (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare1 s1 s2 #'char-greaterp #'char-equal #'string-compare-helper>
      start1 end1 start2 end2))

(defun string-not-lessp (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare1 s1 s2 #'char-not-lessp #'char-equal #'string-compare-helper>=
      start1 end1 start2 end2))

(defun string-not-greaterp (s1 s2 &key (start1 0) (end1 nil) (start2 0) (end2 nil))
   (string-compare1 s1 s2 #'char-not-greaterp #'char-equal #'string-compare-helper<=
      start1 end1 start2 end2))



(defun nstring-upcase (s &key (start 0) (end (length s)))
   (do
      ((i start (1+ i)))
      ((>= i end) s)
      (setf (char s i) (char-upcase (char s i)))))

(defun nstring-downcase (s &key (start 0) (end (length s)))
   (do
      ((i start (1+ i)))
      ((>= i end) s)
      (setf (char s i) (char-downcase (char s i)))))

(defun nstring-capitalize (s &key (start 0) (end (length s)))
   (do*
      ((fg t (not (alphanumericp c)))
       (i start (1+ i))
       (c))
      ((>= i end) s)
      (setq c (char s i))
      (setf (char s i) (if fg (char-upcase c) (char-downcase c)))))

(defun copy-string (str)
   (let* ((len (length str))
          (s (make-simple-string len)))
      (dotimes (i len)
         (setf (char s i) (char str i)))
      s))

(defun string-upcase (s &key (start 0) (end nil endp))
   (setq s (string s))
   (unless endp (setq end (length s)))
   (nstring-upcase (copy-string s) :start start :end end))

(defun string-downcase (s &key (start 0) (end nil endp))
   (setq s (string s))
   (unless endp (setq end (length s)))
   (nstring-downcase (copy-string s) :start start :end end))

(defun string-capitalize (s &key (start 0) (end nil endp))
   (setq s (string s))
   (unless endp (setq end (length s)))
   (nstring-capitalize (copy-string s) :start start :end end))


(defun string-trim1 (bag str l r)
   (setq str (string str))
   (let* ((len (length str))
          (lp 0)
          (rp (1- len)))
      (when l
         (do ()
            ((or (> lp rp)
                 (not (find (char str lp) bag :test #'char=))))
            (setq lp (1+ lp))))
      (when r
         (do ()
            ((or (< rp lp)
                 (not (find (char str rp) bag :test #'char=))))
            (setq rp (1- rp))))
      (if (and (= lp 0) (= rp len))
          str
          (subseq str lp (1+ rp)))))
             
(defun string-trim (bag string)
    (string-trim1 bag string t t))

(defun string-left-trim (bag string)
    (string-trim1 bag string t nil))

(defun string-right-trim (bag string)
    (string-trim1 bag string nil t))

