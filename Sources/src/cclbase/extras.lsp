
;; RLISP to LISP converter. A C Norman 2002


(de expand (l fn) (if (null (cdr l)) (car l) (list fn (car l) (expand (cdr l)
fn))))

(de deflist (a b) (prog (var1001) (setq var1001 a) lab1000 (if (null var1001)
(return nil)) (prog (v) (setq v (car var1001)) (put (car v) b (cadr v))) (
setq var1001 (cdr var1001)) (go lab1000)))

(de global (x) (prog (var1003) (setq var1003 x) lab1002 (if (null var1003) (
return nil)) (prog (v) (setq v (car var1003)) (progn (make-global v) (if (not
(boundp v)) (set v nil)))) (setq var1003 (cdr var1003)) (go lab1002)))

(de fluid (x) (prog (var1005) (setq var1005 x) lab1004 (if (null var1005) (
return nil)) (prog (v) (setq v (car var1005)) (progn (make-special v) (if (
not (boundp v)) (set v nil)))) (setq var1005 (cdr var1005)) (go lab1004)))

(de unglobal (x) (prog (var1007) (setq var1007 x) lab1006 (if (null var1007) 
(return nil)) (prog (v) (setq v (car var1007)) (unmake-global v)) (setq 
var1007 (cdr var1007)) (go lab1006)))

(de unfluid (x) (prog (var1009) (setq var1009 x) lab1008 (if (null var1009) (
return nil)) (prog (v) (setq v (car var1009)) (unmake-special v)) (setq 
var1009 (cdr var1009)) (go lab1008)))

(global (quote ($eof$)))

(setq $eof$ (special-char 8))

(de s::casetest (val g) (if (atom val) (list (quote eql) g (mkquote val)) (if
(null (cdr val)) (list (quote eql) g (mkquote (car val))) (cons (quote or) (
prog (var1011 var1012) (setq var1011 val) lab1010 (if (null var1011) (return 
(nreverse var1012))) (prog (p) (setq p (car var1011)) (setq var1012 (cons (
list (quote eql) g (mkquote p)) var1012))) (setq var1011 (cdr var1011)) (go 
lab1010))))))

(de s::expand_case (u g) (if (null u) nil (if (and (null (cdr u)) (or (eqcar 
(car u) (quote t)) (eqcar (car u) (quote otherwise)))) (list (cons t (cdar u)
)) (cons (cons (s::casetest (caar u) g) (cdar u)) (s::expand_case (cdr u) g))
)))

(dm case (u &optional env) (prog (k g) (setq k (cadr u)) (setq g (gensym)) (
setq u (cddr u)) (return (list (quote let) (list (list g k)) (cons (quote 
cond) (s::expand_case u g))))))

(de oem-supervisor nil (print (eval (read))))

(de break-loop (a) (prog (prompt ifile ofile u v) (setq ifile (rds *debug-io*
)) (setq ofile (wrs *debug-io*)) (setq prompt (setpchar 
"Break loop (:X exits)> ")) top (setq u (read)) (if (equal u (quote ::x)) (go
exit) (if (equal u (quote ::q)) (progn (enable-backtrace nil) (princ 
"Backtrace now disabled") (terpri)) (if (equal u (quote ::v)) (progn (
enable-backtrace t) (princ "Backtrace now enabled") (terpri)) (progn (if (
null u) (setq v nil) (setq v (errorset u nil nil))) (if (atom v) (progn (
princ ":Q   quietens backtrace") (terpri) (princ ":V   enables backtrace") (
terpri) (princ ":X   exits from break loop") (terpri) (princ 
"else form for evaluation") (terpri)) (progn (prin "=> ") (prinl (car v)) (
terpri))))))) (go top) exit (rds ifile) (wrs ofile) (setpchar prompt) (return
nil)))

(global (quote (s::gensym-serial)))

(setq s::gensym-serial 0)

