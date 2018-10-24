
/* u12.c                 Machine generated C code */

/* Signature: 00000000 26-Oct-2000 */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "arith.h"
#include "entries.h"


/*
(DEFUN BOOT::|isHomogeneousList| (|y|)
   (PROG (|x| |z|)
      (RETURN
         (SEQ
            (COND
               ((AND
                   (PAIRP |y|)
                   (EQ (QCDR |y|) NIL)
                   (PROGN (BOOT:SPADLET |x| (QCAR |y|)) 'T))
                  'T)
               ((AND |y| (CDR |y|))
                  (BOOT:SPADLET |z| (CAR |y|))
                  (PROG (#:G18932)
                     (BOOT:SPADLET #:G18932 'T)
                     (RETURN
                        (DO ((#:G18933 NIL (NULL #:G18932))
                              (#:G18934 (CDR |y|) (CDR #:G18934))
                              (|x| NIL))
                           ((OR
                               #:G18933
                               (ATOM #:G18934)
                               (PROGN (SETQ |x| (CAR #:G18934)) NIL))
                              #:G18932)
                           (SEQ
                              (EXIT
                                 (SETQ #:G18932
                                    (AND
                                       #:G18932
                                       (BOOT:|BOOT-EQUAL|
                                          |x|
                                          |z|)))) ))) ))
               ('T NIL)))) ))

*/



/* Code for BOOT::|isHomogeneousList| */

static Lisp_Object CC_BOOT__isHomogeneousList(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V101, V102, V103, V104, V105;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isHomogeneousList|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = V2;
/* end of prologue */
    V101 = stack[0];
    fn = elt(env, 1); /* CONSP */
    V101 = (*qfn1(fn))(qenv(fn), V101);
    nil = C_nil;
    if (exception_pending()) goto V107;
    if (V101 == nil) goto V15;
    V101 = stack[0];
    V101 = qcdr(V101);
    if (!(V101 == nil)) goto V15;
    V101 = lisp_true;
    if (V101 == nil) goto V15;
    V101 = lisp_true;
    { popv(1); return onevalue(V101); }

V15:
    V101 = stack[0];
    if (V101 == nil) goto V28;
    V101 = stack[0];
    if (!car_legal(V101)) goto V108;
    V101 = qcdr(V101);
    if (V101 == nil) goto V28;
    V101 = stack[0];
    if (!car_legal(V101)) goto V109;
    V101 = qcar(V101);
    V104 = V101;
    V101 = lisp_true;
    V103 = V101;
    V101 = stack[0];
    if (!car_legal(V101)) goto V108;
    V102 = qcdr(V101);
    V101 = nil;
    V105 = V102;
    V102 = V101;
    goto V49;

V49:
    V101 = V102;
    if (!(V101 == nil)) { popv(1); return onevalue(V103); }
    V101 = V105;
    if (!consp(V101)) { popv(1); return onevalue(V103); }
    V101 = V105;
    if (!car_legal(V101)) goto V109;
    V101 = qcar(V101);
    V102 = V101;
    V101 = nil;
    if (!(V101 == nil)) { popv(1); return onevalue(V103); }
    V101 = V103;
    if (V101 == nil) goto V68;
    V101 = V104;
    V101 = (cl_equal(V102, V101) ? lisp_true : nil);
    goto V67;

V67:
    V103 = V101;
    V101 = V103;
    V101 = (V101 == nil ? lisp_true : nil);
    V102 = V101;
    V101 = V105;
    if (!car_legal(V101)) goto V108;
    V101 = qcdr(V101);
    V105 = V101;
    goto V49;

V68:
    V101 = nil;
    goto V67;

V28:
    V101 = lisp_true;
    if (V101 == nil) goto V97;
    V101 = nil;
    { popv(1); return onevalue(V101); }

V97:
    V101 = nil;
    { popv(1); return onevalue(V101); }
/* error exit handlers */
V109:
    popv(1);
    return error(1, err_bad_car, V101);
V108:
    popv(1);
    return error(1, err_bad_cdr, V101);
V107:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|LO;-;2$;3| (|x| |$|)
   (CONS (BOOT:SPADCALL (QCAR |x|) (VMLISP:QREFELT |$| 16)) (QCDR |x|)))

*/



/* Code for BOOT::|LO;-;2$;3| */

static Lisp_Object CC_BOOT__LOUKU2DU3(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V40, V41, V42;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|LO;-;2$;3|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    V40 = V3;
    stack[0] = V2;
/* end of prologue */
    V41 = V40;
    V40 = (Lisp_Object)257; /* 16 */
    V40 = Lgetv(nil, V41, V40);
    nil = C_nil;
    if (exception_pending()) goto V44;
    env = stack[-1];
    V41 = V40;
    if (!car_legal(V41)) goto V45;
    V42 = qcar(V41);
    V41 = stack[0];
    V41 = qcar(V41);
    if (!car_legal(V40)) goto V46;
    V40 = qcdr(V40);
    V40 = Lapply2(nil, 3, V42, V41, V40);
    nil = C_nil;
    if (exception_pending()) goto V44;
    V41 = V40;
    V40 = stack[0];
    V40 = qcdr(V40);
    popv(2);
    { Lisp_Object retVal = cons(V41, V40);
    errexit();
    return onevalue(retVal); }
/* error exit handlers */
V46:
    popv(2);
    return error(1, err_bad_cdr, V40);
V45:
    popv(2);
    return error(1, err_bad_car, V41);
V44:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|EUCDOM-;gcd;3S;5| (|x| |y| |$|)
   (PROG (BOOT::|#G13| BOOT::|#G14|)
      (RETURN
         (SEQ
            (BOOT::LETT
               |x|
               (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 18))
               BOOT::|EUCDOM-;gcd;3S;5|)
            (BOOT::LETT
               |y|
               (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 18))
               BOOT::|EUCDOM-;gcd;3S;5|)
            (SEQ
               BOOT::G190
               (COND
                  ((NULL
                      (COND
                         ((BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 8)) 'NIL)
                         ('T 'T)))
                     (GO BOOT::G191)))
               (SEQ
                  (PROGN
                     (BOOT::LETT BOOT::|#G13| |y| BOOT::|EUCDOM-;gcd;3S;5|)
                     (BOOT::LETT
                        BOOT::|#G14|
                        (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 19))
                        BOOT::|EUCDOM-;gcd;3S;5|)
                     (BOOT::LETT |x| BOOT::|#G13| BOOT::|EUCDOM-;gcd;3S;5|)
                     (BOOT::LETT
                        |y|
                        BOOT::|#G14|
                        BOOT::|EUCDOM-;gcd;3S;5|))
                  (EXIT
                     (BOOT::LETT
                        |y|
                        (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 18))
                        BOOT::|EUCDOM-;gcd;3S;5|)))
               NIL
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT |x|)))) )

*/



/* Code for BOOT::|EUCDOM-;gcd;3S;5| */

