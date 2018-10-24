
/* u10.c                 Machine generated C code */

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
(DEFUN BOOT::|SUP;exquo;2$U;27| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (|a| BOOT::|ee| #:G113023 BOOT::|rout|)
      (RETURN
         (SEQ
            (EXIT
               (COND
                  ((NULL BOOT::|p2|) (BOOT::|error| "Division by 0"))
                  ((BOOT:SPADCALL
                      BOOT::|p2|
                      (BOOT::|spadConstant| |$| 18)
                      (VMLISP:QREFELT |$| 98))
                     (CONS 0 BOOT::|p1|))
                  ((BOOT:SPADCALL
                      BOOT::|p1|
                      BOOT::|p2|
                      (VMLISP:QREFELT |$| 98))
                     (CONS 0 (BOOT::|spadConstant| |$| 18)))
                  ('T
                     (SEQ
                        (BOOT::LETT
                           BOOT::|rout|
                           NIL
                           BOOT::|SUP;exquo;2$U;27|)
                        (SEQ
                           BOOT::G190
                           (COND
                              ((NULL
                                  (COND ((NULL BOOT::|p1|) 'NIL) ('T 'T)))
                                 (GO BOOT::G191)))
                           (SEQ
                              (BOOT::LETT
                                 |a|
                                 (BOOT:SPADCALL
                                    (QCDR (BOOT::|SPADfirst| BOOT::|p1|))
                                    (QCDR (BOOT::|SPADfirst| BOOT::|p2|))
                                    (VMLISP:QREFELT |$| 99))
                                 BOOT::|SUP;exquo;2$U;27|)
                              (EXIT
                                 (COND
                                    ((BOOT::QEQCAR |a| 1)
                                       (PROGN
                                          (BOOT::LETT
                                             #:G113023
                                             (CONS 1 "failed")
                                             BOOT::|SUP;exquo;2$U;27|)
                                          (GO #:G113023)))
                                    ('T
                                       (SEQ
                                          (BOOT::LETT
                                             BOOT::|ee|
                                             (BOOT:SPADCALL
                                                (QCAR
                                                   (BOOT::|SPADfirst|
                                                      BOOT::|p1|))
                                                (QCAR
                                                   (BOOT::|SPADfirst|
                                                      BOOT::|p2|))
                                                (VMLISP:QREFELT |$| 39))
                                             BOOT::|SUP;exquo;2$U;27|)
                                          (EXIT
                                             (COND
                                                ((BOOT::QEQCAR
                                                    BOOT::|ee|
                                                    1)
                                                   (PROGN
        (BOOT::LETT #:G113023 (CONS 1 "failed") BOOT::|SUP;exquo;2$U;27|)
        (GO #:G113023)))
                                                ('T
                                                   (SEQ
        (BOOT::LETT
        BOOT::|p1|
        (BOOT:SPADCALL
           (CDR BOOT::|p1|)
           (QCDR BOOT::|ee|)
           (QCDR |a|) (CDR BOOT::|p2|) (VMLISP:QREFELT |$| 100))
        BOOT::|SUP;exquo;2$U;27|)
        (EXIT
        (BOOT::LETT
        BOOT::|rout|
           (CONS (CONS (QCDR BOOT::|ee|) (QCDR |a|)) BOOT::|rout|)
     BOOT::|SUP;exquo;2$U;27|)))) ))) ))) )
                           NIL
                           (GO BOOT::G190)
                           BOOT::G191
                           (EXIT NIL))
                        (EXIT
                           (COND
                              ((NULL BOOT::|p1|)
                              (CONS 0 (REVERSE BOOT::|rout|)))
                              ('T (CONS 1 "failed")))) ))) )
            #:G113023
            (EXIT #:G113023)))) )

*/



/* Code for BOOT::|SUP;exquo;2$U;27| */

static Lisp_Object MS_CDECL CC_BOOT__SUPUexquoU2DUU27(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V402, V403, V404, V405, V406, V407;
    Lisp_Object fn;
    argcheck(nargs, 3, "SUP;exquo;2$U;27");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SUP;exquo;2$U;27|\n");
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
    V402 = stack[-5];
    if (V402 == nil) goto V19;
    V403 = stack[-4];
    V402 = (Lisp_Object)1569; /* 98 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    stack[-2] = V402;
    V402 = stack[-2];
    if (!car_legal(V402)) goto V417;
    stack[-1] = qcar(V402);
    stack[0] = stack[-5];
    V403 = stack[-4];
    V402 = (Lisp_Object)289; /* 18 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    V403 = V402;
    if (!car_legal(V403)) goto V418;
    V403 = qcar(V403);
    if (!car_legal(V402)) goto V419;
    V402 = qcdr(V402);
    V402 = Lapply1(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    V403 = V402;
    V402 = stack[-2];
    if (!car_legal(V402)) goto V419;
    V402 = qcdr(V402);
    V402 = Lapply3(nil, 4, stack[-1], stack[0], V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    if (V402 == nil) goto V87;
    V403 = (Lisp_Object)1; /* 0 */
    V402 = stack[-6];
    popv(9);
    { Lisp_Object retVal = cons(V403, V402);
    errexit();
    return onevalue(retVal); }

V87:
    V403 = stack[-4];
    V402 = (Lisp_Object)1569; /* 98 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    V403 = V402;
    if (!car_legal(V403)) goto V418;
    V405 = qcar(V403);
    V404 = stack[-6];
    V403 = stack[-5];
    if (!car_legal(V402)) goto V419;
    V402 = qcdr(V402);
    V402 = Lapply3(nil, 4, V405, V404, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    if (V402 == nil) goto V82;
    stack[0] = (Lisp_Object)1; /* 0 */
    V403 = stack[-4];
    V402 = (Lisp_Object)289; /* 18 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    V403 = V402;
    if (!car_legal(V403)) goto V418;
    V403 = qcar(V403);
    if (!car_legal(V402)) goto V419;
    V402 = qcdr(V402);
    V402 = Lapply1(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    {
        Lisp_Object V420 = stack[0];
        popv(9);
        { Lisp_Object retVal = cons(V420, V402);
        errexit();
        return onevalue(retVal); }
    }

V82:
    V402 = lisp_true;
    if (V402 == nil) goto V139;
    V402 = nil;
    stack[-3] = V402;
    goto V146;

V146:
    V402 = stack[-6];
    if (V402 == nil) goto V154;
    V402 = lisp_true;
    if (V402 == nil) goto V159;
    V402 = lisp_true;
    goto V153;

V153:
    if (V402 == nil) goto V145;
    V403 = stack[-4];
    V402 = (Lisp_Object)1585; /* 99 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    stack[-2] = V402;
    V402 = stack[-2];
    if (!car_legal(V402)) goto V417;
    stack[-1] = qcar(V402);
    V402 = stack[-6];
    V403 = V402;
    V402 = V403;
    if (V402 == nil) goto V194;
    V402 = V403;
    if (!car_legal(V402)) goto V417;
    V402 = qcar(V402);
    goto V189;

V189:
    stack[0] = qcdr(V402);
    V402 = stack[-5];
    V403 = V402;
    V402 = V403;
    if (V402 == nil) goto V207;
    V402 = V403;
    if (!car_legal(V402)) goto V417;
    V402 = qcar(V402);
    goto V202;

V202:
    V403 = qcdr(V402);
    V402 = stack[-2];
    if (!car_legal(V402)) goto V419;
    V402 = qcdr(V402);
    V402 = Lapply3(nil, 4, stack[-1], stack[0], V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    stack[-7] = V402;
    V402 = stack[-7];
    V403 = qcar(V402);
    V402 = (Lisp_Object)17; /* 1 */
    V402 = Leql(nil, V403, V402);
    env = stack[-8];
    if (V402 == nil) goto V218;
    V402 = (Lisp_Object)17; /* 1 */
    V403 = elt(env, 2); /* "failed" */
    popv(9);
    { Lisp_Object retVal = cons(V402, V403);
    errexit();
    return onevalue(retVal); }

V218:
    V402 = lisp_true;
    if (V402 == nil) goto V146;
    V403 = stack[-4];
    V402 = (Lisp_Object)625; /* 39 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    stack[-2] = V402;
    V402 = stack[-2];
    if (!car_legal(V402)) goto V417;
    stack[-1] = qcar(V402);
    V402 = stack[-6];
    V403 = V402;
    V402 = V403;
    if (V402 == nil) goto V271;
    V402 = V403;
    if (!car_legal(V402)) goto V417;
    V402 = qcar(V402);
    goto V266;

V266:
    stack[0] = qcar(V402);
    V402 = stack[-5];
    V403 = V402;
    V402 = V403;
    if (V402 == nil) goto V284;
    V402 = V403;
    if (!car_legal(V402)) goto V417;
    V402 = qcar(V402);
    goto V279;

V279:
    V403 = qcar(V402);
    V402 = stack[-2];
    if (!car_legal(V402)) goto V419;
    V402 = qcdr(V402);
    V402 = Lapply3(nil, 4, stack[-1], stack[0], V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    stack[0] = V402;
    V402 = stack[0];
    V403 = qcar(V402);
    V402 = (Lisp_Object)17; /* 1 */
    V402 = Leql(nil, V403, V402);
    env = stack[-8];
    if (V402 == nil) goto V295;
    V402 = (Lisp_Object)17; /* 1 */
    V403 = elt(env, 2); /* "failed" */
    popv(9);
    { Lisp_Object retVal = cons(V402, V403);
    errexit();
    return onevalue(retVal); }

V295:
    V402 = lisp_true;
    if (V402 == nil) goto V146;
    V403 = stack[-4];
    V402 = (Lisp_Object)1601; /* 100 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    V403 = V402;
    if (!car_legal(V403)) goto V418;
    V407 = qcar(V403);
    V403 = stack[-6];
    if (!car_legal(V403)) goto V421;
    V406 = qcdr(V403);
    V403 = stack[0];
    V405 = qcdr(V403);
    V403 = stack[-7];
    V404 = qcdr(V403);
    V403 = stack[-5];
    if (!car_legal(V403)) goto V421;
    V403 = qcdr(V403);
    if (!car_legal(V402)) goto V419;
    V402 = qcdr(V402);
    fn = elt(env, 3); /* FUNCALL* */
    V402 = (*qfnn(fn))(qenv(fn), 6, V407, V406, V405, V404, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    stack[-6] = V402;
    V402 = stack[0];
    V404 = qcdr(V402);
    V402 = stack[-7];
    V403 = qcdr(V402);
    V402 = stack[-3];
    V402 = acons(V404, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    stack[-3] = V402;
    goto V146;

V284:
    fn = elt(env, 4); /* BOOT::FIRST-ERROR */
    V402 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    goto V279;

V271:
    fn = elt(env, 4); /* BOOT::FIRST-ERROR */
    V402 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    goto V266;

V207:
    fn = elt(env, 4); /* BOOT::FIRST-ERROR */
    V402 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    goto V202;

V194:
    fn = elt(env, 4); /* BOOT::FIRST-ERROR */
    V402 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V416;
    env = stack[-8];
    goto V189;

V145:
    V402 = stack[-6];
    if (V402 == nil) goto V380;
    V402 = lisp_true;
    if (V402 == nil) goto V389;
    V402 = (Lisp_Object)17; /* 1 */
    V403 = elt(env, 2); /* "failed" */
    popv(9);
    { Lisp_Object retVal = cons(V402, V403);
    errexit();
    return onevalue(retVal); }

V389:
    V402 = nil;
    { popv(9); return onevalue(V402); }

V380:
    stack[0] = (Lisp_Object)1; /* 0 */
    V402 = stack[-3];
    V402 = Lreverse(nil, V402);
    nil = C_nil;
    if (exception_pending()) goto V416;
    {
        Lisp_Object V422 = stack[0];
        popv(9);
        { Lisp_Object retVal = cons(V422, V402);
        errexit();
        return onevalue(retVal); }
    }

V159:
    V402 = nil;
    goto V153;

V154:
    V402 = nil;
    goto V153;

V139:
    V402 = nil;
    { popv(9); return onevalue(V402); }

V19:
    V402 = elt(env, 1); /* "Division by 0" */
    {
        popv(9);
        fn = elt(env, 5); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V402);
    }
/* error exit handlers */
V421:
    popv(9);
    return error(1, err_bad_cdr, V403);
V419:
    popv(9);
    return error(1, err_bad_cdr, V402);
V418:
    popv(9);
    return error(1, err_bad_car, V403);
V417:
    popv(9);
    return error(1, err_bad_car, V402);
V416:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|SUP;exquo;2$U;28| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (|a| BOOT::|ee| #:G113038 BOOT::|rout|)
      (RETURN
         (SEQ
            (EXIT
               (COND
                  ((NULL BOOT::|p2|) (BOOT::|error| "Division by 0"))
                  ((BOOT:SPADCALL
                      BOOT::|p2|
                      (BOOT::|spadConstant| |$| 18)
                      (VMLISP:QREFELT |$| 98))
                     (CONS 0 BOOT::|p1|))
                  ('T
                     (SEQ
                        (BOOT::LETT
                           BOOT::|rout|
                           NIL
                           BOOT::|SUP;exquo;2$U;28|)
                        (SEQ
                           BOOT::G190
                           (COND
                              ((NULL
                                  (COND ((NULL BOOT::|p1|) 'NIL) ('T 'T)))
                                 (GO BOOT::G191)))
                           (SEQ
                              (BOOT::LETT
                                 |a|
                                 (BOOT:SPADCALL
                                    (QCDR (BOOT::|SPADfirst| BOOT::|p1|))
                                    (QCDR (BOOT::|SPADfirst| BOOT::|p2|))
                                    (VMLISP:QREFELT |$| 99))
                                 BOOT::|SUP;exquo;2$U;28|)
                              (EXIT
                                 (COND
                                    ((BOOT::QEQCAR |a| 1)
                                       (PROGN
                                          (BOOT::LETT
                                             #:G113038
                                             (CONS 1 "failed")
                                             BOOT::|SUP;exquo;2$U;28|)
                                          (GO #:G113038)))
                                    ('T
                                       (SEQ
                                          (BOOT::LETT
                                             BOOT::|ee|
                                             (BOOT:SPADCALL
                                                (QCAR
                                                   (BOOT::|SPADfirst|
                                                      BOOT::|p1|))
                                                (QCAR
                                                   (BOOT::|SPADfirst|
                                                      BOOT::|p2|))
                                                (VMLISP:QREFELT |$| 39))
                                             BOOT::|SUP;exquo;2$U;28|)
                                          (EXIT
                                             (COND
                                                ((BOOT::QEQCAR
                                                    BOOT::|ee|
                                                    1)
                                                   (PROGN
        (BOOT::LETT #:G113038 (CONS 1 "failed") BOOT::|SUP;exquo;2$U;28|)
        (GO #:G113038)))
                                                ('T
                                                   (SEQ
        (BOOT::LETT
        BOOT::|p1|
        (BOOT:SPADCALL
           (CDR BOOT::|p1|)
           (QCDR BOOT::|ee|)
           (QCDR |a|) (CDR BOOT::|p2|) (VMLISP:QREFELT |$| 100))
        BOOT::|SUP;exquo;2$U;28|)
        (EXIT
        (BOOT::LETT
        BOOT::|rout|
           (CONS (CONS (QCDR BOOT::|ee|) (QCDR |a|)) BOOT::|rout|)
     BOOT::|SUP;exquo;2$U;28|)))) ))) ))) )
                           NIL
                           (GO BOOT::G190)
                           BOOT::G191
                           (EXIT NIL))
                        (EXIT
                           (COND
                              ((NULL BOOT::|p1|)
                              (CONS 0 (REVERSE BOOT::|rout|)))
                              ('T (CONS 1 "failed")))) ))) )
            #:G113038
            (EXIT #:G113038)))) )

*/



/* Code for BOOT::|SUP;exquo;2$U;28| */

static Lisp_Object MS_CDECL CC_BOOT__SUPUexquoU2DUU28(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V345, V346, V347, V348, V349, V350;
    Lisp_Object fn;
    argcheck(nargs, 3, "SUP;exquo;2$U;28");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SUP;exquo;2$U;28|\n");
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
    V345 = stack[-5];
    if (V345 == nil) goto V19;
    V346 = stack[-4];
    V345 = (Lisp_Object)1569; /* 98 */
    V345 = Lgetv(nil, V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    stack[-2] = V345;
    V345 = stack[-2];
    if (!car_legal(V345)) goto V360;
    stack[-1] = qcar(V345);
    stack[0] = stack[-5];
    V346 = stack[-4];
    V345 = (Lisp_Object)289; /* 18 */
    V345 = Lgetv(nil, V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    V346 = V345;
    if (!car_legal(V346)) goto V361;
    V346 = qcar(V346);
    if (!car_legal(V345)) goto V362;
    V345 = qcdr(V345);
    V345 = Lapply1(nil, V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    V346 = V345;
    V345 = stack[-2];
    if (!car_legal(V345)) goto V362;
    V345 = qcdr(V345);
    V345 = Lapply3(nil, 4, stack[-1], stack[0], V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    if (V345 == nil) goto V25;
    V346 = (Lisp_Object)1; /* 0 */
    V345 = stack[-6];
    popv(9);
    { Lisp_Object retVal = cons(V346, V345);
    errexit();
    return onevalue(retVal); }

V25:
    V345 = lisp_true;
    if (V345 == nil) goto V82;
    V345 = nil;
    stack[-3] = V345;
    goto V89;

V89:
    V345 = stack[-6];
    if (V345 == nil) goto V97;
    V345 = lisp_true;
    if (V345 == nil) goto V102;
    V345 = lisp_true;
    goto V96;

V96:
    if (V345 == nil) goto V88;
    V346 = stack[-4];
    V345 = (Lisp_Object)1585; /* 99 */
    V345 = Lgetv(nil, V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    stack[-2] = V345;
    V345 = stack[-2];
    if (!car_legal(V345)) goto V360;
    stack[-1] = qcar(V345);
    V345 = stack[-6];
    V346 = V345;
    V345 = V346;
    if (V345 == nil) goto V137;
    V345 = V346;
    if (!car_legal(V345)) goto V360;
    V345 = qcar(V345);
    goto V132;

V132:
    stack[0] = qcdr(V345);
    V345 = stack[-5];
    V346 = V345;
    V345 = V346;
    if (V345 == nil) goto V150;
    V345 = V346;
    if (!car_legal(V345)) goto V360;
    V345 = qcar(V345);
    goto V145;

V145:
    V346 = qcdr(V345);
    V345 = stack[-2];
    if (!car_legal(V345)) goto V362;
    V345 = qcdr(V345);
    V345 = Lapply3(nil, 4, stack[-1], stack[0], V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    stack[-7] = V345;
    V345 = stack[-7];
    V346 = qcar(V345);
    V345 = (Lisp_Object)17; /* 1 */
    V345 = Leql(nil, V346, V345);
    env = stack[-8];
    if (V345 == nil) goto V161;
    V345 = (Lisp_Object)17; /* 1 */
    V346 = elt(env, 2); /* "failed" */
    popv(9);
    { Lisp_Object retVal = cons(V345, V346);
    errexit();
    return onevalue(retVal); }

V161:
    V345 = lisp_true;
    if (V345 == nil) goto V89;
    V346 = stack[-4];
    V345 = (Lisp_Object)625; /* 39 */
    V345 = Lgetv(nil, V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    stack[-2] = V345;
    V345 = stack[-2];
    if (!car_legal(V345)) goto V360;
    stack[-1] = qcar(V345);
    V345 = stack[-6];
    V346 = V345;
    V345 = V346;
    if (V345 == nil) goto V214;
    V345 = V346;
    if (!car_legal(V345)) goto V360;
    V345 = qcar(V345);
    goto V209;

V209:
    stack[0] = qcar(V345);
    V345 = stack[-5];
    V346 = V345;
    V345 = V346;
    if (V345 == nil) goto V227;
    V345 = V346;
    if (!car_legal(V345)) goto V360;
    V345 = qcar(V345);
    goto V222;

V222:
    V346 = qcar(V345);
    V345 = stack[-2];
    if (!car_legal(V345)) goto V362;
    V345 = qcdr(V345);
    V345 = Lapply3(nil, 4, stack[-1], stack[0], V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    stack[0] = V345;
    V345 = stack[0];
    V346 = qcar(V345);
    V345 = (Lisp_Object)17; /* 1 */
    V345 = Leql(nil, V346, V345);
    env = stack[-8];
    if (V345 == nil) goto V238;
    V345 = (Lisp_Object)17; /* 1 */
    V346 = elt(env, 2); /* "failed" */
    popv(9);
    { Lisp_Object retVal = cons(V345, V346);
    errexit();
    return onevalue(retVal); }

V238:
    V345 = lisp_true;
    if (V345 == nil) goto V89;
    V346 = stack[-4];
    V345 = (Lisp_Object)1601; /* 100 */
    V345 = Lgetv(nil, V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    V346 = V345;
    if (!car_legal(V346)) goto V361;
    V350 = qcar(V346);
    V346 = stack[-6];
    if (!car_legal(V346)) goto V363;
    V349 = qcdr(V346);
    V346 = stack[0];
    V348 = qcdr(V346);
    V346 = stack[-7];
    V347 = qcdr(V346);
    V346 = stack[-5];
    if (!car_legal(V346)) goto V363;
    V346 = qcdr(V346);
    if (!car_legal(V345)) goto V362;
    V345 = qcdr(V345);
    fn = elt(env, 3); /* FUNCALL* */
    V345 = (*qfnn(fn))(qenv(fn), 6, V350, V349, V348, V347, V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    stack[-6] = V345;
    V345 = stack[0];
    V347 = qcdr(V345);
    V345 = stack[-7];
    V346 = qcdr(V345);
    V345 = stack[-3];
    V345 = acons(V347, V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    stack[-3] = V345;
    goto V89;

V227:
    fn = elt(env, 4); /* BOOT::FIRST-ERROR */
    V345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    goto V222;

V214:
    fn = elt(env, 4); /* BOOT::FIRST-ERROR */
    V345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    goto V209;

V150:
    fn = elt(env, 4); /* BOOT::FIRST-ERROR */
    V345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    goto V145;

V137:
    fn = elt(env, 4); /* BOOT::FIRST-ERROR */
    V345 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V359;
    env = stack[-8];
    goto V132;

V88:
    V345 = stack[-6];
    if (V345 == nil) goto V323;
    V345 = lisp_true;
    if (V345 == nil) goto V332;
    V345 = (Lisp_Object)17; /* 1 */
    V346 = elt(env, 2); /* "failed" */
    popv(9);
    { Lisp_Object retVal = cons(V345, V346);
    errexit();
    return onevalue(retVal); }

V332:
    V345 = nil;
    { popv(9); return onevalue(V345); }

V323:
    stack[0] = (Lisp_Object)1; /* 0 */
    V345 = stack[-3];
    V345 = Lreverse(nil, V345);
    nil = C_nil;
    if (exception_pending()) goto V359;
    {
        Lisp_Object V364 = stack[0];
        popv(9);
        { Lisp_Object retVal = cons(V364, V345);
        errexit();
        return onevalue(retVal); }
    }

V102:
    V345 = nil;
    goto V96;

V97:
    V345 = nil;
    goto V96;

V82:
    V345 = nil;
    { popv(9); return onevalue(V345); }

V19:
    V345 = elt(env, 1); /* "Division by 0" */
    {
        popv(9);
        fn = elt(env, 5); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V345);
    }
/* error exit handlers */
V363:
    popv(9);
    return error(1, err_bad_cdr, V346);
V362:
    popv(9);
    return error(1, err_bad_cdr, V345);
V361:
    popv(9);
    return error(1, err_bad_car, V346);
V360:
    popv(9);
    return error(1, err_bad_car, V345);
V359:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|PR;coerce;R$;12| (|r| |$|)
   (COND
      ((BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 36))
         (BOOT::|spadConstant| |$| 22))
      ('T (LIST (CONS (BOOT::|spadConstant| |$| 10) |r|)))) )

*/



/* Code for BOOT::|PR;coerce;R$;12| */

static Lisp_Object CC_BOOT__PRUcoerceURDU12(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V88, V89, V90;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PR;coerce;R$;12|\n");
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
    V89 = stack[0];
    V88 = (Lisp_Object)577; /* 36 */
    V88 = Lgetv(nil, V89, V88);
    nil = C_nil;
    if (exception_pending()) goto V93;
    env = stack[-2];
    V89 = V88;
    if (!car_legal(V89)) goto V94;
    V90 = qcar(V89);
    V89 = stack[-1];
    if (!car_legal(V88)) goto V95;
    V88 = qcdr(V88);
    V88 = Lapply2(nil, 3, V90, V89, V88);
    nil = C_nil;
    if (exception_pending()) goto V93;
    env = stack[-2];
    if (V88 == nil) goto V10;
    V89 = stack[0];
    V88 = (Lisp_Object)353; /* 22 */
    V88 = Lgetv(nil, V89, V88);
    nil = C_nil;
    if (exception_pending()) goto V93;
    V89 = V88;
    if (!car_legal(V89)) goto V94;
    V89 = qcar(V89);
    if (!car_legal(V88)) goto V95;
    V88 = qcdr(V88);
        popv(3);
        return Lapply1(nil, V89, V88);

V10:
    V88 = lisp_true;
    if (V88 == nil) goto V57;
    V89 = stack[0];
    V88 = (Lisp_Object)161; /* 10 */
    V88 = Lgetv(nil, V89, V88);
    nil = C_nil;
    if (exception_pending()) goto V93;
    env = stack[-2];
    V89 = V88;
    if (!car_legal(V89)) goto V94;
    V89 = qcar(V89);
    if (!car_legal(V88)) goto V95;
    V88 = qcdr(V88);
    V88 = Lapply1(nil, V89, V88);
    nil = C_nil;
    if (exception_pending()) goto V93;
    env = stack[-2];
    V89 = V88;
    V88 = stack[-1];
    V88 = cons(V89, V88);
    nil = C_nil;
    if (exception_pending()) goto V93;
    popv(3);
    { Lisp_Object retVal = ncons(V88);
    errexit();
    return onevalue(retVal); }

V57:
    V88 = nil;
    { popv(3); return onevalue(V88); }
/* error exit handlers */
V95:
    popv(3);
    return error(1, err_bad_cdr, V88);
V94:
    popv(3);
    return error(1, err_bad_car, V89);
V93:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|REPSQ;expt;SPiS;1| (|x| |n| |$|)
   (COND
      ((ONEP |n|) |x|)
      ((ODDP |n|)
         (BOOT:SPADCALL
            |x|
            (BOOT:SPADCALL
               (BOOT:SPADCALL |x| |x| (VMLISP:QREFELT |$| 7))
               (ASH |n| -1)
               (VMLISP:QREFELT |$| 9))
            (VMLISP:QREFELT |$| 7)))
      ('T
         (BOOT:SPADCALL
            (BOOT:SPADCALL |x| |x| (VMLISP:QREFELT |$| 7))
            (ASH |n| -1)
            (VMLISP:QREFELT |$| 9)))) )

*/



/* Code for BOOT::|REPSQ;expt;SPiS;1| */

static Lisp_Object MS_CDECL CC_BOOT__REPSQUexptUSPiSU1(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V168, V169, V170, V171;
    argcheck(nargs, 3, "REPSQ;expt;SPiS;1");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|REPSQ;expt;SPiS;1|\n");
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
    V168 = stack[-5];
    V168 = Lonep(nil, V168);
    env = stack[-8];
    if (!(V168 == nil)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    V168 = stack[-5];
    V168 = Loddp(nil, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-8];
    if (V168 == nil) goto V16;
    V169 = stack[-4];
    V168 = (Lisp_Object)113; /* 7 */
    V168 = Lgetv(nil, V169, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-8];
    stack[-7] = V168;
    V168 = stack[-7];
    if (!car_legal(V168)) goto V181;
    stack[-3] = qcar(V168);
    stack[-2] = stack[-6];
    V169 = stack[-4];
    V168 = (Lisp_Object)145; /* 9 */
    V168 = Lgetv(nil, V169, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-8];
    stack[-1] = V168;
    V168 = stack[-1];
    if (!car_legal(V168)) goto V181;
    stack[0] = qcar(V168);
    V169 = stack[-4];
    V168 = (Lisp_Object)113; /* 7 */
    V168 = Lgetv(nil, V169, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-8];
    V169 = V168;
    if (!car_legal(V169)) goto V182;
    V171 = qcar(V169);
    V170 = stack[-6];
    V169 = stack[-6];
    if (!car_legal(V168)) goto V183;
    V168 = qcdr(V168);
    V168 = Lapply3(nil, 4, V171, V170, V169, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-8];
    stack[-4] = V168;
    V169 = stack[-5];
    V168 = (Lisp_Object)-15; /* -1 */
    V169 = Lash1(nil, V169, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-8];
    V168 = stack[-1];
    if (!car_legal(V168)) goto V183;
    V168 = qcdr(V168);
    V168 = Lapply3(nil, 4, stack[0], stack[-4], V169, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    V169 = V168;
    V168 = stack[-7];
    if (!car_legal(V168)) goto V183;
    V168 = qcdr(V168);
    {
        Lisp_Object V184 = stack[-3];
        Lisp_Object V185 = stack[-2];
        popv(9);
        return Lapply3(nil, 4, V184, V185, V169, V168);
    }

V16:
    V168 = lisp_true;
    if (V168 == nil) goto V106;
    V169 = stack[-4];
    V168 = (Lisp_Object)145; /* 9 */
    V168 = Lgetv(nil, V169, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-8];
    stack[-1] = V168;
    V168 = stack[-1];
    if (!car_legal(V168)) goto V181;
    stack[0] = qcar(V168);
    V169 = stack[-4];
    V168 = (Lisp_Object)113; /* 7 */
    V168 = Lgetv(nil, V169, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-8];
    V169 = V168;
    if (!car_legal(V169)) goto V182;
    V171 = qcar(V169);
    V170 = stack[-6];
    V169 = stack[-6];
    if (!car_legal(V168)) goto V183;
    V168 = qcdr(V168);
    V168 = Lapply3(nil, 4, V171, V170, V169, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-8];
    stack[-2] = V168;
    V169 = stack[-5];
    V168 = (Lisp_Object)-15; /* -1 */
    V169 = Lash1(nil, V169, V168);
    nil = C_nil;
    if (exception_pending()) goto V180;
    V168 = stack[-1];
    if (!car_legal(V168)) goto V183;
    V168 = qcdr(V168);
    {
        Lisp_Object V186 = stack[0];
        Lisp_Object V187 = stack[-2];
        popv(9);
        return Lapply3(nil, 4, V186, V187, V169, V168);
    }

V106:
    V168 = nil;
    { popv(9); return onevalue(V168); }
/* error exit handlers */
V183:
    popv(9);
    return error(1, err_bad_cdr, V168);
V182:
    popv(9);
    return error(1, err_bad_car, V169);
V181:
    popv(9);
    return error(1, err_bad_car, V168);
V180:
    popv(9);
    return nil;
}

/*
(DEFUN VMLISP:QENUM (VMLISP:CVEC VMLISP::IND)
   (|CHAR-CODE| (CHAR VMLISP:CVEC VMLISP::IND)))

*/



/* Code for VMLISP:QENUM */

static Lisp_Object CC_VMLISP__QENUM(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V16, V17;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering VMLISP:QENUM\n");
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
    V16 = V3;
    V17 = V2;
/* end of prologue */
    fn = elt(env, 1); /* CHAR */
    V16 = (*qfn2(fn))(qenv(fn), V17, V16);
    errexit();
        return Lchar_code(nil, V16);
}

/*
(DEFUN VMLISP:GGREATERP (VMLISP::|COMPERAND-1| VMLISP::|COMPERAND-2|)
   (COND
      ((EQ VMLISP::|COMPERAND-1| VMLISP::|COMPERAND-2|) NIL)
      ((SYMBOLP VMLISP::|COMPERAND-1|)
         (COND
            ((SYMBOLP VMLISP::|COMPERAND-2|)
               (VMLISP:CGREATERP
                  (|SYMBOL-NAME| VMLISP::|COMPERAND-1|)
                  (|SYMBOL-NAME| VMLISP::|COMPERAND-2|)))
            ('VMLISP::ELSE T)))
      ((SYMBOLP VMLISP::|COMPERAND-2|) NIL)
      ((CONSP VMLISP::|COMPERAND-1|)
         (COND
            ((CONSP VMLISP::|COMPERAND-2|)
               (COND
                  ((EQUAL
                      (QCAR VMLISP::|COMPERAND-1|)
                      (QCAR VMLISP::|COMPERAND-2|))
                     (VMLISP:GGREATERP
                        (QCDR VMLISP::|COMPERAND-1|)
                        (QCDR VMLISP::|COMPERAND-2|)))
                  ((VMLISP:GGREATERP
                      (QCAR VMLISP::|COMPERAND-1|)
                      (QCAR VMLISP::|COMPERAND-2|)))) )
            ('VMLISP::ELSE T)))
      ((CONSP VMLISP::|COMPERAND-2|) NIL)
      ((NULL VMLISP::|COMPERAND-1|) 'T)
      ((NULL VMLISP::|COMPERAND-2|) NIL)
      ((VMLISP:VECP VMLISP::|COMPERAND-1|)
         (COND
            ((VMLISP:VECP VMLISP::|COMPERAND-2|)
               (VMLISP::VGREATERP
                  VMLISP::|COMPERAND-1|
                  VMLISP::|COMPERAND-2|))
            ('VMLISP::ELSE T)))
      ((VMLISP:VECP VMLISP::|COMPERAND-2|) NIL)
      ((OR
          (VMLISP:IVECP VMLISP::|COMPERAND-1|)
          (VMLISP:RVECP VMLISP::|COMPERAND-1|))
         (COND
            ((OR
                (VMLISP:IVECP VMLISP::|COMPERAND-2|)
                (VMLISP:RVECP VMLISP::|COMPERAND-2|))
               (VMLISP::VGREATERP
                  VMLISP::|COMPERAND-1|
                  VMLISP::|COMPERAND-2|))
            ('VMLISP::ELSE T)))
      ((OR
          (VMLISP:IVECP VMLISP::|COMPERAND-2|)
          (VMLISP:RVECP VMLISP::|COMPERAND-2|))
         NIL)
      ((STRINGP VMLISP::|COMPERAND-1|)
         (COND
            ((STRINGP VMLISP::|COMPERAND-2|)
               (VMLISP:CGREATERP
                  VMLISP::|COMPERAND-1|
                  VMLISP::|COMPERAND-2|))
            ('VMLISP::ELSE T)))
      ((STRINGP VMLISP::|COMPERAND-2|) NIL)
      ((NUMBERP VMLISP::|COMPERAND-1|)
         (COND
            ((NUMBERP VMLISP::|COMPERAND-2|)
               (|>| VMLISP::|COMPERAND-1| VMLISP::|COMPERAND-2|))
            ('VMLISP::ELSE T)))
      ((NUMBERP VMLISP::|COMPERAND-2|) NIL)
      ((CHARACTERP VMLISP::|COMPERAND-1|)
         (COND
            ((CHARACTERP VMLISP::|COMPERAND-2|)
               (|CHAR>| VMLISP::|COMPERAND-1| VMLISP::|COMPERAND-2|))
            ('VMLISP::ELSE T)))
      ((CHARACTERP VMLISP::|COMPERAND-2|) NIL)
      ((VMLISP:FBPIP VMLISP::|COMPERAND-1|)
         (COND
            ((VMLISP:FBPIP VMLISP::|COMPERAND-2|)
               (VMLISP:GGREATERP
                  (VMLISP:BPINAME VMLISP::|COMPERAND-1|)
                  (VMLISP:BPINAME VMLISP::|COMPERAND-2|)))
            ('VMLISP::ELSE T)))
      ((VMLISP:FBPIP VMLISP::|COMPERAND-2|) NIL)
      ((VMLISP:MBPIP VMLISP::|COMPERAND-1|)
         (COND
            ((VMLISP:MBPIP VMLISP::|COMPERAND-2|)
               (VMLISP:GGREATERP
                  (VMLISP:BPINAME VMLISP::|COMPERAND-1|)
                  (VMLISP:BPINAME VMLISP::|COMPERAND-2|)))
            ('VMLISP::ELSE T)))
      ((VMLISP:MBPIP VMLISP::|COMPERAND-2|) NIL)
      ((|>|
          (SXHASH VMLISP::|COMPERAND-1|)
          (SXHASH VMLISP::|COMPERAND-2|)))) )

*/



/* Code for VMLISP:GGREATERP */

static Lisp_Object CC_VMLISP__GGREATERP(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V339, V340;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering VMLISP:GGREATERP\n");
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

V11:
    V340 = stack[-1];
    V339 = stack[0];
    if (V340 == V339) goto V9;
    V339 = stack[-1];
    fn = elt(env, 3); /* SYMBOLP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V20;
    V339 = stack[0];
    fn = elt(env, 3); /* SYMBOLP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V26;
    V339 = stack[-1];
    V340 = Lsymbol_name(nil, V339);
    env = stack[-2];
    V339 = stack[0];
    V339 = Lsymbol_name(nil, V339);
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 4); /* VMLISP:CGREATERP */
        return (*qfn2(fn))(qenv(fn), V340, V339);
    }

V26:
    V339 = elt(env, 1); /* VMLISP::ELSE */
    if (V339 == nil) goto V40;
    V339 = lisp_true;
    { popv(3); return onevalue(V339); }

V40:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V20:
    V339 = stack[0];
    fn = elt(env, 3); /* SYMBOLP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V44;
    V339 = nil;
    { popv(3); return onevalue(V339); }

V44:
    V339 = stack[-1];
    if (!consp(V339)) goto V49;
    V339 = stack[0];
    if (!consp(V339)) goto V54;
    V339 = stack[-1];
    V340 = qcar(V339);
    V339 = stack[0];
    V339 = qcar(V339);
    if (cl_equal(V340, V339)) goto V70;
    V339 = stack[-1];
    V340 = qcar(V339);
    V339 = stack[0];
    V339 = qcar(V339);
    V339 = CC_VMLISP__GGREATERP(env, V340, V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    if (!(V339 == nil)) { popv(3); return onevalue(V339); }
    V339 = nil;
    { popv(3); return onevalue(V339); }

V70:
    V339 = stack[-1];
    V340 = qcdr(V339);
    V339 = stack[0];
    V339 = qcdr(V339);
    stack[-1] = V340;
    stack[0] = V339;
    goto V11;

V54:
    V339 = elt(env, 1); /* VMLISP::ELSE */
    if (V339 == nil) goto V92;
    V339 = lisp_true;
    { popv(3); return onevalue(V339); }

V92:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V49:
    V339 = stack[0];
    if (!consp(V339)) goto V96;
    V339 = nil;
    { popv(3); return onevalue(V339); }

V96:
    V339 = stack[-1];
    if (V339 == nil) goto V99;
    V339 = stack[0];
    if (V339 == nil) goto V103;
    V339 = stack[-1];
    fn = elt(env, 5); /* SIMPLE-VECTOR-P */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V108;
    V339 = stack[0];
    fn = elt(env, 5); /* SIMPLE-VECTOR-P */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V114;
    V340 = stack[-1];
    V339 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* VMLISP::VGREATERP */
        return (*qfn2(fn))(qenv(fn), V340, V339);
    }

V114:
    V339 = elt(env, 1); /* VMLISP::ELSE */
    if (V339 == nil) goto V126;
    V339 = lisp_true;
    { popv(3); return onevalue(V339); }

V126:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V108:
    V339 = stack[0];
    fn = elt(env, 5); /* SIMPLE-VECTOR-P */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V130;
    V339 = nil;
    { popv(3); return onevalue(V339); }

V130:
    V339 = stack[-1];
    fn = elt(env, 7); /* VMLISP:IVECP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (!(V339 == nil)) goto V134;
    V340 = stack[-1];
    V339 = elt(env, 2); /* (VECTOR FLOAT) */
    fn = elt(env, 8); /* TYPEP */
    V339 = (*qfn2(fn))(qenv(fn), V340, V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (!(V339 == nil)) goto V134;
    V339 = stack[0];
    fn = elt(env, 7); /* VMLISP:IVECP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (!(V339 == nil)) goto V176;
    V340 = stack[0];
    V339 = elt(env, 2); /* (VECTOR FLOAT) */
    fn = elt(env, 8); /* TYPEP */
    V339 = (*qfn2(fn))(qenv(fn), V340, V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (!(V339 == nil)) goto V176;
    V339 = stack[-1];
    V339 = Lstringp(nil, V339);
    env = stack[-2];
    if (V339 == nil) goto V192;
    V339 = stack[0];
    V339 = Lstringp(nil, V339);
    env = stack[-2];
    if (V339 == nil) goto V198;
    V340 = stack[-1];
    V339 = stack[0];
    {
        popv(3);
        fn = elt(env, 4); /* VMLISP:CGREATERP */
        return (*qfn2(fn))(qenv(fn), V340, V339);
    }

V198:
    V339 = elt(env, 1); /* VMLISP::ELSE */
    if (V339 == nil) goto V210;
    V339 = lisp_true;
    { popv(3); return onevalue(V339); }

V210:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V192:
    V339 = stack[0];
    V339 = Lstringp(nil, V339);
    env = stack[-2];
    if (V339 == nil) goto V214;
    V339 = nil;
    { popv(3); return onevalue(V339); }

V214:
    V339 = stack[-1];
    if (is_number(V339)) goto V218;
    V339 = stack[0];
    if (is_number(V339)) goto V238;
    V339 = stack[-1];
    fn = elt(env, 9); /* CHARACTERP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V243;
    V339 = stack[0];
    fn = elt(env, 9); /* CHARACTERP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V249;
    V340 = stack[-1];
    V339 = stack[0];
    {
        popv(3);
        fn = elt(env, 10); /* CHAR> */
        return (*qfn2(fn))(qenv(fn), V340, V339);
    }

V249:
    V339 = elt(env, 1); /* VMLISP::ELSE */
    if (V339 == nil) goto V261;
    V339 = lisp_true;
    { popv(3); return onevalue(V339); }

V261:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V243:
    V339 = stack[0];
    fn = elt(env, 9); /* CHARACTERP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V265;
    V339 = nil;
    { popv(3); return onevalue(V339); }

V265:
    V339 = stack[-1];
    fn = elt(env, 11); /* VMLISP:FBPIP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V270;
    V339 = stack[0];
    fn = elt(env, 11); /* VMLISP:FBPIP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V276;
    V339 = stack[-1];
    fn = elt(env, 12); /* VMLISP:BPINAME */
    stack[-1] = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    V339 = stack[0];
    fn = elt(env, 12); /* VMLISP:BPINAME */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    stack[0] = V339;
    goto V11;

V276:
    V339 = elt(env, 1); /* VMLISP::ELSE */
    if (V339 == nil) goto V290;
    V339 = lisp_true;
    { popv(3); return onevalue(V339); }

V290:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V270:
    V339 = stack[0];
    fn = elt(env, 11); /* VMLISP:FBPIP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V294;
    V339 = nil;
    { popv(3); return onevalue(V339); }

V294:
    V339 = stack[-1];
    fn = elt(env, 13); /* VMLISP:MBPIP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V299;
    V339 = stack[0];
    fn = elt(env, 13); /* VMLISP:MBPIP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V305;
    V339 = stack[-1];
    fn = elt(env, 12); /* VMLISP:BPINAME */
    stack[-1] = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    V339 = stack[0];
    fn = elt(env, 12); /* VMLISP:BPINAME */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    stack[0] = V339;
    goto V11;

V305:
    V339 = elt(env, 1); /* VMLISP::ELSE */
    if (V339 == nil) goto V319;
    V339 = lisp_true;
    { popv(3); return onevalue(V339); }

V319:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V299:
    V339 = stack[0];
    fn = elt(env, 13); /* VMLISP:MBPIP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (V339 == nil) goto V330;
    V339 = nil;
    { popv(3); return onevalue(V339); }

V330:
    V339 = stack[-1];
    fn = elt(env, 14); /* SXHASH */
    stack[-1] = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    V339 = stack[0];
    fn = elt(env, 14); /* SXHASH */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    V339 = (Lisp_Object)greaterp2(stack[-1], V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    V339 = V339 ? lisp_true : nil;
    if (!(V339 == nil)) { popv(3); return onevalue(V339); }
    V339 = nil;
    { popv(3); return onevalue(V339); }

V238:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V218:
    V339 = stack[0];
    if (is_number(V339)) goto V227;
    V339 = elt(env, 1); /* VMLISP::ELSE */
    if (V339 == nil) goto V235;
    V339 = lisp_true;
    { popv(3); return onevalue(V339); }

V235:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V227:
    V340 = stack[-1];
    V339 = stack[0];
        popv(3);
        return Lgreaterp(nil, V340, V339);

V176:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V134:
    V339 = stack[0];
    fn = elt(env, 7); /* VMLISP:IVECP */
    V339 = (*qfn1(fn))(qenv(fn), V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (!(V339 == nil)) goto V165;
    V340 = stack[0];
    V339 = elt(env, 2); /* (VECTOR FLOAT) */
    fn = elt(env, 8); /* TYPEP */
    V339 = (*qfn2(fn))(qenv(fn), V340, V339);
    nil = C_nil;
    if (exception_pending()) goto V343;
    env = stack[-2];
    if (!(V339 == nil)) goto V165;
    V339 = elt(env, 1); /* VMLISP::ELSE */
    if (V339 == nil) goto V173;
    V339 = lisp_true;
    { popv(3); return onevalue(V339); }

V173:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V165:
    V340 = stack[-1];
    V339 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* VMLISP::VGREATERP */
        return (*qfn2(fn))(qenv(fn), V340, V339);
    }

V103:
    V339 = nil;
    { popv(3); return onevalue(V339); }

V99:
    V339 = lisp_true;
    { popv(3); return onevalue(V339); }

V9:
    V339 = nil;
    { popv(3); return onevalue(V339); }
/* error exit handlers */
V343:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|startTimingProcess| (BOOT::|name|)
   (PROGN
      (BOOT::|updateTimedName| (BOOT::|peekTimedName|))
      (BOOT::|pushTimedName| BOOT::|name|)
      (COND
         ((EQ BOOT::|name| 'BOOT::|load|) (BOOT::|statRecordLoadEvent|))
         ('T NIL))))

*/



/* Code for BOOT::|startTimingProcess| */

static Lisp_Object CC_BOOT__startTimingProcess(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V26, V27;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|startTimingProcess|\n");
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
    fn = elt(env, 2); /* BOOT::|peekTimedName| */
    V26 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V29;
    env = stack[-1];
    fn = elt(env, 3); /* BOOT::|updateTimedName| */
    V26 = (*qfn1(fn))(qenv(fn), V26);
    nil = C_nil;
    if (exception_pending()) goto V29;
    env = stack[-1];
    V26 = stack[0];
    fn = elt(env, 4); /* BOOT::|pushTimedName| */
    V26 = (*qfn1(fn))(qenv(fn), V26);
    nil = C_nil;
    if (exception_pending()) goto V29;
    env = stack[-1];
    V27 = stack[0];
    V26 = elt(env, 1); /* BOOT::|load| */
    if (V27 == V26) goto V12;
    V26 = lisp_true;
    if (V26 == nil) goto V23;
    V26 = nil;
    { popv(2); return onevalue(V26); }

V23:
    V26 = nil;
    { popv(2); return onevalue(V26); }

V12:
    {
        popv(2);
        fn = elt(env, 5); /* BOOT::|statRecordLoadEvent| */
        return (*qfnn(fn))(qenv(fn), 0);
    }
/* error exit handlers */
V29:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|domainEqualList| (BOOT::|argl1| BOOT::|argl2|)
   (PROG (BOOT::|item1| BOOT::|item2| BOOT::|partsMatch|)
      (RETURN
         (SEQ
            (PROGN
               (DO NIL
                  ((NULL (AND BOOT::|argl1| BOOT::|argl2|)) NIL)
                  (SEQ
                     (EXIT
                        (PROGN
                           (BOOT:SPADLET
                              BOOT::|item1|
                              (BOOT::|devaluate| (CAR BOOT::|argl1|)))
                           (BOOT:SPADLET BOOT::|item2| (CAR BOOT::|argl2|))
                           (BOOT:SPADLET
                              BOOT::|partsMatch|
                              (COND
                                 ((BOOT:|BOOT-EQUAL|
                                     BOOT::|item1|
                                     BOOT::|item2|)
                                    'T)
                                 ('T NIL)))
                           (COND
                              ((NULL BOOT::|partsMatch|) (RETURN NIL))
                              ('T
                                 (BOOT:SPADLET
                                    BOOT::|argl1|
                                    (CDR BOOT::|argl1|))
                                 (BOOT:SPADLET
                                    BOOT::|argl2|
                                    (CDR BOOT::|argl2|)))) ))) )
               (COND ((OR BOOT::|argl1| BOOT::|argl2|) NIL) ('T 'T)))) )))

*/



/* Code for BOOT::|domainEqualList| */

static Lisp_Object CC_BOOT__domainEqualList(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V80, V81;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|domainEqualList|\n");
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

V16:
    V80 = stack[-1];
    if (V80 == nil) goto V15;
    V80 = stack[0];
    if (V80 == nil) goto V15;
    V80 = stack[-1];
    if (!car_legal(V80)) goto V84;
    V80 = qcar(V80);
    fn = elt(env, 1); /* BOOT::|devaluate| */
    V80 = (*qfn1(fn))(qenv(fn), V80);
    nil = C_nil;
    if (exception_pending()) goto V85;
    env = stack[-2];
    V81 = V80;
    V80 = stack[0];
    if (!car_legal(V80)) goto V84;
    V80 = qcar(V80);
    V80 = (cl_equal(V81, V80) ? lisp_true : nil);
    if (V80 == nil) goto V37;
    V80 = lisp_true;
    goto V35;

V35:
    if (V80 == nil) goto V15;
    V80 = lisp_true;
    if (V80 == nil) goto V16;
    V80 = stack[-1];
    if (!car_legal(V80)) goto V86;
    V80 = qcdr(V80);
    stack[-1] = V80;
    V80 = stack[0];
    if (!car_legal(V80)) goto V86;
    V80 = qcdr(V80);
    stack[0] = V80;
    goto V16;

V15:
    V80 = stack[-1];
    if (!(V80 == nil)) goto V68;
    V80 = stack[0];
    if (!(V80 == nil)) goto V68;
    V80 = lisp_true;
    if (V80 == nil) goto V76;
    V80 = lisp_true;
    { popv(3); return onevalue(V80); }

V76:
    V80 = nil;
    { popv(3); return onevalue(V80); }

V68:
    V80 = nil;
    { popv(3); return onevalue(V80); }

V37:
    V80 = lisp_true;
    if (V80 == nil) goto V48;
    V80 = nil;
    goto V35;

V48:
    V80 = nil;
    goto V35;
/* error exit handlers */
V86:
    popv(3);
    return error(1, err_bad_cdr, V80);
V85:
    popv(3);
    return nil;
V84:
    popv(3);
    return error(1, err_bad_car, V80);
}

/*
(DEFUN BOOT::|newExpandLocalType| (BOOT::|lazyt|
      BOOT::|dollar|
      BOOT::|domain|)
   (PROG (BOOT::|vec| BOOT::|ISTMP#1| BOOT::|lazyForm|)
      (RETURN
         (COND
            ((VMLISP:VECP BOOT::|lazyt|) (ELT BOOT::|lazyt| 0))
            ((BOOT::|isDomain| BOOT::|lazyt|)
               (BOOT::|devaluate| BOOT::|lazyt|))
            ((ATOM BOOT::|lazyt|) BOOT::|lazyt|)
            ((AND
                (PAIRP BOOT::|lazyt|)
                (PROGN
                   (BOOT:SPADLET BOOT::|vec| (QCAR BOOT::|lazyt|))
                   (BOOT:SPADLET BOOT::|ISTMP#1| (QCDR BOOT::|lazyt|))
                   (AND
                      (PAIRP BOOT::|ISTMP#1|)
                      (PROGN
                         (BOOT:SPADLET
                            BOOT::|lazyForm|
                            (QCDR BOOT::|ISTMP#1|))
                         'T)))
                (VMLISP:VECP BOOT::|vec|))
               (BOOT::|newExpandLocalTypeForm|
                  BOOT::|lazyForm|
                  BOOT::|dollar|
                  BOOT::|domain|))
            ('T
               (BOOT::|newExpandLocalTypeForm|
                  BOOT::|lazyt|
                  BOOT::|dollar|
                  BOOT::|domain|)))) ))

*/



/* Code for BOOT::|newExpandLocalType| */

static Lisp_Object MS_CDECL CC_BOOT__newExpandLocalType(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V87, V88, V89;
    Lisp_Object fn;
    argcheck(nargs, 3, "newExpandLocalType");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|newExpandLocalType|\n");
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
    stack[0] = nil;
    V87 = stack[-4];
    fn = elt(env, 1); /* SIMPLE-VECTOR-P */
    V87 = (*qfn1(fn))(qenv(fn), V87);
    nil = C_nil;
    if (exception_pending()) goto V96;
    env = stack[-6];
    if (V87 == nil) goto V16;
    V88 = stack[-4];
    V87 = (Lisp_Object)1; /* 0 */
    {
        popv(7);
        fn = elt(env, 2); /* ELT */
        return (*qfn2(fn))(qenv(fn), V88, V87);
    }

V16:
    V87 = stack[-4];
    fn = elt(env, 3); /* BOOT::|isDomain| */
    V87 = (*qfn1(fn))(qenv(fn), V87);
    nil = C_nil;
    if (exception_pending()) goto V96;
    env = stack[-6];
    if (V87 == nil) goto V28;
    V87 = stack[-4];
    {
        popv(7);
        fn = elt(env, 4); /* BOOT::|devaluate| */
        return (*qfn1(fn))(qenv(fn), V87);
    }

V28:
    V87 = stack[-4];
    if (!consp(V87)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    V87 = stack[-4];
    fn = elt(env, 5); /* CONSP */
    V87 = (*qfn1(fn))(qenv(fn), V87);
    nil = C_nil;
    if (exception_pending()) goto V96;
    env = stack[-6];
    if (V87 == nil) goto V38;
    V87 = stack[-4];
    V87 = qcar(V87);
    stack[-5] = V87;
    V87 = stack[-4];
    V87 = qcdr(V87);
    stack[-1] = V87;
    V87 = stack[-1];
    fn = elt(env, 5); /* CONSP */
    V87 = (*qfn1(fn))(qenv(fn), V87);
    nil = C_nil;
    if (exception_pending()) goto V96;
    env = stack[-6];
    if (V87 == nil) goto V49;
    V87 = stack[-1];
    V87 = qcdr(V87);
    stack[0] = V87;
    V87 = lisp_true;
    goto V48;

V48:
    if (V87 == nil) goto V38;
    V87 = stack[-5];
    fn = elt(env, 1); /* SIMPLE-VECTOR-P */
    V87 = (*qfn1(fn))(qenv(fn), V87);
    nil = C_nil;
    if (exception_pending()) goto V96;
    env = stack[-6];
    if (V87 == nil) goto V38;
    V89 = stack[0];
    V88 = stack[-3];
    V87 = stack[-2];
    {
        popv(7);
        fn = elt(env, 6); /* BOOT::|newExpandLocalTypeForm| */
        return (*qfnn(fn))(qenv(fn), 3, V89, V88, V87);
    }

V38:
    V87 = lisp_true;
    if (V87 == nil) goto V74;
    V89 = stack[-4];
    V88 = stack[-3];
    V87 = stack[-2];
    {
        popv(7);
        fn = elt(env, 6); /* BOOT::|newExpandLocalTypeForm| */
        return (*qfnn(fn))(qenv(fn), 3, V89, V88, V87);
    }

V74:
    V87 = nil;
    { popv(7); return onevalue(V87); }

V49:
    V87 = nil;
    goto V48;
/* error exit handlers */
V96:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|isDefaultPackageForm?| (|x|)
   (PROG (BOOT::|op| |s|)
      (RETURN
         (AND
            (PAIRP |x|)
            (PROGN (BOOT:SPADLET BOOT::|op| (QCAR |x|)) 'T)
            (VMLISP:IDENTP BOOT::|op|)
            (BOOT:|BOOT-EQUAL|
               (ELT
                  (BOOT:SPADLET |s| (SYSTEM::PNAME BOOT::|op|))
                  (VMLISP:MAXINDEX |s|))
               '|&|)))) )

*/



/* Code for BOOT::|isDefaultPackageForm?| */

static Lisp_Object CC_BOOT__isDefaultPackageFormW(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V78, V79;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isDefaultPackageForm?|\n");
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
    V78 = stack[0];
    fn = elt(env, 2); /* CONSP */
    V78 = (*qfn1(fn))(qenv(fn), V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    if (V78 == nil) goto V12;
    V78 = stack[0];
    V78 = qcar(V78);
    stack[-1] = V78;
    V78 = lisp_true;
    if (V78 == nil) goto V17;
    V78 = stack[-1];
    if (V78 == nil) goto V27;
    V78 = stack[-1];
    fn = elt(env, 3); /* SYMBOLP */
    V78 = (*qfn1(fn))(qenv(fn), V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    goto V26;

V26:
    if (V78 == nil) goto V23;
    V78 = stack[-1];
    fn = elt(env, 4); /* SYSTEM::PNAME */
    stack[0] = (*qfn1(fn))(qenv(fn), V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    V78 = stack[0];
    V78 = Llength(nil, V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    V78 = sub1(V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    fn = elt(env, 5); /* ELT */
    V79 = (*qfn2(fn))(qenv(fn), stack[0], V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    V78 = elt(env, 1); /* BOOT::& */
    V78 = Leql(nil, V79, V78);
    env = stack[-2];
    if (!(V78 == nil)) { popv(3); return onevalue(V78); }
    V78 = stack[-1];
    fn = elt(env, 4); /* SYSTEM::PNAME */
    stack[0] = (*qfn1(fn))(qenv(fn), V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    V78 = stack[0];
    V78 = Llength(nil, V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    V78 = sub1(V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    fn = elt(env, 5); /* ELT */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    V78 = elt(env, 1); /* BOOT::& */
    fn = elt(env, 6); /* CHARACTER */
    V78 = (*qfn1(fn))(qenv(fn), V78);
    nil = C_nil;
    if (exception_pending()) goto V82;
    {
        Lisp_Object V83 = stack[0];
        popv(3);
        return Leql(nil, V83, V78);
    }

V23:
    V78 = nil;
    { popv(3); return onevalue(V78); }

V27:
    V78 = nil;
    goto V26;

V17:
    V78 = nil;
    { popv(3); return onevalue(V78); }

V12:
    V78 = nil;
    { popv(3); return onevalue(V78); }
/* error exit handlers */
V82:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|A1AGG-;=;2AB;28| (|x| |y| |$|)
   (PROG (|i| #:G86200 #:G86199 #:G86197)
      (RETURN
         (SEQ
            (EXIT
               (COND
                  ((NULL
                      (EQL
                         (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 45))
                         (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 45))))
                     'NIL)
                  ('T
                     (SEQ
                        (SEQ
                           (EXIT
                              (SEQ
                                 (BOOT::LETT
                                    |i|
                                    (BOOT:SPADCALL
                                       |x|
                                       (VMLISP:QREFELT |$| 9))
                                    BOOT::|A1AGG-;=;2AB;28|)
                                 (BOOT::LETT
                                    #:G86200
                                    (BOOT:SPADCALL
                                       |x|
                                       (VMLISP:QREFELT |$| 10))
                                    BOOT::|A1AGG-;=;2AB;28|)
                                 BOOT::G190
                                 (COND
                                    ((|>| |i| #:G86200) (GO BOOT::G191)))
                                 (SEQ
                                    (EXIT
                                       (COND
                                          ((NULL
                                              (BOOT:SPADCALL
                                                 (BOOT:SPADCALL
                                                    |x|
                                                    |i|
                                                    (VMLISP:QREFELT
                                                       |$|
                                                       11))
                                                 (BOOT:SPADCALL
                                                    |y|
                                                    |i|
                                                    (VMLISP:QREFELT
                                                       |$|
                                                       11))
                                                 (VMLISP:QREFELT |$| 39)))
                                             (PROGN
                                                (BOOT::LETT
                                                   #:G86197
                                                   (PROGN
        (BOOT::LETT #:G86199 'NIL BOOT::|A1AGG-;=;2AB;28|)
        (GO #:G86199))
                                                   BOOT::|A1AGG-;=;2AB;28|)
                                                (GO #:G86197)))) ))
                                 (BOOT::LETT
                                    |i|
                                    (|+| |i| 1)
                                    BOOT::|A1AGG-;=;2AB;28|)
                                 (GO BOOT::G190)
                                 BOOT::G191
                                 (EXIT NIL)))
                           #:G86197
                           (EXIT #:G86197))
                        (EXIT 'T)))) )
            #:G86199
            (EXIT #:G86199)))) )

*/



/* Code for BOOT::|A1AGG-;=;2AB;28| */

static Lisp_Object MS_CDECL CC_BOOT__A1AGGKUMU2ABU28(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V245, V246, V247, V248;
    argcheck(nargs, 3, "A1AGG-;=;2AB;28");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|A1AGG-;=;2AB;28|\n");
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
    V246 = stack[-4];
    V245 = (Lisp_Object)721; /* 45 */
    V245 = Lgetv(nil, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    V246 = V245;
    if (!car_legal(V246)) goto V258;
    V247 = qcar(V246);
    V246 = stack[-6];
    if (!car_legal(V245)) goto V259;
    V245 = qcdr(V245);
    V245 = Lapply2(nil, 3, V247, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    stack[0] = V245;
    V246 = stack[-4];
    V245 = (Lisp_Object)721; /* 45 */
    V245 = Lgetv(nil, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    V246 = V245;
    if (!car_legal(V246)) goto V258;
    V247 = qcar(V246);
    V246 = stack[-5];
    if (!car_legal(V245)) goto V259;
    V245 = qcdr(V245);
    V245 = Lapply2(nil, 3, V247, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    V245 = Leql(nil, stack[0], V245);
    env = stack[-8];
    if (V245 == nil) goto V19;
    V245 = lisp_true;
    if (V245 == nil) goto V77;
    V246 = stack[-4];
    V245 = (Lisp_Object)145; /* 9 */
    V245 = Lgetv(nil, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    V246 = V245;
    if (!car_legal(V246)) goto V258;
    V247 = qcar(V246);
    V246 = stack[-6];
    if (!car_legal(V245)) goto V259;
    V245 = qcdr(V245);
    V245 = Lapply2(nil, 3, V247, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    stack[-7] = V245;
    V246 = stack[-4];
    V245 = (Lisp_Object)161; /* 10 */
    V245 = Lgetv(nil, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    V246 = V245;
    if (!car_legal(V246)) goto V258;
    V247 = qcar(V246);
    V246 = stack[-6];
    if (!car_legal(V245)) goto V259;
    V245 = qcdr(V245);
    V245 = Lapply2(nil, 3, V247, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    stack[-3] = V245;
    goto V141;

V141:
    V246 = stack[-7];
    V245 = stack[-3];
    V245 = (Lisp_Object)greaterp2(V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    V245 = V245 ? lisp_true : nil;
    env = stack[-8];
    if (V245 == nil) goto V158;
    V245 = lisp_true;
    { popv(9); return onevalue(V245); }

V158:
    V246 = stack[-4];
    V245 = (Lisp_Object)625; /* 39 */
    V245 = Lgetv(nil, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    stack[-2] = V245;
    V245 = stack[-2];
    if (!car_legal(V245)) goto V260;
    stack[-1] = qcar(V245);
    V246 = stack[-4];
    V245 = (Lisp_Object)177; /* 11 */
    V245 = Lgetv(nil, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    V246 = V245;
    if (!car_legal(V246)) goto V258;
    V248 = qcar(V246);
    V247 = stack[-6];
    V246 = stack[-7];
    if (!car_legal(V245)) goto V259;
    V245 = qcdr(V245);
    V245 = Lapply3(nil, 4, V248, V247, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    stack[0] = V245;
    V246 = stack[-4];
    V245 = (Lisp_Object)177; /* 11 */
    V245 = Lgetv(nil, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    V246 = V245;
    if (!car_legal(V246)) goto V258;
    V248 = qcar(V246);
    V247 = stack[-5];
    V246 = stack[-7];
    if (!car_legal(V245)) goto V259;
    V245 = qcdr(V245);
    V245 = Lapply3(nil, 4, V248, V247, V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    V246 = V245;
    V245 = stack[-2];
    if (!car_legal(V245)) goto V259;
    V245 = qcdr(V245);
    V245 = Lapply3(nil, 4, stack[-1], stack[0], V246, V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    if (V245 == nil) goto V152;
    V245 = stack[-7];
    V245 = add1(V245);
    nil = C_nil;
    if (exception_pending()) goto V257;
    env = stack[-8];
    stack[-7] = V245;
    goto V141;

V152:
    V245 = nil;
    { popv(9); return onevalue(V245); }

V77:
    V245 = nil;
    { popv(9); return onevalue(V245); }

V19:
    V245 = nil;
    { popv(9); return onevalue(V245); }
/* error exit handlers */
V260:
    popv(9);
    return error(1, err_bad_car, V245);
V259:
    popv(9);
    return error(1, err_bad_cdr, V245);
V258:
    popv(9);
    return error(1, err_bad_car, V246);
V257:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|EXPR;coerce;Smp$;24| (|p| |$|)
   (BOOT:SPADCALL |p| (VMLISP:QREFELT |$| 83)))

*/



/* Code for BOOT::|EXPR;coerce;Smp$;24| */

static Lisp_Object CC_BOOT__EXPRUcoerceUSmpDU24(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;coerce;Smp$;24|\n");
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
    V31 = (Lisp_Object)1329; /* 83 */
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
(DEFUN BOOT::|PR;*;3$;21| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (BOOT::|yy| BOOT::|xx| BOOT::|tx| #:G111044 BOOT::|res|)
      (RETURN
         (SEQ
            (BOOT::LETT BOOT::|xx| BOOT::|p1| BOOT::|PR;*;3$;21|)
            (EXIT
               (COND
                  ((NULL BOOT::|xx|) BOOT::|p1|)
                  ('T
                     (SEQ
                        (BOOT::LETT
                           BOOT::|yy|
                           BOOT::|p2|
                           BOOT::|PR;*;3$;21|)
                        (EXIT
                           (COND
                              ((NULL BOOT::|yy|) BOOT::|p2|)
                              ((BOOT:SPADCALL
                                  (QCAR (BOOT::|SPADfirst| BOOT::|xx|))
                                  (VMLISP:QREFELT |$| 26))
                                 (BOOT:SPADCALL
                                    (QCDR (BOOT::|SPADfirst| BOOT::|xx|))
                                    BOOT::|p2|
                                    (VMLISP:QREFELT |$| 48)))
                              ((BOOT:SPADCALL
                                  (QCAR (BOOT::|SPADfirst| BOOT::|yy|))
                                  (VMLISP:QREFELT |$| 26))
                                 (BOOT:SPADCALL
                                    BOOT::|p1|
                                    (QCDR (BOOT::|SPADfirst| BOOT::|yy|))
                                    (VMLISP:QREFELT |$| 49)))
                              ('T
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|xx|
                                       (REVERSE BOOT::|xx|)
                                       BOOT::|PR;*;3$;21|)
                                    (BOOT::LETT
                                       BOOT::|res|
                                       NIL
                                       BOOT::|PR;*;3$;21|)
                                    (SEQ
                                       (BOOT::LETT
                                          BOOT::|tx|
                                          NIL
                                          BOOT::|PR;*;3$;21|)
                                       (BOOT::LETT
                                          #:G111044
                                          BOOT::|xx|
                                          BOOT::|PR;*;3$;21|)
                                       BOOT::G190
                                       (COND
                                          ((OR
                                              (ATOM #:G111044)
                                              (PROGN
                                                 (BOOT::LETT
                                                    BOOT::|tx|
                                                    (CAR #:G111044)
                                                    BOOT::|PR;*;3$;21|)
                                                 NIL))
                                             (GO BOOT::G191)))
                                       (SEQ
                                          (EXIT
                                             (BOOT::LETT
                                                BOOT::|res|
                                                (BOOT::|PR;addm!|
                                                   BOOT::|res|
                                                   (QCDR BOOT::|tx|)
                                                   (QCAR BOOT::|tx|)
                                                   BOOT::|yy|
                                                   |$|)
                                                BOOT::|PR;*;3$;21|)))
                                       (BOOT::LETT
                                          #:G111044
                                          (CDR #:G111044)
                                          BOOT::|PR;*;3$;21|)
                                       (GO BOOT::G190)
                                       BOOT::G191
                                       (EXIT NIL))
                                    (EXIT BOOT::|res|)))) ))) ))) )))

*/



/* Code for BOOT::|PR;*;3$;21| */

static Lisp_Object MS_CDECL CC_BOOT__PRUHU3DU21(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V244, V245, V246, V247, V248;
    Lisp_Object fn;
    argcheck(nargs, 3, "PR;*;3$;21");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PR;*;3$;21|\n");
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
    V244 = stack[-5];
    stack[-2] = V244;
    V244 = stack[-2];
    if (V244 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    V244 = lisp_true;
    if (V244 == nil) goto V25;
    V244 = stack[-4];
    stack[-6] = V244;
    V244 = stack[-6];
    if (V244 == nil) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    V245 = stack[-3];
    V244 = (Lisp_Object)417; /* 26 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-7];
    stack[-1] = V244;
    V244 = stack[-1];
    if (!car_legal(V244)) goto V257;
    stack[0] = qcar(V244);
    V244 = stack[-2];
    V245 = V244;
    V244 = V245;
    if (V244 == nil) goto V66;
    V244 = V245;
    if (!car_legal(V244)) goto V257;
    V244 = qcar(V244);
    goto V61;

V61:
    V245 = qcar(V244);
    V244 = stack[-1];
    if (!car_legal(V244)) goto V258;
    V244 = qcdr(V244);
    V244 = Lapply2(nil, 3, stack[0], V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-7];
    if (V244 == nil) goto V119;
    V245 = stack[-3];
    V244 = (Lisp_Object)769; /* 48 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-7];
    stack[-1] = V244;
    V244 = stack[-1];
    if (!car_legal(V244)) goto V257;
    stack[0] = qcar(V244);
    V244 = stack[-2];
    V245 = V244;
    V244 = V245;
    if (V244 == nil) goto V104;
    V244 = V245;
    if (!car_legal(V244)) goto V257;
    V244 = qcar(V244);
    goto V99;

V99:
    V246 = qcdr(V244);
    V245 = stack[-4];
    V244 = stack[-1];
    if (!car_legal(V244)) goto V258;
    V244 = qcdr(V244);
    {
        Lisp_Object V259 = stack[0];
        popv(8);
        return Lapply3(nil, 4, V259, V246, V245, V244);
    }

V104:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V244 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V256;
    goto V99;

V119:
    V245 = stack[-3];
    V244 = (Lisp_Object)417; /* 26 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-7];
    stack[-1] = V244;
    V244 = stack[-1];
    if (!car_legal(V244)) goto V257;
    stack[0] = qcar(V244);
    V244 = stack[-6];
    V245 = V244;
    V244 = V245;
    if (V244 == nil) goto V143;
    V244 = V245;
    if (!car_legal(V244)) goto V257;
    V244 = qcar(V244);
    goto V138;

V138:
    V245 = qcar(V244);
    V244 = stack[-1];
    if (!car_legal(V244)) goto V258;
    V244 = qcdr(V244);
    V244 = Lapply2(nil, 3, stack[0], V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-7];
    if (V244 == nil) goto V114;
    V245 = stack[-3];
    V244 = (Lisp_Object)785; /* 49 */
    V244 = Lgetv(nil, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-7];
    stack[-1] = V244;
    V244 = stack[-1];
    if (!car_legal(V244)) goto V257;
    stack[0] = qcar(V244);
    stack[-2] = stack[-5];
    V244 = stack[-6];
    V245 = V244;
    V244 = V245;
    if (V244 == nil) goto V182;
    V244 = V245;
    if (!car_legal(V244)) goto V257;
    V244 = qcar(V244);
    goto V177;

V177:
    V245 = qcdr(V244);
    V244 = stack[-1];
    if (!car_legal(V244)) goto V258;
    V244 = qcdr(V244);
    {
        Lisp_Object V260 = stack[0];
        Lisp_Object V261 = stack[-2];
        popv(8);
        return Lapply3(nil, 4, V260, V261, V245, V244);
    }

V182:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V244 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V256;
    goto V177;

V114:
    V244 = lisp_true;
    if (V244 == nil) goto V191;
    V244 = stack[-2];
    V244 = Lreverse(nil, V244);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-7];
    stack[-2] = V244;
    V244 = nil;
    V246 = V244;
    V244 = stack[-2];
    stack[0] = V244;
    goto V200;

V200:
    V244 = stack[0];
    if (!consp(V244)) { popv(8); return onevalue(V246); }
    V244 = stack[0];
    if (!car_legal(V244)) goto V257;
    V244 = qcar(V244);
    V245 = nil;
    if (!(V245 == nil)) { popv(8); return onevalue(V246); }
    V248 = V246;
    V245 = V244;
    V247 = qcdr(V245);
    V246 = qcar(V244);
    V245 = stack[-6];
    V244 = stack[-3];
    fn = elt(env, 2); /* BOOT::|PR;addm!| */
    V244 = (*qfnn(fn))(qenv(fn), 5, V248, V247, V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-7];
    V246 = V244;
    V244 = stack[0];
    if (!car_legal(V244)) goto V258;
    V244 = qcdr(V244);
    stack[0] = V244;
    goto V200;

V191:
    V244 = nil;
    { popv(8); return onevalue(V244); }

V143:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V244 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-7];
    goto V138;

V66:
    fn = elt(env, 1); /* BOOT::FIRST-ERROR */
    V244 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V256;
    env = stack[-7];
    goto V61;

V25:
    V244 = nil;
    { popv(8); return onevalue(V244); }
/* error exit handlers */
V258:
    popv(8);
    return error(1, err_bad_cdr, V244);
V257:
    popv(8);
    return error(1, err_bad_car, V244);
V256:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|superspan| (|u|)
   (COND
      ((ATOM |u|) 0)
      ((NUMBERP (CDR |u|)) (BOOT::|superspan| (CAR |u|)))
      ((AND
          (NULL (ATOM (CAR |u|)))
          (ATOM (CAAR |u|))
          (NULL (NUMBERP (CAAR |u|)))
          (VMLISP:GETL (CAAR |u|) 'BOOT::SUPERSPAN))
         (VMLISP:APPLX
            (VMLISP:GETL (CAAR |u|) 'BOOT::SUPERSPAN)
            (LIST |u|)))
      ('T
         (MAX
            (BOOT::|superspan| (CAR |u|))
            (BOOT::|superspan| (CDR |u|)))) ))

*/



/* Code for BOOT::|superspan| */

static Lisp_Object CC_BOOT__superspan(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V76, V77;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|superspan|\n");
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

V1:
    V76 = stack[0];
    if (!consp(V76)) goto V8;
    V76 = stack[0];
    if (!car_legal(V76)) goto V80;
    V76 = qcdr(V76);
    if (is_number(V76)) goto V12;
    V76 = stack[0];
    if (!car_legal(V76)) goto V81;
    V76 = qcar(V76);
    if (!consp(V76)) goto V20;
    V76 = stack[0];
    if (!car_legal(V76)) goto V81;
    V76 = qcar(V76);
    if (!car_legal(V76)) goto V81;
    V76 = qcar(V76);
    if (!(!consp(V76))) goto V20;
    V76 = stack[0];
    if (!car_legal(V76)) goto V81;
    V76 = qcar(V76);
    if (!car_legal(V76)) goto V81;
    V76 = qcar(V76);
    if (is_number(V76)) goto V20;
    V76 = stack[0];
    if (!car_legal(V76)) goto V81;
    V76 = qcar(V76);
    if (!car_legal(V76)) goto V81;
    V77 = qcar(V76);
    V76 = elt(env, 1); /* BOOT::SUPERSPAN */
    fn = elt(env, 2); /* VMLISP:GETL */
    V76 = (*qfn2(fn))(qenv(fn), V77, V76);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    if (V76 == nil) goto V20;
    V76 = stack[0];
    if (!car_legal(V76)) goto V81;
    V76 = qcar(V76);
    if (!car_legal(V76)) goto V81;
    V77 = qcar(V76);
    V76 = elt(env, 1); /* BOOT::SUPERSPAN */
    fn = elt(env, 2); /* VMLISP:GETL */
    stack[-1] = (*qfn2(fn))(qenv(fn), V77, V76);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    V76 = stack[0];
    V76 = ncons(V76);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    {
        Lisp_Object V83 = stack[-1];
        popv(3);
        fn = elt(env, 3); /* APPLY */
        return (*qfn2(fn))(qenv(fn), V83, V76);
    }

V20:
    V76 = lisp_true;
    if (V76 == nil) goto V62;
    V76 = stack[0];
    if (!car_legal(V76)) goto V81;
    V76 = qcar(V76);
    stack[-1] = CC_BOOT__superspan(env, V76);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    V76 = stack[0];
    if (!car_legal(V76)) goto V80;
    V76 = qcdr(V76);
    V76 = CC_BOOT__superspan(env, V76);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    {
        Lisp_Object V84 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* MAX */
        return (*qfn2(fn))(qenv(fn), V84, V76);
    }

V62:
    V76 = nil;
    { popv(3); return onevalue(V76); }

V12:
    V76 = stack[0];
    if (!car_legal(V76)) goto V81;
    V76 = qcar(V76);
    stack[0] = V76;
    goto V1;

V8:
    V76 = (Lisp_Object)1; /* 0 */
    { popv(3); return onevalue(V76); }
/* error exit handlers */
V82:
    popv(3);
    return nil;
V81:
    popv(3);
    return error(1, err_bad_car, V76);
V80:
    popv(3);
    return error(1, err_bad_cdr, V76);
}

/*
(DEFUN BOOT::|SET;empty;$;4| (|$|) (BOOT:SPADCALL (VMLISP:QREFELT |$| 14)))

*/



/* Code for BOOT::|SET;empty;$;4| */

static Lisp_Object CC_BOOT__SETUemptyUDU4(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V27, V28;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SET;empty;$;4|\n");
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
    V27 = V2;
/* end of prologue */
    V28 = V27;
    V27 = (Lisp_Object)225; /* 14 */
    V27 = Lgetv(nil, V28, V27);
    errexit();
    V28 = V27;
    if (!car_legal(V28)) goto V29;
    V28 = qcar(V28);
    if (!car_legal(V27)) goto V30;
    V27 = qcdr(V27);
        return Lapply1(nil, V28, V27);
/* error exit handlers */
V30:
    return error(1, err_bad_cdr, V27);
V29:
    return error(1, err_bad_car, V28);
}

/*
(DEFUN BOOT::|A1AGG-;sort!;M2A;2| (|f| |a| |$|)
   (BOOT:SPADCALL |f| |a| (VMLISP:QREFELT |$| 16)))

*/



/* Code for BOOT::|A1AGG-;sort!;M2A;2| */

static Lisp_Object MS_CDECL CC_BOOT__A1AGGKUsortBUM2AU2(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "A1AGG-;sort!;M2A;2");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|A1AGG-;sort!;M2A;2|\n");
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
    V35 = (Lisp_Object)257; /* 16 */
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
(DEFUN |SUB-WRITE-STRING| (OBJECT)
   (IF |*PRINT-ESCAPE*| (|~TYO| "))
   (DOTIMES (I (LENGTH OBJECT))
      (LET ((C (CHAR OBJECT I)))
         (IF (AND |*PRINT-ESCAPE*| (OR (|CHAR=| C ") (|CHAR=| C \)))
            (|~TYO| \))
         (|~TYO| C)))
   (IF |*PRINT-ESCAPE*| (|~TYO| "))
   OBJECT)

*/



/* Code for SUB-WRITE-STRING */

static Lisp_Object CC_LISP__SUBKWRITEKSTRING(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V93, V94;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering SUB-WRITE-STRING\n");
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
    V93 = qvalue(elt(env, 1)); /* *PRINT-ESCAPE* */
    if (V93 == nil) goto V7;
    V93 = elt(env, 2); /* #\" */
    fn = elt(env, 4); /* ~TYO */
    V93 = (*qfn1(fn))(qenv(fn), V93);
    nil = C_nil;
    if (exception_pending()) goto V98;
    env = stack[-3];
    goto V7;

V7:
    V93 = (Lisp_Object)1; /* 0 */
    stack[-2] = V93;
    goto V26;

V26:
    stack[0] = stack[-2];
    V93 = stack[-1];
    V93 = Llength(nil, V93);
    nil = C_nil;
    if (exception_pending()) goto V98;
    env = stack[-3];
    fn = elt(env, 5); /* >= */
    V93 = (*qfn2(fn))(qenv(fn), stack[0], V93);
    nil = C_nil;
    if (exception_pending()) goto V98;
    env = stack[-3];
    if (V93 == nil) goto V40;
    V93 = qvalue(elt(env, 1)); /* *PRINT-ESCAPE* */
    if (V93 == nil) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    V93 = elt(env, 2); /* #\" */
    fn = elt(env, 4); /* ~TYO */
    V93 = (*qfn1(fn))(qenv(fn), V93);
    nil = C_nil;
    if (exception_pending()) goto V98;
    { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

V40:
    V94 = stack[-1];
    V93 = stack[-2];
    fn = elt(env, 6); /* CHAR */
    V93 = (*qfn2(fn))(qenv(fn), V94, V93);
    nil = C_nil;
    if (exception_pending()) goto V98;
    env = stack[-3];
    stack[0] = V93;
    V93 = qvalue(elt(env, 1)); /* *PRINT-ESCAPE* */
    if (V93 == nil) goto V48;
    V94 = stack[0];
    V93 = elt(env, 2); /* #\" */
    fn = elt(env, 7); /* CHAR= */
    V93 = (*qfn2(fn))(qenv(fn), V94, V93);
    nil = C_nil;
    if (exception_pending()) goto V98;
    env = stack[-3];
    if (!(V93 == nil)) goto V49;
    V94 = stack[0];
    V93 = elt(env, 3); /* #\\ */
    fn = elt(env, 7); /* CHAR= */
    V93 = (*qfn2(fn))(qenv(fn), V94, V93);
    nil = C_nil;
    if (exception_pending()) goto V98;
    env = stack[-3];
    if (!(V93 == nil)) goto V49;

V48:
    V93 = stack[0];
    fn = elt(env, 4); /* ~TYO */
    V93 = (*qfn1(fn))(qenv(fn), V93);
    nil = C_nil;
    if (exception_pending()) goto V98;
    env = stack[-3];
    V93 = stack[-2];
    V93 = add1(V93);
    nil = C_nil;
    if (exception_pending()) goto V98;
    env = stack[-3];
    stack[-2] = V93;
    goto V26;

V49:
    V93 = elt(env, 3); /* #\\ */
    fn = elt(env, 4); /* ~TYO */
    V93 = (*qfn1(fn))(qenv(fn), V93);
    nil = C_nil;
    if (exception_pending()) goto V98;
    env = stack[-3];
    goto V48;
/* error exit handlers */
V98:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|hasCat| (BOOT::|domainOrCatName| BOOT::|catName|)
   (OR
      (BOOT:|BOOT-EQUAL| BOOT::|catName| 'BOOT::|Object|)
      (BOOT:|BOOT-EQUAL| BOOT::|catName| 'BOOT::|Type|)
      (BOOT::GETDATABASE
         (CONS BOOT::|domainOrCatName| BOOT::|catName|)
         'BOOT::HASCATEGORY)))

*/



/* Code for BOOT::|hasCat| */

static Lisp_Object CC_BOOT__hasCat(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V42, V43, V44, V45;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|hasCat|\n");
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
    V44 = V3;
    V45 = V2;
/* end of prologue */
    V43 = V44;
    V42 = elt(env, 1); /* BOOT::|Object| */
    V42 = (V43 == V42 ? lisp_true : nil);
    if (!(V42 == nil)) { popv(1); return onevalue(V42); }
    V43 = V44;
    V42 = elt(env, 2); /* BOOT::|Type| */
    V42 = (V43 == V42 ? lisp_true : nil);
    if (!(V42 == nil)) { popv(1); return onevalue(V42); }
    V42 = V45;
    V43 = V44;
    V43 = cons(V42, V43);
    nil = C_nil;
    if (exception_pending()) goto V46;
    env = stack[0];
    V42 = elt(env, 3); /* BOOT::HASCATEGORY */
    {
        popv(1);
        fn = elt(env, 4); /* BOOT::GETDATABASE */
        return (*qfn2(fn))(qenv(fn), V43, V42);
    }
/* error exit handlers */
V46:
    popv(1);
    return nil;
}

/*
(DEFUN BOOT::|ncAlist| (|x|)
   (PROG NIL
      (RETURN
         (COND
            ((NULL (CONSP |x|)) (BOOT::|ncBug| 'BOOT::S2CB0031 NIL))
            ('T
               (PROGN
                  (SETQ |x| (QCAR |x|))
                  (COND
                     ((VMLISP:IDENTP |x|) NIL)
                     ((NULL (CONSP |x|))
                        (BOOT::|ncBug| 'BOOT::S2CB0031 NIL))
                     ('T (QCDR |x|)))) ))) ))

*/



/* Code for BOOT::|ncAlist| */

static Lisp_Object CC_BOOT__ncAlist(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V57, V58;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ncAlist|\n");
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
    V57 = stack[0];
    if (!consp(V57)) goto V14;
    V57 = lisp_true;
    if (V57 == nil) goto V22;
    V57 = stack[0];
    V57 = qcar(V57);
    stack[0] = V57;
    V57 = stack[0];
    if (V57 == nil) goto V32;
    V57 = stack[0];
    fn = elt(env, 2); /* SYMBOLP */
    V57 = (*qfn1(fn))(qenv(fn), V57);
    nil = C_nil;
    if (exception_pending()) goto V60;
    env = stack[-1];
    goto V31;

V31:
    if (V57 == nil) goto V29;
    V57 = nil;
    { popv(2); return onevalue(V57); }

V29:
    V57 = stack[0];
    if (!consp(V57)) goto V45;
    V57 = lisp_true;
    if (V57 == nil) goto V53;
    V57 = stack[0];
    V57 = qcdr(V57);
    { popv(2); return onevalue(V57); }

V53:
    V57 = nil;
    { popv(2); return onevalue(V57); }

V45:
    V58 = elt(env, 1); /* BOOT::S2CB0031 */
    V57 = nil;
    {
        popv(2);
        fn = elt(env, 3); /* BOOT::|ncBug| */
        return (*qfn2(fn))(qenv(fn), V58, V57);
    }

V32:
    V57 = nil;
    goto V31;

V22:
    V57 = nil;
    { popv(2); return onevalue(V57); }

V14:
    V58 = elt(env, 1); /* BOOT::S2CB0031 */
    V57 = nil;
    {
        popv(2);
        fn = elt(env, 3); /* BOOT::|ncBug| */
        return (*qfn2(fn))(qenv(fn), V58, V57);
    }
/* error exit handlers */
V60:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|INS-;symmetricRemainder;3S;27| (|x| |n| |$|)
   (PROG (|r|)
      (RETURN
         (SEQ
            (BOOT::LETT
               |r|
               (BOOT:SPADCALL |x| |n| (VMLISP:QREFELT |$| 74))
               BOOT::|INS-;symmetricRemainder;3S;27|)
            (EXIT
               (COND
                  ((BOOT:SPADCALL
                      |r|
                      (BOOT::|spadConstant| |$| 9)
                      (VMLISP:QREFELT |$| 24))
                     |r|)
                  ('T
                     (SEQ
                        (COND
                           ((BOOT:SPADCALL
                               |n|
                               (BOOT::|spadConstant| |$| 9)
                               (VMLISP:QREFELT |$| 14))
                              (BOOT::LETT
                                 |n|
                                 (BOOT:SPADCALL
                                    |n|
                                    (VMLISP:QREFELT |$| 17))
                                 BOOT::|INS-;symmetricRemainder;3S;27|)))
                        (EXIT
                           (COND
                              ((BOOT:SPADCALL
                                  (BOOT::|spadConstant| |$| 9)
                                  |r|
                                  (VMLISP:QREFELT |$| 14))
                                 (COND
                                    ((BOOT:SPADCALL
                                        |n|
                                        (BOOT:SPADCALL
                                           2
                                           |r|
                                           (VMLISP:QREFELT |$| 76))
                                        (VMLISP:QREFELT |$| 14))
                                       (BOOT:SPADCALL
                                          |r|
                                          |n|
                                          (VMLISP:QREFELT |$| 61)))
                                    ('T |r|)))
                              ((NULL
                                  (BOOT:SPADCALL
                                     (BOOT::|spadConstant| |$| 9)
                                     (BOOT:SPADCALL
                                        (BOOT:SPADCALL
                                           2
                                           |r|
                                           (VMLISP:QREFELT |$| 76))
                                        |n|
                                        (VMLISP:QREFELT |$| 77))
                                     (VMLISP:QREFELT |$| 14)))
                                 (BOOT:SPADCALL
                                    |r|
                                    |n|
                                    (VMLISP:QREFELT |$| 77)))
                              ('T |r|)))) ))) ))) )

*/



/* Code for BOOT::|INS-;symmetricRemainder;3S;27| */

static Lisp_Object MS_CDECL CC_BOOT__INSKUsymmetricRemainderU3SU27(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V445, V446, V447, V448;
    argcheck(nargs, 3, "INS-;symmetricRemainder;3S;27");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|INS-;symmetricRemainder;3S;27|\n");
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
    V446 = stack[-5];
    V445 = (Lisp_Object)1185; /* 74 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    if (!car_legal(V446)) goto V458;
    V448 = qcar(V446);
    V447 = stack[0];
    V446 = stack[-6];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply3(nil, 4, V448, V447, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    stack[-7] = V445;
    V446 = stack[-5];
    V445 = (Lisp_Object)385; /* 24 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    stack[-2] = V445;
    V445 = stack[-2];
    if (!car_legal(V445)) goto V460;
    stack[-1] = qcar(V445);
    stack[0] = stack[-7];
    V446 = stack[-5];
    V445 = (Lisp_Object)145; /* 9 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    if (!car_legal(V446)) goto V458;
    V446 = qcar(V446);
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply1(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    V445 = stack[-2];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply3(nil, 4, stack[-1], stack[0], V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    if (!(V445 == nil)) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    V445 = lisp_true;
    if (V445 == nil) goto V93;
    V446 = stack[-5];
    V445 = (Lisp_Object)225; /* 14 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    stack[-2] = V445;
    V445 = stack[-2];
    if (!car_legal(V445)) goto V460;
    stack[-1] = qcar(V445);
    stack[0] = stack[-6];
    V446 = stack[-5];
    V445 = (Lisp_Object)145; /* 9 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    if (!car_legal(V446)) goto V458;
    V446 = qcar(V446);
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply1(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    V445 = stack[-2];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply3(nil, 4, stack[-1], stack[0], V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    if (V445 == nil) goto V180;
    V446 = stack[-5];
    V445 = (Lisp_Object)273; /* 17 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    if (!car_legal(V446)) goto V458;
    V447 = qcar(V446);
    V446 = stack[-6];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply2(nil, 3, V447, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    stack[-6] = V445;
    goto V180;

V180:
    V446 = stack[-5];
    V445 = (Lisp_Object)225; /* 14 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    stack[-1] = V445;
    V445 = stack[-1];
    if (!car_legal(V445)) goto V460;
    stack[0] = qcar(V445);
    V446 = stack[-5];
    V445 = (Lisp_Object)145; /* 9 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    if (!car_legal(V446)) goto V458;
    V446 = qcar(V446);
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply1(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V447 = V445;
    V446 = stack[-7];
    V445 = stack[-1];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply3(nil, 4, stack[0], V447, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    if (V445 == nil) goto V317;
    V446 = stack[-5];
    V445 = (Lisp_Object)225; /* 14 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    stack[-2] = V445;
    V445 = stack[-2];
    if (!car_legal(V445)) goto V460;
    stack[-1] = qcar(V445);
    stack[0] = stack[-6];
    V446 = stack[-5];
    V445 = (Lisp_Object)1217; /* 76 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    if (!car_legal(V446)) goto V458;
    V448 = qcar(V446);
    V447 = (Lisp_Object)33; /* 2 */
    V446 = stack[-7];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply3(nil, 4, V448, V447, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    V445 = stack[-2];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply3(nil, 4, stack[-1], stack[0], V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    if (V445 == nil) goto V226;
    V446 = stack[-5];
    V445 = (Lisp_Object)977; /* 61 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    V446 = V445;
    if (!car_legal(V446)) goto V458;
    V448 = qcar(V446);
    V447 = stack[-7];
    V446 = stack[-6];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
        popv(9);
        return Lapply3(nil, 4, V448, V447, V446, V445);

V226:
    V445 = lisp_true;
    if (!(V445 == nil)) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    V445 = nil;
    { popv(9); return onevalue(V445); }

V317:
    V446 = stack[-5];
    V445 = (Lisp_Object)225; /* 14 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    stack[-4] = V445;
    V445 = stack[-4];
    if (!car_legal(V445)) goto V460;
    stack[-3] = qcar(V445);
    V446 = stack[-5];
    V445 = (Lisp_Object)145; /* 9 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    if (!car_legal(V446)) goto V458;
    V446 = qcar(V446);
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply1(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    stack[-2] = V445;
    V446 = stack[-5];
    V445 = (Lisp_Object)1233; /* 77 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    stack[-1] = V445;
    V445 = stack[-1];
    if (!car_legal(V445)) goto V460;
    stack[0] = qcar(V445);
    V446 = stack[-5];
    V445 = (Lisp_Object)1217; /* 76 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    if (!car_legal(V446)) goto V458;
    V448 = qcar(V446);
    V447 = (Lisp_Object)33; /* 2 */
    V446 = stack[-7];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply3(nil, 4, V448, V447, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V447 = V445;
    V446 = stack[-6];
    V445 = stack[-1];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply3(nil, 4, stack[0], V447, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    V446 = V445;
    V445 = stack[-4];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
    V445 = Lapply3(nil, 4, stack[-3], stack[-2], V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    env = stack[-8];
    if (V445 == nil) goto V416;
    V445 = lisp_true;
    if (!(V445 == nil)) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    V445 = nil;
    { popv(9); return onevalue(V445); }

V416:
    V446 = stack[-5];
    V445 = (Lisp_Object)1233; /* 77 */
    V445 = Lgetv(nil, V446, V445);
    nil = C_nil;
    if (exception_pending()) goto V457;
    V446 = V445;
    if (!car_legal(V446)) goto V458;
    V448 = qcar(V446);
    V447 = stack[-7];
    V446 = stack[-6];
    if (!car_legal(V445)) goto V459;
    V445 = qcdr(V445);
        popv(9);
        return Lapply3(nil, 4, V448, V447, V446, V445);

V93:
    V445 = nil;
    { popv(9); return onevalue(V445); }
/* error exit handlers */
V460:
    popv(9);
    return error(1, err_bad_car, V445);
V459:
    popv(9);
    return error(1, err_bad_cdr, V445);
V458:
    popv(9);
    return error(1, err_bad_car, V446);
V457:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|FM;*;$R$;3| (|x| |r| |$|)
   (PROG (#:G110716 |u| #:G110717)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 11))
                  (BOOT::|spadConstant| |$| 12))
               ((BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 13)) |x|)
               ('T
                  (PROGN
                     (BOOT::LETT #:G110716 NIL BOOT::|FM;*;$R$;3|)
                     (SEQ
                        (BOOT::LETT |u| NIL BOOT::|FM;*;$R$;3|)
                        (BOOT::LETT #:G110717 |x| BOOT::|FM;*;$R$;3|)
                        BOOT::G190
                        (COND
                           ((OR
                               (ATOM #:G110717)
                               (PROGN
                                  (BOOT::LETT
                                     |u|
                                     (CAR #:G110717)
                                     BOOT::|FM;*;$R$;3|)
                                  NIL))
                              (GO BOOT::G191)))
                        (SEQ
                           (EXIT
                              (BOOT::LETT
                                 #:G110716
                                 (CONS
                                    (CONS
                                       (QCAR |u|)
                                       (BOOT:SPADCALL
                                          (QCDR |u|)
                                          |r|
                                          (VMLISP:QREFELT |$| 14)))
                                    #:G110716)
                                 BOOT::|FM;*;$R$;3|)))
                        (BOOT::LETT
                           #:G110717
                           (CDR #:G110717)
                           BOOT::|FM;*;$R$;3|)
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT (NREVERSE0 #:G110716)))) ))) )))

*/



/* Code for BOOT::|FM;*;$R$;3| */

static Lisp_Object MS_CDECL CC_BOOT__FMUHUDRDU3(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V159, V160, V161, V162;
    Lisp_Object fn;
    argcheck(nargs, 3, "FM;*;$R$;3");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FM;*;$R$;3|\n");
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
    V160 = stack[-2];
    V161 = qcdr(V160);
    V160 = stack[-4];
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
(DEFUN BOOT::|FM;*;$R$;4| (|x| |r| |$|)
   (PROG (#:G110723 |u| #:G110724 |a|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 11))
                  (BOOT::|spadConstant| |$| 12))
               ((BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 13)) |x|)
               ('T
                  (PROGN
                     (BOOT::LETT #:G110723 NIL BOOT::|FM;*;$R$;4|)
                     (SEQ
                        (BOOT::LETT |u| NIL BOOT::|FM;*;$R$;4|)
                        (BOOT::LETT #:G110724 |x| BOOT::|FM;*;$R$;4|)
                        BOOT::G190
                        (COND
                           ((OR
                               (ATOM #:G110724)
                               (PROGN
                                  (BOOT::LETT
                                     |u|
                                     (CAR #:G110724)
                                     BOOT::|FM;*;$R$;4|)
                                  NIL))
                              (GO BOOT::G191)))
                        (SEQ
                           (EXIT
                              (COND
                                 ((SEQ
                                     (BOOT::LETT
                                        |a|
                                        (BOOT:SPADCALL
                                           (QCDR |u|)
                                           |r|
                                           (VMLISP:QREFELT |$| 14))
                                        BOOT::|FM;*;$R$;4|)
                                     (EXIT
                                        (COND
                                           ((BOOT:SPADCALL
                                               |a|
                                               (BOOT::|spadConstant|
                                                  |$|
                                                  16)
                                               (VMLISP:QREFELT |$| 17))
                                              'NIL)
                                           ('T 'T))))
                                    (BOOT::LETT
                                       #:G110723
                                       (CONS
                                          (CONS (QCAR |u|) |a|)
                                          #:G110723)
                                       BOOT::|FM;*;$R$;4|)))) )
                        (BOOT::LETT
                           #:G110724
                           (CDR #:G110724)
                           BOOT::|FM;*;$R$;4|)
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT (NREVERSE0 #:G110723)))) ))) )))

*/



/* Code for BOOT::|FM;*;$R$;4| */

static Lisp_Object MS_CDECL CC_BOOT__FMUHUDRDU4(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V224, V225, V226, V227;
    Lisp_Object fn;
    argcheck(nargs, 3, "FM;*;$R$;4");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FM;*;$R$;4|\n");
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
    stack[-6] = V4;
    stack[-7] = V3;
    stack[0] = V2;
/* end of prologue */
    V225 = stack[-6];
    V224 = (Lisp_Object)177; /* 11 */
    V224 = Lgetv(nil, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    V225 = V224;
    if (!car_legal(V225)) goto V238;
    V226 = qcar(V225);
    V225 = stack[-7];
    if (!car_legal(V224)) goto V239;
    V224 = qcdr(V224);
    V224 = Lapply2(nil, 3, V226, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    if (V224 == nil) goto V71;
    V225 = stack[-6];
    V224 = (Lisp_Object)193; /* 12 */
    V224 = Lgetv(nil, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    V225 = V224;
    if (!car_legal(V225)) goto V238;
    V225 = qcar(V225);
    if (!car_legal(V224)) goto V239;
    V224 = qcdr(V224);
        popv(10);
        return Lapply1(nil, V225, V224);

V71:
    V225 = stack[-6];
    V224 = (Lisp_Object)209; /* 13 */
    V224 = Lgetv(nil, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    V225 = V224;
    if (!car_legal(V225)) goto V238;
    V226 = qcar(V225);
    V225 = stack[-7];
    if (!car_legal(V224)) goto V239;
    V224 = qcdr(V224);
    V224 = Lapply2(nil, 3, V226, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    if (!(V224 == nil)) { Lisp_Object res = stack[0]; popv(10); return onevalue(res); }
    V224 = lisp_true;
    if (V224 == nil) goto V93;
    V224 = nil;
    stack[-8] = V224;
    V224 = stack[0];
    stack[-4] = V224;
    goto V98;

V98:
    V224 = stack[-4];
    if (!consp(V224)) goto V99;
    V224 = stack[-4];
    if (!car_legal(V224)) goto V240;
    V224 = qcar(V224);
    stack[-5] = V224;
    V224 = nil;
    if (!(V224 == nil)) goto V99;
    V225 = stack[-6];
    V224 = (Lisp_Object)225; /* 14 */
    V224 = Lgetv(nil, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    V225 = V224;
    if (!car_legal(V225)) goto V238;
    V227 = qcar(V225);
    V225 = stack[-5];
    V226 = qcdr(V225);
    V225 = stack[-7];
    if (!car_legal(V224)) goto V239;
    V224 = qcdr(V224);
    V224 = Lapply3(nil, 4, V227, V226, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    stack[-3] = V224;
    V225 = stack[-6];
    V224 = (Lisp_Object)273; /* 17 */
    V224 = Lgetv(nil, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    stack[-2] = V224;
    V224 = stack[-2];
    if (!car_legal(V224)) goto V240;
    stack[-1] = qcar(V224);
    stack[0] = stack[-3];
    V225 = stack[-6];
    V224 = (Lisp_Object)257; /* 16 */
    V224 = Lgetv(nil, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    V225 = V224;
    if (!car_legal(V225)) goto V238;
    V225 = qcar(V225);
    if (!car_legal(V224)) goto V239;
    V224 = qcdr(V224);
    V224 = Lapply1(nil, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    V225 = V224;
    V224 = stack[-2];
    if (!car_legal(V224)) goto V239;
    V224 = qcdr(V224);
    V224 = Lapply3(nil, 4, stack[-1], stack[0], V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    if (V224 == nil) goto V151;
    V224 = nil;
    goto V119;

V119:
    if (V224 == nil) goto V113;
    V224 = stack[-5];
    V226 = qcar(V224);
    V225 = stack[-3];
    V224 = stack[-8];
    V224 = acons(V226, V225, V224);
    nil = C_nil;
    if (exception_pending()) goto V237;
    env = stack[-9];
    stack[-8] = V224;
    goto V113;

V113:
    V224 = stack[-4];
    if (!car_legal(V224)) goto V239;
    V224 = qcdr(V224);
    stack[-4] = V224;
    goto V98;

V151:
    V224 = lisp_true;
    if (V224 == nil) goto V201;
    V224 = lisp_true;
    goto V119;

V201:
    V224 = nil;
    goto V119;

V99:
    V224 = stack[-8];
    {
        popv(10);
        fn = elt(env, 1); /* NREVERSE0 */
        return (*qfn1(fn))(qenv(fn), V224);
    }

V93:
    V224 = nil;
    { popv(10); return onevalue(V224); }
/* error exit handlers */
V240:
    popv(10);
    return error(1, err_bad_car, V224);
V239:
    popv(10);
    return error(1, err_bad_cdr, V224);
V238:
    popv(10);
    return error(1, err_bad_car, V225);
V237:
    popv(10);
    return nil;
}

/*
(DEFUN BOOT::|IFARRAY;new;NniS$;8| (|n| |a| |$|)
   (VECTOR |n| |n| (BOOT:SPADCALL |n| |a| (VMLISP:QREFELT |$| 21))))

*/



/* Code for BOOT::|IFARRAY;new;NniS$;8| */

static Lisp_Object MS_CDECL CC_BOOT__IFARRAYUnewUNniSDU8(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V45, V46, V47, V48;
    Lisp_Object fn;
    argcheck(nargs, 3, "IFARRAY;new;NniS$;8");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;new;NniS$;8|\n");
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
    V45 = V4;
    stack[-1] = V3;
    stack[-2] = V2;
/* end of prologue */
    stack[-3] = stack[-2];
    stack[0] = stack[-2];
    V46 = V45;
    V45 = (Lisp_Object)337; /* 21 */
    V45 = Lgetv(nil, V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V53;
    env = stack[-4];
    V46 = V45;
    if (!car_legal(V46)) goto V54;
    V48 = qcar(V46);
    V47 = stack[-2];
    V46 = stack[-1];
    if (!car_legal(V45)) goto V55;
    V45 = qcdr(V45);
    V45 = Lapply3(nil, 4, V48, V47, V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V53;
    env = stack[-4];
    {
        Lisp_Object V56 = stack[-3];
        Lisp_Object V57 = stack[0];
        popv(5);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V56, V57, V45);
    }
/* error exit handlers */
V55:
    popv(5);
    return error(1, err_bad_cdr, V45);
V54:
    popv(5);
    return error(1, err_bad_car, V46);
V53:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|BOP;properties;$Al;3| (BOOT::|op| |$|)
   (VMLISP:QVELT BOOT::|op| 2))

*/



/* Code for BOOT::|BOP;properties;$Al;3| */

static Lisp_Object CC_BOOT__BOPUpropertiesUDAlU3(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|BOP;properties;$Al;3|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V15 = V3;
    V16 = V2;
/* end of prologue */
    V15 = (Lisp_Object)33; /* 2 */
        return Lgetv(nil, V16, V15);
}

/*
(DEFUN BOOT::|PGCD;better| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (#:G82463)
      (RETURN
         (COND
            ((BOOT:SPADCALL BOOT::|p1| (VMLISP:QREFELT |$| 76)) 'T)
            ((BOOT:SPADCALL BOOT::|p2| (VMLISP:QREFELT |$| 76)) 'NIL)
            ('T
               (|<|
                  (BOOT:SPADCALL
                     BOOT::|p1|
                     (PROG2
                        (BOOT::LETT
                           #:G82463
                           (BOOT:SPADCALL
                              BOOT::|p1|
                              (VMLISP:QREFELT |$| 78))
                           BOOT::|PGCD;better|)
                        (QCDR #:G82463)
                        (BOOT::|check-union|
                           (BOOT::QEQCAR #:G82463 0)
                           (VMLISP:QREFELT |$| 7)
                           #:G82463))
                     (VMLISP:QREFELT |$| 79))
                  (BOOT:SPADCALL
                     BOOT::|p2|
                     (PROG2
                        (BOOT::LETT
                           #:G82463
                           (BOOT:SPADCALL
                              BOOT::|p2|
                              (VMLISP:QREFELT |$| 78))
                           BOOT::|PGCD;better|)
                        (QCDR #:G82463)
                        (BOOT::|check-union|
                           (BOOT::QEQCAR #:G82463 0)
                           (VMLISP:QREFELT |$| 7)
                           #:G82463))
                     (VMLISP:QREFELT |$| 79)))) ))) )

*/



/* Code for BOOT::|PGCD;better| */

static Lisp_Object MS_CDECL CC_BOOT__PGCDUbetter(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V250, V251, V252;
    Lisp_Object fn;
    argcheck(nargs, 3, "PGCD;better");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PGCD;better|\n");
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
    stack[-5] = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V251 = stack[-5];
    V250 = (Lisp_Object)1217; /* 76 */
    V250 = Lgetv(nil, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    V251 = V250;
    if (!car_legal(V251)) goto V261;
    V252 = qcar(V251);
    V251 = stack[-1];
    if (!car_legal(V250)) goto V262;
    V250 = qcdr(V250);
    V250 = Lapply2(nil, 3, V252, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    if (V250 == nil) goto V46;
    V250 = lisp_true;
    { popv(8); return onevalue(V250); }

V46:
    V251 = stack[-5];
    V250 = (Lisp_Object)1217; /* 76 */
    V250 = Lgetv(nil, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    V251 = V250;
    if (!car_legal(V251)) goto V261;
    V252 = qcar(V251);
    V251 = stack[0];
    if (!car_legal(V250)) goto V262;
    V250 = qcdr(V250);
    V250 = Lapply2(nil, 3, V252, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    if (V250 == nil) goto V41;
    V250 = nil;
    { popv(8); return onevalue(V250); }

V41:
    V250 = lisp_true;
    if (V250 == nil) goto V68;
    V251 = stack[-5];
    V250 = (Lisp_Object)1265; /* 79 */
    V250 = Lgetv(nil, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    stack[-6] = V250;
    V250 = stack[-6];
    if (!car_legal(V250)) goto V263;
    stack[-4] = qcar(V250);
    stack[-3] = stack[-1];
    V251 = stack[-5];
    V250 = (Lisp_Object)1249; /* 78 */
    V250 = Lgetv(nil, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    V251 = V250;
    if (!car_legal(V251)) goto V261;
    V252 = qcar(V251);
    V251 = stack[-1];
    if (!car_legal(V250)) goto V262;
    V250 = qcdr(V250);
    V250 = Lapply2(nil, 3, V252, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    V252 = V250;
    V250 = V252;
    V250 = qcdr(V250);
    stack[-2] = V250;
    V250 = V252;
    V251 = qcar(V250);
    V250 = (Lisp_Object)1; /* 0 */
    V250 = Leql(nil, V251, V250);
    env = stack[-7];
    if (!(V250 == nil)) goto V131;
    stack[-1] = V252;
    V251 = stack[-5];
    V250 = (Lisp_Object)113; /* 7 */
    V250 = Lgetv(nil, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    fn = elt(env, 1); /* BOOT::COERCE-FAILURE-MSG */
    V250 = (*qfn2(fn))(qenv(fn), stack[-1], V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    fn = elt(env, 2); /* BOOT::|error| */
    V250 = (*qfn1(fn))(qenv(fn), V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    goto V131;

V131:
    V250 = stack[-2];
    V251 = V250;
    V250 = stack[-6];
    if (!car_legal(V250)) goto V262;
    V250 = qcdr(V250);
    V250 = Lapply3(nil, 4, stack[-4], stack[-3], V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    stack[-6] = V250;
    V251 = stack[-5];
    V250 = (Lisp_Object)1265; /* 79 */
    V250 = Lgetv(nil, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    stack[-4] = V250;
    V250 = stack[-4];
    if (!car_legal(V250)) goto V263;
    stack[-3] = qcar(V250);
    stack[-2] = stack[0];
    V251 = stack[-5];
    V250 = (Lisp_Object)1249; /* 78 */
    V250 = Lgetv(nil, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    V251 = V250;
    if (!car_legal(V251)) goto V261;
    V252 = qcar(V251);
    V251 = stack[0];
    if (!car_legal(V250)) goto V262;
    V250 = qcdr(V250);
    V250 = Lapply2(nil, 3, V252, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    V252 = V250;
    V250 = V252;
    V250 = qcdr(V250);
    stack[-1] = V250;
    V250 = V252;
    V251 = qcar(V250);
    V250 = (Lisp_Object)1; /* 0 */
    V250 = Leql(nil, V251, V250);
    env = stack[-7];
    if (!(V250 == nil)) goto V218;
    stack[0] = V252;
    V251 = stack[-5];
    V250 = (Lisp_Object)113; /* 7 */
    V250 = Lgetv(nil, V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    fn = elt(env, 1); /* BOOT::COERCE-FAILURE-MSG */
    V250 = (*qfn2(fn))(qenv(fn), stack[0], V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    fn = elt(env, 2); /* BOOT::|error| */
    V250 = (*qfn1(fn))(qenv(fn), V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    env = stack[-7];
    goto V218;

V218:
    V250 = stack[-1];
    V251 = V250;
    V250 = stack[-4];
    if (!car_legal(V250)) goto V262;
    V250 = qcdr(V250);
    V250 = Lapply3(nil, 4, stack[-3], stack[-2], V251, V250);
    nil = C_nil;
    if (exception_pending()) goto V260;
    {
        Lisp_Object V264 = stack[-6];
        popv(8);
        return Llessp(nil, V264, V250);
    }

V68:
    V250 = nil;
    { popv(8); return onevalue(V250); }
/* error exit handlers */
V263:
    popv(8);
    return error(1, err_bad_car, V250);
V262:
    popv(8);
    return error(1, err_bad_cdr, V250);
V261:
    popv(8);
    return error(1, err_bad_car, V251);
V260:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|INT;positiveRemainder;3$;28| (|a| |b| |$|)
   (PROG (|r|)
      (RETURN
         (COND
            ((MINUSP
                (BOOT::LETT
                   |r|
                   (BOOT::REMAINDER2 |a| |b|)
                   BOOT::|INT;positiveRemainder;3$;28|))
               (COND ((MINUSP |b|) (|-| |r| |b|)) ('T (|+| |r| |b|))))
            ('T |r|)))) )

*/



/* Code for BOOT::|INT;positiveRemainder;3$;28| */

static Lisp_Object MS_CDECL CC_BOOT__INTUpositiveRemainderU3DU28(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V53, V54;
    Lisp_Object fn;
    argcheck(nargs, 3, "INT;positiveRemainder;3$;28");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|INT;positiveRemainder;3$;28|\n");
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
    V53 = V4;
    stack[0] = V3;
    V54 = V2;
/* end of prologue */
    V53 = stack[0];
    fn = elt(env, 1); /* REM */
    V53 = (*qfn2(fn))(qenv(fn), V54, V53);
    nil = C_nil;
    if (exception_pending()) goto V56;
    env = stack[-1];
    V54 = V53;
    V53 = Lminusp(nil, V53);
    env = stack[-1];
    if (V53 == nil) goto V14;
    V53 = stack[0];
    V53 = Lminusp(nil, V53);
    if (V53 == nil) goto V27;
    V53 = stack[0];
    popv(2);
    { Lisp_Object retVal = difference2(V54, V53);
    errexit();
    return onevalue(retVal); }

V27:
    V53 = lisp_true;
    if (V53 == nil) goto V39;
    V53 = stack[0];
    popv(2);
    { Lisp_Object retVal = plus2(V54, V53);
    errexit();
    return onevalue(retVal); }

V39:
    V53 = nil;
    { popv(2); return onevalue(V53); }

V14:
    V53 = lisp_true;
    if (!(V53 == nil)) { popv(2); return onevalue(V54); }
    V53 = nil;
    { popv(2); return onevalue(V53); }
/* error exit handlers */
V56:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|SGROUP-;**;SPiS;1| (|x| |n| |$|)
   (BOOT:SPADCALL |x| |n| (VMLISP:QREFELT |$| 9)))

*/



/* Code for BOOT::|SGROUP-;**;SPiS;1| */

static Lisp_Object MS_CDECL CC_BOOT__SGROUPKUHHUSPiSU1(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "SGROUP-;**;SPiS;1");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SGROUP-;**;SPiS;1|\n");
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
(DEFUN BOOT::|IFARRAY;empty;$;3| (|$|) (VECTOR 0 0 (VMLISP:GETREFV 0)))

*/



/* Code for BOOT::|IFARRAY;empty;$;3| */

static Lisp_Object CC_BOOT__IFARRAYUemptyUDU3(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V18;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;empty;$;3|\n");
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
    V18 = V2;
/* end of prologue */
    stack[-1] = (Lisp_Object)1; /* 0 */
    stack[0] = (Lisp_Object)1; /* 0 */
    V18 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 1); /* MAKE-ARRAY-1 */
    V18 = (*qfn1(fn))(qenv(fn), V18);
    nil = C_nil;
    if (exception_pending()) goto V21;
    env = stack[-2];
    {
        Lisp_Object V22 = stack[-1];
        Lisp_Object V23 = stack[0];
        popv(3);
        fn = elt(env, 2); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V22, V23, V18);
    }
/* error exit handlers */
V21:
    popv(3);
    return nil;
}

/*
(DEFUN |WRITE-TO-STRING-1| (OBJECT)
   (LET ((|*STANDARD-OUTPUT*| (|MAKE-STRING-OUTPUT-STREAM|)))
      (|SUB-WRITE| OBJECT)
      (|GET-OUTPUT-STREAM-STRING| |*STANDARD-OUTPUT*|)))

*/



/* Code for WRITE-TO-STRING-1 */

static Lisp_Object CC_LISP__WRITEKTOKSTRINGK1(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V14;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering WRITE-TO-STRING-1\n");
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
    stack[-1] = qvalue(elt(env, 1)); /* *STANDARD-OUTPUT* */
    qvalue(elt(env, 1)) = nil; /* *STANDARD-OUTPUT* */
    fn = elt(env, 2); /* MAKE-STRING-OUTPUT-STREAM */
    V14 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V17;
    env = stack[-2];
    qvalue(elt(env, 1)) = V14; /* *STANDARD-OUTPUT* */
    V14 = stack[0];
    fn = elt(env, 3); /* SUB-WRITE */
    V14 = (*qfn1(fn))(qenv(fn), V14);
    nil = C_nil;
    if (exception_pending()) goto V17;
    env = stack[-2];
    V14 = qvalue(elt(env, 1)); /* *STANDARD-OUTPUT* */
    fn = elt(env, 4); /* GET-OUTPUT-STREAM-STRING */
    V14 = (*qfn1(fn))(qenv(fn), V14);
    nil = C_nil;
    if (exception_pending()) goto V17;
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* *STANDARD-OUTPUT* */
    { popv(3); return onevalue(V14); }
/* error exit handlers */
V17:
    env = stack[-2];
    qvalue(elt(env, 1)) = stack[-1]; /* *STANDARD-OUTPUT* */
    popv(3);
    return nil;
}



setup_type const u10_setup[] =
{
    {"BOOT@@SUP;exquo;2$U;27@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__SUPUexquoU2DUU27},
    {"BOOT@@SUP;exquo;2$U;28@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__SUPUexquoU2DUU28},
    {"BOOT@@PR;coerce;R$;12@@Builtin",too_few_2,CC_BOOT__PRUcoerceURDU12,wrong_no_2},
    {"BOOT@@REPSQ;expt;SPiS;1@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__REPSQUexptUSPiSU1},
    {"VMLISP@@QENUM@@Builtin",  too_few_2,      CC_VMLISP__QENUM,wrong_no_2},
    {"VMLISP@@GGREATERP@@Builtin",too_few_2,    CC_VMLISP__GGREATERP,wrong_no_2},
    {"BOOT@@startTimingProcess@@Builtin",CC_BOOT__startTimingProcess,too_many_1,wrong_no_1},
    {"BOOT@@domainEqualList@@Builtin",too_few_2,CC_BOOT__domainEqualList,wrong_no_2},
    {"BOOT@@newExpandLocalType@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__newExpandLocalType},
    {"BOOT@@isDefaultPackageForm?@@Builtin",CC_BOOT__isDefaultPackageFormW,too_many_1,wrong_no_1},
    {"BOOT@@A1AGG-;=;2AB;28@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__A1AGGKUMU2ABU28},
    {"BOOT@@EXPR;coerce;Smp$;24@@Builtin",too_few_2,CC_BOOT__EXPRUcoerceUSmpDU24,wrong_no_2},
    {"BOOT@@PR;*;3$;21@@Builtin",wrong_no_na,   wrong_no_nb,   (n_args *)CC_BOOT__PRUHU3DU21},
    {"BOOT@@superspan@@Builtin",CC_BOOT__superspan,too_many_1, wrong_no_1},
    {"BOOT@@SET;empty;$;4@@Builtin",CC_BOOT__SETUemptyUDU4,too_many_1,wrong_no_1},
    {"BOOT@@A1AGG-;sort!;M2A;2@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__A1AGGKUsortBUM2AU2},
    {"LISP@@SUB-WRITE-STRING@@Builtin",CC_LISP__SUBKWRITEKSTRING,too_many_1,wrong_no_1},
    {"BOOT@@hasCat@@Builtin",   too_few_2,      CC_BOOT__hasCat,wrong_no_2},
    {"BOOT@@ncAlist@@Builtin",  CC_BOOT__ncAlist,too_many_1,   wrong_no_1},
    {"BOOT@@INS-;symmetricRemainder;3S;27@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__INSKUsymmetricRemainderU3SU27},
    {"BOOT@@FM;*;$R$;3@@Builtin",wrong_no_na,   wrong_no_nb,   (n_args *)CC_BOOT__FMUHUDRDU3},
    {"BOOT@@FM;*;$R$;4@@Builtin",wrong_no_na,   wrong_no_nb,   (n_args *)CC_BOOT__FMUHUDRDU4},
    {"BOOT@@IFARRAY;new;NniS$;8@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IFARRAYUnewUNniSDU8},
    {"BOOT@@BOP;properties;$Al;3@@Builtin",too_few_2,CC_BOOT__BOPUpropertiesUDAlU3,wrong_no_2},
    {"BOOT@@PGCD;better@@Builtin",wrong_no_na,  wrong_no_nb,   (n_args *)CC_BOOT__PGCDUbetter},
    {"BOOT@@INT;positiveRemainder;3$;28@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__INTUpositiveRemainderU3DU28},
    {"BOOT@@SGROUP-;**;SPiS;1@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__SGROUPKUHHUSPiSU1},
    {"BOOT@@IFARRAY;empty;$;3@@Builtin",CC_BOOT__IFARRAYUemptyUDU3,too_many_1,wrong_no_1},
    {"LISP@@WRITE-TO-STRING-1@@Builtin",CC_LISP__WRITEKTOKSTRINGK1,too_many_1,wrong_no_1},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
