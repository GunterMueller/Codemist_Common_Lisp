;
;  Copyright (c) 1991-2002, The Numerical Algorithms Group Ltd.
;  All rights reserved.
;  
;  Redistribution and use in source and binary forms, with or without
;  modification, are permitted provided that the following conditions are
;  met:
;  
;      - Redistributions of source code must retain the above copyright
;        notice, this list of conditions and the following disclaimer.
;  
;      - Redistributions in binary form must reproduce the above copyright
;        notice, this list of conditions and the following disclaimer in
;        the documentation and/or other materials provided with the
;        distribution.
;  
;      - Neither the name of The Numerical ALgorithms Group Ltd. nor the
;        names of its contributors may be used to endorse or promote products
;        derived from this software without specific prior written permission.
;  
;  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
;  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
;  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
;  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
;  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
;  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
;  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES-- LOSS OF USE, DATA, OR
;  PROFITS-- OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
;  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
;  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
;  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

;; Code for subtypep, designed to provide the facilities needed in AXIOM.
;;
;; Mike Dewar 20.10.95
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


(defconstant *float-types* '(double-float long-float short-float single-float))
(defconstant *integer-types* '(fixnum bignum))
(defconstant *number-types* '(float double-float long-float short-float 
                              single-float integer fixnum bignum ratio rational
                             ))
(defconstant *aggregate-list* '(array list sequence simple-array simple-vector
                                vector) ))

(defmacro predicate (u) `(values (if ,u 't 'nil) 't) )

(defun subtypep (type1 type2)
  (cond 
    ((equal type2 type1)    (values 't 't))
    ((equal type2 'float)   (predicate (member type1 *float-types*)))
    ((equal type2 'integer) (predicate (member type1 *integer-types*)))
    ((equal type2 'number)  (predicate (member type1 *number-types*)))
    ((or (listp type1) (listp type2)) 
                            (subtypep1 (simptype type1) (simptype type2)))
    ('t (values nil nil))
  )
)

(defun subtypep1 (type1 type2)
 (cond
   ((equal type2 type1)    (values 't 't))
   ((> (length type2) (length type1)) (values nil 't) )
   ((not (member (first type1) *aggregate-list*)) (values nil nil) )
   ((not (member (first type2) *aggregate-list*)) (values nil nil) )
   ((not (eq (first type1) (first type2))) (values nil 't) )
   ((onep (length type2)) (values 't 't))
   ((not (or (equal (second type1) (second type2)) (equal (second type2) '*)))
                             (values nil 't))
   ((equal 2 (length type2)) (values 't 't)) 
   ((equal (third type1) (third type2)) (values 't 't) )
   ('t (values nil 't))
 )
)

(defun strip-wildcards (u) (if (eqcar u '*) (strip-wildcards (cdr u)) u) )

(defun simptype (type)
 (cond
  ((atom type) (list type))
  ((> (length type) 3) (error "Type descriptor with more than 3 elements") )
  ('t (reversip (strip-wildcards (reversip type))))
 )
)

;; End of subtypep code

;; Code for directory, using the grep code supplied by NAG
;;
;; Mike Dewar 25.10.95
;;

(defconstant *directory-separator* "/") ;; This should be in sys*.c
(defconstant *wildcard-replacement* 
  '(#\[ #\a #\- #\z #\A #\- #\Z #\0 #\- #\9 #\\ #\. #\_ #\- #\& #\] #\* ))

;; Transform a list of characters involving wildcards into an egrep string.
(defmacro make-egrep-pattern (pattern)
  `(coerce 
     (replace-wildcards (cons '#\^ (coerce ,pattern '(list character))))
     'string) )

(defun replace-wildcards (pattern)
  (cond ((null pattern) nil)
        ((eqcar pattern #\.)
            (append '(#\\ #\.) (replace-wildcards (cdr pattern))))
        ((eqcar pattern #\*)
            (append *wildcard-replacement* (replace-wildcards (cdr pattern))))
        ('t (cons (car pattern) (replace-wildcards (cdr pattern))) )))

;;(defun simplify-path (p)
;; (let ((l (length p)))
;;      (cond  ((zerop l) ".")
;;             ((onep l) p)
;;             ((and (char= #\. (elt p 0)) 
;;              (char= (character *directory-separator*) (elt p 1)) )
;;                (simplify-path (subseq p 2)) )
;;             ('else p))))

(defun directory (path)
  (let* ((wildcard (search "*" path)))
        (cond  (wildcard (split-search wildcard path))
               ((filep path) (list path))
               ('else nil))))

;;(defun directory (path)
;;  (let* ((path2 (simplify-path path)) (wildcard (search "*" path2)))
;;        (cond  ((and wildcard (onep (length path2))) (list-directory "."))
;;               (wildcard (split-search wildcard path2))
;;               ((directoryp path2) (list-directory path2))
;;               ((filep path2) (list path2))
;;               ('else nil))))

(defmacro ls (u) `(list-directory (if (zerop (length ,u)) "." ,u)))

;; The variable index indicates where the first wildcard character is in path.
(defun split-search (index path) 
  (let (stem pattern tail)
    (multiple-value-setq (stem pattern tail) (segment-path index path))
    (mapcan #'directory 
      (mapcar '(lambda (x) (concatenate 'string stem x tail))
             (grep (ls stem) (make-egrep-pattern pattern) 't 't)))))

;; Split path into three bits (where the first and last can be empty):
;; The "stem", which is completely defined, the "pattern", where one or
;; more wildcards are present, and the "tail", everything else.
(defun segment-path (index path)
  (let (s-index t-index)
    (setq s-index (search *directory-separator* path :end2 index :from-end 't))
    (setq t-index (search *directory-separator* path :start2 index))
    (if (null s-index) (setq s-index -1))
    (if (null t-index) (setq t-index (length path)))
    (values
      (subseq path 0 (plus s-index 1))
      (subseq path (plus s-index 1) t-index)
      (subseq path t-index)))) 