static Lisp_Object MS_CDECL CC_BOOT__EUCDOMKUgcdU3SU5(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V165, V166, V167, V168;
    argcheck(nargs, 3, "EUCDOM-;gcd;3S;5");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EUCDOM-;gcd;3S;5|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = V4;
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    V166 = stack[0];
    V165 = (Lisp_Object)289; /* 18 */
    V165 = Lgetv(nil, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-4];
    V166 = V165;
    if (!car_legal(V166)) goto V174;
    V167 = qcar(V166);
    V166 = stack[-2];
    if (!car_legal(V165)) goto V175;
    V165 = qcdr(V165);
    V165 = Lapply2(nil, 3, V167, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-4];
    stack[-2] = V165;
    V166 = stack[0];
    V165 = (Lisp_Object)289; /* 18 */
    V165 = Lgetv(nil, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-4];
    V166 = V165;
    if (!car_legal(V166)) goto V174;
    V167 = qcar(V166);
    V166 = stack[-1];
    if (!car_legal(V165)) goto V175;
    V165 = qcdr(V165);
    V165 = Lapply2(nil, 3, V167, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-4];
    stack[-1] = V165;
    goto V78;

V78:
    V166 = stack[0];
    V165 = (Lisp_Object)129; /* 8 */
    V165 = Lgetv(nil, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-4];
    V166 = V165;
    if (!car_legal(V166)) goto V174;
    V167 = qcar(V166);
    V166 = stack[-1];
    if (!car_legal(V165)) goto V175;
    V165 = qcdr(V165);
    V165 = Lapply2(nil, 3, V167, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-4];
    if (V165 == nil) goto V73;
    V165 = nil;
    goto V71;

V71:
    if (V165 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    V165 = stack[-1];
    stack[-3] = V165;
    V166 = stack[0];
    V165 = (Lisp_Object)305; /* 19 */
    V165 = Lgetv(nil, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-4];
    V166 = V165;
    if (!car_legal(V166)) goto V174;
    V168 = qcar(V166);
    V167 = stack[-2];
    V166 = stack[-1];
    if (!car_legal(V165)) goto V175;
    V165 = qcdr(V165);
    V165 = Lapply3(nil, 4, V168, V167, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-4];
    V166 = V165;
    V165 = stack[-3];
    stack[-2] = V165;
    V165 = V166;
    stack[-1] = V165;
    V166 = stack[0];
    V165 = (Lisp_Object)289; /* 18 */
    V165 = Lgetv(nil, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-4];
    V166 = V165;
    if (!car_legal(V166)) goto V174;
    V167 = qcar(V166);
    V166 = stack[-1];
    if (!car_legal(V165)) goto V175;
    V165 = qcdr(V165);
    V165 = Lapply2(nil, 3, V167, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-4];
    stack[-1] = V165;
    goto V78;

V73:
    V165 = lisp_true;
    if (V165 == nil) goto V100;
    V165 = lisp_true;
    goto V71;

V100:
    V165 = nil;
    goto V71;
/* error exit handlers */
V175:
    popv(5);
    return error(1, err_bad_cdr, V165);
V174:
    popv(5);
    return error(1, err_bad_car, V166);
V173:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|newLookupInAddChain| (BOOT::|op|
      BOOT::|sig|
      BOOT::|addFormDomain|
      BOOT::|dollar|)
   (PROG (BOOT::|addFunction|)
      (RETURN
         (PROGN
            (COND
               (BOOT::|$monitorNewWorld|
                  (BOOT::|sayLooking1|
                     (VMLISP:MAKESTRING "looking up add-chain: ")
                     BOOT::|addFormDomain|)))
            (BOOT:SPADLET
               BOOT::|addFunction|
               (BOOT::|newLookupInDomain|
                  BOOT::|op|
                  BOOT::|sig|
                  BOOT::|addFormDomain|
                  BOOT::|dollar|
                  5))
            (COND
               (BOOT::|addFunction|
                  (COND
                     (BOOT::|$monitorNewWorld|
                        (BOOT::|sayLooking1|
                           (BOOT::|concat|
                              (VMLISP:MAKESTRING
                                 "<----add-chain function found for ")
                              (BOOT::|form2String|
                                 (BOOT::|devaluate| BOOT::|addFormDomain|))
                              (VMLISP:MAKESTRING "<----"))
                           (CDR BOOT::|addFunction|))))
                  BOOT::|addFunction|)
               ('T NIL)))) ))

*/



/* Code for BOOT::|newLookupInAddChain| */

static Lisp_Object MS_CDECL CC_BOOT__newLookupInAddChain(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V78, V79, V80, V81, V82;
    Lisp_Object fn;
    argcheck(nargs, 4, "newLookupInAddChain");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|newLookupInAddChain|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V5);
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        pop(V5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = V5;
    stack[-1] = V4;
    stack[-2] = V3;
    stack[-3] = V2;
/* end of prologue */
    V78 = qvalue(elt(env, 1)); /* BOOT::|$monitorNewWorld| */
    if (V78 == nil) goto V26;
    V79 = elt(env, 2); /* "looking up add-chain: " */
    V78 = stack[-1];
    fn = elt(env, 5); /* BOOT::|sayLooking1| */
    V78 = (*qfn2(fn))(qenv(fn), V79, V78);
    nil = C_nil;
    if (exception_pending()) goto V87;
    env = stack[-4];
    goto V26;

V26:
    V82 = stack[-3];
    V81 = stack[-2];
    V80 = stack[-1];
    V79 = stack[0];
    V78 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 6); /* BOOT::|newLookupInDomain| */
    V78 = (*qfnn(fn))(qenv(fn), 5, V82, V81, V80, V79, V78);
    nil = C_nil;
    if (exception_pending()) goto V87;
    env = stack[-4];
    stack[-2] = V78;
    V78 = stack[-2];
    if (V78 == nil) goto V45;
    V78 = qvalue(elt(env, 1)); /* BOOT::|$monitorNewWorld| */
    if (V78 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = elt(env, 3); /* "<----add-chain function found for " */
    V78 = stack[-1];
    fn = elt(env, 7); /* BOOT::|devaluate| */
    V78 = (*qfn1(fn))(qenv(fn), V78);
    nil = C_nil;
    if (exception_pending()) goto V87;
    env = stack[-4];
    fn = elt(env, 8); /* BOOT::|form2String| */
    V79 = (*qfn1(fn))(qenv(fn), V78);
    nil = C_nil;
    if (exception_pending()) goto V87;
    env = stack[-4];
    V78 = elt(env, 4); /* "<----" */
    fn = elt(env, 9); /* BOOT::|concat| */
    V79 = (*qfnn(fn))(qenv(fn), 3, stack[0], V79, V78);
    nil = C_nil;
    if (exception_pending()) goto V87;
    env = stack[-4];
    V78 = stack[-2];
    if (!car_legal(V78)) goto V88;
    V78 = qcdr(V78);
    fn = elt(env, 5); /* BOOT::|sayLooking1| */
    V78 = (*qfn2(fn))(qenv(fn), V79, V78);
    nil = C_nil;
    if (exception_pending()) goto V87;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

V45:
    V78 = lisp_true;
    if (V78 == nil) goto V75;
    V78 = nil;
    { popv(5); return onevalue(V78); }

V75:
    V78 = nil;
    { popv(5); return onevalue(V78); }
/* error exit handlers */
V88:
    popv(5);
    return error(1, err_bad_cdr, V78);
V87:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|LO;=;2$B;4| (|x| |y| |$|)
   (BOOT:SPADCALL
      (BOOT:SPADCALL (QCDR |y|) (QCAR |x|) (VMLISP:QREFELT |$| 18))
      (BOOT:SPADCALL (QCDR |x|) (QCAR |y|) (VMLISP:QREFELT |$| 18))
      (VMLISP:QREFELT |$| 19)))

*/



/* Code for BOOT::|LO;=;2$B;4| */

static Lisp_Object MS_CDECL CC_BOOT__LOUMU2DBU4(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V91, V92, V93, V94;
    argcheck(nargs, 3, "LO;=;2$B;4");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|LO;=;2$B;4|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = V4;
    stack[-3] = V3;
    stack[-4] = V2;
/* end of prologue */
    V92 = stack[-2];
    V91 = (Lisp_Object)305; /* 19 */
    V91 = Lgetv(nil, V92, V91);
    nil = C_nil;
    if (exception_pending()) goto V101;
    env = stack[-6];
    stack[-5] = V91;
    V91 = stack[-5];
    if (!car_legal(V91)) goto V102;
    stack[-1] = qcar(V91);
    V92 = stack[-2];
    V91 = (Lisp_Object)289; /* 18 */
    V91 = Lgetv(nil, V92, V91);
    nil = C_nil;
    if (exception_pending()) goto V101;
    env = stack[-6];
    V92 = V91;
    if (!car_legal(V92)) goto V103;
    V94 = qcar(V92);
    V92 = stack[-3];
    V93 = qcdr(V92);
    V92 = stack[-4];
    V92 = qcar(V92);
    if (!car_legal(V91)) goto V104;
    V91 = qcdr(V91);
    V91 = Lapply3(nil, 4, V94, V93, V92, V91);
    nil = C_nil;
    if (exception_pending()) goto V101;
    env = stack[-6];
    stack[0] = V91;
    V92 = stack[-2];
    V91 = (Lisp_Object)289; /* 18 */
    V91 = Lgetv(nil, V92, V91);
    nil = C_nil;
    if (exception_pending()) goto V101;
    env = stack[-6];
    V92 = V91;
    if (!car_legal(V92)) goto V103;
    V94 = qcar(V92);
    V92 = stack[-4];
    V93 = qcdr(V92);
    V92 = stack[-3];
    V92 = qcar(V92);
    if (!car_legal(V91)) goto V104;
    V91 = qcdr(V91);
    V91 = Lapply3(nil, 4, V94, V93, V92, V91);
    nil = C_nil;
    if (exception_pending()) goto V101;
    V92 = V91;
    V91 = stack[-5];
    if (!car_legal(V91)) goto V104;
    V91 = qcdr(V91);
    {
        Lisp_Object V105 = stack[-1];
        Lisp_Object V106 = stack[0];
        popv(7);
        return Lapply3(nil, 4, V105, V106, V92, V91);
    }
/* error exit handlers */
V104:
    popv(7);
    return error(1, err_bad_cdr, V91);
V103:
    popv(7);
    return error(1, err_bad_car, V92);
V102:
    popv(7);
    return error(1, err_bad_car, V91);
V101:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|newLookupInDomain| (BOOT::|op|
      BOOT::|sig|
      BOOT::|addFormDomain|
      BOOT::|dollar|
      BOOT::|index|)
   (PROG (BOOT::|addFormCell|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADLET
                   BOOT::|addFormCell|
                   (ELT BOOT::|addFormDomain| BOOT::|index|))
                  (COND
                     ((INTEGERP (BOOT:KAR BOOT::|addFormCell|))
                        (PROG (#:G18873)
                           (BOOT:SPADLET #:G18873 NIL)
                           (RETURN
                              (DO ((#:G18874 NIL #:G18873)
                                    (#:G18875
                                       BOOT::|addFormCell|
                                       (CDR #:G18875))
                                    (|i| NIL))
                                 ((OR
                                     #:G18874
                                     (ATOM #:G18875)
                                     (PROGN (SETQ |i| (CAR #:G18875)) NIL))
                                    #:G18873)
                                 (SEQ
                                    (EXIT
                                       (SETQ #:G18873
                                          (OR
                                             #:G18873
                                             (BOOT::|newLookupInDomain|
                                                BOOT::|op|
                                                BOOT::|sig|
                                                BOOT::|addFormDomain|
                                                BOOT::|dollar|
                                                |i|)))) ))) ))
                     ('T
                        (COND
                           ((NULL (VMLISP:VECP BOOT::|addFormCell|))
                              (BOOT::|lazyDomainSet|
                                 BOOT::|addFormCell|
                                 BOOT::|addFormDomain|
                                 BOOT::|index|)))
                        (BOOT::|lookupInDomainVector|
                           BOOT::|op|
                           BOOT::|sig|
                           (ELT BOOT::|addFormDomain| BOOT::|index|)
                           BOOT::|dollar|))))
               ('T NIL)))) ))

*/



/* Code for BOOT::|newLookupInDomain| */

static Lisp_Object MS_CDECL CC_BOOT__newLookupInDomain(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5,
                         Lisp_Object V6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V151, V152, V153, V154, V155;
    Lisp_Object fn;
    argcheck(nargs, 5, "newLookupInDomain");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|newLookupInDomain|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V6);
        push(V5);
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        pop(V5);
        pop(V6);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[0] = V6;
    stack[-1] = V5;
    stack[-2] = V4;
    stack[-3] = V3;
    stack[-4] = V2;
/* end of prologue */
    V152 = stack[-2];
    V151 = stack[0];
    fn = elt(env, 1); /* ELT */
    V151 = (*qfn2(fn))(qenv(fn), V152, V151);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-6];
    stack[-5] = V151;
    if (V151 == nil) goto V18;
    V151 = stack[-5];
    if (!consp(V151)) goto V34;
    V151 = stack[-5];
    V151 = qcar(V151);
    goto V33;

V33:
    V151 = Lintegerp(nil, V151);
    env = stack[-6];
    if (V151 == nil) goto V30;
    V151 = nil;
    V152 = V151;
    V153 = stack[-5];
    V151 = nil;
    stack[0] = V153;
    V153 = V151;
    goto V54;

V54:
    V151 = V153;
    if (!(V151 == nil)) { popv(7); return onevalue(V152); }
    V151 = stack[0];
    if (!consp(V151)) { popv(7); return onevalue(V152); }
    V151 = stack[0];
    if (!car_legal(V151)) goto V163;
    V151 = qcar(V151);
    V153 = nil;
    if (!(V153 == nil)) { popv(7); return onevalue(V152); }
    if (!(V152 == nil)) goto V70;
    V155 = stack[-4];
    V154 = stack[-3];
    V153 = stack[-2];
    V152 = stack[-1];
    V151 = CC_BOOT__newLookupInDomain(env, 5, V155, V154, V153, V152, V151);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-6];
    V152 = V151;
    goto V70;

V70:
    V151 = V152;
    V153 = V151;
    V151 = stack[0];
    if (!car_legal(V151)) goto V164;
    V151 = qcdr(V151);
    stack[0] = V151;
    goto V54;

V30:
    V151 = lisp_true;
    if (V151 == nil) goto V106;
    V151 = stack[-5];
    fn = elt(env, 2); /* SIMPLE-VECTOR-P */
    V151 = (*qfn1(fn))(qenv(fn), V151);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-6];
    if (!(V151 == nil)) goto V138;
    V153 = stack[-5];
    V152 = stack[-2];
    V151 = stack[0];
    fn = elt(env, 3); /* BOOT::|lazyDomainSet| */
    V151 = (*qfnn(fn))(qenv(fn), 3, V153, V152, V151);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-6];
    goto V138;

V138:
    V152 = stack[-2];
    V151 = stack[0];
    fn = elt(env, 1); /* ELT */
    V152 = (*qfn2(fn))(qenv(fn), V152, V151);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-6];
    V151 = stack[-1];
    {
        Lisp_Object V165 = stack[-4];
        Lisp_Object V166 = stack[-3];
        popv(7);
        fn = elt(env, 4); /* BOOT::|lookupInDomainVector| */
        return (*qfnn(fn))(qenv(fn), 4, V165, V166, V152, V151);
    }

V106:
    V151 = nil;
    { popv(7); return onevalue(V151); }

V34:
    V151 = nil;
    goto V33;

V18:
    V151 = lisp_true;
    if (V151 == nil) goto V147;
    V151 = nil;
    { popv(7); return onevalue(V151); }

V147:
    V151 = nil;
    { popv(7); return onevalue(V151); }
/* error exit handlers */
V164:
    popv(7);
    return error(1, err_bad_cdr, V151);
V163:
    popv(7);
    return error(1, err_bad_car, V151);
V162:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|atom2String| (|x|)
   (COND
      ((VMLISP:IDENTP |x|) (SYSTEM::PNAME |x|))
      ((STRINGP |x|) |x|)
      ('T (BOOT::|stringer| |x|))))

*/



/* Code for BOOT::|atom2String| */

static Lisp_Object CC_BOOT__atom2String(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V32;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|atom2String|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = V2;
/* end of prologue */
    V32 = stack[0];
    if (V32 == nil) goto V12;
    V32 = stack[0];
    fn = elt(env, 1); /* SYMBOLP */
    V32 = (*qfn1(fn))(qenv(fn), V32);
    nil = C_nil;
    if (exception_pending()) goto V34;
    env = stack[-1];
    goto V11;

V11:
    if (V32 == nil) goto V9;
    V32 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); /* SYSTEM::PNAME */
        return (*qfn1(fn))(qenv(fn), V32);
    }

V9:
    V32 = stack[0];
    V32 = Lstringp(nil, V32);
    env = stack[-1];
    if (!(V32 == nil)) { Lisp_Object res = stack[0]; popv(2); return onevalue(res); }
    V32 = lisp_true;
    if (V32 == nil) goto V28;
    V32 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* BOOT::|stringer| */
        return (*qfn1(fn))(qenv(fn), V32);
    }

V28:
    V32 = nil;
    { popv(2); return onevalue(V32); }

V12:
    V32 = nil;
    goto V11;
/* error exit handlers */
V34:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|IARRAY1;elt;$IS;16| (|x| |i| |$|)
   (COND
      ((OR (VMLISP:QSLESSP |i| 1) (VMLISP:QSLESSP (VMLISP:QVSIZE |x|) |i|))
         (BOOT::|error| "index out of range"))
      ('T (ELT |x| (|-| |i| 1)))) )

*/



/* Code for BOOT::|IARRAY1;elt;$IS;16| */

static Lisp_Object MS_CDECL CC_BOOT__IARRAY1UeltUDISU16(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V45, V46;
    Lisp_Object fn;
    argcheck(nargs, 3, "IARRAY1;elt;$IS;16");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IARRAY1;elt;$IS;16|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    V45 = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V46 = stack[0];
    V45 = (Lisp_Object)17; /* 1 */
    V45 = (Lisp_Object)lessp2(V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V49;
    V45 = V45 ? lisp_true : nil;
    env = stack[-2];
    if (!(V45 == nil)) goto V10;
    V45 = stack[-1];
    V46 = Llength(nil, V45);
    nil = C_nil;
    if (exception_pending()) goto V49;
    env = stack[-2];
    V45 = stack[0];
    V45 = (Lisp_Object)lessp2(V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V49;
    V45 = V45 ? lisp_true : nil;
    env = stack[-2];
    if (!(V45 == nil)) goto V10;
    V45 = lisp_true;
    if (V45 == nil) goto V34;
    V45 = stack[0];
    V45 = sub1(V45);
    nil = C_nil;
    if (exception_pending()) goto V49;
    env = stack[-2];
    {
        Lisp_Object V50 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* ELT */
        return (*qfn2(fn))(qenv(fn), V50, V45);
    }

V34:
    V45 = nil;
    { popv(3); return onevalue(V45); }

V10:
    V45 = elt(env, 1); /* "index out of range" */
    {
        popv(3);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V45);
    }
/* error exit handlers */
V49:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|EXPR;+;3$;12| (|x| |y| |$|)
   (BOOT::|EXPR;reduc|
      (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 36))
      (BOOT::|EXPR;commonk| |x| |y| |$|)
      |$|))

*/



/* Code for BOOT::|EXPR;+;3$;12| */

static Lisp_Object MS_CDECL CC_BOOT__EXPRULU3DU12(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V55, V56, V57, V58;
    Lisp_Object fn;
    argcheck(nargs, 3, "EXPR;+;3$;12");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;+;3$;12|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = V4;
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    V56 = stack[0];
    V55 = (Lisp_Object)577; /* 36 */
    V55 = Lgetv(nil, V56, V55);
    nil = C_nil;
    if (exception_pending()) goto V63;
    env = stack[-4];
    V56 = V55;
    if (!car_legal(V56)) goto V64;
    V58 = qcar(V56);
    V57 = stack[-2];
    V56 = stack[-1];
    if (!car_legal(V55)) goto V65;
    V55 = qcdr(V55);
    V55 = Lapply3(nil, 4, V58, V57, V56, V55);
    nil = C_nil;
    if (exception_pending()) goto V63;
    env = stack[-4];
    stack[-3] = V55;
    V57 = stack[-2];
    V56 = stack[-1];
    V55 = stack[0];
    fn = elt(env, 1); /* BOOT::|EXPR;commonk| */
    V56 = (*qfnn(fn))(qenv(fn), 3, V57, V56, V55);
    nil = C_nil;
    if (exception_pending()) goto V63;
    env = stack[-4];
    V55 = stack[0];
    {
        Lisp_Object V66 = stack[-3];
        popv(5);
        fn = elt(env, 2); /* BOOT::|EXPR;reduc| */
        return (*qfnn(fn))(qenv(fn), 3, V66, V56, V55);
    }
/* error exit handlers */
V65:
    popv(5);
    return error(1, err_bad_cdr, V55);
V64:
    popv(5);
    return error(1, err_bad_car, V56);
V63:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|COMPCAT-;rem;3S;53| (|x| |y| |$|)
   (PROG (BOOT::|yr|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL
                   (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 92))
                   (VMLISP:QREFELT |$| 82))
                  (SEQ
                     (BOOT::LETT
                        BOOT::|yr|
                        (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 24))
                        BOOT::|COMPCAT-;rem;3S;53|)
                     (EXIT
                        (BOOT:SPADCALL
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 24))
                              BOOT::|yr|
                              (VMLISP:QREFELT |$| 219))
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 92))
                              BOOT::|yr|
                              (VMLISP:QREFELT |$| 219))
                           (VMLISP:QREFELT |$| 30)))) )
               ('T
                  (QCDR
                     (BOOT:SPADCALL
                        |x|
                        |y|
                        (VMLISP:QREFELT |$| 220)))) ))) ))

*/



/* Code for BOOT::|COMPCAT-;rem;3S;53| */

static Lisp_Object MS_CDECL CC_BOOT__COMPCATKUremU3SU53(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V248, V249, V250, V251;
    argcheck(nargs, 3, "COMPCAT-;rem;3S;53");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPCAT-;rem;3S;53|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = V4;
    stack[-1] = V3;
    stack[-6] = V2;
/* end of prologue */
    V249 = stack[-5];
    V248 = (Lisp_Object)1313; /* 82 */
    V248 = Lgetv(nil, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    stack[-2] = V248;
    V248 = stack[-2];
    if (!car_legal(V248)) goto V261;
    stack[0] = qcar(V248);
    V249 = stack[-5];
    V248 = (Lisp_Object)1473; /* 92 */
    V248 = Lgetv(nil, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    V249 = V248;
    if (!car_legal(V249)) goto V262;
    V250 = qcar(V249);
    V249 = stack[-1];
    if (!car_legal(V248)) goto V263;
    V248 = qcdr(V248);
    V248 = Lapply2(nil, 3, V250, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    V249 = V248;
    V248 = stack[-2];
    if (!car_legal(V248)) goto V263;
    V248 = qcdr(V248);
    V248 = Lapply2(nil, 3, stack[0], V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    if (V248 == nil) goto V16;
    V249 = stack[-5];
    V248 = (Lisp_Object)385; /* 24 */
    V248 = Lgetv(nil, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    V249 = V248;
    if (!car_legal(V249)) goto V262;
    V250 = qcar(V249);
    V249 = stack[-1];
    if (!car_legal(V248)) goto V263;
    V248 = qcdr(V248);
    V248 = Lapply2(nil, 3, V250, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    stack[-7] = V248;
    V249 = stack[-5];
    V248 = (Lisp_Object)481; /* 30 */
    V248 = Lgetv(nil, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    stack[-4] = V248;
    V248 = stack[-4];
    if (!car_legal(V248)) goto V261;
    stack[-3] = qcar(V248);
    V249 = stack[-5];
    V248 = (Lisp_Object)3505; /* 219 */
    V248 = Lgetv(nil, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    stack[-1] = V248;
    V248 = stack[-1];
    if (!car_legal(V248)) goto V261;
    stack[0] = qcar(V248);
    V249 = stack[-5];
    V248 = (Lisp_Object)385; /* 24 */
    V248 = Lgetv(nil, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    V249 = V248;
    if (!car_legal(V249)) goto V262;
    V250 = qcar(V249);
    V249 = stack[-6];
    if (!car_legal(V248)) goto V263;
    V248 = qcdr(V248);
    V248 = Lapply2(nil, 3, V250, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    V250 = V248;
    V249 = stack[-7];
    V248 = stack[-1];
    if (!car_legal(V248)) goto V263;
    V248 = qcdr(V248);
    V248 = Lapply3(nil, 4, stack[0], V250, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    stack[-2] = V248;
    V249 = stack[-5];
    V248 = (Lisp_Object)3505; /* 219 */
    V248 = Lgetv(nil, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    stack[-1] = V248;
    V248 = stack[-1];
    if (!car_legal(V248)) goto V261;
    stack[0] = qcar(V248);
    V249 = stack[-5];
    V248 = (Lisp_Object)1473; /* 92 */
    V248 = Lgetv(nil, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    V249 = V248;
    if (!car_legal(V249)) goto V262;
    V250 = qcar(V249);
    V249 = stack[-6];
    if (!car_legal(V248)) goto V263;
    V248 = qcdr(V248);
    V248 = Lapply2(nil, 3, V250, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    V250 = V248;
    V249 = stack[-7];
    V248 = stack[-1];
    if (!car_legal(V248)) goto V263;
    V248 = qcdr(V248);
    V248 = Lapply3(nil, 4, stack[0], V250, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    V249 = V248;
    V248 = stack[-4];
    if (!car_legal(V248)) goto V263;
    V248 = qcdr(V248);
    {
        Lisp_Object V264 = stack[-3];
        Lisp_Object V265 = stack[-2];
        popv(9);
        return Lapply3(nil, 4, V264, V265, V249, V248);
    }

V16:
    V248 = lisp_true;
    if (V248 == nil) goto V217;
    V249 = stack[-5];
    V248 = (Lisp_Object)3521; /* 220 */
    V248 = Lgetv(nil, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-8];
    V249 = V248;
    if (!car_legal(V249)) goto V262;
    V251 = qcar(V249);
    V250 = stack[-6];
    V249 = stack[-1];
    if (!car_legal(V248)) goto V263;
    V248 = qcdr(V248);
    V248 = Lapply3(nil, 4, V251, V250, V249, V248);
    nil = C_nil;
    if (exception_pending()) goto V260;
    V248 = qcdr(V248);
    { popv(9); return onevalue(V248); }

V217:
    V248 = nil;
    { popv(9); return onevalue(V248); }
/* error exit handlers */
V263:
    popv(9);
    return error(1, err_bad_cdr, V248);
V262:
    popv(9);
    return error(1, err_bad_car, V249);
V261:
    popv(9);
    return error(1, err_bad_car, V248);
V260:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|FIELD-;/;3S;11| (|x| |y| |$|)
   (COND
      ((BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 8))
         (BOOT::|error| "catdef: division by zero"))
      ('T
         (BOOT:SPADCALL
            |x|
            (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 11))
            (VMLISP:QREFELT |$| 31)))) )

*/



/* Code for BOOT::|FIELD-;/;3S;11| */

static Lisp_Object MS_CDECL CC_BOOT__FIELDKUVU3SU11(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V91, V92, V93;
    Lisp_Object fn;
    argcheck(nargs, 3, "FIELD-;/;3S;11");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FIELD-;/;3S;11|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = V4;
    stack[-2] = V3;
    stack[-3] = V2;
/* end of prologue */
    V92 = stack[-1];
    V91 = (Lisp_Object)129; /* 8 */
    V91 = Lgetv(nil, V92, V91);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    V92 = V91;
    if (!car_legal(V92)) goto V100;
    V93 = qcar(V92);
    V92 = stack[-2];
    if (!car_legal(V91)) goto V101;
    V91 = qcdr(V91);
    V91 = Lapply2(nil, 3, V93, V92, V91);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    if (V91 == nil) goto V11;
    V91 = elt(env, 1); /* "catdef: division by zero" */
    {
        popv(6);
        fn = elt(env, 2); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V91);
    }

V11:
    V91 = lisp_true;
    if (V91 == nil) goto V39;
    V92 = stack[-1];
    V91 = (Lisp_Object)497; /* 31 */
    V91 = Lgetv(nil, V92, V91);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    stack[-4] = V91;
    V91 = stack[-4];
    if (!car_legal(V91)) goto V102;
    stack[0] = qcar(V91);
    V92 = stack[-1];
    V91 = (Lisp_Object)177; /* 11 */
    V91 = Lgetv(nil, V92, V91);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    V92 = V91;
    if (!car_legal(V92)) goto V100;
    V93 = qcar(V92);
    V92 = stack[-2];
    if (!car_legal(V91)) goto V101;
    V91 = qcdr(V91);
    V91 = Lapply2(nil, 3, V93, V92, V91);
    nil = C_nil;
    if (exception_pending()) goto V99;
    V92 = V91;
    V91 = stack[-4];
    if (!car_legal(V91)) goto V101;
    V91 = qcdr(V91);
    {
        Lisp_Object V103 = stack[0];
        Lisp_Object V104 = stack[-3];
        popv(6);
        return Lapply3(nil, 4, V103, V104, V92, V91);
    }

V39:
    V91 = nil;
    { popv(6); return onevalue(V91); }
/* error exit handlers */
V102:
    popv(6);
    return error(1, err_bad_car, V91);
V101:
    popv(6);
    return error(1, err_bad_cdr, V91);
V100:
    popv(6);
    return error(1, err_bad_car, V92);
V99:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|SMP;univariate;$VarSetSup;13| (|p| BOOT::|mvar| |$|)
   (PROG (BOOT::|pt|)
      (RETURN
         (SEQ
            (COND
               ((OR
                   (BOOT::QEQCAR |p| 0)
                   (BOOT:SPADCALL
                      (QCAR (QCDR |p|))
                      BOOT::|mvar|
                      (VMLISP:QREFELT |$| 50)))
                  (BOOT:SPADCALL |p| 0 (VMLISP:QREFELT |$| 27)))
               ('T
                  (SEQ
                     (BOOT::LETT
                        BOOT::|pt|
                        (QCDR (QCDR |p|))
                        BOOT::|SMP;univariate;$VarSetSup;13|)
                     (EXIT
                        (COND
                           ((BOOT:SPADCALL
                               BOOT::|mvar|
                               (QCAR (QCDR |p|))
                               (VMLISP:QREFELT |$| 51))
                              BOOT::|pt|)
                           ('T
                              (BOOT:SPADCALL
                                 (BOOT:SPADCALL
                                    (BOOT:SPADCALL
                                       (BOOT::|spadConstant| |$| 14)
                                       (QCAR (QCDR |p|))
                                       (BOOT:SPADCALL
                                          BOOT::|pt|
                                          (VMLISP:QREFELT |$| 40))
                                       (VMLISP:QREFELT |$| 52))
                                    (BOOT:SPADCALL
                                       (BOOT:SPADCALL
                                          BOOT::|pt|
                                          (VMLISP:QREFELT |$| 22))
                                       BOOT::|mvar|
                                       (VMLISP:QREFELT |$| 54))
                                    (VMLISP:QREFELT |$| 55))
                                 (BOOT:SPADCALL
                                    (BOOT::|SMP;red| |p| |$|)
                                    BOOT::|mvar|
                                    (VMLISP:QREFELT |$| 54))
                                 (VMLISP:QREFELT |$| 56)))) ))) ))) ))

*/



/* Code for BOOT::|SMP;univariate;$VarSetSup;13| */

static Lisp_Object MS_CDECL CC_BOOT__SMPUunivariateUDVarSetSupU13(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V340, V341, V342, V343;
    Lisp_Object fn;
    argcheck(nargs, 3, "SMP;univariate;$VarSetSup;13");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;univariate;$VarSetSup;13|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-8] = V4;
    stack[-9] = V3;
    stack[-10] = V2;
/* end of prologue */
    V340 = stack[-10];
    V341 = qcar(V340);
    V340 = (Lisp_Object)1; /* 0 */
    V340 = Leql(nil, V341, V340);
    env = stack[-12];
    if (!(V340 == nil)) goto V61;
    V341 = stack[-8];
    V340 = (Lisp_Object)801; /* 50 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    V341 = V340;
    if (!car_legal(V341)) goto V357;
    V343 = qcar(V341);
    V341 = stack[-10];
    V341 = qcdr(V341);
    V342 = qcar(V341);
    V341 = stack[-9];
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
    V340 = Lapply3(nil, 4, V343, V342, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    if (!(V340 == nil)) goto V61;
    V340 = lisp_true;
    if (V340 == nil) goto V85;
    V340 = stack[-10];
    V340 = qcdr(V340);
    V340 = qcdr(V340);
    stack[-11] = V340;
    V341 = stack[-8];
    V340 = (Lisp_Object)817; /* 51 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    V341 = V340;
    if (!car_legal(V341)) goto V357;
    V343 = qcar(V341);
    V342 = stack[-9];
    V341 = stack[-10];
    V341 = qcdr(V341);
    V341 = qcar(V341);
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
    V340 = Lapply3(nil, 4, V343, V342, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    if (!(V340 == nil)) { Lisp_Object res = stack[-11]; popv(13); return onevalue(res); }
    V340 = lisp_true;
    if (V340 == nil) goto V127;
    V341 = stack[-8];
    V340 = (Lisp_Object)897; /* 56 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    stack[-7] = V340;
    V340 = stack[-7];
    if (!car_legal(V340)) goto V359;
    stack[-6] = qcar(V340);
    V341 = stack[-8];
    V340 = (Lisp_Object)881; /* 55 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    stack[-5] = V340;
    V340 = stack[-5];
    if (!car_legal(V340)) goto V359;
    stack[-4] = qcar(V340);
    V341 = stack[-8];
    V340 = (Lisp_Object)833; /* 52 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    stack[-3] = V340;
    V340 = stack[-3];
    if (!car_legal(V340)) goto V359;
    stack[-2] = qcar(V340);
    V341 = stack[-8];
    V340 = (Lisp_Object)225; /* 14 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    V341 = V340;
    if (!car_legal(V341)) goto V357;
    V341 = qcar(V341);
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
    V340 = Lapply1(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    stack[-1] = V340;
    V340 = stack[-10];
    V340 = qcdr(V340);
    stack[0] = qcar(V340);
    V341 = stack[-8];
    V340 = (Lisp_Object)641; /* 40 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    V341 = V340;
    if (!car_legal(V341)) goto V357;
    V342 = qcar(V341);
    V341 = stack[-11];
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
    V340 = Lapply2(nil, 3, V342, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    V341 = V340;
    V340 = stack[-3];
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
    fn = elt(env, 1); /* FUNCALL* */
    V340 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    stack[-2] = V340;
    V341 = stack[-8];
    V340 = (Lisp_Object)865; /* 54 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    stack[-1] = V340;
    V340 = stack[-1];
    if (!car_legal(V340)) goto V359;
    stack[0] = qcar(V340);
    V341 = stack[-8];
    V340 = (Lisp_Object)353; /* 22 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    V341 = V340;
    if (!car_legal(V341)) goto V357;
    V342 = qcar(V341);
    V341 = stack[-11];
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
    V340 = Lapply2(nil, 3, V342, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    V342 = V340;
    V341 = stack[-9];
    V340 = stack[-1];
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
    V340 = Lapply3(nil, 4, stack[0], V342, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    V341 = V340;
    V340 = stack[-5];
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
    V340 = Lapply3(nil, 4, stack[-4], stack[-2], V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    stack[-2] = V340;
    V341 = stack[-8];
    V340 = (Lisp_Object)865; /* 54 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    stack[-1] = V340;
    V340 = stack[-1];
    if (!car_legal(V340)) goto V359;
    stack[0] = qcar(V340);
    V341 = stack[-10];
    V340 = stack[-8];
    fn = elt(env, 2); /* BOOT::|SMP;red| */
    V342 = (*qfn2(fn))(qenv(fn), V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    env = stack[-12];
    V341 = stack[-9];
    V340 = stack[-1];
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
    V340 = Lapply3(nil, 4, stack[0], V342, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    V341 = V340;
    V340 = stack[-7];
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
    {
        Lisp_Object V360 = stack[-6];
        Lisp_Object V361 = stack[-2];
        popv(13);
        return Lapply3(nil, 4, V360, V361, V341, V340);
    }

V127:
    V340 = nil;
    { popv(13); return onevalue(V340); }

V85:
    V340 = nil;
    { popv(13); return onevalue(V340); }

V61:
    V341 = stack[-8];
    V340 = (Lisp_Object)433; /* 27 */
    V340 = Lgetv(nil, V341, V340);
    nil = C_nil;
    if (exception_pending()) goto V356;
    V341 = V340;
    if (!car_legal(V341)) goto V357;
    V343 = qcar(V341);
    V342 = stack[-10];
    V341 = (Lisp_Object)1; /* 0 */
    if (!car_legal(V340)) goto V358;
    V340 = qcdr(V340);
        popv(13);
        return Lapply3(nil, 4, V343, V342, V341, V340);
/* error exit handlers */
V359:
    popv(13);
    return error(1, err_bad_car, V340);
V358:
    popv(13);
    return error(1, err_bad_cdr, V340);
V357:
    popv(13);
    return error(1, err_bad_car, V341);
V356:
    popv(13);
    return nil;
}

/*
(DEFUN BOOT::|hasCate| (BOOT::|dom| BOOT::|cat| BOOT::SL)
   (PROG (BOOT::NSL |p| S |v| |d| BOOT::SL1)
      (RETURN
         (SEQ
            (COND
               ((BOOT:|BOOT-EQUAL| BOOT::|dom| BOOT:|$EmptyMode|) NIL)
               ((BOOT::|isPatternVar| BOOT::|dom|)
                  (COND
                     ((AND
                         (BOOT:SPADLET
                            |p|
                            (VMLISP:ASSQ BOOT::|dom| BOOT::SL))
                         (BOOT:NEQUAL
                            (BOOT:SPADLET
                               BOOT::NSL
                               (BOOT::|hasCate|
                                  (CDR |p|)
                                  BOOT::|cat|
                                  BOOT::SL))
                            'BOOT::|failed|))
                        BOOT::NSL)
                     ((OR
                         (BOOT:SPADLET
                            |p|
                            (VMLISP:ASSQ BOOT::|dom| BOOT::|$Subst|))
                         (BOOT:SPADLET
                            |p|
                            (VMLISP:ASSQ BOOT::|dom| BOOT::SL)))
                        (BOOT:SPADLET
                           S
                           (BOOT::|hasCate1|
                              (CDR |p|)
                              BOOT::|cat|
                              BOOT::SL
                              BOOT::|dom|))
                        (COND
                           ((NULL (BOOT:|BOOT-EQUAL| S 'BOOT::|failed|)) S)
                           ('T
                              (BOOT::|hasCateSpecial|
                                 BOOT::|dom|
                                 (CDR |p|)
                                 BOOT::|cat|
                                 BOOT::SL))))
                     ('T
                        (COND
                           ((BOOT:NEQUAL BOOT::SL 'BOOT::|failed|)
                              (BOOT:SPADLET BOOT::|$hope| 'T)))
                        'BOOT::|failed|)))
               ('T
                  (BOOT:SPADLET
                     BOOT::SL1
                     (PROG (#:G19008)
                        (BOOT:SPADLET #:G19008 NIL)
                        (RETURN
                           (DO ((#:G19009 BOOT::SL (CDR #:G19009))
                                 (#:G19007 NIL))
                              ((OR
                                  (ATOM #:G19009)
                                  (PROGN
                                     (SETQ #:G19007 (CAR #:G19009))
                                     NIL)
                                  (PROGN
                                     (PROGN
                                        (BOOT:SPADLET |v| (CAR #:G19007))
                                        (BOOT:SPADLET |d| (CDR #:G19007))
                                        #:G19007)
                                     NIL))
                                 (NREVERSE0 #:G19008))
                              (SEQ
                                 (EXIT
                                    (COND
                                       ((NULL
                                           (BOOT::|containsVariables| |d|))
                                          (SETQ #:G19008
                                             (CONS
                                                (CONS |v| |d|)
                                                #:G19008)))) ))) )))
                  (COND
                     (BOOT::SL1
                        (BOOT:SPADLET
                           BOOT::|cat|
                           (BOOT::|subCopy| BOOT::|cat| BOOT::SL1))))
                  (BOOT::|hasCaty| BOOT::|dom| BOOT::|cat| BOOT::SL)))) )))

*/



/* Code for BOOT::|hasCate| */

static Lisp_Object MS_CDECL CC_BOOT__hasCate(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V240, V241, V242, V243;
    Lisp_Object fn;
    argcheck(nargs, 3, "hasCate");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|hasCate|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-3] = V4;
    stack[-4] = V3;
    stack[-5] = V2;
/* end of prologue */
    V241 = stack[-5];
    V240 = qvalue(elt(env, 1)); /* BOOT::|$EmptyMode| */
    V240 = (cl_equal(V241, V240) ? lisp_true : nil);
    if (V240 == nil) goto V21;
    V240 = nil;
    { popv(8); return onevalue(V240); }

V21:
    V240 = stack[-5];
    fn = elt(env, 5); /* BOOT::|isPatternVar| */
    V240 = (*qfn1(fn))(qenv(fn), V240);
    nil = C_nil;
    if (exception_pending()) goto V251;
    env = stack[-7];
    if (V240 == nil) goto V32;
    V241 = stack[-5];
    V240 = stack[-3];
    V240 = Latsoc(nil, V241, V240);
    stack[0] = V240;
    if (V240 == nil) goto V73;
    V240 = stack[0];
    if (!car_legal(V240)) goto V252;
    V242 = qcdr(V240);
    V241 = stack[-4];
    V240 = stack[-3];
    V241 = CC_BOOT__hasCate(env, 3, V242, V241, V240);
    nil = C_nil;
    if (exception_pending()) goto V251;
    env = stack[-7];
    V242 = V241;
    V240 = elt(env, 2); /* BOOT::|failed| */
    V240 = (V241 == V240 ? lisp_true : nil);
    V240 = (V240 == nil ? lisp_true : nil);
    if (!(V240 == nil)) { popv(8); return onevalue(V242); }

V73:
    V241 = stack[-5];
    V240 = qvalue(elt(env, 3)); /* BOOT::|$Subst| */
    V240 = Latsoc(nil, V241, V240);
    stack[0] = V240;
    if (!(V240 == nil)) goto V91;
    V241 = stack[-5];
    V240 = stack[-3];
    V240 = Latsoc(nil, V241, V240);
    stack[0] = V240;
    if (!(V240 == nil)) goto V91;
    V240 = lisp_true;
    if (V240 == nil) goto V137;
    V241 = stack[-3];
    V240 = elt(env, 2); /* BOOT::|failed| */
    V240 = (V241 == V240 ? lisp_true : nil);
    V240 = (V240 == nil ? lisp_true : nil);
    if (V240 == nil) goto V140;
    V240 = lisp_true;
    qvalue(elt(env, 4)) = V240; /* BOOT::|$hope| */
    goto V140;

V140:
    V240 = elt(env, 2); /* BOOT::|failed| */
    { popv(8); return onevalue(V240); }

V137:
    V240 = nil;
    { popv(8); return onevalue(V240); }

V91:
    V240 = stack[0];
    if (!car_legal(V240)) goto V252;
    V243 = qcdr(V240);
    V242 = stack[-4];
    V241 = stack[-3];
    V240 = stack[-5];
    fn = elt(env, 6); /* BOOT::|hasCate1| */
    V240 = (*qfnn(fn))(qenv(fn), 4, V243, V242, V241, V240);
    nil = C_nil;
    if (exception_pending()) goto V251;
    env = stack[-7];
    V242 = V240;
    V241 = V242;
    V240 = elt(env, 2); /* BOOT::|failed| */
    V240 = (V241 == V240 ? lisp_true : nil);
    if (V240 == nil) { popv(8); return onevalue(V242); }
    V240 = lisp_true;
    if (V240 == nil) goto V119;
    V243 = stack[-5];
    V240 = stack[0];
    if (!car_legal(V240)) goto V252;
    V242 = qcdr(V240);
    V241 = stack[-4];
    V240 = stack[-3];
    {
        popv(8);
        fn = elt(env, 7); /* BOOT::|hasCateSpecial| */
        return (*qfnn(fn))(qenv(fn), 4, V243, V242, V241, V240);
    }

V119:
    V240 = nil;
    { popv(8); return onevalue(V240); }

V32:
    V240 = lisp_true;
    if (V240 == nil) goto V155;
    V240 = nil;
    stack[-1] = V240;
    V240 = stack[-3];
    stack[0] = V240;
    goto V167;

V167:
    V240 = stack[0];
    if (!consp(V240)) goto V170;
    V240 = stack[0];
    if (!car_legal(V240)) goto V253;
    V240 = qcar(V240);
    V241 = V240;
    V240 = nil;
    if (!(V240 == nil)) goto V170;
    V240 = V241;
    if (!car_legal(V240)) goto V253;
    V240 = qcar(V240);
    stack[-6] = V240;
    V240 = V241;
    if (!car_legal(V240)) goto V252;
    V240 = qcdr(V240);
    stack[-2] = V240;
    V240 = nil;
    if (!(V240 == nil)) goto V170;
    V240 = stack[-2];
    fn = elt(env, 8); /* BOOT::|containsVariables| */
    V240 = (*qfn1(fn))(qenv(fn), V240);
    nil = C_nil;
    if (exception_pending()) goto V251;
    env = stack[-7];
    if (!(V240 == nil)) goto V189;
    V242 = stack[-6];
    V241 = stack[-2];
    V240 = stack[-1];
    V240 = acons(V242, V241, V240);
    nil = C_nil;
    if (exception_pending()) goto V251;
    env = stack[-7];
    stack[-1] = V240;
    goto V189;

V189:
    V240 = stack[0];
    if (!car_legal(V240)) goto V252;
    V240 = qcdr(V240);
    stack[0] = V240;
    goto V167;

V170:
    V240 = stack[-1];
    fn = elt(env, 9); /* NREVERSE0 */
    V240 = (*qfn1(fn))(qenv(fn), V240);
    nil = C_nil;
    if (exception_pending()) goto V251;
    env = stack[-7];
    V241 = V240;
    if (V241 == nil) goto V229;
    V241 = stack[-4];
    fn = elt(env, 10); /* BOOT::|subCopy| */
    V240 = (*qfn2(fn))(qenv(fn), V241, V240);
    nil = C_nil;
    if (exception_pending()) goto V251;
    env = stack[-7];
    stack[-4] = V240;
    goto V229;

V229:
    V242 = stack[-5];
    V241 = stack[-4];
    V240 = stack[-3];
    {
        popv(8);
        fn = elt(env, 11); /* BOOT::|hasCaty| */
        return (*qfnn(fn))(qenv(fn), 3, V242, V241, V240);
    }

V155:
    V240 = nil;
    { popv(8); return onevalue(V240); }
/* error exit handlers */
V253:
    popv(8);
    return error(1, err_bad_car, V240);
V252:
    popv(8);
    return error(1, err_bad_cdr, V240);
V251:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|URAGG-;tail;2A;16| (|x| |$|)
   (PROG (|k| |y|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 20))
                  (BOOT::|error| "empty list"))
               ('T
                  (SEQ
                     (BOOT::LETT
                        |y|
                        (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 14))
                        BOOT::|URAGG-;tail;2A;16|)
                     (SEQ
                        (BOOT::LETT |k| 0 BOOT::|URAGG-;tail;2A;16|)
                        BOOT::G190
                        (COND
                           ((NULL
                               (COND
                                  ((BOOT:SPADCALL
                                      |y|
                                      (VMLISP:QREFELT |$| 20))
                                     'NIL)
                                  ('T 'T)))
                              (GO BOOT::G191)))
                        (SEQ
                           (COND
                              ((EQL |k| 1000)
                                 (COND
                                    ((BOOT:SPADCALL
                                        |x|
                                        (VMLISP:QREFELT |$| 33))
                                       (EXIT
                                          (BOOT::|error|
                                             "cyclic list")))) ))
                           (EXIT
                              (BOOT::LETT
                                 |y|
                                 (BOOT:SPADCALL
                                    (BOOT::LETT
                                       |x|
                                       |y|
                                       BOOT::|URAGG-;tail;2A;16|)
                                    (VMLISP:QREFELT |$| 14))
                                 BOOT::|URAGG-;tail;2A;16|)))
                        (BOOT::LETT
                           |k|
                           (VMLISP:QSADD1 |k|)
                           BOOT::|URAGG-;tail;2A;16|)
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT NIL))
                     (EXIT |x|)))) ))) )

*/



/* Code for BOOT::|URAGG-;tail;2A;16| */

static Lisp_Object CC_BOOT__URAGGKUtailU2AU16(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V190, V191, V192;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|URAGG-;tail;2A;16|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    V191 = stack[-1];
    V190 = (Lisp_Object)321; /* 20 */
    V190 = Lgetv(nil, V191, V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    V191 = V190;
    if (!car_legal(V191)) goto V198;
    V192 = qcar(V191);
    V191 = stack[-2];
    if (!car_legal(V190)) goto V199;
    V190 = qcdr(V190);
    V190 = Lapply2(nil, 3, V192, V191, V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    if (V190 == nil) goto V16;
    V190 = elt(env, 1); /* "empty list" */
    {
        popv(5);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V190);
    }

V16:
    V190 = lisp_true;
    if (V190 == nil) goto V44;
    V191 = stack[-1];
    V190 = (Lisp_Object)225; /* 14 */
    V190 = Lgetv(nil, V191, V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    V191 = V190;
    if (!car_legal(V191)) goto V198;
    V192 = qcar(V191);
    V191 = stack[-2];
    if (!car_legal(V190)) goto V199;
    V190 = qcdr(V190);
    V190 = Lapply2(nil, 3, V192, V191, V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    stack[0] = V190;
    V190 = (Lisp_Object)1; /* 0 */
    stack[-3] = V190;
    goto V89;

V89:
    V191 = stack[-1];
    V190 = (Lisp_Object)321; /* 20 */
    V190 = Lgetv(nil, V191, V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    V191 = V190;
    if (!car_legal(V191)) goto V198;
    V192 = qcar(V191);
    V191 = stack[0];
    if (!car_legal(V190)) goto V199;
    V190 = qcdr(V190);
    V190 = Lapply2(nil, 3, V192, V191, V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    if (V190 == nil) goto V84;
    V190 = nil;
    goto V82;

V82:
    if (V190 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    V191 = stack[-3];
    V190 = (Lisp_Object)16001; /* 1000 */
    V190 = Leql(nil, V191, V190);
    env = stack[-4];
    if (V190 == nil) goto V162;
    V191 = stack[-1];
    V190 = (Lisp_Object)529; /* 33 */
    V190 = Lgetv(nil, V191, V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    V191 = V190;
    if (!car_legal(V191)) goto V198;
    V192 = qcar(V191);
    V191 = stack[-2];
    if (!car_legal(V190)) goto V199;
    V190 = qcdr(V190);
    V190 = Lapply2(nil, 3, V192, V191, V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    if (V190 == nil) goto V162;
    V190 = elt(env, 2); /* "cyclic list" */
    fn = elt(env, 3); /* BOOT::|error| */
    V190 = (*qfn1(fn))(qenv(fn), V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    goto V115;

V115:
    V190 = stack[-3];
    V190 = add1(V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    stack[-3] = V190;
    goto V89;

V162:
    V191 = stack[-1];
    V190 = (Lisp_Object)225; /* 14 */
    V190 = Lgetv(nil, V191, V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    V191 = V190;
    if (!car_legal(V191)) goto V198;
    V192 = qcar(V191);
    V191 = stack[0];
    stack[-2] = V191;
    if (!car_legal(V190)) goto V199;
    V190 = qcdr(V190);
    V190 = Lapply2(nil, 3, V192, V191, V190);
    nil = C_nil;
    if (exception_pending()) goto V197;
    env = stack[-4];
    stack[0] = V190;
    goto V115;

V84:
    V190 = lisp_true;
    if (V190 == nil) goto V111;
    V190 = lisp_true;
    goto V82;

V111:
    V190 = nil;
    goto V82;

V44:
    V190 = nil;
    { popv(5); return onevalue(V190); }
/* error exit handlers */
V199:
    popv(5);
    return error(1, err_bad_cdr, V190);
V198:
    popv(5);
    return error(1, err_bad_car, V191);
V197:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|npInfGeneric| (|s|)
   (PROG NIL
      (RETURN
         (AND
            (BOOT::|npDDInfKey| |s|)
            (OR (BOOT::|npEqKey| 'BOOT::BACKSET) T)))) )

*/



/* Code for BOOT::|npInfGeneric| */

static Lisp_Object CC_BOOT__npInfGeneric(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V23;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|npInfGeneric|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    V23 = V2;
/* end of prologue */
    fn = elt(env, 2); /* BOOT::|npDDInfKey| */
    V23 = (*qfn1(fn))(qenv(fn), V23);
    nil = C_nil;
    if (exception_pending()) goto V24;
    env = stack[0];
    if (V23 == nil) goto V10;
    V23 = elt(env, 1); /* BOOT::BACKSET */
    fn = elt(env, 3); /* BOOT::|npEqKey| */
    V23 = (*qfn1(fn))(qenv(fn), V23);
    nil = C_nil;
    if (exception_pending()) goto V24;
    if (!(V23 == nil)) { popv(1); return onevalue(V23); }
    V23 = lisp_true;
    { popv(1); return onevalue(V23); }

V10:
    V23 = nil;
    { popv(1); return onevalue(V23); }
/* error exit handlers */
V24:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|FACUTIL;lowerPolynomial;SupSup;1| (|f| |$|)
   (COND
      ((BOOT:SPADCALL |f| (VMLISP:QREFELT |$| 12))
         (BOOT::|spadConstant| |$| 14))
      ('T
         (BOOT:SPADCALL
            (BOOT:SPADCALL
               (BOOT:SPADCALL
                  (BOOT:SPADCALL |f| (VMLISP:QREFELT |$| 15))
                  (VMLISP:QREFELT |$| 16))
               (BOOT:SPADCALL |f| (VMLISP:QREFELT |$| 18))
               (VMLISP:QREFELT |$| 19))
            (BOOT:SPADCALL
               (BOOT:SPADCALL |f| (VMLISP:QREFELT |$| 20))
               (VMLISP:QREFELT |$| 21))
            (VMLISP:QREFELT |$| 22)))) )

*/



/* Code for BOOT::|FACUTIL;lowerPolynomial;SupSup;1| */

static Lisp_Object CC_BOOT__FACUTILUlowerPolynomialUSupSupU1(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V227, V228, V229;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FACUTIL;lowerPolynomial;SupSup;1|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = V3;
    stack[-6] = V2;
/* end of prologue */
    V228 = stack[-5];
    V227 = (Lisp_Object)193; /* 12 */
    V227 = Lgetv(nil, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    V228 = V227;
    if (!car_legal(V228)) goto V239;
    V229 = qcar(V228);
    V228 = stack[-6];
    if (!car_legal(V227)) goto V240;
    V227 = qcdr(V227);
    V227 = Lapply2(nil, 3, V229, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    if (V227 == nil) goto V10;
    V228 = stack[-5];
    V227 = (Lisp_Object)225; /* 14 */
    V227 = Lgetv(nil, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    V228 = V227;
    if (!car_legal(V228)) goto V239;
    V228 = qcar(V228);
    if (!car_legal(V227)) goto V240;
    V227 = qcdr(V227);
        popv(9);
        return Lapply1(nil, V228, V227);

V10:
    V227 = lisp_true;
    if (V227 == nil) goto V57;
    V228 = stack[-5];
    V227 = (Lisp_Object)353; /* 22 */
    V227 = Lgetv(nil, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    stack[-7] = V227;
    V227 = stack[-7];
    if (!car_legal(V227)) goto V241;
    stack[-4] = qcar(V227);
    V228 = stack[-5];
    V227 = (Lisp_Object)305; /* 19 */
    V227 = Lgetv(nil, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    stack[-3] = V227;
    V227 = stack[-3];
    if (!car_legal(V227)) goto V241;
    stack[-2] = qcar(V227);
    V228 = stack[-5];
    V227 = (Lisp_Object)257; /* 16 */
    V227 = Lgetv(nil, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    stack[-1] = V227;
    V227 = stack[-1];
    if (!car_legal(V227)) goto V241;
    stack[0] = qcar(V227);
    V228 = stack[-5];
    V227 = (Lisp_Object)241; /* 15 */
    V227 = Lgetv(nil, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    V228 = V227;
    if (!car_legal(V228)) goto V239;
    V229 = qcar(V228);
    V228 = stack[-6];
    if (!car_legal(V227)) goto V240;
    V227 = qcdr(V227);
    V227 = Lapply2(nil, 3, V229, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    V228 = V227;
    V227 = stack[-1];
    if (!car_legal(V227)) goto V240;
    V227 = qcdr(V227);
    V227 = Lapply2(nil, 3, stack[0], V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    stack[0] = V227;
    V228 = stack[-5];
    V227 = (Lisp_Object)289; /* 18 */
    V227 = Lgetv(nil, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    V228 = V227;
    if (!car_legal(V228)) goto V239;
    V229 = qcar(V228);
    V228 = stack[-6];
    if (!car_legal(V227)) goto V240;
    V227 = qcdr(V227);
    V227 = Lapply2(nil, 3, V229, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    V228 = V227;
    V227 = stack[-3];
    if (!car_legal(V227)) goto V240;
    V227 = qcdr(V227);
    V227 = Lapply3(nil, 4, stack[-2], stack[0], V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    stack[-2] = V227;
    V228 = stack[-5];
    V227 = (Lisp_Object)337; /* 21 */
    V227 = Lgetv(nil, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    stack[-1] = V227;
    V227 = stack[-1];
    if (!car_legal(V227)) goto V241;
    stack[0] = qcar(V227);
    V228 = stack[-5];
    V227 = (Lisp_Object)321; /* 20 */
    V227 = Lgetv(nil, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    V228 = V227;
    if (!car_legal(V228)) goto V239;
    V229 = qcar(V228);
    V228 = stack[-6];
    if (!car_legal(V227)) goto V240;
    V227 = qcdr(V227);
    V227 = Lapply2(nil, 3, V229, V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    env = stack[-8];
    V228 = V227;
    V227 = stack[-1];
    if (!car_legal(V227)) goto V240;
    V227 = qcdr(V227);
    V227 = Lapply2(nil, 3, stack[0], V228, V227);
    nil = C_nil;
    if (exception_pending()) goto V238;
    V228 = V227;
    V227 = stack[-7];
    if (!car_legal(V227)) goto V240;
    V227 = qcdr(V227);
    {
        Lisp_Object V242 = stack[-4];
        Lisp_Object V243 = stack[-2];
        popv(9);
        return Lapply3(nil, 4, V242, V243, V228, V227);
    }

V57:
    V227 = nil;
    { popv(9); return onevalue(V227); }
/* error exit handlers */
V241:
    popv(9);
    return error(1, err_bad_car, V227);
V240:
    popv(9);
    return error(1, err_bad_cdr, V227);
V239:
    popv(9);
    return error(1, err_bad_car, V228);
V238:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|underDomainOf| (#:G18925)
   (PROG NIL
      (RETURN
         (PROG (#:G18926)
            (RETURN
               (COND
                  ((SETQ #:G18926
                      (VMLISP:HGET BOOT::|underDomainOf;AL| #:G18925))
                     (BOOT::|CDRwithIncrement| #:G18926))
                  ('T
                     (CDR
                        (VMLISP:HPUT
                           BOOT::|underDomainOf;AL|
                           #:G18925
                           (CONS
                              1
                              (BOOT::|underDomainOf;|
                                 #:G18925)))) ))) ))) )

*/



/* Code for BOOT::|underDomainOf| */

static Lisp_Object CC_BOOT__underDomainOf(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V48, V49;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|underDomainOf|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = V2;
/* end of prologue */
    V49 = stack[-2];
    V48 = qvalue(elt(env, 1)); /* BOOT::|underDomainOf;AL| */
    fn = elt(env, 2); /* GETHASH */
    V48 = (*qfn2(fn))(qenv(fn), V49, V48);
    nil = C_nil;
    if (exception_pending()) goto V54;
    env = stack[-4];
    V49 = V48;
    if (V48 == nil) goto V14;
    V48 = V49;
    {
        popv(5);
        fn = elt(env, 3); /* BOOT::|CDRwithIncrement| */
        return (*qfn1(fn))(qenv(fn), V48);
    }

V14:
    V48 = lisp_true;
    if (V48 == nil) goto V26;
    stack[-3] = qvalue(elt(env, 1)); /* BOOT::|underDomainOf;AL| */
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)17; /* 1 */
    V48 = stack[-2];
    fn = elt(env, 4); /* BOOT::|underDomainOf;| */
    V48 = (*qfn1(fn))(qenv(fn), V48);
    nil = C_nil;
    if (exception_pending()) goto V54;
    env = stack[-4];
    V48 = cons(stack[0], V48);
    nil = C_nil;
    if (exception_pending()) goto V54;
    env = stack[-4];
    fn = elt(env, 5); /* VMLISP::HPUT */
    V48 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-1], V48);
    nil = C_nil;
    if (exception_pending()) goto V54;
    if (!car_legal(V48)) goto V55;
    V48 = qcdr(V48);
    { popv(5); return onevalue(V48); }

V26:
    V48 = nil;
    { popv(5); return onevalue(V48); }
/* error exit handlers */
V55:
    popv(5);
    return error(1, err_bad_cdr, V48);
V54:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|SMP;degree;$Ie;71| (|p| |$|)
   (COND
      ((BOOT::QEQCAR |p| 0) (BOOT::|spadConstant| |$| 183))
      ('T
         (BOOT:SPADCALL
            (BOOT:SPADCALL
               (BOOT:SPADCALL (QCDR (QCDR |p|)) (VMLISP:QREFELT |$| 22))
               (VMLISP:QREFELT |$| 184))
            (BOOT:SPADCALL
               (BOOT:SPADCALL (QCDR (QCDR |p|)) (VMLISP:QREFELT |$| 40))
               (QCAR (QCDR |p|))
               (VMLISP:QREFELT |$| 185))
            (VMLISP:QREFELT |$| 186)))) )

*/



/* Code for BOOT::|SMP;degree;$Ie;71| */

static Lisp_Object CC_BOOT__SMPUdegreeUDIeU71(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V172, V173, V174;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;degree;$Ie;71|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = V3;
    stack[-5] = V2;
/* end of prologue */
    V172 = stack[-5];
    V173 = qcar(V172);
    V172 = (Lisp_Object)1; /* 0 */
    V172 = Leql(nil, V173, V172);
    env = stack[-7];
    if (V172 == nil) goto V10;
    V173 = stack[-4];
    V172 = (Lisp_Object)2929; /* 183 */
    V172 = Lgetv(nil, V173, V172);
    nil = C_nil;
    if (exception_pending()) goto V182;
    V173 = V172;
    if (!car_legal(V173)) goto V183;
    V173 = qcar(V173);
    if (!car_legal(V172)) goto V184;
    V172 = qcdr(V172);
        popv(8);
        return Lapply1(nil, V173, V172);

V10:
    V172 = lisp_true;
    if (V172 == nil) goto V42;
    V173 = stack[-4];
    V172 = (Lisp_Object)2977; /* 186 */
    V172 = Lgetv(nil, V173, V172);
    nil = C_nil;
    if (exception_pending()) goto V182;
    env = stack[-7];
    stack[-6] = V172;
    V172 = stack[-6];
    if (!car_legal(V172)) goto V185;
    stack[-3] = qcar(V172);
    V173 = stack[-4];
    V172 = (Lisp_Object)2945; /* 184 */
    V172 = Lgetv(nil, V173, V172);
    nil = C_nil;
    if (exception_pending()) goto V182;
    env = stack[-7];
    stack[-1] = V172;
    V172 = stack[-1];
    if (!car_legal(V172)) goto V185;
    stack[0] = qcar(V172);
    V173 = stack[-4];
    V172 = (Lisp_Object)353; /* 22 */
    V172 = Lgetv(nil, V173, V172);
    nil = C_nil;
    if (exception_pending()) goto V182;
    env = stack[-7];
    V173 = V172;
    if (!car_legal(V173)) goto V183;
    V174 = qcar(V173);
    V173 = stack[-5];
    V173 = qcdr(V173);
    V173 = qcdr(V173);
    if (!car_legal(V172)) goto V184;
    V172 = qcdr(V172);
    V172 = Lapply2(nil, 3, V174, V173, V172);
    nil = C_nil;
    if (exception_pending()) goto V182;
    env = stack[-7];
    V173 = V172;
    V172 = stack[-1];
    if (!car_legal(V172)) goto V184;
    V172 = qcdr(V172);
    V172 = Lapply2(nil, 3, stack[0], V173, V172);
    nil = C_nil;
    if (exception_pending()) goto V182;
    env = stack[-7];
    stack[-2] = V172;
    V173 = stack[-4];
    V172 = (Lisp_Object)2961; /* 185 */
    V172 = Lgetv(nil, V173, V172);
    nil = C_nil;
    if (exception_pending()) goto V182;
    env = stack[-7];
    stack[-1] = V172;
    V172 = stack[-1];
    if (!car_legal(V172)) goto V185;
    stack[0] = qcar(V172);
    V173 = stack[-4];
    V172 = (Lisp_Object)641; /* 40 */
    V172 = Lgetv(nil, V173, V172);
    nil = C_nil;
    if (exception_pending()) goto V182;
    env = stack[-7];
    V173 = V172;
    if (!car_legal(V173)) goto V183;
    V174 = qcar(V173);
    V173 = stack[-5];
    V173 = qcdr(V173);
    V173 = qcdr(V173);
    if (!car_legal(V172)) goto V184;
    V172 = qcdr(V172);
    V172 = Lapply2(nil, 3, V174, V173, V172);
    nil = C_nil;
    if (exception_pending()) goto V182;
    env = stack[-7];
    V174 = V172;
    V172 = stack[-5];
    V172 = qcdr(V172);
    V173 = qcar(V172);
    V172 = stack[-1];
    if (!car_legal(V172)) goto V184;
    V172 = qcdr(V172);
    V172 = Lapply3(nil, 4, stack[0], V174, V173, V172);
    nil = C_nil;
    if (exception_pending()) goto V182;
    V173 = V172;
    V172 = stack[-6];
    if (!car_legal(V172)) goto V184;
    V172 = qcdr(V172);
    {
        Lisp_Object V186 = stack[-3];
        Lisp_Object V187 = stack[-2];
        popv(8);
        return Lapply3(nil, 4, V186, V187, V173, V172);
    }

V42:
    V172 = nil;
    { popv(8); return onevalue(V172); }
/* error exit handlers */
V185:
    popv(8);
    return error(1, err_bad_car, V172);
V184:
    popv(8);
    return error(1, err_bad_cdr, V172);
V183:
    popv(8);
    return error(1, err_bad_car, V173);
V182:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|FAMR-;ground;SR;4| (|x| |$|)
   (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 28)))

*/



/* Code for BOOT::|FAMR-;ground;SR;4| */

static Lisp_Object CC_BOOT__FAMRKUgroundUSRU4(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FAMR-;ground;SR;4|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    V31 = V3;
    stack[0] = V2;
/* end of prologue */
    V32 = V31;
    V31 = (Lisp_Object)449; /* 28 */
    V31 = Lgetv(nil, V32, V31);
    nil = C_nil;
    if (exception_pending()) goto V35;
    V32 = V31;
    if (!car_legal(V32)) goto V36;
    V33 = qcar(V32);
    V32 = stack[0];
    if (!car_legal(V31)) goto V37;
    V31 = qcdr(V31);
        popv(1);
        return Lapply2(nil, 3, V33, V32, V31);
/* error exit handlers */
V37:
    popv(1);
    return error(1, err_bad_cdr, V31);
V36:
    popv(1);
    return error(1, err_bad_car, V32);
V35:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|STAGG-;first;ANniA;3| (|x| |n| |$|)
   (PROG (#:G87053 |i|)
      (RETURN
         (SEQ
            (BOOT:SPADCALL
               (PROGN
                  (BOOT::LETT #:G87053 NIL BOOT::|STAGG-;first;ANniA;3|)
                  (SEQ
                     (BOOT::LETT |i| 1 BOOT::|STAGG-;first;ANniA;3|)
                     BOOT::G190
                     (COND ((VMLISP:QSGREATERP |i| |n|) (GO BOOT::G191)))
                     (SEQ
                        (EXIT
                           (BOOT::LETT
                              #:G87053
                              (CONS
                                 (BOOT::|STAGG-;c2|
                                    |x|
                                    (BOOT::LETT
                                       |x|
                                       (BOOT:SPADCALL
                                          |x|
                                          (VMLISP:QREFELT |$| 12))
                                       BOOT::|STAGG-;first;ANniA;3|)
                                    |$|)
                                 #:G87053)
                              BOOT::|STAGG-;first;ANniA;3|)))
                     (BOOT::LETT
                        |i|
                        (VMLISP:QSADD1 |i|)
                        BOOT::|STAGG-;first;ANniA;3|)
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT (NREVERSE0 #:G87053))))
               (VMLISP:QREFELT |$| 14)))) ))

*/



/* Code for BOOT::|STAGG-;first;ANniA;3| */

static Lisp_Object MS_CDECL CC_BOOT__STAGGKUfirstUANniAU3(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V105, V106, V107;
    Lisp_Object fn;
    argcheck(nargs, 3, "STAGG-;first;ANniA;3");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STAGG-;first;ANniA;3|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = V4;
    stack[-5] = V3;
    stack[-6] = V2;
/* end of prologue */
    V106 = stack[-4];
    V105 = (Lisp_Object)225; /* 14 */
    V105 = Lgetv(nil, V106, V105);
    nil = C_nil;
    if (exception_pending()) goto V116;
    env = stack[-8];
    stack[-2] = V105;
    V105 = stack[-2];
    if (!car_legal(V105)) goto V117;
    stack[-1] = qcar(V105);
    V105 = nil;
    stack[-7] = V105;
    V105 = (Lisp_Object)17; /* 1 */
    stack[-3] = V105;
    goto V46;

V46:
    V106 = stack[-3];
    V105 = stack[-5];
    V105 = (Lisp_Object)greaterp2(V106, V105);
    nil = C_nil;
    if (exception_pending()) goto V116;
    V105 = V105 ? lisp_true : nil;
    env = stack[-8];
    if (V105 == nil) goto V62;
    V105 = stack[-7];
    fn = elt(env, 1); /* NREVERSE0 */
    V105 = (*qfn1(fn))(qenv(fn), V105);
    nil = C_nil;
    if (exception_pending()) goto V116;
    V106 = V105;
    V105 = stack[-2];
    if (!car_legal(V105)) goto V118;
    V105 = qcdr(V105);
    {
        Lisp_Object V119 = stack[-1];
        popv(9);
        return Lapply2(nil, 3, V119, V106, V105);
    }

V62:
    stack[0] = stack[-6];
    V106 = stack[-4];
    V105 = (Lisp_Object)193; /* 12 */
    V105 = Lgetv(nil, V106, V105);
    nil = C_nil;
    if (exception_pending()) goto V116;
    env = stack[-8];
    V106 = V105;
    if (!car_legal(V106)) goto V120;
    V107 = qcar(V106);
    V106 = stack[-6];
    if (!car_legal(V105)) goto V118;
    V105 = qcdr(V105);
    V105 = Lapply2(nil, 3, V107, V106, V105);
    nil = C_nil;
    if (exception_pending()) goto V116;
    env = stack[-8];
    V106 = V105;
    stack[-6] = V106;
    V105 = stack[-4];
    fn = elt(env, 2); /* BOOT::|STAGG-;c2| */
    V106 = (*qfnn(fn))(qenv(fn), 3, stack[0], V106, V105);
    nil = C_nil;
    if (exception_pending()) goto V116;
    env = stack[-8];
    V105 = stack[-7];
    V105 = cons(V106, V105);
    nil = C_nil;
    if (exception_pending()) goto V116;
    env = stack[-8];
    stack[-7] = V105;
    V105 = stack[-3];
    V105 = add1(V105);
    nil = C_nil;
    if (exception_pending()) goto V116;
    env = stack[-8];
    stack[-3] = V105;
    goto V46;
/* error exit handlers */
V120:
    popv(9);
    return error(1, err_bad_car, V106);
V118:
    popv(9);
    return error(1, err_bad_cdr, V105);
V117:
    popv(9);
    return error(1, err_bad_car, V105);
V116:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|FRAC;recip;$U;30| (|x| |$|)
   (COND
      ((BOOT:SPADCALL (QCAR |x|) (VMLISP:QREFELT |$| 12))
         (CONS 1 "failed"))
      ('T (CONS 0 (CONS (QCDR |x|) (QCAR |x|)))) ))

*/



/* Code for BOOT::|FRAC;recip;$U;30| */

static Lisp_Object CC_BOOT__FRACUrecipUDUU30(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V60, V61, V62;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FRAC;recip;$U;30|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    V60 = V3;
    stack[0] = V2;
/* end of prologue */
    V61 = V60;
    V60 = (Lisp_Object)193; /* 12 */
    V60 = Lgetv(nil, V61, V60);
    nil = C_nil;
    if (exception_pending()) goto V64;
    env = stack[-1];
    V61 = V60;
    if (!car_legal(V61)) goto V65;
    V62 = qcar(V61);
    V61 = stack[0];
    V61 = qcar(V61);
    if (!car_legal(V60)) goto V66;
    V60 = qcdr(V60);
    V60 = Lapply2(nil, 3, V62, V61, V60);
    nil = C_nil;
    if (exception_pending()) goto V64;
    env = stack[-1];
    if (V60 == nil) goto V10;
    V60 = (Lisp_Object)17; /* 1 */
    V61 = elt(env, 1); /* "failed" */
    popv(2);
    { Lisp_Object retVal = cons(V60, V61);
    errexit();
    return onevalue(retVal); }

V10:
    V60 = lisp_true;
    if (V60 == nil) goto V45;
    V62 = (Lisp_Object)1; /* 0 */
    V60 = stack[0];
    V61 = qcdr(V60);
    V60 = stack[0];
    V60 = qcar(V60);
    popv(2);
    { Lisp_Object retVal = list2star(V62, V61, V60);
    errexit();
    return onevalue(retVal); }

V45:
    V60 = nil;
    { popv(2); return onevalue(V60); }
/* error exit handlers */
V66:
    popv(2);
    return error(1, err_bad_cdr, V60);
V65:
    popv(2);
    return error(1, err_bad_car, V61);
V64:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|allOrMatchingMms| (BOOT::|mms|
      BOOT::|args1|
      BOOT::|tar|
      BOOT::|dc|)
   (PROG (BOOT::|sig| BOOT::|LETTMP#1| BOOT::|res| BOOT::|args| |x|)
      (RETURN
         (SEQ
            (COND
               ((OR (NULL BOOT::|mms|) (NULL (CDR BOOT::|mms|)))
                  BOOT::|mms|)
               ('T
                  (BOOT:SPADLET |x| NIL)
                  (DO ((#:G18931 BOOT::|mms| (CDR #:G18931))
                        (BOOT::|mm| NIL))
                     ((OR
                         (ATOM #:G18931)
                         (PROGN (SETQ BOOT::|mm| (CAR #:G18931)) NIL))
                        NIL)
                     (SEQ
                        (EXIT
                           (PROGN
                              (BOOT:SPADLET BOOT::|sig| (CAR BOOT::|mm|))
                              (BOOT:SPADLET
                                 BOOT::|LETTMP#1|
                                 (VMLISP:MSUBSTQ
                                    BOOT::|dc|
                                    '|$|
                                    BOOT::|sig|))
                              (BOOT:SPADLET
                                 BOOT::|res|
                                 (CAR BOOT::|LETTMP#1|))
                              (BOOT:SPADLET
                                 BOOT::|args|
                                 (CDR BOOT::|LETTMP#1|))
                              (COND
                                 ((BOOT:NEQUAL BOOT::|args| BOOT::|args1|)
                                    NIL)
                                 ('T
                                    (BOOT:SPADLET
                                       |x|
                                       (CONS BOOT::|mm| |x|)))) ))) )
                  (COND (|x| |x|) ('T BOOT::|mms|)))) ))) )

*/



/* Code for BOOT::|allOrMatchingMms| */

static Lisp_Object MS_CDECL CC_BOOT__allOrMatchingMms(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V114, V115, V116;
    argcheck(nargs, 4, "allOrMatchingMms");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|allOrMatchingMms|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V5);
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        pop(V5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-2] = V5;
    V114 = V4;
    stack[-3] = V3;
    stack[-4] = V2;
/* end of prologue */
    V114 = stack[-4];
    if (V114 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    V114 = stack[-4];
    if (!car_legal(V114)) goto V123;
    V114 = qcdr(V114);
    if (V114 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    V114 = lisp_true;
    if (V114 == nil) goto V29;
    V114 = nil;
    stack[-5] = V114;
    V114 = stack[-4];
    stack[0] = V114;
    goto V38;

V38:
    V114 = stack[0];
    if (!consp(V114)) goto V33;
    V114 = stack[0];
    if (!car_legal(V114)) goto V124;
    V114 = qcar(V114);
    stack[-1] = V114;
    V114 = nil;
    if (!(V114 == nil)) goto V33;
    V114 = stack[-1];
    if (!car_legal(V114)) goto V124;
    V114 = qcar(V114);
    V116 = stack[-2];
    V115 = elt(env, 1); /* BOOT::$ */
    V114 = Lsubst(nil, 3, V116, V115, V114);
    nil = C_nil;
    if (exception_pending()) goto V125;
    env = stack[-6];
    if (!car_legal(V114)) goto V123;
    V114 = qcdr(V114);
    V115 = V114;
    V114 = stack[-3];
    V114 = (cl_equal(V115, V114) ? lisp_true : nil);
    V114 = (V114 == nil ? lisp_true : nil);
    if (!(V114 == nil)) goto V52;
    V114 = lisp_true;
    if (V114 == nil) goto V52;
    V115 = stack[-1];
    V114 = stack[-5];
    V114 = cons(V115, V114);
    nil = C_nil;
    if (exception_pending()) goto V125;
    env = stack[-6];
    stack[-5] = V114;
    goto V52;

V52:
    V114 = stack[0];
    if (!car_legal(V114)) goto V123;
    V114 = qcdr(V114);
    stack[0] = V114;
    goto V38;

V33:
    V114 = stack[-5];
    if (!(V114 == nil)) { Lisp_Object res = stack[-5]; popv(7); return onevalue(res); }
    V114 = lisp_true;
    if (!(V114 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    V114 = nil;
    { popv(7); return onevalue(V114); }

V29:
    V114 = nil;
    { popv(7); return onevalue(V114); }
/* error exit handlers */
V125:
    popv(7);
    return nil;
V124:
    popv(7);
    return error(1, err_bad_car, V114);
V123:
    popv(7);
    return error(1, err_bad_cdr, V114);
}

/*
(DEFUN BOOT::|IARRAY1;fill!;$S$;2| (|x| |s| |$|)
   (PROG (|i| #:G83151)
      (RETURN
         (SEQ
            (SEQ
               (BOOT::LETT |i| 0 BOOT::|IARRAY1;fill!;$S$;2|)
               (BOOT::LETT
                  #:G83151
                  (VMLISP:QVMAXINDEX |x|)
                  BOOT::|IARRAY1;fill!;$S$;2|)
               BOOT::G190
               (COND ((VMLISP:QSGREATERP |i| #:G83151) (GO BOOT::G191)))
               (SEQ (EXIT (SETELT |x| |i| |s|)))
               (BOOT::LETT
                  |i|
                  (VMLISP:QSADD1 |i|)
                  BOOT::|IARRAY1;fill!;$S$;2|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT |x|)))) )

*/



/* Code for BOOT::|IARRAY1;fill!;$S$;2| */

static Lisp_Object MS_CDECL CC_BOOT__IARRAY1UfillBUDSDU2(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V54, V55, V56;
    Lisp_Object fn;
    argcheck(nargs, 3, "IARRAY1;fill!;$S$;2");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IARRAY1;fill!;$S$;2|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    V54 = V4;
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    V54 = (Lisp_Object)1; /* 0 */
    stack[-3] = V54;
    V54 = stack[-2];
    V54 = Llength(nil, V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-4];
    V54 = sub1(V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-4];
    stack[0] = V54;
    goto V27;

V27:
    V55 = stack[-3];
    V54 = stack[0];
    V54 = (Lisp_Object)greaterp2(V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    V54 = V54 ? lisp_true : nil;
    env = stack[-4];
    if (!(V54 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    V56 = stack[-2];
    V55 = stack[-3];
    V54 = stack[-1];
    fn = elt(env, 1); /* SETELT */
    V54 = (*qfnn(fn))(qenv(fn), 3, V56, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-4];
    V54 = stack[-3];
    V54 = add1(V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-4];
    stack[-3] = V54;
    goto V27;
/* error exit handlers */
V61:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|IFARRAY;concat!;$S$;21| (|r| |x| |$|)
   (SEQ
      (BOOT::|IFARRAY;growAndFill| |r| 1 |x| |$|)
      (SETELT (VMLISP:QVELT |r| 2) (|-| (VMLISP:QVELT |r| 1) 1) |x|)
      (EXIT |r|)))

*/



/* Code for BOOT::|IFARRAY;concat!;$S$;21| */

static Lisp_Object MS_CDECL CC_BOOT__IFARRAYUconcatBUDSDU21(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V52, V53, V54, V55;
    Lisp_Object fn;
    argcheck(nargs, 3, "IFARRAY;concat!;$S$;21");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;concat!;$S$;21|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    V52 = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V55 = stack[-1];
    V54 = (Lisp_Object)17; /* 1 */
    V53 = stack[0];
    fn = elt(env, 1); /* BOOT::|IFARRAY;growAndFill| */
    V52 = (*qfnn(fn))(qenv(fn), 4, V55, V54, V53, V52);
    nil = C_nil;
    if (exception_pending()) goto V59;
    env = stack[-3];
    V53 = stack[-1];
    V52 = (Lisp_Object)33; /* 2 */
    stack[-2] = Lgetv(nil, V53, V52);
    nil = C_nil;
    if (exception_pending()) goto V59;
    env = stack[-3];
    V53 = stack[-1];
    V52 = (Lisp_Object)17; /* 1 */
    V52 = Lgetv(nil, V53, V52);
    nil = C_nil;
    if (exception_pending()) goto V59;
    env = stack[-3];
    V53 = sub1(V52);
    nil = C_nil;
    if (exception_pending()) goto V59;
    env = stack[-3];
    V52 = stack[0];
    fn = elt(env, 2); /* SETELT */
    V52 = (*qfnn(fn))(qenv(fn), 3, stack[-2], V53, V52);
    nil = C_nil;
    if (exception_pending()) goto V59;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
/* error exit handlers */
V59:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|BOP;is?;$SB;1| (BOOT::|op| |s| |$|)
   (EQUAL (BOOT:SPADCALL BOOT::|op| (VMLISP:QREFELT |$| 8)) |s|))

*/



/* Code for BOOT::|BOP;is?;$SB;1| */

static Lisp_Object MS_CDECL CC_BOOT__BOPUisWUDSBU1(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V39, V40, V41;
    argcheck(nargs, 3, "BOP;is?;$SB;1");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|BOP;is?;$SB;1|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    V39 = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V40 = V39;
    V39 = (Lisp_Object)129; /* 8 */
    V39 = Lgetv(nil, V40, V39);
    nil = C_nil;
    if (exception_pending()) goto V44;
    env = stack[-2];
    V40 = V39;
    if (!car_legal(V40)) goto V45;
    V41 = qcar(V40);
    V40 = stack[-1];
    if (!car_legal(V39)) goto V46;
    V39 = qcdr(V39);
    V39 = Lapply2(nil, 3, V41, V40, V39);
    nil = C_nil;
    if (exception_pending()) goto V44;
    V40 = V39;
    V39 = stack[0];
    V39 = (cl_equal(V40, V39) ? lisp_true : nil);
    { popv(3); return onevalue(V39); }
/* error exit handlers */
V46:
    popv(3);
    return error(1, err_bad_cdr, V39);
V45:
    popv(3);
    return error(1, err_bad_car, V40);
V44:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|FRAC;*;I2$;24| (|n| |x| |$|)
   (PROG (|y|)
      (RETURN
         (SEQ
            (BOOT::LETT
               |y|
               (CONS
                  (BOOT:SPADCALL |n| (VMLISP:QREFELT |$| 59))
                  (QCDR |x|))
               BOOT::|FRAC;*;I2$;24|)
            (BOOT::|FRAC;cancelGcd| |y| |$|)
            (EXIT
               (BOOT::|FRAC;normalize|
                  (CONS
                     (BOOT:SPADCALL
                        (QCAR |x|)
                        (QCAR |y|)
                        (VMLISP:QREFELT |$| 49))
                     (QCDR |y|))
                  |$|)))) ))

*/



/* Code for BOOT::|FRAC;*;I2$;24| */

static Lisp_Object MS_CDECL CC_BOOT__FRACUHUI2DU24(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V98, V99, V100, V101;
    Lisp_Object fn;
    argcheck(nargs, 3, "FRAC;*;I2$;24");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FRAC;*;I2$;24|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = V4;
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    V99 = stack[0];
    V98 = (Lisp_Object)945; /* 59 */
    V98 = Lgetv(nil, V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V105;
    env = stack[-3];
    V99 = V98;
    if (!car_legal(V99)) goto V106;
    V100 = qcar(V99);
    V99 = stack[-2];
    if (!car_legal(V98)) goto V107;
    V98 = qcdr(V98);
    V98 = Lapply2(nil, 3, V100, V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V105;
    env = stack[-3];
    V99 = V98;
    V98 = stack[-1];
    V98 = qcdr(V98);
    V98 = cons(V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V105;
    env = stack[-3];
    stack[-2] = V98;
    V99 = stack[-2];
    V98 = stack[0];
    fn = elt(env, 1); /* BOOT::|FRAC;cancelGcd| */
    V98 = (*qfn2(fn))(qenv(fn), V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V105;
    env = stack[-3];
    V99 = stack[0];
    V98 = (Lisp_Object)785; /* 49 */
    V98 = Lgetv(nil, V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V105;
    env = stack[-3];
    V99 = V98;
    if (!car_legal(V99)) goto V106;
    V101 = qcar(V99);
    V99 = stack[-1];
    V100 = qcar(V99);
    V99 = stack[-2];
    V99 = qcar(V99);
    if (!car_legal(V98)) goto V107;
    V98 = qcdr(V98);
    V98 = Lapply3(nil, 4, V101, V100, V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V105;
    env = stack[-3];
    V99 = V98;
    V98 = stack[-2];
    V98 = qcdr(V98);
    V99 = cons(V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V105;
    env = stack[-3];
    V98 = stack[0];
    {
        popv(4);
        fn = elt(env, 2); /* BOOT::|FRAC;normalize| */
        return (*qfn2(fn))(qenv(fn), V99, V98);
    }
/* error exit handlers */
V107:
    popv(4);
    return error(1, err_bad_cdr, V98);
V106:
    popv(4);
    return error(1, err_bad_car, V99);
V105:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|IFARRAY;growWith| (|r| |n| |x| |$|)
   (PROG (#:G82564 |y| |a| |k| #:G82569)
      (RETURN
         (SEQ
            (BOOT::LETT
               |y|
               (BOOT:SPADCALL
                  (PROG1
                     (BOOT::LETT #:G82564 |n| BOOT::|IFARRAY;growWith|)
                     (BOOT::|check-subtype|
                        (|>=| #:G82564 0)
                        '(BOOT:|NonNegativeInteger|)
                        #:G82564))
                  |x|
                  (VMLISP:QREFELT |$| 21))
               BOOT::|IFARRAY;growWith|)
            (BOOT::LETT |a| (VMLISP:QVELT |r| 2) BOOT::|IFARRAY;growWith|)
            (SEQ
               (BOOT::LETT |k| 0 BOOT::|IFARRAY;growWith|)
               (BOOT::LETT
                  #:G82569
                  (|-| (VMLISP:QVELT |r| 0) 1)
                  BOOT::|IFARRAY;growWith|)
               BOOT::G190
               (COND ((VMLISP:QSGREATERP |k| #:G82569) (GO BOOT::G191)))
               (SEQ (EXIT (SETELT |y| |k| (ELT |a| |k|))))
               (BOOT::LETT
                  |k|
                  (VMLISP:QSADD1 |k|)
                  BOOT::|IFARRAY;growWith|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (VMLISP:QSETVELT |r| 0 |n|)
            (VMLISP:QSETVELT |r| 2 |y|)
            (EXIT |r|)))) )

*/



/* Code for BOOT::|IFARRAY;growWith| */

static Lisp_Object MS_CDECL CC_BOOT__IFARRAYUgrowWith(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V155, V156, V157;
    Lisp_Object fn;
    argcheck(nargs, 4, "IFARRAY;growWith");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;growWith|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V5);
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        pop(V5);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    V155 = V5;
    stack[-3] = V4;
    stack[-5] = V3;
    stack[-6] = V2;
/* end of prologue */
    V156 = V155;
    V155 = (Lisp_Object)337; /* 21 */
    V155 = Lgetv(nil, V156, V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    stack[-2] = V155;
    V155 = stack[-2];
    if (!car_legal(V155)) goto V167;
    stack[-1] = qcar(V155);
    V155 = stack[-5];
    stack[-4] = V155;
    stack[0] = V155;
    V156 = stack[-4];
    V155 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 2); /* >= */
    V155 = (*qfn2(fn))(qenv(fn), V156, V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    if (!(V155 == nil)) goto V47;
    V156 = stack[-4];
    V155 = elt(env, 1); /* (BOOT:|NonNegativeInteger|) */
    fn = elt(env, 3); /* BOOT::COERCE-FAILURE-MSG */
    V155 = (*qfn2(fn))(qenv(fn), V156, V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    fn = elt(env, 4); /* BOOT::|error| */
    V155 = (*qfn1(fn))(qenv(fn), V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    goto V47;

V47:
    V155 = stack[0];
    V157 = V155;
    V156 = stack[-3];
    V155 = stack[-2];
    if (!car_legal(V155)) goto V168;
    V155 = qcdr(V155);
    V155 = Lapply3(nil, 4, stack[-1], V157, V156, V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    stack[-7] = V155;
    V156 = stack[-6];
    V155 = (Lisp_Object)33; /* 2 */
    V155 = Lgetv(nil, V156, V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    stack[-4] = V155;
    V155 = (Lisp_Object)1; /* 0 */
    stack[-3] = V155;
    V156 = stack[-6];
    V155 = (Lisp_Object)1; /* 0 */
    V155 = Lgetv(nil, V156, V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    V155 = sub1(V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    stack[-2] = V155;
    goto V99;

V99:
    V156 = stack[-3];
    V155 = stack[-2];
    V155 = (Lisp_Object)greaterp2(V156, V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    V155 = V155 ? lisp_true : nil;
    env = stack[-8];
    if (V155 == nil) goto V109;
    V157 = stack[-6];
    V156 = (Lisp_Object)1; /* 0 */
    V155 = stack[-5];
    V155 = Lputv(nil, 3, V157, V156, V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    V157 = stack[-6];
    V156 = (Lisp_Object)33; /* 2 */
    V155 = stack[-7];
    V155 = Lputv(nil, 3, V157, V156, V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }

V109:
    stack[-1] = stack[-7];
    stack[0] = stack[-3];
    V156 = stack[-4];
    V155 = stack[-3];
    fn = elt(env, 5); /* ELT */
    V155 = (*qfn2(fn))(qenv(fn), V156, V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    fn = elt(env, 6); /* SETELT */
    V155 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    V155 = stack[-3];
    V155 = add1(V155);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-8];
    stack[-3] = V155;
    goto V99;
/* error exit handlers */
V168:
    popv(9);
    return error(1, err_bad_cdr, V155);
V167:
    popv(9);
    return error(1, err_bad_car, V155);
V166:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|loadIfNecessary| (|u|) (BOOT::|loadLibIfNecessary| |u| 'T))

*/



/* Code for BOOT::|loadIfNecessary| */

static Lisp_Object CC_BOOT__loadIfNecessary(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V14, V15;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|loadIfNecessary|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V14 = V2;
/* end of prologue */
    V15 = V14;
    V14 = lisp_true;
    {
        fn = elt(env, 1); /* BOOT::|loadLibIfNecessary| */
        return (*qfn2(fn))(qenv(fn), V15, V14);
    }
}

/*
(DEFUN BOOT::|EXPR;coerce;I$;10| (|n| |$|)
   (BOOT:SPADCALL |n| (VMLISP:QREFELT |$| 32)))

*/



/* Code for BOOT::|EXPR;coerce;I$;10| */

static Lisp_Object CC_BOOT__EXPRUcoerceUIDU10(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;coerce;I$;10|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    V31 = V3;
    stack[0] = V2;
/* end of prologue */
    V32 = V31;
    V31 = (Lisp_Object)513; /* 32 */
    V31 = Lgetv(nil, V32, V31);
    nil = C_nil;
    if (exception_pending()) goto V35;
    V32 = V31;
    if (!car_legal(V32)) goto V36;
    V33 = qcar(V32);
    V32 = stack[0];
    if (!car_legal(V31)) goto V37;
    V31 = qcdr(V31);
        popv(1);
        return Lapply2(nil, 3, V33, V32, V31);
/* error exit handlers */
V37:
    popv(1);
    return error(1, err_bad_cdr, V31);
V36:
    popv(1);
    return error(1, err_bad_car, V32);
V35:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|typeIsASmallInteger| (|x|)
   (BOOT:|BOOT-EQUAL| |x| BOOT::|$SingleInteger|))

*/



/* Code for BOOT::|typeIsASmallInteger| */

static Lisp_Object CC_BOOT__typeIsASmallInteger(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V14, V15;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|typeIsASmallInteger|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V14 = V2;
/* end of prologue */
    V15 = qvalue(elt(env, 1)); /* BOOT::|$SingleInteger| */
    V14 = (cl_equal(V14, V15) ? lisp_true : nil);
    return onevalue(V14);
}

/*
(DEFUN BOOT::|ILIST;split!;$I$;29| (|p| |n| |$|)
   (PROG (#:G102085 |q|)
      (RETURN
         (SEQ
            (COND
               ((|<| |n| 1) (BOOT::|error| "index out of range"))
               ('T
                  (SEQ
                     (BOOT::LETT
                        |p|
                        (BOOT:SPADCALL
                           |p|
                           (PROG1
                              (BOOT::LETT
                                 #:G102085
                                 (|-| |n| 1)
                                 BOOT::|ILIST;split!;$I$;29|)
                              (BOOT::|check-subtype|
                                 (|>=| #:G102085 0)
                                 '(BOOT:|NonNegativeInteger|)
                                 #:G102085))
                           (VMLISP:QREFELT |$| 32))
                        BOOT::|ILIST;split!;$I$;29|)
                     (BOOT::LETT
                        |q|
                        (QCDR |p|)
                        BOOT::|ILIST;split!;$I$;29|)
                     (VMLISP:QRPLACD |p| NIL)
                     (EXIT |q|)))) ))) )

*/



/* Code for BOOT::|ILIST;split!;$I$;29| */

static Lisp_Object MS_CDECL CC_BOOT__ILISTUsplitBUDIDU29(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V101, V102;
    Lisp_Object fn;
    argcheck(nargs, 3, "ILIST;split!;$I$;29");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;split!;$I$;29|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V102 = stack[0];
    V101 = (Lisp_Object)17; /* 1 */
    V101 = (Lisp_Object)lessp2(V102, V101);
    nil = C_nil;
    if (exception_pending()) goto V108;
    V101 = V101 ? lisp_true : nil;
    env = stack[-5];
    if (V101 == nil) goto V17;
    V101 = elt(env, 1); /* "index out of range" */
    {
        popv(6);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V101);
    }

V17:
    V101 = lisp_true;
    if (V101 == nil) goto V29;
    V102 = stack[-2];
    V101 = (Lisp_Object)513; /* 32 */
    V101 = Lgetv(nil, V102, V101);
    nil = C_nil;
    if (exception_pending()) goto V108;
    env = stack[-5];
    stack[-3] = V101;
    V101 = stack[-3];
    if (!car_legal(V101)) goto V109;
    stack[-2] = qcar(V101);
    V101 = stack[0];
    V101 = sub1(V101);
    nil = C_nil;
    if (exception_pending()) goto V108;
    env = stack[-5];
    stack[-4] = V101;
    stack[0] = V101;
    V102 = stack[-4];
    V101 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* >= */
    V101 = (*qfn2(fn))(qenv(fn), V102, V101);
    nil = C_nil;
    if (exception_pending()) goto V108;
    env = stack[-5];
    if (!(V101 == nil)) goto V64;
    V102 = stack[-4];
    V101 = elt(env, 2); /* (BOOT:|NonNegativeInteger|) */
    fn = elt(env, 5); /* BOOT::COERCE-FAILURE-MSG */
    V101 = (*qfn2(fn))(qenv(fn), V102, V101);
    nil = C_nil;
    if (exception_pending()) goto V108;
    env = stack[-5];
    fn = elt(env, 3); /* BOOT::|error| */
    V101 = (*qfn1(fn))(qenv(fn), V101);
    nil = C_nil;
    if (exception_pending()) goto V108;
    env = stack[-5];
    goto V64;

V64:
    V101 = stack[0];
    V102 = V101;
    V101 = stack[-3];
    if (!car_legal(V101)) goto V110;
    V101 = qcdr(V101);
    V101 = Lapply3(nil, 4, stack[-2], stack[-1], V102, V101);
    nil = C_nil;
    if (exception_pending()) goto V108;
    env = stack[-5];
    stack[-1] = V101;
    V101 = stack[-1];
    V101 = qcdr(V101);
    stack[0] = V101;
    V102 = stack[-1];
    V101 = nil;
    V101 = Lrplacd(nil, V102, V101);
    nil = C_nil;
    if (exception_pending()) goto V108;
    { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }

V29:
    V101 = nil;
    { popv(6); return onevalue(V101); }
/* error exit handlers */
V110:
    popv(6);
    return error(1, err_bad_cdr, V101);
V109:
    popv(6);
    return error(1, err_bad_car, V101);
V108:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|EUCDOM-;unitNormalizeIdealElt| (|s| |$|)
   (PROG (BOOT::|#G16| |u| |c| |a|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT::LETT
                  BOOT::|#G16|
                  (BOOT:SPADCALL
                     (VMLISP:QVELT |s| 2)
                     (VMLISP:QREFELT |$| 22))
                  BOOT::|EUCDOM-;unitNormalizeIdealElt|)
               (BOOT::LETT
                  |u|
                  (VMLISP:QVELT BOOT::|#G16| 0)
                  BOOT::|EUCDOM-;unitNormalizeIdealElt|)
               (BOOT::LETT
                  |c|
                  (VMLISP:QVELT BOOT::|#G16| 1)
                  BOOT::|EUCDOM-;unitNormalizeIdealElt|)
               (BOOT::LETT
                  |a|
                  (VMLISP:QVELT BOOT::|#G16| 2)
                  BOOT::|EUCDOM-;unitNormalizeIdealElt|)
               BOOT::|#G16|)
            (EXIT
               (COND
                  ((BOOT:SPADCALL |a| (VMLISP:QREFELT |$| 23)) |s|)
                  ('T
                     (VECTOR
                        (BOOT:SPADCALL
                           |a|
                           (VMLISP:QVELT |s| 0)
                           (VMLISP:QREFELT |$| 24))
                        (BOOT:SPADCALL
                           |a|
                           (VMLISP:QVELT |s| 1)
                           (VMLISP:QREFELT |$| 24))
                        |c|)))) ))) )

*/



/* Code for BOOT::|EUCDOM-;unitNormalizeIdealElt| */

static Lisp_Object CC_BOOT__EUCDOMKUunitNormalizeIdealElt(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V181, V182, V183;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EUCDOM-;unitNormalizeIdealElt|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-4] = V3;
    stack[-5] = V2;
/* end of prologue */
    V182 = stack[-4];
    V181 = (Lisp_Object)353; /* 22 */
    V181 = Lgetv(nil, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[-1] = V181;
    V181 = stack[-1];
    if (!car_legal(V181)) goto V192;
    stack[0] = qcar(V181);
    V182 = stack[-5];
    V181 = (Lisp_Object)33; /* 2 */
    V182 = Lgetv(nil, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V181 = stack[-1];
    if (!car_legal(V181)) goto V193;
    V181 = qcdr(V181);
    V181 = Lapply2(nil, 3, stack[0], V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[0] = V181;
    V182 = stack[0];
    V181 = (Lisp_Object)1; /* 0 */
    V181 = Lgetv(nil, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V182 = stack[0];
    V181 = (Lisp_Object)17; /* 1 */
    V181 = Lgetv(nil, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[-6] = V181;
    V182 = stack[0];
    V181 = (Lisp_Object)33; /* 2 */
    V181 = Lgetv(nil, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[-3] = V181;
    V182 = stack[-4];
    V181 = (Lisp_Object)369; /* 23 */
    V181 = Lgetv(nil, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V182 = V181;
    if (!car_legal(V182)) goto V194;
    V183 = qcar(V182);
    V182 = stack[-3];
    if (!car_legal(V181)) goto V193;
    V181 = qcdr(V181);
    V181 = Lapply2(nil, 3, V183, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    if (!(V181 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    V181 = lisp_true;
    if (V181 == nil) goto V101;
    V182 = stack[-4];
    V181 = (Lisp_Object)385; /* 24 */
    V181 = Lgetv(nil, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[-2] = V181;
    V181 = stack[-2];
    if (!car_legal(V181)) goto V192;
    stack[-1] = qcar(V181);
    stack[0] = stack[-3];
    V182 = stack[-5];
    V181 = (Lisp_Object)1; /* 0 */
    V182 = Lgetv(nil, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V181 = stack[-2];
    if (!car_legal(V181)) goto V193;
    V181 = qcdr(V181);
    V181 = Lapply3(nil, 4, stack[-1], stack[0], V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[-1] = V181;
    V182 = stack[-4];
    V181 = (Lisp_Object)385; /* 24 */
    V181 = Lgetv(nil, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[-2] = V181;
    V181 = stack[-2];
    if (!car_legal(V181)) goto V192;
    stack[0] = qcar(V181);
    V182 = stack[-5];
    V181 = (Lisp_Object)17; /* 1 */
    V182 = Lgetv(nil, V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V181 = stack[-2];
    if (!car_legal(V181)) goto V193;
    V181 = qcdr(V181);
    V181 = Lapply3(nil, 4, stack[0], stack[-3], V182, V181);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V182 = V181;
    V181 = stack[-6];
    {
        Lisp_Object V195 = stack[-1];
        popv(8);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V195, V182, V181);
    }

V101:
    V181 = nil;
    { popv(8); return onevalue(V181); }
/* error exit handlers */
V194:
    popv(8);
    return error(1, err_bad_car, V182);
V193:
    popv(8);
    return error(1, err_bad_cdr, V181);
V192:
    popv(8);
    return error(1, err_bad_car, V181);
V191:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|IDPAG;-;3$;4| (|x| |y| |$|)
   (PROG (|r| BOOT::|newcell| BOOT::|endcell| BOOT::|end| BOOT::|res|)
      (RETURN
         (SEQ
            (COND
               ((NULL |x|) (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 11)))
               ((NULL |y|) |x|)
               ('T
                  (SEQ
                     (BOOT::LETT BOOT::|endcell| NIL BOOT::|IDPAG;-;3$;4|)
                     (BOOT::LETT BOOT::|res| NIL BOOT::|IDPAG;-;3$;4|)
                     (SEQ
                        BOOT::G190
                        (COND
                           ((NULL
                               (COND
                                  ((OR (NULL |x|) (NULL |y|)) 'NIL)
                                  ('T 'T)))
                              (GO BOOT::G191)))
                        (SEQ
                           (BOOT::LETT
                              BOOT::|newcell|
                              NIL
                              BOOT::|IDPAG;-;3$;4|)
                           (COND
                              ((BOOT:SPADCALL
                                  (QCAR (BOOT::|SPADfirst| |x|))
                                  (QCAR (BOOT::|SPADfirst| |y|))
                                  (VMLISP:QREFELT |$| 19))
                                 (SEQ
                                    (BOOT::LETT
                                       |r|
                                       (BOOT:SPADCALL
                                          (QCDR (BOOT::|SPADfirst| |x|))
                                          (QCDR (BOOT::|SPADfirst| |y|))
                                          (VMLISP:QREFELT |$| 20))
                                       BOOT::|IDPAG;-;3$;4|)
                                    (COND
                                       ((NULL
                                           (BOOT:SPADCALL
                                              |r|
                                              (VMLISP:QREFELT |$| 21)))
                                          (BOOT::LETT
                                             BOOT::|newcell|
                                             (CONS
                                                (CONS
                                                   (QCAR
        (BOOT::|SPADfirst| |x|))
                                                   |r|)
                                                NIL)
                                             BOOT::|IDPAG;-;3$;4|)))
                                    (BOOT::LETT
                                       |x|
                                       (CDR |x|)
                                       BOOT::|IDPAG;-;3$;4|)
                                    (EXIT
                                       (BOOT::LETT
                                          |y|
                                          (CDR |y|)
                                          BOOT::|IDPAG;-;3$;4|))))
                              ((BOOT:SPADCALL
                                  (QCAR (BOOT::|SPADfirst| |y|))
                                  (QCAR (BOOT::|SPADfirst| |x|))
                                  (VMLISP:QREFELT |$| 22))
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|newcell|
                                       (CONS (BOOT::|SPADfirst| |x|) NIL)
                                       BOOT::|IDPAG;-;3$;4|)
                                    (EXIT
                                       (BOOT::LETT
                                          |x|
                                          (CDR |x|)
                                          BOOT::|IDPAG;-;3$;4|))))
                              ('T
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|newcell|
                                       (CONS
                                          (CONS
                                             (QCAR (BOOT::|SPADfirst| |y|))
                                             (BOOT:SPADCALL
                                                (QCDR
                                                   (BOOT::|SPADfirst| |y|))
                                                (VMLISP:QREFELT |$| 10)))
                                          NIL)
                                       BOOT::|IDPAG;-;3$;4|)
                                    (EXIT
                                       (BOOT::LETT
                                          |y|
                                          (CDR |y|)
                                          BOOT::|IDPAG;-;3$;4|)))) )
                           (EXIT
                              (COND
                                 ((NULL (NULL BOOT::|newcell|))
                                    (COND
                                       ((NULL BOOT::|endcell|)
                                          (SEQ
                                             (BOOT::LETT
                                                BOOT::|res|
                                                BOOT::|newcell|
                                                BOOT::|IDPAG;-;3$;4|)
                                             (EXIT
                                                (BOOT::LETT
                                                   BOOT::|endcell|
                                                   BOOT::|res|
                                                   BOOT::|IDPAG;-;3$;4|))))
                                       ('T
                                          (SEQ
                                             (BOOT::|IDPAG;qsetrest!|
                                                BOOT::|endcell|
                                                BOOT::|newcell|
                                                |$|)
                                             (EXIT
                                                (BOOT::LETT
                                                   BOOT::|endcell|
                                                   BOOT::|newcell|
                                          BOOT::|IDPAG;-;3$;4|)))) ))) ))
                        NIL
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT NIL))
                     (COND
                        ((NULL |x|)
                           (BOOT::LETT
                              BOOT::|end|
                              (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 11))
                              BOOT::|IDPAG;-;3$;4|))
                        ('T
                           (BOOT::LETT
                              BOOT::|end|
                              |x|
                              BOOT::|IDPAG;-;3$;4|)))
                     (COND
                        ((NULL BOOT::|res|)
                           (BOOT::LETT
                              BOOT::|res|
                              BOOT::|end|
                              BOOT::|IDPAG;-;3$;4|))
                        ('T
                           (BOOT::|IDPAG;qsetrest!|
                              BOOT::|endcell|
                              BOOT::|end|
                              |$|)))
                     (EXIT BOOT::|res|)))) ))) )

*/



/* Code for BOOT::|IDPAG;-;3$;4| */

static Lisp_Object MS_CDECL CC_BOOT__IDPAGUKU3DU4(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V471, V472, V473;
    Lisp_Object fn;
    argcheck(nargs, 3, "IDPAG;-;3$;4");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IDPAG;-;3$;4|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V4);
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        pop(V4);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = V4;
    stack[-7] = V3;
    stack[-8] = V2;
/* end of prologue */
    stack[-4] = nil;
    V471 = stack[-8];
    if (V471 == nil) goto V26;
    V471 = stack[-7];
    if (V471 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    V471 = lisp_true;
    if (V471 == nil) goto V51;
    V471 = nil;
    stack[-5] = V471;
    V471 = nil;
    stack[-3] = V471;
    goto V59;

V59:
    V471 = stack[-8];
    if (V471 == nil) goto V67;
    V471 = stack[-7];
    if (V471 == nil) goto V67;
    V471 = lisp_true;
    if (V471 == nil) goto V75;
    V471 = lisp_true;
    goto V66;

V66:
    if (V471 == nil) goto V58;
    V471 = nil;
    stack[-9] = V471;
    V472 = stack[-6];
    V471 = (Lisp_Object)305; /* 19 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    stack[-2] = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V485;
    stack[-1] = qcar(V471);
    V471 = stack[-8];
    V472 = V471;
    V471 = V472;
    if (V471 == nil) goto V115;
    V471 = V472;
    if (!car_legal(V471)) goto V485;
    V471 = qcar(V471);
    goto V110;

V110:
    stack[0] = qcar(V471);
    V471 = stack[-7];
    V472 = V471;
    V471 = V472;
    if (V471 == nil) goto V128;
    V471 = V472;
    if (!car_legal(V471)) goto V485;
    V471 = qcar(V471);
    goto V123;

V123:
    V472 = qcar(V471);
    V471 = stack[-2];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, stack[-1], stack[0], V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    if (V471 == nil) goto V249;
    V472 = stack[-6];
    V471 = (Lisp_Object)321; /* 20 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    stack[-2] = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V485;
    stack[-1] = qcar(V471);
    V471 = stack[-8];
    V472 = V471;
    V471 = V472;
    if (V471 == nil) goto V168;
    V471 = V472;
    if (!car_legal(V471)) goto V485;
    V471 = qcar(V471);
    goto V163;

V163:
    stack[0] = qcdr(V471);
    V471 = stack[-7];
    V472 = V471;
    V471 = V472;
    if (V471 == nil) goto V181;
    V471 = V472;
    if (!car_legal(V471)) goto V485;
    V471 = qcar(V471);
    goto V176;

V176:
    V472 = qcdr(V471);
    V471 = stack[-2];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, stack[-1], stack[0], V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    stack[0] = V471;
    V472 = stack[-6];
    V471 = (Lisp_Object)337; /* 21 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    V472 = V471;
    if (!car_legal(V472)) goto V487;
    V473 = qcar(V472);
    V472 = stack[0];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply2(nil, 3, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    if (!(V471 == nil)) goto V190;
    V471 = stack[-8];
    V472 = V471;
    V471 = V472;
    if (V471 == nil) goto V231;
    V471 = V472;
    if (!car_legal(V471)) goto V485;
    V471 = qcar(V471);
    goto V226;

V226:
    V472 = qcar(V471);
    V471 = stack[0];
    V471 = cons(V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    V471 = ncons(V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    stack[-9] = V471;
    goto V190;

V190:
    V471 = stack[-8];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    stack[-8] = V471;
    V471 = stack[-7];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    stack[-7] = V471;
    goto V82;

V82:
    V471 = stack[-9];
    if (V471 == nil) goto V59;
    V471 = stack[-5];
    if (V471 == nil) goto V385;
    V471 = lisp_true;
    if (V471 == nil) goto V59;
    V473 = stack[-5];
    V472 = stack[-9];
    V471 = stack[-6];
    fn = elt(env, 1); /* BOOT::|IDPAG;qsetrest!| */
    V471 = (*qfnn(fn))(qenv(fn), 3, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    V471 = stack[-9];
    stack[-5] = V471;
    goto V59;

V385:
    V471 = stack[-9];
    stack[-3] = V471;
    V471 = stack[-3];
    stack[-5] = V471;
    goto V59;

V231:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V471 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    goto V226;

V181:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V471 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    goto V176;

V168:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V471 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    goto V163;

V249:
    V472 = stack[-6];
    V471 = (Lisp_Object)353; /* 22 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    stack[-2] = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V485;
    stack[-1] = qcar(V471);
    V471 = stack[-7];
    V472 = V471;
    V471 = V472;
    if (V471 == nil) goto V275;
    V471 = V472;
    if (!car_legal(V471)) goto V485;
    V471 = qcar(V471);
    goto V270;

V270:
    stack[0] = qcar(V471);
    V471 = stack[-8];
    V472 = V471;
    V471 = V472;
    if (V471 == nil) goto V288;
    V471 = V472;
    if (!car_legal(V471)) goto V485;
    V471 = qcar(V471);
    goto V283;

V283:
    V472 = qcar(V471);
    V471 = stack[-2];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, stack[-1], stack[0], V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    if (V471 == nil) goto V244;
    V471 = stack[-8];
    V472 = V471;
    V471 = V472;
    if (V471 == nil) goto V306;
    V471 = V472;
    if (!car_legal(V471)) goto V485;
    V471 = qcar(V471);
    goto V301;

V301:
    V471 = ncons(V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    stack[-9] = V471;
    V471 = stack[-8];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    stack[-8] = V471;
    goto V82;

V306:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V471 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    goto V301;

V244:
    V471 = lisp_true;
    if (V471 == nil) goto V82;
    V471 = stack[-7];
    V472 = V471;
    V471 = V472;
    if (V471 == nil) goto V333;
    V471 = V472;
    if (!car_legal(V471)) goto V485;
    V471 = qcar(V471);
    goto V328;

V328:
    stack[-2] = qcar(V471);
    V472 = stack[-6];
    V471 = (Lisp_Object)161; /* 10 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    stack[-1] = V471;
    V471 = stack[-1];
    if (!car_legal(V471)) goto V485;
    stack[0] = qcar(V471);
    V471 = stack[-7];
    V472 = V471;
    V471 = V472;
    if (V471 == nil) goto V367;
    V471 = V472;
    if (!car_legal(V471)) goto V485;
    V471 = qcar(V471);
    goto V362;

V362:
    V472 = qcdr(V471);
    V471 = stack[-1];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply2(nil, 3, stack[0], V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    V471 = cons(stack[-2], V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    V471 = ncons(V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    stack[-9] = V471;
    V471 = stack[-7];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    stack[-7] = V471;
    goto V82;

V367:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V471 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    goto V362;

V333:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V471 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    goto V328;

V288:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V471 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    goto V283;

V275:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V471 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    goto V270;

V128:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V471 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    goto V123;

V115:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V471 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    goto V110;

V58:
    V471 = stack[-8];
    if (V471 == nil) goto V424;
    V471 = lisp_true;
    if (V471 == nil) goto V416;
    V471 = stack[-8];
    stack[-4] = V471;
    goto V416;

V416:
    V471 = stack[-3];
    if (V471 == nil) goto V450;
    V471 = lisp_true;
    if (V471 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    V473 = stack[-5];
    V472 = stack[-4];
    V471 = stack[-6];
    fn = elt(env, 1); /* BOOT::|IDPAG;qsetrest!| */
    V471 = (*qfnn(fn))(qenv(fn), 3, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }

V450:
    V471 = stack[-4];
    stack[-3] = V471;
    { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }

V424:
    V472 = stack[-6];
    V471 = (Lisp_Object)177; /* 11 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    V472 = V471;
    if (!car_legal(V472)) goto V487;
    V473 = qcar(V472);
    V472 = stack[-7];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply2(nil, 3, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-10];
    stack[-4] = V471;
    goto V416;

V75:
    V471 = nil;
    goto V66;

V67:
    V471 = nil;
    goto V66;

V51:
    V471 = nil;
    { popv(11); return onevalue(V471); }

V26:
    V472 = stack[-6];
    V471 = (Lisp_Object)177; /* 11 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    V472 = V471;
    if (!car_legal(V472)) goto V487;
    V473 = qcar(V472);
    V472 = stack[-7];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
        popv(11);
        return Lapply2(nil, 3, V473, V472, V471);
/* error exit handlers */
V487:
    popv(11);
    return error(1, err_bad_car, V472);
V486:
    popv(11);
    return error(1, err_bad_cdr, V471);
V485:
    popv(11);
    return error(1, err_bad_car, V471);
V484:
    popv(11);
    return nil;
}

/*
(DEFUN BOOT::|RING-;coerce;IS;1| (|n| |$|)
   (BOOT:SPADCALL |n| (BOOT::|spadConstant| |$| 7) (VMLISP:QREFELT |$| 9)))

*/



/* Code for BOOT::|RING-;coerce;IS;1| */

static Lisp_Object CC_BOOT__RINGKUcoerceUISU1(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V54, V55;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|RING-;coerce;IS;1|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V3);
        push(V2);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(V2);
        pop(V3);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    V55 = stack[-1];
    V54 = (Lisp_Object)145; /* 9 */
    V54 = Lgetv(nil, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V60;
    env = stack[-4];
    stack[-3] = V54;
    V54 = stack[-3];
    if (!car_legal(V54)) goto V61;
    stack[0] = qcar(V54);
    V55 = stack[-1];
    V54 = (Lisp_Object)113; /* 7 */
    V54 = Lgetv(nil, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V60;
    env = stack[-4];
    V55 = V54;
    if (!car_legal(V55)) goto V62;
    V55 = qcar(V55);
    if (!car_legal(V54)) goto V63;
    V54 = qcdr(V54);
    V54 = Lapply1(nil, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V60;
    V55 = V54;
    V54 = stack[-3];
    if (!car_legal(V54)) goto V63;
    V54 = qcdr(V54);
    {
        Lisp_Object V64 = stack[0];
        Lisp_Object V65 = stack[-2];
        popv(5);
        return Lapply3(nil, 4, V64, V65, V55, V54);
    }
/* error exit handlers */
V63:
    popv(5);
    return error(1, err_bad_cdr, V54);
V62:
    popv(5);
    return error(1, err_bad_car, V55);
V61:
    popv(5);
    return error(1, err_bad_car, V54);
V60:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|deepSubCopy| (|t| BOOT::SL)
   (COND ((NULL BOOT::SL) |t|) ('T (BOOT::|deepSubCopy0| |t| BOOT::SL))))

*/



/* Code for BOOT::|deepSubCopy| */

static Lisp_Object CC_BOOT__deepSubCopy(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V24, V25, V26;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|deepSubCopy|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V25 = V3;
    V26 = V2;
/* end of prologue */
    V24 = V25;
    if (V24 == nil) return onevalue(V26);
    V24 = lisp_true;
    if (V24 == nil) goto V14;
    V24 = V26;
    {
        fn = elt(env, 1); /* BOOT::|deepSubCopy0| */
        return (*qfn2(fn))(qenv(fn), V24, V25);
    }

V14:
    V24 = nil;
    return onevalue(V24);
}



setup_type const u12_setup[] =
{
    {"BOOT@@isHomogeneousList@@Builtin",CC_BOOT__isHomogeneousList,too_many_1,wrong_no_1},
    {"BOOT@@LO;-;2$;3@@Builtin",too_few_2,      CC_BOOT__LOUKU2DU3,wrong_no_2},
    {"BOOT@@EUCDOM-;gcd;3S;5@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__EUCDOMKUgcdU3SU5},
    {"BOOT@@newLookupInAddChain@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__newLookupInAddChain},
    {"BOOT@@LO;=;2$B;4@@Builtin",wrong_no_na,   wrong_no_nb,   (n_args *)CC_BOOT__LOUMU2DBU4},
    {"BOOT@@newLookupInDomain@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__newLookupInDomain},
    {"BOOT@@atom2String@@Builtin",CC_BOOT__atom2String,too_many_1,wrong_no_1},
    {"BOOT@@IARRAY1;elt;$IS;16@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IARRAY1UeltUDISU16},
    {"BOOT@@EXPR;+;3$;12@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__EXPRULU3DU12},
    {"BOOT@@COMPCAT-;rem;3S;53@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__COMPCATKUremU3SU53},
    {"BOOT@@FIELD-;/;3S;11@@Builtin",wrong_no_na,wrong_no_nb,  (n_args *)CC_BOOT__FIELDKUVU3SU11},
    {"BOOT@@SMP;univariate;$VarSetSup;13@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__SMPUunivariateUDVarSetSupU13},
    {"BOOT@@hasCate@@Builtin",  wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__hasCate},
    {"BOOT@@URAGG-;tail;2A;16@@Builtin",too_few_2,CC_BOOT__URAGGKUtailU2AU16,wrong_no_2},
    {"BOOT@@npInfGeneric@@Builtin",CC_BOOT__npInfGeneric,too_many_1,wrong_no_1},
    {"BOOT@@FACUTIL;lowerPolynomial;SupSup;1@@Builtin",too_few_2,CC_BOOT__FACUTILUlowerPolynomialUSupSupU1,wrong_no_2},
    {"BOOT@@underDomainOf@@Builtin",CC_BOOT__underDomainOf,too_many_1,wrong_no_1},
    {"BOOT@@SMP;degree;$Ie;71@@Builtin",too_few_2,CC_BOOT__SMPUdegreeUDIeU71,wrong_no_2},
    {"BOOT@@FAMR-;ground;SR;4@@Builtin",too_few_2,CC_BOOT__FAMRKUgroundUSRU4,wrong_no_2},
    {"BOOT@@STAGG-;first;ANniA;3@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__STAGGKUfirstUANniAU3},
    {"BOOT@@FRAC;recip;$U;30@@Builtin",too_few_2,CC_BOOT__FRACUrecipUDUU30,wrong_no_2},
    {"BOOT@@allOrMatchingMms@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__allOrMatchingMms},
    {"BOOT@@IARRAY1;fill!;$S$;2@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IARRAY1UfillBUDSDU2},
    {"BOOT@@IFARRAY;concat!;$S$;21@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IFARRAYUconcatBUDSDU21},
    {"BOOT@@BOP;is?;$SB;1@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__BOPUisWUDSBU1},
    {"BOOT@@FRAC;*;I2$;24@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__FRACUHUI2DU24},
    {"BOOT@@IFARRAY;growWith@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IFARRAYUgrowWith},
    {"BOOT@@loadIfNecessary@@Builtin",CC_BOOT__loadIfNecessary,too_many_1,wrong_no_1},
    {"BOOT@@EXPR;coerce;I$;10@@Builtin",too_few_2,CC_BOOT__EXPRUcoerceUIDU10,wrong_no_2},
    {"BOOT@@typeIsASmallInteger@@Builtin",CC_BOOT__typeIsASmallInteger,too_many_1,wrong_no_1},
    {"BOOT@@ILIST;split!;$I$;29@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__ILISTUsplitBUDIDU29},
    {"BOOT@@EUCDOM-;unitNormalizeIdealElt@@Builtin",too_few_2,CC_BOOT__EUCDOMKUunitNormalizeIdealElt,wrong_no_2},
    {"BOOT@@IDPAG;-;3$;4@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__IDPAGUKU3DU4},
    {"BOOT@@RING-;coerce;IS;1@@Builtin",too_few_2,CC_BOOT__RINGKUcoerceUISU1,wrong_no_2},
    {"BOOT@@deepSubCopy@@Builtin",too_few_2,    CC_BOOT__deepSubCopy,wrong_no_2},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