(de s::stamp (n) (if (lessp n 0) (append (s::stamp (minus n)) (quote (-))) (
if (equal n 0) nil (cons (schar "0123456789abcdefghijklmnopqrstuvwxyz" (
remainder n 36)) (s::stamp (truncate n 36))))))

(de dated-name (base) (intern (list-to-string (append (explodec base) (cons (
quote _) (append (reverse (s::stamp (datestamp))) (cons (quote _) (explodec (
setq s::gensym-serial (plus s::gensym-serial 1))))))))))

(de hashtagged-name (base value) (intern (list-to-string (append (explodec 
base) (cons (quote _) (s::stamp (md60 value)))))))

(remflag (quote (sort sortip)) (quote lose))

(de sort (l pred) (stable-sortip (append l nil) pred))

(de stable-sort (l pred) (stable-sortip (append l nil) pred))

(de sortip (l pred) (stable-sortip l pred))

(de stable-sortip (l pred) (prog (l1 l2 w) (if (null l) (return l)) (setq l1 
l) (setq l2 (cdr l)) (if (null l2) (return l)) (setq l (cdr l2)) (if (null l)
(progn (if (apply2 pred (car l2) (car l1)) (progn (setq l (car l1)) (rplaca 
l1 (car l2)) (rplaca l2 l))) (return l1))) (setq l l1) (prog nil lab1013 (if 
(null (and l2 (not (apply2 pred (car l2) (car l))))) (return nil)) (progn (
setq l l2) (setq l2 (cdr l2))) (go lab1013)) (if (null l2) (return l1)) (setq
l2 l1) (setq l (cddr l2)) (prog nil lab1014 (if (null (and l (cdr l))) (
return nil)) (progn (setq l2 (cdr l2)) (setq l (cddr l))) (go lab1014)) (setq
l l2) (setq l2 (cdr l2)) (rplacd l nil) (setq l1 (stable-sortip l1 pred)) (
setq l2 (stable-sortip l2 pred)) (setq l (setq w (list nil))) (prog nil 
lab1015 (if (null (and l1 l2)) (return nil)) (progn (if (apply2 pred (car l2)
(car l1)) (progn (rplacd w l2) (setq w l2) (setq l2 (cdr l2))) (progn (
rplacd w l1) (setq w l1) (setq l1 (cdr l1))))) (go lab1015)) (if l1 (setq l2 
l1)) (rplacd w l2) (return (cdr l))))

(fluid (quote (*prinl-visited-nodes* *prinl-index* *prinl-fn* *loop-print* 
*print-array* *print-length* *print-level*)))

(setq *print-length* (setq *print-level* nil))

(setq *prinl-visited-nodes* (mkhash 10 0 1.5))

(de s::prinl0 (x *prinl-fn*) (prog (*prinl-index*) (setq *prinl-index* 0) (
unwind-protect (progn (s::prinl1 x 0) (s::prinl2 x 0)) (clrhash 
*prinl-visited-nodes*)) (return x)))

(de s::prinl1 (x depth) (prog (w length) (if (and (fixp *print-level*) (
greaterp depth *print-level*)) (return nil)) (setq length 0) top (if (and (
atom x) (not (simple-vector-p x)) (not (gensymp x))) (return nil) (if (setq w
(gethash x *prinl-visited-nodes*)) (progn (if (equal w 0) (progn (setq 
*prinl-index* (plus *prinl-index* 1)) (puthash x *prinl-visited-nodes* 
*prinl-index*))) (return nil)) (progn (puthash x *prinl-visited-nodes* 0) (if
(simple-vector-p x) (progn (if *print-array* (progn (setq length (upbv x)) (
if (and (fixp *print-length*) (lessp *print-length* length)) (setq length 
*print-length*)) (prog (i) (setq i 0) lab1016 (if (minusp (times 1 (
difference length i))) (return nil)) (s::prinl1 (getv x i) (plus depth 1)) (
setq i (plus i 1)) (go lab1016))))) (if (not (atom x)) (progn (s::prinl1 (car
x) (plus depth 1)) (if (and (fixp *print-length*) (greaterp (setq length (
plus length 1)) *print-length*)) (return nil)) (setq x (cdr x)) (go top))))))
)))

