
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


(setq *package* (find-package 'lisp))

(de sys::explist (l)
   (tagbody
top   (if (eq l nil) (go out))
      (extern (car l))
      (prin (car l))                ;; to trace it
      (princ " ")
      (setq l (cdr l))
      (go top)
out   ))


(sys::explist '(abs acons))

(sys::explist '(
   acos acosh adjoin adjustable-array-p adjust-array
   &allow-other-keys alpha-char-p alphanumericp and append apply
   applyhook *applyhook* apropos apropos-list aref array array-dimension
   array-dimension-limit array-dimensions array-element-type
   array-has-fill-pointer-p array-in-bounds-p complex-arrayp arrayp array-rank
   array-rank-limit array-row-major-index array-total-size
   array-total-size-limit ash asin  asinh assert assoc  assoc-if))

(sys::explist '(
   assoc-if-not atan atanh atom &aux bignum bit bit-and bit-andc1
   bit-andc2 bit-eqv bit-ior bit-nand bit-nor bit not bit-orc1 bit-orc2
   bit-vector bit-vector-p bit-xor block &body boole boole-and
   boole-andc1 boole-andc2 boole-c1 boole-c2 boole-clr boole-eqv
   boole-ior boole-nand boole-nor boole-orc1 boole-orc2 boole-set
   boole-xor boole-1 boole-2 both-case-p boundp break *break-on-warnings*
   butlast byte byte-position byte-size caaaar caaadr caaar caadar caaddr
   caadr caar cadaar cadadr cadar caddar cadddr caddr cadr))

(sys::explist '(
   call-arguments-limit car case catch ccase cdaaaar cdaadr cdaar cdadar
   cdaddr cdadr cdar cddaar cddadr cddar cdddar cddddr cdddr cddr cdr
   ceiling cerror char character characterp char-bit char-bits
   char-bits-limit char-code char-code-limit char-control-bit
   char-downcase char-equal char-font char-font-limit char-greaterp
   char-hyper-bit char-int char-lessp char-meta-bit char-name
   char-not-equal char-not-greaterp char-not-lessp char-super-bit
   char-upcase char/= char< char <= char> char>= check-type chdir cis))

(sys::explist '(
   clear-input clear-output close clrhash code-char coerce common commonp
   compile compiled-function compiled-function-p compile-file
   compiler-let complex complexp concatenate cond conjugate cons consp
   constantp copy-alist copy-list copy-readtable copy-seq copy-symbol
   copy-tree cos cosh count count-if count-if-not ctypecase *debug-io*
   decf declaration declare decode-float decode-universal-time
   *default-pathname-defaults* defconstant define-modify-macro
   define-setf-method defmacro defparameter defsetf defstruct deftype
   defun defvar delete delete-duplicates delete-file delete-if))

(sys::explist '(
   delete-if-not denominator deposite-field describe digit-char
   digit-char-p directory directory-namestring disassemble do do*
   do-all-symbols do-external-symbols do-symbols documentation dolist
   dotimes  double-float double-float-epsilon
   double-float-negative-epsilon dpb dribble ecase ed eighth elt
   enable-backtrace
   encode-universal-time endp enough-namestring &environment eq eql equal
   equalp error *error-output* etypecase eval evalhook *evalhook*
   eval-when evenp every exp export expt fboundp fceiling *features*
   ffloor fifth file-author file-namestring file-position))

(sys::explist '(
   file-write-date fill fill-pointer find find-all-symbols find-if
   find-if-not find-package find-symbol finish-output first fixnum flet
   float float-digits float-precision float-radix float-sign floatp floor
   fmakunbound force-output format fourth fresh-line fround ftruncate
   ftype funcall function functionp gcd gensym gentemp get get-current-directory
   get-decoded-time get-dispatch-macro-character getf gethash
   get-internal-real-time get-internal-run-time get-macro-character))

(sys::explist '(
   get-output-stream-string get-properties get-setf-method
   get-setf-method-multiple-values get-universal-time go graphic-char-p
   hash-table hash-table-count hash-table-p host-namestring identity if
   ignore imagpart import in-package incf inline input-stream-p inspect
   int-char integer integer-decode-float integer-length integerp intern
   internal-time-units-per-second intersection isqrt &key keyword))

(sys::explist '(
   keywordp labels lambda lambda-list-keywords lambda-parameters-limit
   last lcm ldb ldb-test ldiff least-negative-double-float
   least-negative-long-float least-negative-short-float
   least-negative-single-float least-positive-double-float
   least-positive-long-float least-positive-short-float
   least-positive-single-float length let let* lisp-implementation-type
   lisp-implementation-version list list* list-all-packages list-length
   listen listp load *load-verbose* locally log logand logandc1 logandc2
   logbitp logcount logeqv logior lognand lognor lognot logorc1 logorc2
   logtest logxor long-float long-float-epsilon))

