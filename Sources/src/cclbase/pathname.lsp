(in-package 'lisp)
;;
;; File System Interface support for CCL
;;                                                    A C Norman, June 1994
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


;;
;; To store pathnames I have a thing called a pathname-structure. It
;; is not just a pathname because the exported constructor and access
;; functions need to do so many curious things.

(defstruct pathname-structure host device directory name type version)

(defun wild-pathname-p (pathname &optional field-key)
   (if (pathname-structure-p pathname)
      (or
        (and (or (null field-key) (eq field-key :host))
             (eq (pathname-structure-host pathname) :wild))
        (and (or (null field-key) (eq field-key :device))
             (eq (pathname-structure-device pathname) :wild))
        (and (or (null field-key) (eq field-key :directory))
             (or (eq (pathname-structure-directory pathname) :wild)
                 (member :wild (pathname-structure-directory pathname))
                 (member :wild-inferiors
                    (pathname-structure-directory pathname))))
        (and (or (null field-key) (eq field-key :name))
             (eq (pathname-structure-name pathname) :wild))
        (and (or (null field-key) (eq field-key :type))
             (eq (pathname-structure-type pathname) :wild))
        (and (or (null field-key) (eq field-key :version))
             (eq (pathname-structure-version pathname) :wild)))
      (error "not a pathname for wild-pathname-p")))

(defun pathname-match-p (pathname wildname)
   (error "pathname-match-p not implemented"))

(defun translate-pathname (source from-wildname to-wildname)
   (error "translate pathname not implemented"))

(defun logical-pathname (pathname)
   (error "logical-pathname"))

(defun translate-logical-pathname (pathname) 
   (error "translate-logical-pathname"))

(defun logical-pathname-translations (host)
   (error "logical-pathname-translations"))

(defun load-logical-pathname-translations (host)
   (error "load-logical-pathname-translations"))

(defun compile-file-pathname (pathname &key output-file)
   (error "compile-file-pathname"))

(defun pathname (arg) ;; convert arg to be a pathname
   (cond
     ((pathname-structure-p arg) arg)
     ((symbolp arg) (pathname (symbol-name arg)))
     ((stringp arg) (subst-slashes arg))
     (t (error "pathname")) ))

(defun subst-slashes (s)
  (let ((new-s (make-string (length s))))
    (dotimes (i (length s))
      (let ((c (char s i)))
	(setf (char new-s i) 
	      (if (char-equal c #\\) #\/ c))))
    new-s))

(defun unsubst-slashes (s)
  (let ((new-s (make-string (length s))))
    (dotimes (i (length s))
      (let ((c (char s i)))
	(setf (char new-s i) 
	      (if (char-equal c #\/) #\\ c))))
    new-s))

(defun canonical-name (s)
	(if (memq :win32 *features*) (subst-slashes s) s))

(defun uncanonical-name (s)
	(if (memq :win32 *features*) (unsubst-slashes s) s))

;;(defun truename (xx) xx)
(defun merge-pathnames (xx) xx)

(defun make-pathname (&key host device directory name type version defaults)
  (prog (dir) 
    (setq dir
      (apply 'concatenate
             (cons 'string
               (if (listp directory)
                   (mapcan 'list directory
                     (make-list (length directory) :initial-element "/" ))
                   (list directory "/")))))
     (if type (setq type (concatenate 'string "." type)))
     (return (concatenate 'string dir name type))))


(defvar *default-pathname-defaults* "")

(defun lastpos (char s)
  (let ((rpos (position char (reverse s)))) ;; :from-end t doesn't work
    (if (null rpos) nil
      (- (length s) (1+ rpos)))))

(defun pathnamep (x) nil) ;; pathnames don't exist yet

(defun namestring (s) 
  (let ((s (string s)))
    (if (memq :win32 *features*) (unsubst-slashes s) s)))

(defun pathname-name (s)
  (setq s (string s))
  (let ((dpos (lastpos #\. s)))
    (if dpos (setq s (subseq s 0 dpos)))
    (setq dpos (lastpos #\/ s))
    (if dpos (setq s (subseq s (1+ dpos))))
    s))

(defun pathname-type (s)
  (setq s (string s))
  (let ((dpos (lastpos #\. s)))
    (if dpos (subseq s (1+ dpos)) nil)))

(defun pathname-directory (s)
  (setq s (canonical-name (string s)))
  (let ((spos (position #\/ s)))
    (if spos 
	(cons (subseq s 0 spos) 
	      (pathname-directory (subseq s (1+ spos))))
      nil)))

(defun directory-namestring-0 (s)
    (setq s (let ((dpos (lastpos #\/ s)))
	      (if dpos (subseq s 0 dpos) nil)))
    (if s (concatenate 'string s "/") ""))

(defun directory-namestring (s)
   (uncanonical-name (directory-namestring-0 (canonical-name (string s)))))
 
(defun file-namestring (p)
  (concatenate 'string (pathname-name p) "." (pathname-type p)))

(defun parse-namestring (xx) xx)

