
/* u03.c                 Machine generated C code */

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
(DEFUN BOOT::|PERMGRP;testIdentity| (|p| |$|)
   (PROG (|i| #:G82428 #:G82427 #:G82425)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (SEQ
                     (EXIT
                        (SEQ
                           (BOOT::LETT |i| 1 BOOT::|PERMGRP;testIdentity|)
                           (BOOT::LETT
                              #:G82428
                              (VMLISP:QREFELT |$| 11)
                              BOOT::|PERMGRP;testIdentity|)
                           BOOT::G190
                           (COND
                              ((VMLISP:QSGREATERP |i| #:G82428)
                                 (GO BOOT::G191)))
                           (SEQ
                              (EXIT
                                 (COND
                                    ((NULL
                                        (EQL
                                           (BOOT:SPADCALL
                                              |p|
                                              |i|
                                              (VMLISP:QREFELT |$| 39))
                                           |i|))
                                       (PROGN
                                          (BOOT::LETT
                                             #:G82425
                                             (PROGN
                                                (BOOT::LETT
                                                   #:G82427
                                                   'NIL
                                             BOOT::|PERMGRP;testIdentity|)
                                                (GO #:G82427))
                                             BOOT::|PERMGRP;testIdentity|)
                                          (GO #:G82425)))) ))
                           (BOOT::LETT
                              |i|
                              (VMLISP:QSADD1 |i|)
                              BOOT::|PERMGRP;testIdentity|)
                           (GO BOOT::G190)
                           BOOT::G191
                           (EXIT NIL)))
                     #:G82425
                     (EXIT #:G82425))
                  (EXIT 'T)))
            #:G82427
            (EXIT #:G82427)))) )

*/



/* Code for BOOT::|PERMGRP;testIdentity| */

static Lisp_Object CC_BOOT__PERMGRPUtestIdentity(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V98, V99, V100, V101;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PERMGRP;testIdentity|\n");
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
    V98 = (Lisp_Object)17; /* 1 */
    stack[-3] = V98;
    V99 = stack[-1];
    V98 = (Lisp_Object)177; /* 11 */
    V98 = Lgetv(nil, V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V106;
    env = stack[-4];
    stack[0] = V98;
    goto V39;

V39:
    V99 = stack[-3];
    V98 = stack[0];
    V98 = (Lisp_Object)greaterp2(V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V106;
    V98 = V98 ? lisp_true : nil;
    env = stack[-4];
    if (V98 == nil) goto V62;
    V98 = lisp_true;
    { popv(5); return onevalue(V98); }

V62:
    V99 = stack[-1];
    V98 = (Lisp_Object)625; /* 39 */
    V98 = Lgetv(nil, V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V106;
    env = stack[-4];
    V99 = V98;
    if (!car_legal(V99)) goto V107;
    V101 = qcar(V99);
    V100 = stack[-2];
    V99 = stack[-3];
    if (!car_legal(V98)) goto V108;
    V98 = qcdr(V98);
    V98 = Lapply3(nil, 4, V101, V100, V99, V98);
    nil = C_nil;
    if (exception_pending()) goto V106;
    env = stack[-4];
    V99 = V98;
    V98 = stack[-3];
    V98 = Leql(nil, V99, V98);
    env = stack[-4];
    if (V98 == nil) goto V50;
    V98 = stack[-3];
    V98 = add1(V98);
    nil = C_nil;
    if (exception_pending()) goto V106;
    env = stack[-4];
    stack[-3] = V98;
    goto V39;

V50:
    V98 = nil;
    { popv(5); return onevalue(V98); }
/* error exit handlers */
V108:
    popv(5);
    return error(1, err_bad_cdr, V98);
V107:
    popv(5);
    return error(1, err_bad_car, V99);
V106:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|STAGG-;elt;AIS;5| (|x| |i| |$|)
   (PROG (#:G87056)
      (RETURN
         (SEQ
            (BOOT::LETT
               |i|
               (|-| |i| (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 20)))
               BOOT::|STAGG-;elt;AIS;5|)
            (COND
               ((OR
                   (|<| |i| 0)
                   (BOOT:SPADCALL
                      (BOOT::LETT
                         |x|
                         (BOOT:SPADCALL
                            |x|
                            (PROG1
                               (BOOT::LETT
                                  #:G87056
                                  |i|
                                  BOOT::|STAGG-;elt;AIS;5|)
                               (BOOT::|check-subtype|
                                  (|>=| #:G87056 0)
                                  '(BOOT:|NonNegativeInteger|)
                                  #:G87056))
                            (VMLISP:QREFELT |$| 21))
                         BOOT::|STAGG-;elt;AIS;5|)
                      (VMLISP:QREFELT |$| 17)))
                  (EXIT (BOOT::|error| "index out of range"))))
            (EXIT (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 18)))) )))

*/



/* Code for BOOT::|STAGG-;elt;AIS;5| */

static Lisp_Object MS_CDECL CC_BOOT__STAGGKUeltUAISU5(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V162, V163, V164;
    Lisp_Object fn;
    argcheck(nargs, 3, "STAGG-;elt;AIS;5");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STAGG-;elt;AIS;5|\n");
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
    stack[-6] = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V163 = stack[-6];
    V162 = (Lisp_Object)321; /* 20 */
    V162 = Lgetv(nil, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-8];
    V163 = V162;
    if (!car_legal(V163)) goto V174;
    V164 = qcar(V163);
    V163 = stack[-1];
    if (!car_legal(V162)) goto V175;
    V162 = qcdr(V162);
    V162 = Lapply2(nil, 3, V164, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-8];
    V162 = difference2(stack[0], V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-8];
    stack[0] = V162;
    V163 = stack[0];
    V162 = (Lisp_Object)1; /* 0 */
    V162 = (Lisp_Object)lessp2(V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    V162 = V162 ? lisp_true : nil;
    env = stack[-8];
    if (!(V162 == nil)) goto V46;
    V163 = stack[-6];
    V162 = (Lisp_Object)273; /* 17 */
    V162 = Lgetv(nil, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-8];
    stack[-5] = V162;
    V162 = stack[-5];
    if (!car_legal(V162)) goto V176;
    stack[-4] = qcar(V162);
    V163 = stack[-6];
    V162 = (Lisp_Object)337; /* 21 */
    V162 = Lgetv(nil, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-8];
    stack[-3] = V162;
    V162 = stack[-3];
    if (!car_legal(V162)) goto V176;
    stack[-2] = qcar(V162);
    V162 = stack[0];
    stack[-7] = V162;
    stack[0] = V162;
    V163 = stack[-7];
    V162 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 3); /* >= */
    V162 = (*qfn2(fn))(qenv(fn), V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-8];
    if (!(V162 == nil)) goto V109;
    V163 = stack[-7];
    V162 = elt(env, 1); /* (BOOT:|NonNegativeInteger|) */
    fn = elt(env, 4); /* BOOT::COERCE-FAILURE-MSG */
    V162 = (*qfn2(fn))(qenv(fn), V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-8];
    fn = elt(env, 5); /* BOOT::|error| */
    V162 = (*qfn1(fn))(qenv(fn), V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-8];
    goto V109;

V109:
    V162 = stack[0];
    V163 = V162;
    V162 = stack[-3];
    if (!car_legal(V162)) goto V175;
    V162 = qcdr(V162);
    V162 = Lapply3(nil, 4, stack[-2], stack[-1], V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-8];
    V163 = V162;
    stack[-1] = V163;
    V162 = stack[-5];
    if (!car_legal(V162)) goto V175;
    V162 = qcdr(V162);
    V162 = Lapply2(nil, 3, stack[-4], V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    env = stack[-8];
    if (!(V162 == nil)) goto V46;
    V163 = stack[-6];
    V162 = (Lisp_Object)289; /* 18 */
    V162 = Lgetv(nil, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V173;
    V163 = V162;
    if (!car_legal(V163)) goto V174;
    V164 = qcar(V163);
    V163 = stack[-1];
    if (!car_legal(V162)) goto V175;
    V162 = qcdr(V162);
        popv(9);
        return Lapply2(nil, 3, V164, V163, V162);

V46:
    V162 = elt(env, 2); /* "index out of range" */
    {
        popv(9);
        fn = elt(env, 5); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V162);
    }
/* error exit handlers */
V176:
    popv(9);
    return error(1, err_bad_car, V162);
V175:
    popv(9);
    return error(1, err_bad_cdr, V162);
V174:
    popv(9);
    return error(1, err_bad_car, V163);
V173:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|PRIMARR;#;$Nni;1| (|x| |$|) (VMLISP:QVSIZE |x|))

*/



/* Code for BOOT::|PRIMARR;#;$Nni;1| */

static Lisp_Object CC_BOOT__PRIMARRUZUDNniU1(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V9, V10;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PRIMARR;#;$Nni;1|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V9 = V3;
    V10 = V2;
/* end of prologue */
    V9 = V10;
        return Llength(nil, V9);
}

/*
(DEFUN BOOT::|termMatch| (BOOT::|tp| |t| BOOT::SL BOOT::|vars|)
   (PROG (|p| BOOT::|tp1| BOOT::|tp2| BOOT::|t1| BOOT::|t2|)
      (RETURN
         (COND
            ((BOOT:|BOOT-EQUAL| BOOT::|tp| |t|) BOOT::SL)
            ((ATOM BOOT::|tp|)
               (COND
                  ((MEMQ BOOT::|tp| BOOT::|vars|)
                     (COND
                        ((BOOT:SPADLET
                            |p|
                            (VMLISP:|assoc| BOOT::|tp| BOOT::SL))
                           (BOOT:|BOOT-EQUAL| (CDR |p|) |t|))
                        ('T (CONS (CONS BOOT::|tp| |t|) BOOT::SL))))
                  ('T 'BOOT::|failed|)))
            ((ATOM |t|) 'BOOT::|failed|)
            ('T
               (BOOT:SPADLET BOOT::|tp1| (CAR BOOT::|tp|))
               (BOOT:SPADLET BOOT::|tp2| (CDR BOOT::|tp|))
               (BOOT:SPADLET BOOT::|t1| (CAR |t|))
               (BOOT:SPADLET BOOT::|t2| (CDR |t|))
               (BOOT:SPADLET
                  BOOT::SL
                  (BOOT::|termMatch|
                     BOOT::|tp1|
                     BOOT::|t1|
                     BOOT::SL
                     BOOT::|vars|))
               (COND
                  ((BOOT:|BOOT-EQUAL| BOOT::SL 'BOOT::|failed|)
                     'BOOT::|failed|)
                  ((AND BOOT::|tp2| BOOT::|t2|)
                     (BOOT::|termMatch|
                        BOOT::|tp2|
                        BOOT::|t2|
                        BOOT::SL
                        BOOT::|vars|))
                  ((OR BOOT::|tp2| BOOT::|t2|) 'BOOT::|failed|)
                  ('T BOOT::SL)))) )))

*/



/* Code for BOOT::|termMatch| */

static Lisp_Object MS_CDECL CC_BOOT__termMatch(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V156, V157, V158, V159;
    Lisp_Object fn;
    argcheck(nargs, 4, "termMatch");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|termMatch|\n");
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

V20:
    V157 = stack[-3];
    V156 = stack[-2];
    V156 = (cl_equal(V157, V156) ? lisp_true : nil);
    if (!(V156 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    V156 = stack[-3];
    if (!consp(V156)) goto V36;
    V156 = stack[-2];
    if (!consp(V156)) goto V83;
    V156 = lisp_true;
    if (V156 == nil) goto V88;
    V156 = stack[-3];
    if (!car_legal(V156)) goto V164;
    V156 = qcar(V156);
    V158 = V156;
    V156 = stack[-3];
    if (!car_legal(V156)) goto V165;
    V156 = qcdr(V156);
    stack[-3] = V156;
    V156 = stack[-2];
    if (!car_legal(V156)) goto V164;
    V156 = qcar(V156);
    V157 = V156;
    V156 = stack[-2];
    if (!car_legal(V156)) goto V165;
    V156 = qcdr(V156);
    stack[-2] = V156;
    V159 = V158;
    V158 = V157;
    V157 = stack[-1];
    V156 = stack[0];
    V156 = CC_BOOT__termMatch(env, 4, V159, V158, V157, V156);
    nil = C_nil;
    if (exception_pending()) goto V166;
    env = stack[-4];
    stack[-1] = V156;
    V157 = stack[-1];
    V156 = elt(env, 1); /* BOOT::|failed| */
    V156 = (V157 == V156 ? lisp_true : nil);
    if (V156 == nil) goto V115;
    V156 = elt(env, 1); /* BOOT::|failed| */
    { popv(5); return onevalue(V156); }

V115:
    V156 = stack[-3];
    if (V156 == nil) goto V126;
    V156 = stack[-2];
    if (V156 == nil) goto V126;
    V159 = stack[-3];
    V158 = stack[-2];
    V157 = stack[-1];
    V156 = stack[0];
    stack[-3] = V159;
    stack[-2] = V158;
    stack[-1] = V157;
    stack[0] = V156;
    goto V20;

V126:
    V156 = stack[-3];
    if (!(V156 == nil)) goto V145;
    V156 = stack[-2];
    if (!(V156 == nil)) goto V145;
    V156 = lisp_true;
    if (!(V156 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    V156 = nil;
    { popv(5); return onevalue(V156); }

V145:
    V156 = elt(env, 1); /* BOOT::|failed| */
    { popv(5); return onevalue(V156); }

V88:
    V156 = nil;
    { popv(5); return onevalue(V156); }

V83:
    V156 = elt(env, 1); /* BOOT::|failed| */
    { popv(5); return onevalue(V156); }

V36:
    V157 = stack[-3];
    V156 = stack[0];
    V156 = Lmemq(nil, V157, V156);
    if (V156 == nil) goto V35;
    V157 = stack[-3];
    V156 = stack[-1];
    fn = elt(env, 2); /* ASSOC** */
    V156 = (*qfn2(fn))(qenv(fn), V157, V156);
    nil = C_nil;
    if (exception_pending()) goto V166;
    V157 = V156;
    if (V156 == nil) goto V47;
    V156 = V157;
    if (!car_legal(V156)) goto V165;
    V157 = qcdr(V156);
    V156 = stack[-2];
    V156 = (cl_equal(V157, V156) ? lisp_true : nil);
    { popv(5); return onevalue(V156); }

V47:
    V156 = lisp_true;
    if (V156 == nil) goto V66;
    V158 = stack[-3];
    V157 = stack[-2];
    V156 = stack[-1];
    popv(5);
    { Lisp_Object retVal = acons(V158, V157, V156);
    errexit();
    return onevalue(retVal); }

V66:
    V156 = nil;
    { popv(5); return onevalue(V156); }

V35:
    V156 = lisp_true;
    if (V156 == nil) goto V80;
    V156 = elt(env, 1); /* BOOT::|failed| */
    { popv(5); return onevalue(V156); }

V80:
    V156 = nil;
    { popv(5); return onevalue(V156); }
/* error exit handlers */
V166:
    popv(5);
    return nil;
V165:
    popv(5);
    return error(1, err_bad_cdr, V156);
V164:
    popv(5);
    return error(1, err_bad_car, V156);
}

/*
(DEFUN BOOT::|IFARRAY;elt;$IS;17| (|r| |i| |$|)
   (COND
      ((OR
          (|<| |i| (VMLISP:QREFELT |$| 7))
          (NULL
             (|<| |i| (|+| (VMLISP:QVELT |r| 1) (VMLISP:QREFELT |$| 7)))) )
         (BOOT::|error| "index out of range"))
      ('T (ELT (VMLISP:QVELT |r| 2) (|-| |i| (VMLISP:QREFELT |$| 7)))) ))

*/



/* Code for BOOT::|IFARRAY;elt;$IS;17| */

static Lisp_Object MS_CDECL CC_BOOT__IFARRAYUeltUDISU17(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V92, V93;
    Lisp_Object fn;
    argcheck(nargs, 3, "IFARRAY;elt;$IS;17");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;elt;$IS;17|\n");
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
    stack[0] = stack[-2];
    V93 = stack[-1];
    V92 = (Lisp_Object)113; /* 7 */
    V92 = Lgetv(nil, V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    V92 = (Lisp_Object)lessp2(stack[0], V92);
    nil = C_nil;
    if (exception_pending()) goto V99;
    V92 = V92 ? lisp_true : nil;
    env = stack[-5];
    if (!(V92 == nil)) goto V10;
    stack[-4] = stack[-2];
    V93 = stack[-3];
    V92 = (Lisp_Object)17; /* 1 */
    stack[0] = Lgetv(nil, V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    V93 = stack[-1];
    V92 = (Lisp_Object)113; /* 7 */
    V92 = Lgetv(nil, V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    V92 = plus2(stack[0], V92);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    V92 = (Lisp_Object)lessp2(stack[-4], V92);
    nil = C_nil;
    if (exception_pending()) goto V99;
    V92 = V92 ? lisp_true : nil;
    env = stack[-5];
    if (V92 == nil) goto V10;
    V92 = lisp_true;
    if (V92 == nil) goto V61;
    V93 = stack[-3];
    V92 = (Lisp_Object)33; /* 2 */
    stack[0] = Lgetv(nil, V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    V93 = stack[-1];
    V92 = (Lisp_Object)113; /* 7 */
    V92 = Lgetv(nil, V93, V92);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    V92 = difference2(stack[-2], V92);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-5];
    {
        Lisp_Object V100 = stack[0];
        popv(6);
        fn = elt(env, 2); /* ELT */
        return (*qfn2(fn))(qenv(fn), V100, V92);
    }

V61:
    V92 = nil;
    { popv(6); return onevalue(V92); }

V10:
    V92 = elt(env, 1); /* "index out of range" */
    {
        popv(6);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V92);
    }
/* error exit handlers */
V99:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|ILIST;empty;$;6| (|$|) NIL)

*/



/* Code for BOOT::|ILIST;empty;$;6| */

static Lisp_Object CC_BOOT__ILISTUemptyUDU6(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V7;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;empty;$;6|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V7 = V2;
/* end of prologue */
    V7 = nil;
    return onevalue(V7);
}

/*
(DEFUN BOOT::GETALIST (BOOT::|alist| BOOT::|prop|)
   (CDR (VMLISP:|assoc| BOOT::|prop| BOOT::|alist|)))

*/



/* Code for BOOT::GETALIST */

static Lisp_Object CC_BOOT__GETALIST(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V16, V17;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::GETALIST\n");
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
/* copy arguments values to proper place */
    V17 = V3;
    V16 = V2;
/* end of prologue */
    fn = elt(env, 1); /* ASSOC** */
    V16 = (*qfn2(fn))(qenv(fn), V17, V16);
    errexit();
    if (!car_legal(V16)) goto V18;
    V16 = qcdr(V16);
    return onevalue(V16);
/* error exit handlers */
V18:
    return error(1, err_bad_cdr, V16);
}

/*
(DEFUN BOOT::|opOf| (|x|) (COND ((ATOM |x|) |x|) ('T (CAR |x|))))

*/



/* Code for BOOT::|opOf| */

static Lisp_Object CC_BOOT__opOf(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V17, V18;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|opOf|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V17 = V2;
/* end of prologue */
    V18 = V17;
    if (!consp(V18)) return onevalue(V17);
    V18 = lisp_true;
    if (V18 == nil) goto V13;
    if (!car_legal(V17)) goto V19;
    V17 = qcar(V17);
    return onevalue(V17);

V13:
    V17 = nil;
    return onevalue(V17);
/* error exit handlers */
V19:
    return error(1, err_bad_car, V17);
}

/*
(DEFUN BOOT::|BOP;name;$S;2| (BOOT::|op| |$|) (VMLISP:QVELT BOOT::|op| 0))

*/



/* Code for BOOT::|BOP;name;$S;2| */

static Lisp_Object CC_BOOT__BOPUnameUDSU2(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|BOP;name;$S;2|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V15 = V3;
    V16 = V2;
/* end of prologue */
    V15 = (Lisp_Object)1; /* 0 */
        return Lgetv(nil, V16, V15);
}

/*
(DEFUN BOOT::|INT;one?;$B;7| (|x| |$|) (ONEP |x|))

*/



/* Code for BOOT::|INT;one?;$B;7| */

static Lisp_Object CC_BOOT__INTUoneWUDBU7(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V9, V10;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|INT;one?;$B;7|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V9 = V3;
    V10 = V2;
/* end of prologue */
    V9 = V10;
        return Lonep(nil, V9);
}

/*
(DEFUN BOOT::|isPatternVar| (|v|)
   (AND
      (VMLISP:IDENTP |v|)
      (MEMQ
         |v|
         '(|**| BOOT::|*1| BOOT::|*2| BOOT::|*3| BOOT::|*4| BOOT::|*5|
             BOOT::|*6| BOOT::|*7| BOOT::|*8| BOOT::|*9| BOOT::|*10|
             BOOT::|*11| BOOT::|*12| BOOT::|*13| BOOT::|*14| BOOT::|*15|
             BOOT::|*16| BOOT::|*17| BOOT::|*18| BOOT::|*19| BOOT::|*20|))
      'T))

*/



/* Code for BOOT::|isPatternVar| */

static Lisp_Object CC_BOOT__isPatternVar(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isPatternVar|\n");
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
    V35 = stack[0];
    if (V35 == nil) goto V12;
    V35 = stack[0];
    fn = elt(env, 2); /* SYMBOLP */
    V35 = (*qfn1(fn))(qenv(fn), V35);
    nil = C_nil;
    if (exception_pending()) goto V38;
    env = stack[-1];
    goto V11;

V11:
    if (V35 == nil) goto V8;
    V35 = stack[0];
    V36 = elt(env, 1); /* (** BOOT::*1 BOOT::*2 BOOT::*3 BOOT::*4 BOOT::*5 BOOT::*6 BOOT::*7 BOOT::*8 BOOT::*9 BOOT::*10 BOOT::*11 BOOT::*12 BOOT::*13 BOOT::*14 BOOT::*15 BOOT::*16 BOOT::*17 BOOT::*18
BOOT::*19 BOOT::*20) */
    V35 = Lmemq(nil, V35, V36);
    if (V35 == nil) goto V21;
    V35 = lisp_true;
    { popv(2); return onevalue(V35); }

V21:
    V35 = nil;
    { popv(2); return onevalue(V35); }

V8:
    V35 = nil;
    { popv(2); return onevalue(V35); }

V12:
    V35 = nil;
    goto V11;
/* error exit handlers */
V38:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|ILIST;copy;2$;20| (|x| |$|)
   (PROG (|i| |y|)
      (RETURN
         (SEQ
            (BOOT::LETT
               |y|
               (BOOT:SPADCALL (VMLISP:QREFELT |$| 16))
               BOOT::|ILIST;copy;2$;20|)
            (SEQ
               (BOOT::LETT |i| 0 BOOT::|ILIST;copy;2$;20|)
               BOOT::G190
               (COND
                  ((NULL (COND ((NULL |x|) 'NIL) ('T 'T)))
                     (GO BOOT::G191)))
               (SEQ
                  (COND
                     ((EQ |i| 1000)
                        (COND
                           ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 33))
                              (BOOT::|error| "cyclic list")))) )
                  (BOOT::LETT
                     |y|
                     (CONS (QCAR |x|) |y|)
                     BOOT::|ILIST;copy;2$;20|)
                  (EXIT
                     (BOOT::LETT |x| (QCDR |x|) BOOT::|ILIST;copy;2$;20|)))
               (BOOT::LETT
                  |i|
                  (VMLISP:QSADD1 |i|)
                  BOOT::|ILIST;copy;2$;20|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT (NREVERSE |y|)))) ))

*/



/* Code for BOOT::|ILIST;copy;2$;20| */

static Lisp_Object CC_BOOT__ILISTUcopyU2DU20(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V115, V116, V117;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;copy;2$;20|\n");
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
    V116 = stack[-1];
    V115 = (Lisp_Object)257; /* 16 */
    V115 = Lgetv(nil, V116, V115);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-4];
    V116 = V115;
    if (!car_legal(V116)) goto V123;
    V116 = qcar(V116);
    if (!car_legal(V115)) goto V124;
    V115 = qcdr(V115);
    V115 = Lapply1(nil, V116, V115);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-4];
    stack[0] = V115;
    V115 = (Lisp_Object)1; /* 0 */
    stack[-3] = V115;
    goto V36;

V36:
    V115 = stack[-2];
    if (V115 == nil) goto V45;
    V115 = lisp_true;
    if (V115 == nil) goto V50;
    V115 = lisp_true;
    goto V44;

V44:
    if (V115 == nil) goto V35;
    V116 = stack[-3];
    V115 = (Lisp_Object)16001; /* 1000 */
    if (!(V116 == V115)) goto V97;
    V116 = stack[-1];
    V115 = (Lisp_Object)529; /* 33 */
    V115 = Lgetv(nil, V116, V115);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-4];
    V116 = V115;
    if (!car_legal(V116)) goto V123;
    V117 = qcar(V116);
    V116 = stack[-2];
    if (!car_legal(V115)) goto V124;
    V115 = qcdr(V115);
    V115 = Lapply2(nil, 3, V117, V116, V115);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-4];
    if (V115 == nil) goto V97;
    V115 = elt(env, 1); /* "cyclic list" */
    fn = elt(env, 2); /* BOOT::|error| */
    V115 = (*qfn1(fn))(qenv(fn), V115);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-4];
    goto V97;

V97:
    V115 = stack[-2];
    V116 = qcar(V115);
    V115 = stack[0];
    V115 = cons(V116, V115);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-4];
    stack[0] = V115;
    V115 = stack[-2];
    V115 = qcdr(V115);
    stack[-2] = V115;
    V115 = stack[-3];
    V115 = add1(V115);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-4];
    stack[-3] = V115;
    goto V36;

V35:
    V115 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); /* NREVERSE */
        return (*qfn1(fn))(qenv(fn), V115);
    }

V50:
    V115 = nil;
    goto V44;

V45:
    V115 = nil;
    goto V44;
/* error exit handlers */
V124:
    popv(5);
    return error(1, err_bad_cdr, V115);
V123:
    popv(5);
    return error(1, err_bad_car, V116);
V122:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|IFARRAY;setelt;$I2S;18| (|r| |i| |x| |$|)
   (COND
      ((OR
          (|<| |i| (VMLISP:QREFELT |$| 7))
          (NULL
             (|<| |i| (|+| (VMLISP:QVELT |r| 1) (VMLISP:QREFELT |$| 7)))) )
         (BOOT::|error| "index out of range"))
      ('T
         (SETELT
            (VMLISP:QVELT |r| 2)
            (|-| |i| (VMLISP:QREFELT |$| 7))
            |x|))))

*/



/* Code for BOOT::|IFARRAY;setelt;$I2S;18| */

static Lisp_Object MS_CDECL CC_BOOT__IFARRAYUseteltUDI2SU18(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V96, V97;
    Lisp_Object fn;
    argcheck(nargs, 4, "IFARRAY;setelt;$I2S;18");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;setelt;$I2S;18|\n");
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
    stack[-1] = V5;
    stack[-2] = V4;
    stack[-3] = V3;
    stack[-4] = V2;
/* end of prologue */
    stack[0] = stack[-3];
    V97 = stack[-1];
    V96 = (Lisp_Object)113; /* 7 */
    V96 = Lgetv(nil, V97, V96);
    nil = C_nil;
    if (exception_pending()) goto V104;
    env = stack[-6];
    V96 = (Lisp_Object)lessp2(stack[0], V96);
    nil = C_nil;
    if (exception_pending()) goto V104;
    V96 = V96 ? lisp_true : nil;
    env = stack[-6];
    if (!(V96 == nil)) goto V11;
    stack[-5] = stack[-3];
    V97 = stack[-4];
    V96 = (Lisp_Object)17; /* 1 */
    stack[0] = Lgetv(nil, V97, V96);
    nil = C_nil;
    if (exception_pending()) goto V104;
    env = stack[-6];
    V97 = stack[-1];
    V96 = (Lisp_Object)113; /* 7 */
    V96 = Lgetv(nil, V97, V96);
    nil = C_nil;
    if (exception_pending()) goto V104;
    env = stack[-6];
    V96 = plus2(stack[0], V96);
    nil = C_nil;
    if (exception_pending()) goto V104;
    env = stack[-6];
    V96 = (Lisp_Object)lessp2(stack[-5], V96);
    nil = C_nil;
    if (exception_pending()) goto V104;
    V96 = V96 ? lisp_true : nil;
    env = stack[-6];
    if (V96 == nil) goto V11;
    V96 = lisp_true;
    if (V96 == nil) goto V62;
    V97 = stack[-4];
    V96 = (Lisp_Object)33; /* 2 */
    stack[0] = Lgetv(nil, V97, V96);
    nil = C_nil;
    if (exception_pending()) goto V104;
    env = stack[-6];
    V97 = stack[-1];
    V96 = (Lisp_Object)113; /* 7 */
    V96 = Lgetv(nil, V97, V96);
    nil = C_nil;
    if (exception_pending()) goto V104;
    env = stack[-6];
    V97 = difference2(stack[-3], V96);
    nil = C_nil;
    if (exception_pending()) goto V104;
    env = stack[-6];
    V96 = stack[-2];
    {
        Lisp_Object V105 = stack[0];
        popv(7);
        fn = elt(env, 2); /* SETELT */
        return (*qfnn(fn))(qenv(fn), 3, V105, V97, V96);
    }

V62:
    V96 = nil;
    { popv(7); return onevalue(V96); }

V11:
    V96 = elt(env, 1); /* "index out of range" */
    {
        popv(7);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V96);
    }
/* error exit handlers */
V104:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|ALIST;search;Key$U;15| (|k| |t| |$|)
   (PROG (|r| #:G102951 #:G102950 #:G102945)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (SEQ
                     (EXIT
                        (SEQ
                           (BOOT::LETT
                              |r|
                              NIL
                              BOOT::|ALIST;search;Key$U;15|)
                           (BOOT::LETT
                              #:G102951
                              (BOOT:SPADCALL |t| (VMLISP:QREFELT |$| 14))
                              BOOT::|ALIST;search;Key$U;15|)
                           BOOT::G190
                           (COND
                              ((OR
                                  (ATOM #:G102951)
                                  (PROGN
                                     (BOOT::LETT
                                        |r|
                                        (CAR #:G102951)
                                        BOOT::|ALIST;search;Key$U;15|)
                                     NIL))
                                 (GO BOOT::G191)))
                           (SEQ
                              (EXIT
                                 (COND
                                    ((BOOT:SPADCALL
                                        |k|
                                        (QCAR |r|)
                                        (VMLISP:QREFELT |$| 35))
                                       (PROGN
                                          (BOOT::LETT
                                             #:G102945
                                             (PROGN
                                                (BOOT::LETT
                                                   #:G102950
                                                   (CONS
                                                      0
        (QCDR |r|))
                                                   BOOT::|ALIST;search;Key$U;15|)
                                                (GO #:G102950))
                                             BOOT::|ALIST;search;Key$U;15|)
                                          (GO #:G102945)))) ))
                           (BOOT::LETT
                              #:G102951
                              (CDR #:G102951)
                              BOOT::|ALIST;search;Key$U;15|)
                           (GO BOOT::G190)
                           BOOT::G191
                           (EXIT NIL)))
                     #:G102945
                     (EXIT #:G102945))
                  (EXIT (CONS 1 "failed"))))
            #:G102950
            (EXIT #:G102950)))) )

*/



/* Code for BOOT::|ALIST;search;Key$U;15| */

static Lisp_Object MS_CDECL CC_BOOT__ALISTUsearchUKeyDUU15(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V122, V123, V124, V125;
    argcheck(nargs, 3, "ALIST;search;Key$U;15");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ALIST;search;Key$U;15|\n");
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
    stack[-1] = V4;
    stack[0] = V3;
    stack[-2] = V2;
/* end of prologue */
    V123 = stack[-1];
    V122 = (Lisp_Object)225; /* 14 */
    V122 = Lgetv(nil, V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V130;
    env = stack[-4];
    V123 = V122;
    if (!car_legal(V123)) goto V131;
    V124 = qcar(V123);
    V123 = stack[0];
    if (!car_legal(V122)) goto V132;
    V122 = qcdr(V122);
    V122 = Lapply2(nil, 3, V124, V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V130;
    env = stack[-4];
    stack[0] = V122;
    goto V24;

V24:
    V122 = stack[0];
    if (!consp(V122)) goto V112;
    V122 = stack[0];
    if (!car_legal(V122)) goto V133;
    V122 = qcar(V122);
    stack[-3] = V122;
    V122 = nil;
    if (!(V122 == nil)) goto V112;
    V123 = stack[-1];
    V122 = (Lisp_Object)561; /* 35 */
    V122 = Lgetv(nil, V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V130;
    env = stack[-4];
    V123 = V122;
    if (!car_legal(V123)) goto V131;
    V125 = qcar(V123);
    V124 = stack[-2];
    V123 = stack[-3];
    V123 = qcar(V123);
    if (!car_legal(V122)) goto V132;
    V122 = qcdr(V122);
    V122 = Lapply3(nil, 4, V125, V124, V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V130;
    env = stack[-4];
    if (V122 == nil) goto V62;
    V123 = (Lisp_Object)1; /* 0 */
    V122 = stack[-3];
    V122 = qcdr(V122);
    popv(5);
    { Lisp_Object retVal = cons(V123, V122);
    errexit();
    return onevalue(retVal); }

V62:
    V122 = stack[0];
    if (!car_legal(V122)) goto V132;
    V122 = qcdr(V122);
    stack[0] = V122;
    goto V24;

V112:
    V122 = (Lisp_Object)17; /* 1 */
    V123 = elt(env, 1); /* "failed" */
    popv(5);
    { Lisp_Object retVal = cons(V122, V123);
    errexit();
    return onevalue(retVal); }
/* error exit handlers */
V133:
    popv(5);
    return error(1, err_bad_car, V122);
V132:
    popv(5);
    return error(1, err_bad_cdr, V122);
V131:
    popv(5);
    return error(1, err_bad_car, V123);
V130:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|getOpCode| (BOOT::|op| BOOT::|vec| BOOT::|max|)
   (PROG (BOOT::|res|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET BOOT::|res| NIL)
               (COND
                  ((BOOT::|hashCode?| BOOT::|op|)
                     (SEQ
                        (DO ((|i| 0 (|+| |i| 2)))
                           ((|>| |i| BOOT::|max|) NIL)
                           (SEQ
                              (EXIT
                                 (COND
                                    ((EQL
                                        (BOOT::|hashString|
                                           (SYSTEM::PNAME
                                              (VMLISP:QVELT
                                                 BOOT::|vec|
                                                 |i|)))
                                        BOOT::|op|)
                                       (EXIT
                                          (RETURN
                                             (BOOT:SPADLET
                                                BOOT::|res|
                                                (VMLISP:QSADD1
                                                   |i|)))) ))) ))
                        (EXIT BOOT::|res|)))
                  ('T
                     (SEQ
                        (DO ((|i| 0 (|+| |i| 2)))
                           ((|>| |i| BOOT::|max|) NIL)
                           (SEQ
                              (EXIT
                                 (COND
                                    ((EQ
                                        (VMLISP:QVELT BOOT::|vec| |i|)
                                        BOOT::|op|)
                                       (EXIT
                                          (RETURN
                                             (BOOT:SPADLET
                                                BOOT::|res|
                                                (VMLISP:QSADD1
                                                   |i|)))) ))) ))
                        (EXIT BOOT::|res|)))) ))) ))

*/



/* Code for BOOT::|getOpCode| */

static Lisp_Object MS_CDECL CC_BOOT__getOpCode(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V149, V150;
    Lisp_Object fn;
    argcheck(nargs, 3, "getOpCode");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|getOpCode|\n");
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
    V149 = nil;
    stack[-4] = V149;
    V149 = stack[-3];
    fn = elt(env, 1); /* BOOT::|hashCode?| */
    V149 = (*qfn1(fn))(qenv(fn), V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    env = stack[-5];
    if (V149 == nil) goto V17;
    V149 = (Lisp_Object)1; /* 0 */
    stack[0] = V149;
    goto V34;

V34:
    V150 = stack[0];
    V149 = stack[-1];
    V149 = (Lisp_Object)greaterp2(V150, V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    V149 = V149 ? lisp_true : nil;
    env = stack[-5];
    if (!(V149 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    V150 = stack[-2];
    V149 = stack[0];
    V149 = Lgetv(nil, V150, V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    env = stack[-5];
    fn = elt(env, 2); /* SYSTEM::PNAME */
    V149 = (*qfn1(fn))(qenv(fn), V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    env = stack[-5];
    fn = elt(env, 3); /* BOOT::|hashString| */
    V150 = (*qfn1(fn))(qenv(fn), V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    env = stack[-5];
    V149 = stack[-3];
    V149 = Leql(nil, V150, V149);
    env = stack[-5];
    if (V149 == nil) goto V73;
    V149 = stack[0];
    V149 = add1(V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    stack[-4] = V149;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

V73:
    V150 = stack[0];
    V149 = (Lisp_Object)33; /* 2 */
    V149 = plus2(V150, V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    env = stack[-5];
    stack[0] = V149;
    goto V34;

V17:
    V149 = lisp_true;
    if (V149 == nil) goto V85;
    V149 = (Lisp_Object)1; /* 0 */
    stack[0] = V149;
    goto V101;

V101:
    V150 = stack[0];
    V149 = stack[-1];
    V149 = (Lisp_Object)greaterp2(V150, V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    V149 = V149 ? lisp_true : nil;
    env = stack[-5];
    if (!(V149 == nil)) { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }
    V150 = stack[-2];
    V149 = stack[0];
    V150 = Lgetv(nil, V150, V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    env = stack[-5];
    V149 = stack[-3];
    if (V150 == V149) goto V114;
    V150 = stack[0];
    V149 = (Lisp_Object)33; /* 2 */
    V149 = plus2(V150, V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    env = stack[-5];
    stack[0] = V149;
    goto V101;

V114:
    V149 = stack[0];
    V149 = add1(V149);
    nil = C_nil;
    if (exception_pending()) goto V156;
    stack[-4] = V149;
    { Lisp_Object res = stack[-4]; popv(6); return onevalue(res); }

V85:
    V149 = nil;
    { popv(6); return onevalue(V149); }
/* error exit handlers */
V156:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|SMP;zero?;$B;3| (|p| |$|)
   (COND
      ((BOOT::QEQCAR |p| 0)
         (BOOT:SPADCALL (QCDR |p|) (VMLISP:QREFELT |$| 16)))
      ('T 'NIL)))

*/



/* Code for BOOT::|SMP;zero?;$B;3| */

static Lisp_Object CC_BOOT__SMPUzeroWUDBU3(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V49, V50, V51;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;zero?;$B;3|\n");
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
    V50 = V3;
    stack[0] = V2;
/* end of prologue */
    V49 = stack[0];
    V51 = qcar(V49);
    V49 = (Lisp_Object)1; /* 0 */
    V49 = Leql(nil, V51, V49);
    env = stack[-1];
    if (V49 == nil) goto V10;
    V49 = (Lisp_Object)257; /* 16 */
    V49 = Lgetv(nil, V50, V49);
    nil = C_nil;
    if (exception_pending()) goto V53;
    V50 = V49;
    if (!car_legal(V50)) goto V54;
    V51 = qcar(V50);
    V50 = stack[0];
    V50 = qcdr(V50);
    if (!car_legal(V49)) goto V55;
    V49 = qcdr(V49);
        popv(2);
        return Lapply2(nil, 3, V51, V50, V49);

V10:
    V49 = lisp_true;
    if (V49 == nil) goto V46;
    V49 = nil;
    { popv(2); return onevalue(V49); }

V46:
    V49 = nil;
    { popv(2); return onevalue(V49); }
/* error exit handlers */
V55:
    popv(2);
    return error(1, err_bad_cdr, V49);
V54:
    popv(2);
    return error(1, err_bad_car, V50);
V53:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|ELTAGG-;qelt;SDomIm;1| (|a| |x| |$|)
   (BOOT:SPADCALL |a| |x| (VMLISP:QREFELT |$| 9)))

*/



/* Code for BOOT::|ELTAGG-;qelt;SDomIm;1| */

static Lisp_Object MS_CDECL CC_BOOT__ELTAGGKUqeltUSDomImU1(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "ELTAGG-;qelt;SDomIm;1");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ELTAGG-;qelt;SDomIm;1|\n");
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
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    V35 = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V36 = V35;
    V35 = (Lisp_Object)145; /* 9 */
    V35 = Lgetv(nil, V36, V35);
    nil = C_nil;
    if (exception_pending()) goto V41;
    V36 = V35;
    if (!car_legal(V36)) goto V42;
    V38 = qcar(V36);
    V37 = stack[-1];
    V36 = stack[0];
    if (!car_legal(V35)) goto V43;
    V35 = qcdr(V35);
        popv(2);
        return Lapply3(nil, 4, V38, V37, V36, V35);
/* error exit handlers */
V43:
    popv(2);
    return error(1, err_bad_cdr, V35);
V42:
    popv(2);
    return error(1, err_bad_car, V36);
V41:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|SMP;one?;$B;4| (|p| |$|)
   (COND
      ((BOOT::QEQCAR |p| 0)
         (BOOT:SPADCALL (QCDR |p|) (VMLISP:QREFELT |$| 18)))
      ('T 'NIL)))

*/



/* Code for BOOT::|SMP;one?;$B;4| */

static Lisp_Object CC_BOOT__SMPUoneWUDBU4(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V49, V50, V51;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;one?;$B;4|\n");
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
    V50 = V3;
    stack[0] = V2;
/* end of prologue */
    V49 = stack[0];
    V51 = qcar(V49);
    V49 = (Lisp_Object)1; /* 0 */
    V49 = Leql(nil, V51, V49);
    env = stack[-1];
    if (V49 == nil) goto V10;
    V49 = (Lisp_Object)289; /* 18 */
    V49 = Lgetv(nil, V50, V49);
    nil = C_nil;
    if (exception_pending()) goto V53;
    V50 = V49;
    if (!car_legal(V50)) goto V54;
    V51 = qcar(V50);
    V50 = stack[0];
    V50 = qcdr(V50);
    if (!car_legal(V49)) goto V55;
    V49 = qcdr(V49);
        popv(2);
        return Lapply2(nil, 3, V51, V50, V49);

V10:
    V49 = lisp_true;
    if (V49 == nil) goto V46;
    V49 = nil;
    { popv(2); return onevalue(V49); }

V46:
    V49 = nil;
    { popv(2); return onevalue(V49); }
/* error exit handlers */
V55:
    popv(2);
    return error(1, err_bad_cdr, V49);
V54:
    popv(2);
    return error(1, err_bad_car, V50);
V53:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|ELAGG-;removeDuplicates;2A;12| (|x| |$|)
   (BOOT:SPADCALL
      (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 8))
      (VMLISP:QREFELT |$| 35)))

*/



/* Code for BOOT::|ELAGG-;removeDuplicates;2A;12| */

static Lisp_Object CC_BOOT__ELAGGKUremoveDuplicatesU2AU12(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V54, V55, V56;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ELAGG-;removeDuplicates;2A;12|\n");
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
    V54 = (Lisp_Object)561; /* 35 */
    V54 = Lgetv(nil, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-4];
    stack[-3] = V54;
    V54 = stack[-3];
    if (!car_legal(V54)) goto V62;
    stack[0] = qcar(V54);
    V55 = stack[-1];
    V54 = (Lisp_Object)129; /* 8 */
    V54 = Lgetv(nil, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-4];
    V55 = V54;
    if (!car_legal(V55)) goto V63;
    V56 = qcar(V55);
    V55 = stack[-2];
    if (!car_legal(V54)) goto V64;
    V54 = qcdr(V54);
    V54 = Lapply2(nil, 3, V56, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    V55 = V54;
    V54 = stack[-3];
    if (!car_legal(V54)) goto V64;
    V54 = qcdr(V54);
    {
        Lisp_Object V65 = stack[0];
        popv(5);
        return Lapply2(nil, 3, V65, V55, V54);
    }
/* error exit handlers */
V64:
    popv(5);
    return error(1, err_bad_cdr, V54);
V63:
    popv(5);
    return error(1, err_bad_car, V55);
V62:
    popv(5);
    return error(1, err_bad_car, V54);
V61:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|SMP;=;2$B;29| (BOOT::|p1| BOOT::|p2| |$|)
   (COND
      ((BOOT::QEQCAR BOOT::|p1| 0)
         (COND
            ((BOOT::QEQCAR BOOT::|p2| 0)
               (BOOT:SPADCALL
                  (QCDR BOOT::|p1|)
                  (QCDR BOOT::|p2|)
                  (VMLISP:QREFELT |$| 89)))
            ('T 'NIL)))
      ((BOOT::QEQCAR BOOT::|p2| 0) 'NIL)
      ('T
         (COND
            ((BOOT:SPADCALL
                (QCAR (QCDR BOOT::|p1|))
                (QCAR (QCDR BOOT::|p2|))
                (VMLISP:QREFELT |$| 51))
               (BOOT:SPADCALL
                  (QCDR (QCDR BOOT::|p1|))
                  (QCDR (QCDR BOOT::|p2|))
                  (VMLISP:QREFELT |$| 97)))
            ('T 'NIL)))) )

*/



/* Code for BOOT::|SMP;=;2$B;29| */

static Lisp_Object MS_CDECL CC_BOOT__SMPUMU2DBU29(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V152, V153, V154, V155;
    argcheck(nargs, 3, "SMP;=;2$B;29");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;=;2$B;29|\n");
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
    V152 = stack[-2];
    V153 = qcar(V152);
    V152 = (Lisp_Object)1; /* 0 */
    V152 = Leql(nil, V153, V152);
    env = stack[-3];
    if (V152 == nil) goto V70;
    V152 = stack[-1];
    V153 = qcar(V152);
    V152 = (Lisp_Object)1; /* 0 */
    V152 = Leql(nil, V153, V152);
    env = stack[-3];
    if (V152 == nil) goto V24;
    V153 = stack[0];
    V152 = (Lisp_Object)1425; /* 89 */
    V152 = Lgetv(nil, V153, V152);
    nil = C_nil;
    if (exception_pending()) goto V159;
    V153 = V152;
    if (!car_legal(V153)) goto V160;
    V155 = qcar(V153);
    V153 = stack[-2];
    V154 = qcdr(V153);
    V153 = stack[-1];
    V153 = qcdr(V153);
    if (!car_legal(V152)) goto V161;
    V152 = qcdr(V152);
        popv(4);
        return Lapply3(nil, 4, V155, V154, V153, V152);

V24:
    V152 = lisp_true;
    if (V152 == nil) goto V64;
    V152 = nil;
    { popv(4); return onevalue(V152); }

V64:
    V152 = nil;
    { popv(4); return onevalue(V152); }

V70:
    V152 = stack[-1];
    V153 = qcar(V152);
    V152 = (Lisp_Object)1; /* 0 */
    V152 = Leql(nil, V153, V152);
    env = stack[-3];
    if (V152 == nil) goto V68;
    V152 = nil;
    { popv(4); return onevalue(V152); }

V68:
    V152 = lisp_true;
    if (V152 == nil) goto V80;
    V153 = stack[0];
    V152 = (Lisp_Object)817; /* 51 */
    V152 = Lgetv(nil, V153, V152);
    nil = C_nil;
    if (exception_pending()) goto V159;
    env = stack[-3];
    V153 = V152;
    if (!car_legal(V153)) goto V160;
    V155 = qcar(V153);
    V153 = stack[-2];
    V153 = qcdr(V153);
    V154 = qcar(V153);
    V153 = stack[-1];
    V153 = qcdr(V153);
    V153 = qcar(V153);
    if (!car_legal(V152)) goto V161;
    V152 = qcdr(V152);
    V152 = Lapply3(nil, 4, V155, V154, V153, V152);
    nil = C_nil;
    if (exception_pending()) goto V159;
    env = stack[-3];
    if (V152 == nil) goto V85;
    V153 = stack[0];
    V152 = (Lisp_Object)1553; /* 97 */
    V152 = Lgetv(nil, V153, V152);
    nil = C_nil;
    if (exception_pending()) goto V159;
    V153 = V152;
    if (!car_legal(V153)) goto V160;
    V155 = qcar(V153);
    V153 = stack[-2];
    V153 = qcdr(V153);
    V154 = qcdr(V153);
    V153 = stack[-1];
    V153 = qcdr(V153);
    V153 = qcdr(V153);
    if (!car_legal(V152)) goto V161;
    V152 = qcdr(V152);
        popv(4);
        return Lapply3(nil, 4, V155, V154, V153, V152);

V85:
    V152 = lisp_true;
    if (V152 == nil) goto V149;
    V152 = nil;
    { popv(4); return onevalue(V152); }

V149:
    V152 = nil;
    { popv(4); return onevalue(V152); }

V80:
    V152 = nil;
    { popv(4); return onevalue(V152); }
/* error exit handlers */
V161:
    popv(4);
    return error(1, err_bad_cdr, V152);
V160:
    popv(4);
    return error(1, err_bad_car, V153);
V159:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|PR;reductum;2$;8| (|p| |$|)
   (COND ((NULL |p|) |p|) ('T (CDR |p|))))

*/



/* Code for BOOT::|PR;reductum;2$;8| */

static Lisp_Object CC_BOOT__PRUreductumU2DU8(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V18, V19;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PR;reductum;2$;8|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V18 = V3;
    V19 = V2;
/* end of prologue */
    V18 = V19;
    if (V18 == nil) return onevalue(V19);
    V18 = lisp_true;
    if (V18 == nil) goto V14;
    V18 = V19;
    if (!car_legal(V18)) goto V20;
    V18 = qcdr(V18);
    return onevalue(V18);

V14:
    V18 = nil;
    return onevalue(V18);
/* error exit handlers */
V20:
    return error(1, err_bad_cdr, V18);
}

/*
(DEFUN BOOT::|SMP;variables;$L;62| (|p| |$|)
   (PROG (BOOT::|lv| |q|)
      (RETURN
         (SEQ
            (COND
               ((BOOT::QEQCAR |p| 0) NIL)
               ('T
                  (SEQ
                     (BOOT::LETT
                        BOOT::|lv|
                        NIL
                        BOOT::|SMP;variables;$L;62|)
                     (BOOT::LETT
                        |q|
                        (QCDR (QCDR |p|))
                        BOOT::|SMP;variables;$L;62|)
                     (SEQ
                        BOOT::G190
                        (COND
                           ((NULL
                               (COND
                                  ((BOOT:SPADCALL
                                      |q|
                                      (VMLISP:QREFELT |$| 128))
                                     'NIL)
                                  ('T 'T)))
                              (GO BOOT::G191)))
                        (SEQ
                           (BOOT::LETT
                              BOOT::|lv|
                              (BOOT::|SMP;mymerge|
                                 BOOT::|lv|
                                 (BOOT:SPADCALL
                                    (BOOT:SPADCALL
                                       |q|
                                       (VMLISP:QREFELT |$| 22))
                                    (VMLISP:QREFELT |$| 161))
                                 |$|)
                              BOOT::|SMP;variables;$L;62|)
                           (EXIT
                              (BOOT::LETT
                                 |q|
                                 (BOOT:SPADCALL
                                    |q|
                                    (VMLISP:QREFELT |$| 20))
                                 BOOT::|SMP;variables;$L;62|)))
                        NIL
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT NIL))
                     (EXIT (CONS (QCAR (QCDR |p|)) BOOT::|lv|)))) ))) ))

*/



/* Code for BOOT::|SMP;variables;$L;62| */

static Lisp_Object CC_BOOT__SMPUvariablesUDLU62(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V176, V177, V178;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;variables;$L;62|\n");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-3] = V3;
    stack[-4] = V2;
/* end of prologue */
    V176 = stack[-4];
    V177 = qcar(V176);
    V176 = (Lisp_Object)1; /* 0 */
    V176 = Leql(nil, V177, V176);
    env = stack[-6];
    if (V176 == nil) goto V16;
    V176 = nil;
    { popv(7); return onevalue(V176); }

V16:
    V176 = lisp_true;
    if (V176 == nil) goto V28;
    V176 = nil;
    stack[0] = V176;
    V176 = stack[-4];
    V176 = qcdr(V176);
    V176 = qcdr(V176);
    stack[-5] = V176;
    goto V52;

V52:
    V177 = stack[-3];
    V176 = (Lisp_Object)2049; /* 128 */
    V176 = Lgetv(nil, V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V185;
    env = stack[-6];
    V177 = V176;
    if (!car_legal(V177)) goto V186;
    V178 = qcar(V177);
    V177 = stack[-5];
    if (!car_legal(V176)) goto V187;
    V176 = qcdr(V176);
    V176 = Lapply2(nil, 3, V178, V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V185;
    env = stack[-6];
    if (V176 == nil) goto V47;
    V176 = nil;
    goto V45;

V45:
    if (V176 == nil) goto V165;
    stack[-2] = stack[0];
    V177 = stack[-3];
    V176 = (Lisp_Object)2577; /* 161 */
    V176 = Lgetv(nil, V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V185;
    env = stack[-6];
    stack[-1] = V176;
    V176 = stack[-1];
    if (!car_legal(V176)) goto V188;
    stack[0] = qcar(V176);
    V177 = stack[-3];
    V176 = (Lisp_Object)353; /* 22 */
    V176 = Lgetv(nil, V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V185;
    env = stack[-6];
    V177 = V176;
    if (!car_legal(V177)) goto V186;
    V178 = qcar(V177);
    V177 = stack[-5];
    if (!car_legal(V176)) goto V187;
    V176 = qcdr(V176);
    V176 = Lapply2(nil, 3, V178, V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V185;
    env = stack[-6];
    V177 = V176;
    V176 = stack[-1];
    if (!car_legal(V176)) goto V187;
    V176 = qcdr(V176);
    V176 = Lapply2(nil, 3, stack[0], V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V185;
    env = stack[-6];
    V177 = V176;
    V176 = stack[-3];
    fn = elt(env, 1); /* BOOT::|SMP;mymerge| */
    V176 = (*qfnn(fn))(qenv(fn), 3, stack[-2], V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V185;
    env = stack[-6];
    stack[0] = V176;
    V177 = stack[-3];
    V176 = (Lisp_Object)321; /* 20 */
    V176 = Lgetv(nil, V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V185;
    env = stack[-6];
    V177 = V176;
    if (!car_legal(V177)) goto V186;
    V178 = qcar(V177);
    V177 = stack[-5];
    if (!car_legal(V176)) goto V187;
    V176 = qcdr(V176);
    V176 = Lapply2(nil, 3, V178, V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V185;
    env = stack[-6];
    stack[-5] = V176;
    goto V52;

V165:
    V176 = stack[-4];
    V176 = qcdr(V176);
    V177 = qcar(V176);
    V176 = stack[0];
    popv(7);
    { Lisp_Object retVal = cons(V177, V176);
    errexit();
    return onevalue(retVal); }

V47:
    V176 = lisp_true;
    if (V176 == nil) goto V74;
    V176 = lisp_true;
    goto V45;

V74:
    V176 = nil;
    goto V45;

V28:
    V176 = nil;
    { popv(7); return onevalue(V176); }
/* error exit handlers */
V188:
    popv(7);
    return error(1, err_bad_car, V176);
V187:
    popv(7);
    return error(1, err_bad_cdr, V176);
V186:
    popv(7);
    return error(1, err_bad_car, V177);
V185:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|isDomain| (|a|)
   (AND
      (PAIRP |a|)
      (VMLISP:VECP (CAR |a|))
      (VMLISP:|member| (ELT (CAR |a|) 0) BOOT::|$domainTypeTokens|)))

*/



/* Code for BOOT::|isDomain| */

static Lisp_Object CC_BOOT__isDomain(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V37, V38;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isDomain|\n");
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
    V37 = stack[0];
    fn = elt(env, 2); /* CONSP */
    V37 = (*qfn1(fn))(qenv(fn), V37);
    nil = C_nil;
    if (exception_pending()) goto V40;
    env = stack[-1];
    if (V37 == nil) goto V8;
    V37 = stack[0];
    if (!car_legal(V37)) goto V41;
    V37 = qcar(V37);
    fn = elt(env, 3); /* SIMPLE-VECTOR-P */
    V37 = (*qfn1(fn))(qenv(fn), V37);
    nil = C_nil;
    if (exception_pending()) goto V40;
    env = stack[-1];
    if (V37 == nil) goto V13;
    V37 = stack[0];
    if (!car_legal(V37)) goto V41;
    V38 = qcar(V37);
    V37 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* ELT */
    V38 = (*qfn2(fn))(qenv(fn), V38, V37);
    nil = C_nil;
    if (exception_pending()) goto V40;
    env = stack[-1];
    V37 = qvalue(elt(env, 1)); /* BOOT::|$domainTypeTokens| */
    {
        popv(2);
        fn = elt(env, 5); /* VMLISP:|member| */
        return (*qfn2(fn))(qenv(fn), V38, V37);
    }

V13:
    V37 = nil;
    { popv(2); return onevalue(V37); }

V8:
    V37 = nil;
    { popv(2); return onevalue(V37); }
/* error exit handlers */
V41:
    popv(2);
    return error(1, err_bad_car, V37);
V40:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|PR;leadingCoefficient;$R;6| (|p| |$|)
   (COND
      ((NULL |p|) (BOOT::|spadConstant| |$| 20))
      ('T (QCDR (BOOT::|SPADfirst| |p|)))) )

*/



/* Code for BOOT::|PR;leadingCoefficient;$R;6| */

static Lisp_Object CC_BOOT__PRUleadingCoefficientUDRU6(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V49, V50, V51;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PR;leadingCoefficient;$R;6|\n");
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
/* copy arguments values to proper place */
    V50 = V3;
    V51 = V2;
/* end of prologue */
    V49 = V51;
    if (V49 == nil) goto V18;
    V49 = lisp_true;
    if (V49 == nil) goto V34;
    V49 = V51;
    V50 = V49;
    V49 = V50;
    if (V49 == nil) goto V43;
    V49 = V50;
    if (!car_legal(V49)) goto V52;
    V49 = qcar(V49);
    goto V38;

V38:
    V49 = qcdr(V49);
    return onevalue(V49);

V43:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V49 = (*qfnn(fn))(qenv(fn), 0);
    errexit();
    goto V38;

V34:
    V49 = nil;
    return onevalue(V49);

V18:
    V49 = (Lisp_Object)321; /* 20 */
    V49 = Lgetv(nil, V50, V49);
    errexit();
    V50 = V49;
    if (!car_legal(V50)) goto V53;
    V50 = qcar(V50);
    if (!car_legal(V49)) goto V54;
    V49 = qcdr(V49);
        return Lapply1(nil, V50, V49);
/* error exit handlers */
V54:
    return error(1, err_bad_cdr, V49);
V53:
    return error(1, err_bad_car, V50);
V52:
    return error(1, err_bad_car, V49);
}

/*
(DEFUN BOOT::|KERNEL;position;$Nni;7| (|k| |$|) (VMLISP:QVELT |k| 3))

*/



/* Code for BOOT::|KERNEL;position;$Nni;7| */

static Lisp_Object CC_BOOT__KERNELUpositionUDNniU7(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|KERNEL;position;$Nni;7|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V15 = V3;
    V16 = V2;
/* end of prologue */
    V15 = (Lisp_Object)49; /* 3 */
        return Lgetv(nil, V16, V15);
}

/*
(DEFUN BOOT::|lazyMatchArg| (|s| |a| BOOT::|dollar| BOOT::|domain|)
   (BOOT::|lazyMatchArg2| |s| |a| BOOT::|dollar| BOOT::|domain| 'T))

*/



/* Code for BOOT::|lazyMatchArg| */

static Lisp_Object MS_CDECL CC_BOOT__lazyMatchArg(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V26, V27, V28, V29, V30;
    Lisp_Object fn;
    argcheck(nargs, 4, "lazyMatchArg");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|lazyMatchArg|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V26 = V5;
    V27 = V4;
    V28 = V3;
    V29 = V2;
/* end of prologue */
    V30 = V29;
    V29 = V28;
    V28 = V27;
    V27 = V26;
    V26 = lisp_true;
    {
        fn = elt(env, 1); /* BOOT::|lazyMatchArg2| */
        return (*qfnn(fn))(qenv(fn), 5, V30, V29, V28, V27, V26);
    }
}

/*
(DEFUN BOOT::|containsVars1| (|t|)
   (PROG (BOOT::|t1| BOOT::|t2|)
      (RETURN
         (PROGN
            (BOOT:SPADLET BOOT::|t1| (CAR |t|))
            (BOOT:SPADLET BOOT::|t2| (CDR |t|))
            (COND
               ((ATOM BOOT::|t1|)
                  (OR
                     (BOOT::|isPatternVar| BOOT::|t1|)
                     (COND
                        ((ATOM BOOT::|t2|)
                           (BOOT::|isPatternVar| BOOT::|t2|))
                        ('T (BOOT::|containsVars1| BOOT::|t2|)))) )
               ('T
                  (OR
                     (BOOT::|containsVars1| BOOT::|t1|)
                     (COND
                        ((ATOM BOOT::|t2|)
                           (BOOT::|isPatternVar| BOOT::|t2|))
                        ('T (BOOT::|containsVars1| BOOT::|t2|)))) ))) )))

*/



/* Code for BOOT::|containsVars1| */

static Lisp_Object CC_BOOT__containsVars1(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V56, V57;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|containsVars1|\n");
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
    V56 = V2;
/* end of prologue */

V1:
    V57 = V56;
    if (!car_legal(V57)) goto V59;
    V57 = qcar(V57);
    if (!car_legal(V56)) goto V60;
    V56 = qcdr(V56);
    stack[0] = V56;
    V56 = V57;
    if (!consp(V56)) goto V16;
    V56 = lisp_true;
    if (V56 == nil) goto V37;
    V56 = V57;
    V56 = CC_BOOT__containsVars1(env, V56);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-1];
    if (!(V56 == nil)) { popv(2); return onevalue(V56); }
    V56 = stack[0];
    if (!consp(V56)) goto V46;
    V56 = lisp_true;
    if (V56 == nil) goto V52;
    V56 = stack[0];
    goto V1;

V52:
    V56 = nil;
    { popv(2); return onevalue(V56); }

V46:
    V56 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* BOOT::|isPatternVar| */
        return (*qfn1(fn))(qenv(fn), V56);
    }

V37:
    V56 = nil;
    { popv(2); return onevalue(V56); }

V16:
    V56 = V57;
    fn = elt(env, 1); /* BOOT::|isPatternVar| */
    V56 = (*qfn1(fn))(qenv(fn), V56);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-1];
    if (!(V56 == nil)) { popv(2); return onevalue(V56); }
    V56 = stack[0];
    if (!consp(V56)) goto V26;
    V56 = lisp_true;
    if (V56 == nil) goto V32;
    V56 = stack[0];
    goto V1;

V32:
    V56 = nil;
    { popv(2); return onevalue(V56); }

V26:
    V56 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* BOOT::|isPatternVar| */
        return (*qfn1(fn))(qenv(fn), V56);
    }
/* error exit handlers */
V61:
    popv(2);
    return nil;
V60:
    popv(2);
    return error(1, err_bad_cdr, V56);
V59:
    popv(2);
    return error(1, err_bad_car, V57);
}

/*
(DEFUN BOOT::|subCopy| (|t| BOOT::SL) (SUBLIS BOOT::SL |t|))

*/



/* Code for BOOT::|subCopy| */

static Lisp_Object CC_BOOT__subCopy(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|subCopy|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V16 = V3;
    V15 = V2;
/* end of prologue */
    {
        fn = elt(env, 1); /* SUBLIS */
        return (*qfn2(fn))(qenv(fn), V16, V15);
    }
}

/*
(DEFUN BOOT::|isFreeFunctionFromMmCond| (BOOT::|cond|)
   (PROG (|c| BOOT::|ISTMP#1| BOOT::|ISTMP#2| BOOT::|cl| BOOT::|condList|
         BOOT::|iff|)
      (RETURN
         (SEQ
            (PROGN
               (COND
                  ((AND
                      (PAIRP BOOT::|cond|)
                      (EQ (QCAR BOOT::|cond|) 'BOOT::|partial|)
                      (PROGN (BOOT:SPADLET |c| (QCDR BOOT::|cond|)) 'T))
                     (BOOT:SPADLET BOOT::|cond| |c|)))
               (BOOT:SPADLET
                  BOOT::|condList|
                  (COND
                     ((AND
                         (PAIRP BOOT::|cond|)
                         (EQ (QCAR BOOT::|cond|) 'AND)
                         (PROGN
                            (BOOT:SPADLET BOOT::|cl| (QCDR BOOT::|cond|))
                            'T))
                        BOOT::|cl|)
                     ((AND
                         (PAIRP BOOT::|cond|)
                         (EQ (QCAR BOOT::|cond|) 'OR)
                         (PROGN
                            (BOOT:SPADLET
                               BOOT::|ISTMP#1|
                               (QCDR BOOT::|cond|))
                            (AND
                               (PAIRP BOOT::|ISTMP#1|)
                               (PROGN
                                  (BOOT:SPADLET
                                     BOOT::|ISTMP#2|
                                     (QCAR BOOT::|ISTMP#1|))
                                  (AND
                                     (PAIRP BOOT::|ISTMP#2|)
                                     (EQ (QCAR BOOT::|ISTMP#2|) 'AND)
                                     (PROGN
                                        (BOOT:SPADLET
                                           BOOT::|cl|
                                           (QCDR BOOT::|ISTMP#2|))
                                        'T)))) ))
                        BOOT::|cl|)
                     ('T (CONS BOOT::|cond| NIL))))
               (BOOT:SPADLET BOOT::|iff| NIL)
               (DO ((#:G18927 BOOT::|condList| (CDR #:G18927))
                     (BOOT::|condition| NIL))
                  ((OR
                      (ATOM #:G18927)
                      (PROGN (SETQ BOOT::|condition| (CAR #:G18927)) NIL)
                      (NULL (NULL BOOT::|iff|)))
                     NIL)
                  (SEQ
                     (EXIT
                        (COND
                           ((AND
                               (PAIRP BOOT::|condition|)
                               (EQ
                                  (QCAR BOOT::|condition|)
                                  'BOOT::|isFreeFunction|))
                              (BOOT:SPADLET BOOT::|iff| 'T))
                           ('T NIL)))) )
               BOOT::|iff|)))) )

*/



/* Code for BOOT::|isFreeFunctionFromMmCond| */

static Lisp_Object CC_BOOT__isFreeFunctionFromMmCond(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V170, V171;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isFreeFunctionFromMmCond|\n");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = V2;
/* end of prologue */
    stack[0] = nil;
    V170 = stack[-1];
    fn = elt(env, 5); /* CONSP */
    V170 = (*qfn1(fn))(qenv(fn), V170);
    nil = C_nil;
    if (exception_pending()) goto V175;
    env = stack[-3];
    if (V170 == nil) goto V17;
    V170 = stack[-1];
    V171 = qcar(V170);
    V170 = elt(env, 1); /* BOOT::|partial| */
    if (!(V171 == V170)) goto V17;
    V170 = stack[-1];
    V170 = qcdr(V170);
    V171 = V170;
    V170 = lisp_true;
    if (V170 == nil) goto V17;
    V170 = V171;
    stack[-1] = V170;
    goto V17;

V17:
    V170 = stack[-1];
    fn = elt(env, 5); /* CONSP */
    V170 = (*qfn1(fn))(qenv(fn), V170);
    nil = C_nil;
    if (exception_pending()) goto V175;
    env = stack[-3];
    if (V170 == nil) goto V40;
    V170 = stack[-1];
    V171 = qcar(V170);
    V170 = elt(env, 2); /* AND */
    if (!(V171 == V170)) goto V40;
    V170 = stack[-1];
    V170 = qcdr(V170);
    stack[0] = V170;
    V170 = lisp_true;
    if (V170 == nil) goto V40;
    V170 = stack[0];
    goto V38;

V38:
    V171 = V170;
    V170 = nil;
    stack[-2] = V170;
    V170 = V171;
    stack[0] = V170;
    goto V122;

V122:
    V170 = stack[0];
    if (!consp(V170)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    V170 = stack[0];
    if (!car_legal(V170)) goto V176;
    V170 = qcar(V170);
    stack[-1] = V170;
    V170 = nil;
    if (!(V170 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    V170 = stack[-2];
    if (!(V170 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    V170 = stack[-1];
    fn = elt(env, 5); /* CONSP */
    V170 = (*qfn1(fn))(qenv(fn), V170);
    nil = C_nil;
    if (exception_pending()) goto V175;
    env = stack[-3];
    if (V170 == nil) goto V142;
    V170 = stack[-1];
    V171 = qcar(V170);
    V170 = elt(env, 4); /* BOOT::|isFreeFunction| */
    if (!(V171 == V170)) goto V142;
    V170 = lisp_true;
    stack[-2] = V170;
    goto V138;

V138:
    V170 = stack[0];
    if (!car_legal(V170)) goto V177;
    V170 = qcdr(V170);
    stack[0] = V170;
    goto V122;

V142:
    V170 = lisp_true;
    if (V170 == nil) goto V138;
    else goto V138;

V40:
    V170 = stack[-1];
    fn = elt(env, 5); /* CONSP */
    V170 = (*qfn1(fn))(qenv(fn), V170);
    nil = C_nil;
    if (exception_pending()) goto V175;
    env = stack[-3];
    if (V170 == nil) goto V59;
    V170 = stack[-1];
    V171 = qcar(V170);
    V170 = elt(env, 3); /* OR */
    if (!(V171 == V170)) goto V59;
    V170 = stack[-1];
    V170 = qcdr(V170);
    stack[-2] = V170;
    V170 = stack[-2];
    fn = elt(env, 5); /* CONSP */
    V170 = (*qfn1(fn))(qenv(fn), V170);
    nil = C_nil;
    if (exception_pending()) goto V175;
    env = stack[-3];
    if (V170 == nil) goto V77;
    V170 = stack[-2];
    V170 = qcar(V170);
    stack[-2] = V170;
    V170 = stack[-2];
    fn = elt(env, 5); /* CONSP */
    V170 = (*qfn1(fn))(qenv(fn), V170);
    nil = C_nil;
    if (exception_pending()) goto V175;
    env = stack[-3];
    if (V170 == nil) goto V88;
    V170 = stack[-2];
    V171 = qcar(V170);
    V170 = elt(env, 2); /* AND */
    if (V171 == V170) goto V104;
    V170 = nil;
    goto V76;

V76:
    if (V170 == nil) goto V59;
    V170 = stack[0];
    goto V38;

V59:
    V170 = lisp_true;
    if (V170 == nil) goto V111;
    V170 = stack[-1];
    V170 = ncons(V170);
    nil = C_nil;
    if (exception_pending()) goto V175;
    env = stack[-3];
    goto V38;

V111:
    V170 = nil;
    goto V38;

V104:
    V170 = stack[-2];
    V170 = qcdr(V170);
    stack[0] = V170;
    V170 = lisp_true;
    goto V76;

V88:
    V170 = nil;
    goto V76;

V77:
    V170 = nil;
    goto V76;
/* error exit handlers */
V177:
    popv(4);
    return error(1, err_bad_cdr, V170);
V176:
    popv(4);
    return error(1, err_bad_car, V170);
V175:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|ILIST;first;$S;4| (|x| |$|) (BOOT::|SPADfirst| |x|))

*/



/* Code for BOOT::|ILIST;first;$S;4| */

static Lisp_Object CC_BOOT__ILISTUfirstUDSU4(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V19, V20;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;first;$S;4|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V19 = V3;
    V20 = V2;
/* end of prologue */
    V19 = V20;
    V20 = V19;
    V19 = V20;
    if (V19 == nil) goto V14;
    V19 = V20;
    if (!car_legal(V19)) goto V21;
    V19 = qcar(V19);
    return onevalue(V19);

V14:
    {
        fn = elt(env, 1); /* BOOT::FIRST-ERROR */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
V21:
    return error(1, err_bad_car, V19);
}

/*
(DEFUN BOOT::|ELTAGG-;qsetelt!;SDom2Im;2| (|a| |x| |y| |$|)
   (BOOT:SPADCALL |a| |x| |y| (VMLISP:QREFELT |$| 11)))

*/



/* Code for BOOT::|ELTAGG-;qsetelt!;SDom2Im;2| */

static Lisp_Object MS_CDECL CC_BOOT__ELTAGGKUqseteltBUSDom2ImU2(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V39, V40, V41, V42, V43;
    Lisp_Object fn;
    argcheck(nargs, 4, "ELTAGG-;qsetelt!;SDom2Im;2");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ELTAGG-;qsetelt!;SDom2Im;2|\n");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    V39 = V5;
    stack[0] = V4;
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    V40 = V39;
    V39 = (Lisp_Object)177; /* 11 */
    V39 = Lgetv(nil, V40, V39);
    nil = C_nil;
    if (exception_pending()) goto V47;
    env = stack[-3];
    V40 = V39;
    if (!car_legal(V40)) goto V48;
    V43 = qcar(V40);
    V42 = stack[-2];
    V41 = stack[-1];
    V40 = stack[0];
    if (!car_legal(V39)) goto V49;
    V39 = qcdr(V39);
    {
        popv(4);
        fn = elt(env, 1); /* FUNCALL* */
        return (*qfnn(fn))(qenv(fn), 5, V43, V42, V41, V40, V39);
    }
/* error exit handlers */
V49:
    popv(4);
    return error(1, err_bad_cdr, V39);
V48:
    popv(4);
    return error(1, err_bad_car, V40);
V47:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|isFreeFunctionFromMm| (BOOT::|mm|)
   (PROG (BOOT::|cond|)
      (RETURN
         (PROGN
            (BOOT:SPADLET BOOT::|cond| (CADR BOOT::|mm|))
            (BOOT::|isFreeFunctionFromMmCond| BOOT::|cond|)))) )

*/



/* Code for BOOT::|isFreeFunctionFromMm| */

static Lisp_Object CC_BOOT__isFreeFunctionFromMm(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V14;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isFreeFunctionFromMm|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V14 = V2;
/* end of prologue */
    if (!car_legal(V14)) goto V15;
    V14 = qcdr(V14);
    if (!car_legal(V14)) goto V16;
    V14 = qcar(V14);
    {
        fn = elt(env, 1); /* BOOT::|isFreeFunctionFromMmCond| */
        return (*qfn1(fn))(qenv(fn), V14);
    }
/* error exit handlers */
V16:
    return error(1, err_bad_car, V14);
V15:
    return error(1, err_bad_cdr, V14);
}

/*
(DEFUN BOOT::|BOP;property;$SU;7| (BOOT::|op| BOOT::|name| |$|)
   (BOOT:SPADCALL
      BOOT::|name|
      (VMLISP:QVELT BOOT::|op| 2)
      (VMLISP:QREFELT |$| 23)))

*/



/* Code for BOOT::|BOP;property;$SU;7| */

static Lisp_Object MS_CDECL CC_BOOT__BOPUpropertyUDSUU7(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V42, V43;
    argcheck(nargs, 3, "BOP;property;$SU;7");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|BOP;property;$SU;7|\n");
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
    V42 = V4;
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    V43 = V42;
    V42 = (Lisp_Object)369; /* 23 */
    V42 = Lgetv(nil, V43, V42);
    nil = C_nil;
    if (exception_pending()) goto V48;
    env = stack[-4];
    stack[-3] = V42;
    V42 = stack[-3];
    if (!car_legal(V42)) goto V49;
    stack[0] = qcar(V42);
    V43 = stack[-2];
    V42 = (Lisp_Object)33; /* 2 */
    V43 = Lgetv(nil, V43, V42);
    nil = C_nil;
    if (exception_pending()) goto V48;
    V42 = stack[-3];
    if (!car_legal(V42)) goto V50;
    V42 = qcdr(V42);
    {
        Lisp_Object V51 = stack[0];
        Lisp_Object V52 = stack[-1];
        popv(5);
        return Lapply3(nil, 4, V51, V52, V43, V42);
    }
/* error exit handlers */
V50:
    popv(5);
    return error(1, err_bad_cdr, V42);
V49:
    popv(5);
    return error(1, err_bad_car, V42);
V48:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|EXPR;numer;$Smp;22| (|x| |$|)
   (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 78)))

*/



/* Code for BOOT::|EXPR;numer;$Smp;22| */

static Lisp_Object CC_BOOT__EXPRUnumerUDSmpU22(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;numer;$Smp;22|\n");
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
    V31 = (Lisp_Object)1249; /* 78 */
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
(DEFUN BOOT::|EXPR;numer;$Smp;126| (|x| |$|) |x|)

*/



/* Code for BOOT::|EXPR;numer;$Smp;126| */

static Lisp_Object CC_BOOT__EXPRUnumerUDSmpU126(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    nil_as_base
    Lisp_Object V8, V9;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;numer;$Smp;126|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V8 = V3;
    V9 = V2;
/* end of prologue */
    return onevalue(V9);
}

/*
(DEFUN BOOT::|KERNEL;B2Z| (BOOT::|flag| |$|)
   (COND (BOOT::|flag| -1) ('T 1)))

*/



/* Code for BOOT::|KERNEL;B2Z| */

static Lisp_Object CC_BOOT__KERNELUB2Z(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V17, V18;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|KERNEL;B2Z|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V17 = V3;
    V18 = V2;
/* end of prologue */
    V17 = V18;
    if (V17 == nil) goto V10;
    V17 = (Lisp_Object)-15; /* -1 */
    return onevalue(V17);

V10:
    V17 = lisp_true;
    if (V17 == nil) goto V14;
    V17 = (Lisp_Object)17; /* 1 */
    return onevalue(V17);

V14:
    V17 = nil;
    return onevalue(V17);
}

/*
(DEFUN BOOT::|EXPR;denom;$Smp;23| (|x| |$|)
   (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 81)))

*/



/* Code for BOOT::|EXPR;denom;$Smp;23| */

static Lisp_Object CC_BOOT__EXPRUdenomUDSmpU23(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;denom;$Smp;23|\n");
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
    V31 = (Lisp_Object)1297; /* 81 */
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
(DEFUN BOOT::|ILIST;sort!;M2$;27| (|f| |l| |$|)
   (BOOT::|ILIST;mergeSort|
      |f|
      |l|
      (BOOT:SPADCALL |l| (VMLISP:QREFELT |$| 9))
      |$|))

*/



/* Code for BOOT::|ILIST;sort!;M2$;27| */

static Lisp_Object MS_CDECL CC_BOOT__ILISTUsortBUM2DU27(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V45, V46, V47;
    Lisp_Object fn;
    argcheck(nargs, 3, "ILIST;sort!;M2$;27");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;sort!;M2$;27|\n");
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
    stack[-1] = V4;
    stack[-2] = V3;
    V45 = V2;
/* end of prologue */
    stack[-3] = V45;
    stack[0] = stack[-2];
    V46 = stack[-1];
    V45 = (Lisp_Object)145; /* 9 */
    V45 = Lgetv(nil, V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V52;
    env = stack[-4];
    V46 = V45;
    if (!car_legal(V46)) goto V53;
    V47 = qcar(V46);
    V46 = stack[-2];
    if (!car_legal(V45)) goto V54;
    V45 = qcdr(V45);
    V45 = Lapply2(nil, 3, V47, V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V52;
    env = stack[-4];
    V46 = V45;
    V45 = stack[-1];
    {
        Lisp_Object V55 = stack[-3];
        Lisp_Object V56 = stack[0];
        popv(5);
        fn = elt(env, 1); /* BOOT::|ILIST;mergeSort| */
        return (*qfnn(fn))(qenv(fn), 4, V55, V56, V46, V45);
    }
/* error exit handlers */
V54:
    popv(5);
    return error(1, err_bad_cdr, V45);
V53:
    popv(5);
    return error(1, err_bad_car, V46);
V52:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|SMP;*;R2$;26| (|c| |p| |$|)
   (PROG (BOOT::|mvar| BOOT::|up|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL
                   |c|
                   (QCDR (BOOT::|spadConstant| |$| 14))
                   (VMLISP:QREFELT |$| 89))
                  |p|)
               ((BOOT::QEQCAR |p| 0)
                  (CONS
                     0
                     (BOOT:SPADCALL
                        |c|
                        (QCDR |p|)
                        (VMLISP:QREFELT |$| 90))))
               ('T
                  (SEQ
                     (BOOT::LETT
                        BOOT::|mvar|
                        (QCAR (QCDR |p|))
                        BOOT::|SMP;*;R2$;26|)
                     (BOOT::LETT
                        BOOT::|up|
                        (BOOT:SPADCALL
                           (CONS 0 |c|)
                           (QCDR (QCDR |p|))
                           (VMLISP:QREFELT |$| 55))
                        BOOT::|SMP;*;R2$;26|)
                     (EXIT
                        (COND
                           ((BOOT:SPADCALL
                               BOOT::|up|
                               (VMLISP:QREFELT |$| 21))
                              (BOOT:SPADCALL
                                 BOOT::|up|
                                 (VMLISP:QREFELT |$| 22)))
                           ('T
                              (CONS
                                 1
                                 (CONS
                                    BOOT::|mvar|
                                    BOOT::|up|)))) ))) ))) ))

*/



/* Code for BOOT::|SMP;*;R2$;26| */

static Lisp_Object MS_CDECL CC_BOOT__SMPUHUR2DU26(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V225, V226, V227, V228;
    argcheck(nargs, 3, "SMP;*;R2$;26");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;*;R2$;26|\n");
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
    V226 = stack[-2];
    V225 = (Lisp_Object)1425; /* 89 */
    V225 = Lgetv(nil, V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    env = stack[-6];
    stack[-5] = V225;
    V225 = stack[-5];
    if (!car_legal(V225)) goto V236;
    stack[-1] = qcar(V225);
    stack[0] = stack[-4];
    V226 = stack[-2];
    V225 = (Lisp_Object)225; /* 14 */
    V225 = Lgetv(nil, V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    env = stack[-6];
    V226 = V225;
    if (!car_legal(V226)) goto V237;
    V226 = qcar(V226);
    if (!car_legal(V225)) goto V238;
    V225 = qcdr(V225);
    V225 = Lapply1(nil, V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    env = stack[-6];
    V226 = qcdr(V225);
    V225 = stack[-5];
    if (!car_legal(V225)) goto V238;
    V225 = qcdr(V225);
    V225 = Lapply3(nil, 4, stack[-1], stack[0], V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    env = stack[-6];
    if (!(V225 == nil)) { Lisp_Object res = stack[-3]; popv(7); return onevalue(res); }
    V225 = stack[-3];
    V226 = qcar(V225);
    V225 = (Lisp_Object)1; /* 0 */
    V225 = Leql(nil, V226, V225);
    env = stack[-6];
    if (V225 == nil) goto V68;
    stack[0] = (Lisp_Object)1; /* 0 */
    V226 = stack[-2];
    V225 = (Lisp_Object)1441; /* 90 */
    V225 = Lgetv(nil, V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    env = stack[-6];
    V226 = V225;
    if (!car_legal(V226)) goto V237;
    V228 = qcar(V226);
    V227 = stack[-4];
    V226 = stack[-3];
    V226 = qcdr(V226);
    if (!car_legal(V225)) goto V238;
    V225 = qcdr(V225);
    V225 = Lapply3(nil, 4, V228, V227, V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    {
        Lisp_Object V239 = stack[0];
        popv(7);
        { Lisp_Object retVal = cons(V239, V225);
        errexit();
        return onevalue(retVal); }
    }

V68:
    V225 = lisp_true;
    if (V225 == nil) goto V114;
    V225 = stack[-3];
    V225 = qcdr(V225);
    V225 = qcar(V225);
    stack[-5] = V225;
    V226 = stack[-2];
    V225 = (Lisp_Object)881; /* 55 */
    V225 = Lgetv(nil, V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    env = stack[-6];
    stack[-1] = V225;
    V225 = stack[-1];
    if (!car_legal(V225)) goto V236;
    stack[0] = qcar(V225);
    V226 = (Lisp_Object)1; /* 0 */
    V225 = stack[-4];
    V227 = cons(V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    env = stack[-6];
    V225 = stack[-3];
    V225 = qcdr(V225);
    V226 = qcdr(V225);
    V225 = stack[-1];
    if (!car_legal(V225)) goto V238;
    V225 = qcdr(V225);
    V225 = Lapply3(nil, 4, stack[0], V227, V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    env = stack[-6];
    stack[0] = V225;
    V226 = stack[-2];
    V225 = (Lisp_Object)337; /* 21 */
    V225 = Lgetv(nil, V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    env = stack[-6];
    V226 = V225;
    if (!car_legal(V226)) goto V237;
    V227 = qcar(V226);
    V226 = stack[0];
    if (!car_legal(V225)) goto V238;
    V225 = qcdr(V225);
    V225 = Lapply2(nil, 3, V227, V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    env = stack[-6];
    if (V225 == nil) goto V160;
    V226 = stack[-2];
    V225 = (Lisp_Object)353; /* 22 */
    V225 = Lgetv(nil, V226, V225);
    nil = C_nil;
    if (exception_pending()) goto V235;
    V226 = V225;
    if (!car_legal(V226)) goto V237;
    V227 = qcar(V226);
    V226 = stack[0];
    if (!car_legal(V225)) goto V238;
    V225 = qcdr(V225);
        popv(7);
        return Lapply2(nil, 3, V227, V226, V225);

V160:
    V225 = lisp_true;
    if (V225 == nil) goto V210;
    V227 = (Lisp_Object)17; /* 1 */
    V226 = stack[-5];
    V225 = stack[0];
    popv(7);
    { Lisp_Object retVal = list2star(V227, V226, V225);
    errexit();
    return onevalue(retVal); }

V210:
    V225 = nil;
    { popv(7); return onevalue(V225); }

V114:
    V225 = nil;
    { popv(7); return onevalue(V225); }
/* error exit handlers */
V238:
    popv(7);
    return error(1, err_bad_cdr, V225);
V237:
    popv(7);
    return error(1, err_bad_car, V226);
V236:
    popv(7);
    return error(1, err_bad_car, V225);
V235:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|getDomainFromMm| (BOOT::|mm|)
   (PROG (|c| BOOT::|cond| BOOT::|cl| BOOT::|condList| BOOT::|dom|
         BOOT::|ISTMP#1| BOOT::|ISTMP#2| BOOT::|cat| BOOT::|val|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET BOOT::|cond| (CADR BOOT::|mm|))
               (COND
                  ((AND
                      (PAIRP BOOT::|cond|)
                      (EQ (QCAR BOOT::|cond|) 'BOOT::|partial|)
                      (PROGN (BOOT:SPADLET |c| (QCDR BOOT::|cond|)) 'T))
                     (BOOT:SPADLET BOOT::|cond| |c|)))
               (BOOT:SPADLET
                  BOOT::|condList|
                  (COND
                     ((AND
                         (PAIRP BOOT::|cond|)
                         (EQ (QCAR BOOT::|cond|) 'AND)
                         (PROGN
                            (BOOT:SPADLET BOOT::|cl| (QCDR BOOT::|cond|))
                            'T))
                        BOOT::|cl|)
                     ((AND
                         (PAIRP BOOT::|cond|)
                         (EQ (QCAR BOOT::|cond|) 'OR)
                         (PROGN
                            (BOOT:SPADLET
                               BOOT::|ISTMP#1|
                               (QCDR BOOT::|cond|))
                            (AND
                               (PAIRP BOOT::|ISTMP#1|)
                               (PROGN
                                  (BOOT:SPADLET
                                     BOOT::|ISTMP#2|
                                     (QCAR BOOT::|ISTMP#1|))
                                  (AND
                                     (PAIRP BOOT::|ISTMP#2|)
                                     (EQ (QCAR BOOT::|ISTMP#2|) 'AND)
                                     (PROGN
                                        (BOOT:SPADLET
                                           BOOT::|cl|
                                           (QCDR BOOT::|ISTMP#2|))
                                        'T)))) ))
                        BOOT::|cl|)
                     ('T (CONS BOOT::|cond| NIL))))
               (BOOT:SPADLET
                  BOOT::|val|
                  (DO ((#:G18925 BOOT::|condList| (CDR #:G18925))
                        (BOOT::|condition| NIL))
                     ((OR
                         (ATOM #:G18925)
                         (PROGN
                            (SETQ BOOT::|condition| (CAR #:G18925))
                            NIL))
                        NIL)
                     (SEQ
                        (EXIT
                           (COND
                              ((AND
                                  (PAIRP BOOT::|condition|)
                                  (EQ
                                     (QCAR BOOT::|condition|)
                                     'BOOT::|isDomain|)
                                  (PROGN
                                     (BOOT:SPADLET
                                        BOOT::|ISTMP#1|
                                        (QCDR BOOT::|condition|))
                                     (AND
                                        (PAIRP BOOT::|ISTMP#1|)
                                        (EQ
                                           (QCAR BOOT::|ISTMP#1|)
                                           'BOOT::|*1|)
                                        (PROGN
                                           (BOOT:SPADLET
                                              BOOT::|ISTMP#2|
                                              (QCDR BOOT::|ISTMP#1|))
                                           (AND
                                              (PAIRP BOOT::|ISTMP#2|)
                                              (EQ
                                                 (QCDR BOOT::|ISTMP#2|)
                                                 NIL)
                                              (PROGN
                                                 (BOOT:SPADLET
                                                    BOOT::|dom|
                                                    (QCAR BOOT::|ISTMP#2|))
                                                 'T)))) ))
                                 (RETURN (BOOT::|opOf| BOOT::|dom|)))
                              ((AND
                                  (PAIRP BOOT::|condition|)
                                  (EQ
                                     (QCAR BOOT::|condition|)
                                     'BOOT::|ofCategory|)
                                  (PROGN
                                     (BOOT:SPADLET
                                        BOOT::|ISTMP#1|
                                        (QCDR BOOT::|condition|))
                                     (AND
                                        (PAIRP BOOT::|ISTMP#1|)
                                        (EQ
                                           (QCAR BOOT::|ISTMP#1|)
                                           'BOOT::|*1|)
                                        (PROGN
                                           (BOOT:SPADLET
                                              BOOT::|ISTMP#2|
                                              (QCDR BOOT::|ISTMP#1|))
                                           (AND
                                              (PAIRP BOOT::|ISTMP#2|)
                                              (EQ
                                                 (QCDR BOOT::|ISTMP#2|)
                                                 NIL)
                                              (PROGN
                                                 (BOOT:SPADLET
                                                    BOOT::|cat|
                                                    (QCAR BOOT::|ISTMP#2|))
                                                 'T)))) ))
                                 (RETURN
                                    (BOOT::|opOf| BOOT::|cat|)))) ))) )
               (COND
                  ((NULL BOOT::|val|)
                     (BOOT::|keyedSystemError|
                        'BOOT::S2GE0016
                        (CONS
                           (VMLISP:MAKESTRING "getDomainFromMm")
                           (CONS
                              (VMLISP:MAKESTRING
                                 "Can't find domain in modemap condition")
                              NIL))))
                  ('T BOOT::|val|)))) )))

*/



/* Code for BOOT::|getDomainFromMm| */

static Lisp_Object CC_BOOT__getDomainFromMm(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V296, V297, V298;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|getDomainFromMm|\n");
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
/* copy arguments values to proper place */
    V296 = V2;
/* end of prologue */
    stack[0] = nil;
    stack[-4] = nil;
    stack[-2] = nil;
    if (!car_legal(V296)) goto V304;
    V296 = qcdr(V296);
    if (!car_legal(V296)) goto V305;
    V296 = qcar(V296);
    stack[-1] = V296;
    V296 = stack[-1];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V23;
    V296 = stack[-1];
    V297 = qcar(V296);
    V296 = elt(env, 1); /* BOOT::|partial| */
    if (!(V297 == V296)) goto V23;
    V296 = stack[-1];
    V296 = qcdr(V296);
    V297 = V296;
    V296 = lisp_true;
    if (V296 == nil) goto V23;
    V296 = V297;
    stack[-1] = V296;
    goto V23;

V23:
    V296 = stack[-1];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V46;
    V296 = stack[-1];
    V297 = qcar(V296);
    V296 = elt(env, 2); /* AND */
    if (!(V297 == V296)) goto V46;
    V296 = stack[-1];
    V296 = qcdr(V296);
    stack[0] = V296;
    V296 = lisp_true;
    if (V296 == nil) goto V46;
    V296 = stack[0];
    goto V44;

V44:
    stack[0] = V296;
    goto V127;

V127:
    V296 = stack[0];
    if (!consp(V296)) goto V130;
    V296 = stack[0];
    if (!car_legal(V296)) goto V305;
    V296 = qcar(V296);
    stack[-1] = V296;
    V296 = nil;
    if (!(V296 == nil)) goto V130;
    V296 = stack[-1];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V145;
    V296 = stack[-1];
    V297 = qcar(V296);
    V296 = elt(env, 4); /* BOOT::|isDomain| */
    if (!(V297 == V296)) goto V145;
    V296 = stack[-1];
    V296 = qcdr(V296);
    stack[-3] = V296;
    V296 = stack[-3];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V163;
    V296 = stack[-3];
    V297 = qcar(V296);
    V296 = elt(env, 5); /* BOOT::*1 */
    if (V297 == V296) goto V179;
    V296 = nil;
    goto V162;

V162:
    if (V296 == nil) goto V145;
    V296 = stack[-4];
    fn = elt(env, 11); /* BOOT::|opOf| */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    goto V122;

V122:
    V297 = V296;
    V296 = V297;
    if (V296 == nil) goto V274;
    V296 = lisp_true;
    if (!(V296 == nil)) { popv(6); return onevalue(V297); }
    V296 = nil;
    { popv(6); return onevalue(V296); }

V274:
    stack[0] = elt(env, 7); /* BOOT::S2GE0016 */
    V298 = elt(env, 8); /* "getDomainFromMm" */
    V297 = elt(env, 9); /* "Can't find domain in modemap condition" */
    V296 = nil;
    V296 = list2star(V298, V297, V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    {
        Lisp_Object V307 = stack[0];
        popv(6);
        fn = elt(env, 12); /* BOOT::|keyedSystemError| */
        return (*qfn2(fn))(qenv(fn), V307, V296);
    }

V145:
    V296 = stack[-1];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V141;
    V296 = stack[-1];
    V297 = qcar(V296);
    V296 = elt(env, 6); /* BOOT::|ofCategory| */
    if (!(V297 == V296)) goto V141;
    V296 = stack[-1];
    V296 = qcdr(V296);
    stack[-3] = V296;
    V296 = stack[-3];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V221;
    V296 = stack[-3];
    V297 = qcar(V296);
    V296 = elt(env, 5); /* BOOT::*1 */
    if (V297 == V296) goto V237;
    V296 = nil;
    goto V220;

V220:
    if (V296 == nil) goto V141;
    V296 = stack[-2];
    fn = elt(env, 11); /* BOOT::|opOf| */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    goto V122;

V141:
    V296 = stack[0];
    if (!car_legal(V296)) goto V304;
    V296 = qcdr(V296);
    stack[0] = V296;
    goto V127;

V237:
    V296 = stack[-3];
    V296 = qcdr(V296);
    stack[-3] = V296;
    V296 = stack[-3];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V243;
    V296 = stack[-3];
    V296 = qcdr(V296);
    if (V296 == nil) goto V253;
    V296 = nil;
    goto V220;

V253:
    V296 = stack[-3];
    V296 = qcar(V296);
    stack[-2] = V296;
    V296 = lisp_true;
    goto V220;

V243:
    V296 = nil;
    goto V220;

V221:
    V296 = nil;
    goto V220;

V179:
    V296 = stack[-3];
    V296 = qcdr(V296);
    stack[-3] = V296;
    V296 = stack[-3];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V185;
    V296 = stack[-3];
    V296 = qcdr(V296);
    if (V296 == nil) goto V195;
    V296 = nil;
    goto V162;

V195:
    V296 = stack[-3];
    V296 = qcar(V296);
    stack[-4] = V296;
    V296 = lisp_true;
    goto V162;

V185:
    V296 = nil;
    goto V162;

V163:
    V296 = nil;
    goto V162;

V130:
    V296 = nil;
    goto V122;

V46:
    V296 = stack[-1];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V65;
    V296 = stack[-1];
    V297 = qcar(V296);
    V296 = elt(env, 3); /* OR */
    if (!(V297 == V296)) goto V65;
    V296 = stack[-1];
    V296 = qcdr(V296);
    stack[-3] = V296;
    V296 = stack[-3];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V83;
    V296 = stack[-3];
    V296 = qcar(V296);
    stack[-3] = V296;
    V296 = stack[-3];
    fn = elt(env, 10); /* CONSP */
    V296 = (*qfn1(fn))(qenv(fn), V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    if (V296 == nil) goto V94;
    V296 = stack[-3];
    V297 = qcar(V296);
    V296 = elt(env, 2); /* AND */
    if (V297 == V296) goto V110;
    V296 = nil;
    goto V82;

V82:
    if (V296 == nil) goto V65;
    V296 = stack[0];
    goto V44;

V65:
    V296 = lisp_true;
    if (V296 == nil) goto V117;
    V296 = stack[-1];
    V296 = ncons(V296);
    nil = C_nil;
    if (exception_pending()) goto V306;
    env = stack[-5];
    goto V44;

V117:
    V296 = nil;
    goto V44;

V110:
    V296 = stack[-3];
    V296 = qcdr(V296);
    stack[0] = V296;
    V296 = lisp_true;
    goto V82;

V94:
    V296 = nil;
    goto V82;

V83:
    V296 = nil;
    goto V82;
/* error exit handlers */
V306:
    popv(6);
    return nil;
V305:
    popv(6);
    return error(1, err_bad_car, V296);
V304:
    popv(6);
    return error(1, err_bad_cdr, V296);
}

/*
(DEFUN BOOT::|FRAC;zero?;$B;2| (|x| |$|)
   (BOOT:SPADCALL (QCAR |x|) (VMLISP:QREFELT |$| 12)))

*/



/* Code for BOOT::|FRAC;zero?;$B;2| */

static Lisp_Object CC_BOOT__FRACUzeroWUDBU2(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V32, V33, V34;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FRAC;zero?;$B;2|\n");
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
    V32 = V3;
    stack[0] = V2;
/* end of prologue */
    V33 = V32;
    V32 = (Lisp_Object)193; /* 12 */
    V32 = Lgetv(nil, V33, V32);
    nil = C_nil;
    if (exception_pending()) goto V36;
    V33 = V32;
    if (!car_legal(V33)) goto V37;
    V34 = qcar(V33);
    V33 = stack[0];
    V33 = qcar(V33);
    if (!car_legal(V32)) goto V38;
    V32 = qcdr(V32);
        popv(1);
        return Lapply2(nil, 3, V34, V33, V32);
/* error exit handlers */
V38:
    popv(1);
    return error(1, err_bad_cdr, V32);
V37:
    popv(1);
    return error(1, err_bad_car, V33);
V36:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|POLYCATQ;variables;FL;5| (|f| |$|)
   (BOOT::|POLYCATQ;mymerge|
      (BOOT:SPADCALL
         (BOOT:SPADCALL |f| (VMLISP:QREFELT |$| 11))
         (VMLISP:QREFELT |$| 35))
      (BOOT:SPADCALL
         (BOOT:SPADCALL |f| (VMLISP:QREFELT |$| 12))
         (VMLISP:QREFELT |$| 35))
      |$|))

*/



/* Code for BOOT::|POLYCATQ;variables;FL;5| */

static Lisp_Object CC_BOOT__POLYCATQUvariablesUFLU5(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V110, V111, V112;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|POLYCATQ;variables;FL;5|\n");
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
    V111 = stack[-2];
    V110 = (Lisp_Object)561; /* 35 */
    V110 = Lgetv(nil, V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V118;
    env = stack[-5];
    stack[-1] = V110;
    V110 = stack[-1];
    if (!car_legal(V110)) goto V119;
    stack[0] = qcar(V110);
    V111 = stack[-2];
    V110 = (Lisp_Object)177; /* 11 */
    V110 = Lgetv(nil, V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V118;
    env = stack[-5];
    V111 = V110;
    if (!car_legal(V111)) goto V120;
    V112 = qcar(V111);
    V111 = stack[-3];
    if (!car_legal(V110)) goto V121;
    V110 = qcdr(V110);
    V110 = Lapply2(nil, 3, V112, V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V118;
    env = stack[-5];
    V111 = V110;
    V110 = stack[-1];
    if (!car_legal(V110)) goto V121;
    V110 = qcdr(V110);
    V110 = Lapply2(nil, 3, stack[0], V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V118;
    env = stack[-5];
    stack[-4] = V110;
    V111 = stack[-2];
    V110 = (Lisp_Object)561; /* 35 */
    V110 = Lgetv(nil, V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V118;
    env = stack[-5];
    stack[-1] = V110;
    V110 = stack[-1];
    if (!car_legal(V110)) goto V119;
    stack[0] = qcar(V110);
    V111 = stack[-2];
    V110 = (Lisp_Object)193; /* 12 */
    V110 = Lgetv(nil, V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V118;
    env = stack[-5];
    V111 = V110;
    if (!car_legal(V111)) goto V120;
    V112 = qcar(V111);
    V111 = stack[-3];
    if (!car_legal(V110)) goto V121;
    V110 = qcdr(V110);
    V110 = Lapply2(nil, 3, V112, V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V118;
    env = stack[-5];
    V111 = V110;
    V110 = stack[-1];
    if (!car_legal(V110)) goto V121;
    V110 = qcdr(V110);
    V110 = Lapply2(nil, 3, stack[0], V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V118;
    env = stack[-5];
    V111 = V110;
    V110 = stack[-2];
    {
        Lisp_Object V122 = stack[-4];
        popv(6);
        fn = elt(env, 1); /* BOOT::|POLYCATQ;mymerge| */
        return (*qfnn(fn))(qenv(fn), 3, V122, V111, V110);
    }
/* error exit handlers */
V121:
    popv(6);
    return error(1, err_bad_cdr, V110);
V120:
    popv(6);
    return error(1, err_bad_car, V111);
V119:
    popv(6);
    return error(1, err_bad_car, V110);
V118:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|INTDOM-;unitCanonical;2S;2| (|x| |$|)
   (VMLISP:QVELT (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 10)) 1))

*/



/* Code for BOOT::|INTDOM-;unitCanonical;2S;2| */

static Lisp_Object CC_BOOT__INTDOMKUunitCanonicalU2SU2(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V38, V39, V40;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|INTDOM-;unitCanonical;2S;2|\n");
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
    V38 = V3;
    stack[0] = V2;
/* end of prologue */
    V39 = V38;
    V38 = (Lisp_Object)161; /* 10 */
    V38 = Lgetv(nil, V39, V38);
    nil = C_nil;
    if (exception_pending()) goto V42;
    env = stack[-1];
    V39 = V38;
    if (!car_legal(V39)) goto V43;
    V40 = qcar(V39);
    V39 = stack[0];
    if (!car_legal(V38)) goto V44;
    V38 = qcdr(V38);
    V38 = Lapply2(nil, 3, V40, V39, V38);
    nil = C_nil;
    if (exception_pending()) goto V42;
    V39 = V38;
    V38 = (Lisp_Object)17; /* 1 */
        popv(2);
        return Lgetv(nil, V39, V38);
/* error exit handlers */
V44:
    popv(2);
    return error(1, err_bad_cdr, V38);
V43:
    popv(2);
    return error(1, err_bad_car, V39);
V42:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|STAGG-;concat;3A;7| (|x| |y| |$|)
   (BOOT:SPADCALL
      (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 26))
      |y|
      (VMLISP:QREFELT |$| 31)))

*/



/* Code for BOOT::|STAGG-;concat;3A;7| */

static Lisp_Object MS_CDECL CC_BOOT__STAGGKUconcatU3AU7(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V58, V59, V60;
    argcheck(nargs, 3, "STAGG-;concat;3A;7");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STAGG-;concat;3A;7|\n");
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
    V59 = stack[-1];
    V58 = (Lisp_Object)497; /* 31 */
    V58 = Lgetv(nil, V59, V58);
    nil = C_nil;
    if (exception_pending()) goto V66;
    env = stack[-5];
    stack[-4] = V58;
    V58 = stack[-4];
    if (!car_legal(V58)) goto V67;
    stack[0] = qcar(V58);
    V59 = stack[-1];
    V58 = (Lisp_Object)417; /* 26 */
    V58 = Lgetv(nil, V59, V58);
    nil = C_nil;
    if (exception_pending()) goto V66;
    env = stack[-5];
    V59 = V58;
    if (!car_legal(V59)) goto V68;
    V60 = qcar(V59);
    V59 = stack[-3];
    if (!car_legal(V58)) goto V69;
    V58 = qcdr(V58);
    V58 = Lapply2(nil, 3, V60, V59, V58);
    nil = C_nil;
    if (exception_pending()) goto V66;
    V60 = V58;
    V59 = stack[-2];
    V58 = stack[-4];
    if (!car_legal(V58)) goto V69;
    V58 = qcdr(V58);
    {
        Lisp_Object V70 = stack[0];
        popv(6);
        return Lapply3(nil, 4, V70, V60, V59, V58);
    }
/* error exit handlers */
V69:
    popv(6);
    return error(1, err_bad_cdr, V58);
V68:
    popv(6);
    return error(1, err_bad_car, V59);
V67:
    popv(6);
    return error(1, err_bad_car, V58);
V66:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|PR;degree;$E;4| (|p| |$|)
   (COND
      ((NULL |p|) (BOOT::|spadConstant| |$| 10))
      ('T (QCAR (BOOT::|SPADfirst| |p|)))) )

*/



/* Code for BOOT::|PR;degree;$E;4| */

static Lisp_Object CC_BOOT__PRUdegreeUDEU4(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V49, V50, V51;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PR;degree;$E;4|\n");
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
/* copy arguments values to proper place */
    V50 = V3;
    V51 = V2;
/* end of prologue */
    V49 = V51;
    if (V49 == nil) goto V18;
    V49 = lisp_true;
    if (V49 == nil) goto V34;
    V49 = V51;
    V50 = V49;
    V49 = V50;
    if (V49 == nil) goto V43;
    V49 = V50;
    if (!car_legal(V49)) goto V52;
    V49 = qcar(V49);
    goto V38;

V38:
    V49 = qcar(V49);
    return onevalue(V49);

V43:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V49 = (*qfnn(fn))(qenv(fn), 0);
    errexit();
    goto V38;

V34:
    V49 = nil;
    return onevalue(V49);

V18:
    V49 = (Lisp_Object)161; /* 10 */
    V49 = Lgetv(nil, V50, V49);
    errexit();
    V50 = V49;
    if (!car_legal(V50)) goto V53;
    V50 = qcar(V50);
    if (!car_legal(V49)) goto V54;
    V49 = qcdr(V49);
        return Lapply1(nil, V50, V49);
/* error exit handlers */
V54:
    return error(1, err_bad_cdr, V49);
V53:
    return error(1, err_bad_car, V50);
V52:
    return error(1, err_bad_car, V49);
}

/*
(DEFUN BOOT::|FS-;kernels;SL;60| (|x| |$|)
   (BOOT:SPADCALL
      (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 86))
      (VMLISP:QREFELT |$| 176)))

*/



/* Code for BOOT::|FS-;kernels;SL;60| */

static Lisp_Object CC_BOOT__FSKUkernelsUSLU60(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V54, V55, V56;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FS-;kernels;SL;60|\n");
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
    V54 = (Lisp_Object)2817; /* 176 */
    V54 = Lgetv(nil, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-4];
    stack[-3] = V54;
    V54 = stack[-3];
    if (!car_legal(V54)) goto V62;
    stack[0] = qcar(V54);
    V55 = stack[-1];
    V54 = (Lisp_Object)1377; /* 86 */
    V54 = Lgetv(nil, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-4];
    V55 = V54;
    if (!car_legal(V55)) goto V63;
    V56 = qcar(V55);
    V55 = stack[-2];
    if (!car_legal(V54)) goto V64;
    V54 = qcdr(V54);
    V54 = Lapply2(nil, 3, V56, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    V55 = V54;
    V54 = stack[-3];
    if (!car_legal(V54)) goto V64;
    V54 = qcdr(V54);
    {
        Lisp_Object V65 = stack[0];
        popv(5);
        return Lapply2(nil, 3, V65, V55, V54);
    }
/* error exit handlers */
V64:
    popv(5);
    return error(1, err_bad_cdr, V54);
V63:
    popv(5);
    return error(1, err_bad_car, V55);
V62:
    popv(5);
    return error(1, err_bad_car, V54);
V61:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::QUOTIENT2 (X Y) (VALUES (TRUNCATE X Y)))

*/



/* Code for BOOT::QUOTIENT2 */

static Lisp_Object CC_BOOT__QUOTIENT2(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V16, V17;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::QUOTIENT2\n");
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
    V16 = V3;
    V17 = V2;
/* end of prologue */
    fn = elt(env, 1); /* TRUNCATE */
    V16 = (*qfn2(fn))(qenv(fn), V17, V16);
    nil = C_nil;
    if (exception_pending()) goto V18;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* VALUES */
        return (*qfn1(fn))(qenv(fn), V16);
    }
/* error exit handlers */
V18:
    popv(1);
    return nil;
}

/*
(DEFUN VMLISP:CGREATERP (VMLISP::S1 VMLISP::S2)
   (|STRING>| (STRING VMLISP::S1) (STRING VMLISP::S2)))

*/



/* Code for VMLISP:CGREATERP */

static Lisp_Object CC_VMLISP__CGREATERP(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V17;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering VMLISP:CGREATERP\n");
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
    V17 = V2;
/* end of prologue */
    fn = elt(env, 1); /* STRING */
    stack[-1] = (*qfn1(fn))(qenv(fn), V17);
    nil = C_nil;
    if (exception_pending()) goto V20;
    env = stack[-2];
    V17 = stack[0];
    fn = elt(env, 1); /* STRING */
    V17 = (*qfn1(fn))(qenv(fn), V17);
    nil = C_nil;
    if (exception_pending()) goto V20;
    env = stack[-2];
    {
        Lisp_Object V21 = stack[-1];
        popv(3);
        fn = elt(env, 2); /* STRING>2 */
        return (*qfn2(fn))(qenv(fn), V21, V17);
    }
/* error exit handlers */
V20:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|IARRAY1;qelt;$IS;14| (|x| |i| |$|) (ELT |x| (|-| |i| 1)))

*/



/* Code for BOOT::|IARRAY1;qelt;$IS;14| */

static Lisp_Object MS_CDECL CC_BOOT__IARRAY1UqeltUDISU14(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V17, V18, V19;
    Lisp_Object fn;
    argcheck(nargs, 3, "IARRAY1;qelt;$IS;14");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IARRAY1;qelt;$IS;14|\n");
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
    push(nil);
/* copy arguments values to proper place */
    V17 = V4;
    V18 = V3;
    V19 = V2;
/* end of prologue */
    stack[0] = V19;
    V17 = V18;
    V17 = sub1(V17);
    nil = C_nil;
    if (exception_pending()) goto V21;
    env = stack[-1];
    {
        Lisp_Object V22 = stack[0];
        popv(2);
        fn = elt(env, 1); /* ELT */
        return (*qfn2(fn))(qenv(fn), V22, V17);
    }
/* error exit handlers */
V21:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|COMPCAT-;=;2SB;15| (|x| |y| |$|)
   (COND
      ((BOOT:SPADCALL
          (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 24))
          (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 24))
          (VMLISP:QREFELT |$| 102))
         (BOOT:SPADCALL
            (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 92))
            (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 92))
            (VMLISP:QREFELT |$| 102)))
      ('T 'NIL)))

*/



/* Code for BOOT::|COMPCAT-;=;2SB;15| */

static Lisp_Object MS_CDECL CC_BOOT__COMPCATKUMU2SBU15(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V162, V163, V164;
    argcheck(nargs, 3, "COMPCAT-;=;2SB;15");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPCAT-;=;2SB;15|\n");
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
    V163 = stack[-2];
    V162 = (Lisp_Object)1633; /* 102 */
    V162 = Lgetv(nil, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    env = stack[-6];
    stack[-5] = V162;
    V162 = stack[-5];
    if (!car_legal(V162)) goto V172;
    stack[-1] = qcar(V162);
    V163 = stack[-2];
    V162 = (Lisp_Object)385; /* 24 */
    V162 = Lgetv(nil, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    env = stack[-6];
    V163 = V162;
    if (!car_legal(V163)) goto V173;
    V164 = qcar(V163);
    V163 = stack[-4];
    if (!car_legal(V162)) goto V174;
    V162 = qcdr(V162);
    V162 = Lapply2(nil, 3, V164, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    env = stack[-6];
    stack[0] = V162;
    V163 = stack[-2];
    V162 = (Lisp_Object)385; /* 24 */
    V162 = Lgetv(nil, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    env = stack[-6];
    V163 = V162;
    if (!car_legal(V163)) goto V173;
    V164 = qcar(V163);
    V163 = stack[-3];
    if (!car_legal(V162)) goto V174;
    V162 = qcdr(V162);
    V162 = Lapply2(nil, 3, V164, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    env = stack[-6];
    V163 = V162;
    V162 = stack[-5];
    if (!car_legal(V162)) goto V174;
    V162 = qcdr(V162);
    V162 = Lapply3(nil, 4, stack[-1], stack[0], V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    env = stack[-6];
    if (V162 == nil) goto V11;
    V163 = stack[-2];
    V162 = (Lisp_Object)1633; /* 102 */
    V162 = Lgetv(nil, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    env = stack[-6];
    stack[-1] = V162;
    V162 = stack[-1];
    if (!car_legal(V162)) goto V172;
    stack[0] = qcar(V162);
    V163 = stack[-2];
    V162 = (Lisp_Object)1473; /* 92 */
    V162 = Lgetv(nil, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    env = stack[-6];
    V163 = V162;
    if (!car_legal(V163)) goto V173;
    V164 = qcar(V163);
    V163 = stack[-4];
    if (!car_legal(V162)) goto V174;
    V162 = qcdr(V162);
    V162 = Lapply2(nil, 3, V164, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    env = stack[-6];
    stack[-4] = V162;
    V163 = stack[-2];
    V162 = (Lisp_Object)1473; /* 92 */
    V162 = Lgetv(nil, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    env = stack[-6];
    V163 = V162;
    if (!car_legal(V163)) goto V173;
    V164 = qcar(V163);
    V163 = stack[-3];
    if (!car_legal(V162)) goto V174;
    V162 = qcdr(V162);
    V162 = Lapply2(nil, 3, V164, V163, V162);
    nil = C_nil;
    if (exception_pending()) goto V171;
    V163 = V162;
    V162 = stack[-1];
    if (!car_legal(V162)) goto V174;
    V162 = qcdr(V162);
    {
        Lisp_Object V175 = stack[0];
        Lisp_Object V176 = stack[-4];
        popv(7);
        return Lapply3(nil, 4, V175, V176, V163, V162);
    }

V11:
    V162 = lisp_true;
    if (V162 == nil) goto V159;
    V162 = nil;
    { popv(7); return onevalue(V162); }

V159:
    V162 = nil;
    { popv(7); return onevalue(V162); }
/* error exit handlers */
V174:
    popv(7);
    return error(1, err_bad_cdr, V162);
V173:
    popv(7);
    return error(1, err_bad_car, V163);
V172:
    popv(7);
    return error(1, err_bad_car, V162);
V171:
    popv(7);
    return nil;
}

/*
(DEFUN VMLISP:GETL (VMLISP::SYM VMLISP::KEY)
   (COND
      ((CONSP VMLISP::SYM) (CDR (VMLISP:ASSQ VMLISP::KEY VMLISP::SYM)))
      ((SYMBOLP VMLISP::SYM) (GET VMLISP::SYM VMLISP::KEY))))

*/



/* Code for VMLISP:GETL */

static Lisp_Object CC_VMLISP__GETL(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V33, V34;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering VMLISP:GETL\n");
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
    V33 = stack[-1];
    if (!consp(V33)) goto V10;
    V34 = stack[0];
    V33 = stack[-1];
    V33 = Latsoc(nil, V34, V33);
    if (!car_legal(V33)) goto V37;
    V33 = qcdr(V33);
    { popv(3); return onevalue(V33); }

V10:
    V33 = stack[-1];
    fn = elt(env, 1); /* SYMBOLP */
    V33 = (*qfn1(fn))(qenv(fn), V33);
    nil = C_nil;
    if (exception_pending()) goto V38;
    env = stack[-2];
    if (V33 == nil) goto V22;
    V34 = stack[-1];
    V33 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* GET */
        return (*qfn2(fn))(qenv(fn), V34, V33);
    }

V22:
    V33 = nil;
    { popv(3); return onevalue(V33); }
/* error exit handlers */
V38:
    popv(3);
    return nil;
V37:
    popv(3);
    return error(1, err_bad_cdr, V33);
}

/*
(DEFUN BOOT::|IDPO;=;2$B;1| (|x| |y| |$|)
   (PROG (#:G82362)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (SEQ
                     BOOT::G190
                     (COND
                        ((NULL
                            (COND
                               ((OR (NULL |x|) (NULL |y|)) 'NIL)
                               ('T 'T)))
                           (GO BOOT::G191)))
                     (SEQ
                        (EXIT
                           (COND
                              ((OR
                                  (NULL
                                     (BOOT:SPADCALL
                                        (QCAR (BOOT::|SPADfirst| |x|))
                                        (QCAR (BOOT::|SPADfirst| |y|))
                                        (VMLISP:QREFELT |$| 11)))
                                  (NULL
                                     (BOOT:SPADCALL
                                        (QCDR (BOOT::|SPADfirst| |x|))
                                        (QCDR (BOOT::|SPADfirst| |y|))
                                        (VMLISP:QREFELT |$| 12))))
                                 (PROGN
                                    (BOOT::LETT
                                       #:G82362
                                       'NIL
                                       BOOT::|IDPO;=;2$B;1|)
                                    (GO #:G82362)))
                              ('T
                                 (SEQ
                                    (BOOT::LETT
                                       |x|
                                       (CDR |x|)
                                       BOOT::|IDPO;=;2$B;1|)
                                    (EXIT
                                       (BOOT::LETT
                                          |y|
                                          (CDR |y|)
                                          BOOT::|IDPO;=;2$B;1|)))) )))
                     NIL
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT NIL))
                  (EXIT (COND ((NULL |x|) (NULL |y|)) ('T 'NIL)))) )
            #:G82362
            (EXIT #:G82362)))) )

*/



/* Code for BOOT::|IDPO;=;2$B;1| */

static Lisp_Object MS_CDECL CC_BOOT__IDPOUMU2DBU1(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V176, V177;
    Lisp_Object fn;
    argcheck(nargs, 3, "IDPO;=;2$B;1");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IDPO;=;2$B;1|\n");
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

V18:
    V176 = stack[-4];
    if (V176 == nil) goto V26;
    V176 = stack[-3];
    if (V176 == nil) goto V26;
    V176 = lisp_true;
    if (V176 == nil) goto V34;
    V176 = lisp_true;
    goto V25;

V25:
    if (V176 == nil) goto V17;
    V177 = stack[-2];
    V176 = (Lisp_Object)177; /* 11 */
    V176 = Lgetv(nil, V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V184;
    env = stack[-6];
    stack[-5] = V176;
    V176 = stack[-5];
    if (!car_legal(V176)) goto V185;
    stack[-1] = qcar(V176);
    V176 = stack[-4];
    V177 = V176;
    V176 = V177;
    if (V176 == nil) goto V74;
    V176 = V177;
    if (!car_legal(V176)) goto V185;
    V176 = qcar(V176);
    goto V69;

V69:
    stack[0] = qcar(V176);
    V176 = stack[-3];
    V177 = V176;
    V176 = V177;
    if (V176 == nil) goto V87;
    V176 = V177;
    if (!car_legal(V176)) goto V185;
    V176 = qcar(V176);
    goto V82;

V82:
    V177 = qcar(V176);
    V176 = stack[-5];
    if (!car_legal(V176)) goto V186;
    V176 = qcdr(V176);
    V176 = Lapply3(nil, 4, stack[-1], stack[0], V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V184;
    env = stack[-6];
    if (V176 == nil) goto V41;
    V177 = stack[-2];
    V176 = (Lisp_Object)193; /* 12 */
    V176 = Lgetv(nil, V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V184;
    env = stack[-6];
    stack[-5] = V176;
    V176 = stack[-5];
    if (!car_legal(V176)) goto V185;
    stack[-1] = qcar(V176);
    V176 = stack[-4];
    V177 = V176;
    V176 = V177;
    if (V176 == nil) goto V126;
    V176 = V177;
    if (!car_legal(V176)) goto V185;
    V176 = qcar(V176);
    goto V121;

V121:
    stack[0] = qcdr(V176);
    V176 = stack[-3];
    V177 = V176;
    V176 = V177;
    if (V176 == nil) goto V139;
    V176 = V177;
    if (!car_legal(V176)) goto V185;
    V176 = qcar(V176);
    goto V134;

V134:
    V177 = qcdr(V176);
    V176 = stack[-5];
    if (!car_legal(V176)) goto V186;
    V176 = qcdr(V176);
    V176 = Lapply3(nil, 4, stack[-1], stack[0], V177, V176);
    nil = C_nil;
    if (exception_pending()) goto V184;
    env = stack[-6];
    if (V176 == nil) goto V41;
    V176 = lisp_true;
    if (V176 == nil) goto V18;
    V176 = stack[-4];
    if (!car_legal(V176)) goto V186;
    V176 = qcdr(V176);
    stack[-4] = V176;
    V176 = stack[-3];
    if (!car_legal(V176)) goto V186;
    V176 = qcdr(V176);
    stack[-3] = V176;
    goto V18;

V41:
    V176 = nil;
    { popv(7); return onevalue(V176); }

V139:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V176 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V184;
    env = stack[-6];
    goto V134;

V126:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V176 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V184;
    env = stack[-6];
    goto V121;

V87:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V176 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V184;
    env = stack[-6];
    goto V82;

V74:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V176 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V184;
    env = stack[-6];
    goto V69;

V17:
    V176 = stack[-4];
    if (V176 == nil) goto V164;
    V176 = lisp_true;
    if (V176 == nil) goto V170;
    V176 = nil;
    { popv(7); return onevalue(V176); }

V170:
    V176 = nil;
    { popv(7); return onevalue(V176); }

V164:
    V176 = stack[-3];
    V176 = (V176 == nil ? lisp_true : nil);
    { popv(7); return onevalue(V176); }

V34:
    V176 = nil;
    goto V25;

V26:
    V176 = nil;
    goto V25;
/* error exit handlers */
V186:
    popv(7);
    return error(1, err_bad_cdr, V176);
V185:
    popv(7);
    return error(1, err_bad_car, V176);
V184:
    popv(7);
    return nil;
}



setup_type const u03_setup[] =
{
    {"BOOT@@PERMGRP;testIdentity@@Builtin",too_few_2,CC_BOOT__PERMGRPUtestIdentity,wrong_no_2},
    {"BOOT@@STAGG-;elt;AIS;5@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__STAGGKUeltUAISU5},
    {"BOOT@@PRIMARR;#;$Nni;1@@Builtin",too_few_2,CC_BOOT__PRIMARRUZUDNniU1,wrong_no_2},
    {"BOOT@@termMatch@@Builtin",wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__termMatch},
    {"BOOT@@IFARRAY;elt;$IS;17@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IFARRAYUeltUDISU17},
    {"BOOT@@ILIST;empty;$;6@@Builtin",CC_BOOT__ILISTUemptyUDU6,too_many_1,wrong_no_1},
    {"BOOT@@GETALIST@@Builtin", too_few_2,      CC_BOOT__GETALIST,wrong_no_2},
    {"BOOT@@opOf@@Builtin",     CC_BOOT__opOf,  too_many_1,    wrong_no_1},
    {"BOOT@@BOP;name;$S;2@@Builtin",too_few_2,  CC_BOOT__BOPUnameUDSU2,wrong_no_2},
    {"BOOT@@INT;one?;$B;7@@Builtin",too_few_2,  CC_BOOT__INTUoneWUDBU7,wrong_no_2},
    {"BOOT@@isPatternVar@@Builtin",CC_BOOT__isPatternVar,too_many_1,wrong_no_1},
    {"BOOT@@ILIST;copy;2$;20@@Builtin",too_few_2,CC_BOOT__ILISTUcopyU2DU20,wrong_no_2},
    {"BOOT@@IFARRAY;setelt;$I2S;18@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IFARRAYUseteltUDI2SU18},
    {"BOOT@@ALIST;search;Key$U;15@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__ALISTUsearchUKeyDUU15},
    {"BOOT@@getOpCode@@Builtin",wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__getOpCode},
    {"BOOT@@SMP;zero?;$B;3@@Builtin",too_few_2, CC_BOOT__SMPUzeroWUDBU3,wrong_no_2},
    {"BOOT@@ELTAGG-;qelt;SDomIm;1@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__ELTAGGKUqeltUSDomImU1},
    {"BOOT@@SMP;one?;$B;4@@Builtin",too_few_2,  CC_BOOT__SMPUoneWUDBU4,wrong_no_2},
    {"BOOT@@ELAGG-;removeDuplicates;2A;12@@Builtin",too_few_2,CC_BOOT__ELAGGKUremoveDuplicatesU2AU12,wrong_no_2},
    {"BOOT@@SMP;=;2$B;29@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__SMPUMU2DBU29},
    {"BOOT@@PR;reductum;2$;8@@Builtin",too_few_2,CC_BOOT__PRUreductumU2DU8,wrong_no_2},
    {"BOOT@@SMP;variables;$L;62@@Builtin",too_few_2,CC_BOOT__SMPUvariablesUDLU62,wrong_no_2},
    {"BOOT@@isDomain@@Builtin", CC_BOOT__isDomain,too_many_1,  wrong_no_1},
    {"BOOT@@PR;leadingCoefficient;$R;6@@Builtin",too_few_2,CC_BOOT__PRUleadingCoefficientUDRU6,wrong_no_2},
    {"BOOT@@KERNEL;position;$Nni;7@@Builtin",too_few_2,CC_BOOT__KERNELUpositionUDNniU7,wrong_no_2},
    {"BOOT@@lazyMatchArg@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__lazyMatchArg},
    {"BOOT@@containsVars1@@Builtin",CC_BOOT__containsVars1,too_many_1,wrong_no_1},
    {"BOOT@@subCopy@@Builtin",  too_few_2,      CC_BOOT__subCopy,wrong_no_2},
    {"BOOT@@isFreeFunctionFromMmCond@@Builtin",CC_BOOT__isFreeFunctionFromMmCond,too_many_1,wrong_no_1},
    {"BOOT@@ILIST;first;$S;4@@Builtin",too_few_2,CC_BOOT__ILISTUfirstUDSU4,wrong_no_2},
    {"BOOT@@ELTAGG-;qsetelt!;SDom2Im;2@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__ELTAGGKUqseteltBUSDom2ImU2},
    {"BOOT@@isFreeFunctionFromMm@@Builtin",CC_BOOT__isFreeFunctionFromMm,too_many_1,wrong_no_1},
    {"BOOT@@BOP;property;$SU;7@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__BOPUpropertyUDSUU7},
    {"BOOT@@EXPR;numer;$Smp;22@@Builtin",too_few_2,CC_BOOT__EXPRUnumerUDSmpU22,wrong_no_2},
    {"BOOT@@EXPR;numer;$Smp;126@@Builtin",too_few_2,CC_BOOT__EXPRUnumerUDSmpU126,wrong_no_2},
    {"BOOT@@KERNEL;B2Z@@Builtin",too_few_2,     CC_BOOT__KERNELUB2Z,wrong_no_2},
    {"BOOT@@EXPR;denom;$Smp;23@@Builtin",too_few_2,CC_BOOT__EXPRUdenomUDSmpU23,wrong_no_2},
    {"BOOT@@ILIST;sort!;M2$;27@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__ILISTUsortBUM2DU27},
    {"BOOT@@SMP;*;R2$;26@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__SMPUHUR2DU26},
    {"BOOT@@getDomainFromMm@@Builtin",CC_BOOT__getDomainFromMm,too_many_1,wrong_no_1},
    {"BOOT@@FRAC;zero?;$B;2@@Builtin",too_few_2,CC_BOOT__FRACUzeroWUDBU2,wrong_no_2},
    {"BOOT@@POLYCATQ;variables;FL;5@@Builtin",too_few_2,CC_BOOT__POLYCATQUvariablesUFLU5,wrong_no_2},
    {"BOOT@@INTDOM-;unitCanonical;2S;2@@Builtin",too_few_2,CC_BOOT__INTDOMKUunitCanonicalU2SU2,wrong_no_2},
    {"BOOT@@STAGG-;concat;3A;7@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__STAGGKUconcatU3AU7},
    {"BOOT@@PR;degree;$E;4@@Builtin",too_few_2, CC_BOOT__PRUdegreeUDEU4,wrong_no_2},
    {"BOOT@@FS-;kernels;SL;60@@Builtin",too_few_2,CC_BOOT__FSKUkernelsUSLU60,wrong_no_2},
    {"BOOT@@QUOTIENT2@@Builtin",too_few_2,      CC_BOOT__QUOTIENT2,wrong_no_2},
    {"VMLISP@@CGREATERP@@Builtin",too_few_2,    CC_VMLISP__CGREATERP,wrong_no_2},
    {"BOOT@@IARRAY1;qelt;$IS;14@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IARRAY1UqeltUDISU14},
    {"BOOT@@COMPCAT-;=;2SB;15@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__COMPCATKUMU2SBU15},
    {"VMLISP@@GETL@@Builtin",   too_few_2,      CC_VMLISP__GETL,wrong_no_2},
    {"BOOT@@IDPO;=;2$B;1@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__IDPOUMU2DBU1},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