(de s::prinl2 (x depth) (if (and (fixp *print-level*) (greaterp depth 
*print-level*)) (princ "#") (if (and (atom x) (not (simple-vector-p x)) (not 
(gensymp x))) (progn (if (and (complex-arrayp x) (not *print-array*)) (princ 
"[Array]") (if (and (structp x) (not *print-array*)) (princ "[Struct]") (
funcall *prinl-fn* x)))) (prog (w length) (setq w (gethash x 
*prinl-visited-nodes*)) (if (not (zerop w)) (progn (if (lessp w 0) (progn (
princ "#") (princ (minus w)) (princ "#") (return nil)) (progn (puthash x 
*prinl-visited-nodes* (minus w)) (princ "#") (princ w) (princ "="))))) (if (
simple-vector-p x) (progn (princ "%(") (if *print-array* (progn (setq length 
(upbv x)) (if (and (fixp *print-length*) (lessp *print-length* length)) (setq
length *print-length*)) (prog (i) (setq i 0) lab1017 (if (minusp (times 1 (
difference length i))) (return nil)) (progn (s::prinl2 (getv x i) (plus depth
1)) (if (not (equal i (upbv x))) (princ " "))) (setq i (plus i 1)) (go 
lab1017))) (princ "...")) (princ ")") (return nil)) (if (atom x) (return (
funcall *prinl-fn* x)))) (princ "(") (setq length 0) loop (s::prinl2 (car x) 
(plus depth 1)) (setq x (cdr x)) (if (atom x) (progn (if (simple-vector-p x) 
(progn (princ " . %(") (if *print-array* (progn (setq length (upbv x)) (if (
and (fixp *print-length*) (lessp *print-length* length)) (setq length 
*print-length*)) (prog (i) (setq i 0) lab1018 (if (minusp (times 1 (
difference length i))) (return nil)) (progn (s::prinl2 (getv x i) (plus depth
1)) (if (not (equal i (upbv x))) (princ " "))) (setq i (plus i 1)) (go 
lab1018))) (princ "...")) (princ ")")) (if x (progn (princ " . ") (funcall 
*prinl-fn* x)))) (return (princ ")")))) (if (and (fixp *print-length*) (
greaterp (setq length (plus length 1)) *print-length*)) (return (princ 
" ...)"))) (setq w (gethash x *prinl-visited-nodes*)) (if (not (equal w 0)) (
if (lessp w 0) (progn (princ " . #") (princ (minus w)) (return (princ "#)")))
(progn (princ " . ") (s::prinl2 x (plus depth 1)) (return (princ ")")))) (
princ " ")) (go loop)))))

(de printl (x) (progn (prinl x) (terpri) x))

(de printcl (x) (progn (princl x) (terpri) x))

(de princl (x) (s::prinl0 x (function princ)))

(de prinl (x) (s::prinl0 x (function prin)))

(fluid (quote (bn bufferi buffero indblanks indentlevel initialblanks lmar 
pendingrpars rmar rparcount stack)))

(global (quote (*quotes *pretty-symmetric thin*)))

(setq *pretty-symmetric t)

(setq *quotes t)

(setq thin* 5)

(de prettyprint (x) (progn (superprinm x (posn)) (terpri) nil))

(de superprintm (x lmar) (progn (superprinm x lmar) (terpri) x))

