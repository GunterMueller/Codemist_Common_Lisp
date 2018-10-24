
/* u08.c                 Machine generated C code */

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
(DEFUN BOOT::|PGCD;gcd;3P;15| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (BOOT::|mv1| #:G82524 BOOT::|mv2|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL BOOT::|p1| (VMLISP:QREFELT |$| 76))
                  (SEQ
                     (BOOT::LETT
                        BOOT::|p1|
                        (BOOT:SPADCALL BOOT::|p1| (VMLISP:QREFELT |$| 102))
                        BOOT::|PGCD;gcd;3P;15|)
                     (EXIT
                        (COND
                           ((BOOT:SPADCALL
                               BOOT::|p1|
                               (BOOT::|spadConstant| |$| 40)
                               (VMLISP:QREFELT |$| 83))
                              BOOT::|p1|)
                           ((BOOT:SPADCALL
                               BOOT::|p1|
                               (BOOT::|spadConstant| |$| 103)
                               (VMLISP:QREFELT |$| 83))
                              (BOOT:SPADCALL
                                 BOOT::|p2|
                                 (VMLISP:QREFELT |$| 102)))
                           ('T
                              (COND
                                 ((BOOT:SPADCALL
                                     BOOT::|p2|
                                     (VMLISP:QREFELT |$| 76))
                                    (BOOT:SPADCALL
                                       (BOOT:SPADCALL
                                          (BOOT:SPADCALL
                                             BOOT::|p1|
                                             (VMLISP:QREFELT |$| 95))
                                          (BOOT:SPADCALL
                                             BOOT::|p2|
                                             (VMLISP:QREFELT |$| 95))
                                          (VMLISP:QREFELT |$| 104))
                                       (VMLISP:QREFELT |$| 105)))
                                 ('T
                                    (BOOT::|PGCD;gcdTermList|
                                       BOOT::|p1|
                                       BOOT::|p2|
                                       |$|)))) ))) )
               ((BOOT:SPADCALL BOOT::|p2| (VMLISP:QREFELT |$| 76))
                  (SEQ
                     (BOOT::LETT
                        BOOT::|p2|
                        (BOOT:SPADCALL BOOT::|p2| (VMLISP:QREFELT |$| 102))
                        BOOT::|PGCD;gcd;3P;15|)
                     (EXIT
                        (COND
                           ((BOOT:SPADCALL
                               BOOT::|p2|
                               (BOOT::|spadConstant| |$| 40)
                               (VMLISP:QREFELT |$| 83))
                              BOOT::|p2|)
                           ((BOOT:SPADCALL
                               BOOT::|p2|
                               (BOOT::|spadConstant| |$| 103)
                               (VMLISP:QREFELT |$| 83))
                              (BOOT:SPADCALL
                                 BOOT::|p1|
                                 (VMLISP:QREFELT |$| 102)))
                           ('T
                              (BOOT::|PGCD;gcdTermList|
                                 BOOT::|p2|
                                 BOOT::|p1|
                                 |$|)))) ))
               ('T
                  (SEQ
                     (BOOT::LETT
                        BOOT::|p1|
                        (BOOT:SPADCALL BOOT::|p1| (VMLISP:QREFELT |$| 102))
                        BOOT::|PGCD;gcd;3P;15|)
                     (BOOT::LETT
                        BOOT::|p2|
                        (BOOT:SPADCALL BOOT::|p2| (VMLISP:QREFELT |$| 102))
                        BOOT::|PGCD;gcd;3P;15|)
                     (EXIT
                        (COND
                           ((BOOT:SPADCALL
                               BOOT::|p1|
                               BOOT::|p2|
                               (VMLISP:QREFELT |$| 83))
                              BOOT::|p1|)
                           ('T
                              (SEQ
                                 (BOOT::LETT
                                    BOOT::|mv1|
                                    (PROG2
                                       (BOOT::LETT
                                          #:G82524
                                          (BOOT:SPADCALL
                                             BOOT::|p1|
                                             (VMLISP:QREFELT |$| 78))
                                          BOOT::|PGCD;gcd;3P;15|)
                                       (QCDR #:G82524)
                                       (BOOT::|check-union|
                                          (BOOT::QEQCAR #:G82524 0)
                                          (VMLISP:QREFELT |$| 7)
                                          #:G82524))
                                    BOOT::|PGCD;gcd;3P;15|)
                                 (BOOT::LETT
                                    BOOT::|mv2|
                                    (PROG2
                                       (BOOT::LETT
                                          #:G82524
                                          (BOOT:SPADCALL
                                             BOOT::|p2|
                                             (VMLISP:QREFELT |$| 78))
                                          BOOT::|PGCD;gcd;3P;15|)
                                       (QCDR #:G82524)
                                       (BOOT::|check-union|
                                          (BOOT::QEQCAR #:G82524 0)
                                          (VMLISP:QREFELT |$| 7)
                                          #:G82524))
                                    BOOT::|PGCD;gcd;3P;15|)
                                 (EXIT
                                    (COND
                                       ((BOOT:SPADCALL
                                           BOOT::|mv1|
                                           BOOT::|mv2|
                                           (VMLISP:QREFELT |$| 106))
                                          (BOOT:SPADCALL
                                             (BOOT:SPADCALL
                                                (BOOT:SPADCALL
                                                   BOOT::|p1|
                                                   BOOT::|mv1|
                                                   (VMLISP:QREFELT |$| 81))
                                                (BOOT:SPADCALL
                                                   BOOT::|p2|
                                                   BOOT::|mv1|
                                                   (VMLISP:QREFELT |$| 81))
                                                (VMLISP:QREFELT |$| 48))
                                             BOOT::|mv1|
                                             (VMLISP:QREFELT |$| 107)))
                                       ((BOOT:SPADCALL
                                           BOOT::|mv1|
                                           BOOT::|mv2|
                                           (VMLISP:QREFELT |$| 57))
                                          (BOOT::|PGCD;gcdTermList|
                                             BOOT::|p1|
                                             BOOT::|p2|
                                             |$|))
                                       ('T
                                          (BOOT::|PGCD;gcdTermList|
                                             BOOT::|p2|
                                             BOOT::|p1|
                                             |$|)))) ))) ))) ))) ))

*/



/* Code for BOOT::|PGCD;gcd;3P;15| */

static Lisp_Object MS_CDECL CC_BOOT__PGCDUgcdU3PU15(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V933, V934, V935, V936;
    Lisp_Object fn;
    argcheck(nargs, 3, "PGCD;gcd;3P;15");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PGCD;gcd;3P;15|\n");
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
    V934 = stack[-4];
    V933 = (Lisp_Object)1217; /* 76 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-6];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    if (V933 == nil) goto V342;
    V934 = stack[-4];
    V933 = (Lisp_Object)1633; /* 102 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-6];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-6] = V933;
    V934 = stack[-4];
    V933 = (Lisp_Object)1329; /* 83 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-2] = V933;
    V933 = stack[-2];
    if (!car_legal(V933)) goto V948;
    stack[-1] = qcar(V933);
    stack[0] = stack[-6];
    V934 = stack[-4];
    V933 = (Lisp_Object)641; /* 40 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V934 = qcar(V934);
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply1(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    V933 = stack[-2];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, stack[-1], stack[0], V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    if (!(V933 == nil)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    V934 = stack[-4];
    V933 = (Lisp_Object)1329; /* 83 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-2] = V933;
    V933 = stack[-2];
    if (!car_legal(V933)) goto V948;
    stack[-1] = qcar(V933);
    stack[0] = stack[-6];
    V934 = stack[-4];
    V933 = (Lisp_Object)1649; /* 103 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V934 = qcar(V934);
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply1(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    V933 = stack[-2];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, stack[-1], stack[0], V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    if (V933 == nil) goto V122;
    V934 = stack[-4];
    V933 = (Lisp_Object)1633; /* 102 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-5];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
        popv(9);
        return Lapply2(nil, 3, V935, V934, V933);

V122:
    V933 = lisp_true;
    if (V933 == nil) goto V195;
    V934 = stack[-4];
    V933 = (Lisp_Object)1217; /* 76 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-5];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    if (V933 == nil) goto V200;
    V934 = stack[-4];
    V933 = (Lisp_Object)1681; /* 105 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-3] = V933;
    V933 = stack[-3];
    if (!car_legal(V933)) goto V948;
    stack[-2] = qcar(V933);
    V934 = stack[-4];
    V933 = (Lisp_Object)1665; /* 104 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-1] = V933;
    V933 = stack[-1];
    if (!car_legal(V933)) goto V948;
    stack[0] = qcar(V933);
    V934 = stack[-4];
    V933 = (Lisp_Object)1521; /* 95 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-6];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-6] = V933;
    V934 = stack[-4];
    V933 = (Lisp_Object)1521; /* 95 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-5];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    V933 = stack[-1];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, stack[0], stack[-6], V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    V934 = V933;
    V933 = stack[-3];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    {
        Lisp_Object V949 = stack[-2];
        popv(9);
        return Lapply2(nil, 3, V949, V934, V933);
    }

V200:
    V933 = lisp_true;
    if (V933 == nil) goto V322;
    V935 = stack[-6];
    V934 = stack[-5];
    V933 = stack[-4];
    {
        popv(9);
        fn = elt(env, 1); /* BOOT::|PGCD;gcdTermList| */
        return (*qfnn(fn))(qenv(fn), 3, V935, V934, V933);
    }

V322:
    V933 = nil;
    { popv(9); return onevalue(V933); }

V195:
    V933 = nil;
    { popv(9); return onevalue(V933); }

V342:
    V934 = stack[-4];
    V933 = (Lisp_Object)1217; /* 76 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-5];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    if (V933 == nil) goto V337;
    V934 = stack[-4];
    V933 = (Lisp_Object)1633; /* 102 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-5];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-5] = V933;
    V934 = stack[-4];
    V933 = (Lisp_Object)1329; /* 83 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-2] = V933;
    V933 = stack[-2];
    if (!car_legal(V933)) goto V948;
    stack[-1] = qcar(V933);
    stack[0] = stack[-5];
    V934 = stack[-4];
    V933 = (Lisp_Object)641; /* 40 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V934 = qcar(V934);
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply1(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    V933 = stack[-2];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, stack[-1], stack[0], V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    if (!(V933 == nil)) { Lisp_Object res = stack[-5]; popv(9); return onevalue(res); }
    V934 = stack[-4];
    V933 = (Lisp_Object)1329; /* 83 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-2] = V933;
    V933 = stack[-2];
    if (!car_legal(V933)) goto V948;
    stack[-1] = qcar(V933);
    stack[0] = stack[-5];
    V934 = stack[-4];
    V933 = (Lisp_Object)1649; /* 103 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V934 = qcar(V934);
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply1(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    V933 = stack[-2];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, stack[-1], stack[0], V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    if (V933 == nil) goto V441;
    V934 = stack[-4];
    V933 = (Lisp_Object)1633; /* 102 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-6];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
        popv(9);
        return Lapply2(nil, 3, V935, V934, V933);

V441:
    V933 = lisp_true;
    if (V933 == nil) goto V514;
    V935 = stack[-5];
    V934 = stack[-6];
    V933 = stack[-4];
    {
        popv(9);
        fn = elt(env, 1); /* BOOT::|PGCD;gcdTermList| */
        return (*qfnn(fn))(qenv(fn), 3, V935, V934, V933);
    }

V514:
    V933 = nil;
    { popv(9); return onevalue(V933); }

V337:
    V933 = lisp_true;
    if (V933 == nil) goto V529;
    V934 = stack[-4];
    V933 = (Lisp_Object)1633; /* 102 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-6];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-6] = V933;
    V934 = stack[-4];
    V933 = (Lisp_Object)1633; /* 102 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-5];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-5] = V933;
    V934 = stack[-4];
    V933 = (Lisp_Object)1329; /* 83 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V936 = qcar(V934);
    V935 = stack[-6];
    V934 = stack[-5];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, V936, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    if (!(V933 == nil)) { Lisp_Object res = stack[-6]; popv(9); return onevalue(res); }
    V933 = lisp_true;
    if (V933 == nil) goto V614;
    V934 = stack[-4];
    V933 = (Lisp_Object)1249; /* 78 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-6];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V935 = V933;
    V933 = V935;
    V933 = qcdr(V933);
    stack[-1] = V933;
    V933 = V935;
    V934 = qcar(V933);
    V933 = (Lisp_Object)1; /* 0 */
    V933 = Leql(nil, V934, V933);
    env = stack[-8];
    if (!(V933 == nil)) goto V649;
    stack[0] = V935;
    V934 = stack[-4];
    V933 = (Lisp_Object)113; /* 7 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    fn = elt(env, 2); /* BOOT::COERCE-FAILURE-MSG */
    V933 = (*qfn2(fn))(qenv(fn), stack[0], V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    fn = elt(env, 3); /* BOOT::|error| */
    V933 = (*qfn1(fn))(qenv(fn), V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    goto V649;

V649:
    V933 = stack[-1];
    stack[-7] = V933;
    V934 = stack[-4];
    V933 = (Lisp_Object)1249; /* 78 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V935 = qcar(V934);
    V934 = stack[-5];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply2(nil, 3, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V935 = V933;
    V933 = V935;
    V933 = qcdr(V933);
    stack[-1] = V933;
    V933 = V935;
    V934 = qcar(V933);
    V933 = (Lisp_Object)1; /* 0 */
    V933 = Leql(nil, V934, V933);
    env = stack[-8];
    if (!(V933 == nil)) goto V710;
    stack[0] = V935;
    V934 = stack[-4];
    V933 = (Lisp_Object)113; /* 7 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    fn = elt(env, 2); /* BOOT::COERCE-FAILURE-MSG */
    V933 = (*qfn2(fn))(qenv(fn), stack[0], V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    fn = elt(env, 3); /* BOOT::|error| */
    V933 = (*qfn1(fn))(qenv(fn), V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    goto V710;

V710:
    V933 = stack[-1];
    stack[0] = V933;
    V934 = stack[-4];
    V933 = (Lisp_Object)1697; /* 106 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V936 = qcar(V934);
    V935 = stack[-7];
    V934 = stack[0];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, V936, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    if (V933 == nil) goto V882;
    V934 = stack[-4];
    V933 = (Lisp_Object)1713; /* 107 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-3] = V933;
    V933 = stack[-3];
    if (!car_legal(V933)) goto V948;
    stack[-2] = qcar(V933);
    V934 = stack[-4];
    V933 = (Lisp_Object)769; /* 48 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-1] = V933;
    V933 = stack[-1];
    if (!car_legal(V933)) goto V948;
    stack[0] = qcar(V933);
    V934 = stack[-4];
    V933 = (Lisp_Object)1297; /* 81 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V936 = qcar(V934);
    V935 = stack[-6];
    V934 = stack[-7];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, V936, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    stack[-6] = V933;
    V934 = stack[-4];
    V933 = (Lisp_Object)1297; /* 81 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V936 = qcar(V934);
    V935 = stack[-5];
    V934 = stack[-7];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, V936, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    V933 = stack[-1];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, stack[0], stack[-6], V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    V935 = V933;
    V934 = stack[-7];
    V933 = stack[-3];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    {
        Lisp_Object V950 = stack[-2];
        popv(9);
        return Lapply3(nil, 4, V950, V935, V934, V933);
    }

V882:
    V934 = stack[-4];
    V933 = (Lisp_Object)913; /* 57 */
    V933 = Lgetv(nil, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    V934 = V933;
    if (!car_legal(V934)) goto V946;
    V936 = qcar(V934);
    V935 = stack[-7];
    V934 = stack[0];
    if (!car_legal(V933)) goto V947;
    V933 = qcdr(V933);
    V933 = Lapply3(nil, 4, V936, V935, V934, V933);
    nil = C_nil;
    if (exception_pending()) goto V945;
    env = stack[-8];
    if (V933 == nil) goto V877;
    V935 = stack[-6];
    V934 = stack[-5];
    V933 = stack[-4];
    {
        popv(9);
        fn = elt(env, 1); /* BOOT::|PGCD;gcdTermList| */
        return (*qfnn(fn))(qenv(fn), 3, V935, V934, V933);
    }

V877:
    V933 = lisp_true;
    if (V933 == nil) goto V917;
    V935 = stack[-5];
    V934 = stack[-6];
    V933 = stack[-4];
    {
        popv(9);
        fn = elt(env, 1); /* BOOT::|PGCD;gcdTermList| */
        return (*qfnn(fn))(qenv(fn), 3, V935, V934, V933);
    }

V917:
    V933 = nil;
    { popv(9); return onevalue(V933); }

V614:
    V933 = nil;
    { popv(9); return onevalue(V933); }

V529:
    V933 = nil;
    { popv(9); return onevalue(V933); }
/* error exit handlers */
V948:
    popv(9);
    return error(1, err_bad_car, V933);
V947:
    popv(9);
    return error(1, err_bad_cdr, V933);
V946:
    popv(9);
    return error(1, err_bad_car, V934);
V945:
    popv(9);
    return nil;
}

/*
(DEFUN BOOT::|filterModemapsFromPackages| (BOOT::|mms|
      BOOT::|names|
      BOOT::|op|)
   (PROG (BOOT::|mpolys|
         BOOT::|mpacks|
         BOOT::|type|
         BOOT::|name|
         BOOT::|found|
         BOOT::|good|
         BOOT::|bad|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET BOOT::|good| NIL)
               (BOOT:SPADLET BOOT::|bad| NIL)
               (BOOT:SPADLET
                  BOOT::|mpolys|
                  '("Polynomial"
                      "MultivariatePolynomial"
                      "DistributedMultivariatePolynomial"
                      "HomogeneousDistributedMultivariatePolynomial"))
               (BOOT:SPADLET
                  BOOT::|mpacks|
                  '("MFactorize" "MRationalFactorize"))
               (DO ((#:G18950 BOOT::|mms| (CDR #:G18950)) (BOOT::|mm| NIL))
                  ((OR
                      (ATOM #:G18950)
                      (PROGN (SETQ BOOT::|mm| (CAR #:G18950)) NIL))
                     NIL)
                  (SEQ
                     (EXIT
                        (COND
                           ((BOOT::|isFreeFunctionFromMm| BOOT::|mm|)
                              (BOOT:SPADLET
                                 BOOT::|bad|
                                 (CONS BOOT::|mm| BOOT::|bad|)))
                           ('T
                              (BOOT:SPADLET
                                 BOOT::|type|
                                 (BOOT::|getDomainFromMm| BOOT::|mm|))
                              (COND
                                 ((NULL BOOT::|type|)
                                    (BOOT:SPADLET
                                       BOOT::|bad|
                                       (CONS BOOT::|mm| BOOT::|bad|)))
                                 ('T
                                    (COND
                                       ((PAIRP BOOT::|type|)
                                          (BOOT:SPADLET
                                             BOOT::|type|
                                             (CAR BOOT::|type|))))
                                    (COND
                                       ((BOOT:|BOOT-EQUAL|
                                           (BOOT::GETDATABASE
                                              BOOT::|type|
                                              'BOOT::CONSTRUCTORKIND)
                                           'BOOT::|category|)
                                          (BOOT:SPADLET
                                             BOOT::|bad|
                                             (CONS
                                                BOOT::|mm|
                                                BOOT::|bad|)))
                                       ('T
                                          (BOOT:SPADLET
                                             BOOT::|name|
                                             (BOOT::|object2String|
                                                BOOT::|type|))
                                          (BOOT:SPADLET BOOT::|found| NIL)
                                          (DO ((#:G18951
                                                 BOOT::|names|
                                                 (CDR #:G18951))
                                                (|n| NIL))
                                             ((OR
                                                 (ATOM #:G18951)
                                                 (PROGN
                                                    (SETQ |n|
        (CAR #:G18951))
                                                    NIL)
                                                 (NULL
                                                    (NULL BOOT::|found|)))
                                                NIL)
                                             (SEQ
                                                (EXIT
                                                   (COND
        ((VMLISP:STRPOS |n| BOOT::|name| 0 NIL)
        (BOOT:SPADLET BOOT::|found| 'T))
        ((AND
         (BOOT:|BOOT-EQUAL| BOOT::|op| 'BOOT::|factor|)
         (VMLISP:|member| |n| BOOT::|mpolys|)
         (VMLISP:|member| BOOT::|name| BOOT::|mpacks|))
        (BOOT:SPADLET BOOT::|found| 'T)))) ))
                                          (COND
                                             (BOOT::|found|
                                                (BOOT:SPADLET
                                                   BOOT::|good|
                                                   (CONS
                                                      BOOT::|mm|
                                                      BOOT::|good|)))
                                             ('T
                                                (BOOT:SPADLET
                                                   BOOT::|bad|
                                                   (CONS
                                                      BOOT::|mm|
                                                BOOT::|bad|)))) ))) ))) )))
               (CONS BOOT::|good| (CONS BOOT::|bad| NIL)))) )))

*/



/* Code for BOOT::|filterModemapsFromPackages| */

static Lisp_Object MS_CDECL CC_BOOT__filterModemapsFromPackages(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V244, V245, V246, V247;
    Lisp_Object fn;
    argcheck(nargs, 3, "filterModemapsFromPackages");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|filterModemapsFromPackages|\n");
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
    stack[-9] = V4;
    stack[-10] = V3;
    V245 = V2;
/* end of prologue */
    V244 = nil;
    stack[-5] = V244;
    V244 = nil;
    stack[-4] = V244;
    V244 = elt(env, 1); /* ("Polynomial" "MultivariatePolynomial" "DistributedMultivariatePolynomial" "HomogeneousDistributedMultivariatePolynomial") */
    stack[-11] = V244;
    V244 = elt(env, 2); /* ("MFactorize" "MRationalFactorize") */
    stack[-8] = V244;
    V244 = V245;
    stack[-2] = V244;
    goto V29;

V29:
    V244 = stack[-2];
    if (!consp(V244)) goto V233;
    V244 = stack[-2];
    if (!car_legal(V244)) goto V260;
    V244 = qcar(V244);
    stack[-3] = V244;
    V244 = nil;
    if (!(V244 == nil)) goto V233;
    V244 = stack[-3];
    fn = elt(env, 6); /* BOOT::|isFreeFunctionFromMm| */
    V244 = (*qfn1(fn))(qenv(fn), V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    if (V244 == nil) goto V47;
    V245 = stack[-3];
    V244 = stack[-4];
    V244 = cons(V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    stack[-4] = V244;
    goto V43;

V43:
    V244 = stack[-2];
    if (!car_legal(V244)) goto V262;
    V244 = qcdr(V244);
    stack[-2] = V244;
    goto V29;

V47:
    V244 = lisp_true;
    if (V244 == nil) goto V43;
    V244 = stack[-3];
    fn = elt(env, 7); /* BOOT::|getDomainFromMm| */
    V244 = (*qfn1(fn))(qenv(fn), V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    stack[0] = V244;
    V244 = stack[0];
    if (V244 == nil) goto V69;
    V244 = lisp_true;
    if (V244 == nil) goto V43;
    V244 = stack[0];
    fn = elt(env, 8); /* CONSP */
    V244 = (*qfn1(fn))(qenv(fn), V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    if (V244 == nil) goto V97;
    V244 = stack[0];
    if (!car_legal(V244)) goto V260;
    V244 = qcar(V244);
    stack[0] = V244;
    goto V97;

V97:
    V245 = stack[0];
    V244 = elt(env, 3); /* BOOT::CONSTRUCTORKIND */
    fn = elt(env, 9); /* BOOT::GETDATABASE */
    V245 = (*qfn2(fn))(qenv(fn), V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    V244 = elt(env, 4); /* BOOT::|category| */
    V244 = (V245 == V244 ? lisp_true : nil);
    if (V244 == nil) goto V90;
    V245 = stack[-3];
    V244 = stack[-4];
    V244 = cons(V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    stack[-4] = V244;
    goto V43;

V90:
    V244 = lisp_true;
    if (V244 == nil) goto V43;
    V244 = stack[0];
    fn = elt(env, 10); /* BOOT::|object2String| */
    V244 = (*qfn1(fn))(qenv(fn), V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    stack[-7] = V244;
    V244 = nil;
    stack[-6] = V244;
    V244 = stack[-10];
    stack[0] = V244;
    goto V126;

V126:
    V244 = stack[0];
    if (!consp(V244)) goto V121;
    V244 = stack[0];
    if (!car_legal(V244)) goto V260;
    V244 = qcar(V244);
    stack[-1] = V244;
    V244 = nil;
    if (!(V244 == nil)) goto V121;
    V244 = stack[-6];
    if (!(V244 == nil)) goto V121;
    V247 = stack[-1];
    V246 = stack[-7];
    V245 = (Lisp_Object)1; /* 0 */
    V244 = nil;
    fn = elt(env, 11); /* VMLISP:STRPOS */
    V244 = (*qfnn(fn))(qenv(fn), 4, V247, V246, V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    if (V244 == nil) goto V165;
    V244 = lisp_true;
    stack[-6] = V244;
    goto V142;

V142:
    V244 = stack[0];
    if (!car_legal(V244)) goto V262;
    V244 = qcdr(V244);
    stack[0] = V244;
    goto V126;

V165:
    V245 = stack[-9];
    V244 = elt(env, 5); /* BOOT::|factor| */
    V244 = (V245 == V244 ? lisp_true : nil);
    if (V244 == nil) goto V142;
    V245 = stack[-1];
    V244 = stack[-11];
    fn = elt(env, 12); /* VMLISP:|member| */
    V244 = (*qfn2(fn))(qenv(fn), V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    if (V244 == nil) goto V142;
    V245 = stack[-7];
    V244 = stack[-8];
    fn = elt(env, 12); /* VMLISP:|member| */
    V244 = (*qfn2(fn))(qenv(fn), V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    if (V244 == nil) goto V142;
    V244 = lisp_true;
    stack[-6] = V244;
    goto V142;

V121:
    V244 = stack[-6];
    if (V244 == nil) goto V203;
    V245 = stack[-3];
    V244 = stack[-5];
    V244 = cons(V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    stack[-5] = V244;
    goto V43;

V203:
    V244 = lisp_true;
    if (V244 == nil) goto V43;
    V245 = stack[-3];
    V244 = stack[-4];
    V244 = cons(V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    stack[-4] = V244;
    goto V43;

V69:
    V245 = stack[-3];
    V244 = stack[-4];
    V244 = cons(V245, V244);
    nil = C_nil;
    if (exception_pending()) goto V261;
    env = stack[-12];
    stack[-4] = V244;
    goto V43;

V233:
    V246 = stack[-5];
    V245 = stack[-4];
    V244 = nil;
    popv(13);
    { Lisp_Object retVal = list2star(V246, V245, V244);
    errexit();
    return onevalue(retVal); }
/* error exit handlers */
V262:
    popv(13);
    return error(1, err_bad_cdr, V244);
V261:
    popv(13);
    return nil;
V260:
    popv(13);
    return error(1, err_bad_car, V244);
}

/*
(DEFUN BOOT::|selectMmsGen,matchMms| (BOOT::|mmaps|
      BOOT::|op|
      BOOT::|tar|
      BOOT::|args1|
      BOOT::|args2|)
   (PROG (BOOT::|sig| BOOT::|mmC| BOOT::|res| |c| |t| |a| BOOT::|mmS|)
      (RETURN
         (SEQ
            (BOOT:SPADLET BOOT::|mmS| NIL)
            (DO ((#:G18956 BOOT::|mmaps| (CDR #:G18956)) (#:G18955 NIL))
               ((OR
                   (ATOM #:G18956)
                   (PROGN (SETQ #:G18955 (CAR #:G18956)) NIL)
                   (PROGN
                      (PROGN
                         (BOOT:SPADLET BOOT::|sig| (CAR #:G18955))
                         (BOOT:SPADLET BOOT::|mmC| (CADR #:G18955))
                         #:G18955)
                      NIL))
                  NIL)
               (SEQ
                  (BOOT:SPADLET
                     BOOT::|$Subst|
                     (SEQ
                        (IF (AND
                              BOOT::|tar|
                              (NULL (BOOT::|isPartialMode| BOOT::|tar|)))
                           (EXIT
                              (SEQ
                                 (BOOT:SPADLET
                                    BOOT::|res|
                                    (CADR BOOT::|sig|))
                                 (IF (VMLISP:|member|
                                       BOOT::|res|
                                       (CDDR BOOT::|sig|))
                                    (EXIT NIL))
                                 (EXIT
                                    (CONS
                                       (CONS BOOT::|res| BOOT::|tar|)
                                       NIL)))) )
                        (EXIT NIL)))
                  (PROGN
                     (BOOT:SPADLET |c| (CAR BOOT::|sig|))
                     (BOOT:SPADLET |t| (CADR BOOT::|sig|))
                     (BOOT:SPADLET |a| (CDDR BOOT::|sig|))
                     BOOT::|sig|)
                  (IF |a|
                     (BOOT::|matchTypes| |a| BOOT::|args1| BOOT::|args2|)
                     NIL)
                  (EXIT
                     (IF (NULL (EQ BOOT::|$Subst| 'BOOT::|failed|))
                        (EXIT
                           (BOOT:SPADLET
                              BOOT::|mmS|
                              (NCONC
                                 (BOOT::|evalMm|
                                    BOOT::|op|
                                    BOOT::|tar|
                                    BOOT::|sig|
                                    BOOT::|mmC|)
                                 BOOT::|mmS|)))) )))
            (EXIT BOOT::|mmS|)))) )

*/



/* Code for BOOT::|selectMmsGen,matchMms| */

static Lisp_Object MS_CDECL CC_BOOT__selectMmsGenPmatchMms(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5,
                         Lisp_Object V6, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V165, V166, V167, V168;
    Lisp_Object fn;
    argcheck(nargs, 5, "selectMmsGen,matchMms");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|selectMmsGen,matchMms|\n");
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
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-4] = V6;
    stack[-5] = V5;
    stack[-6] = V4;
    stack[-7] = V3;
    V166 = V2;
/* end of prologue */
    V165 = nil;
    stack[-1] = V165;
    V165 = V166;
    stack[0] = V165;
    goto V28;

V28:
    V165 = stack[0];
    if (!consp(V165)) { Lisp_Object res = stack[-1]; popv(10); return onevalue(res); }
    V165 = stack[0];
    if (!car_legal(V165)) goto V178;
    V165 = qcar(V165);
    V166 = V165;
    V165 = nil;
    if (!(V165 == nil)) { Lisp_Object res = stack[-1]; popv(10); return onevalue(res); }
    V165 = V166;
    if (!car_legal(V165)) goto V178;
    V165 = qcar(V165);
    stack[-8] = V165;
    V165 = V166;
    if (!car_legal(V165)) goto V179;
    V165 = qcdr(V165);
    if (!car_legal(V165)) goto V178;
    V165 = qcar(V165);
    stack[-3] = V165;
    V165 = nil;
    if (!(V165 == nil)) { Lisp_Object res = stack[-1]; popv(10); return onevalue(res); }
    V165 = stack[-6];
    if (V165 == nil) goto V54;
    V165 = stack[-6];
    fn = elt(env, 3); /* BOOT::|isPartialMode| */
    V165 = (*qfn1(fn))(qenv(fn), V165);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-9];
    if (!(V165 == nil)) goto V54;
    V165 = stack[-8];
    if (!car_legal(V165)) goto V179;
    V165 = qcdr(V165);
    if (!car_legal(V165)) goto V178;
    V165 = qcar(V165);
    stack[-2] = V165;
    V166 = stack[-2];
    V165 = stack[-8];
    if (!car_legal(V165)) goto V179;
    V165 = qcdr(V165);
    if (!car_legal(V165)) goto V179;
    V165 = qcdr(V165);
    fn = elt(env, 4); /* VMLISP:|member| */
    V165 = (*qfn2(fn))(qenv(fn), V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-9];
    if (V165 == nil) goto V85;
    V165 = nil;
    goto V52;

V52:
    qvalue(elt(env, 1)) = V165; /* BOOT::|$Subst| */
    V165 = stack[-8];
    if (!car_legal(V165)) goto V179;
    V165 = qcdr(V165);
    if (!car_legal(V165)) goto V179;
    V165 = qcdr(V165);
    V166 = V165;
    V165 = V166;
    if (V165 == nil) goto V126;
    V167 = V166;
    V166 = stack[-5];
    V165 = stack[-4];
    fn = elt(env, 5); /* BOOT::|matchTypes| */
    V165 = (*qfnn(fn))(qenv(fn), 3, V167, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-9];
    goto V126;

V126:
    V166 = qvalue(elt(env, 1)); /* BOOT::|$Subst| */
    V165 = elt(env, 2); /* BOOT::|failed| */
    if (V166 == V165) goto V50;
    V168 = stack[-7];
    V167 = stack[-6];
    V166 = stack[-8];
    V165 = stack[-3];
    fn = elt(env, 6); /* BOOT::|evalMm| */
    V166 = (*qfnn(fn))(qenv(fn), 4, V168, V167, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-9];
    V165 = stack[-1];
    V165 = Lnconc(nil, V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-9];
    stack[-1] = V165;
    goto V50;

V50:
    V165 = stack[0];
    if (!car_legal(V165)) goto V179;
    V165 = qcdr(V165);
    stack[0] = V165;
    goto V28;

V85:
    V166 = stack[-2];
    V165 = stack[-6];
    V165 = cons(V166, V165);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-9];
    V165 = ncons(V165);
    nil = C_nil;
    if (exception_pending()) goto V180;
    env = stack[-9];
    goto V52;

V54:
    V165 = nil;
    goto V52;
/* error exit handlers */
V180:
    popv(10);
    return nil;
V179:
    popv(10);
    return error(1, err_bad_cdr, V165);
V178:
    popv(10);
    return error(1, err_bad_car, V165);
}

/*
(DEFUN BOOT::|BOP;<;2$B;29| (BOOT::|op1| BOOT::|op2| |$|)
   (PROG (BOOT::|w1| BOOT::|w2| #:G82440 BOOT::|k1| BOOT::|k2| BOOT::|d1|
         BOOT::|n1| BOOT::|d2| BOOT::|n2| #:G82432 BOOT::|func|)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (SEQ
                     (BOOT::LETT
                        BOOT::|w1|
                        (BOOT:SPADCALL BOOT::|op1| (VMLISP:QREFELT |$| 68))
                        BOOT::|BOP;<;2$B;29|)
                     (BOOT::LETT
                        BOOT::|w2|
                        (BOOT:SPADCALL BOOT::|op2| (VMLISP:QREFELT |$| 68))
                        BOOT::|BOP;<;2$B;29|)
                     (EXIT
                        (COND
                           ((NULL (EQL BOOT::|w1| BOOT::|w2|))
                              (PROGN
                                 (BOOT::LETT
                                    #:G82440
                                    (|<| BOOT::|w1| BOOT::|w2|)
                                    BOOT::|BOP;<;2$B;29|)
                                 (GO #:G82440)))) ))
                  (COND
                     ((NULL
                         (EQL
                            (VMLISP:QVELT BOOT::|op1| 1)
                            (VMLISP:QVELT BOOT::|op2| 1)))
                        (EXIT
                           (|<|
                              (VMLISP:QVELT BOOT::|op1| 1)
                              (VMLISP:QVELT BOOT::|op2| 1)))) )
                  (COND
                     ((NULL
                         (EQUAL
                            (BOOT:SPADCALL
                               BOOT::|op1|
                               (VMLISP:QREFELT |$| 8))
                            (BOOT:SPADCALL
                               BOOT::|op2|
                               (VMLISP:QREFELT |$| 8))))
                        (EXIT
                           (VMLISP:GGREATERP
                              (BOOT:SPADCALL
                                 BOOT::|op2|
                                 (VMLISP:QREFELT |$| 8))
                              (BOOT:SPADCALL
                                 BOOT::|op1|
                                 (VMLISP:QREFELT |$| 8)))) ))
                  (BOOT::LETT
                     BOOT::|n1|
                     (BOOT:SPADCALL
                        (BOOT::LETT
                           BOOT::|k1|
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL
                                 (BOOT:SPADCALL
                                    BOOT::|op1|
                                    (VMLISP:QREFELT |$| 12))
                                 (VMLISP:QREFELT |$| 63))
                              (VMLISP:QREFELT |$| 65))
                           BOOT::|BOP;<;2$B;29|)
                        (VMLISP:QREFELT |$| 69))
                     BOOT::|BOP;<;2$B;29|)
                  (BOOT::LETT
                     BOOT::|n2|
                     (BOOT:SPADCALL
                        (BOOT::LETT
                           BOOT::|k2|
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL
                                 (BOOT:SPADCALL
                                    BOOT::|op2|
                                    (VMLISP:QREFELT |$| 12))
                                 (VMLISP:QREFELT |$| 63))
                              (VMLISP:QREFELT |$| 65))
                           BOOT::|BOP;<;2$B;29|)
                        (VMLISP:QREFELT |$| 69))
                     BOOT::|BOP;<;2$B;29|)
                  (EXIT
                     (COND
                        ((EQL BOOT::|n1| BOOT::|n2|)
                           (COND
                              ((NULL
                                  (ZEROP
                                     (BOOT::LETT
                                        BOOT::|n1|
                                        (BOOT:SPADCALL
                                           (BOOT::LETT
                                              BOOT::|d1|
                                              (BOOT:SPADCALL
                                                 BOOT::|k1|
                                                 BOOT::|k2|
                                                 (VMLISP:QREFELT |$| 70))
                                              BOOT::|BOP;<;2$B;29|)
                                           (VMLISP:QREFELT |$| 69))
                                        BOOT::|BOP;<;2$B;29|)))
                                 (SEQ
                                    (EXIT
                                       (SEQ
                                          (SEQ
                                             (BOOT::LETT
                                                BOOT::|n2|
                                                (BOOT:SPADCALL
                                                   (BOOT::LETT
                                                      BOOT::|d2|
        (BOOT:SPADCALL BOOT::|k2| BOOT::|k1| (VMLISP:QREFELT |$| 70))
                                                      BOOT::|BOP;<;2$B;29|)
                                                   (VMLISP:QREFELT |$| 69))
                                                BOOT::|BOP;<;2$B;29|)
                                             (EXIT
                                                (COND
                                                   ((NULL
        (EQL BOOT::|n1| BOOT::|n2|))
        (PROGN
        (BOOT::LETT
           #:G82432 (|<| BOOT::|n1| BOOT::|n2|) BOOT::|BOP;<;2$B;29|)
        (GO #:G82432)))) ))
                                          (EXIT
                                             (VMLISP:CGREATERP
                                                (BOOT:SPADCALL
                                                BOOT::|d2|
                                    (VMLISP:QREFELT |$| 71))
                                                (BOOT:SPADCALL
                                                BOOT::|d1|
                                                   (VMLISP:QREFELT
                                                      |$|
                                                      71)))) ))
                                    #:G82432
                                    (EXIT #:G82432)))
                              ('T
                                 (SEQ
                                    (BOOT::LETT
                                       BOOT::|func|
                                       (BOOT:SPADCALL
                                          BOOT::|op1|
                                          "%less?"
                           (VMLISP:QREFELT |$| 24))
                                       BOOT::|BOP;<;2$B;29|)
                                    (EXIT
                                       (COND
                              ((BOOT::QEQCAR BOOT::|func| 0)
                                             (BOOT:SPADCALL
                                                BOOT::|op1|
                                                BOOT::|op2|
                                                (QCDR BOOT::|func|)))
                                          ('T
                                             (SEQ
                                                (BOOT::LETT
                                                BOOT::|func|
                                                (BOOT:SPADCALL
                                                      BOOT::|op1|
                                                      "%equal?"
        (VMLISP:QREFELT |$| 24))
                                                BOOT::|BOP;<;2$B;29|)
                                                (EXIT
                                                   (COND
        ((BOOT::QEQCAR BOOT::|func| 0)
        (COND
     ((BOOT:SPADCALL BOOT::|op1| BOOT::|op2| (QCDR BOOT::|func|)) 'NIL)
           ('T 'T)))
        ('T 'NIL)))) ))) ))) )
                        ('T (|<| BOOT::|n1| BOOT::|n2|)))) ))
            #:G82440
            (EXIT #:G82440)))) )

*/



/* Code for BOOT::|BOP;<;2$B;29| */

static Lisp_Object MS_CDECL CC_BOOT__BOPURU2DBU29(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V805, V806, V807, V808;
    Lisp_Object fn;
    argcheck(nargs, 3, "BOP;<;2$B;29");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|BOP;<;2$B;29|\n");
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
    V806 = stack[-7];
    V805 = (Lisp_Object)1089; /* 68 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V807 = qcar(V806);
    V806 = stack[-9];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[0] = V805;
    V806 = stack[-7];
    V805 = (Lisp_Object)1089; /* 68 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V807 = qcar(V806);
    V806 = stack[-8];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V807 = V805;
    V806 = stack[0];
    V805 = V807;
    V805 = Leql(nil, V806, V805);
    env = stack[-11];
    if (V805 == nil) goto V89;
    V806 = stack[-9];
    V805 = (Lisp_Object)17; /* 1 */
    stack[0] = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = stack[-8];
    V805 = (Lisp_Object)17; /* 1 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V805 = Leql(nil, stack[0], V805);
    env = stack[-11];
    if (V805 == nil) goto V130;
    V806 = stack[-7];
    V805 = (Lisp_Object)129; /* 8 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V807 = qcar(V806);
    V806 = stack[-9];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[0] = V805;
    V806 = stack[-7];
    V805 = (Lisp_Object)129; /* 8 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V807 = qcar(V806);
    V806 = stack[-8];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    if (cl_equal(stack[0], V805)) goto V260;
    V806 = stack[-7];
    V805 = (Lisp_Object)129; /* 8 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V807 = qcar(V806);
    V806 = stack[-8];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[0] = V805;
    V806 = stack[-7];
    V805 = (Lisp_Object)129; /* 8 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V807 = qcar(V806);
    V806 = stack[-9];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    {
        Lisp_Object V823 = stack[0];
        popv(12);
        fn = elt(env, 3); /* VMLISP:GGREATERP */
        return (*qfn2(fn))(qenv(fn), V823, V805);
    }

V260:
    V806 = stack[-7];
    V805 = (Lisp_Object)1105; /* 69 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[-4] = V805;
    V805 = stack[-4];
    if (!car_legal(V805)) goto V824;
    stack[-3] = qcar(V805);
    V806 = stack[-7];
    V805 = (Lisp_Object)1041; /* 65 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[-5] = V805;
    V805 = stack[-5];
    if (!car_legal(V805)) goto V824;
    stack[-2] = qcar(V805);
    V806 = stack[-7];
    V805 = (Lisp_Object)1009; /* 63 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[-1] = V805;
    V805 = stack[-1];
    if (!car_legal(V805)) goto V824;
    stack[0] = qcar(V805);
    V806 = stack[-7];
    V805 = (Lisp_Object)193; /* 12 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V807 = qcar(V806);
    V806 = stack[-9];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    V805 = stack[-1];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, stack[0], V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    V805 = stack[-5];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, stack[-2], V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    stack[-10] = V806;
    V805 = stack[-4];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, stack[-3], V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[-6] = V805;
    V806 = stack[-7];
    V805 = (Lisp_Object)1105; /* 69 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[-5] = V805;
    V805 = stack[-5];
    if (!car_legal(V805)) goto V824;
    stack[-4] = qcar(V805);
    V806 = stack[-7];
    V805 = (Lisp_Object)1041; /* 65 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[-3] = V805;
    V805 = stack[-3];
    if (!car_legal(V805)) goto V824;
    stack[-2] = qcar(V805);
    V806 = stack[-7];
    V805 = (Lisp_Object)1009; /* 63 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[-1] = V805;
    V805 = stack[-1];
    if (!car_legal(V805)) goto V824;
    stack[0] = qcar(V805);
    V806 = stack[-7];
    V805 = (Lisp_Object)193; /* 12 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V807 = qcar(V806);
    V806 = stack[-8];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    V805 = stack[-1];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, stack[0], V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    V805 = stack[-3];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, stack[-2], V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    stack[0] = V806;
    V805 = stack[-5];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, stack[-4], V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V807 = V805;
    V806 = stack[-6];
    V805 = V807;
    V805 = Leql(nil, V806, V805);
    env = stack[-11];
    if (V805 == nil) goto V445;
    V806 = stack[-7];
    V805 = (Lisp_Object)1105; /* 69 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[-3] = V805;
    V805 = stack[-3];
    if (!car_legal(V805)) goto V824;
    stack[-1] = qcar(V805);
    V806 = stack[-7];
    V805 = (Lisp_Object)1121; /* 70 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V808 = qcar(V806);
    V807 = stack[-10];
    V806 = stack[0];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply3(nil, 4, V808, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    stack[-2] = V806;
    V805 = stack[-3];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, stack[-1], V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[-6] = V805;
    V805 = (Lisp_Object)zerop(V805);
    V805 = V805 ? lisp_true : nil;
    env = stack[-11];
    if (V805 == nil) goto V520;
    V805 = lisp_true;
    if (V805 == nil) goto V645;
    V806 = stack[-7];
    V805 = (Lisp_Object)385; /* 24 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V808 = qcar(V806);
    V807 = stack[-9];
    V806 = elt(env, 1); /* "%less?" */
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply3(nil, 4, V808, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V807 = V805;
    V805 = V807;
    V806 = qcar(V805);
    V805 = (Lisp_Object)1; /* 0 */
    V805 = Leql(nil, V806, V805);
    env = stack[-11];
    if (V805 == nil) goto V679;
    V805 = V807;
    V805 = qcdr(V805);
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V808 = qcar(V806);
    V807 = stack[-9];
    V806 = stack[-8];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
        popv(12);
        return Lapply3(nil, 4, V808, V807, V806, V805);

V679:
    V805 = lisp_true;
    if (V805 == nil) goto V711;
    V806 = stack[-7];
    V805 = (Lisp_Object)385; /* 24 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V808 = qcar(V806);
    V807 = stack[-9];
    V806 = elt(env, 2); /* "%equal?" */
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply3(nil, 4, V808, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V807 = V805;
    V805 = V807;
    V806 = qcar(V805);
    V805 = (Lisp_Object)1; /* 0 */
    V805 = Leql(nil, V806, V805);
    env = stack[-11];
    if (V805 == nil) goto V745;
    V805 = V807;
    V805 = qcdr(V805);
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V808 = qcar(V806);
    V807 = stack[-9];
    V806 = stack[-8];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply3(nil, 4, V808, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    if (V805 == nil) goto V758;
    V805 = nil;
    { popv(12); return onevalue(V805); }

V758:
    V805 = lisp_true;
    if (V805 == nil) goto V782;
    V805 = lisp_true;
    { popv(12); return onevalue(V805); }

V782:
    V805 = nil;
    { popv(12); return onevalue(V805); }

V745:
    V805 = lisp_true;
    if (V805 == nil) goto V786;
    V805 = nil;
    { popv(12); return onevalue(V805); }

V786:
    V805 = nil;
    { popv(12); return onevalue(V805); }

V711:
    V805 = nil;
    { popv(12); return onevalue(V805); }

V645:
    V805 = nil;
    { popv(12); return onevalue(V805); }

V520:
    V806 = stack[-7];
    V805 = (Lisp_Object)1105; /* 69 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[-3] = V805;
    V805 = stack[-3];
    if (!car_legal(V805)) goto V824;
    stack[-1] = qcar(V805);
    V806 = stack[-7];
    V805 = (Lisp_Object)1121; /* 70 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V808 = qcar(V806);
    V807 = stack[0];
    V806 = stack[-10];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply3(nil, 4, V808, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    stack[0] = V806;
    V805 = stack[-3];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, stack[-1], V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V807 = V805;
    V806 = stack[-6];
    V805 = V807;
    V805 = Leql(nil, V806, V805);
    env = stack[-11];
    if (V805 == nil) goto V579;
    V806 = stack[-7];
    V805 = (Lisp_Object)1137; /* 71 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V807 = qcar(V806);
    V806 = stack[0];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    stack[0] = V805;
    V806 = stack[-7];
    V805 = (Lisp_Object)1137; /* 71 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = V805;
    if (!car_legal(V806)) goto V821;
    V807 = qcar(V806);
    V806 = stack[-2];
    if (!car_legal(V805)) goto V822;
    V805 = qcdr(V805);
    V805 = Lapply2(nil, 3, V807, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    {
        Lisp_Object V825 = stack[0];
        popv(12);
        fn = elt(env, 4); /* VMLISP:CGREATERP */
        return (*qfn2(fn))(qenv(fn), V825, V805);
    }

V579:
    V805 = stack[-6];
    V806 = V807;
        popv(12);
        return Llessp(nil, V805, V806);

V445:
    V805 = lisp_true;
    if (V805 == nil) goto V792;
    V805 = stack[-6];
    V806 = V807;
        popv(12);
        return Llessp(nil, V805, V806);

V792:
    V805 = nil;
    { popv(12); return onevalue(V805); }

V130:
    V806 = stack[-9];
    V805 = (Lisp_Object)17; /* 1 */
    stack[0] = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    env = stack[-11];
    V806 = stack[-8];
    V805 = (Lisp_Object)17; /* 1 */
    V805 = Lgetv(nil, V806, V805);
    nil = C_nil;
    if (exception_pending()) goto V820;
    {
        Lisp_Object V826 = stack[0];
        popv(12);
        return Llessp(nil, V826, V805);
    }

V89:
    V805 = stack[0];
    V806 = V807;
        popv(12);
        return Llessp(nil, V805, V806);
/* error exit handlers */
V824:
    popv(12);
    return error(1, err_bad_car, V805);
V822:
    popv(12);
    return error(1, err_bad_cdr, V805);
V821:
    popv(12);
    return error(1, err_bad_car, V806);
V820:
    popv(12);
    return nil;
}

/*
(DEFUN BOOT::|evalMmStack| (BOOT::|mmC|)
   (PROG (|a| BOOT::|mmD| BOOT::|pvar| BOOT::|cat| BOOT::|args|
         BOOT::|ISTMP#1| BOOT::|pat| BOOT::|ISTMP#2| |x|)
      (RETURN
         (SEQ
            (COND
               ((AND
                   (PAIRP BOOT::|mmC|)
                   (EQ (QCAR BOOT::|mmC|) 'AND)
                   (PROGN (BOOT:SPADLET |a| (QCDR BOOT::|mmC|)) 'T))
                  (CONS
                     (PROG (#:G18975)
                        (BOOT:SPADLET #:G18975 NIL)
                        (RETURN
                           (DO ((#:G18976 |a| (CDR #:G18976))
                                 (BOOT::|cond| NIL))
                              ((OR
                                  (ATOM #:G18976)
                                  (PROGN
                                     (SETQ BOOT::|cond| (CAR #:G18976))
                                     NIL))
                                 #:G18975)
                              (SEQ
                                 (EXIT
                                    (SETQ #:G18975
                                       (NCONC
                                          #:G18975
                                          (BOOT::|evalMmStackInner|
                                             BOOT::|cond|)))) ))) )
                     NIL))
               ((AND
                   (PAIRP BOOT::|mmC|)
                   (EQ (QCAR BOOT::|mmC|) 'OR)
                   (PROGN
                      (BOOT:SPADLET BOOT::|args| (QCDR BOOT::|mmC|))
                      'T))
                  (PROG (#:G18973)
                     (BOOT:SPADLET #:G18973 NIL)
                     (RETURN
                        (DO ((#:G18974 BOOT::|args| (CDR #:G18974))
                              (|a| NIL))
                           ((OR
                               (ATOM #:G18974)
                               (PROGN (SETQ |a| (CAR #:G18974)) NIL))
                              #:G18973)
                           (SEQ
                              (EXIT
                                 (SETQ #:G18973
                                    (APPEND
                                       #:G18973
                                       (BOOT::|evalMmStack| |a|)))) ))) ))
               ((AND
                   (PAIRP BOOT::|mmC|)
                   (EQ (QCAR BOOT::|mmC|) 'BOOT::|partial|)
                   (PROGN
                      (BOOT:SPADLET BOOT::|mmD| (QCDR BOOT::|mmC|))
                      'T))
                  (BOOT::|evalMmStack| BOOT::|mmD|))
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
                  (BOOT::|evalMmStack|
                     (CONS
                        'AND
                        (PROG (#:G18971)
                           (BOOT:SPADLET #:G18971 NIL)
                           (RETURN
                              (DO ((#:G18972 BOOT::|args| (CDR #:G18972))
                                    (|c| NIL))
                                 ((OR
                                     (ATOM #:G18972)
                                     (PROGN (SETQ |c| (CAR #:G18972)) NIL))
                                    (NREVERSE0 #:G18971))
                                 (SEQ
                                    (EXIT
                                       (SETQ #:G18971
                                          (CONS
                                             (CONS
                                                'BOOT::|ofCategory|
                                                (CONS
                                                   BOOT::|pvar|
                                                   (CONS |c| NIL)))
                                             #:G18971)))) ))) )))
               ((AND
                   (PAIRP BOOT::|mmC|)
                   (EQ (QCAR BOOT::|mmC|) 'BOOT::|ofType|))
                  (CONS NIL NIL))
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
                              NIL)
                           NIL))
                     ('T
                        (CONS
                           (CONS
                              'BOOT::|ofCategory|
                              (CONS BOOT::|pat| (CONS |x| NIL)))
                           NIL))))
               ('T (CONS (CONS BOOT::|mmC| NIL) NIL)))) )))

*/



/* Code for BOOT::|evalMmStack| */

static Lisp_Object CC_BOOT__evalMmStack(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V411, V412, V413;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|evalMmStack|\n");
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
    V411 = stack[-4];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V22;
    V411 = stack[-4];
    V412 = qcar(V411);
    V411 = elt(env, 1); /* AND */
    if (!(V412 == V411)) goto V22;
    V411 = stack[-4];
    V411 = qcdr(V411);
    V412 = lisp_true;
    if (V412 == nil) goto V22;
    V412 = nil;
    V413 = V412;
    stack[-1] = V411;
    goto V50;

V50:
    V411 = stack[-1];
    if (!consp(V411)) goto V53;
    V411 = stack[-1];
    if (!car_legal(V411)) goto V421;
    V411 = qcar(V411);
    V412 = V411;
    V411 = nil;
    if (!(V411 == nil)) goto V53;
    stack[0] = V413;
    V411 = V412;
    fn = elt(env, 12); /* BOOT::|evalMmStackInner| */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    V411 = Lnconc(nil, stack[0], V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    V413 = V411;
    V411 = stack[-1];
    if (!car_legal(V411)) goto V422;
    V411 = qcdr(V411);
    stack[-1] = V411;
    goto V50;

V53:
    V411 = V413;
    popv(7);
    { Lisp_Object retVal = ncons(V411);
    errexit();
    return onevalue(retVal); }

V22:
    V411 = stack[-4];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V83;
    V411 = stack[-4];
    V412 = qcar(V411);
    V411 = elt(env, 2); /* OR */
    if (!(V412 == V411)) goto V83;
    V411 = stack[-4];
    V411 = qcdr(V411);
    V412 = lisp_true;
    if (V412 == nil) goto V83;
    V412 = nil;
    V413 = V412;
    stack[-1] = V411;
    goto V110;

V110:
    V411 = stack[-1];
    if (!consp(V411)) { popv(7); return onevalue(V413); }
    V411 = stack[-1];
    if (!car_legal(V411)) goto V421;
    V411 = qcar(V411);
    V412 = V411;
    V411 = nil;
    if (!(V411 == nil)) { popv(7); return onevalue(V413); }
    stack[0] = V413;
    V411 = V412;
    V411 = CC_BOOT__evalMmStack(env, V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    fn = elt(env, 13); /* APPEND */
    V411 = (*qfn2(fn))(qenv(fn), stack[0], V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    V413 = V411;
    V411 = stack[-1];
    if (!car_legal(V411)) goto V422;
    V411 = qcdr(V411);
    stack[-1] = V411;
    goto V110;

V83:
    V411 = stack[-4];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V143;
    V411 = stack[-4];
    V412 = qcar(V411);
    V411 = elt(env, 3); /* BOOT::|partial| */
    if (!(V412 == V411)) goto V143;
    V411 = stack[-4];
    V411 = qcdr(V411);
    V412 = V411;
    V411 = lisp_true;
    if (V411 == nil) goto V143;
    V411 = V412;
    stack[-4] = V411;
    goto V1;

V143:
    V411 = stack[-4];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V163;
    V411 = stack[-4];
    V412 = qcar(V411);
    V411 = elt(env, 4); /* BOOT::|ofCategory| */
    if (!(V412 == V411)) goto V163;
    V411 = stack[-4];
    V411 = qcdr(V411);
    stack[-1] = V411;
    V411 = stack[-1];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V181;
    V411 = stack[-1];
    V411 = qcar(V411);
    stack[-5] = V411;
    V411 = stack[-1];
    V411 = qcdr(V411);
    stack[-1] = V411;
    V411 = stack[-1];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V194;
    V411 = stack[-1];
    V411 = qcdr(V411);
    if (V411 == nil) goto V204;
    V411 = nil;
    goto V180;

V180:
    if (V411 == nil) goto V163;
    V411 = stack[-3];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V163;
    V411 = stack[-3];
    V412 = qcar(V411);
    V411 = elt(env, 5); /* BOOT::|Join| */
    if (!(V412 == V411)) goto V163;
    V411 = stack[-3];
    V411 = qcdr(V411);
    V412 = lisp_true;
    if (V412 == nil) goto V163;
    stack[-3] = elt(env, 1); /* AND */
    V412 = nil;
    stack[-2] = V412;
    stack[-1] = V411;
    goto V243;

V243:
    V411 = stack[-1];
    if (!consp(V411)) goto V246;
    V411 = stack[-1];
    if (!car_legal(V411)) goto V421;
    V411 = qcar(V411);
    V412 = nil;
    if (!(V412 == nil)) goto V246;
    stack[0] = elt(env, 4); /* BOOT::|ofCategory| */
    V413 = stack[-5];
    V412 = V411;
    V411 = nil;
    V412 = list2star(V413, V412, V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    V411 = stack[-2];
    V411 = acons(stack[0], V412, V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    stack[-2] = V411;
    V411 = stack[-1];
    if (!car_legal(V411)) goto V422;
    V411 = qcdr(V411);
    stack[-1] = V411;
    goto V243;

V246:
    V411 = stack[-2];
    fn = elt(env, 14); /* NREVERSE0 */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    V411 = cons(stack[-3], V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    stack[-4] = V411;
    goto V1;

V163:
    V411 = stack[-4];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V289;
    V411 = stack[-4];
    V412 = qcar(V411);
    V411 = elt(env, 6); /* BOOT::|ofType| */
    if (!(V412 == V411)) goto V289;
    V411 = nil;
    popv(7);
    { Lisp_Object retVal = ncons(V411);
    errexit();
    return onevalue(retVal); }

V289:
    V411 = stack[-4];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V305;
    V411 = stack[-4];
    V412 = qcar(V411);
    V411 = elt(env, 7); /* BOOT::|has| */
    if (!(V412 == V411)) goto V305;
    V411 = stack[-4];
    V411 = qcdr(V411);
    stack[-1] = V411;
    V411 = stack[-1];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V323;
    V411 = stack[-1];
    V411 = qcar(V411);
    stack[-2] = V411;
    V411 = stack[-1];
    V411 = qcdr(V411);
    stack[-1] = V411;
    V411 = stack[-1];
    fn = elt(env, 11); /* CONSP */
    V411 = (*qfn1(fn))(qenv(fn), V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    if (V411 == nil) goto V336;
    V411 = stack[-1];
    V411 = qcdr(V411);
    if (V411 == nil) goto V346;
    V411 = nil;
    goto V322;

V322:
    if (V411 == nil) goto V305;
    V412 = stack[0];
    V411 = elt(env, 8); /* (BOOT::ATTRIBUTE BOOT::SIGNATURE) */
    V411 = Lmemq(nil, V412, V411);
    if (V411 == nil) goto V354;
    stack[-3] = elt(env, 4); /* BOOT::|ofCategory| */
    stack[-4] = stack[-2];
    stack[-2] = elt(env, 9); /* BOOT::CATEGORY */
    stack[-1] = elt(env, 10); /* BOOT::|unknown| */
    V411 = stack[0];
    V411 = ncons(V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    V411 = list2star(stack[-2], stack[-1], V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    V411 = ncons(V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    V411 = list2star(stack[-3], stack[-4], V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    V411 = ncons(V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    popv(7);
    { Lisp_Object retVal = ncons(V411);
    errexit();
    return onevalue(retVal); }

V354:
    V411 = lisp_true;
    if (V411 == nil) goto V389;
    stack[-1] = elt(env, 4); /* BOOT::|ofCategory| */
    V411 = stack[0];
    V411 = ncons(V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    env = stack[-6];
    V411 = list2star(stack[-1], stack[-2], V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    popv(7);
    { Lisp_Object retVal = ncons(V411);
    errexit();
    return onevalue(retVal); }

V389:
    V411 = nil;
    { popv(7); return onevalue(V411); }

V305:
    V411 = lisp_true;
    if (V411 == nil) goto V405;
    V411 = stack[-4];
    V411 = ncons(V411);
    nil = C_nil;
    if (exception_pending()) goto V420;
    popv(7);
    { Lisp_Object retVal = ncons(V411);
    errexit();
    return onevalue(retVal); }

V405:
    V411 = nil;
    { popv(7); return onevalue(V411); }

V346:
    V411 = stack[-1];
    V411 = qcar(V411);
    stack[0] = V411;
    V411 = lisp_true;
    goto V322;

V336:
    V411 = nil;
    goto V322;

V323:
    V411 = nil;
    goto V322;

V204:
    V411 = stack[-1];
    V411 = qcar(V411);
    stack[-3] = V411;
    V411 = lisp_true;
    goto V180;

V194:
    V411 = nil;
    goto V180;

V181:
    V411 = nil;
    goto V180;
/* error exit handlers */
V422:
    popv(7);
    return error(1, err_bad_cdr, V411);
V421:
    popv(7);
    return error(1, err_bad_car, V411);
V420:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::|EXPR;commonk0| (|x| |y| |$|)
   (PROG (|k| #:G82432 BOOT::|ans|)
      (RETURN
         (SEQ
            (BOOT::LETT BOOT::|ans| NIL BOOT::|EXPR;commonk0|)
            (SEQ
               (BOOT::LETT |k| NIL BOOT::|EXPR;commonk0|)
               (BOOT::LETT #:G82432 (NREVERSE |x|) BOOT::|EXPR;commonk0|)
               BOOT::G190
               (COND
                  ((OR
                      (ATOM #:G82432)
                      (PROGN
                         (BOOT::LETT
                            |k|
                            (CAR #:G82432)
                            BOOT::|EXPR;commonk0|)
                         NIL))
                     (GO BOOT::G191)))
               (SEQ
                  (EXIT
                     (COND
                        ((BOOT:SPADCALL |k| |y| (VMLISP:QREFELT |$| 112))
                           (BOOT::LETT
                              BOOT::|ans|
                              (BOOT:SPADCALL
                                 |k|
                                 BOOT::|ans|
                                 (VMLISP:QREFELT |$| 113))
                              BOOT::|EXPR;commonk0|)))) )
               (BOOT::LETT #:G82432 (CDR #:G82432) BOOT::|EXPR;commonk0|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT BOOT::|ans|)))) )

*/



/* Code for BOOT::|EXPR;commonk0| */

static Lisp_Object MS_CDECL CC_BOOT__EXPRUcommonk0(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V100, V101, V102, V103;
    Lisp_Object fn;
    argcheck(nargs, 3, "EXPR;commonk0");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;commonk0|\n");
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
    V101 = V2;
/* end of prologue */
    V100 = nil;
    stack[0] = V100;
    V100 = V101;
    fn = elt(env, 1); /* NREVERSE */
    V100 = (*qfn1(fn))(qenv(fn), V100);
    nil = C_nil;
    if (exception_pending()) goto V109;
    env = stack[-5];
    stack[-1] = V100;
    goto V18;

V18:
    V100 = stack[-1];
    if (!consp(V100)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    V100 = stack[-1];
    if (!car_legal(V100)) goto V110;
    V100 = qcar(V100);
    stack[-4] = V100;
    V100 = nil;
    if (!(V100 == nil)) { Lisp_Object res = stack[0]; popv(6); return onevalue(res); }
    V101 = stack[-2];
    V100 = (Lisp_Object)1793; /* 112 */
    V100 = Lgetv(nil, V101, V100);
    nil = C_nil;
    if (exception_pending()) goto V109;
    env = stack[-5];
    V101 = V100;
    if (!car_legal(V101)) goto V111;
    V103 = qcar(V101);
    V102 = stack[-4];
    V101 = stack[-3];
    if (!car_legal(V100)) goto V112;
    V100 = qcdr(V100);
    V100 = Lapply3(nil, 4, V103, V102, V101, V100);
    nil = C_nil;
    if (exception_pending()) goto V109;
    env = stack[-5];
    if (V100 == nil) goto V34;
    V101 = stack[-2];
    V100 = (Lisp_Object)1809; /* 113 */
    V100 = Lgetv(nil, V101, V100);
    nil = C_nil;
    if (exception_pending()) goto V109;
    env = stack[-5];
    V101 = V100;
    if (!car_legal(V101)) goto V111;
    V103 = qcar(V101);
    V102 = stack[-4];
    V101 = stack[0];
    if (!car_legal(V100)) goto V112;
    V100 = qcdr(V100);
    V100 = Lapply3(nil, 4, V103, V102, V101, V100);
    nil = C_nil;
    if (exception_pending()) goto V109;
    env = stack[-5];
    stack[0] = V100;
    goto V34;

V34:
    V100 = stack[-1];
    if (!car_legal(V100)) goto V112;
    V100 = qcdr(V100);
    stack[-1] = V100;
    goto V18;
/* error exit handlers */
V112:
    popv(6);
    return error(1, err_bad_cdr, V100);
V111:
    popv(6);
    return error(1, err_bad_car, V101);
V110:
    popv(6);
    return error(1, err_bad_car, V100);
V109:
    popv(6);
    return nil;
}

/*
(DEFUN BOOT::|get0| (|x| BOOT::|prop| |e|)
   (PROG (BOOT::|tail| |u|)
      (RETURN
         (COND
            ((NULL (ATOM |x|)) (BOOT::|get| (QCAR |x|) BOOT::|prop| |e|))
            ((BOOT:SPADLET |u| (BOOT:QLASSQ |x| (CAR (QCAR |e|))))
               (BOOT:QLASSQ BOOT::|prop| |u|))
            ((AND
                (BOOT:SPADLET BOOT::|tail| (CDR (QCAR |e|)))
                (BOOT:SPADLET
                   |u|
                   (BOOT::|fastSearchCurrentEnv| |x| BOOT::|tail|)))
               (BOOT:QLASSQ BOOT::|prop| |u|))
            ('T NIL)))) )

*/



/* Code for BOOT::|get0| */

static Lisp_Object MS_CDECL CC_BOOT__get0(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V76, V77, V78;
    Lisp_Object fn;
    argcheck(nargs, 3, "get0");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|get0|\n");
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
    V76 = stack[-2];
    if (!consp(V76)) goto V32;
    V76 = stack[-2];
    V78 = qcar(V76);
    V77 = stack[-1];
    V76 = stack[0];
    {
        popv(4);
        fn = elt(env, 1); /* BOOT::|get| */
        return (*qfnn(fn))(qenv(fn), 3, V78, V77, V76);
    }

V32:
    V77 = stack[-2];
    V76 = stack[0];
    V76 = qcar(V76);
    if (!car_legal(V76)) goto V82;
    V76 = qcar(V76);
    fn = elt(env, 2); /* BOOT:QLASSQ */
    V77 = (*qfn2(fn))(qenv(fn), V77, V76);
    nil = C_nil;
    if (exception_pending()) goto V83;
    env = stack[-3];
    V76 = V77;
    if (V77 == nil) goto V30;
    V77 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* BOOT:QLASSQ */
        return (*qfn2(fn))(qenv(fn), V77, V76);
    }

V30:
    V76 = stack[0];
    V76 = qcar(V76);
    if (!car_legal(V76)) goto V84;
    V77 = qcdr(V76);
    V76 = V77;
    if (V77 == nil) goto V50;
    V77 = stack[-2];
    fn = elt(env, 3); /* BOOT::|fastSearchCurrentEnv| */
    V77 = (*qfn2(fn))(qenv(fn), V77, V76);
    nil = C_nil;
    if (exception_pending()) goto V83;
    env = stack[-3];
    V76 = V77;
    if (V77 == nil) goto V50;
    V77 = stack[-1];
    {
        popv(4);
        fn = elt(env, 2); /* BOOT:QLASSQ */
        return (*qfn2(fn))(qenv(fn), V77, V76);
    }

V50:
    V76 = lisp_true;
    if (V76 == nil) goto V73;
    V76 = nil;
    { popv(4); return onevalue(V76); }

V73:
    V76 = nil;
    { popv(4); return onevalue(V76); }
/* error exit handlers */
V84:
    popv(4);
    return error(1, err_bad_cdr, V76);
V83:
    popv(4);
    return nil;
V82:
    popv(4);
    return error(1, err_bad_car, V76);
}

/*
(DEFUN BOOT::|sigDomainVal| (BOOT::|dollar| BOOT::|domain| BOOT::|index|)
   (COND
      ((EQL BOOT::|index| 0) '|$|)
      ((EQL BOOT::|index| 2) BOOT::|domain|)
      ('T (ELT BOOT::|domain| BOOT::|index|))))

*/



/* Code for BOOT::|sigDomainVal| */

static Lisp_Object MS_CDECL CC_BOOT__sigDomainVal(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V43, V44, V45, V46;
    Lisp_Object fn;
    argcheck(nargs, 3, "sigDomainVal");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|sigDomainVal|\n");
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
    V43 = V2;
/* end of prologue */
    V46 = V44;
    V43 = (Lisp_Object)1; /* 0 */
    V43 = Leql(nil, V46, V43);
    env = stack[0];
    if (V43 == nil) goto V24;
    V43 = elt(env, 1); /* BOOT::$ */
    { popv(1); return onevalue(V43); }

V24:
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
        fn = elt(env, 2); /* ELT */
        return (*qfn2(fn))(qenv(fn), V43, V44);
    }

V33:
    V43 = nil;
    { popv(1); return onevalue(V43); }
}

/*
(DEFUN BOOT::|FSAGG-;brace;LA;3| (|l| |$|)
   (BOOT:SPADCALL |l| (VMLISP:QREFELT |$| 18)))

*/



/* Code for BOOT::|FSAGG-;brace;LA;3| */

static Lisp_Object CC_BOOT__FSAGGKUbraceULAU3(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FSAGG-;brace;LA;3|\n");
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
    V31 = (Lisp_Object)289; /* 18 */
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
(DEFUN BOOT::|MONOID-;one?;SB;2| (|x| |$|)
   (BOOT:SPADCALL
      |x|
      (BOOT::|spadConstant| |$| 10)
      (VMLISP:QREFELT |$| 12)))

*/



/* Code for BOOT::|MONOID-;one?;SB;2| */

static Lisp_Object CC_BOOT__MONOIDKUoneWUSBU2(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V54, V55;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|MONOID-;one?;SB;2|\n");
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
    V54 = (Lisp_Object)193; /* 12 */
    V54 = Lgetv(nil, V55, V54);
    nil = C_nil;
    if (exception_pending()) goto V60;
    env = stack[-4];
    stack[-3] = V54;
    V54 = stack[-3];
    if (!car_legal(V54)) goto V61;
    stack[0] = qcar(V54);
    V55 = stack[-1];
    V54 = (Lisp_Object)161; /* 10 */
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
(DEFUN BOOT::|STAGG-;c2| (|x| |r| |$|)
   (COND
      ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 17))
         (BOOT::|error| "Index out of range"))
      ('T (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 18)))) )

*/



/* Code for BOOT::|STAGG-;c2| */

static Lisp_Object MS_CDECL CC_BOOT__STAGGKUc2(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V65, V66, V67;
    Lisp_Object fn;
    argcheck(nargs, 3, "STAGG-;c2");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|STAGG-;c2|\n");
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
    V65 = V3;
    stack[-1] = V2;
/* end of prologue */
    V66 = stack[0];
    V65 = (Lisp_Object)273; /* 17 */
    V65 = Lgetv(nil, V66, V65);
    nil = C_nil;
    if (exception_pending()) goto V70;
    env = stack[-2];
    V66 = V65;
    if (!car_legal(V66)) goto V71;
    V67 = qcar(V66);
    V66 = stack[-1];
    if (!car_legal(V65)) goto V72;
    V65 = qcdr(V65);
    V65 = Lapply2(nil, 3, V67, V66, V65);
    nil = C_nil;
    if (exception_pending()) goto V70;
    env = stack[-2];
    if (V65 == nil) goto V11;
    V65 = elt(env, 1); /* "Index out of range" */
    {
        popv(3);
        fn = elt(env, 2); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V65);
    }

V11:
    V65 = lisp_true;
    if (V65 == nil) goto V39;
    V66 = stack[0];
    V65 = (Lisp_Object)289; /* 18 */
    V65 = Lgetv(nil, V66, V65);
    nil = C_nil;
    if (exception_pending()) goto V70;
    V66 = V65;
    if (!car_legal(V66)) goto V71;
    V67 = qcar(V66);
    V66 = stack[-1];
    if (!car_legal(V65)) goto V72;
    V65 = qcdr(V65);
        popv(3);
        return Lapply2(nil, 3, V67, V66, V65);

V39:
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
(DEFUN BOOT::|IFARRAY;#;$Nni;4| (|r| |$|)
   (PROG (#:G82538)
      (RETURN
         (PROG1
            (BOOT::LETT
               #:G82538
               (VMLISP:QVELT |r| 1)
               BOOT::|IFARRAY;#;$Nni;4|)
            (BOOT::|check-subtype|
               (|>=| #:G82538 0)
               '(BOOT:|NonNegativeInteger|)
               #:G82538)))) )

*/



/* Code for BOOT::|IFARRAY;#;$Nni;4| */

static Lisp_Object CC_BOOT__IFARRAYUZUDNniU4(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V45, V46;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;#;$Nni;4|\n");
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
    V46 = V2;
/* end of prologue */
    V45 = (Lisp_Object)17; /* 1 */
    V45 = Lgetv(nil, V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V49;
    env = stack[-2];
    stack[-1] = V45;
    stack[0] = V45;
    V46 = stack[-1];
    V45 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 2); /* >= */
    V45 = (*qfn2(fn))(qenv(fn), V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V49;
    env = stack[-2];
    if (!(V45 == nil)) { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
    V46 = stack[-1];
    V45 = elt(env, 1); /* (BOOT:|NonNegativeInteger|) */
    fn = elt(env, 3); /* BOOT::COERCE-FAILURE-MSG */
    V45 = (*qfn2(fn))(qenv(fn), V46, V45);
    nil = C_nil;
    if (exception_pending()) goto V49;
    env = stack[-2];
    fn = elt(env, 4); /* BOOT::|error| */
    V45 = (*qfn1(fn))(qenv(fn), V45);
    nil = C_nil;
    if (exception_pending()) goto V49;
    { Lisp_Object res = stack[0]; popv(3); return onevalue(res); }
/* error exit handlers */
V49:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|IDPAM;map;M2$;7| (|f| |x| |$|)
   (PROG (#:G82540 BOOT::|tm| #:G82541 |a|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT::LETT #:G82540 NIL BOOT::|IDPAM;map;M2$;7|)
               (SEQ
                  (BOOT::LETT BOOT::|tm| NIL BOOT::|IDPAM;map;M2$;7|)
                  (BOOT::LETT #:G82541 |x| BOOT::|IDPAM;map;M2$;7|)
                  BOOT::G190
                  (COND
                     ((OR
                         (ATOM #:G82541)
                         (PROGN
                            (BOOT::LETT
                               BOOT::|tm|
                               (CAR #:G82541)
                               BOOT::|IDPAM;map;M2$;7|)
                            NIL))
                        (GO BOOT::G191)))
                  (SEQ
                     (EXIT
                        (COND
                           ((SEQ
                               (BOOT::LETT
                                  |a|
                                  (BOOT:SPADCALL (QCDR BOOT::|tm|) |f|)
                                  BOOT::|IDPAM;map;M2$;7|)
                               (EXIT
                                  (COND
                                     ((BOOT:SPADCALL
                                         |a|
                                         (BOOT::|spadConstant| |$| 18)
                                         (VMLISP:QREFELT |$| 21))
                                        'NIL)
                                     ('T 'T))))
                              (BOOT::LETT
                                 #:G82540
                                 (CONS
                                    (CONS (QCAR BOOT::|tm|) |a|)
                                    #:G82540)
                                 BOOT::|IDPAM;map;M2$;7|)))) )
                  (BOOT::LETT
                     #:G82541
                     (CDR #:G82541)
                     BOOT::|IDPAM;map;M2$;7|)
                  (GO BOOT::G190)
                  BOOT::G191
                  (EXIT (NREVERSE0 #:G82540)))) ))) )

*/



/* Code for BOOT::|IDPAM;map;M2$;7| */

static Lisp_Object MS_CDECL CC_BOOT__IDPAMUmapUM2DU7(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V135, V136, V137;
    Lisp_Object fn;
    argcheck(nargs, 3, "IDPAM;map;M2$;7");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IDPAM;map;M2$;7|\n");
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
    V136 = V3;
    stack[-7] = V2;
/* end of prologue */
    V135 = nil;
    stack[-8] = V135;
    V135 = V136;
    stack[-4] = V135;
    goto V19;

V19:
    V135 = stack[-4];
    if (!consp(V135)) goto V20;
    V135 = stack[-4];
    if (!car_legal(V135)) goto V147;
    V135 = qcar(V135);
    stack[-5] = V135;
    V135 = nil;
    if (!(V135 == nil)) goto V20;
    V135 = stack[-7];
    V136 = V135;
    if (!car_legal(V136)) goto V148;
    V137 = qcar(V136);
    V136 = stack[-5];
    V136 = qcdr(V136);
    if (!car_legal(V135)) goto V149;
    V135 = qcdr(V135);
    V135 = Lapply2(nil, 3, V137, V136, V135);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-9];
    stack[-3] = V135;
    V136 = stack[-6];
    V135 = (Lisp_Object)337; /* 21 */
    V135 = Lgetv(nil, V136, V135);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-9];
    stack[-2] = V135;
    V135 = stack[-2];
    if (!car_legal(V135)) goto V147;
    stack[-1] = qcar(V135);
    stack[0] = stack[-3];
    V136 = stack[-6];
    V135 = (Lisp_Object)289; /* 18 */
    V135 = Lgetv(nil, V136, V135);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-9];
    V136 = V135;
    if (!car_legal(V136)) goto V148;
    V136 = qcar(V136);
    if (!car_legal(V135)) goto V149;
    V135 = qcdr(V135);
    V135 = Lapply1(nil, V136, V135);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-9];
    V136 = V135;
    V135 = stack[-2];
    if (!car_legal(V135)) goto V149;
    V135 = qcdr(V135);
    V135 = Lapply3(nil, 4, stack[-1], stack[0], V136, V135);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-9];
    if (V135 == nil) goto V62;
    V135 = nil;
    goto V40;

V40:
    if (V135 == nil) goto V34;
    V135 = stack[-5];
    V137 = qcar(V135);
    V136 = stack[-3];
    V135 = stack[-8];
    V135 = acons(V137, V136, V135);
    nil = C_nil;
    if (exception_pending()) goto V150;
    env = stack[-9];
    stack[-8] = V135;
    goto V34;

V34:
    V135 = stack[-4];
    if (!car_legal(V135)) goto V149;
    V135 = qcdr(V135);
    stack[-4] = V135;
    goto V19;

V62:
    V135 = lisp_true;
    if (V135 == nil) goto V112;
    V135 = lisp_true;
    goto V40;

V112:
    V135 = nil;
    goto V40;

V20:
    V135 = stack[-8];
    {
        popv(10);
        fn = elt(env, 1); /* NREVERSE0 */
        return (*qfn1(fn))(qenv(fn), V135);
    }
/* error exit handlers */
V150:
    popv(10);
    return nil;
V149:
    popv(10);
    return error(1, err_bad_cdr, V135);
V148:
    popv(10);
    return error(1, err_bad_car, V136);
V147:
    popv(10);
    return error(1, err_bad_car, V135);
}

/*
(DEFUN BOOT::|resolveTMEq| (|t| |m|)
   (PROG (BOOT::|res| BOOT::|cm| BOOT::|argm| |c| BOOT::|LETTMP#1|
         BOOT::|ct| BOOT::|argt| BOOT::SL |b| BOOT:TL)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADLET
                   BOOT::|res|
                   (BOOT::|resolveTMSpecial| |t| |m|))
                  BOOT::|res|)
               ('T
                  (BOOT:SPADLET
                     BOOT::|LETTMP#1|
                     (BOOT::|deconstructT| |m|))
                  (BOOT:SPADLET BOOT::|cm| (CAR BOOT::|LETTMP#1|))
                  (BOOT:SPADLET BOOT::|argm| (CDR BOOT::|LETTMP#1|))
                  (BOOT:SPADLET |c| (BOOT::|containsVars| BOOT::|cm|))
                  (BOOT:SPADLET BOOT:TL NIL)
                  (DO ((#:G18901 NIL (OR |b| (NULL |t|))))
                     (#:G18901 NIL)
                     (SEQ
                        (EXIT
                           (PROGN
                              (BOOT:SPADLET
                                 BOOT::|LETTMP#1|
                                 (BOOT::|deconstructT| |t|))
                              (BOOT:SPADLET
                                 BOOT::|ct|
                                 (CAR BOOT::|LETTMP#1|))
                              (BOOT:SPADLET
                                 BOOT::|argt|
                                 (CDR BOOT::|LETTMP#1|))
                              (BOOT:SPADLET
                                 |b|
                                 (COND
                                    (|c|
                                       (BOOT:SPADLET
                                          BOOT::SL
                                          (BOOT::|resolveTMEq1|
                                             BOOT::|ct|
                                             BOOT::|cm|))
                                       (NULL
                                          (EQ BOOT::SL 'BOOT::|failed|)))
                                    ('T
                                       (BOOT:|BOOT-EQUAL|
                                          BOOT::|ct|
                                          BOOT::|cm|))))
                              (COND
                                 ((NULL |b|)
                                    (PROGN
                                       (BOOT:SPADLET
                                          BOOT:TL
                                          (CONS
                                             BOOT::|ct|
                                             (CONS BOOT::|argt| BOOT:TL)))
                                       (BOOT:SPADLET
                                          |t|
                                          (AND
                                             BOOT::|argt|
                                             (VMLISP:|last|
                                                BOOT::|argt|)))) ))) )))
                  (AND
                     |b|
                     (PROGN
                        (BOOT:SPADLET
                           |t|
                           (BOOT::|resolveTMEq2|
                              BOOT::|cm|
                              BOOT::|argm|
                              (CONS
                                 BOOT::|ct|
                                 (CONS BOOT::|argt| BOOT:TL))))
                        (COND
                           (|t|
                              (DO ((#:G18900 BOOT::SL (CDR #:G18900))
                                    (|p| NIL))
                                 ((OR
                                     (ATOM #:G18900)
                                     (PROGN (SETQ |p| (CAR #:G18900)) NIL))
                                    NIL)
                                 (SEQ
                                    (EXIT
                                       (BOOT:SPADLET
                                          BOOT::|$Subst|
                                          (BOOT::|augmentSub|
                                             (CAR |p|)
                                             (CDR |p|)
                                             BOOT::|$Subst|)))) )))
                        |t|)))) ))) )

*/



/* Code for BOOT::|resolveTMEq| */

static Lisp_Object CC_BOOT__resolveTMEq(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V216, V217, V218;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|resolveTMEq|\n");
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
    stack[0] = V3;
    stack[-7] = V2;
/* end of prologue */
    stack[-4] = nil;
    stack[-3] = nil;
    stack[-2] = nil;
    stack[-1] = nil;
    V217 = stack[-7];
    V216 = stack[0];
    fn = elt(env, 3); /* BOOT::|resolveTMSpecial| */
    V216 = (*qfn2(fn))(qenv(fn), V217, V216);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-9];
    V217 = V216;
    if (!(V216 == nil)) { popv(10); return onevalue(V217); }
    V216 = lisp_true;
    if (V216 == nil) goto V35;
    V216 = stack[0];
    fn = elt(env, 4); /* BOOT::|deconstructT| */
    V216 = (*qfn1(fn))(qenv(fn), V216);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-9];
    V217 = V216;
    V216 = V217;
    if (!car_legal(V216)) goto V229;
    V216 = qcar(V216);
    stack[-8] = V216;
    V216 = V217;
    if (!car_legal(V216)) goto V230;
    V216 = qcdr(V216);
    stack[-6] = V216;
    V216 = stack[-8];
    fn = elt(env, 5); /* BOOT::|containsVars| */
    V216 = (*qfn1(fn))(qenv(fn), V216);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-9];
    stack[-5] = V216;
    V216 = nil;
    stack[0] = V216;
    V216 = nil;
    goto V51;

V51:
    if (V216 == nil) goto V53;
    V216 = stack[-1];
    if (V216 == nil) goto V140;
    stack[-1] = stack[-8];
    stack[-5] = stack[-6];
    V218 = stack[-4];
    V217 = stack[-3];
    V216 = stack[0];
    V216 = list2star(V218, V217, V216);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-9];
    fn = elt(env, 6); /* BOOT::|resolveTMEq2| */
    V216 = (*qfnn(fn))(qenv(fn), 3, stack[-1], stack[-5], V216);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-9];
    stack[-7] = V216;
    V216 = stack[-7];
    if (V216 == nil) { Lisp_Object res = stack[-7]; popv(10); return onevalue(res); }
    V216 = stack[-2];
    stack[0] = V216;
    goto V178;

V178:
    V216 = stack[0];
    if (!consp(V216)) { Lisp_Object res = stack[-7]; popv(10); return onevalue(res); }
    V216 = stack[0];
    if (!car_legal(V216)) goto V229;
    V216 = qcar(V216);
    V217 = nil;
    if (!(V217 == nil)) { Lisp_Object res = stack[-7]; popv(10); return onevalue(res); }
    V217 = V216;
    if (!car_legal(V217)) goto V231;
    V218 = qcar(V217);
    if (!car_legal(V216)) goto V230;
    V217 = qcdr(V216);
    V216 = qvalue(elt(env, 2)); /* BOOT::|$Subst| */
    fn = elt(env, 7); /* BOOT::|augmentSub| */
    V216 = (*qfnn(fn))(qenv(fn), 3, V218, V217, V216);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-9];
    qvalue(elt(env, 2)) = V216; /* BOOT::|$Subst| */
    V216 = stack[0];
    if (!car_legal(V216)) goto V230;
    V216 = qcdr(V216);
    stack[0] = V216;
    goto V178;

V140:
    V216 = nil;
    { popv(10); return onevalue(V216); }

V53:
    V216 = stack[-7];
    fn = elt(env, 4); /* BOOT::|deconstructT| */
    V216 = (*qfn1(fn))(qenv(fn), V216);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-9];
    V217 = V216;
    V216 = V217;
    if (!car_legal(V216)) goto V229;
    V216 = qcar(V216);
    stack[-4] = V216;
    V216 = V217;
    if (!car_legal(V216)) goto V230;
    V216 = qcdr(V216);
    stack[-3] = V216;
    V216 = stack[-5];
    if (V216 == nil) goto V70;
    V217 = stack[-4];
    V216 = stack[-8];
    fn = elt(env, 8); /* BOOT::|resolveTMEq1| */
    V216 = (*qfn2(fn))(qenv(fn), V217, V216);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-9];
    stack[-2] = V216;
    V217 = stack[-2];
    V216 = elt(env, 1); /* BOOT::|failed| */
    V216 = (V217 == V216 ? lisp_true : nil);
    V216 = (V216 == nil ? lisp_true : nil);
    goto V68;

V68:
    stack[-1] = V216;
    V216 = stack[-1];
    if (!(V216 == nil)) goto V60;
    V218 = stack[-4];
    V217 = stack[-3];
    V216 = stack[0];
    V216 = list2star(V218, V217, V216);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-9];
    stack[0] = V216;
    V216 = stack[-3];
    if (V216 == nil) goto V118;
    V216 = stack[-3];
    fn = elt(env, 9); /* VMLISP:|last| */
    V216 = (*qfn1(fn))(qenv(fn), V216);
    nil = C_nil;
    if (exception_pending()) goto V228;
    env = stack[-9];
    goto V117;

V117:
    stack[-7] = V216;
    goto V60;

V60:
    V216 = stack[-1];
    if (!(V216 == nil)) goto V51;
    V216 = stack[-7];
    V216 = (V216 == nil ? lisp_true : nil);
    goto V51;

V118:
    V216 = nil;
    goto V117;

V70:
    V216 = lisp_true;
    if (V216 == nil) goto V90;
    V217 = stack[-4];
    V216 = stack[-8];
    V216 = (cl_equal(V217, V216) ? lisp_true : nil);
    goto V68;

V90:
    V216 = nil;
    goto V68;

V35:
    V216 = nil;
    { popv(10); return onevalue(V216); }
/* error exit handlers */
V231:
    popv(10);
    return error(1, err_bad_car, V217);
V230:
    popv(10);
    return error(1, err_bad_cdr, V216);
V229:
    popv(10);
    return error(1, err_bad_car, V216);
V228:
    popv(10);
    return nil;
}



setup_type const u08_setup[] =
{
    {"BOOT@@PGCD;gcd;3P;15@@Builtin",wrong_no_na,wrong_no_nb,  (n_args *)CC_BOOT__PGCDUgcdU3PU15},
    {"BOOT@@filterModemapsFromPackages@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__filterModemapsFromPackages},
    {"BOOT@@selectMmsGen,matchMms@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__selectMmsGenPmatchMms},
    {"BOOT@@BOP;<;2$B;29@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__BOPURU2DBU29},
    {"BOOT@@evalMmStack@@Builtin",CC_BOOT__evalMmStack,too_many_1,wrong_no_1},
    {"BOOT@@EXPR;commonk0@@Builtin",wrong_no_na,wrong_no_nb,   (n_args *)CC_BOOT__EXPRUcommonk0},
    {"BOOT@@get0@@Builtin",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__get0},
    {"BOOT@@sigDomainVal@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__sigDomainVal},
    {"BOOT@@FSAGG-;brace;LA;3@@Builtin",too_few_2,CC_BOOT__FSAGGKUbraceULAU3,wrong_no_2},
    {"BOOT@@MONOID-;one?;SB;2@@Builtin",too_few_2,CC_BOOT__MONOIDKUoneWUSBU2,wrong_no_2},
    {"BOOT@@STAGG-;c2@@Builtin",wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__STAGGKUc2},
    {"BOOT@@IFARRAY;#;$Nni;4@@Builtin",too_few_2,CC_BOOT__IFARRAYUZUDNniU4,wrong_no_2},
    {"BOOT@@IDPAM;map;M2$;7@@Builtin",wrong_no_na,wrong_no_nb, (n_args *)CC_BOOT__IDPAMUmapUM2DU7},
    {"BOOT@@resolveTMEq@@Builtin",too_few_2,    CC_BOOT__resolveTMEq,wrong_no_2},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