(sys::explist '(
   long-float-negative-epsilon long-site-name loop lower-case-p
   machine-instance machine-type machine-version macro-function
   macroexpand *macroexpand-hook* macroexpand-1 macrolet make-array
   make-broadcast-stream make-char make-concatenated-stream
   make-dispatch-macro-character make-echo-stream make-hash-table
   make-list make-package make-pathname make-random-state make-sequence))

(sys::explist '(
   make-string make-string-input-stream make-string-output-stream
   make-symbol make-synonym-stream make-two-way-stream makunbound map
   mapc mapcan mapcar mapcon maphash mapl maplist mask-field max member
   member-if member-if-not merge merge-pathnames min minusp mismatch mod
   *modules* most-negative-double-float most-negative-fixnum
   most-negative-long-float most-negative-short-float))

(sys::explist '(
   most-negative-single-float most-postive-double-float
   most-positive-fixnum most-positive-long-float
   most-positive-short-float most-positive-single-float
   multiple-value-bind multiple-value-call multiple-value-list
   multiple-value-prog1 multiple-value-setq multiple-values-limit
   name-char namestring nbutlast nconc nil nintersection ninth not notany
   notevery notinline nreconc nreverse nset-difference nset-exclusive-or
   nstring-capitalize nstring-downcase nstring-upcase nsublis nsubst
   nsubst-if nsubst-if-not nsubstitute nsubstitute-if nsubstitute-if-not))

(sys::explist '(
   nth nthcdr null number numberp numerator nunion oddp open optimize
   &optional or output-stream-p package *package* package-name
   package-nicknames packagep package-shadowing-symbols package-use-list
   package-used-by-list pairlis parse-integer parse-namestring pathname
   pathname-device pathname-directory pathname-host pathname-name
   pathnamep pathname-type pathname-version peek-char phase pi plusp pop
   position position-if position-if-not pprint princ princ-to-string
   print *print-array* *print-base* *print-case* *print-circle*))

(sys::explist '(
   *print-escape* *print-gensym* *print-length* *print-level*
   *print-pretty* *print-radix* prin1 prin1-to-string probe-file proclaim
   prog prog* progn progv prog1 prog2 provide psetf psetq push pushnew
   *query-io* quote random random-state *random-state* random-state-p
   rassoc rassoc-if rassoc-if-not ratio rational rationalize manexp rationalp
   read *read-base* read-byte read-char read-char-no-hang))

(sys::explist '(
   *read-default-float-format* read-delimited-list read-from-string
   read-line read-preserving-whitespace *read-suppress* readtable
   *readtable* readtablep realpart reduce rem remf remhash remove
   remove-duplicates remove-if remove-if-not remprop rename-file
   rename-package replace require rest &rest return return-from revappend
   reverse room rotatef round rplaca rplacd satisfies sbit scale-float
   schar search second sequence set set-char-bit set-difference
   set-dispatch-macro-character set-exclusive-or setf set-macro-character))

(sys::explist '(
   setq set-syntax-from-char seventh shadow shadowing-import shiftf
   short-float short-float-epsilon short-float-negative-epsilon
   short-site-name signed-byte signum simple-array simple-bit-vector
   simple-bit-vector-p simple-string simple-string-p simple-vector
   simple-vector-p sin single-float single-float-epsilon
   single-float-negative-epsilin sinh sixth sleep software-type
   software-version some sort special special-form-p sqrt stable-sort))

(sys::explist '(
   standard-char standard-char-p *standard-input* *standard-output* step
   stream stream-element-type streamp string string-capitalize
   string-char string-char-p string-downcase string-equal string-greaterp
   string-left-trim string-lessp string-not-equal string-not-greaterp
   string-not-lessp stringp string-right-trim string-trim string-upcase
   string/= string< string<= string= string> string>= sublis subseq
   subsetp subst subst-if subst-if-not substitute substitute-if))

