
;;;; Stream input & output

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



; The system-coded primitive function ~OPEN opens a file, and takes a second
; argument that indicates what options are needed.
;
; see print.c for further detauls of the options.

;   x x xx xxx 00   direction PROBE
;   x x xx xxx 01             INPUT
;   x x xx xxx 10             OUTPUT
;   x x xx xxx 11             IO
;  
;   x x xx 000 xx   if-exists NIL
;   x x xx 001 xx             overwrite
;   x x xx 010 xx             append
;   x x xx 011 xx             rename
;   x x xx 100 xx             error
;   x x xx 101 xx             new-version
;   x x xx 110 xx             (supersede)
;   x x xx 111 xx             (rename-and-delete)
;  
;   x x 00 xxx xx   if-does-not-exist NIL
;   x x 01 xxx xx                     create
;   x x 10 xxx xx                     error
;  
;   x 0 xx xxx xx   regular text file
;   x 1 xx xxx xx   open for binary access
;  
;   0 x xx xxx xx   regular file
;   1 x xx xxx xx   open as a pipe

(defun open (filename &key 
                      (direction :input)
                      (element-type 'character)
                      (if-exists :error if-exists-p)
                      (if-does-not-exist :error if-does-not-exist-p)
                      (external-format :default))
  (let ((openmode 0))
    (cond
      ((eq direction :probe)
         (when (not if-does-not-exist-p) (setq if-does-not-exist nil)))
      ((eq direction :input) 
         (setq openmode 1)
         (setq if-exists nil))
      ((eq direction :output)
;; It may be a bit dodgy here - I try to make things behave more the way I
;; had "wanted/expected" by behaving as if filenames in these cases were all
;; types as :newest and so I can default to :new-version which I then treat
;; the same as :overwrite.  Some rationalisation of this may be needed later.
         (when (not if-exists-p) (setq if-exists :new-version))
         (when (and (not if-does-not-exist-p)
                    (not (or (eq if-exists :overwrite)
                             (eq if-exists :append))))
               (setq if-does-not-exist :create))
         (setq openmode 2))
      ((eq direction :io)
         (when (not if-exists-p) (setq if-exists :overwrite))
         (when (not if-does-not-exist-p)
            (when (not (or (eq if-exists :overwrite)
                           (eq if-exists :append)))
                  (setq if-does-not-exist :create)))
         (setq openmode 3))
      (t (error "Illegal direction for open")))
    (cond
      ((eq if-exists :overwrite) (setq openmode (+ openmode 4)))
      ((eq if-exists :append) (setq openmode (+ openmode 8)))
      ((eq if-exists :rename) (setq openmode (+ openmode 12)))
      ((eq if-exists :error) (setq openmode (+ openmode 16)))
      ((eq if-exists :new-version) (setq openmode (+ openmode 20)))
      ((eq if-exists :supersede) (setq openmode (+ openmode 24)))
      ((eq if-exists :rename-and-delete) (setq openmode (+ openmode 28))))
    (cond
      ((eq if-does-not-exist :create) (setq openmode (+ openmode 32)))
      ((eq if-does-not-exist :error) (setq openmode (+ openmode 64))))
    (~open filename openmode)))

(defmacro with-open-file (&whole a)
   (let ((sname (caadr a))
         (openargs (cdadr a))
         (body (cddr a))
         (g (gensym)))
     `(let ((,g (open ,@openargs)))
         (unwind-protect
            (let ((,sname ,g))
                 ,@body)
            (close ,g)))))


(defmacro with-open-stream (&whole x)
   (let ((var (car (cadr x)))
         (stream (cadr (cadr x)))
         (body (cddr x)))
     `(let ((,var ,stream))
        (unwind-protect (let () ,@body)
           (close ,var)))))

(defun force-output (&optional (stream *standard-output*))
   (flush stream))

(defun file-position (stream &optional (position nil positionp))
   (cond ((null positionp) (rtell stream))
         ((eq position :start) (rseek stream 0))
         ((eq position :end) (lisp::rseekend stream))
         ('else (progn (rseek stream position) t))))

(defun peek-char (&optional type 
                            (stream *standard-input*)
                            (eof-error-p t)
                            eof-value
                            recursive-p)
   (let ((ch (peekch type stream)))
      (if (eq ch #\eof)
          (if eof-error-p (error "end of file detected in peek-char")
              eof-value)
          ch)))

(defun read-byte (stream &optional (eof-error-p t) eof-value)
   (let ((ch (readb stream)))
      (if (eq ch #\eof)
          (if eof-error-p (error "end of file detected in read-char")
              eof-value)
          ch)))

(defun read-char (&optional (stream *standard-input*)
                            (eof-error-p t)
                            eof-value
                            recursive-p)
   (let ((ch (readch stream)))
      (if (eq ch #\eof)
          (if eof-error-p (error "end of file detected in read-char")
              eof-value)
          ch)))


(defun read-line (&optional stream
                            (eof-error-p t)
                            eof-value
                            recursive-p)
   (multiple-value-bind
      (s fg) 
      (readline stream)
      (if (eq s #\eof)
          (if eof-error-p (error "end of file detected in read-line")
              eof-value)
          (values s fg))))

;;following needs to support keyword arg
(defun read-from-string (x &rest doobries) (compress1 (explodec x)))

(defun nth (n list) (car (nthcdr n list)))

;;following needs to support keyword arg
(defun parse-integer (s &key junk-allowed) (read-from-string s))

;; end of file stream.lsp

