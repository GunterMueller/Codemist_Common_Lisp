
/* u09.c                 Machine generated C code */

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
(DEFUN BOOT::|COMPCAT-;unitNormal;SR;49| (|x| |$|)
   (PROG (|u| |c|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 209))
                  (VECTOR
                     (BOOT::|spadConstant| |$| 8)
                     |x|
                     (BOOT::|spadConstant| |$| 8)))
               ('T
                  (SEQ
                     (BOOT::LETT
                        |u|
                        (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 210))
                        BOOT::|COMPCAT-;unitNormal;SR;49|)
                     (EXIT
                        (COND
                           ((BOOT::QEQCAR |u| 0)
                              (VECTOR
                                 |x|
                                 (BOOT::|spadConstant| |$| 8)
                                 (QCDR |u|)))
                           ((BOOT:SPADCALL
                               (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 24))
                               (VMLISP:QREFELT |$| 82))
                              (SEQ
                                 (BOOT::LETT
                                    |c|
                                    (BOOT:SPADCALL
                                       (BOOT:SPADCALL
                                          |x|
                                          (VMLISP:QREFELT |$| 92))
                                       (VMLISP:QREFELT |$| 212))
                                    BOOT::|COMPCAT-;unitNormal;SR;49|)
                                 (EXIT
                                    (VECTOR
                                       (BOOT:SPADCALL
                                          (BOOT::|spadConstant| |$| 21)
                                          (VMLISP:QVELT |c| 0)
                                          (VMLISP:QREFELT |$| 30))
                                       (BOOT:SPADCALL
                                          (BOOT:SPADCALL
                                             (VMLISP:QVELT |c| 2)
                                             (BOOT:SPADCALL
                                                |x|
                                                (VMLISP:QREFELT |$| 92))
                                             (VMLISP:QREFELT |$| 106))
                                          (VMLISP:QREFELT |$| 78))
                                       (BOOT:SPADCALL
                                          (BOOT::|spadConstant| |$| 21)
                                          (BOOT:SPADCALL
                                             (VMLISP:QVELT |c| 2)
                                             (VMLISP:QREFELT |$| 89))
                                          (VMLISP:QREFELT |$| 30)))) ))
                           ('T
                              (SEQ
                                 (BOOT::LETT
                                    |c|
                                    (BOOT:SPADCALL
                                       (BOOT:SPADCALL
                                          |x|
                                          (VMLISP:QREFELT |$| 24))
                                       (VMLISP:QREFELT |$| 212))
                                    BOOT::|COMPCAT-;unitNormal;SR;49|)
                                 (BOOT::LETT
                                    |x|
                                    (BOOT:SPADCALL
                                       (VMLISP:QVELT |c| 2)
                                       |x|
                                       (VMLISP:QREFELT |$| 213))
                                    BOOT::|COMPCAT-;unitNormal;SR;49|)
                                 (EXIT
                                    (COND
                                       ((BOOT:SPADCALL
                                           (BOOT:SPADCALL
                                              |x|
                                              (VMLISP:QREFELT |$| 92))
                                           (BOOT::|spadConstant| |$| 21)
                                           (VMLISP:QREFELT |$| 191))
                                          (SEQ
                                             (BOOT::LETT
                                                |x|
                                                (BOOT:SPADCALL
                                                   (BOOT:SPADCALL
        (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 92))
        (VMLISP:QREFELT |$| 89))
                                                   (BOOT:SPADCALL
                                                      |x|
        (VMLISP:QREFELT |$| 24))
                                                   (VMLISP:QREFELT |$| 30))
                                       BOOT::|COMPCAT-;unitNormal;SR;49|)
                                             (EXIT
                                                (VECTOR
                                                   (BOOT:SPADCALL
        (BOOT:SPADCALL
        (VMLISP:QVELT |c| 0)
        (BOOT:SPADCALL (VMLISP:QREFELT |$| 214)) (VMLISP:QREFELT |$| 213))
        (VMLISP:QREFELT |$| 215))
                                                   |x|
                                                   (BOOT:SPADCALL
        (VMLISP:QVELT |c| 2)
        (BOOT:SPADCALL (VMLISP:QREFELT |$| 214))
        (VMLISP:QREFELT |$| 213)))) ))
                                       ('T
                                       (VECTOR
                                          (BOOT:SPADCALL
                                                (VMLISP:QVELT |c| 0)
                                                (VMLISP:QREFELT |$| 78))
                                          |x|
                                          (BOOT:SPADCALL
                                                (VMLISP:QVELT |c| 2)
                              (VMLISP:QREFELT |$| 78)))) ))) ))) ))) ))) )

*/



/* Code for BOOT::|COMPCAT-;unitNormal;SR;49| */

static Lisp_Object CC_BOOT__COMPCATKUunitNormalUSRU49(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V960, V961, V962;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPCAT-;unitNormal;SR;49|\n");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-6] = V3;
    stack[-7] = V2;
/* end of prologue */
    V961 = stack[-6];
    V960 = (Lisp_Object)3345; /* 209 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V962 = qcar(V961);
    V961 = stack[-7];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, V962, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    if (V960 == nil) goto V16;
    V961 = stack[-6];
    V960 = (Lisp_Object)129; /* 8 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V961 = qcar(V961);
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply1(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[0] = V960;
    stack[-1] = stack[-7];
    V961 = stack[-6];
    V960 = (Lisp_Object)129; /* 8 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V961 = qcar(V961);
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply1(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    {
        Lisp_Object V975 = stack[0];
        Lisp_Object V976 = stack[-1];
        popv(10);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V975, V976, V960);
    }

V16:
    V960 = lisp_true;
    if (V960 == nil) goto V93;
    V961 = stack[-6];
    V960 = (Lisp_Object)3361; /* 210 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V962 = qcar(V961);
    V961 = stack[-7];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, V962, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[0] = V960;
    V960 = stack[0];
    V961 = qcar(V960);
    V960 = (Lisp_Object)1; /* 0 */
    V960 = Leql(nil, V961, V960);
    env = stack[-9];
    if (V960 == nil) goto V172;
    stack[-1] = stack[-7];
    V961 = stack[-6];
    V960 = (Lisp_Object)129; /* 8 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V961 = qcar(V961);
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply1(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[0];
    V960 = qcdr(V960);
    {
        Lisp_Object V977 = stack[-1];
        popv(10);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V977, V961, V960);
    }

V172:
    V961 = stack[-6];
    V960 = (Lisp_Object)1313; /* 82 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-1] = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V978;
    stack[0] = qcar(V960);
    V961 = stack[-6];
    V960 = (Lisp_Object)385; /* 24 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V962 = qcar(V961);
    V961 = stack[-7];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, V962, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    if (V960 == nil) goto V167;
    V961 = stack[-6];
    V960 = (Lisp_Object)3393; /* 212 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-1] = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V978;
    stack[0] = qcar(V960);
    V961 = stack[-6];
    V960 = (Lisp_Object)1473; /* 92 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V962 = qcar(V961);
    V961 = stack[-7];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, V962, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-8] = V960;
    V961 = stack[-6];
    V960 = (Lisp_Object)481; /* 30 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-2] = V960;
    V960 = stack[-2];
    if (!car_legal(V960)) goto V978;
    stack[-1] = qcar(V960);
    V961 = stack[-6];
    V960 = (Lisp_Object)337; /* 21 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V961 = qcar(V961);
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply1(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[0] = V960;
    V961 = stack[-8];
    V960 = (Lisp_Object)1; /* 0 */
    V961 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V960 = stack[-2];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply3(nil, 4, stack[-1], stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-5] = V960;
    V961 = stack[-6];
    V960 = (Lisp_Object)1249; /* 78 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-4] = V960;
    V960 = stack[-4];
    if (!car_legal(V960)) goto V978;
    stack[-3] = qcar(V960);
    V961 = stack[-6];
    V960 = (Lisp_Object)1697; /* 106 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-2] = V960;
    V960 = stack[-2];
    if (!car_legal(V960)) goto V978;
    stack[-1] = qcar(V960);
    V961 = stack[-8];
    V960 = (Lisp_Object)33; /* 2 */
    stack[0] = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = stack[-6];
    V960 = (Lisp_Object)1473; /* 92 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V962 = qcar(V961);
    V961 = stack[-7];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, V962, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-2];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply3(nil, 4, stack[-1], stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-4];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, stack[-3], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-4] = V960;
    V961 = stack[-6];
    V960 = (Lisp_Object)481; /* 30 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-3] = V960;
    V960 = stack[-3];
    if (!car_legal(V960)) goto V978;
    stack[-2] = qcar(V960);
    V961 = stack[-6];
    V960 = (Lisp_Object)337; /* 21 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V961 = qcar(V961);
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply1(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-1] = V960;
    V961 = stack[-6];
    V960 = (Lisp_Object)1425; /* 89 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-6] = V960;
    V960 = stack[-6];
    if (!car_legal(V960)) goto V978;
    stack[0] = qcar(V960);
    V961 = stack[-8];
    V960 = (Lisp_Object)33; /* 2 */
    V961 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V960 = stack[-6];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-3];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply3(nil, 4, stack[-2], stack[-1], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    {
        Lisp_Object V979 = stack[-5];
        Lisp_Object V980 = stack[-4];
        popv(10);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V979, V980, V960);
    }

V167:
    V960 = lisp_true;
    if (V960 == nil) goto V485;
    V961 = stack[-6];
    V960 = (Lisp_Object)3393; /* 212 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-1] = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V978;
    stack[0] = qcar(V960);
    V961 = stack[-6];
    V960 = (Lisp_Object)385; /* 24 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V962 = qcar(V961);
    V961 = stack[-7];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, V962, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-8] = V960;
    V961 = stack[-6];
    V960 = (Lisp_Object)3409; /* 213 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-1] = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V978;
    stack[0] = qcar(V960);
    V961 = stack[-8];
    V960 = (Lisp_Object)33; /* 2 */
    V962 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = stack[-7];
    V960 = stack[-1];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply3(nil, 4, stack[0], V962, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-7] = V960;
    V961 = stack[-6];
    V960 = (Lisp_Object)3057; /* 191 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-2] = V960;
    V960 = stack[-2];
    if (!car_legal(V960)) goto V978;
    stack[-1] = qcar(V960);
    V961 = stack[-6];
    V960 = (Lisp_Object)1473; /* 92 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V962 = qcar(V961);
    V961 = stack[-7];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, V962, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[0] = V960;
    V961 = stack[-6];
    V960 = (Lisp_Object)337; /* 21 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V961 = qcar(V961);
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply1(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-2];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply3(nil, 4, stack[-1], stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    if (V960 == nil) goto V573;
    V961 = stack[-6];
    V960 = (Lisp_Object)481; /* 30 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-3] = V960;
    V960 = stack[-3];
    if (!car_legal(V960)) goto V978;
    stack[-2] = qcar(V960);
    V961 = stack[-6];
    V960 = (Lisp_Object)1425; /* 89 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-1] = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V978;
    stack[0] = qcar(V960);
    V961 = stack[-6];
    V960 = (Lisp_Object)1473; /* 92 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V962 = qcar(V961);
    V961 = stack[-7];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, V962, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[0] = V960;
    V961 = stack[-6];
    V960 = (Lisp_Object)385; /* 24 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V962 = qcar(V961);
    V961 = stack[-7];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, V962, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-3];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply3(nil, 4, stack[-2], stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-7] = V960;
    V961 = stack[-6];
    V960 = (Lisp_Object)3441; /* 215 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-4] = V960;
    V960 = stack[-4];
    if (!car_legal(V960)) goto V978;
    stack[-3] = qcar(V960);
    V961 = stack[-6];
    V960 = (Lisp_Object)3409; /* 213 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-2] = V960;
    V960 = stack[-2];
    if (!car_legal(V960)) goto V978;
    stack[-1] = qcar(V960);
    V961 = stack[-8];
    V960 = (Lisp_Object)1; /* 0 */
    stack[0] = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = stack[-6];
    V960 = (Lisp_Object)3425; /* 214 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V961 = qcar(V961);
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply1(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-2];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply3(nil, 4, stack[-1], stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-4];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, stack[-3], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-2] = V960;
    stack[-3] = stack[-7];
    V961 = stack[-6];
    V960 = (Lisp_Object)3409; /* 213 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-1] = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V978;
    stack[0] = qcar(V960);
    V961 = stack[-8];
    V960 = (Lisp_Object)33; /* 2 */
    stack[-4] = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = stack[-6];
    V960 = (Lisp_Object)3425; /* 214 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    if (!car_legal(V961)) goto V973;
    V961 = qcar(V961);
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply1(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V961 = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply3(nil, 4, stack[0], stack[-4], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    {
        Lisp_Object V981 = stack[-2];
        Lisp_Object V982 = stack[-3];
        popv(10);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V981, V982, V960);
    }

V573:
    V960 = lisp_true;
    if (V960 == nil) goto V884;
    V961 = stack[-6];
    V960 = (Lisp_Object)1249; /* 78 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-1] = V960;
    V960 = stack[-1];
    if (!car_legal(V960)) goto V978;
    stack[0] = qcar(V960);
    V961 = stack[-8];
    V960 = (Lisp_Object)1; /* 0 */
    V961 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V960 = stack[-1];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-1] = V960;
    stack[-2] = stack[-7];
    V961 = stack[-6];
    V960 = (Lisp_Object)1249; /* 78 */
    V960 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    stack[-3] = V960;
    V960 = stack[-3];
    if (!car_legal(V960)) goto V978;
    stack[0] = qcar(V960);
    V961 = stack[-8];
    V960 = (Lisp_Object)33; /* 2 */
    V961 = Lgetv(nil, V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    V960 = stack[-3];
    if (!car_legal(V960)) goto V974;
    V960 = qcdr(V960);
    V960 = Lapply2(nil, 3, stack[0], V961, V960);
    nil = C_nil;
    if (exception_pending()) goto V972;
    env = stack[-9];
    {
        Lisp_Object V983 = stack[-1];
        Lisp_Object V984 = stack[-2];
        popv(10);
        fn = elt(env, 1); /* VECTOR */
        return (*qfnn(fn))(qenv(fn), 3, V983, V984, V960);
    }

V884:
    V960 = nil;
    { popv(10); return onevalue(V960); }

V485:
    V960 = nil;
    { popv(10); return onevalue(V960); }

V93:
    V960 = nil;
    { popv(10); return onevalue(V960); }
/* error exit handlers */
V978:
    popv(10);
    return error(1, err_bad_car, V960);
V974:
    popv(10);
    return error(1, err_bad_cdr, V960);
V973:
    popv(10);
    return error(1, err_bad_car, V961);
V972:
    popv(10);
    return nil;
}