(sys::explist '(
   substitute-if-not subtypep svref sxhash symbol symbol-function 
   symbol-name symbolp symbol-package symbol-plist symbol-value t tagbody
   tailp tan tanh tenth *terminal-io* terpri the third throw time trace
   *trace-output* tree-equal truename truncate type type-of typecase
   typep unexport unintern union unless unread-char unsigned-byte untrace
   unuse-package unwind-protect upper-case-p use-package
   user-homedir-pathname values values-list vector vector-pop vector-push
   vector-push-extend vectorp warn when &whole with-input-from-string
   with-open-file with-open-stream with-output-to-string write write-byte
   write-char write-line write-string write-to-string y-or-n-p
   yes-or-no-p zerop * ** *** + ++ +++ - / // /// /= 1+ 1- < <= = > >=))

;; Now I will have a bunch of things that are specific to CCL, but where it
;; is convenient to have them exported by the LISP package so that almost
;; everybody has access to them.

(sys::explist '(
  de dm gc preserve *keyword-package*
  getenv faslout faslend stop special-char
  graphic-char-p make-global expr fexpr macro
  fluid global $eol$ $eof$
  add1 difference list-to-string whitespace-char-p
  otherwise *comp *plap digit *echo spool
  set-autoload list-directory list-modules copy-module modulep
  delete-module writable-libraryp get-lisp-directory
  reset-keywords display-keywords assoc** nreverse0
  clear_source_database load_source_database save_source_database
  display_source_database *where_defined* list-to-vector protected-symbol-warn
  protect-symbols symbol-protect c-compile c-end *break-loop* break-loop
  ACOSD ACOT ACOTD ACOTH ACSC ACSCD 
  ACSCH ASEC ASECD ASECH ASET ASIND 
  ATAND ATSOC BATCHP BPSP BYTECOUNTS 
  CBRT CDAAAR CHARPOS CHARSET CODEP COMPD 
  CONTAINED COPY COSD COT COTD COTH 
  CSC CSCD CSCH DATE DATELESSP DATESTAMP 
  DEFLIST DEFSETTER DELEQ DIGIT DIRECTORYP DIVIDE DRIBBLE
  EJECT EQCAR EQLHASH EQN EQUALS ERRORSET 
  EVLIS EXPAND EXPLIST EXPLODE EXPLODEBINARY EXPLODEC 
  EXPLODECN EXPLODEHEX EXPLODEN EXPLODEOCTAL FASLEND FASLOUT 
))

(sys::explist '(
  FILEDATE FILEP FILE-LENGTH FIXP FLAG FLAGP FLAGPCAR 
  FLUID FLUIDP FLUSH FREXP GCTIME GENSYMP 
  GEQ GETD GETENV GETV GLOBAL GLOBALP 
  GREATERP HASHCONTENTS HELP HYPOT IDIFFERENCE IDP 
  IGEQ IGREATERP ILEQ ILESSP ILOGAND ILOGOR 
  ILOGXOR IMAX IMIN IMINUS IMINUSP INDIRECT 
  INORM IONEP IPLUS IQUOTIENT IREMAINDER IRIGHTSHIFT 
  ITIMES IZEROP LASTCAR LENGTHC LEQ LESSP 
  LINELENGTH LN LOADLIT LPOSN LSD MAPSTORE 
  MEMQ MINUS MKEVECT MKHASH MKQUOTE MKVECT 
  MKXVECT MODULEP MSD NCONS NEQ NEXTCHAR 
  NONDESCENDING OBLIST OBLIST ONEP ORDERP PAGELENGTH 
  PAIR PEEKCH PLIST PLUS POSN PREDICATE 
))

(sys::explist '(
  PRETTYPRINT PRIN PRINBINARY PRINCL PRINHEX PRINL 
  PRINOCTAL PRINTC PRINTCL PRINTL PUT PUTC 
  PUTD PUTHASH PUTV PUTVEC QCAAR QCADR 
  QCAR QCDAR QCDDR QCDR QGETV QPUTV 
  QUOTIENT RDF RDS READB READCH READLINE REMAINDER 
  REMD REMFLAG REPRESENTATION REVERSIP RPLACW RSEEK 
  RTELL SBITSET SEC SECD SECH SETDIFF SETELT 
  SETNTH SETPCHAR SIMPTYPE SIND SMEMQ SORTIP 
  SPACES SPOOL STOP STRUCTP STRUCTUREP SUBLA 
  SUPERPRINM SUPERPRINTM SYSTEM TAND TIMES TMPNAM 
  TTAB UNFLUID UNGLOBAL UNREADCH UPBV VERBOS 
  WHILE WRS XASSOC XCONS XDIFFERENCE XN 
  XTAB |APPLY0| |APPLY1| |APPLY2| |APPLY3| |ATAN2D| 
))

(sys::explist '(
  |ATAN2| |BINARY_CLOSE_INPUT| |BINARY_CLOSE_OUTPUT|
  |BINARY_OPEN_INPUT| |BINARY_OPEN_OUTPUT| |BINARY_PRIN1| 
  |BINARY_PRIN2| |BINARY_PRIN3| |BINARY_PRINBYTE| |BINARY_PRINC| 
  |BINARY_PRINFLOAT| |BINARY_READ2| |BINARY_READ3| |BINARY_READ4| 
  |BINARY_READBYTE| |BINARY_READFLOAT| |BINARY_SELECT_INPUT| |BINARY_TERPRI| 
  |BIT-NOT| |BIT-OF-BITS-NAME| |BPS-GETV| |BPS-PUTV| |BPS-UPBV| 
  |BYTE-GETV| |CHAR<=| |CHAR=| |CLOSE-LIBRARY| |COMPILE-ALL| 
  |COMPRESS1| |CONVERT-TO-ARRAY| |CONVERT-TO-STRUCT| |COPY-MODULE| 
  |COPY-STRING| |COPY-VECTOR| |CREATE-DIRECTORY| |C_END| |C_OUT| 
  |DATED-NAME| |DEFINE-IN-MODULE| |DOUBLE-EXECUTE| |DOUBLE-FLOATP| 
  |ERROR1| |EXPLODE2LCN| |EXPLODE2LC| |EXPLODE2N| |EXPLODE2| 
  |FGETV32| |FGETV64| |FILE-READABLEP| |FILE-WRITEABLEP| 
))