(de superprinm (x lmar) (prog (stack bufferi buffero bn initialblanks rmar 
pendingrpars indentlevel indblanks rparcount w) (setq bufferi (setq buffero (
list nil))) (setq initialblanks 0) (setq rparcount 0) (setq indblanks 0) (
setq rmar (linelength nil)) (linelength 500) (if (lessp rmar 25) (error 0 (
list rmar "Linelength too short for superprinting"))) (setq bn 0) (setq 
indentlevel 0) (if (geq (plus lmar 20) rmar) (setq lmar (difference rmar 21))
) (setq w (posn)) (if (greaterp w lmar) (progn (terpri) (setq w 0))) (if (
lessp w lmar) (setq initialblanks (difference lmar w))) (s::prindent x (plus 
lmar 3)) (s::overflow (quote none)) (linelength rmar) (return x)))

(dm s::top (u &optional v) (quote (car stack)))

(dm s::depth (u &optional v) (list (quote car) (cadr u)))

(dm s::indenting (u &optional v) (list (quote cadr) (cadr u)))

(dm s::blankcount (u &optional v) (list (quote caddr) (cadr u)))

(dm s::blanklist (u &optional v) (list (quote cdddr) (cadr u)))

(dm s::setindenting (u &optional v) (list (quote rplaca) (list (quote cdr) (
cadr u)) (caddr u)))

(dm s::setblankcount (u &optional v) (list (quote rplaca) (list (quote cddr) 
(cadr u)) (caddr u)))

(dm s::setblanklist (u &optional v) (list (quote rplacd) (list (quote cddr) (
cadr u)) (caddr u)))

(dm s::newframe (u &optional v) (list (quote list) (cadr u) nil 0))

(dm s::blankp (u &optional v) (list (quote numberp) (list (quote car) (cadr u
))))