/*
(DEFUN BOOT::|FLASORT;quickSort;M2V;1| (|l| |r| |$|)
   (BOOT::|FLASORT;QuickSort|
      |l|
      |r|
      (BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 9))
      (BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 10))
      |$|))

*/



/* Code for BOOT::|FLASORT;quickSort;M2V;1| */

static Lisp_Object MS_CDECL CC_BOOT__FLASORTUquickSortUM2VU1(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V71, V72, V73;
    Lisp_Object fn;
    argcheck(nargs, 3, "FLASORT;quickSort;M2V;1");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FLASORT;quickSort;M2V;1|\n");
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
    stack[-3] = V3;
    V71 = V2;
/* end of prologue */
    stack[-4] = V71;
    stack[-1] = stack[-3];
    V72 = stack[-2];
    V71 = (Lisp_Object)145; /* 9 */
    V71 = Lgetv(nil, V72, V71);
    nil = C_nil;
    if (exception_pending()) goto V79;
    env = stack[-5];
    V72 = V71;
    if (!car_legal(V72)) goto V80;
    V73 = qcar(V72);
    V72 = stack[-3];
    if (!car_legal(V71)) goto V81;
    V71 = qcdr(V71);
    V71 = Lapply2(nil, 3, V73, V72, V71);
    nil = C_nil;
    if (exception_pending()) goto V79;
    env = stack[-5];
    stack[0] = V71;
    V72 = stack[-2];
    V71 = (Lisp_Object)161; /* 10 */
    V71 = Lgetv(nil, V72, V71);
    nil = C_nil;
    if (exception_pending()) goto V79;
    env = stack[-5];
    V72 = V71;
    if (!car_legal(V72)) goto V80;
    V73 = qcar(V72);
    V72 = stack[-3];
    if (!car_legal(V71)) goto V81;
    V71 = qcdr(V71);
    V71 = Lapply2(nil, 3, V73, V72, V71);
    nil = C_nil;
    if (exception_pending()) goto V79;
    env = stack[-5];
    V72 = V71;
    V71 = stack[-2];
    {
        Lisp_Object V82 = stack[-4];
        Lisp_Object V83 = stack[-1];
        Lisp_Object V84 = stack[0];
        popv(6);
        fn = elt(env, 1); /* BOOT::|FLASORT;QuickSort| */
        return (*qfnn(fn))(qenv(fn), 5, V82, V83, V84, V72, V71);
    }
/* error exit handlers */
V81:
    popv(6);
    return error(1, err_bad_cdr, V71);
V80:
    popv(6);
    return error(1, err_bad_car, V72);
V79:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|NNI;subtractIfCan;2$U;3| (|x| |y| |$|)
   (PROG (|c|)
      (RETURN
         (SEQ
            (BOOT::LETT |c| (|-| |x| |y|) BOOT::|NNI;subtractIfCan;2$U;3|)
            (EXIT
               (COND
                  ((|<| |c| 0) (CONS 1 "failed"))
                  ('T (CONS 0 |c|)))) ))) )

*/



/* Code for BOOT::|NNI;subtractIfCan;2$U;3| */

static Lisp_Object MS_CDECL CC_BOOT__NNIUsubtractIfCanU2DUU3(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V53, V54, V55;
    argcheck(nargs, 3, "NNI;subtractIfCan;2$U;3");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|NNI;subtractIfCan;2$U;3|\n");
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
    V54 = V3;
    V55 = V2;
/* end of prologue */
    V53 = V55;
    V53 = difference2(V53, V54);
    nil = C_nil;
    if (exception_pending()) goto V57;
    env = stack[-1];
    stack[0] = V53;
    V54 = stack[0];
    V53 = (Lisp_Object)1; /* 0 */
    V53 = (Lisp_Object)lessp2(V54, V53);
    nil = C_nil;
    if (exception_pending()) goto V57;
    V53 = V53 ? lisp_true : nil;
    env = stack[-1];
    if (V53 == nil) goto V24;
    V53 = (Lisp_Object)17; /* 1 */
    V54 = elt(env, 1); /* "failed" */
    popv(2);
    { Lisp_Object retVal = cons(V53, V54);
    errexit();
    return onevalue(retVal); }

V24:
    V53 = lisp_true;
    if (V53 == nil) goto V42;
    V54 = (Lisp_Object)1; /* 0 */
    V53 = stack[0];
    popv(2);
    { Lisp_Object retVal = cons(V54, V53);
    errexit();
    return onevalue(retVal); }

V42:
    V53 = nil;
    { popv(2); return onevalue(V53); }
/* error exit handlers */
V57:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|SMP;-;2$;24| (|p| |$|)
   (COND
      ((BOOT::QEQCAR |p| 0)
         (CONS 0 (BOOT:SPADCALL (QCDR |p|) (VMLISP:QREFELT |$| 83))))
      ('T
         (CONS
            1
            (CONS
               (QCAR (QCDR |p|))
               (BOOT:SPADCALL
                  (QCDR (QCDR |p|))
                  (VMLISP:QREFELT |$| 84)))) )))

*/



/* Code for BOOT::|SMP;-;2$;24| */

static Lisp_Object CC_BOOT__SMPUKU2DU24(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V93, V94, V95;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SMP;-;2$;24|\n");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    V94 = V3;
    stack[-1] = V2;
/* end of prologue */
    V93 = stack[-1];
    V95 = qcar(V93);
    V93 = (Lisp_Object)1; /* 0 */
    V93 = Leql(nil, V95, V93);
    env = stack[-3];
    if (V93 == nil) goto V10;
    stack[0] = (Lisp_Object)1; /* 0 */
    V93 = (Lisp_Object)1329; /* 83 */
    V93 = Lgetv(nil, V94, V93);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-3];
    V94 = V93;
    if (!car_legal(V94)) goto V100;
    V95 = qcar(V94);
    V94 = stack[-1];
    V94 = qcdr(V94);
    if (!car_legal(V93)) goto V101;
    V93 = qcdr(V93);
    V93 = Lapply2(nil, 3, V95, V94, V93);
    nil = C_nil;
    if (exception_pending()) goto V99;
    {
        Lisp_Object V102 = stack[0];
        popv(4);
        { Lisp_Object retVal = cons(V102, V93);
        errexit();
        return onevalue(retVal); }
    }

V10:
    V93 = lisp_true;
    if (V93 == nil) goto V53;
    stack[-2] = (Lisp_Object)17; /* 1 */
    V93 = stack[-1];
    V93 = qcdr(V93);
    stack[0] = qcar(V93);
    V93 = (Lisp_Object)1345; /* 84 */
    V93 = Lgetv(nil, V94, V93);
    nil = C_nil;
    if (exception_pending()) goto V99;
    env = stack[-3];
    V94 = V93;
    if (!car_legal(V94)) goto V100;
    V95 = qcar(V94);
    V94 = stack[-1];
    V94 = qcdr(V94);
    V94 = qcdr(V94);
    if (!car_legal(V93)) goto V101;
    V93 = qcdr(V93);
    V93 = Lapply2(nil, 3, V95, V94, V93);
    nil = C_nil;
    if (exception_pending()) goto V99;
    {
        Lisp_Object V103 = stack[-2];
        Lisp_Object V104 = stack[0];
        popv(4);
        { Lisp_Object retVal = list2star(V103, V104, V93);
        errexit();
        return onevalue(retVal); }
    }

V53:
    V93 = nil;
    { popv(4); return onevalue(V93); }
/* error exit handlers */
V101:
    popv(4);
    return error(1, err_bad_cdr, V93);
V100:
    popv(4);
    return error(1, err_bad_car, V94);
V99:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|SUP;fmecg;$NniR2$;29| (BOOT::|p1| |e| |r| BOOT::|p2| |$|)
   (PROG (BOOT::|tm| #:G113048 BOOT::|e2| BOOT::|c2| |u| BOOT::|rout|)
      (RETURN
         (SEQ
            (BOOT::LETT BOOT::|rout| NIL BOOT::|SUP;fmecg;$NniR2$;29|)
            (BOOT::LETT
               |r|
               (BOOT:SPADCALL |r| (VMLISP:QREFELT |$| 102))
               BOOT::|SUP;fmecg;$NniR2$;29|)
            (SEQ
               (BOOT::LETT BOOT::|tm| NIL BOOT::|SUP;fmecg;$NniR2$;29|)
               (BOOT::LETT
                  #:G113048
                  BOOT::|p2|
                  BOOT::|SUP;fmecg;$NniR2$;29|)
               BOOT::G190
               (COND
                  ((OR
                      (ATOM #:G113048)
                      (PROGN
                         (BOOT::LETT
                            BOOT::|tm|
                            (CAR #:G113048)
                            BOOT::|SUP;fmecg;$NniR2$;29|)
                         NIL))
                     (GO BOOT::G191)))
               (SEQ
                  (BOOT::LETT
                     BOOT::|e2|
                     (|+| |e| (QCAR BOOT::|tm|))
                     BOOT::|SUP;fmecg;$NniR2$;29|)
                  (BOOT::LETT
                     BOOT::|c2|
                     (BOOT:SPADCALL
                        |r|
                        (QCDR BOOT::|tm|)
                        (VMLISP:QREFELT |$| 44))
                     BOOT::|SUP;fmecg;$NniR2$;29|)
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
                                       BOOT::|SUP;fmecg;$NniR2$;29|)
                                    (EXIT
                                       (BOOT::LETT
                                          BOOT::|p1|
                                          (CDR BOOT::|p1|)
                                          BOOT::|SUP;fmecg;$NniR2$;29|)))
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
                                          BOOT::|SUP;fmecg;$NniR2$;29|))))
                              (SEQ
                                 (BOOT::LETT
                                    |u|
                                    (BOOT:SPADCALL
                                       (QCDR
                                          (BOOT::|SPADfirst| BOOT::|p1|))
                                       BOOT::|c2|
                                       (VMLISP:QREFELT |$| 46))
                                    BOOT::|SUP;fmecg;$NniR2$;29|)
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
                                       BOOT::|SUP;fmecg;$NniR2$;29|)))) )
                              (EXIT
                                 (BOOT::LETT
                                    BOOT::|p1|
                                    (CDR BOOT::|p1|)
                                    BOOT::|SUP;fmecg;$NniR2$;29|)))) )))
               (BOOT::LETT
                  #:G113048
                  (CDR #:G113048)
                  BOOT::|SUP;fmecg;$NniR2$;29|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT (NRECONC BOOT::|rout| BOOT::|p1|)))) ))

*/



/* Code for BOOT::|SUP;fmecg;$NniR2$;29| */

