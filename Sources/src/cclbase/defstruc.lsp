
;;;; Defstruct structure definition package

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


;; A bootstrap-adequate (only just!) version of princ-to-string

(defun princ-to-string (x)
    (if (symbolp x)
        (symbol-name x)
        (svref '#.(vector
             "0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
            "10" "11" "12" "13" "14" "15" "16" "17" "18" "19") x)))


;;; These explicit macros are a hand-expansion of a defstruct shown later,
;;; elaborated just as far as is necessary for this package to work

(defun make-defstruct-description (&key name doc slots conc-name
      constructor boa-constructors copier predicate include included-by
      print-function type lisp-type named offset ((:length xlength)))
   (let
      ((_v_ (make-simple-vector 17)))
      (putv _v_ 0 'defstruct-description)
      (putv _v_ 1 name)
      (putv _v_ 2 doc)
      (putv _v_ 3 slots)
      (putv _v_ 4 conc-name)
      (putv _v_ 5 constructor)
      (putv _v_ 6 boa-constructors)
      (putv _v_ 7 copier)
      (putv _v_ 8 predicate)
      (putv _v_ 9 include)
      (putv _v_ 10 included-by)
      (putv _v_ 11 print-function)
      (putv _v_ 12 type)
      (putv _v_ 13 lisp-type)
      (putv _v_ 14 named)
      (putv _v_ 15 offset)
      (putv _v_ 16 xlength)
      (convert-to-struct _v_)))

(defun copy-defstruct-description (old)
   (let ((new (make-simple-vector 17)))
      (dotimes (i 17) (putv new i (svref old i)))
      (convert-to-struct new)))

(defun dd-name (v) (svref v 1))

(defun dd-doc (v) (svref v 2))

(defun dd-slots (v) (svref v 3))

(defun dd-conc-name (v) (svref v 4))

(defun dd-constructor (v) (svref v 5))

(defun dd-boa-constructors (v) (svref v 6))

(defun dd-copier (v) (svref v 7))

(defun dd-predicate (v) (svref v 8))

(defun dd-include (v) (svref v 9))

(defun dd-included-by (v) (svref v 10))

(defun dd-print-function (v) (svref v 11))

(defun dd-type (v) (svref v 12))

(defun dd-lisp-type (v) (svref v 13))

(defun dd-named (v) (svref v 14))

(defun dd-offset (v) (svref v 15))

(defun dd-length (v) (svref v 16))

(defsetf dd-name (v) (x) `(putv ,v 1 ,x))

(defsetf dd-doc (v) (x) `(putv ,v 2 ,x))

(defsetf dd-slots (v) (x) `(putv ,v 3 ,x))

(defsetf dd-conc-name (v) (x) `(putv ,v 4 ,x))

(defsetf dd-constructor (v) (x) `(putv ,v 5 ,x))

(defsetf dd-boa-constructors (v) (x) `(putv ,v 6 ,x))

(defsetf dd-copier (v) (x) `(putv ,v 7 ,x))

(defsetf dd-predicate (v) (x) `(putv ,v 8 ,x))

(defsetf dd-include (v) (x) `(putv ,v 9 ,x))

(defsetf dd-included-by (v) (x) `(putv ,v 10 ,x))

(defsetf dd-print-function (v) (x) `(putv ,v 11 ,x))

(defsetf dd-type (v) (x) `(putv ,v 12 ,x))

(defsetf dd-lisp-type (v) (x) `(putv ,v 13 ,x))

(defsetf dd-named (v) (x) `(putv ,v 14 ,x))

(defsetf dd-offset (v) (x) `(putv ,v 15 ,x))

(defsetf dd-length (v) (x) `(putv ,v 16 ,x))


(defun make-defstruct-slot-description (&key name index accessor default
      type read-only)
   (let
      ((_v_ (make-simple-vector 7)))
      (putv _v_ 0 'defstruct-slot-descriptor)
      (putv _v_ 1 name)
      (putv _v_ 2 index)
      (putv _v_ 3 accessor)
      (putv _v_ 4 default)
      (putv _v_ 5 type)
      (putv _v_ 6 read-only)
      (convert-to-struct _v_)))

(defun dsd-name (v) (svref v 1))

(defun dsd-index (v) (svref v 2))

(defun dsd-accessor (v) (svref v 3))

(defun dsd-default (v) (svref v 4))

(defun dsd-type (v) (svref v 5))

(defun dsd-read-only (v) (svref v 6))

(defsetf dsd-name (v) (x) `(putv ,v 1 ,x))

(defsetf dsd-index (v) (x) `(putv ,v 2 ,x))

(defsetf dsd-accessor (v) (x) `(putv ,v 3 ,x))

(defsetf dsd-default (v) (x) `(putv ,v 4 ,x))

(defsetf dsd-type (v) (x) `(putv ,v 5 ,x))

(defsetf dsd-read-only (v) (x) `(putv ,v 6 ,x))

;;;
;;; End of hand-expansion
;;;



(defun print-defstruct-description (structure stream depth)
   (declare (ignore depth))
   (format stream "#<Defstruct-Description for ~S>" (dd-name structure)))

(defun print-defstruct-slot-description (structure stream depth)
   (declare (ignore depth))
   (format
      stream
      "#<Defstruct-Slot-Description for ~S>"
      (dsd-name structure)))


;;; The legendary macro itself.

(defmacro defstruct (name-and-options &rest slot-descriptions)
   "Defines a structure.  See the manual for details."
   (let*
      ((defstruct (parse-name-and-options name-and-options))
         (name (dd-name defstruct)))
      (parse-slot-descriptions defstruct slot-descriptions)
      `(progn
         ,@(define-accessors defstruct)
         ,@(define-setters defstruct)
         ,@(define-constructor defstruct)
         ,@(define-boa-constructors defstruct)
         ,@(define-copier defstruct)
         ,@(define-predicate defstruct)
         ,@(if
            (dd-include defstruct)
            `((push
                ',name
                (dd-included-by
                   (get
                      ',(car (dd-include defstruct))
                      :structure-definition)))) )
         ,@(if
            (dd-doc defstruct)
            `((setf
                (get ',name :struct-documentation)
                ',(dd-doc defstruct))))
         (eval-when
            (load)
            (setf (get ',name :structure-definition) ',defstruct))
         (eval-when
            (compile eval)
            (let
               ((old (get ',name :structure-definition))
                  (new (copy-defstruct-description ',defstruct)))
               (setf (dd-included-by new) (if old (dd-included-by old)))
               (setf (get ',name :structure-definition) new)))
         ',name)))

(defun parse-name-and-options (name-and-options)
   (if
      (atom name-and-options)
      (setq name-and-options (list name-and-options)))
   (do*
      ((options (cdr name-and-options) (cdr options))
         (name (car name-and-options))
         (print-function 'default-structure-print)
         (conc-name (concat-pnames name '-))
         (constructor (concat-pnames 'make- name))
         (saw-constructor)
         (boa-constructors '())
         (copier (concat-pnames 'copy- name))
         (predicate (concat-pnames name '-p))
         (include)
         (saw-type)
         (type 'vector)
         (saw-named)
         (offset 0))
      ((null options)
         (make-defstruct-description :name name :conc-name conc-name
            :constructor
            constructor :boa-constructors boa-constructors :copier copier
            :predicate predicate :include include :print-function
            print-function
            :type
            type
            :lisp-type
            (cond
               ((eq type 'vector) 'simple-vector)
               ((eq type 'list) 'list)
               ((and (listp type) (eq (car type) 'vector))
                  (cons 'simple-array (cdr type)))
               (t (error (format nil "~S is a bad :TYPE for Defstruct." type))))
            :named
            (if saw-type saw-named t)
            :offset
            offset))
      (if
         (atom (car options))
         (case
            (car options)
            (:constructor
               (setq saw-constructor
                  t
                  constructor
                  (concat-pnames 'make- name)))
            (:copier)
            (:predicate)
            (:named (setq saw-named t))
            (t (error
                (format nil
                  "The Defstruct option ~S cannot be used with 0 arguments."
                  (car options)))))
         (let
            ((option (caar options)) (args (cdar options)))
            (case
               option
               (:conc-name (setq conc-name (car args)))
               (:constructor
                  (cond
                     ((cdr args)
                        (unless saw-constructor (setq constructor nil))
                        (push args boa-constructors))
                     (t (setq constructor (car args)))) )
               (:copier (setq copier (car args)))
               (:predicate (setq predicate (car args)))
               (:include (setq include args))
               (:print-function (setq print-function (car args)))
               (:type (setq saw-type t type (car args)))
               (:named
                  (error "The Defstruct option :NAMED takes no arguments."))
               (:initial-offset (setq offset (car args)))
               (t (error (format nil "~S is an unknown Defstruct option." option))))) )))

;;; Parse-Slot-Descriptions parses the slot descriptions (surprise) and does
;;; any structure inclusion that needs to be done.
(defun parse-slot-descriptions (defstruct slots)
   ;; First strip off any doc string and stash it in the Defstruct.
   (when
      (stringp (car slots))
      (setf (dd-doc defstruct) (car slots))
      (setq slots (cdr slots)))
   ;; Then include stuff.  We add unparsed items to the start of the Slots.
   (when
      (dd-include defstruct)
      (let
         ((included-thing
             (get (car (dd-include defstruct)) :structure-definition))
            (modified-slots (cdr (dd-include defstruct))))
         (unless
            included-thing
            (error (format nil
                 "Cannot find description of structure ~S to use for inclusion."
                 (car (dd-include defstruct)))))
         (setf (dd-offset defstruct) (dd-offset included-thing))
         (do*
            ((islots
                (mapcar
                   #'(lambda (slot)
                      `(,(dsd-name slot)
                         ,(dsd-default slot)
                         :type
                         ,(dsd-type slot)
                         :read-only
                         ,(dsd-read-only slot)))
                   (dd-slots included-thing)))
               (islots* islots (cdr islots*)))
            ((null islots*) (setq slots (nconc islots slots)))
            (let*
               ((islot (car islots*))
                  (modifiee
                     (find
                        (car islot)
                        modified-slots
                        :key
                        #'(lambda (x) (if (atom x) x (car x)))
                        :test
                        #'string=)))
               (when
                  modifiee
                  (cond
                     ((symbolp modifiee)
                        ;; If it's just a symbol, nilify the default.
                        (setf (cadr islot) nil))
                     ((listp modifiee)
                        ;; If it's a list, parse new defaults and options.
                        (setf (cadr islot) (cadr modifiee))
                        (when
                           (cddr modifiee)
                           (do
                              ((options (cddr modifiee) (cddr options)))
                              ((null options))
                              (case
                                 (car options)
                                 (:type (setf (cadddr islot) (cadr options)))
                                 (:read-only
                                    (setf
                                       (cadr (cddddr islot))
                                       (cadr options)))
                                 (t (error (format nil
                                    "Bad option in included slot spec: ~S."
                                       (car options))))) ))) ))) )))
   ;; Finally parse the slots into Slot-Description objects.
   (do
      ((slots slots (cdr slots))
         (index
            (+ (dd-offset defstruct) (if (dd-named defstruct) 1 0))
            (\1+ index))
         (descriptions '()))
      ((null slots)
         (setf (dd-length defstruct) index)
         (setf (dd-slots defstruct) (nreverse descriptions)))
      (let
         ((slot (car slots)))
         (push
            (if
               (atom slot)
               (let
                  ((name slot))
                  (make-defstruct-slot-description :name name :index index
                     :accessor
                     (concat-pnames (dd-conc-name defstruct) name)
                     :type
                     t))
               (do
                  ((options (cddr slot) (cddr options))
                     (name (car slot))
                     (default (cadr slot))
                     (type t)
                     (read-only nil))
                  ((null options)
                     (make-defstruct-slot-description :name name :index index
                        :accessor
                        (concat-pnames (dd-conc-name defstruct) name)
                        :default default :type type :read-only
                        read-only))
                  (case
                     (car options)
                     (:type (setq type (cadr options)))
                     (:read-only (setq read-only (cadr options)))) ))
            descriptions))))

(eval-when
   (compile load eval)
   (defun concat-pnames (name1 name2)
      (if
         name1
         (intern
            (concatenate
               'simple-string
               (symbol-name name1)
               (symbol-name name2)))
         name2))
   (defun concat-pnames* (name1 name2)
      (if
         name1
         (make-symbol
            (concatenate
               'simple-string
               (symbol-name name1)
               (symbol-name name2)))
         name2))
   (defun concat-stuff (thing1 thing2)
      (intern
         (concatenate
            'simple-string
            (princ-to-string thing1)
            (princ-to-string thing2))))
   ;;; The set of simple-vector structure accessors and setters that we want
   ;;; defined.  These are shared by all simple-vector structure accessors
   ;;; and setters for the first number-of-built-in-slot-frobbers.
   (defconstant number-of-built-in-slot-frobbers 20))

(defvar built-in-accessors (make-array number-of-built-in-slot-frobbers))

(defvar built-in-setters (make-array number-of-built-in-slot-frobbers))

(eval-when
   (compile eval)
   (defmacro make-built-in-slot-frobbers ()
      (do
         ((i 0 (\1+ i)) (them ()))
         ((= i number-of-built-in-slot-frobbers) `(progn . ,them))
         (let
            ((accessor (concat-stuff '~get- i))
               (setter (concat-stuff '~set- i)))
            (push
               `(progn
                  (defun ,accessor (x) (svref x ,i))
                  (setf (svref built-in-accessors ,i) ',accessor)
                  (s::compilermacro ,accessor (x) `(svref ,x ,',i))
                  (defun ,setter (x y) (setf (svref x ,i) y))
                  (setf (svref built-in-setters ,i) ',setter)
                  (s::compilermacro ,setter (x y) `(setf (svref ,x ,',i) ,y))
               )
               them)))) )

(make-built-in-slot-frobbers)

;;; The built in copier for the default kind of structure:
(defun built-in-copier (old)
   (declare (simple-vector old))
   (do*
      ((index 0 (\1+ index))
        (lengthold (length old))
        (new (make-array lengthold)))
      ((= index lengthold) (convert-to-struct new))
      (setf (svref new index) (svref old index))))

;;; Define-Accessors returns a list of function definitions for accessing
;;; slots of the given Defstruct.  The functions are proclaimed to be
;;; inline, and the types of their arguments and results are declared as
;;; well.  We count on the compiler to do clever things with Elt.  We use
;;; deftransform instead of declaring the functions inline, since inline
;;; optimization is not as tense as could be.
(defun define-accessors (defstruct)
   (do
      ((slots (dd-slots defstruct) (cdr slots))
         (stuff '())
         (type (dd-lisp-type defstruct)))
      ((null slots) stuff)
      (let*
         ((slot (car slots))
            (name (dsd-accessor slot))
            (index (dsd-index slot)))
         (push
            (if
               (and
                  (eq type 'simple-vector)
                  (< index number-of-built-in-slot-frobbers))
               `(progn
                  (setf
                     (symbol-function ',name)
                     (symbol-function ',(svref built-in-accessors index)))
                  (eval-when
                     (compile load eval)
                     (setf
                        (get ',name 's::newname)
                        ',(svref built-in-accessors index) )
                     ) )
               (if (eq type 'simple-vector)
               `(progn
                  (defun ,name (structure)
                     (svref (the ,type structure) ,index))
                  (eval-when
                     (compile load eval)
                     (s::compilermacro
                        ,name
                        (structure)
                        `(svref (the ,',type ,structure) ,',index)))) 
               `(progn
                  (defun ,name (structure)
                     (elt (the ,type structure) ,index))
                  (eval-when
                     (compile load eval)
                     (s::compilermacro
                        ,name
                        (structure)
                        `(elt (the ,',type ,structure) ,',index)))) 
                 ))
            stuff))))

;;; Define-Setters returns a list of Defsetfs for setting slots of the given
;;; Defstruct.  We count on the compiler to do clever things with Setf of
;;; Elt.
;;; Since a straighforward "complicated" defsetf results in about a page
;;; worth of code in Spice Lisp, we define a setter function use the
;;; "simple" defsetf.
(defun define-setters (defstruct)
   (do
      ((slots (dd-slots defstruct) (cdr slots))
         (stuff '())
         (type (dd-lisp-type defstruct)))
      ((null slots) stuff)
      (let*
         ((slot (car slots))
            (name (concat-pnames* 'set- (dsd-accessor slot)))
            (index (dsd-index slot)))
         (unless
            (dsd-read-only slot)
            (push
               (if
                  (and
                     (eq type 'simple-vector)
                     (< index number-of-built-in-slot-frobbers))
                  `(defsetf
                     ,(dsd-accessor slot)
                     ,(svref built-in-setters index))
                  (if (eq type 'simple-vector)
                  `(progn
                     (defun ,name (structure new-value)
                        (setf (svref (the ,type structure) ,index) new-value))
                     (eval-when
                        (compile load eval)
                        (s::compilermacro
                           ,name
                           (structure new-value)
                           `(setf
                              (svref (the ,',type ,structure) ,',index)
                              ,new-value)))
                     (defsetf ,(dsd-accessor slot) ,name))
                  `(progn
                     (defun ,name (structure new-value)
                        (setf (elt (the ,type structure) ,index) new-value))
                     (eval-when
                        (compile load eval)
                        (s::compilermacro
                           ,name
                           (structure new-value)
                           `(setf
                              (elt (the ,',type ,structure) ,',index)
                              ,new-value)))
                     (defsetf ,(dsd-accessor slot) ,name))
               ))
               stuff)))) )

;;; Define-Constructor returns a definition for the constructor function of
;;; the given Defstruct.  If the structure is implemented as a vector and
;;; is named, we structurify it.  If the structure is a vector of some
;;; specialized type, we can't use the Vector function.
(defun define-constructor (defstruct)
   (let
      ((name (dd-constructor defstruct)))
      (when
         name
         (let*
            ((initial-cruft (make-list (dd-offset defstruct)))
               (slots (dd-slots defstruct))
               (arg-names (mapcar #'dsd-name slots))
               (args
                  (mapcar
                     #'(lambda (slot)
                        `(,(dsd-name slot) ,(dsd-default slot)))
                     slots)))
            `((defun ,name (&key ,@args)
                ,(if
                   (eq (dd-type defstruct) 'list)
                   `(list
                      ,@(if (dd-named defstruct) `(',(dd-name defstruct)))
                      ,@initial-cruft
                      ,@arg-names)
                   (if
                      (dd-named defstruct)
                      `(convert-to-struct
                         (vector
                            ',(dd-name defstruct)
                            ,@initial-cruft
                            ,@arg-names))
                      (if
                         (eq (dd-type defstruct) 'vector)
                         `(vector ,@initial-cruft ,@arg-names)
                         (do
                            ((sluts slots (cdr sluts))
                               (sets '())
                               (temp (gensym)))
                            ((null sluts)
                               `(let
                                  ((,temp
                                      (make-array
                                         ,(dd-length defstruct)
                                         :element-type
                                         ',(cadr
                                            (dd-lisp-type defstruct)))) )
                                  ,@sets
                                  ,temp))
                            (let
                               ((slot (car sluts)))
                               (push
                                  `(setf
                                     (aref ,temp ,(dsd-index slot))
                                     ,(dsd-name slot))
                                  sets)))) ))) ))) ))

;;; Define-Boa-Constructors defines positional constructor functions.
;;;  We generate code to set each variable not specified in the arglist
;;; to the default given in the Defstruct.  We just slap required args
;;; in, as with rest args and aux args.  Optionals are treated a little
;;; differently.  Those that aren't supplied with a default in the arg
;;; list are mashed so that their default in the arglist is the
;;; corresponding default from the Defstruct.
(defun define-boa-constructors (defstruct)
   (do*
      ((boas (dd-boa-constructors defstruct) (cdr boas))
         (name (car (car boas)) (car (car boas)))
         (args (copy-list (cadr (car boas))) (copy-list (cadr (car boas))))
         (slots (dd-slots defstruct) (dd-slots defstruct))
         (slots-in-arglist '() '())
         (defuns '()))
      ((null boas) defuns)
      ;; Find the slots in the arglist and hack the defaultless optionals.
      (do
         ((args args (cdr args)) (arg-kind 'required))
         ((null args))
         (let
            ((arg (car args)))
            (if
               (atom arg)
               (if
                  (memq arg '(&optional &rest &aux))
                  (setq arg-kind arg)
                  (case
                     arg-kind
                     ((required &rest &aux) (push arg slots-in-arglist))
                     (&optional
                        (push arg slots-in-arglist)
                        (rplaca
                           args
                           (cons
                              arg
                              (dsd-default
                                 (find arg slots :key #'dsd-name)))) )))
               (push (car arg) slots-in-arglist))))
      ;; Then make a list that can be used with a (list ...) or (vector ...).
      (let
         ((initial-cruft (make-list (dd-offset defstruct)))
            (thing
               (mapcar
                  #'(lambda (slot)
                     (if
                        (memq (dsd-name slot) slots-in-arglist)
                        (dsd-name slot)
                        (dsd-default slot)))
                  slots)))
         (push
            `(defun ,name ,args
               ,(if
                  (eq (dd-type defstruct) 'list)
                  `(list
                     ,@(if (dd-named defstruct) `(',(dd-name defstruct)))
                     ,@initial-cruft
                     ,@thing)
                  (if
                     (dd-named defstruct)
                     `(convert-to-struct
                        (vector
                           ',(dd-name defstruct)
                           ,@initial-cruft
                           ,@thing))
                     (if
                        (eq (dd-type defstruct) 'vector)
                        `(vector ,@initial-cruft ,@thing)
                        (do
                           ((things thing (cdr things))
                              (index 0 (\1+ index))
                              (sets '())
                              (temp (gensym)))
                           ((null things)
                              `(let
                                 ((,temp
                                     (make-array
                                        ,(dd-length defstruct)
                                        :element-type
                                        ',(cadr (dd-lisp-type defstruct)))) )
                                 ,@sets
                                 ,temp))
                           (push
                              `(setf (aref ,temp index) ,(car things))
                              sets)))) ))
            defuns))))

;;; Define-Copier returns the definition for a copier function for the given
;;; Defstruct if one is desired.  If the structure is implemented as a vector
;;; and is named, we use our Built-In-Copier.
(defun define-copier (defstruct)
   (if
      (dd-copier defstruct)
      (cond
         ((and
             (eq (dd-lisp-type defstruct) 'simple-vector)
             (dd-named defstruct))
            `((setf
                (symbol-function ',(dd-copier defstruct))
                (symbol-function 'built-in-copier))))
         ((eq (dd-lisp-type defstruct) 'list)
            `((setf
                (symbol-function ',(dd-copier defstruct))
                (symbol-function 'copy-list))))
         (t `((defun ,(dd-copier defstruct) (structure)
                (copy-seq (the ,(dd-lisp-type defstruct) structure)))) ))) )

;;; Define-Predicate returns a definition for a predicate function if one is
;;; desired.
(defun define-predicate (defstruct)
   (when
      (and (dd-predicate defstruct) (dd-named defstruct))
      `((defun ,(dd-predicate defstruct) (object)
          ,(if
             (eq (dd-type defstruct) 'list)
             `(and
                (listp object)
                (or
                   (eq (car object) ',(dd-name defstruct))
                   (memq
                      (car object)
                      (dd-included-by
                         (get
                            ',(dd-name defstruct)
                            :structure-definition)))) )
             `(and
                (structp object)
                (or
                   (eq (svref object 0) ',(dd-name defstruct))
                   (if
                      (memq
                         (svref object 0)
                         (dd-included-by
                            (get
                               ',(dd-name defstruct)
                               :structure-definition)))
                      t)))) ))) )

;;; Random sorts of stuff.
(defun default-structure-print (structure stream depth)
   (declare (ignore depth) (special *print-length*))
   (write-string "#S(" stream)
   (prin1 (svref structure 0) stream)
   (do
      ((index 1 (\1+ index))
         (length (length structure))
         (slots
            (dd-slots (get (svref structure 0) :structure-definition))
            (cdr slots)))
      ((or (= index length) (and *print-length* (= index *print-length*)))
         (if
            (= index length)
            (write-string ")" stream)
            (write-string "...)" stream)))
      (write-char #\  stream)
      (prin1 (dsd-name (car slots)) stream)
      (write-char #\  stream)
      (prin1 (svref structure index) stream)))


;;; Now use the package to define the proper versions of the substructures
;;; that it uses. Note that it is quite important that the hand expansion
;;; used earlier and this automatic one match up properly.


(defstruct
   (defstruct-description
      (:conc-name dd-)
      (:print-function print-defstruct-description))
   name
   ; name of the structure
   doc
   ; documentation on the structure
   slots
   ; list of slots
   conc-name
   ; prefix for slot names
   constructor
   ; name of standard constructor function
   boa-constructors
   ; name of by-position constructors
   copier
   ; name of copying function
   predicate
   ; name of type predictate
   include
   ; name of included structure
   included-by
   ; names of structures including this one
   print-function
   ; function used to print it
   type
   ; type specified
   lisp-type
   ; actual type used for implementation
   named
   ; T if named, Nil otherwise
   offset
   ; first slot's offset into implementation sequence
   length)
   ; total length of the thing


(defstruct
   (defstruct-slot-description
      (:conc-name dsd-)
      (:print-function print-defstruct-slot-description))
   name
   ; name of the slot
   index
   ; its position in the implementation sequence
   accessor
   ; name of it accessor function
   default
   ; default value
   type
   ; declared type
   read-only)
   ; T if there's to be no setter for it