(sys::explist '(
  |FLOAT-DENORMALIZED-P| |FLOAT-INFINITY-P| |FLOAT-STRING| 
  |FLONUM-TO-STRING| |FP-EVALUATE| |FPUTV32| |FPUTV64| |FULLY-MACROEXPAND| 
  |GENSYM1| |GENSYM2| |GETV-BIT| |GETV16| |GETV32| |GETV8| 
  |HASH-TABLE-REHASH-SIZE| |HASH-TABLE-REHASH-THRESHOLD| |HASH-TABLE-TEST| 
  |HASHTAGGED-NAME| |IADD1| |INPUT-LIBRARIES| |IPLUS2| |IS-CONSOLE| 
  |ISUB1| |ITIMES2| |LIBRARY-NAME| |LIST2*| |LIST2| |LIST3| |LOAD-MODULE|
  |LOG10| |LONG-FLOATP| |MAKE-BPS| |MAKE-SPECIAL| |MAX2| |MIN2| |MKFVECT32|
  |MKFVECT64| |MKVECT16| |MKVECT32| |MKVECT8| |MODULAR-DIFFERENCE| |MODULAR-EXPT| 
  |MODULAR-MINUS| |MODULAR-NUMBER| |MODULAR-PLUS| |MODULAR-QUOTIENT| 
  |MODULAR-RECIPROCAL| |MODULAR-TIMES| |NEXT-RANDOM-NUMBER| |NOISY-SETQ| 
))

(sys::explist '(
  |OEM-SUPERVISOR| |OPEN-LIBRARY| |OUTPUT-LIBRARY| |PLUS2| |PRIN2| 
  |PRINC-DOWNCASE| |PRINC-UPCASE| |PUTV-BIT| |PUTV-CHAR| |PUTV16| 
  |PUTV32| |PUTV8| |RESTART-CSL| |SET-PRINT-PRECISION| |SET-SMALL-MODULUS| 
  |SHORT-FLOATP| |SHRINK-VECTOR| |SINGLE-FLOATP| |START-MODULE| |SUB1| 
  |SYMBOL-ENV| |SYMBOL-FASTGETS| |SYMBOL-FN-CELL| |SYMBOL-MAKE-FASTGET| 
  |SYMBOL-SET-DEFINITION| |SYMBOL-SET-ENV| |SYMBOL-TO-STRING| |TIME*| 
  |TIMES2| |UNDOUBLE-EXECUTE| |UNMAKE-GLOBAL| |UNMAKE-SPECIAL|
  |USE-PACKAGE*| |WRITE-MODULE| 
))
  

(sys::explist '(open_server sock_get_int sock_send_int sock_get_string_buf
                sock_send_string_len sock_get_float sock_send_float 
                sock_send_wakeup server_switch flush_stdout sock_send_signal
                print_line plus_infinity minus_infinity NANQ))

(sys::explist '(xdr-open xdr-write xdr-read))

(sys::explist '(grep))

(sys::explist '(get-ax-char set-ax-return-code))

(sys::explist '(hashtable-flavour))

(sys::explist '(init-lm close-lm))

(sys::explist '(om-openFileDev om-openStringDev om-closeDev om-setDevEncoding
                om-makeConn om-closeConn om-getConnInDev om-getConnOutDev
                om-connectTCP om-bindTCP om-putApp om-putEndApp om-putAtp
                om-putEndAtp om-putAttr om-putEndAttr om-putBind om-putEndBind
                om-putBVar om-putEndBVar om-putError om-putEndError
                om-putObject om-putEndObject om-putInt om-putFloat
                om-putByteArray om-putVar om-putString om-putSymbol
                om-getApp om-getEndApp om-getAtp om-getEndAtp om-getAttr
                om-getEndAttr om-getBind om-getEndBind om-getBVar om-getEndBVar                 om-getError om-getEndError om-getObject om-getEndObject
                om-getInt om-getFloat om-getByteArray om-getVar om-getString
                om-getSymbol om-getType om-stringToStringPtr 
                om-stringPtrToString))

(sys::explist '(om-read om-supportsCD om-supportsSymbol om-listCDs
                om-listSymbols om-whichCDs))

