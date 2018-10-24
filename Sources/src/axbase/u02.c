
/* u02.c                 Machine generated C code */

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
(DEFUN BOOT::|ARR2CAT-;copy;2S;10| (|m| |$|)
   (PROG (BOOT::|ans| |i| #:G82407 |j| #:G82408)
      (RETURN
         (SEQ
            (BOOT::LETT
               BOOT::|ans|
               (BOOT:SPADCALL
                  (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 21))
                  (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 22))
                  NIL
                  (VMLISP:QREFELT |$| 31))
               BOOT::|ARR2CAT-;copy;2S;10|)
            (SEQ
               (BOOT::LETT
                  |i|
                  (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 11))
                  BOOT::|ARR2CAT-;copy;2S;10|)
               (BOOT::LETT
                  #:G82407
                  (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 12))
                  BOOT::|ARR2CAT-;copy;2S;10|)
               BOOT::G190
               (COND ((|>| |i| #:G82407) (GO BOOT::G191)))
               (SEQ
                  (EXIT
                     (SEQ
                        (BOOT::LETT
                           |j|
                           (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 13))
                           BOOT::|ARR2CAT-;copy;2S;10|)
                        (BOOT::LETT
                           #:G82408
                           (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 14))
                           BOOT::|ARR2CAT-;copy;2S;10|)
                        BOOT::G190
                        (COND ((|>| |j| #:G82408) (GO BOOT::G191)))
                        (SEQ
                           (EXIT
                              (BOOT:SPADCALL
                                 BOOT::|ans|
                                 |i|
                                 |j|
                                 (BOOT:SPADCALL
                                    |m|
                                    |i|
                                    |j|
                                    (VMLISP:QREFELT |$| 15))
                                 (VMLISP:QREFELT |$| 32))))
                        (BOOT::LETT
                           |j|
                           (|+| |j| 1)
                           BOOT::|ARR2CAT-;copy;2S;10|)
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT NIL))))
               (BOOT::LETT |i| (|+| |i| 1) BOOT::|ARR2CAT-;copy;2S;10|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT BOOT::|ans|)))) )

*/



/* Code for BOOT::|ARR2CAT-;copy;2S;10| */

static Lisp_Object CC_BOOT__ARR2CATKUcopyU2SU10(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V298, V299, V300, V301, V302;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ARR2CAT-;copy;2S;10|\n");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-9] = V3;
    stack[-10] = V2;
/* end of prologue */
    V299 = stack[-9];
    V298 = (Lisp_Object)497; /* 31 */
    V298 = Lgetv(nil, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    stack[-2] = V298;
    V298 = stack[-2];
    if (!car_legal(V298)) goto V316;
    stack[-1] = qcar(V298);
    V299 = stack[-9];
    V298 = (Lisp_Object)337; /* 21 */
    V298 = Lgetv(nil, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    V299 = V298;
    if (!car_legal(V299)) goto V317;
    V300 = qcar(V299);
    V299 = stack[-10];
    if (!car_legal(V298)) goto V318;
    V298 = qcdr(V298);
    V298 = Lapply2(nil, 3, V300, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    stack[0] = V298;
    V299 = stack[-9];
    V298 = (Lisp_Object)353; /* 22 */
    V298 = Lgetv(nil, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    V299 = V298;
    if (!car_legal(V299)) goto V317;
    V300 = qcar(V299);
    V299 = stack[-10];
    if (!car_legal(V298)) goto V318;
    V298 = qcdr(V298);
    V298 = Lapply2(nil, 3, V300, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    V300 = V298;
    V299 = nil;
    V298 = stack[-2];
    if (!car_legal(V298)) goto V318;
    V298 = qcdr(V298);
    fn = elt(env, 1); /* FUNCALL* */
    V298 = (*qfnn(fn))(qenv(fn), 5, stack[-1], stack[0], V300, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    stack[-11] = V298;
    V299 = stack[-9];
    V298 = (Lisp_Object)177; /* 11 */
    V298 = Lgetv(nil, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    V299 = V298;
    if (!car_legal(V299)) goto V317;
    V300 = qcar(V299);
    V299 = stack[-10];
    if (!car_legal(V298)) goto V318;
    V298 = qcdr(V298);
    V298 = Lapply2(nil, 3, V300, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    stack[-8] = V298;
    V299 = stack[-9];
    V298 = (Lisp_Object)193; /* 12 */
    V298 = Lgetv(nil, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    V299 = V298;
    if (!car_legal(V299)) goto V317;
    V300 = qcar(V299);
    V299 = stack[-10];
    if (!car_legal(V298)) goto V318;
    V298 = qcdr(V298);
    V298 = Lapply2(nil, 3, V300, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    stack[-7] = V298;
    goto V149;

V149:
    V299 = stack[-8];
    V298 = stack[-7];
    V298 = (Lisp_Object)greaterp2(V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    V298 = V298 ? lisp_true : nil;
    env = stack[-12];
    if (!(V298 == nil)) { Lisp_Object res = stack[-11]; popv(13); return onevalue(res); }
    V299 = stack[-9];
    V298 = (Lisp_Object)209; /* 13 */
    V298 = Lgetv(nil, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    V299 = V298;
    if (!car_legal(V299)) goto V317;
    V300 = qcar(V299);
    V299 = stack[-10];
    if (!car_legal(V298)) goto V318;
    V298 = qcdr(V298);
    V298 = Lapply2(nil, 3, V300, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    stack[-6] = V298;
    V299 = stack[-9];
    V298 = (Lisp_Object)225; /* 14 */
    V298 = Lgetv(nil, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    V299 = V298;
    if (!car_legal(V299)) goto V317;
    V300 = qcar(V299);
    V299 = stack[-10];
    if (!car_legal(V298)) goto V318;
    V298 = qcdr(V298);
    V298 = Lapply2(nil, 3, V300, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    stack[-5] = V298;
    goto V215;

V215:
    V299 = stack[-6];
    V298 = stack[-5];
    V298 = (Lisp_Object)greaterp2(V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    V298 = V298 ? lisp_true : nil;
    env = stack[-12];
    if (V298 == nil) goto V228;
    V298 = stack[-8];
    V298 = add1(V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    stack[-8] = V298;
    goto V149;

V228:
    V299 = stack[-9];
    V298 = (Lisp_Object)513; /* 32 */
    V298 = Lgetv(nil, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    stack[-4] = V298;
    V298 = stack[-4];
    if (!car_legal(V298)) goto V316;
    stack[-3] = qcar(V298);
    stack[-2] = stack[-11];
    stack[-1] = stack[-8];
    stack[0] = stack[-6];
    V299 = stack[-9];
    V298 = (Lisp_Object)241; /* 15 */
    V298 = Lgetv(nil, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    V299 = V298;
    if (!car_legal(V299)) goto V317;
    V302 = qcar(V299);
    V301 = stack[-10];
    V300 = stack[-8];
    V299 = stack[-6];
    if (!car_legal(V298)) goto V318;
    V298 = qcdr(V298);
    fn = elt(env, 1); /* FUNCALL* */
    V298 = (*qfnn(fn))(qenv(fn), 5, V302, V301, V300, V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    V299 = V298;
    V298 = stack[-4];
    if (!car_legal(V298)) goto V318;
    V298 = qcdr(V298);
    fn = elt(env, 1); /* FUNCALL* */
    V298 = (*qfnn(fn))(qenv(fn), 6, stack[-3], stack[-2], stack[-1], stack[0], V299, V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    V298 = stack[-6];
    V298 = add1(V298);
    nil = C_nil;
    if (exception_pending()) goto V315;
    env = stack[-12];
    stack[-6] = V298;
    goto V215;
/* error exit handlers */
V318:
    popv(13);
    return error(1, err_bad_cdr, V298);
V317:
    popv(13);
    return error(1, err_bad_car, V299);
V316:
    popv(13);
    return error(1, err_bad_car, V298);
V315:
    popv(13);
    return nil;
}

/*
(DEFUN BOOT::|IMATLIN;rowEchelon;2M;3| (|y| |$|)
   (PROG (|x| BOOT::|minR| BOOT::|maxR| BOOT::|minC| BOOT::|maxC| |j|
         #:G82363 |n| #:G82353 |b| |k| BOOT::|k1| |i|)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (BOOT::LETT
                     |x|
                     (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 19))
                     BOOT::|IMATLIN;rowEchelon;2M;3|)
                  (BOOT::LETT
                     BOOT::|minR|
                     (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 17))
                     BOOT::|IMATLIN;rowEchelon;2M;3|)
                  (BOOT::LETT
                     BOOT::|maxR|
                     (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 18))
                     BOOT::|IMATLIN;rowEchelon;2M;3|)
                  (BOOT::LETT
                     BOOT::|minC|
                     (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 11))
                     BOOT::|IMATLIN;rowEchelon;2M;3|)
                  (BOOT::LETT
                     BOOT::|maxC|
                     (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 12))
                     BOOT::|IMATLIN;rowEchelon;2M;3|)
                  (BOOT::LETT
                     |i|
                     BOOT::|minR|
                     BOOT::|IMATLIN;rowEchelon;2M;3|)
                  (BOOT::LETT
                     |n|
                     (|-| BOOT::|minR| 1)
                     BOOT::|IMATLIN;rowEchelon;2M;3|)
                  (SEQ
                     (BOOT::LETT
                        |j|
                        BOOT::|minC|
                        BOOT::|IMATLIN;rowEchelon;2M;3|)
                     BOOT::G190
                     (COND ((|>| |j| BOOT::|maxC|) (GO BOOT::G191)))
                     (SEQ
                        (EXIT
                           (COND
                              ((|<| BOOT::|maxR| |i|)
                                 (PROGN
                                    (BOOT::LETT
                                       #:G82363
                                       |x|
                                       BOOT::|IMATLIN;rowEchelon;2M;3|)
                                    (GO #:G82363)))
                              ('T
                                 (SEQ
                                    (BOOT::LETT
                                       |n|
                                       (|-| BOOT::|minR| 1)
                                       BOOT::|IMATLIN;rowEchelon;2M;3|)
                                    (SEQ
                                       (EXIT
                                          (SEQ
                                             (BOOT::LETT
                                                |k|
                                                |i|
                                          BOOT::|IMATLIN;rowEchelon;2M;3|)
                                             BOOT::G190
                                             (COND
                                                ((|>| |k| BOOT::|maxR|)
                                                   (GO BOOT::G191)))
                                             (SEQ
                                                (EXIT
                                                   (COND
        ((NULL
         (BOOT:SPADCALL
            (BOOT:SPADCALL |x| |k| |j| (VMLISP:QREFELT |$| 13))
            (BOOT::|spadConstant| |$| 14) (VMLISP:QREFELT |$| 16)))
        (PROGN
           (BOOT::LETT
              #:G82353
              (BOOT::LETT |n| |k| BOOT::|IMATLIN;rowEchelon;2M;3|)
              BOOT::|IMATLIN;rowEchelon;2M;3|)
           (GO #:G82353)))) ))
                                             (BOOT::LETT
                                                |k|
                                                (|+| |k| 1)
                                          BOOT::|IMATLIN;rowEchelon;2M;3|)
                                             (GO BOOT::G190)
                                             BOOT::G191
                                             (EXIT NIL)))
                                       #:G82353
                                       (EXIT #:G82353))
                                    (EXIT
                                       (COND
                                          ((EQL |n| (|-| BOOT::|minR| 1))
                                             "no non-zeroes")
                                          ('T
                                             (SEQ
                                                (COND
                                                   ((NULL
        (EQL |i| |n|))
        (BOOT:SPADCALL |x| |i| |n| (VMLISP:QREFELT |$| 21))))
                                                (BOOT::LETT
                                                   |b|
                                                   (BOOT:SPADCALL
        (BOOT:SPADCALL |x| |i| |j| (VMLISP:QREFELT |$| 13))
        (VMLISP:QREFELT |$| 22))
                                                   BOOT::|IMATLIN;rowEchelon;2M;3|)
                                                (BOOT:SPADCALL
                                                   |x|
                                                   |i|
                                                   |j|
                                                   (BOOT::|spadConstant|
                                                      |$|
                                                      20)
                                                   (VMLISP:QREFELT |$| 23))
                                                (SEQ
                                                   (BOOT::LETT
                                                      |k|
        (|+| |j| 1)
                                                      BOOT::|IMATLIN;rowEchelon;2M;3|)
                                                   BOOT::G190
                                                   (COND
        ((|>| |k| BOOT::|maxC|) (GO BOOT::G191)))
                                                   (SEQ
        (EXIT
        (BOOT:SPADCALL
           |x|
           |i|
           |k|
           (BOOT:SPADCALL
              |b|
              (BOOT:SPADCALL |x| |i| |k| (VMLISP:QREFELT |$| 13))
              (VMLISP:QREFELT |$| 24)) (VMLISP:QREFELT |$| 23))))
                                                   (BOOT::LETT
                                                      |k|
        (|+| |k| 1)
                                                      BOOT::|IMATLIN;rowEchelon;2M;3|)
                                                   (GO BOOT::G190)
                                                   BOOT::G191
                                                   (EXIT NIL))
                                                (SEQ
                                                   (BOOT::LETT
                                                      |k|
                                                      BOOT::|minR|
                                          BOOT::|IMATLIN;rowEchelon;2M;3|)
                                                   BOOT::G190
                                                   (COND
        ((|>| |k| BOOT::|maxR|) (GO BOOT::G191)))
                                                   (SEQ
        (EXIT
        (COND
           ((NULL (EQL |k| |i|))
              (COND
                 ((NULL
                     (BOOT:SPADCALL
                        (BOOT:SPADCALL |x| |k| |j| (VMLISP:QREFELT |$| 13))
                        (BOOT::|spadConstant| |$| 14)
                        (VMLISP:QREFELT |$| 16)))
                    (SEQ
                       (SEQ
                          (BOOT::LETT
                             BOOT::|k1|
                             (|+| |j| 1)
                             BOOT::|IMATLIN;rowEchelon;2M;3|)
                          BOOT::G190
                          (COND
                             ((|>| BOOT::|k1| BOOT::|maxC|)
                                (GO BOOT::G191)))
                          (SEQ
                             (EXIT
                                (BOOT:SPADCALL
                                   |x|
                                   |k|
                                   BOOT::|k1|
                                   (BOOT:SPADCALL
                                      (BOOT:SPADCALL
                                         |x|
                                         |k|
                                         BOOT::|k1|
                                         (VMLISP:QREFELT |$| 13))
                                      (BOOT:SPADCALL
                                         (BOOT:SPADCALL
                                            |x|
                                            |k|
                                            |j|
                                            (VMLISP:QREFELT |$| 13))
                                         (BOOT:SPADCALL
                                            |x|
                                            |i|
                                            BOOT::|k1|
                                            (VMLISP:QREFELT |$| 13))
                                         (VMLISP:QREFELT |$| 24))
                                      (VMLISP:QREFELT |$| 25))
                                   (VMLISP:QREFELT |$| 23))))
                          (BOOT::LETT
                             BOOT::|k1|
                             (|+| BOOT::|k1| 1)
                             BOOT::|IMATLIN;rowEchelon;2M;3|)
                          (GO BOOT::G190)
                          BOOT::G191
                          (EXIT NIL))
                       (EXIT
                          (BOOT:SPADCALL
                             |x|
                             |k|
                             |j|
                             (BOOT::|spadConstant| |$| 14)
                             (VMLISP:QREFELT |$| 23)))) ))) )))
                                                   (BOOT::LETT
                                                      |k|
        (|+| |k| 1)
                                                      BOOT::|IMATLIN;rowEchelon;2M;3|)
                                                   (GO BOOT::G190)
                                                   BOOT::G191
                                                   (EXIT NIL))
                                                (EXIT
                                                   (BOOT::LETT
                                                      |i|
        (|+| |i| 1)
                              BOOT::|IMATLIN;rowEchelon;2M;3|)))) ))) ))) )
                     (BOOT::LETT
                        |j|
                        (|+| |j| 1)
                        BOOT::|IMATLIN;rowEchelon;2M;3|)
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT NIL))
                  (EXIT |x|)))
            #:G82363
            (EXIT #:G82363)))) )

*/



/* Code for BOOT::|IMATLIN;rowEchelon;2M;3| */

static Lisp_Object CC_BOOT__IMATLINUrowEchelonU2MU3(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V961, V962, V963, V964, V965;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IMATLIN;rowEchelon;2M;3|\n");
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
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-18] = V3;
    stack[0] = V2;
/* end of prologue */
    V962 = stack[-18];
    V961 = (Lisp_Object)305; /* 19 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V963 = qcar(V962);
    V962 = stack[0];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply2(nil, 3, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-19] = V961;
    V962 = stack[-18];
    V961 = (Lisp_Object)273; /* 17 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V963 = qcar(V962);
    V962 = stack[-19];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply2(nil, 3, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-17] = V961;
    V962 = stack[-18];
    V961 = (Lisp_Object)289; /* 18 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V963 = qcar(V962);
    V962 = stack[-19];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply2(nil, 3, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-16] = V961;
    V962 = stack[-18];
    V961 = (Lisp_Object)177; /* 11 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V963 = qcar(V962);
    V962 = stack[-19];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply2(nil, 3, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[0] = V961;
    V962 = stack[-18];
    V961 = (Lisp_Object)193; /* 12 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V963 = qcar(V962);
    V962 = stack[-19];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply2(nil, 3, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-15] = V961;
    V961 = stack[-17];
    stack[-11] = V961;
    V961 = stack[-17];
    V961 = sub1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V961 = stack[0];
    stack[-14] = V961;
    goto V160;

V160:
    V962 = stack[-14];
    V961 = stack[-15];
    V961 = (Lisp_Object)greaterp2(V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    V961 = V961 ? lisp_true : nil;
    env = stack[-20];
    if (!(V961 == nil)) { Lisp_Object res = stack[-19]; popv(21); return onevalue(res); }
    V962 = stack[-16];
    V961 = stack[-11];
    V961 = (Lisp_Object)lessp2(V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    V961 = V961 ? lisp_true : nil;
    env = stack[-20];
    if (!(V961 == nil)) { Lisp_Object res = stack[-19]; popv(21); return onevalue(res); }
    V961 = lisp_true;
    if (V961 == nil) goto V168;
    V961 = stack[-17];
    V961 = sub1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-3] = V961;
    V961 = stack[-11];
    stack[-13] = V961;
    goto V202;

V202:
    V962 = stack[-13];
    V961 = stack[-16];
    V961 = (Lisp_Object)greaterp2(V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    V961 = V961 ? lisp_true : nil;
    env = stack[-20];
    if (!(V961 == nil)) goto V304;
    V962 = stack[-18];
    V961 = (Lisp_Object)257; /* 16 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-2] = V961;
    V961 = stack[-2];
    if (!car_legal(V961)) goto V989;
    stack[-1] = qcar(V961);
    V962 = stack[-18];
    V961 = (Lisp_Object)209; /* 13 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V965 = qcar(V962);
    V964 = stack[-19];
    V963 = stack[-13];
    V962 = stack[-14];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 5, V965, V964, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[0] = V961;
    V962 = stack[-18];
    V961 = (Lisp_Object)225; /* 14 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V962 = qcar(V962);
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply1(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    V961 = stack[-2];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply3(nil, 4, stack[-1], stack[0], V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    if (V961 == nil) goto V213;
    V961 = stack[-13];
    V961 = add1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-13] = V961;
    goto V202;

V213:
    V961 = stack[-13];
    stack[-3] = V961;
    goto V304;

V304:
    stack[0] = stack[-3];
    V961 = stack[-17];
    V961 = sub1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V961 = Leql(nil, stack[0], V961);
    env = stack[-20];
    if (!(V961 == nil)) goto V168;
    V961 = lisp_true;
    if (V961 == nil) goto V168;
    V962 = stack[-11];
    V961 = stack[-3];
    V961 = Leql(nil, V962, V961);
    env = stack[-20];
    if (!(V961 == nil)) goto V364;
    V962 = stack[-18];
    V961 = (Lisp_Object)337; /* 21 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V965 = qcar(V962);
    V964 = stack[-19];
    V963 = stack[-11];
    V962 = stack[-3];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 5, V965, V964, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    goto V364;

V364:
    V962 = stack[-18];
    V961 = (Lisp_Object)353; /* 22 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-1] = V961;
    V961 = stack[-1];
    if (!car_legal(V961)) goto V989;
    stack[0] = qcar(V961);
    V962 = stack[-18];
    V961 = (Lisp_Object)209; /* 13 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V965 = qcar(V962);
    V964 = stack[-19];
    V963 = stack[-11];
    V962 = stack[-14];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 5, V965, V964, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    V961 = stack[-1];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply2(nil, 3, stack[0], V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-8] = V961;
    V962 = stack[-18];
    V961 = (Lisp_Object)369; /* 23 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-4] = V961;
    V961 = stack[-4];
    if (!car_legal(V961)) goto V989;
    stack[-3] = qcar(V961);
    stack[-2] = stack[-19];
    stack[-1] = stack[-11];
    stack[0] = stack[-14];
    V962 = stack[-18];
    V961 = (Lisp_Object)321; /* 20 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V962 = qcar(V962);
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply1(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    V961 = stack[-4];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 6, stack[-3], stack[-2], stack[-1], stack[0], V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V961 = stack[-14];
    V961 = add1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-13] = V961;
    goto V477;

V477:
    V962 = stack[-13];
    V961 = stack[-15];
    V961 = (Lisp_Object)greaterp2(V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    V961 = V961 ? lisp_true : nil;
    env = stack[-20];
    if (V961 == nil) goto V490;
    V961 = stack[-17];
    stack[-13] = V961;
    goto V589;

V589:
    V962 = stack[-13];
    V961 = stack[-16];
    V961 = (Lisp_Object)greaterp2(V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    V961 = V961 ? lisp_true : nil;
    env = stack[-20];
    if (V961 == nil) goto V603;
    V961 = stack[-11];
    V961 = add1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-11] = V961;
    goto V168;

V168:
    V961 = stack[-14];
    V961 = add1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-14] = V961;
    goto V160;

V603:
    V962 = stack[-13];
    V961 = stack[-11];
    V961 = Leql(nil, V962, V961);
    env = stack[-20];
    if (!(V961 == nil)) goto V597;
    V962 = stack[-18];
    V961 = (Lisp_Object)257; /* 16 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-2] = V961;
    V961 = stack[-2];
    if (!car_legal(V961)) goto V989;
    stack[-1] = qcar(V961);
    V962 = stack[-18];
    V961 = (Lisp_Object)209; /* 13 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V965 = qcar(V962);
    V964 = stack[-19];
    V963 = stack[-13];
    V962 = stack[-14];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 5, V965, V964, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[0] = V961;
    V962 = stack[-18];
    V961 = (Lisp_Object)225; /* 14 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V962 = qcar(V962);
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply1(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    V961 = stack[-2];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply3(nil, 4, stack[-1], stack[0], V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    if (!(V961 == nil)) goto V597;
    V961 = stack[-14];
    V961 = add1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-12] = V961;
    goto V703;

V703:
    V962 = stack[-12];
    V961 = stack[-15];
    V961 = (Lisp_Object)greaterp2(V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    V961 = V961 ? lisp_true : nil;
    env = stack[-20];
    if (V961 == nil) goto V716;
    V962 = stack[-18];
    V961 = (Lisp_Object)369; /* 23 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-4] = V961;
    V961 = stack[-4];
    if (!car_legal(V961)) goto V989;
    stack[-3] = qcar(V961);
    stack[-2] = stack[-19];
    stack[-1] = stack[-13];
    stack[0] = stack[-14];
    V962 = stack[-18];
    V961 = (Lisp_Object)225; /* 14 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V962 = qcar(V962);
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply1(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    V961 = stack[-4];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 6, stack[-3], stack[-2], stack[-1], stack[0], V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    goto V597;

V597:
    V961 = stack[-13];
    V961 = add1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-13] = V961;
    goto V589;

V716:
    V962 = stack[-18];
    V961 = (Lisp_Object)369; /* 23 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-10] = V961;
    V961 = stack[-10];
    if (!car_legal(V961)) goto V989;
    stack[-9] = qcar(V961);
    stack[-8] = stack[-19];
    stack[-7] = stack[-13];
    stack[-6] = stack[-12];
    V962 = stack[-18];
    V961 = (Lisp_Object)401; /* 25 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-5] = V961;
    V961 = stack[-5];
    if (!car_legal(V961)) goto V989;
    stack[-4] = qcar(V961);
    V962 = stack[-18];
    V961 = (Lisp_Object)209; /* 13 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V965 = qcar(V962);
    V964 = stack[-19];
    V963 = stack[-13];
    V962 = stack[-12];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 5, V965, V964, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-3] = V961;
    V962 = stack[-18];
    V961 = (Lisp_Object)385; /* 24 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-2] = V961;
    V961 = stack[-2];
    if (!car_legal(V961)) goto V989;
    stack[-1] = qcar(V961);
    V962 = stack[-18];
    V961 = (Lisp_Object)209; /* 13 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V965 = qcar(V962);
    V964 = stack[-19];
    V963 = stack[-13];
    V962 = stack[-14];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 5, V965, V964, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[0] = V961;
    V962 = stack[-18];
    V961 = (Lisp_Object)209; /* 13 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V965 = qcar(V962);
    V964 = stack[-19];
    V963 = stack[-11];
    V962 = stack[-12];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 5, V965, V964, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    V961 = stack[-2];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply3(nil, 4, stack[-1], stack[0], V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    V961 = stack[-5];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply3(nil, 4, stack[-4], stack[-3], V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    V961 = stack[-10];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 6, stack[-9], stack[-8], stack[-7], stack[-6], V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V961 = stack[-12];
    V961 = add1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-12] = V961;
    goto V703;

V490:
    V962 = stack[-18];
    V961 = (Lisp_Object)369; /* 23 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-7] = V961;
    V961 = stack[-7];
    if (!car_legal(V961)) goto V989;
    stack[-6] = qcar(V961);
    stack[-5] = stack[-19];
    stack[-4] = stack[-11];
    stack[-3] = stack[-13];
    V962 = stack[-18];
    V961 = (Lisp_Object)385; /* 24 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-2] = V961;
    V961 = stack[-2];
    if (!car_legal(V961)) goto V989;
    stack[-1] = qcar(V961);
    stack[0] = stack[-8];
    V962 = stack[-18];
    V961 = (Lisp_Object)209; /* 13 */
    V961 = Lgetv(nil, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    if (!car_legal(V962)) goto V987;
    V965 = qcar(V962);
    V964 = stack[-19];
    V963 = stack[-11];
    V962 = stack[-13];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 5, V965, V964, V963, V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    V961 = stack[-2];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    V961 = Lapply3(nil, 4, stack[-1], stack[0], V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V962 = V961;
    V961 = stack[-7];
    if (!car_legal(V961)) goto V988;
    V961 = qcdr(V961);
    fn = elt(env, 2); /* FUNCALL* */
    V961 = (*qfnn(fn))(qenv(fn), 6, stack[-6], stack[-5], stack[-4], stack[-3], V962, V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    V961 = stack[-13];
    V961 = add1(V961);
    nil = C_nil;
    if (exception_pending()) goto V986;
    env = stack[-20];
    stack[-13] = V961;
    goto V477;
/* error exit handlers */
V989:
    popv(21);
    return error(1, err_bad_car, V961);
V988:
    popv(21);
    return error(1, err_bad_cdr, V961);
V987:
    popv(21);
    return error(1, err_bad_car, V962);
V986:
    popv(21);
    return nil;
}

/*
(DEFUN BOOT::|MATCAT-;*;3S;29| (|x| |y| |$|)
   (PROG (BOOT::|ans| |i| #:G82612 |j| #:G82613 |l| #:G82615 |k| #:G82614
         BOOT::|sum| BOOT::|entry|)
      (RETURN
         (SEQ
            (COND
               ((NULL
                   (EQL
                      (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 12))
                      (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 11))))
                  (BOOT::|error|
                     "can't multiply matrices of incompatible dimensions"))
               ('T
                  (SEQ
                     (BOOT::LETT
                        BOOT::|ans|
                        (BOOT:SPADCALL
                           (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 11))
                           (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 12))
                           (BOOT::|spadConstant| |$| 29)
                           (VMLISP:QREFELT |$| 30))
                        BOOT::|MATCAT-;*;3S;29|)
                     (SEQ
                        (BOOT::LETT
                           |i|
                           (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 17))
                           BOOT::|MATCAT-;*;3S;29|)
                        (BOOT::LETT
                           #:G82612
                           (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 18))
                           BOOT::|MATCAT-;*;3S;29|)
                        BOOT::G190
                        (COND ((|>| |i| #:G82612) (GO BOOT::G191)))
                        (SEQ
                           (EXIT
                              (SEQ
                                 (BOOT::LETT
                                    |j|
                                    (BOOT:SPADCALL
                                       |y|
                                       (VMLISP:QREFELT |$| 19))
                                    BOOT::|MATCAT-;*;3S;29|)
                                 (BOOT::LETT
                                    #:G82613
                                    (BOOT:SPADCALL
                                       |y|
                                       (VMLISP:QREFELT |$| 20))
                                    BOOT::|MATCAT-;*;3S;29|)
                                 BOOT::G190
                                 (COND
                                    ((|>| |j| #:G82613) (GO BOOT::G191)))
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|entry|
                                       (SEQ
                                          (BOOT::LETT
                                             BOOT::|sum|
                                             (BOOT::|spadConstant| |$| 29)
                                             BOOT::|MATCAT-;*;3S;29|)
                                          (SEQ
                                             (BOOT::LETT
                                                |l|
                                                (BOOT:SPADCALL
                                                   |x|
                                                   (VMLISP:QREFELT |$| 19))
                                                BOOT::|MATCAT-;*;3S;29|)
                                             (BOOT::LETT
                                                #:G82615
                                                (BOOT:SPADCALL
                                                   |x|
                                                   (VMLISP:QREFELT |$| 20))
                                                BOOT::|MATCAT-;*;3S;29|)
                                             (BOOT::LETT
                                                |k|
                                                (BOOT:SPADCALL
                                                   |y|
                                                   (VMLISP:QREFELT |$| 17))
                                                BOOT::|MATCAT-;*;3S;29|)
                                             (BOOT::LETT
                                                #:G82614
                                                (BOOT:SPADCALL
                                                   |y|
                                                   (VMLISP:QREFELT |$| 18))
                                                BOOT::|MATCAT-;*;3S;29|)
                                             BOOT::G190
                                             (COND
                                                ((OR
                                                    (|>| |k| #:G82614)
                                                    (|>| |l| #:G82615))
                                                   (GO BOOT::G191)))
                                             (SEQ
                                                (EXIT
                                                   (BOOT::LETT
                                                      BOOT::|sum|
        (BOOT:SPADCALL
        BOOT::|sum|
        (BOOT:SPADCALL
           (BOOT:SPADCALL |x| |i| |l| (VMLISP:QREFELT |$| 21))
           (BOOT:SPADCALL |y| |k| |j| (VMLISP:QREFELT |$| 21))
           (VMLISP:QREFELT |$| 70)) (VMLISP:QREFELT |$| 63))
                                                BOOT::|MATCAT-;*;3S;29|)))
                                             (BOOT::LETT
                                                |k|
                                                (PROG1
                                                   (|+| |k| 1)
                                                   (BOOT::LETT
                                                      |l|
        (|+| |l| 1)
                                                BOOT::|MATCAT-;*;3S;29|))
                                                BOOT::|MATCAT-;*;3S;29|)
                                             (GO BOOT::G190)
                                             BOOT::G191
                                             (EXIT NIL))
                                          (EXIT BOOT::|sum|))
                                       BOOT::|MATCAT-;*;3S;29|)
                                    (EXIT
                                       (BOOT:SPADCALL
                                          BOOT::|ans|
                                          |i|
                                          |j|
                                          BOOT::|entry|
                                          (VMLISP:QREFELT |$| 32))))
                                 (BOOT::LETT
                                    |j|
                                    (|+| |j| 1)
                                    BOOT::|MATCAT-;*;3S;29|)
                                 (GO BOOT::G190)
                                 BOOT::G191
                                 (EXIT NIL))))
                        (BOOT::LETT
                           |i|
                           (|+| |i| 1)
                           BOOT::|MATCAT-;*;3S;29|)
                        (GO BOOT::G190)
                        BOOT::G191
                        (EXIT NIL))
                     (EXIT BOOT::|ans|)))) ))) )

*/



/* Code for BOOT::|MATCAT-;*;3S;29| */

static Lisp_Object MS_CDECL CC_BOOT__MATCATKUHU3SU29(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V634, V635, V636, V637, V638, V639;
    Lisp_Object fn;
    argcheck(nargs, 3, "MATCAT-;*;3S;29");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|MATCAT-;*;3S;29|\n");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-14] = V4;
    stack[-15] = V3;
    stack[-16] = V2;
/* end of prologue */
    V635 = stack[-14];
    V634 = (Lisp_Object)193; /* 12 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-16];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[0] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)177; /* 11 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-15];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V634 = Leql(nil, stack[0], V634);
    env = stack[-18];
    if (V634 == nil) goto V25;
    V634 = lisp_true;
    if (V634 == nil) goto V84;
    V635 = stack[-14];
    V634 = (Lisp_Object)481; /* 30 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-3] = V634;
    V634 = stack[-3];
    if (!car_legal(V634)) goto V661;
    stack[-2] = qcar(V634);
    V635 = stack[-14];
    V634 = (Lisp_Object)177; /* 11 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-16];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-1] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)193; /* 12 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-15];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[0] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)465; /* 29 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V635 = qcar(V635);
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply1(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    V634 = stack[-3];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    fn = elt(env, 2); /* FUNCALL* */
    V634 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-17] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)273; /* 17 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-16];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-13] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)289; /* 18 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-16];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-12] = V634;
    goto V241;

V241:
    V635 = stack[-13];
    V634 = stack[-12];
    V634 = (Lisp_Object)greaterp2(V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    V634 = V634 ? lisp_true : nil;
    env = stack[-18];
    if (!(V634 == nil)) { Lisp_Object res = stack[-17]; popv(19); return onevalue(res); }
    V635 = stack[-14];
    V634 = (Lisp_Object)305; /* 19 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-15];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-11] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)321; /* 20 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-15];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-10] = V634;
    goto V307;

V307:
    V635 = stack[-11];
    V634 = stack[-10];
    V634 = (Lisp_Object)greaterp2(V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    V634 = V634 ? lisp_true : nil;
    env = stack[-18];
    if (V634 == nil) goto V322;
    V634 = stack[-13];
    V634 = add1(V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-13] = V634;
    goto V241;

V322:
    V635 = stack[-14];
    V634 = (Lisp_Object)465; /* 29 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V635 = qcar(V635);
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply1(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[0] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)305; /* 19 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-16];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-9] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)321; /* 20 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-16];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-8] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)273; /* 17 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-15];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-7] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)289; /* 18 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V636 = qcar(V635);
    V635 = stack[-15];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply2(nil, 3, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-6] = V634;
    goto V445;

V445:
    V635 = stack[-7];
    V634 = stack[-6];
    V634 = (Lisp_Object)greaterp2(V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    V634 = V634 ? lisp_true : nil;
    env = stack[-18];
    if (!(V634 == nil)) goto V340;
    V635 = stack[-9];
    V634 = stack[-8];
    V634 = (Lisp_Object)greaterp2(V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    V634 = V634 ? lisp_true : nil;
    env = stack[-18];
    if (!(V634 == nil)) goto V340;
    V635 = stack[-14];
    V634 = (Lisp_Object)1009; /* 63 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-5] = V634;
    V634 = stack[-5];
    if (!car_legal(V634)) goto V661;
    stack[-4] = qcar(V634);
    stack[-3] = stack[0];
    V635 = stack[-14];
    V634 = (Lisp_Object)1121; /* 70 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-2] = V634;
    V634 = stack[-2];
    if (!car_legal(V634)) goto V661;
    stack[-1] = qcar(V634);
    V635 = stack[-14];
    V634 = (Lisp_Object)337; /* 21 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V638 = qcar(V635);
    V637 = stack[-16];
    V636 = stack[-13];
    V635 = stack[-9];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    fn = elt(env, 2); /* FUNCALL* */
    V634 = (*qfnn(fn))(qenv(fn), 5, V638, V637, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[0] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)337; /* 21 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V638 = qcar(V635);
    V637 = stack[-15];
    V636 = stack[-7];
    V635 = stack[-11];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    fn = elt(env, 2); /* FUNCALL* */
    V634 = (*qfnn(fn))(qenv(fn), 5, V638, V637, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    V634 = stack[-2];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply3(nil, 4, stack[-1], stack[0], V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    V634 = stack[-5];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    V634 = Lapply3(nil, 4, stack[-4], stack[-3], V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[0] = V634;
    V634 = stack[-7];
    V634 = add1(V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-1] = V634;
    V634 = stack[-9];
    V634 = add1(V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-9] = V634;
    V634 = stack[-1];
    stack[-7] = V634;
    goto V445;

V340:
    V634 = stack[0];
    stack[0] = V634;
    V635 = stack[-14];
    V634 = (Lisp_Object)513; /* 32 */
    V634 = Lgetv(nil, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V635 = V634;
    if (!car_legal(V635)) goto V659;
    V639 = qcar(V635);
    V638 = stack[-17];
    V637 = stack[-13];
    V636 = stack[-11];
    V635 = stack[0];
    if (!car_legal(V634)) goto V660;
    V634 = qcdr(V634);
    fn = elt(env, 2); /* FUNCALL* */
    V634 = (*qfnn(fn))(qenv(fn), 6, V639, V638, V637, V636, V635, V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    V634 = stack[-11];
    V634 = add1(V634);
    nil = C_nil;
    if (exception_pending()) goto V658;
    env = stack[-18];
    stack[-11] = V634;
    goto V307;

V84:
    V634 = nil;
    { popv(19); return onevalue(V634); }

V25:
    V634 = elt(env, 1); /* "can't multiply matrices of incompatible dimensions" */
    {
        popv(19);
        fn = elt(env, 3); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V634);
    }
/* error exit handlers */
V661:
    popv(19);
    return error(1, err_bad_car, V634);
V660:
    popv(19);
    return error(1, err_bad_cdr, V634);
V659:
    popv(19);
    return error(1, err_bad_car, V635);
V658:
    popv(19);
    return nil;
}

/*
(DEFUN BOOT::|SINT;zero?;$B;38| (|x| |$|) (VMLISP:QSZEROP |x|))

*/



/* Code for BOOT::|SINT;zero?;$B;38| */

static Lisp_Object CC_BOOT__SINTUzeroWUDBU38(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V9, V10;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SINT;zero?;$B;38|\n");
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    V9 = V3;
    V10 = V2;
/* end of prologue */
    V9 = V10;
        return Lzerop(nil, V9);
}

/*
(DEFUN BOOT::|DIRPROD;<;2$B;18| (|x| |y| |$|)
   (PROG (|i| #:G84486 #:G84485 #:G84481)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (SEQ
                     (BOOT::LETT |i| 1 BOOT::|DIRPROD;<;2$B;18|)
                     (BOOT::LETT
                        #:G84486
                        (VMLISP:QREFELT |$| 6)
                        BOOT::|DIRPROD;<;2$B;18|)
                     BOOT::G190
                     (COND
                        ((VMLISP:QSGREATERP |i| #:G84486) (GO BOOT::G191)))
                     (SEQ
                        (EXIT
                           (COND
                              ((BOOT:SPADCALL
                                  (BOOT:SPADCALL
                                     |x|
                                     |i|
                                     (VMLISP:QREFELT |$| 51))
                                  (BOOT:SPADCALL
                                     |y|
                                     |i|
                                     (VMLISP:QREFELT |$| 51))
                                  (VMLISP:QREFELT |$| 57))
                                 (PROGN
                                    (BOOT::LETT
                                       #:G84485
                                       'T
                                       BOOT::|DIRPROD;<;2$B;18|)
                                    (GO #:G84485)))
                              ('T
                                 (SEQ
                                    (EXIT
                                       (COND
                                          ((BOOT:SPADCALL
                                              (BOOT:SPADCALL
                                                 |y|
                                                 |i|
                                                 (VMLISP:QREFELT |$| 51))
                                              (BOOT:SPADCALL
                                                 |x|
                                                 |i|
                                                 (VMLISP:QREFELT |$| 51))
                                              (VMLISP:QREFELT |$| 57))
                                             (PROGN
                                                (BOOT::LETT
                                                   #:G84481
                                                   (PROGN
        (BOOT::LETT #:G84485 'NIL BOOT::|DIRPROD;<;2$B;18|)
        (GO #:G84485))
                                                   BOOT::|DIRPROD;<;2$B;18|)
                                                (GO #:G84481)))) )
                                    #:G84481
                                    (EXIT #:G84481)))) ))
                     (BOOT::LETT
                        |i|
                        (VMLISP:QSADD1 |i|)
                        BOOT::|DIRPROD;<;2$B;18|)
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT NIL))
                  (EXIT 'NIL)))
            #:G84485
            (EXIT #:G84485)))) )

*/



/* Code for BOOT::|DIRPROD;<;2$B;18| */

static Lisp_Object MS_CDECL CC_BOOT__DIRPRODURU2DBU18(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V231, V232, V233, V234;
    argcheck(nargs, 3, "DIRPROD;<;2$B;18");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|DIRPROD;<;2$B;18|\n");
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
    V231 = (Lisp_Object)17; /* 1 */
    stack[-7] = V231;
    V232 = stack[-4];
    V231 = (Lisp_Object)97; /* 6 */
    V231 = Lgetv(nil, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    stack[-3] = V231;
    goto V37;

V37:
    V232 = stack[-7];
    V231 = stack[-3];
    V231 = (Lisp_Object)greaterp2(V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    V231 = V231 ? lisp_true : nil;
    env = stack[-8];
    if (V231 == nil) goto V54;
    V231 = nil;
    { popv(9); return onevalue(V231); }

V54:
    V232 = stack[-4];
    V231 = (Lisp_Object)913; /* 57 */
    V231 = Lgetv(nil, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    stack[-2] = V231;
    V231 = stack[-2];
    if (!car_legal(V231)) goto V244;
    stack[-1] = qcar(V231);
    V232 = stack[-4];
    V231 = (Lisp_Object)817; /* 51 */
    V231 = Lgetv(nil, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    V232 = V231;
    if (!car_legal(V232)) goto V245;
    V234 = qcar(V232);
    V233 = stack[-6];
    V232 = stack[-7];
    if (!car_legal(V231)) goto V246;
    V231 = qcdr(V231);
    V231 = Lapply3(nil, 4, V234, V233, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    stack[0] = V231;
    V232 = stack[-4];
    V231 = (Lisp_Object)817; /* 51 */
    V231 = Lgetv(nil, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    V232 = V231;
    if (!car_legal(V232)) goto V245;
    V234 = qcar(V232);
    V233 = stack[-5];
    V232 = stack[-7];
    if (!car_legal(V231)) goto V246;
    V231 = qcdr(V231);
    V231 = Lapply3(nil, 4, V234, V233, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    V232 = V231;
    V231 = stack[-2];
    if (!car_legal(V231)) goto V246;
    V231 = qcdr(V231);
    V231 = Lapply3(nil, 4, stack[-1], stack[0], V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    if (V231 == nil) goto V49;
    V231 = lisp_true;
    { popv(9); return onevalue(V231); }

V49:
    V231 = lisp_true;
    if (V231 == nil) goto V45;
    V232 = stack[-4];
    V231 = (Lisp_Object)913; /* 57 */
    V231 = Lgetv(nil, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    stack[-2] = V231;
    V231 = stack[-2];
    if (!car_legal(V231)) goto V244;
    stack[-1] = qcar(V231);
    V232 = stack[-4];
    V231 = (Lisp_Object)817; /* 51 */
    V231 = Lgetv(nil, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    V232 = V231;
    if (!car_legal(V232)) goto V245;
    V234 = qcar(V232);
    V233 = stack[-5];
    V232 = stack[-7];
    if (!car_legal(V231)) goto V246;
    V231 = qcdr(V231);
    V231 = Lapply3(nil, 4, V234, V233, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    stack[0] = V231;
    V232 = stack[-4];
    V231 = (Lisp_Object)817; /* 51 */
    V231 = Lgetv(nil, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    V232 = V231;
    if (!car_legal(V232)) goto V245;
    V234 = qcar(V232);
    V233 = stack[-6];
    V232 = stack[-7];
    if (!car_legal(V231)) goto V246;
    V231 = qcdr(V231);
    V231 = Lapply3(nil, 4, V234, V233, V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    V232 = V231;
    V231 = stack[-2];
    if (!car_legal(V231)) goto V246;
    V231 = qcdr(V231);
    V231 = Lapply3(nil, 4, stack[-1], stack[0], V232, V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    if (V231 == nil) goto V45;
    V231 = nil;
    { popv(9); return onevalue(V231); }

V45:
    V231 = stack[-7];
    V231 = add1(V231);
    nil = C_nil;
    if (exception_pending()) goto V243;
    env = stack[-8];
    stack[-7] = V231;
    goto V37;
/* error exit handlers */
V246:
    popv(9);
    return error(1, err_bad_cdr, V231);
V245:
    popv(9);
    return error(1, err_bad_car, V232);
V244:
    popv(9);
    return error(1, err_bad_car, V231);
V243:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|DIRPROD;subtractIfCan;2$U;14| (|u| |v| |$|)
   (PROG (|w| |i| #:G84466 |c| #:G84465)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (BOOT::LETT
                     |w|
                     (BOOT:SPADCALL
                        (VMLISP:QREFELT |$| 6)
                        (BOOT::|spadConstant| |$| 44)
                        (VMLISP:QREFELT |$| 37))
                     BOOT::|DIRPROD;subtractIfCan;2$U;14|)
                  (SEQ
                     (BOOT::LETT
                        |i|
                        1
                        BOOT::|DIRPROD;subtractIfCan;2$U;14|)
                     (BOOT::LETT
                        #:G84466
                        (VMLISP:QREFELT |$| 6)
                        BOOT::|DIRPROD;subtractIfCan;2$U;14|)
                     BOOT::G190
                     (COND
                        ((VMLISP:QSGREATERP |i| #:G84466) (GO BOOT::G191)))
                     (SEQ
                        (BOOT::LETT
                           |c|
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL
                                 |u|
                                 |i|
                                 (VMLISP:QREFELT |$| 25))
                              (BOOT:SPADCALL
                                 |v|
                                 |i|
                                 (VMLISP:QREFELT |$| 25))
                              (VMLISP:QREFELT |$| 46))
                           BOOT::|DIRPROD;subtractIfCan;2$U;14|)
                        (EXIT
                           (COND
                              ((BOOT::QEQCAR |c| 1)
                                 (PROGN
                                    (BOOT::LETT
                                       #:G84465
                                       (CONS 1 "failed")
                                    BOOT::|DIRPROD;subtractIfCan;2$U;14|)
                                    (GO #:G84465)))
                              ('T
                                 (BOOT:SPADCALL
                                    |w|
                                    |i|
                                    (QCDR |c|)
                                    (VMLISP:QREFELT |$| 47)))) ))
                     (BOOT::LETT
                        |i|
                        (VMLISP:QSADD1 |i|)
                        BOOT::|DIRPROD;subtractIfCan;2$U;14|)
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT NIL))
                  (EXIT (CONS 0 |w|))))
            #:G84465
            (EXIT #:G84465)))) )

*/



/* Code for BOOT::|DIRPROD;subtractIfCan;2$U;14| */

static Lisp_Object MS_CDECL CC_BOOT__DIRPRODUsubtractIfCanU2DUU14(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V251, V252, V253, V254, V255;
    Lisp_Object fn;
    argcheck(nargs, 3, "DIRPROD;subtractIfCan;2$U;14");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|DIRPROD;subtractIfCan;2$U;14|\n");
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
    V252 = stack[-5];
    V251 = (Lisp_Object)593; /* 37 */
    V251 = Lgetv(nil, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    stack[-2] = V251;
    V251 = stack[-2];
    if (!car_legal(V251)) goto V266;
    stack[-1] = qcar(V251);
    V252 = stack[-5];
    V251 = (Lisp_Object)97; /* 6 */
    stack[0] = Lgetv(nil, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    V252 = stack[-5];
    V251 = (Lisp_Object)705; /* 44 */
    V251 = Lgetv(nil, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    V252 = V251;
    if (!car_legal(V252)) goto V267;
    V252 = qcar(V252);
    if (!car_legal(V251)) goto V268;
    V251 = qcdr(V251);
    V251 = Lapply1(nil, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    V252 = V251;
    V251 = stack[-2];
    if (!car_legal(V251)) goto V268;
    V251 = qcdr(V251);
    V251 = Lapply3(nil, 4, stack[-1], stack[0], V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    stack[-8] = V251;
    V251 = (Lisp_Object)17; /* 1 */
    stack[-4] = V251;
    V252 = stack[-5];
    V251 = (Lisp_Object)97; /* 6 */
    V251 = Lgetv(nil, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    stack[-3] = V251;
    goto V92;

V92:
    V252 = stack[-4];
    V251 = stack[-3];
    V251 = (Lisp_Object)greaterp2(V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    V251 = V251 ? lisp_true : nil;
    env = stack[-9];
    if (V251 == nil) goto V105;
    V252 = (Lisp_Object)1; /* 0 */
    V251 = stack[-8];
    popv(10);
    { Lisp_Object retVal = cons(V252, V251);
    errexit();
    return onevalue(retVal); }

V105:
    V252 = stack[-5];
    V251 = (Lisp_Object)737; /* 46 */
    V251 = Lgetv(nil, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    stack[-2] = V251;
    V251 = stack[-2];
    if (!car_legal(V251)) goto V266;
    stack[-1] = qcar(V251);
    V252 = stack[-5];
    V251 = (Lisp_Object)401; /* 25 */
    V251 = Lgetv(nil, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    V252 = V251;
    if (!car_legal(V252)) goto V267;
    V254 = qcar(V252);
    V253 = stack[-7];
    V252 = stack[-4];
    if (!car_legal(V251)) goto V268;
    V251 = qcdr(V251);
    V251 = Lapply3(nil, 4, V254, V253, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    stack[0] = V251;
    V252 = stack[-5];
    V251 = (Lisp_Object)401; /* 25 */
    V251 = Lgetv(nil, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    V252 = V251;
    if (!car_legal(V252)) goto V267;
    V254 = qcar(V252);
    V253 = stack[-6];
    V252 = stack[-4];
    if (!car_legal(V251)) goto V268;
    V251 = qcdr(V251);
    V251 = Lapply3(nil, 4, V254, V253, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    V252 = V251;
    V251 = stack[-2];
    if (!car_legal(V251)) goto V268;
    V251 = qcdr(V251);
    V251 = Lapply3(nil, 4, stack[-1], stack[0], V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    stack[0] = V251;
    V251 = stack[0];
    V252 = qcar(V251);
    V251 = (Lisp_Object)17; /* 1 */
    V251 = Leql(nil, V252, V251);
    env = stack[-9];
    if (V251 == nil) goto V183;
    V251 = (Lisp_Object)17; /* 1 */
    V252 = elt(env, 1); /* "failed" */
    popv(10);
    { Lisp_Object retVal = cons(V251, V252);
    errexit();
    return onevalue(retVal); }

V183:
    V251 = lisp_true;
    if (V251 == nil) goto V100;
    V252 = stack[-5];
    V251 = (Lisp_Object)753; /* 47 */
    V251 = Lgetv(nil, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    V252 = V251;
    if (!car_legal(V252)) goto V267;
    V255 = qcar(V252);
    V254 = stack[-8];
    V253 = stack[-4];
    V252 = stack[0];
    V252 = qcdr(V252);
    if (!car_legal(V251)) goto V268;
    V251 = qcdr(V251);
    fn = elt(env, 2); /* FUNCALL* */
    V251 = (*qfnn(fn))(qenv(fn), 5, V255, V254, V253, V252, V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    goto V100;

V100:
    V251 = stack[-4];
    V251 = add1(V251);
    nil = C_nil;
    if (exception_pending()) goto V265;
    env = stack[-9];
    stack[-4] = V251;
    goto V92;
/* error exit handlers */
V268:
    popv(10);
    return error(1, err_bad_cdr, V251);
V267:
    popv(10);
    return error(1, err_bad_car, V252);
V266:
    popv(10);
    return error(1, err_bad_car, V251);
V265:
    popv(10);
    return nil;
}

/*
(DEFUN BOOT::|A1AGG-;copy;2A;19| (|x| |$|)
   (PROG (|y| |j| |i| #:G86142)
      (RETURN
         (SEQ
            (BOOT::LETT
               |y|
               (BOOT::|A1AGG-;stupidnew|
                  (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 45))
                  |x|
                  |x|
                  |$|)
               BOOT::|A1AGG-;copy;2A;19|)
            (SEQ
               (BOOT::LETT
                  |j|
                  (BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 9))
                  BOOT::|A1AGG-;copy;2A;19|)
               (BOOT::LETT
                  |i|
                  (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 9))
                  BOOT::|A1AGG-;copy;2A;19|)
               (BOOT::LETT
                  #:G86142
                  (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 10))
                  BOOT::|A1AGG-;copy;2A;19|)
               BOOT::G190
               (COND ((|>| |i| #:G86142) (GO BOOT::G191)))
               (SEQ
                  (EXIT
                     (BOOT:SPADCALL
                        |y|
                        |j|
                        (BOOT:SPADCALL |x| |i| (VMLISP:QREFELT |$| 11))
                        (VMLISP:QREFELT |$| 27))))
               (BOOT::LETT
                  |i|
                  (PROG1
                     (|+| |i| 1)
                     (BOOT::LETT
                        |j|
                        (|+| |j| 1)
                        BOOT::|A1AGG-;copy;2A;19|))
                  BOOT::|A1AGG-;copy;2A;19|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT |y|)))) )

*/



/* Code for BOOT::|A1AGG-;copy;2A;19| */

static Lisp_Object CC_BOOT__A1AGGKUcopyU2AU19(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V212, V213, V214, V215;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|A1AGG-;copy;2A;19|\n");
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
/* copy arguments values to proper place */
    stack[-7] = V3;
    stack[-8] = V2;
/* end of prologue */
    V213 = stack[-7];
    V212 = (Lisp_Object)721; /* 45 */
    V212 = Lgetv(nil, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    V213 = V212;
    if (!car_legal(V213)) goto V227;
    V214 = qcar(V213);
    V213 = stack[-8];
    if (!car_legal(V212)) goto V228;
    V212 = qcdr(V212);
    V212 = Lapply2(nil, 3, V214, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    V215 = V212;
    V214 = stack[-8];
    V213 = stack[-8];
    V212 = stack[-7];
    fn = elt(env, 1); /* BOOT::|A1AGG-;stupidnew| */
    V212 = (*qfnn(fn))(qenv(fn), 4, V215, V214, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    stack[-9] = V212;
    V213 = stack[-7];
    V212 = (Lisp_Object)145; /* 9 */
    V212 = Lgetv(nil, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    V213 = V212;
    if (!car_legal(V213)) goto V227;
    V214 = qcar(V213);
    V213 = stack[-9];
    if (!car_legal(V212)) goto V228;
    V212 = qcdr(V212);
    V212 = Lapply2(nil, 3, V214, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    stack[-6] = V212;
    V213 = stack[-7];
    V212 = (Lisp_Object)145; /* 9 */
    V212 = Lgetv(nil, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    V213 = V212;
    if (!car_legal(V213)) goto V227;
    V214 = qcar(V213);
    V213 = stack[-8];
    if (!car_legal(V212)) goto V228;
    V212 = qcdr(V212);
    V212 = Lapply2(nil, 3, V214, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    stack[-5] = V212;
    V213 = stack[-7];
    V212 = (Lisp_Object)161; /* 10 */
    V212 = Lgetv(nil, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    V213 = V212;
    if (!car_legal(V213)) goto V227;
    V214 = qcar(V213);
    V213 = stack[-8];
    if (!car_legal(V212)) goto V228;
    V212 = qcdr(V212);
    V212 = Lapply2(nil, 3, V214, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    stack[-4] = V212;
    goto V133;

V133:
    V213 = stack[-5];
    V212 = stack[-4];
    V212 = (Lisp_Object)greaterp2(V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    V212 = V212 ? lisp_true : nil;
    env = stack[-10];
    if (!(V212 == nil)) { Lisp_Object res = stack[-9]; popv(11); return onevalue(res); }
    V213 = stack[-7];
    V212 = (Lisp_Object)433; /* 27 */
    V212 = Lgetv(nil, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    stack[-3] = V212;
    V212 = stack[-3];
    if (!car_legal(V212)) goto V229;
    stack[-2] = qcar(V212);
    stack[-1] = stack[-9];
    stack[0] = stack[-6];
    V213 = stack[-7];
    V212 = (Lisp_Object)177; /* 11 */
    V212 = Lgetv(nil, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    V213 = V212;
    if (!car_legal(V213)) goto V227;
    V215 = qcar(V213);
    V214 = stack[-8];
    V213 = stack[-5];
    if (!car_legal(V212)) goto V228;
    V212 = qcdr(V212);
    V212 = Lapply3(nil, 4, V215, V214, V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    V213 = V212;
    V212 = stack[-3];
    if (!car_legal(V212)) goto V228;
    V212 = qcdr(V212);
    fn = elt(env, 2); /* FUNCALL* */
    V212 = (*qfnn(fn))(qenv(fn), 5, stack[-2], stack[-1], stack[0], V213, V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    V212 = stack[-5];
    V212 = add1(V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    stack[0] = V212;
    V212 = stack[-6];
    V212 = add1(V212);
    nil = C_nil;
    if (exception_pending()) goto V226;
    env = stack[-10];
    stack[-6] = V212;
    V212 = stack[0];
    stack[-5] = V212;
    goto V133;
/* error exit handlers */
V229:
    popv(11);
    return error(1, err_bad_car, V212);
V228:
    popv(11);
    return error(1, err_bad_cdr, V212);
V227:
    popv(11);
    return error(1, err_bad_car, V213);
V226:
    popv(11);
    return nil;
}

/*
(DEFUN BOOT::|GDMP;univariate;$OvlSup;21| (|p| |v| |$|)
   (PROG (BOOT::|exp| BOOT::|locv| #:G82451 #:G82452 |i| #:G82453
         BOOT::|deg| BOOT::|nexp|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL |p| (VMLISP:QREFELT |$| 13))
                  (BOOT::|spadConstant| |$| 79))
               ('T
                  (SEQ
                     (BOOT::LETT
                        BOOT::|exp|
                        (BOOT:SPADCALL |p| (VMLISP:QREFELT |$| 66))
                        BOOT::|GDMP;univariate;$OvlSup;21|)
                     (BOOT::LETT
                        BOOT::|locv|
                        (BOOT:SPADCALL |v| (VMLISP:QREFELT |$| 24))
                        BOOT::|GDMP;univariate;$OvlSup;21|)
                     (BOOT::LETT
                        BOOT::|deg|
                        0
                        BOOT::|GDMP;univariate;$OvlSup;21|)
                     (BOOT::LETT
                        BOOT::|nexp|
                        (BOOT:SPADCALL
                           (BOOT::PRIMVEC2ARR
                              (PROGN
                                 (BOOT::LETT
                                    #:G82451
                                    (VMLISP:GETREFV
                                       (VMLISP:QREFELT |$| 11))
                                    BOOT::|GDMP;univariate;$OvlSup;21|)
                                 (SEQ
                                    (BOOT::LETT
                                       #:G82452
                                       0
                                       BOOT::|GDMP;univariate;$OvlSup;21|)
                                    (BOOT::LETT
                                       |i|
                                       1
                                       BOOT::|GDMP;univariate;$OvlSup;21|)
                                    (BOOT::LETT
                                       #:G82453
                                       (VMLISP:QREFELT |$| 11)
                                       BOOT::|GDMP;univariate;$OvlSup;21|)
                                    BOOT::G190
                                    (COND
                                       ((VMLISP:QSGREATERP |i| #:G82453)
                                          (GO BOOT::G191)))
                                    (SEQ
                                       (EXIT
                                          (SETELT
                                             #:G82451
                                             #:G82452
                                             (COND
                                                ((EQL |i| BOOT::|locv|)
                                                   (SEQ
        (BOOT::LETT
        BOOT::|deg|
        (BOOT:SPADCALL BOOT::|exp| |i| (VMLISP:QREFELT |$| 70))
        BOOT::|GDMP;univariate;$OvlSup;21|)
        (EXIT 0)))
                                                ('T
                                                   (BOOT:SPADCALL
                                                      BOOT::|exp|
                                                      |i|
        (VMLISP:QREFELT |$| 70)))) )))
                                    (BOOT::LETT
                                       |i|
                                       (PROG1
                                          (VMLISP:QSADD1 |i|)
                                          (BOOT::LETT
                                             #:G82452
                                             (VMLISP:QSADD1 #:G82452)
                                       BOOT::|GDMP;univariate;$OvlSup;21|))
                                       BOOT::|GDMP;univariate;$OvlSup;21|)
                                    (GO BOOT::G190)
                                    BOOT::G191
                                    (EXIT NIL))
                                 #:G82451))
                           (VMLISP:QREFELT |$| 27))
                        BOOT::|GDMP;univariate;$OvlSup;21|)
                     (EXIT
                        (BOOT:SPADCALL
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL
                                 (BOOT:SPADCALL
                                    |p|
                                    (VMLISP:QREFELT |$| 41))
                                 BOOT::|nexp|
                                 (VMLISP:QREFELT |$| 28))
                              BOOT::|deg|
                              (VMLISP:QREFELT |$| 80))
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL |p| (VMLISP:QREFELT |$| 67))
                              |v|
                              (VMLISP:QREFELT |$| 46))
                           (VMLISP:QREFELT |$| 81)))) ))) )))

*/



/* Code for BOOT::|GDMP;univariate;$OvlSup;21| */

static Lisp_Object MS_CDECL CC_BOOT__GDMPUunivariateUDOvlSupU21(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V432, V433, V434, V435;
    Lisp_Object fn;
    argcheck(nargs, 3, "GDMP;univariate;$OvlSup;21");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|GDMP;univariate;$OvlSup;21|\n");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-10] = V4;
    stack[-11] = V3;
    stack[-12] = V2;
/* end of prologue */
    V433 = stack[-10];
    V432 = (Lisp_Object)209; /* 13 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V433 = V432;
    if (!car_legal(V433)) goto V451;
    V434 = qcar(V433);
    V433 = stack[-12];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply2(nil, 3, V434, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    if (V432 == nil) goto V23;
    V433 = stack[-10];
    V432 = (Lisp_Object)1265; /* 79 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    V433 = V432;
    if (!car_legal(V433)) goto V451;
    V433 = qcar(V433);
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
        popv(15);
        return Lapply1(nil, V433, V432);

V23:
    V432 = lisp_true;
    if (V432 == nil) goto V70;
    V433 = stack[-10];
    V432 = (Lisp_Object)1057; /* 66 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V433 = V432;
    if (!car_legal(V433)) goto V451;
    V434 = qcar(V433);
    V433 = stack[-12];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply2(nil, 3, V434, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-13] = V432;
    V433 = stack[-10];
    V432 = (Lisp_Object)385; /* 24 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V433 = V432;
    if (!car_legal(V433)) goto V451;
    V434 = qcar(V433);
    V433 = stack[-11];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply2(nil, 3, V434, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-9] = V432;
    V432 = (Lisp_Object)1; /* 0 */
    stack[-4] = V432;
    V433 = stack[-10];
    V432 = (Lisp_Object)433; /* 27 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-3] = V432;
    V432 = stack[-3];
    if (!car_legal(V432)) goto V453;
    stack[-2] = qcar(V432);
    V433 = stack[-10];
    V432 = (Lisp_Object)177; /* 11 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    fn = elt(env, 1); /* MAKE-ARRAY-1 */
    V432 = (*qfn1(fn))(qenv(fn), V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-8] = V432;
    V432 = (Lisp_Object)1; /* 0 */
    stack[-7] = V432;
    V432 = (Lisp_Object)17; /* 1 */
    stack[-6] = V432;
    V433 = stack[-10];
    V432 = (Lisp_Object)177; /* 11 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-5] = V432;
    goto V172;

V172:
    V433 = stack[-6];
    V432 = stack[-5];
    V432 = (Lisp_Object)greaterp2(V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    V432 = V432 ? lisp_true : nil;
    env = stack[-14];
    if (V432 == nil) goto V182;
    V433 = stack[-8];
    V432 = stack[-3];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply2(nil, 3, stack[-2], V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-7] = V432;
    V433 = stack[-10];
    V432 = (Lisp_Object)1297; /* 81 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-6] = V432;
    V432 = stack[-6];
    if (!car_legal(V432)) goto V453;
    stack[-5] = qcar(V432);
    V433 = stack[-10];
    V432 = (Lisp_Object)1281; /* 80 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-3] = V432;
    V432 = stack[-3];
    if (!car_legal(V432)) goto V453;
    stack[-2] = qcar(V432);
    V433 = stack[-10];
    V432 = (Lisp_Object)449; /* 28 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-1] = V432;
    V432 = stack[-1];
    if (!car_legal(V432)) goto V453;
    stack[0] = qcar(V432);
    V433 = stack[-10];
    V432 = (Lisp_Object)657; /* 41 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V433 = V432;
    if (!car_legal(V433)) goto V451;
    V434 = qcar(V433);
    V433 = stack[-12];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply2(nil, 3, V434, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V434 = V432;
    V433 = stack[-7];
    V432 = stack[-1];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply3(nil, 4, stack[0], V434, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V434 = V432;
    V433 = stack[-4];
    V432 = stack[-3];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply3(nil, 4, stack[-2], V434, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-2] = V432;
    V433 = stack[-10];
    V432 = (Lisp_Object)737; /* 46 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-1] = V432;
    V432 = stack[-1];
    if (!car_legal(V432)) goto V453;
    stack[0] = qcar(V432);
    V433 = stack[-10];
    V432 = (Lisp_Object)1073; /* 67 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V433 = V432;
    if (!car_legal(V433)) goto V451;
    V434 = qcar(V433);
    V433 = stack[-12];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply2(nil, 3, V434, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V434 = V432;
    V433 = stack[-11];
    V432 = stack[-1];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply3(nil, 4, stack[0], V434, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    V433 = V432;
    V432 = stack[-6];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    {
        Lisp_Object V454 = stack[-5];
        Lisp_Object V455 = stack[-2];
        popv(15);
        return Lapply3(nil, 4, V454, V455, V433, V432);
    }

V182:
    stack[-1] = stack[-8];
    stack[0] = stack[-7];
    V433 = stack[-6];
    V432 = stack[-9];
    V432 = Leql(nil, V433, V432);
    env = stack[-14];
    if (V432 == nil) goto V194;
    V433 = stack[-10];
    V432 = (Lisp_Object)1121; /* 70 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V433 = V432;
    if (!car_legal(V433)) goto V451;
    V435 = qcar(V433);
    V434 = stack[-13];
    V433 = stack[-6];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply3(nil, 4, V435, V434, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-4] = V432;
    V432 = (Lisp_Object)1; /* 0 */
    goto V187;

V187:
    fn = elt(env, 2); /* SETELT */
    V432 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V432 = stack[-6];
    V432 = add1(V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[0] = V432;
    V432 = stack[-7];
    V432 = add1(V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    stack[-7] = V432;
    V432 = stack[0];
    stack[-6] = V432;
    goto V172;

V194:
    V432 = lisp_true;
    if (V432 == nil) goto V235;
    V433 = stack[-10];
    V432 = (Lisp_Object)1121; /* 70 */
    V432 = Lgetv(nil, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    V433 = V432;
    if (!car_legal(V433)) goto V451;
    V435 = qcar(V433);
    V434 = stack[-13];
    V433 = stack[-6];
    if (!car_legal(V432)) goto V452;
    V432 = qcdr(V432);
    V432 = Lapply3(nil, 4, V435, V434, V433, V432);
    nil = C_nil;
    if (exception_pending()) goto V450;
    env = stack[-14];
    goto V187;

V235:
    V432 = nil;
    goto V187;

V70:
    V432 = nil;
    { popv(15); return onevalue(V432); }
/* error exit handlers */
V453:
    popv(15);
    return error(1, err_bad_car, V432);
V452:
    popv(15);
    return error(1, err_bad_cdr, V432);
V451:
    popv(15);
    return error(1, err_bad_car, V433);
V450:
    popv(15);
    return nil;
}

/*
(DEFUN VMLISP:SIZE (L)
   (COND
      ((VECTORP L) (LENGTH L))
      ((STRINGP L) (LENGTH L))
      ((CONSP L) (LENGTH L))
      (T 0)))

*/



/* Code for VMLISP:SIZE */

static Lisp_Object CC_VMLISP__SIZE(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V28, V29;
#ifdef DEBUG_U_FILES
    err_printf("Entering VMLISP:SIZE\n");
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
    V28 = V2;
/* end of prologue */
    V29 = V28;
    V29 = Lvectorp(nil, V29);
    env = stack[0];
    if (V29 == nil) goto V9;
        popv(1);
        return Llength(nil, V28);

V9:
    V29 = V28;
    V29 = Lstringp(nil, V29);
    if (V29 == nil) goto V15;
        popv(1);
        return Llength(nil, V28);

V15:
    V29 = V28;
    if (!consp(V29)) goto V25;
        popv(1);
        return Llength(nil, V28);

V25:
    V28 = (Lisp_Object)1; /* 0 */
    { popv(1); return onevalue(V28); }
}

/*
(DEFUN BOOT::|IARRAY1;map;M3$;8| (|f| |a| |b| |$|)
   (PROG (BOOT::|maxind| |c| |i|)
      (RETURN
         (SEQ
            (BOOT::LETT
               BOOT::|maxind|
               (MIN (VMLISP:QVMAXINDEX |a|) (VMLISP:QVMAXINDEX |b|))
               BOOT::|IARRAY1;map;M3$;8|)
            (EXIT
               (COND
                  ((|<| BOOT::|maxind| 0)
                     (BOOT:SPADCALL (VMLISP:QREFELT |$| 13)))
                  ('T
                     (SEQ
                        (BOOT::LETT
                           |c|
                           (VMLISP:GETREFV (|+| BOOT::|maxind| 1))
                           BOOT::|IARRAY1;map;M3$;8|)
                        (SEQ
                           (BOOT::LETT |i| 0 BOOT::|IARRAY1;map;M3$;8|)
                           BOOT::G190
                           (COND
                              ((VMLISP:QSGREATERP |i| BOOT::|maxind|)
                                 (GO BOOT::G191)))
                           (SEQ
                              (EXIT
                                 (SETELT
                                    |c|
                                    |i|
                                    (BOOT:SPADCALL
                                       (ELT |a| |i|)
                                       (ELT |b| |i|)
                                       |f|))))
                           (BOOT::LETT
                              |i|
                              (VMLISP:QSADD1 |i|)
                              BOOT::|IARRAY1;map;M3$;8|)
                           (GO BOOT::G190)
                           BOOT::G191
                           (EXIT NIL))
                        (EXIT |c|)))) ))) ))

*/



/* Code for BOOT::|IARRAY1;map;M3$;8| */

static Lisp_Object MS_CDECL CC_BOOT__IARRAY1UmapUM3DU8(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V140, V141;
    Lisp_Object fn;
    argcheck(nargs, 4, "IARRAY1;map;M3$;8");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IARRAY1;map;M3$;8|\n");
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
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[0] = V5;
    stack[-7] = V4;
    stack[-8] = V3;
    stack[-9] = V2;
/* end of prologue */
    V140 = stack[-8];
    V140 = Llength(nil, V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    stack[-1] = sub1(V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    V140 = stack[-7];
    V140 = Llength(nil, V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    V140 = sub1(V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    fn = elt(env, 1); /* MIN */
    V140 = (*qfn2(fn))(qenv(fn), stack[-1], V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    stack[-10] = V140;
    V141 = stack[-10];
    V140 = (Lisp_Object)1; /* 0 */
    V140 = (Lisp_Object)lessp2(V141, V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    V140 = V140 ? lisp_true : nil;
    env = stack[-11];
    if (V140 == nil) goto V31;
    V141 = stack[0];
    V140 = (Lisp_Object)209; /* 13 */
    V140 = Lgetv(nil, V141, V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    V141 = V140;
    if (!car_legal(V141)) goto V154;
    V141 = qcar(V141);
    if (!car_legal(V140)) goto V155;
    V140 = qcdr(V140);
        popv(12);
        return Lapply1(nil, V141, V140);

V31:
    V140 = lisp_true;
    if (V140 == nil) goto V62;
    V140 = stack[-10];
    V140 = add1(V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    fn = elt(env, 2); /* MAKE-ARRAY-1 */
    V140 = (*qfn1(fn))(qenv(fn), V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    stack[-6] = V140;
    V140 = (Lisp_Object)1; /* 0 */
    stack[-5] = V140;
    goto V79;

V79:
    V141 = stack[-5];
    V140 = stack[-10];
    V140 = (Lisp_Object)greaterp2(V141, V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    V140 = V140 ? lisp_true : nil;
    env = stack[-11];
    if (!(V140 == nil)) { Lisp_Object res = stack[-6]; popv(12); return onevalue(res); }
    stack[-4] = stack[-6];
    stack[-3] = stack[-5];
    V140 = stack[-9];
    stack[-2] = V140;
    V140 = stack[-2];
    if (!car_legal(V140)) goto V156;
    stack[-1] = qcar(V140);
    V141 = stack[-8];
    V140 = stack[-5];
    fn = elt(env, 3); /* ELT */
    stack[0] = (*qfn2(fn))(qenv(fn), V141, V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    V141 = stack[-7];
    V140 = stack[-5];
    fn = elt(env, 3); /* ELT */
    V141 = (*qfn2(fn))(qenv(fn), V141, V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    V140 = stack[-2];
    if (!car_legal(V140)) goto V155;
    V140 = qcdr(V140);
    V140 = Lapply3(nil, 4, stack[-1], stack[0], V141, V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    fn = elt(env, 4); /* SETELT */
    V140 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[-3], V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    V140 = stack[-5];
    V140 = add1(V140);
    nil = C_nil;
    if (exception_pending()) goto V153;
    env = stack[-11];
    stack[-5] = V140;
    goto V79;

V62:
    V140 = nil;
    { popv(12); return onevalue(V140); }
/* error exit handlers */
V156:
    popv(12);
    return error(1, err_bad_car, V140);
V155:
    popv(12);
    return error(1, err_bad_cdr, V140);
V154:
    popv(12);
    return error(1, err_bad_car, V141);
V153:
    popv(12);
    return nil;
}

/*
(DEFUN BOOT::|AGG-;size?;SNniB;6| (|a| |n| |$|)
   (EQL (BOOT:SPADCALL |a| (VMLISP:QREFELT |$| 12)) |n|))

*/



/* Code for BOOT::|AGG-;size?;SNniB;6| */

static Lisp_Object MS_CDECL CC_BOOT__AGGKUsizeWUSNniBU6(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V39, V40, V41;
    argcheck(nargs, 3, "AGG-;size?;SNniB;6");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|AGG-;size?;SNniB;6|\n");
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
    V39 = (Lisp_Object)193; /* 12 */
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
        popv(3);
        return Leql(nil, V40, V39);
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
(DEFUN BOOT::|PERMGRP;times| (|p| |q| |$|)
   (PROG (#:G82391 #:G82392 |i| #:G82393)
      (RETURN
         (SEQ
            (BOOT::PRIMVEC2ARR
               (PROGN
                  (BOOT::LETT
                     #:G82391
                     (VMLISP:GETREFV (VMLISP:QREFELT |$| 11))
                     BOOT::|PERMGRP;times|)
                  (SEQ
                     (BOOT::LETT #:G82392 0 BOOT::|PERMGRP;times|)
                     (BOOT::LETT |i| 1 BOOT::|PERMGRP;times|)
                     (BOOT::LETT
                        #:G82393
                        (VMLISP:QREFELT |$| 11)
                        BOOT::|PERMGRP;times|)
                     BOOT::G190
                     (COND
                        ((VMLISP:QSGREATERP |i| #:G82393) (GO BOOT::G191)))
                     (SEQ
                        (EXIT
                           (SETELT
                              #:G82391
                              #:G82392
                              (BOOT:SPADCALL
                                 |p|
                                 (BOOT:SPADCALL
                                    |q|
                                    |i|
                                    (VMLISP:QREFELT |$| 39))
                                 (VMLISP:QREFELT |$| 39)))) )
                     (BOOT::LETT
                        |i|
                        (PROG1
                           (VMLISP:QSADD1 |i|)
                           (BOOT::LETT
                              #:G82392
                              (VMLISP:QSADD1 #:G82392)
                              BOOT::|PERMGRP;times|))
                        BOOT::|PERMGRP;times|)
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT NIL))
                  #:G82391)))) ))

*/



/* Code for BOOT::|PERMGRP;times| */

static Lisp_Object MS_CDECL CC_BOOT__PERMGRPUtimes(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V130, V131, V132, V133;
    Lisp_Object fn;
    argcheck(nargs, 3, "PERMGRP;times");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PERMGRP;times|\n");
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
    V131 = stack[-8];
    V130 = (Lisp_Object)177; /* 11 */
    V130 = Lgetv(nil, V131, V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    env = stack[-12];
    fn = elt(env, 1); /* MAKE-ARRAY-1 */
    V130 = (*qfn1(fn))(qenv(fn), V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    env = stack[-12];
    stack[-11] = V130;
    V130 = (Lisp_Object)1; /* 0 */
    stack[-7] = V130;
    V130 = (Lisp_Object)17; /* 1 */
    stack[-6] = V130;
    V131 = stack[-8];
    V130 = (Lisp_Object)177; /* 11 */
    V130 = Lgetv(nil, V131, V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    env = stack[-12];
    stack[-5] = V130;
    goto V44;

V44:
    V131 = stack[-6];
    V130 = stack[-5];
    V130 = (Lisp_Object)greaterp2(V131, V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    V130 = V130 ? lisp_true : nil;
    env = stack[-12];
    if (!(V130 == nil)) { Lisp_Object res = stack[-11]; popv(13); return onevalue(res); }
    stack[-4] = stack[-11];
    stack[-3] = stack[-7];
    V131 = stack[-8];
    V130 = (Lisp_Object)625; /* 39 */
    V130 = Lgetv(nil, V131, V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    env = stack[-12];
    stack[-2] = V130;
    V130 = stack[-2];
    if (!car_legal(V130)) goto V147;
    stack[-1] = qcar(V130);
    stack[0] = stack[-10];
    V131 = stack[-8];
    V130 = (Lisp_Object)625; /* 39 */
    V130 = Lgetv(nil, V131, V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    env = stack[-12];
    V131 = V130;
    if (!car_legal(V131)) goto V148;
    V133 = qcar(V131);
    V132 = stack[-9];
    V131 = stack[-6];
    if (!car_legal(V130)) goto V149;
    V130 = qcdr(V130);
    V130 = Lapply3(nil, 4, V133, V132, V131, V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    env = stack[-12];
    V131 = V130;
    V130 = stack[-2];
    if (!car_legal(V130)) goto V149;
    V130 = qcdr(V130);
    V130 = Lapply3(nil, 4, stack[-1], stack[0], V131, V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    env = stack[-12];
    fn = elt(env, 2); /* SETELT */
    V130 = (*qfnn(fn))(qenv(fn), 3, stack[-4], stack[-3], V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    env = stack[-12];
    V130 = stack[-6];
    V130 = add1(V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    env = stack[-12];
    stack[0] = V130;
    V130 = stack[-7];
    V130 = add1(V130);
    nil = C_nil;
    if (exception_pending()) goto V146;
    env = stack[-12];
    stack[-7] = V130;
    V130 = stack[0];
    stack[-6] = V130;
    goto V44;
/* error exit handlers */
V149:
    popv(13);
    return error(1, err_bad_cdr, V130);
V148:
    popv(13);
    return error(1, err_bad_car, V131);
V147:
    popv(13);
    return error(1, err_bad_car, V130);
V146:
    popv(13);
    return nil;
}

/*
(DEFUN BOOT::|PERMGRP;inv| (|p| |$|)
   (PROG (|q| |i| #:G82415)
      (RETURN
         (SEQ
            (BOOT::LETT
               |q|
               (BOOT:SPADCALL
                  (VMLISP:QREFELT |$| 11)
                  0
                  (VMLISP:QREFELT |$| 53))
               BOOT::|PERMGRP;inv|)
            (SEQ
               (BOOT::LETT |i| 1 BOOT::|PERMGRP;inv|)
               (BOOT::LETT
                  #:G82415
                  (VMLISP:QREFELT |$| 11)
                  BOOT::|PERMGRP;inv|)
               BOOT::G190
               (COND ((VMLISP:QSGREATERP |i| #:G82415) (GO BOOT::G191)))
               (SEQ
                  (EXIT
                     (BOOT:SPADCALL
                        |q|
                        (BOOT:SPADCALL |p| |i| (VMLISP:QREFELT |$| 39))
                        |i|
                        (VMLISP:QREFELT |$| 54))))
               (BOOT::LETT |i| (VMLISP:QSADD1 |i|) BOOT::|PERMGRP;inv|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT |q|)))) )

*/



/* Code for BOOT::|PERMGRP;inv| */

static Lisp_Object CC_BOOT__PERMGRPUinv(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V138, V139, V140, V141;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PERMGRP;inv|\n");
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
    V139 = stack[-5];
    V138 = (Lisp_Object)849; /* 53 */
    V138 = Lgetv(nil, V139, V138);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-8];
    stack[-1] = V138;
    V138 = stack[-1];
    if (!car_legal(V138)) goto V151;
    stack[0] = qcar(V138);
    V139 = stack[-5];
    V138 = (Lisp_Object)177; /* 11 */
    V140 = Lgetv(nil, V139, V138);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-8];
    V139 = (Lisp_Object)1; /* 0 */
    V138 = stack[-1];
    if (!car_legal(V138)) goto V152;
    V138 = qcdr(V138);
    V138 = Lapply3(nil, 4, stack[0], V140, V139, V138);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-8];
    stack[-7] = V138;
    V138 = (Lisp_Object)17; /* 1 */
    stack[-4] = V138;
    V139 = stack[-5];
    V138 = (Lisp_Object)177; /* 11 */
    V138 = Lgetv(nil, V139, V138);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-8];
    stack[-3] = V138;
    goto V66;

V66:
    V139 = stack[-4];
    V138 = stack[-3];
    V138 = (Lisp_Object)greaterp2(V139, V138);
    nil = C_nil;
    if (exception_pending()) goto V150;
    V138 = V138 ? lisp_true : nil;
    env = stack[-8];
    if (!(V138 == nil)) { Lisp_Object res = stack[-7]; popv(9); return onevalue(res); }
    V139 = stack[-5];
    V138 = (Lisp_Object)865; /* 54 */
    V138 = Lgetv(nil, V139, V138);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-8];
    stack[-2] = V138;
    V138 = stack[-2];
    if (!car_legal(V138)) goto V151;
    stack[-1] = qcar(V138);
    stack[0] = stack[-7];
    V139 = stack[-5];
    V138 = (Lisp_Object)625; /* 39 */
    V138 = Lgetv(nil, V139, V138);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-8];
    V139 = V138;
    if (!car_legal(V139)) goto V153;
    V141 = qcar(V139);
    V140 = stack[-6];
    V139 = stack[-4];
    if (!car_legal(V138)) goto V152;
    V138 = qcdr(V138);
    V138 = Lapply3(nil, 4, V141, V140, V139, V138);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-8];
    V140 = V138;
    V139 = stack[-4];
    V138 = stack[-2];
    if (!car_legal(V138)) goto V152;
    V138 = qcdr(V138);
    fn = elt(env, 1); /* FUNCALL* */
    V138 = (*qfnn(fn))(qenv(fn), 5, stack[-1], stack[0], V140, V139, V138);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-8];
    V138 = stack[-4];
    V138 = add1(V138);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-8];
    stack[-4] = V138;
    goto V66;
/* error exit handlers */
V153:
    popv(9);
    return error(1, err_bad_car, V139);
V152:
    popv(9);
    return error(1, err_bad_cdr, V138);
V151:
    popv(9);
    return error(1, err_bad_car, V138);
V150:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|PERMGRP;orbitWithSvc| (BOOT::|group| BOOT::|point| |$|)
   (PROG (BOOT::|el| #:G82444 BOOT::|newGroup| BOOT::|schreierVector| |i|
         #:G82443 BOOT::|newPoint| BOOT::|orbit| BOOT::|position|)
      (RETURN
         (SEQ
            (BOOT::LETT BOOT::|newGroup| NIL BOOT::|PERMGRP;orbitWithSvc|)
            (SEQ
               (BOOT::LETT BOOT::|el| NIL BOOT::|PERMGRP;orbitWithSvc|)
               (BOOT::LETT
                  #:G82444
                  BOOT::|group|
                  BOOT::|PERMGRP;orbitWithSvc|)
               BOOT::G190
               (COND
                  ((OR
                      (ATOM #:G82444)
                      (PROGN
                         (BOOT::LETT
                            BOOT::|el|
                            (CAR #:G82444)
                            BOOT::|PERMGRP;orbitWithSvc|)
                         NIL))
                     (GO BOOT::G191)))
               (SEQ
                  (EXIT
                     (BOOT::LETT
                        BOOT::|newGroup|
                        (CONS
                           (BOOT::|PERMGRP;inv| BOOT::|el| |$|)
                           BOOT::|newGroup|)
                        BOOT::|PERMGRP;orbitWithSvc|)))
               (BOOT::LETT
                  #:G82444
                  (CDR #:G82444)
                  BOOT::|PERMGRP;orbitWithSvc|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (BOOT::LETT
               BOOT::|newGroup|
               (REVERSE BOOT::|newGroup|)
               BOOT::|PERMGRP;orbitWithSvc|)
            (BOOT::LETT
               BOOT::|orbit|
               (LIST BOOT::|point|)
               BOOT::|PERMGRP;orbitWithSvc|)
            (BOOT::LETT
               BOOT::|schreierVector|
               (BOOT:SPADCALL
                  (VMLISP:QREFELT |$| 11)
                  -2
                  (VMLISP:QREFELT |$| 60))
               BOOT::|PERMGRP;orbitWithSvc|)
            (BOOT:SPADCALL
               BOOT::|schreierVector|
               BOOT::|point|
               -1
               (VMLISP:QREFELT |$| 61))
            (BOOT::LETT BOOT::|position| 1 BOOT::|PERMGRP;orbitWithSvc|)
            (SEQ
               BOOT::G190
               (COND
                  ((NULL (COND ((ZEROP BOOT::|position|) 'NIL) ('T 'T)))
                     (GO BOOT::G191)))
               (SEQ
                  (SEQ
                     (BOOT::LETT |i| 1 BOOT::|PERMGRP;orbitWithSvc|)
                     (BOOT::LETT
                        #:G82443
                        (LENGTH BOOT::|newGroup|)
                        BOOT::|PERMGRP;orbitWithSvc|)
                     BOOT::G190
                     (COND
                        ((VMLISP:QSGREATERP |i| #:G82443) (GO BOOT::G191)))
                     (SEQ
                        (BOOT::LETT
                           BOOT::|newPoint|
                           (BOOT:SPADCALL
                              BOOT::|orbit|
                              BOOT::|position|
                              (VMLISP:QREFELT |$| 30))
                           BOOT::|PERMGRP;orbitWithSvc|)
                        (BOOT::LETT
                           BOOT::|newPoint|
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL
                                 BOOT::|newGroup|
                                 |i|
                                 (VMLISP:QREFELT |$| 44))
                              BOOT::|newPoint|
                              (VMLISP:QREFELT |$| 40))
                           BOOT::|PERMGRP;orbitWithSvc|)
                        (EXIT
                           (COND
                              ((NULL
                                  (BOOT:SPADCALL
                                     BOOT::|newPoint|
                                     BOOT::|orbit|
                                     (VMLISP:QREFELT |$| 32)))
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|orbit|
                                       (CONS
                                          BOOT::|newPoint|
                                          BOOT::|orbit|)
                                       BOOT::|PERMGRP;orbitWithSvc|)
                                    (BOOT::LETT
                                       BOOT::|position|
                                       (|+| BOOT::|position| 1)
                                       BOOT::|PERMGRP;orbitWithSvc|)
                                    (EXIT
                                       (BOOT:SPADCALL
                                          BOOT::|schreierVector|
                                          BOOT::|newPoint|
                                          |i|
                                          (VMLISP:QREFELT |$| 61)))) ))) )
                     (BOOT::LETT
                        |i|
                        (VMLISP:QSADD1 |i|)
                        BOOT::|PERMGRP;orbitWithSvc|)
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT NIL))
                  (EXIT
                     (BOOT::LETT
                        BOOT::|position|
                        (|-| BOOT::|position| 1)
                        BOOT::|PERMGRP;orbitWithSvc|)))
               NIL
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT
               (CONS (REVERSE BOOT::|orbit|) BOOT::|schreierVector|)))) ))

*/



/* Code for BOOT::|PERMGRP;orbitWithSvc| */

static Lisp_Object MS_CDECL CC_BOOT__PERMGRPUorbitWithSvc(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V346, V347, V348, V349, V350;
    Lisp_Object fn;
    argcheck(nargs, 3, "PERMGRP;orbitWithSvc");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PERMGRP;orbitWithSvc|\n");
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
    stack[-8] = V4;
    stack[0] = V3;
    V347 = V2;
/* end of prologue */
    V346 = nil;
    stack[-9] = V346;
    V346 = V347;
    stack[-1] = V346;
    goto V24;

V24:
    V346 = stack[-1];
    if (!consp(V346)) goto V23;
    V346 = stack[-1];
    if (!car_legal(V346)) goto V361;
    V346 = qcar(V346);
    V347 = V346;
    V346 = nil;
    if (!(V346 == nil)) goto V23;
    V346 = stack[-8];
    fn = elt(env, 1); /* BOOT::|PERMGRP;inv| */
    V347 = (*qfn2(fn))(qenv(fn), V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    V346 = stack[-9];
    V346 = cons(V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-9] = V346;
    V346 = stack[-1];
    if (!car_legal(V346)) goto V363;
    V346 = qcdr(V346);
    stack[-1] = V346;
    goto V24;

V23:
    V346 = stack[-9];
    V346 = Lreverse(nil, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-9] = V346;
    V346 = stack[0];
    V346 = ncons(V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-3] = V346;
    V347 = stack[-8];
    V346 = (Lisp_Object)961; /* 60 */
    V346 = Lgetv(nil, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-2] = V346;
    V346 = stack[-2];
    if (!car_legal(V346)) goto V361;
    stack[-1] = qcar(V346);
    V347 = stack[-8];
    V346 = (Lisp_Object)177; /* 11 */
    V348 = Lgetv(nil, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    V347 = (Lisp_Object)-31; /* -2 */
    V346 = stack[-2];
    if (!car_legal(V346)) goto V363;
    V346 = qcdr(V346);
    V346 = Lapply3(nil, 4, stack[-1], V348, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-7] = V346;
    V347 = stack[-8];
    V346 = (Lisp_Object)977; /* 61 */
    V346 = Lgetv(nil, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    V347 = V346;
    if (!car_legal(V347)) goto V364;
    V350 = qcar(V347);
    V349 = stack[-7];
    V348 = stack[0];
    V347 = (Lisp_Object)-15; /* -1 */
    if (!car_legal(V346)) goto V363;
    V346 = qcdr(V346);
    fn = elt(env, 2); /* FUNCALL* */
    V346 = (*qfnn(fn))(qenv(fn), 5, V350, V349, V348, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    V346 = (Lisp_Object)17; /* 1 */
    stack[-2] = V346;
    goto V131;

V131:
    V346 = stack[-2];
    V346 = (Lisp_Object)zerop(V346);
    V346 = V346 ? lisp_true : nil;
    env = stack[-10];
    if (V346 == nil) goto V140;
    V346 = nil;
    goto V138;

V138:
    if (V346 == nil) goto V337;
    V346 = (Lisp_Object)17; /* 1 */
    stack[-6] = V346;
    V346 = stack[-9];
    V346 = Llength(nil, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-5] = V346;
    goto V162;

V162:
    V347 = stack[-6];
    V346 = stack[-5];
    V346 = (Lisp_Object)greaterp2(V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    V346 = V346 ? lisp_true : nil;
    env = stack[-10];
    if (V346 == nil) goto V175;
    V346 = stack[-2];
    V346 = sub1(V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-2] = V346;
    goto V131;

V175:
    V347 = stack[-8];
    V346 = (Lisp_Object)481; /* 30 */
    V346 = Lgetv(nil, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    V347 = V346;
    if (!car_legal(V347)) goto V364;
    V349 = qcar(V347);
    V348 = stack[-3];
    V347 = stack[-2];
    if (!car_legal(V346)) goto V363;
    V346 = qcdr(V346);
    V346 = Lapply3(nil, 4, V349, V348, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-4] = V346;
    V347 = stack[-8];
    V346 = (Lisp_Object)641; /* 40 */
    V346 = Lgetv(nil, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-1] = V346;
    V346 = stack[-1];
    if (!car_legal(V346)) goto V361;
    stack[0] = qcar(V346);
    V347 = stack[-8];
    V346 = (Lisp_Object)705; /* 44 */
    V346 = Lgetv(nil, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    V347 = V346;
    if (!car_legal(V347)) goto V364;
    V349 = qcar(V347);
    V348 = stack[-9];
    V347 = stack[-6];
    if (!car_legal(V346)) goto V363;
    V346 = qcdr(V346);
    V346 = Lapply3(nil, 4, V349, V348, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    V348 = V346;
    V347 = stack[-4];
    V346 = stack[-1];
    if (!car_legal(V346)) goto V363;
    V346 = qcdr(V346);
    V346 = Lapply3(nil, 4, stack[0], V348, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-4] = V346;
    V347 = stack[-8];
    V346 = (Lisp_Object)513; /* 32 */
    V346 = Lgetv(nil, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    V347 = V346;
    if (!car_legal(V347)) goto V364;
    V349 = qcar(V347);
    V348 = stack[-4];
    V347 = stack[-3];
    if (!car_legal(V346)) goto V363;
    V346 = qcdr(V346);
    V346 = Lapply3(nil, 4, V349, V348, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    if (!(V346 == nil)) goto V170;
    V347 = stack[-4];
    V346 = stack[-3];
    V346 = cons(V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-3] = V346;
    V346 = stack[-2];
    V346 = add1(V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-2] = V346;
    V347 = stack[-8];
    V346 = (Lisp_Object)977; /* 61 */
    V346 = Lgetv(nil, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    V347 = V346;
    if (!car_legal(V347)) goto V364;
    V350 = qcar(V347);
    V349 = stack[-7];
    V348 = stack[-4];
    V347 = stack[-6];
    if (!car_legal(V346)) goto V363;
    V346 = qcdr(V346);
    fn = elt(env, 2); /* FUNCALL* */
    V346 = (*qfnn(fn))(qenv(fn), 5, V350, V349, V348, V347, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    goto V170;

V170:
    V346 = stack[-6];
    V346 = add1(V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    env = stack[-10];
    stack[-6] = V346;
    goto V162;

V337:
    V346 = stack[-3];
    V347 = Lreverse(nil, V346);
    nil = C_nil;
    if (exception_pending()) goto V362;
    V346 = stack[-7];
    popv(11);
    { Lisp_Object retVal = cons(V347, V346);
    errexit();
    return onevalue(retVal); }

V140:
    V346 = lisp_true;
    if (V346 == nil) goto V145;
    V346 = lisp_true;
    goto V138;

V145:
    V346 = nil;
    goto V138;
/* error exit handlers */
V364:
    popv(11);
    return error(1, err_bad_car, V347);
V363:
    popv(11);
    return error(1, err_bad_cdr, V346);
V362:
    popv(11);
    return nil;
V361:
    popv(11);
    return error(1, err_bad_car, V346);
}



setup_type const u02_setup[] =
{
    {"BOOT@@ARR2CAT-;copy;2S;10@@Builtin",too_few_2,CC_BOOT__ARR2CATKUcopyU2SU10,wrong_no_2},
    {"BOOT@@IMATLIN;rowEchelon;2M;3@@Builtin",too_few_2,CC_BOOT__IMATLINUrowEchelonU2MU3,wrong_no_2},
    {"BOOT@@MATCAT-;*;3S;29@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__MATCATKUHU3SU29},
    {"BOOT@@SINT;zero?;$B;38@@Builtin",too_few_2,CC_BOOT__SINTUzeroWUDBU38,wrong_no_2},
    {"BOOT@@DIRPROD;<;2$B;18@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__DIRPRODURU2DBU18},
    {"BOOT@@DIRPROD;subtractIfCan;2$U;14@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__DIRPRODUsubtractIfCanU2DUU14},
    {"BOOT@@A1AGG-;copy;2A;19@@Builtin",too_few_2,CC_BOOT__A1AGGKUcopyU2AU19,wrong_no_2},
    {"BOOT@@GDMP;univariate;$OvlSup;21@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__GDMPUunivariateUDOvlSupU21},
    {"VMLISP@@SIZE@@Builtin",   CC_VMLISP__SIZE,too_many_1,    wrong_no_1},
    {"BOOT@@IARRAY1;map;M3$;8@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IARRAY1UmapUM3DU8},
    {"BOOT@@AGG-;size?;SNniB;6@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__AGGKUsizeWUSNniBU6},
    {"BOOT@@PERMGRP;times@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__PERMGRPUtimes},
    {"BOOT@@PERMGRP;inv@@Builtin",too_few_2,    CC_BOOT__PERMGRPUinv,wrong_no_2},
    {"BOOT@@PERMGRP;orbitWithSvc@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__PERMGRPUorbitWithSvc},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