(de s::prindent (x n) (if (atom x) (if (simple-vector-p x) (s::prvector x n) 
(prog (var1020) (setq var1020 (if *pretty-symmetric (if (stringp x) (
s::explodes x) (explode x)) (explode2 x))) lab1019 (if (null var1020) (return
nil)) (prog (c) (setq c (car var1020)) (s::putch c)) (setq var1020 (cdr 
var1020)) (go lab1019))) (if (s::quotep x) (progn (s::putch (quote |'|)) (
s::prindent (cadr x) (plus n 1))) (prog (cx) (if (greaterp (times 4 n) (times
3 rmar)) (progn (s::overflow (quote all)) (setq n (truncate n 8)) (if (
greaterp initialblanks n) (progn (setq lmar (plus (difference lmar 
initialblanks) n)) (setq initialblanks n))))) (setq stack (cons (s::newframe 
n) stack)) (s::putch (cons (quote lpar) (s::top))) (setq cx (car x)) (
s::prindent cx (plus n 1)) (if (and (idp cx) (not (atom (cdr x)))) (setq cx (
get cx (quote s::ppformat))) (setq cx nil)) (if (and (equal cx 2) (atom (cddr
x))) (setq cx nil)) (if (equal cx (quote prog)) (progn (s::putch (quote | |)
) (s::prindent (car (setq x (cdr x))) (plus n 3)))) (setq x (cdr x)) scan (if
(atom x) (go outt)) (s::finishpending) (if (equal cx (quote prog)) (progn (
s::putblank) (s::overflow bufferi) (if (atom (car x)) (progn (setq lmar (setq
initialblanks (max (difference lmar 6) 0))) (s::prindent (car x) (difference
n 3)) (setq x (cdr x)) (if (and (not (atom x)) (atom (car x))) (go scan)) (
if (greaterp (plus lmar bn) n) (s::putblank) (prog (i) (setq i (plus lmar bn)
) lab1021 (if (minusp (times 1 (difference (difference n 1) i))) (return nil)
) (s::putch (quote | |)) (setq i (plus i 1)) (go lab1021))) (if (atom x) (go 
outt))))) (if (numberp cx) (progn (setq cx (difference cx 1)) (if (equal cx 0
) (setq cx nil)) (s::putch (quote | |))) (s::putblank))) (s::prindent (car x)
(plus n 3)) (setq x (cdr x)) (go scan) outt (if (not (null x)) (progn (
s::finishpending) (s::putblank) (s::putch (quote |.|)) (s::putch (quote | |))
(s::prindent x (plus n 5)))) (s::putch (cons (quote rpar) (difference n 3)))
(if (and (equal (s::indenting (s::top)) (quote indent)) (not (null (
s::blanklist (s::top))))) (s::overflow (car (s::blanklist (s::top)))) (
s::endlist (s::top))) (setq stack (cdr stack))))))

(de s::explodes (x) (explode x))

(de s::prvector (x n) (prog (bound) (setq bound (upbv x)) (setq stack (cons (
s::newframe n) stack)) (s::putch (cons (quote lsquare) (s::top))) (
s::prindent (getv x 0) (plus n 3)) (prog (i) (setq i 1) lab1022 (if (minusp (
times 1 (difference bound i))) (return nil)) (progn (s::putch (quote |,|)) (
s::putblank) (s::prindent (getv x i) (plus n 3))) (setq i (plus i 1)) (go 
lab1022)) (s::putch (cons (quote rsquare) (difference n 3))) (s::endlist (
s::top)) (setq stack (cdr stack))))

(de s::putblank nil (prog nil (s::putch (s::top)) (s::setblankcount (s::top) 
(plus (s::blankcount (s::top)) 1)) (s::setblanklist (s::top) (cons bufferi (
s::blanklist (s::top)))) (setq indblanks (plus indblanks 1))))

(de s::endlist (l) (setq pendingrpars (cons l pendingrpars)))

(de s::finishpending nil (progn (prog (var1026) (setq var1026 pendingrpars) 
lab1025 (if (null var1026) (return nil)) (prog (stackframe) (setq stackframe 
(car var1026)) (progn (if (neq (s::indenting stackframe) (quote indent)) (
prog (var1024) (setq var1024 (s::blanklist stackframe)) lab1023 (if (null 
var1024) (return nil)) (prog (b) (setq b (car var1024)) (progn (rplaca b (
quote | |)) (setq indblanks (difference indblanks 1)))) (setq var1024 (cdr 
var1024)) (go lab1023))) (s::setblanklist stackframe t))) (setq var1026 (cdr 
var1026)) (go lab1025)) (setq pendingrpars nil)))

(de s::quotep (x) (and *quotes (not (atom x)) (equal (car x) (quote quote)) (
not (atom (cdr x))) (null (cddr x))))

(put (quote prog) (quote s::ppformat) (quote prog))

(put (quote lambda) (quote s::ppformat) 1)

(put (quote lambdaq) (quote s::ppformat) 1)

(put (quote setq) (quote s::ppformat) 1)

(put (quote set) (quote s::ppformat) 1)

(put (quote while) (quote s::ppformat) 1)

(put (quote t) (quote s::ppformat) 1)

(put (quote de) (quote s::ppformat) 2)

(put (quote df) (quote s::ppformat) 2)

(put (quote dm) (quote s::ppformat) 2)

(put (quote defun) (quote s::ppformat) 2)

(put (quote defmacro) (quote s::ppformat) 2)

(put (quote foreach) (quote s::ppformat) 4)

(de s::putch (c) (prog nil (if (atom c) (setq rparcount 0) (if (s::blankp c) 
(progn (setq rparcount 0) (go nocheck)) (if (equal (car c) (quote rpar)) (
progn (setq rparcount (plus rparcount 1)) (if (greaterp rparcount 4) (progn (
s::putch (quote | |)) (setq rparcount 2)))) (setq rparcount 0)))) (prog nil 
lab1027 (if (null (geq (plus lmar bn) rmar)) (return nil)) (s::overflow (
quote more)) (go lab1027)) nocheck (setq bufferi (cdr (rplacd bufferi (list c
)))) (setq bn (plus bn 1))))

(de s::overflow (flg) (prog (c blankstoskip) (if (and (equal indblanks 0) (
greaterp initialblanks 3) (equal flg (quote more))) (progn (setq 
initialblanks (difference initialblanks 3)) (setq lmar (difference lmar 3)) (
return (quote moved-left)))) fblank (if (equal bn 0) (progn (if (not (equal 
flg (quote more))) (return (quote empty))) (if (atom (car buffero)) (prin2 
"%+")) (terpri) (setq lmar 0) (return (quote continued))) (progn (spaces 
initialblanks) (setq initialblanks 0))) (setq buffero (cdr buffero)) (setq bn
(difference bn 1)) (setq lmar (plus lmar 1)) (setq c (car buffero)) (if (
atom c) (progn (prin2 c) (go fblank)) (if (s::blankp c) (if (not (atom 
blankstoskip)) (progn (prin2 (quote | |)) (setq indblanks (difference 
indblanks 1)) (if (eq c (car blankstoskip)) (progn (rplacd blankstoskip (
difference (cdr blankstoskip) 1)) (if (equal (cdr blankstoskip) 0) (setq 
blankstoskip t)))) (go fblank)) (go blankfound)) (if (or (equal (car c) (
quote lpar)) (equal (car c) (quote lsquare))) (progn (prin2 (get (car c) (
quote s::ppchar))) (if (equal flg (quote none)) (go fblank)) (setq c (cdr c))
(if (not (null (s::blanklist c))) (go fblank)) (if (greaterp (s::depth c) 
indentlevel) (progn (setq indentlevel (s::depth c)) (s::setindenting c (quote
indent)))) (go fblank)) (if (or (equal (car c) (quote rpar)) (equal (car c) 
(quote rsquare))) (progn (if (lessp (cdr c) indentlevel) (setq indentlevel (
cdr c))) (prin2 (get (car c) (quote s::ppchar))) (go fblank)) (error 0 (list 
c "UNKNOWN TAG IN OVERFLOW")))))) blankfound (if (eqcar (s::blanklist c) 
buffero) (s::setblanklist c nil)) (setq indblanks (difference indblanks 1)) (
if (greaterp (s::depth c) indentlevel) (progn (if (equal flg (quote none)) (
progn (prin2 (quote | |)) (go fblank))) (if blankstoskip (setq blankstoskip 
nil) (progn (setq indentlevel (s::depth c)) (s::setindenting c (quote indent)
))))) (if (greaterp (s::blankcount c) (difference thin* 1)) (progn (setq 
blankstoskip (cons c (difference (s::blankcount c) 2))) (s::setindenting c (
quote thin)) (s::setblankcount c 1) (setq indentlevel (difference (s::depth c
) 1)) (prin2 (quote | |)) (go fblank))) (s::setblankcount c (difference (
s::blankcount c) 1)) (terpri) (setq lmar (setq initialblanks (s::depth c))) (
if (eq buffero flg) (return (quote to-flg))) (if (or blankstoskip (not (equal
flg (quote more)))) (go fblank)) (return (quote more))))

(put (quote lpar) (quote s::ppchar) (quote |(|))

(put (quote lsquare) (quote s::ppchar) (quote |[|))

(put (quote rpar) (quote s::ppchar) (quote |)|))

(put (quote rsquare) (quote s::ppchar) (quote |]|))

(de fetch-url (url &optional dest) (prog (a b c d e w) (setq a (open-url url)
) (if (null a) (return nil)) (if dest (progn (setq d (open dest (quote output
))) (if (null d) (progn (close a) (return (error 0 
"unable to open destination file")))) (setq d (wrs d)))) (setq b (rds a)) (
setq w (linelength 500)) (prog nil lab1028 (if (null (not (equal (setq c (
readch)) $eof$))) (return nil)) (princ c) (go lab1028)) (linelength e) (rds b
) (close a) (if dest (close (wrs d)))))


;; end of file
