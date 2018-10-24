
/* u01.c                 Machine generated C code */

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
(DEFUN BOOT::|SUP;pomopo!;$RNni2$;13| (BOOT::|p1| |r| |e| BOOT::|p2| |$|)
   (PROG (BOOT::|tm| #:G112980 BOOT::|e2| BOOT::|c2| |u| BOOT::|rout|)
      (RETURN
         (SEQ
            (BOOT::LETT BOOT::|rout| NIL BOOT::|SUP;pomopo!;$RNni2$;13|)
            (SEQ
               (BOOT::LETT BOOT::|tm| NIL BOOT::|SUP;pomopo!;$RNni2$;13|)
               (BOOT::LETT
                  #:G112980
                  BOOT::|p2|
                  BOOT::|SUP;pomopo!;$RNni2$;13|)
               BOOT::G190
               (COND
                  ((OR
                      (ATOM #:G112980)
                      (PROGN
                         (BOOT::LETT
                            BOOT::|tm|
                            (CAR #:G112980)
                            BOOT::|SUP;pomopo!;$RNni2$;13|)
                         NIL))
                     (GO BOOT::G191)))
               (SEQ
                  (BOOT::LETT
                     BOOT::|e2|
                     (|+| |e| (QCAR BOOT::|tm|))
                     BOOT::|SUP;pomopo!;$RNni2$;13|)
                  (BOOT::LETT
                     BOOT::|c2|
                     (BOOT:SPADCALL
                        |r|
                        (QCDR BOOT::|tm|)
                        (VMLISP:QREFELT |$| 44))
                     BOOT::|SUP;pomopo!;$RNni2$;13|)
                  (EXIT
                     (COND
                        ((BOOT:SPADCALL
                            BOOT::|c2|
                            (BOOT::|spadConstant| |$| 38)
                            (VMLISP:QREFELT |$| 45))
                           "next term")
                        ('T
                           (SEQ
                              (SEQ
                                 BOOT::G190
                                 (COND
                                    ((NULL
                                        (COND
                                           ((NULL BOOT::|p1|) 'NIL)
                                           ('T
                                              (|<|
                                                 BOOT::|e2|
                                                 (QCAR
                                                    (BOOT::|SPADfirst|
                                                       BOOT::|p1|)))) ))
                                       (GO BOOT::G191)))
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|rout|
                                       (CONS
                                          (BOOT::|SPADfirst| BOOT::|p1|)
                                          BOOT::|rout|)
                                       BOOT::|SUP;pomopo!;$RNni2$;13|)
                                    (EXIT
                                       (BOOT::LETT
                                          BOOT::|p1|
                                          (CDR BOOT::|p1|)
                                          BOOT::|SUP;pomopo!;$RNni2$;13|)))
                                 NIL
                                 (GO BOOT::G190)
                                 BOOT::G191
                                 (EXIT NIL))
                              (COND
                                 ((OR
                                     (NULL BOOT::|p1|)
                                     (|<|
                                        (QCAR
                                           (BOOT::|SPADfirst| BOOT::|p1|))
                                        BOOT::|e2|))
                                    (EXIT
                                       (BOOT::LETT
                                          BOOT::|rout|
                                          (CONS
                                             (CONS BOOT::|e2| BOOT::|c2|)
                                             BOOT::|rout|)
                                       BOOT::|SUP;pomopo!;$RNni2$;13|))))
                              (SEQ
                                 (BOOT::LETT
                                    |u|
                                    (BOOT:SPADCALL
                                       (QCDR
                                          (BOOT::|SPADfirst| BOOT::|p1|))
                                       BOOT::|c2|
                                       (VMLISP:QREFELT |$| 46))
                                    BOOT::|SUP;pomopo!;$RNni2$;13|)
                                 (EXIT
                                    (COND
                                       ((NULL
                                           (BOOT:SPADCALL
                                              |u|
                                              (BOOT::|spadConstant| |$| 38)
                                              (VMLISP:QREFELT |$| 45)))
                                          (BOOT::LETT
                                             BOOT::|rout|
                                             (CONS
                                                (CONS BOOT::|e2| |u|)
                                                BOOT::|rout|)
                                       BOOT::|SUP;pomopo!;$RNni2$;13|)))) )
                              (EXIT
                                 (BOOT::LETT
                                    BOOT::|p1|
                                    (CDR BOOT::|p1|)
                                    BOOT::|SUP;pomopo!;$RNni2$;13|)))) )))
               (BOOT::LETT
                  #:G112980
                  (CDR #:G112980)
                  BOOT::|SUP;pomopo!;$RNni2$;13|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT (NRECONC BOOT::|rout| BOOT::|p1|)))) ))

*/



/* Code for BOOT::|SUP;pomopo!;$RNni2$;13| */

static Lisp_Object MS_CDECL CC_BOOT__SUPUpomopoBUDRNni2DU13(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5,
                         Lisp_Object V6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V356, V357, V358, V359;
    Lisp_Object fn;
    argcheck(nargs, 5, "SUP;pomopo!;$RNni2$;13");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SUP;pomopo!;$RNni2$;13|\n");
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
    V357 = V5;
    stack[-6] = V4;
    stack[-7] = V3;
    stack[-8] = V2;
/* end of prologue */
    V356 = nil;
    stack[-3] = V356;
    V356 = V357;
    stack[-9] = V356;
    goto V23;

V23:
    V356 = stack[-9];
    if (!consp(V356)) goto V348;
    V356 = stack[-9];
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    stack[0] = V356;
    V356 = nil;
    if (!(V356 == nil)) goto V348;
    V357 = stack[-6];
    V356 = stack[0];
    V356 = qcar(V356);
    V356 = plus2(V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    stack[-4] = V356;
    V357 = stack[-5];
    V356 = (Lisp_Object)705; /* 44 */
    V356 = Lgetv(nil, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    V357 = V356;
    if (!car_legal(V357)) goto V373;
    V359 = qcar(V357);
    V358 = stack[-7];
    V357 = stack[0];
    V357 = qcdr(V357);
    if (!car_legal(V356)) goto V374;
    V356 = qcdr(V356);
    V356 = Lapply3(nil, 4, V359, V358, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    stack[-10] = V356;
    V357 = stack[-5];
    V356 = (Lisp_Object)721; /* 45 */
    V356 = Lgetv(nil, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    stack[-2] = V356;
    V356 = stack[-2];
    if (!car_legal(V356)) goto V371;
    stack[-1] = qcar(V356);
    stack[0] = stack[-10];
    V357 = stack[-5];
    V356 = (Lisp_Object)609; /* 38 */
    V356 = Lgetv(nil, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    V357 = V356;
    if (!car_legal(V357)) goto V373;
    V357 = qcar(V357);
    if (!car_legal(V356)) goto V374;
    V356 = qcdr(V356);
    V356 = Lapply1(nil, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    V357 = V356;
    V356 = stack[-2];
    if (!car_legal(V356)) goto V374;
    V356 = qcdr(V356);
    V356 = Lapply3(nil, 4, stack[-1], stack[0], V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    if (!(V356 == nil)) goto V38;
    V356 = lisp_true;
    if (!(V356 == nil)) goto V135;

V38:
    V356 = stack[-9];
    if (!car_legal(V356)) goto V374;
    V356 = qcdr(V356);
    stack[-9] = V356;
    goto V23;

V135:
    V356 = stack[-8];
    if (V356 == nil) goto V143;
    V356 = lisp_true;
    if (V356 == nil) goto V148;
    stack[0] = stack[-4];
    V356 = stack[-8];
    V357 = V356;
    V356 = V357;
    if (V356 == nil) goto V164;
    V356 = V357;
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    goto V159;

V159:
    V356 = qcar(V356);
    V356 = (Lisp_Object)lessp2(stack[0], V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    V356 = V356 ? lisp_true : nil;
    env = stack[-11];
    goto V142;

V142:
    if (V356 == nil) goto V134;
    V356 = stack[-8];
    V357 = V356;
    V356 = V357;
    if (V356 == nil) goto V185;
    V356 = V357;
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    goto V183;

V183:
    V357 = V356;
    V356 = stack[-3];
    V356 = cons(V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    stack[-3] = V356;
    V356 = stack[-8];
    if (!car_legal(V356)) goto V374;
    V356 = qcdr(V356);
    stack[-8] = V356;
    goto V135;

V185:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V356 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    goto V183;

V134:
    V356 = stack[-8];
    if (V356 == nil) goto V225;
    V356 = stack[-8];
    V357 = V356;
    V356 = V357;
    if (V356 == nil) goto V217;
    V356 = V357;
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    goto V212;

V212:
    V357 = qcar(V356);
    V356 = stack[-4];
    V356 = (Lisp_Object)lessp2(V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    V356 = V356 ? lisp_true : nil;
    env = stack[-11];
    if (!(V356 == nil)) goto V225;
    V357 = stack[-5];
    V356 = (Lisp_Object)737; /* 46 */
    V356 = Lgetv(nil, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    stack[-1] = V356;
    V356 = stack[-1];
    if (!car_legal(V356)) goto V371;
    stack[0] = qcar(V356);
    V356 = stack[-8];
    V357 = V356;
    V356 = V357;
    if (V356 == nil) goto V267;
    V356 = V357;
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    goto V262;

V262:
    V358 = qcdr(V356);
    V357 = stack[-10];
    V356 = stack[-1];
    if (!car_legal(V356)) goto V374;
    V356 = qcdr(V356);
    V356 = Lapply3(nil, 4, stack[0], V358, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    stack[-10] = V356;
    V357 = stack[-5];
    V356 = (Lisp_Object)721; /* 45 */
    V356 = Lgetv(nil, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    stack[-2] = V356;
    V356 = stack[-2];
    if (!car_legal(V356)) goto V371;
    stack[-1] = qcar(V356);
    stack[0] = stack[-10];
    V357 = stack[-5];
    V356 = (Lisp_Object)609; /* 38 */
    V356 = Lgetv(nil, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    V357 = V356;
    if (!car_legal(V357)) goto V373;
    V357 = qcar(V357);
    if (!car_legal(V356)) goto V374;
    V356 = qcdr(V356);
    V356 = Lapply1(nil, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    V357 = V356;
    V356 = stack[-2];
    if (!car_legal(V356)) goto V374;
    V356 = qcdr(V356);
    V356 = Lapply3(nil, 4, stack[-1], stack[0], V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    if (!(V356 == nil)) goto V236;
    V358 = stack[-4];
    V357 = stack[-10];
    V356 = stack[-3];
    V356 = acons(V358, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    stack[-3] = V356;
    goto V236;

V236:
    V356 = stack[-8];
    if (!car_legal(V356)) goto V374;
    V356 = qcdr(V356);
    stack[-8] = V356;
    goto V38;

V267:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V356 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    goto V262;

V225:
    V358 = stack[-4];
    V357 = stack[-10];
    V356 = stack[-3];
    V356 = acons(V358, V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    stack[-3] = V356;
    goto V38;

V217:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V356 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    goto V212;

V164:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V356 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-11];
    goto V159;

V148:
    V356 = nil;
    goto V142;

V143:
    V356 = nil;
    goto V142;

V348:
    V357 = stack[-3];
    V356 = stack[-8];
    {
        popv(12);
        fn = elt(env, 3); /* NRECONC */
        return (*qfn2(fn))(qenv(fn), V357, V356);
    }
/* error exit handlers */
V374:
    popv(12);
    return error(1, err_bad_cdr, V356);
V373:
    popv(12);
    return error(1, err_bad_car, V357);
V372:
    popv(12);
    return nil;
V371:
    popv(12);
    return error(1, err_bad_car, V356);
}

/*
(DEFUN BOOT::|OVAR;<;2$B;10| (BOOT::|s1| BOOT::|s2| |$|)
   (|<| BOOT::|s2| BOOT::|s1|))

*/



/* Code for BOOT::|OVAR;<;2$B;10| */

static Lisp_Object MS_CDECL CC_BOOT__OVARURU2DBU10(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V16, V17, V18;
    argcheck(nargs, 3, "OVAR;<;2$B;10");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|OVAR;<;2$B;10|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V16 = V4;
    V17 = V3;
    V18 = V2;
/* end of prologue */
    V16 = V17;
    V17 = V18;
        return Llessp(nil, V16, V17);
}

/*
(DEFUN BOOT::|NSMP;mvar;$VarSet;5| (|p| |$|)
   (COND
      ((BOOT::QEQCAR |p| 0)
         (BOOT::|error| " Error in mvar from NSMP : #1 has no variables."))
      ('T (QCAR (QCDR |p|)))) )

*/



/* Code for BOOT::|NSMP;mvar;$VarSet;5| */

static Lisp_Object CC_BOOT__NSMPUmvarUDVarSetU5(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V28, V29, V30;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|NSMP;mvar;$VarSet;5|\n");
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
    V28 = V3;
    V29 = V2;
/* end of prologue */
    V28 = V29;
    V30 = qcar(V28);
    V28 = (Lisp_Object)1; /* 0 */
    V28 = Leql(nil, V30, V28);
    env = stack[0];
    if (V28 == nil) goto V10;
    V28 = elt(env, 1); /* " Error in mvar from NSMP : #1 has no variables." */
    {
        popv(1);
        fn = elt(env, 2); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V28);
    }

V10:
    V28 = lisp_true;
    if (V28 == nil) goto V23;
    V28 = V29;
    V28 = qcdr(V28);
    V28 = qcar(V28);
    { popv(1); return onevalue(V28); }

V23:
    V28 = nil;
    { popv(1); return onevalue(V28); }
}

/*
(DEFUN BOOT::|SUP;ground?;$B;7| (|p| |$|)
   (COND
      ((NULL |p|) 'T)
      ((NULL (CDR |p|)) (ZEROP (QCAR (BOOT::|SPADfirst| |p|))))
      ('T 'NIL)))

*/



/* Code for BOOT::|SUP;ground?;$B;7| */

static Lisp_Object CC_BOOT__SUPUgroundWUDBU7(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SUP;ground?;$B;7|\n");
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
    V35 = V3;
    V36 = V2;
/* end of prologue */
    V35 = V36;
    if (V35 == nil) goto V9;
    V35 = V36;
    if (!car_legal(V35)) goto V37;
    V35 = qcdr(V35);
    if (V35 == nil) goto V13;
    V35 = lisp_true;
    if (V35 == nil) goto V32;
    V35 = nil;
    return onevalue(V35);

V32:
    V35 = nil;
    return onevalue(V35);

V13:
    V35 = V36;
    V36 = V35;
    V35 = V36;
    if (V35 == nil) goto V25;
    V35 = V36;
    if (!car_legal(V35)) goto V38;
    V35 = qcar(V35);
    goto V20;

V20:
    V35 = qcar(V35);
        return Lzerop(nil, V35);

V25:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V35 = (*qfnn(fn))(qenv(fn), 0);
    errexit();
    goto V20;

V9:
    V35 = lisp_true;
    return onevalue(V35);
/* error exit handlers */
V38:
    return error(1, err_bad_car, V35);
V37:
    return error(1, err_bad_cdr, V35);
}

/*
(DEFUN BOOT::|PR;addm!| (BOOT::|p1|
      BOOT::|coef|
      BOOT::|exp|
      BOOT::|p2|
      |$|)
   (PROG (BOOT::|tx| BOOT::|ty| BOOT::|exy| BOOT::|newcoef| BOOT::|ttt|
         BOOT::|res| BOOT::|endcell| BOOT::|newcell|)
      (RETURN
         (SEQ
            (BOOT::LETT BOOT::|res| NIL BOOT::|PR;addm!|)
            (BOOT::LETT BOOT::|endcell| NIL BOOT::|PR;addm!|)
            (SEQ
               BOOT::G190
               (COND
                  ((NULL
                      (COND
                         ((OR (NULL BOOT::|p1|) (NULL BOOT::|p2|)) 'NIL)
                         ('T 'T)))
                     (GO BOOT::G191)))
               (SEQ
                  (BOOT::LETT
                     BOOT::|tx|
                     (BOOT::|SPADfirst| BOOT::|p1|)
                     BOOT::|PR;addm!|)
                  (BOOT::LETT
                     BOOT::|ty|
                     (BOOT::|SPADfirst| BOOT::|p2|)
                     BOOT::|PR;addm!|)
                  (BOOT::LETT
                     BOOT::|exy|
                     (BOOT:SPADCALL
                        BOOT::|exp|
                        (QCAR BOOT::|ty|)
                        (VMLISP:QREFELT |$| 43))
                     BOOT::|PR;addm!|)
                  (BOOT::LETT BOOT::|newcell| NIL BOOT::|PR;addm!|)
                  (COND
                     ((BOOT:SPADCALL
                         (QCAR BOOT::|tx|)
                         BOOT::|exy|
                         (VMLISP:QREFELT |$| 29))
                        (SEQ
                           (BOOT::LETT
                              BOOT::|newcoef|
                              (BOOT:SPADCALL
                                 (QCDR BOOT::|tx|)
                                 (BOOT:SPADCALL
                                    BOOT::|coef|
                                    (QCDR BOOT::|ty|)
                                    (VMLISP:QREFELT |$| 42))
                                 (VMLISP:QREFELT |$| 46))
                              BOOT::|PR;addm!|)
                           (COND
                              ((NULL
                                  (BOOT:SPADCALL
                                     BOOT::|newcoef|
                                     (VMLISP:QREFELT |$| 36)))
                                 (SEQ
                                    (PROGN
                                       (RPLACD BOOT::|tx| BOOT::|newcoef|)
                                       (QCDR BOOT::|tx|))
                                    (EXIT
                                       (BOOT::LETT
                                          BOOT::|newcell|
                                          BOOT::|p1|
                                          BOOT::|PR;addm!|)))) )
                           (BOOT::LETT
                              BOOT::|p1|
                              (CDR BOOT::|p1|)
                              BOOT::|PR;addm!|)
                           (EXIT
                              (BOOT::LETT
                                 BOOT::|p2|
                                 (CDR BOOT::|p2|)
                                 BOOT::|PR;addm!|))))
                     ((BOOT:SPADCALL
                         BOOT::|exy|
                         (QCAR BOOT::|tx|)
                         (VMLISP:QREFELT |$| 30))
                        (SEQ
                           (BOOT::LETT
                              BOOT::|newcell|
                              BOOT::|p1|
                              BOOT::|PR;addm!|)
                           (EXIT
                              (BOOT::LETT
                                 BOOT::|p1|
                                 (CDR BOOT::|p1|)
                                 BOOT::|PR;addm!|))))
                     ('T
                        (SEQ
                           (BOOT::LETT
                              BOOT::|newcoef|
                              (BOOT:SPADCALL
                                 BOOT::|coef|
                                 (QCDR BOOT::|ty|)
                                 (VMLISP:QREFELT |$| 42))
                              BOOT::|PR;addm!|)
                           (COND
                              ((OR
                                  (VMLISP:QREFELT |$| 41)
                                  (NULL
                                     (BOOT:SPADCALL
                                        BOOT::|newcoef|
                                        (VMLISP:QREFELT |$| 36))))
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|ttt|
                                       (CONS BOOT::|exy| BOOT::|newcoef|)
                                       BOOT::|PR;addm!|)
                                    (EXIT
                                       (BOOT::LETT
                                          BOOT::|newcell|
                                          (CONS BOOT::|ttt| NIL)
                                          BOOT::|PR;addm!|))))
                              ('T
                                 (BOOT::LETT
                                    BOOT::|newcell|
                                    NIL
                                    BOOT::|PR;addm!|)))
                           (EXIT
                              (BOOT::LETT
                                 BOOT::|p2|
                                 (CDR BOOT::|p2|)
                                 BOOT::|PR;addm!|)))) )
                  (EXIT
                     (COND
                        ((NULL (NULL BOOT::|newcell|))
                           (COND
                              ((NULL BOOT::|res|)
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|res|
                                       BOOT::|newcell|
                                       BOOT::|PR;addm!|)
                                    (EXIT
                                       (BOOT::LETT
                                          BOOT::|endcell|
                                          BOOT::|res|
                                          BOOT::|PR;addm!|))))
                              ('T
                                 (SEQ
                                    (BOOT::|PR;qsetrest!|
                                       BOOT::|endcell|
                                       BOOT::|newcell|
                                       |$|)
                                    (EXIT
                                       (BOOT::LETT
                                          BOOT::|endcell|
                                          BOOT::|newcell|
                                          BOOT::|PR;addm!|)))) ))) ))
               NIL
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (COND
               ((NULL BOOT::|p1|)
                  (BOOT::LETT
                     BOOT::|newcell|
                     (BOOT::|PR;times|
                        BOOT::|coef|
                        BOOT::|exp|
                        BOOT::|p2|
                        |$|)
                     BOOT::|PR;addm!|))
               ('T
                  (BOOT::LETT
                     BOOT::|newcell|
                     BOOT::|p1|
                     BOOT::|PR;addm!|)))
            (EXIT
               (COND
                  ((NULL BOOT::|res|) BOOT::|newcell|)
                  ('T
                     (SEQ
                        (BOOT::|PR;qsetrest!|
                           BOOT::|endcell|
                           BOOT::|newcell|
                           |$|)
                        (EXIT BOOT::|res|)))) ))) ))

*/



/* Code for BOOT::|PR;addm!| */

static Lisp_Object MS_CDECL CC_BOOT__PRUaddmB(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5,
                         Lisp_Object V6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V448, V449, V450, V451;
    Lisp_Object fn;
    argcheck(nargs, 5, "PR;addm!");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PR;addm!|\n");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-7] = V6;
    stack[-8] = V5;
    stack[-9] = V4;
    stack[-10] = V3;
    stack[-11] = V2;
/* end of prologue */
    stack[-3] = nil;
    V448 = nil;
    stack[-5] = V448;
    V448 = nil;
    stack[-4] = V448;
    goto V26;

V26:
    V448 = stack[-11];
    if (V448 == nil) goto V34;
    V448 = stack[-8];
    if (V448 == nil) goto V34;
    V448 = lisp_true;
    if (V448 == nil) goto V42;
    V448 = lisp_true;
    goto V33;

V33:
    if (V448 == nil) goto V25;
    V448 = stack[-11];
    V449 = V448;
    V448 = V449;
    if (V448 == nil) goto V54;
    V448 = V449;
    if (!car_legal(V448)) goto V465;
    V448 = qcar(V448);
    goto V49;

V49:
    stack[-12] = V448;
    V448 = stack[-8];
    V449 = V448;
    V448 = V449;
    if (V448 == nil) goto V66;
    V448 = V449;
    if (!car_legal(V448)) goto V465;
    V448 = qcar(V448);
    goto V61;

V61:
    stack[-6] = V448;
    V449 = stack[-7];
    V448 = (Lisp_Object)689; /* 43 */
    V448 = Lgetv(nil, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V449 = V448;
    if (!car_legal(V449)) goto V467;
    V451 = qcar(V449);
    V450 = stack[-9];
    V449 = stack[-6];
    V449 = qcar(V449);
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    V448 = Lapply3(nil, 4, V451, V450, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    stack[0] = V448;
    V448 = nil;
    stack[-3] = V448;
    V449 = stack[-7];
    V448 = (Lisp_Object)465; /* 29 */
    V448 = Lgetv(nil, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V449 = V448;
    if (!car_legal(V449)) goto V467;
    V451 = qcar(V449);
    V449 = stack[-12];
    V450 = qcar(V449);
    V449 = stack[0];
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    V448 = Lapply3(nil, 4, V451, V450, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    if (V448 == nil) goto V242;
    V449 = stack[-7];
    V448 = (Lisp_Object)737; /* 46 */
    V448 = Lgetv(nil, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    stack[-2] = V448;
    V448 = stack[-2];
    if (!car_legal(V448)) goto V465;
    stack[-1] = qcar(V448);
    V448 = stack[-12];
    stack[0] = qcdr(V448);
    V449 = stack[-7];
    V448 = (Lisp_Object)673; /* 42 */
    V448 = Lgetv(nil, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V449 = V448;
    if (!car_legal(V449)) goto V467;
    V451 = qcar(V449);
    V450 = stack[-10];
    V449 = stack[-6];
    V449 = qcdr(V449);
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    V448 = Lapply3(nil, 4, V451, V450, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V449 = V448;
    V448 = stack[-2];
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    V448 = Lapply3(nil, 4, stack[-1], stack[0], V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    stack[-1] = V448;
    V449 = stack[-7];
    V448 = (Lisp_Object)577; /* 36 */
    V448 = Lgetv(nil, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V449 = V448;
    if (!car_legal(V449)) goto V467;
    V450 = qcar(V449);
    V449 = stack[-1];
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    V448 = Lapply2(nil, 3, V450, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    if (!(V448 == nil)) goto V190;
    V449 = stack[-12];
    V448 = stack[-1];
    V448 = Lrplacd(nil, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V448 = stack[-11];
    stack[-3] = V448;
    goto V190;

V190:
    V448 = stack[-11];
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    stack[-11] = V448;
    V448 = stack[-8];
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    stack[-8] = V448;
    goto V101;

V101:
    V448 = stack[-3];
    if (V448 == nil) goto V26;
    V448 = stack[-5];
    if (V448 == nil) goto V370;
    V448 = lisp_true;
    if (V448 == nil) goto V26;
    V450 = stack[-4];
    V449 = stack[-3];
    V448 = stack[-7];
    fn = elt(env, 1); /* BOOT::|PR;qsetrest!| */
    V448 = (*qfnn(fn))(qenv(fn), 3, V450, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V448 = stack[-3];
    stack[-4] = V448;
    goto V26;

V370:
    V448 = stack[-3];
    stack[-5] = V448;
    V448 = stack[-5];
    stack[-4] = V448;
    goto V26;

V242:
    V449 = stack[-7];
    V448 = (Lisp_Object)481; /* 30 */
    V448 = Lgetv(nil, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V449 = V448;
    if (!car_legal(V449)) goto V467;
    V451 = qcar(V449);
    V450 = stack[0];
    V449 = stack[-12];
    V449 = qcar(V449);
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    V448 = Lapply3(nil, 4, V451, V450, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    if (V448 == nil) goto V237;
    V448 = stack[-11];
    stack[-3] = V448;
    V448 = stack[-11];
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    stack[-11] = V448;
    goto V101;

V237:
    V448 = lisp_true;
    if (V448 == nil) goto V101;
    V449 = stack[-7];
    V448 = (Lisp_Object)673; /* 42 */
    V448 = Lgetv(nil, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V449 = V448;
    if (!car_legal(V449)) goto V467;
    V451 = qcar(V449);
    V450 = stack[-10];
    V449 = stack[-6];
    V449 = qcdr(V449);
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    V448 = Lapply3(nil, 4, V451, V450, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    stack[-1] = V448;
    V449 = stack[-7];
    V448 = (Lisp_Object)657; /* 41 */
    V448 = Lgetv(nil, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    if (!(V448 == nil)) goto V346;
    V449 = stack[-7];
    V448 = (Lisp_Object)577; /* 36 */
    V448 = Lgetv(nil, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V449 = V448;
    if (!car_legal(V449)) goto V467;
    V450 = qcar(V449);
    V449 = stack[-1];
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    V448 = Lapply2(nil, 3, V450, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    if (V448 == nil) goto V346;
    V448 = lisp_true;
    if (V448 == nil) goto V306;
    V448 = nil;
    stack[-3] = V448;
    goto V306;

V306:
    V448 = stack[-8];
    if (!car_legal(V448)) goto V468;
    V448 = qcdr(V448);
    stack[-8] = V448;
    goto V101;

V346:
    V449 = stack[0];
    V448 = stack[-1];
    V448 = cons(V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    V448 = ncons(V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    stack[-3] = V448;
    goto V306;

V66:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V448 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    goto V61;

V54:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V448 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    goto V49;

V25:
    V448 = stack[-11];
    if (V448 == nil) goto V406;
    V448 = lisp_true;
    if (V448 == nil) goto V401;
    V448 = stack[-11];
    stack[-3] = V448;
    goto V401;

V401:
    V448 = stack[-5];
    if (V448 == nil) { Lisp_Object res = stack[-3]; popv(14); return onevalue(res); }
    V448 = lisp_true;
    if (V448 == nil) goto V430;
    V450 = stack[-4];
    V449 = stack[-3];
    V448 = stack[-7];
    fn = elt(env, 1); /* BOOT::|PR;qsetrest!| */
    V448 = (*qfnn(fn))(qenv(fn), 3, V450, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    { Lisp_Object res = stack[-5]; popv(14); return onevalue(res); }

V430:
    V448 = nil;
    { popv(14); return onevalue(V448); }

V406:
    V451 = stack[-10];
    V450 = stack[-9];
    V449 = stack[-8];
    V448 = stack[-7];
    fn = elt(env, 3); /* BOOT::|PR;times| */
    V448 = (*qfnn(fn))(qenv(fn), 4, V451, V450, V449, V448);
    nil = C_nil;
    if (exception_pending()) goto V466;
    env = stack[-13];
    stack[-3] = V448;
    goto V401;

V42:
    V448 = nil;
    goto V33;

V34:
    V448 = nil;
    goto V33;
/* error exit handlers */
V468:
    popv(14);
    return error(1, err_bad_cdr, V448);
V467:
    popv(14);
    return error(1, err_bad_car, V449);
V466:
    popv(14);
    return nil;
V465:
    popv(14);
    return error(1, err_bad_car, V448);
}

/*
(DEFUN BOOT::|SMP;+;3$;27| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (BOOT::|mvar| BOOT::|up|)
      (RETURN
         (SEQ
            (COND
               ((BOOT::QEQCAR BOOT::|p1| 0)
                  (COND
                     ((BOOT::QEQCAR BOOT::|p2| 0)
                        (EXIT
                           (CONS
                              0
                              (BOOT:SPADCALL
                                 (QCDR BOOT::|p1|)
                                 (QCDR BOOT::|p2|)
                                 (VMLISP:QREFELT |$| 92)))) ))) )
            (EXIT
               (COND
                  ((BOOT::QEQCAR BOOT::|p1| 0)
                     (CONS
                        1
                        (CONS
                           (QCAR (QCDR BOOT::|p2|))
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL
                                 BOOT::|p1|
                                 (VMLISP:QREFELT |$| 93))
                              (QCDR (QCDR BOOT::|p2|))
                              (VMLISP:QREFELT |$| 56)))) )
                  ((BOOT::QEQCAR BOOT::|p2| 0)
                     (CONS
                        1
                        (CONS
                           (QCAR (QCDR BOOT::|p1|))
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p1|))
                              (BOOT:SPADCALL
                                 BOOT::|p2|
                                 (VMLISP:QREFELT |$| 93))
                              (VMLISP:QREFELT |$| 56)))) )
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
                                 BOOT::|SMP;+;3$;27|)
                              (BOOT::LETT
                                 BOOT::|up|
                                 (BOOT:SPADCALL
                                    (QCDR (QCDR BOOT::|p1|))
                                    (QCDR (QCDR BOOT::|p2|))
                                    (VMLISP:QREFELT |$| 56))
                                 BOOT::|SMP;+;3$;27|)
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
                            (QCAR (QCDR BOOT::|p1|))
                            (QCAR (QCDR BOOT::|p2|))
                            (VMLISP:QREFELT |$| 50))
                           (CONS
                              1
                              (CONS
                                 (QCAR (QCDR BOOT::|p2|))
                                 (BOOT:SPADCALL
                                    (BOOT:SPADCALL
                                       BOOT::|p1|
                                       (VMLISP:QREFELT |$| 93))
                                    (QCDR (QCDR BOOT::|p2|))
                                    (VMLISP:QREFELT |$| 56)))) )
                        ('T
                           (CONS
                              1
                              (CONS
                                 (QCAR (QCDR BOOT::|p1|))
                                 (BOOT:SPADCALL
                                    (QCDR (QCDR BOOT::|p1|))
                                    (BOOT:SPADCALL
                                       BOOT::|p2|
                                       (VMLISP:QREFELT |$| 93))
                                    (VMLISP:QREFELT |$| 56)))) ))) ))) )))

*/



/* Code for BOOT::|SMP;+;3$;27| */

static Lisp_Object MS_CDECL CC_BOOT__SMPULU3DU27(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V534, V535, V536, V537;
    argcheck(nargs, 3, "SMP;+;3$;27");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;+;3$;27|\n");
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
    V534 = stack[-5];
    V535 = qcar(V534);
    V534 = (Lisp_Object)1; /* 0 */
    V534 = Leql(nil, V535, V534);
    env = stack[-7];
    if (V534 == nil) goto V81;
    V534 = stack[-4];
    V535 = qcar(V534);
    V534 = (Lisp_Object)1; /* 0 */
    V534 = Leql(nil, V535, V534);
    env = stack[-7];
    if (V534 == nil) goto V81;
    stack[0] = (Lisp_Object)1; /* 0 */
    V535 = stack[-3];
    V534 = (Lisp_Object)1473; /* 92 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    if (!car_legal(V535)) goto V546;
    V537 = qcar(V535);
    V535 = stack[-5];
    V536 = qcdr(V535);
    V535 = stack[-4];
    V535 = qcdr(V535);
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply3(nil, 4, V537, V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    {
        Lisp_Object V548 = stack[0];
        popv(8);
        { Lisp_Object retVal = cons(V548, V534);
        errexit();
        return onevalue(retVal); }
    }

V81:
    V534 = stack[-5];
    V535 = qcar(V534);
    V534 = (Lisp_Object)1; /* 0 */
    V534 = Leql(nil, V535, V534);
    env = stack[-7];
    if (V534 == nil) goto V156;
    stack[-6] = (Lisp_Object)17; /* 1 */
    V534 = stack[-4];
    V534 = qcdr(V534);
    stack[-2] = qcar(V534);
    V535 = stack[-3];
    V534 = (Lisp_Object)897; /* 56 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    stack[-1] = V534;
    V534 = stack[-1];
    if (!car_legal(V534)) goto V549;
    stack[0] = qcar(V534);
    V535 = stack[-3];
    V534 = (Lisp_Object)1489; /* 93 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    if (!car_legal(V535)) goto V546;
    V536 = qcar(V535);
    V535 = stack[-5];
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply2(nil, 3, V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V536 = V534;
    V534 = stack[-4];
    V534 = qcdr(V534);
    V535 = qcdr(V534);
    V534 = stack[-1];
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply3(nil, 4, stack[0], V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    {
        Lisp_Object V550 = stack[-6];
        Lisp_Object V551 = stack[-2];
        popv(8);
        { Lisp_Object retVal = list2star(V550, V551, V534);
        errexit();
        return onevalue(retVal); }
    }

V156:
    V534 = stack[-4];
    V535 = qcar(V534);
    V534 = (Lisp_Object)1; /* 0 */
    V534 = Leql(nil, V535, V534);
    env = stack[-7];
    if (V534 == nil) goto V154;
    stack[-6] = (Lisp_Object)17; /* 1 */
    V534 = stack[-5];
    V534 = qcdr(V534);
    stack[-2] = qcar(V534);
    V535 = stack[-3];
    V534 = (Lisp_Object)897; /* 56 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    stack[-1] = V534;
    V534 = stack[-1];
    if (!car_legal(V534)) goto V549;
    stack[0] = qcar(V534);
    V534 = stack[-5];
    V534 = qcdr(V534);
    stack[-5] = qcdr(V534);
    V535 = stack[-3];
    V534 = (Lisp_Object)1489; /* 93 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    if (!car_legal(V535)) goto V546;
    V536 = qcar(V535);
    V535 = stack[-4];
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply2(nil, 3, V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    V534 = stack[-1];
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply3(nil, 4, stack[0], stack[-5], V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    {
        Lisp_Object V552 = stack[-6];
        Lisp_Object V553 = stack[-2];
        popv(8);
        { Lisp_Object retVal = list2star(V552, V553, V534);
        errexit();
        return onevalue(retVal); }
    }

V154:
    V534 = lisp_true;
    if (V534 == nil) goto V229;
    V535 = stack[-3];
    V534 = (Lisp_Object)817; /* 51 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    if (!car_legal(V535)) goto V546;
    V537 = qcar(V535);
    V535 = stack[-5];
    V535 = qcdr(V535);
    V536 = qcar(V535);
    V535 = stack[-4];
    V535 = qcdr(V535);
    V535 = qcar(V535);
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply3(nil, 4, V537, V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    if (V534 == nil) goto V375;
    V534 = stack[-5];
    V534 = qcdr(V534);
    V534 = qcar(V534);
    stack[0] = V534;
    V535 = stack[-3];
    V534 = (Lisp_Object)897; /* 56 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    if (!car_legal(V535)) goto V546;
    V537 = qcar(V535);
    V535 = stack[-5];
    V535 = qcdr(V535);
    V536 = qcdr(V535);
    V535 = stack[-4];
    V535 = qcdr(V535);
    V535 = qcdr(V535);
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply3(nil, 4, V537, V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    stack[-1] = V534;
    V535 = stack[-3];
    V534 = (Lisp_Object)337; /* 21 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    if (!car_legal(V535)) goto V546;
    V536 = qcar(V535);
    V535 = stack[-1];
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply2(nil, 3, V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    if (V534 == nil) goto V305;
    V535 = stack[-3];
    V534 = (Lisp_Object)353; /* 22 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    V535 = V534;
    if (!car_legal(V535)) goto V546;
    V536 = qcar(V535);
    V535 = stack[-1];
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
        popv(8);
        return Lapply2(nil, 3, V536, V535, V534);

V305:
    V534 = lisp_true;
    if (V534 == nil) goto V355;
    V536 = (Lisp_Object)17; /* 1 */
    V535 = stack[0];
    V534 = stack[-1];
    popv(8);
    { Lisp_Object retVal = list2star(V536, V535, V534);
    errexit();
    return onevalue(retVal); }

V355:
    V534 = nil;
    { popv(8); return onevalue(V534); }

V375:
    V535 = stack[-3];
    V534 = (Lisp_Object)801; /* 50 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    if (!car_legal(V535)) goto V546;
    V537 = qcar(V535);
    V535 = stack[-5];
    V535 = qcdr(V535);
    V536 = qcar(V535);
    V535 = stack[-4];
    V535 = qcdr(V535);
    V535 = qcar(V535);
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply3(nil, 4, V537, V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    if (V534 == nil) goto V370;
    stack[-6] = (Lisp_Object)17; /* 1 */
    V534 = stack[-4];
    V534 = qcdr(V534);
    stack[-2] = qcar(V534);
    V535 = stack[-3];
    V534 = (Lisp_Object)897; /* 56 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    stack[-1] = V534;
    V534 = stack[-1];
    if (!car_legal(V534)) goto V549;
    stack[0] = qcar(V534);
    V535 = stack[-3];
    V534 = (Lisp_Object)1489; /* 93 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    if (!car_legal(V535)) goto V546;
    V536 = qcar(V535);
    V535 = stack[-5];
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply2(nil, 3, V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V536 = V534;
    V534 = stack[-4];
    V534 = qcdr(V534);
    V535 = qcdr(V534);
    V534 = stack[-1];
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply3(nil, 4, stack[0], V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    {
        Lisp_Object V554 = stack[-6];
        Lisp_Object V555 = stack[-2];
        popv(8);
        { Lisp_Object retVal = list2star(V554, V555, V534);
        errexit();
        return onevalue(retVal); }
    }

V370:
    V534 = lisp_true;
    if (V534 == nil) goto V467;
    stack[-6] = (Lisp_Object)17; /* 1 */
    V534 = stack[-5];
    V534 = qcdr(V534);
    stack[-2] = qcar(V534);
    V535 = stack[-3];
    V534 = (Lisp_Object)897; /* 56 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    stack[-1] = V534;
    V534 = stack[-1];
    if (!car_legal(V534)) goto V549;
    stack[0] = qcar(V534);
    V534 = stack[-5];
    V534 = qcdr(V534);
    stack[-5] = qcdr(V534);
    V535 = stack[-3];
    V534 = (Lisp_Object)1489; /* 93 */
    V534 = Lgetv(nil, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    if (!car_legal(V535)) goto V546;
    V536 = qcar(V535);
    V535 = stack[-4];
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply2(nil, 3, V536, V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    env = stack[-7];
    V535 = V534;
    V534 = stack[-1];
    if (!car_legal(V534)) goto V547;
    V534 = qcdr(V534);
    V534 = Lapply3(nil, 4, stack[0], stack[-5], V535, V534);
    nil = C_nil;
    if (exception_pending()) goto V545;
    {
        Lisp_Object V556 = stack[-6];
        Lisp_Object V557 = stack[-2];
        popv(8);
        { Lisp_Object retVal = list2star(V556, V557, V534);
        errexit();
        return onevalue(retVal); }
    }

V467:
    V534 = nil;
    { popv(8); return onevalue(V534); }

V229:
    V534 = nil;
    { popv(8); return onevalue(V534); }
/* error exit handlers */
V549:
    popv(8);
    return error(1, err_bad_car, V534);
V547:
    popv(8);
    return error(1, err_bad_cdr, V534);
V546:
    popv(8);
    return error(1, err_bad_car, V535);
V545:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|PR;times!0| (BOOT::|#1| BOOT::|$$|)
   (BOOT::|PR;termTimes|
      (VMLISP:QREFELT BOOT::|$$| 2)
      (VMLISP:QREFELT BOOT::|$$| 1)
      BOOT::|#1|
      (VMLISP:QREFELT BOOT::|$$| 0)))

*/



/* Code for BOOT::|PR;times!0| */

static Lisp_Object CC_BOOT__PRUtimesB0(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V42, V43;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PR;times!0|\n");
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
    V43 = stack[-1];
    V42 = (Lisp_Object)33; /* 2 */
    stack[-3] = Lgetv(nil, V43, V42);
    nil = C_nil;
    if (exception_pending()) goto V48;
    env = stack[-4];
    V43 = stack[-1];
    V42 = (Lisp_Object)17; /* 1 */
    stack[0] = Lgetv(nil, V43, V42);
    nil = C_nil;
    if (exception_pending()) goto V48;
    env = stack[-4];
    V43 = stack[-1];
    V42 = (Lisp_Object)1; /* 0 */
    V42 = Lgetv(nil, V43, V42);
    nil = C_nil;
    if (exception_pending()) goto V48;
    env = stack[-4];
    {
        Lisp_Object V49 = stack[-3];
        Lisp_Object V50 = stack[0];
        Lisp_Object V51 = stack[-2];
        popv(5);
        fn = elt(env, 1); /* BOOT::|PR;termTimes| */
        return (*qfnn(fn))(qenv(fn), 4, V49, V50, V51, V42);
    }
/* error exit handlers */
V48:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|PR;termTimes| (|r| |e| BOOT::|tx| |$|)
   (CONS
      (BOOT:SPADCALL |e| (QCAR BOOT::|tx|) (VMLISP:QREFELT |$| 43))
      (BOOT:SPADCALL |r| (QCDR BOOT::|tx|) (VMLISP:QREFELT |$| 42))))

*/



/* Code for BOOT::|PR;termTimes| */

static Lisp_Object MS_CDECL CC_BOOT__PRUtermTimes(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V71, V72, V73, V74;
    argcheck(nargs, 4, "PR;termTimes");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PR;termTimes|\n");
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
    V72 = stack[0];
    V71 = (Lisp_Object)689; /* 43 */
    V71 = Lgetv(nil, V72, V71);
    nil = C_nil;
    if (exception_pending()) goto V79;
    env = stack[-4];
    V72 = V71;
    if (!car_legal(V72)) goto V80;
    V74 = qcar(V72);
    V73 = stack[-2];
    V72 = stack[-1];
    V72 = qcar(V72);
    if (!car_legal(V71)) goto V81;
    V71 = qcdr(V71);
    V71 = Lapply3(nil, 4, V74, V73, V72, V71);
    nil = C_nil;
    if (exception_pending()) goto V79;
    env = stack[-4];
    stack[-2] = V71;
    V72 = stack[0];
    V71 = (Lisp_Object)673; /* 42 */
    V71 = Lgetv(nil, V72, V71);
    nil = C_nil;
    if (exception_pending()) goto V79;
    env = stack[-4];
    V72 = V71;
    if (!car_legal(V72)) goto V80;
    V74 = qcar(V72);
    V73 = stack[-3];
    V72 = stack[-1];
    V72 = qcdr(V72);
    if (!car_legal(V71)) goto V81;
    V71 = qcdr(V71);
    V71 = Lapply3(nil, 4, V74, V73, V72, V71);
    nil = C_nil;
    if (exception_pending()) goto V79;
    {
        Lisp_Object V82 = stack[-2];
        popv(5);
        { Lisp_Object retVal = cons(V82, V71);
        errexit();
        return onevalue(retVal); }
    }
/* error exit handlers */
V81:
    popv(5);
    return error(1, err_bad_cdr, V71);
V80:
    popv(5);
    return error(1, err_bad_car, V72);
V79:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|IIARRAY2;qsetelt!;$2I2R;12| (|m| |i| |j| |r| |$|)
   (SETELT
      (ELT |m| (|-| |i| (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 24))))
      (|-| |j| (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 25)))
      |r|))

*/



/* Code for BOOT::|IIARRAY2;qsetelt!;$2I2R;12| */

static Lisp_Object MS_CDECL CC_BOOT__IIARRAY2UqseteltBUD2I2RU12(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5,
                         Lisp_Object V6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V88, V89, V90;
    Lisp_Object fn;
    argcheck(nargs, 5, "IIARRAY2;qsetelt!;$2I2R;12");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IIARRAY2;qsetelt!;$2I2R;12|\n");
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
    stack[-1] = V6;
    stack[-2] = V5;
    stack[-3] = V4;
    V88 = V3;
    stack[-4] = V2;
/* end of prologue */
    stack[-5] = stack[-4];
    stack[0] = V88;
    V89 = stack[-1];
    V88 = (Lisp_Object)385; /* 24 */
    V88 = Lgetv(nil, V89, V88);
    nil = C_nil;
    if (exception_pending()) goto V97;
    env = stack[-6];
    V89 = V88;
    if (!car_legal(V89)) goto V98;
    V90 = qcar(V89);
    V89 = stack[-4];
    if (!car_legal(V88)) goto V99;
    V88 = qcdr(V88);
    V88 = Lapply2(nil, 3, V90, V89, V88);
    nil = C_nil;
    if (exception_pending()) goto V97;
    env = stack[-6];
    V88 = difference2(stack[0], V88);
    nil = C_nil;
    if (exception_pending()) goto V97;
    env = stack[-6];
    fn = elt(env, 1); /* ELT */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-5], V88);
    nil = C_nil;
    if (exception_pending()) goto V97;
    env = stack[-6];
    V89 = stack[-1];
    V88 = (Lisp_Object)401; /* 25 */
    V88 = Lgetv(nil, V89, V88);
    nil = C_nil;
    if (exception_pending()) goto V97;
    env = stack[-6];
    V89 = V88;
    if (!car_legal(V89)) goto V98;
    V90 = qcar(V89);
    V89 = stack[-4];
    if (!car_legal(V88)) goto V99;
    V88 = qcdr(V88);
    V88 = Lapply2(nil, 3, V90, V89, V88);
    nil = C_nil;
    if (exception_pending()) goto V97;
    env = stack[-6];
    V89 = difference2(stack[-3], V88);
    nil = C_nil;
    if (exception_pending()) goto V97;
    env = stack[-6];
    V88 = stack[-2];
    {
        Lisp_Object V100 = stack[0];
        popv(7);
        fn = elt(env, 2); /* SETELT */
        return (*qfnn(fn))(qenv(fn), 3, V100, V89, V88);
    }
/* error exit handlers */
V99:
    popv(7);
    return error(1, err_bad_cdr, V88);
V98:
    popv(7);
    return error(1, err_bad_car, V89);
V97:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|IIARRAY2;elt;$2IR;11| (|m| |i| |j| |$|)
   (COND
      ((OR
          (|<| |i| (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 24)))
          (|<| (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 27)) |i|))
         (BOOT::|error| "elt: index out of range"))
      ((OR
          (|<| |j| (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 25)))
          (|<| (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 29)) |j|))
         (BOOT::|error| "elt: index out of range"))
      ('T (BOOT:SPADCALL |m| |i| |j| (VMLISP:QREFELT |$| 30)))) )

*/



/* Code for BOOT::|IIARRAY2;elt;$2IR;11| */

static Lisp_Object MS_CDECL CC_BOOT__IIARRAY2UeltUD2IRU11(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V180, V181, V182, V183, V184;
    Lisp_Object fn;
    argcheck(nargs, 4, "IIARRAY2;elt;$2IR;11");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IIARRAY2;elt;$2IR;11|\n");
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
/* copy arguments values to proper place */
    stack[0] = V5;
    stack[-1] = V4;
    stack[-2] = V3;
    stack[-3] = V2;
/* end of prologue */
    stack[-4] = stack[-2];
    V181 = stack[0];
    V180 = (Lisp_Object)385; /* 24 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    env = stack[-5];
    V181 = V180;
    if (!car_legal(V181)) goto V191;
    V182 = qcar(V181);
    V181 = stack[-3];
    if (!car_legal(V180)) goto V192;
    V180 = qcdr(V180);
    V180 = Lapply2(nil, 3, V182, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    env = stack[-5];
    V180 = (Lisp_Object)lessp2(stack[-4], V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    V180 = V180 ? lisp_true : nil;
    env = stack[-5];
    if (!(V180 == nil)) goto V11;
    V181 = stack[0];
    V180 = (Lisp_Object)433; /* 27 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    env = stack[-5];
    V181 = V180;
    if (!car_legal(V181)) goto V191;
    V182 = qcar(V181);
    V181 = stack[-3];
    if (!car_legal(V180)) goto V192;
    V180 = qcdr(V180);
    V180 = Lapply2(nil, 3, V182, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    env = stack[-5];
    V181 = V180;
    V180 = stack[-2];
    V180 = (Lisp_Object)lessp2(V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    V180 = V180 ? lisp_true : nil;
    env = stack[-5];
    if (!(V180 == nil)) goto V11;
    stack[-4] = stack[-1];
    V181 = stack[0];
    V180 = (Lisp_Object)401; /* 25 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    env = stack[-5];
    V181 = V180;
    if (!car_legal(V181)) goto V191;
    V182 = qcar(V181);
    V181 = stack[-3];
    if (!car_legal(V180)) goto V192;
    V180 = qcdr(V180);
    V180 = Lapply2(nil, 3, V182, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    env = stack[-5];
    V180 = (Lisp_Object)lessp2(stack[-4], V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    V180 = V180 ? lisp_true : nil;
    env = stack[-5];
    if (!(V180 == nil)) goto V79;
    V181 = stack[0];
    V180 = (Lisp_Object)465; /* 29 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    env = stack[-5];
    V181 = V180;
    if (!car_legal(V181)) goto V191;
    V182 = qcar(V181);
    V181 = stack[-3];
    if (!car_legal(V180)) goto V192;
    V180 = qcdr(V180);
    V180 = Lapply2(nil, 3, V182, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    env = stack[-5];
    V181 = V180;
    V180 = stack[-1];
    V180 = (Lisp_Object)lessp2(V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    V180 = V180 ? lisp_true : nil;
    env = stack[-5];
    if (!(V180 == nil)) goto V79;
    V180 = lisp_true;
    if (V180 == nil) goto V148;
    V181 = stack[0];
    V180 = (Lisp_Object)481; /* 30 */
    V180 = Lgetv(nil, V181, V180);
    nil = C_nil;
    if (exception_pending()) goto V190;
    env = stack[-5];
    V181 = V180;
    if (!car_legal(V181)) goto V191;
    V184 = qcar(V181);
    V183 = stack[-3];
    V182 = stack[-2];
    V181 = stack[-1];
    if (!car_legal(V180)) goto V192;
    V180 = qcdr(V180);
    {
        popv(6);
        fn = elt(env, 2); /* FUNCALL* */
        return (*qfnn(fn))(qenv(fn), 5, V184, V183, V182, V181, V180);
    }

V148:
    V180 = nil;
    { popv(6); return onevalue(V180); }

V79:
    V180 = elt(env, 1); /* "elt: index out of range" */
    {
        popv(6);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V180);
    }

V11:
    V180 = elt(env, 1); /* "elt: index out of range" */
    {
        popv(6);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V180);
    }
/* error exit handlers */
V192:
    popv(6);
    return error(1, err_bad_cdr, V180);
V191:
    popv(6);
    return error(1, err_bad_car, V181);
V190:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|IIARRAY2;nrows;$Nni;8| (|m| |$|) (VMLISP:QVSIZE |m|))

*/



/* Code for BOOT::|IIARRAY2;nrows;$Nni;8| */

static Lisp_Object CC_BOOT__IIARRAY2UnrowsUDNniU8(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V9, V10;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IIARRAY2;nrows;$Nni;8|\n");
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
(DEFUN BOOT::|IIARRAY2;empty?;$B;1| (|m| |$|)
   (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 13)))

*/



/* Code for BOOT::|IIARRAY2;empty?;$B;1| */

static Lisp_Object CC_BOOT__IIARRAY2UemptyWUDBU1(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IIARRAY2;empty?;$B;1|\n");
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
    V31 = (Lisp_Object)209; /* 13 */
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
(DEFUN BOOT::|IIARRAY2;maxRowIndex;$I;6| (|m| |$|)
   (|-|
      (|+|
         (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 26))
         (VMLISP:QREFELT |$| 7))
      1))

*/



/* Code for BOOT::|IIARRAY2;maxRowIndex;$I;6| */

static Lisp_Object CC_BOOT__IIARRAY2UmaxRowIndexUDIU6(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V46, V47, V48;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IIARRAY2;maxRowIndex;$I;6|\n");
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
    V47 = stack[0];
    V46 = (Lisp_Object)417; /* 26 */
    V46 = Lgetv(nil, V47, V46);
    nil = C_nil;
    if (exception_pending()) goto V51;
    env = stack[-2];
    V47 = V46;
    if (!car_legal(V47)) goto V52;
    V48 = qcar(V47);
    V47 = stack[-1];
    if (!car_legal(V46)) goto V53;
    V46 = qcdr(V46);
    V46 = Lapply2(nil, 3, V48, V47, V46);
    nil = C_nil;
    if (exception_pending()) goto V51;
    env = stack[-2];
    stack[-1] = V46;
    V47 = stack[0];
    V46 = (Lisp_Object)113; /* 7 */
    V46 = Lgetv(nil, V47, V46);
    nil = C_nil;
    if (exception_pending()) goto V51;
    env = stack[-2];
    V46 = plus2(stack[-1], V46);
    nil = C_nil;
    if (exception_pending()) goto V51;
    popv(3);
    { Lisp_Object retVal = sub1(V46);
    errexit();
    return onevalue(retVal); }
/* error exit handlers */
V53:
    popv(3);
    return error(1, err_bad_cdr, V46);
V52:
    popv(3);
    return error(1, err_bad_car, V47);
V51:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|IIARRAY2;maxColIndex;$I;7| (|m| |$|)
   (|-|
      (|+|
         (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 28))
         (VMLISP:QREFELT |$| 8))
      1))

*/



/* Code for BOOT::|IIARRAY2;maxColIndex;$I;7| */

static Lisp_Object CC_BOOT__IIARRAY2UmaxColIndexUDIU7(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V46, V47, V48;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IIARRAY2;maxColIndex;$I;7|\n");
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
    V47 = stack[0];
    V46 = (Lisp_Object)449; /* 28 */
    V46 = Lgetv(nil, V47, V46);
    nil = C_nil;
    if (exception_pending()) goto V51;
    env = stack[-2];
    V47 = V46;
    if (!car_legal(V47)) goto V52;
    V48 = qcar(V47);
    V47 = stack[-1];
    if (!car_legal(V46)) goto V53;
    V46 = qcdr(V46);
    V46 = Lapply2(nil, 3, V48, V47, V46);
    nil = C_nil;
    if (exception_pending()) goto V51;
    env = stack[-2];
    stack[-1] = V46;
    V47 = stack[0];
    V46 = (Lisp_Object)129; /* 8 */
    V46 = Lgetv(nil, V47, V46);
    nil = C_nil;
    if (exception_pending()) goto V51;
    env = stack[-2];
    V46 = plus2(stack[-1], V46);
    nil = C_nil;
    if (exception_pending()) goto V51;
    popv(3);
    { Lisp_Object retVal = sub1(V46);
    errexit();
    return onevalue(retVal); }
/* error exit handlers */
V53:
    popv(3);
    return error(1, err_bad_cdr, V46);
V52:
    popv(3);
    return error(1, err_bad_car, V47);
V51:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|IIARRAY2;ncols;$Nni;9| (|m| |$|)
   (COND
      ((BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 14)) 0)
      ('T (VMLISP:QVSIZE (ELT |m| 0)))) )

*/



/* Code for BOOT::|IIARRAY2;ncols;$Nni;9| */

static Lisp_Object CC_BOOT__IIARRAY2UncolsUDNniU9(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V48, V49, V50;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IIARRAY2;ncols;$Nni;9|\n");
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
    V48 = V3;
    stack[0] = V2;
/* end of prologue */
    V49 = V48;
    V48 = (Lisp_Object)225; /* 14 */
    V48 = Lgetv(nil, V49, V48);
    nil = C_nil;
    if (exception_pending()) goto V52;
    env = stack[-1];
    V49 = V48;
    if (!car_legal(V49)) goto V53;
    V50 = qcar(V49);
    V49 = stack[0];
    if (!car_legal(V48)) goto V54;
    V48 = qcdr(V48);
    V48 = Lapply2(nil, 3, V50, V49, V48);
    nil = C_nil;
    if (exception_pending()) goto V52;
    env = stack[-1];
    if (V48 == nil) goto V10;
    V48 = (Lisp_Object)1; /* 0 */
    { popv(2); return onevalue(V48); }

V10:
    V48 = lisp_true;
    if (V48 == nil) goto V37;
    V49 = stack[0];
    V48 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* ELT */
    V48 = (*qfn2(fn))(qenv(fn), V49, V48);
    nil = C_nil;
    if (exception_pending()) goto V52;
        popv(2);
        return Llength(nil, V48);

V37:
    V48 = nil;
    { popv(2); return onevalue(V48); }
/* error exit handlers */
V54:
    popv(2);
    return error(1, err_bad_cdr, V48);
V53:
    popv(2);
    return error(1, err_bad_car, V49);
V52:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|IARRAY1;setelt;$I2S;17| (|x| |i| |s| |$|)
   (COND
      ((OR (VMLISP:QSLESSP |i| 1) (VMLISP:QSLESSP (VMLISP:QVSIZE |x|) |i|))
         (BOOT::|error| "index out of range"))
      ('T (SETELT |x| (|-| |i| 1) |s|))))

*/



/* Code for BOOT::|IARRAY1;setelt;$I2S;17| */

static Lisp_Object MS_CDECL CC_BOOT__IARRAY1UseteltUDI2SU17(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V49, V50;
    Lisp_Object fn;
    argcheck(nargs, 4, "IARRAY1;setelt;$I2S;17");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IARRAY1;setelt;$I2S;17|\n");
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
    V49 = V5;
    stack[0] = V4;
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    V50 = stack[-1];
    V49 = (Lisp_Object)17; /* 1 */
    V49 = (Lisp_Object)lessp2(V50, V49);
    nil = C_nil;
    if (exception_pending()) goto V54;
    V49 = V49 ? lisp_true : nil;
    env = stack[-3];
    if (!(V49 == nil)) goto V11;
    V49 = stack[-2];
    V50 = Llength(nil, V49);
    nil = C_nil;
    if (exception_pending()) goto V54;
    env = stack[-3];
    V49 = stack[-1];
    V49 = (Lisp_Object)lessp2(V50, V49);
    nil = C_nil;
    if (exception_pending()) goto V54;
    V49 = V49 ? lisp_true : nil;
    env = stack[-3];
    if (!(V49 == nil)) goto V11;
    V49 = lisp_true;
    if (V49 == nil) goto V35;
    V49 = stack[-1];
    V50 = sub1(V49);
    nil = C_nil;
    if (exception_pending()) goto V54;
    env = stack[-3];
    V49 = stack[0];
    {
        Lisp_Object V55 = stack[-2];
        popv(4);
        fn = elt(env, 2); /* SETELT */
        return (*qfnn(fn))(qenv(fn), 3, V55, V50, V49);
    }

V35:
    V49 = nil;
    { popv(4); return onevalue(V49); }

V11:
    V49 = elt(env, 1); /* "index out of range" */
    {
        popv(4);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V49);
    }
/* error exit handlers */
V54:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|IARRAY1;new;NniS$;5| (|n| |s| |$|)
   (BOOT:SPADCALL (VMLISP:GETREFV |n|) |s| (VMLISP:QREFELT |$| 10)))

*/



/* Code for BOOT::|IARRAY1;new;NniS$;5| */

static Lisp_Object MS_CDECL CC_BOOT__IARRAY1UnewUNniSDU5(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V36, V37, V38;
    Lisp_Object fn;
    argcheck(nargs, 3, "IARRAY1;new;NniS$;5");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IARRAY1;new;NniS$;5|\n");
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
    V36 = (Lisp_Object)161; /* 10 */
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
(DEFUN BOOT::|IARRAY1;qsetelt!;$I2S;15| (|x| |i| |s| |$|)
   (SETELT |x| (|-| |i| 1) |s|))

*/



/* Code for BOOT::|IARRAY1;qsetelt!;$I2S;15| */

static Lisp_Object MS_CDECL CC_BOOT__IARRAY1UqseteltBUDI2SU15(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V21, V22, V23;
    Lisp_Object fn;
    argcheck(nargs, 4, "IARRAY1;qsetelt!;$I2S;15");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IARRAY1;qsetelt!;$I2S;15|\n");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    V21 = V5;
    stack[0] = V4;
    V22 = V3;
    V23 = V2;
/* end of prologue */
    stack[-1] = V23;
    V21 = V22;
    V22 = sub1(V21);
    nil = C_nil;
    if (exception_pending()) goto V26;
    env = stack[-2];
    V21 = stack[0];
    {
        Lisp_Object V27 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* SETELT */
        return (*qfnn(fn))(qenv(fn), 3, V27, V22, V21);
    }
/* error exit handlers */
V26:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|IARRAY1;minIndex;$I;3| (|x| |$|) (VMLISP:QREFELT |$| 7))

*/



/* Code for BOOT::|IARRAY1;minIndex;$I;3| */

static Lisp_Object CC_BOOT__IARRAY1UminIndexUDIU3(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IARRAY1;minIndex;$I;3|\n");
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
(DEFUN BOOT::|IARRAY1;maxIndex;$I;13| (|x| |$|) (VMLISP:QVSIZE |x|))

*/



/* Code for BOOT::|IARRAY1;maxIndex;$I;13| */

static Lisp_Object CC_BOOT__IARRAY1UmaxIndexUDIU13(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V9, V10;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IARRAY1;maxIndex;$I;13|\n");
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
(DEFUN BOOT::|IARRAY1;#;$Nni;1| (|x| |$|) (VMLISP:QVSIZE |x|))

*/



/* Code for BOOT::|IARRAY1;#;$Nni;1| */

static Lisp_Object CC_BOOT__IARRAY1UZUDNniU1(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V9, V10;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IARRAY1;#;$Nni;1|\n");
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
(DEFUN BOOT::|AGG-;empty?;SB;3| (|a| |$|)
   (EQL (BOOT:SPADCALL |a| (VMLISP:QREFELT |$| 12)) 0))

*/



/* Code for BOOT::|AGG-;empty?;SB;3| */

static Lisp_Object CC_BOOT__AGGKUemptyWUSBU3(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V38, V39, V40;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|AGG-;empty?;SB;3|\n");
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
    V38 = (Lisp_Object)193; /* 12 */
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
    V38 = (Lisp_Object)1; /* 0 */
        popv(2);
        return Leql(nil, V39, V38);
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
(DEFUN BOOT::|STREAM;setfrst!| (|x| |s| |$|)
   (PROGN (RPLACA |x| |s|) (QCAR |x|)))

*/



/* Code for BOOT::|STREAM;setfrst!| */

static Lisp_Object MS_CDECL CC_BOOT__STREAMUsetfrstB(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V18, V19;
    argcheck(nargs, 3, "STREAM;setfrst!");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STREAM;setfrst!|\n");
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
    V19 = V4;
    V18 = V3;
    stack[0] = V2;
/* end of prologue */
    V19 = stack[0];
    V18 = Lrplaca(nil, V19, V18);
    nil = C_nil;
    if (exception_pending()) goto V21;
    V18 = stack[0];
    V18 = qcar(V18);
    { popv(1); return onevalue(V18); }
/* error exit handlers */
V21:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|STREAM;setrst!| (|x| |y| |$|)
   (PROGN (RPLACD |x| |y|) (QCDR |x|)))

*/



/* Code for BOOT::|STREAM;setrst!| */

static Lisp_Object MS_CDECL CC_BOOT__STREAMUsetrstB(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V18, V19;
    argcheck(nargs, 3, "STREAM;setrst!");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STREAM;setrst!|\n");
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
    V19 = V4;
    V18 = V3;
    stack[0] = V2;
/* end of prologue */
    V19 = stack[0];
    V18 = Lrplacd(nil, V19, V18);
    nil = C_nil;
    if (exception_pending()) goto V21;
    V18 = stack[0];
    V18 = qcdr(V18);
    { popv(1); return onevalue(V18); }
/* error exit handlers */
V21:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|STREAM;lazyEval| (|x| |$|)
   (BOOT:SPADCALL (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 14))))

*/



/* Code for BOOT::|STREAM;lazyEval| */

static Lisp_Object CC_BOOT__STREAMUlazyEval(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V44, V45, V46;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STREAM;lazyEval|\n");
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
    V44 = V3;
    stack[0] = V2;
/* end of prologue */
    V45 = V44;
    V44 = (Lisp_Object)225; /* 14 */
    V44 = Lgetv(nil, V45, V44);
    nil = C_nil;
    if (exception_pending()) goto V48;
    env = stack[-1];
    V45 = V44;
    if (!car_legal(V45)) goto V49;
    V46 = qcar(V45);
    V45 = stack[0];
    if (!car_legal(V44)) goto V50;
    V44 = qcdr(V44);
    V44 = Lapply2(nil, 3, V46, V45, V44);
    nil = C_nil;
    if (exception_pending()) goto V48;
    V45 = V44;
    if (!car_legal(V45)) goto V49;
    V45 = qcar(V45);
    if (!car_legal(V44)) goto V50;
    V44 = qcdr(V44);
        popv(2);
        return Lapply1(nil, V45, V44);
/* error exit handlers */
V50:
    popv(2);
    return error(1, err_bad_cdr, V44);
V49:
    popv(2);
    return error(1, err_bad_car, V45);
V48:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|STREAM;empty;$;33| (|$|) (CONS (VMLISP:QREFELT |$| 7) NIL))

*/



/* Code for BOOT::|STREAM;empty;$;33| */

static Lisp_Object CC_BOOT__STREAMUemptyUDU33(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STREAM;empty;$;33|\n");
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
    V15 = V2;
/* end of prologue */
    V16 = V15;
    V15 = (Lisp_Object)113; /* 7 */
    V15 = Lgetv(nil, V16, V15);
    errexit();
    { Lisp_Object retVal = ncons(V15);
    errexit();
    return onevalue(retVal); }
}

/*
(DEFUN BOOT::|PRTITION;<;2$B;5| (|x| |y| |$|)
   (COND
      ((NULL |x|) (COND ((NULL |y|) 'NIL) ('T 'T)))
      ((NULL |y|) 'NIL)
      ((EQL (BOOT::|SPADfirst| |x|) (BOOT::|SPADfirst| |y|))
         (BOOT:SPADCALL (CDR |x|) (CDR |y|) (VMLISP:QREFELT |$| 18)))
      ('T (|<| (BOOT::|SPADfirst| |x|) (BOOT::|SPADfirst| |y|)))) )

*/



/* Code for BOOT::|PRTITION;<;2$B;5| */

static Lisp_Object MS_CDECL CC_BOOT__PRTITIONURU2DBU5(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V121, V122, V123, V124;
    Lisp_Object fn;
    argcheck(nargs, 3, "PRTITION;<;2$B;5");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PRTITION;<;2$B;5|\n");
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
    V121 = stack[-2];
    if (V121 == nil) goto V10;
    V121 = stack[-1];
    if (V121 == nil) goto V23;
    V121 = stack[-2];
    V122 = V121;
    V121 = V122;
    if (V121 == nil) goto V42;
    V121 = V122;
    if (!car_legal(V121)) goto V129;
    V121 = qcar(V121);
    goto V40;

V40:
    stack[-3] = V121;
    V121 = stack[-1];
    V122 = V121;
    V121 = V122;
    if (V121 == nil) goto V54;
    V121 = V122;
    if (!car_legal(V121)) goto V129;
    V121 = qcar(V121);
    goto V33;

V33:
    V121 = Leql(nil, stack[-3], V121);
    env = stack[-4];
    if (V121 == nil) goto V28;
    V122 = stack[0];
    V121 = (Lisp_Object)289; /* 18 */
    V121 = Lgetv(nil, V122, V121);
    nil = C_nil;
    if (exception_pending()) goto V130;
    V122 = V121;
    if (!car_legal(V122)) goto V131;
    V124 = qcar(V122);
    V122 = stack[-2];
    if (!car_legal(V122)) goto V132;
    V123 = qcdr(V122);
    V122 = stack[-1];
    if (!car_legal(V122)) goto V132;
    V122 = qcdr(V122);
    if (!car_legal(V121)) goto V133;
    V121 = qcdr(V121);
        popv(5);
        return Lapply3(nil, 4, V124, V123, V122, V121);

V28:
    V121 = lisp_true;
    if (V121 == nil) goto V89;
    V121 = stack[-2];
    V122 = V121;
    V121 = V122;
    if (V121 == nil) goto V104;
    V121 = V122;
    if (!car_legal(V121)) goto V129;
    V121 = qcar(V121);
    goto V102;

V102:
    stack[0] = V121;
    V121 = stack[-1];
    V122 = V121;
    V121 = V122;
    if (V121 == nil) goto V116;
    V121 = V122;
    if (!car_legal(V121)) goto V129;
    V121 = qcar(V121);
    goto V95;

V95:
    {
        Lisp_Object V134 = stack[0];
        popv(5);
        return Llessp(nil, V134, V121);
    }

V116:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V130;
    goto V95;

V104:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V130;
    env = stack[-4];
    goto V102;

V89:
    V121 = nil;
    { popv(5); return onevalue(V121); }

V54:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V130;
    env = stack[-4];
    goto V33;

V42:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V121 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V130;
    env = stack[-4];
    goto V40;

V23:
    V121 = nil;
    { popv(5); return onevalue(V121); }

V10:
    V121 = stack[-1];
    if (V121 == nil) goto V15;
    V121 = lisp_true;
    if (V121 == nil) goto V20;
    V121 = lisp_true;
    { popv(5); return onevalue(V121); }

V20:
    V121 = nil;
    { popv(5); return onevalue(V121); }

V15:
    V121 = nil;
    { popv(5); return onevalue(V121); }
/* error exit handlers */
V133:
    popv(5);
    return error(1, err_bad_cdr, V121);
V132:
    popv(5);
    return error(1, err_bad_cdr, V122);
V131:
    popv(5);
    return error(1, err_bad_car, V122);
V130:
    popv(5);
    return nil;
V129:
    popv(5);
    return error(1, err_bad_car, V121);
}

/*
(DEFUN BOOT::|ILIST;minIndex;$I;18| (|x| |$|) (VMLISP:QREFELT |$| 7))

*/



/* Code for BOOT::|ILIST;minIndex;$I;18| */

static Lisp_Object CC_BOOT__ILISTUminIndexUDIU18(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;minIndex;$I;18|\n");
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
(DEFUN BOOT::|STREAM2;mapp!0| (BOOT::|$$|)
   (PROG (|x| |$| |f|)
      (BOOT::LETT |x| (VMLISP:QREFELT BOOT::|$$| 2) BOOT::|STREAM2;mapp|)
      (BOOT::LETT |$| (VMLISP:QREFELT BOOT::|$$| 1) BOOT::|STREAM2;mapp|)
      (BOOT::LETT |f| (VMLISP:QREFELT BOOT::|$$| 0) BOOT::|STREAM2;mapp|)
      (RETURN
         (PROGN
            (COND
               ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 10))
                  (BOOT:SPADCALL (VMLISP:QREFELT |$| 12)))
               ('T
                  (BOOT:SPADCALL
                     (BOOT:SPADCALL
                        (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 13))
                        |f|)
                     (BOOT:SPADCALL
                        |f|
                        (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 14))
                        (VMLISP:QREFELT |$| 16))
                     (VMLISP:QREFELT |$| 17)))) ))) )

*/



/* Code for BOOT::|STREAM2;mapp!0| */

static Lisp_Object CC_BOOT__STREAM2UmappB0(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V202, V203, V204;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STREAM2;mapp!0|\n");
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
    stack[0] = V2;
/* end of prologue */
    V203 = stack[0];
    V202 = (Lisp_Object)33; /* 2 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    stack[-7] = V202;
    V203 = stack[0];
    V202 = (Lisp_Object)17; /* 1 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    stack[-6] = V202;
    V203 = stack[0];
    V202 = (Lisp_Object)1; /* 0 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    stack[0] = V202;
    V203 = stack[-6];
    V202 = (Lisp_Object)161; /* 10 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    V203 = V202;
    if (!car_legal(V203)) goto V214;
    V204 = qcar(V203);
    V203 = stack[-7];
    if (!car_legal(V202)) goto V215;
    V202 = qcdr(V202);
    V202 = Lapply2(nil, 3, V204, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    if (V202 == nil) goto V38;
    V203 = stack[-6];
    V202 = (Lisp_Object)193; /* 12 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    V203 = V202;
    if (!car_legal(V203)) goto V214;
    V203 = qcar(V203);
    if (!car_legal(V202)) goto V215;
    V202 = qcdr(V202);
        popv(9);
        return Lapply1(nil, V203, V202);

V38:
    V202 = lisp_true;
    if (V202 == nil) goto V85;
    V203 = stack[-6];
    V202 = (Lisp_Object)273; /* 17 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    stack[-5] = V202;
    V202 = stack[-5];
    if (!car_legal(V202)) goto V216;
    stack[-4] = qcar(V202);
    V202 = stack[0];
    stack[-2] = V202;
    V202 = stack[-2];
    if (!car_legal(V202)) goto V216;
    stack[-1] = qcar(V202);
    V203 = stack[-6];
    V202 = (Lisp_Object)209; /* 13 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    V203 = V202;
    if (!car_legal(V203)) goto V214;
    V204 = qcar(V203);
    V203 = stack[-7];
    if (!car_legal(V202)) goto V215;
    V202 = qcdr(V202);
    V202 = Lapply2(nil, 3, V204, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    V203 = V202;
    V202 = stack[-2];
    if (!car_legal(V202)) goto V215;
    V202 = qcdr(V202);
    V202 = Lapply2(nil, 3, stack[-1], V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    stack[-3] = V202;
    V203 = stack[-6];
    V202 = (Lisp_Object)257; /* 16 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    stack[-2] = V202;
    V202 = stack[-2];
    if (!car_legal(V202)) goto V216;
    stack[-1] = qcar(V202);
    V203 = stack[-6];
    V202 = (Lisp_Object)225; /* 14 */
    V202 = Lgetv(nil, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    V203 = V202;
    if (!car_legal(V203)) goto V214;
    V204 = qcar(V203);
    V203 = stack[-7];
    if (!car_legal(V202)) goto V215;
    V202 = qcdr(V202);
    V202 = Lapply2(nil, 3, V204, V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    env = stack[-8];
    V203 = V202;
    V202 = stack[-2];
    if (!car_legal(V202)) goto V215;
    V202 = qcdr(V202);
    V202 = Lapply3(nil, 4, stack[-1], stack[0], V203, V202);
    nil = C_nil;
    if (exception_pending()) goto V213;
    V203 = V202;
    V202 = stack[-5];
    if (!car_legal(V202)) goto V215;
    V202 = qcdr(V202);
    {
        Lisp_Object V217 = stack[-4];
        Lisp_Object V218 = stack[-3];
        popv(9);
        return Lapply3(nil, 4, V217, V218, V203, V202);
    }

V85:
    V202 = nil;
    { popv(9); return onevalue(V202); }
/* error exit handlers */
V216:
    popv(9);
    return error(1, err_bad_car, V202);
V215:
    popv(9);
    return error(1, err_bad_cdr, V202);
V214:
    popv(9);
    return error(1, err_bad_car, V203);
V213:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|STREAM2;mapp| (|f| |x| |$|)
   (PROG NIL
      (RETURN
         (BOOT:SPADCALL
            (CONS (FUNCTION BOOT::|STREAM2;mapp!0|) (VECTOR |f| |$| |x|))
            (VMLISP:QREFELT |$| 19)))) )

*/



/* Code for BOOT::|STREAM2;mapp| */

static Lisp_Object MS_CDECL CC_BOOT__STREAM2Umapp(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V51, V52, V53;
    Lisp_Object fn;
    argcheck(nargs, 3, "STREAM2;mapp");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STREAM2;mapp|\n");
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
    V52 = stack[-2];
    V51 = (Lisp_Object)305; /* 19 */
    V51 = Lgetv(nil, V52, V51);
    nil = C_nil;
    if (exception_pending()) goto V60;
    env = stack[-6];
    stack[-5] = V51;
    V51 = stack[-5];
    if (!car_legal(V51)) goto V61;
    stack[-1] = qcar(V51);
    stack[0] = elt(env, 1); /* BOOT::|STREAM2;mapp!0| */
    V53 = stack[-4];
    V52 = stack[-2];
    V51 = stack[-3];
    fn = elt(env, 2); /* VECTOR */
    V51 = (*qfnn(fn))(qenv(fn), 3, V53, V52, V51);
    nil = C_nil;
    if (exception_pending()) goto V60;
    env = stack[-6];
    V52 = cons(stack[0], V51);
    nil = C_nil;
    if (exception_pending()) goto V60;
    V51 = stack[-5];
    if (!car_legal(V51)) goto V62;
    V51 = qcdr(V51);
    {
        Lisp_Object V63 = stack[-1];
        popv(7);
        return Lapply2(nil, 3, V63, V52, V51);
    }
/* error exit handlers */
V62:
    popv(7);
    return error(1, err_bad_cdr, V51);
V61:
    popv(7);
    return error(1, err_bad_car, V51);
V60:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|STREAM2;map;MSS;2| (|f| |x| |$|)
   (COND
      ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 20))
         (BOOT:SPADCALL (VMLISP:QREFELT |$| 12)))
      ((BOOT:SPADCALL
          |x|
          (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 14))
          (VMLISP:QREFELT |$| 21))
         (BOOT:SPADCALL
            (LIST
               (BOOT:SPADCALL
                  (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 13))
                  |f|))
            (VMLISP:QREFELT |$| 23)))
      ('T (BOOT::|STREAM2;mapp| |f| |x| |$|))))

*/



/* Code for BOOT::|STREAM2;map;MSS;2| */

static Lisp_Object MS_CDECL CC_BOOT__STREAM2UmapUMSSU2(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V187, V188, V189;
    Lisp_Object fn;
    argcheck(nargs, 3, "STREAM2;map;MSS;2");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STREAM2;map;MSS;2|\n");
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
    stack[-4] = V3;
    stack[0] = V2;
/* end of prologue */
    V188 = stack[-3];
    V187 = (Lisp_Object)321; /* 20 */
    V187 = Lgetv(nil, V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    env = stack[-6];
    V188 = V187;
    if (!car_legal(V188)) goto V197;
    V189 = qcar(V188);
    V188 = stack[-4];
    if (!car_legal(V187)) goto V198;
    V187 = qcdr(V187);
    V187 = Lapply2(nil, 3, V189, V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    env = stack[-6];
    if (V187 == nil) goto V63;
    V188 = stack[-3];
    V187 = (Lisp_Object)193; /* 12 */
    V187 = Lgetv(nil, V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    V188 = V187;
    if (!car_legal(V188)) goto V197;
    V188 = qcar(V188);
    if (!car_legal(V187)) goto V198;
    V187 = qcdr(V187);
        popv(7);
        return Lapply1(nil, V188, V187);

V63:
    V188 = stack[-3];
    V187 = (Lisp_Object)337; /* 21 */
    V187 = Lgetv(nil, V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    env = stack[-6];
    stack[-5] = V187;
    V187 = stack[-5];
    if (!car_legal(V187)) goto V199;
    stack[-2] = qcar(V187);
    stack[-1] = stack[-4];
    V188 = stack[-3];
    V187 = (Lisp_Object)225; /* 14 */
    V187 = Lgetv(nil, V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    env = stack[-6];
    V188 = V187;
    if (!car_legal(V188)) goto V197;
    V189 = qcar(V188);
    V188 = stack[-4];
    if (!car_legal(V187)) goto V198;
    V187 = qcdr(V187);
    V187 = Lapply2(nil, 3, V189, V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    env = stack[-6];
    V188 = V187;
    V187 = stack[-5];
    if (!car_legal(V187)) goto V198;
    V187 = qcdr(V187);
    V187 = Lapply3(nil, 4, stack[-2], stack[-1], V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    env = stack[-6];
    if (V187 == nil) goto V58;
    V188 = stack[-3];
    V187 = (Lisp_Object)369; /* 23 */
    V187 = Lgetv(nil, V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    env = stack[-6];
    stack[-5] = V187;
    V187 = stack[-5];
    if (!car_legal(V187)) goto V199;
    stack[-2] = qcar(V187);
    V187 = stack[0];
    stack[-1] = V187;
    V187 = stack[-1];
    if (!car_legal(V187)) goto V199;
    stack[0] = qcar(V187);
    V188 = stack[-3];
    V187 = (Lisp_Object)209; /* 13 */
    V187 = Lgetv(nil, V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    env = stack[-6];
    V188 = V187;
    if (!car_legal(V188)) goto V197;
    V189 = qcar(V188);
    V188 = stack[-4];
    if (!car_legal(V187)) goto V198;
    V187 = qcdr(V187);
    V187 = Lapply2(nil, 3, V189, V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    env = stack[-6];
    V188 = V187;
    V187 = stack[-1];
    if (!car_legal(V187)) goto V198;
    V187 = qcdr(V187);
    V187 = Lapply2(nil, 3, stack[0], V188, V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    env = stack[-6];
    V188 = ncons(V187);
    nil = C_nil;
    if (exception_pending()) goto V196;
    V187 = stack[-5];
    if (!car_legal(V187)) goto V198;
    V187 = qcdr(V187);
    {
        Lisp_Object V200 = stack[-2];
        popv(7);
        return Lapply2(nil, 3, V200, V188, V187);
    }

V58:
    V187 = lisp_true;
    if (V187 == nil) goto V174;
    V189 = stack[0];
    V188 = stack[-4];
    V187 = stack[-3];
    {
        popv(7);
        fn = elt(env, 1); /* BOOT::|STREAM2;mapp| */
        return (*qfnn(fn))(qenv(fn), 3, V189, V188, V187);
    }

V174:
    V187 = nil;
    { popv(7); return onevalue(V187); }
/* error exit handlers */
V199:
    popv(7);
    return error(1, err_bad_car, V187);
V198:
    popv(7);
    return error(1, err_bad_cdr, V187);
V197:
    popv(7);
    return error(1, err_bad_car, V188);
V196:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|STTAYLOR;+;3S;2| (|x| |y| |$|)
   (PROG NIL
      (RETURN
         (BOOT:SPADCALL
            (CONS
               (FUNCTION BOOT::|STTAYLOR;+;3S;2!2|)
               (VECTOR |x| |$| |y|))
            (VMLISP:QREFELT |$| 20)))) )

*/



/* Code for BOOT::|STTAYLOR;+;3S;2| */

static Lisp_Object MS_CDECL CC_BOOT__STTAYLORULU3SU2(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V51, V52, V53;
    Lisp_Object fn;
    argcheck(nargs, 3, "STTAYLOR;+;3S;2");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STTAYLOR;+;3S;2|\n");
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
    V52 = stack[-2];
    V51 = (Lisp_Object)321; /* 20 */
    V51 = Lgetv(nil, V52, V51);
    nil = C_nil;
    if (exception_pending()) goto V60;
    env = stack[-6];
    stack[-5] = V51;
    V51 = stack[-5];
    if (!car_legal(V51)) goto V61;
    stack[-1] = qcar(V51);
    stack[0] = elt(env, 1); /* BOOT::|STTAYLOR;+;3S;2!2| */
    V53 = stack[-4];
    V52 = stack[-2];
    V51 = stack[-3];
    fn = elt(env, 2); /* VECTOR */
    V51 = (*qfnn(fn))(qenv(fn), 3, V53, V52, V51);
    nil = C_nil;
    if (exception_pending()) goto V60;
    env = stack[-6];
    V52 = cons(stack[0], V51);
    nil = C_nil;
    if (exception_pending()) goto V60;
    V51 = stack[-5];
    if (!car_legal(V51)) goto V62;
    V51 = qcdr(V51);
    {
        Lisp_Object V63 = stack[-1];
        popv(7);
        return Lapply2(nil, 3, V63, V52, V51);
    }
/* error exit handlers */
V62:
    popv(7);
    return error(1, err_bad_cdr, V51);
V61:
    popv(7);
    return error(1, err_bad_car, V51);
V60:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|ZMOD;*;3$;30| (|x| |y| |$|)
   (BOOT::QSMULTMOD |x| |y| (VMLISP:QREFELT |$| 47)))

*/



/* Code for BOOT::|ZMOD;*;3$;30| */

static Lisp_Object MS_CDECL CC_BOOT__ZMODUHU3DU30(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V30, V31;
    Lisp_Object fn;
    argcheck(nargs, 3, "ZMOD;*;3$;30");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ZMOD;*;3$;30|\n");
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
    V30 = V3;
    V31 = V2;
/* end of prologue */
    stack[-1] = times2(V31, V30);
    nil = C_nil;
    if (exception_pending()) goto V34;
    env = stack[-2];
    V31 = stack[0];
    V30 = (Lisp_Object)753; /* 47 */
    V30 = Lgetv(nil, V31, V30);
    nil = C_nil;
    if (exception_pending()) goto V34;
    env = stack[-2];
    {
        Lisp_Object V35 = stack[-1];
        popv(3);
        fn = elt(env, 1); /* REM */
        return (*qfn2(fn))(qenv(fn), V35, V30);
    }
/* error exit handlers */
V34:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|ZMOD;+;3$;32| (|x| |y| |$|)
   (BOOT::QSADDMOD |x| |y| (VMLISP:QREFELT |$| 47)))

*/



/* Code for BOOT::|ZMOD;+;3$;32| */

static Lisp_Object MS_CDECL CC_BOOT__ZMODULU3DU32(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V45, V46;
    argcheck(nargs, 3, "ZMOD;+;3$;32");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ZMOD;+;3$;32|\n");
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
    stack[-1] = V4;
    V45 = V3;
    V46 = V2;
/* end of prologue */
    V45 = plus2(V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V50;
    env = stack[-3];
    stack[-2] = V45;
    stack[0] = stack[-2];
    V46 = stack[-1];
    V45 = (Lisp_Object)753; /* 47 */
    V45 = Lgetv(nil, V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V50;
    env = stack[-3];
    V45 = difference2(stack[0], V45);
    nil = C_nil;
    if (exception_pending()) goto V50;
    env = stack[-3];
    V46 = V45;
    V45 = V46;
    V45 = Lminusp(nil, V45);
    if (V45 == nil) { popv(4); return onevalue(V46); }
    else { Lisp_Object res = stack[-2]; popv(4); return onevalue(res); }
/* error exit handlers */
V50:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|ZMOD;-;3$;33| (|x| |y| |$|)
   (BOOT::QSDIFMOD |x| |y| (VMLISP:QREFELT |$| 47)))

*/



/* Code for BOOT::|ZMOD;-;3$;33| */

static Lisp_Object MS_CDECL CC_BOOT__ZMODUKU3DU33(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V41, V42;
    argcheck(nargs, 3, "ZMOD;-;3$;33");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ZMOD;-;3$;33|\n");
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
    V41 = V3;
    V42 = V2;
/* end of prologue */
    V41 = difference2(V42, V41);
    nil = C_nil;
    if (exception_pending()) goto V45;
    env = stack[-2];
    V42 = V41;
    V41 = V42;
    V41 = Lminusp(nil, V41);
    env = stack[-2];
    if (V41 == nil) { popv(3); return onevalue(V42); }
    stack[-1] = V42;
    V42 = stack[0];
    V41 = (Lisp_Object)753; /* 47 */
    V41 = Lgetv(nil, V42, V41);
    nil = C_nil;
    if (exception_pending()) goto V45;
    {
        Lisp_Object V46 = stack[-1];
        popv(3);
        { Lisp_Object retVal = plus2(V46, V41);
        errexit();
        return onevalue(retVal); }
    }
/* error exit handlers */
V45:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|ZMOD;-;2$;36| (|x| |$|)
   (COND
      ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 11))
         (BOOT::|spadConstant| |$| 23))
      ('T (VMLISP:QSDIFFERENCE (VMLISP:QREFELT |$| 47) |x|))))

*/



/* Code for BOOT::|ZMOD;-;2$;36| */

static Lisp_Object CC_BOOT__ZMODUKU2DU36(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V74, V75, V76;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ZMOD;-;2$;36|\n");
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
    V75 = stack[0];
    V74 = (Lisp_Object)177; /* 11 */
    V74 = Lgetv(nil, V75, V74);
    nil = C_nil;
    if (exception_pending()) goto V79;
    env = stack[-2];
    V75 = V74;
    if (!car_legal(V75)) goto V80;
    V76 = qcar(V75);
    V75 = stack[-1];
    if (!car_legal(V74)) goto V81;
    V74 = qcdr(V74);
    V74 = Lapply2(nil, 3, V76, V75, V74);
    nil = C_nil;
    if (exception_pending()) goto V79;
    env = stack[-2];
    if (V74 == nil) goto V10;
    V75 = stack[0];
    V74 = (Lisp_Object)369; /* 23 */
    V74 = Lgetv(nil, V75, V74);
    nil = C_nil;
    if (exception_pending()) goto V79;
    V75 = V74;
    if (!car_legal(V75)) goto V80;
    V75 = qcar(V75);
    if (!car_legal(V74)) goto V81;
    V74 = qcdr(V74);
        popv(3);
        return Lapply1(nil, V75, V74);

V10:
    V74 = lisp_true;
    if (V74 == nil) goto V57;
    V75 = stack[0];
    V74 = (Lisp_Object)753; /* 47 */
    V75 = Lgetv(nil, V75, V74);
    nil = C_nil;
    if (exception_pending()) goto V79;
    V74 = stack[-1];
    popv(3);
    { Lisp_Object retVal = difference2(V75, V74);
    errexit();
    return onevalue(retVal); }

V57:
    V74 = nil;
    { popv(3); return onevalue(V74); }
/* error exit handlers */
V81:
    popv(3);
    return error(1, err_bad_cdr, V74);
V80:
    popv(3);
    return error(1, err_bad_car, V75);
V79:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|FFP;*;3$;21| (|x| |y| |$|)
   (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 99)))

*/



/* Code for BOOT::|FFP;*;3$;21| */

static Lisp_Object MS_CDECL CC_BOOT__FFPUHU3DU21(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "FFP;*;3$;21");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FFP;*;3$;21|\n");
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
    V35 = (Lisp_Object)1585; /* 99 */
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
(DEFUN BOOT::|FFP;+;3$;22| (|x| |y| |$|)
   (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 100)))

*/



/* Code for BOOT::|FFP;+;3$;22| */

static Lisp_Object MS_CDECL CC_BOOT__FFPULU3DU22(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "FFP;+;3$;22");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FFP;+;3$;22|\n");
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
    V35 = (Lisp_Object)1601; /* 100 */
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
(DEFUN BOOT::|FFP;=;2$B;24| (|x| |y| |$|)
   (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 104)))

*/



/* Code for BOOT::|FFP;=;2$B;24| */

static Lisp_Object MS_CDECL CC_BOOT__FFPUMU2DBU24(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "FFP;=;2$B;24");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FFP;=;2$B;24|\n");
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
    V35 = (Lisp_Object)1665; /* 104 */
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
(DEFUN BOOT::|FFP;-;3$;23| (|x| |y| |$|)
   (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 102)))

*/



/* Code for BOOT::|FFP;-;3$;23| */

static Lisp_Object MS_CDECL CC_BOOT__FFPUKU3DU23(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "FFP;-;3$;23");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FFP;-;3$;23|\n");
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
    V35 = (Lisp_Object)1633; /* 102 */
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
(DEFUN BOOT::|SAE;reduce;UP$;11| (|p| |$|)
   (QCDR
      (BOOT:SPADCALL |p| (VMLISP:QREFELT |$| 8) (VMLISP:QREFELT |$| 60))))

*/



/* Code for BOOT::|SAE;reduce;UP$;11| */

static Lisp_Object CC_BOOT__SAEUreduceUUPDU11(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V42, V43;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SAE;reduce;UP$;11|\n");
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
    V43 = stack[-1];
    V42 = (Lisp_Object)961; /* 60 */
    V42 = Lgetv(nil, V43, V42);
    nil = C_nil;
    if (exception_pending()) goto V48;
    env = stack[-4];
    stack[-3] = V42;
    V42 = stack[-3];
    if (!car_legal(V42)) goto V49;
    stack[0] = qcar(V42);
    V43 = stack[-1];
    V42 = (Lisp_Object)129; /* 8 */
    V43 = Lgetv(nil, V43, V42);
    nil = C_nil;
    if (exception_pending()) goto V48;
    env = stack[-4];
    V42 = stack[-3];
    if (!car_legal(V42)) goto V50;
    V42 = qcdr(V42);
    V42 = Lapply3(nil, 4, stack[0], stack[-2], V43, V42);
    nil = C_nil;
    if (exception_pending()) goto V48;
    V42 = qcdr(V42);
    { popv(5); return onevalue(V42); }
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
(DEFUN BOOT::|SAE;*;3$;15| (|x| |y| |$|)
   (BOOT:SPADCALL
      (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 68))
      (VMLISP:QREFELT |$| 61)))

*/



/* Code for BOOT::|SAE;*;3$;15| */

static Lisp_Object MS_CDECL CC_BOOT__SAEUHU3DU15(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V58, V59, V60, V61;
    argcheck(nargs, 3, "SAE;*;3$;15");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SAE;*;3$;15|\n");
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
    V58 = (Lisp_Object)977; /* 61 */
    V58 = Lgetv(nil, V59, V58);
    nil = C_nil;
    if (exception_pending()) goto V67;
    env = stack[-5];
    stack[-4] = V58;
    V58 = stack[-4];
    if (!car_legal(V58)) goto V68;
    stack[0] = qcar(V58);
    V59 = stack[-1];
    V58 = (Lisp_Object)1089; /* 68 */
    V58 = Lgetv(nil, V59, V58);
    nil = C_nil;
    if (exception_pending()) goto V67;
    env = stack[-5];
    V59 = V58;
    if (!car_legal(V59)) goto V69;
    V61 = qcar(V59);
    V60 = stack[-3];
    V59 = stack[-2];
    if (!car_legal(V58)) goto V70;
    V58 = qcdr(V58);
    V58 = Lapply3(nil, 4, V61, V60, V59, V58);
    nil = C_nil;
    if (exception_pending()) goto V67;
    V59 = V58;
    V58 = stack[-4];
    if (!car_legal(V58)) goto V70;
    V58 = qcdr(V58);
    {
        Lisp_Object V71 = stack[0];
        popv(6);
        return Lapply2(nil, 3, V71, V59, V58);
    }
/* error exit handlers */
V70:
    popv(6);
    return error(1, err_bad_cdr, V58);
V69:
    popv(6);
    return error(1, err_bad_car, V59);
V68:
    popv(6);
    return error(1, err_bad_car, V58);
V67:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|SAE;+;3$;13| (|x| |y| |$|)
   (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 64)))

*/



/* Code for BOOT::|SAE;+;3$;13| */

static Lisp_Object MS_CDECL CC_BOOT__SAEULU3DU13(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "SAE;+;3$;13");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SAE;+;3$;13|\n");
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
    V35 = (Lisp_Object)1025; /* 64 */
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
(DEFUN BOOT::|SAE;=;2$B;12| (|x| |y| |$|)
   (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 62)))

*/



/* Code for BOOT::|SAE;=;2$B;12| */

static Lisp_Object MS_CDECL CC_BOOT__SAEUMU2DBU12(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "SAE;=;2$B;12");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SAE;=;2$B;12|\n");
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
    V35 = (Lisp_Object)993; /* 62 */
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
(DEFUN BOOT::|SAE;-;2$;14| (|x| |$|)
   (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 66)))

*/



/* Code for BOOT::|SAE;-;2$;14| */

static Lisp_Object CC_BOOT__SAEUKU2DU14(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SAE;-;2$;14|\n");
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
    V31 = (Lisp_Object)1057; /* 66 */
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
(DEFUN BOOT::|SUP;monicDivide;2$R;36| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (|n| |u| #:G113087 BOOT::|rout|)
      (RETURN
         (SEQ
            (COND
               ((NULL BOOT::|p2|)
                  (BOOT::|error| "monicDivide: division by 0"))
               ((NULL
                   (BOOT:SPADCALL
                      (BOOT:SPADCALL BOOT::|p2| (VMLISP:QREFELT |$| 54))
                      (BOOT::|spadConstant| |$| 26)
                      (VMLISP:QREFELT |$| 45)))
                  (BOOT::|error| "Divisor Not Monic"))
               ('T
                  (COND
                     ((BOOT:SPADCALL
                         BOOT::|p2|
                         (BOOT::|spadConstant| |$| 18)
                         (VMLISP:QREFELT |$| 98))
                        (CONS BOOT::|p1| (BOOT::|spadConstant| |$| 17)))
                     ((NULL BOOT::|p1|)
                        (CONS
                           (BOOT::|spadConstant| |$| 17)
                           (BOOT::|spadConstant| |$| 17)))
                     ('T
                        (COND
                           ((|<|
                               (BOOT:SPADCALL
                                  BOOT::|p1|
                                  (VMLISP:QREFELT |$| 56))
                               (BOOT::LETT
                                  |n|
                                  (BOOT:SPADCALL
                                     BOOT::|p2|
                                     (VMLISP:QREFELT |$| 56))
                                  BOOT::|SUP;monicDivide;2$R;36|))
                              (CONS
                                 (BOOT::|spadConstant| |$| 17)
                                 BOOT::|p1|))
                           ('T
                              (SEQ
                                 (BOOT::LETT
                                    BOOT::|rout|
                                    NIL
                                    BOOT::|SUP;monicDivide;2$R;36|)
                                 (BOOT::LETT
                                    BOOT::|p2|
                                    (CDR BOOT::|p2|)
                                    BOOT::|SUP;monicDivide;2$R;36|)
                                 (SEQ
                                    (EXIT
                                       (SEQ
                                          BOOT::G190
                                          (COND
                                             ((NULL
                                                 (COND
                                                    ((NULL BOOT::|p1|)
                                                       'NIL)
                                                    ('T 'T)))
                                                (GO BOOT::G191)))
                                          (SEQ
                                             (BOOT::LETT
                                                |u|
                                                (BOOT:SPADCALL
                                                   (QCAR
        (BOOT::|SPADfirst| BOOT::|p1|))
                                                   |n|
                                                   (VMLISP:QREFELT |$| 39))
                                          BOOT::|SUP;monicDivide;2$R;36|)
                                             (EXIT
                                                (COND
                                                   ((BOOT::QEQCAR |u| 1)
        (PROGN
        (BOOT::LETT
           #:G113087 BOOT:|$NoValue| BOOT::|SUP;monicDivide;2$R;36|)
        (GO #:G113087)))
                                                   ('T
        (SEQ
        (BOOT::LETT
           BOOT::|rout|
           (CONS
     (CONS (QCDR |u|) (QCDR (BOOT::|SPADfirst| BOOT::|p1|))) BOOT::|rout|)
           BOOT::|SUP;monicDivide;2$R;36|)
        (EXIT
           (BOOT::LETT
              BOOT::|p1|
              (BOOT:SPADCALL
              (CDR BOOT::|p1|)
           (QCAR (BOOT::|SPADfirst| BOOT::|rout|))
        (QCDR (BOOT::|SPADfirst| BOOT::|rout|))
                 BOOT::|p2|
                 (VMLISP:QREFELT |$| 100))
              BOOT::|SUP;monicDivide;2$R;36|)))) )))
                                          NIL
                                          (GO BOOT::G190)
                                          BOOT::G191
                                          (EXIT NIL)))
                                    #:G113087
                                    (EXIT #:G113087))
                                 (EXIT
                  (CONS (NREVERSE BOOT::|rout|) BOOT::|p1|)))) ))) ))) )))

*/



/* Code for BOOT::|SUP;monicDivide;2$R;36| */

static Lisp_Object MS_CDECL CC_BOOT__SUPUmonicDivideU2DRU36(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V508, V509, V510;
    Lisp_Object fn;
    argcheck(nargs, 3, "SUP;monicDivide;2$R;36");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SUP;monicDivide;2$R;36|\n");
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
    stack[-6] = V3;
    stack[0] = V2;
/* end of prologue */
    V508 = stack[-6];
    if (V508 == nil) goto V18;
    V509 = stack[-5];
    V508 = (Lisp_Object)721; /* 45 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    stack[-3] = V508;
    V508 = stack[-3];
    if (!car_legal(V508)) goto V520;
    stack[-2] = qcar(V508);
    V509 = stack[-5];
    V508 = (Lisp_Object)865; /* 54 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    if (!car_legal(V509)) goto V521;
    V510 = qcar(V509);
    V509 = stack[-6];
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply2(nil, 3, V510, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    stack[-1] = V508;
    V509 = stack[-5];
    V508 = (Lisp_Object)417; /* 26 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    if (!car_legal(V509)) goto V521;
    V509 = qcar(V509);
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply1(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    V508 = stack[-3];
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply3(nil, 4, stack[-2], stack[-1], V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    if (V508 == nil) goto V23;
    V508 = lisp_true;
    if (V508 == nil) goto V98;
    V509 = stack[-5];
    V508 = (Lisp_Object)1569; /* 98 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    stack[-3] = V508;
    V508 = stack[-3];
    if (!car_legal(V508)) goto V520;
    stack[-2] = qcar(V508);
    stack[-1] = stack[-6];
    V509 = stack[-5];
    V508 = (Lisp_Object)289; /* 18 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    if (!car_legal(V509)) goto V521;
    V509 = qcar(V509);
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply1(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    V508 = stack[-3];
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply3(nil, 4, stack[-2], stack[-1], V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    if (V508 == nil) goto V103;
    V509 = stack[-5];
    V508 = (Lisp_Object)273; /* 17 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    if (!car_legal(V509)) goto V521;
    V509 = qcar(V509);
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply1(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    {
        Lisp_Object V523 = stack[0];
        popv(9);
        { Lisp_Object retVal = cons(V523, V508);
        errexit();
        return onevalue(retVal); }
    }

V103:
    V508 = stack[0];
    if (V508 == nil) goto V192;
    V508 = lisp_true;
    if (V508 == nil) goto V231;
    V509 = stack[-5];
    V508 = (Lisp_Object)897; /* 56 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    if (!car_legal(V509)) goto V521;
    V510 = qcar(V509);
    V509 = stack[0];
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply2(nil, 3, V510, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    stack[-1] = V508;
    V509 = stack[-5];
    V508 = (Lisp_Object)897; /* 56 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    if (!car_legal(V509)) goto V521;
    V510 = qcar(V509);
    V509 = stack[-6];
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply2(nil, 3, V510, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    stack[-7] = V508;
    V508 = (Lisp_Object)lessp2(stack[-1], V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    V508 = V508 ? lisp_true : nil;
    env = stack[-8];
    if (V508 == nil) goto V236;
    V509 = stack[-5];
    V508 = (Lisp_Object)273; /* 17 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    if (!car_legal(V509)) goto V521;
    V509 = qcar(V509);
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply1(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    V509 = V508;
    V508 = stack[0];
    popv(9);
    { Lisp_Object retVal = cons(V509, V508);
    errexit();
    return onevalue(retVal); }

V236:
    V508 = lisp_true;
    if (V508 == nil) goto V320;
    V508 = nil;
    stack[-4] = V508;
    V508 = stack[-6];
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    stack[-6] = V508;
    goto V332;

V332:
    V508 = stack[0];
    if (V508 == nil) goto V340;
    V508 = lisp_true;
    if (V508 == nil) goto V345;
    V508 = lisp_true;
    goto V339;

V339:
    if (V508 == nil) goto V498;
    V509 = stack[-5];
    V508 = (Lisp_Object)625; /* 39 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    stack[-2] = V508;
    V508 = stack[-2];
    if (!car_legal(V508)) goto V520;
    stack[-1] = qcar(V508);
    V508 = stack[0];
    V509 = V508;
    V508 = V509;
    if (V508 == nil) goto V380;
    V508 = V509;
    if (!car_legal(V508)) goto V520;
    V508 = qcar(V508);
    goto V375;

V375:
    V510 = qcar(V508);
    V509 = stack[-7];
    V508 = stack[-2];
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply3(nil, 4, stack[-1], V510, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V510 = V508;
    V508 = V510;
    V509 = qcar(V508);
    V508 = (Lisp_Object)17; /* 1 */
    V508 = Leql(nil, V509, V508);
    env = stack[-8];
    if (!(V508 == nil)) goto V498;
    V508 = lisp_true;
    if (V508 == nil) goto V332;
    V508 = V510;
    stack[-1] = qcdr(V508);
    V508 = stack[0];
    V509 = V508;
    V508 = V509;
    if (V508 == nil) goto V425;
    V508 = V509;
    if (!car_legal(V508)) goto V520;
    V508 = qcar(V508);
    goto V420;

V420:
    V509 = qcdr(V508);
    V508 = stack[-4];
    V508 = acons(stack[-1], V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    stack[-4] = V508;
    V509 = stack[-5];
    V508 = (Lisp_Object)1601; /* 100 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    stack[-3] = V508;
    V508 = stack[-3];
    if (!car_legal(V508)) goto V520;
    stack[-2] = qcar(V508);
    V508 = stack[0];
    if (!car_legal(V508)) goto V522;
    stack[-1] = qcdr(V508);
    V508 = stack[-4];
    V509 = V508;
    V508 = V509;
    if (V508 == nil) goto V468;
    V508 = V509;
    if (!car_legal(V508)) goto V520;
    V508 = qcar(V508);
    goto V463;

V463:
    stack[0] = qcar(V508);
    V508 = stack[-4];
    V509 = V508;
    V508 = V509;
    if (V508 == nil) goto V481;
    V508 = V509;
    if (!car_legal(V508)) goto V520;
    V508 = qcar(V508);
    goto V476;

V476:
    V510 = qcdr(V508);
    V509 = stack[-6];
    V508 = stack[-3];
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    fn = elt(env, 4); /* FUNCALL* */
    V508 = (*qfnn(fn))(qenv(fn), 6, stack[-2], stack[-1], stack[0], V510, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    stack[0] = V508;
    goto V332;

V481:
    fn = elt(env, 5); /* BOOT::FIRST-ERROR */
    V508 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    goto V476;

V468:
    fn = elt(env, 5); /* BOOT::FIRST-ERROR */
    V508 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    goto V463;

V425:
    fn = elt(env, 5); /* BOOT::FIRST-ERROR */
    V508 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    goto V420;

V498:
    V508 = stack[-4];
    fn = elt(env, 6); /* NREVERSE */
    V509 = (*qfn1(fn))(qenv(fn), V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    V508 = stack[0];
    popv(9);
    { Lisp_Object retVal = cons(V509, V508);
    errexit();
    return onevalue(retVal); }

V380:
    fn = elt(env, 5); /* BOOT::FIRST-ERROR */
    V508 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    goto V375;

V345:
    V508 = nil;
    goto V339;

V340:
    V508 = nil;
    goto V339;

V320:
    V508 = nil;
    { popv(9); return onevalue(V508); }

V231:
    V508 = nil;
    { popv(9); return onevalue(V508); }

V192:
    V509 = stack[-5];
    V508 = (Lisp_Object)273; /* 17 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    if (!car_legal(V509)) goto V521;
    V509 = qcar(V509);
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply1(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    stack[0] = V508;
    V509 = stack[-5];
    V508 = (Lisp_Object)273; /* 17 */
    V508 = Lgetv(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    env = stack[-8];
    V509 = V508;
    if (!car_legal(V509)) goto V521;
    V509 = qcar(V509);
    if (!car_legal(V508)) goto V522;
    V508 = qcdr(V508);
    V508 = Lapply1(nil, V509, V508);
    nil = C_nil;
    if (exception_pending()) goto V519;
    {
        Lisp_Object V524 = stack[0];
        popv(9);
        { Lisp_Object retVal = cons(V524, V508);
        errexit();
        return onevalue(retVal); }
    }

V98:
    V508 = nil;
    { popv(9); return onevalue(V508); }

V23:
    V508 = elt(env, 2); /* "Divisor Not Monic" */
    {
        popv(9);
        fn = elt(env, 7); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V508);
    }

V18:
    V508 = elt(env, 1); /* "monicDivide: division by 0" */
    {
        popv(9);
        fn = elt(env, 7); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V508);
    }
/* error exit handlers */
V522:
    popv(9);
    return error(1, err_bad_cdr, V508);
V521:
    popv(9);
    return error(1, err_bad_car, V509);
V520:
    popv(9);
    return error(1, err_bad_car, V508);
V519:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|ABELMON-;zero?;SB;1| (|x| |$|)
   (BOOT:SPADCALL |x| (BOOT::|spadConstant| |$| 7) (VMLISP:QREFELT |$| 9)))

*/



/* Code for BOOT::|ABELMON-;zero?;SB;1| */

static Lisp_Object CC_BOOT__ABELMONKUzeroWUSBU1(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V54, V55;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ABELMON-;zero?;SB;1|\n");
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
(DEFUN BOOT::|ABELGRP-;-;3S;1| (|x| |y| |$|)
   (BOOT:SPADCALL
      |x|
      (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 7))
      (VMLISP:QREFELT |$| 8)))

*/



/* Code for BOOT::|ABELGRP-;-;3S;1| */

static Lisp_Object MS_CDECL CC_BOOT__ABELGRPKUKU3SU1(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V58, V59, V60;
    argcheck(nargs, 3, "ABELGRP-;-;3S;1");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ABELGRP-;-;3S;1|\n");
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
    V58 = (Lisp_Object)129; /* 8 */
    V58 = Lgetv(nil, V59, V58);
    nil = C_nil;
    if (exception_pending()) goto V66;
    env = stack[-5];
    stack[-4] = V58;
    V58 = stack[-4];
    if (!car_legal(V58)) goto V67;
    stack[0] = qcar(V58);
    V59 = stack[-1];
    V58 = (Lisp_Object)113; /* 7 */
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
(DEFUN BOOT::|MATCAT-;*;S2Col;32| (|x| |v| |$|)
   (PROG (|w| |k| #:G82630 |i| #:G82629 |l| #:G82632 |j| #:G82631
         BOOT::|sum|)
      (RETURN
         (SEQ
            (COND
               ((NULL
                   (EQL
                      (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 12))
                      (BOOT:SPADCALL |v| (VMLISP:QREFELT |$| 41))))
                  (BOOT::|error|
                  "can't multiply matrix A and vector v if #cols A ^= #v"))
               ('T
                  (SEQ
                     (BOOT::LETT
                        |w|
                        (BOOT:SPADCALL
                           (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 11))
                           (BOOT::|spadConstant| |$| 29)
                           (VMLISP:QREFELT |$| 79))
                        BOOT::|MATCAT-;*;S2Col;32|)
                     (SEQ
                        (BOOT::LETT
                           |k|
                           (BOOT:SPADCALL |w| (VMLISP:QREFELT |$| 42))
                           BOOT::|MATCAT-;*;S2Col;32|)
                        (BOOT::LETT
                           #:G82630
                           (BOOT:SPADCALL |w| (VMLISP:QREFELT |$| 43))
                           BOOT::|MATCAT-;*;S2Col;32|)
                        (BOOT::LETT
                           |i|
                           (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 17))
                           BOOT::|MATCAT-;*;S2Col;32|)
                        (BOOT::LETT
                           #:G82629
                           (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 18))
                           BOOT::|MATCAT-;*;S2Col;32|)
                        BOOT::G190
                        (COND
                           ((OR (|>| |i| #:G82629) (|>| |k| #:G82630))
                              (GO BOOT::G191)))
                        (SEQ
                           (EXIT
                              (BOOT:SPADCALL
                                 |w|
                                 |k|
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|sum|
                                       (BOOT::|spadConstant| |$| 29)
                                       BOOT::|MATCAT-;*;S2Col;32|)
                                    (SEQ
                                       (BOOT::LETT
                                          |l|
                                          (BOOT:SPADCALL
                                             |v|
                                             (VMLISP:QREFELT |$| 42))
                                          BOOT::|MATCAT-;*;S2Col;32|)
                                       (BOOT::LETT
                                          #:G82632
                                          (BOOT:SPADCALL
                                             |v|
                                             (VMLISP:QREFELT |$| 43))
                                          BOOT::|MATCAT-;*;S2Col;32|)
                                       (BOOT::LETT
                                          |j|
                                          (BOOT:SPADCALL
                                             |x|
                                             (VMLISP:QREFELT |$| 19))
                                          BOOT::|MATCAT-;*;S2Col;32|)
                                       (BOOT::LETT
                                          #:G82631
                                          (BOOT:SPADCALL
                                             |x|
                                             (VMLISP:QREFELT |$| 20))
                                          BOOT::|MATCAT-;*;S2Col;32|)
                                       BOOT::G190
                                       (COND
                                          ((OR
                                              (|>| |j| #:G82631)
                                              (|>| |l| #:G82632))
                                             (GO BOOT::G191)))
                                       (SEQ
                                          (EXIT
                                             (BOOT::LETT
                                                BOOT::|sum|
                                                (BOOT:SPADCALL
                                                   BOOT::|sum|
                                                   (BOOT:SPADCALL
        (BOOT:SPADCALL |x| |i| |j| (VMLISP:QREFELT |$| 21))
        (BOOT:SPADCALL |v| |l| (VMLISP:QREFELT |$| 80))
        (VMLISP:QREFELT |$| 70))
                                                   (VMLISP:QREFELT |$| 63))
                                             BOOT::|MATCAT-;*;S2Col;32|)))
                                       (BOOT::LETT
                                          |j|
                                          (PROG1
                                             (|+| |j| 1)
                                             (BOOT::LETT
                                                |l|
                                                (|+| |l| 1)
                                             BOOT::|MATCAT-;*;S2Col;32|))
                                          BOOT::|MATCAT-;*;S2Col;32|)
                                       (GO BOOT::G190)
                                       BOOT::G191
                                       (EXIT NIL))
                                    (EXIT BOOT::|sum|))
                                 (VMLISP:QREFELT |$| 81))))
                        (BOOT::LETT
                           |i|
                           (PROG1
                              (|+| |i| 1)
                              (BOOT::LETT
                                 |k|
                                 (|+| |k| 1)
                                 BOOT::|MATCAT-;*;S2Col;32|))
                           BOOT::|MATCAT-;*;S2Col;32|)
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT NIL))
                     (EXIT |w|)))) ))) )

*/



/* Code for BOOT::|MATCAT-;*;S2Col;32| */

static Lisp_Object MS_CDECL CC_BOOT__MATCATKUHUS2ColU32(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V594, V595, V596, V597, V598;
    Lisp_Object fn;
    argcheck(nargs, 3, "MATCAT-;*;S2Col;32");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|MATCAT-;*;S2Col;32|\n");
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
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-18] = V4;
    stack[-19] = V3;
    stack[-20] = V2;
/* end of prologue */
    V595 = stack[-18];
    V594 = (Lisp_Object)193; /* 12 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-20];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[0] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)657; /* 41 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-19];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V594 = Leql(nil, stack[0], V594);
    env = stack[-22];
    if (V594 == nil) goto V24;
    V594 = lisp_true;
    if (V594 == nil) goto V83;
    V595 = stack[-18];
    V594 = (Lisp_Object)1265; /* 79 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-2] = V594;
    V594 = stack[-2];
    if (!car_legal(V594)) goto V624;
    stack[-1] = qcar(V594);
    V595 = stack[-18];
    V594 = (Lisp_Object)177; /* 11 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-20];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[0] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)465; /* 29 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V595 = qcar(V595);
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply1(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    V594 = stack[-2];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply3(nil, 4, stack[-1], stack[0], V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-21] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)673; /* 42 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-21];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-17] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)689; /* 43 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-21];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-16] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)273; /* 17 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-20];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-15] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)289; /* 18 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-20];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-14] = V594;
    goto V263;

V263:
    V595 = stack[-15];
    V594 = stack[-14];
    V594 = (Lisp_Object)greaterp2(V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    V594 = V594 ? lisp_true : nil;
    env = stack[-22];
    if (!(V594 == nil)) { Lisp_Object res = stack[-21]; popv(23); return onevalue(res); }
    V595 = stack[-17];
    V594 = stack[-16];
    V594 = (Lisp_Object)greaterp2(V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    V594 = V594 ? lisp_true : nil;
    env = stack[-22];
    if (!(V594 == nil)) { Lisp_Object res = stack[-21]; popv(23); return onevalue(res); }
    V595 = stack[-18];
    V594 = (Lisp_Object)1297; /* 81 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-9] = V594;
    V594 = stack[-9];
    if (!car_legal(V594)) goto V624;
    stack[-8] = qcar(V594);
    stack[-7] = stack[-21];
    stack[-6] = stack[-17];
    V595 = stack[-18];
    V594 = (Lisp_Object)465; /* 29 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V595 = qcar(V595);
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply1(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[0] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)673; /* 42 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-19];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-13] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)689; /* 43 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-19];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-12] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)305; /* 19 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-20];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-11] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)321; /* 20 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V596 = qcar(V595);
    V595 = stack[-20];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply2(nil, 3, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-10] = V594;
    goto V437;

V437:
    V595 = stack[-11];
    V594 = stack[-10];
    V594 = (Lisp_Object)greaterp2(V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    V594 = V594 ? lisp_true : nil;
    env = stack[-22];
    if (!(V594 == nil)) goto V332;
    V595 = stack[-13];
    V594 = stack[-12];
    V594 = (Lisp_Object)greaterp2(V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    V594 = V594 ? lisp_true : nil;
    env = stack[-22];
    if (!(V594 == nil)) goto V332;
    V595 = stack[-18];
    V594 = (Lisp_Object)1009; /* 63 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-5] = V594;
    V594 = stack[-5];
    if (!car_legal(V594)) goto V624;
    stack[-4] = qcar(V594);
    stack[-3] = stack[0];
    V595 = stack[-18];
    V594 = (Lisp_Object)1121; /* 70 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-2] = V594;
    V594 = stack[-2];
    if (!car_legal(V594)) goto V624;
    stack[-1] = qcar(V594);
    V595 = stack[-18];
    V594 = (Lisp_Object)337; /* 21 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V598 = qcar(V595);
    V597 = stack[-20];
    V596 = stack[-15];
    V595 = stack[-11];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    fn = elt(env, 2); /* FUNCALL* */
    V594 = (*qfnn(fn))(qenv(fn), 5, V598, V597, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[0] = V594;
    V595 = stack[-18];
    V594 = (Lisp_Object)1281; /* 80 */
    V594 = Lgetv(nil, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    if (!car_legal(V595)) goto V622;
    V597 = qcar(V595);
    V596 = stack[-19];
    V595 = stack[-13];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply3(nil, 4, V597, V596, V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    V594 = stack[-2];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply3(nil, 4, stack[-1], stack[0], V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V595 = V594;
    V594 = stack[-5];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    V594 = Lapply3(nil, 4, stack[-4], stack[-3], V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[0] = V594;
    V594 = stack[-11];
    V594 = add1(V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-1] = V594;
    V594 = stack[-13];
    V594 = add1(V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-13] = V594;
    V594 = stack[-1];
    stack[-11] = V594;
    goto V437;

V332:
    V594 = stack[0];
    V595 = V594;
    V594 = stack[-9];
    if (!car_legal(V594)) goto V623;
    V594 = qcdr(V594);
    fn = elt(env, 2); /* FUNCALL* */
    V594 = (*qfnn(fn))(qenv(fn), 5, stack[-8], stack[-7], stack[-6], V595, V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    V594 = stack[-15];
    V594 = add1(V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[0] = V594;
    V594 = stack[-17];
    V594 = add1(V594);
    nil = C_nil;
    if (exception_pending()) goto V621;
    env = stack[-22];
    stack[-17] = V594;
    V594 = stack[0];
    stack[-15] = V594;
    goto V263;

V83:
    V594 = nil;
    { popv(23); return onevalue(V594); }

V24:
    V594 = elt(env, 1); /* "can't multiply matrix A and vector v if #cols A ^= #v" */
    {
        popv(23);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V594);
    }
/* error exit handlers */
V624:
    popv(23);
    return error(1, err_bad_car, V594);
V623:
    popv(23);
    return error(1, err_bad_cdr, V594);
V622:
    popv(23);
    return error(1, err_bad_car, V595);
V621:
    popv(23);
    return nil;
}



setup_type const u01_setup[] =
{
    {"BOOT@@SUP;pomopo!;$RNni2$;13@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__SUPUpomopoBUDRNni2DU13},
    {"BOOT@@OVAR;<;2$B;10@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__OVARURU2DBU10},
    {"BOOT@@NSMP;mvar;$VarSet;5@@Builtin",too_few_2,CC_BOOT__NSMPUmvarUDVarSetU5,wrong_no_2},
    {"BOOT@@SUP;ground?;$B;7@@Builtin",too_few_2,CC_BOOT__SUPUgroundWUDBU7,wrong_no_2},
    {"BOOT@@PR;addm!@@Builtin", wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__PRUaddmB},
    {"BOOT@@SMP;+;3$;27@@Builtin",wrong_no_na,  wrong_no_nb,   (n_args *)CC_BOOT__SMPULU3DU27},
    {"BOOT@@PR;times!0@@Builtin",too_few_2,     CC_BOOT__PRUtimesB0,wrong_no_2},
    {"BOOT@@PR;termTimes@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__PRUtermTimes},
    {"BOOT@@IIARRAY2;qsetelt!;$2I2R;12@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IIARRAY2UqseteltBUD2I2RU12},
    {"BOOT@@IIARRAY2;elt;$2IR;11@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IIARRAY2UeltUD2IRU11},
    {"BOOT@@IIARRAY2;nrows;$Nni;8@@Builtin",too_few_2,CC_BOOT__IIARRAY2UnrowsUDNniU8,wrong_no_2},
    {"BOOT@@IIARRAY2;empty?;$B;1@@Builtin",too_few_2,CC_BOOT__IIARRAY2UemptyWUDBU1,wrong_no_2},
    {"BOOT@@IIARRAY2;maxRowIndex;$I;6@@Builtin",too_few_2,CC_BOOT__IIARRAY2UmaxRowIndexUDIU6,wrong_no_2},
    {"BOOT@@IIARRAY2;maxColIndex;$I;7@@Builtin",too_few_2,CC_BOOT__IIARRAY2UmaxColIndexUDIU7,wrong_no_2},
    {"BOOT@@IIARRAY2;ncols;$Nni;9@@Builtin",too_few_2,CC_BOOT__IIARRAY2UncolsUDNniU9,wrong_no_2},
    {"BOOT@@IARRAY1;setelt;$I2S;17@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IARRAY1UseteltUDI2SU17},
    {"BOOT@@IARRAY1;new;NniS$;5@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IARRAY1UnewUNniSDU5},
    {"BOOT@@IARRAY1;qsetelt!;$I2S;15@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IARRAY1UqseteltBUDI2SU15},
    {"BOOT@@IARRAY1;minIndex;$I;3@@Builtin",too_few_2,CC_BOOT__IARRAY1UminIndexUDIU3,wrong_no_2},
    {"BOOT@@IARRAY1;maxIndex;$I;13@@Builtin",too_few_2,CC_BOOT__IARRAY1UmaxIndexUDIU13,wrong_no_2},
    {"BOOT@@IARRAY1;#;$Nni;1@@Builtin",too_few_2,CC_BOOT__IARRAY1UZUDNniU1,wrong_no_2},
    {"BOOT@@AGG-;empty?;SB;3@@Builtin",too_few_2,CC_BOOT__AGGKUemptyWUSBU3,wrong_no_2},
    {"BOOT@@STREAM;setfrst!@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__STREAMUsetfrstB},
    {"BOOT@@STREAM;setrst!@@Builtin",wrong_no_na,wrong_no_nb,  (n_args *)CC_BOOT__STREAMUsetrstB},
    {"BOOT@@STREAM;lazyEval@@Builtin",too_few_2,CC_BOOT__STREAMUlazyEval,wrong_no_2},
    {"BOOT@@STREAM;empty;$;33@@Builtin",CC_BOOT__STREAMUemptyUDU33,too_many_1,wrong_no_1},
    {"BOOT@@PRTITION;<;2$B;5@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__PRTITIONURU2DBU5},
    {"BOOT@@ILIST;minIndex;$I;18@@Builtin",too_few_2,CC_BOOT__ILISTUminIndexUDIU18,wrong_no_2},
    {"BOOT@@STREAM2;mapp!0@@Builtin",CC_BOOT__STREAM2UmappB0,too_many_1,wrong_no_1},
    {"BOOT@@STREAM2;mapp@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__STREAM2Umapp},
    {"BOOT@@STREAM2;map;MSS;2@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__STREAM2UmapUMSSU2},
    {"BOOT@@STTAYLOR;+;3S;2@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__STTAYLORULU3SU2},
    {"BOOT@@ZMOD;*;3$;30@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__ZMODUHU3DU30},
    {"BOOT@@ZMOD;+;3$;32@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__ZMODULU3DU32},
    {"BOOT@@ZMOD;-;3$;33@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__ZMODUKU3DU33},
    {"BOOT@@ZMOD;-;2$;36@@Builtin",too_few_2,   CC_BOOT__ZMODUKU2DU36,wrong_no_2},
    {"BOOT@@FFP;*;3$;21@@Builtin",wrong_no_na,  wrong_no_nb,   (n_args *)CC_BOOT__FFPUHU3DU21},
    {"BOOT@@FFP;+;3$;22@@Builtin",wrong_no_na,  wrong_no_nb,   (n_args *)CC_BOOT__FFPULU3DU22},
    {"BOOT@@FFP;=;2$B;24@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__FFPUMU2DBU24},
    {"BOOT@@FFP;-;3$;23@@Builtin",wrong_no_na,  wrong_no_nb,   (n_args *)CC_BOOT__FFPUKU3DU23},
    {"BOOT@@SAE;reduce;UP$;11@@Builtin",too_few_2,CC_BOOT__SAEUreduceUUPDU11,wrong_no_2},
    {"BOOT@@SAE;*;3$;15@@Builtin",wrong_no_na,  wrong_no_nb,   (n_args *)CC_BOOT__SAEUHU3DU15},
    {"BOOT@@SAE;+;3$;13@@Builtin",wrong_no_na,  wrong_no_nb,   (n_args *)CC_BOOT__SAEULU3DU13},
    {"BOOT@@SAE;=;2$B;12@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__SAEUMU2DBU12},
    {"BOOT@@SAE;-;2$;14@@Builtin",too_few_2,    CC_BOOT__SAEUKU2DU14,wrong_no_2},
    {"BOOT@@SUP;monicDivide;2$R;36@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__SUPUmonicDivideU2DRU36},
    {"BOOT@@ABELMON-;zero?;SB;1@@Builtin",too_few_2,CC_BOOT__ABELMONKUzeroWUSBU1,wrong_no_2},
    {"BOOT@@ABELGRP-;-;3S;1@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__ABELGRPKUKU3SU1},
    {"BOOT@@MATCAT-;*;S2Col;32@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__MATCATKUHUS2ColU32},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
