
/* u05.c                 Machine generated C code */

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
(DEFUN BOOT::|evalMmDom| (BOOT::|st|)
   (PROG (|d| |p| BOOT::|d1| BOOT::|ISTMP#1| |v| BOOT::|ISTMP#2|
         BOOT::|fun| BOOT::SL)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET BOOT::SL NIL)
               (DO ((#:G18997 BOOT::|st| (CDR #:G18997))
                     (BOOT::|mmC| NIL)
                     (#:G18998
                        NIL
                        (BOOT:|BOOT-EQUAL| BOOT::SL 'BOOT::|failed|)))
                  ((OR
                      (ATOM #:G18997)
                      (PROGN (SETQ BOOT::|mmC| (CAR #:G18997)) NIL)
                      #:G18998)
                     NIL)
                  (SEQ
                     (EXIT
                        (COND
                           ((AND
                               (PAIRP BOOT::|mmC|)
                               (EQ (QCAR BOOT::|mmC|) 'BOOT::|isDomain|)
                               (PROGN
                                  (BOOT:SPADLET
                                     BOOT::|ISTMP#1|
                                     (QCDR BOOT::|mmC|))
                                  (AND
                                     (PAIRP BOOT::|ISTMP#1|)
                                     (PROGN
                                        (BOOT:SPADLET
                                           |v|
                                           (QCAR BOOT::|ISTMP#1|))
                                        (BOOT:SPADLET
                                           BOOT::|ISTMP#2|
                                           (QCDR BOOT::|ISTMP#1|))
                                        (AND
                                           (PAIRP BOOT::|ISTMP#2|)
                                           (EQ (QCDR BOOT::|ISTMP#2|) NIL)
                                           (PROGN
                                              (BOOT:SPADLET
                                                 |d|
                                                 (QCAR BOOT::|ISTMP#2|))
                                              'T)))) ))
                              (COND
                                 ((STRINGP |d|)
                                    (BOOT:SPADLET
                                       BOOT::SL
                                       'BOOT::|failed|))
                                 ((BOOT:SPADLET
                                     |p|
                                     (AND
                                        (VMLISP:ASSQ |v| BOOT::SL)
                                        (NULL
                                           (BOOT:|BOOT-EQUAL|
                                              |d|
                                              (CDR |p|)))) )
                                    (BOOT:SPADLET
                                       BOOT::SL
                                       'BOOT::|failed|))
                                 ('T
                                    (BOOT:SPADLET
                                       BOOT::|d1|
                                       (BOOT::|subCopy| |d| BOOT::SL))
                                    (COND
                                       ((AND
                                           (CONSP BOOT::|d1|)
                                           (MEMQ |v| BOOT::|d1|))
                                          (BOOT:SPADLET
                                             BOOT::SL
                                             'BOOT::|failed|))
                                       ('T
                                          (BOOT:SPADLET
                                             BOOT::SL
                                             (BOOT::|augmentSub|
                                                |v|
                                                BOOT::|d1|
                                                BOOT::SL)))) )))
                           ((AND
                               (PAIRP BOOT::|mmC|)
                               (EQ
                                  (QCAR BOOT::|mmC|)
                                  'BOOT::|isFreeFunction|)
                               (PROGN
                                  (BOOT:SPADLET
                                     BOOT::|ISTMP#1|
                                     (QCDR BOOT::|mmC|))
                                  (AND
                                     (PAIRP BOOT::|ISTMP#1|)
                                     (PROGN
                                        (BOOT:SPADLET
                                           |v|
                                           (QCAR BOOT::|ISTMP#1|))
                                        (BOOT:SPADLET
                                           BOOT::|ISTMP#2|
                                           (QCDR BOOT::|ISTMP#1|))
                                        (AND
                                           (PAIRP BOOT::|ISTMP#2|)
                                           (EQ (QCDR BOOT::|ISTMP#2|) NIL)
                                           (PROGN
                                              (BOOT:SPADLET
                                                 BOOT::|fun|
                                                 (QCAR BOOT::|ISTMP#2|))
                                              'T)))) ))
                              (BOOT:SPADLET
                                 BOOT::SL
                                 (BOOT::|augmentSub|
                                    |v|
                                    (BOOT::|subCopy| BOOT::|fun| BOOT::SL)
                                    BOOT::SL)))) )))
               BOOT::SL)))) )

*/



/* Code for BOOT::|evalMmDom| */

static Lisp_Object CC_BOOT__evalMmDom(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V256, V257, V258;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|evalMmDom|\n");
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
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    V256 = V2;
/* end of prologue */
    stack[-7] = nil;
    stack[-6] = nil;
    stack[-5] = nil;
    stack[-3] = nil;
    V257 = nil;
    stack[-2] = V257;
    V257 = nil;
    stack[0] = V256;
    goto V27;

V27:
    V256 = stack[0];
    if (!consp(V256)) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    V256 = stack[0];
    if (!car_legal(V256)) goto V267;
    V256 = qcar(V256);
    stack[-1] = V256;
    V256 = nil;
    if (!(V256 == nil)) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    V256 = V257;
    if (!(V256 == nil)) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    V256 = stack[-1];
    fn = elt(env, 4); /* CONSP */
    V256 = (*qfn1(fn))(qenv(fn), V256);
    nil = C_nil;
    if (exception_pending()) goto V268;
    env = stack[-8];
    if (V256 == nil) goto V47;
    V256 = stack[-1];
    V257 = qcar(V256);
    V256 = elt(env, 1); /* BOOT::|isDomain| */
    if (!(V257 == V256)) goto V47;
    V256 = stack[-1];
    V256 = qcdr(V256);
    stack[-4] = V256;
    V256 = stack[-4];
    fn = elt(env, 4); /* CONSP */
    V256 = (*qfn1(fn))(qenv(fn), V256);
    nil = C_nil;
    if (exception_pending()) goto V268;
    env = stack[-8];
    if (V256 == nil) goto V65;
    V256 = stack[-4];
    V256 = qcar(V256);
    stack[-5] = V256;
    V256 = stack[-4];
    V256 = qcdr(V256);
    stack[-4] = V256;
    V256 = stack[-4];
    fn = elt(env, 4); /* CONSP */
    V256 = (*qfn1(fn))(qenv(fn), V256);
    nil = C_nil;
    if (exception_pending()) goto V268;
    env = stack[-8];
    if (V256 == nil) goto V78;
    V256 = stack[-4];
    V256 = qcdr(V256);
    if (V256 == nil) goto V88;
    V256 = nil;
    goto V64;

V64:
    if (V256 == nil) goto V47;
    V256 = stack[-7];
    V256 = Lstringp(nil, V256);
    env = stack[-8];
    if (V256 == nil) goto V106;
    V256 = elt(env, 2); /* BOOT::|failed| */
    stack[-2] = V256;
    goto V43;

V43:
    V256 = stack[0];
    if (!car_legal(V256)) goto V269;
    V256 = qcdr(V256);
    V258 = V256;
    V257 = stack[-2];
    V256 = elt(env, 2); /* BOOT::|failed| */
    V256 = (V257 == V256 ? lisp_true : nil);
    V257 = V258;
    stack[0] = V257;
    V257 = V256;
    goto V27;

V106:
    V257 = stack[-5];
    V256 = stack[-2];
    V256 = Latsoc(nil, V257, V256);
    if (V256 == nil) goto V104;
    V257 = stack[-7];
    V256 = stack[-6];
    if (!car_legal(V256)) goto V269;
    V256 = qcdr(V256);
    V256 = (cl_equal(V257, V256) ? lisp_true : nil);
    V256 = (V256 == nil ? lisp_true : nil);
    goto V103;

V103:
    stack[-6] = V256;
    if (V256 == nil) goto V101;
    V256 = elt(env, 2); /* BOOT::|failed| */
    stack[-2] = V256;
    goto V43;

V101:
    V256 = lisp_true;
    if (V256 == nil) goto V43;
    V257 = stack[-7];
    V256 = stack[-2];
    fn = elt(env, 5); /* BOOT::|subCopy| */
    V256 = (*qfn2(fn))(qenv(fn), V257, V256);
    nil = C_nil;
    if (exception_pending()) goto V268;
    env = stack[-8];
    V257 = V256;
    V256 = V257;
    if (!consp(V256)) goto V142;
    V258 = stack[-5];
    V256 = V257;
    V256 = Lmemq(nil, V258, V256);
    if (V256 == nil) goto V142;
    V256 = elt(env, 2); /* BOOT::|failed| */
    stack[-2] = V256;
    goto V43;

V142:
    V256 = lisp_true;
    if (V256 == nil) goto V43;
    V258 = stack[-5];
    V256 = stack[-2];
    fn = elt(env, 6); /* BOOT::|augmentSub| */
    V256 = (*qfnn(fn))(qenv(fn), 3, V258, V257, V256);
    nil = C_nil;
    if (exception_pending()) goto V268;
    env = stack[-8];
    stack[-2] = V256;
    goto V43;

V104:
    V256 = nil;
    goto V103;

V47:
    V256 = stack[-1];
    fn = elt(env, 4); /* CONSP */
    V256 = (*qfn1(fn))(qenv(fn), V256);
    nil = C_nil;
    if (exception_pending()) goto V268;
    env = stack[-8];
    if (V256 == nil) goto V43;
    V256 = stack[-1];
    V257 = qcar(V256);
    V256 = elt(env, 3); /* BOOT::|isFreeFunction| */
    if (!(V257 == V256)) goto V43;
    V256 = stack[-1];
    V256 = qcdr(V256);
    stack[-4] = V256;
    V256 = stack[-4];
    fn = elt(env, 4); /* CONSP */
    V256 = (*qfn1(fn))(qenv(fn), V256);
    nil = C_nil;
    if (exception_pending()) goto V268;
    env = stack[-8];
    if (V256 == nil) goto V188;
    V256 = stack[-4];
    V256 = qcar(V256);
    stack[-5] = V256;
    V256 = stack[-4];
    V256 = qcdr(V256);
    stack[-4] = V256;
    V256 = stack[-4];
    fn = elt(env, 4); /* CONSP */
    V256 = (*qfn1(fn))(qenv(fn), V256);
    nil = C_nil;
    if (exception_pending()) goto V268;
    env = stack[-8];
    if (V256 == nil) goto V201;
    V256 = stack[-4];
    V256 = qcdr(V256);
    if (V256 == nil) goto V211;
    V256 = nil;
    goto V187;

V187:
    if (V256 == nil) goto V43;
    stack[-1] = stack[-5];
    V257 = stack[-3];
    V256 = stack[-2];
    fn = elt(env, 5); /* BOOT::|subCopy| */
    V257 = (*qfn2(fn))(qenv(fn), V257, V256);
    nil = C_nil;
    if (exception_pending()) goto V268;
    env = stack[-8];
    V256 = stack[-2];
    fn = elt(env, 6); /* BOOT::|augmentSub| */
    V256 = (*qfnn(fn))(qenv(fn), 3, stack[-1], V257, V256);
    nil = C_nil;
    if (exception_pending()) goto V268;
    env = stack[-8];
    stack[-2] = V256;
    goto V43;

V211:
    V256 = stack[-4];
    V256 = qcar(V256);
    stack[-3] = V256;
    V256 = lisp_true;
    goto V187;

V201:
    V256 = nil;
    goto V187;

V188:
    V256 = nil;
    goto V187;

V88:
    V256 = stack[-4];
    V256 = qcar(V256);
    stack[-7] = V256;
    V256 = lisp_true;
    goto V64;

V78:
    V256 = nil;
    goto V64;

V65:
    V256 = nil;
    goto V64;
/* error exit handlers */
V269:
    popv(9);
    return error(1, err_bad_cdr, V256);
V268:
    popv(9);
    return nil;
V267:
    popv(9);
    return error(1, err_bad_car, V256);
}

/*
(DEFUN QUOTIENT (X Y)
   (COND ((OR (FLOATP X) (FLOATP Y)) (|/| X Y)) (T (TRUNCATE X Y))))

*/



/* Code for QUOTIENT */

static Lisp_Object CC_LISP__QUOTIENT(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering QUOTIENT\n");
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
/* copy arguments values to proper place */
    V35 = V3;
    V36 = V2;
/* end of prologue */
    V37 = V36;
    V37 = Lfloatp(nil, V37);
    env = stack[0];
    if (!(V37 == nil)) goto V21;
    V37 = V35;
    V37 = Lfloatp(nil, V37);
    env = stack[0];
    if (!(V37 == nil)) goto V21;
    {
        popv(1);
        fn = elt(env, 1); /* TRUNCATE */
        return (*qfn2(fn))(qenv(fn), V36, V35);
    }

V21:
    {
        popv(1);
        fn = elt(env, 2); /* / */
        return (*qfn2(fn))(qenv(fn), V36, V35);
    }
}

/*
(DEFUN BOOT::|FAMR-;coefficients;SL;6| (|x| |$|)
   (COND
      ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 30)) NIL)
      ('T
         (CONS
            (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 31))
            (BOOT:SPADCALL
               (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 34))
               (VMLISP:QREFELT |$| 37)))) ))

*/



/* Code for BOOT::|FAMR-;coefficients;SL;6| */

static Lisp_Object CC_BOOT__FAMRKUcoefficientsUSLU6(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V116, V117, V118;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FAMR-;coefficients;SL;6|\n");
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
/* copy arguments values to proper place */
    stack[-2] = V3;
    stack[-3] = V2;
/* end of prologue */
    V117 = stack[-2];
    V116 = (Lisp_Object)481; /* 30 */
    V116 = Lgetv(nil, V117, V116);
    nil = C_nil;
    if (exception_pending()) goto V124;
    env = stack[-5];
    V117 = V116;
    if (!car_legal(V117)) goto V125;
    V118 = qcar(V117);
    V117 = stack[-3];
    if (!car_legal(V116)) goto V126;
    V116 = qcdr(V116);
    V116 = Lapply2(nil, 3, V118, V117, V116);
    nil = C_nil;
    if (exception_pending()) goto V124;
    env = stack[-5];
    if (V116 == nil) goto V10;
    V116 = nil;
    { popv(6); return onevalue(V116); }

V10:
    V116 = lisp_true;
    if (V116 == nil) goto V37;
    V117 = stack[-2];
    V116 = (Lisp_Object)497; /* 31 */
    V116 = Lgetv(nil, V117, V116);
    nil = C_nil;
    if (exception_pending()) goto V124;
    env = stack[-5];
    V117 = V116;
    if (!car_legal(V117)) goto V125;
    V118 = qcar(V117);
    V117 = stack[-3];
    if (!car_legal(V116)) goto V126;
    V116 = qcdr(V116);
    V116 = Lapply2(nil, 3, V118, V117, V116);
    nil = C_nil;
    if (exception_pending()) goto V124;
    env = stack[-5];
    stack[-4] = V116;
    V117 = stack[-2];
    V116 = (Lisp_Object)593; /* 37 */
    V116 = Lgetv(nil, V117, V116);
    nil = C_nil;
    if (exception_pending()) goto V124;
    env = stack[-5];
    stack[-1] = V116;
    V116 = stack[-1];
    if (!car_legal(V116)) goto V127;
    stack[0] = qcar(V116);
    V117 = stack[-2];
    V116 = (Lisp_Object)545; /* 34 */
    V116 = Lgetv(nil, V117, V116);
    nil = C_nil;
    if (exception_pending()) goto V124;
    env = stack[-5];
    V117 = V116;
    if (!car_legal(V117)) goto V125;
    V118 = qcar(V117);
    V117 = stack[-3];
    if (!car_legal(V116)) goto V126;
    V116 = qcdr(V116);
    V116 = Lapply2(nil, 3, V118, V117, V116);
    nil = C_nil;
    if (exception_pending()) goto V124;
    env = stack[-5];
    V117 = V116;
    V116 = stack[-1];
    if (!car_legal(V116)) goto V126;
    V116 = qcdr(V116);
    V116 = Lapply2(nil, 3, stack[0], V117, V116);
    nil = C_nil;
    if (exception_pending()) goto V124;
    {
        Lisp_Object V128 = stack[-4];
        popv(6);
        { Lisp_Object retVal = cons(V128, V116);
        errexit();
        return onevalue(retVal); }
    }

V37:
    V116 = nil;
    { popv(6); return onevalue(V116); }
/* error exit handlers */
V127:
    popv(6);
    return error(1, err_bad_car, V116);
V126:
    popv(6);
    return error(1, err_bad_cdr, V116);
V125:
    popv(6);
    return error(1, err_bad_car, V117);
V124:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|LSAGG-;select!;M2A;5| (|f| |x| |$|)
   (PROG (|y| |z|)
      (RETURN
         (SEQ
            (SEQ
               BOOT::G190
               (COND
                  ((NULL
                      (COND
                         ((OR
                             (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 16))
                             (BOOT:SPADCALL
                                (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 18))
                                |f|))
                            'NIL)
                         ('T 'T)))
                     (GO BOOT::G191)))
               (SEQ
                  (EXIT
                     (BOOT::LETT
                        |x|
                        (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 17))
                        BOOT::|LSAGG-;select!;M2A;5|)))
               NIL
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT
               (COND
                  ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 16)) |x|)
                  ('T
                     (SEQ
                        (BOOT::LETT |y| |x| BOOT::|LSAGG-;select!;M2A;5|)
                        (BOOT::LETT
                           |z|
                           (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 17))
                           BOOT::|LSAGG-;select!;M2A;5|)
                        (SEQ
                           BOOT::G190
                           (COND
                              ((NULL
                                  (COND
                                     ((BOOT:SPADCALL
                                         |z|
                                         (VMLISP:QREFELT |$| 16))
                                        'NIL)
                                     ('T 'T)))
                                 (GO BOOT::G191)))
                           (SEQ
                              (EXIT
                                 (COND
                                    ((BOOT:SPADCALL
                                        (BOOT:SPADCALL
                                           |z|
                                           (VMLISP:QREFELT |$| 18))
                                        |f|)
                                       (SEQ
                                          (BOOT::LETT
                                             |y|
                                             |z|
                                             BOOT::|LSAGG-;select!;M2A;5|)
                                          (EXIT
                                             (BOOT::LETT
                                                |z|
                                                (BOOT:SPADCALL
                                                   |z|
                                                   (VMLISP:QREFELT |$| 17))
                                          BOOT::|LSAGG-;select!;M2A;5|))))
                                    ('T
                                       (SEQ
                                          (BOOT::LETT
                                             |z|
                                             (BOOT:SPADCALL
                                                |z|
                                                (VMLISP:QREFELT |$| 17))
                                             BOOT::|LSAGG-;select!;M2A;5|)
                                          (EXIT
                                             (BOOT:SPADCALL
                                                |y|
                                                |z|
                                                (VMLISP:QREFELT
                                                   |$|
                                                   25)))) ))) )
                           NIL
                           (GO BOOT::G190)
                           BOOT::G191
                           (EXIT NIL))
                        (EXIT |x|)))) ))) ))

*/



/* Code for BOOT::|LSAGG-;select!;M2A;5| */

static Lisp_Object MS_CDECL CC_BOOT__LSAGGKUselectBUM2AU5(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V365, V366, V367, V368;
    argcheck(nargs, 3, "LSAGG-;select!;M2A;5");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|LSAGG-;select!;M2A;5|\n");
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

V31:
    V366 = stack[-3];
    V365 = (Lisp_Object)257; /* 16 */
    V365 = Lgetv(nil, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    if (!car_legal(V366)) goto V377;
    V367 = qcar(V366);
    V366 = stack[-4];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, V367, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    if (!(V365 == nil)) goto V24;
    V365 = stack[-5];
    stack[-1] = V365;
    V365 = stack[-1];
    if (!car_legal(V365)) goto V379;
    stack[0] = qcar(V365);
    V366 = stack[-3];
    V365 = (Lisp_Object)289; /* 18 */
    V365 = Lgetv(nil, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    if (!car_legal(V366)) goto V377;
    V367 = qcar(V366);
    V366 = stack[-4];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, V367, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    V365 = stack[-1];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, stack[0], V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    if (!(V365 == nil)) goto V24;
    V365 = lisp_true;
    if (V365 == nil) goto V94;
    V365 = lisp_true;
    goto V23;

V23:
    if (V365 == nil) goto V135;
    V366 = stack[-3];
    V365 = (Lisp_Object)273; /* 17 */
    V365 = Lgetv(nil, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    if (!car_legal(V366)) goto V377;
    V367 = qcar(V366);
    V366 = stack[-4];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, V367, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    stack[-4] = V365;
    goto V31;

V135:
    V366 = stack[-3];
    V365 = (Lisp_Object)257; /* 16 */
    V365 = Lgetv(nil, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    if (!car_legal(V366)) goto V377;
    V367 = qcar(V366);
    V366 = stack[-4];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, V367, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    if (!(V365 == nil)) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    V365 = lisp_true;
    if (V365 == nil) goto V157;
    V365 = stack[-4];
    stack[-6] = V365;
    V366 = stack[-3];
    V365 = (Lisp_Object)273; /* 17 */
    V365 = Lgetv(nil, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    if (!car_legal(V366)) goto V377;
    V367 = qcar(V366);
    V366 = stack[-6];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, V367, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    stack[-2] = V365;
    goto V202;

V202:
    V366 = stack[-3];
    V365 = (Lisp_Object)257; /* 16 */
    V365 = Lgetv(nil, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    if (!car_legal(V366)) goto V377;
    V367 = qcar(V366);
    V366 = stack[-2];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, V367, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    if (V365 == nil) goto V197;
    V365 = nil;
    goto V195;

V195:
    if (V365 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    V365 = stack[-5];
    stack[-1] = V365;
    V365 = stack[-1];
    if (!car_legal(V365)) goto V379;
    stack[0] = qcar(V365);
    V366 = stack[-3];
    V365 = (Lisp_Object)289; /* 18 */
    V365 = Lgetv(nil, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    if (!car_legal(V366)) goto V377;
    V367 = qcar(V366);
    V366 = stack[-2];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, V367, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    V365 = stack[-1];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, stack[0], V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    if (V365 == nil) goto V232;
    V365 = stack[-2];
    stack[-6] = V365;
    V366 = stack[-3];
    V365 = (Lisp_Object)273; /* 17 */
    V365 = Lgetv(nil, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    if (!car_legal(V366)) goto V377;
    V367 = qcar(V366);
    V366 = stack[-2];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, V367, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    stack[-2] = V365;
    goto V202;

V232:
    V365 = lisp_true;
    if (V365 == nil) goto V202;
    V366 = stack[-3];
    V365 = (Lisp_Object)273; /* 17 */
    V365 = Lgetv(nil, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    if (!car_legal(V366)) goto V377;
    V367 = qcar(V366);
    V366 = stack[-2];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply2(nil, 3, V367, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    stack[-2] = V365;
    V366 = stack[-3];
    V365 = (Lisp_Object)401; /* 25 */
    V365 = Lgetv(nil, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    V366 = V365;
    if (!car_legal(V366)) goto V377;
    V368 = qcar(V366);
    V367 = stack[-6];
    V366 = stack[-2];
    if (!car_legal(V365)) goto V378;
    V365 = qcdr(V365);
    V365 = Lapply3(nil, 4, V368, V367, V366, V365);
    nil = C_nil;
    if (exception_pending()) goto V376;
    env = stack[-7];
    goto V202;

V197:
    V365 = lisp_true;
    if (V365 == nil) goto V224;
    V365 = lisp_true;
    goto V195;

V224:
    V365 = nil;
    goto V195;

V157:
    V365 = nil;
    { popv(8); return onevalue(V365); }

V94:
    V365 = nil;
    goto V23;

V24:
    V365 = nil;
    goto V23;
/* error exit handlers */
V379:
    popv(8);
    return error(1, err_bad_car, V365);
V378:
    popv(8);
    return error(1, err_bad_cdr, V365);
V377:
    popv(8);
    return error(1, err_bad_car, V366);
V376:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|LSAGG-;<;2AB;25| (|x| |y| |$|)
   (PROG (#:G87662)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (SEQ
                     BOOT::G190
                     (COND
                        ((NULL
                            (COND
                               ((OR
                                   (BOOT:SPADCALL
                                      |x|
                                      (VMLISP:QREFELT |$| 16))
                                   (BOOT:SPADCALL
                                      |y|
                                      (VMLISP:QREFELT |$| 16)))
                                  'NIL)
                               ('T 'T)))
                           (GO BOOT::G191)))
                     (SEQ
                        (EXIT
                           (COND
                              ((NULL
                                  (BOOT:SPADCALL
                                     (BOOT:SPADCALL
                                        |x|
                                        (VMLISP:QREFELT |$| 18))
                                     (BOOT:SPADCALL
                                        |y|
                                        (VMLISP:QREFELT |$| 18))
                                     (VMLISP:QREFELT |$| 51)))
                                 (PROGN
                                    (BOOT::LETT
                                       #:G87662
                                       (BOOT:SPADCALL
                                          (BOOT:SPADCALL
                                             |x|
                                             (VMLISP:QREFELT |$| 18))
                                          (BOOT:SPADCALL
                                             |y|
                                             (VMLISP:QREFELT |$| 18))
                                          (VMLISP:QREFELT |$| 63))
                                       BOOT::|LSAGG-;<;2AB;25|)
                                    (GO #:G87662)))
                              ('T
                                 (SEQ
                                    (BOOT::LETT
                                       |x|
                                       (BOOT:SPADCALL
                                          |x|
                                          (VMLISP:QREFELT |$| 17))
                                       BOOT::|LSAGG-;<;2AB;25|)
                                    (EXIT
                                       (BOOT::LETT
                                          |y|
                                          (BOOT:SPADCALL
                                             |y|
                                             (VMLISP:QREFELT |$| 17))
                                          BOOT::|LSAGG-;<;2AB;25|)))) )))
                     NIL
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT NIL))
                  (EXIT
                     (COND
                        ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 16))
                           (COND
                              ((BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 16))
                                 'NIL)
                              ('T 'T)))
                        ('T 'NIL)))) )
            #:G87662
            (EXIT #:G87662)))) )

*/



/* Code for BOOT::|LSAGG-;<;2AB;25| */

static Lisp_Object MS_CDECL CC_BOOT__LSAGGKURU2ABU25(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V361, V362, V363;
    argcheck(nargs, 3, "LSAGG-;<;2AB;25");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|LSAGG-;<;2AB;25|\n");
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

V33:
    V362 = stack[-2];
    V361 = (Lisp_Object)257; /* 16 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    if (!car_legal(V362)) goto V371;
    V363 = qcar(V362);
    V362 = stack[-4];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply2(nil, 3, V363, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    if (!(V361 == nil)) goto V26;
    V362 = stack[-2];
    V361 = (Lisp_Object)257; /* 16 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    if (!car_legal(V362)) goto V371;
    V363 = qcar(V362);
    V362 = stack[-3];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply2(nil, 3, V363, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    if (!(V361 == nil)) goto V26;
    V361 = lisp_true;
    if (V361 == nil) goto V80;
    V361 = lisp_true;
    goto V25;

V25:
    if (V361 == nil) goto V301;
    V362 = stack[-2];
    V361 = (Lisp_Object)817; /* 51 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    stack[-5] = V361;
    V361 = stack[-5];
    if (!car_legal(V361)) goto V373;
    stack[-1] = qcar(V361);
    V362 = stack[-2];
    V361 = (Lisp_Object)289; /* 18 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    if (!car_legal(V362)) goto V371;
    V363 = qcar(V362);
    V362 = stack[-4];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply2(nil, 3, V363, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    stack[0] = V361;
    V362 = stack[-2];
    V361 = (Lisp_Object)289; /* 18 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    if (!car_legal(V362)) goto V371;
    V363 = qcar(V362);
    V362 = stack[-3];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply2(nil, 3, V363, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    V361 = stack[-5];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply3(nil, 4, stack[-1], stack[0], V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    if (V361 == nil) goto V166;
    V361 = lisp_true;
    if (V361 == nil) goto V33;
    V362 = stack[-2];
    V361 = (Lisp_Object)273; /* 17 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    if (!car_legal(V362)) goto V371;
    V363 = qcar(V362);
    V362 = stack[-4];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply2(nil, 3, V363, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    stack[-4] = V361;
    V362 = stack[-2];
    V361 = (Lisp_Object)273; /* 17 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    if (!car_legal(V362)) goto V371;
    V363 = qcar(V362);
    V362 = stack[-3];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply2(nil, 3, V363, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    stack[-3] = V361;
    goto V33;

V166:
    V362 = stack[-2];
    V361 = (Lisp_Object)1009; /* 63 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    stack[-1] = V361;
    V361 = stack[-1];
    if (!car_legal(V361)) goto V373;
    stack[0] = qcar(V361);
    V362 = stack[-2];
    V361 = (Lisp_Object)289; /* 18 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    if (!car_legal(V362)) goto V371;
    V363 = qcar(V362);
    V362 = stack[-4];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply2(nil, 3, V363, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    stack[-4] = V361;
    V362 = stack[-2];
    V361 = (Lisp_Object)289; /* 18 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    if (!car_legal(V362)) goto V371;
    V363 = qcar(V362);
    V362 = stack[-3];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply2(nil, 3, V363, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    V362 = V361;
    V361 = stack[-1];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    {
        Lisp_Object V374 = stack[0];
        Lisp_Object V375 = stack[-4];
        popv(7);
        return Lapply3(nil, 4, V374, V375, V362, V361);
    }

V301:
    V362 = stack[-2];
    V361 = (Lisp_Object)257; /* 16 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    if (!car_legal(V362)) goto V371;
    V363 = qcar(V362);
    V362 = stack[-4];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply2(nil, 3, V363, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    if (V361 == nil) goto V296;
    V362 = stack[-2];
    V361 = (Lisp_Object)257; /* 16 */
    V361 = Lgetv(nil, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    env = stack[-6];
    V362 = V361;
    if (!car_legal(V362)) goto V371;
    V363 = qcar(V362);
    V362 = stack[-3];
    if (!car_legal(V361)) goto V372;
    V361 = qcdr(V361);
    V361 = Lapply2(nil, 3, V363, V362, V361);
    nil = C_nil;
    if (exception_pending()) goto V370;
    if (V361 == nil) goto V324;
    V361 = nil;
    { popv(7); return onevalue(V361); }

V324:
    V361 = lisp_true;
    if (V361 == nil) goto V351;
    V361 = lisp_true;
    { popv(7); return onevalue(V361); }

V351:
    V361 = nil;
    { popv(7); return onevalue(V361); }

V296:
    V361 = lisp_true;
    if (V361 == nil) goto V355;
    V361 = nil;
    { popv(7); return onevalue(V361); }

V355:
    V361 = nil;
    { popv(7); return onevalue(V361); }

V80:
    V361 = nil;
    goto V25;

V26:
    V361 = nil;
    goto V25;
/* error exit handlers */
V373:
    popv(7);
    return error(1, err_bad_car, V361);
V372:
    popv(7);
    return error(1, err_bad_cdr, V361);
V371:
    popv(7);
    return error(1, err_bad_car, V362);
V370:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|isSubDomain| (BOOT::|d1| BOOT::|d2|)
   (PROG (BOOT::|subDomainList| |l|)
      (RETURN
         (PROGN
            (BOOT:SPADLET
               BOOT::|subDomainList|
               '(BOOT:|Integer|
                   BOOT:|NonNegativeInteger|
                   BOOT:|PositiveInteger|))
            (COND
               ((OR (ATOM BOOT::|d1|) (ATOM BOOT::|d2|)) NIL)
               ((BOOT:SPADLET
                   |l|
                   (MEMQ (CAR BOOT::|d2|) BOOT::|subDomainList|))
                  (MEMQ (CAR BOOT::|d1|) (CDR |l|)))
               ('T NIL)))) ))

*/



/* Code for BOOT::|isSubDomain| */

static Lisp_Object CC_BOOT__isSubDomain(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V46, V47, V48, V49;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isSubDomain|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V47 = V3;
    V48 = V2;
/* end of prologue */
    V46 = elt(env, 1); /* (BOOT:|Integer| BOOT:|NonNegativeInteger| BOOT:|PositiveInteger|) */
    V49 = V46;
    V46 = V48;
    if (!consp(V46)) goto V14;
    V46 = V47;
    if (!consp(V46)) goto V14;
    V46 = V47;
    if (!car_legal(V46)) goto V50;
    V46 = qcar(V46);
    V47 = V49;
    V46 = Lmemq(nil, V46, V47);
    V47 = V46;
    if (V46 == nil) goto V22;
    V46 = V48;
    if (!car_legal(V46)) goto V50;
    V46 = qcar(V46);
    if (!car_legal(V47)) goto V51;
    V47 = qcdr(V47);
    V46 = Lmemq(nil, V46, V47);
    return onevalue(V46);

V22:
    V46 = lisp_true;
    if (V46 == nil) goto V43;
    V46 = nil;
    return onevalue(V46);

V43:
    V46 = nil;
    return onevalue(V46);

V14:
    V46 = nil;
    return onevalue(V46);
/* error exit handlers */
V51:
    return error(1, err_bad_cdr, V47);
V50:
    return error(1, err_bad_car, V46);
}

/*
(DEFUN BOOT::|KERNEL;=;2$B;13| (BOOT::|k1| BOOT::|k2| |$|)
   (SEQ
      (COND
         ((EQL (VMLISP:QVELT BOOT::|k1| 3) 0)
            (BOOT:SPADCALL
               BOOT::|k1|
               (CONS (BOOT:|function| BOOT::|KERNEL;triage|) |$|)
               (VMLISP:QREFELT |$| 38))))
      (COND
         ((EQL (VMLISP:QVELT BOOT::|k2| 3) 0)
            (BOOT:SPADCALL
               BOOT::|k2|
               (CONS (BOOT:|function| BOOT::|KERNEL;triage|) |$|)
               (VMLISP:QREFELT |$| 38))))
      (EXIT
         (EQL (VMLISP:QVELT BOOT::|k1| 3) (VMLISP:QVELT BOOT::|k2| 3)))) )

*/



/* Code for BOOT::|KERNEL;=;2$B;13| */

static Lisp_Object MS_CDECL CC_BOOT__KERNELUMU2DBU13(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V139, V140;
    argcheck(nargs, 3, "KERNEL;=;2$B;13");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|KERNEL;=;2$B;13|\n");
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
    V140 = stack[-4];
    V139 = (Lisp_Object)49; /* 3 */
    V140 = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    V139 = (Lisp_Object)1; /* 0 */
    V139 = Leql(nil, V140, V139);
    env = stack[-6];
    if (V139 == nil) goto V74;
    V140 = stack[-2];
    V139 = (Lisp_Object)609; /* 38 */
    V139 = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    stack[-5] = V139;
    V139 = stack[-5];
    if (!car_legal(V139)) goto V148;
    stack[-1] = qcar(V139);
    stack[0] = stack[-4];
    V140 = elt(env, 1); /* BOOT::|KERNEL;triage| */
    V139 = stack[-2];
    V140 = cons(V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    V139 = stack[-5];
    if (!car_legal(V139)) goto V149;
    V139 = qcdr(V139);
    V139 = Lapply3(nil, 4, stack[-1], stack[0], V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    goto V74;

V74:
    V140 = stack[-3];
    V139 = (Lisp_Object)49; /* 3 */
    V140 = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    V139 = (Lisp_Object)1; /* 0 */
    V139 = Leql(nil, V140, V139);
    env = stack[-6];
    if (V139 == nil) goto V123;
    V140 = stack[-2];
    V139 = (Lisp_Object)609; /* 38 */
    V139 = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    stack[-5] = V139;
    V139 = stack[-5];
    if (!car_legal(V139)) goto V148;
    stack[-1] = qcar(V139);
    stack[0] = stack[-3];
    V140 = elt(env, 1); /* BOOT::|KERNEL;triage| */
    V139 = stack[-2];
    V140 = cons(V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    V139 = stack[-5];
    if (!car_legal(V139)) goto V149;
    V139 = qcdr(V139);
    V139 = Lapply3(nil, 4, stack[-1], stack[0], V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    goto V123;

V123:
    V140 = stack[-4];
    V139 = (Lisp_Object)49; /* 3 */
    stack[0] = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    V140 = stack[-3];
    V139 = (Lisp_Object)49; /* 3 */
    V139 = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    {
        Lisp_Object V150 = stack[0];
        popv(7);
        return Leql(nil, V150, V139);
    }
/* error exit handlers */
V149:
    popv(7);
    return error(1, err_bad_cdr, V139);
V148:
    popv(7);
    return error(1, err_bad_car, V139);
V147:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|CDRwithIncrement| (|x|)
   (PROGN (RPLACA |x| (VMLISP:QSADD1 (CAR |x|))) (CDR |x|)))

*/



/* Code for BOOT::|CDRwithIncrement| */

static Lisp_Object CC_BOOT__CDRwithIncrement(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V18;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|CDRwithIncrement|\n");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = V2;
/* end of prologue */
    stack[-1] = stack[0];
    V18 = stack[0];
    if (!car_legal(V18)) goto V21;
    V18 = qcar(V18);
    V18 = add1(V18);
    nil = C_nil;
    if (exception_pending()) goto V22;
    env = stack[-2];
    V18 = Lrplaca(nil, stack[-1], V18);
    nil = C_nil;
    if (exception_pending()) goto V22;
    V18 = stack[0];
    if (!car_legal(V18)) goto V23;
    V18 = qcdr(V18);
    { popv(3); return onevalue(V18); }
/* error exit handlers */
V23:
    popv(3);
    return error(1, err_bad_cdr, V18);
V22:
    popv(3);
    return nil;
V21:
    popv(3);
    return error(1, err_bad_car, V18);
}

/*
(DEFUN BOOT::|lookupInDomainVector| (BOOT::|op|
      BOOT::|sig|
      BOOT::|domain|
      BOOT::|dollar|)
   (PROG (BOOT::|slot1|)
      (RETURN
         (COND
            ((PAIRP BOOT::|domain|)
               (BOOT::|basicLookupCheckDefaults|
                  BOOT::|op|
                  BOOT::|sig|
                  BOOT::|domain|
                  BOOT::|domain|))
            ('T
               (BOOT:SPADLET BOOT::|slot1| (ELT BOOT::|domain| 1))
               (BOOT:SPADCALL
                  BOOT::|op|
                  BOOT::|sig|
                  BOOT::|dollar|
                  BOOT::|slot1|)))) ))

*/



/* Code for BOOT::|lookupInDomainVector| */

static Lisp_Object MS_CDECL CC_BOOT__lookupInDomainVector(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V66, V67, V68, V69, V70;
    Lisp_Object fn;
    argcheck(nargs, 4, "lookupInDomainVector");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|lookupInDomainVector|\n");
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
    V66 = stack[-1];
    fn = elt(env, 1); /* CONSP */
    V66 = (*qfn1(fn))(qenv(fn), V66);
    nil = C_nil;
    if (exception_pending()) goto V75;
    env = stack[-4];
    if (V66 == nil) goto V15;
    V69 = stack[-3];
    V68 = stack[-2];
    V67 = stack[-1];
    V66 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); /* BOOT::|basicLookupCheckDefaults| */
        return (*qfnn(fn))(qenv(fn), 4, V69, V68, V67, V66);
    }

V15:
    V66 = lisp_true;
    if (V66 == nil) goto V33;
    V67 = stack[-1];
    V66 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* ELT */
    V66 = (*qfn2(fn))(qenv(fn), V67, V66);
    nil = C_nil;
    if (exception_pending()) goto V75;
    env = stack[-4];
    V67 = V66;
    if (!car_legal(V67)) goto V76;
    V70 = qcar(V67);
    V69 = stack[-3];
    V68 = stack[-2];
    V67 = stack[0];
    if (!car_legal(V66)) goto V77;
    V66 = qcdr(V66);
    {
        popv(5);
        fn = elt(env, 4); /* FUNCALL* */
        return (*qfnn(fn))(qenv(fn), 5, V70, V69, V68, V67, V66);
    }

V33:
    V66 = nil;
    { popv(5); return onevalue(V66); }
/* error exit handlers */
V77:
    popv(5);
    return error(1, err_bad_cdr, V66);
V76:
    popv(5);
    return error(1, err_bad_car, V67);
V75:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|KERNEL;<;2$B;14| (BOOT::|k1| BOOT::|k2| |$|)
   (SEQ
      (COND
         ((EQL (VMLISP:QVELT BOOT::|k1| 3) 0)
            (BOOT:SPADCALL
               BOOT::|k1|
               (CONS (BOOT:|function| BOOT::|KERNEL;triage|) |$|)
               (VMLISP:QREFELT |$| 38))))
      (COND
         ((EQL (VMLISP:QVELT BOOT::|k2| 3) 0)
            (BOOT:SPADCALL
               BOOT::|k2|
               (CONS (BOOT:|function| BOOT::|KERNEL;triage|) |$|)
               (VMLISP:QREFELT |$| 38))))
      (EXIT
         (|<| (VMLISP:QVELT BOOT::|k1| 3) (VMLISP:QVELT BOOT::|k2| 3)))) )

*/



/* Code for BOOT::|KERNEL;<;2$B;14| */

static Lisp_Object MS_CDECL CC_BOOT__KERNELURU2DBU14(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V139, V140;
    argcheck(nargs, 3, "KERNEL;<;2$B;14");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|KERNEL;<;2$B;14|\n");
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
    V140 = stack[-4];
    V139 = (Lisp_Object)49; /* 3 */
    V140 = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    V139 = (Lisp_Object)1; /* 0 */
    V139 = Leql(nil, V140, V139);
    env = stack[-6];
    if (V139 == nil) goto V74;
    V140 = stack[-2];
    V139 = (Lisp_Object)609; /* 38 */
    V139 = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    stack[-5] = V139;
    V139 = stack[-5];
    if (!car_legal(V139)) goto V148;
    stack[-1] = qcar(V139);
    stack[0] = stack[-4];
    V140 = elt(env, 1); /* BOOT::|KERNEL;triage| */
    V139 = stack[-2];
    V140 = cons(V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    V139 = stack[-5];
    if (!car_legal(V139)) goto V149;
    V139 = qcdr(V139);
    V139 = Lapply3(nil, 4, stack[-1], stack[0], V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    goto V74;

V74:
    V140 = stack[-3];
    V139 = (Lisp_Object)49; /* 3 */
    V140 = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    V139 = (Lisp_Object)1; /* 0 */
    V139 = Leql(nil, V140, V139);
    env = stack[-6];
    if (V139 == nil) goto V123;
    V140 = stack[-2];
    V139 = (Lisp_Object)609; /* 38 */
    V139 = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    stack[-5] = V139;
    V139 = stack[-5];
    if (!car_legal(V139)) goto V148;
    stack[-1] = qcar(V139);
    stack[0] = stack[-3];
    V140 = elt(env, 1); /* BOOT::|KERNEL;triage| */
    V139 = stack[-2];
    V140 = cons(V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    V139 = stack[-5];
    if (!car_legal(V139)) goto V149;
    V139 = qcdr(V139);
    V139 = Lapply3(nil, 4, stack[-1], stack[0], V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    goto V123;

V123:
    V140 = stack[-4];
    V139 = (Lisp_Object)49; /* 3 */
    stack[0] = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-6];
    V140 = stack[-3];
    V139 = (Lisp_Object)49; /* 3 */
    V139 = Lgetv(nil, V140, V139);
    nil = C_nil;
    if (exception_pending()) goto V147;
    {
        Lisp_Object V150 = stack[0];
        popv(7);
        return Llessp(nil, V150, V139);
    }
/* error exit handlers */
V149:
    popv(7);
    return error(1, err_bad_cdr, V139);
V148:
    popv(7);
    return error(1, err_bad_car, V139);
V147:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|FRAC;cancelGcd| (|x| |$|)
   (PROG (|d| BOOT::|xn| BOOT::|xd|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL (QCDR |x|) (VMLISP:QREFELT |$| 14))
                  (QCDR |x|))
               ('T
                  (SEQ
                     (BOOT::LETT
                        |d|
                        (BOOT:SPADCALL
                           (QCAR |x|)
                           (QCDR |x|)
                           (VMLISP:QREFELT |$| 51))
                        BOOT::|FRAC;cancelGcd|)
                     (BOOT::LETT
                        BOOT::|xn|
                        (BOOT:SPADCALL
                           (QCAR |x|)
                           |d|
                           (VMLISP:QREFELT |$| 19))
                        BOOT::|FRAC;cancelGcd|)
                     (EXIT
                        (COND
                           ((BOOT::QEQCAR BOOT::|xn| 1)
                              (BOOT::|error|
                              "gcd not gcd in QF cancelGcd (numerator)"))
                           ('T
                              (SEQ
                                 (BOOT::LETT
                                    BOOT::|xd|
                                    (BOOT:SPADCALL
                                       (QCDR |x|)
                                       |d|
                                       (VMLISP:QREFELT |$| 19))
                                    BOOT::|FRAC;cancelGcd|)
                                 (EXIT
                                    (COND
                                       ((BOOT::QEQCAR BOOT::|xd| 1)
                                          (BOOT::|error|
                              "gcd not gcd in QF cancelGcd (denominator)"))
                                       ('T
                                          (SEQ
                                             (PROGN
                                                (RPLACA
                                                   |x|
                                                   (QCDR BOOT::|xn|))
                                                (QCAR |x|))
                                             (PROGN
                                                (RPLACD
                                                   |x|
                                                   (QCDR BOOT::|xd|))
                                                (QCDR |x|))
                                             (EXIT |d|)))) ))) ))) ))) )))

*/



/* Code for BOOT::|FRAC;cancelGcd| */

static Lisp_Object CC_BOOT__FRACUcancelGcd(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V202, V203, V204, V205;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FRAC;cancelGcd|\n");
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
    V203 = stack[-1];
    V202 = (Lisp_Object)225; /* 14 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V210;
    env = stack[-4];
    V203 = V202;
    if (!car_legal(V203)) goto V211;
    V204 = qcar(V203);
    V203 = stack[-2];
    V203 = qcdr(V203);
    if (!car_legal(V202)) goto V212;
    V202 = qcdr(V202);
    V202 = Lapply2(nil, 3, V204, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V210;
    env = stack[-4];
    if (V202 == nil) goto V17;
    V202 = stack[-2];
    V202 = qcdr(V202);
    { popv(5); return onevalue(V202); }

V17:
    V202 = lisp_true;
    if (V202 == nil) goto V46;
    V203 = stack[-1];
    V202 = (Lisp_Object)817; /* 51 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V210;
    env = stack[-4];
    V203 = V202;
    if (!car_legal(V203)) goto V211;
    V205 = qcar(V203);
    V203 = stack[-2];
    V204 = qcar(V203);
    V203 = stack[-2];
    V203 = qcdr(V203);
    if (!car_legal(V202)) goto V212;
    V202 = qcdr(V202);
    V202 = Lapply3(nil, 4, V205, V204, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V210;
    env = stack[-4];
    stack[-3] = V202;
    V203 = stack[-1];
    V202 = (Lisp_Object)305; /* 19 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V210;
    env = stack[-4];
    V203 = V202;
    if (!car_legal(V203)) goto V211;
    V205 = qcar(V203);
    V203 = stack[-2];
    V204 = qcar(V203);
    V203 = stack[-3];
    if (!car_legal(V202)) goto V212;
    V202 = qcdr(V202);
    V202 = Lapply3(nil, 4, V205, V204, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V210;
    env = stack[-4];
    stack[0] = V202;
    V202 = stack[0];
    V203 = qcar(V202);
    V202 = (Lisp_Object)17; /* 1 */
    V202 = Leql(nil, V203, V202);
    env = stack[-4];
    if (V202 == nil) goto V110;
    V202 = elt(env, 1); /* "gcd not gcd in QF cancelGcd (numerator)" */
    {
        popv(5);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V202);
    }

V110:
    V202 = lisp_true;
    if (V202 == nil) goto V123;
    V203 = stack[-1];
    V202 = (Lisp_Object)305; /* 19 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V210;
    env = stack[-4];
    V203 = V202;
    if (!car_legal(V203)) goto V211;
    V205 = qcar(V203);
    V203 = stack[-2];
    V204 = qcdr(V203);
    V203 = stack[-3];
    if (!car_legal(V202)) goto V212;
    V202 = qcdr(V202);
    V202 = Lapply3(nil, 4, V205, V204, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V210;
    env = stack[-4];
    stack[-1] = V202;
    V202 = stack[-1];
    V203 = qcar(V202);
    V202 = (Lisp_Object)17; /* 1 */
    V202 = Leql(nil, V203, V202);
    env = stack[-4];
    if (V202 == nil) goto V158;
    V202 = elt(env, 2); /* "gcd not gcd in QF cancelGcd (denominator)" */
    {
        popv(5);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V202);
    }

V158:
    V202 = lisp_true;
    if (V202 == nil) goto V171;
    V203 = stack[-2];
    V202 = stack[0];
    V202 = qcdr(V202);
    V202 = Lrplaca(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V210;
    env = stack[-4];
    V203 = stack[-2];
    V202 = stack[-1];
    V202 = qcdr(V202);
    V202 = Lrplacd(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V210;
    { Lisp_Object res = stack[-3]; popv(5); return onevalue(res); }

V171:
    V202 = nil;
    { popv(5); return onevalue(V202); }

V123:
    V202 = nil;
    { popv(5); return onevalue(V202); }

V46:
    V202 = nil;
    { popv(5); return onevalue(V202); }
/* error exit handlers */
V212:
    popv(5);
    return error(1, err_bad_cdr, V202);
V211:
    popv(5);
    return error(1, err_bad_car, V203);
V210:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|KERNEL;triage| (BOOT::|k1| BOOT::|k2| |$|)
   (PROG (BOOT::|n1| BOOT::|n2| BOOT::|func| #:G82747 BOOT::|x2| #:G82750
         BOOT::|x1| #:G82749 #:G82748 #:G82746)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (EXIT
                     (COND
                        ((NULL
                            (EQL
                               (VMLISP:QVELT BOOT::|k1| 2)
                               (VMLISP:QVELT BOOT::|k2| 2)))
                           (BOOT::|KERNEL;B2Z|
                              (|<|
                                 (VMLISP:QVELT BOOT::|k1| 2)
                                 (VMLISP:QVELT BOOT::|k2| 2))
                              |$|))
                        ((NULL
                            (BOOT:SPADCALL
                               (VMLISP:QVELT BOOT::|k1| 0)
                               (VMLISP:QVELT BOOT::|k2| 0)
                               (VMLISP:QREFELT |$| 17)))
                           (BOOT::|KERNEL;B2Z|
                              (BOOT:SPADCALL
                                 (VMLISP:QVELT BOOT::|k1| 0)
                                 (VMLISP:QVELT BOOT::|k2| 0)
                                 (VMLISP:QREFELT |$| 52))
                              |$|))
                        ('T
                           (SEQ
                              (SEQ
                                 (BOOT::LETT
                                    BOOT::|n1|
                                    (LENGTH
                                       (BOOT:SPADCALL
                                          BOOT::|k1|
                                          (VMLISP:QREFELT |$| 24)))
                                    BOOT::|KERNEL;triage|)
                                 (BOOT::LETT
                                    BOOT::|n2|
                                    (LENGTH
                                       (BOOT:SPADCALL
                                          BOOT::|k2|
                                          (VMLISP:QREFELT |$| 24)))
                                    BOOT::|KERNEL;triage|)
                                 (EXIT
                                    (COND
                                       ((NULL (EQL BOOT::|n1| BOOT::|n2|))
                                          (PROGN
                                             (BOOT::LETT
                                                #:G82747
                                                (BOOT::|KERNEL;B2Z|
                                                   (|<|
                                                      BOOT::|n1|
                                                      BOOT::|n2|)
                                                   |$|)
                                                BOOT::|KERNEL;triage|)
                                             (GO #:G82747)))) ))
                              (SEQ
                                 (BOOT::LETT
                                    BOOT::|func|
                                    (BOOT:SPADCALL
                                       (BOOT:SPADCALL
                                          BOOT::|k1|
                                          (VMLISP:QREFELT |$| 12))
                                       "%specialEqual"
                                       (VMLISP:QREFELT |$| 33))
                                    BOOT::|KERNEL;triage|)
                                 (EXIT
                                    (COND
                                       ((BOOT::QEQCAR BOOT::|func| 0)
                                          (COND
                                             ((BOOT:SPADCALL
                                                 BOOT::|k1|
                                                 BOOT::|k2|
                                                 (QCDR BOOT::|func|))
                                                (PROGN
                                                   (BOOT::LETT
                                                      #:G82747
                                                      0
                                                   BOOT::|KERNEL;triage|)
                                                   (GO #:G82747)))) ))) )
                              (SEQ
                                 (EXIT
                                    (SEQ
                                       (BOOT::LETT
                                          BOOT::|x2|
                                          NIL
                                          BOOT::|KERNEL;triage|)
                                       (BOOT::LETT
                                          #:G82750
                                          (BOOT:SPADCALL
                                             BOOT::|k2|
                                             (VMLISP:QREFELT |$| 24))
                                          BOOT::|KERNEL;triage|)
                                       (BOOT::LETT
                                          BOOT::|x1|
                                          NIL
                                          BOOT::|KERNEL;triage|)
                                       (BOOT::LETT
                                          #:G82749
                                          (BOOT:SPADCALL
                                             BOOT::|k1|
                                             (VMLISP:QREFELT |$| 24))
                                          BOOT::|KERNEL;triage|)
                                       BOOT::G190
                                       (COND
                                          ((OR
                                              (ATOM #:G82749)
                                              (PROGN
                                                 (BOOT::LETT
                                                    BOOT::|x1|
                                                    (CAR #:G82749)
                                                    BOOT::|KERNEL;triage|)
                                                 NIL)
                                              (ATOM #:G82750)
                                              (PROGN
                                                 (BOOT::LETT
                                                    BOOT::|x2|
                                                    (CAR #:G82750)
                                                    BOOT::|KERNEL;triage|)
                                                 NIL))
                                             (GO BOOT::G191)))
                                       (SEQ
                                          (EXIT
                                             (COND
                                                ((NULL
                                                    (BOOT:SPADCALL
                                                       BOOT::|x1|
                                                       BOOT::|x2|
        (VMLISP:QREFELT |$| 53)))
                                                   (PROGN
        (BOOT::LETT
        #:G82746
        (PROGN
           (BOOT::LETT
              #:G82748
              (BOOT::|KERNEL;B2Z|
                 (BOOT:SPADCALL
  BOOT::|x1| BOOT::|x2| (VMLISP:QREFELT |$| 54)) |$|) BOOT::|KERNEL;triage|)
           (GO #:G82748)) BOOT::|KERNEL;triage|)
        (GO #:G82746)))) ))
                                       (BOOT::LETT
                                          #:G82749
                                          (PROG1
                                             (CDR #:G82749)
                                             (BOOT::LETT
                                                #:G82750
                                    (CDR #:G82750)
                           BOOT::|KERNEL;triage|))
                                          BOOT::|KERNEL;triage|)
                                       (GO BOOT::G190)
                                       BOOT::G191
                                       (EXIT NIL)))
                                 #:G82746
                                 (EXIT #:G82746))
                              (EXIT 0)))) )
                  #:G82747
                  (EXIT #:G82747)))
            #:G82748
            (EXIT #:G82748)))) )

*/



/* Code for BOOT::|KERNEL;triage| */

static Lisp_Object MS_CDECL CC_BOOT__KERNELUtriage(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V509, V510, V511, V512;
    Lisp_Object fn;
    argcheck(nargs, 3, "KERNEL;triage");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|KERNEL;triage|\n");
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
    V510 = stack[-4];
    V509 = (Lisp_Object)33; /* 2 */
    stack[0] = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = stack[-3];
    V509 = (Lisp_Object)33; /* 2 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V509 = Leql(nil, stack[0], V509);
    env = stack[-6];
    if (V509 == nil) goto V65;
    V510 = stack[-2];
    V509 = (Lisp_Object)273; /* 17 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    stack[-5] = V509;
    V509 = stack[-5];
    if (!car_legal(V509)) goto V520;
    stack[-1] = qcar(V509);
    V510 = stack[-4];
    V509 = (Lisp_Object)1; /* 0 */
    stack[0] = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = stack[-3];
    V509 = (Lisp_Object)1; /* 0 */
    V510 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V509 = stack[-5];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply3(nil, 4, stack[-1], stack[0], V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    if (V509 == nil) goto V134;
    V509 = lisp_true;
    if (V509 == nil) goto V173;
    V510 = stack[-2];
    V509 = (Lisp_Object)385; /* 24 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = V509;
    if (!car_legal(V510)) goto V522;
    V511 = qcar(V510);
    V510 = stack[-4];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply2(nil, 3, V511, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V509 = Llength(nil, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    stack[0] = V509;
    V510 = stack[-2];
    V509 = (Lisp_Object)385; /* 24 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = V509;
    if (!car_legal(V510)) goto V522;
    V511 = qcar(V510);
    V510 = stack[-3];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply2(nil, 3, V511, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V509 = Llength(nil, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V511 = V509;
    V510 = stack[0];
    V509 = V511;
    V509 = Leql(nil, V510, V509);
    env = stack[-6];
    if (V509 == nil) goto V248;
    V510 = stack[-2];
    V509 = (Lisp_Object)529; /* 33 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    stack[-1] = V509;
    V509 = stack[-1];
    if (!car_legal(V509)) goto V520;
    stack[0] = qcar(V509);
    V510 = stack[-2];
    V509 = (Lisp_Object)193; /* 12 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = V509;
    if (!car_legal(V510)) goto V522;
    V511 = qcar(V510);
    V510 = stack[-4];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply2(nil, 3, V511, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V511 = V509;
    V510 = elt(env, 1); /* "%specialEqual" */
    V509 = stack[-1];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply3(nil, 4, stack[0], V511, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V511 = V509;
    V509 = V511;
    V510 = qcar(V509);
    V509 = (Lisp_Object)1; /* 0 */
    V509 = Leql(nil, V510, V509);
    env = stack[-6];
    if (V509 == nil) goto V361;
    V509 = V511;
    V509 = qcdr(V509);
    V510 = V509;
    if (!car_legal(V510)) goto V522;
    V512 = qcar(V510);
    V511 = stack[-4];
    V510 = stack[-3];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply3(nil, 4, V512, V511, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    if (V509 == nil) goto V361;
    V509 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(V509); }

V361:
    V510 = stack[-2];
    V509 = (Lisp_Object)385; /* 24 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = V509;
    if (!car_legal(V510)) goto V522;
    V511 = qcar(V510);
    V510 = stack[-3];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply2(nil, 3, V511, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    stack[-3] = V509;
    V510 = stack[-2];
    V509 = (Lisp_Object)385; /* 24 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = V509;
    if (!car_legal(V510)) goto V522;
    V511 = qcar(V510);
    V510 = stack[-4];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply2(nil, 3, V511, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    stack[0] = V509;
    goto V354;

V354:
    V509 = stack[0];
    if (!consp(V509)) goto V350;
    V509 = stack[0];
    if (!car_legal(V509)) goto V520;
    V509 = qcar(V509);
    stack[-1] = V509;
    V509 = nil;
    if (!(V509 == nil)) goto V350;
    V509 = stack[-3];
    if (!consp(V509)) goto V350;
    V509 = stack[-3];
    if (!car_legal(V509)) goto V520;
    V509 = qcar(V509);
    stack[-4] = V509;
    V509 = nil;
    if (!(V509 == nil)) goto V350;
    V510 = stack[-2];
    V509 = (Lisp_Object)849; /* 53 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = V509;
    if (!car_legal(V510)) goto V522;
    V512 = qcar(V510);
    V511 = stack[-1];
    V510 = stack[-4];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply3(nil, 4, V512, V511, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    if (V509 == nil) goto V465;
    V509 = stack[0];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V510 = V509;
    V509 = stack[-3];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    stack[-3] = V509;
    V509 = V510;
    stack[0] = V509;
    goto V354;

V465:
    V510 = stack[-2];
    V509 = (Lisp_Object)865; /* 54 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = V509;
    if (!car_legal(V510)) goto V522;
    V512 = qcar(V510);
    V511 = stack[-1];
    V510 = stack[-4];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply3(nil, 4, V512, V511, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = V509;
    V509 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* BOOT::|KERNEL;B2Z| */
        return (*qfn2(fn))(qenv(fn), V510, V509);
    }

V350:
    V509 = (Lisp_Object)1; /* 0 */
    { popv(7); return onevalue(V509); }

V248:
    V509 = stack[0];
    V510 = V511;
    V510 = (Lisp_Object)lessp2(V509, V510);
    nil = C_nil;
    if (exception_pending()) goto V519;
    V510 = V510 ? lisp_true : nil;
    env = stack[-6];
    V509 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* BOOT::|KERNEL;B2Z| */
        return (*qfn2(fn))(qenv(fn), V510, V509);
    }

V173:
    V509 = nil;
    { popv(7); return onevalue(V509); }

V134:
    V510 = stack[-2];
    V509 = (Lisp_Object)833; /* 52 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    stack[-1] = V509;
    V509 = stack[-1];
    if (!car_legal(V509)) goto V520;
    stack[0] = qcar(V509);
    V510 = stack[-4];
    V509 = (Lisp_Object)1; /* 0 */
    stack[-4] = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = stack[-3];
    V509 = (Lisp_Object)1; /* 0 */
    V510 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V509 = stack[-1];
    if (!car_legal(V509)) goto V521;
    V509 = qcdr(V509);
    V509 = Lapply3(nil, 4, stack[0], stack[-4], V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = V509;
    V509 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* BOOT::|KERNEL;B2Z| */
        return (*qfn2(fn))(qenv(fn), V510, V509);
    }

V65:
    V510 = stack[-4];
    V509 = (Lisp_Object)33; /* 2 */
    stack[0] = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = stack[-3];
    V509 = (Lisp_Object)33; /* 2 */
    V509 = Lgetv(nil, V510, V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-6];
    V510 = (Lisp_Object)lessp2(stack[0], V509);
    nil = C_nil;
    if (exception_pending()) goto V519;
    V510 = V510 ? lisp_true : nil;
    env = stack[-6];
    V509 = stack[-2];
    {
        popv(7);
        fn = elt(env, 2); /* BOOT::|KERNEL;B2Z| */
        return (*qfn2(fn))(qenv(fn), V510, V509);
    }
/* error exit handlers */
V522:
    popv(7);
    return error(1, err_bad_car, V510);
V521:
    popv(7);
    return error(1, err_bad_cdr, V509);
V520:
    popv(7);
    return error(1, err_bad_car, V509);
V519:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|isPartialMode| (|m|) (CONTAINED BOOT:|$EmptyMode| |m|))

*/



/* Code for BOOT::|isPartialMode| */

static Lisp_Object CC_BOOT__isPartialMode(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V14, V15;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isPartialMode|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V14 = V2;
/* end of prologue */
    V15 = qvalue(elt(env, 1)); /* BOOT::|$EmptyMode| */
    {
        fn = elt(env, 2); /* CONTAINED */
        return (*qfn2(fn))(qenv(fn), V15, V14);
    }
}

/*
(DEFUN BOOT::|ILIST;mergeSort| (|f| |p| |n| |$|)
   (PROG (#:G102089 |l| |q|)
      (RETURN
         (SEQ
            (COND
               ((EQL |n| 2)
                  (COND
                     ((BOOT:SPADCALL
                         (BOOT:SPADCALL
                            (BOOT:SPADCALL |p| (VMLISP:QREFELT |$| 18))
                            (VMLISP:QREFELT |$| 13))
                         (BOOT:SPADCALL |p| (VMLISP:QREFELT |$| 13))
                         |f|)
                        (BOOT::LETT
                           |p|
                           (BOOT:SPADCALL |p| (VMLISP:QREFELT |$| 28))
                           BOOT::|ILIST;mergeSort|)))) )
            (EXIT
               (COND
                  ((|<| |n| 3) |p|)
                  ('T
                     (SEQ
                        (BOOT::LETT
                           |l|
                           (PROG1
                              (BOOT::LETT
                                 #:G102089
                                 (BOOT::QUOTIENT2 |n| 2)
                                 BOOT::|ILIST;mergeSort|)
                              (BOOT::|check-subtype|
                                 (|>=| #:G102089 0)
                                 '(BOOT:|NonNegativeInteger|)
                                 #:G102089))
                           BOOT::|ILIST;mergeSort|)
                        (BOOT::LETT
                           |q|
                           (BOOT:SPADCALL |p| |l| (VMLISP:QREFELT |$| 57))
                           BOOT::|ILIST;mergeSort|)
                        (BOOT::LETT
                           |p|
                           (BOOT::|ILIST;mergeSort| |f| |p| |l| |$|)
                           BOOT::|ILIST;mergeSort|)
                        (BOOT::LETT
                           |q|
                           (BOOT::|ILIST;mergeSort|
                              |f|
                              |q|
                              (|-| |n| |l|)
                              |$|)
                           BOOT::|ILIST;mergeSort|)
                        (EXIT
                           (BOOT:SPADCALL
                              |f|
                              |p|
                              |q|
                              (VMLISP:QREFELT |$| 56)))) ))) ))) )

*/



/* Code for BOOT::|ILIST;mergeSort| */

static Lisp_Object MS_CDECL CC_BOOT__ILISTUmergeSort(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V292, V293, V294, V295, V296;
    Lisp_Object fn;
    argcheck(nargs, 4, "ILIST;mergeSort");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;mergeSort|\n");
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
    stack[-3] = V5;
    stack[-4] = V4;
    stack[-5] = V3;
    stack[-6] = V2;
/* end of prologue */
    V293 = stack[-4];
    V292 = (Lisp_Object)33; /* 2 */
    V292 = Leql(nil, V293, V292);
    env = stack[-8];
    if (V292 == nil) goto V150;
    V292 = stack[-6];
    stack[-7] = V292;
    V292 = stack[-7];
    if (!car_legal(V292)) goto V305;
    stack[-2] = qcar(V292);
    V293 = stack[-3];
    V292 = (Lisp_Object)209; /* 13 */
    V292 = Lgetv(nil, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    stack[-1] = V292;
    V292 = stack[-1];
    if (!car_legal(V292)) goto V305;
    stack[0] = qcar(V292);
    V293 = stack[-3];
    V292 = (Lisp_Object)289; /* 18 */
    V292 = Lgetv(nil, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    V293 = V292;
    if (!car_legal(V293)) goto V307;
    V294 = qcar(V293);
    V293 = stack[-5];
    if (!car_legal(V292)) goto V308;
    V292 = qcdr(V292);
    V292 = Lapply2(nil, 3, V294, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    V293 = V292;
    V292 = stack[-1];
    if (!car_legal(V292)) goto V308;
    V292 = qcdr(V292);
    V292 = Lapply2(nil, 3, stack[0], V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    stack[0] = V292;
    V293 = stack[-3];
    V292 = (Lisp_Object)209; /* 13 */
    V292 = Lgetv(nil, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    V293 = V292;
    if (!car_legal(V293)) goto V307;
    V294 = qcar(V293);
    V293 = stack[-5];
    if (!car_legal(V292)) goto V308;
    V292 = qcdr(V292);
    V292 = Lapply2(nil, 3, V294, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    V293 = V292;
    V292 = stack[-7];
    if (!car_legal(V292)) goto V308;
    V292 = qcdr(V292);
    V292 = Lapply3(nil, 4, stack[-2], stack[0], V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    if (V292 == nil) goto V150;
    V293 = stack[-3];
    V292 = (Lisp_Object)449; /* 28 */
    V292 = Lgetv(nil, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    V293 = V292;
    if (!car_legal(V293)) goto V307;
    V294 = qcar(V293);
    V293 = stack[-5];
    if (!car_legal(V292)) goto V308;
    V292 = qcdr(V292);
    V292 = Lapply2(nil, 3, V294, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    stack[-5] = V292;
    goto V150;

V150:
    V293 = stack[-4];
    V292 = (Lisp_Object)49; /* 3 */
    V292 = (Lisp_Object)lessp2(V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    V292 = V292 ? lisp_true : nil;
    env = stack[-8];
    if (!(V292 == nil)) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    V292 = lisp_true;
    if (V292 == nil) goto V159;
    V293 = stack[-4];
    V292 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 2); /* BOOT::QUOTIENT2 */
    V292 = (*qfn2(fn))(qenv(fn), V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    stack[-1] = V292;
    stack[0] = V292;
    V293 = stack[-1];
    V292 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 3); /* >= */
    V292 = (*qfn2(fn))(qenv(fn), V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    if (!(V292 == nil)) goto V176;
    V293 = stack[-1];
    V292 = elt(env, 1); /* (BOOT:|NonNegativeInteger|) */
    fn = elt(env, 4); /* BOOT::COERCE-FAILURE-MSG */
    V292 = (*qfn2(fn))(qenv(fn), V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    fn = elt(env, 5); /* BOOT::|error| */
    V292 = (*qfn1(fn))(qenv(fn), V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    goto V176;

V176:
    V292 = stack[0];
    stack[-2] = V292;
    V293 = stack[-3];
    V292 = (Lisp_Object)913; /* 57 */
    V292 = Lgetv(nil, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    V293 = V292;
    if (!car_legal(V293)) goto V307;
    V295 = qcar(V293);
    V294 = stack[-5];
    V293 = stack[-2];
    if (!car_legal(V292)) goto V308;
    V292 = qcdr(V292);
    V292 = Lapply3(nil, 4, V295, V294, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    stack[0] = V292;
    V295 = stack[-6];
    V294 = stack[-5];
    V293 = stack[-2];
    V292 = stack[-3];
    V292 = CC_BOOT__ILISTUmergeSort(env, 4, V295, V294, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    stack[-5] = V292;
    stack[-1] = stack[-6];
    V293 = stack[-4];
    V292 = stack[-2];
    V293 = difference2(V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    V292 = stack[-3];
    V292 = CC_BOOT__ILISTUmergeSort(env, 4, stack[-1], stack[0], V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    stack[0] = V292;
    V293 = stack[-3];
    V292 = (Lisp_Object)897; /* 56 */
    V292 = Lgetv(nil, V293, V292);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-8];
    V293 = V292;
    if (!car_legal(V293)) goto V307;
    V296 = qcar(V293);
    V295 = stack[-6];
    V294 = stack[-5];
    V293 = stack[0];
    if (!car_legal(V292)) goto V308;
    V292 = qcdr(V292);
    {
        popv(9);
        fn = elt(env, 6); /* FUNCALL* */
        return (*qfnn(fn))(qenv(fn), 5, V296, V295, V294, V293, V292);
    }

V159:
    V292 = nil;
    { popv(9); return onevalue(V292); }
/* error exit handlers */
V308:
    popv(9);
    return error(1, err_bad_cdr, V292);
V307:
    popv(9);
    return error(1, err_bad_car, V293);
V306:
    popv(9);
    return nil;
V305:
    popv(9);
    return error(1, err_bad_car, V292);
}

/*
(DEFUN BOOT::|getDomainByteVector| (BOOT::|dom|)
   (CDDR (ELT BOOT::|dom| 4)))

*/



/* Code for BOOT::|getDomainByteVector| */

static Lisp_Object CC_BOOT__getDomainByteVector(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V16, V17;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|getDomainByteVector|\n");
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
/* copy arguments values to proper place */
    V16 = V2;
/* end of prologue */
    V17 = V16;
    V16 = (Lisp_Object)65; /* 4 */
    fn = elt(env, 1); /* ELT */
    V16 = (*qfn2(fn))(qenv(fn), V17, V16);
    errexit();
    if (!car_legal(V16)) goto V18;
    V16 = qcdr(V16);
    if (!car_legal(V16)) goto V18;
    V16 = qcdr(V16);
    return onevalue(V16);
/* error exit handlers */
V18:
    return error(1, err_bad_cdr, V16);
}

/*
(DEFUN BOOT::|isFunctor| (|x|)
   (PROG (BOOT::|op| |u| BOOT::|prop|)
      (RETURN
         (PROGN
            (BOOT:SPADLET BOOT::|op| (BOOT::|opOf| |x|))
            (COND
               ((NULL (VMLISP:IDENTP BOOT::|op|)) NIL)
               (BOOT:|$InteractiveMode|
                  (COND
                     ((MEMQ
                         BOOT::|op|
                         '(BOOT::|Union|
                             BOOT::|SubDomain|
                             BOOT::|Mapping|
                             BOOT::|Record|))
                        'T)
                     ('T
                        (MEMQ
                           (BOOT::GETDATABASE
                              BOOT::|op|
                              'BOOT::CONSTRUCTORKIND)
                           '(BOOT::|domain| BOOT::|package|)))) )
               ((BOOT:SPADLET
                   |u|
                   (OR
                      (BOOT::|get|
                         BOOT::|op|
                         'BOOT::|isFunctor|
                         BOOT:|$CategoryFrame|)
                      (MEMQ
                         BOOT::|op|
                         '(BOOT::|SubDomain|
                             BOOT::|Union|
                             BOOT::|Record|))))
                  |u|)
               ((BOOT::|constructor?| BOOT::|op|)
                  (COND
                     ((BOOT:SPADLET
                         BOOT::|prop|
                         (BOOT::|get|
                            BOOT::|op|
                            'BOOT::|isFunctor|
                            BOOT:|$CategoryFrame|))
                        BOOT::|prop|)
                     ('T
                        (COND
                           ((BOOT:|BOOT-EQUAL|
                               (BOOT::GETDATABASE
                                  BOOT::|op|
                                  'BOOT::CONSTRUCTORKIND)
                               'BOOT::|category|)
                              (BOOT::|updateCategoryFrameForCategory|
                                 BOOT::|op|))
                           ('T
                              (BOOT::|updateCategoryFrameForConstructor|
                                 BOOT::|op|)))
                        (BOOT::|get|
                           BOOT::|op|
                           'BOOT::|isFunctor|
                           BOOT:|$CategoryFrame|))))
               ('T NIL)))) ))

*/



/* Code for BOOT::|isFunctor| */

static Lisp_Object CC_BOOT__isFunctor(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V151, V152, V153;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isFunctor|\n");
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
    V151 = V2;
/* end of prologue */
    fn = elt(env, 8); /* BOOT::|opOf| */
    V151 = (*qfn1(fn))(qenv(fn), V151);
    nil = C_nil;
    if (exception_pending()) goto V155;
    env = stack[-1];
    stack[0] = V151;
    V151 = stack[0];
    if (V151 == nil) goto V19;
    V151 = stack[0];
    fn = elt(env, 9); /* SYMBOLP */
    V151 = (*qfn1(fn))(qenv(fn), V151);
    nil = C_nil;
    if (exception_pending()) goto V155;
    env = stack[-1];
    goto V18;

V18:
    if (V151 == nil) goto V15;
    V151 = qvalue(elt(env, 1)); /* BOOT::|$InteractiveMode| */
    if (V151 == nil) goto V68;
    V152 = stack[0];
    V151 = elt(env, 2); /* (BOOT::|Union| BOOT::|SubDomain| BOOT::|Mapping| BOOT::|Record|) */
    V151 = Lmemq(nil, V152, V151);
    if (V151 == nil) goto V34;
    V151 = lisp_true;
    { popv(2); return onevalue(V151); }

V34:
    V151 = lisp_true;
    if (V151 == nil) goto V45;
    V152 = stack[0];
    V151 = elt(env, 3); /* BOOT::CONSTRUCTORKIND */
    fn = elt(env, 10); /* BOOT::GETDATABASE */
    V151 = (*qfn2(fn))(qenv(fn), V152, V151);
    nil = C_nil;
    if (exception_pending()) goto V155;
    env = stack[-1];
    V152 = elt(env, 4); /* (BOOT::|domain| BOOT::|package|) */
    V151 = Lmemq(nil, V151, V152);
    { popv(2); return onevalue(V151); }

V45:
    V151 = nil;
    { popv(2); return onevalue(V151); }

V68:
    V153 = stack[0];
    V152 = elt(env, 0); /* BOOT::|isFunctor| */
    V151 = qvalue(elt(env, 5)); /* BOOT::|$CategoryFrame| */
    fn = elt(env, 11); /* BOOT::|get| */
    V151 = (*qfnn(fn))(qenv(fn), 3, V153, V152, V151);
    nil = C_nil;
    if (exception_pending()) goto V155;
    env = stack[-1];
    if (!(V151 == nil)) goto V65;
    V152 = stack[0];
    V151 = elt(env, 6); /* (BOOT::|SubDomain| BOOT::|Union| BOOT::|Record|) */
    V151 = Lmemq(nil, V152, V151);
    goto V65;

V65:
    V152 = V151;
    if (!(V151 == nil)) { popv(2); return onevalue(V152); }
    V151 = stack[0];
    fn = elt(env, 12); /* BOOT::|constructor?| */
    V151 = (*qfn1(fn))(qenv(fn), V151);
    nil = C_nil;
    if (exception_pending()) goto V155;
    env = stack[-1];
    if (V151 == nil) goto V88;
    V153 = stack[0];
    V152 = elt(env, 0); /* BOOT::|isFunctor| */
    V151 = qvalue(elt(env, 5)); /* BOOT::|$CategoryFrame| */
    fn = elt(env, 11); /* BOOT::|get| */
    V151 = (*qfnn(fn))(qenv(fn), 3, V153, V152, V151);
    nil = C_nil;
    if (exception_pending()) goto V155;
    env = stack[-1];
    V152 = V151;
    if (!(V151 == nil)) { popv(2); return onevalue(V152); }
    V151 = lisp_true;
    if (V151 == nil) goto V108;
    V152 = stack[0];
    V151 = elt(env, 3); /* BOOT::CONSTRUCTORKIND */
    fn = elt(env, 10); /* BOOT::GETDATABASE */
    V152 = (*qfn2(fn))(qenv(fn), V152, V151);
    nil = C_nil;
    if (exception_pending()) goto V155;
    env = stack[-1];
    V151 = elt(env, 7); /* BOOT::|category| */
    V151 = (V152 == V151 ? lisp_true : nil);
    if (V151 == nil) goto V113;
    V151 = stack[0];
    fn = elt(env, 13); /* BOOT::|updateCategoryFrameForCategory| */
    V151 = (*qfn1(fn))(qenv(fn), V151);
    nil = C_nil;
    if (exception_pending()) goto V155;
    env = stack[-1];
    goto V137;

V137:
    V153 = stack[0];
    V152 = elt(env, 0); /* BOOT::|isFunctor| */
    V151 = qvalue(elt(env, 5)); /* BOOT::|$CategoryFrame| */
    {
        popv(2);
        fn = elt(env, 11); /* BOOT::|get| */
        return (*qfnn(fn))(qenv(fn), 3, V153, V152, V151);
    }

V113:
    V151 = lisp_true;
    if (V151 == nil) goto V137;
    V151 = stack[0];
    fn = elt(env, 14); /* BOOT::|updateCategoryFrameForConstructor| */
    V151 = (*qfn1(fn))(qenv(fn), V151);
    nil = C_nil;
    if (exception_pending()) goto V155;
    env = stack[-1];
    goto V137;

V108:
    V151 = nil;
    { popv(2); return onevalue(V151); }

V88:
    V151 = lisp_true;
    if (V151 == nil) goto V148;
    V151 = nil;
    { popv(2); return onevalue(V151); }

V148:
    V151 = nil;
    { popv(2); return onevalue(V151); }

V15:
    V151 = nil;
    { popv(2); return onevalue(V151); }

V19:
    V151 = nil;
    goto V18;
/* error exit handlers */
V155:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|SMP;leadingCoefficient;$R;77| (|p| |$|)
   (COND
      ((BOOT::QEQCAR |p| 0) (QCDR |p|))
      ('T
         (BOOT:SPADCALL
            (BOOT:SPADCALL (QCDR (QCDR |p|)) (VMLISP:QREFELT |$| 22))
            (VMLISP:QREFELT |$| 37)))) )

*/



/* Code for BOOT::|SMP;leadingCoefficient;$R;77| */

static Lisp_Object CC_BOOT__SMPUleadingCoefficientUDRU77(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V74, V75, V76;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;leadingCoefficient;$R;77|\n");
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
    V74 = stack[-2];
    V75 = qcar(V74);
    V74 = (Lisp_Object)1; /* 0 */
    V74 = Leql(nil, V75, V74);
    env = stack[-4];
    if (V74 == nil) goto V10;
    V74 = stack[-2];
    V74 = qcdr(V74);
    { popv(5); return onevalue(V74); }

V10:
    V74 = lisp_true;
    if (V74 == nil) goto V23;
    V75 = stack[-1];
    V74 = (Lisp_Object)593; /* 37 */
    V74 = Lgetv(nil, V75, V74);
    nil = C_nil;
    if (exception_pending()) goto V81;
    env = stack[-4];
    stack[-3] = V74;
    V74 = stack[-3];
    if (!car_legal(V74)) goto V82;
    stack[0] = qcar(V74);
    V75 = stack[-1];
    V74 = (Lisp_Object)353; /* 22 */
    V74 = Lgetv(nil, V75, V74);
    nil = C_nil;
    if (exception_pending()) goto V81;
    env = stack[-4];
    V75 = V74;
    if (!car_legal(V75)) goto V83;
    V76 = qcar(V75);
    V75 = stack[-2];
    V75 = qcdr(V75);
    V75 = qcdr(V75);
    if (!car_legal(V74)) goto V84;
    V74 = qcdr(V74);
    V74 = Lapply2(nil, 3, V76, V75, V74);
    nil = C_nil;
    if (exception_pending()) goto V81;
    V75 = V74;
    V74 = stack[-3];
    if (!car_legal(V74)) goto V84;
    V74 = qcdr(V74);
    {
        Lisp_Object V85 = stack[0];
        popv(5);
        return Lapply2(nil, 3, V85, V75, V74);
    }

V23:
    V74 = nil;
    { popv(5); return onevalue(V74); }
/* error exit handlers */
V84:
    popv(5);
    return error(1, err_bad_cdr, V74);
V83:
    popv(5);
    return error(1, err_bad_car, V75);
V82:
    popv(5);
    return error(1, err_bad_car, V74);
V81:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|EXPR;commonk| (|x| |y| |$|)
   (BOOT::|EXPR;commonk0|
      (BOOT::|EXPR;algkernels|
         (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 47))
         |$|)
      (BOOT::|EXPR;algkernels|
         (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 47))
         |$|)
      |$|))

*/



/* Code for BOOT::|EXPR;commonk| */

static Lisp_Object MS_CDECL CC_BOOT__EXPRUcommonk(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V79, V80, V81;
    Lisp_Object fn;
    argcheck(nargs, 3, "EXPR;commonk");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;commonk|\n");
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
    V80 = stack[0];
    V79 = (Lisp_Object)753; /* 47 */
    V79 = Lgetv(nil, V80, V79);
    nil = C_nil;
    if (exception_pending()) goto V85;
    env = stack[-3];
    V80 = V79;
    if (!car_legal(V80)) goto V86;
    V81 = qcar(V80);
    V80 = stack[-2];
    if (!car_legal(V79)) goto V87;
    V79 = qcdr(V79);
    V79 = Lapply2(nil, 3, V81, V80, V79);
    nil = C_nil;
    if (exception_pending()) goto V85;
    env = stack[-3];
    V80 = V79;
    V79 = stack[0];
    fn = elt(env, 1); /* BOOT::|EXPR;algkernels| */
    stack[-2] = (*qfn2(fn))(qenv(fn), V80, V79);
    nil = C_nil;
    if (exception_pending()) goto V85;
    env = stack[-3];
    V80 = stack[0];
    V79 = (Lisp_Object)753; /* 47 */
    V79 = Lgetv(nil, V80, V79);
    nil = C_nil;
    if (exception_pending()) goto V85;
    env = stack[-3];
    V80 = V79;
    if (!car_legal(V80)) goto V86;
    V81 = qcar(V80);
    V80 = stack[-1];
    if (!car_legal(V79)) goto V87;
    V79 = qcdr(V79);
    V79 = Lapply2(nil, 3, V81, V80, V79);
    nil = C_nil;
    if (exception_pending()) goto V85;
    env = stack[-3];
    V80 = V79;
    V79 = stack[0];
    fn = elt(env, 1); /* BOOT::|EXPR;algkernels| */
    V80 = (*qfn2(fn))(qenv(fn), V80, V79);
    nil = C_nil;
    if (exception_pending()) goto V85;
    env = stack[-3];
    V79 = stack[0];
    {
        Lisp_Object V88 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* BOOT::|EXPR;commonk0| */
        return (*qfnn(fn))(qenv(fn), 3, V88, V80, V79);
    }
/* error exit handlers */
V87:
    popv(4);
    return error(1, err_bad_cdr, V79);
V86:
    popv(4);
    return error(1, err_bad_car, V80);
V85:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|SMP;retract;$R;59| (|p| |$|)
   (COND
      ((BOOT::QEQCAR |p| 0) (QCDR |p|))
      ('T (BOOT::|error| "cannot retract nonconstant polynomial"))))

*/



/* Code for BOOT::|SMP;retract;$R;59| */

static Lisp_Object CC_BOOT__SMPUretractUDRU59(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V27, V28, V29;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;retract;$R;59|\n");
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
/* copy arguments values to proper place */
    V27 = V3;
    V28 = V2;
/* end of prologue */
    V27 = V28;
    V29 = qcar(V27);
    V27 = (Lisp_Object)1; /* 0 */
    V27 = Leql(nil, V29, V27);
    env = stack[0];
    if (V27 == nil) goto V10;
    V27 = V28;
    V27 = qcdr(V27);
    { popv(1); return onevalue(V27); }

V10:
    V27 = lisp_true;
    if (V27 == nil) goto V23;
    V27 = elt(env, 1); /* "cannot retract nonconstant polynomial" */
    {
        popv(1);
        fn = elt(env, 2); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V27);
    }

V23:
    V27 = nil;
    { popv(1); return onevalue(V27); }
}

/*
(DEFUN BOOT::|IDPAM;monomial;AS$;6| (|r| |s| |$|)
   (COND
      ((BOOT:SPADCALL
          |r|
          (BOOT::|spadConstant| |$| 18)
          (VMLISP:QREFELT |$| 21))
         (BOOT::|spadConstant| |$| 10))
      ('T (LIST (CONS |s| |r|)))) )

*/



/* Code for BOOT::|IDPAM;monomial;AS$;6| */

static Lisp_Object MS_CDECL CC_BOOT__IDPAMUmonomialUASDU6(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V92, V93;
    argcheck(nargs, 3, "IDPAM;monomial;AS$;6");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IDPAM;monomial;AS$;6|\n");
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
    V93 = stack[-2];
    V92 = (Lisp_Object)337; /* 21 */
    V92 = Lgetv(nil, V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V100;
    env = stack[-6];
    stack[-5] = V92;
    V92 = stack[-5];
    if (!car_legal(V92)) goto V101;
    stack[-1] = qcar(V92);
    stack[0] = stack[-4];
    V93 = stack[-2];
    V92 = (Lisp_Object)289; /* 18 */
    V92 = Lgetv(nil, V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V100;
    env = stack[-6];
    V93 = V92;
    if (!car_legal(V93)) goto V102;
    V93 = qcar(V93);
    if (!car_legal(V92)) goto V103;
    V92 = qcdr(V92);
    V92 = Lapply1(nil, V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V100;
    env = stack[-6];
    V93 = V92;
    V92 = stack[-5];
    if (!car_legal(V92)) goto V103;
    V92 = qcdr(V92);
    V92 = Lapply3(nil, 4, stack[-1], stack[0], V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V100;
    env = stack[-6];
    if (V92 == nil) goto V11;
    V93 = stack[-2];
    V92 = (Lisp_Object)161; /* 10 */
    V92 = Lgetv(nil, V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V100;
    V93 = V92;
    if (!car_legal(V93)) goto V102;
    V93 = qcar(V93);
    if (!car_legal(V92)) goto V103;
    V92 = qcdr(V92);
        popv(7);
        return Lapply1(nil, V93, V92);

V11:
    V92 = lisp_true;
    if (V92 == nil) goto V81;
    V93 = stack[-3];
    V92 = stack[-4];
    V92 = cons(V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V100;
    popv(7);
    { Lisp_Object retVal = ncons(V92);
    errexit();
    return onevalue(retVal); }

V81:
    V92 = nil;
    { popv(7); return onevalue(V92); }
/* error exit handlers */
V103:
    popv(7);
    return error(1, err_bad_cdr, V92);
V102:
    popv(7);
    return error(1, err_bad_car, V93);
V101:
    popv(7);
    return error(1, err_bad_car, V92);
V100:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|PRIMARR;fill!;$S$;9| (|x| |s| |$|)
   (PROG (|i| #:G82338)
      (RETURN
         (SEQ
            (SEQ
               (BOOT::LETT |i| 0 BOOT::|PRIMARR;fill!;$S$;9|)
               (BOOT::LETT
                  #:G82338
                  (VMLISP:QVMAXINDEX |x|)
                  BOOT::|PRIMARR;fill!;$S$;9|)
               BOOT::G190
               (COND ((VMLISP:QSGREATERP |i| #:G82338) (GO BOOT::G191)))
               (SEQ (EXIT (SETELT |x| |i| |s|)))
               (BOOT::LETT
                  |i|
                  (VMLISP:QSADD1 |i|)
                  BOOT::|PRIMARR;fill!;$S$;9|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT |x|)))) )

*/



/* Code for BOOT::|PRIMARR;fill!;$S$;9| */

static Lisp_Object MS_CDECL CC_BOOT__PRIMARRUfillBUDSDU9(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V54, V55, V56;
    Lisp_Object fn;
    argcheck(nargs, 3, "PRIMARR;fill!;$S$;9");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PRIMARR;fill!;$S$;9|\n");
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
(DEFUN BOOT::|IFARRAY;maxIndex;$I;6| (|r| |$|)
   (|+| (|-| (VMLISP:QVELT |r| 1) 1) (VMLISP:QREFELT |$| 7)))

*/



/* Code for BOOT::|IFARRAY;maxIndex;$I;6| */

static Lisp_Object CC_BOOT__IFARRAYUmaxIndexUDIU6(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V30, V31;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;maxIndex;$I;6|\n");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = V3;
    V30 = V2;
/* end of prologue */
    V31 = V30;
    V30 = (Lisp_Object)17; /* 1 */
    V30 = Lgetv(nil, V31, V30);
    nil = C_nil;
    if (exception_pending()) goto V34;
    env = stack[-2];
    stack[-1] = sub1(V30);
    nil = C_nil;
    if (exception_pending()) goto V34;
    env = stack[-2];
    V31 = stack[0];
    V30 = (Lisp_Object)113; /* 7 */
    V30 = Lgetv(nil, V31, V30);
    nil = C_nil;
    if (exception_pending()) goto V34;
    {
        Lisp_Object V35 = stack[-1];
        popv(3);
        { Lisp_Object retVal = plus2(V35, V30);
        errexit();
        return onevalue(retVal); }
    }
/* error exit handlers */
V34:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|lookupComplete| (BOOT::|op|
      BOOT::|sig|
      BOOT::|dollar|
      BOOT::|env|)
   (COND
      ((BOOT::|hashCode?| BOOT::|sig|)
         (BOOT::|hashNewLookupInTable|
            BOOT::|op|
            BOOT::|sig|
            BOOT::|dollar|
            BOOT::|env|
            NIL))
      ('T
         (BOOT::|newLookupInTable|
            BOOT::|op|
            BOOT::|sig|
            BOOT::|dollar|
            BOOT::|env|
            NIL))))

*/



/* Code for BOOT::|lookupComplete| */

static Lisp_Object MS_CDECL CC_BOOT__lookupComplete(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V52, V53, V54, V55, V56;
    Lisp_Object fn;
    argcheck(nargs, 4, "lookupComplete");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|lookupComplete|\n");
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
    V52 = stack[-2];
    fn = elt(env, 1); /* BOOT::|hashCode?| */
    V52 = (*qfn1(fn))(qenv(fn), V52);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-4];
    if (V52 == nil) goto V12;
    V56 = stack[-3];
    V55 = stack[-2];
    V54 = stack[-1];
    V53 = stack[0];
    V52 = nil;
    {
        popv(5);
        fn = elt(env, 2); /* BOOT::|hashNewLookupInTable| */
        return (*qfnn(fn))(qenv(fn), 5, V56, V55, V54, V53, V52);
    }

V12:
    V52 = lisp_true;
    if (V52 == nil) goto V33;
    V56 = stack[-3];
    V55 = stack[-2];
    V54 = stack[-1];
    V53 = stack[0];
    V52 = nil;
    {
        popv(5);
        fn = elt(env, 3); /* BOOT::|newLookupInTable| */
        return (*qfnn(fn))(qenv(fn), 5, V56, V55, V54, V53, V52);
    }

V33:
    V52 = nil;
    { popv(5); return onevalue(V52); }
/* error exit handlers */
V61:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|FRAC;one?;$B;28| (|x| |$|)
   (COND
      ((BOOT:SPADCALL (QCAR |x|) (VMLISP:QREFELT |$| 14))
         (BOOT:SPADCALL (QCDR |x|) (VMLISP:QREFELT |$| 14)))
      ('T 'NIL)))

*/



/* Code for BOOT::|FRAC;one?;$B;28| */

static Lisp_Object CC_BOOT__FRACUoneWUDBU28(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V65, V66, V67;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FRAC;one?;$B;28|\n");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V66 = stack[0];
    V65 = (Lisp_Object)225; /* 14 */
    V65 = Lgetv(nil, V66, V65);
    nil = C_nil;
    if (exception_pending()) goto V70;
    env = stack[-2];
    V66 = V65;
    if (!car_legal(V66)) goto V71;
    V67 = qcar(V66);
    V66 = stack[-1];
    V66 = qcar(V66);
    if (!car_legal(V65)) goto V72;
    V65 = qcdr(V65);
    V65 = Lapply2(nil, 3, V67, V66, V65);
    nil = C_nil;
    if (exception_pending()) goto V70;
    env = stack[-2];
    if (V65 == nil) goto V10;
    V66 = stack[0];
    V65 = (Lisp_Object)225; /* 14 */
    V65 = Lgetv(nil, V66, V65);
    nil = C_nil;
    if (exception_pending()) goto V70;
    V66 = V65;
    if (!car_legal(V66)) goto V71;
    V67 = qcar(V66);
    V66 = stack[-1];
    V66 = qcdr(V66);
    if (!car_legal(V65)) goto V72;
    V65 = qcdr(V65);
        popv(3);
        return Lapply2(nil, 3, V67, V66, V65);

V10:
    V65 = lisp_true;
    if (V65 == nil) goto V62;
    V65 = nil;
    { popv(3); return onevalue(V65); }

V62:
    V65 = nil;
    { popv(3); return onevalue(V65); }
/* error exit handlers */
V72:
    popv(3);
    return error(1, err_bad_cdr, V65);
V71:
    popv(3);
    return error(1, err_bad_car, V66);
V70:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|getSystemModemaps| (BOOT::|op| BOOT::|nargs|)
   (PROG (BOOT::|mml| BOOT::|sig| BOOT::|mms|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADLET
                   BOOT::|mml|
                   (BOOT::GETDATABASE BOOT::|op| 'BOOT::OPERATION))
                  (BOOT:SPADLET BOOT::|mms| NIL)
                  (DO ((#:G18928 BOOT::|mml| (CDR #:G18928)) (|x| NIL))
                     ((OR
                         (ATOM #:G18928)
                         (PROGN (SETQ |x| (CAR #:G18928)) NIL)
                         (PROGN
                            (PROGN
                               (BOOT:SPADLET BOOT::|sig| (CDAR |x|))
                               |x|)
                            NIL))
                        NIL)
                     (SEQ
                        (EXIT
                           (COND
                              ((AND
                                  (NUMBERP BOOT::|nargs|)
                                  (BOOT:NEQUAL
                                     BOOT::|nargs|
                                     (|#| (QCDR BOOT::|sig|))))
                                 'BOOT::|iterate|)
                              ((OR
                                  BOOT::|$getUnexposedOperations|
                                  (BOOT::|isFreeFunctionFromMm| |x|)
                                  (BOOT::|isExposedConstructor|
                                     (BOOT::|getDomainFromMm| |x|)))
                                 (BOOT:SPADLET
                                    BOOT::|mms|
                                    (CONS |x| BOOT::|mms|)))
                              ('T 'BOOT::|iterate|)))) )
                  BOOT::|mms|)
               ('T NIL)))) ))

*/



/* Code for BOOT::|getSystemModemaps| */

static Lisp_Object CC_BOOT__getSystemModemaps(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V110, V111;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|getSystemModemaps|\n");
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
/* copy arguments values to proper place */
    stack[-3] = V3;
    V110 = V2;
/* end of prologue */
    V111 = V110;
    V110 = elt(env, 1); /* BOOT::OPERATION */
    fn = elt(env, 4); /* BOOT::GETDATABASE */
    V110 = (*qfn2(fn))(qenv(fn), V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V117;
    env = stack[-5];
    V111 = V110;
    if (V110 == nil) goto V17;
    V110 = nil;
    stack[-4] = V110;
    V110 = V111;
    stack[-1] = V110;
    goto V33;

V33:
    V110 = stack[-1];
    if (!consp(V110)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    V110 = stack[-1];
    if (!car_legal(V110)) goto V118;
    V110 = qcar(V110);
    stack[-2] = V110;
    V110 = nil;
    if (!(V110 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    V110 = stack[-2];
    if (!car_legal(V110)) goto V118;
    V110 = qcar(V110);
    if (!car_legal(V110)) goto V119;
    V110 = qcdr(V110);
    V111 = V110;
    V110 = nil;
    if (!(V110 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    V110 = stack[-3];
    if (!(is_number(V110))) goto V57;
    stack[0] = stack[-3];
    V110 = V111;
    V110 = qcdr(V110);
    fn = elt(env, 5); /* VMLISP:SIZE */
    V110 = (*qfn1(fn))(qenv(fn), V110);
    nil = C_nil;
    if (exception_pending()) goto V117;
    env = stack[-5];
    V110 = (cl_equal(stack[0], V110) ? lisp_true : nil);
    V110 = (V110 == nil ? lisp_true : nil);
    if (!(V110 == nil)) goto V53;

V57:
    V110 = qvalue(elt(env, 3)); /* BOOT::|$getUnexposedOperations| */
    if (!(V110 == nil)) goto V85;
    V110 = stack[-2];
    fn = elt(env, 6); /* BOOT::|isFreeFunctionFromMm| */
    V110 = (*qfn1(fn))(qenv(fn), V110);
    nil = C_nil;
    if (exception_pending()) goto V117;
    env = stack[-5];
    if (!(V110 == nil)) goto V85;
    V110 = stack[-2];
    fn = elt(env, 7); /* BOOT::|getDomainFromMm| */
    V110 = (*qfn1(fn))(qenv(fn), V110);
    nil = C_nil;
    if (exception_pending()) goto V117;
    env = stack[-5];
    fn = elt(env, 8); /* BOOT::|isExposedConstructor| */
    V110 = (*qfn1(fn))(qenv(fn), V110);
    nil = C_nil;
    if (exception_pending()) goto V117;
    env = stack[-5];
    if (!(V110 == nil)) goto V85;
    V110 = lisp_true;
    if (!(V110 == nil)) goto V53;

V53:
    V110 = stack[-1];
    if (!car_legal(V110)) goto V119;
    V110 = qcdr(V110);
    stack[-1] = V110;
    goto V33;

V85:
    V111 = stack[-2];
    V110 = stack[-4];
    V110 = cons(V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V117;
    env = stack[-5];
    stack[-4] = V110;
    goto V53;

V17:
    V110 = lisp_true;
    if (V110 == nil) goto V106;
    V110 = nil;
    { popv(6); return onevalue(V110); }

V106:
    V110 = nil;
    { popv(6); return onevalue(V110); }
/* error exit handlers */
V119:
    popv(6);
    return error(1, err_bad_cdr, V110);
V118:
    popv(6);
    return error(1, err_bad_car, V110);
V117:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|stuffSlot| (BOOT::|dollar| |i| BOOT::|item|)
   (PROG (|n| BOOT::|op| BOOT::|ISTMP#1| BOOT::|ISTMP#2| BOOT::|ISTMP#3|
         BOOT::|ISTMP#4| |a| BOOT::|ISTMP#5| |b|)
      (RETURN
         (SETELT
            BOOT::|dollar|
            |i|
            (COND
               ((ATOM BOOT::|item|)
                  (CONS (|SYMBOL-FUNCTION| BOOT::|item|) BOOT::|dollar|))
               ((AND
                   (PAIRP BOOT::|item|)
                   (PROGN
                      (BOOT:SPADLET |n| (QCAR BOOT::|item|))
                      (BOOT:SPADLET BOOT::|op| (QCDR BOOT::|item|))
                      'T)
                   (INTEGERP |n|))
                  (CONS
                     'BOOT::|newGoGet|
                     (CONS BOOT::|dollar| BOOT::|item|)))
               ((AND
                   (PAIRP BOOT::|item|)
                   (EQ (QCAR BOOT::|item|) 'CONS)
                   (PROGN
                      (BOOT:SPADLET BOOT::|ISTMP#1| (QCDR BOOT::|item|))
                      (AND
                         (PAIRP BOOT::|ISTMP#1|)
                         (PROGN
                            (BOOT:SPADLET
                               BOOT::|ISTMP#2|
                               (QCDR BOOT::|ISTMP#1|))
                            (AND
                               (PAIRP BOOT::|ISTMP#2|)
                               (EQ (QCDR BOOT::|ISTMP#2|) NIL)
                               (PROGN
                                  (BOOT:SPADLET
                                     BOOT::|ISTMP#3|
                                     (QCAR BOOT::|ISTMP#2|))
                                  (AND
                                     (PAIRP BOOT::|ISTMP#3|)
                                     (EQ (QCAR BOOT::|ISTMP#3|) 'FUNCALL)
                                     (PROGN
                                        (BOOT:SPADLET
                                           BOOT::|ISTMP#4|
                                           (QCDR BOOT::|ISTMP#3|))
                                        (AND
                                           (PAIRP BOOT::|ISTMP#4|)
                                           (PROGN
                                              (BOOT:SPADLET
                                                 |a|
                                                 (QCAR BOOT::|ISTMP#4|))
                                              (BOOT:SPADLET
                                                 BOOT::|ISTMP#5|
                                                 (QCDR BOOT::|ISTMP#4|))
                                              (AND
                                                 (PAIRP BOOT::|ISTMP#5|)
                                                 (EQ
                                                    (QCDR BOOT::|ISTMP#5|)
                                                    NIL)
                                                 (PROGN
                                                    (BOOT:SPADLET
                                                       |b|
        (QCAR BOOT::|ISTMP#5|))
                                                    'T)))) ))) ))) ))
                  (COND
                     ((BOOT:|BOOT-EQUAL| |b| '|$|)
                        (CONS
                           'BOOT::|makeSpadConstant|
                           (CONS
                              (BOOT::|eval| |a|)
                              (CONS BOOT::|dollar| (CONS |i| NIL)))) )
                     ('T
                        (BOOT:|sayBrightlyNT|
                           (VMLISP:MAKESTRING
                              "Unexpected constant environment!!"))
                        (BOOT:|pp| (BOOT::|devaluate| |b|))
                        NIL)))
               ('T BOOT::|item|)))) ))

*/



/* Code for BOOT::|stuffSlot| */

static Lisp_Object MS_CDECL CC_BOOT__stuffSlot(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V223, V224, V225;
    Lisp_Object fn;
    argcheck(nargs, 3, "stuffSlot");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|stuffSlot|\n");
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
    stack[-7] = nil;
    stack[-2] = nil;
    stack[-1] = stack[-6];
    stack[0] = stack[-5];
    V223 = stack[-4];
    if (!consp(V223)) goto V35;
    V223 = stack[-4];
    fn = elt(env, 7); /* CONSP */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    if (V223 == nil) goto V44;
    V223 = stack[-4];
    V223 = qcar(V223);
    V224 = V223;
    V223 = lisp_true;
    if (V223 == nil) goto V44;
    V223 = V224;
    V223 = Lintegerp(nil, V223);
    env = stack[-8];
    if (V223 == nil) goto V44;
    V225 = elt(env, 1); /* BOOT::|newGoGet| */
    V224 = stack[-6];
    V223 = stack[-4];
    V223 = list2star(V225, V224, V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    goto V25;

V25:
    {
        Lisp_Object V235 = stack[-1];
        Lisp_Object V236 = stack[0];
        popv(9);
        fn = elt(env, 8); /* SETELT */
        return (*qfnn(fn))(qenv(fn), 3, V235, V236, V223);
    }

V44:
    V223 = stack[-4];
    fn = elt(env, 7); /* CONSP */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    if (V223 == nil) goto V69;
    V223 = stack[-4];
    V224 = qcar(V223);
    V223 = elt(env, 2); /* CONS */
    if (!(V224 == V223)) goto V69;
    V223 = stack[-4];
    V223 = qcdr(V223);
    stack[-3] = V223;
    V223 = stack[-3];
    fn = elt(env, 7); /* CONSP */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    if (V223 == nil) goto V87;
    V223 = stack[-3];
    V223 = qcdr(V223);
    stack[-3] = V223;
    V223 = stack[-3];
    fn = elt(env, 7); /* CONSP */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    if (V223 == nil) goto V98;
    V223 = stack[-3];
    V223 = qcdr(V223);
    if (V223 == nil) goto V108;
    V223 = nil;
    goto V86;

V86:
    if (V223 == nil) goto V69;
    V224 = stack[-2];
    V223 = elt(env, 4); /* BOOT::$ */
    V223 = Leql(nil, V224, V223);
    env = stack[-8];
    if (!(V223 == nil)) goto V169;
    stack[-3] = stack[-2];
    V223 = elt(env, 4); /* BOOT::$ */
    fn = elt(env, 9); /* CHARACTER */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    V223 = Leql(nil, stack[-3], V223);
    env = stack[-8];
    goto V169;

V169:
    if (V223 == nil) goto V167;
    stack[-2] = elt(env, 5); /* BOOT::|makeSpadConstant| */
    V223 = stack[-7];
    fn = elt(env, 10); /* BOOT::|eval| */
    stack[-3] = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    V225 = stack[-6];
    V224 = stack[-5];
    V223 = nil;
    V223 = list2star(V225, V224, V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    V223 = list2star(stack[-2], stack[-3], V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    goto V25;

V167:
    V223 = lisp_true;
    if (V223 == nil) goto V211;
    V223 = elt(env, 6); /* "Unexpected constant environment!!" */
    fn = elt(env, 11); /* BOOT:|sayBrightlyNT| */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    V223 = stack[-2];
    fn = elt(env, 12); /* BOOT::|devaluate| */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    fn = elt(env, 13); /* BOOT:|pp| */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    V223 = nil;
    goto V25;

V211:
    V223 = nil;
    goto V25;

V69:
    V223 = lisp_true;
    if (V223 == nil) goto V220;
    V223 = stack[-4];
    goto V25;

V220:
    V223 = nil;
    goto V25;

V108:
    V223 = stack[-3];
    V223 = qcar(V223);
    stack[-3] = V223;
    V223 = stack[-3];
    fn = elt(env, 7); /* CONSP */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    if (V223 == nil) goto V114;
    V223 = stack[-3];
    V224 = qcar(V223);
    V223 = elt(env, 3); /* FUNCALL */
    if (V224 == V223) goto V130;
    V223 = nil;
    goto V86;

V130:
    V223 = stack[-3];
    V223 = qcdr(V223);
    stack[-3] = V223;
    V223 = stack[-3];
    fn = elt(env, 7); /* CONSP */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    if (V223 == nil) goto V136;
    V223 = stack[-3];
    V223 = qcar(V223);
    stack[-7] = V223;
    V223 = stack[-3];
    V223 = qcdr(V223);
    stack[-3] = V223;
    V223 = stack[-3];
    fn = elt(env, 7); /* CONSP */
    V223 = (*qfn1(fn))(qenv(fn), V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    if (V223 == nil) goto V149;
    V223 = stack[-3];
    V223 = qcdr(V223);
    if (V223 == nil) goto V159;
    V223 = nil;
    goto V86;

V159:
    V223 = stack[-3];
    V223 = qcar(V223);
    stack[-2] = V223;
    V223 = lisp_true;
    goto V86;

V149:
    V223 = nil;
    goto V86;

V136:
    V223 = nil;
    goto V86;

V114:
    V223 = nil;
    goto V86;

V98:
    V223 = nil;
    goto V86;

V87:
    V223 = nil;
    goto V86;

V35:
    V223 = stack[-4];
    V224 = Lsymbol_function(nil, V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    V223 = stack[-6];
    V223 = cons(V224, V223);
    nil = C_nil;
    if (exception_pending()) goto V234;
    env = stack[-8];
    goto V25;
/* error exit handlers */
V234:
    popv(9);
    return nil;
}



setup_type const u05_setup[] =
{
    {"BOOT@@evalMmDom@@Builtin",CC_BOOT__evalMmDom,too_many_1, wrong_no_1},
    {"LISP@@QUOTIENT@@Builtin", too_few_2,      CC_LISP__QUOTIENT,wrong_no_2},
    {"BOOT@@FAMR-;coefficients;SL;6@@Builtin",too_few_2,CC_BOOT__FAMRKUcoefficientsUSLU6,wrong_no_2},
    {"BOOT@@LSAGG-;select!;M2A;5@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__LSAGGKUselectBUM2AU5},
    {"BOOT@@LSAGG-;<;2AB;25@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__LSAGGKURU2ABU25},
    {"BOOT@@isSubDomain@@Builtin",too_few_2,    CC_BOOT__isSubDomain,wrong_no_2},
    {"BOOT@@KERNEL;=;2$B;13@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__KERNELUMU2DBU13},
    {"BOOT@@CDRwithIncrement@@Builtin",CC_BOOT__CDRwithIncrement,too_many_1,wrong_no_1},
    {"BOOT@@lookupInDomainVector@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__lookupInDomainVector},
    {"BOOT@@KERNEL;<;2$B;14@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__KERNELURU2DBU14},
    {"BOOT@@FRAC;cancelGcd@@Builtin",too_few_2, CC_BOOT__FRACUcancelGcd,wrong_no_2},
    {"BOOT@@KERNEL;triage@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__KERNELUtriage},
    {"BOOT@@isPartialMode@@Builtin",CC_BOOT__isPartialMode,too_many_1,wrong_no_1},
    {"BOOT@@ILIST;mergeSort@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__ILISTUmergeSort},
    {"BOOT@@getDomainByteVector@@Builtin",CC_BOOT__getDomainByteVector,too_many_1,wrong_no_1},
    {"BOOT@@isFunctor@@Builtin",CC_BOOT__isFunctor,too_many_1, wrong_no_1},
    {"BOOT@@SMP;leadingCoefficient;$R;77@@Builtin",too_few_2,CC_BOOT__SMPUleadingCoefficientUDRU77,wrong_no_2},
    {"BOOT@@EXPR;commonk@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__EXPRUcommonk},
    {"BOOT@@SMP;retract;$R;59@@Builtin",too_few_2,CC_BOOT__SMPUretractUDRU59,wrong_no_2},
    {"BOOT@@IDPAM;monomial;AS$;6@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IDPAMUmonomialUASDU6},
    {"BOOT@@PRIMARR;fill!;$S$;9@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__PRIMARRUfillBUDSDU9},
    {"BOOT@@IFARRAY;maxIndex;$I;6@@Builtin",too_few_2,CC_BOOT__IFARRAYUmaxIndexUDIU6,wrong_no_2},
    {"BOOT@@lookupComplete@@Builtin",wrong_no_na,wrong_no_nb,  (n_args *)CC_BOOT__lookupComplete},
    {"BOOT@@FRAC;one?;$B;28@@Builtin",too_few_2,CC_BOOT__FRACUoneWUDBU28,wrong_no_2},
    {"BOOT@@getSystemModemaps@@Builtin",too_few_2,CC_BOOT__getSystemModemaps,wrong_no_2},
    {"BOOT@@stuffSlot@@Builtin",wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__stuffSlot},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
