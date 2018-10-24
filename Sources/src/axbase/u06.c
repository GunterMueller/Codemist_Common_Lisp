
/* u06.c                 Machine generated C code */

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
(DEFUN BOOT::|IDPAM;+;3$;4| (|x| |y| |$|)
   (PROG (|r| BOOT::|newcell| BOOT::|endcell| BOOT::|end| BOOT::|res|)
      (RETURN
         (SEQ
            (COND
               ((NULL |x|) |y|)
               ((NULL |y|) |x|)
               ('T
                  (SEQ
                     (BOOT::LETT BOOT::|endcell| NIL BOOT::|IDPAM;+;3$;4|)
                     (BOOT::LETT BOOT::|res| NIL BOOT::|IDPAM;+;3$;4|)
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
                              BOOT::|IDPAM;+;3$;4|)
                           (COND
                              ((BOOT:SPADCALL
                                  (QCAR (BOOT::|SPADfirst| |x|))
                                  (QCAR (BOOT::|SPADfirst| |y|))
                                  (VMLISP:QREFELT |$| 13))
                                 (SEQ
                                    (BOOT::LETT
                                       |r|
                                       (BOOT:SPADCALL
                                          (QCDR (BOOT::|SPADfirst| |x|))
                                          (QCDR (BOOT::|SPADfirst| |y|))
                                          (VMLISP:QREFELT |$| 14))
                                       BOOT::|IDPAM;+;3$;4|)
                                    (COND
                                       ((NULL
                                           (BOOT:SPADCALL
                                              |r|
                                              (VMLISP:QREFELT |$| 15)))
                                          (BOOT::LETT
                                             BOOT::|newcell|
                                             (CONS
                                                (CONS
                                                   (QCAR
        (BOOT::|SPADfirst| |x|))
                                                   |r|)
                                                NIL)
                                             BOOT::|IDPAM;+;3$;4|)))
                                    (BOOT::LETT
                                       |x|
                                       (CDR |x|)
                                       BOOT::|IDPAM;+;3$;4|)
                                    (EXIT
                                       (BOOT::LETT
                                          |y|
                                          (CDR |y|)
                                          BOOT::|IDPAM;+;3$;4|))))
                              ((BOOT:SPADCALL
                                  (QCAR (BOOT::|SPADfirst| |y|))
                                  (QCAR (BOOT::|SPADfirst| |x|))
                                  (VMLISP:QREFELT |$| 16))
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|newcell|
                                       (CONS (BOOT::|SPADfirst| |x|) NIL)
                                       BOOT::|IDPAM;+;3$;4|)
                                    (EXIT
                                       (BOOT::LETT
                                          |x|
                                          (CDR |x|)
                                          BOOT::|IDPAM;+;3$;4|))))
                              ('T
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|newcell|
                                       (CONS (BOOT::|SPADfirst| |y|) NIL)
                                       BOOT::|IDPAM;+;3$;4|)
                                    (EXIT
                                       (BOOT::LETT
                                          |y|
                                          (CDR |y|)
                                          BOOT::|IDPAM;+;3$;4|)))) )
                           (EXIT
                              (COND
                                 ((NULL (NULL BOOT::|newcell|))
                                    (COND
                                       ((NULL BOOT::|endcell|)
                                          (SEQ
                                             (BOOT::LETT
                                                BOOT::|res|
                                                BOOT::|newcell|
                                                BOOT::|IDPAM;+;3$;4|)
                                             (EXIT
                                                (BOOT::LETT
                                                   BOOT::|endcell|
                                                   BOOT::|res|
                                                   BOOT::|IDPAM;+;3$;4|))))
                                       ('T
                                          (SEQ
                                             (BOOT::|IDPAM;qsetrest!|
                                                BOOT::|endcell|
                                                BOOT::|newcell|
                                                |$|)
                                             (EXIT
                                                (BOOT::LETT
                                                   BOOT::|endcell|
                                                   BOOT::|newcell|
                                          BOOT::|IDPAM;+;3$;4|)))) ))) ))
                        NIL
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT NIL))
                     (COND
                        ((NULL |x|)
                           (BOOT::LETT
                              BOOT::|end|
                              |y|
                              BOOT::|IDPAM;+;3$;4|))
                        ('T
                           (BOOT::LETT
                              BOOT::|end|
                              |x|
                              BOOT::|IDPAM;+;3$;4|)))
                     (COND
                        ((NULL BOOT::|res|)
                           (BOOT::LETT
                              BOOT::|res|
                              BOOT::|end|
                              BOOT::|IDPAM;+;3$;4|))
                        ('T
                           (BOOT::|IDPAM;qsetrest!|
                              BOOT::|endcell|
                              BOOT::|end|
                              |$|)))
                     (EXIT BOOT::|res|)))) ))) )

*/



/* Code for BOOT::|IDPAM;+;3$;4| */

