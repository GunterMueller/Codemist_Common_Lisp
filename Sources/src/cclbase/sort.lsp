
;;;; Sorting

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


(defvar ~predicate)
(defvar ~tail)
(defvar ~key)
(defvar ~keyp)

(defmacro nondescending (a b)
   `(if ~keyp
        (not (funcall ~predicate (funcall ~key ,b) (funcall ~key ,a)))
        (not (funcall ~predicate ,b ,a))))


(defun sort-list (l)
   ;; This merge-sort is stable, so I do not need a separate piece
   ;; of code for stable-sort on lists
   (if (endp l)
       nil
       (let (n (w l) ~tail)
          ;; I find the first run of non-descending items in the input
          (while
             (and
                (not (endp (setq ~tail (cdr l))))
                (nondescending (car l) (car ~tail)))
             (setq l ~tail))
          (rplacd l nil)
          (unless (endp ~tail)
             (setq n 0)
             (while ~tail
                (setq w (merge-to-list w (sort-select n)))
                (setq n (\1+ n))))
          w)))

(defun sort-select (n)
   ;; grab up to 2^n items from the front of ~tail
   (if (endp ~tail)
       nil
       (let ((p ~tail) q w)
         (block nil
            (cond
               ((endp (setq q (cdr p)))
                  ;; singleton list was left
                  (setq ~tail nil)
                  (return-from nil p))
               ((endp (setq w (cdr q)))
                  (setq ~tail nil)
                  (if (nondescending (car p) (car q))
                      (return-from nil p)
                      (progn
                        (rplacd q p)
                        (rplacd p nil)
                        (return-from nil q))))
               ;; here the remaining input is at least 3 items long
               ;; with p, q, r being the 3 front cons cells
               ((nondescending (car p) (car q))
                     (cond
                        ((nondescending (car q) (car w))
                              ;; fill out the run with whatever more is
                              ;; non-descending.
                              (setq q w)
                              (while (and
                                    (not (endp (setq w (cdr q))))
                                    (nondescending (car q) (car w)))
                                 (setq q w))
                              (setq ~tail w)
                              (rplacd q nil))
                        ((nondescending (car p) (car w))
                              (setq ~tail (cdr w))
                              (rplacd p w)
                              (rplacd q nil)
                              (rplacd w q))
                        (t    (setq ~tail (cdr w))
                              (rplacd w p)
                              (rplacd q nil)
                              (setq p w))))
               ((nondescending (car p) (car w))
                     (setq ~tail (cdr w))
                     (rplacd p w)
                     (rplacd q p)
                     (rplacd w nil)
                     (setq p q))
               ((nondescending (car q) (car w))
                     (setq ~tail (cdr w))
                     (rplacd w p)
                     (rplacd p nil)
                     (setq p q))
               (t    (setq ~tail (cdr w))
                     (rplacd p nil)
                     (rplacd q p)
                     (rplacd w q)
                     (setq p w)))
            (if (or (endp ~tail) (= n 0))
                (return-from nil p))
            (setq q 0)
            (while (and (< q n) (not (endp ~tail)))
                  (setq p (merge-to-list p (sort-select q)))
                  (setq q (\1+ q)))
            (return-from nil p)))) )

(defun merge-to-list (l1 l2)
   (cond
      ((endp l1) l2)
      ((endp l2) l1)
      (t (let (s p)
            (block nil (tagbody
               ;; I found this code seemed to want labels in it.
               (if (nondescending (car l1) (car l2))
                   (setq s l1 p s l1 (cdr l1))
                   (progn
                      (setq s l2 p l2 l2 (cdr l2))
                      (go movel2)))
     movel1    (when (endp l1)
                     (rplacd p l2)
                     (return-from nil s))
               (when (nondescending (car l1) (car l2))
                     (setq p l1 l1 (cdr l1))
                     (go movel1))
               (rplacd p l2)
     movel2    (when (endp l2)
                     (rplacd p l1)
                     (return-from nil s))
               (when (not (nondescending (car l1) (car l2)))
                     (setq p l2 l2 (cdr l2))
                     (go movel2))
               (rplacd p l1)
               (go movel1)))))))


(defun sort-vector (v)
   (format t "sort-vector calls stable-sort-vector for now")
   (stable-sort-vector))

(defun stable-sort-vector (v)
   ;; I stable-sort vectors by copying to a list, sorting there and
   ;; then copying back into the vector.
   (let* ((len (length v))
          (w nil))
      (do ((i 0 (\1+ i)))
          ((= i len))
          (push (aref v i) w))
      (setq w (sort-list w))     ;; this is stable
      (do ((i 0 (\1+ i)))
          ((= i len) v)
          (setf (aref v i) (pop w)))))

(defun merge-to-simple (output-type v1 v2)
   (error "merge on vectors not supported yet"))

;;; Top-level entrypoints

(defun sort (l ~predicate &key ((:key ~key) nil ~keyp))
   (if (listp l)
       (sort-list l)
       (if (vectorp l)
           (sort-vector l)
           (error (format nil "Argument for sort is not a sequence (~S)" l)))))


(defun stable-sort (l ~predicate &key ((:key ~key) nil ~keyp))
   (if (listp l)
       (sort-list l)     ; the regular method I use is stable
       (if (vectorp l)
           (stable-sort-vector l)
           (error (format nil "Argument for stable-sort is not a sequence (~S)" l)))))


(defun merge (result-type seq1 seq2 ~predicate
              &key ((:key ~key) nil ~keyp))
   (case (type-specifier result-type)
         (list (unless (listp seq1) (setq seq1 (coerce seq1 'list)))
               (unless (listp seq2) (setq seq2 (coerce seq2 'list)))
               (merge-to-list seq1 seq2))
         ((simple-vector simple-string vector string array)
               (merge-to-simple result-type seq1 seq2))
         (t (error (format nil "~S: invalid output type specification."
                           result-type)))))



(defun sort-2 (l ~predicate)
 (let ((~keyp))
   (if (listp l)
       (sort-list l)
       (if (vectorp l)
           (sort-vector l)
           (error (format nil "Argument for sort is not a sequence (~S)" l))))))


(defun stable-sort-2 (l ~predicate)
 (let ((~keyp))
   (if (listp l)
       (sort-list l)     ; the regular method I use is stable
       (if (vectorp l)
           (stable-sort-vector l)
           (error (format nil "Argument for stable-sort is not a sequence (~S)" l))))))


(defun merge-4 (result-type seq1 seq2 ~predicate)
 (let ((~keyp))
   (case (type-specifier result-type)
         (list (unless (listp seq1) (setq seq1 (coerce seq1 'list)))
               (unless (listp seq2) (setq seq2 (coerce seq2 'list)))
               (merge-to-list seq1 seq2))
         ((simple-vector simple-string vector string array)
               (merge-to-simple result-type seq1 seq2))
         (t (error (format nil "~S: invalid output type specification."
                           result-type))))))