static Lisp_Object MS_CDECL CC_BOOT__SUPUfmecgUDNniR2DU29(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5,
                         Lisp_Object V6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V380, V381, V382, V383;
    Lisp_Object fn;
    argcheck(nargs, 5, "SUP;fmecg;$NniR2$;29");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|SUP;fmecg;$NniR2$;29|\n");
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
    stack[0] = V5;
    stack[-6] = V4;
    stack[-7] = V3;
    stack[-8] = V2;
/* end of prologue */
    V380 = nil;
    stack[-3] = V380;
    V381 = stack[-5];
    V380 = (Lisp_Object)1633; /* 102 */
    V380 = Lgetv(nil, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    V381 = V380;
    if (!car_legal(V381)) goto V396;
    V382 = qcar(V381);
    V381 = stack[-6];
    if (!car_legal(V380)) goto V397;
    V380 = qcdr(V380);
    V380 = Lapply2(nil, 3, V382, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    stack[-6] = V380;
    V380 = stack[0];
    stack[-9] = V380;
    goto V47;

V47:
    V380 = stack[-9];
    if (!consp(V380)) goto V372;
    V380 = stack[-9];
    if (!car_legal(V380)) goto V398;
    V380 = qcar(V380);
    stack[0] = V380;
    V380 = nil;
    if (!(V380 == nil)) goto V372;
    V381 = stack[-7];
    V380 = stack[0];
    V380 = qcar(V380);
    V380 = plus2(V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    stack[-4] = V380;
    V381 = stack[-5];
    V380 = (Lisp_Object)705; /* 44 */
    V380 = Lgetv(nil, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    V381 = V380;
    if (!car_legal(V381)) goto V396;
    V383 = qcar(V381);
    V382 = stack[-6];
    V381 = stack[0];
    V381 = qcdr(V381);
    if (!car_legal(V380)) goto V397;
    V380 = qcdr(V380);
    V380 = Lapply3(nil, 4, V383, V382, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    stack[-10] = V380;
    V381 = stack[-5];
    V380 = (Lisp_Object)721; /* 45 */
    V380 = Lgetv(nil, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    stack[-2] = V380;
    V380 = stack[-2];
    if (!car_legal(V380)) goto V398;
    stack[-1] = qcar(V380);
    stack[0] = stack[-10];
    V381 = stack[-5];
    V380 = (Lisp_Object)609; /* 38 */
    V380 = Lgetv(nil, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    V381 = V380;
    if (!car_legal(V381)) goto V396;
    V381 = qcar(V381);
    if (!car_legal(V380)) goto V397;
    V380 = qcdr(V380);
    V380 = Lapply1(nil, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    V381 = V380;
    V380 = stack[-2];
    if (!car_legal(V380)) goto V397;
    V380 = qcdr(V380);
    V380 = Lapply3(nil, 4, stack[-1], stack[0], V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    if (!(V380 == nil)) goto V62;
    V380 = lisp_true;
    if (!(V380 == nil)) goto V159;

V62:
    V380 = stack[-9];
    if (!car_legal(V380)) goto V397;
    V380 = qcdr(V380);
    stack[-9] = V380;
    goto V47;

V159:
    V380 = stack[-8];
    if (V380 == nil) goto V167;
    V380 = lisp_true;
    if (V380 == nil) goto V172;
    stack[0] = stack[-4];
    V380 = stack[-8];
    V381 = V380;
    V380 = V381;
    if (V380 == nil) goto V188;
    V380 = V381;
    if (!car_legal(V380)) goto V398;
    V380 = qcar(V380);
    goto V183;

V183:
    V380 = qcar(V380);
    V380 = (Lisp_Object)lessp2(stack[0], V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    V380 = V380 ? lisp_true : nil;
    env = stack[-11];
    goto V166;

V166:
    if (V380 == nil) goto V158;
    V380 = stack[-8];
    V381 = V380;
    V380 = V381;
    if (V380 == nil) goto V209;
    V380 = V381;
    if (!car_legal(V380)) goto V398;
    V380 = qcar(V380);
    goto V207;

V207:
    V381 = V380;
    V380 = stack[-3];
    V380 = cons(V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    stack[-3] = V380;
    V380 = stack[-8];
    if (!car_legal(V380)) goto V397;
    V380 = qcdr(V380);
    stack[-8] = V380;
    goto V159;

V209:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V380 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    goto V207;

V158:
    V380 = stack[-8];
    if (V380 == nil) goto V249;
    V380 = stack[-8];
    V381 = V380;
    V380 = V381;
    if (V380 == nil) goto V241;
    V380 = V381;
    if (!car_legal(V380)) goto V398;
    V380 = qcar(V380);
    goto V236;

V236:
    V381 = qcar(V380);
    V380 = stack[-4];
    V380 = (Lisp_Object)lessp2(V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    V380 = V380 ? lisp_true : nil;
    env = stack[-11];
    if (!(V380 == nil)) goto V249;
    V381 = stack[-5];
    V380 = (Lisp_Object)737; /* 46 */
    V380 = Lgetv(nil, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    stack[-1] = V380;
    V380 = stack[-1];
    if (!car_legal(V380)) goto V398;
    stack[0] = qcar(V380);
    V380 = stack[-8];
    V381 = V380;
    V380 = V381;
    if (V380 == nil) goto V291;
    V380 = V381;
    if (!car_legal(V380)) goto V398;
    V380 = qcar(V380);
    goto V286;

V286:
    V382 = qcdr(V380);
    V381 = stack[-10];
    V380 = stack[-1];
    if (!car_legal(V380)) goto V397;
    V380 = qcdr(V380);
    V380 = Lapply3(nil, 4, stack[0], V382, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    stack[-10] = V380;
    V381 = stack[-5];
    V380 = (Lisp_Object)721; /* 45 */
    V380 = Lgetv(nil, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    stack[-2] = V380;
    V380 = stack[-2];
    if (!car_legal(V380)) goto V398;
    stack[-1] = qcar(V380);
    stack[0] = stack[-10];
    V381 = stack[-5];
    V380 = (Lisp_Object)609; /* 38 */
    V380 = Lgetv(nil, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    V381 = V380;
    if (!car_legal(V381)) goto V396;
    V381 = qcar(V381);
    if (!car_legal(V380)) goto V397;
    V380 = qcdr(V380);
    V380 = Lapply1(nil, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    V381 = V380;
    V380 = stack[-2];
    if (!car_legal(V380)) goto V397;
    V380 = qcdr(V380);
    V380 = Lapply3(nil, 4, stack[-1], stack[0], V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    if (!(V380 == nil)) goto V260;
    V382 = stack[-4];
    V381 = stack[-10];
    V380 = stack[-3];
    V380 = acons(V382, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    stack[-3] = V380;
    goto V260;

V260:
    V380 = stack[-8];
    if (!car_legal(V380)) goto V397;
    V380 = qcdr(V380);
    stack[-8] = V380;
    goto V62;

V291:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V380 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    goto V286;

V249:
    V382 = stack[-4];
    V381 = stack[-10];
    V380 = stack[-3];
    V380 = acons(V382, V381, V380);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    stack[-3] = V380;
    goto V62;

V241:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V380 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    goto V236;

V188:
    fn = elt(env, 2); /* BOOT::FIRST-ERROR */
    V380 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V395;
    env = stack[-11];
    goto V183;

V172:
    V380 = nil;
    goto V166;

V167:
    V380 = nil;
    goto V166;

V372:
    V381 = stack[-3];
    V380 = stack[-8];
    {
        popv(12);
        fn = elt(env, 3); /* NRECONC */
        return (*qfn2(fn))(qenv(fn), V381, V380);
    }
/* error exit handlers */
V398:
    popv(12);
    return error(1, err_bad_car, V380);
V397:
    popv(12);
    return error(1, err_bad_cdr, V380);
V396:
    popv(12);
    return error(1, err_bad_car, V381);
V395:
    popv(12);
    return nil;
}

/*
(DEFUN BOOT::|evalMm| (BOOT::|op| BOOT::|tar| BOOT::|sig| BOOT::|mmC|)
   (PROG (BOOT::SL |m| BOOT::|dc| |t| BOOT::|args| BOOT::|mS|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET BOOT::|mS| NIL)
               (DO ((#:G18964
                      (BOOT::|evalMmStack| BOOT::|mmC|)
                      (CDR #:G18964))
                     (BOOT::|st| NIL))
                  ((OR
                      (ATOM #:G18964)
                      (PROGN (SETQ BOOT::|st| (CAR #:G18964)) NIL))
                     NIL)
                  (SEQ
                     (EXIT
                        (PROGN
                           (BOOT:SPADLET
                              BOOT::SL
                              (BOOT::|evalMmCond|
                                 BOOT::|op|
                                 BOOT::|sig|
                                 BOOT::|st|))
                           (COND
                              ((NULL (EQ BOOT::SL 'BOOT::|failed|))
                                 (PROGN
                                    (BOOT:SPADLET
                                       BOOT::SL
                                       (BOOT::|fixUpTypeArgs| BOOT::SL))
                                    (BOOT:SPADLET
                                       BOOT::|sig|
                                       (PROG (#:G18968)
                                          (BOOT:SPADLET #:G18968 NIL)
                                          (RETURN
                                             (DO ((#:G18969
                                                    BOOT::|sig|
                                                    (CDR #:G18969))
                                                   (|x| NIL))
                                                ((OR
                                                    (ATOM #:G18969)
                                                    (PROGN
        (SETQ |x| (CAR #:G18969))
                                                       NIL))
                                                   (NREVERSE0 #:G18968))
                                                (SEQ
                                                   (EXIT
        (SETQ #:G18968
        (CONS
           (BOOT::|subCopy|
  (BOOT::|deepSubCopy| |x| BOOT::SL) BOOT::|$Subst|) #:G18968)))) ))) )
                                    (COND
                                       ((NULL
                                  (BOOT::|containsVars| BOOT::|sig|))
                                          (COND
                                    ((AND
             (BOOT::|isFreeFunctionFromMmCond| BOOT::|mmC|)
                                                 (BOOT:SPADLET
                                           |m|
                                     (BOOT::|evalMmFreeFunction|
                                                    BOOT::|op|
                                                    BOOT::|tar|
                                                 BOOT::|sig|
                                              BOOT::|mmC|)))
                                                (BOOT:SPADLET
                                                   BOOT::|mS|
                                 (NCONC |m| BOOT::|mS|)))
                                             ((PROG (#:G18965)
                                                 (BOOT:SPADLET
                                                    #:G18965
                                                    NIL)
                                                 (RETURN
                                                    (DO ((#:G18966
         NIL #:G18965)
        (#:G18967 BOOT::|sig| (CDR #:G18967))
        (BOOT::|arg| NIL))
        ((OR
         #:G18966
         (ATOM #:G18967) (PROGN (SETQ BOOT::|arg| (CAR #:G18967)) NIL))
        #:G18965)
        (SEQ
        (EXIT
           (SETQ #:G18965
              (OR #:G18965 (NULL (BOOT::|isValidType| BOOT::|arg|)))) ))) ))
                                                NIL)
                                             ('T
                                                (BOOT:SPADLET
                                                   BOOT::|dc|
                                                   (CAR BOOT::|sig|))
                                                (BOOT:SPADLET
                                                   |t|
                                                   (CADR BOOT::|sig|))
                                                (BOOT:SPADLET
                                                   BOOT::|args|
                                                   (CDDR BOOT::|sig|))
                                                (COND
                                                   ((OR
                                                       BOOT::|$Coerce|
        (NULL BOOT::|tar|)
        (BOOT:|BOOT-EQUAL| BOOT::|tar| |t|))
  (BOOT:SPADLET
     BOOT::|mS|
        (NCONC
        (BOOT::|findFunctionInDomain| BOOT::|op| BOOT::|dc| |t| BOOT::|args|
              BOOT::|args| NIL 'T) BOOT::|mS|)))) ))) ))) ))) ))
               BOOT::|mS|)))) )

*/



/* Code for BOOT::|evalMm| */

static Lisp_Object MS_CDECL CC_BOOT__evalMm(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V278, V279, V280, V281, V282, V283, V284;
    Lisp_Object fn;
    argcheck(nargs, 4, "evalMm");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|evalMm|\n");
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
    V278 = nil;
    stack[-2] = V278;
    V278 = stack[-3];
    fn = elt(env, 4); /* BOOT::|evalMmStack| */
    V278 = (*qfn1(fn))(qenv(fn), V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    stack[-1] = V278;
    goto V27;

V27:
    V278 = stack[-1];
    if (!consp(V278)) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    V278 = stack[-1];
    if (!car_legal(V278)) goto V294;
    V278 = qcar(V278);
    V279 = nil;
    if (!(V279 == nil)) { Lisp_Object res = stack[-2]; popv(9); return onevalue(res); }
    V280 = stack[-6];
    V279 = stack[-4];
    fn = elt(env, 5); /* BOOT::|evalMmCond| */
    V278 = (*qfnn(fn))(qenv(fn), 3, V280, V279, V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    stack[-7] = V278;
    V279 = stack[-7];
    V278 = elt(env, 1); /* BOOT::|failed| */
    if (V279 == V278) goto V41;
    V278 = stack[-7];
    fn = elt(env, 6); /* BOOT::|fixUpTypeArgs| */
    V278 = (*qfn1(fn))(qenv(fn), V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    stack[-7] = V278;
    V278 = nil;
    stack[0] = V278;
    V278 = stack[-4];
    stack[-4] = V278;
    goto V76;

V76:
    V278 = stack[-4];
    if (!consp(V278)) goto V79;
    V278 = stack[-4];
    if (!car_legal(V278)) goto V294;
    V278 = qcar(V278);
    V279 = V278;
    V278 = nil;
    if (!(V278 == nil)) goto V79;
    V278 = stack[-7];
    fn = elt(env, 7); /* BOOT::|deepSubCopy| */
    V279 = (*qfn2(fn))(qenv(fn), V279, V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    V278 = qvalue(elt(env, 2)); /* BOOT::|$Subst| */
    fn = elt(env, 8); /* BOOT::|subCopy| */
    V279 = (*qfn2(fn))(qenv(fn), V279, V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    V278 = stack[0];
    V278 = cons(V279, V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    stack[0] = V278;
    V278 = stack[-4];
    if (!car_legal(V278)) goto V295;
    V278 = qcdr(V278);
    stack[-4] = V278;
    goto V76;

V79:
    V278 = stack[0];
    fn = elt(env, 9); /* NREVERSE0 */
    V278 = (*qfn1(fn))(qenv(fn), V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    stack[-4] = V278;
    V278 = stack[-4];
    fn = elt(env, 10); /* BOOT::|containsVars| */
    V278 = (*qfn1(fn))(qenv(fn), V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    if (!(V278 == nil)) goto V41;
    V278 = stack[-3];
    fn = elt(env, 11); /* BOOT::|isFreeFunctionFromMmCond| */
    V278 = (*qfn1(fn))(qenv(fn), V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    if (V278 == nil) goto V131;
    V281 = stack[-6];
    V280 = stack[-5];
    V279 = stack[-4];
    V278 = stack[-3];
    fn = elt(env, 12); /* BOOT::|evalMmFreeFunction| */
    V278 = (*qfnn(fn))(qenv(fn), 4, V281, V280, V279, V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    V279 = V278;
    if (V278 == nil) goto V131;
    V278 = stack[-2];
    V278 = Lnconc(nil, V279, V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    stack[-2] = V278;
    goto V41;

V41:
    V278 = stack[-1];
    if (!car_legal(V278)) goto V295;
    V278 = qcdr(V278);
    stack[-1] = V278;
    goto V27;

V131:
    V278 = nil;
    V280 = V278;
    V279 = stack[-4];
    V278 = nil;
    stack[0] = V279;
    V279 = V278;
    goto V172;

V172:
    V278 = V279;
    if (!(V278 == nil)) goto V175;
    V278 = stack[0];
    if (!consp(V278)) goto V175;
    V278 = stack[0];
    if (!car_legal(V278)) goto V294;
    V278 = qcar(V278);
    V279 = V278;
    V278 = nil;
    if (!(V278 == nil)) goto V175;
    V278 = V280;
    if (!(V278 == nil)) goto V190;
    V278 = V279;
    fn = elt(env, 13); /* BOOT::|isValidType| */
    V278 = (*qfn1(fn))(qenv(fn), V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    V278 = (V278 == nil ? lisp_true : nil);
    goto V190;

V190:
    V280 = V278;
    V278 = V280;
    V279 = V278;
    V278 = stack[0];
    if (!car_legal(V278)) goto V295;
    V278 = qcdr(V278);
    stack[0] = V278;
    goto V172;

V175:
    V278 = V280;
    if (!(V278 == nil)) goto V41;
    V278 = lisp_true;
    if (V278 == nil) goto V41;
    V278 = stack[-4];
    if (!car_legal(V278)) goto V294;
    V278 = qcar(V278);
    V281 = V278;
    V278 = stack[-4];
    if (!car_legal(V278)) goto V295;
    V278 = qcdr(V278);
    if (!car_legal(V278)) goto V294;
    V278 = qcar(V278);
    V280 = V278;
    V278 = stack[-4];
    if (!car_legal(V278)) goto V295;
    V278 = qcdr(V278);
    if (!car_legal(V278)) goto V295;
    V278 = qcdr(V278);
    V279 = qvalue(elt(env, 3)); /* BOOT::|$Coerce| */
    if (!(V279 == nil)) goto V245;
    V279 = stack[-5];
    if (V279 == nil) goto V245;
    V282 = stack[-5];
    V279 = V280;
    V279 = (cl_equal(V282, V279) ? lisp_true : nil);
    if (V279 == nil) goto V41;
    else goto V245;

V245:
    V284 = stack[-6];
    V283 = V281;
    V282 = V280;
    V281 = V278;
    V280 = V278;
    V279 = nil;
    V278 = lisp_true;
    fn = elt(env, 14); /* BOOT::|findFunctionInDomain| */
    V279 = (*qfnn(fn))(qenv(fn), 7, V284, V283, V282, V281, V280, V279, V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    V278 = stack[-2];
    V278 = Lnconc(nil, V279, V278);
    nil = C_nil;
    if (exception_pending()) goto V293;
    env = stack[-8];
    stack[-2] = V278;
    goto V41;
/* error exit handlers */
V295:
    popv(9);
    return error(1, err_bad_cdr, V278);
V294:
    popv(9);
    return error(1, err_bad_car, V278);
V293:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|COMPLEX;one?;$B;9| (|x| |$|)
   (COND
      ((BOOT:SPADCALL (QCAR |x|) (VMLISP:QREFELT |$| 34))
         (BOOT:SPADCALL (QCDR |x|) (VMLISP:QREFELT |$| 32)))
      ('T 'NIL)))

*/



/* Code for BOOT::|COMPLEX;one?;$B;9| */

static Lisp_Object CC_BOOT__COMPLEXUoneWUDBU9(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V65, V66, V67;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPLEX;one?;$B;9|\n");
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
    V65 = (Lisp_Object)545; /* 34 */
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
(DEFUN BOOT::|FLAGG-;sort!;2A;8| (|l| |$|)
   (BOOT:SPADCALL (ELT |$| 13) |l| (VMLISP:QREFELT |$| 26)))

*/



/* Code for BOOT::|FLAGG-;sort!;2A;8| */

static Lisp_Object CC_BOOT__FLAGGKUsortBU2AU8(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V41, V42, V43;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FLAGG-;sort!;2A;8|\n");
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
    V41 = (Lisp_Object)417; /* 26 */
    V41 = Lgetv(nil, V42, V41);
    nil = C_nil;
    if (exception_pending()) goto V48;
    env = stack[-4];
    stack[-3] = V41;
    V41 = stack[-3];
    if (!car_legal(V41)) goto V49;
    stack[0] = qcar(V41);
    V42 = stack[-1];
    V41 = (Lisp_Object)209; /* 13 */
    fn = elt(env, 1); /* ELT */
    V43 = (*qfn2(fn))(qenv(fn), V42, V41);
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
(DEFUN BOOT::|object2String| (|x|)
   (COND
      ((STRINGP |x|) |x|)
      ((VMLISP:IDENTP |x|) (SYSTEM::PNAME |x|))
      ((NULL |x|) (VMLISP:MAKESTRING ""))
      ((PAIRP |x|)
         (VMLISP:STRCONC
            (BOOT::|object2String| (CAR |x|))
            (BOOT::|object2String| (CDR |x|))))
      ('T (|WRITE-TO-STRING| |x|))))

*/



/* Code for BOOT::|object2String| */

static Lisp_Object CC_BOOT__object2String(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V52;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|object2String|\n");
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
    V52 = stack[0];
    V52 = Lstringp(nil, V52);
    env = stack[-2];
    if (!(V52 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    V52 = stack[0];
    if (V52 == nil) goto V17;
    V52 = stack[0];
    fn = elt(env, 2); /* SYMBOLP */
    V52 = (*qfn1(fn))(qenv(fn), V52);
    nil = C_nil;
    if (exception_pending()) goto V55;
    env = stack[-2];
    goto V16;

V16:
    if (V52 == nil) goto V14;
    V52 = stack[0];
    {
        popv(3);
        fn = elt(env, 3); /* SYSTEM::PNAME */
        return (*qfn1(fn))(qenv(fn), V52);
    }

V14:
    V52 = stack[0];
    if (V52 == nil) goto V27;
    V52 = stack[0];
    fn = elt(env, 4); /* CONSP */
    V52 = (*qfn1(fn))(qenv(fn), V52);
    nil = C_nil;
    if (exception_pending()) goto V55;
    env = stack[-2];
    if (V52 == nil) goto V32;
    V52 = stack[0];
    if (!car_legal(V52)) goto V56;
    V52 = qcar(V52);
    stack[-1] = CC_BOOT__object2String(env, V52);
    nil = C_nil;
    if (exception_pending()) goto V55;
    env = stack[-2];
    V52 = stack[0];
    if (!car_legal(V52)) goto V57;
    V52 = qcdr(V52);
    V52 = CC_BOOT__object2String(env, V52);
    nil = C_nil;
    if (exception_pending()) goto V55;
    env = stack[-2];
    {
        Lisp_Object V58 = stack[-1];
        popv(3);
        fn = elt(env, 5); /* VMLISP:CONCAT */
        return (*qfn2(fn))(qenv(fn), V58, V52);
    }

V32:
    V52 = lisp_true;
    if (V52 == nil) goto V48;
    V52 = stack[0];
    {
        popv(3);
        fn = elt(env, 6); /* WRITE-TO-STRING-1 */
        return (*qfn1(fn))(qenv(fn), V52);
    }

V48:
    V52 = nil;
    { popv(3); return onevalue(V52); }

V27:
    V52 = elt(env, 1); /* "" */
    { popv(3); return onevalue(V52); }

V17:
    V52 = nil;
    goto V16;
/* error exit handlers */
V57:
    popv(3);
    return error(1, err_bad_cdr, V52);
V56:
    popv(3);
    return error(1, err_bad_car, V52);
V55:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|FRAC;coerce;S$;1| (|d| |$|)
   (CONS |d| (BOOT::|spadConstant| |$| 9)))

*/



/* Code for BOOT::|FRAC;coerce;S$;1| */

static Lisp_Object CC_BOOT__FRACUcoerceUSDU1(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FRAC;coerce;S$;1|\n");
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
    V35 = (Lisp_Object)145; /* 9 */
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
(DEFUN BOOT::|COMPCAT-;*;R2S;18| (|r| |x| |$|)
   (BOOT:SPADCALL
      (BOOT:SPADCALL
         |r|
         (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 24))
         (VMLISP:QREFELT |$| 106))
      (BOOT:SPADCALL
         |r|
         (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 92))
         (VMLISP:QREFELT |$| 106))
      (VMLISP:QREFELT |$| 30)))

*/



/* Code for BOOT::|COMPCAT-;*;R2S;18| */

static Lisp_Object MS_CDECL CC_BOOT__COMPCATKUHUR2SU18(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V133, V134, V135;
    argcheck(nargs, 3, "COMPCAT-;*;R2S;18");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|COMPCAT-;*;R2S;18|\n");
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
    V134 = stack[-4];
    V133 = (Lisp_Object)481; /* 30 */
    V133 = Lgetv(nil, V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-8];
    stack[-7] = V133;
    V133 = stack[-7];
    if (!car_legal(V133)) goto V145;
    stack[-3] = qcar(V133);
    V134 = stack[-4];
    V133 = (Lisp_Object)1697; /* 106 */
    V133 = Lgetv(nil, V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-8];
    stack[-2] = V133;
    V133 = stack[-2];
    if (!car_legal(V133)) goto V145;
    stack[-1] = qcar(V133);
    stack[0] = stack[-6];
    V134 = stack[-4];
    V133 = (Lisp_Object)385; /* 24 */
    V133 = Lgetv(nil, V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-8];
    V134 = V133;
    if (!car_legal(V134)) goto V146;
    V135 = qcar(V134);
    V134 = stack[-5];
    if (!car_legal(V133)) goto V147;
    V133 = qcdr(V133);
    V133 = Lapply2(nil, 3, V135, V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-8];
    V134 = V133;
    V133 = stack[-2];
    if (!car_legal(V133)) goto V147;
    V133 = qcdr(V133);
    V133 = Lapply3(nil, 4, stack[-1], stack[0], V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-8];
    stack[-2] = V133;
    V134 = stack[-4];
    V133 = (Lisp_Object)1697; /* 106 */
    V133 = Lgetv(nil, V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-8];
    stack[-1] = V133;
    V133 = stack[-1];
    if (!car_legal(V133)) goto V145;
    stack[0] = qcar(V133);
    V134 = stack[-4];
    V133 = (Lisp_Object)1473; /* 92 */
    V133 = Lgetv(nil, V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-8];
    V134 = V133;
    if (!car_legal(V134)) goto V146;
    V135 = qcar(V134);
    V134 = stack[-5];
    if (!car_legal(V133)) goto V147;
    V133 = qcdr(V133);
    V133 = Lapply2(nil, 3, V135, V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V144;
    env = stack[-8];
    V134 = V133;
    V133 = stack[-1];
    if (!car_legal(V133)) goto V147;
    V133 = qcdr(V133);
    V133 = Lapply3(nil, 4, stack[0], stack[-6], V134, V133);
    nil = C_nil;
    if (exception_pending()) goto V144;
    V134 = V133;
    V133 = stack[-7];
    if (!car_legal(V133)) goto V147;
    V133 = qcdr(V133);
    {
        Lisp_Object V148 = stack[-3];
        Lisp_Object V149 = stack[-2];
        popv(9);
        return Lapply3(nil, 4, V148, V149, V134, V133);
    }
/* error exit handlers */
V147:
    popv(9);
    return error(1, err_bad_cdr, V133);
V146:
    popv(9);
    return error(1, err_bad_car, V134);
V145:
    popv(9);
    return error(1, err_bad_car, V133);
V144:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|EXPR;*;3$;11| (|x| |y| |$|)
   (BOOT::|EXPR;reduc|
      (BOOT:SPADCALL |x| |y| (VMLISP:QREFELT |$| 34))
      (BOOT::|EXPR;commonk| |x| |y| |$|)
      |$|))

*/



/* Code for BOOT::|EXPR;*;3$;11| */

static Lisp_Object MS_CDECL CC_BOOT__EXPRUHU3DU11(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V55, V56, V57, V58;
    Lisp_Object fn;
    argcheck(nargs, 3, "EXPR;*;3$;11");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;*;3$;11|\n");
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
    V55 = (Lisp_Object)545; /* 34 */
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
(DEFUN BOOT::|IIARRAY2;qelt;$2IR;10| (|m| |i| |j| |$|)
   (ELT
      (ELT |m| (|-| |i| (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 24))))
      (|-| |j| (BOOT:SPADCALL |m| (VMLISP:QREFELT |$| 25)))) )

*/



/* Code for BOOT::|IIARRAY2;qelt;$2IR;10| */

static Lisp_Object MS_CDECL CC_BOOT__IIARRAY2UqeltUD2IRU10(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V84, V85, V86;
    Lisp_Object fn;
    argcheck(nargs, 4, "IIARRAY2;qelt;$2IR;10");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IIARRAY2;qelt;$2IR;10|\n");
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
    stack[-1] = V5;
    stack[-2] = V4;
    V84 = V3;
    stack[-3] = V2;
/* end of prologue */
    stack[-4] = stack[-3];
    stack[0] = V84;
    V85 = stack[-1];
    V84 = (Lisp_Object)385; /* 24 */
    V84 = Lgetv(nil, V85, V84);
    nil = C_nil;
    if (exception_pending()) goto V92;
    env = stack[-5];
    V85 = V84;
    if (!car_legal(V85)) goto V93;
    V86 = qcar(V85);
    V85 = stack[-3];
    if (!car_legal(V84)) goto V94;
    V84 = qcdr(V84);
    V84 = Lapply2(nil, 3, V86, V85, V84);
    nil = C_nil;
    if (exception_pending()) goto V92;
    env = stack[-5];
    V84 = difference2(stack[0], V84);
    nil = C_nil;
    if (exception_pending()) goto V92;
    env = stack[-5];
    fn = elt(env, 1); /* ELT */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[-4], V84);
    nil = C_nil;
    if (exception_pending()) goto V92;
    env = stack[-5];
    V85 = stack[-1];
    V84 = (Lisp_Object)401; /* 25 */
    V84 = Lgetv(nil, V85, V84);
    nil = C_nil;
    if (exception_pending()) goto V92;
    env = stack[-5];
    V85 = V84;
    if (!car_legal(V85)) goto V93;
    V86 = qcar(V85);
    V85 = stack[-3];
    if (!car_legal(V84)) goto V94;
    V84 = qcdr(V84);
    V84 = Lapply2(nil, 3, V86, V85, V84);
    nil = C_nil;
    if (exception_pending()) goto V92;
    env = stack[-5];
    V84 = difference2(stack[-2], V84);
    nil = C_nil;
    if (exception_pending()) goto V92;
    env = stack[-5];
    {
        Lisp_Object V95 = stack[0];
        popv(6);
        fn = elt(env, 1); /* ELT */
        return (*qfn2(fn))(qenv(fn), V95, V84);
    }
/* error exit handlers */
V94:
    popv(6);
    return error(1, err_bad_cdr, V84);
V93:
    popv(6);
    return error(1, err_bad_car, V85);
V92:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|ALIST;keys;$L;6| (|t| |$|)
   (PROG (#:G102919 |k| #:G102920)
      (RETURN
         (SEQ
            (PROGN
               (BOOT::LETT #:G102919 NIL BOOT::|ALIST;keys;$L;6|)
               (SEQ
                  (BOOT::LETT |k| NIL BOOT::|ALIST;keys;$L;6|)
                  (BOOT::LETT
                     #:G102920
                     (BOOT:SPADCALL |t| (VMLISP:QREFELT |$| 14))
                     BOOT::|ALIST;keys;$L;6|)
                  BOOT::G190
                  (COND
                     ((OR
                         (ATOM #:G102920)
                         (PROGN
                            (BOOT::LETT
                               |k|
                               (CAR #:G102920)
                               BOOT::|ALIST;keys;$L;6|)
                            NIL))
                        (GO BOOT::G191)))
                  (SEQ
                     (EXIT
                        (BOOT::LETT
                           #:G102919
                           (CONS (QCAR |k|) #:G102919)
                           BOOT::|ALIST;keys;$L;6|)))
                  (BOOT::LETT
                     #:G102920
                     (CDR #:G102920)
                     BOOT::|ALIST;keys;$L;6|)
                  (GO BOOT::G190)
                  BOOT::G191
                  (EXIT (NREVERSE0 #:G102919)))) ))) )

*/



/* Code for BOOT::|ALIST;keys;$L;6| */

static Lisp_Object CC_BOOT__ALISTUkeysUDLU6(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V72, V73, V74;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ALIST;keys;$L;6|\n");
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
    V73 = V3;
    stack[0] = V2;
/* end of prologue */
    V72 = nil;
    stack[-1] = V72;
    V72 = (Lisp_Object)225; /* 14 */
    V72 = Lgetv(nil, V73, V72);
    nil = C_nil;
    if (exception_pending()) goto V77;
    env = stack[-2];
    V73 = V72;
    if (!car_legal(V73)) goto V78;
    V74 = qcar(V73);
    V73 = stack[0];
    if (!car_legal(V72)) goto V79;
    V72 = qcdr(V72);
    V72 = Lapply2(nil, 3, V74, V73, V72);
    nil = C_nil;
    if (exception_pending()) goto V77;
    env = stack[-2];
    stack[0] = V72;
    goto V17;

V17:
    V72 = stack[0];
    if (!consp(V72)) goto V18;
    V72 = stack[0];
    if (!car_legal(V72)) goto V80;
    V72 = qcar(V72);
    V73 = V72;
    V72 = nil;
    if (!(V72 == nil)) goto V18;
    V72 = V73;
    V73 = qcar(V72);
    V72 = stack[-1];
    V72 = cons(V73, V72);
    nil = C_nil;
    if (exception_pending()) goto V77;
    env = stack[-2];
    stack[-1] = V72;
    V72 = stack[0];
    if (!car_legal(V72)) goto V79;
    V72 = qcdr(V72);
    stack[0] = V72;
    goto V17;

V18:
    V72 = stack[-1];
    {
        popv(3);
        fn = elt(env, 1); /* NREVERSE0 */
        return (*qfn1(fn))(qenv(fn), V72);
    }
/* error exit handlers */
V80:
    popv(3);
    return error(1, err_bad_car, V72);
V79:
    popv(3);
    return error(1, err_bad_cdr, V72);
V78:
    popv(3);
    return error(1, err_bad_car, V73);
V77:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|isEqualOrSubDomain| (BOOT::|d1| BOOT::|d2|)
   (PROG (BOOT::|ISTMP#1|)
      (RETURN
         (OR
            (BOOT:|BOOT-EQUAL| BOOT::|d1| BOOT::|d2|)
            (BOOT::|isSubDomain| BOOT::|d1| BOOT::|d2|)
            (AND
               (ATOM BOOT::|d1|)
               (OR
                  (AND
                     (PAIRP BOOT::|d2|)
                     (EQ (QCAR BOOT::|d2|) 'BOOT::|Variable|)
                     (PROGN
                        (BOOT:SPADLET BOOT::|ISTMP#1| (QCDR BOOT::|d2|))
                        (AND
                           (PAIRP BOOT::|ISTMP#1|)
                           (EQ (QCDR BOOT::|ISTMP#1|) NIL)
                           (EQUAL (QCAR BOOT::|ISTMP#1|) BOOT::|d1|))))
                  (AND
                     (PAIRP BOOT::|d2|)
                     (EQ (QCDR BOOT::|d2|) NIL)
                     (EQUAL (QCAR BOOT::|d2|) BOOT::|d1|))))
            (AND
               (ATOM BOOT::|d2|)
               (OR
                  (AND
                     (PAIRP BOOT::|d1|)
                     (EQ (QCAR BOOT::|d1|) 'BOOT::|Variable|)
                     (PROGN
                        (BOOT:SPADLET BOOT::|ISTMP#1| (QCDR BOOT::|d1|))
                        (AND
                           (PAIRP BOOT::|ISTMP#1|)
                           (EQ (QCDR BOOT::|ISTMP#1|) NIL)
                           (EQUAL (QCAR BOOT::|ISTMP#1|) BOOT::|d2|))))
                  (AND
                     (PAIRP BOOT::|d1|)
                     (EQ (QCDR BOOT::|d1|) NIL)
                     (EQUAL (QCAR BOOT::|d1|) BOOT::|d2|)))) ))) )

*/



/* Code for BOOT::|isEqualOrSubDomain| */

static Lisp_Object CC_BOOT__isEqualOrSubDomain(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V189, V190;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|isEqualOrSubDomain|\n");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V190 = stack[-1];
    V189 = stack[0];
    V189 = (cl_equal(V190, V189) ? lisp_true : nil);
    if (!(V189 == nil)) { popv(4); return onevalue(V189); }
    V190 = stack[-1];
    V189 = stack[0];
    fn = elt(env, 2); /* BOOT::|isSubDomain| */
    V189 = (*qfn2(fn))(qenv(fn), V190, V189);
    nil = C_nil;
    if (exception_pending()) goto V194;
    env = stack[-3];
    if (!(V189 == nil)) { popv(4); return onevalue(V189); }
    V189 = stack[-1];
    if (!consp(V189)) goto V37;
    V189 = nil;
    goto V32;

V32:
    if (!(V189 == nil)) { popv(4); return onevalue(V189); }
    V189 = stack[0];
    if (!consp(V189)) goto V116;
    V189 = nil;
    { popv(4); return onevalue(V189); }

V116:
    V189 = stack[-1];
    fn = elt(env, 3); /* CONSP */
    V189 = (*qfn1(fn))(qenv(fn), V189);
    nil = C_nil;
    if (exception_pending()) goto V194;
    env = stack[-3];
    if (V189 == nil) goto V123;
    V189 = stack[-1];
    V190 = qcar(V189);
    V189 = elt(env, 1); /* BOOT::|Variable| */
    if (V190 == V189) goto V139;
    V189 = nil;
    goto V122;

V122:
    if (!(V189 == nil)) { popv(4); return onevalue(V189); }
    V189 = stack[-1];
    fn = elt(env, 3); /* CONSP */
    V189 = (*qfn1(fn))(qenv(fn), V189);
    nil = C_nil;
    if (exception_pending()) goto V194;
    if (V189 == nil) goto V168;
    V189 = stack[-1];
    V189 = qcdr(V189);
    if (V189 == nil) goto V180;
    V189 = nil;
    { popv(4); return onevalue(V189); }

V180:
    V189 = stack[-1];
    V190 = qcar(V189);
    V189 = stack[0];
    V189 = (cl_equal(V190, V189) ? lisp_true : nil);
    { popv(4); return onevalue(V189); }

V168:
    V189 = nil;
    { popv(4); return onevalue(V189); }

V139:
    V189 = stack[-1];
    V189 = qcdr(V189);
    stack[-2] = V189;
    V189 = stack[-2];
    fn = elt(env, 3); /* CONSP */
    V189 = (*qfn1(fn))(qenv(fn), V189);
    nil = C_nil;
    if (exception_pending()) goto V194;
    env = stack[-3];
    if (V189 == nil) goto V145;
    V189 = stack[-2];
    V189 = qcdr(V189);
    if (V189 == nil) goto V157;
    V189 = nil;
    goto V122;

V157:
    V189 = stack[-2];
    V190 = qcar(V189);
    V189 = stack[0];
    V189 = (cl_equal(V190, V189) ? lisp_true : nil);
    goto V122;

V145:
    V189 = nil;
    goto V122;

V123:
    V189 = nil;
    goto V122;

V37:
    V189 = stack[0];
    fn = elt(env, 3); /* CONSP */
    V189 = (*qfn1(fn))(qenv(fn), V189);
    nil = C_nil;
    if (exception_pending()) goto V194;
    env = stack[-3];
    if (V189 == nil) goto V44;
    V189 = stack[0];
    V190 = qcar(V189);
    V189 = elt(env, 1); /* BOOT::|Variable| */
    if (V190 == V189) goto V60;
    V189 = nil;
    goto V43;

V43:
    if (!(V189 == nil)) goto V32;
    V189 = stack[0];
    fn = elt(env, 3); /* CONSP */
    V189 = (*qfn1(fn))(qenv(fn), V189);
    nil = C_nil;
    if (exception_pending()) goto V194;
    env = stack[-3];
    if (V189 == nil) goto V89;
    V189 = stack[0];
    V189 = qcdr(V189);
    if (V189 == nil) goto V101;
    V189 = nil;
    goto V32;

V101:
    V189 = stack[0];
    V190 = qcar(V189);
    V189 = stack[-1];
    V189 = (cl_equal(V190, V189) ? lisp_true : nil);
    goto V32;

V89:
    V189 = nil;
    goto V32;

V60:
    V189 = stack[0];
    V189 = qcdr(V189);
    stack[-2] = V189;
    V189 = stack[-2];
    fn = elt(env, 3); /* CONSP */
    V189 = (*qfn1(fn))(qenv(fn), V189);
    nil = C_nil;
    if (exception_pending()) goto V194;
    env = stack[-3];
    if (V189 == nil) goto V66;
    V189 = stack[-2];
    V189 = qcdr(V189);
    if (V189 == nil) goto V78;
    V189 = nil;
    goto V43;

V78:
    V189 = stack[-2];
    V190 = qcar(V189);
    V189 = stack[-1];
    V189 = (cl_equal(V190, V189) ? lisp_true : nil);
    goto V43;

V66:
    V189 = nil;
    goto V43;

V44:
    V189 = nil;
    goto V43;
/* error exit handlers */
V194:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|hashString| (BOOT::|str|)
   (PROG (|j| |h|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET |h| 0)
               (DO ((#:G18875 (BOOT:SPADDIFFERENCE (|#| BOOT::|str|) 1))
                     (|i| 0 (VMLISP:QSADD1 |i|)))
                  ((VMLISP:QSGREATERP |i| #:G18875) NIL)
                  (SEQ
                     (EXIT
                        (PROGN
                           (BOOT:SPADLET
                              |j|
                              (|CHAR-CODE|
                                 (BOOT:|char| (ELT BOOT::|str| |i|))))
                           (BOOT:SPADLET |h| (LOGXOR |h| (ASH |h| 8)))
                           (BOOT:SPADLET |h| (PLUS (PLUS |h| |j|) 200041))
                           (BOOT:SPADLET |h| (LOGAND |h| 1073741823)))) ))
               (REM |h| BOOT::|$hashModulus|)))) ))

*/



/* Code for BOOT::|hashString| */

static Lisp_Object CC_BOOT__hashString(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V103, V104;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|hashString|\n");
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
    V103 = (Lisp_Object)1; /* 0 */
    stack[-3] = V103;
    stack[0] = (Lisp_Object)1; /* 0 */
    V103 = stack[-4];
    fn = elt(env, 3); /* VMLISP:SIZE */
    V103 = (*qfn1(fn))(qenv(fn), V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    V103 = sub1(V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    stack[-2] = stack[0];
    stack[-1] = V103;
    goto V27;

V27:
    V104 = stack[-2];
    V103 = stack[-1];
    V103 = (Lisp_Object)greaterp2(V104, V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    V103 = V103 ? lisp_true : nil;
    env = stack[-6];
    if (V103 == nil) goto V41;
    V104 = stack[-3];
    V103 = qvalue(elt(env, 2)); /* BOOT::|$hashModulus| */
    {
        popv(7);
        fn = elt(env, 4); /* REM */
        return (*qfn2(fn))(qenv(fn), V104, V103);
    }

V41:
    V104 = stack[-4];
    V103 = stack[-2];
    fn = elt(env, 5); /* ELT */
    V103 = (*qfn2(fn))(qenv(fn), V104, V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    fn = elt(env, 6); /* CHARACTER */
    V103 = (*qfn1(fn))(qenv(fn), V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    V103 = Lchar_code(nil, V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    stack[-5] = V103;
    stack[0] = stack[-3];
    V104 = stack[-3];
    V103 = (Lisp_Object)129; /* 8 */
    V103 = Lash1(nil, V104, V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    fn = elt(env, 7); /* LOGXOR */
    V103 = (*qfn2(fn))(qenv(fn), stack[0], V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    stack[-3] = V103;
    V104 = stack[-3];
    V103 = stack[-5];
    V104 = plus2(V104, V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    V103 = (Lisp_Object)3200657; /* 200041 */
    V103 = plus2(V104, V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    stack[-3] = V103;
    V104 = stack[-3];
    V103 = elt(env, 1); /* 1073741823 */
    fn = elt(env, 8); /* LOGAND */
    V103 = (*qfn2(fn))(qenv(fn), V104, V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    stack[-3] = V103;
    V103 = stack[-2];
    V103 = add1(V103);
    nil = C_nil;
    if (exception_pending()) goto V111;
    env = stack[-6];
    stack[-2] = V103;
    goto V27;
/* error exit handlers */
V111:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|EXPR;reduc| (|x| |l| |$|)
   (PROG (|k| #:G82512 |p|)
      (RETURN
         (SEQ
            (SEQ
               (BOOT::LETT |k| NIL BOOT::|EXPR;reduc|)
               (BOOT::LETT #:G82512 |l| BOOT::|EXPR;reduc|)
               BOOT::G190
               (COND
                  ((OR
                      (ATOM #:G82512)
                      (PROGN
                         (BOOT::LETT |k| (CAR #:G82512) BOOT::|EXPR;reduc|)
                         NIL))
                     (GO BOOT::G191)))
               (SEQ
                  (BOOT::LETT
                     |p|
                     (BOOT:SPADCALL |k| (VMLISP:QREFELT |$| 262))
                     BOOT::|EXPR;reduc|)
                  (EXIT
                     (BOOT::LETT
                        |x|
                        (BOOT:SPADCALL
                           (BOOT::|EXPR;evl|
                              (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 80))
                              |k|
                              |p|
                              |$|)
                           (BOOT::|EXPR;evl|
                              (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 82))
                              |k|
                              |p|
                              |$|)
                           (VMLISP:QREFELT |$| 40))
                        BOOT::|EXPR;reduc|)))
               (BOOT::LETT #:G82512 (CDR #:G82512) BOOT::|EXPR;reduc|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT |x|)))) )

*/



/* Code for BOOT::|EXPR;reduc| */

static Lisp_Object MS_CDECL CC_BOOT__EXPRUreduc(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V163, V164, V165, V166;
    Lisp_Object fn;
    argcheck(nargs, 3, "EXPR;reduc");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;reduc|\n");
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
    V163 = V3;
    stack[-6] = V2;
/* end of prologue */
    stack[-4] = V163;
    goto V17;

V17:
    V163 = stack[-4];
    if (!consp(V163)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    V163 = stack[-4];
    if (!car_legal(V163)) goto V175;
    V163 = qcar(V163);
    stack[-7] = V163;
    V163 = nil;
    if (!(V163 == nil)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    V164 = stack[-5];
    V163 = (Lisp_Object)4193; /* 262 */
    V163 = Lgetv(nil, V164, V163);
    nil = C_nil;
    if (exception_pending()) goto V176;
    env = stack[-8];
    V164 = V163;
    if (!car_legal(V164)) goto V177;
    V165 = qcar(V164);
    V164 = stack[-7];
    if (!car_legal(V163)) goto V178;
    V163 = qcdr(V163);
    V163 = Lapply2(nil, 3, V165, V164, V163);
    nil = C_nil;
    if (exception_pending()) goto V176;
    env = stack[-8];
    stack[-3] = V163;
    V164 = stack[-5];
    V163 = (Lisp_Object)641; /* 40 */
    V163 = Lgetv(nil, V164, V163);
    nil = C_nil;
    if (exception_pending()) goto V176;
    env = stack[-8];
    stack[-2] = V163;
    V163 = stack[-2];
    if (!car_legal(V163)) goto V175;
    stack[-1] = qcar(V163);
    V164 = stack[-5];
    V163 = (Lisp_Object)1281; /* 80 */
    V163 = Lgetv(nil, V164, V163);
    nil = C_nil;
    if (exception_pending()) goto V176;
    env = stack[-8];
    V164 = V163;
    if (!car_legal(V164)) goto V177;
    V165 = qcar(V164);
    V164 = stack[-6];
    if (!car_legal(V163)) goto V178;
    V163 = qcdr(V163);
    V163 = Lapply2(nil, 3, V165, V164, V163);
    nil = C_nil;
    if (exception_pending()) goto V176;
    env = stack[-8];
    V166 = V163;
    V165 = stack[-7];
    V164 = stack[-3];
    V163 = stack[-5];
    fn = elt(env, 1); /* BOOT::|EXPR;evl| */
    stack[0] = (*qfnn(fn))(qenv(fn), 4, V166, V165, V164, V163);
    nil = C_nil;
    if (exception_pending()) goto V176;
    env = stack[-8];
    V164 = stack[-5];
    V163 = (Lisp_Object)1313; /* 82 */
    V163 = Lgetv(nil, V164, V163);
    nil = C_nil;
    if (exception_pending()) goto V176;
    env = stack[-8];
    V164 = V163;
    if (!car_legal(V164)) goto V177;
    V165 = qcar(V164);
    V164 = stack[-6];
    if (!car_legal(V163)) goto V178;
    V163 = qcdr(V163);
    V163 = Lapply2(nil, 3, V165, V164, V163);
    nil = C_nil;
    if (exception_pending()) goto V176;
    env = stack[-8];
    V166 = V163;
    V165 = stack[-7];
    V164 = stack[-3];
    V163 = stack[-5];
    fn = elt(env, 1); /* BOOT::|EXPR;evl| */
    V164 = (*qfnn(fn))(qenv(fn), 4, V166, V165, V164, V163);
    nil = C_nil;
    if (exception_pending()) goto V176;
    env = stack[-8];
    V163 = stack[-2];
    if (!car_legal(V163)) goto V178;
    V163 = qcdr(V163);
    V163 = Lapply3(nil, 4, stack[-1], stack[0], V164, V163);
    nil = C_nil;
    if (exception_pending()) goto V176;
    env = stack[-8];
    stack[-6] = V163;
    V163 = stack[-4];
    if (!car_legal(V163)) goto V178;
    V163 = qcdr(V163);
    stack[-4] = V163;
    goto V17;
/* error exit handlers */
V178:
    popv(9);
    return error(1, err_bad_cdr, V163);
V177:
    popv(9);
    return error(1, err_bad_car, V164);
V176:
    popv(9);
    return nil;
V175:
    popv(9);
    return error(1, err_bad_car, V163);
}

/*
(DEFUN BOOT:ELEMN (X N DEFAULT)
   (COND
      ((NULL X) DEFAULT)
      ((EQL N 1) (CAR X))
      ((BOOT:ELEMN (CDR X) (SUB1 N) DEFAULT))))

*/



/* Code for BOOT:ELEMN */

static Lisp_Object MS_CDECL CC_BOOT__ELEMN(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V41, V42, V43, V44;
    argcheck(nargs, 3, "ELEMN");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT:ELEMN\n");
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
    V42 = V3;
    V43 = V2;
/* end of prologue */
    V41 = V43;
    if (V41 == nil) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    V44 = V42;
    V41 = (Lisp_Object)17; /* 1 */
    V41 = Leql(nil, V44, V41);
    env = stack[-2];
    if (V41 == nil) goto V29;
    V41 = V43;
    if (!car_legal(V41)) goto V47;
    V41 = qcar(V41);
    { popv(3); return onevalue(V41); }

V29:
    V41 = V43;
    if (!car_legal(V41)) goto V48;
    stack[-1] = qcdr(V41);
    V41 = V42;
    V42 = sub1(V41);
    nil = C_nil;
    if (exception_pending()) goto V49;
    env = stack[-2];
    V41 = stack[0];
    V41 = CC_BOOT__ELEMN(env, 3, stack[-1], V42, V41);
    nil = C_nil;
    if (exception_pending()) goto V49;
    if (!(V41 == nil)) { popv(3); return onevalue(V41); }
    V41 = nil;
    { popv(3); return onevalue(V41); }
/* error exit handlers */
V49:
    popv(3);
    return nil;
V48:
    popv(3);
    return error(1, err_bad_cdr, V41);
V47:
    popv(3);
    return error(1, err_bad_car, V41);
}

/*
(DEFUN BOOT::|MDDFACT;reduction!0| (BOOT::|#1| BOOT::|$$|)
   (BOOT:SPADCALL
      BOOT::|#1|
      (VMLISP:QREFELT BOOT::|$$| 1)
      (VMLISP:QREFELT (VMLISP:QREFELT BOOT::|$$| 0) 8)))

*/



/* Code for BOOT::|MDDFACT;reduction!0| */

static Lisp_Object CC_BOOT__MDDFACTUreductionB0(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V48, V49;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|MDDFACT;reduction!0|\n");
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
    V49 = stack[-1];
    V48 = (Lisp_Object)1; /* 0 */
    V49 = Lgetv(nil, V49, V48);
    nil = C_nil;
    if (exception_pending()) goto V54;
    env = stack[-4];
    V48 = (Lisp_Object)129; /* 8 */
    V48 = Lgetv(nil, V49, V48);
    nil = C_nil;
    if (exception_pending()) goto V54;
    env = stack[-4];
    stack[-3] = V48;
    V48 = stack[-3];
    if (!car_legal(V48)) goto V55;
    stack[0] = qcar(V48);
    V49 = stack[-1];
    V48 = (Lisp_Object)17; /* 1 */
    V49 = Lgetv(nil, V49, V48);
    nil = C_nil;
    if (exception_pending()) goto V54;
    V48 = stack[-3];
    if (!car_legal(V48)) goto V56;
    V48 = qcdr(V48);
    {
        Lisp_Object V57 = stack[0];
        Lisp_Object V58 = stack[-2];
        popv(5);
        return Lapply3(nil, 4, V57, V58, V49, V48);
    }
/* error exit handlers */
V56:
    popv(5);
    return error(1, err_bad_cdr, V48);
V55:
    popv(5);
    return error(1, err_bad_car, V48);
V54:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|HDP;<;2$B;1| (BOOT::|v1| BOOT::|v2| |$|)
   (PROG (#:G82736 BOOT::|n1| BOOT::|n2| |i| #:G82735)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (BOOT::LETT
                     BOOT::|n1|
                     (BOOT::|spadConstant| |$| 9)
                     BOOT::|HDP;<;2$B;1|)
                  (BOOT::LETT
                     BOOT::|n2|
                     (BOOT::|spadConstant| |$| 9)
                     BOOT::|HDP;<;2$B;1|)
                  (SEQ
                     (BOOT::LETT |i| 1 BOOT::|HDP;<;2$B;1|)
                     (BOOT::LETT
                        #:G82736
                        (VMLISP:QREFELT |$| 6)
                        BOOT::|HDP;<;2$B;1|)
                     BOOT::G190
                     (COND
                        ((VMLISP:QSGREATERP |i| #:G82736) (GO BOOT::G191)))
                     (SEQ
                        (BOOT::LETT
                           BOOT::|n1|
                           (BOOT:SPADCALL
                              BOOT::|n1|
                              (BOOT:SPADCALL
                                 BOOT::|v1|
                                 |i|
                                 (VMLISP:QREFELT |$| 11))
                              (VMLISP:QREFELT |$| 12))
                           BOOT::|HDP;<;2$B;1|)
                        (EXIT
                           (BOOT::LETT
                              BOOT::|n2|
                              (BOOT:SPADCALL
                                 BOOT::|n2|
                                 (BOOT:SPADCALL
                                    BOOT::|v2|
                                    |i|
                                    (VMLISP:QREFELT |$| 11))
                                 (VMLISP:QREFELT |$| 12))
                              BOOT::|HDP;<;2$B;1|)))
                     (BOOT::LETT
                        |i|
                        (VMLISP:QSADD1 |i|)
                        BOOT::|HDP;<;2$B;1|)
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT NIL))
                  (EXIT
                     (COND
                        ((BOOT:SPADCALL
                            BOOT::|n1|
                            BOOT::|n2|
                            (VMLISP:QREFELT |$| 14))
                           'T)
                        ((BOOT:SPADCALL
                            BOOT::|n2|
                            BOOT::|n1|
                            (VMLISP:QREFELT |$| 14))
                           'NIL)
                        ('T
                           (SEQ
                              (SEQ
                                 (BOOT::LETT
                                    |i|
                                    (VMLISP:QREFELT |$| 6)
                                    BOOT::|HDP;<;2$B;1|)
                                 BOOT::G190
                                 (COND ((|<| |i| 1) (GO BOOT::G191)))
                                 (SEQ
                                    (COND
                                       ((BOOT:SPADCALL
                                           (BOOT:SPADCALL
                                              BOOT::|v2|
                                              |i|
                                              (VMLISP:QREFELT |$| 11))
                                           (BOOT:SPADCALL
                                              BOOT::|v1|
                                              |i|
                                              (VMLISP:QREFELT |$| 11))
                                           (VMLISP:QREFELT |$| 14))
                                          (PROGN
                                             (BOOT::LETT
                                                #:G82735
                                                'T
                                                BOOT::|HDP;<;2$B;1|)
                                             (GO #:G82735))))
                                    (EXIT
                                       (COND
                                          ((BOOT:SPADCALL
                                              (BOOT:SPADCALL
                                                 BOOT::|v1|
                                                 |i|
                                                 (VMLISP:QREFELT |$| 11))
                                              (BOOT:SPADCALL
                                                 BOOT::|v2|
                                                 |i|
                                                 (VMLISP:QREFELT |$| 11))
                                              (VMLISP:QREFELT |$| 14))
                                             (PROGN
                                                (BOOT::LETT
                                                   #:G82735
                                                   'NIL
                                                   BOOT::|HDP;<;2$B;1|)
                                                (GO #:G82735)))) ))
                                 (BOOT::LETT
                                    |i|
                                    (|+| |i| -1)
                                    BOOT::|HDP;<;2$B;1|)
                                 (GO BOOT::G190)
                                 BOOT::G191
                                 (EXIT NIL))
                              (EXIT 'NIL)))) )))
            #:G82735
            (EXIT #:G82735)))) )

*/



/* Code for BOOT::|HDP;<;2$B;1| */

static Lisp_Object MS_CDECL CC_BOOT__HDPURU2DBU1(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V471, V472, V473, V474;
    argcheck(nargs, 3, "HDP;<;2$B;1");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|HDP;<;2$B;1|\n");
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
    V472 = stack[-5];
    V471 = (Lisp_Object)145; /* 9 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    if (!car_legal(V472)) goto V485;
    V472 = qcar(V472);
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply1(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[-4] = V471;
    V472 = stack[-5];
    V471 = (Lisp_Object)145; /* 9 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    if (!car_legal(V472)) goto V485;
    V472 = qcar(V472);
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply1(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[0] = V471;
    V471 = (Lisp_Object)17; /* 1 */
    stack[-3] = V471;
    V472 = stack[-5];
    V471 = (Lisp_Object)97; /* 6 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[-8] = V471;
    goto V80;

V80:
    V472 = stack[-3];
    V471 = stack[-8];
    V471 = (Lisp_Object)greaterp2(V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    V471 = V471 ? lisp_true : nil;
    env = stack[-9];
    if (V471 == nil) goto V93;
    V472 = stack[-5];
    V471 = (Lisp_Object)225; /* 14 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    if (!car_legal(V472)) goto V485;
    V474 = qcar(V472);
    V473 = stack[-4];
    V472 = stack[0];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, V474, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    if (V471 == nil) goto V238;
    V471 = lisp_true;
    { popv(10); return onevalue(V471); }

V238:
    V472 = stack[-5];
    V471 = (Lisp_Object)225; /* 14 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    if (!car_legal(V472)) goto V485;
    V474 = qcar(V472);
    V473 = stack[0];
    V472 = stack[-4];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, V474, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    if (V471 == nil) goto V233;
    V471 = nil;
    { popv(10); return onevalue(V471); }

V233:
    V471 = lisp_true;
    if (V471 == nil) goto V263;
    V472 = stack[-5];
    V471 = (Lisp_Object)97; /* 6 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[-3] = V471;
    goto V284;

V284:
    V472 = stack[-3];
    V471 = (Lisp_Object)17; /* 1 */
    V471 = (Lisp_Object)lessp2(V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    V471 = V471 ? lisp_true : nil;
    env = stack[-9];
    if (V471 == nil) goto V301;
    V471 = nil;
    { popv(10); return onevalue(V471); }

V301:
    V472 = stack[-5];
    V471 = (Lisp_Object)225; /* 14 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[-2] = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V487;
    stack[-1] = qcar(V471);
    V472 = stack[-5];
    V471 = (Lisp_Object)177; /* 11 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    if (!car_legal(V472)) goto V485;
    V474 = qcar(V472);
    V473 = stack[-6];
    V472 = stack[-3];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, V474, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[0] = V471;
    V472 = stack[-5];
    V471 = (Lisp_Object)177; /* 11 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    if (!car_legal(V472)) goto V485;
    V474 = qcar(V472);
    V473 = stack[-7];
    V472 = stack[-3];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, V474, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, stack[-1], stack[0], V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    if (V471 == nil) goto V385;
    V471 = lisp_true;
    { popv(10); return onevalue(V471); }

V385:
    V472 = stack[-5];
    V471 = (Lisp_Object)225; /* 14 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[-2] = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V487;
    stack[-1] = qcar(V471);
    V472 = stack[-5];
    V471 = (Lisp_Object)177; /* 11 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    if (!car_legal(V472)) goto V485;
    V474 = qcar(V472);
    V473 = stack[-7];
    V472 = stack[-3];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, V474, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[0] = V471;
    V472 = stack[-5];
    V471 = (Lisp_Object)177; /* 11 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    if (!car_legal(V472)) goto V485;
    V474 = qcar(V472);
    V473 = stack[-6];
    V472 = stack[-3];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, V474, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, stack[-1], stack[0], V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    if (V471 == nil) goto V292;
    V471 = nil;
    { popv(10); return onevalue(V471); }

V292:
    V471 = stack[-3];
    V471 = sub1(V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[-3] = V471;
    goto V284;

V263:
    V471 = nil;
    { popv(10); return onevalue(V471); }

V93:
    V472 = stack[-5];
    V471 = (Lisp_Object)193; /* 12 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[-2] = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V487;
    stack[-1] = qcar(V471);
    V472 = stack[-5];
    V471 = (Lisp_Object)177; /* 11 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    if (!car_legal(V472)) goto V485;
    V474 = qcar(V472);
    V473 = stack[-7];
    V472 = stack[-3];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, V474, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, stack[-1], stack[-4], V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[-4] = V471;
    V472 = stack[-5];
    V471 = (Lisp_Object)193; /* 12 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[-2] = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V487;
    stack[-1] = qcar(V471);
    V472 = stack[-5];
    V471 = (Lisp_Object)177; /* 11 */
    V471 = Lgetv(nil, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    if (!car_legal(V472)) goto V485;
    V474 = qcar(V472);
    V473 = stack[-6];
    V472 = stack[-3];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, V474, V473, V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    V472 = V471;
    V471 = stack[-2];
    if (!car_legal(V471)) goto V486;
    V471 = qcdr(V471);
    V471 = Lapply3(nil, 4, stack[-1], stack[0], V472, V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[0] = V471;
    V471 = stack[-3];
    V471 = add1(V471);
    nil = C_nil;
    if (exception_pending()) goto V484;
    env = stack[-9];
    stack[-3] = V471;
    goto V80;
/* error exit handlers */
V487:
    popv(10);
    return error(1, err_bad_car, V471);
V486:
    popv(10);
    return error(1, err_bad_cdr, V471);
V485:
    popv(10);
    return error(1, err_bad_car, V472);
V484:
    popv(10);
    return nil;
}

/*
(DEFUN BOOT::|stuffDomainSlots| (BOOT::|dollar|)
   (PROG (BOOT::|domname|
         BOOT::|infovec|
         BOOT::|lookupFunction|
         BOOT::|template|
         BOOT::|item|
         BOOT::|proto4|
         BOOT::|bitVector|
         BOOT::|predvec|
         BOOT::|packagevec|
         BOOT::|auxvec|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET
                  BOOT::|domname|
                  (BOOT::|devaluate| BOOT::|dollar|))
               (BOOT:SPADLET
                  BOOT::|infovec|
                  (VMLISP:GETL
                     (BOOT::|opOf| BOOT::|domname|)
                     'BOOT::|infovec|))
               (BOOT:SPADLET
                  BOOT::|lookupFunction|
                  (BOOT::|getLookupFun| BOOT::|infovec|))
               (BOOT:SPADLET
                  BOOT::|lookupFunction|
                  (COND
                     ((BOOT:|BOOT-EQUAL|
                         BOOT::|lookupFunction|
                         'BOOT::|lookupIncomplete|)
                        (BOOT:|function| BOOT::|lookupIncomplete|))
                     ('T (BOOT:|function| BOOT::|lookupComplete|))))
               (BOOT:SPADLET BOOT::|template| (ELT BOOT::|infovec| 0))
               (COND
                  ((ELT BOOT::|template| 5)
                     (BOOT::|stuffSlot|
                        BOOT::|dollar|
                        5
                        (ELT BOOT::|template| 5))))
               (DO ((#:G18893 (VMLISP:MAXINDEX BOOT::|template|))
                     (|i|
                        (PLUS 6 (|#| (CDR BOOT::|domname|)))
                        (|+| |i| 1)))
                  ((|>| |i| #:G18893) NIL)
                  (SEQ
                     (EXIT
                        (COND
                           ((BOOT:SPADLET
                               BOOT::|item|
                               (ELT BOOT::|template| |i|))
                              (BOOT::|stuffSlot|
                                 BOOT::|dollar|
                                 |i|
                                 BOOT::|item|)))) ))
               (SETELT
                  BOOT::|dollar|
                  1
                  (LIST
                     BOOT::|lookupFunction|
                     BOOT::|dollar|
                     (ELT BOOT::|infovec| 1)))
               (SETELT BOOT::|dollar| 2 (ELT BOOT::|infovec| 2))
               (BOOT:SPADLET BOOT::|proto4| (ELT BOOT::|infovec| 3))
               (SETELT
                  BOOT::|dollar|
                  4
                  (COND
                     ((VMLISP:VECP (CDDR BOOT::|proto4|))
                        (CONS
                           (|COPY-SEQ| (CAR BOOT::|proto4|))
                           (CDR BOOT::|proto4|)))
                     ('T
                        (BOOT:SPADLET
                           BOOT::|bitVector|
                           (ELT BOOT::|dollar| 3))
                        (BOOT:SPADLET BOOT::|predvec| (CAR BOOT::|proto4|))
                        (BOOT:SPADLET
                           BOOT::|packagevec|
                           (CADR BOOT::|proto4|))
                        (BOOT:SPADLET
                           BOOT::|auxvec|
                           (VMLISP:LIST2VEC
                              (PROG (#:G18891)
                                 (BOOT:SPADLET #:G18891 NIL)
                                 (RETURN
                                    (DO ((#:G18892
                                           (VMLISP:MAXINDEX
                                              BOOT::|predvec|))
                                          (|i| 0 (VMLISP:QSADD1 |i|)))
                                       ((VMLISP:QSGREATERP |i| #:G18892)
                                          (NREVERSE0 #:G18891))
                                       (SEQ
                                          (EXIT
                                             (SETQ #:G18891
                                                (CONS
                                                   (COND
        ((NULL
         (BOOT::|testBitVector|
            BOOT::|bitVector| (ELT BOOT::|predvec| |i|))) NIL)
        ('T (OR (ELT BOOT::|packagevec| |i|) 'T)))
                                                #:G18891)))) ))) ))
                        (CONS
                           BOOT::|auxvec|
                           (CDDR BOOT::|proto4|)))) ))) )))

*/



/* Code for BOOT::|stuffDomainSlots| */

static Lisp_Object CC_BOOT__stuffDomainSlots(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V345, V346, V347;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|stuffDomainSlots|\n");
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
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = V2;
/* end of prologue */
    V345 = stack[-2];
    fn = elt(env, 4); /* BOOT::|devaluate| */
    V345 = (*qfn1(fn))(qenv(fn), V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-6] = V345;
    V345 = stack[-6];
    fn = elt(env, 5); /* BOOT::|opOf| */
    V346 = (*qfn1(fn))(qenv(fn), V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    V345 = elt(env, 1); /* BOOT::|infovec| */
    fn = elt(env, 6); /* VMLISP:GETL */
    V345 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-5] = V345;
    V345 = stack[-5];
    fn = elt(env, 7); /* BOOT::|getLookupFun| */
    V345 = (*qfn1(fn))(qenv(fn), V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-4] = V345;
    V346 = stack[-4];
    V345 = elt(env, 2); /* BOOT::|lookupIncomplete| */
    V345 = (V346 == V345 ? lisp_true : nil);
    if (V345 == nil) goto V36;
    V345 = elt(env, 2); /* BOOT::|lookupIncomplete| */
    goto V34;

V34:
    stack[-4] = V345;
    V346 = stack[-5];
    V345 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 8); /* ELT */
    V345 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-3] = V345;
    V346 = stack[-3];
    V345 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 8); /* ELT */
    V345 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    if (V345 == nil) goto V91;
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)81; /* 5 */
    V346 = stack[-3];
    V345 = (Lisp_Object)81; /* 5 */
    fn = elt(env, 8); /* ELT */
    V345 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    fn = elt(env, 9); /* BOOT::|stuffSlot| */
    V345 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    goto V91;

V91:
    stack[0] = (Lisp_Object)97; /* 6 */
    V345 = stack[-6];
    if (!car_legal(V345)) goto V359;
    V345 = qcdr(V345);
    fn = elt(env, 10); /* VMLISP:SIZE */
    V345 = (*qfn1(fn))(qenv(fn), V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[0] = plus2(stack[0], V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    V345 = stack[-3];
    V345 = Llength(nil, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    V345 = sub1(V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-1] = stack[0];
    stack[0] = V345;
    goto V111;

V111:
    V346 = stack[-1];
    V345 = stack[0];
    V345 = (Lisp_Object)greaterp2(V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    V345 = V345 ? lisp_true : nil;
    env = stack[-10];
    if (V345 == nil) goto V127;
    stack[-3] = stack[-2];
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = stack[-2];
    V346 = stack[-5];
    V345 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 8); /* ELT */
    V345 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    V345 = ncons(V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    V345 = list2star(stack[-4], stack[0], V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    fn = elt(env, 11); /* SETELT */
    V345 = (*qfnn(fn))(qenv(fn), 3, stack[-3], stack[-1], V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-1] = stack[-2];
    stack[0] = (Lisp_Object)33; /* 2 */
    V346 = stack[-5];
    V345 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 8); /* ELT */
    V345 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    fn = elt(env, 11); /* SETELT */
    V345 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[0], V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    V346 = stack[-5];
    V345 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 8); /* ELT */
    V345 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-9] = V345;
    stack[-5] = stack[-2];
    stack[-4] = (Lisp_Object)65; /* 4 */
    V345 = stack[-9];
    if (!car_legal(V345)) goto V359;
    V345 = qcdr(V345);
    if (!car_legal(V345)) goto V359;
    V345 = qcdr(V345);
    fn = elt(env, 12); /* SIMPLE-VECTOR-P */
    V345 = (*qfn1(fn))(qenv(fn), V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    if (V345 == nil) goto V221;
    V345 = stack[-9];
    if (!car_legal(V345)) goto V360;
    V345 = qcar(V345);
    fn = elt(env, 13); /* COPY-SEQ */
    V346 = (*qfn1(fn))(qenv(fn), V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    V345 = stack[-9];
    if (!car_legal(V345)) goto V359;
    V345 = qcdr(V345);
    V345 = cons(V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    goto V214;

V214:
    {
        Lisp_Object V361 = stack[-5];
        Lisp_Object V362 = stack[-4];
        popv(11);
        fn = elt(env, 11); /* SETELT */
        return (*qfnn(fn))(qenv(fn), 3, V361, V362, V345);
    }

V221:
    V345 = lisp_true;
    if (V345 == nil) goto V238;
    V346 = stack[-2];
    V345 = (Lisp_Object)49; /* 3 */
    fn = elt(env, 8); /* ELT */
    V345 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-8] = V345;
    V345 = stack[-9];
    if (!car_legal(V345)) goto V360;
    V345 = qcar(V345);
    stack[-7] = V345;
    V345 = stack[-9];
    if (!car_legal(V345)) goto V359;
    V345 = qcdr(V345);
    if (!car_legal(V345)) goto V360;
    V345 = qcar(V345);
    stack[-6] = V345;
    V345 = nil;
    stack[-3] = V345;
    stack[0] = (Lisp_Object)1; /* 0 */
    V345 = stack[-7];
    V345 = Llength(nil, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    V345 = sub1(V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-2] = stack[0];
    stack[-1] = V345;
    goto V272;

V272:
    V346 = stack[-2];
    V345 = stack[-1];
    V345 = (Lisp_Object)greaterp2(V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    V345 = V345 ? lisp_true : nil;
    env = stack[-10];
    if (V345 == nil) goto V295;
    V345 = stack[-3];
    fn = elt(env, 14); /* NREVERSE0 */
    V345 = (*qfn1(fn))(qenv(fn), V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    fn = elt(env, 15); /* VMLISP:LIST2VEC */
    V345 = (*qfn1(fn))(qenv(fn), V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    V346 = V345;
    V345 = stack[-9];
    if (!car_legal(V345)) goto V359;
    V345 = qcdr(V345);
    if (!car_legal(V345)) goto V359;
    V345 = qcdr(V345);
    V345 = cons(V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    goto V214;

V295:
    stack[0] = stack[-8];
    V346 = stack[-7];
    V345 = stack[-2];
    fn = elt(env, 8); /* ELT */
    V345 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    fn = elt(env, 16); /* BOOT::|testBitVector| */
    V345 = (*qfn2(fn))(qenv(fn), stack[0], V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    if (V345 == nil) goto V292;
    V345 = lisp_true;
    if (V345 == nil) goto V311;
    V346 = stack[-6];
    V345 = stack[-2];
    fn = elt(env, 8); /* ELT */
    V345 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    if (!(V345 == nil)) goto V314;
    V345 = lisp_true;
    goto V314;

V314:
    V346 = V345;
    goto V287;

V287:
    V345 = stack[-3];
    V345 = cons(V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-3] = V345;
    V345 = stack[-2];
    V345 = add1(V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-2] = V345;
    goto V272;

V311:
    V346 = nil;
    goto V287;

V292:
    V345 = nil;
    V346 = V345;
    goto V287;

V238:
    V345 = nil;
    goto V214;

V127:
    V346 = stack[-3];
    V345 = stack[-1];
    fn = elt(env, 8); /* ELT */
    V346 = (*qfn2(fn))(qenv(fn), V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    V345 = V346;
    if (V346 == nil) goto V121;
    V347 = stack[-2];
    V346 = stack[-1];
    fn = elt(env, 9); /* BOOT::|stuffSlot| */
    V345 = (*qfnn(fn))(qenv(fn), 3, V347, V346, V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    goto V121;

V121:
    V345 = stack[-1];
    V345 = add1(V345);
    nil = C_nil;
    if (exception_pending()) goto V358;
    env = stack[-10];
    stack[-1] = V345;
    goto V111;

V36:
    V345 = lisp_true;
    if (V345 == nil) goto V47;
    V345 = elt(env, 3); /* BOOT::|lookupComplete| */
    goto V34;

V47:
    V345 = nil;
    goto V34;
/* error exit handlers */
V360:
    popv(11);
    return error(1, err_bad_car, V345);
V359:
    popv(11);
    return error(1, err_bad_cdr, V345);
V358:
    popv(11);
    return nil;
}

/*
(DEFUN BOOT::|subspan| (|u|)
   (COND
      ((ATOM |u|) 0)
      ((NUMBERP (CDR |u|)) (BOOT::|subspan| (CAR |u|)))
      ((AND
          (NULL (ATOM (CAR |u|)))
          (ATOM (CAAR |u|))
          (NULL (NUMBERP (CAAR |u|)))
          (VMLISP:GETL (CAAR |u|) 'BOOT::SUBSPAN))
         (VMLISP:APPLX (VMLISP:GETL (CAAR |u|) 'BOOT::SUBSPAN) (LIST |u|)))
      ('T (MAX (BOOT::|subspan| (CAR |u|)) (BOOT::|subspan| (CDR |u|)))) ))

*/



/* Code for BOOT::|subspan| */

static Lisp_Object CC_BOOT__subspan(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V76, V77;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|subspan|\n");
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
    V76 = elt(env, 1); /* BOOT::SUBSPAN */
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
    V76 = elt(env, 1); /* BOOT::SUBSPAN */
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
    stack[-1] = CC_BOOT__subspan(env, V76);
    nil = C_nil;
    if (exception_pending()) goto V82;
    env = stack[-2];
    V76 = stack[0];
    if (!car_legal(V76)) goto V80;
    V76 = qcdr(V76);
    V76 = CC_BOOT__subspan(env, V76);
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
(DEFUN BOOT::|deconstructT| (|t|)
   (PROG (BOOT::|dt| BOOT::|args| |x| |c|)
      (RETURN
         (SEQ
            (COND
               ((AND (BOOT:KDR |t|) (BOOT::|constructor?| (CAR |t|)))
                  (BOOT:SPADLET BOOT::|dt| (BOOT::|destructT| (CAR |t|)))
                  (BOOT:SPADLET
                     BOOT::|args|
                     (PROG (#:G18921)
                        (BOOT:SPADLET #:G18921 NIL)
                        (RETURN
                           (DO ((#:G18922 BOOT::|dt| (CDR #:G18922))
                                 (|d| NIL)
                                 (#:G18923 |t| (CDR #:G18923))
                                 (|y| NIL))
                              ((OR
                                  (ATOM #:G18922)
                                  (PROGN (SETQ |d| (CAR #:G18922)) NIL)
                                  (ATOM #:G18923)
                                  (PROGN (SETQ |y| (CAR #:G18923)) NIL))
                                 (NREVERSE0 #:G18921))
                              (SEQ
                                 (EXIT
                                    (COND
                                       ((BOOT:SPADLET |x| (AND |d| |y|))
                                          (SETQ #:G18921
                                             (CONS |x| #:G18921)))) ))) )))
                  (BOOT:SPADLET
                     |c|
                     (PROG (#:G18918)
                        (BOOT:SPADLET #:G18918 NIL)
                        (RETURN
                           (DO ((#:G18919 BOOT::|dt| (CDR #:G18919))
                                 (|d| NIL)
                                 (#:G18920 |t| (CDR #:G18920))
                                 (|y| NIL))
                              ((OR
                                  (ATOM #:G18919)
                                  (PROGN (SETQ |d| (CAR #:G18919)) NIL)
                                  (ATOM #:G18920)
                                  (PROGN (SETQ |y| (CAR #:G18920)) NIL))
                                 (NREVERSE0 #:G18918))
                              (SEQ
                                 (EXIT
                                    (COND
                                       ((BOOT:SPADLET
                                           |x|
                                           (AND (NULL |d|) |y|))
                                          (SETQ #:G18918
                                             (CONS |x| #:G18918)))) ))) )))
                  (CONS |c| BOOT::|args|))
               ('T (CONS |t| NIL)))) )))

*/



/* Code for BOOT::|deconstructT| */

static Lisp_Object CC_BOOT__deconstructT(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V192, V193, V194, V195;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|deconstructT|\n");
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
    V192 = stack[-2];
    if (!consp(V192)) goto V21;
    V192 = stack[-2];
    V192 = qcdr(V192);
    goto V20;

V20:
    if (V192 == nil) goto V17;
    V192 = stack[-2];
    if (!car_legal(V192)) goto V200;
    V192 = qcar(V192);
    fn = elt(env, 1); /* BOOT::|constructor?| */
    V192 = (*qfn1(fn))(qenv(fn), V192);
    nil = C_nil;
    if (exception_pending()) goto V201;
    env = stack[-4];
    if (V192 == nil) goto V17;
    V192 = stack[-2];
    if (!car_legal(V192)) goto V200;
    V192 = qcar(V192);
    fn = elt(env, 2); /* BOOT::|destructT| */
    V192 = (*qfn1(fn))(qenv(fn), V192);
    nil = C_nil;
    if (exception_pending()) goto V201;
    env = stack[-4];
    stack[-3] = V192;
    V192 = nil;
    V195 = V192;
    V193 = stack[-2];
    V192 = stack[-3];
    stack[-1] = V193;
    stack[0] = V192;
    goto V50;

V50:
    V192 = stack[0];
    if (!consp(V192)) goto V53;
    V192 = stack[0];
    if (!car_legal(V192)) goto V200;
    V192 = qcar(V192);
    V193 = V192;
    V192 = nil;
    if (!(V192 == nil)) goto V53;
    V192 = stack[-1];
    if (!consp(V192)) goto V53;
    V192 = stack[-1];
    if (!car_legal(V192)) goto V200;
    V192 = qcar(V192);
    V194 = V192;
    V192 = nil;
    if (!(V192 == nil)) goto V53;
    V192 = V193;
    if (V192 == nil) goto V78;
    V192 = V194;
    V193 = V192;
    goto V77;

V77:
    V192 = V193;
    if (V193 == nil) goto V71;
    V193 = V195;
    V192 = cons(V192, V193);
    nil = C_nil;
    if (exception_pending()) goto V201;
    env = stack[-4];
    V195 = V192;
    goto V71;

V71:
    V192 = stack[0];
    if (!car_legal(V192)) goto V202;
    V192 = qcdr(V192);
    V193 = stack[-1];
    if (!car_legal(V193)) goto V203;
    V193 = qcdr(V193);
    stack[0] = V192;
    V192 = V193;
    stack[-1] = V192;
    goto V50;

V78:
    V192 = nil;
    V193 = V192;
    goto V77;

V53:
    V192 = V195;
    fn = elt(env, 3); /* NREVERSE0 */
    V192 = (*qfn1(fn))(qenv(fn), V192);
    nil = C_nil;
    if (exception_pending()) goto V201;
    env = stack[-4];
    stack[0] = V192;
    V192 = nil;
    V195 = V192;
    V193 = stack[-2];
    V192 = stack[-3];
    stack[-2] = V193;
    stack[-1] = V192;
    goto V121;

V121:
    V192 = stack[-1];
    if (!consp(V192)) goto V124;
    V192 = stack[-1];
    if (!car_legal(V192)) goto V200;
    V192 = qcar(V192);
    V193 = V192;
    V192 = nil;
    if (!(V192 == nil)) goto V124;
    V192 = stack[-2];
    if (!consp(V192)) goto V124;
    V192 = stack[-2];
    if (!car_legal(V192)) goto V200;
    V192 = qcar(V192);
    V194 = V192;
    V192 = nil;
    if (!(V192 == nil)) goto V124;
    V192 = V193;
    if (V192 == nil) goto V153;
    V192 = nil;
    V193 = V192;
    goto V148;

V148:
    V192 = V193;
    if (V193 == nil) goto V142;
    V193 = V195;
    V192 = cons(V192, V193);
    nil = C_nil;
    if (exception_pending()) goto V201;
    env = stack[-4];
    V195 = V192;
    goto V142;

V142:
    V192 = stack[-1];
    if (!car_legal(V192)) goto V202;
    V192 = qcdr(V192);
    V193 = stack[-2];
    if (!car_legal(V193)) goto V203;
    V193 = qcdr(V193);
    stack[-1] = V192;
    V192 = V193;
    stack[-2] = V192;
    goto V121;

V153:
    V192 = V194;
    V193 = V192;
    goto V148;

V124:
    V192 = V195;
    fn = elt(env, 3); /* NREVERSE0 */
    V192 = (*qfn1(fn))(qenv(fn), V192);
    nil = C_nil;
    if (exception_pending()) goto V201;
    V193 = V192;
    V192 = stack[0];
    popv(5);
    { Lisp_Object retVal = cons(V193, V192);
    errexit();
    return onevalue(retVal); }

V17:
    V192 = lisp_true;
    if (V192 == nil) goto V187;
    V192 = stack[-2];
    popv(5);
    { Lisp_Object retVal = ncons(V192);
    errexit();
    return onevalue(retVal); }

V187:
    V192 = nil;
    { popv(5); return onevalue(V192); }

V21:
    V192 = nil;
    goto V20;
/* error exit handlers */
V203:
    popv(5);
    return error(1, err_bad_cdr, V193);
V202:
    popv(5);
    return error(1, err_bad_cdr, V192);
V201:
    popv(5);
    return nil;
V200:
    popv(5);
    return error(1, err_bad_car, V192);
}



setup_type const u09_setup[] =
{
    {"BOOT@@COMPCAT-;unitNormal;SR;49@@Builtin",too_few_2,CC_BOOT__COMPCATKUunitNormalUSRU49,wrong_no_2},
    {"BOOT@@FLASORT;quickSort;M2V;1@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__FLASORTUquickSortUM2VU1},
    {"BOOT@@NNI;subtractIfCan;2$U;3@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__NNIUsubtractIfCanU2DUU3},
    {"BOOT@@SMP;-;2$;24@@Builtin",too_few_2,    CC_BOOT__SMPUKU2DU24,wrong_no_2},
    {"BOOT@@SUP;fmecg;$NniR2$;29@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__SUPUfmecgUDNniR2DU29},
    {"BOOT@@evalMm@@Builtin",   wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__evalMm},
    {"BOOT@@COMPLEX;one?;$B;9@@Builtin",too_few_2,CC_BOOT__COMPLEXUoneWUDBU9,wrong_no_2},
    {"BOOT@@FLAGG-;sort!;2A;8@@Builtin",too_few_2,CC_BOOT__FLAGGKUsortBU2AU8,wrong_no_2},
    {"BOOT@@object2String@@Builtin",CC_BOOT__object2String,too_many_1,wrong_no_1},
    {"BOOT@@FRAC;coerce;S$;1@@Builtin",too_few_2,CC_BOOT__FRACUcoerceUSDU1,wrong_no_2},
    {"BOOT@@COMPCAT-;*;R2S;18@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__COMPCATKUHUR2SU18},
    {"BOOT@@EXPR;*;3$;11@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__EXPRUHU3DU11},
    {"BOOT@@IIARRAY2;qelt;$2IR;10@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IIARRAY2UqeltUD2IRU10},
    {"BOOT@@ALIST;keys;$L;6@@Builtin",too_few_2,CC_BOOT__ALISTUkeysUDLU6,wrong_no_2},
    {"BOOT@@isEqualOrSubDomain@@Builtin",too_few_2,CC_BOOT__isEqualOrSubDomain,wrong_no_2},
    {"BOOT@@hashString@@Builtin",CC_BOOT__hashString,too_many_1,wrong_no_1},
    {"BOOT@@EXPR;reduc@@Builtin",wrong_no_na,   wrong_no_nb,   (n_args *)CC_BOOT__EXPRUreduc},
    {"BOOT@@ELEMN@@Builtin",    wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__ELEMN},
    {"BOOT@@MDDFACT;reduction!0@@Builtin",too_few_2,CC_BOOT__MDDFACTUreductionB0,wrong_no_2},
    {"BOOT@@HDP;<;2$B;1@@Builtin",wrong_no_na,  wrong_no_nb,   (n_args *)CC_BOOT__HDPURU2DBU1},
    {"BOOT@@stuffDomainSlots@@Builtin",CC_BOOT__stuffDomainSlots,too_many_1,wrong_no_1},
    {"BOOT@@subspan@@Builtin",  CC_BOOT__subspan,too_many_1,   wrong_no_1},
    {"BOOT@@deconstructT@@Builtin",CC_BOOT__deconstructT,too_many_1,wrong_no_1},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