static Lisp_Object MS_CDECL CC_BOOT__IDPAMULU3DU4(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V382, V383, V384;
    Lisp_Object fn;
    argcheck(nargs, 3, "IDPAM;+;3$;4");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IDPAM;+;3$;4|\n");
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
    V382 = stack[-8];
    if (V382 == nil) { Lisp_Object res = stack[-7]; popv(11); return onevalue(res); }
    V382 = stack[-7];
    if (V382 == nil) { Lisp_Object res = stack[-8]; popv(11); return onevalue(res); }
    V382 = lisp_true;
    if (V382 == nil) goto V28;
    V382 = nil;
    stack[-5] = V382;
    V382 = nil;
    stack[-3] = V382;
    goto V36;

V36:
    V382 = stack[-8];
    if (V382 == nil) goto V44;
    V382 = stack[-7];
    if (V382 == nil) goto V44;
    V382 = lisp_true;
    if (V382 == nil) goto V52;
    V382 = lisp_true;
    goto V43;

V43:
    if (V382 == nil) goto V35;
    V382 = nil;
    stack[-9] = V382;
    V383 = stack[-6];
    V382 = (Lisp_Object)209; /* 13 */
    V382 = Lgetv(nil, V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    stack[-2] = V382;
    V382 = stack[-2];
    if (!car_legal(V382)) goto V396;
    stack[-1] = qcar(V382);
    V382 = stack[-8];
    V383 = V382;
    V382 = V383;
    if (V382 == nil) goto V92;
    V382 = V383;
    if (!car_legal(V382)) goto V396;
    V382 = qcar(V382);
    goto V87;

V87:
    stack[0] = qcar(V382);
    V382 = stack[-7];
    V383 = V382;
    V382 = V383;
    if (V382 == nil) goto V105;
    V382 = V383;
    if (!car_legal(V382)) goto V396;
    V382 = qcar(V382);
    goto V100;

V100:
    V383 = qcar(V382);
    V382 = stack[-2];
    if (!car_legal(V382)) goto V397;
    V382 = qcdr(V382);
    V382 = Lapply3(nil, 4, stack[-1], stack[0], V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    if (V382 == nil) goto V226;
    V383 = stack[-6];
    V382 = (Lisp_Object)225; /* 14 */
    V382 = Lgetv(nil, V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    stack[-2] = V382;
    V382 = stack[-2];
    if (!car_legal(V382)) goto V396;
    stack[-1] = qcar(V382);
    V382 = stack[-8];
    V383 = V382;
    V382 = V383;
    if (V382 == nil) goto V145;
    V382 = V383;
    if (!car_legal(V382)) goto V396;
    V382 = qcar(V382);
    goto V140;

V140:
    stack[0] = qcdr(V382);
    V382 = stack[-7];
    V383 = V382;
    V382 = V383;
    if (V382 == nil) goto V158;
    V382 = V383;
    if (!car_legal(V382)) goto V396;
    V382 = qcar(V382);
    goto V153;

V153:
    V383 = qcdr(V382);
    V382 = stack[-2];
    if (!car_legal(V382)) goto V397;
    V382 = qcdr(V382);
    V382 = Lapply3(nil, 4, stack[-1], stack[0], V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    stack[0] = V382;
    V383 = stack[-6];
    V382 = (Lisp_Object)241; /* 15 */
    V382 = Lgetv(nil, V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    V383 = V382;
    if (!car_legal(V383)) goto V398;
    V384 = qcar(V383);
    V383 = stack[0];
    if (!car_legal(V382)) goto V397;
    V382 = qcdr(V382);
    V382 = Lapply2(nil, 3, V384, V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    if (!(V382 == nil)) goto V167;
    V382 = stack[-8];
    V383 = V382;
    V382 = V383;
    if (V382 == nil) goto V208;
    V382 = V383;
    if (!car_legal(V382)) goto V396;
    V382 = qcar(V382);
    goto V203;

V203:
    V383 = qcar(V382);
    V382 = stack[0];
    V382 = cons(V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    V382 = ncons(V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    stack[-9] = V382;
    goto V167;

V167:
    V382 = stack[-8];
    if (!car_legal(V382)) goto V397;
    V382 = qcdr(V382);
    stack[-8] = V382;
    V382 = stack[-7];
    if (!car_legal(V382)) goto V397;
    V382 = qcdr(V382);
    stack[-7] = V382;
    goto V59;

V59:
    V382 = stack[-9];
    if (V382 == nil) goto V36;
    V382 = stack[-5];
    if (V382 == nil) goto V319;
    V382 = lisp_true;
    if (V382 == nil) goto V36;
    V384 = stack[-5];
    V383 = stack[-9];
    V382 = stack[-6];
    fn = elt(env, 1); /* BOOT::|IDPAM;qsetrest!| */
    V382 = (*qfnn(fn))(qenv(fn), 3, V384, V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    V382 = stack[-9];
    stack[-5] = V382;
    goto V36;

V319:
    V382 = stack[-9];
    stack[-3] = V382;
    V382 = stack[-3];
    stack[-5] = V382;
    goto V36;

V208:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V382 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    goto V203;

V158:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V382 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    goto V153;

V145:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V382 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    goto V140;

V226:
    V383 = stack[-6];
    V382 = (Lisp_Object)257; /* 16 */
    V382 = Lgetv(nil, V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    stack[-2] = V382;
    V382 = stack[-2];
    if (!car_legal(V382)) goto V396;
    stack[-1] = qcar(V382);
    V382 = stack[-7];
    V383 = V382;
    V382 = V383;
    if (V382 == nil) goto V252;
    V382 = V383;
    if (!car_legal(V382)) goto V396;
    V382 = qcar(V382);
    goto V247;

V247:
    stack[0] = qcar(V382);
    V382 = stack[-8];
    V383 = V382;
    V382 = V383;
    if (V382 == nil) goto V265;
    V382 = V383;
    if (!car_legal(V382)) goto V396;
    V382 = qcar(V382);
    goto V260;

V260:
    V383 = qcar(V382);
    V382 = stack[-2];
    if (!car_legal(V382)) goto V397;
    V382 = qcdr(V382);
    V382 = Lapply3(nil, 4, stack[-1], stack[0], V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    if (V382 == nil) goto V221;
    V382 = stack[-8];
    V383 = V382;
    V382 = V383;
    if (V382 == nil) goto V283;
    V382 = V383;
    if (!car_legal(V382)) goto V396;
    V382 = qcar(V382);
    goto V278;

V278:
    V382 = ncons(V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    stack[-9] = V382;
    V382 = stack[-8];
    if (!car_legal(V382)) goto V397;
    V382 = qcdr(V382);
    stack[-8] = V382;
    goto V59;

V283:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V382 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    goto V278;

V221:
    V382 = lisp_true;
    if (V382 == nil) goto V59;
    V382 = stack[-7];
    V383 = V382;
    V382 = V383;
    if (V382 == nil) goto V304;
    V382 = V383;
    if (!car_legal(V382)) goto V396;
    V382 = qcar(V382);
    goto V299;

V299:
    V382 = ncons(V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    stack[-9] = V382;
    V382 = stack[-7];
    if (!car_legal(V382)) goto V397;
    V382 = qcdr(V382);
    stack[-7] = V382;
    goto V59;

V304:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V382 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    goto V299;

V265:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V382 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    goto V260;

V252:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V382 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    goto V247;

V105:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V382 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    goto V100;

V92:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V382 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-10];
    goto V87;

V35:
    V382 = stack[-8];
    if (V382 == nil) goto V351;
    V382 = lisp_true;
    if (V382 == nil) goto V350;
    V382 = stack[-8];
    stack[-4] = V382;
    goto V350;

V350:
    V382 = stack[-3];
    if (V382 == nil) goto V361;
    V382 = lisp_true;
    if (V382 == nil) { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }
    V384 = stack[-5];
    V383 = stack[-4];
    V382 = stack[-6];
    fn = elt(env, 1); /* BOOT::|IDPAM;qsetrest!| */
    V382 = (*qfnn(fn))(qenv(fn), 3, V384, V383, V382);
    nil = C_nil;
    if (exception_pending()) goto V395;
    { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }

V361:
    V382 = stack[-4];
    stack[-3] = V382;
    { Lisp_Object res = stack[-3]; popv(11); return onevalue(res); }

V351:
    V382 = stack[-7];
    stack[-4] = V382;
    goto V350;

V52:
    V382 = nil;
    goto V43;

V44:
    V382 = nil;
    goto V43;

V28:
    V382 = nil;
    { popv(11); return onevalue(V382); }
/* error exit handlers */
V398:
    popv(11);
    return error(1, err_bad_car, V383);
V397:
    popv(11);
    return error(1, err_bad_cdr, V382);
V396:
    popv(11);
    return error(1, err_bad_car, V382);
V395:
    popv(11);
    return nil;
}

/*
(DEFUN BOOT::|FRAC;normalize| (|x| |$|)
   (PROG (BOOT::|uca|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL (QCAR |x|) (VMLISP:QREFELT |$| 12))
                  (BOOT::|spadConstant| |$| 22))
               ((BOOT:SPADCALL (QCDR |x|) (VMLISP:QREFELT |$| 14)) |x|)
               ('T
                  (SEQ
                     (BOOT::LETT
                        BOOT::|uca|
                        (BOOT:SPADCALL (QCDR |x|) (VMLISP:QREFELT |$| 48))
                        BOOT::|FRAC;normalize|)
                     (EXIT
                        (COND
                           ((BOOT:SPADCALL
                               (PROGN
                                  (RPLACD |x| (VMLISP:QVELT BOOT::|uca| 1))
                                  (QCDR |x|))
                               (VMLISP:QREFELT |$| 12))
                              (BOOT::|error| "division by zero"))
                           ('T
                              (SEQ
                                 (PROGN
                                    (RPLACA
                                       |x|
                                       (BOOT:SPADCALL
                                          (QCAR |x|)
                                          (VMLISP:QVELT BOOT::|uca| 2)
                                          (VMLISP:QREFELT |$| 49)))
                                    (QCAR |x|))
                                 (EXIT |x|)))) ))) ))) ))

*/



/* Code for BOOT::|FRAC;normalize| */

static Lisp_Object CC_BOOT__FRACUnormalize(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V219, V220, V221;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FRAC;normalize|\n");
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
    stack[-1] = V3;
    stack[-4] = V2;
/* end of prologue */
    V220 = stack[-1];
    V219 = (Lisp_Object)193; /* 12 */
    V219 = Lgetv(nil, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    V220 = V219;
    if (!car_legal(V220)) goto V229;
    V221 = qcar(V220);
    V220 = stack[-4];
    V220 = qcar(V220);
    if (!car_legal(V219)) goto V230;
    V219 = qcdr(V219);
    V219 = Lapply2(nil, 3, V221, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    if (V219 == nil) goto V68;
    V220 = stack[-1];
    V219 = (Lisp_Object)353; /* 22 */
    V219 = Lgetv(nil, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    V220 = V219;
    if (!car_legal(V220)) goto V229;
    V220 = qcar(V220);
    if (!car_legal(V219)) goto V230;
    V219 = qcdr(V219);
        popv(7);
        return Lapply1(nil, V220, V219);

V68:
    V220 = stack[-1];
    V219 = (Lisp_Object)225; /* 14 */
    V219 = Lgetv(nil, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    V220 = V219;
    if (!car_legal(V220)) goto V229;
    V221 = qcar(V220);
    V220 = stack[-4];
    V220 = qcdr(V220);
    if (!car_legal(V219)) goto V230;
    V219 = qcdr(V219);
    V219 = Lapply2(nil, 3, V221, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    if (!(V219 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    V219 = lisp_true;
    if (V219 == nil) goto V91;
    V220 = stack[-1];
    V219 = (Lisp_Object)769; /* 48 */
    V219 = Lgetv(nil, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    V220 = V219;
    if (!car_legal(V220)) goto V229;
    V221 = qcar(V220);
    V220 = stack[-4];
    V220 = qcdr(V220);
    if (!car_legal(V219)) goto V230;
    V219 = qcdr(V219);
    V219 = Lapply2(nil, 3, V221, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    stack[-5] = V219;
    V220 = stack[-1];
    V219 = (Lisp_Object)193; /* 12 */
    V219 = Lgetv(nil, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    stack[-3] = V219;
    V219 = stack[-3];
    if (!car_legal(V219)) goto V231;
    stack[-2] = qcar(V219);
    stack[0] = stack[-4];
    V220 = stack[-5];
    V219 = (Lisp_Object)17; /* 1 */
    V219 = Lgetv(nil, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    V219 = Lrplacd(nil, stack[0], V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    V219 = stack[-4];
    V220 = qcdr(V219);
    V219 = stack[-3];
    if (!car_legal(V219)) goto V230;
    V219 = qcdr(V219);
    V219 = Lapply2(nil, 3, stack[-2], V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    if (V219 == nil) goto V123;
    V219 = elt(env, 1); /* "division by zero" */
    {
        popv(7);
        fn = elt(env, 2); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V219);
    }

V123:
    V219 = lisp_true;
    if (V219 == nil) goto V167;
    stack[-3] = stack[-4];
    V220 = stack[-1];
    V219 = (Lisp_Object)785; /* 49 */
    V219 = Lgetv(nil, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    stack[-2] = V219;
    V219 = stack[-2];
    if (!car_legal(V219)) goto V231;
    stack[-1] = qcar(V219);
    V219 = stack[-4];
    stack[0] = qcar(V219);
    V220 = stack[-5];
    V219 = (Lisp_Object)33; /* 2 */
    V220 = Lgetv(nil, V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    V219 = stack[-2];
    if (!car_legal(V219)) goto V230;
    V219 = qcdr(V219);
    V219 = Lapply3(nil, 4, stack[-1], stack[0], V220, V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-6];
    V219 = Lrplaca(nil, stack[-3], V219);
    nil = C_nil;
    if (exception_pending()) goto V228;
    { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }

V167:
    V219 = nil;
    { popv(7); return onevalue(V219); }

V91:
    V219 = nil;
    { popv(7); return onevalue(V219); }
/* error exit handlers */
V231:
    popv(7);
    return error(1, err_bad_car, V219);
V230:
    popv(7);
    return error(1, err_bad_cdr, V219);
V229:
    popv(7);
    return error(1, err_bad_car, V220);
V228:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|COMPLEX;coerce;R$;10| (|r| |$|)
   (CONS |r| (BOOT::|spadConstant| |$| 29)))

*/



/* Code for BOOT::|COMPLEX;coerce;R$;10| */

static Lisp_Object CC_BOOT__COMPLEXUcoerceURDU10(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPLEX;coerce;R$;10|\n");
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
    V35 = V3;
    V36 = V2;
/* end of prologue */
    stack[0] = V36;
    V36 = V35;
    V35 = (Lisp_Object)465; /* 29 */
    V35 = Lgetv(nil, V36, V35);
    nil = C_nil;
    if (exception_pending()) goto V38;
    env = stack[-1];
    V36 = V35;
    if (!car_legal(V36)) goto V39;
    V36 = qcar(V36);
    if (!car_legal(V35)) goto V40;
    V35 = qcdr(V35);
    V35 = Lapply1(nil, V36, V35);
    nil = C_nil;
    if (exception_pending()) goto V38;
    {
        Lisp_Object V41 = stack[0];
        popv(2);
        { Lisp_Object retVal = cons(V41, V35);
        errexit();
        return onevalue(retVal); }
    }
/* error exit handlers */
V40:
    popv(2);
    return error(1, err_bad_cdr, V35);
V39:
    popv(2);
    return error(1, err_bad_car, V36);
V38:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|BOP;has?;$SB;9| (BOOT::|op| BOOT::|name| |$|)
   (BOOT:SPADCALL
      BOOT::|name|
      (VMLISP:QVELT BOOT::|op| 2)
      (VMLISP:QREFELT |$| 28)))

*/



/* Code for BOOT::|BOP;has?;$SB;9| */

static Lisp_Object MS_CDECL CC_BOOT__BOPUhasWUDSBU9(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V42, V43;
    argcheck(nargs, 3, "BOP;has?;$SB;9");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|BOP;has?;$SB;9|\n");
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
    V42 = (Lisp_Object)449; /* 28 */
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
(DEFUN BOOT::|tokPart| (|x|)
   (PROG NIL
      (RETURN (CDR |x|))))

*/



/* Code for BOOT::|tokPart| */

static Lisp_Object CC_BOOT__tokPart(Lisp_Object env,
                         Lisp_Object V2)
{
    nil_as_base
    Lisp_Object V10;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|tokPart|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V10 = V2;
/* end of prologue */
    if (!car_legal(V10)) goto V11;
    V10 = qcdr(V10);
    return onevalue(V10);
/* error exit handlers */
V11:
    return error(1, err_bad_cdr, V10);
}

/*
(DEFUN BOOT::|newCompareSig| (BOOT::|sig|
      BOOT::|numvec|
      BOOT::|index|
      BOOT::|dollar|
      BOOT::|domain|)
   (PROG (BOOT::|target| |k|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET |k| BOOT::|index|)
               (COND
                  ((OR
                      (NULL
                         (BOOT:SPADLET BOOT::|target| (CAR BOOT::|sig|)))
                      (BOOT::|lazyMatchArg|
                         BOOT::|target|
                         (ELT BOOT::|numvec| |k|)
                         BOOT::|dollar|
                         BOOT::|domain|))
                     (COND
                        ((PROG (#:G18892)
                            (BOOT:SPADLET #:G18892 'T)
                            (RETURN
                               (DO ((#:G18893 NIL (NULL #:G18892))
                                     (#:G18894
                                        (CDR BOOT::|sig|)
                                        (CDR #:G18894))
                                     (|s| NIL)
                                     (|i|
                                        (PLUS BOOT::|index| 1)
                                        (|+| |i| 1)))
                                  ((OR
                                      #:G18893
                                      (ATOM #:G18894)
                                      (PROGN
                                         (SETQ |s| (CAR #:G18894))
                                         NIL))
                                     #:G18892)
                                  (SEQ
                                     (EXIT
                                        (SETQ #:G18892
                                           (AND
                                              #:G18892
                                              (BOOT::|lazyMatchArg|
                                                 |s|
                                                 (ELT
                                                    BOOT::|numvec|
                                                    (BOOT:SPADLET |k| |i|))
                                                 BOOT::|dollar|
                                                 BOOT::|domain|)))) ))) )
                           (ELT BOOT::|numvec| (VMLISP:QSINC1 |k|)))
                        ('T NIL)))
                  ('T NIL)))) )))

*/



/* Code for BOOT::|newCompareSig| */

static Lisp_Object MS_CDECL CC_BOOT__newCompareSig(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5,
                         Lisp_Object V6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V150, V151, V152;
    Lisp_Object fn;
    argcheck(nargs, 5, "newCompareSig");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|newCompareSig|\n");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = V6;
    stack[-5] = V5;
    stack[0] = V4;
    stack[-6] = V3;
    stack[-1] = V2;
/* end of prologue */
    V150 = stack[0];
    stack[-7] = V150;
    V150 = stack[-1];
    if (!car_legal(V150)) goto V161;
    V150 = qcar(V150);
    V151 = V150;
    if (V150 == nil) goto V19;
    stack[-2] = V151;
    V151 = stack[-6];
    V150 = stack[-7];
    fn = elt(env, 1); /* ELT */
    V152 = (*qfn2(fn))(qenv(fn), V151, V150);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-8];
    V151 = stack[-5];
    V150 = stack[-4];
    fn = elt(env, 2); /* BOOT::|lazyMatchArg| */
    V150 = (*qfnn(fn))(qenv(fn), 4, stack[-2], V152, V151, V150);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-8];
    if (!(V150 == nil)) goto V19;
    V150 = lisp_true;
    if (V150 == nil) goto V146;
    V150 = nil;
    { popv(9); return onevalue(V150); }

V146:
    V150 = nil;
    { popv(9); return onevalue(V150); }

V19:
    V150 = lisp_true;
    stack[-3] = V150;
    V150 = stack[0];
    V152 = add1(V150);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-8];
    V150 = stack[-1];
    if (!car_legal(V150)) goto V163;
    V151 = qcdr(V150);
    V150 = nil;
    stack[-2] = V152;
    stack[0] = V151;
    V152 = V150;
    goto V66;

V66:
    V150 = V152;
    if (!(V150 == nil)) goto V69;
    V150 = stack[0];
    if (!consp(V150)) goto V69;
    V150 = stack[0];
    if (!car_legal(V150)) goto V161;
    V150 = qcar(V150);
    V151 = V150;
    V150 = nil;
    if (!(V150 == nil)) goto V69;
    V150 = stack[-3];
    if (V150 == nil) goto V85;
    stack[-1] = V151;
    V151 = stack[-6];
    V150 = stack[-2];
    stack[-7] = V150;
    fn = elt(env, 1); /* ELT */
    V152 = (*qfn2(fn))(qenv(fn), V151, V150);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-8];
    V151 = stack[-5];
    V150 = stack[-4];
    fn = elt(env, 2); /* BOOT::|lazyMatchArg| */
    V150 = (*qfnn(fn))(qenv(fn), 4, stack[-1], V152, V151, V150);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-8];
    goto V84;

V84:
    stack[-3] = V150;
    V150 = stack[-3];
    V150 = (V150 == nil ? lisp_true : nil);
    stack[-1] = V150;
    V150 = stack[0];
    if (!car_legal(V150)) goto V163;
    V150 = qcdr(V150);
    stack[0] = V150;
    V150 = stack[-2];
    V150 = add1(V150);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-8];
    V151 = V150;
    V150 = stack[-1];
    V152 = V150;
    V150 = stack[0];
    stack[0] = V150;
    V150 = V151;
    stack[-2] = V150;
    goto V66;

V85:
    V150 = nil;
    goto V84;

V69:
    V150 = stack[-3];
    if (V150 == nil) goto V49;
    stack[0] = stack[-6];
    V150 = stack[-7];
    V150 = add1(V150);
    nil = C_nil;
    if (exception_pending()) goto V162;
    env = stack[-8];
    {
        Lisp_Object V164 = stack[0];
        popv(9);
        fn = elt(env, 1); /* ELT */
        return (*qfn2(fn))(qenv(fn), V164, V150);
    }

V49:
    V150 = lisp_true;
    if (V150 == nil) goto V142;
    V150 = nil;
    { popv(9); return onevalue(V150); }

V142:
    V150 = nil;
    { popv(9); return onevalue(V150); }
/* error exit handlers */
V163:
    popv(9);
    return error(1, err_bad_cdr, V150);
V162:
    popv(9);
    return nil;
V161:
    popv(9);
    return error(1, err_bad_car, V150);
}

/*
(DEFUN BOOT::|lazyMatchArg2| (|s|
      |a|
      BOOT::|dollar|
      BOOT::|domain|
      BOOT::|typeFlag|)
   (PROG (|d| BOOT::|domainArg| BOOT::|dhash| BOOT::|ISTMP#1| |y|
         BOOT::|op|)
      (RETURN
         (PROGN
            (COND
               ((BOOT:|BOOT-EQUAL| |s| '|$|)
                  (BOOT:SPADLET |s| (BOOT::|devaluate| BOOT::|dollar|))))
            (COND
               ((INTEGERP |a|)
                  (COND
                     ((NULL BOOT::|typeFlag|)
                        (BOOT:|BOOT-EQUAL| |s| (ELT BOOT::|domain| |a|)))
                     ((AND (EQL |a| 6) BOOT::|$isDefaultingPackage|)
                        (BOOT:|BOOT-EQUAL|
                           |s|
                           (BOOT::|devaluate| BOOT::|dollar|)))
                     ((VMLISP:VECP
                         (BOOT:SPADLET
                            |d|
                            (BOOT::|domainVal|
                               BOOT::|dollar|
                               BOOT::|domain|
                               |a|)))
                        (COND
                           ((BOOT:|BOOT-EQUAL| |s| (ELT |d| 0)) 'T)
                           ('T
                              (BOOT:SPADLET
                                 BOOT::|domainArg|
                                 (COND
                                    (BOOT::|$isDefaultingPackage|
                                       (ELT (ELT BOOT::|domain| 6) 0))
                                    ('T (ELT BOOT::|domain| 0))))
                              (AND
                                 (BOOT:|BOOT-EQUAL|
                                    (BOOT:KAR |s|)
                                    (QCAR (ELT |d| 0)))
                                 (BOOT::|lazyMatchArgDollarCheck|
                                    |s|
                                    (ELT |d| 0)
                                    (ELT BOOT::|dollar| 0)
                                    BOOT::|domainArg|)))) )
                     ((BOOT::|isDomain| |d|)
                        (BOOT:SPADLET
                           BOOT::|dhash|
                           (BOOT::|getDomainHash| |d|))
                        (BOOT:|BOOT-EQUAL|
                           BOOT::|dhash|
                           (COND
                              ((BOOT::|hashCode?| |s|) |s|)
                              ('T (BOOT::|hashType| |s| BOOT::|dhash|)))) )
                     ('T
                        (BOOT::|lazyMatch|
                           |s|
                           |d|
                           BOOT::|dollar|
                           BOOT::|domain|))))
               ((BOOT:|BOOT-EQUAL| |a| '|$|)
                  (BOOT:|BOOT-EQUAL|
                     |s|
                     (BOOT::|devaluate| BOOT::|dollar|)))
               ((BOOT:|BOOT-EQUAL| |a| 'BOOT::|$$|)
                  (BOOT:|BOOT-EQUAL|
                     |s|
                     (BOOT::|devaluate| BOOT::|domain|)))
               ((STRINGP |a|)
                  (COND
                     ((STRINGP |s|) (BOOT:|BOOT-EQUAL| |a| |s|))
                     ('T
                        (AND
                           (PAIRP |s|)
                           (EQ (QCAR |s|) 'QUOTE)
                           (PROGN
                              (BOOT:SPADLET BOOT::|ISTMP#1| (QCDR |s|))
                              (AND
                                 (PAIRP BOOT::|ISTMP#1|)
                                 (EQ (QCDR BOOT::|ISTMP#1|) NIL)
                                 (PROGN
                                    (BOOT:SPADLET
                                       |y|
                                       (QCAR BOOT::|ISTMP#1|))
                                    'T)))
                           (BOOT:|BOOT-EQUAL| (SYSTEM::PNAME |y|) |a|))
                        (AND
                           (VMLISP:IDENTP |s|)
                           (BOOT:|BOOT-EQUAL| (SYSTEM::PNAME |s|) |a|)))) )
               ((ATOM |a|) (BOOT:|BOOT-EQUAL| |a| |s|))
               ('T
                  (BOOT:SPADLET BOOT::|op| (BOOT::|opOf| |a|))
                  (COND
                     ((BOOT:|BOOT-EQUAL| BOOT::|op| 'BOOT::NRTEVAL)
                        (BOOT:|BOOT-EQUAL|
                           |s|
                           (BOOT::|nrtEval| (CADR |a|) BOOT::|domain|)))
                     ((BOOT:|BOOT-EQUAL| BOOT::|op| 'QUOTE)
                        (BOOT:|BOOT-EQUAL| |s| (CADR |a|)))
                     ('T
                        (BOOT::|lazyMatch|
                           |s|
                           |a|
                           BOOT::|dollar|
                           BOOT::|domain|)))) ))) ))

*/



/* Code for BOOT::|lazyMatchArg2| */

static Lisp_Object MS_CDECL CC_BOOT__lazyMatchArg2(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5,
                         Lisp_Object V6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V498, V499, V500, V501;
    Lisp_Object fn;
    argcheck(nargs, 5, "lazyMatchArg2");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|lazyMatchArg2|\n");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = V6;
    stack[-2] = V5;
    stack[-3] = V4;
    stack[-4] = V3;
    stack[-5] = V2;
/* end of prologue */
    stack[-6] = nil;
    V499 = stack[-5];
    V498 = elt(env, 1); /* BOOT::$ */
    V498 = Leql(nil, V499, V498);
    env = stack[-7];
    if (!(V498 == nil)) goto V23;
    stack[0] = stack[-5];
    V498 = elt(env, 1); /* BOOT::$ */
    fn = elt(env, 6); /* CHARACTER */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    V498 = Leql(nil, stack[0], V498);
    env = stack[-7];
    goto V23;

V23:
    if (V498 == nil) goto V19;
    V498 = stack[-3];
    fn = elt(env, 7); /* BOOT::|devaluate| */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    stack[-5] = V498;
    goto V19;

V19:
    V498 = stack[-4];
    V498 = Lintegerp(nil, V498);
    env = stack[-7];
    if (V498 == nil) goto V274;
    V498 = stack[-1];
    if (V498 == nil) goto V55;
    V499 = stack[-4];
    V498 = (Lisp_Object)97; /* 6 */
    V498 = Leql(nil, V499, V498);
    env = stack[-7];
    if (V498 == nil) goto V96;
    V498 = qvalue(elt(env, 2)); /* BOOT::|$isDefaultingPackage| */
    if (V498 == nil) goto V96;
    stack[0] = stack[-5];
    V498 = stack[-3];
    fn = elt(env, 7); /* BOOT::|devaluate| */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    V498 = (cl_equal(stack[0], V498) ? lisp_true : nil);
    { popv(8); return onevalue(V498); }

V96:
    V500 = stack[-3];
    V499 = stack[-2];
    V498 = stack[-4];
    fn = elt(env, 8); /* BOOT::|domainVal| */
    V498 = (*qfnn(fn))(qenv(fn), 3, V500, V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    stack[-1] = V498;
    fn = elt(env, 9); /* SIMPLE-VECTOR-P */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    if (V498 == nil) goto V93;
    stack[0] = stack[-5];
    V499 = stack[-1];
    V498 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 10); /* ELT */
    V498 = (*qfn2(fn))(qenv(fn), V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    V498 = (cl_equal(stack[0], V498) ? lisp_true : nil);
    if (V498 == nil) goto V109;
    V498 = lisp_true;
    { popv(8); return onevalue(V498); }

V109:
    V498 = lisp_true;
    if (V498 == nil) goto V127;
    V498 = qvalue(elt(env, 2)); /* BOOT::|$isDefaultingPackage| */
    if (V498 == nil) goto V132;
    V499 = stack[-2];
    V498 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 10); /* ELT */
    V499 = (*qfn2(fn))(qenv(fn), V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    V498 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 10); /* ELT */
    V498 = (*qfn2(fn))(qenv(fn), V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    goto V130;

V130:
    stack[-2] = V498;
    V498 = stack[-5];
    if (!consp(V498)) goto V171;
    V498 = stack[-5];
    V498 = qcar(V498);
    stack[0] = V498;
    goto V180;

V180:
    V499 = stack[-1];
    V498 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 10); /* ELT */
    V498 = (*qfn2(fn))(qenv(fn), V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    V498 = qcar(V498);
    V498 = (cl_equal(stack[0], V498) ? lisp_true : nil);
    if (V498 == nil) goto V162;
    stack[0] = stack[-5];
    V499 = stack[-1];
    V498 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 10); /* ELT */
    stack[-1] = (*qfn2(fn))(qenv(fn), V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    V499 = stack[-3];
    V498 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 10); /* ELT */
    V499 = (*qfn2(fn))(qenv(fn), V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    V498 = stack[-2];
    {
        Lisp_Object V510 = stack[0];
        Lisp_Object V511 = stack[-1];
        popv(8);
        fn = elt(env, 11); /* BOOT::|lazyMatchArgDollarCheck| */
        return (*qfnn(fn))(qenv(fn), 4, V510, V511, V499, V498);
    }

V162:
    V498 = nil;
    { popv(8); return onevalue(V498); }

V171:
    V498 = nil;
    stack[0] = V498;
    goto V180;

V132:
    V498 = lisp_true;
    if (V498 == nil) goto V150;
    V499 = stack[-2];
    V498 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 10); /* ELT */
    V498 = (*qfn2(fn))(qenv(fn), V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    goto V130;

V150:
    V498 = nil;
    goto V130;

V127:
    V498 = nil;
    { popv(8); return onevalue(V498); }

V93:
    V498 = stack[-1];
    fn = elt(env, 12); /* BOOT::|isDomain| */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    if (V498 == nil) goto V221;
    V498 = stack[-1];
    fn = elt(env, 13); /* BOOT::|getDomainHash| */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    stack[-1] = V498;
    stack[0] = stack[-1];
    V498 = stack[-5];
    fn = elt(env, 14); /* BOOT::|hashCode?| */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    if (V498 == nil) goto V235;
    V498 = stack[-5];
    goto V229;

V229:
    V498 = (cl_equal(stack[0], V498) ? lisp_true : nil);
    { popv(8); return onevalue(V498); }

V235:
    V498 = lisp_true;
    if (V498 == nil) goto V240;
    V499 = stack[-5];
    V498 = stack[-1];
    fn = elt(env, 15); /* BOOT::|hashType| */
    V498 = (*qfn2(fn))(qenv(fn), V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    goto V229;

V240:
    V498 = nil;
    goto V229;

V221:
    V498 = lisp_true;
    if (V498 == nil) goto V252;
    V501 = stack[-5];
    V500 = stack[-1];
    V499 = stack[-3];
    V498 = stack[-2];
    {
        popv(8);
        fn = elt(env, 16); /* BOOT::|lazyMatch| */
        return (*qfnn(fn))(qenv(fn), 4, V501, V500, V499, V498);
    }

V252:
    V498 = nil;
    { popv(8); return onevalue(V498); }

V55:
    stack[0] = stack[-5];
    V499 = stack[-2];
    V498 = stack[-4];
    fn = elt(env, 10); /* ELT */
    V498 = (*qfn2(fn))(qenv(fn), V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    V498 = (cl_equal(stack[0], V498) ? lisp_true : nil);
    { popv(8); return onevalue(V498); }

V274:
    V499 = stack[-4];
    V498 = elt(env, 1); /* BOOT::$ */
    V498 = Leql(nil, V499, V498);
    env = stack[-7];
    if (!(V498 == nil)) goto V271;
    stack[0] = stack[-4];
    V498 = elt(env, 1); /* BOOT::$ */
    fn = elt(env, 6); /* CHARACTER */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    V498 = Leql(nil, stack[0], V498);
    env = stack[-7];
    goto V271;

V271:
    if (V498 == nil) goto V301;
    stack[0] = stack[-5];
    V498 = stack[-3];
    fn = elt(env, 7); /* BOOT::|devaluate| */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    V498 = (cl_equal(stack[0], V498) ? lisp_true : nil);
    { popv(8); return onevalue(V498); }

V301:
    V499 = stack[-4];
    V498 = elt(env, 3); /* BOOT::$$ */
    V498 = (V499 == V498 ? lisp_true : nil);
    if (V498 == nil) goto V300;
    stack[0] = stack[-5];
    V498 = stack[-2];
    fn = elt(env, 7); /* BOOT::|devaluate| */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    V498 = (cl_equal(stack[0], V498) ? lisp_true : nil);
    { popv(8); return onevalue(V498); }

V300:
    V498 = stack[-4];
    V498 = Lstringp(nil, V498);
    env = stack[-7];
    if (V498 == nil) goto V319;
    V498 = stack[-5];
    V498 = Lstringp(nil, V498);
    env = stack[-7];
    if (V498 == nil) goto V325;
    V499 = stack[-4];
    V498 = stack[-5];
    V498 = (cl_equal(V499, V498) ? lisp_true : nil);
    { popv(8); return onevalue(V498); }

V325:
    V498 = lisp_true;
    if (V498 == nil) goto V337;
    V498 = stack[-5];
    fn = elt(env, 17); /* CONSP */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    if (V498 == nil) goto V340;
    V498 = stack[-5];
    V499 = qcar(V498);
    V498 = elt(env, 4); /* QUOTE */
    if (!(V499 == V498)) goto V340;
    V498 = stack[-5];
    V498 = qcdr(V498);
    stack[0] = V498;
    V498 = stack[0];
    fn = elt(env, 17); /* CONSP */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    if (V498 == nil) goto V363;
    V498 = stack[0];
    V498 = qcdr(V498);
    if (V498 == nil) goto V373;
    V498 = nil;
    goto V362;

V362:
    if (V498 == nil) goto V340;
    V498 = stack[-6];
    fn = elt(env, 18); /* SYSTEM::PNAME */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    goto V340;

V340:
    V498 = stack[-5];
    if (V498 == nil) goto V396;
    V498 = stack[-5];
    fn = elt(env, 19); /* SYMBOLP */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    goto V395;

V395:
    if (V498 == nil) goto V392;
    V498 = stack[-5];
    fn = elt(env, 18); /* SYSTEM::PNAME */
    V499 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    V498 = stack[-4];
    V498 = (cl_equal(V499, V498) ? lisp_true : nil);
    { popv(8); return onevalue(V498); }

V392:
    V498 = nil;
    { popv(8); return onevalue(V498); }

V396:
    V498 = nil;
    goto V395;

V373:
    V498 = stack[0];
    V498 = qcar(V498);
    stack[-6] = V498;
    V498 = lisp_true;
    goto V362;

V363:
    V498 = nil;
    goto V362;

V337:
    V498 = nil;
    { popv(8); return onevalue(V498); }

V319:
    V498 = stack[-4];
    if (!consp(V498)) goto V419;
    V498 = lisp_true;
    if (V498 == nil) goto V428;
    V498 = stack[-4];
    fn = elt(env, 20); /* BOOT::|opOf| */
    V498 = (*qfn1(fn))(qenv(fn), V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    env = stack[-7];
    V500 = V498;
    V499 = V500;
    V498 = elt(env, 5); /* BOOT::NRTEVAL */
    V498 = (V499 == V498 ? lisp_true : nil);
    if (V498 == nil) goto V463;
    stack[0] = stack[-5];
    V498 = stack[-4];
    if (!car_legal(V498)) goto V512;
    V498 = qcdr(V498);
    if (!car_legal(V498)) goto V513;
    V499 = qcar(V498);
    V498 = stack[-2];
    fn = elt(env, 21); /* BOOT::|nrtEval| */
    V498 = (*qfn2(fn))(qenv(fn), V499, V498);
    nil = C_nil;
    if (exception_pending()) goto V509;
    V498 = (cl_equal(stack[0], V498) ? lisp_true : nil);
    { popv(8); return onevalue(V498); }

V463:
    V499 = V500;
    V498 = elt(env, 4); /* QUOTE */
    V498 = (V499 == V498 ? lisp_true : nil);
    if (V498 == nil) goto V462;
    V499 = stack[-5];
    V498 = stack[-4];
    if (!car_legal(V498)) goto V512;
    V498 = qcdr(V498);
    if (!car_legal(V498)) goto V513;
    V498 = qcar(V498);
    V498 = (cl_equal(V499, V498) ? lisp_true : nil);
    { popv(8); return onevalue(V498); }

V462:
    V498 = lisp_true;
    if (V498 == nil) goto V482;
    V501 = stack[-5];
    V500 = stack[-4];
    V499 = stack[-3];
    V498 = stack[-2];
    {
        popv(8);
        fn = elt(env, 16); /* BOOT::|lazyMatch| */
        return (*qfnn(fn))(qenv(fn), 4, V501, V500, V499, V498);
    }

V482:
    V498 = nil;
    { popv(8); return onevalue(V498); }

V428:
    V498 = nil;
    { popv(8); return onevalue(V498); }

V419:
    V499 = stack[-4];
    V498 = stack[-5];
    V498 = (cl_equal(V499, V498) ? lisp_true : nil);
    { popv(8); return onevalue(V498); }
/* error exit handlers */
V513:
    popv(8);
    return error(1, err_bad_car, V498);
V512:
    popv(8);
    return error(1, err_bad_cdr, V498);
V509:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|KDAGG-;key?;KeySB;1| (|k| |t| |$|)
   (BOOT::QEQCAR (BOOT:SPADCALL |k| |t| (VMLISP:QREFELT |$| 10)) 0))

*/



/* Code for BOOT::|KDAGG-;key?;KeySB;1| */

static Lisp_Object MS_CDECL CC_BOOT__KDAGGKUkeyWUKeySBU1(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V43, V44, V45, V46;
    argcheck(nargs, 3, "KDAGG-;key?;KeySB;1");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|KDAGG-;key?;KeySB;1|\n");
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
    V43 = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V44 = V43;
    V43 = (Lisp_Object)161; /* 10 */
    V43 = Lgetv(nil, V44, V43);
    nil = C_nil;
    if (exception_pending()) goto V49;
    env = stack[-2];
    V44 = V43;
    if (!car_legal(V44)) goto V50;
    V46 = qcar(V44);
    V45 = stack[-1];
    V44 = stack[0];
    if (!car_legal(V43)) goto V51;
    V43 = qcdr(V43);
    V43 = Lapply3(nil, 4, V46, V45, V44, V43);
    nil = C_nil;
    if (exception_pending()) goto V49;
    V44 = qcar(V43);
    V43 = (Lisp_Object)1; /* 0 */
        popv(3);
        return Leql(nil, V44, V43);
/* error exit handlers */
V51:
    popv(3);
    return error(1, err_bad_cdr, V43);
V50:
    popv(3);
    return error(1, err_bad_car, V44);
V49:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|EXPR;=;2$B;21| (|x| |y| |$|)
   (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 76)))

*/



/* Code for BOOT::|EXPR;=;2$B;21| */

static Lisp_Object MS_CDECL CC_BOOT__EXPRUMU2DBU21(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "EXPR;=;2$B;21");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;=;2$B;21|\n");
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
    V35 = (Lisp_Object)1217; /* 76 */
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
(DEFUN BOOT::|COMPCAT-;recip;SU;48| (|x| |$|)
   (BOOT:SPADCALL
      (BOOT::|spadConstant| |$| 8)
      |x|
      (VMLISP:QREFELT |$| 207)))

*/



/* Code for BOOT::|COMPCAT-;recip;SU;48| */

static Lisp_Object CC_BOOT__COMPCATKUrecipUSUU48(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V54, V55, V56;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPCAT-;recip;SU;48|\n");
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
    V54 = (Lisp_Object)3313; /* 207 */
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
    V55 = qcar(V55);
    if (!car_legal(V54)) goto V64;
    V54 = qcdr(V54);
    V54 = Lapply1(nil, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V61;
    V56 = V54;
    V55 = stack[-2];
    V54 = stack[-3];
    if (!car_legal(V54)) goto V64;
    V54 = qcdr(V54);
    {
        Lisp_Object V65 = stack[0];
        popv(5);
        return Lapply3(nil, 4, V65, V56, V55, V54);
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
(DEFUN BOOT::|SMP;mainVariable;$U;63| (|p| |$|)
   (COND
      ((BOOT::QEQCAR |p| 0) (CONS 1 "failed"))
      ('T (CONS 0 (QCAR (QCDR |p|)))) ))

*/



/* Code for BOOT::|SMP;mainVariable;$U;63| */

static Lisp_Object CC_BOOT__SMPUmainVariableUDUU63(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V41, V42, V43;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;mainVariable;$U;63|\n");
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
    V41 = V3;
    V42 = V2;
/* end of prologue */
    V41 = V42;
    V43 = qcar(V41);
    V41 = (Lisp_Object)1; /* 0 */
    V41 = Leql(nil, V43, V41);
    env = stack[0];
    if (V41 == nil) goto V10;
    V41 = (Lisp_Object)17; /* 1 */
    V42 = elt(env, 1); /* "failed" */
    popv(1);
    { Lisp_Object retVal = cons(V41, V42);
    errexit();
    return onevalue(retVal); }

V10:
    V41 = lisp_true;
    if (V41 == nil) goto V29;
    V41 = (Lisp_Object)1; /* 0 */
    V42 = qcdr(V42);
    V42 = qcar(V42);
    popv(1);
    { Lisp_Object retVal = cons(V41, V42);
    errexit();
    return onevalue(retVal); }

V29:
    V41 = nil;
    { popv(1); return onevalue(V41); }
}

/*
(DEFUN BOOT::|SCACHE;enterInCache;SMS;5| (|x| BOOT::|triage| |$|)
   (PROG (|i| #:G82372 |y| |n| #:G82365 #:G82371 BOOT::|scan| BOOT::|pos|)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (BOOT::LETT
                     BOOT::|scan|
                     (BOOT:SPADCALL (VMLISP:QREFELT |$| 9))
                     BOOT::|SCACHE;enterInCache;SMS;5|)
                  (BOOT::LETT
                     BOOT::|pos|
                     0
                     BOOT::|SCACHE;enterInCache;SMS;5|)
                  (SEQ
                     (BOOT::LETT |i| 1 BOOT::|SCACHE;enterInCache;SMS;5|)
                     (BOOT::LETT
                        #:G82372
                        (LENGTH BOOT::|scan|)
                        BOOT::|SCACHE;enterInCache;SMS;5|)
                     BOOT::G190
                     (COND
                        ((VMLISP:QSGREATERP |i| #:G82372) (GO BOOT::G191)))
                     (SEQ
                        (EXIT
                           (COND
                              ((ZEROP
                                  (BOOT::LETT
                                     |n|
                                     (BOOT:SPADCALL
                                        |x|
                                        (BOOT::LETT
                                           |y|
                                           (BOOT::|SPADfirst| BOOT::|scan|)
                                        BOOT::|SCACHE;enterInCache;SMS;5|)
                                        BOOT::|triage|)
                                     BOOT::|SCACHE;enterInCache;SMS;5|))
                                 (SEQ
                                    (BOOT:SPADCALL
                                       |x|
                                       (BOOT:SPADCALL
                                          |y|
                                          (VMLISP:QREFELT |$| 11))
                                       (VMLISP:QREFELT |$| 13))
                                    (EXIT
                                       (PROGN
                                          (BOOT::LETT
                                             #:G82371
                                             |y|
                                       BOOT::|SCACHE;enterInCache;SMS;5|)
                                          (GO #:G82371)))) )
                              ((|<| |n| 0)
                                 (PROGN
                                    (BOOT::LETT
                                       #:G82371
                                       (BOOT::|SCACHE;insertInCache|
                                          (BOOT:SPADCALL
                                             (BOOT:SPADCALL
                                                (VMLISP:QREFELT |$| 9))
                                             (PROG1
                                                (BOOT::LETT
                                                   #:G82365
                                                   (|-| |i| 1)
                                       BOOT::|SCACHE;enterInCache;SMS;5|)
                                                (BOOT::|check-subtype|
                                                   (|>=| #:G82365 0)
                                             '(BOOT:|NonNegativeInteger|)
                                                   #:G82365))
                                             (VMLISP:QREFELT |$| 19))
                                          BOOT::|scan|
                                          |x|
                                          BOOT::|pos|
                                          |$|)
                                       BOOT::|SCACHE;enterInCache;SMS;5|)
                                    (GO #:G82371)))
                              ('T
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|scan|
                                       (CDR BOOT::|scan|)
                                       BOOT::|SCACHE;enterInCache;SMS;5|)
                                    (EXIT
                                       (BOOT::LETT
                                          BOOT::|pos|
                                          (BOOT:SPADCALL
                                             |y|
                                             (VMLISP:QREFELT |$| 11))
                                 BOOT::|SCACHE;enterInCache;SMS;5|)))) )))
                     (BOOT::LETT
                        |i|
                        (VMLISP:QSADD1 |i|)
                        BOOT::|SCACHE;enterInCache;SMS;5|)
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT NIL))
                  (BOOT:SPADCALL
                     |x|
                     (|+| BOOT::|pos| 1024)
                     (VMLISP:QREFELT |$| 13))
                  (PROGN
                     (RPLACA
                        (VMLISP:QREFELT |$| 7)
                        (BOOT:SPADCALL
                           (BOOT:SPADCALL (VMLISP:QREFELT |$| 9))
                           |x|
                           (VMLISP:QREFELT |$| 16)))
                     (QCAR (VMLISP:QREFELT |$| 7)))
                  (EXIT |x|)))
            #:G82371
            (EXIT #:G82371)))) )

*/



/* Code for BOOT::|SCACHE;enterInCache;SMS;5| */

static Lisp_Object MS_CDECL CC_BOOT__SCACHEUenterInCacheUSMSU5(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V402, V403, V404, V405, V406;
    Lisp_Object fn;
    argcheck(nargs, 3, "SCACHE;enterInCache;SMS;5");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SCACHE;enterInCache;SMS;5|\n");
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
    stack[-7] = V4;
    stack[-8] = V3;
    stack[-9] = V2;
/* end of prologue */
    V403 = stack[-7];
    V402 = (Lisp_Object)145; /* 9 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V403 = V402;
    if (!car_legal(V403)) goto V419;
    V403 = qcar(V403);
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    V402 = Lapply1(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    stack[-4] = V402;
    V402 = (Lisp_Object)1; /* 0 */
    stack[-3] = V402;
    V402 = (Lisp_Object)17; /* 1 */
    stack[-10] = V402;
    V402 = stack[-4];
    V402 = Llength(nil, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    stack[-6] = V402;
    goto V57;

V57:
    V403 = stack[-10];
    V402 = stack[-6];
    V402 = (Lisp_Object)greaterp2(V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    V402 = V402 ? lisp_true : nil;
    env = stack[-11];
    if (V402 == nil) goto V53;
    V403 = stack[-7];
    V402 = (Lisp_Object)209; /* 13 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    stack[-2] = V402;
    V402 = stack[-2];
    if (!car_legal(V402)) goto V421;
    stack[-1] = qcar(V402);
    stack[0] = stack[-9];
    V403 = stack[-3];
    V402 = (Lisp_Object)16385; /* 1024 */
    V403 = plus2(V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V402 = stack[-2];
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    V402 = Lapply3(nil, 4, stack[-1], stack[0], V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V403 = stack[-7];
    V402 = (Lisp_Object)113; /* 7 */
    stack[-2] = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V403 = stack[-7];
    V402 = (Lisp_Object)257; /* 16 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    stack[-1] = V402;
    V402 = stack[-1];
    if (!car_legal(V402)) goto V421;
    stack[0] = qcar(V402);
    V403 = stack[-7];
    V402 = (Lisp_Object)145; /* 9 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V403 = V402;
    if (!car_legal(V403)) goto V419;
    V403 = qcar(V403);
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    V402 = Lapply1(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V404 = V402;
    V403 = stack[-9];
    V402 = stack[-1];
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    V402 = Lapply3(nil, 4, stack[0], V404, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V402 = Lrplaca(nil, stack[-2], V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V403 = stack[-7];
    V402 = (Lisp_Object)113; /* 7 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    { Lisp_Object res = stack[-9]; popv(12); return onevalue(res); }

V53:
    V402 = stack[-8];
    stack[-2] = V402;
    V402 = stack[-2];
    if (!car_legal(V402)) goto V421;
    stack[-1] = qcar(V402);
    stack[0] = stack[-9];
    V402 = stack[-4];
    V403 = V402;
    V402 = V403;
    if (V402 == nil) goto V95;
    V402 = V403;
    if (!car_legal(V402)) goto V421;
    V402 = qcar(V402);
    goto V93;

V93:
    V403 = V402;
    stack[-5] = V403;
    V402 = stack[-2];
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    V402 = Lapply3(nil, 4, stack[-1], stack[0], V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V403 = V402;
    V402 = (Lisp_Object)zerop(V402);
    V402 = V402 ? lisp_true : nil;
    env = stack[-11];
    if (V402 == nil) goto V161;
    V403 = stack[-7];
    V402 = (Lisp_Object)209; /* 13 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    stack[-1] = V402;
    V402 = stack[-1];
    if (!car_legal(V402)) goto V421;
    stack[0] = qcar(V402);
    stack[-2] = stack[-9];
    V403 = stack[-7];
    V402 = (Lisp_Object)177; /* 11 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V403 = V402;
    if (!car_legal(V403)) goto V419;
    V404 = qcar(V403);
    V403 = stack[-5];
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    V402 = Lapply2(nil, 3, V404, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V403 = V402;
    V402 = stack[-1];
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    V402 = Lapply3(nil, 4, stack[0], stack[-2], V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    { Lisp_Object res = stack[-5]; popv(12); return onevalue(res); }

V161:
    V402 = (Lisp_Object)1; /* 0 */
    V402 = (Lisp_Object)lessp2(V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    V402 = V402 ? lisp_true : nil;
    env = stack[-11];
    if (V402 == nil) goto V157;
    V403 = stack[-7];
    V402 = (Lisp_Object)305; /* 19 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    stack[-5] = V402;
    V402 = stack[-5];
    if (!car_legal(V402)) goto V421;
    stack[-2] = qcar(V402);
    V403 = stack[-7];
    V402 = (Lisp_Object)145; /* 9 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V403 = V402;
    if (!car_legal(V403)) goto V419;
    V403 = qcar(V403);
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    V402 = Lapply1(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    stack[-1] = V402;
    V402 = stack[-10];
    V402 = sub1(V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    stack[-6] = V402;
    stack[0] = V402;
    V403 = stack[-6];
    V402 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 2); /* >= */
    V402 = (*qfn2(fn))(qenv(fn), V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    if (!(V402 == nil)) goto V229;
    V403 = stack[-6];
    V402 = elt(env, 1); /* (BOOT:|NonNegativeInteger|) */
    fn = elt(env, 3); /* BOOT::COERCE-FAILURE-MSG */
    V402 = (*qfn2(fn))(qenv(fn), V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    fn = elt(env, 4); /* BOOT::|error| */
    V402 = (*qfn1(fn))(qenv(fn), V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    goto V229;

V229:
    V402 = stack[0];
    V403 = V402;
    V402 = stack[-5];
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    V402 = Lapply3(nil, 4, stack[-2], stack[-1], V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V406 = V402;
    V405 = stack[-4];
    V404 = stack[-9];
    V403 = stack[-3];
    V402 = stack[-7];
    {
        popv(12);
        fn = elt(env, 5); /* BOOT::|SCACHE;insertInCache| */
        return (*qfnn(fn))(qenv(fn), 5, V406, V405, V404, V403, V402);
    }

V157:
    V402 = lisp_true;
    if (V402 == nil) goto V65;
    V402 = stack[-4];
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    stack[-4] = V402;
    V403 = stack[-7];
    V402 = (Lisp_Object)177; /* 11 */
    V402 = Lgetv(nil, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    V403 = V402;
    if (!car_legal(V403)) goto V419;
    V404 = qcar(V403);
    V403 = stack[-5];
    if (!car_legal(V402)) goto V420;
    V402 = qcdr(V402);
    V402 = Lapply2(nil, 3, V404, V403, V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    stack[-3] = V402;
    goto V65;

V65:
    V402 = stack[-10];
    V402 = add1(V402);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    stack[-10] = V402;
    goto V57;

V95:
    fn = elt(env, 6); /* BOOT::FIRST-ERROR */
    V402 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V418;
    env = stack[-11];
    goto V93;
/* error exit handlers */
V421:
    popv(12);
    return error(1, err_bad_car, V402);
V420:
    popv(12);
    return error(1, err_bad_cdr, V402);
V419:
    popv(12);
    return error(1, err_bad_car, V403);
V418:
    popv(12);
    return nil;
}

/*
(DEFUN BOOT::|SMP;coerce;R$;21| (|c| |$|) (CONS 0 |c|))

*/



/* Code for BOOT::|SMP;coerce;R$;21| */

static Lisp_Object CC_BOOT__SMPUcoerceURDU21(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;coerce;R$;21|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V15 = V3;
    V16 = V2;
/* end of prologue */
    V15 = (Lisp_Object)1; /* 0 */
    { Lisp_Object retVal = cons(V15, V16);
    errexit();
    return onevalue(retVal); }
}

/*
(DEFUN BOOT::|COMPLEX;exquo;2$U;16| (|x| |y| |$|)
   (COND
      ((BOOT:SPADCALL (QCDR |y|) (VMLISP:QREFELT |$| 32))
         (BOOT:SPADCALL |x| (QCAR |y|) (VMLISP:QREFELT |$| 44)))
      ('T
         (BOOT:SPADCALL
            (BOOT:SPADCALL
               |x|
               (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 45))
               (VMLISP:QREFELT |$| 42))
            (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 46))
            (VMLISP:QREFELT |$| 44)))) )

*/



/* Code for BOOT::|COMPLEX;exquo;2$U;16| */

static Lisp_Object MS_CDECL CC_BOOT__COMPLEXUexquoU2DUU16(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V167, V168, V169, V170;
    argcheck(nargs, 3, "COMPLEX;exquo;2$U;16");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPLEX;exquo;2$U;16|\n");
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
    V168 = stack[-3];
    V167 = (Lisp_Object)513; /* 32 */
    V167 = Lgetv(nil, V168, V167);
    nil = C_nil;
    if (exception_pending()) goto V178;
    env = stack[-7];
    V168 = V167;
    if (!car_legal(V168)) goto V179;
    V169 = qcar(V168);
    V168 = stack[-4];
    V168 = qcdr(V168);
    if (!car_legal(V167)) goto V180;
    V167 = qcdr(V167);
    V167 = Lapply2(nil, 3, V169, V168, V167);
    nil = C_nil;
    if (exception_pending()) goto V178;
    env = stack[-7];
    if (V167 == nil) goto V11;
    V168 = stack[-3];
    V167 = (Lisp_Object)705; /* 44 */
    V167 = Lgetv(nil, V168, V167);
    nil = C_nil;
    if (exception_pending()) goto V178;
    V168 = V167;
    if (!car_legal(V168)) goto V179;
    V170 = qcar(V168);
    V169 = stack[-5];
    V168 = stack[-4];
    V168 = qcar(V168);
    if (!car_legal(V167)) goto V180;
    V167 = qcdr(V167);
        popv(8);
        return Lapply3(nil, 4, V170, V169, V168, V167);

V11:
    V167 = lisp_true;
    if (V167 == nil) goto V66;
    V168 = stack[-3];
    V167 = (Lisp_Object)705; /* 44 */
    V167 = Lgetv(nil, V168, V167);
    nil = C_nil;
    if (exception_pending()) goto V178;
    env = stack[-7];
    stack[-6] = V167;
    V167 = stack[-6];
    if (!car_legal(V167)) goto V181;
    stack[-2] = qcar(V167);
    V168 = stack[-3];
    V167 = (Lisp_Object)673; /* 42 */
    V167 = Lgetv(nil, V168, V167);
    nil = C_nil;
    if (exception_pending()) goto V178;
    env = stack[-7];
    stack[-1] = V167;
    V167 = stack[-1];
    if (!car_legal(V167)) goto V181;
    stack[0] = qcar(V167);
    V168 = stack[-3];
    V167 = (Lisp_Object)721; /* 45 */
    V167 = Lgetv(nil, V168, V167);
    nil = C_nil;
    if (exception_pending()) goto V178;
    env = stack[-7];
    V168 = V167;
    if (!car_legal(V168)) goto V179;
    V169 = qcar(V168);
    V168 = stack[-4];
    if (!car_legal(V167)) goto V180;
    V167 = qcdr(V167);
    V167 = Lapply2(nil, 3, V169, V168, V167);
    nil = C_nil;
    if (exception_pending()) goto V178;
    env = stack[-7];
    V168 = V167;
    V167 = stack[-1];
    if (!car_legal(V167)) goto V180;
    V167 = qcdr(V167);
    V167 = Lapply3(nil, 4, stack[0], stack[-5], V168, V167);
    nil = C_nil;
    if (exception_pending()) goto V178;
    env = stack[-7];
    stack[0] = V167;
    V168 = stack[-3];
    V167 = (Lisp_Object)737; /* 46 */
    V167 = Lgetv(nil, V168, V167);
    nil = C_nil;
    if (exception_pending()) goto V178;
    env = stack[-7];
    V168 = V167;
    if (!car_legal(V168)) goto V179;
    V169 = qcar(V168);
    V168 = stack[-4];
    if (!car_legal(V167)) goto V180;
    V167 = qcdr(V167);
    V167 = Lapply2(nil, 3, V169, V168, V167);
    nil = C_nil;
    if (exception_pending()) goto V178;
    V168 = V167;
    V167 = stack[-6];
    if (!car_legal(V167)) goto V180;
    V167 = qcdr(V167);
    {
        Lisp_Object V182 = stack[-2];
        Lisp_Object V183 = stack[0];
        popv(8);
        return Lapply3(nil, 4, V182, V183, V168, V167);
    }

V66:
    V167 = nil;
    { popv(8); return onevalue(V167); }
/* error exit handlers */
V181:
    popv(8);
    return error(1, err_bad_car, V167);
V180:
    popv(8);
    return error(1, err_bad_cdr, V167);
V179:
    popv(8);
    return error(1, err_bad_car, V168);
V178:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|get| (|x| BOOT::|prop| |e|)
   (COND
      (BOOT:|$InteractiveMode| (BOOT::|get0| |x| BOOT::|prop| |e|))
      ('T (BOOT::|get1| |x| BOOT::|prop| |e|))))

*/



/* Code for BOOT::|get| */

static Lisp_Object MS_CDECL CC_BOOT__get(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V38, V39, V40, V41;
    Lisp_Object fn;
    argcheck(nargs, 3, "get");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|get|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V39 = V4;
    V40 = V3;
    V41 = V2;
/* end of prologue */
    V38 = qvalue(elt(env, 1)); /* BOOT::|$InteractiveMode| */
    if (V38 == nil) goto V11;
    V38 = V41;
    {
        fn = elt(env, 2); /* BOOT::|get0| */
        return (*qfnn(fn))(qenv(fn), 3, V38, V40, V39);
    }

V11:
    V38 = lisp_true;
    if (V38 == nil) goto V25;
    V38 = V41;
    {
        fn = elt(env, 3); /* BOOT::|get1| */
        return (*qfnn(fn))(qenv(fn), 3, V38, V40, V39);
    }

V25:
    V38 = nil;
    return onevalue(V38);
}

/*
(DEFUN BOOT::|SMP;exquo;2$U;39| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (|a| BOOT::|mvar| BOOT::|up|)
      (RETURN
         (SEQ
            (COND
               ((BOOT::QEQCAR BOOT::|p1| 0)
                  (COND
                     ((BOOT::QEQCAR BOOT::|p2| 0)
                        (EXIT
                           (SEQ
                              (BOOT::LETT
                                 |a|
                                 (BOOT:SPADCALL
                                    (QCDR BOOT::|p1|)
                                    (QCDR BOOT::|p2|)
                                    (VMLISP:QREFELT |$| 119))
                                 BOOT::|SMP;exquo;2$U;39|)
                              (EXIT
                                 (COND
                                    ((BOOT::QEQCAR |a| 1)
                                       (CONS 1 "failed"))
                                    ('T
                                       (CONS
                                          0
                                          (CONS 0 (QCDR |a|)))) ))) ))) ))
            (EXIT
               (COND
                  ((OR
                      (BOOT:SPADCALL BOOT::|p1| (VMLISP:QREFELT |$| 17))
                      (BOOT:SPADCALL BOOT::|p2| (VMLISP:QREFELT |$| 19)))
                     (CONS 0 BOOT::|p1|))
                  ('T
                     (SEQ
                        (COND
                           ((BOOT::QEQCAR BOOT::|p1| 0)
                              (EXIT (CONS 1 "failed")))
                           ((BOOT::QEQCAR BOOT::|p2| 1)
                              (COND
                                 ((BOOT:SPADCALL
                                     (QCAR (QCDR BOOT::|p1|))
                                     (QCAR (QCDR BOOT::|p2|))
                                     (VMLISP:QREFELT |$| 50))
                                    (EXIT (CONS 1 "failed")))) ))
                        (COND
                           ((OR
                               (BOOT::QEQCAR BOOT::|p2| 0)
                               (BOOT:SPADCALL
                                  (QCAR (QCDR BOOT::|p2|))
                                  (QCAR (QCDR BOOT::|p1|))
                                  (VMLISP:QREFELT |$| 50)))
                              (EXIT
                                 (SEQ
                                    (BOOT::LETT
                                       |a|
                                       (BOOT:SPADCALL
                                          (QCDR (QCDR BOOT::|p1|))
                                          (BOOT:SPADCALL
                                             BOOT::|p2|
                                             (VMLISP:QREFELT |$| 93))
                                          (VMLISP:QREFELT |$| 120))
                                       BOOT::|SMP;exquo;2$U;39|)
                                    (EXIT
                                       (COND
                                          ((BOOT::QEQCAR |a| 1)
                                             (CONS 1 "failed"))
                                          ('T
                                             (CONS
                                                0
                                                (CONS
                                                   1
                                                   (CONS
        (QCAR (QCDR BOOT::|p1|))
        (QCDR |a|)))) ))) ))) )
                        (EXIT
                           (COND
                              ((BOOT:SPADCALL
                                  BOOT::|p1|
                                  BOOT::|p2|
                                  (VMLISP:QREFELT |$| 98))
                                 (CONS 0 (BOOT::|spadConstant| |$| 14)))
                              ('T
                                 (SEQ
                                    (BOOT::LETT
                                       |a|
                                       (BOOT:SPADCALL
                                          (QCDR (QCDR BOOT::|p1|))
                                          (QCDR (QCDR BOOT::|p2|))
                                          (VMLISP:QREFELT |$| 120))
                                       BOOT::|SMP;exquo;2$U;39|)
                                    (EXIT
                                       (COND
                                          ((BOOT::QEQCAR |a| 1)
                                             (CONS 1 "failed"))
                                          ('T
                                             (SEQ
                                                (BOOT::LETT
                                                   BOOT::|mvar|
                                                   (QCAR
        (QCDR BOOT::|p1|))
                                                   BOOT::|SMP;exquo;2$U;39|)
                                                (BOOT::LETT
                                                   BOOT::|up|
                                                   (QCDR |a|)
                                                BOOT::|SMP;exquo;2$U;39|)
                                                (EXIT
                                                   (COND
        ((BOOT:SPADCALL BOOT::|up| (VMLISP:QREFELT |$| 62))
        (CONS 0 (BOOT:SPADCALL BOOT::|up| (VMLISP:QREFELT |$| 60))))
        ('T
        (CONS
           0
           (CONS
              1
              (CONS
                 BOOT::|mvar|
                 BOOT::|up|)))) ))) ))) ))) ))) ))) )))

*/



/* Code for BOOT::|SMP;exquo;2$U;39| */

static Lisp_Object MS_CDECL CC_BOOT__SMPUexquoU2DUU39(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V607, V608, V609, V610;
    argcheck(nargs, 3, "SMP;exquo;2$U;39");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;exquo;2$U;39|\n");
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
    V607 = stack[-4];
    V608 = qcar(V607);
    V607 = (Lisp_Object)1; /* 0 */
    V607 = Leql(nil, V608, V607);
    env = stack[-6];
    if (V607 == nil) goto V118;
    V607 = stack[-3];
    V608 = qcar(V607);
    V607 = (Lisp_Object)1; /* 0 */
    V607 = Leql(nil, V608, V607);
    env = stack[-6];
    if (V607 == nil) goto V118;
    V608 = stack[-2];
    V607 = (Lisp_Object)1905; /* 119 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V610 = qcar(V608);
    V608 = stack[-4];
    V609 = qcdr(V608);
    V608 = stack[-3];
    V608 = qcdr(V608);
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply3(nil, 4, V610, V609, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V609 = V607;
    V607 = V609;
    V608 = qcar(V607);
    V607 = (Lisp_Object)17; /* 1 */
    V607 = Leql(nil, V608, V607);
    env = stack[-6];
    if (V607 == nil) goto V75;
    V607 = (Lisp_Object)17; /* 1 */
    V608 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V607, V608);
    errexit();
    return onevalue(retVal); }

V75:
    V607 = lisp_true;
    if (V607 == nil) goto V94;
    V608 = (Lisp_Object)1; /* 0 */
    V607 = (Lisp_Object)1; /* 0 */
    V609 = qcdr(V609);
    popv(7);
    { Lisp_Object retVal = list2star(V608, V607, V609);
    errexit();
    return onevalue(retVal); }

V94:
    V607 = nil;
    { popv(7); return onevalue(V607); }

V118:
    V608 = stack[-2];
    V607 = (Lisp_Object)273; /* 17 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V609 = qcar(V608);
    V608 = stack[-4];
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply2(nil, 3, V609, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    if (!(V607 == nil)) goto V164;
    V608 = stack[-2];
    V607 = (Lisp_Object)305; /* 19 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V609 = qcar(V608);
    V608 = stack[-3];
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply2(nil, 3, V609, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    if (!(V607 == nil)) goto V164;
    V607 = lisp_true;
    if (V607 == nil) goto V172;
    V607 = stack[-4];
    V608 = qcar(V607);
    V607 = (Lisp_Object)1; /* 0 */
    V607 = Leql(nil, V608, V607);
    env = stack[-6];
    if (V607 == nil) goto V200;
    V607 = (Lisp_Object)17; /* 1 */
    V608 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V607, V608);
    errexit();
    return onevalue(retVal); }

V200:
    V607 = stack[-3];
    V608 = qcar(V607);
    V607 = (Lisp_Object)17; /* 1 */
    V607 = Leql(nil, V608, V607);
    env = stack[-6];
    if (V607 == nil) goto V257;
    V608 = stack[-2];
    V607 = (Lisp_Object)801; /* 50 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V610 = qcar(V608);
    V608 = stack[-4];
    V608 = qcdr(V608);
    V609 = qcar(V608);
    V608 = stack[-3];
    V608 = qcdr(V608);
    V608 = qcar(V608);
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply3(nil, 4, V610, V609, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    if (V607 == nil) goto V257;
    V607 = (Lisp_Object)17; /* 1 */
    V608 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V607, V608);
    errexit();
    return onevalue(retVal); }

V257:
    V607 = stack[-3];
    V608 = qcar(V607);
    V607 = (Lisp_Object)1; /* 0 */
    V607 = Leql(nil, V608, V607);
    env = stack[-6];
    if (!(V607 == nil)) goto V303;
    V608 = stack[-2];
    V607 = (Lisp_Object)801; /* 50 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V610 = qcar(V608);
    V608 = stack[-3];
    V608 = qcdr(V608);
    V609 = qcar(V608);
    V608 = stack[-4];
    V608 = qcdr(V608);
    V608 = qcar(V608);
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply3(nil, 4, V610, V609, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    if (!(V607 == nil)) goto V303;
    V608 = stack[-2];
    V607 = (Lisp_Object)1569; /* 98 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V610 = qcar(V608);
    V609 = stack[-4];
    V608 = stack[-3];
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply3(nil, 4, V610, V609, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    if (V607 == nil) goto V400;
    stack[0] = (Lisp_Object)1; /* 0 */
    V608 = stack[-2];
    V607 = (Lisp_Object)225; /* 14 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V608 = qcar(V608);
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply1(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    {
        Lisp_Object V620 = stack[0];
        popv(7);
        { Lisp_Object retVal = cons(V620, V607);
        errexit();
        return onevalue(retVal); }
    }

V400:
    V607 = lisp_true;
    if (V607 == nil) goto V457;
    V608 = stack[-2];
    V607 = (Lisp_Object)1921; /* 120 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V610 = qcar(V608);
    V608 = stack[-4];
    V608 = qcdr(V608);
    V609 = qcdr(V608);
    V608 = stack[-3];
    V608 = qcdr(V608);
    V608 = qcdr(V608);
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply3(nil, 4, V610, V609, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V609 = V607;
    V607 = V609;
    V608 = qcar(V607);
    V607 = (Lisp_Object)17; /* 1 */
    V607 = Leql(nil, V608, V607);
    env = stack[-6];
    if (V607 == nil) goto V495;
    V607 = (Lisp_Object)17; /* 1 */
    V608 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V607, V608);
    errexit();
    return onevalue(retVal); }

V495:
    V607 = lisp_true;
    if (V607 == nil) goto V514;
    V607 = stack[-4];
    V607 = qcdr(V607);
    V607 = qcar(V607);
    stack[-3] = V607;
    V607 = V609;
    V607 = qcdr(V607);
    stack[-1] = V607;
    V608 = stack[-2];
    V607 = (Lisp_Object)993; /* 62 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V609 = qcar(V608);
    V608 = stack[-1];
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply2(nil, 3, V609, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    if (V607 == nil) goto V526;
    stack[0] = (Lisp_Object)1; /* 0 */
    V608 = stack[-2];
    V607 = (Lisp_Object)961; /* 60 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V609 = qcar(V608);
    V608 = stack[-1];
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply2(nil, 3, V609, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    {
        Lisp_Object V621 = stack[0];
        popv(7);
        { Lisp_Object retVal = cons(V621, V607);
        errexit();
        return onevalue(retVal); }
    }

V526:
    V607 = lisp_true;
    if (V607 == nil) goto V583;
    stack[-2] = (Lisp_Object)1; /* 0 */
    stack[0] = (Lisp_Object)17; /* 1 */
    V608 = stack[-3];
    V607 = stack[-1];
    V607 = cons(V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    {
        Lisp_Object V622 = stack[-2];
        Lisp_Object V623 = stack[0];
        popv(7);
        { Lisp_Object retVal = list2star(V622, V623, V607);
        errexit();
        return onevalue(retVal); }
    }

V583:
    V607 = nil;
    { popv(7); return onevalue(V607); }

V514:
    V607 = nil;
    { popv(7); return onevalue(V607); }

V457:
    V607 = nil;
    { popv(7); return onevalue(V607); }

V303:
    V608 = stack[-2];
    V607 = (Lisp_Object)1921; /* 120 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    stack[-5] = V607;
    V607 = stack[-5];
    if (!car_legal(V607)) goto V624;
    stack[-1] = qcar(V607);
    V607 = stack[-4];
    V607 = qcdr(V607);
    stack[0] = qcdr(V607);
    V608 = stack[-2];
    V607 = (Lisp_Object)1489; /* 93 */
    V607 = Lgetv(nil, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    if (!car_legal(V608)) goto V618;
    V609 = qcar(V608);
    V608 = stack[-3];
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply2(nil, 3, V609, V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V608 = V607;
    V607 = stack[-5];
    if (!car_legal(V607)) goto V619;
    V607 = qcdr(V607);
    V607 = Lapply3(nil, 4, stack[-1], stack[0], V608, V607);
    nil = C_nil;
    if (exception_pending()) goto V617;
    env = stack[-6];
    V609 = V607;
    V607 = V609;
    V608 = qcar(V607);
    V607 = (Lisp_Object)17; /* 1 */
    V607 = Leql(nil, V608, V607);
    env = stack[-6];
    if (V607 == nil) goto V354;
    V607 = (Lisp_Object)17; /* 1 */
    V608 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V607, V608);
    errexit();
    return onevalue(retVal); }

V354:
    V607 = lisp_true;
    if (V607 == nil) goto V373;
    stack[-1] = (Lisp_Object)1; /* 0 */
    stack[0] = (Lisp_Object)17; /* 1 */
    V607 = stack[-4];
    V607 = qcdr(V607);
    V607 = qcar(V607);
    V608 = V609;
    V608 = qcdr(V608);
    V607 = cons(V607, V608);
    nil = C_nil;
    if (exception_pending()) goto V617;
    {
        Lisp_Object V625 = stack[-1];
        Lisp_Object V626 = stack[0];
        popv(7);
        { Lisp_Object retVal = list2star(V625, V626, V607);
        errexit();
        return onevalue(retVal); }
    }

V373:
    V607 = nil;
    { popv(7); return onevalue(V607); }

V172:
    V607 = nil;
    { popv(7); return onevalue(V607); }

V164:
    V608 = (Lisp_Object)1; /* 0 */
    V607 = stack[-4];
    popv(7);
    { Lisp_Object retVal = cons(V608, V607);
    errexit();
    return onevalue(retVal); }
/* error exit handlers */
V624:
    popv(7);
    return error(1, err_bad_car, V607);
V619:
    popv(7);
    return error(1, err_bad_cdr, V607);
V618:
    popv(7);
    return error(1, err_bad_car, V608);
V617:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|SMP;exquo;2$U;40| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (|a| BOOT::|mvar| BOOT::|up|)
      (RETURN
         (SEQ
            (COND
               ((BOOT::QEQCAR BOOT::|p1| 0)
                  (COND
                     ((BOOT::QEQCAR BOOT::|p2| 0)
                        (EXIT
                           (SEQ
                              (BOOT::LETT
                                 |a|
                                 (BOOT:SPADCALL
                                    (QCDR BOOT::|p1|)
                                    (QCDR BOOT::|p2|)
                                    (VMLISP:QREFELT |$| 119))
                                 BOOT::|SMP;exquo;2$U;40|)
                              (EXIT
                                 (COND
                                    ((BOOT::QEQCAR |a| 1)
                                       (CONS 1 "failed"))
                                    ('T
                                       (CONS
                                          0
                                          (CONS 0 (QCDR |a|)))) ))) ))) ))
            (EXIT
               (COND
                  ((OR
                      (BOOT:SPADCALL BOOT::|p1| (VMLISP:QREFELT |$| 17))
                      (BOOT:SPADCALL BOOT::|p2| (VMLISP:QREFELT |$| 19)))
                     (CONS 0 BOOT::|p1|))
                  ('T
                     (SEQ
                        (COND
                           ((BOOT::QEQCAR BOOT::|p1| 0)
                              (EXIT (CONS 1 "failed")))
                           ((BOOT::QEQCAR BOOT::|p2| 1)
                              (COND
                                 ((BOOT:SPADCALL
                                     (QCAR (QCDR BOOT::|p1|))
                                     (QCAR (QCDR BOOT::|p2|))
                                     (VMLISP:QREFELT |$| 50))
                                    (EXIT (CONS 1 "failed")))) ))
                        (COND
                           ((OR
                               (BOOT::QEQCAR BOOT::|p2| 0)
                               (BOOT:SPADCALL
                                  (QCAR (QCDR BOOT::|p2|))
                                  (QCAR (QCDR BOOT::|p1|))
                                  (VMLISP:QREFELT |$| 50)))
                              (EXIT
                                 (SEQ
                                    (BOOT::LETT
                                       |a|
                                       (BOOT:SPADCALL
                                          (QCDR (QCDR BOOT::|p1|))
                                          (BOOT:SPADCALL
                                             BOOT::|p2|
                                             (VMLISP:QREFELT |$| 93))
                                          (VMLISP:QREFELT |$| 120))
                                       BOOT::|SMP;exquo;2$U;40|)
                                    (EXIT
                                       (COND
                                          ((BOOT::QEQCAR |a| 1)
                                             (CONS 1 "failed"))
                                          ('T
                                             (CONS
                                                0
                                                (CONS
                                                   1
                                                   (CONS
        (QCAR (QCDR BOOT::|p1|))
        (QCDR |a|)))) ))) ))) )
                        (BOOT::LETT
                           |a|
                           (BOOT:SPADCALL
                              (QCDR (QCDR BOOT::|p1|))
                              (QCDR (QCDR BOOT::|p2|))
                              (VMLISP:QREFELT |$| 120))
                           BOOT::|SMP;exquo;2$U;40|)
                        (EXIT
                           (COND
                              ((BOOT::QEQCAR |a| 1) (CONS 1 "failed"))
                              ('T
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|mvar|
                                       (QCAR (QCDR BOOT::|p1|))
                                       BOOT::|SMP;exquo;2$U;40|)
                                    (BOOT::LETT
                                       BOOT::|up|
                                       (QCDR |a|)
                                       BOOT::|SMP;exquo;2$U;40|)
                                    (EXIT
                                       (COND
                                          ((BOOT:SPADCALL
                                              BOOT::|up|
                                              (VMLISP:QREFELT |$| 62))
                                             (CONS
                                                0
                                                (BOOT:SPADCALL
                                                   BOOT::|up|
                                                   (VMLISP:QREFELT
                                                      |$|
                                                      60))))
                                          ('T
                                             (CONS
                                                0
                                                (CONS
                                                   1
                                                   (CONS
                                                      BOOT::|mvar|
                                          BOOT::|up|)))) ))) ))) ))) ))) ))

*/



/* Code for BOOT::|SMP;exquo;2$U;40| */

static Lisp_Object MS_CDECL CC_BOOT__SMPUexquoU2DUU40(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V542, V543, V544, V545;
    argcheck(nargs, 3, "SMP;exquo;2$U;40");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;exquo;2$U;40|\n");
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
    V542 = stack[-4];
    V543 = qcar(V542);
    V542 = (Lisp_Object)1; /* 0 */
    V542 = Leql(nil, V543, V542);
    env = stack[-6];
    if (V542 == nil) goto V118;
    V542 = stack[-3];
    V543 = qcar(V542);
    V542 = (Lisp_Object)1; /* 0 */
    V542 = Leql(nil, V543, V542);
    env = stack[-6];
    if (V542 == nil) goto V118;
    V543 = stack[-2];
    V542 = (Lisp_Object)1905; /* 119 */
    V542 = Lgetv(nil, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V543 = V542;
    if (!car_legal(V543)) goto V553;
    V545 = qcar(V543);
    V543 = stack[-4];
    V544 = qcdr(V543);
    V543 = stack[-3];
    V543 = qcdr(V543);
    if (!car_legal(V542)) goto V554;
    V542 = qcdr(V542);
    V542 = Lapply3(nil, 4, V545, V544, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V544 = V542;
    V542 = V544;
    V543 = qcar(V542);
    V542 = (Lisp_Object)17; /* 1 */
    V542 = Leql(nil, V543, V542);
    env = stack[-6];
    if (V542 == nil) goto V75;
    V542 = (Lisp_Object)17; /* 1 */
    V543 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V542, V543);
    errexit();
    return onevalue(retVal); }

V75:
    V542 = lisp_true;
    if (V542 == nil) goto V94;
    V543 = (Lisp_Object)1; /* 0 */
    V542 = (Lisp_Object)1; /* 0 */
    V544 = qcdr(V544);
    popv(7);
    { Lisp_Object retVal = list2star(V543, V542, V544);
    errexit();
    return onevalue(retVal); }

V94:
    V542 = nil;
    { popv(7); return onevalue(V542); }

V118:
    V543 = stack[-2];
    V542 = (Lisp_Object)273; /* 17 */
    V542 = Lgetv(nil, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V543 = V542;
    if (!car_legal(V543)) goto V553;
    V544 = qcar(V543);
    V543 = stack[-4];
    if (!car_legal(V542)) goto V554;
    V542 = qcdr(V542);
    V542 = Lapply2(nil, 3, V544, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    if (!(V542 == nil)) goto V164;
    V543 = stack[-2];
    V542 = (Lisp_Object)305; /* 19 */
    V542 = Lgetv(nil, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V543 = V542;
    if (!car_legal(V543)) goto V553;
    V544 = qcar(V543);
    V543 = stack[-3];
    if (!car_legal(V542)) goto V554;
    V542 = qcdr(V542);
    V542 = Lapply2(nil, 3, V544, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    if (!(V542 == nil)) goto V164;
    V542 = lisp_true;
    if (V542 == nil) goto V172;
    V542 = stack[-4];
    V543 = qcar(V542);
    V542 = (Lisp_Object)1; /* 0 */
    V542 = Leql(nil, V543, V542);
    env = stack[-6];
    if (V542 == nil) goto V200;
    V542 = (Lisp_Object)17; /* 1 */
    V543 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V542, V543);
    errexit();
    return onevalue(retVal); }

V200:
    V542 = stack[-3];
    V543 = qcar(V542);
    V542 = (Lisp_Object)17; /* 1 */
    V542 = Leql(nil, V543, V542);
    env = stack[-6];
    if (V542 == nil) goto V257;
    V543 = stack[-2];
    V542 = (Lisp_Object)801; /* 50 */
    V542 = Lgetv(nil, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V543 = V542;
    if (!car_legal(V543)) goto V553;
    V545 = qcar(V543);
    V543 = stack[-4];
    V543 = qcdr(V543);
    V544 = qcar(V543);
    V543 = stack[-3];
    V543 = qcdr(V543);
    V543 = qcar(V543);
    if (!car_legal(V542)) goto V554;
    V542 = qcdr(V542);
    V542 = Lapply3(nil, 4, V545, V544, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    if (V542 == nil) goto V257;
    V542 = (Lisp_Object)17; /* 1 */
    V543 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V542, V543);
    errexit();
    return onevalue(retVal); }

V257:
    V542 = stack[-3];
    V543 = qcar(V542);
    V542 = (Lisp_Object)1; /* 0 */
    V542 = Leql(nil, V543, V542);
    env = stack[-6];
    if (!(V542 == nil)) goto V303;
    V543 = stack[-2];
    V542 = (Lisp_Object)801; /* 50 */
    V542 = Lgetv(nil, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V543 = V542;
    if (!car_legal(V543)) goto V553;
    V545 = qcar(V543);
    V543 = stack[-3];
    V543 = qcdr(V543);
    V544 = qcar(V543);
    V543 = stack[-4];
    V543 = qcdr(V543);
    V543 = qcar(V543);
    if (!car_legal(V542)) goto V554;
    V542 = qcdr(V542);
    V542 = Lapply3(nil, 4, V545, V544, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    if (!(V542 == nil)) goto V303;
    V543 = stack[-2];
    V542 = (Lisp_Object)1921; /* 120 */
    V542 = Lgetv(nil, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V543 = V542;
    if (!car_legal(V543)) goto V553;
    V545 = qcar(V543);
    V543 = stack[-4];
    V543 = qcdr(V543);
    V544 = qcdr(V543);
    V543 = stack[-3];
    V543 = qcdr(V543);
    V543 = qcdr(V543);
    if (!car_legal(V542)) goto V554;
    V542 = qcdr(V542);
    V542 = Lapply3(nil, 4, V545, V544, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V544 = V542;
    V542 = V544;
    V543 = qcar(V542);
    V542 = (Lisp_Object)17; /* 1 */
    V542 = Leql(nil, V543, V542);
    env = stack[-6];
    if (V542 == nil) goto V431;
    V542 = (Lisp_Object)17; /* 1 */
    V543 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V542, V543);
    errexit();
    return onevalue(retVal); }

V431:
    V542 = lisp_true;
    if (V542 == nil) goto V450;
    V542 = stack[-4];
    V542 = qcdr(V542);
    V542 = qcar(V542);
    stack[-3] = V542;
    V542 = V544;
    V542 = qcdr(V542);
    stack[-1] = V542;
    V543 = stack[-2];
    V542 = (Lisp_Object)993; /* 62 */
    V542 = Lgetv(nil, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V543 = V542;
    if (!car_legal(V543)) goto V553;
    V544 = qcar(V543);
    V543 = stack[-1];
    if (!car_legal(V542)) goto V554;
    V542 = qcdr(V542);
    V542 = Lapply2(nil, 3, V544, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    if (V542 == nil) goto V462;
    stack[0] = (Lisp_Object)1; /* 0 */
    V543 = stack[-2];
    V542 = (Lisp_Object)961; /* 60 */
    V542 = Lgetv(nil, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V543 = V542;
    if (!car_legal(V543)) goto V553;
    V544 = qcar(V543);
    V543 = stack[-1];
    if (!car_legal(V542)) goto V554;
    V542 = qcdr(V542);
    V542 = Lapply2(nil, 3, V544, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    {
        Lisp_Object V555 = stack[0];
        popv(7);
        { Lisp_Object retVal = cons(V555, V542);
        errexit();
        return onevalue(retVal); }
    }

V462:
    V542 = lisp_true;
    if (V542 == nil) goto V519;
    stack[-2] = (Lisp_Object)1; /* 0 */
    stack[0] = (Lisp_Object)17; /* 1 */
    V543 = stack[-3];
    V542 = stack[-1];
    V542 = cons(V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    {
        Lisp_Object V556 = stack[-2];
        Lisp_Object V557 = stack[0];
        popv(7);
        { Lisp_Object retVal = list2star(V556, V557, V542);
        errexit();
        return onevalue(retVal); }
    }

V519:
    V542 = nil;
    { popv(7); return onevalue(V542); }

V450:
    V542 = nil;
    { popv(7); return onevalue(V542); }

V303:
    V543 = stack[-2];
    V542 = (Lisp_Object)1921; /* 120 */
    V542 = Lgetv(nil, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    stack[-5] = V542;
    V542 = stack[-5];
    if (!car_legal(V542)) goto V558;
    stack[-1] = qcar(V542);
    V542 = stack[-4];
    V542 = qcdr(V542);
    stack[0] = qcdr(V542);
    V543 = stack[-2];
    V542 = (Lisp_Object)1489; /* 93 */
    V542 = Lgetv(nil, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V543 = V542;
    if (!car_legal(V543)) goto V553;
    V544 = qcar(V543);
    V543 = stack[-3];
    if (!car_legal(V542)) goto V554;
    V542 = qcdr(V542);
    V542 = Lapply2(nil, 3, V544, V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V543 = V542;
    V542 = stack[-5];
    if (!car_legal(V542)) goto V554;
    V542 = qcdr(V542);
    V542 = Lapply3(nil, 4, stack[-1], stack[0], V543, V542);
    nil = C_nil;
    if (exception_pending()) goto V552;
    env = stack[-6];
    V544 = V542;
    V542 = V544;
    V543 = qcar(V542);
    V542 = (Lisp_Object)17; /* 1 */
    V542 = Leql(nil, V543, V542);
    env = stack[-6];
    if (V542 == nil) goto V354;
    V542 = (Lisp_Object)17; /* 1 */
    V543 = elt(env, 1); /* "failed" */
    popv(7);
    { Lisp_Object retVal = cons(V542, V543);
    errexit();
    return onevalue(retVal); }

V354:
    V542 = lisp_true;
    if (V542 == nil) goto V373;
    stack[-1] = (Lisp_Object)1; /* 0 */
    stack[0] = (Lisp_Object)17; /* 1 */
    V542 = stack[-4];
    V542 = qcdr(V542);
    V542 = qcar(V542);
    V543 = V544;
    V543 = qcdr(V543);
    V542 = cons(V542, V543);
    nil = C_nil;
    if (exception_pending()) goto V552;
    {
        Lisp_Object V559 = stack[-1];
        Lisp_Object V560 = stack[0];
        popv(7);
        { Lisp_Object retVal = list2star(V559, V560, V542);
        errexit();
        return onevalue(retVal); }
    }

V373:
    V542 = nil;
    { popv(7); return onevalue(V542); }

V172:
    V542 = nil;
    { popv(7); return onevalue(V542); }

V164:
    V543 = (Lisp_Object)1; /* 0 */
    V542 = stack[-4];
    popv(7);
    { Lisp_Object retVal = cons(V543, V542);
    errexit();
    return onevalue(retVal); }
/* error exit handlers */
V558:
    popv(7);
    return error(1, err_bad_car, V542);
V554:
    popv(7);
    return error(1, err_bad_cdr, V542);
V553:
    popv(7);
    return error(1, err_bad_car, V543);
V552:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|KERNEL;argument;$L;6| (|k| |$|) (VMLISP:QVELT |k| 1))

*/



/* Code for BOOT::|KERNEL;argument;$L;6| */

static Lisp_Object CC_BOOT__KERNELUargumentUDLU6(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|KERNEL;argument;$L;6|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V15 = V3;
    V16 = V2;
/* end of prologue */
    V15 = (Lisp_Object)17; /* 1 */
        return Lgetv(nil, V16, V15);
}

/*
(DEFUN BOOT::|isNewWorldDomain| (BOOT::|domain|)
   (INTEGERP (ELT BOOT::|domain| 3)))

*/



/* Code for BOOT::|isNewWorldDomain| */

static Lisp_Object CC_BOOT__isNewWorldDomain(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isNewWorldDomain|\n");
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
    V15 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 1); /* ELT */
    V15 = (*qfn2(fn))(qenv(fn), V16, V15);
    errexit();
        return Lintegerp(nil, V15);
}

/*
(DEFUN BOOT::|computeElapsedTime| NIL
   (PROG (BOOT::|currentTime|
         BOOT::|currentGCTime|
         BOOT::|gcDelta|
         BOOT::|elapsedSeconds|)
      (RETURN
         (PROGN
            (BOOT:SPADLET BOOT::|currentTime| (BOOT::|elapsedUserTime|))
            (BOOT:SPADLET BOOT::|currentGCTime| (BOOT::|elapsedGcTime|))
            (BOOT:SPADLET
               BOOT::|gcDelta|
               (BOOT:SPADDIFFERENCE
                  BOOT::|currentGCTime|
                  BOOT::|$oldElapsedGCTime|))
            (BOOT:SPADLET
               BOOT::|elapsedSeconds|
               (COND
                  (BOOT::|$cclSystem|
                     (QUOTIENT
                        (TIMES
                           1.0
                           (BOOT:SPADDIFFERENCE
                              BOOT::|currentTime|
                              BOOT::|$oldElapsedTime|))
                        BOOT:|$timerTicksPerSecond|))
                  ('T
                     (QUOTIENT
                        (TIMES
                           1.0
                           (BOOT:SPADDIFFERENCE
                              (BOOT:SPADDIFFERENCE
                                 BOOT::|currentTime|
                                 BOOT::|$oldElapsedTime|)
                              BOOT::|gcDelta|))
                        BOOT:|$timerTicksPerSecond|))))
            (PUT
               'BOOT::|gc|
               'BOOT::|TimeTotal|
               (PLUS
                  (VMLISP:GETL 'BOOT::|gc| 'BOOT::|TimeTotal|)
                  (QUOTIENT
                     (TIMES 1.0 BOOT::|gcDelta|)
                     BOOT:|$timerTicksPerSecond|)))
            (BOOT:SPADLET
               BOOT::|$oldElapsedTime|
               (BOOT::|elapsedUserTime|))
            (BOOT:SPADLET
               BOOT::|$oldElapsedGCTime|
               (BOOT::|elapsedGcTime|))
            BOOT::|elapsedSeconds|))))

*/



/* Code for BOOT::|computeElapsedTime| */

static Lisp_Object MS_CDECL CC_BOOT__computeElapsedTime(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V122, V123;
    Lisp_Object fn;
    argcheck(nargs, 0, "computeElapsedTime");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|computeElapsedTime|\n");
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* end of prologue */
    fn = elt(env, 8); /* GET-INTERNAL-RUN-TIME */
    V122 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    stack[-1] = V122;
    V122 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    V123 = V122;
    V122 = qvalue(elt(env, 1)); /* BOOT::|$oldElapsedGCTime| */
    V122 = difference2(V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    stack[-4] = V122;
    V122 = qvalue(elt(env, 2)); /* BOOT::|$cclSystem| */
    if (V122 == nil) goto V24;
    stack[0] = elt(env, 3); /* 1.0 */
    V123 = stack[-1];
    V122 = qvalue(elt(env, 4)); /* BOOT::|$oldElapsedTime| */
    V122 = difference2(V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    V123 = times2(stack[0], V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    V122 = qvalue(elt(env, 5)); /* BOOT::|$timerTicksPerSecond| */
    V122 = quot2(V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    goto V22;

V22:
    stack[-3] = V122;
    stack[-2] = elt(env, 6); /* BOOT::|gc| */
    stack[-1] = elt(env, 7); /* BOOT::|TimeTotal| */
    V123 = elt(env, 6); /* BOOT::|gc| */
    V122 = elt(env, 7); /* BOOT::|TimeTotal| */
    fn = elt(env, 9); /* VMLISP:GETL */
    stack[0] = (*qfn2(fn))(qenv(fn), V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    V123 = elt(env, 3); /* 1.0 */
    V122 = stack[-4];
    V123 = times2(V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    V122 = qvalue(elt(env, 5)); /* BOOT::|$timerTicksPerSecond| */
    V122 = quot2(V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    V122 = plus2(stack[0], V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    V122 = Lputprop(nil, 3, stack[-2], stack[-1], V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    fn = elt(env, 8); /* GET-INTERNAL-RUN-TIME */
    V122 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    qvalue(elt(env, 4)) = V122; /* BOOT::|$oldElapsedTime| */
    V122 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    qvalue(elt(env, 1)) = V122; /* BOOT::|$oldElapsedGCTime| */
    { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }

V24:
    V122 = lisp_true;
    if (V122 == nil) goto V49;
    stack[0] = elt(env, 3); /* 1.0 */
    V123 = stack[-1];
    V122 = qvalue(elt(env, 4)); /* BOOT::|$oldElapsedTime| */
    V123 = difference2(V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    V122 = stack[-4];
    V122 = difference2(V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    V123 = times2(stack[0], V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    V122 = qvalue(elt(env, 5)); /* BOOT::|$timerTicksPerSecond| */
    V122 = quot2(V123, V122);
    nil = C_nil;
    if (exception_pending()) goto V129;
    env = stack[-5];
    goto V22;

V49:
    V122 = nil;
    goto V22;
/* error exit handlers */
V129:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|IIARRAY2;minColIndex;$I;5| (|m| |$|) (VMLISP:QREFELT |$| 8))

*/



/* Code for BOOT::|IIARRAY2;minColIndex;$I;5| */

static Lisp_Object CC_BOOT__IIARRAY2UminColIndexUDIU5(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IIARRAY2;minColIndex;$I;5|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V15 = V3;
    V16 = V2;
/* end of prologue */
    V16 = V15;
    V15 = (Lisp_Object)129; /* 8 */
        return Lgetv(nil, V16, V15);
}

/*
(DEFUN BOOT::|IIARRAY2;minRowIndex;$I;4| (|m| |$|) (VMLISP:QREFELT |$| 7))

*/



/* Code for BOOT::|IIARRAY2;minRowIndex;$I;4| */

static Lisp_Object CC_BOOT__IIARRAY2UminRowIndexUDIU4(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V15, V16;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IIARRAY2;minRowIndex;$I;4|\n");
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
(DEFUN BOOT::|FRAC;=;2$B;27| (|x| |y| |$|)
   (COND
      ((BOOT:SPADCALL (QCAR |x|) (QCAR |y|) (VMLISP:QREFELT |$| 64))
         (BOOT:SPADCALL (QCDR |x|) (QCDR |y|) (VMLISP:QREFELT |$| 64)))
      ('T 'NIL)))

*/



/* Code for BOOT::|FRAC;=;2$B;27| */

static Lisp_Object MS_CDECL CC_BOOT__FRACUMU2DBU27(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V74, V75, V76, V77;
    argcheck(nargs, 3, "FRAC;=;2$B;27");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FRAC;=;2$B;27|\n");
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
    V75 = stack[0];
    V74 = (Lisp_Object)1025; /* 64 */
    V74 = Lgetv(nil, V75, V74);
    nil = C_nil;
    if (exception_pending()) goto V81;
    env = stack[-3];
    V75 = V74;
    if (!car_legal(V75)) goto V82;
    V77 = qcar(V75);
    V75 = stack[-2];
    V76 = qcar(V75);
    V75 = stack[-1];
    V75 = qcar(V75);
    if (!car_legal(V74)) goto V83;
    V74 = qcdr(V74);
    V74 = Lapply3(nil, 4, V77, V76, V75, V74);
    nil = C_nil;
    if (exception_pending()) goto V81;
    env = stack[-3];
    if (V74 == nil) goto V11;
    V75 = stack[0];
    V74 = (Lisp_Object)1025; /* 64 */
    V74 = Lgetv(nil, V75, V74);
    nil = C_nil;
    if (exception_pending()) goto V81;
    V75 = V74;
    if (!car_legal(V75)) goto V82;
    V77 = qcar(V75);
    V75 = stack[-2];
    V76 = qcdr(V75);
    V75 = stack[-1];
    V75 = qcdr(V75);
    if (!car_legal(V74)) goto V83;
    V74 = qcdr(V74);
        popv(4);
        return Lapply3(nil, 4, V77, V76, V75, V74);

V11:
    V74 = lisp_true;
    if (V74 == nil) goto V71;
    V74 = nil;
    { popv(4); return onevalue(V74); }

V71:
    V74 = nil;
    { popv(4); return onevalue(V74); }
/* error exit handlers */
V83:
    popv(4);
    return error(1, err_bad_cdr, V74);
V82:
    popv(4);
    return error(1, err_bad_car, V75);
V81:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|BOP;=;2$B;27| (BOOT::|op1| BOOT::|op2| |$|)
   (PROG (BOOT::|func|)
      (RETURN
         (SEQ
            (COND
               ((NULL
                   (EQUAL
                      (BOOT:SPADCALL BOOT::|op1| (VMLISP:QREFELT |$| 8))
                      (BOOT:SPADCALL BOOT::|op2| (VMLISP:QREFELT |$| 8))))
                  'NIL)
               ((NULL
                   (EQL
                      (VMLISP:QVELT BOOT::|op1| 1)
                      (VMLISP:QVELT BOOT::|op2| 1)))
                  'NIL)
               ((NULL
                   (BOOT:SPADCALL
                      (BOOT:SPADCALL
                         (BOOT:SPADCALL
                            (BOOT:SPADCALL
                               BOOT::|op1|
                               (VMLISP:QREFELT |$| 12))
                            (VMLISP:QREFELT |$| 63))
                         (VMLISP:QREFELT |$| 65))
                      (BOOT:SPADCALL
                         (BOOT:SPADCALL
                            (BOOT:SPADCALL
                               BOOT::|op2|
                               (VMLISP:QREFELT |$| 12))
                            (VMLISP:QREFELT |$| 63))
                         (VMLISP:QREFELT |$| 65))
                      (VMLISP:QREFELT |$| 66)))
                  'NIL)
               ('T
                  (SEQ
                     (BOOT::LETT
                        BOOT::|func|
                        (BOOT:SPADCALL
                           BOOT::|op1|
                           "%equal?"
                           (VMLISP:QREFELT |$| 24))
                        BOOT::|BOP;=;2$B;27|)
                     (EXIT
                        (COND
                           ((BOOT::QEQCAR BOOT::|func| 0)
                              (BOOT:SPADCALL
                                 BOOT::|op1|
                                 BOOT::|op2|
                                 (QCDR BOOT::|func|)))
                           ('T 'T)))) ))) )))

*/



/* Code for BOOT::|BOP;=;2$B;27| */

static Lisp_Object MS_CDECL CC_BOOT__BOPUMU2DBU27(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V336, V337, V338, V339;
    argcheck(nargs, 3, "BOP;=;2$B;27");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|BOP;=;2$B;27|\n");
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
    V337 = stack[-6];
    V336 = (Lisp_Object)129; /* 8 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = V336;
    if (!car_legal(V337)) goto V351;
    V338 = qcar(V337);
    V337 = stack[-8];
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
    V336 = Lapply2(nil, 3, V338, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    stack[0] = V336;
    V337 = stack[-6];
    V336 = (Lisp_Object)129; /* 8 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = V336;
    if (!car_legal(V337)) goto V351;
    V338 = qcar(V337);
    V337 = stack[-7];
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
    V336 = Lapply2(nil, 3, V338, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    if (cl_equal(stack[0], V336)) goto V80;
    V336 = nil;
    { popv(11); return onevalue(V336); }

V80:
    V337 = stack[-8];
    V336 = (Lisp_Object)17; /* 1 */
    stack[0] = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = stack[-7];
    V336 = (Lisp_Object)17; /* 1 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V336 = Leql(nil, stack[0], V336);
    env = stack[-10];
    if (V336 == nil) goto V71;
    V337 = stack[-6];
    V336 = (Lisp_Object)1057; /* 66 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    stack[-9] = V336;
    V336 = stack[-9];
    if (!car_legal(V336)) goto V353;
    stack[-5] = qcar(V336);
    V337 = stack[-6];
    V336 = (Lisp_Object)1041; /* 65 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    stack[-3] = V336;
    V336 = stack[-3];
    if (!car_legal(V336)) goto V353;
    stack[-2] = qcar(V336);
    V337 = stack[-6];
    V336 = (Lisp_Object)1009; /* 63 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    stack[-1] = V336;
    V336 = stack[-1];
    if (!car_legal(V336)) goto V353;
    stack[0] = qcar(V336);
    V337 = stack[-6];
    V336 = (Lisp_Object)193; /* 12 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = V336;
    if (!car_legal(V337)) goto V351;
    V338 = qcar(V337);
    V337 = stack[-8];
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
    V336 = Lapply2(nil, 3, V338, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = V336;
    V336 = stack[-1];
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
    V336 = Lapply2(nil, 3, stack[0], V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = V336;
    V336 = stack[-3];
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
    V336 = Lapply2(nil, 3, stack[-2], V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    stack[-4] = V336;
    V337 = stack[-6];
    V336 = (Lisp_Object)1041; /* 65 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    stack[-3] = V336;
    V336 = stack[-3];
    if (!car_legal(V336)) goto V353;
    stack[-2] = qcar(V336);
    V337 = stack[-6];
    V336 = (Lisp_Object)1009; /* 63 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    stack[-1] = V336;
    V336 = stack[-1];
    if (!car_legal(V336)) goto V353;
    stack[0] = qcar(V336);
    V337 = stack[-6];
    V336 = (Lisp_Object)193; /* 12 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = V336;
    if (!car_legal(V337)) goto V351;
    V338 = qcar(V337);
    V337 = stack[-7];
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
    V336 = Lapply2(nil, 3, V338, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = V336;
    V336 = stack[-1];
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
    V336 = Lapply2(nil, 3, stack[0], V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = V336;
    V336 = stack[-3];
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
    V336 = Lapply2(nil, 3, stack[-2], V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = V336;
    V336 = stack[-9];
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
    V336 = Lapply3(nil, 4, stack[-5], stack[-4], V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    if (V336 == nil) goto V96;
    V336 = lisp_true;
    if (V336 == nil) goto V265;
    V337 = stack[-6];
    V336 = (Lisp_Object)385; /* 24 */
    V336 = Lgetv(nil, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V337 = V336;
    if (!car_legal(V337)) goto V351;
    V339 = qcar(V337);
    V338 = stack[-8];
    V337 = elt(env, 1); /* "%equal?" */
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
    V336 = Lapply3(nil, 4, V339, V338, V337, V336);
    nil = C_nil;
    if (exception_pending()) goto V350;
    env = stack[-10];
    V338 = V336;
    V336 = V338;
    V337 = qcar(V336);
    V336 = (Lisp_Object)1; /* 0 */
    V336 = Leql(nil, V337, V336);
    if (V336 == nil) goto V299;
    V336 = V338;
    V336 = qcdr(V336);
    V337 = V336;
    if (!car_legal(V337)) goto V351;
    V339 = qcar(V337);
    V338 = stack[-8];
    V337 = stack[-7];
    if (!car_legal(V336)) goto V352;
    V336 = qcdr(V336);
        popv(11);
        return Lapply3(nil, 4, V339, V338, V337, V336);

V299:
    V336 = lisp_true;
    if (V336 == nil) goto V331;
    V336 = lisp_true;
    { popv(11); return onevalue(V336); }

V331:
    V336 = nil;
    { popv(11); return onevalue(V336); }

V265:
    V336 = nil;
    { popv(11); return onevalue(V336); }

V96:
    V336 = nil;
    { popv(11); return onevalue(V336); }

V71:
    V336 = nil;
    { popv(11); return onevalue(V336); }
/* error exit handlers */
V353:
    popv(11);
    return error(1, err_bad_car, V336);
V352:
    popv(11);
    return error(1, err_bad_cdr, V336);
V351:
    popv(11);
    return error(1, err_bad_car, V337);
V350:
    popv(11);
    return nil;
}

/*
(DEFUN BOOT::|SET;construct;L$;19| (|l| |$|)
   (PROG (|n| |a| |x| #:G82381 |i|)
      (RETURN
         (SEQ
            (COND
               ((ZEROP
                   (BOOT::LETT
                      |n|
                      (LENGTH |l|)
                      BOOT::|SET;construct;L$;19|))
                  (BOOT:SPADCALL (VMLISP:QREFELT |$| 11)))
               ('T
                  (SEQ
                     (BOOT::LETT
                        |a|
                        (BOOT:SPADCALL
                           |n|
                           (BOOT::|SPADfirst| |l|)
                           (VMLISP:QREFELT |$| 58))
                        BOOT::|SET;construct;L$;19|)
                     (SEQ
                        (BOOT::LETT |x| NIL BOOT::|SET;construct;L$;19|)
                        (BOOT::LETT
                           #:G82381
                           |l|
                           BOOT::|SET;construct;L$;19|)
                        (BOOT::LETT
                           |i|
                           (BOOT:SPADCALL |a| (VMLISP:QREFELT |$| 56))
                           BOOT::|SET;construct;L$;19|)
                        BOOT::G190
                        (COND
                           ((OR
                               (ATOM #:G82381)
                               (PROGN
                                  (BOOT::LETT
                                     |x|
                                     (CAR #:G82381)
                                     BOOT::|SET;construct;L$;19|)
                                  NIL))
                              (GO BOOT::G191)))
                        (SEQ
                           (EXIT
                              (BOOT:SPADCALL
                                 |a|
                                 |i|
                                 |x|
                                 (VMLISP:QREFELT |$| 59))))
                        (BOOT::LETT
                           |i|
                           (PROG1
                              (|+| |i| 1)
                              (BOOT::LETT
                                 #:G82381
                                 (CDR #:G82381)
                                 BOOT::|SET;construct;L$;19|))
                           BOOT::|SET;construct;L$;19|)
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT NIL))
                     (EXIT
                        (BOOT:SPADCALL
                           (BOOT:SPADCALL |a| (VMLISP:QREFELT |$| 60))
                           (VMLISP:QREFELT |$| 36)))) ))) )))

*/



/* Code for BOOT::|SET;construct;L$;19| */

static Lisp_Object CC_BOOT__SETUconstructULDU19(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V220, V221, V222, V223, V224;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SET;construct;L$;19|\n");
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
    V220 = stack[-3];
    V220 = Llength(nil, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    stack[0] = V220;
    V220 = (Lisp_Object)zerop(V220);
    V220 = V220 ? lisp_true : nil;
    env = stack[-5];
    if (V220 == nil) goto V19;
    V221 = stack[-2];
    V220 = (Lisp_Object)177; /* 11 */
    V220 = Lgetv(nil, V221, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    V221 = V220;
    if (!car_legal(V221)) goto V231;
    V221 = qcar(V221);
    if (!car_legal(V220)) goto V232;
    V220 = qcdr(V220);
        popv(6);
        return Lapply1(nil, V221, V220);

V19:
    V220 = lisp_true;
    if (V220 == nil) goto V45;
    V221 = stack[-2];
    V220 = (Lisp_Object)929; /* 58 */
    V220 = Lgetv(nil, V221, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    stack[-4] = V220;
    V220 = stack[-4];
    if (!car_legal(V220)) goto V233;
    stack[-1] = qcar(V220);
    V220 = stack[-3];
    V221 = V220;
    V220 = V221;
    if (V220 == nil) goto V80;
    V220 = V221;
    if (!car_legal(V220)) goto V233;
    V220 = qcar(V220);
    goto V78;

V78:
    V221 = V220;
    V220 = stack[-4];
    if (!car_legal(V220)) goto V232;
    V220 = qcdr(V220);
    V220 = Lapply3(nil, 4, stack[-1], stack[0], V221, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    stack[-4] = V220;
    V220 = stack[-3];
    stack[-1] = V220;
    V221 = stack[-2];
    V220 = (Lisp_Object)897; /* 56 */
    V220 = Lgetv(nil, V221, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    V221 = V220;
    if (!car_legal(V221)) goto V231;
    V222 = qcar(V221);
    V221 = stack[-4];
    if (!car_legal(V220)) goto V232;
    V220 = qcdr(V220);
    V220 = Lapply2(nil, 3, V222, V221, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    stack[0] = V220;
    goto V89;

V89:
    V220 = stack[-1];
    if (!consp(V220)) goto V175;
    V220 = stack[-1];
    if (!car_legal(V220)) goto V233;
    V220 = qcar(V220);
    stack[-3] = V220;
    V220 = nil;
    if (!(V220 == nil)) goto V175;
    V221 = stack[-2];
    V220 = (Lisp_Object)945; /* 59 */
    V220 = Lgetv(nil, V221, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    V221 = V220;
    if (!car_legal(V221)) goto V231;
    V224 = qcar(V221);
    V223 = stack[-4];
    V222 = stack[0];
    V221 = stack[-3];
    if (!car_legal(V220)) goto V232;
    V220 = qcdr(V220);
    fn = elt(env, 1); /* FUNCALL* */
    V220 = (*qfnn(fn))(qenv(fn), 5, V224, V223, V222, V221, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    V220 = stack[0];
    V220 = add1(V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    V221 = V220;
    V220 = stack[-1];
    if (!car_legal(V220)) goto V232;
    V220 = qcdr(V220);
    stack[-1] = V220;
    V220 = V221;
    stack[0] = V220;
    goto V89;

V175:
    V221 = stack[-2];
    V220 = (Lisp_Object)577; /* 36 */
    V220 = Lgetv(nil, V221, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    stack[-1] = V220;
    V220 = stack[-1];
    if (!car_legal(V220)) goto V233;
    stack[0] = qcar(V220);
    V221 = stack[-2];
    V220 = (Lisp_Object)961; /* 60 */
    V220 = Lgetv(nil, V221, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    V221 = V220;
    if (!car_legal(V221)) goto V231;
    V222 = qcar(V221);
    V221 = stack[-4];
    if (!car_legal(V220)) goto V232;
    V220 = qcdr(V220);
    V220 = Lapply2(nil, 3, V222, V221, V220);
    nil = C_nil;
    if (exception_pending()) goto V230;
    V221 = V220;
    V220 = stack[-1];
    if (!car_legal(V220)) goto V232;
    V220 = qcdr(V220);
    {
        Lisp_Object V234 = stack[0];
        popv(6);
        return Lapply2(nil, 3, V234, V221, V220);
    }

V80:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V220 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V230;
    env = stack[-5];
    goto V78;

V45:
    V220 = nil;
    { popv(6); return onevalue(V220); }
/* error exit handlers */
V233:
    popv(6);
    return error(1, err_bad_car, V220);
V232:
    popv(6);
    return error(1, err_bad_cdr, V220);
V231:
    popv(6);
    return error(1, err_bad_car, V221);
V230:
    popv(6);
    return nil;
}



setup_type const u06_setup[] =
{
    {"BOOT@@IDPAM;+;3$;4@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__IDPAMULU3DU4},
    {"BOOT@@FRAC;normalize@@Builtin",too_few_2, CC_BOOT__FRACUnormalize,wrong_no_2},
    {"BOOT@@COMPLEX;coerce;R$;10@@Builtin",too_few_2,CC_BOOT__COMPLEXUcoerceURDU10,wrong_no_2},
    {"BOOT@@BOP;has?;$SB;9@@Builtin",wrong_no_na,wrong_no_nb,  (n_args *)CC_BOOT__BOPUhasWUDSBU9},
    {"BOOT@@tokPart@@Builtin",  CC_BOOT__tokPart,too_many_1,   wrong_no_1},
    {"BOOT@@newCompareSig@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__newCompareSig},
    {"BOOT@@lazyMatchArg2@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__lazyMatchArg2},
    {"BOOT@@KDAGG-;key?;KeySB;1@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__KDAGGKUkeyWUKeySBU1},
    {"BOOT@@EXPR;=;2$B;21@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__EXPRUMU2DBU21},
    {"BOOT@@COMPCAT-;recip;SU;48@@Builtin",too_few_2,CC_BOOT__COMPCATKUrecipUSUU48,wrong_no_2},
    {"BOOT@@SMP;mainVariable;$U;63@@Builtin",too_few_2,CC_BOOT__SMPUmainVariableUDUU63,wrong_no_2},
    {"BOOT@@SCACHE;enterInCache;SMS;5@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__SCACHEUenterInCacheUSMSU5},
    {"BOOT@@SMP;coerce;R$;21@@Builtin",too_few_2,CC_BOOT__SMPUcoerceURDU21,wrong_no_2},
    {"BOOT@@COMPLEX;exquo;2$U;16@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__COMPLEXUexquoU2DUU16},
    {"BOOT@@get@@Builtin",      wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__get},
    {"BOOT@@SMP;exquo;2$U;39@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__SMPUexquoU2DUU39},
    {"BOOT@@SMP;exquo;2$U;40@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__SMPUexquoU2DUU40},
    {"BOOT@@KERNEL;argument;$L;6@@Builtin",too_few_2,CC_BOOT__KERNELUargumentUDLU6,wrong_no_2},
    {"BOOT@@isNewWorldDomain@@Builtin",CC_BOOT__isNewWorldDomain,too_many_1,wrong_no_1},
    {"BOOT@@computeElapsedTime@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__computeElapsedTime},
    {"BOOT@@IIARRAY2;minColIndex;$I;5@@Builtin",too_few_2,CC_BOOT__IIARRAY2UminColIndexUDIU5,wrong_no_2},
    {"BOOT@@IIARRAY2;minRowIndex;$I;4@@Builtin",too_few_2,CC_BOOT__IIARRAY2UminRowIndexUDIU4,wrong_no_2},
    {"BOOT@@FRAC;=;2$B;27@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__FRACUMU2DBU27},
    {"BOOT@@BOP;=;2$B;27@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__BOPUMU2DBU27},
    {"BOOT@@SET;construct;L$;19@@Builtin",too_few_2,CC_BOOT__SETUconstructULDU19,wrong_no_2},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
