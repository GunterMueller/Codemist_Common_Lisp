
/* u07.c                 Machine generated C code */

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
(DEFUN BOOT::|FLASORT;QuickSort| (|l| |r| |i| |j| |$|)
   (PROG (|n| #:G82404 |k|)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (BOOT::LETT |n| (|-| |j| |i|) BOOT::|FLASORT;QuickSort|)
                  (COND
                     ((ONEP |n|)
                        (COND
                           ((BOOT:SPADCALL
                               (BOOT:SPADCALL
                                  |r|
                                  |j|
                                  (VMLISP:QREFELT |$| 13))
                               (BOOT:SPADCALL
                                  |r|
                                  |i|
                                  (VMLISP:QREFELT |$| 13))
                               |l|)
                              (BOOT:SPADCALL
                                 |r|
                                 |i|
                                 |j|
                                 (VMLISP:QREFELT |$| 20)))) ))
                  (EXIT
                     (COND
                        ((|<| |n| 2)
                           (PROGN
                              (BOOT::LETT
                                 #:G82404
                                 |r|
                                 BOOT::|FLASORT;QuickSort|)
                              (GO #:G82404)))
                        ('T
                           (SEQ
                              (BOOT::LETT
                                 |k|
                                 (BOOT::|FLASORT;partition| |l| |r| |i| |j|
                                    (|+| |i| (ASH |n| -1)) |$|)
                                 BOOT::|FLASORT;QuickSort|)
                              (BOOT::|FLASORT;QuickSort|
                                 |l|
                                 |r|
                                 |i|
                                 (|-| |k| 1)
                                 |$|)
                              (EXIT
                                 (BOOT::|FLASORT;QuickSort|
                                    |l|
                                    |r|
                                    (|+| |k| 1)
                                    |j|
                                    |$|)))) ))) )
            #:G82404
            (EXIT #:G82404)))) )

*/



/* Code for BOOT::|FLASORT;QuickSort| */

static Lisp_Object MS_CDECL CC_BOOT__FLASORTUQuickSort(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5,
                         Lisp_Object V6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V232, V233, V234, V235, V236;
    Lisp_Object fn;
    argcheck(nargs, 5, "FLASORT;QuickSort");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FLASORT;QuickSort|\n");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-5] = V6;
    stack[-6] = V5;
    stack[-7] = V4;
    stack[-8] = V3;
    stack[-9] = V2;
/* end of prologue */

V21:
    V233 = stack[-6];
    V232 = stack[-7];
    V232 = difference2(V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    stack[-10] = V232;
    V232 = stack[-10];
    V232 = Lonep(nil, V232);
    env = stack[-11];
    if (V232 == nil) goto V145;
    V232 = stack[-9];
    stack[-2] = V232;
    V232 = stack[-2];
    if (!car_legal(V232)) goto V249;
    stack[-1] = qcar(V232);
    V233 = stack[-5];
    V232 = (Lisp_Object)209; /* 13 */
    V232 = Lgetv(nil, V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    V233 = V232;
    if (!car_legal(V233)) goto V250;
    V235 = qcar(V233);
    V234 = stack[-8];
    V233 = stack[-6];
    if (!car_legal(V232)) goto V251;
    V232 = qcdr(V232);
    V232 = Lapply3(nil, 4, V235, V234, V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    stack[0] = V232;
    V233 = stack[-5];
    V232 = (Lisp_Object)209; /* 13 */
    V232 = Lgetv(nil, V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    V233 = V232;
    if (!car_legal(V233)) goto V250;
    V235 = qcar(V233);
    V234 = stack[-8];
    V233 = stack[-7];
    if (!car_legal(V232)) goto V251;
    V232 = qcdr(V232);
    V232 = Lapply3(nil, 4, V235, V234, V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    V233 = V232;
    V232 = stack[-2];
    if (!car_legal(V232)) goto V251;
    V232 = qcdr(V232);
    V232 = Lapply3(nil, 4, stack[-1], stack[0], V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    if (V232 == nil) goto V145;
    V233 = stack[-5];
    V232 = (Lisp_Object)321; /* 20 */
    V232 = Lgetv(nil, V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    V233 = V232;
    if (!car_legal(V233)) goto V250;
    V236 = qcar(V233);
    V235 = stack[-8];
    V234 = stack[-7];
    V233 = stack[-6];
    if (!car_legal(V232)) goto V251;
    V232 = qcdr(V232);
    fn = elt(env, 1); /* FUNCALL* */
    V232 = (*qfnn(fn))(qenv(fn), 5, V236, V235, V234, V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    goto V145;

V145:
    V233 = stack[-10];
    V232 = (Lisp_Object)33; /* 2 */
    V232 = (Lisp_Object)lessp2(V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    V232 = V232 ? lisp_true : nil;
    env = stack[-11];
    if (!(V232 == nil)) { Lisp_Object res = stack[-8]; popv(12); return onevalue(res); }
    V232 = lisp_true;
    if (V232 == nil) goto V154;
    stack[-4] = stack[-9];
    stack[-3] = stack[-8];
    stack[-2] = stack[-7];
    stack[-1] = stack[-6];
    stack[0] = stack[-7];
    V233 = stack[-10];
    V232 = (Lisp_Object)-15; /* -1 */
    V232 = Lash1(nil, V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    V233 = plus2(stack[0], V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    V232 = stack[-5];
    fn = elt(env, 2); /* BOOT::|FLASORT;partition| */
    V232 = (*qfnn(fn))(qenv(fn), 6, stack[-4], stack[-3], stack[-2], stack[-1], V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    stack[-2] = V232;
    stack[-1] = stack[-9];
    stack[0] = stack[-8];
    stack[-3] = stack[-7];
    V232 = stack[-2];
    V233 = sub1(V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    V232 = stack[-5];
    V232 = CC_BOOT__FLASORTUQuickSort(env, 5, stack[-1], stack[0], stack[-3], V233, V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    stack[-1] = stack[-9];
    stack[0] = stack[-8];
    V232 = stack[-2];
    V234 = add1(V232);
    nil = C_nil;
    if (exception_pending()) goto V248;
    env = stack[-11];
    V233 = stack[-6];
    V232 = stack[-5];
    stack[-9] = stack[-1];
    stack[-8] = stack[0];
    stack[-7] = V234;
    stack[-6] = V233;
    stack[-5] = V232;
    goto V21;

V154:
    V232 = nil;
    { popv(12); return onevalue(V232); }
/* error exit handlers */
V251:
    popv(12);
    return error(1, err_bad_cdr, V232);
V250:
    popv(12);
    return error(1, err_bad_car, V233);
V249:
    popv(12);
    return error(1, err_bad_car, V232);
V248:
    popv(12);
    return nil;
}

/*
(DEFUN BOOT::|EXPR;algkernels!0| (BOOT::|#1| |$|)
   (BOOT:SPADCALL
      (BOOT:SPADCALL BOOT::|#1| (VMLISP:QREFELT |$| 86))
      "%alg"
      (VMLISP:QREFELT |$| 87)))

*/



/* Code for BOOT::|EXPR;algkernels!0| */

static Lisp_Object CC_BOOT__EXPRUalgkernelsB0(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V57, V58, V59;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;algkernels!0|\n");
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
    V58 = stack[-1];
    V57 = (Lisp_Object)1393; /* 87 */
    V57 = Lgetv(nil, V58, V57);
    nil = C_nil;
    if (exception_pending()) goto V64;
    env = stack[-4];
    stack[-3] = V57;
    V57 = stack[-3];
    if (!car_legal(V57)) goto V65;
    stack[0] = qcar(V57);
    V58 = stack[-1];
    V57 = (Lisp_Object)1377; /* 86 */
    V57 = Lgetv(nil, V58, V57);
    nil = C_nil;
    if (exception_pending()) goto V64;
    env = stack[-4];
    V58 = V57;
    if (!car_legal(V58)) goto V66;
    V59 = qcar(V58);
    V58 = stack[-2];
    if (!car_legal(V57)) goto V67;
    V57 = qcdr(V57);
    V57 = Lapply2(nil, 3, V59, V58, V57);
    nil = C_nil;
    if (exception_pending()) goto V64;
    env = stack[-4];
    V58 = V57;
    V59 = elt(env, 1); /* "%alg" */
    V57 = stack[-3];
    if (!car_legal(V57)) goto V67;
    V57 = qcdr(V57);
    {
        Lisp_Object V68 = stack[0];
        popv(5);
        return Lapply3(nil, 4, V68, V58, V59, V57);
    }
/* error exit handlers */
V67:
    popv(5);
    return error(1, err_bad_cdr, V57);
V66:
    popv(5);
    return error(1, err_bad_car, V58);
V65:
    popv(5);
    return error(1, err_bad_car, V57);
V64:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|pfAbSynOp?| (BOOT::|form| BOOT::|op|)
   (PROG (BOOT::|hd|)
      (RETURN
         (PROGN
            (SETQ BOOT::|hd| (CAR BOOT::|form|))
            (OR
               (EQ BOOT::|hd| BOOT::|op|)
               (EQCAR BOOT::|hd| BOOT::|op|)))) ))

*/



/* Code for BOOT::|pfAbSynOp?| */

static Lisp_Object CC_BOOT__pfAbSynOpW(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33, V34;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|pfAbSynOp?|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V33 = V3;
    V31 = V2;
/* end of prologue */
    if (!car_legal(V31)) goto V35;
    V31 = qcar(V31);
    V34 = V31;
    V32 = V34;
    V31 = V33;
    V31 = (V32 == V31 ? lisp_true : nil);
    if (!(V31 == nil)) return onevalue(V31);
    V31 = V34;
    V32 = V33;
        return Leqcar(nil, V31, V32);
/* error exit handlers */
V35:
    return error(1, err_bad_car, V31);
}

/*
(DEFUN BOOT::|COMPLEX;*;3$;15| (|x| |y| |$|)
   (CONS
      (BOOT:SPADCALL
         (BOOT:SPADCALL (QCAR |x|) (QCAR |y|) (VMLISP:QREFELT |$| 40))
         (BOOT:SPADCALL (QCDR |x|) (QCDR |y|) (VMLISP:QREFELT |$| 40))
         (VMLISP:QREFELT |$| 41))
      (BOOT:SPADCALL
         (BOOT:SPADCALL (QCDR |x|) (QCAR |y|) (VMLISP:QREFELT |$| 40))
         (BOOT:SPADCALL (QCDR |y|) (QCAR |x|) (VMLISP:QREFELT |$| 40))
         (VMLISP:QREFELT |$| 38))))

*/



/* Code for BOOT::|COMPLEX;*;3$;15| */

static Lisp_Object MS_CDECL CC_BOOT__COMPLEXUHU3DU15(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V180, V181, V182, V183;
    argcheck(nargs, 3, "COMPLEX;*;3$;15");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPLEX;*;3$;15|\n");
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
    V181 = stack[-3];
    V180 = (Lisp_Object)657; /* 41 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[-2] = V180;
    V180 = stack[-2];
    if (!car_legal(V180)) goto V192;
    stack[-1] = qcar(V180);
    V181 = stack[-3];
    V180 = (Lisp_Object)641; /* 40 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V181 = V180;
    if (!car_legal(V181)) goto V193;
    V183 = qcar(V181);
    V181 = stack[-5];
    V182 = qcar(V181);
    V181 = stack[-4];
    V181 = qcar(V181);
    if (!car_legal(V180)) goto V194;
    V180 = qcdr(V180);
    V180 = Lapply3(nil, 4, V183, V182, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[0] = V180;
    V181 = stack[-3];
    V180 = (Lisp_Object)641; /* 40 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V181 = V180;
    if (!car_legal(V181)) goto V193;
    V183 = qcar(V181);
    V181 = stack[-5];
    V182 = qcdr(V181);
    V181 = stack[-4];
    V181 = qcdr(V181);
    if (!car_legal(V180)) goto V194;
    V180 = qcdr(V180);
    V180 = Lapply3(nil, 4, V183, V182, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V181 = V180;
    V180 = stack[-2];
    if (!car_legal(V180)) goto V194;
    V180 = qcdr(V180);
    V180 = Lapply3(nil, 4, stack[-1], stack[0], V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[-6] = V180;
    V181 = stack[-3];
    V180 = (Lisp_Object)609; /* 38 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[-2] = V180;
    V180 = stack[-2];
    if (!car_legal(V180)) goto V192;
    stack[-1] = qcar(V180);
    V181 = stack[-3];
    V180 = (Lisp_Object)641; /* 40 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V181 = V180;
    if (!car_legal(V181)) goto V193;
    V183 = qcar(V181);
    V181 = stack[-5];
    V182 = qcdr(V181);
    V181 = stack[-4];
    V181 = qcar(V181);
    if (!car_legal(V180)) goto V194;
    V180 = qcdr(V180);
    V180 = Lapply3(nil, 4, V183, V182, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    stack[0] = V180;
    V181 = stack[-3];
    V180 = (Lisp_Object)641; /* 40 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V181 = V180;
    if (!car_legal(V181)) goto V193;
    V183 = qcar(V181);
    V181 = stack[-4];
    V182 = qcdr(V181);
    V181 = stack[-5];
    V181 = qcar(V181);
    if (!car_legal(V180)) goto V194;
    V180 = qcdr(V180);
    V180 = Lapply3(nil, 4, V183, V182, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-7];
    V181 = V180;
    V180 = stack[-2];
    if (!car_legal(V180)) goto V194;
    V180 = qcdr(V180);
    V180 = Lapply3(nil, 4, stack[-1], stack[0], V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V191;
    {
        Lisp_Object V195 = stack[-6];
        popv(8);
        { Lisp_Object retVal = cons(V195, V180);
        errexit();
        return onevalue(retVal); }
    }
/* error exit handlers */
V194:
    popv(8);
    return error(1, err_bad_cdr, V180);
V193:
    popv(8);
    return error(1, err_bad_car, V181);
V192:
    popv(8);
    return error(1, err_bad_car, V180);
V191:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|selectMmsGen,exact?| (BOOT::|mmS| BOOT::|tar| BOOT::|args|)
   (PROG (BOOT::|sig| BOOT::|mmC| |c| |t| |a| BOOT::|ok| BOOT::|ex|
         BOOT::|inex|)
      (RETURN
         (SEQ
            (BOOT:SPADLET BOOT::|ex| (BOOT:SPADLET BOOT::|inex| NIL))
            (DO ((#:G18952 BOOT::|mmS| (CDR #:G18952)) (BOOT::|mm| NIL))
               ((OR
                   (ATOM #:G18952)
                   (PROGN (SETQ BOOT::|mm| (CAR #:G18952)) NIL)
                   (PROGN
                      (PROGN
                         (BOOT:SPADLET BOOT::|sig| (CAR BOOT::|mm|))
                         (BOOT:SPADLET BOOT::|mmC| (CAADR BOOT::|mm|))
                         BOOT::|mm|)
                      NIL))
                  NIL)
               (SEQ
                  (PROGN
                     (BOOT:SPADLET |c| (CAR BOOT::|sig|))
                     (BOOT:SPADLET |t| (CADR BOOT::|sig|))
                     (BOOT:SPADLET |a| (CDDR BOOT::|sig|))
                     BOOT::|sig|)
                  (BOOT:SPADLET BOOT::|ok| 'T)
                  (DO ((#:G18953 |a| (CDR #:G18953))
                        (BOOT::|pat| NIL)
                        (#:G18954 BOOT::|args| (CDR #:G18954))
                        (BOOT::|arg| NIL))
                     ((OR
                         (ATOM #:G18953)
                         (PROGN (SETQ BOOT::|pat| (CAR #:G18953)) NIL)
                         (ATOM #:G18954)
                         (PROGN (SETQ BOOT::|arg| (CAR #:G18954)) NIL)
                         (NULL BOOT::|ok|))
                        NIL)
                     (SEQ
                        (EXIT
                           (IF (NULL
                                 (CONTAINED
                                    (CONS
                                       'BOOT::|isDomain|
                                       (CONS
                                          BOOT::|pat|
                                          (CONS BOOT::|arg| NIL)))
                                    BOOT::|mmC|))
                              (EXIT (BOOT:SPADLET BOOT::|ok| NIL)))) ))
                  (IF BOOT::|ok|
                     (EXIT
                        (BOOT:SPADLET
                           BOOT::|ex|
                           (CONS BOOT::|mm| BOOT::|ex|))))
                  (EXIT
                     (BOOT:SPADLET
                        BOOT::|inex|
                        (CONS BOOT::|mm| BOOT::|inex|)))) )
            (EXIT (CONS BOOT::|ex| (CONS BOOT::|inex| NIL)))) )))

*/



/* Code for BOOT::|selectMmsGen,exact?| */

static Lisp_Object MS_CDECL CC_BOOT__selectMmsGenPexactW(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V175, V176, V177;
    Lisp_Object fn;
    argcheck(nargs, 3, "selectMmsGen,exact?");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|selectMmsGen,exact?|\n");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = V4;
    V175 = V3;
    V176 = V2;
/* end of prologue */
    V175 = nil;
    stack[-6] = V175;
    stack[-7] = V175;
    V175 = V176;
    stack[-4] = V175;
    goto V27;

V27:
    V175 = stack[-4];
    if (!consp(V175)) goto V164;
    V175 = stack[-4];
    if (!car_legal(V175)) goto V189;
    V175 = qcar(V175);
    stack[-5] = V175;
    V175 = nil;
    if (!(V175 == nil)) goto V164;
    V175 = stack[-5];
    if (!car_legal(V175)) goto V189;
    V175 = qcar(V175);
    V176 = V175;
    V175 = stack[-5];
    if (!car_legal(V175)) goto V190;
    V175 = qcdr(V175);
    if (!car_legal(V175)) goto V189;
    V175 = qcar(V175);
    if (!car_legal(V175)) goto V189;
    V175 = qcar(V175);
    stack[-10] = V175;
    V175 = nil;
    if (!(V175 == nil)) goto V164;
    V175 = V176;
    if (!car_legal(V175)) goto V190;
    V175 = qcdr(V175);
    if (!car_legal(V175)) goto V190;
    V175 = qcdr(V175);
    V176 = lisp_true;
    stack[-8] = V176;
    V176 = stack[-9];
    stack[-3] = V176;
    stack[-2] = V175;
    goto V71;

V71:
    V175 = stack[-2];
    if (!consp(V175)) goto V62;
    V175 = stack[-2];
    if (!car_legal(V175)) goto V189;
    V175 = qcar(V175);
    V176 = V175;
    V175 = nil;
    if (!(V175 == nil)) goto V62;
    V175 = stack[-3];
    if (!consp(V175)) goto V62;
    V175 = stack[-3];
    if (!car_legal(V175)) goto V189;
    V175 = qcar(V175);
    V177 = V175;
    V175 = nil;
    if (!(V175 == nil)) goto V62;
    V175 = stack[-8];
    if (V175 == nil) goto V62;
    stack[-1] = elt(env, 1); /* BOOT::|isDomain| */
    stack[0] = V176;
    V175 = V177;
    V175 = ncons(V175);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-11];
    V176 = list2star(stack[-1], stack[0], V175);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-11];
    V175 = stack[-10];
    fn = elt(env, 2); /* CONTAINED */
    V175 = (*qfn2(fn))(qenv(fn), V176, V175);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-11];
    if (!(V175 == nil)) goto V93;
    V175 = nil;
    stack[-8] = V175;
    goto V93;

V93:
    V175 = stack[-2];
    if (!car_legal(V175)) goto V190;
    V175 = qcdr(V175);
    V176 = stack[-3];
    if (!car_legal(V176)) goto V192;
    V176 = qcdr(V176);
    stack[-2] = V175;
    V175 = V176;
    stack[-3] = V175;
    goto V71;

V62:
    V175 = stack[-8];
    if (V175 == nil) goto V148;
    V176 = stack[-5];
    V175 = stack[-7];
    V175 = cons(V176, V175);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-11];
    stack[-7] = V175;
    goto V50;

V50:
    V175 = stack[-4];
    if (!car_legal(V175)) goto V190;
    V175 = qcdr(V175);
    stack[-4] = V175;
    goto V27;

V148:
    V176 = stack[-5];
    V175 = stack[-6];
    V175 = cons(V176, V175);
    nil = C_nil;
    if (exception_pending()) goto V191;
    env = stack[-11];
    stack[-6] = V175;
    goto V50;

V164:
    V177 = stack[-7];
    V176 = stack[-6];
    V175 = nil;
    popv(12);
    { Lisp_Object retVal = list2star(V177, V176, V175);
    errexit();
    return onevalue(retVal); }
/* error exit handlers */
V192:
    popv(12);
    return error(1, err_bad_cdr, V176);
V191:
    popv(12);
    return nil;
V190:
    popv(12);
    return error(1, err_bad_cdr, V175);
V189:
    popv(12);
    return error(1, err_bad_car, V175);
}

/*
(DEFUN VMLISP:|last| (X) (CAR (VMLISP:LASTPAIR X)))

*/



/* Code for VMLISP:|last| */

static Lisp_Object CC_VMLISP__last(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V9;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering VMLISP:|last|\n");
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
    V9 = V2;
/* end of prologue */
    fn = elt(env, 1); /* LAST */
    V9 = (*qfn1(fn))(qenv(fn), V9);
    errexit();
    if (!car_legal(V9)) goto V10;
    V9 = qcar(V9);
    return onevalue(V9);
/* error exit handlers */
V10:
    return error(1, err_bad_car, V9);
}

/*
(DEFUN BOOT::|evalMmCond0| (BOOT::|op| BOOT::|sig| BOOT::|st|)
   (PROG (BOOT::SL BOOT::|p1| |t| BOOT::|t1| |b|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET BOOT::SL (BOOT::|evalMmDom| BOOT::|st|))
               (COND
                  ((BOOT:|BOOT-EQUAL| BOOT::SL 'BOOT::|failed|)
                     'BOOT::|failed|)
                  ('T
                     (DO ((#:G18979 BOOT::SL (CDR #:G18979))
                           (|p| NIL)
                           (#:G18980 NIL (AND BOOT::|p1| (NULL |b|))))
                        ((OR
                            (ATOM #:G18979)
                            (PROGN (SETQ |p| (CAR #:G18979)) NIL)
                            #:G18980)
                           NIL)
                        (SEQ
                           (EXIT
                              (BOOT:SPADLET
                                 |b|
                                 (PROGN
                                    (BOOT:SPADLET
                                       BOOT::|p1|
                                       (VMLISP:ASSQ
                                          (CAR |p|)
                                          BOOT::|$Subst|))
                                    (AND
                                       BOOT::|p1|
                                       (PROGN
                                          (BOOT:SPADLET
                                             BOOT::|t1|
                                             (CDR BOOT::|p1|))
                                          (BOOT:SPADLET |t| (CDR |p|))
                                          (OR
                                             (BOOT:|BOOT-EQUAL|
                                                |t|
                                                BOOT::|t1|)
                                             (COND
                                                ((BOOT::|containsVars| |t|)
                                                   (COND
        ((AND BOOT::|$Coerce| (EQCAR BOOT::|t1| 'BOOT::|Symbol|))
        (BOOT:SPADLET BOOT::|t1| (BOOT::|getSymbolType| (CAR |p|)))) )
                                                   (BOOT::|resolveTM1|
                                                      BOOT::|t1|
                                                      |t|))
                                                ('T
                                                   (AND
                                                      BOOT::|$Coerce|
        (COND
        ((AND
            (BOOT:|BOOT-EQUAL| BOOT::|t1| BOOT::|$AnonymousFunction|)
            (PAIRP |t|) (EQ (QCAR |t|) 'BOOT::|Mapping|)) |t|)
        ((AND
            (BOOT:|BOOT-EQUAL| (CAR |p|) (CADR BOOT::|sig|))
            (NULL (VMLISP:|member| (CAR |p|) (CDDR BOOT::|sig|))))
           (COND ((BOOT::|canCoerceFrom| |t| BOOT::|t1|) 'T) ('T NIL)))
        ((BOOT::|canCoerceFrom| BOOT::|t1| |t|) 'T)
        ((BOOT::|isSubDomain| |t| BOOT::|t1|) (RPLACD |p| BOOT::|t1|))
        ('T
           (AND
              (EQCAR BOOT::|t1| 'BOOT::|Symbol|)
              (BOOT::|canCoerceFrom|
                 (BOOT::|getSymbolType| (CAR |p|))
                 |t|)))) ))) ))) ))) ))
                     (OR
                        (AND
                           BOOT::SL
                           BOOT::|p1|
                           (NULL |b|)
                           'BOOT::|failed|)
                        (BOOT::|evalMmCat|
                           BOOT::|op|
                           BOOT::|sig|
                           BOOT::|st|
                           BOOT::SL)))) ))) ))

*/



/* Code for BOOT::|evalMmCond0| */

static Lisp_Object MS_CDECL CC_BOOT__evalMmCond0(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V318, V319, V320, V321;
    Lisp_Object fn;
    argcheck(nargs, 3, "evalMmCond0");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|evalMmCond0|\n");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-5] = V4;
    stack[-6] = V3;
    stack[-7] = V2;
/* end of prologue */
    stack[-4] = nil;
    stack[-2] = nil;
    V318 = stack[-5];
    fn = elt(env, 7); /* BOOT::|evalMmDom| */
    V318 = (*qfn1(fn))(qenv(fn), V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    stack[-8] = V318;
    V319 = stack[-8];
    V318 = elt(env, 1); /* BOOT::|failed| */
    V318 = (V319 == V318 ? lisp_true : nil);
    if (V318 == nil) goto V22;
    V318 = elt(env, 1); /* BOOT::|failed| */
    { popv(10); return onevalue(V318); }

V22:
    V318 = lisp_true;
    if (V318 == nil) goto V33;
    V319 = nil;
    V318 = stack[-8];
    stack[0] = V318;
    goto V43;

V43:
    V318 = stack[0];
    if (!consp(V318)) goto V36;
    V318 = stack[0];
    if (!car_legal(V318)) goto V332;
    V318 = qcar(V318);
    stack[-1] = V318;
    V318 = nil;
    if (!(V318 == nil)) goto V36;
    V318 = V319;
    if (!(V318 == nil)) goto V36;
    V318 = stack[-1];
    if (!car_legal(V318)) goto V332;
    V319 = qcar(V318);
    V318 = qvalue(elt(env, 2)); /* BOOT::|$Subst| */
    V318 = Latsoc(nil, V319, V318);
    stack[-4] = V318;
    V318 = stack[-4];
    if (V318 == nil) goto V71;
    V318 = stack[-4];
    if (!car_legal(V318)) goto V333;
    V318 = qcdr(V318);
    stack[-2] = V318;
    V318 = stack[-1];
    if (!car_legal(V318)) goto V333;
    V318 = qcdr(V318);
    stack[-3] = V318;
    V319 = stack[-3];
    V318 = stack[-2];
    V318 = (cl_equal(V319, V318) ? lisp_true : nil);
    if (!(V318 == nil)) goto V70;
    V318 = stack[-3];
    fn = elt(env, 8); /* BOOT::|containsVars| */
    V318 = (*qfn1(fn))(qenv(fn), V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    if (V318 == nil) goto V95;
    V318 = qvalue(elt(env, 3)); /* BOOT::|$Coerce| */
    if (V318 == nil) goto V117;
    V319 = stack[-2];
    V318 = elt(env, 4); /* BOOT::|Symbol| */
    if (!consp(V319)) goto V117;
    V319 = qcar(V319);
    if (!(V319 == V318)) goto V117;
    V318 = stack[-1];
    if (!car_legal(V318)) goto V332;
    V318 = qcar(V318);
    fn = elt(env, 9); /* BOOT::|getSymbolType| */
    V318 = (*qfn1(fn))(qenv(fn), V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    stack[-2] = V318;
    goto V117;

V117:
    V319 = stack[-2];
    V318 = stack[-3];
    fn = elt(env, 10); /* BOOT::|resolveTM1| */
    V318 = (*qfn2(fn))(qenv(fn), V319, V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    goto V70;

V70:
    stack[-2] = V318;
    V318 = stack[0];
    if (!car_legal(V318)) goto V333;
    V318 = qcdr(V318);
    V319 = stack[-4];
    if (V319 == nil) goto V272;
    V319 = stack[-2];
    V319 = (V319 == nil ? lisp_true : nil);
    goto V271;

V271:
    stack[0] = V318;
    V318 = V319;
    V319 = V318;
    goto V43;

V272:
    V319 = nil;
    goto V271;

V95:
    V318 = lisp_true;
    if (V318 == nil) goto V125;
    V318 = qvalue(elt(env, 3)); /* BOOT::|$Coerce| */
    if (V318 == nil) goto V129;
    V319 = stack[-2];
    V318 = qvalue(elt(env, 5)); /* BOOT::|$AnonymousFunction| */
    V318 = (cl_equal(V319, V318) ? lisp_true : nil);
    if (V318 == nil) goto V164;
    V318 = stack[-3];
    fn = elt(env, 11); /* CONSP */
    V318 = (*qfn1(fn))(qenv(fn), V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    if (V318 == nil) goto V164;
    V318 = stack[-3];
    V319 = qcar(V318);
    V318 = elt(env, 6); /* BOOT::|Mapping| */
    if (!(V319 == V318)) goto V164;
    V318 = stack[-3];
    goto V70;

V164:
    V318 = stack[-1];
    if (!car_legal(V318)) goto V332;
    V319 = qcar(V318);
    V318 = stack[-6];
    if (!car_legal(V318)) goto V333;
    V318 = qcdr(V318);
    if (!car_legal(V318)) goto V332;
    V318 = qcar(V318);
    V318 = (cl_equal(V319, V318) ? lisp_true : nil);
    if (V318 == nil) goto V207;
    V318 = stack[-1];
    if (!car_legal(V318)) goto V332;
    V319 = qcar(V318);
    V318 = stack[-6];
    if (!car_legal(V318)) goto V333;
    V318 = qcdr(V318);
    if (!car_legal(V318)) goto V333;
    V318 = qcdr(V318);
    fn = elt(env, 12); /* VMLISP:|member| */
    V318 = (*qfn2(fn))(qenv(fn), V319, V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    if (!(V318 == nil)) goto V207;
    V319 = stack[-3];
    V318 = stack[-2];
    fn = elt(env, 13); /* BOOT::|canCoerceFrom| */
    V318 = (*qfn2(fn))(qenv(fn), V319, V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    if (V318 == nil) goto V190;
    V318 = lisp_true;
    goto V70;

V190:
    V318 = lisp_true;
    if (V318 == nil) goto V201;
    V318 = nil;
    goto V70;

V201:
    V318 = nil;
    goto V70;

V207:
    V319 = stack[-2];
    V318 = stack[-3];
    fn = elt(env, 13); /* BOOT::|canCoerceFrom| */
    V318 = (*qfn2(fn))(qenv(fn), V319, V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    if (V318 == nil) goto V218;
    V318 = lisp_true;
    goto V70;

V218:
    V319 = stack[-3];
    V318 = stack[-2];
    fn = elt(env, 14); /* BOOT::|isSubDomain| */
    V318 = (*qfn2(fn))(qenv(fn), V319, V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    if (V318 == nil) goto V216;
    V319 = stack[-1];
    V318 = stack[-2];
    V318 = Lrplacd(nil, V319, V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    goto V70;

V216:
    V318 = lisp_true;
    if (V318 == nil) goto V234;
    V319 = stack[-2];
    V318 = elt(env, 4); /* BOOT::|Symbol| */
    if (!consp(V319)) goto V238;
    V319 = qcar(V319);
    if (!(V319 == V318)) goto V238;
    V318 = stack[-1];
    if (!car_legal(V318)) goto V332;
    V318 = qcar(V318);
    fn = elt(env, 9); /* BOOT::|getSymbolType| */
    V319 = (*qfn1(fn))(qenv(fn), V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    V318 = stack[-3];
    fn = elt(env, 13); /* BOOT::|canCoerceFrom| */
    V318 = (*qfn2(fn))(qenv(fn), V319, V318);
    nil = C_nil;
    if (exception_pending()) goto V331;
    env = stack[-9];
    goto V70;

V238:
    V318 = nil;
    goto V70;

V234:
    V318 = nil;
    goto V70;

V129:
    V318 = nil;
    goto V70;

V125:
    V318 = nil;
    goto V70;

V71:
    V318 = nil;
    goto V70;

V36:
    V318 = stack[-8];
    if (V318 == nil) goto V288;
    V318 = stack[-4];
    if (V318 == nil) goto V292;
    V318 = stack[-2];
    if (V318 == nil) goto V300;
    V318 = nil;
    goto V287;

V287:
    if (!(V318 == nil)) { popv(10); return onevalue(V318); }
    V321 = stack[-7];
    V320 = stack[-6];
    V319 = stack[-5];
    V318 = stack[-8];
    {
        popv(10);
        fn = elt(env, 15); /* BOOT::|evalMmCat| */
        return (*qfnn(fn))(qenv(fn), 4, V321, V320, V319, V318);
    }

V300:
    V318 = elt(env, 1); /* BOOT::|failed| */
    goto V287;

V292:
    V318 = nil;
    goto V287;

V288:
    V318 = nil;
    goto V287;

V33:
    V318 = nil;
    { popv(10); return onevalue(V318); }
/* error exit handlers */
V333:
    popv(10);
    return error(1, err_bad_cdr, V318);
V332:
    popv(10);
    return error(1, err_bad_car, V318);
V331:
    popv(10);
    return nil;
}

/*
(DEFUN BOOT::|COMPCAT-;exquo;SRU;46| (|x| |r| |$|)
   (PROG (BOOT::|r1| BOOT::|r2|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 133)) (CONS 0 |x|))
               ('T
                  (SEQ
                     (BOOT::LETT
                        BOOT::|r1|
                        (BOOT:SPADCALL
                           (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 24))
                           |r|
                           (VMLISP:QREFELT |$| 202))
                        BOOT::|COMPCAT-;exquo;SRU;46|)
                     (EXIT
                        (COND
                           ((BOOT::QEQCAR BOOT::|r1| 1) (CONS 1 "failed"))
                           ('T
                              (SEQ
                                 (BOOT::LETT
                                    BOOT::|r2|
                                    (BOOT:SPADCALL
                                       (BOOT:SPADCALL
                                          |x|
                                          (VMLISP:QREFELT |$| 92))
                                       |r|
                                       (VMLISP:QREFELT |$| 202))
                                    BOOT::|COMPCAT-;exquo;SRU;46|)
                                 (EXIT
                                    (COND
                                       ((BOOT::QEQCAR BOOT::|r2| 1)
                                          (CONS 1 "failed"))
                                       ('T
                                          (CONS
                                             0
                                             (BOOT:SPADCALL
                                                (QCDR BOOT::|r1|)
                                                (QCDR BOOT::|r2|)
                                                (VMLISP:QREFELT
                                                   |$|
                                                   30)))) ))) ))) ))) ))) )

*/



/* Code for BOOT::|COMPCAT-;exquo;SRU;46| */

static Lisp_Object MS_CDECL CC_BOOT__COMPCATKUexquoUSRUU46(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V244, V245, V246, V247;
    argcheck(nargs, 3, "COMPCAT-;exquo;SRU;46");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPCAT-;exquo;SRU;46|\n");
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
    V245 = stack[-2];
    V244 = (Lisp_Object)2129; /* 133 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    V245 = V244;
    if (!car_legal(V245)) goto V255;
    V246 = qcar(V245);
    V245 = stack[-3];
    if (!car_legal(V244)) goto V256;
    V244 = qcdr(V244);
    V244 = Lapply2(nil, 3, V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    if (V244 == nil) goto V17;
    V245 = (Lisp_Object)1; /* 0 */
    V244 = stack[-4];
    popv(7);
    { Lisp_Object retVal = cons(V245, V244);
    errexit();
    return onevalue(retVal); }

V17:
    V244 = lisp_true;
    if (V244 == nil) goto V51;
    V245 = stack[-2];
    V244 = (Lisp_Object)3233; /* 202 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    stack[-1] = V244;
    V244 = stack[-1];
    if (!car_legal(V244)) goto V257;
    stack[0] = qcar(V244);
    V245 = stack[-2];
    V244 = (Lisp_Object)385; /* 24 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    V245 = V244;
    if (!car_legal(V245)) goto V255;
    V246 = qcar(V245);
    V245 = stack[-4];
    if (!car_legal(V244)) goto V256;
    V244 = qcdr(V244);
    V244 = Lapply2(nil, 3, V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    V246 = V244;
    V245 = stack[-3];
    V244 = stack[-1];
    if (!car_legal(V244)) goto V256;
    V244 = qcdr(V244);
    V244 = Lapply3(nil, 4, stack[0], V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    stack[-5] = V244;
    V244 = stack[-5];
    V245 = qcar(V244);
    V244 = (Lisp_Object)17; /* 1 */
    V244 = Leql(nil, V245, V244);
    env = stack[-6];
    if (V244 == nil) goto V108;
    V244 = (Lisp_Object)17; /* 1 */
    V245 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V244, V245);
    errexit();
    return onevalue(retVal); }

V108:
    V244 = lisp_true;
    if (V244 == nil) goto V127;
    V245 = stack[-2];
    V244 = (Lisp_Object)3233; /* 202 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    stack[-1] = V244;
    V244 = stack[-1];
    if (!car_legal(V244)) goto V257;
    stack[0] = qcar(V244);
    V245 = stack[-2];
    V244 = (Lisp_Object)1473; /* 92 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    V245 = V244;
    if (!car_legal(V245)) goto V255;
    V246 = qcar(V245);
    V245 = stack[-4];
    if (!car_legal(V244)) goto V256;
    V244 = qcdr(V244);
    V244 = Lapply2(nil, 3, V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    V246 = V244;
    V245 = stack[-3];
    V244 = stack[-1];
    if (!car_legal(V244)) goto V256;
    V244 = qcdr(V244);
    V244 = Lapply3(nil, 4, stack[0], V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    stack[-1] = V244;
    V244 = stack[-1];
    V245 = qcar(V244);
    V244 = (Lisp_Object)17; /* 1 */
    V244 = Leql(nil, V245, V244);
    env = stack[-6];
    if (V244 == nil) goto V184;
    V244 = (Lisp_Object)17; /* 1 */
    V245 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V244, V245);
    errexit();
    return onevalue(retVal); }

V184:
    V244 = lisp_true;
    if (V244 == nil) goto V203;
    stack[0] = (Lisp_Object)1; /* 0 */
    V245 = stack[-2];
    V244 = (Lisp_Object)481; /* 30 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    env = stack[-6];
    V245 = V244;
    if (!car_legal(V245)) goto V255;
    V247 = qcar(V245);
    V245 = stack[-5];
    V246 = qcdr(V245);
    V245 = stack[-1];
    V245 = qcdr(V245);
    if (!car_legal(V244)) goto V256;
    V244 = qcdr(V244);
    V244 = Lapply3(nil, 4, V247, V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V254;
    {
        Lisp_Object V258 = stack[0];
        popv(7);
        { Lisp_Object retVal = cons(V258, V244);
        errexit();
        return onevalue(retVal); }
    }

V203:
    V244 = nil;
    { popv(7); return onevalue(V244); }

V127:
    V244 = nil;
    { popv(7); return onevalue(V244); }

V51:
    V244 = nil;
    { popv(7); return onevalue(V244); }
/* error exit handlers */
V257:
    popv(7);
    return error(1, err_bad_car, V244);
V256:
    popv(7);
    return error(1, err_bad_cdr, V244);
V255:
    popv(7);
    return error(1, err_bad_car, V245);
V254:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|FLASORT;partition| (|l| |r| |i| |j| |k| |$|)
   (PROG (|x| |t|)
      (RETURN
         (SEQ
            (BOOT::LETT
               |x|
               (BOOT:SPADCALL |r| |k| (VMLISP:QREFELT |$| 13))
               BOOT::|FLASORT;partition|)
            (BOOT::LETT
               |t|
               (BOOT:SPADCALL |r| |i| (VMLISP:QREFELT |$| 13))
               BOOT::|FLASORT;partition|)
            (BOOT:SPADCALL
               |r|
               |k|
               (BOOT:SPADCALL |r| |j| (VMLISP:QREFELT |$| 13))
               (VMLISP:QREFELT |$| 16))
            (SEQ
               BOOT::G190
               (COND ((NULL (|<| |i| |j|)) (GO BOOT::G191)))
               (SEQ
                  (EXIT
                     (COND
                        ((BOOT:SPADCALL |x| |t| |l|)
                           (SEQ
                              (BOOT:SPADCALL
                                 |r|
                                 |j|
                                 |t|
                                 (VMLISP:QREFELT |$| 16))
                              (BOOT::LETT
                                 |j|
                                 (|-| |j| 1)
                                 BOOT::|FLASORT;partition|)
                              (EXIT
                                 (BOOT::LETT
                                    |t|
                                    (BOOT:SPADCALL
                                       |r|
                                       |i|
                                       (BOOT:SPADCALL
                                          |r|
                                          |j|
                                          (VMLISP:QREFELT |$| 13))
                                       (VMLISP:QREFELT |$| 16))
                                    BOOT::|FLASORT;partition|))))
                        ('T
                           (SEQ
                              (BOOT::LETT
                                 |i|
                                 (|+| |i| 1)
                                 BOOT::|FLASORT;partition|)
                              (EXIT
                                 (BOOT::LETT
                                    |t|
                                    (BOOT:SPADCALL
                                       |r|
                                       |i|
                                       (VMLISP:QREFELT |$| 13))
                                    BOOT::|FLASORT;partition|)))) )))
               NIL
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (BOOT:SPADCALL |r| |j| |x| (VMLISP:QREFELT |$| 16))
            (EXIT |j|)))) )

*/



/* Code for BOOT::|FLASORT;partition| */

static Lisp_Object MS_CDECL CC_BOOT__FLASORTUpartition(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5,
                         Lisp_Object V6, Lisp_Object V7, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V331, V332, V333, V334, V335;
    Lisp_Object fn;
    argcheck(nargs, 6, "FLASORT;partition");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FLASORT;partition|\n");
#endif
    if (stack >= stacklimit)
    {
        push(V7);
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
        pop(V7);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = V7;
    stack[-5] = V6;
    stack[-6] = V5;
    stack[-7] = V4;
    stack[-8] = V3;
    stack[-9] = V2;
/* end of prologue */
    V332 = stack[-4];
    V331 = (Lisp_Object)209; /* 13 */
    V331 = Lgetv(nil, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    V332 = V331;
    if (!car_legal(V332)) goto V348;
    V334 = qcar(V332);
    V333 = stack[-8];
    V332 = stack[-5];
    if (!car_legal(V331)) goto V349;
    V331 = qcdr(V331);
    V331 = Lapply3(nil, 4, V334, V333, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    stack[-10] = V331;
    V332 = stack[-4];
    V331 = (Lisp_Object)209; /* 13 */
    V331 = Lgetv(nil, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    V332 = V331;
    if (!car_legal(V332)) goto V348;
    V334 = qcar(V332);
    V333 = stack[-8];
    V332 = stack[-7];
    if (!car_legal(V331)) goto V349;
    V331 = qcdr(V331);
    V331 = Lapply3(nil, 4, V334, V333, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    stack[-3] = V331;
    V332 = stack[-4];
    V331 = (Lisp_Object)257; /* 16 */
    V331 = Lgetv(nil, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    stack[-2] = V331;
    V331 = stack[-2];
    if (!car_legal(V331)) goto V350;
    stack[-1] = qcar(V331);
    stack[0] = stack[-8];
    V332 = stack[-4];
    V331 = (Lisp_Object)209; /* 13 */
    V331 = Lgetv(nil, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    V332 = V331;
    if (!car_legal(V332)) goto V348;
    V334 = qcar(V332);
    V333 = stack[-8];
    V332 = stack[-6];
    if (!car_legal(V331)) goto V349;
    V331 = qcdr(V331);
    V331 = Lapply3(nil, 4, V334, V333, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    V332 = V331;
    V331 = stack[-2];
    if (!car_legal(V331)) goto V349;
    V331 = qcdr(V331);
    fn = elt(env, 1); /* FUNCALL* */
    V331 = (*qfnn(fn))(qenv(fn), 5, stack[-1], stack[0], stack[-5], V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    goto V136;

V136:
    V332 = stack[-7];
    V331 = stack[-6];
    V331 = (Lisp_Object)lessp2(V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    V331 = V331 ? lisp_true : nil;
    env = stack[-11];
    if (V331 == nil) goto V303;
    V331 = stack[-9];
    V332 = V331;
    if (!car_legal(V332)) goto V348;
    V334 = qcar(V332);
    V333 = stack[-10];
    V332 = stack[-3];
    if (!car_legal(V331)) goto V349;
    V331 = qcdr(V331);
    V331 = Lapply3(nil, 4, V334, V333, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    if (V331 == nil) goto V148;
    V332 = stack[-4];
    V331 = (Lisp_Object)257; /* 16 */
    V331 = Lgetv(nil, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    V332 = V331;
    if (!car_legal(V332)) goto V348;
    V335 = qcar(V332);
    V334 = stack[-8];
    V333 = stack[-6];
    V332 = stack[-3];
    if (!car_legal(V331)) goto V349;
    V331 = qcdr(V331);
    fn = elt(env, 1); /* FUNCALL* */
    V331 = (*qfnn(fn))(qenv(fn), 5, V335, V334, V333, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    V331 = stack[-6];
    V331 = sub1(V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    stack[-6] = V331;
    V332 = stack[-4];
    V331 = (Lisp_Object)257; /* 16 */
    V331 = Lgetv(nil, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    stack[-3] = V331;
    V331 = stack[-3];
    if (!car_legal(V331)) goto V350;
    stack[-2] = qcar(V331);
    stack[-1] = stack[-8];
    stack[0] = stack[-7];
    V332 = stack[-4];
    V331 = (Lisp_Object)209; /* 13 */
    V331 = Lgetv(nil, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    V332 = V331;
    if (!car_legal(V332)) goto V348;
    V334 = qcar(V332);
    V333 = stack[-8];
    V332 = stack[-6];
    if (!car_legal(V331)) goto V349;
    V331 = qcdr(V331);
    V331 = Lapply3(nil, 4, V334, V333, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    V332 = V331;
    V331 = stack[-3];
    if (!car_legal(V331)) goto V349;
    V331 = qcdr(V331);
    fn = elt(env, 1); /* FUNCALL* */
    V331 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    stack[-3] = V331;
    goto V136;

V148:
    V331 = lisp_true;
    if (V331 == nil) goto V136;
    V331 = stack[-7];
    V331 = add1(V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    stack[-7] = V331;
    V332 = stack[-4];
    V331 = (Lisp_Object)209; /* 13 */
    V331 = Lgetv(nil, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    V332 = V331;
    if (!car_legal(V332)) goto V348;
    V334 = qcar(V332);
    V333 = stack[-8];
    V332 = stack[-7];
    if (!car_legal(V331)) goto V349;
    V331 = qcdr(V331);
    V331 = Lapply3(nil, 4, V334, V333, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    stack[-3] = V331;
    goto V136;

V303:
    V332 = stack[-4];
    V331 = (Lisp_Object)257; /* 16 */
    V331 = Lgetv(nil, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    env = stack[-11];
    V332 = V331;
    if (!car_legal(V332)) goto V348;
    V335 = qcar(V332);
    V334 = stack[-8];
    V333 = stack[-6];
    V332 = stack[-10];
    if (!car_legal(V331)) goto V349;
    V331 = qcdr(V331);
    fn = elt(env, 1); /* FUNCALL* */
    V331 = (*qfnn(fn))(qenv(fn), 5, V335, V334, V333, V332, V331);
    nil = C_nil;
    if (exception_pending()) goto V347;
    { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
/* error exit handlers */
V350:
    popv(12);
    return error(1, err_bad_car, V331);
V349:
    popv(12);
    return error(1, err_bad_cdr, V331);
V348:
    popv(12);
    return error(1, err_bad_car, V332);
V347:
    popv(12);
    return nil;
}

/*
(DEFUN BOOT::|FM;*;R2$;1| (|r| |x| |$|)
   (PROG (#:G110703 |u| #:G110704)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 11))
                  (BOOT::|spadConstant| |$| 12))
               ((BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 13)) |x|)
               ('T
                  (PROGN
                     (BOOT::LETT #:G110703 NIL BOOT::|FM;*;R2$;1|)
                     (SEQ
                        (BOOT::LETT |u| NIL BOOT::|FM;*;R2$;1|)
                        (BOOT::LETT #:G110704 |x| BOOT::|FM;*;R2$;1|)
                        BOOT::G190
                        (COND
                           ((OR
                               (ATOM #:G110704)
                               (PROGN
                                  (BOOT::LETT
                                     |u|
                                     (CAR #:G110704)
                                     BOOT::|FM;*;R2$;1|)
                                  NIL))
                              (GO BOOT::G191)))
                        (SEQ
                           (EXIT
                              (BOOT::LETT
                                 #:G110703
                                 (CONS
                                    (CONS
                                       (QCAR |u|)
                                       (BOOT:SPADCALL
                                          |r|
                                          (QCDR |u|)
                                          (VMLISP:QREFELT |$| 14)))
                                    #:G110703)
                                 BOOT::|FM;*;R2$;1|)))
                        (BOOT::LETT
                           #:G110704
                           (CDR #:G110704)
                           BOOT::|FM;*;R2$;1|)
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT (NREVERSE0 #:G110703)))) ))) )))

*/



/* Code for BOOT::|FM;*;R2$;1| */

static Lisp_Object MS_CDECL CC_BOOT__FMUHUR2DU1(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V159, V160, V161, V162;
    Lisp_Object fn;
    argcheck(nargs, 3, "FM;*;R2$;1");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FM;*;R2$;1|\n");
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
    stack[-3] = V4;
    stack[0] = V3;
    stack[-4] = V2;
/* end of prologue */
    V160 = stack[-3];
    V159 = (Lisp_Object)177; /* 11 */
    V159 = Lgetv(nil, V160, V159);
    nil = C_nil;
    if (exception_pending()) goto V169;
    env = stack[-6];
    V160 = V159;
    if (!car_legal(V160)) goto V170;
    V161 = qcar(V160);
    V160 = stack[-4];
    if (!car_legal(V159)) goto V171;
    V159 = qcdr(V159);
    V159 = Lapply2(nil, 3, V161, V160, V159);
    nil = C_nil;
    if (exception_pending()) goto V169;
    env = stack[-6];
    if (V159 == nil) goto V70;
    V160 = stack[-3];
    V159 = (Lisp_Object)193; /* 12 */
    V159 = Lgetv(nil, V160, V159);
    nil = C_nil;
    if (exception_pending()) goto V169;
    V160 = V159;
    if (!car_legal(V160)) goto V170;
    V160 = qcar(V160);
    if (!car_legal(V159)) goto V171;
    V159 = qcdr(V159);
        popv(7);
        return Lapply1(nil, V160, V159);

V70:
    V160 = stack[-3];
    V159 = (Lisp_Object)209; /* 13 */
    V159 = Lgetv(nil, V160, V159);
    nil = C_nil;
    if (exception_pending()) goto V169;
    env = stack[-6];
    V160 = V159;
    if (!car_legal(V160)) goto V170;
    V161 = qcar(V160);
    V160 = stack[-4];
    if (!car_legal(V159)) goto V171;
    V159 = qcdr(V159);
    V159 = Lapply2(nil, 3, V161, V160, V159);
    nil = C_nil;
    if (exception_pending()) goto V169;
    env = stack[-6];
    if (!(V159 == nil)) { Lisp_Object res = stack[0]; popv(7); return onevalue(res); }
    V159 = lisp_true;
    if (V159 == nil) goto V92;
    V159 = nil;
    stack[-5] = V159;
    V159 = stack[0];
    stack[-1] = V159;
    goto V97;

V97:
    V159 = stack[-1];
    if (!consp(V159)) goto V98;
    V159 = stack[-1];
    if (!car_legal(V159)) goto V172;
    V159 = qcar(V159);
    stack[-2] = V159;
    V159 = nil;
    if (!(V159 == nil)) goto V98;
    V159 = stack[-2];
    stack[0] = qcar(V159);
    V160 = stack[-3];
    V159 = (Lisp_Object)225; /* 14 */
    V159 = Lgetv(nil, V160, V159);
    nil = C_nil;
    if (exception_pending()) goto V169;
    env = stack[-6];
    V160 = V159;
    if (!car_legal(V160)) goto V170;
    V162 = qcar(V160);
    V161 = stack[-4];
    V160 = stack[-2];
    V160 = qcdr(V160);
    if (!car_legal(V159)) goto V171;
    V159 = qcdr(V159);
    V159 = Lapply3(nil, 4, V162, V161, V160, V159);
    nil = C_nil;
    if (exception_pending()) goto V169;
    env = stack[-6];
    V160 = V159;
    V159 = stack[-5];
    V159 = acons(stack[0], V160, V159);
    nil = C_nil;
    if (exception_pending()) goto V169;
    env = stack[-6];
    stack[-5] = V159;
    V159 = stack[-1];
    if (!car_legal(V159)) goto V171;
    V159 = qcdr(V159);
    stack[-1] = V159;
    goto V97;

V98:
    V159 = stack[-5];
    {
        popv(7);
        fn = elt(env, 1); /* NREVERSE0 */
        return (*qfn1(fn))(qenv(fn), V159);
    }

V92:
    V159 = nil;
    { popv(7); return onevalue(V159); }
/* error exit handlers */
V172:
    popv(7);
    return error(1, err_bad_car, V159);
V171:
    popv(7);
    return error(1, err_bad_cdr, V159);
V170:
    popv(7);
    return error(1, err_bad_car, V160);
V169:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|newExpandTypeSlot| (BOOT::|slot|
      BOOT::|dollar|
      BOOT::|domain|)
   (BOOT::|newExpandLocalType|
      (BOOT::|sigDomainVal| BOOT::|dollar| BOOT::|domain| BOOT::|slot|)
      BOOT::|dollar|
      BOOT::|domain|))

*/



/* Code for BOOT::|newExpandTypeSlot| */

static Lisp_Object MS_CDECL CC_BOOT__newExpandTypeSlot(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V29, V30, V31;
    Lisp_Object fn;
    argcheck(nargs, 3, "newExpandTypeSlot");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|newExpandTypeSlot|\n");
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
    stack[0] = V4;
    stack[-1] = V3;
    V29 = V2;
/* end of prologue */
    V31 = stack[-1];
    V30 = stack[0];
    fn = elt(env, 1); /* BOOT::|sigDomainVal| */
    V31 = (*qfnn(fn))(qenv(fn), 3, V31, V30, V29);
    nil = C_nil;
    if (exception_pending()) goto V34;
    env = stack[-2];
    V30 = stack[-1];
    V29 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); /* BOOT::|newExpandLocalType| */
        return (*qfnn(fn))(qenv(fn), 3, V31, V30, V29);
    }
/* error exit handlers */
V34:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|FRAC;*;3$;23| (|x| |y| |$|)
   (PROG (BOOT::|#G35| BOOT::|#G36|)
      (RETURN
         (SEQ
            (COND
               ((OR
                   (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 13))
                   (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 13)))
                  (BOOT::|spadConstant| |$| 22))
               ('T
                  (COND
                     ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 56)) |y|)
                     ((BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 56)) |x|)
                     ('T
                        (SEQ
                           (PROGN
                              (BOOT::LETT
                                 BOOT::|#G35|
                                 (CONS (QCAR |x|) (QCDR |y|))
                                 BOOT::|FRAC;*;3$;23|)
                              (BOOT::LETT
                                 BOOT::|#G36|
                                 (CONS (QCAR |y|) (QCDR |x|))
                                 BOOT::|FRAC;*;3$;23|)
                              (BOOT::LETT
                                 |x|
                                 BOOT::|#G35|
                                 BOOT::|FRAC;*;3$;23|)
                              (BOOT::LETT
                                 |y|
                                 BOOT::|#G36|
                                 BOOT::|FRAC;*;3$;23|))
                           (BOOT::|FRAC;cancelGcd| |x| |$|)
                           (BOOT::|FRAC;cancelGcd| |y| |$|)
                           (EXIT
                              (BOOT::|FRAC;normalize|
                                 (CONS
                                    (BOOT:SPADCALL
                                       (QCAR |x|)
                                       (QCAR |y|)
                                       (VMLISP:QREFELT |$| 49))
                                    (BOOT:SPADCALL
                                       (QCDR |x|)
                                       (QCDR |y|)
                                       (VMLISP:QREFELT |$| 49)))
                                 |$|)))) ))) ))) )

*/



/* Code for BOOT::|FRAC;*;3$;23| */

static Lisp_Object MS_CDECL CC_BOOT__FRACUHU3DU23(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V264, V265, V266, V267;
    Lisp_Object fn;
    argcheck(nargs, 3, "FRAC;*;3$;23");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FRAC;*;3$;23|\n");
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
    V265 = stack[0];
    V264 = (Lisp_Object)209; /* 13 */
    V264 = Lgetv(nil, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V265 = V264;
    if (!car_legal(V265)) goto V273;
    V266 = qcar(V265);
    V265 = stack[-2];
    if (!car_legal(V264)) goto V274;
    V264 = qcdr(V264);
    V264 = Lapply2(nil, 3, V266, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    if (!(V264 == nil)) goto V72;
    V265 = stack[0];
    V264 = (Lisp_Object)209; /* 13 */
    V264 = Lgetv(nil, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V265 = V264;
    if (!car_legal(V265)) goto V273;
    V266 = qcar(V265);
    V265 = stack[-1];
    if (!car_legal(V264)) goto V274;
    V264 = qcdr(V264);
    V264 = Lapply2(nil, 3, V266, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    if (!(V264 == nil)) goto V72;
    V264 = lisp_true;
    if (V264 == nil) goto V90;
    V265 = stack[0];
    V264 = (Lisp_Object)897; /* 56 */
    V264 = Lgetv(nil, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V265 = V264;
    if (!car_legal(V265)) goto V273;
    V266 = qcar(V265);
    V265 = stack[-2];
    if (!car_legal(V264)) goto V274;
    V264 = qcdr(V264);
    V264 = Lapply2(nil, 3, V266, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    if (!(V264 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    V265 = stack[0];
    V264 = (Lisp_Object)897; /* 56 */
    V264 = Lgetv(nil, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V265 = V264;
    if (!car_legal(V265)) goto V273;
    V266 = qcar(V265);
    V265 = stack[-1];
    if (!car_legal(V264)) goto V274;
    V264 = qcdr(V264);
    V264 = Lapply2(nil, 3, V266, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    if (!(V264 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    V264 = lisp_true;
    if (V264 == nil) goto V149;
    V264 = stack[-2];
    V265 = qcar(V264);
    V264 = stack[-1];
    V264 = qcdr(V264);
    V264 = cons(V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    stack[-3] = V264;
    V264 = stack[-1];
    V265 = qcar(V264);
    V264 = stack[-2];
    V264 = qcdr(V264);
    V264 = cons(V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V265 = V264;
    V264 = stack[-3];
    stack[-2] = V264;
    V264 = V265;
    stack[-1] = V264;
    V265 = stack[-2];
    V264 = stack[0];
    fn = elt(env, 1); /* BOOT::|FRAC;cancelGcd| */
    V264 = (*qfn2(fn))(qenv(fn), V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V265 = stack[-1];
    V264 = stack[0];
    fn = elt(env, 1); /* BOOT::|FRAC;cancelGcd| */
    V264 = (*qfn2(fn))(qenv(fn), V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V265 = stack[0];
    V264 = (Lisp_Object)785; /* 49 */
    V264 = Lgetv(nil, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V265 = V264;
    if (!car_legal(V265)) goto V273;
    V267 = qcar(V265);
    V265 = stack[-2];
    V266 = qcar(V265);
    V265 = stack[-1];
    V265 = qcar(V265);
    if (!car_legal(V264)) goto V274;
    V264 = qcdr(V264);
    V264 = Lapply3(nil, 4, V267, V266, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    stack[-3] = V264;
    V265 = stack[0];
    V264 = (Lisp_Object)785; /* 49 */
    V264 = Lgetv(nil, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V265 = V264;
    if (!car_legal(V265)) goto V273;
    V267 = qcar(V265);
    V265 = stack[-2];
    V266 = qcdr(V265);
    V265 = stack[-1];
    V265 = qcdr(V265);
    if (!car_legal(V264)) goto V274;
    V264 = qcdr(V264);
    V264 = Lapply3(nil, 4, V267, V266, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V265 = cons(stack[-3], V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    env = stack[-4];
    V264 = stack[0];
    {
        popv(5);
        fn = elt(env, 2); /* BOOT::|FRAC;normalize| */
        return (*qfn2(fn))(qenv(fn), V265, V264);
    }

V149:
    V264 = nil;
    { popv(5); return onevalue(V264); }

V90:
    V264 = nil;
    { popv(5); return onevalue(V264); }

V72:
    V265 = stack[0];
    V264 = (Lisp_Object)353; /* 22 */
    V264 = Lgetv(nil, V265, V264);
    nil = C_nil;
    if (exception_pending()) goto V272;
    V265 = V264;
    if (!car_legal(V265)) goto V273;
    V265 = qcar(V265);
    if (!car_legal(V264)) goto V274;
    V264 = qcdr(V264);
        popv(5);
        return Lapply1(nil, V265, V264);
/* error exit handlers */
V274:
    popv(5);
    return error(1, err_bad_cdr, V264);
V273:
    popv(5);
    return error(1, err_bad_car, V265);
V272:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|matchTypes| (BOOT::|pm| BOOT::|args1| BOOT::|args2|)
   (PROG (|p| BOOT::|t3| |q| |t| BOOT::|t1| BOOT::|t0|)
      (RETURN
         (SEQ
            (DO ((#:G18960 BOOT::|pm| (CDR #:G18960))
                  (|v| NIL)
                  (#:G18961 BOOT::|args1| (CDR #:G18961))
                  (BOOT::|t1| NIL)
                  (#:G18962 BOOT::|args2| (CDR #:G18962))
                  (BOOT::|t2| NIL)
                  (#:G18963
                     NIL
                     (BOOT:|BOOT-EQUAL| BOOT::|$Subst| 'BOOT::|failed|)))
               ((OR
                   (ATOM #:G18960)
                   (PROGN (SETQ |v| (CAR #:G18960)) NIL)
                   (ATOM #:G18961)
                   (PROGN (SETQ BOOT::|t1| (CAR #:G18961)) NIL)
                   (ATOM #:G18962)
                   (PROGN (SETQ BOOT::|t2| (CAR #:G18962)) NIL)
                   #:G18963)
                  NIL)
               (SEQ
                  (EXIT
                     (COND
                        ((BOOT:SPADLET
                            |p|
                            (VMLISP:ASSQ |v| BOOT::|$Subst|))
                           (BOOT:SPADLET |t| (CDR |p|))
                           (COND
                              ((BOOT:|BOOT-EQUAL| |t| BOOT::|t1|)
                                 (AND
                                    BOOT::|$Coerce|
                                    (EQCAR BOOT::|t1| 'BOOT::|Symbol|)
                                    (BOOT:SPADLET
                                       |q|
                                       (VMLISP:ASSQ
                                          |v|
                                          BOOT::|$SymbolType|))
                                    BOOT::|t2|
                                    (BOOT:SPADLET
                                       BOOT::|t3|
                                       (BOOT::|resolveTT|
                                          (CDR |q|)
                                          BOOT::|t2|))
                                    (RPLACD |q| BOOT::|t3|)))
                              (BOOT::|$Coerce|
                                 (COND
                                    ((AND
                                        (EQCAR |t| 'BOOT::|Symbol|)
                                        (BOOT:SPADLET
                                           |q|
                                           (VMLISP:ASSQ
                                              |v|
                                              BOOT::|$SymbolType|)))
                                       (BOOT:SPADLET |t| (CDR |q|))))
                                 (COND
                                    ((AND
                                        (EQCAR BOOT::|t1| 'BOOT::|Symbol|)
                                        BOOT::|t2|)
                                       (BOOT:SPADLET
                                          BOOT::|t1|
                                          BOOT::|t2|)))
                                 (COND
                                    ((BOOT:SPADLET
                                        BOOT::|t0|
                                        (BOOT::|resolveTT| |t| BOOT::|t1|))
                                       (RPLACD |p| BOOT::|t0|))
                                    ('T
                                       (BOOT:SPADLET
                                          BOOT::|$Subst|
                                          'BOOT::|failed|))))
                              ('T
                                 (BOOT:SPADLET
                                    BOOT::|$Subst|
                                    'BOOT::|failed|))))
                        ('T
                           (BOOT:SPADLET
                              BOOT::|$Subst|
                              (CONS (CONS |v| BOOT::|t1|) BOOT::|$Subst|))
                           (COND
                              ((AND
                                  (EQCAR BOOT::|t1| 'BOOT::|Symbol|)
                                  BOOT::|t2|)
                                 (BOOT:SPADLET
                                    BOOT::|$SymbolType|
                                    (CONS
                                       (CONS |v| BOOT::|t2|)
                                       BOOT::|$SymbolType|)))
                              ('T NIL)))) ))) ))) )

*/



/* Code for BOOT::|matchTypes| */

static Lisp_Object MS_CDECL CC_BOOT__matchTypes(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V291, V292, V293, V294, V295;
    Lisp_Object fn;
    argcheck(nargs, 3, "matchTypes");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|matchTypes|\n");
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
    V294 = V4;
    V293 = V3;
    V292 = V2;
/* end of prologue */
    V291 = nil;
    stack[-4] = V294;
    stack[-2] = V293;
    stack[0] = V292;
    goto V34;

V34:
    V292 = stack[0];
    if (!consp(V292)) goto V37;
    V292 = stack[0];
    if (!car_legal(V292)) goto V303;
    V292 = qcar(V292);
    stack[-1] = V292;
    V292 = nil;
    if (!(V292 == nil)) goto V37;
    V292 = stack[-2];
    if (!consp(V292)) goto V37;
    V292 = stack[-2];
    if (!car_legal(V292)) goto V303;
    V292 = qcar(V292);
    stack[-3] = V292;
    V292 = nil;
    if (!(V292 == nil)) goto V37;
    V292 = stack[-4];
    if (!consp(V292)) goto V37;
    V292 = stack[-4];
    if (!car_legal(V292)) goto V303;
    V292 = qcar(V292);
    stack[-5] = V292;
    V292 = nil;
    if (!(V292 == nil)) goto V37;
    if (!(V291 == nil)) goto V37;
    V292 = stack[-1];
    V291 = qvalue(elt(env, 1)); /* BOOT::|$Subst| */
    V291 = Latsoc(nil, V292, V291);
    stack[-6] = V291;
    if (V291 == nil) goto V66;
    V291 = stack[-6];
    if (!car_legal(V291)) goto V304;
    V291 = qcdr(V291);
    V293 = V291;
    V292 = V293;
    V291 = stack[-3];
    V291 = (cl_equal(V292, V291) ? lisp_true : nil);
    if (V291 == nil) goto V80;
    V291 = qvalue(elt(env, 2)); /* BOOT::|$Coerce| */
    if (V291 == nil) goto V62;
    V292 = stack[-3];
    V291 = elt(env, 3); /* BOOT::|Symbol| */
    if (!consp(V292)) goto V62;
    V292 = qcar(V292);
    if (!(V292 == V291)) goto V62;
    V292 = stack[-1];
    V291 = qvalue(elt(env, 4)); /* BOOT::|$SymbolType| */
    V291 = Latsoc(nil, V292, V291);
    stack[-1] = V291;
    if (V291 == nil) goto V62;
    V291 = stack[-5];
    if (V291 == nil) goto V62;
    V291 = stack[-1];
    if (!car_legal(V291)) goto V304;
    V292 = qcdr(V291);
    V291 = stack[-5];
    fn = elt(env, 6); /* BOOT::|resolveTT| */
    V292 = (*qfn2(fn))(qenv(fn), V292, V291);
    nil = C_nil;
    if (exception_pending()) goto V305;
    env = stack[-7];
    V291 = V292;
    if (V292 == nil) goto V62;
    V292 = stack[-1];
    V291 = Lrplacd(nil, V292, V291);
    nil = C_nil;
    if (exception_pending()) goto V305;
    env = stack[-7];
    goto V62;

V62:
    V291 = stack[0];
    if (!car_legal(V291)) goto V304;
    V291 = qcdr(V291);
    V295 = V291;
    V291 = stack[-2];
    if (!car_legal(V291)) goto V304;
    V291 = qcdr(V291);
    V294 = V291;
    V291 = stack[-4];
    if (!car_legal(V291)) goto V304;
    V291 = qcdr(V291);
    V293 = V291;
    V292 = qvalue(elt(env, 1)); /* BOOT::|$Subst| */
    V291 = elt(env, 5); /* BOOT::|failed| */
    V291 = (V292 == V291 ? lisp_true : nil);
    V292 = V295;
    stack[0] = V292;
    V292 = V294;
    stack[-2] = V292;
    V292 = V293;
    stack[-4] = V292;
    goto V34;

V80:
    V291 = qvalue(elt(env, 2)); /* BOOT::|$Coerce| */
    if (V291 == nil) goto V144;
    V292 = V293;
    V291 = elt(env, 3); /* BOOT::|Symbol| */
    if (!consp(V292)) goto V176;
    V292 = qcar(V292);
    if (!(V292 == V291)) goto V176;
    V292 = stack[-1];
    V291 = qvalue(elt(env, 4)); /* BOOT::|$SymbolType| */
    V291 = Latsoc(nil, V292, V291);
    stack[-1] = V291;
    if (V291 == nil) goto V176;
    V291 = stack[-1];
    if (!car_legal(V291)) goto V304;
    V291 = qcdr(V291);
    V293 = V291;
    goto V176;

V176:
    V292 = stack[-3];
    V291 = elt(env, 3); /* BOOT::|Symbol| */
    if (!consp(V292)) goto V191;
    V292 = qcar(V292);
    if (!(V292 == V291)) goto V191;
    V291 = stack[-5];
    if (V291 == nil) goto V191;
    V291 = stack[-5];
    stack[-3] = V291;
    goto V191;

V191:
    V292 = V293;
    V291 = stack[-3];
    fn = elt(env, 6); /* BOOT::|resolveTT| */
    V292 = (*qfn2(fn))(qenv(fn), V292, V291);
    nil = C_nil;
    if (exception_pending()) goto V305;
    env = stack[-7];
    V291 = V292;
    if (V292 == nil) goto V189;
    V292 = stack[-6];
    V291 = Lrplacd(nil, V292, V291);
    nil = C_nil;
    if (exception_pending()) goto V305;
    env = stack[-7];
    goto V62;

V189:
    V291 = lisp_true;
    if (V291 == nil) goto V62;
    V291 = elt(env, 5); /* BOOT::|failed| */
    qvalue(elt(env, 1)) = V291; /* BOOT::|$Subst| */
    goto V62;

V144:
    V291 = lisp_true;
    if (V291 == nil) goto V62;
    V291 = elt(env, 5); /* BOOT::|failed| */
    qvalue(elt(env, 1)) = V291; /* BOOT::|$Subst| */
    goto V62;

V66:
    V291 = lisp_true;
    if (V291 == nil) goto V62;
    V293 = stack[-1];
    V292 = stack[-3];
    V291 = qvalue(elt(env, 1)); /* BOOT::|$Subst| */
    V291 = acons(V293, V292, V291);
    nil = C_nil;
    if (exception_pending()) goto V305;
    env = stack[-7];
    qvalue(elt(env, 1)) = V291; /* BOOT::|$Subst| */
    V292 = stack[-3];
    V291 = elt(env, 3); /* BOOT::|Symbol| */
    if (!consp(V292)) goto V231;
    V292 = qcar(V292);
    if (!(V292 == V291)) goto V231;
    V291 = stack[-5];
    if (V291 == nil) goto V231;
    V293 = stack[-1];
    V292 = stack[-5];
    V291 = qvalue(elt(env, 4)); /* BOOT::|$SymbolType| */
    V291 = acons(V293, V292, V291);
    nil = C_nil;
    if (exception_pending()) goto V305;
    env = stack[-7];
    qvalue(elt(env, 4)) = V291; /* BOOT::|$SymbolType| */
    goto V62;

V231:
    V291 = lisp_true;
    if (V291 == nil) goto V62;
    else goto V62;

V37:
    V291 = nil;
    { popv(8); return onevalue(V291); }
/* error exit handlers */
V305:
    popv(8);
    return nil;
V304:
    popv(8);
    return error(1, err_bad_cdr, V291);
V303:
    popv(8);
    return error(1, err_bad_car, V292);
}

/*
(DEFUN BOOT::|term1RWall| (|t| R)
   (PROG (BOOT::|vars| BOOT::|varRules| BOOT::SL)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET BOOT::|vars| (CAR R))
               (BOOT:SPADLET BOOT::|varRules| (CDR R))
               (PROG (#:G18872)
                  (BOOT:SPADLET #:G18872 NIL)
                  (RETURN
                     (DO ((#:G18873 BOOT::|varRules| (CDR #:G18873))
                           (|r| NIL))
                        ((OR
                            (ATOM #:G18873)
                            (PROGN (SETQ |r| (CAR #:G18873)) NIL))
                           (NREVERSE0 #:G18872))
                        (SEQ
                           (EXIT
                              (COND
                                 ((NULL
                                     (EQ
                                        (BOOT:SPADLET
                                           BOOT::SL
                                           (BOOT::|termMatch|
                                              (CAR |r|)
                                              |t|
                                              NIL
                                              BOOT::|vars|))
                                        'BOOT::|failed|))
                                    (SETQ #:G18872
                                       (CONS
                                          (AND
                                             (NULL
                                                (BOOT:|BOOT-EQUAL|
                                                   BOOT::SL
                                                   'BOOT::|failed|))
                                             (BOOT::|subCopy|
                                                (COPY (CDR |r|))
                                                BOOT::SL))
                                          #:G18872)))) ))) ))) ))) )

*/



/* Code for BOOT::|term1RWall| */

static Lisp_Object CC_BOOT__term1RWall(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V110, V111, V112, V113;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|term1RWall|\n");
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
    V111 = V3;
    stack[-4] = V2;
/* end of prologue */
    V110 = V111;
    if (!car_legal(V110)) goto V120;
    V110 = qcar(V110);
    stack[-5] = V110;
    V110 = V111;
    if (!car_legal(V110)) goto V121;
    V110 = qcdr(V110);
    V111 = V110;
    V110 = nil;
    stack[-2] = V110;
    V110 = V111;
    stack[0] = V110;
    goto V28;

V28:
    V110 = stack[0];
    if (!consp(V110)) goto V31;
    V110 = stack[0];
    if (!car_legal(V110)) goto V120;
    V110 = qcar(V110);
    stack[-1] = V110;
    V110 = nil;
    if (!(V110 == nil)) goto V31;
    V110 = stack[-1];
    if (!car_legal(V110)) goto V120;
    V113 = qcar(V110);
    V112 = stack[-4];
    V111 = nil;
    V110 = stack[-5];
    fn = elt(env, 2); /* BOOT::|termMatch| */
    V111 = (*qfnn(fn))(qenv(fn), 4, V113, V112, V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-6];
    stack[-3] = V111;
    V110 = elt(env, 1); /* BOOT::|failed| */
    if (V111 == V110) goto V43;
    V111 = stack[-3];
    V110 = elt(env, 1); /* BOOT::|failed| */
    V110 = (V111 == V110 ? lisp_true : nil);
    if (V110 == nil) goto V91;
    V110 = nil;
    V111 = V110;
    goto V72;

V72:
    V110 = stack[-2];
    V110 = cons(V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-6];
    stack[-2] = V110;
    goto V43;

V43:
    V110 = stack[0];
    if (!car_legal(V110)) goto V121;
    V110 = qcdr(V110);
    stack[0] = V110;
    goto V28;

V91:
    V110 = stack[-1];
    if (!car_legal(V110)) goto V121;
    V110 = qcdr(V110);
    fn = elt(env, 3); /* COPY */
    V111 = (*qfn1(fn))(qenv(fn), V110);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-6];
    V110 = stack[-3];
    fn = elt(env, 4); /* BOOT::|subCopy| */
    V110 = (*qfn2(fn))(qenv(fn), V111, V110);
    nil = C_nil;
    if (exception_pending()) goto V122;
    env = stack[-6];
    V111 = V110;
    goto V72;

V31:
    V110 = stack[-2];
    {
        popv(7);
        fn = elt(env, 5); /* NREVERSE0 */
        return (*qfn1(fn))(qenv(fn), V110);
    }
/* error exit handlers */
V122:
    popv(7);
    return nil;
V121:
    popv(7);
    return error(1, err_bad_cdr, V110);
V120:
    popv(7);
    return error(1, err_bad_car, V110);
}

/*
(DEFUN BOOT::|testBitVector| (BOOT::|vec| |i|)
   (COND
      ((EQ |i| 0) 'T)
      ('T (LOGBITP (BOOT:SPADDIFFERENCE |i| 1) BOOT::|vec|))))

*/



/* Code for BOOT::|testBitVector| */

static Lisp_Object CC_BOOT__testBitVector(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|testBitVector|\n");
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
    V33 = V3;
    stack[0] = V2;
/* end of prologue */
    V32 = V33;
    V31 = (Lisp_Object)1; /* 0 */
    if (V32 == V31) goto V9;
    V31 = lisp_true;
    if (V31 == nil) goto V20;
    V31 = V33;
    V32 = sub1(V31);
    nil = C_nil;
    if (exception_pending()) goto V35;
    env = stack[-1];
    V31 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); /* LOGBITP */
        return (*qfn2(fn))(qenv(fn), V32, V31);
    }

V20:
    V31 = nil;
    { popv(2); return onevalue(V31); }

V9:
    V31 = lisp_true;
    { popv(2); return onevalue(V31); }
/* error exit handlers */
V35:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|PRIMARR;new;NniS$;4| (|n| |x| |$|)
   (BOOT:SPADCALL (VMLISP:GETREFV |n|) |x| (VMLISP:QREFELT |$| 12)))

*/



/* Code for BOOT::|PRIMARR;new;NniS$;4| */

static Lisp_Object MS_CDECL CC_BOOT__PRIMARRUnewUNniSDU4(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V36, V37, V38;
    Lisp_Object fn;
    argcheck(nargs, 3, "PRIMARR;new;NniS$;4");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PRIMARR;new;NniS$;4|\n");
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
    V36 = V4;
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    V37 = V36;
    V36 = (Lisp_Object)193; /* 12 */
    V36 = Lgetv(nil, V37, V36);
    nil = C_nil;
    if (exception_pending()) goto V43;
    env = stack[-4];
    stack[-3] = V36;
    V36 = stack[-3];
    if (!car_legal(V36)) goto V44;
    stack[0] = qcar(V36);
    V36 = stack[-2];
    fn = elt(env, 1); /* MAKE-ARRAY-1 */
    V38 = (*qfn1(fn))(qenv(fn), V36);
    nil = C_nil;
    if (exception_pending()) goto V43;
    V37 = stack[-1];
    V36 = stack[-3];
    if (!car_legal(V36)) goto V45;
    V36 = qcdr(V36);
    {
        Lisp_Object V46 = stack[0];
        popv(5);
        return Lapply3(nil, 4, V46, V38, V37, V36);
    }
/* error exit handlers */
V45:
    popv(5);
    return error(1, err_bad_cdr, V36);
V44:
    popv(5);
    return error(1, err_bad_car, V36);
V43:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|SMP;gcd;3$;45| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (BOOT::|mvar| BOOT::|up|)
      (RETURN
         (SEQ
            (COND
               ((BOOT::QEQCAR BOOT::|p1| 0)
                  (COND
                     ((BOOT::QEQCAR BOOT::|p2| 0)
                        (CONS
                           0
                           (BOOT:SPADCALL
                              (QCDR BOOT::|p1|)
                              (QCDR BOOT::|p2|)
                              (VMLISP:QREFELT |$| 130))))
                     ((BOOT:SPADCALL BOOT::|p1| (VMLISP:QREFELT |$| 17))
                        BOOT::|p2|)
                     ('T
                        (BOOT:SPADCALL
                           BOOT::|p1|
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p2|))
                              (VMLISP:QREFELT |$| 131))
                           (VMLISP:QREFELT |$| 133)))) )
               ((BOOT::QEQCAR BOOT::|p2| 0)
                  (COND
                     ((BOOT:SPADCALL BOOT::|p2| (VMLISP:QREFELT |$| 17))
                        BOOT::|p1|)
                     ('T
                        (BOOT:SPADCALL
                           BOOT::|p2|
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p1|))
                              (VMLISP:QREFELT |$| 131))
                           (VMLISP:QREFELT |$| 133)))) )
               ('T
                  (COND
                     ((BOOT:SPADCALL
                         (QCAR (QCDR BOOT::|p1|))
                         (QCAR (QCDR BOOT::|p2|))
                         (VMLISP:QREFELT |$| 50))
                        (BOOT:SPADCALL
                           BOOT::|p1|
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p2|))
                              (VMLISP:QREFELT |$| 131))
                           (VMLISP:QREFELT |$| 133)))
                     ((BOOT:SPADCALL
                         (QCAR (QCDR BOOT::|p2|))
                         (QCAR (QCDR BOOT::|p1|))
                         (VMLISP:QREFELT |$| 50))
                        (BOOT:SPADCALL
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p1|))
                              (VMLISP:QREFELT |$| 131))
                           BOOT::|p2|
                           (VMLISP:QREFELT |$| 133)))
                     ('T
                        (SEQ
                           (BOOT::LETT
                              BOOT::|mvar|
                              (QCAR (QCDR BOOT::|p1|))
                              BOOT::|SMP;gcd;3$;45|)
                           (BOOT::LETT
                              BOOT::|up|
                              (BOOT:SPADCALL
                                 (QCDR (QCDR BOOT::|p1|))
                                 (QCDR (QCDR BOOT::|p2|))
                                 (VMLISP:QREFELT |$| 134))
                              BOOT::|SMP;gcd;3$;45|)
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
                                          BOOT::|up|)))) ))) ))) ))) )

*/



/* Code for BOOT::|SMP;gcd;3$;45| */

static Lisp_Object MS_CDECL CC_BOOT__SMPUgcdU3DU45(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V535, V536, V537, V538;
    argcheck(nargs, 3, "SMP;gcd;3$;45");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;gcd;3$;45|\n");
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
    V535 = stack[-3];
    V536 = qcar(V535);
    V535 = (Lisp_Object)1; /* 0 */
    V535 = Leql(nil, V536, V535);
    env = stack[-5];
    if (V535 == nil) goto V161;
    V535 = stack[-2];
    V536 = qcar(V535);
    V535 = (Lisp_Object)1; /* 0 */
    V535 = Leql(nil, V536, V535);
    env = stack[-5];
    if (V535 == nil) goto V82;
    stack[0] = (Lisp_Object)1; /* 0 */
    V536 = stack[-1];
    V535 = (Lisp_Object)2081; /* 130 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-3];
    V537 = qcdr(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    {
        Lisp_Object V547 = stack[0];
        popv(6);
        { Lisp_Object retVal = cons(V547, V535);
        errexit();
        return onevalue(retVal); }
    }

V82:
    V536 = stack[-1];
    V535 = (Lisp_Object)273; /* 17 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-3];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (!(V535 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    V535 = lisp_true;
    if (V535 == nil) goto V104;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V549 = stack[0];
        Lisp_Object V550 = stack[-3];
        popv(6);
        return Lapply3(nil, 4, V549, V550, V536, V535);
    }

V104:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V161:
    V535 = stack[-2];
    V536 = qcar(V535);
    V535 = (Lisp_Object)1; /* 0 */
    V535 = Leql(nil, V536, V535);
    env = stack[-5];
    if (V535 == nil) goto V159;
    V536 = stack[-1];
    V535 = (Lisp_Object)273; /* 17 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (!(V535 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    V535 = lisp_true;
    if (V535 == nil) goto V199;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V551 = stack[0];
        Lisp_Object V552 = stack[-2];
        popv(6);
        return Lapply3(nil, 4, V551, V552, V536, V535);
    }

V199:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V159:
    V535 = lisp_true;
    if (V535 == nil) goto V254;
    V536 = stack[-1];
    V535 = (Lisp_Object)801; /* 50 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V537 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcar(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (V535 == nil) goto V349;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V553 = stack[0];
        Lisp_Object V554 = stack[-3];
        popv(6);
        return Lapply3(nil, 4, V553, V554, V536, V535);
    }

V349:
    V536 = stack[-1];
    V535 = (Lisp_Object)801; /* 50 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V537 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V536 = qcar(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (V535 == nil) goto V344;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V537 = V535;
    V536 = stack[-2];
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V555 = stack[0];
        popv(6);
        return Lapply3(nil, 4, V555, V537, V536, V535);
    }

V344:
    V535 = lisp_true;
    if (V535 == nil) goto V429;
    V535 = stack[-3];
    V535 = qcdr(V535);
    V535 = qcar(V535);
    stack[0] = V535;
    V536 = stack[-1];
    V535 = (Lisp_Object)2145; /* 134 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V537 = qcdr(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-2] = V535;
    V536 = stack[-1];
    V535 = (Lisp_Object)337; /* 21 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (V535 == nil) goto V470;
    V536 = stack[-1];
    V535 = (Lisp_Object)353; /* 22 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
        popv(6);
        return Lapply2(nil, 3, V537, V536, V535);

V470:
    V535 = lisp_true;
    if (V535 == nil) goto V520;
    V537 = (Lisp_Object)17; /* 1 */
    V536 = stack[0];
    V535 = stack[-2];
    popv(6);
    { Lisp_Object retVal = list2star(V537, V536, V535);
    errexit();
    return onevalue(retVal); }

V520:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V429:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V254:
    V535 = nil;
    { popv(6); return onevalue(V535); }
/* error exit handlers */
V548:
    popv(6);
    return error(1, err_bad_car, V535);
V546:
    popv(6);
    return error(1, err_bad_cdr, V535);
V545:
    popv(6);
    return error(1, err_bad_car, V536);
V544:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|SMP;gcd;3$;48| (BOOT::|p1| BOOT::|p2| |$|)
   (BOOT:SPADCALL BOOT::|p1| BOOT::|p2| (VMLISP:QREFELT |$| 144)))

*/



/* Code for BOOT::|SMP;gcd;3$;48| */

static Lisp_Object MS_CDECL CC_BOOT__SMPUgcdU3DU48(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "SMP;gcd;3$;48");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;gcd;3$;48|\n");
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
    V35 = (Lisp_Object)2305; /* 144 */
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
(DEFUN BOOT::|SMP;gcd;3$;52| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (BOOT::|mvar| BOOT::|up|)
      (RETURN
         (SEQ
            (COND
               ((BOOT::QEQCAR BOOT::|p1| 0)
                  (COND
                     ((BOOT::QEQCAR BOOT::|p2| 0)
                        (CONS
                           0
                           (BOOT:SPADCALL
                              (QCDR BOOT::|p1|)
                              (QCDR BOOT::|p2|)
                              (VMLISP:QREFELT |$| 130))))
                     ((BOOT:SPADCALL BOOT::|p1| (VMLISP:QREFELT |$| 17))
                        BOOT::|p2|)
                     ('T
                        (BOOT:SPADCALL
                           BOOT::|p1|
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p2|))
                              (VMLISP:QREFELT |$| 131))
                           (VMLISP:QREFELT |$| 133)))) )
               ((BOOT::QEQCAR BOOT::|p2| 0)
                  (COND
                     ((BOOT:SPADCALL BOOT::|p2| (VMLISP:QREFELT |$| 17))
                        BOOT::|p1|)
                     ('T
                        (BOOT:SPADCALL
                           BOOT::|p2|
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p1|))
                              (VMLISP:QREFELT |$| 131))
                           (VMLISP:QREFELT |$| 133)))) )
               ('T
                  (COND
                     ((BOOT:SPADCALL
                         (QCAR (QCDR BOOT::|p1|))
                         (QCAR (QCDR BOOT::|p2|))
                         (VMLISP:QREFELT |$| 50))
                        (BOOT:SPADCALL
                           BOOT::|p1|
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p2|))
                              (VMLISP:QREFELT |$| 131))
                           (VMLISP:QREFELT |$| 133)))
                     ((BOOT:SPADCALL
                         (QCAR (QCDR BOOT::|p2|))
                         (QCAR (QCDR BOOT::|p1|))
                         (VMLISP:QREFELT |$| 50))
                        (BOOT:SPADCALL
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p1|))
                              (VMLISP:QREFELT |$| 131))
                           BOOT::|p2|
                           (VMLISP:QREFELT |$| 133)))
                     ('T
                        (SEQ
                           (BOOT::LETT
                              BOOT::|mvar|
                              (QCAR (QCDR BOOT::|p1|))
                              BOOT::|SMP;gcd;3$;52|)
                           (BOOT::LETT
                              BOOT::|up|
                              (BOOT:SPADCALL
                                 (QCDR (QCDR BOOT::|p1|))
                                 (QCDR (QCDR BOOT::|p2|))
                                 (VMLISP:QREFELT |$| 134))
                              BOOT::|SMP;gcd;3$;52|)
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
                                          BOOT::|up|)))) ))) ))) ))) )

*/



/* Code for BOOT::|SMP;gcd;3$;52| */

static Lisp_Object MS_CDECL CC_BOOT__SMPUgcdU3DU52(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V535, V536, V537, V538;
    argcheck(nargs, 3, "SMP;gcd;3$;52");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;gcd;3$;52|\n");
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
    V535 = stack[-3];
    V536 = qcar(V535);
    V535 = (Lisp_Object)1; /* 0 */
    V535 = Leql(nil, V536, V535);
    env = stack[-5];
    if (V535 == nil) goto V161;
    V535 = stack[-2];
    V536 = qcar(V535);
    V535 = (Lisp_Object)1; /* 0 */
    V535 = Leql(nil, V536, V535);
    env = stack[-5];
    if (V535 == nil) goto V82;
    stack[0] = (Lisp_Object)1; /* 0 */
    V536 = stack[-1];
    V535 = (Lisp_Object)2081; /* 130 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-3];
    V537 = qcdr(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    {
        Lisp_Object V547 = stack[0];
        popv(6);
        { Lisp_Object retVal = cons(V547, V535);
        errexit();
        return onevalue(retVal); }
    }

V82:
    V536 = stack[-1];
    V535 = (Lisp_Object)273; /* 17 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-3];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (!(V535 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    V535 = lisp_true;
    if (V535 == nil) goto V104;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V549 = stack[0];
        Lisp_Object V550 = stack[-3];
        popv(6);
        return Lapply3(nil, 4, V549, V550, V536, V535);
    }

V104:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V161:
    V535 = stack[-2];
    V536 = qcar(V535);
    V535 = (Lisp_Object)1; /* 0 */
    V535 = Leql(nil, V536, V535);
    env = stack[-5];
    if (V535 == nil) goto V159;
    V536 = stack[-1];
    V535 = (Lisp_Object)273; /* 17 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (!(V535 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    V535 = lisp_true;
    if (V535 == nil) goto V199;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V551 = stack[0];
        Lisp_Object V552 = stack[-2];
        popv(6);
        return Lapply3(nil, 4, V551, V552, V536, V535);
    }

V199:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V159:
    V535 = lisp_true;
    if (V535 == nil) goto V254;
    V536 = stack[-1];
    V535 = (Lisp_Object)801; /* 50 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V537 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcar(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (V535 == nil) goto V349;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V553 = stack[0];
        Lisp_Object V554 = stack[-3];
        popv(6);
        return Lapply3(nil, 4, V553, V554, V536, V535);
    }

V349:
    V536 = stack[-1];
    V535 = (Lisp_Object)801; /* 50 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V537 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V536 = qcar(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (V535 == nil) goto V344;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V537 = V535;
    V536 = stack[-2];
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V555 = stack[0];
        popv(6);
        return Lapply3(nil, 4, V555, V537, V536, V535);
    }

V344:
    V535 = lisp_true;
    if (V535 == nil) goto V429;
    V535 = stack[-3];
    V535 = qcdr(V535);
    V535 = qcar(V535);
    stack[0] = V535;
    V536 = stack[-1];
    V535 = (Lisp_Object)2145; /* 134 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V537 = qcdr(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-2] = V535;
    V536 = stack[-1];
    V535 = (Lisp_Object)337; /* 21 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (V535 == nil) goto V470;
    V536 = stack[-1];
    V535 = (Lisp_Object)353; /* 22 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
        popv(6);
        return Lapply2(nil, 3, V537, V536, V535);

V470:
    V535 = lisp_true;
    if (V535 == nil) goto V520;
    V537 = (Lisp_Object)17; /* 1 */
    V536 = stack[0];
    V535 = stack[-2];
    popv(6);
    { Lisp_Object retVal = list2star(V537, V536, V535);
    errexit();
    return onevalue(retVal); }

V520:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V429:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V254:
    V535 = nil;
    { popv(6); return onevalue(V535); }
/* error exit handlers */
V548:
    popv(6);
    return error(1, err_bad_car, V535);
V546:
    popv(6);
    return error(1, err_bad_cdr, V535);
V545:
    popv(6);
    return error(1, err_bad_car, V536);
V544:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|SMP;gcd;3$;55| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (BOOT::|mvar| BOOT::|up|)
      (RETURN
         (SEQ
            (COND
               ((BOOT::QEQCAR BOOT::|p1| 0)
                  (COND
                     ((BOOT::QEQCAR BOOT::|p2| 0)
                        (CONS
                           0
                           (BOOT:SPADCALL
                              (QCDR BOOT::|p1|)
                              (QCDR BOOT::|p2|)
                              (VMLISP:QREFELT |$| 130))))
                     ((BOOT:SPADCALL BOOT::|p1| (VMLISP:QREFELT |$| 17))
                        BOOT::|p2|)
                     ('T
                        (BOOT:SPADCALL
                           BOOT::|p1|
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p2|))
                              (VMLISP:QREFELT |$| 131))
                           (VMLISP:QREFELT |$| 133)))) )
               ((BOOT::QEQCAR BOOT::|p2| 0)
                  (COND
                     ((BOOT:SPADCALL BOOT::|p2| (VMLISP:QREFELT |$| 17))
                        BOOT::|p1|)
                     ('T
                        (BOOT:SPADCALL
                           BOOT::|p2|
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p1|))
                              (VMLISP:QREFELT |$| 131))
                           (VMLISP:QREFELT |$| 133)))) )
               ('T
                  (COND
                     ((BOOT:SPADCALL
                         (QCAR (QCDR BOOT::|p1|))
                         (QCAR (QCDR BOOT::|p2|))
                         (VMLISP:QREFELT |$| 50))
                        (BOOT:SPADCALL
                           BOOT::|p1|
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p2|))
                              (VMLISP:QREFELT |$| 131))
                           (VMLISP:QREFELT |$| 133)))
                     ((BOOT:SPADCALL
                         (QCAR (QCDR BOOT::|p2|))
                         (QCAR (QCDR BOOT::|p1|))
                         (VMLISP:QREFELT |$| 50))
                        (BOOT:SPADCALL
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p1|))
                              (VMLISP:QREFELT |$| 131))
                           BOOT::|p2|
                           (VMLISP:QREFELT |$| 133)))
                     ('T
                        (SEQ
                           (BOOT::LETT
                              BOOT::|mvar|
                              (QCAR (QCDR BOOT::|p1|))
                              BOOT::|SMP;gcd;3$;55|)
                           (BOOT::LETT
                              BOOT::|up|
                              (BOOT:SPADCALL
                                 (QCDR (QCDR BOOT::|p1|))
                                 (QCDR (QCDR BOOT::|p2|))
                                 (VMLISP:QREFELT |$| 134))
                              BOOT::|SMP;gcd;3$;55|)
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
                                          BOOT::|up|)))) ))) ))) ))) )

*/



/* Code for BOOT::|SMP;gcd;3$;55| */

static Lisp_Object MS_CDECL CC_BOOT__SMPUgcdU3DU55(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V535, V536, V537, V538;
    argcheck(nargs, 3, "SMP;gcd;3$;55");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;gcd;3$;55|\n");
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
    V535 = stack[-3];
    V536 = qcar(V535);
    V535 = (Lisp_Object)1; /* 0 */
    V535 = Leql(nil, V536, V535);
    env = stack[-5];
    if (V535 == nil) goto V161;
    V535 = stack[-2];
    V536 = qcar(V535);
    V535 = (Lisp_Object)1; /* 0 */
    V535 = Leql(nil, V536, V535);
    env = stack[-5];
    if (V535 == nil) goto V82;
    stack[0] = (Lisp_Object)1; /* 0 */
    V536 = stack[-1];
    V535 = (Lisp_Object)2081; /* 130 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-3];
    V537 = qcdr(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    {
        Lisp_Object V547 = stack[0];
        popv(6);
        { Lisp_Object retVal = cons(V547, V535);
        errexit();
        return onevalue(retVal); }
    }

V82:
    V536 = stack[-1];
    V535 = (Lisp_Object)273; /* 17 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-3];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (!(V535 == nil)) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    V535 = lisp_true;
    if (V535 == nil) goto V104;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V549 = stack[0];
        Lisp_Object V550 = stack[-3];
        popv(6);
        return Lapply3(nil, 4, V549, V550, V536, V535);
    }

V104:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V161:
    V535 = stack[-2];
    V536 = qcar(V535);
    V535 = (Lisp_Object)1; /* 0 */
    V535 = Leql(nil, V536, V535);
    env = stack[-5];
    if (V535 == nil) goto V159;
    V536 = stack[-1];
    V535 = (Lisp_Object)273; /* 17 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (!(V535 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    V535 = lisp_true;
    if (V535 == nil) goto V199;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V551 = stack[0];
        Lisp_Object V552 = stack[-2];
        popv(6);
        return Lapply3(nil, 4, V551, V552, V536, V535);
    }

V199:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V159:
    V535 = lisp_true;
    if (V535 == nil) goto V254;
    V536 = stack[-1];
    V535 = (Lisp_Object)801; /* 50 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V537 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcar(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (V535 == nil) goto V349;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V553 = stack[0];
        Lisp_Object V554 = stack[-3];
        popv(6);
        return Lapply3(nil, 4, V553, V554, V536, V535);
    }

V349:
    V536 = stack[-1];
    V535 = (Lisp_Object)801; /* 50 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V537 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V536 = qcar(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (V535 == nil) goto V344;
    V536 = stack[-1];
    V535 = (Lisp_Object)2129; /* 133 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-4] = V535;
    V535 = stack[-4];
    if (!car_legal(V535)) goto V548;
    stack[0] = qcar(V535);
    V536 = stack[-1];
    V535 = (Lisp_Object)2097; /* 131 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V537 = V535;
    V536 = stack[-2];
    V535 = stack[-4];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    {
        Lisp_Object V555 = stack[0];
        popv(6);
        return Lapply3(nil, 4, V555, V537, V536, V535);
    }

V344:
    V535 = lisp_true;
    if (V535 == nil) goto V429;
    V535 = stack[-3];
    V535 = qcdr(V535);
    V535 = qcar(V535);
    stack[0] = V535;
    V536 = stack[-1];
    V535 = (Lisp_Object)2145; /* 134 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V538 = qcar(V536);
    V536 = stack[-3];
    V536 = qcdr(V536);
    V537 = qcdr(V536);
    V536 = stack[-2];
    V536 = qcdr(V536);
    V536 = qcdr(V536);
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply3(nil, 4, V538, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    stack[-2] = V535;
    V536 = stack[-1];
    V535 = (Lisp_Object)337; /* 21 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
    V535 = Lapply2(nil, 3, V537, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    env = stack[-5];
    if (V535 == nil) goto V470;
    V536 = stack[-1];
    V535 = (Lisp_Object)353; /* 22 */
    V535 = Lgetv(nil, V536, V535);
    nil = C_nil;
    if (exception_pending()) goto V544;
    V536 = V535;
    if (!car_legal(V536)) goto V545;
    V537 = qcar(V536);
    V536 = stack[-2];
    if (!car_legal(V535)) goto V546;
    V535 = qcdr(V535);
        popv(6);
        return Lapply2(nil, 3, V537, V536, V535);

V470:
    V535 = lisp_true;
    if (V535 == nil) goto V520;
    V537 = (Lisp_Object)17; /* 1 */
    V536 = stack[0];
    V535 = stack[-2];
    popv(6);
    { Lisp_Object retVal = list2star(V537, V536, V535);
    errexit();
    return onevalue(retVal); }

V520:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V429:
    V535 = nil;
    { popv(6); return onevalue(V535); }

V254:
    V535 = nil;
    { popv(6); return onevalue(V535); }
/* error exit handlers */
V548:
    popv(6);
    return error(1, err_bad_car, V535);
V546:
    popv(6);
    return error(1, err_bad_cdr, V535);
V545:
    popv(6);
    return error(1, err_bad_car, V536);
V544:
    popv(6);
    return nil;
}



setup_type const u07_setup[] =
{
    {"BOOT@@FLASORT;QuickSort@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__FLASORTUQuickSort},
    {"BOOT@@EXPR;algkernels!0@@Builtin",too_few_2,CC_BOOT__EXPRUalgkernelsB0,wrong_no_2},
    {"BOOT@@pfAbSynOp?@@Builtin",too_few_2,     CC_BOOT__pfAbSynOpW,wrong_no_2},
    {"BOOT@@COMPLEX;*;3$;15@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__COMPLEXUHU3DU15},
    {"BOOT@@selectMmsGen,exact?@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__selectMmsGenPexactW},
    {"VMLISP@@last@@Builtin",   CC_VMLISP__last,too_many_1,    wrong_no_1},
    {"BOOT@@evalMmCond0@@Builtin",wrong_no_na,  wrong_no_nb,   (n_args *)CC_BOOT__evalMmCond0},
    {"BOOT@@COMPCAT-;exquo;SRU;46@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__COMPCATKUexquoUSRUU46},
    {"BOOT@@FLASORT;partition@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__FLASORTUpartition},
    {"BOOT@@FM;*;R2$;1@@Builtin",wrong_no_na,   wrong_no_nb,   (n_args *)CC_BOOT__FMUHUR2DU1},
    {"BOOT@@newExpandTypeSlot@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__newExpandTypeSlot},
    {"BOOT@@FRAC;*;3$;23@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__FRACUHU3DU23},
    {"BOOT@@matchTypes@@Builtin",wrong_no_na,   wrong_no_nb,   (n_args *)CC_BOOT__matchTypes},
    {"BOOT@@term1RWall@@Builtin",too_few_2,     CC_BOOT__term1RWall,wrong_no_2},
    {"BOOT@@testBitVector@@Builtin",too_few_2,  CC_BOOT__testBitVector,wrong_no_2},
    {"BOOT@@PRIMARR;new;NniS$;4@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__PRIMARRUnewUNniSDU4},
    {"BOOT@@SMP;gcd;3$;45@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__SMPUgcdU3DU45},
    {"BOOT@@SMP;gcd;3$;48@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__SMPUgcdU3DU48},
    {"BOOT@@SMP;gcd;3$;52@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__SMPUgcdU3DU52},
    {"BOOT@@SMP;gcd;3$;55@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__SMPUgcdU3DU55},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
