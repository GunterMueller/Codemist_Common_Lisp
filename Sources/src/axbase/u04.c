
/* u04.c                 Machine generated C code */

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
(DEFUN BOOT::|ILIST;removeDuplicates!;2$;26| (|l| |$|)
   (PROG (|f| |p| BOOT::|pr| BOOT:|pp|)
      (RETURN
         (SEQ
            (BOOT::LETT |p| |l| BOOT::|ILIST;removeDuplicates!;2$;26|)
            (SEQ
               BOOT::G190
               (COND
                  ((NULL (COND ((NULL |p|) 'NIL) ('T 'T)))
                     (GO BOOT::G191)))
               (SEQ
                  (BOOT::LETT
                     BOOT:|pp|
                     |p|
                     BOOT::|ILIST;removeDuplicates!;2$;26|)
                  (BOOT::LETT
                     |f|
                     (QCAR |p|)
                     BOOT::|ILIST;removeDuplicates!;2$;26|)
                  (BOOT::LETT
                     |p|
                     (QCDR |p|)
                     BOOT::|ILIST;removeDuplicates!;2$;26|)
                  (EXIT
                     (SEQ
                        BOOT::G190
                        (COND
                           ((NULL
                               (COND
                                  ((NULL
                                      (BOOT::LETT
                                         BOOT::|pr|
                                         (QCDR BOOT:|pp|)
                                   BOOT::|ILIST;removeDuplicates!;2$;26|))
                                     'NIL)
                                  ('T 'T)))
                              (GO BOOT::G191)))
                        (SEQ
                           (EXIT
                              (COND
                                 ((BOOT:SPADCALL
                                     (QCAR BOOT::|pr|)
                                     |f|
                                     (VMLISP:QREFELT |$| 46))
                                    (VMLISP:QRPLACD
                                       BOOT:|pp|
                                       (QCDR BOOT::|pr|)))
                                 ('T
                                    (BOOT::LETT
                                       BOOT:|pp|
                                       BOOT::|pr|
                              BOOT::|ILIST;removeDuplicates!;2$;26|)))) )
                        NIL
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT NIL))))
               NIL
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT |l|)))) )

*/



/* Code for BOOT::|ILIST;removeDuplicates!;2$;26| */

static Lisp_Object CC_BOOT__ILISTUremoveDuplicatesBU2DU26(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V117, V118, V119, V120;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;removeDuplicates!;2$;26|\n");
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
    V117 = stack[-4];
    stack[-2] = V117;
    goto V18;

V18:
    V117 = stack[-2];
    if (V117 == nil) goto V26;
    V117 = lisp_true;
    if (V117 == nil) goto V31;
    V117 = lisp_true;
    goto V25;

V25:
    if (V117 == nil) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    V117 = stack[-2];
    stack[0] = V117;
    V117 = stack[-2];
    V117 = qcar(V117);
    stack[-5] = V117;
    V117 = stack[-2];
    V117 = qcdr(V117);
    stack[-2] = V117;
    goto V43;

V43:
    V117 = stack[0];
    V117 = qcdr(V117);
    stack[-1] = V117;
    if (V117 == nil) goto V51;
    V117 = lisp_true;
    if (V117 == nil) goto V57;
    V117 = lisp_true;
    goto V50;

V50:
    if (V117 == nil) goto V18;
    V118 = stack[-3];
    V117 = (Lisp_Object)737; /* 46 */
    V117 = Lgetv(nil, V118, V117);
    nil = C_nil;
    if (exception_pending()) goto V127;
    env = stack[-6];
    V118 = V117;
    if (!car_legal(V118)) goto V128;
    V120 = qcar(V118);
    V118 = stack[-1];
    V119 = qcar(V118);
    V118 = stack[-5];
    if (!car_legal(V117)) goto V129;
    V117 = qcdr(V117);
    V117 = Lapply3(nil, 4, V120, V119, V118, V117);
    nil = C_nil;
    if (exception_pending()) goto V127;
    env = stack[-6];
    if (V117 == nil) goto V65;
    V118 = stack[0];
    V117 = stack[-1];
    V117 = qcdr(V117);
    V117 = Lrplacd(nil, V118, V117);
    nil = C_nil;
    if (exception_pending()) goto V127;
    env = stack[-6];
    goto V43;

V65:
    V117 = lisp_true;
    if (V117 == nil) goto V43;
    V117 = stack[-1];
    stack[0] = V117;
    goto V43;

V57:
    V117 = nil;
    goto V50;

V51:
    V117 = nil;
    goto V50;

V31:
    V117 = nil;
    goto V25;

V26:
    V117 = nil;
    goto V25;
/* error exit handlers */
V129:
    popv(7);
    return error(1, err_bad_cdr, V117);
V128:
    popv(7);
    return error(1, err_bad_car, V118);
V127:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::UNSQUEEZE (EXPR)
   (COND
      ((ATOM EXPR)
         (COND
            ((AND (NUMBERP EXPR) (|<=| EXPR 0))
               (SVREF BOOT::|*COMPRESSVECTOR*| (|-| EXPR)))
            (T EXPR)))
      (T (RPLACA EXPR (BOOT::UNSQUEEZE (CAR EXPR)))
         (RPLACD EXPR (BOOT::UNSQUEEZE (CDR EXPR)))
         EXPR)))

*/



/* Code for BOOT::UNSQUEEZE */

static Lisp_Object CC_BOOT__UNSQUEEZE(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V61, V62;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::UNSQUEEZE\n");
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
    V61 = stack[0];
    if (!consp(V61)) goto V8;
    stack[-1] = stack[0];
    V61 = stack[0];
    if (!car_legal(V61)) goto V65;
    V61 = qcar(V61);
    V61 = CC_BOOT__UNSQUEEZE(env, V61);
    nil = C_nil;
    if (exception_pending()) goto V66;
    env = stack[-2];
    V61 = Lrplaca(nil, stack[-1], V61);
    nil = C_nil;
    if (exception_pending()) goto V66;
    env = stack[-2];
    stack[-1] = stack[0];
    V61 = stack[0];
    if (!car_legal(V61)) goto V67;
    V61 = qcdr(V61);
    V61 = CC_BOOT__UNSQUEEZE(env, V61);
    nil = C_nil;
    if (exception_pending()) goto V66;
    env = stack[-2];
    V61 = Lrplacd(nil, stack[-1], V61);
    nil = C_nil;
    if (exception_pending()) goto V66;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }

V8:
    V61 = stack[0];
    if (!(is_number(V61))) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    V62 = stack[0];
    V61 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 2); /* <= */
    V61 = (*qfn2(fn))(qenv(fn), V62, V61);
    nil = C_nil;
    if (exception_pending()) goto V66;
    env = stack[-2];
    if (V61 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = qvalue(elt(env, 1)); /* BOOT::*COMPRESSVECTOR* */
    V61 = stack[0];
    V61 = negate(V61);
    nil = C_nil;
    if (exception_pending()) goto V66;
    {
        Lisp_Object V68 = stack[-1];
        popv(3);
        return Lgetv(nil, V68, V61);
    }
/* error exit handlers */
V67:
    popv(3);
    return error(1, err_bad_cdr, V61);
V66:
    popv(3);
    return nil;
V65:
    popv(3);
    return error(1, err_bad_car, V61);
}

/*
(DEFUN BOOT::|EXPR;algkernels| (|l| |$|)
   (BOOT:SPADCALL
      (CONS (FUNCTION BOOT::|EXPR;algkernels!0|) |$|)
      |l|
      (VMLISP:QREFELT |$| 89)))

*/



/* Code for BOOT::|EXPR;algkernels| */

static Lisp_Object CC_BOOT__EXPRUalgkernels(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V41, V42, V43;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;algkernels|\n");
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
    V42 = stack[-1];
    V41 = (Lisp_Object)1425; /* 89 */
    V41 = Lgetv(nil, V42, V41);
    nil = C_nil;
    if (exception_pending()) goto V48;
    env = stack[-4];
    stack[-3] = V41;
    V41 = stack[-3];
    if (!car_legal(V41)) goto V49;
    stack[0] = qcar(V41);
    V42 = elt(env, 1); /* BOOT::|EXPR;algkernels!0| */
    V41 = stack[-1];
    V43 = cons(V42, V41);
    nil = C_nil;
    if (exception_pending()) goto V48;
    V42 = stack[-2];
    V41 = stack[-3];
    if (!car_legal(V41)) goto V50;
    V41 = qcdr(V41);
    {
        Lisp_Object V51 = stack[0];
        popv(5);
        return Lapply3(nil, 4, V51, V43, V42, V41);
    }
/* error exit handlers */
V50:
    popv(5);
    return error(1, err_bad_cdr, V41);
V49:
    popv(5);
    return error(1, err_bad_car, V41);
V48:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|BOP;weight;$Nni;28| (BOOT::|op| |$|)
   (PROG (|w|)
      (RETURN
         (SEQ
            (BOOT::LETT
               |w|
               (BOOT:SPADCALL BOOT::|op| "%weight" (VMLISP:QREFELT |$| 24))
               BOOT::|BOP;weight;$Nni;28|)
            (EXIT (COND ((BOOT::QEQCAR |w| 1) 1) ('T (QCDR |w|)))) ))) )

*/



/* Code for BOOT::|BOP;weight;$Nni;28| */

static Lisp_Object CC_BOOT__BOPUweightUDNniU28(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V59, V60, V61, V62;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|BOP;weight;$Nni;28|\n");
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
    V59 = V3;
    stack[0] = V2;
/* end of prologue */
    V60 = V59;
    V59 = (Lisp_Object)385; /* 24 */
    V59 = Lgetv(nil, V60, V59);
    nil = C_nil;
    if (exception_pending()) goto V64;
    env = stack[-1];
    V60 = V59;
    if (!car_legal(V60)) goto V65;
    V62 = qcar(V60);
    V61 = stack[0];
    V60 = elt(env, 1); /* "%weight" */
    if (!car_legal(V59)) goto V66;
    V59 = qcdr(V59);
    V59 = Lapply3(nil, 4, V62, V61, V60, V59);
    nil = C_nil;
    if (exception_pending()) goto V64;
    env = stack[-1];
    V61 = V59;
    V59 = V61;
    V60 = qcar(V59);
    V59 = (Lisp_Object)17; /* 1 */
    V59 = Leql(nil, V60, V59);
    if (V59 == nil) goto V42;
    V59 = (Lisp_Object)17; /* 1 */
    { popv(2); return onevalue(V59); }

V42:
    V59 = lisp_true;
    if (V59 == nil) goto V54;
    V59 = V61;
    V59 = qcdr(V59);
    { popv(2); return onevalue(V59); }

V54:
    V59 = nil;
    { popv(2); return onevalue(V59); }
/* error exit handlers */
V66:
    popv(2);
    return error(1, err_bad_cdr, V59);
V65:
    popv(2);
    return error(1, err_bad_car, V60);
V64:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|isExposedConstructor| (BOOT::|name|)
   (PROG (|x| BOOT::|found|)
      (RETURN
         (SEQ
            (COND
               ((MEMQ
                   BOOT::|name|
                   '(BOOT::|Union| BOOT::|Record| BOOT::|Mapping|))
                  'T)
               ((MEMQ BOOT::|name| (ELT BOOT::|$localExposureData| 2)) NIL)
               ((MEMQ BOOT::|name| (ELT BOOT::|$localExposureData| 1)) 'T)
               ('T
                  (BOOT:SPADLET BOOT::|found| NIL)
                  (DO ((#:G18954
                         (ELT BOOT::|$localExposureData| 0)
                         (CDR #:G18954))
                        (|g| NIL))
                     ((OR
                         (ATOM #:G18954)
                         (PROGN (SETQ |g| (CAR #:G18954)) NIL)
                         (NULL (NULL BOOT::|found|)))
                        NIL)
                     (SEQ
                        (EXIT
                           (COND
                              ((NULL
                                  (BOOT:SPADLET
                                     |x|
                                     (BOOT::GETALIST
                                        BOOT::|$globalExposureGroupAlist|
                                        |g|)))
                                 'BOOT::|iterate|)
                              ((BOOT::GETALIST |x| BOOT::|name|)
                                 (BOOT:SPADLET BOOT::|found| 'T))
                              ('T NIL)))) )
                  BOOT::|found|)))) ))

*/



/* Code for BOOT::|isExposedConstructor| */

static Lisp_Object CC_BOOT__isExposedConstructor(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V133, V134;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isExposedConstructor|\n");
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
    V134 = stack[-1];
    V133 = elt(env, 1); /* (BOOT::|Union| BOOT::|Record| BOOT::|Mapping|) */
    V133 = Lmemq(nil, V134, V133);
    if (V133 == nil) goto V27;
    V133 = lisp_true;
    { popv(4); return onevalue(V133); }

V27:
    stack[0] = stack[-1];
    V134 = qvalue(elt(env, 2)); /* BOOT::|$localExposureData| */
    V133 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 5); /* ELT */
    V133 = (*qfn2(fn))(qenv(fn), V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V138;
    env = stack[-3];
    V133 = Lmemq(nil, stack[0], V133);
    if (V133 == nil) goto V45;
    V133 = nil;
    { popv(4); return onevalue(V133); }

V45:
    stack[0] = stack[-1];
    V134 = qvalue(elt(env, 2)); /* BOOT::|$localExposureData| */
    V133 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* ELT */
    V133 = (*qfn2(fn))(qenv(fn), V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V138;
    env = stack[-3];
    V133 = Lmemq(nil, stack[0], V133);
    if (V133 == nil) goto V44;
    V133 = lisp_true;
    { popv(4); return onevalue(V133); }

V44:
    V133 = lisp_true;
    if (V133 == nil) goto V62;
    V133 = nil;
    stack[-2] = V133;
    V134 = qvalue(elt(env, 2)); /* BOOT::|$localExposureData| */
    V133 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 5); /* ELT */
    V133 = (*qfn2(fn))(qenv(fn), V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V138;
    env = stack[-3];
    stack[0] = V133;
    goto V78;

V78:
    V133 = stack[0];
    if (!consp(V133)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    V133 = stack[0];
    if (!car_legal(V133)) goto V139;
    V133 = qcar(V133);
    V134 = nil;
    if (!(V134 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    V134 = stack[-2];
    if (!(V134 == nil)) { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
    V134 = qvalue(elt(env, 3)); /* BOOT::|$globalExposureGroupAlist| */
    fn = elt(env, 6); /* BOOT::GETALIST */
    V133 = (*qfn2(fn))(qenv(fn), V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V138;
    env = stack[-3];
    V134 = V133;
    if (V133 == nil) goto V94;
    V133 = stack[-1];
    fn = elt(env, 6); /* BOOT::GETALIST */
    V133 = (*qfn2(fn))(qenv(fn), V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V138;
    env = stack[-3];
    if (V133 == nil) goto V109;
    V133 = lisp_true;
    stack[-2] = V133;
    goto V94;

V94:
    V133 = stack[0];
    if (!car_legal(V133)) goto V140;
    V133 = qcdr(V133);
    stack[0] = V133;
    goto V78;

V109:
    V133 = lisp_true;
    if (V133 == nil) goto V94;
    else goto V94;

V62:
    V133 = nil;
    { popv(4); return onevalue(V133); }
/* error exit handlers */
V140:
    popv(4);
    return error(1, err_bad_cdr, V133);
V139:
    popv(4);
    return error(1, err_bad_car, V133);
V138:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|SMP;ground?;$B;16| (|p| |$|)
   (COND ((BOOT::QEQCAR |p| 0) 'T) ('T 'NIL)))

*/



/* Code for BOOT::|SMP;ground?;$B;16| */

static Lisp_Object CC_BOOT__SMPUgroundWUDBU16(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V25, V26;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;ground?;$B;16|\n");
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
    V25 = V3;
    V26 = V2;
/* end of prologue */
    V25 = V26;
    V26 = qcar(V25);
    V25 = (Lisp_Object)1; /* 0 */
    V25 = Leql(nil, V26, V25);
    if (V25 == nil) goto V10;
    V25 = lisp_true;
    return onevalue(V25);

V10:
    V25 = lisp_true;
    if (V25 == nil) goto V22;
    V25 = nil;
    return onevalue(V25);

V22:
    V25 = nil;
    return onevalue(V25);
}

/*
(DEFUN BOOT::|containsVars| (|t|)
   (COND
      ((ATOM |t|) (BOOT::|isPatternVar| |t|))
      ('T (BOOT::|containsVars1| |t|))))

*/



/* Code for BOOT::|containsVars| */

static Lisp_Object CC_BOOT__containsVars(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V18, V19;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|containsVars|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V19 = V2;
/* end of prologue */
    V18 = V19;
    if (!consp(V18)) goto V8;
    V18 = lisp_true;
    if (V18 == nil) goto V14;
    V18 = V19;
    {
        fn = elt(env, 1); /* BOOT::|containsVars1| */
        return (*qfn1(fn))(qenv(fn), V18);
    }

V14:
    V18 = nil;
    return onevalue(V18);

V8:
    V18 = V19;
    {
        fn = elt(env, 2); /* BOOT::|isPatternVar| */
        return (*qfn1(fn))(qenv(fn), V18);
    }
}

/*
(DEFUN BOOT:QLASSQ (P BOOT::|A-LIST|) (CDR (VMLISP:ASSQ P BOOT::|A-LIST|)))

*/



/* Code for BOOT:QLASSQ */

static Lisp_Object CC_BOOT__QLASSQ(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V16, V17;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT:QLASSQ\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V16 = V3;
    V17 = V2;
/* end of prologue */
    V16 = Latsoc(nil, V17, V16);
    if (!car_legal(V16)) goto V18;
    V16 = qcdr(V16);
    return onevalue(V16);
/* error exit handlers */
V18:
    return error(1, err_bad_cdr, V16);
}

/*
(DEFUN BOOT::|IFARRAY;removeDuplicates!;2$;30| (|a| |$|)
   (PROG (BOOT::|ct| BOOT::|nlim0| |k| #:G82657 |j| BOOT::|nlim| |i|)
      (RETURN
         (SEQ
            (BOOT::LETT
               BOOT::|ct|
               (BOOT:SPADCALL |a| (VMLISP:QREFELT |$| 15))
               BOOT::|IFARRAY;removeDuplicates!;2$;30|)
            (EXIT
               (COND
                  ((|<| BOOT::|ct| 2) |a|)
                  ('T
                     (SEQ
                        (BOOT::LETT
                           |i|
                           (VMLISP:QREFELT |$| 7)
                           BOOT::|IFARRAY;removeDuplicates!;2$;30|)
                        (BOOT::LETT
                           BOOT::|nlim|
                           (|+| (VMLISP:QREFELT |$| 7) BOOT::|ct|)
                           BOOT::|IFARRAY;removeDuplicates!;2$;30|)
                        (BOOT::LETT
                           BOOT::|nlim0|
                           BOOT::|nlim|
                           BOOT::|IFARRAY;removeDuplicates!;2$;30|)
                        (SEQ
                           BOOT::G190
                           (COND
                              ((NULL (|<| |i| BOOT::|nlim|))
                                 (GO BOOT::G191)))
                           (SEQ
                              (BOOT::LETT
                                 |j|
                                 (|+| |i| 1)
                                 BOOT::|IFARRAY;removeDuplicates!;2$;30|)
                              (SEQ
                                 (BOOT::LETT
                                    |k|
                                    |j|
                                 BOOT::|IFARRAY;removeDuplicates!;2$;30|)
                                 (BOOT::LETT
                                    #:G82657
                                    (|-| BOOT::|nlim| 1)
                                 BOOT::|IFARRAY;removeDuplicates!;2$;30|)
                                 BOOT::G190
                                 (COND
                                    ((|>| |k| #:G82657) (GO BOOT::G191)))
                                 (SEQ
                                    (EXIT
                                       (COND
                                          ((COND
                                              ((BOOT:SPADCALL
                                                  (BOOT:SPADCALL
                                                     |a|
                                                     |k|
                                                     (VMLISP:QREFELT
                                                        |$|
                                                        32))
                                                  (BOOT:SPADCALL
                                                     |a|
                                                     |i|
                                                     (VMLISP:QREFELT
                                                        |$|
                                                        32))
                                                  (VMLISP:QREFELT |$| 52))
                                                 'NIL)
                                              ('T 'T))
                                             (SEQ
                                                (BOOT:SPADCALL
                                                   |a|
                                                   |j|
                                                   (BOOT:SPADCALL
                                                      |a|
                                                      |k|
        (VMLISP:QREFELT |$| 32))
                                                   (VMLISP:QREFELT |$| 27))
                                                (EXIT
                                                   (BOOT::LETT
                                                      |j|
        (|+| |j| 1)
                           BOOT::|IFARRAY;removeDuplicates!;2$;30|)))) )))
                                 (BOOT::LETT
                                    |k|
                                    (|+| |k| 1)
                                 BOOT::|IFARRAY;removeDuplicates!;2$;30|)
                                 (GO BOOT::G190)
                                 BOOT::G191
                                 (EXIT NIL))
                              (BOOT::LETT
                                 BOOT::|nlim|
                                 |j|
                                 BOOT::|IFARRAY;removeDuplicates!;2$;30|)
                              (EXIT
                                 (BOOT::LETT
                                    |i|
                                    (|+| |i| 1)
                                 BOOT::|IFARRAY;removeDuplicates!;2$;30|)))
                           NIL
                           (GO BOOT::G190)
                           BOOT::G191
                           (EXIT NIL))
                        (EXIT
                           (COND
                              ((EQL BOOT::|nlim| BOOT::|nlim0|) |a|)
                              ('T
                                 (BOOT:SPADCALL
                                    |a|
                                    (BOOT:SPADCALL
                                       |i|
                                       (VMLISP:QREFELT |$| 53))
                                    (VMLISP:QREFELT |$| 49)))) ))) ))) )))

*/



/* Code for BOOT::|IFARRAY;removeDuplicates!;2$;30| */

static Lisp_Object CC_BOOT__IFARRAYUremoveDuplicatesBU2DU30(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V358, V359, V360, V361;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;removeDuplicates!;2$;30|\n");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-8] = V3;
    stack[-9] = V2;
/* end of prologue */
    V359 = stack[-8];
    V358 = (Lisp_Object)241; /* 15 */
    V358 = Lgetv(nil, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    V359 = V358;
    if (!car_legal(V359)) goto V374;
    V360 = qcar(V359);
    V359 = stack[-9];
    if (!car_legal(V358)) goto V375;
    V358 = qcdr(V358);
    V358 = Lapply2(nil, 3, V360, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[0] = V358;
    V359 = stack[0];
    V358 = (Lisp_Object)33; /* 2 */
    V358 = (Lisp_Object)lessp2(V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    V358 = V358 ? lisp_true : nil;
    env = stack[-11];
    if (!(V358 == nil)) { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }
    V358 = lisp_true;
    if (V358 == nil) goto V56;
    V359 = stack[-8];
    V358 = (Lisp_Object)113; /* 7 */
    V358 = Lgetv(nil, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[-4] = V358;
    V359 = stack[-8];
    V358 = (Lisp_Object)113; /* 7 */
    V359 = Lgetv(nil, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    V358 = stack[0];
    V358 = plus2(V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[0] = V358;
    V358 = stack[0];
    stack[-10] = V358;
    goto V93;

V93:
    V359 = stack[-4];
    V358 = stack[0];
    V358 = (Lisp_Object)lessp2(V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    V358 = V358 ? lisp_true : nil;
    env = stack[-11];
    if (V358 == nil) goto V295;
    V358 = stack[-4];
    V358 = add1(V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[-5] = V358;
    V358 = stack[-5];
    stack[-7] = V358;
    V358 = stack[0];
    V358 = sub1(V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[-6] = V358;
    goto V116;

V116:
    V359 = stack[-7];
    V358 = stack[-6];
    V358 = (Lisp_Object)greaterp2(V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    V358 = V358 ? lisp_true : nil;
    env = stack[-11];
    if (V358 == nil) goto V137;
    V358 = stack[-5];
    stack[0] = V358;
    V358 = stack[-4];
    V358 = add1(V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[-4] = V358;
    goto V93;

V137:
    V359 = stack[-8];
    V358 = (Lisp_Object)833; /* 52 */
    V358 = Lgetv(nil, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[-2] = V358;
    V358 = stack[-2];
    if (!car_legal(V358)) goto V376;
    stack[-1] = qcar(V358);
    V359 = stack[-8];
    V358 = (Lisp_Object)513; /* 32 */
    V358 = Lgetv(nil, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    V359 = V358;
    if (!car_legal(V359)) goto V374;
    V361 = qcar(V359);
    V360 = stack[-9];
    V359 = stack[-7];
    if (!car_legal(V358)) goto V375;
    V358 = qcdr(V358);
    V358 = Lapply3(nil, 4, V361, V360, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[0] = V358;
    V359 = stack[-8];
    V358 = (Lisp_Object)513; /* 32 */
    V358 = Lgetv(nil, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    V359 = V358;
    if (!car_legal(V359)) goto V374;
    V361 = qcar(V359);
    V360 = stack[-9];
    V359 = stack[-4];
    if (!car_legal(V358)) goto V375;
    V358 = qcdr(V358);
    V358 = Lapply3(nil, 4, V361, V360, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    V359 = V358;
    V358 = stack[-2];
    if (!car_legal(V358)) goto V375;
    V358 = qcdr(V358);
    V358 = Lapply3(nil, 4, stack[-1], stack[0], V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    if (V358 == nil) goto V132;
    V358 = nil;
    goto V130;

V130:
    if (V358 == nil) goto V124;
    V359 = stack[-8];
    V358 = (Lisp_Object)433; /* 27 */
    V358 = Lgetv(nil, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[-3] = V358;
    V358 = stack[-3];
    if (!car_legal(V358)) goto V376;
    stack[-2] = qcar(V358);
    stack[-1] = stack[-9];
    stack[0] = stack[-5];
    V359 = stack[-8];
    V358 = (Lisp_Object)513; /* 32 */
    V358 = Lgetv(nil, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    V359 = V358;
    if (!car_legal(V359)) goto V374;
    V361 = qcar(V359);
    V360 = stack[-9];
    V359 = stack[-7];
    if (!car_legal(V358)) goto V375;
    V358 = qcdr(V358);
    V358 = Lapply3(nil, 4, V361, V360, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    V359 = V358;
    V358 = stack[-3];
    if (!car_legal(V358)) goto V375;
    V358 = qcdr(V358);
    fn = elt(env, 1); /* FUNCALL* */
    V358 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    V358 = stack[-5];
    V358 = add1(V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[-5] = V358;
    goto V124;

V124:
    V358 = stack[-7];
    V358 = add1(V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[-7] = V358;
    goto V116;

V132:
    V358 = lisp_true;
    if (V358 == nil) goto V214;
    V358 = lisp_true;
    goto V130;

V214:
    V358 = nil;
    goto V130;

V295:
    V359 = stack[0];
    V358 = stack[-10];
    V358 = Leql(nil, V359, V358);
    env = stack[-11];
    if (!(V358 == nil)) { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }
    V358 = lisp_true;
    if (V358 == nil) goto V304;
    V359 = stack[-8];
    V358 = (Lisp_Object)785; /* 49 */
    V358 = Lgetv(nil, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    stack[-1] = V358;
    V358 = stack[-1];
    if (!car_legal(V358)) goto V376;
    stack[0] = qcar(V358);
    stack[-2] = stack[-9];
    V359 = stack[-8];
    V358 = (Lisp_Object)849; /* 53 */
    V358 = Lgetv(nil, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    env = stack[-11];
    V359 = V358;
    if (!car_legal(V359)) goto V374;
    V360 = qcar(V359);
    V359 = stack[-4];
    if (!car_legal(V358)) goto V375;
    V358 = qcdr(V358);
    V358 = Lapply2(nil, 3, V360, V359, V358);
    nil = C_nil;
    if (exception_pending()) goto V373;
    V359 = V358;
    V358 = stack[-1];
    if (!car_legal(V358)) goto V375;
    V358 = qcdr(V358);
    {
        Lisp_Object V377 = stack[0];
        Lisp_Object V378 = stack[-2];
        popv(12);
        return Lapply3(nil, 4, V377, V378, V359, V358);
    }

V304:
    V358 = nil;
    { popv(12); return onevalue(V358); }

V56:
    V358 = nil;
    { popv(12); return onevalue(V358); }
/* error exit handlers */
V376:
    popv(12);
    return error(1, err_bad_car, V358);
V375:
    popv(12);
    return error(1, err_bad_cdr, V358);
V374:
    popv(12);
    return error(1, err_bad_car, V359);
V373:
    popv(12);
    return nil;
}

/*
(DEFUN BOOT::|ISTRING;<;2$B;6| (|s| |t| |$|) (VMLISP:CGREATERP |t| |s|))

*/



/* Code for BOOT::|ISTRING;<;2$B;6| */

static Lisp_Object MS_CDECL CC_BOOT__ISTRINGURU2DBU6(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V16, V17, V18;
    Lisp_Object fn;
    argcheck(nargs, 3, "ISTRING;<;2$B;6");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ISTRING;<;2$B;6|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V16 = V4;
    V17 = V3;
    V18 = V2;
/* end of prologue */
    V16 = V17;
    V17 = V18;
    {
        fn = elt(env, 1); /* VMLISP:CGREATERP */
        return (*qfn2(fn))(qenv(fn), V16, V17);
    }
}

/*
(DEFUN BOOT::|SMP;unitNormal;$R;35| (|p| |$|)
   (PROG (BOOT::|#G62| BOOT::|#G63| |u| |c| |a|)
      (RETURN
         (SEQ
            (COND
               ((BOOT::QEQCAR |p| 0)
                  (SEQ
                     (PROGN
                        (BOOT::LETT
                           BOOT::|#G62|
                           (BOOT:SPADCALL
                              (QCDR |p|)
                              (VMLISP:QREFELT |$| 110))
                           BOOT::|SMP;unitNormal;$R;35|)
                        (BOOT::LETT
                           |u|
                           (VMLISP:QVELT BOOT::|#G62| 0)
                           BOOT::|SMP;unitNormal;$R;35|)
                        (BOOT::LETT
                           |c|
                           (VMLISP:QVELT BOOT::|#G62| 1)
                           BOOT::|SMP;unitNormal;$R;35|)
                        (BOOT::LETT
                           |a|
                           (VMLISP:QVELT BOOT::|#G62| 2)
                           BOOT::|SMP;unitNormal;$R;35|)
                        BOOT::|#G62|)
                     (EXIT
                        (VECTOR (CONS 0 |u|) (CONS 0 |c|) (CONS 0 |a|)))) )
               ('T
                  (SEQ
                     (PROGN
                        (BOOT::LETT
                           BOOT::|#G63|
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL |p| (VMLISP:QREFELT |$| 37))
                              (VMLISP:QREFELT |$| 110))
                           BOOT::|SMP;unitNormal;$R;35|)
                        (BOOT::LETT
                           |u|
                           (VMLISP:QVELT BOOT::|#G63| 0)
                           BOOT::|SMP;unitNormal;$R;35|)
                        (BOOT::LETT
                           |c|
                           (VMLISP:QVELT BOOT::|#G63| 1)
                           BOOT::|SMP;unitNormal;$R;35|)
                        (BOOT::LETT
                           |a|
                           (VMLISP:QVELT BOOT::|#G63| 2)
                           BOOT::|SMP;unitNormal;$R;35|)
                        BOOT::|#G63|)
                     (EXIT
                        (VECTOR
                           (CONS 0 |u|)
                           (BOOT:SPADCALL |a| |p| (VMLISP:QREFELT |$| 91))
                           (CONS 0 |a|)))) ))) )))

*/



/* Code for BOOT::|SMP;unitNormal;$R;35| */

static Lisp_Object CC_BOOT__SMPUunitNormalUDRU35(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V244, V245, V246, V247;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;unitNormal;$R;35|\n");
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
    V244 = stack[-2];
    V245 = qcar(V244);
    V244 = (Lisp_Object)1; /* 0 */
    V244 = Leql(nil, V245, V244);
    env = stack[-4];
    if (V244 == nil) goto V19;
    V245 = stack[-1];
    V244 = (Lisp_Object)1761; /* 110 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    V245 = V244;
    if (!car_legal(V245)) goto V253;
    V246 = qcar(V245);
    V245 = stack[-2];
    V245 = qcdr(V245);
    if (!car_legal(V244)) goto V254;
    V244 = qcdr(V244);
    V244 = Lapply2(nil, 3, V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    stack[-2] = V244;
    V245 = stack[-2];
    V244 = (Lisp_Object)1; /* 0 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    stack[0] = V244;
    V245 = stack[-2];
    V244 = (Lisp_Object)17; /* 1 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    stack[-1] = V244;
    V245 = stack[-2];
    V244 = (Lisp_Object)33; /* 2 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    stack[-3] = V244;
    V245 = (Lisp_Object)1; /* 0 */
    V244 = stack[0];
    stack[0] = cons(V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    V245 = (Lisp_Object)1; /* 0 */
    V244 = stack[-1];
    stack[-1] = cons(V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    V245 = (Lisp_Object)1; /* 0 */
    V244 = stack[-3];
    V244 = cons(V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    {
        Lisp_Object V255 = stack[0];
        Lisp_Object V256 = stack[-1];
        popv(5);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V255, V256, V244);
    }

V19:
    V244 = lisp_true;
    if (V244 == nil) goto V115;
    V245 = stack[-1];
    V244 = (Lisp_Object)1761; /* 110 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    stack[-3] = V244;
    V244 = stack[-3];
    if (!car_legal(V244)) goto V257;
    stack[0] = qcar(V244);
    V245 = stack[-1];
    V244 = (Lisp_Object)593; /* 37 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    V245 = V244;
    if (!car_legal(V245)) goto V253;
    V246 = qcar(V245);
    V245 = stack[-2];
    if (!car_legal(V244)) goto V254;
    V244 = qcdr(V244);
    V244 = Lapply2(nil, 3, V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    V245 = V244;
    V244 = stack[-3];
    if (!car_legal(V244)) goto V254;
    V244 = qcdr(V244);
    V244 = Lapply2(nil, 3, stack[0], V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    stack[-3] = V244;
    V245 = stack[-3];
    V244 = (Lisp_Object)1; /* 0 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    stack[0] = V244;
    V245 = stack[-3];
    V244 = (Lisp_Object)17; /* 1 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    V245 = stack[-3];
    V244 = (Lisp_Object)33; /* 2 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    stack[-3] = V244;
    V245 = (Lisp_Object)1; /* 0 */
    V244 = stack[0];
    stack[0] = cons(V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    V245 = stack[-1];
    V244 = (Lisp_Object)1457; /* 91 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    V245 = V244;
    if (!car_legal(V245)) goto V253;
    V247 = qcar(V245);
    V246 = stack[-3];
    V245 = stack[-2];
    if (!car_legal(V244)) goto V254;
    V244 = qcdr(V244);
    V244 = Lapply3(nil, 4, V247, V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    stack[-1] = V244;
    V245 = (Lisp_Object)1; /* 0 */
    V244 = stack[-3];
    V244 = cons(V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V252;
    env = stack[-4];
    {
        Lisp_Object V258 = stack[0];
        Lisp_Object V259 = stack[-1];
        popv(5);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V258, V259, V244);
    }

V115:
    V244 = nil;
    { popv(5); return onevalue(V244); }
/* error exit handlers */
V257:
    popv(5);
    return error(1, err_bad_car, V244);
V254:
    popv(5);
    return error(1, err_bad_cdr, V244);
V253:
    popv(5);
    return error(1, err_bad_car, V245);
V252:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|INT;unitNormal;$R;52| (|x| |$|)
   (COND ((|<| |x| 0) (VECTOR -1 (|-| |x|) -1)) ('T (VECTOR 1 |x| 1))))

*/



/* Code for BOOT::|INT;unitNormal;$R;52| */

static Lisp_Object CC_BOOT__INTUunitNormalUDRU52(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V45, V46, V47;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|INT;unitNormal;$R;52|\n");
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
    V45 = V3;
    stack[0] = V2;
/* end of prologue */
    V46 = stack[0];
    V45 = (Lisp_Object)1; /* 0 */
    V45 = (Lisp_Object)lessp2(V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V50;
    V45 = V45 ? lisp_true : nil;
    env = stack[-2];
    if (V45 == nil) goto V10;
    stack[-1] = (Lisp_Object)-15; /* -1 */
    V45 = stack[0];
    V46 = negate(V45);
    nil = C_nil;
    if (exception_pending()) goto V50;
    env = stack[-2];
    V45 = (Lisp_Object)-15; /* -1 */
    {
        Lisp_Object V51 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V51, V46, V45);
    }

V10:
    V45 = lisp_true;
    if (V45 == nil) goto V32;
    V47 = (Lisp_Object)17; /* 1 */
    V46 = stack[0];
    V45 = (Lisp_Object)17; /* 1 */
    {
        popv(3);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V47, V46, V45);
    }

V32:
    V45 = nil;
    { popv(3); return onevalue(V45); }
/* error exit handlers */
V50:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|devaluate| (|d|)
   (PROG (BOOT::|ISTMP#1| BOOT::|d'|)
      (RETURN
         (COND
            ((BOOT::|isDomain| |d|)
               (BOOT::|DNameToSExpr|
                  (BOOT:SPADCALL (CDR |d|) (ELT (CAR |d|) 1))))
            ((NULL (VMLISP:REFVECP |d|)) |d|)
            ((AND
                (VMLISP:QSGREATERP (VMLISP:QVSIZE |d|) 5)
                (PROGN
                   (BOOT:SPADLET BOOT::|ISTMP#1| (VMLISP:QREFELT |d| 3))
                   (AND
                      (PAIRP BOOT::|ISTMP#1|)
                      (EQ (QCDR BOOT::|ISTMP#1|) NIL)
                      (EQ (QCAR BOOT::|ISTMP#1|) 'BOOT:|Category|))))
               (VMLISP:QREFELT |d| 0))
            ((VMLISP:QSGREATERP (VMLISP:QVSIZE |d|) 0)
               (BOOT:SPADLET BOOT::|d'| (VMLISP:QREFELT |d| 0))
               (COND ((BOOT::|isFunctor| BOOT::|d'|) BOOT::|d'|) ('T |d|)))
            ('T |d|)))) )

*/



/* Code for BOOT::|devaluate| */

static Lisp_Object CC_BOOT__devaluate(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V134, V135, V136;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|devaluate|\n");
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
    V134 = stack[0];
    fn = elt(env, 2); /* BOOT::|isDomain| */
    V134 = (*qfn1(fn))(qenv(fn), V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    env = stack[-2];
    if (V134 == nil) goto V13;
    V134 = stack[0];
    if (!car_legal(V134)) goto V140;
    V135 = qcar(V134);
    V134 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 3); /* ELT */
    V134 = (*qfn2(fn))(qenv(fn), V135, V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    env = stack[-2];
    V135 = V134;
    if (!car_legal(V135)) goto V141;
    V136 = qcar(V135);
    V135 = stack[0];
    if (!car_legal(V135)) goto V142;
    V135 = qcdr(V135);
    if (!car_legal(V134)) goto V143;
    V134 = qcdr(V134);
    V134 = Lapply2(nil, 3, V136, V135, V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* BOOT::|DNameToSExpr| */
        return (*qfn1(fn))(qenv(fn), V134);
    }

V13:
    V134 = stack[0];
    fn = elt(env, 5); /* SIMPLE-VECTOR-P */
    V134 = (*qfn1(fn))(qenv(fn), V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    env = stack[-2];
    if (V134 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    V134 = stack[0];
    V135 = Llength(nil, V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    env = stack[-2];
    V134 = (Lisp_Object)81; /* 5 */
    V134 = (Lisp_Object)greaterp2(V135, V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    V134 = V134 ? lisp_true : nil;
    env = stack[-2];
    if (V134 == nil) goto V103;
    V135 = stack[0];
    V134 = (Lisp_Object)49; /* 3 */
    V134 = Lgetv(nil, V135, V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    env = stack[-2];
    stack[-1] = V134;
    V134 = stack[-1];
    fn = elt(env, 6); /* CONSP */
    V134 = (*qfn1(fn))(qenv(fn), V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    env = stack[-2];
    if (V134 == nil) goto V71;
    V134 = stack[-1];
    V134 = qcdr(V134);
    if (V134 == nil) goto V83;
    V134 = nil;
    goto V70;

V70:
    if (V134 == nil) goto V103;
    V135 = stack[0];
    V134 = (Lisp_Object)1; /* 0 */
        popv(3);
        return Lgetv(nil, V135, V134);

V103:
    V134 = stack[0];
    V135 = Llength(nil, V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    env = stack[-2];
    V134 = (Lisp_Object)1; /* 0 */
    V134 = (Lisp_Object)greaterp2(V135, V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    V134 = V134 ? lisp_true : nil;
    env = stack[-2];
    if (V134 == nil) goto V101;
    V135 = stack[0];
    V134 = (Lisp_Object)1; /* 0 */
    V134 = Lgetv(nil, V135, V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    env = stack[-2];
    stack[-1] = V134;
    V134 = stack[-1];
    fn = elt(env, 7); /* BOOT::|isFunctor| */
    V134 = (*qfn1(fn))(qenv(fn), V134);
    nil = C_nil;
    if (exception_pending()) goto V139;
    if (!(V134 == nil)) { Lisp_Object res = stack[-1]; popv(3); return onevalue(res); }
    V134 = lisp_true;
    if (!(V134 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    V134 = nil;
    { popv(3); return onevalue(V134); }

V101:
    V134 = lisp_true;
    if (!(V134 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    V134 = nil;
    { popv(3); return onevalue(V134); }

V83:
    V134 = stack[-1];
    V135 = qcar(V134);
    V134 = elt(env, 1); /* BOOT:|Category| */
    V134 = (V135 == V134 ? lisp_true : nil);
    goto V70;

V71:
    V134 = nil;
    goto V70;
/* error exit handlers */
V143:
    popv(3);
    return error(1, err_bad_cdr, V134);
V142:
    popv(3);
    return error(1, err_bad_cdr, V135);
V141:
    popv(3);
    return error(1, err_bad_car, V135);
V140:
    popv(3);
    return error(1, err_bad_car, V134);
V139:
    popv(3);
    return nil;
}

/*
(DEFUN VMLISP:|member| (VMLISP::ITEM SEQUENCE)
   (COND
      ((SYMBOLP VMLISP::ITEM) (MEMQ VMLISP::ITEM SEQUENCE))
      ((STRINGP VMLISP::ITEM)
         (MEMBER
            VMLISP::ITEM
            SEQUENCE
            :TEST
            (FUNCTION VMLISP::|STRING-EQUAL-TEST|)))
      ((AND (ATOM VMLISP::ITEM) (NOT (ARRAYP VMLISP::ITEM)))
         (MEMBER VMLISP::ITEM SEQUENCE))
      (T (MEMBER VMLISP::ITEM SEQUENCE :TEST (FUNCTION EQUALP)))) )

*/



/* Code for VMLISP:|member| */

static Lisp_Object CC_VMLISP__member(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V70, V71, V72, V73;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering VMLISP:|member|\n");
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
    V70 = stack[-1];
    fn = elt(env, 4); /* SYMBOLP */
    V70 = (*qfn1(fn))(qenv(fn), V70);
    nil = C_nil;
    if (exception_pending()) goto V76;
    env = stack[-2];
    if (V70 == nil) goto V10;
    V71 = stack[-1];
    V70 = stack[0];
    V70 = Lmemq(nil, V71, V70);
    { popv(3); return onevalue(V70); }

V10:
    V70 = stack[-1];
    V70 = Lstringp(nil, V70);
    env = stack[-2];
    if (V70 == nil) goto V22;
    V73 = stack[-1];
    V72 = stack[0];
    V71 = qvalue(elt(env, 1)); /* :TEST */
    V70 = elt(env, 2); /* VMLISP::STRING-EQUAL-TEST */
    {
        popv(3);
        fn = elt(env, 5); /* MEMBER */
        return (*qfnn(fn))(qenv(fn), 4, V73, V72, V71, V70);
    }

V22:
    V70 = stack[-1];
    if (!(!consp(V70))) goto V57;
    V70 = stack[-1];
    fn = elt(env, 6); /* ARRAYP */
    V70 = (*qfn1(fn))(qenv(fn), V70);
    nil = C_nil;
    if (exception_pending()) goto V76;
    env = stack[-2];
    if (!(V70 == nil)) goto V57;
    V71 = stack[-1];
    V70 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); /* MEMBER */
        return (*qfn2(fn))(qenv(fn), V71, V70);
    }

V57:
    V73 = stack[-1];
    V72 = stack[0];
    V71 = qvalue(elt(env, 1)); /* :TEST */
    V70 = elt(env, 3); /* EQUALP */
    {
        popv(3);
        fn = elt(env, 5); /* MEMBER */
        return (*qfnn(fn))(qenv(fn), 4, V73, V72, V71, V70);
    }
/* error exit handlers */
V76:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|domainVal| (BOOT::|dollar| BOOT::|domain| BOOT::|index|)
   (COND
      ((EQL BOOT::|index| 0) BOOT::|dollar|)
      ((EQL BOOT::|index| 2) BOOT::|domain|)
      ('T (ELT BOOT::|domain| BOOT::|index|))))

*/



/* Code for BOOT::|domainVal| */

static Lisp_Object MS_CDECL CC_BOOT__domainVal(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V43, V44, V45, V46, V47;
    Lisp_Object fn;
    argcheck(nargs, 3, "domainVal");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|domainVal|\n");
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
/* copy arguments values to proper place */
    V44 = V4;
    V45 = V3;
    V46 = V2;
/* end of prologue */
    V47 = V44;
    V43 = (Lisp_Object)1; /* 0 */
    V43 = Leql(nil, V47, V43);
    env = stack[0];
    if (!(V43 == nil)) { popv(1); return onevalue(V46); }
    V46 = V44;
    V43 = (Lisp_Object)33; /* 2 */
    V43 = Leql(nil, V46, V43);
    env = stack[0];
    if (!(V43 == nil)) { popv(1); return onevalue(V45); }
    V43 = lisp_true;
    if (V43 == nil) goto V33;
    V43 = V45;
    {
        popv(1);
        fn = elt(env, 1); /* ELT */
        return (*qfn2(fn))(qenv(fn), V43, V44);
    }

V33:
    V43 = nil;
    { popv(1); return onevalue(V43); }
}

/*
(DEFUN BOOT::|SMP;*;3$;30| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (BOOT::|mvar| BOOT::|up|)
      (RETURN
         (SEQ
            (COND
               ((BOOT::QEQCAR BOOT::|p1| 0)
                  (BOOT:SPADCALL
                     (QCDR BOOT::|p1|)
                     BOOT::|p2|
                     (VMLISP:QREFELT |$| 91)))
               ((BOOT::QEQCAR BOOT::|p2| 0)
                  (SEQ
                     (BOOT::LETT
                        BOOT::|mvar|
                        (QCAR (QCDR BOOT::|p1|))
                        BOOT::|SMP;*;3$;30|)
                     (BOOT::LETT
                        BOOT::|up|
                        (BOOT:SPADCALL
                           (QCDR (QCDR BOOT::|p1|))
                           BOOT::|p2|
                           (VMLISP:QREFELT |$| 99))
                        BOOT::|SMP;*;3$;30|)
                     (EXIT
                        (COND
                           ((BOOT:SPADCALL
                               BOOT::|up|
                               (VMLISP:QREFELT |$| 21))
                              (BOOT:SPADCALL
                                 BOOT::|up|
                                 (VMLISP:QREFELT |$| 22)))
                           ('T
                              (CONS 1 (CONS BOOT::|mvar| BOOT::|up|)))) )))
               ('T
                  (COND
                     ((BOOT:SPADCALL
                         (QCAR (QCDR BOOT::|p1|))
                         (QCAR (QCDR BOOT::|p2|))
                         (VMLISP:QREFELT |$| 51))
                        (SEQ
                           (BOOT::LETT
                              BOOT::|mvar|
                              (QCAR (QCDR BOOT::|p1|))
                              BOOT::|SMP;*;3$;30|)
                           (BOOT::LETT
                              BOOT::|up|
                              (BOOT:SPADCALL
                                 (QCDR (QCDR BOOT::|p1|))
                                 (QCDR (QCDR BOOT::|p2|))
                                 (VMLISP:QREFELT |$| 100))
                              BOOT::|SMP;*;3$;30|)
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
                                          BOOT::|up|)))) )))
                     ((BOOT:SPADCALL
                         (QCAR (QCDR BOOT::|p2|))
                         (QCAR (QCDR BOOT::|p1|))
                         (VMLISP:QREFELT |$| 50))
                        (SEQ
                           (BOOT::LETT
                              BOOT::|mvar|
                              (QCAR (QCDR BOOT::|p1|))
                              BOOT::|SMP;*;3$;30|)
                           (BOOT::LETT
                              BOOT::|up|
                              (BOOT:SPADCALL
                                 (QCDR (QCDR BOOT::|p1|))
                                 BOOT::|p2|
                                 (VMLISP:QREFELT |$| 99))
                              BOOT::|SMP;*;3$;30|)
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
                                          BOOT::|up|)))) )))
                     ('T
                        (SEQ
                           (BOOT::LETT
                              BOOT::|mvar|
                              (QCAR (QCDR BOOT::|p2|))
                              BOOT::|SMP;*;3$;30|)
                           (BOOT::LETT
                              BOOT::|up|
                              (BOOT:SPADCALL
                                 BOOT::|p1|
                                 (QCDR (QCDR BOOT::|p2|))
                                 (VMLISP:QREFELT |$| 55))
                              BOOT::|SMP;*;3$;30|)
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



/* Code for BOOT::|SMP;*;3$;30| */

static Lisp_Object MS_CDECL CC_BOOT__SMPUHU3DU30(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V547, V548, V549, V550;
    argcheck(nargs, 3, "SMP;*;3$;30");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;*;3$;30|\n");
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
    V547 = stack[-2];
    V548 = qcar(V547);
    V547 = (Lisp_Object)1; /* 0 */
    V547 = Leql(nil, V548, V547);
    env = stack[-4];
    if (V547 == nil) goto V58;
    V548 = stack[0];
    V547 = (Lisp_Object)1457; /* 91 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V550 = qcar(V548);
    V548 = stack[-2];
    V549 = qcdr(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
        popv(5);
        return Lapply3(nil, 4, V550, V549, V548, V547);

V58:
    V547 = stack[-1];
    V548 = qcar(V547);
    V547 = (Lisp_Object)1; /* 0 */
    V547 = Leql(nil, V548, V547);
    env = stack[-4];
    if (V547 == nil) goto V56;
    V547 = stack[-2];
    V547 = qcdr(V547);
    V547 = qcar(V547);
    stack[-3] = V547;
    V548 = stack[0];
    V547 = (Lisp_Object)1585; /* 99 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V550 = qcar(V548);
    V548 = stack[-2];
    V548 = qcdr(V548);
    V549 = qcdr(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
    V547 = Lapply3(nil, 4, V550, V549, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    stack[-1] = V547;
    V548 = stack[0];
    V547 = (Lisp_Object)337; /* 21 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V549 = qcar(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
    V547 = Lapply2(nil, 3, V549, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    if (V547 == nil) goto V103;
    V548 = stack[0];
    V547 = (Lisp_Object)353; /* 22 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V549 = qcar(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
        popv(5);
        return Lapply2(nil, 3, V549, V548, V547);

V103:
    V547 = lisp_true;
    if (V547 == nil) goto V153;
    V549 = (Lisp_Object)17; /* 1 */
    V548 = stack[-3];
    V547 = stack[-1];
    popv(5);
    { Lisp_Object retVal = list2star(V549, V548, V547);
    errexit();
    return onevalue(retVal); }

V153:
    V547 = nil;
    { popv(5); return onevalue(V547); }

V56:
    V547 = lisp_true;
    if (V547 == nil) goto V168;
    V548 = stack[0];
    V547 = (Lisp_Object)817; /* 51 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V550 = qcar(V548);
    V548 = stack[-2];
    V548 = qcdr(V548);
    V549 = qcar(V548);
    V548 = stack[-1];
    V548 = qcdr(V548);
    V548 = qcar(V548);
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
    V547 = Lapply3(nil, 4, V550, V549, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    if (V547 == nil) goto V314;
    V547 = stack[-2];
    V547 = qcdr(V547);
    V547 = qcar(V547);
    stack[-3] = V547;
    V548 = stack[0];
    V547 = (Lisp_Object)1601; /* 100 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V550 = qcar(V548);
    V548 = stack[-2];
    V548 = qcdr(V548);
    V549 = qcdr(V548);
    V548 = stack[-1];
    V548 = qcdr(V548);
    V548 = qcdr(V548);
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
    V547 = Lapply3(nil, 4, V550, V549, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    stack[-1] = V547;
    V548 = stack[0];
    V547 = (Lisp_Object)337; /* 21 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V549 = qcar(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
    V547 = Lapply2(nil, 3, V549, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    if (V547 == nil) goto V244;
    V548 = stack[0];
    V547 = (Lisp_Object)353; /* 22 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V549 = qcar(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
        popv(5);
        return Lapply2(nil, 3, V549, V548, V547);

V244:
    V547 = lisp_true;
    if (V547 == nil) goto V294;
    V549 = (Lisp_Object)17; /* 1 */
    V548 = stack[-3];
    V547 = stack[-1];
    popv(5);
    { Lisp_Object retVal = list2star(V549, V548, V547);
    errexit();
    return onevalue(retVal); }

V294:
    V547 = nil;
    { popv(5); return onevalue(V547); }

V314:
    V548 = stack[0];
    V547 = (Lisp_Object)801; /* 50 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V550 = qcar(V548);
    V548 = stack[-1];
    V548 = qcdr(V548);
    V549 = qcar(V548);
    V548 = stack[-2];
    V548 = qcdr(V548);
    V548 = qcar(V548);
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
    V547 = Lapply3(nil, 4, V550, V549, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    if (V547 == nil) goto V309;
    V547 = stack[-2];
    V547 = qcdr(V547);
    V547 = qcar(V547);
    stack[-3] = V547;
    V548 = stack[0];
    V547 = (Lisp_Object)1585; /* 99 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V550 = qcar(V548);
    V548 = stack[-2];
    V548 = qcdr(V548);
    V549 = qcdr(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
    V547 = Lapply3(nil, 4, V550, V549, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    stack[-1] = V547;
    V548 = stack[0];
    V547 = (Lisp_Object)337; /* 21 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V549 = qcar(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
    V547 = Lapply2(nil, 3, V549, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    if (V547 == nil) goto V378;
    V548 = stack[0];
    V547 = (Lisp_Object)353; /* 22 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V549 = qcar(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
        popv(5);
        return Lapply2(nil, 3, V549, V548, V547);

V378:
    V547 = lisp_true;
    if (V547 == nil) goto V428;
    V549 = (Lisp_Object)17; /* 1 */
    V548 = stack[-3];
    V547 = stack[-1];
    popv(5);
    { Lisp_Object retVal = list2star(V549, V548, V547);
    errexit();
    return onevalue(retVal); }

V428:
    V547 = nil;
    { popv(5); return onevalue(V547); }

V309:
    V547 = lisp_true;
    if (V547 == nil) goto V443;
    V547 = stack[-1];
    V547 = qcdr(V547);
    V547 = qcar(V547);
    stack[-3] = V547;
    V548 = stack[0];
    V547 = (Lisp_Object)881; /* 55 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V550 = qcar(V548);
    V549 = stack[-2];
    V548 = stack[-1];
    V548 = qcdr(V548);
    V548 = qcdr(V548);
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
    V547 = Lapply3(nil, 4, V550, V549, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    stack[-1] = V547;
    V548 = stack[0];
    V547 = (Lisp_Object)337; /* 21 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V549 = qcar(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
    V547 = Lapply2(nil, 3, V549, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    env = stack[-4];
    if (V547 == nil) goto V482;
    V548 = stack[0];
    V547 = (Lisp_Object)353; /* 22 */
    V547 = Lgetv(nil, V548, V547);
    nil = C_nil;
    if (exception_pending()) goto V555;
    V548 = V547;
    if (!car_legal(V548)) goto V556;
    V549 = qcar(V548);
    V548 = stack[-1];
    if (!car_legal(V547)) goto V557;
    V547 = qcdr(V547);
        popv(5);
        return Lapply2(nil, 3, V549, V548, V547);

V482:
    V547 = lisp_true;
    if (V547 == nil) goto V532;
    V549 = (Lisp_Object)17; /* 1 */
    V548 = stack[-3];
    V547 = stack[-1];
    popv(5);
    { Lisp_Object retVal = list2star(V549, V548, V547);
    errexit();
    return onevalue(retVal); }

V532:
    V547 = nil;
    { popv(5); return onevalue(V547); }

V443:
    V547 = nil;
    { popv(5); return onevalue(V547); }

V168:
    V547 = nil;
    { popv(5); return onevalue(V547); }
/* error exit handlers */
V557:
    popv(5);
    return error(1, err_bad_cdr, V547);
V556:
    popv(5);
    return error(1, err_bad_car, V548);
V555:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|ILIST;concat!;3$;25| (|x| |y| |$|)
   (PROG (|z|)
      (RETURN
         (SEQ
            (COND
               ((NULL |x|)
                  (COND
                     ((NULL |y|) |x|)
                     ('T
                        (SEQ
                           (PUSH
                              (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 13))
                              |x|)
                           (VMLISP:QRPLACD
                              |x|
                              (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 18)))
                           (EXIT |x|)))) )
               ('T
                  (SEQ
                     (BOOT::LETT |z| |x| BOOT::|ILIST;concat!;3$;25|)
                     (SEQ
                        BOOT::G190
                        (COND
                           ((NULL (COND ((NULL (QCDR |z|)) 'NIL) ('T 'T)))
                              (GO BOOT::G191)))
                        (SEQ
                           (EXIT
                              (BOOT::LETT
                                 |z|
                                 (QCDR |z|)
                                 BOOT::|ILIST;concat!;3$;25|)))
                        NIL
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT NIL))
                     (VMLISP:QRPLACD |z| |y|)
                     (EXIT |x|)))) ))) )

*/



/* Code for BOOT::|ILIST;concat!;3$;25| */

static Lisp_Object MS_CDECL CC_BOOT__ILISTUconcatBU3DU25(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V137, V138, V139;
    argcheck(nargs, 3, "ILIST;concat!;3$;25");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;concat!;3$;25|\n");
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
    V137 = stack[-2];
    if (V137 == nil) goto V15;
    V137 = lisp_true;
    if (V137 == nil) goto V94;
    V137 = stack[-2];
    V138 = V137;
    goto V101;

V101:
    V137 = V138;
    V137 = qcdr(V137);
    if (V137 == nil) goto V109;
    V137 = lisp_true;
    if (V137 == nil) goto V115;
    V137 = lisp_true;
    goto V108;

V108:
    if (V137 == nil) goto V129;
    V137 = V138;
    V137 = qcdr(V137);
    V138 = V137;
    goto V101;

V129:
    V137 = stack[-1];
    V137 = Lrplacd(nil, V138, V137);
    nil = C_nil;
    if (exception_pending()) goto V144;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

V115:
    V137 = nil;
    goto V108;

V109:
    V137 = nil;
    goto V108;

V94:
    V137 = nil;
    { popv(5); return onevalue(V137); }

V15:
    V137 = stack[-1];
    if (V137 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    V137 = lisp_true;
    if (V137 == nil) goto V25;
    V138 = stack[0];
    V137 = (Lisp_Object)209; /* 13 */
    V137 = Lgetv(nil, V138, V137);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-4];
    V138 = V137;
    if (!car_legal(V138)) goto V145;
    V139 = qcar(V138);
    V138 = stack[-1];
    if (!car_legal(V137)) goto V146;
    V137 = qcdr(V137);
    V137 = Lapply2(nil, 3, V139, V138, V137);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-4];
    V138 = V137;
    V137 = stack[-2];
    V137 = cons(V138, V137);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-4];
    stack[-2] = V137;
    stack[-3] = stack[-2];
    V138 = stack[0];
    V137 = (Lisp_Object)289; /* 18 */
    V137 = Lgetv(nil, V138, V137);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-4];
    V138 = V137;
    if (!car_legal(V138)) goto V145;
    V139 = qcar(V138);
    V138 = stack[-1];
    if (!car_legal(V137)) goto V146;
    V137 = qcdr(V137);
    V137 = Lapply2(nil, 3, V139, V138, V137);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-4];
    V137 = Lrplacd(nil, stack[-3], V137);
    nil = C_nil;
    if (exception_pending()) goto V144;
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

V25:
    V137 = nil;
    { popv(5); return onevalue(V137); }
/* error exit handlers */
V146:
    popv(5);
    return error(1, err_bad_cdr, V137);
V145:
    popv(5);
    return error(1, err_bad_car, V138);
V144:
    popv(5);
    return nil;
}

/*
(DEFUN VMLISP::|STRING-EQUAL-TEST| (U V)
   (AND (STRINGP U) (STRINGP V) (|STRING-EQUAL| U V)))

*/



/* Code for VMLISP::STRING-EQUAL-TEST */

static Lisp_Object CC_VMLISP__STRINGKEQUALKTEST(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V29, V30, V31;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering VMLISP::STRING-EQUAL-TEST\n");
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
    V29 = V3;
    V30 = V2;
/* end of prologue */
    V31 = V30;
    V31 = Lstringp(nil, V31);
    env = stack[0];
    if (V31 == nil) goto V9;
    V31 = V29;
    V31 = Lstringp(nil, V31);
    env = stack[0];
    if (V31 == nil) goto V14;
    {
        popv(1);
        fn = elt(env, 1); /* STRING-EQUAL2 */
        return (*qfn2(fn))(qenv(fn), V30, V29);
    }

V14:
    V29 = nil;
    { popv(1); return onevalue(V29); }

V9:
    V29 = nil;
    { popv(1); return onevalue(V29); }
}

/*
(DEFUN BOOT::|INT;exquo;2$U;49| (|x| |y| |$|)
   (COND
      ((OR (ZEROP |y|) (NULL (ZEROP (BOOT::REMAINDER2 |x| |y|))))
         (CONS 1 "failed"))
      ('T (CONS 0 (BOOT::QUOTIENT2 |x| |y|)))) )

*/



/* Code for BOOT::|INT;exquo;2$U;49| */

static Lisp_Object MS_CDECL CC_BOOT__INTUexquoU2DUU49(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V51, V52;
    Lisp_Object fn;
    argcheck(nargs, 3, "INT;exquo;2$U;49");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|INT;exquo;2$U;49|\n");
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
    V51 = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V51 = stack[0];
    V51 = (Lisp_Object)zerop(V51);
    V51 = V51 ? lisp_true : nil;
    env = stack[-3];
    if (!(V51 == nil)) goto V26;
    V52 = stack[-1];
    V51 = stack[0];
    fn = elt(env, 2); /* REM */
    V51 = (*qfn2(fn))(qenv(fn), V52, V51);
    nil = C_nil;
    if (exception_pending()) goto V56;
    env = stack[-3];
    V51 = (Lisp_Object)zerop(V51);
    V51 = V51 ? lisp_true : nil;
    env = stack[-3];
    if (V51 == nil) goto V26;
    V51 = lisp_true;
    if (V51 == nil) goto V34;
    stack[-2] = (Lisp_Object)1; /* 0 */
    V52 = stack[-1];
    V51 = stack[0];
    fn = elt(env, 3); /* BOOT::QUOTIENT2 */
    V51 = (*qfn2(fn))(qenv(fn), V52, V51);
    nil = C_nil;
    if (exception_pending()) goto V56;
    {
        Lisp_Object V57 = stack[-2];
        popv(4);
        { Lisp_Object retVal = cons(V57, V51);
        errexit();
        return onevalue(retVal); }
    }

V34:
    V51 = nil;
    { popv(4); return onevalue(V51); }

V26:
    V51 = (Lisp_Object)17; /* 1 */
    V52 = elt(env, 1); /* "failed" */
    popv(4);
    { Lisp_Object retVal = cons(V51, V52);
    errexit();
    return onevalue(retVal); }
/* error exit handlers */
V56:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|constructor?| (BOOT::|name|)
   (BOOT::GETDATABASE BOOT::|name| 'BOOT::ABBREVIATION))

*/



/* Code for BOOT::|constructor?| */

static Lisp_Object CC_BOOT__constructorW(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V14, V15;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|constructor?|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V14 = V2;
/* end of prologue */
    V15 = V14;
    V14 = elt(env, 1); /* BOOT::ABBREVIATION */
    {
        fn = elt(env, 2); /* BOOT::GETDATABASE */
        return (*qfn2(fn))(qenv(fn), V15, V14);
    }
}

/*
(DEFUN BOOT::|COMPLEX;zero?;$B;8| (|x| |$|)
   (COND
      ((BOOT:SPADCALL (QCAR |x|) (VMLISP:QREFELT |$| 32))
         (BOOT:SPADCALL (QCDR |x|) (VMLISP:QREFELT |$| 32)))
      ('T 'NIL)))

*/



/* Code for BOOT::|COMPLEX;zero?;$B;8| */

static Lisp_Object CC_BOOT__COMPLEXUzeroWUDBU8(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V65, V66, V67;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPLEX;zero?;$B;8|\n");
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
    V65 = (Lisp_Object)513; /* 32 */
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
    V65 = (Lisp_Object)513; /* 32 */
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
(DEFUN BOOT::|destructT| (BOOT::|functor|)
   (BOOT::GETDATABASE (BOOT::|opOf| BOOT::|functor|) 'BOOT::COSIG))

*/



/* Code for BOOT::|destructT| */

static Lisp_Object CC_BOOT__destructT(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|destructT|\n");
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
    V15 = V2;
/* end of prologue */
    fn = elt(env, 2); /* BOOT::|opOf| */
    V16 = (*qfn1(fn))(qenv(fn), V15);
    nil = C_nil;
    if (exception_pending()) goto V17;
    env = stack[0];
    V15 = elt(env, 1); /* BOOT::COSIG */
    {
        popv(1);
        fn = elt(env, 3); /* BOOT::GETDATABASE */
        return (*qfn2(fn))(qenv(fn), V16, V15);
    }
/* error exit handlers */
V17:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|augmentSub| (|v| |t| BOOT::SL)
   (PROG (|q|)
      (RETURN
         (PROGN
            (BOOT:SPADLET |q| (CONS |v| |t|))
            (COND
               ((NULL BOOT::SL) (CONS |q| NIL))
               ('T (CONS |q| BOOT::SL)))) )))

*/



/* Code for BOOT::|augmentSub| */

static Lisp_Object MS_CDECL CC_BOOT__augmentSub(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V37, V38;
    argcheck(nargs, 3, "augmentSub");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|augmentSub|\n");
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
    push(nil);
/* copy arguments values to proper place */
    stack[0] = V4;
    V37 = V3;
    V38 = V2;
/* end of prologue */
    V37 = cons(V38, V37);
    nil = C_nil;
    if (exception_pending()) goto V40;
    V38 = V37;
    V37 = stack[0];
    if (V37 == nil) goto V21;
    V37 = lisp_true;
    if (V37 == nil) goto V27;
    V37 = stack[0];
    popv(1);
    { Lisp_Object retVal = cons(V38, V37);
    errexit();
    return onevalue(retVal); }

V27:
    V37 = nil;
    { popv(1); return onevalue(V37); }

V21:
    V37 = V38;
    popv(1);
    { Lisp_Object retVal = ncons(V37);
    errexit();
    return onevalue(retVal); }
/* error exit handlers */
V40:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|FLAGG-;sort;M2A;6| (|f| |l| |$|)
   (BOOT:SPADCALL
      |f|
      (BOOT:SPADCALL |l| (VMLISP:QREFELT |$| 23))
      (VMLISP:QREFELT |$| 26)))

*/



/* Code for BOOT::|FLAGG-;sort;M2A;6| */

static Lisp_Object MS_CDECL CC_BOOT__FLAGGKUsortUM2AU6(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V58, V59, V60;
    argcheck(nargs, 3, "FLAGG-;sort;M2A;6");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FLAGG-;sort;M2A;6|\n");
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
    V58 = (Lisp_Object)417; /* 26 */
    V58 = Lgetv(nil, V59, V58);
    nil = C_nil;
    if (exception_pending()) goto V66;
    env = stack[-5];
    stack[-4] = V58;
    V58 = stack[-4];
    if (!car_legal(V58)) goto V67;
    stack[0] = qcar(V58);
    V59 = stack[-1];
    V58 = (Lisp_Object)369; /* 23 */
    V58 = Lgetv(nil, V59, V58);
    nil = C_nil;
    if (exception_pending()) goto V66;
    env = stack[-5];
    V59 = V58;
    if (!car_legal(V59)) goto V68;
    V60 = qcar(V59);
    V59 = stack[-2];
    if (!car_legal(V58)) goto V69;
    V58 = qcdr(V58);
    V58 = Lapply2(nil, 3, V60, V59, V58);
    nil = C_nil;
    if (exception_pending()) goto V66;
    V59 = V58;
    V58 = stack[-4];
    if (!car_legal(V58)) goto V69;
    V58 = qcdr(V58);
    {
        Lisp_Object V70 = stack[0];
        Lisp_Object V71 = stack[-3];
        popv(6);
        return Lapply3(nil, 4, V70, V71, V59, V58);
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
(DEFUN BOOT::|KERNEL;operator;$Bo;5| (|k| |$|) (VMLISP:QVELT |k| 0))

*/



/* Code for BOOT::|KERNEL;operator;$Bo;5| */

static Lisp_Object CC_BOOT__KERNELUoperatorUDBoU5(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|KERNEL;operator;$Bo;5|\n");
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
(DEFUN BOOT::|IFARRAY;minIndex;$I;7| (|r| |$|) (VMLISP:QREFELT |$| 7))

*/



/* Code for BOOT::|IFARRAY;minIndex;$I;7| */

static Lisp_Object CC_BOOT__IFARRAYUminIndexUDIU7(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;minIndex;$I;7|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V15 = V3;
    V16 = V2;
/* end of prologue */
    V16 = V15;
    V15 = (Lisp_Object)113; /* 7 */
        return Lgetv(nil, V16, V15);
}

/*
(DEFUN BOOT::|term1RW| (|t| R)
   (PROG (BOOT::|vars| BOOT::|varRules| BOOT::SL)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET BOOT::|vars| (CAR R))
               (BOOT:SPADLET BOOT::|varRules| (CDR R))
               (DO ((#:G18870 BOOT::|varRules| (CDR #:G18870))
                     (|r| NIL)
                     (#:G18871
                        NIL
                        (NULL
                           (BOOT:|BOOT-EQUAL| BOOT::SL 'BOOT::|failed|))))
                  ((OR
                      (ATOM #:G18870)
                      (PROGN (SETQ |r| (CAR #:G18870)) NIL)
                      #:G18871)
                     NIL)
                  (SEQ
                     (EXIT
                        (PROGN
                           (BOOT:SPADLET
                              BOOT::SL
                              (BOOT::|termMatch|
                                 (CAR |r|)
                                 |t|
                                 NIL
                                 BOOT::|vars|))
                           (COND
                              ((NULL
                                  (BOOT:|BOOT-EQUAL|
                                     BOOT::SL
                                     'BOOT::|failed|))
                                 (BOOT:SPADLET
                                    |t|
                                    (BOOT::|subCopy|
                                       (COPY (CDR |r|))
                                       BOOT::SL)))) ))) )
               |t|)))) )

*/



/* Code for BOOT::|term1RW| */

static Lisp_Object CC_BOOT__term1RW(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V103, V104, V105, V106;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|term1RW|\n");
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
    V104 = V3;
    stack[-3] = V2;
/* end of prologue */
    V103 = V104;
    if (!car_legal(V103)) goto V112;
    V103 = qcar(V103);
    stack[-4] = V103;
    V103 = V104;
    if (!car_legal(V103)) goto V113;
    V103 = qcdr(V103);
    V104 = nil;
    stack[0] = V103;
    goto V26;

V26:
    V103 = stack[0];
    if (!consp(V103)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    V103 = stack[0];
    if (!car_legal(V103)) goto V112;
    V103 = qcar(V103);
    stack[-1] = V103;
    V103 = nil;
    if (!(V103 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    V103 = V104;
    if (!(V103 == nil)) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    V103 = stack[-1];
    if (!car_legal(V103)) goto V112;
    V106 = qcar(V103);
    V105 = stack[-3];
    V104 = nil;
    V103 = stack[-4];
    fn = elt(env, 2); /* BOOT::|termMatch| */
    V103 = (*qfnn(fn))(qenv(fn), 4, V106, V105, V104, V103);
    nil = C_nil;
    if (exception_pending()) goto V114;
    env = stack[-5];
    stack[-2] = V103;
    V104 = stack[-2];
    V103 = elt(env, 1); /* BOOT::|failed| */
    V103 = (V104 == V103 ? lisp_true : nil);
    if (!(V103 == nil)) goto V42;
    V103 = stack[-1];
    if (!car_legal(V103)) goto V113;
    V103 = qcdr(V103);
    fn = elt(env, 3); /* COPY */
    V104 = (*qfn1(fn))(qenv(fn), V103);
    nil = C_nil;
    if (exception_pending()) goto V114;
    env = stack[-5];
    V103 = stack[-2];
    fn = elt(env, 4); /* BOOT::|subCopy| */
    V103 = (*qfn2(fn))(qenv(fn), V104, V103);
    nil = C_nil;
    if (exception_pending()) goto V114;
    env = stack[-5];
    stack[-3] = V103;
    goto V42;

V42:
    V103 = stack[0];
    if (!car_legal(V103)) goto V113;
    V103 = qcdr(V103);
    V105 = V103;
    V104 = stack[-2];
    V103 = elt(env, 1); /* BOOT::|failed| */
    V103 = (V104 == V103 ? lisp_true : nil);
    V103 = (V103 == nil ? lisp_true : nil);
    V104 = V105;
    stack[0] = V104;
    V104 = V103;
    goto V26;
/* error exit handlers */
V114:
    popv(6);
    return nil;
V113:
    popv(6);
    return error(1, err_bad_cdr, V103);
V112:
    popv(6);
    return error(1, err_bad_car, V103);
}

/*
(DEFUN BOOT::|lazyMatchAssocV| (|x|
      BOOT::|auxvec|
      BOOT::|catvec|
      BOOT::|domain|)
   (PROG (|n| BOOT::|percentHash| BOOT::|xop| BOOT::|lazyt|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET |n| (VMLISP:MAXINDEX BOOT::|catvec|))
               (COND
                  ((BOOT::|hashCode?| |x|)
                     (BOOT:SPADLET
                        BOOT::|percentHash|
                        (COND
                           ((VMLISP:VECP BOOT::|domain|)
                              (BOOT::|hashType| (ELT BOOT::|domain| 0) 0))
                           ('T (BOOT::|getDomainHash| BOOT::|domain|))))
                     (PROG (#:G18907)
                        (BOOT:SPADLET #:G18907 NIL)
                        (RETURN
                           (DO ((#:G18908 NIL #:G18907)
                                 (|i| 0 (VMLISP:QSADD1 |i|)))
                              ((OR #:G18908 (VMLISP:QSGREATERP |i| |n|))
                                 #:G18907)
                              (SEQ
                                 (EXIT
                                    (COND
                                       ((BOOT:|BOOT-EQUAL|
                                           |x|
                                           (BOOT::|hashType|
                                              (BOOT::|newExpandLocalType|
                                                 (VMLISP:QVELT
                                                    BOOT::|catvec|
                                                    |i|)
                                                 BOOT::|domain|
                                                 BOOT::|domain|)
                                              BOOT::|percentHash|))
                                          (SETQ #:G18907
                                             (OR
                                                #:G18907
                                                (ELT
                                                   BOOT::|auxvec|
                                                   |i|)))) ))) ))) )
                  ('T
                     (BOOT:SPADLET BOOT::|xop| (CAR |x|))
                     (PROG (#:G18905)
                        (BOOT:SPADLET #:G18905 NIL)
                        (RETURN
                           (DO ((#:G18906 NIL #:G18905)
                                 (|i| 0 (VMLISP:QSADD1 |i|)))
                              ((OR #:G18906 (VMLISP:QSGREATERP |i| |n|))
                                 #:G18905)
                              (SEQ
                                 (EXIT
                                    (COND
                                       ((AND
                                           (BOOT:|BOOT-EQUAL|
                                              BOOT::|xop|
                                              (CAR
                                                 (BOOT:SPADLET
                                                    BOOT::|lazyt|
                                                    (BOOT::|getCatForm|
                                                       BOOT::|catvec|
                                                       |i|
                                                       BOOT::|domain|))))
                                           (BOOT::|lazyMatch|
                                              |x|
                                              BOOT::|lazyt|
                                              BOOT::|domain|
                                              BOOT::|domain|))
                                          (SETQ #:G18905
                                             (OR
                                                #:G18905
                                                (ELT
                                                   BOOT::|auxvec|
                                                |i|)))) ))) ))) ))) ))) )

*/



/* Code for BOOT::|lazyMatchAssocV| */

static Lisp_Object MS_CDECL CC_BOOT__lazyMatchAssocV(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V243, V244, V245, V246;
    Lisp_Object fn;
    argcheck(nargs, 4, "lazyMatchAssocV");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|lazyMatchAssocV|\n");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = V5;
    stack[-5] = V4;
    stack[-6] = V3;
    stack[-7] = V2;
/* end of prologue */
    V243 = stack[-5];
    V243 = Llength(nil, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    V243 = sub1(V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    stack[-8] = V243;
    V243 = stack[-7];
    fn = elt(env, 1); /* BOOT::|hashCode?| */
    V243 = (*qfn1(fn))(qenv(fn), V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    if (V243 == nil) goto V23;
    V243 = stack[-4];
    fn = elt(env, 2); /* SIMPLE-VECTOR-P */
    V243 = (*qfn1(fn))(qenv(fn), V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    if (V243 == nil) goto V29;
    V244 = stack[-4];
    V243 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 3); /* ELT */
    V244 = (*qfn2(fn))(qenv(fn), V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    V243 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 4); /* BOOT::|hashType| */
    V243 = (*qfn2(fn))(qenv(fn), V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    goto V27;

V27:
    stack[-3] = V243;
    V243 = nil;
    stack[-2] = V243;
    V244 = (Lisp_Object)1; /* 0 */
    V243 = nil;
    stack[-1] = V244;
    V244 = V243;
    goto V62;

V62:
    V243 = V244;
    if (!(V243 == nil)) { Lisp_Object res = stack[-2]; popv(10); return onevalue(res); }
    V244 = stack[-1];
    V243 = stack[-8];
    V243 = (Lisp_Object)greaterp2(V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    V243 = V243 ? lisp_true : nil;
    env = stack[-9];
    if (!(V243 == nil)) { Lisp_Object res = stack[-2]; popv(10); return onevalue(res); }
    stack[0] = stack[-7];
    V244 = stack[-5];
    V243 = stack[-1];
    V245 = Lgetv(nil, V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    V244 = stack[-4];
    V243 = stack[-4];
    fn = elt(env, 5); /* BOOT::|newExpandLocalType| */
    V244 = (*qfnn(fn))(qenv(fn), 3, V245, V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    V243 = stack[-3];
    fn = elt(env, 4); /* BOOT::|hashType| */
    V243 = (*qfn2(fn))(qenv(fn), V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    V243 = (cl_equal(stack[0], V243) ? lisp_true : nil);
    if (V243 == nil) goto V81;
    V243 = stack[-2];
    if (!(V243 == nil)) goto V119;
    V244 = stack[-6];
    V243 = stack[-1];
    fn = elt(env, 3); /* ELT */
    V243 = (*qfn2(fn))(qenv(fn), V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    goto V119;

V119:
    stack[-2] = V243;
    goto V81;

V81:
    V243 = stack[-2];
    stack[0] = V243;
    V243 = stack[-1];
    V243 = add1(V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    V244 = stack[0];
    stack[-1] = V243;
    goto V62;

V29:
    V243 = lisp_true;
    if (V243 == nil) goto V48;
    V243 = stack[-4];
    fn = elt(env, 6); /* BOOT::|getDomainHash| */
    V243 = (*qfn1(fn))(qenv(fn), V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    goto V27;

V48:
    V243 = nil;
    goto V27;

V23:
    V243 = lisp_true;
    if (V243 == nil) goto V144;
    V243 = stack[-7];
    if (!car_legal(V243)) goto V257;
    V243 = qcar(V243);
    stack[-3] = V243;
    V243 = nil;
    stack[-2] = V243;
    V244 = (Lisp_Object)1; /* 0 */
    V243 = nil;
    stack[-1] = V244;
    V244 = V243;
    goto V158;

V158:
    V243 = V244;
    if (!(V243 == nil)) { Lisp_Object res = stack[-2]; popv(10); return onevalue(res); }
    V244 = stack[-1];
    V243 = stack[-8];
    V243 = (Lisp_Object)greaterp2(V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    V243 = V243 ? lisp_true : nil;
    env = stack[-9];
    if (!(V243 == nil)) { Lisp_Object res = stack[-2]; popv(10); return onevalue(res); }
    stack[0] = stack[-3];
    V245 = stack[-5];
    V244 = stack[-1];
    V243 = stack[-4];
    fn = elt(env, 7); /* BOOT::|getCatForm| */
    V244 = (*qfnn(fn))(qenv(fn), 3, V245, V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    V243 = V244;
    if (!car_legal(V244)) goto V258;
    V244 = qcar(V244);
    V244 = (cl_equal(stack[0], V244) ? lisp_true : nil);
    if (V244 == nil) goto V177;
    V246 = stack[-7];
    V245 = V243;
    V244 = stack[-4];
    V243 = stack[-4];
    fn = elt(env, 8); /* BOOT::|lazyMatch| */
    V243 = (*qfnn(fn))(qenv(fn), 4, V246, V245, V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    if (V243 == nil) goto V177;
    V243 = stack[-2];
    if (!(V243 == nil)) goto V218;
    V244 = stack[-6];
    V243 = stack[-1];
    fn = elt(env, 3); /* ELT */
    V243 = (*qfn2(fn))(qenv(fn), V244, V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    goto V218;

V218:
    stack[-2] = V243;
    goto V177;

V177:
    V243 = stack[-2];
    stack[0] = V243;
    V243 = stack[-1];
    V243 = add1(V243);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-9];
    V244 = stack[0];
    stack[-1] = V243;
    goto V158;

V144:
    V243 = nil;
    { popv(10); return onevalue(V243); }
/* error exit handlers */
V258:
    popv(10);
    return error(1, err_bad_car, V244);
V257:
    popv(10);
    return error(1, err_bad_car, V243);
V256:
    popv(10);
    return nil;
}

/*
(DEFUN SYSTEM::PNAME (X)
   (COND
      ((SYMBOLP X) (|SYMBOL-NAME| X))
      ((CHARACTERP X) (STRING X))
      (T NIL)))

*/



/* Code for SYSTEM::PNAME */

static Lisp_Object CC_SYSTEM__PNAME(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V23;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering SYSTEM::PNAME\n");
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
    V23 = stack[0];
    fn = elt(env, 1); /* SYMBOLP */
    V23 = (*qfn1(fn))(qenv(fn), V23);
    nil = C_nil;
    if (exception_pending()) goto V25;
    env = stack[-1];
    if (V23 == nil) goto V9;
    V23 = stack[0];
        popv(2);
        return Lsymbol_name(nil, V23);

V9:
    V23 = stack[0];
    fn = elt(env, 2); /* CHARACTERP */
    V23 = (*qfn1(fn))(qenv(fn), V23);
    nil = C_nil;
    if (exception_pending()) goto V25;
    env = stack[-1];
    if (V23 == nil) goto V20;
    V23 = stack[0];
    {
        popv(2);
        fn = elt(env, 3); /* STRING */
        return (*qfn1(fn))(qenv(fn), V23);
    }

V20:
    V23 = nil;
    { popv(2); return onevalue(V23); }
/* error exit handlers */
V25:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|evalMmStackInner| (BOOT::|mmC|)
   (PROG (BOOT::|mmD| BOOT::|pvar| BOOT::|cat| BOOT::|args| BOOT::|ISTMP#1|
         BOOT::|pat| BOOT::|ISTMP#2| |x|)
      (RETURN
         (SEQ
            (COND
               ((AND
                   (PAIRP BOOT::|mmC|)
                   (EQ (QCAR BOOT::|mmC|) 'OR)
                   (PROGN
                      (BOOT:SPADLET BOOT::|args| (QCDR BOOT::|mmC|))
                      'T))
                  (BOOT::|keyedSystemError|
                     'BOOT::S2GE0016
                     (CONS
                        (VMLISP:MAKESTRING "evalMmStackInner")
                        (CONS
                           (VMLISP:MAKESTRING
                              "OR condition nested inside an AND")
                           NIL))))
               ((AND
                   (PAIRP BOOT::|mmC|)
                   (EQ (QCAR BOOT::|mmC|) 'BOOT::|partial|)
                   (PROGN
                      (BOOT:SPADLET BOOT::|mmD| (QCDR BOOT::|mmC|))
                      'T))
                  (BOOT::|evalMmStackInner| BOOT::|mmD|))
               ((AND
                   (PAIRP BOOT::|mmC|)
                   (EQ (QCAR BOOT::|mmC|) 'BOOT::|ofCategory|)
                   (PROGN
                      (BOOT:SPADLET BOOT::|ISTMP#1| (QCDR BOOT::|mmC|))
                      (AND
                         (PAIRP BOOT::|ISTMP#1|)
                         (PROGN
                            (BOOT:SPADLET
                               BOOT::|pvar|
                               (QCAR BOOT::|ISTMP#1|))
                            (BOOT:SPADLET
                               BOOT::|ISTMP#2|
                               (QCDR BOOT::|ISTMP#1|))
                            (AND
                               (PAIRP BOOT::|ISTMP#2|)
                               (EQ (QCDR BOOT::|ISTMP#2|) NIL)
                               (PROGN
                                  (BOOT:SPADLET
                                     BOOT::|cat|
                                     (QCAR BOOT::|ISTMP#2|))
                                  'T)))) )
                   (PAIRP BOOT::|cat|)
                   (EQ (QCAR BOOT::|cat|) 'BOOT::|Join|)
                   (PROGN
                      (BOOT:SPADLET BOOT::|args| (QCDR BOOT::|cat|))
                      'T))
                  (PROG (#:G18977)
                     (BOOT:SPADLET #:G18977 NIL)
                     (RETURN
                        (DO ((#:G18978 BOOT::|args| (CDR #:G18978))
                              (|c| NIL))
                           ((OR
                               (ATOM #:G18978)
                               (PROGN (SETQ |c| (CAR #:G18978)) NIL))
                              (NREVERSE0 #:G18977))
                           (SEQ
                              (EXIT
                                 (SETQ #:G18977
                                    (CONS
                                       (CONS
                                          'BOOT::|ofCategory|
                                          (CONS
                                             BOOT::|pvar|
                                             (CONS |c| NIL)))
                                       #:G18977)))) ))) )
               ((AND
                   (PAIRP BOOT::|mmC|)
                   (EQ (QCAR BOOT::|mmC|) 'BOOT::|ofType|))
                  NIL)
               ((AND
                   (PAIRP BOOT::|mmC|)
                   (EQ (QCDR BOOT::|mmC|) NIL)
                   (EQ (QCAR BOOT::|mmC|) 'BOOT::|isAsConstant|))
                  NIL)
               ((AND
                   (PAIRP BOOT::|mmC|)
                   (EQ (QCAR BOOT::|mmC|) 'BOOT::|has|)
                   (PROGN
                      (BOOT:SPADLET BOOT::|ISTMP#1| (QCDR BOOT::|mmC|))
                      (AND
                         (PAIRP BOOT::|ISTMP#1|)
                         (PROGN
                            (BOOT:SPADLET
                               BOOT::|pat|
                               (QCAR BOOT::|ISTMP#1|))
                            (BOOT:SPADLET
                               BOOT::|ISTMP#2|
                               (QCDR BOOT::|ISTMP#1|))
                            (AND
                               (PAIRP BOOT::|ISTMP#2|)
                               (EQ (QCDR BOOT::|ISTMP#2|) NIL)
                               (PROGN
                                  (BOOT:SPADLET |x| (QCAR BOOT::|ISTMP#2|))
                                  'T)))) ))
                  (COND
                     ((MEMQ |x| '(BOOT::ATTRIBUTE BOOT::SIGNATURE))
                        (CONS
                           (CONS
                              'BOOT::|ofCategory|
                              (CONS
                                 BOOT::|pat|
                                 (CONS
                                    (CONS
                                       'BOOT::CATEGORY
                                       (CONS
                                          'BOOT::|unknown|
                                          (CONS |x| NIL)))
                                    NIL)))
                           NIL))
                     ('T
                        (CONS
                           (CONS
                              'BOOT::|ofCategory|
                              (CONS BOOT::|pat| (CONS |x| NIL)))
                           NIL))))
               ('T (CONS BOOT::|mmC| NIL)))) )))

*/



/* Code for BOOT::|evalMmStackInner| */

static Lisp_Object CC_BOOT__evalMmStackInner(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V332, V333, V334;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|evalMmStackInner|\n");
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
    push(nil);
/* copy arguments values to proper place */
    stack[-4] = V2;
/* end of prologue */

V1:
    stack[-5] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[0] = nil;
    V332 = stack[-4];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V21;
    V332 = stack[-4];
    V333 = qcar(V332);
    V332 = elt(env, 1); /* OR */
    if (!(V333 == V332)) goto V21;
    V332 = lisp_true;
    if (V332 == nil) goto V21;
    stack[0] = elt(env, 2); /* BOOT::S2GE0016 */
    V334 = elt(env, 3); /* "evalMmStackInner" */
    V333 = elt(env, 4); /* "OR condition nested inside an AND" */
    V332 = nil;
    V332 = list2star(V334, V333, V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    {
        Lisp_Object V342 = stack[0];
        popv(7);
        fn = elt(env, 15); /* BOOT::|keyedSystemError| */
        return (*qfn2(fn))(qenv(fn), V342, V332);
    }

V21:
    V332 = stack[-4];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V57;
    V332 = stack[-4];
    V333 = qcar(V332);
    V332 = elt(env, 5); /* BOOT::|partial| */
    if (!(V333 == V332)) goto V57;
    V332 = stack[-4];
    V332 = qcdr(V332);
    V333 = V332;
    V332 = lisp_true;
    if (V332 == nil) goto V57;
    V332 = V333;
    stack[-4] = V332;
    goto V1;

V57:
    V332 = stack[-4];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V77;
    V332 = stack[-4];
    V333 = qcar(V332);
    V332 = elt(env, 6); /* BOOT::|ofCategory| */
    if (!(V333 == V332)) goto V77;
    V332 = stack[-4];
    V332 = qcdr(V332);
    stack[-1] = V332;
    V332 = stack[-1];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V95;
    V332 = stack[-1];
    V332 = qcar(V332);
    stack[-5] = V332;
    V332 = stack[-1];
    V332 = qcdr(V332);
    stack[-1] = V332;
    V332 = stack[-1];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V108;
    V332 = stack[-1];
    V332 = qcdr(V332);
    if (V332 == nil) goto V118;
    V332 = nil;
    goto V94;

V94:
    if (V332 == nil) goto V77;
    V332 = stack[-3];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V77;
    V332 = stack[-3];
    V333 = qcar(V332);
    V332 = elt(env, 7); /* BOOT::|Join| */
    if (!(V333 == V332)) goto V77;
    V332 = stack[-3];
    V332 = qcdr(V332);
    V333 = V332;
    V332 = lisp_true;
    if (V332 == nil) goto V77;
    V332 = nil;
    stack[-2] = V332;
    V332 = V333;
    stack[-1] = V332;
    goto V149;

V149:
    V332 = stack[-1];
    if (!consp(V332)) goto V152;
    V332 = stack[-1];
    if (!car_legal(V332)) goto V343;
    V332 = qcar(V332);
    V333 = nil;
    if (!(V333 == nil)) goto V152;
    stack[0] = elt(env, 6); /* BOOT::|ofCategory| */
    V334 = stack[-5];
    V333 = V332;
    V332 = nil;
    V333 = list2star(V334, V333, V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    V332 = stack[-2];
    V332 = acons(stack[0], V333, V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    stack[-2] = V332;
    V332 = stack[-1];
    if (!car_legal(V332)) goto V344;
    V332 = qcdr(V332);
    stack[-1] = V332;
    goto V149;

V152:
    V332 = stack[-2];
    {
        popv(7);
        fn = elt(env, 16); /* NREVERSE0 */
        return (*qfn1(fn))(qenv(fn), V332);
    }

V77:
    V332 = stack[-4];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V195;
    V332 = stack[-4];
    V333 = qcar(V332);
    V332 = elt(env, 8); /* BOOT::|ofType| */
    if (!(V333 == V332)) goto V195;
    V332 = nil;
    { popv(7); return onevalue(V332); }

V195:
    V332 = stack[-4];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V210;
    V332 = stack[-4];
    V332 = qcdr(V332);
    if (!(V332 == nil)) goto V210;
    V332 = stack[-4];
    V333 = qcar(V332);
    V332 = elt(env, 9); /* BOOT::|isAsConstant| */
    if (!(V333 == V332)) goto V210;
    V332 = nil;
    { popv(7); return onevalue(V332); }

V210:
    V332 = stack[-4];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V228;
    V332 = stack[-4];
    V333 = qcar(V332);
    V332 = elt(env, 10); /* BOOT::|has| */
    if (!(V333 == V332)) goto V228;
    V332 = stack[-4];
    V332 = qcdr(V332);
    stack[-1] = V332;
    V332 = stack[-1];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V246;
    V332 = stack[-1];
    V332 = qcar(V332);
    stack[-2] = V332;
    V332 = stack[-1];
    V332 = qcdr(V332);
    stack[-1] = V332;
    V332 = stack[-1];
    fn = elt(env, 14); /* CONSP */
    V332 = (*qfn1(fn))(qenv(fn), V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    if (V332 == nil) goto V259;
    V332 = stack[-1];
    V332 = qcdr(V332);
    if (V332 == nil) goto V269;
    V332 = nil;
    goto V245;

V245:
    if (V332 == nil) goto V228;
    V333 = stack[0];
    V332 = elt(env, 11); /* (BOOT::ATTRIBUTE BOOT::SIGNATURE) */
    V332 = Lmemq(nil, V333, V332);
    if (V332 == nil) goto V277;
    stack[-3] = elt(env, 6); /* BOOT::|ofCategory| */
    stack[-4] = stack[-2];
    stack[-2] = elt(env, 12); /* BOOT::CATEGORY */
    stack[-1] = elt(env, 13); /* BOOT::|unknown| */
    V332 = stack[0];
    V332 = ncons(V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    V332 = list2star(stack[-2], stack[-1], V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    V332 = ncons(V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    V332 = list2star(stack[-3], stack[-4], V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    popv(7);
    { Lisp_Object retVal = ncons(V332);
    errexit();
    return onevalue(retVal); }

V277:
    V332 = lisp_true;
    if (V332 == nil) goto V311;
    stack[-1] = elt(env, 6); /* BOOT::|ofCategory| */
    V332 = stack[0];
    V332 = ncons(V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    env = stack[-6];
    V332 = list2star(stack[-1], stack[-2], V332);
    nil = C_nil;
    if (exception_pending()) goto V341;
    popv(7);
    { Lisp_Object retVal = ncons(V332);
    errexit();
    return onevalue(retVal); }

V311:
    V332 = nil;
    { popv(7); return onevalue(V332); }

V228:
    V332 = lisp_true;
    if (V332 == nil) goto V327;
    V332 = stack[-4];
    popv(7);
    { Lisp_Object retVal = ncons(V332);
    errexit();
    return onevalue(retVal); }

V327:
    V332 = nil;
    { popv(7); return onevalue(V332); }

V269:
    V332 = stack[-1];
    V332 = qcar(V332);
    stack[0] = V332;
    V332 = lisp_true;
    goto V245;

V259:
    V332 = nil;
    goto V245;

V246:
    V332 = nil;
    goto V245;

V118:
    V332 = stack[-1];
    V332 = qcar(V332);
    stack[-3] = V332;
    V332 = lisp_true;
    goto V94;

V108:
    V332 = nil;
    goto V94;

V95:
    V332 = nil;
    goto V94;
/* error exit handlers */
V344:
    popv(7);
    return error(1, err_bad_cdr, V332);
V343:
    popv(7);
    return error(1, err_bad_car, V332);
V341:
    popv(7);
    return nil;
}

/*
(DEFUN VMLISP:IVECP (X)
   (AND (VECTORP X) (SUBTYPEP (|ARRAY-ELEMENT-TYPE| X) 'INTEGER)))

*/



/* Code for VMLISP:IVECP */

static Lisp_Object CC_VMLISP__IVECP(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V24, V25;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering VMLISP:IVECP\n");
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
    V24 = V2;
/* end of prologue */
    V25 = V24;
    V25 = Lvectorp(nil, V25);
    env = stack[0];
    if (V25 == nil) goto V8;
    fn = elt(env, 2); /* ARRAY-ELEMENT-TYPE */
    V25 = (*qfn1(fn))(qenv(fn), V24);
    nil = C_nil;
    if (exception_pending()) goto V26;
    env = stack[0];
    V24 = elt(env, 1); /* INTEGER */
    {
        popv(1);
        fn = elt(env, 3); /* SUBTYPEP */
        return (*qfn2(fn))(qenv(fn), V25, V24);
    }

V8:
    V24 = nil;
    { popv(1); return onevalue(V24); }
/* error exit handlers */
V26:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|CONTAINEDisDomain| (BOOT::|symbol| BOOT::|cond|)
   (PROG (BOOT::|dom|)
      (RETURN
         (SEQ
            (COND
               ((ATOM BOOT::|cond|) NIL)
               ((MEMQ (QCAR BOOT::|cond|) '(AND OR BOOT:|and| BOOT:|or|))
                  (PROG (#:G18898)
                     (BOOT:SPADLET #:G18898 NIL)
                     (RETURN
                        (DO ((#:G18899 NIL #:G18898)
                              (#:G18900 (QCDR BOOT::|cond|) (CDR #:G18900))
                              (|u| NIL))
                           ((OR
                               #:G18899
                               (ATOM #:G18900)
                               (PROGN (SETQ |u| (CAR #:G18900)) NIL))
                              #:G18898)
                           (SEQ
                              (EXIT
                                 (SETQ #:G18898
                                    (OR
                                       #:G18898
                                       (BOOT::|CONTAINEDisDomain|
                                          BOOT::|symbol|
                                          |u|)))) ))) ))
               ((EQ (QCAR BOOT::|cond|) 'BOOT::|isDomain|)
                  (AND
                     (EQ BOOT::|symbol| (CADR BOOT::|cond|))
                     (PAIRP
                        (BOOT:SPADLET BOOT::|dom| (CADDR BOOT::|cond|)))
                     (MEMQ
                        BOOT::|dom|
                        '(BOOT:|PositiveInteger|
                            BOOT:|NonNegativeInteger|))))
               ('T NIL)))) ))

*/



/* Code for BOOT::|CONTAINEDisDomain| */

static Lisp_Object CC_BOOT__CONTAINEDisDomain(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V131, V132, V133;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|CONTAINEDisDomain|\n");
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
    V133 = V3;
    stack[0] = V2;
/* end of prologue */
    V131 = V133;
    if (!consp(V131)) goto V14;
    V131 = V133;
    V132 = qcar(V131);
    V131 = elt(env, 1); /* (AND OR BOOT:|and| BOOT:|or|) */
    V131 = Lmemq(nil, V132, V131);
    if (V131 == nil) goto V86;
    V131 = nil;
    V132 = V131;
    V131 = V133;
    V133 = qcdr(V131);
    V131 = nil;
    stack[-1] = V133;
    V133 = V131;
    goto V42;

V42:
    V131 = V133;
    if (!(V131 == nil)) { popv(3); return onevalue(V132); }
    V131 = stack[-1];
    if (!consp(V131)) { popv(3); return onevalue(V132); }
    V131 = stack[-1];
    if (!car_legal(V131)) goto V136;
    V131 = qcar(V131);
    V133 = V131;
    V131 = nil;
    if (!(V131 == nil)) { popv(3); return onevalue(V132); }
    V131 = V132;
    if (!(V131 == nil)) goto V60;
    V131 = stack[0];
    V132 = V133;
    V131 = CC_BOOT__CONTAINEDisDomain(env, V131, V132);
    nil = C_nil;
    if (exception_pending()) goto V137;
    env = stack[-2];
    goto V60;

V60:
    V132 = V131;
    V131 = V132;
    V133 = V131;
    V131 = stack[-1];
    if (!car_legal(V131)) goto V138;
    V131 = qcdr(V131);
    stack[-1] = V131;
    goto V42;

V86:
    V131 = V133;
    V132 = qcar(V131);
    V131 = elt(env, 2); /* BOOT::|isDomain| */
    if (V132 == V131) goto V98;
    V131 = lisp_true;
    if (V131 == nil) goto V127;
    V131 = nil;
    { popv(3); return onevalue(V131); }

V127:
    V131 = nil;
    { popv(3); return onevalue(V131); }

V98:
    V132 = stack[0];
    V131 = V133;
    if (!car_legal(V131)) goto V138;
    V131 = qcdr(V131);
    if (!car_legal(V131)) goto V136;
    V131 = qcar(V131);
    if (V132 == V131) goto V97;
    V131 = nil;
    { popv(3); return onevalue(V131); }

V97:
    V131 = V133;
    if (!car_legal(V131)) goto V138;
    V131 = qcdr(V131);
    if (!car_legal(V131)) goto V138;
    V131 = qcdr(V131);
    if (!car_legal(V131)) goto V136;
    V131 = qcar(V131);
    stack[0] = V131;
    fn = elt(env, 4); /* CONSP */
    V131 = (*qfn1(fn))(qenv(fn), V131);
    nil = C_nil;
    if (exception_pending()) goto V137;
    env = stack[-2];
    if (V131 == nil) goto V108;
    V131 = stack[0];
    V132 = elt(env, 3); /* (BOOT:|PositiveInteger| BOOT:|NonNegativeInteger|) */
    V131 = Lmemq(nil, V131, V132);
    { popv(3); return onevalue(V131); }

V108:
    V131 = nil;
    { popv(3); return onevalue(V131); }

V14:
    V131 = nil;
    { popv(3); return onevalue(V131); }
/* error exit handlers */
V138:
    popv(3);
    return error(1, err_bad_cdr, V131);
V137:
    popv(3);
    return nil;
V136:
    popv(3);
    return error(1, err_bad_car, V131);
}



setup_type const u04_setup[] =
{
    {"BOOT@@ILIST;removeDuplicates!;2$;26@@Builtin",too_few_2,CC_BOOT__ILISTUremoveDuplicatesBU2DU26,wrong_no_2},
    {"BOOT@@UNSQUEEZE@@Builtin",CC_BOOT__UNSQUEEZE,too_many_1, wrong_no_1},
    {"BOOT@@EXPR;algkernels@@Builtin",too_few_2,CC_BOOT__EXPRUalgkernels,wrong_no_2},
    {"BOOT@@BOP;weight;$Nni;28@@Builtin",too_few_2,CC_BOOT__BOPUweightUDNniU28,wrong_no_2},
    {"BOOT@@isExposedConstructor@@Builtin",CC_BOOT__isExposedConstructor,too_many_1,wrong_no_1},
    {"BOOT@@SMP;ground?;$B;16@@Builtin",too_few_2,CC_BOOT__SMPUgroundWUDBU16,wrong_no_2},
    {"BOOT@@containsVars@@Builtin",CC_BOOT__containsVars,too_many_1,wrong_no_1},
    {"BOOT@@QLASSQ@@Builtin",   too_few_2,      CC_BOOT__QLASSQ,wrong_no_2},
    {"BOOT@@IFARRAY;removeDuplicates!;2$;30@@Builtin",too_few_2,CC_BOOT__IFARRAYUremoveDuplicatesBU2DU30,wrong_no_2},
    {"BOOT@@ISTRING;<;2$B;6@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__ISTRINGURU2DBU6},
    {"BOOT@@SMP;unitNormal;$R;35@@Builtin",too_few_2,CC_BOOT__SMPUunitNormalUDRU35,wrong_no_2},
    {"BOOT@@INT;unitNormal;$R;52@@Builtin",too_few_2,CC_BOOT__INTUunitNormalUDRU52,wrong_no_2},
    {"BOOT@@devaluate@@Builtin",CC_BOOT__devaluate,too_many_1, wrong_no_1},
    {"VMLISP@@member@@Builtin", too_few_2,      CC_VMLISP__member,wrong_no_2},
    {"BOOT@@domainVal@@Builtin",wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__domainVal},
    {"BOOT@@SMP;*;3$;30@@Builtin",wrong_no_na,  wrong_no_nb,   (n_args *)CC_BOOT__SMPUHU3DU30},
    {"BOOT@@ILIST;concat!;3$;25@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__ILISTUconcatBU3DU25},
    {"VMLISP@@STRING-EQUAL-TEST@@Builtin",too_few_2,CC_VMLISP__STRINGKEQUALKTEST,wrong_no_2},
    {"BOOT@@INT;exquo;2$U;49@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__INTUexquoU2DUU49},
    {"BOOT@@constructor?@@Builtin",CC_BOOT__constructorW,too_many_1,wrong_no_1},
    {"BOOT@@COMPLEX;zero?;$B;8@@Builtin",too_few_2,CC_BOOT__COMPLEXUzeroWUDBU8,wrong_no_2},
    {"BOOT@@destructT@@Builtin",CC_BOOT__destructT,too_many_1, wrong_no_1},
    {"BOOT@@augmentSub@@Builtin",wrong_no_na,   wrong_no_nb,   (n_args *)CC_BOOT__augmentSub},
    {"BOOT@@FLAGG-;sort;M2A;6@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__FLAGGKUsortUM2AU6},
    {"BOOT@@KERNEL;operator;$Bo;5@@Builtin",too_few_2,CC_BOOT__KERNELUoperatorUDBoU5,wrong_no_2},
    {"BOOT@@IFARRAY;minIndex;$I;7@@Builtin",too_few_2,CC_BOOT__IFARRAYUminIndexUDIU7,wrong_no_2},
    {"BOOT@@term1RW@@Builtin",  too_few_2,      CC_BOOT__term1RW,wrong_no_2},
    {"BOOT@@lazyMatchAssocV@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__lazyMatchAssocV},
    {"SYSTEM@@PNAME@@Builtin",  CC_SYSTEM__PNAME,too_many_1,   wrong_no_1},
    {"BOOT@@evalMmStackInner@@Builtin",CC_BOOT__evalMmStackInner,too_many_1,wrong_no_1},
    {"VMLISP@@IVECP@@Builtin",  CC_VMLISP__IVECP,too_many_1,   wrong_no_1},
    {"BOOT@@CONTAINEDisDomain@@Builtin",too_few_2,CC_BOOT__CONTAINEDisDomain,wrong_no_2},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
