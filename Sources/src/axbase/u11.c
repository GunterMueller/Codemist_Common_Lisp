
/* u11.c                 Machine generated C code */

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
(DEFUN BOOT::|resolveTM1| (|t| |m|)
   (PROG (|p| BOOT::|tr| BOOT::|mr| BOOT::|ISTMP#1| BOOT::|tt|)
      (RETURN
         (COND
            ((BOOT:|BOOT-EQUAL| |t| |m|) |t|)
            ((AND (PAIRP |m|) (EQ (QCAR |m|) 'BOOT::|Union|))
               (BOOT::|resolveTMUnion| |t| |m|))
            ((BOOT:|BOOT-EQUAL| |m| '(BOOT::|Void|)) |m|)
            ((BOOT:|BOOT-EQUAL| |m| '(BOOT::|Any|)) |m|)
            ((BOOT:|BOOT-EQUAL| |m| '(BOOT::|Exit|)) |t|)
            ((BOOT::|containsVars| |m|)
               (COND
                  ((BOOT::|isPatternVar| |m|)
                     (COND
                        ((BOOT:SPADLET
                            |p|
                            (VMLISP:ASSQ |m| BOOT::|$Subst|))
                           (COND
                              (BOOT::|$Coerce|
                                 (COND
                                    ((BOOT:SPADLET
                                        BOOT::|tt|
                                        (BOOT::|resolveTT1| |t| (CDR |p|)))
                                       (AND
                                          (RPLACD |p| BOOT::|tt|)
                                          BOOT::|tt|))
                                    ('T NIL)))
                              ('T
                                 (AND
                                    (BOOT:|BOOT-EQUAL| |t| (CDR |p|))
                                    |t|))))
                        ('T
                           (BOOT:SPADLET
                              BOOT::|$Subst|
                              (CONS (CONS |m| |t|) BOOT::|$Subst|))
                           |t|)))
                  ((OR (ATOM |t|) (ATOM |m|)) NIL)
                  ((AND
                      (PAIRP |t|)
                      (EQ (QCAR |t|) 'BOOT::|Record|)
                      (PROGN (BOOT:SPADLET BOOT::|tr| (QCDR |t|)) 'T)
                      (PAIRP |m|)
                      (EQ (QCAR |m|) 'BOOT::|Record|)
                      (PROGN (BOOT:SPADLET BOOT::|mr| (QCDR |m|)) 'T)
                      (BOOT:SPADLET
                         BOOT::|tt|
                         (BOOT::|resolveTMRecord| BOOT::|tr| BOOT::|mr|)))
                     BOOT::|tt|)
                  ((OR
                      (AND (PAIRP |t|) (EQ (QCAR |t|) 'BOOT::|Record|))
                      (AND (PAIRP |m|) (EQ (QCAR |m|) 'BOOT::|Record|)))
                     NIL)
                  ((AND
                      (PAIRP |t|)
                      (EQ (QCAR |t|) 'BOOT::|Variable|)
                      (PROGN
                         (BOOT:SPADLET BOOT::|ISTMP#1| (QCDR |t|))
                         (AND
                            (PAIRP BOOT::|ISTMP#1|)
                            (EQ (QCDR BOOT::|ISTMP#1|) NIL)))
                      (PAIRP |m|)
                      (EQ (QCAR |m|) 'BOOT::|Mapping|))
                     |m|)
                  ((AND
                      (PAIRP |t|)
                      (EQ (QCAR |t|) 'BOOT::|FunctionCalled|)
                      (PROGN
                         (BOOT:SPADLET BOOT::|ISTMP#1| (QCDR |t|))
                         (AND
                            (PAIRP BOOT::|ISTMP#1|)
                            (EQ (QCDR BOOT::|ISTMP#1|) NIL)))
                      (PAIRP |m|)
                      (EQ (QCAR |m|) 'BOOT::|Mapping|))
                     |m|)
                  ('T
                     (COND
                        ((BOOT::|isEqualOrSubDomain| |t| BOOT:|$Integer|)
                           (BOOT:SPADLET |t| BOOT:|$Integer|)))
                     (COND
                        ((BOOT:SPADLET
                            BOOT::|tt|
                            (BOOT::|resolveTMEq| |t| |m|))
                           BOOT::|tt|)
                        ('T
                           (AND
                              BOOT::|$Coerce|
                              (COND
                                 ((BOOT:SPADLET
                                     BOOT::|tt|
                                     (BOOT::|resolveTMRed| |t| |m|))
                                    BOOT::|tt|)
                                 ('T (BOOT::|resolveTM2| |t| |m|)))) ))) ))
            ('T
               (AND
                  BOOT::|$Coerce|
                  (BOOT::|canCoerceFrom| |t| |m|)
                  |m|)))) ))

*/



/* Code for BOOT::|resolveTM1| */

static Lisp_Object CC_BOOT__resolveTM1(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V428, V429, V430;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|resolveTM1|\n");
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
    V429 = stack[-2];
    V428 = stack[-1];
    V428 = (cl_equal(V429, V428) ? lisp_true : nil);
    if (!(V428 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    V428 = stack[-1];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V51;
    V428 = stack[-1];
    V429 = qcar(V428);
    V428 = elt(env, 1); /* BOOT::|Union| */
    if (!(V429 == V428)) goto V51;
    V429 = stack[-2];
    V428 = stack[-1];
    {
        popv(5);
        fn = elt(env, 13); /* BOOT::|resolveTMUnion| */
        return (*qfn2(fn))(qenv(fn), V429, V428);
    }

V51:
    V429 = stack[-1];
    V428 = elt(env, 2); /* (BOOT::|Void|) */
    V428 = (cl_equal(V429, V428) ? lisp_true : nil);
    if (!(V428 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    V429 = stack[-1];
    V428 = elt(env, 3); /* (BOOT::|Any|) */
    V428 = (cl_equal(V429, V428) ? lisp_true : nil);
    if (!(V428 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    V429 = stack[-1];
    V428 = elt(env, 4); /* (BOOT::|Exit|) */
    V428 = (cl_equal(V429, V428) ? lisp_true : nil);
    if (!(V428 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    V428 = stack[-1];
    fn = elt(env, 14); /* BOOT::|containsVars| */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V83;
    V428 = stack[-1];
    fn = elt(env, 15); /* BOOT::|isPatternVar| */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V89;
    V429 = stack[-1];
    V428 = qvalue(elt(env, 5)); /* BOOT::|$Subst| */
    V428 = Latsoc(nil, V429, V428);
    stack[-3] = V428;
    if (V428 == nil) goto V95;
    V428 = qvalue(elt(env, 6)); /* BOOT::|$Coerce| */
    if (V428 == nil) goto V107;
    V429 = stack[-2];
    V428 = stack[-3];
    if (!car_legal(V428)) goto V436;
    V428 = qcdr(V428);
    fn = elt(env, 16); /* BOOT::|resolveTT1| */
    V428 = (*qfn2(fn))(qenv(fn), V429, V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    stack[0] = V428;
    if (V428 == nil) goto V112;
    V429 = stack[-3];
    V428 = stack[0];
    V428 = Lrplacd(nil, V429, V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    if (!(V428 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    V428 = nil;
    { popv(5); return onevalue(V428); }

V112:
    V428 = lisp_true;
    if (V428 == nil) goto V139;
    V428 = nil;
    { popv(5); return onevalue(V428); }

V139:
    V428 = nil;
    { popv(5); return onevalue(V428); }

V107:
    V428 = lisp_true;
    if (V428 == nil) goto V143;
    V429 = stack[-2];
    V428 = stack[-3];
    if (!car_legal(V428)) goto V436;
    V428 = qcdr(V428);
    V428 = (cl_equal(V429, V428) ? lisp_true : nil);
    if (!(V428 == nil)) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    V428 = nil;
    { popv(5); return onevalue(V428); }

V143:
    V428 = nil;
    { popv(5); return onevalue(V428); }

V95:
    V428 = lisp_true;
    if (V428 == nil) goto V163;
    V430 = stack[-1];
    V429 = stack[-2];
    V428 = qvalue(elt(env, 5)); /* BOOT::|$Subst| */
    V428 = acons(V430, V429, V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    qvalue(elt(env, 5)) = V428; /* BOOT::|$Subst| */
    { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }

V163:
    V428 = nil;
    { popv(5); return onevalue(V428); }

V89:
    V428 = stack[-2];
    if (!consp(V428)) goto V177;
    V428 = stack[-1];
    if (!consp(V428)) goto V177;
    V428 = stack[-2];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V185;
    V428 = stack[-2];
    V429 = qcar(V428);
    V428 = elt(env, 7); /* BOOT::|Record| */
    if (!(V429 == V428)) goto V185;
    V428 = stack[-2];
    V428 = qcdr(V428);
    stack[0] = V428;
    V428 = lisp_true;
    if (V428 == nil) goto V185;
    V428 = stack[-1];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V185;
    V428 = stack[-1];
    V429 = qcar(V428);
    V428 = elt(env, 7); /* BOOT::|Record| */
    if (!(V429 == V428)) goto V185;
    V428 = stack[-1];
    V428 = qcdr(V428);
    V429 = lisp_true;
    if (V429 == nil) goto V185;
    V429 = stack[0];
    fn = elt(env, 17); /* BOOT::|resolveTMRecord| */
    V428 = (*qfn2(fn))(qenv(fn), V429, V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    stack[0] = V428;
    if (!(V428 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }

V185:
    V428 = stack[-2];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V230;
    V428 = stack[-2];
    V429 = qcar(V428);
    V428 = elt(env, 7); /* BOOT::|Record| */
    if (!(V429 == V428)) goto V230;

V228:
    V428 = nil;
    { popv(5); return onevalue(V428); }

V230:
    V428 = stack[-1];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V229;
    V428 = stack[-1];
    V429 = qcar(V428);
    V428 = elt(env, 7); /* BOOT::|Record| */
    if (V429 == V428) goto V228;
    else goto V229;

V229:
    V428 = stack[-2];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V258;
    V428 = stack[-2];
    V429 = qcar(V428);
    V428 = elt(env, 8); /* BOOT::|Variable| */
    if (!(V429 == V428)) goto V258;
    V428 = stack[-2];
    V428 = qcdr(V428);
    stack[0] = V428;
    V428 = stack[0];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V276;
    V428 = stack[0];
    V428 = qcdr(V428);
    V428 = (V428 == nil ? lisp_true : nil);
    goto V275;

V275:
    if (V428 == nil) goto V258;
    V428 = stack[-1];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V258;
    V428 = stack[-1];
    V429 = qcar(V428);
    V428 = elt(env, 9); /* BOOT::|Mapping| */
    if (V429 == V428) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    else goto V258;

V258:
    V428 = stack[-2];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V300;
    V428 = stack[-2];
    V429 = qcar(V428);
    V428 = elt(env, 10); /* BOOT::|FunctionCalled| */
    if (!(V429 == V428)) goto V300;
    V428 = stack[-2];
    V428 = qcdr(V428);
    stack[0] = V428;
    V428 = stack[0];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V318;
    V428 = stack[0];
    V428 = qcdr(V428);
    V428 = (V428 == nil ? lisp_true : nil);
    goto V317;

V317:
    if (V428 == nil) goto V300;
    V428 = stack[-1];
    fn = elt(env, 12); /* CONSP */
    V428 = (*qfn1(fn))(qenv(fn), V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V300;
    V428 = stack[-1];
    V429 = qcar(V428);
    V428 = elt(env, 9); /* BOOT::|Mapping| */
    if (V429 == V428) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    else goto V300;

V300:
    V428 = lisp_true;
    if (V428 == nil) goto V342;
    V429 = stack[-2];
    V428 = qvalue(elt(env, 11)); /* BOOT::|$Integer| */
    fn = elt(env, 18); /* BOOT::|isEqualOrSubDomain| */
    V428 = (*qfn2(fn))(qenv(fn), V429, V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    if (V428 == nil) goto V362;
    V428 = qvalue(elt(env, 11)); /* BOOT::|$Integer| */
    stack[-2] = V428;
    goto V362;

V362:
    V429 = stack[-2];
    V428 = stack[-1];
    fn = elt(env, 19); /* BOOT::|resolveTMEq| */
    V428 = (*qfn2(fn))(qenv(fn), V429, V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    stack[0] = V428;
    if (!(V428 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    V428 = lisp_true;
    if (V428 == nil) goto V371;
    V428 = qvalue(elt(env, 6)); /* BOOT::|$Coerce| */
    if (V428 == nil) goto V375;
    V429 = stack[-2];
    V428 = stack[-1];
    fn = elt(env, 20); /* BOOT::|resolveTMRed| */
    V428 = (*qfn2(fn))(qenv(fn), V429, V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    env = stack[-4];
    stack[0] = V428;
    if (!(V428 == nil)) { Lisp_Object res = stack[0]; popv(5); return onevalue(res); }
    V428 = lisp_true;
    if (V428 == nil) goto V395;
    V429 = stack[-2];
    V428 = stack[-1];
    {
        popv(5);
        fn = elt(env, 21); /* BOOT::|resolveTM2| */
        return (*qfn2(fn))(qenv(fn), V429, V428);
    }

V395:
    V428 = nil;
    { popv(5); return onevalue(V428); }

V375:
    V428 = nil;
    { popv(5); return onevalue(V428); }

V371:
    V428 = nil;
    { popv(5); return onevalue(V428); }

V342:
    V428 = nil;
    { popv(5); return onevalue(V428); }

V318:
    V428 = nil;
    goto V317;

V276:
    V428 = nil;
    goto V275;

V177:
    V428 = nil;
    { popv(5); return onevalue(V428); }

V83:
    V428 = lisp_true;
    if (V428 == nil) goto V406;
    V428 = qvalue(elt(env, 6)); /* BOOT::|$Coerce| */
    if (V428 == nil) goto V410;
    V429 = stack[-2];
    V428 = stack[-1];
    fn = elt(env, 22); /* BOOT::|canCoerceFrom| */
    V428 = (*qfn2(fn))(qenv(fn), V429, V428);
    nil = C_nil;
    if (exception_pending()) goto V435;
    if (!(V428 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    V428 = nil;
    { popv(5); return onevalue(V428); }

V410:
    V428 = nil;
    { popv(5); return onevalue(V428); }

V406:
    V428 = nil;
    { popv(5); return onevalue(V428); }
/* error exit handlers */
V436:
    popv(5);
    return error(1, err_bad_cdr, V428);
V435:
    popv(5);
    return nil;
}

/*
(DEFUN BOOT::|lazyMatch| (BOOT::|source|
      BOOT::|lazyt|
      BOOT::|dollar|
      BOOT::|domain|)
   (PROG (BOOT::|op| BOOT::|argl| BOOT::|sargl| BOOT::|stag| |s|
         BOOT::|atag| |a| BOOT::|coSig| BOOT::|ISTMP#1| BOOT::|ISTMP#2|
         BOOT::|slotNum| |l|)
      (RETURN
         (SEQ
            (COND
               ((AND
                   (PAIRP BOOT::|lazyt|)
                   (PROGN
                      (BOOT:SPADLET BOOT::|op| (QCAR BOOT::|lazyt|))
                      (BOOT:SPADLET BOOT::|argl| (QCDR BOOT::|lazyt|))
                      'T)
                   (NULL (ATOM BOOT::|source|))
                   (BOOT:|BOOT-EQUAL| BOOT::|op| (CAR BOOT::|source|))
                   (BOOT:|BOOT-EQUAL|
                      (|#|
                         (BOOT:SPADLET BOOT::|sargl| (CDR BOOT::|source|)))
                      (|#| BOOT::|argl|)))
                  (COND
                     ((AND
                         (MEMQ BOOT::|op| '(BOOT::|Record| BOOT::|Union|))
                         (PROGN
                            (BOOT:SPADLET
                               BOOT::|ISTMP#1|
                               (CAR BOOT::|argl|))
                            (AND
                               (PAIRP BOOT::|ISTMP#1|)
                               (EQ (QCAR BOOT::|ISTMP#1|) '|:|))))
                        (PROG (#:G18906)
                           (BOOT:SPADLET #:G18906 'T)
                           (RETURN
                              (DO ((#:G18907 NIL (NULL #:G18906))
                                    (#:G18908 BOOT::|sargl| (CDR #:G18908))
                                    (#:G18895 NIL)
                                    (#:G18909 BOOT::|argl| (CDR #:G18909))
                                    (#:G18896 NIL))
                                 ((OR
                                     #:G18907
                                     (ATOM #:G18908)
                                     (PROGN
                                        (SETQ #:G18895 (CAR #:G18908))
                                        NIL)
                                     (PROGN
                                        (PROGN
                                           (BOOT:SPADLET
                                              BOOT::|stag|
                                              (CADR #:G18895))
                                           (BOOT:SPADLET
                                              |s|
                                              (CADDR #:G18895))
                                           #:G18895)
                                        NIL)
                                     (ATOM #:G18909)
                                     (PROGN
                                        (SETQ #:G18896 (CAR #:G18909))
                                        NIL)
                                     (PROGN
                                        (PROGN
                                           (BOOT:SPADLET
                                              BOOT::|atag|
                                              (CADR #:G18896))
                                           (BOOT:SPADLET
                                              |a|
                                              (CADDR #:G18896))
                                           #:G18896)
                                        NIL))
                                    #:G18906)
                                 (SEQ
                                    (EXIT
                                       (SETQ #:G18906
                                          (AND
                                             #:G18906
                                             (AND
                                                (BOOT:|BOOT-EQUAL|
                                                   BOOT::|stag|
                                                   BOOT::|atag|)
                                                (BOOT::|lazyMatchArg|
                                                   |s|
                                                   |a|
                                                   BOOT::|dollar|
                                                BOOT::|domain|)))) ))) )))
                     ((MEMQ
                         BOOT::|op|
                         '(BOOT::|Union| BOOT::|Mapping| QUOTE))
                        (PROG (#:G18902)
                           (BOOT:SPADLET #:G18902 'T)
                           (RETURN
                              (DO ((#:G18903 NIL (NULL #:G18902))
                                    (#:G18904 BOOT::|sargl| (CDR #:G18904))
                                    (|s| NIL)
                                    (#:G18905 BOOT::|argl| (CDR #:G18905))
                                    (|a| NIL))
                                 ((OR
                                     #:G18903
                                     (ATOM #:G18904)
                                     (PROGN (SETQ |s| (CAR #:G18904)) NIL)
                                     (ATOM #:G18905)
                                     (PROGN (SETQ |a| (CAR #:G18905)) NIL))
                                    #:G18902)
                                 (SEQ
                                    (EXIT
                                       (SETQ #:G18902
                                          (AND
                                             #:G18902
                                             (BOOT::|lazyMatchArg|
                                                |s|
                                                |a|
                                                BOOT::|dollar|
                                                BOOT::|domain|)))) ))) ))
                     ('T
                        (BOOT:SPADLET
                           BOOT::|coSig|
                           (BOOT::GETDATABASE BOOT::|op| 'BOOT::COSIG))
                        (COND
                           ((NULL BOOT::|coSig|)
                              (BOOT::|error|
                                 (CONS
                                    'BOOT::|bad Constructor op|
                                    (CONS BOOT::|op| NIL))))
                           ('T
                              (PROG (#:G18897)
                                 (BOOT:SPADLET #:G18897 'T)
                                 (RETURN
                                    (DO ((#:G18898 NIL (NULL #:G18897))
                                          (#:G18899
                                             BOOT::|sargl|
                                             (CDR #:G18899))
                                          (|s| NIL)
                                          (#:G18900
                                             BOOT::|argl|
                                             (CDR #:G18900))
                                          (|a| NIL)
                                          (#:G18901
                                             (CDR BOOT::|coSig|)
                                             (CDR #:G18901))
                                          (BOOT::|flag| NIL))
                                       ((OR
                                           #:G18898
                                           (ATOM #:G18899)
                                           (PROGN
                                              (SETQ |s| (CAR #:G18899))
                                              NIL)
                                           (ATOM #:G18900)
                                           (PROGN
                                              (SETQ |a| (CAR #:G18900))
                                              NIL)
                                           (ATOM #:G18901)
                                           (PROGN
                                              (SETQ BOOT::|flag|
                                                 (CAR #:G18901))
                                              NIL))
                                          #:G18897)
                                       (SEQ
                                          (EXIT
                                             (SETQ #:G18897
                                                (AND
                                                   #:G18897
                                                   (BOOT::|lazyMatchArg2|
                                                      |s|
                                                      |a|
                                                      BOOT::|dollar|
                                                      BOOT::|domain|
                                             BOOT::|flag|)))) ))) ))) )))
               ((AND
                   (STRINGP BOOT::|source|)
                   (PAIRP BOOT::|lazyt|)
                   (EQ (QCAR BOOT::|lazyt|) 'QUOTE)
                   (PROGN
                      (BOOT:SPADLET BOOT::|ISTMP#1| (QCDR BOOT::|lazyt|))
                      (AND
                         (PAIRP BOOT::|ISTMP#1|)
                         (EQ (QCDR BOOT::|ISTMP#1|) NIL)
                         (EQUAL (QCAR BOOT::|ISTMP#1|) BOOT::|source|))))
                  'T)
               ((NUMBERP BOOT::|source|)
                  (COND
                     ((AND
                         (PAIRP BOOT::|lazyt|)
                         (EQ (QCAR BOOT::|lazyt|) '|#|)
                         (PROGN
                            (BOOT:SPADLET
                               BOOT::|ISTMP#1|
                               (QCDR BOOT::|lazyt|))
                            (AND
                               (PAIRP BOOT::|ISTMP#1|)
                               (EQ (QCDR BOOT::|ISTMP#1|) NIL)
                               (PROGN
                                  (BOOT:SPADLET
                                     BOOT::|slotNum|
                                     (QCAR BOOT::|ISTMP#1|))
                                  'T))))
                        (BOOT:|BOOT-EQUAL|
                           BOOT::|source|
                           (|#| (ELT BOOT::|domain| BOOT::|slotNum|))))
                     ((AND
                         (PAIRP BOOT::|lazyt|)
                         (EQ (QCAR BOOT::|lazyt|) 'BOOT::|call|)
                         (PROGN
                            (BOOT:SPADLET
                               BOOT::|ISTMP#1|
                               (QCDR BOOT::|lazyt|))
                            (AND
                               (PAIRP BOOT::|ISTMP#1|)
                               (EQ (QCAR BOOT::|ISTMP#1|) 'LENGTH)
                               (PROGN
                                  (BOOT:SPADLET
                                     BOOT::|ISTMP#2|
                                     (QCDR BOOT::|ISTMP#1|))
                                  (AND
                                     (PAIRP BOOT::|ISTMP#2|)
                                     (EQ (QCDR BOOT::|ISTMP#2|) NIL)
                                     (PROGN
                                        (BOOT:SPADLET
                                           BOOT::|slotNum|
                                           (QCAR BOOT::|ISTMP#2|))
                                        'T)))) ))
                        (BOOT:|BOOT-EQUAL|
                           BOOT::|source|
                           (|#| (ELT BOOT::|domain| BOOT::|slotNum|))))
                     ('T NIL)))
               ((AND
                   (PAIRP BOOT::|source|)
                   (EQ (QCAR BOOT::|source|) 'BOOT::|construct|)
                   (PROGN (BOOT:SPADLET |l| (QCDR BOOT::|source|)) 'T))
                  (BOOT:|BOOT-EQUAL| |l| BOOT::|lazyt|))
               ('T NIL)))) ))

*/



/* Code for BOOT::|lazyMatch| */

static Lisp_Object MS_CDECL CC_BOOT__lazyMatch(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V641, V642, V643, V644, V645, V646;
    Lisp_Object fn;
    argcheck(nargs, 4, "lazyMatch");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|lazyMatch|\n");
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
    stack[-1] = nil;
    V641 = stack[-6];
    fn = elt(env, 11); /* CONSP */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    if (V641 == nil) goto V28;
    V641 = stack[-6];
    V641 = qcar(V641);
    stack[-8] = V641;
    V641 = stack[-6];
    V641 = qcdr(V641);
    stack[-3] = V641;
    V641 = lisp_true;
    if (V641 == nil) goto V28;
    V641 = stack[-7];
    if (!consp(V641)) goto V28;
    V642 = stack[-8];
    V641 = stack[-7];
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    V641 = (cl_equal(V642, V641) ? lisp_true : nil);
    if (V641 == nil) goto V28;
    V641 = stack[-7];
    if (!car_legal(V641)) goto V658;
    V641 = qcdr(V641);
    stack[-2] = V641;
    fn = elt(env, 12); /* VMLISP:SIZE */
    stack[0] = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    V641 = stack[-3];
    fn = elt(env, 12); /* VMLISP:SIZE */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    V641 = (cl_equal(stack[0], V641) ? lisp_true : nil);
    if (V641 == nil) goto V28;
    V642 = stack[-8];
    V641 = elt(env, 1); /* (BOOT::|Record| BOOT::|Union|) */
    V641 = Lmemq(nil, V642, V641);
    if (V641 == nil) goto V214;
    V641 = stack[-3];
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    stack[0] = V641;
    V641 = stack[0];
    fn = elt(env, 11); /* CONSP */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    if (V641 == nil) goto V80;
    V641 = stack[0];
    V642 = qcar(V641);
    V641 = elt(env, 2); /* BOOT::|:| */
    V641 = (V642 == V641 ? lisp_true : nil);
    goto V79;

V79:
    if (V641 == nil) goto V214;
    V641 = lisp_true;
    V642 = V641;
    V644 = stack[-3];
    V643 = stack[-2];
    V641 = nil;
    stack[-1] = V644;
    stack[0] = V643;
    V644 = V641;
    goto V112;

V112:
    V641 = V644;
    if (!(V641 == nil)) { popv(10); return onevalue(V642); }
    V641 = stack[0];
    if (!consp(V641)) { popv(10); return onevalue(V642); }
    V641 = stack[0];
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    V643 = nil;
    if (!(V643 == nil)) { popv(10); return onevalue(V642); }
    V643 = V641;
    if (!car_legal(V643)) goto V659;
    V643 = qcdr(V643);
    if (!car_legal(V643)) goto V660;
    V643 = qcar(V643);
    V646 = V643;
    if (!car_legal(V641)) goto V658;
    V641 = qcdr(V641);
    if (!car_legal(V641)) goto V658;
    V641 = qcdr(V641);
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    V645 = V641;
    V641 = nil;
    if (!(V641 == nil)) { popv(10); return onevalue(V642); }
    V641 = stack[-1];
    if (!consp(V641)) { popv(10); return onevalue(V642); }
    V641 = stack[-1];
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    V643 = nil;
    if (!(V643 == nil)) { popv(10); return onevalue(V642); }
    V643 = V641;
    if (!car_legal(V643)) goto V659;
    V643 = qcdr(V643);
    if (!car_legal(V643)) goto V660;
    V643 = qcar(V643);
    V644 = V643;
    if (!car_legal(V641)) goto V658;
    V641 = qcdr(V641);
    if (!car_legal(V641)) goto V658;
    V641 = qcdr(V641);
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    V643 = V641;
    V641 = nil;
    if (!(V641 == nil)) { popv(10); return onevalue(V642); }
    V641 = V642;
    if (V641 == nil) goto V157;
    V641 = V646;
    V642 = V644;
    V641 = (cl_equal(V641, V642) ? lisp_true : nil);
    if (V641 == nil) goto V165;
    V644 = V645;
    V642 = stack[-5];
    V641 = stack[-4];
    fn = elt(env, 13); /* BOOT::|lazyMatchArg| */
    V641 = (*qfnn(fn))(qenv(fn), 4, V644, V643, V642, V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    goto V156;

V156:
    V642 = V641;
    V641 = V642;
    V641 = (V641 == nil ? lisp_true : nil);
    V644 = V641;
    V641 = stack[0];
    if (!car_legal(V641)) goto V658;
    V641 = qcdr(V641);
    V643 = stack[-1];
    if (!car_legal(V643)) goto V659;
    V643 = qcdr(V643);
    stack[0] = V641;
    V641 = V643;
    stack[-1] = V641;
    goto V112;

V165:
    V641 = nil;
    goto V156;

V157:
    V641 = nil;
    goto V156;

V214:
    V642 = stack[-8];
    V641 = elt(env, 3); /* (BOOT::|Union| BOOT::|Mapping| QUOTE) */
    V641 = Lmemq(nil, V642, V641);
    if (V641 == nil) goto V213;
    V641 = lisp_true;
    V644 = V641;
    V643 = stack[-3];
    V642 = stack[-2];
    V641 = nil;
    stack[-1] = V643;
    stack[0] = V642;
    V643 = V641;
    goto V238;

V238:
    V641 = V643;
    if (!(V641 == nil)) { popv(10); return onevalue(V644); }
    V641 = stack[0];
    if (!consp(V641)) { popv(10); return onevalue(V644); }
    V641 = stack[0];
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    V643 = V641;
    V641 = nil;
    if (!(V641 == nil)) { popv(10); return onevalue(V644); }
    V641 = stack[-1];
    if (!consp(V641)) { popv(10); return onevalue(V644); }
    V641 = stack[-1];
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    V642 = V641;
    V641 = nil;
    if (!(V641 == nil)) { popv(10); return onevalue(V644); }
    V641 = V644;
    if (V641 == nil) goto V263;
    V644 = V643;
    V643 = V642;
    V642 = stack[-5];
    V641 = stack[-4];
    fn = elt(env, 13); /* BOOT::|lazyMatchArg| */
    V641 = (*qfnn(fn))(qenv(fn), 4, V644, V643, V642, V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    goto V262;

V262:
    V644 = V641;
    V641 = V644;
    V641 = (V641 == nil ? lisp_true : nil);
    V643 = V641;
    V641 = stack[0];
    if (!car_legal(V641)) goto V658;
    V641 = qcdr(V641);
    V642 = stack[-1];
    if (!car_legal(V642)) goto V661;
    V642 = qcdr(V642);
    stack[0] = V641;
    V641 = V642;
    stack[-1] = V641;
    goto V238;

V263:
    V641 = nil;
    goto V262;

V213:
    V641 = lisp_true;
    if (V641 == nil) goto V304;
    V642 = stack[-8];
    V641 = elt(env, 4); /* BOOT::COSIG */
    fn = elt(env, 14); /* BOOT::GETDATABASE */
    V641 = (*qfn2(fn))(qenv(fn), V642, V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    V642 = V641;
    if (V642 == nil) goto V321;
    V642 = lisp_true;
    if (V642 == nil) goto V332;
    V642 = lisp_true;
    V645 = V642;
    if (!car_legal(V641)) goto V658;
    V644 = qcdr(V641);
    V643 = stack[-3];
    V642 = stack[-2];
    V641 = nil;
    stack[-2] = V644;
    stack[-1] = V643;
    stack[0] = V642;
    V644 = V641;
    goto V355;

V355:
    V641 = V644;
    if (!(V641 == nil)) { popv(10); return onevalue(V645); }
    V641 = stack[0];
    if (!consp(V641)) { popv(10); return onevalue(V645); }
    V641 = stack[0];
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    V643 = V641;
    V641 = nil;
    if (!(V641 == nil)) { popv(10); return onevalue(V645); }
    V641 = stack[-1];
    if (!consp(V641)) { popv(10); return onevalue(V645); }
    V641 = stack[-1];
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    V642 = V641;
    V641 = nil;
    if (!(V641 == nil)) { popv(10); return onevalue(V645); }
    V641 = stack[-2];
    if (!consp(V641)) { popv(10); return onevalue(V645); }
    V641 = stack[-2];
    if (!car_legal(V641)) goto V657;
    V641 = qcar(V641);
    V644 = V641;
    V641 = nil;
    if (!(V641 == nil)) { popv(10); return onevalue(V645); }
    V641 = V645;
    if (V641 == nil) goto V386;
    V645 = V643;
    V643 = V642;
    V642 = stack[-5];
    V641 = stack[-4];
    fn = elt(env, 15); /* BOOT::|lazyMatchArg2| */
    V641 = (*qfnn(fn))(qenv(fn), 5, V645, V643, V642, V641, V644);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    goto V385;

V385:
    V645 = V641;
    V641 = V645;
    V641 = (V641 == nil ? lisp_true : nil);
    V644 = V641;
    V641 = stack[0];
    if (!car_legal(V641)) goto V658;
    V641 = qcdr(V641);
    V642 = stack[-1];
    if (!car_legal(V642)) goto V661;
    V642 = qcdr(V642);
    V643 = V642;
    V642 = stack[-2];
    if (!car_legal(V642)) goto V661;
    V642 = qcdr(V642);
    stack[0] = V641;
    V641 = V643;
    stack[-1] = V641;
    V641 = V642;
    stack[-2] = V641;
    goto V355;

V386:
    V641 = nil;
    goto V385;

V332:
    V641 = nil;
    { popv(10); return onevalue(V641); }

V321:
    V643 = elt(env, 5); /* BOOT::|bad Constructor op| */
    V642 = stack[-8];
    V641 = nil;
    V641 = list2star(V643, V642, V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    {
        popv(10);
        fn = elt(env, 16); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V641);
    }

V304:
    V641 = nil;
    { popv(10); return onevalue(V641); }

V80:
    V641 = nil;
    goto V79;

V28:
    V641 = stack[-7];
    V641 = Lstringp(nil, V641);
    env = stack[-9];
    if (V641 == nil) goto V436;
    V641 = stack[-6];
    fn = elt(env, 11); /* CONSP */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    if (V641 == nil) goto V436;
    V641 = stack[-6];
    V642 = qcar(V641);
    V641 = elt(env, 6); /* QUOTE */
    if (!(V642 == V641)) goto V436;
    V641 = stack[-6];
    V641 = qcdr(V641);
    stack[0] = V641;
    V641 = stack[0];
    fn = elt(env, 11); /* CONSP */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    if (V641 == nil) goto V457;
    V641 = stack[0];
    V641 = qcdr(V641);
    if (V641 == nil) goto V469;
    V641 = nil;
    goto V456;

V456:
    if (V641 == nil) goto V436;
    V641 = lisp_true;
    { popv(10); return onevalue(V641); }

V436:
    V641 = stack[-7];
    if (is_number(V641)) goto V479;
    V641 = stack[-7];
    fn = elt(env, 11); /* CONSP */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    if (V641 == nil) goto V611;
    V641 = stack[-7];
    V641 = qcar(V641);
    V642 = elt(env, 10); /* BOOT::|construct| */
    if (!(V641 == V642)) goto V611;
    V641 = stack[-7];
    V641 = qcdr(V641);
    V642 = V641;
    V641 = lisp_true;
    if (V641 == nil) goto V611;
    V641 = stack[-6];
    V641 = (cl_equal(V642, V641) ? lisp_true : nil);
    { popv(10); return onevalue(V641); }

V611:
    V641 = lisp_true;
    if (V641 == nil) goto V637;
    V641 = nil;
    { popv(10); return onevalue(V641); }

V637:
    V641 = nil;
    { popv(10); return onevalue(V641); }

V479:
    V641 = stack[-6];
    fn = elt(env, 11); /* CONSP */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    if (V641 == nil) goto V485;
    V641 = stack[-6];
    V642 = qcar(V641);
    V641 = elt(env, 7); /* BOOT::# */
    if (!(V642 == V641)) goto V485;
    V641 = stack[-6];
    V641 = qcdr(V641);
    stack[0] = V641;
    V641 = stack[0];
    fn = elt(env, 11); /* CONSP */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    if (V641 == nil) goto V503;
    V641 = stack[0];
    V641 = qcdr(V641);
    if (V641 == nil) goto V513;
    V641 = nil;
    goto V502;

V502:
    if (V641 == nil) goto V485;
    stack[0] = stack[-7];
    V642 = stack[-4];
    V641 = stack[-1];
    fn = elt(env, 17); /* ELT */
    V641 = (*qfn2(fn))(qenv(fn), V642, V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    fn = elt(env, 12); /* VMLISP:SIZE */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    V641 = (cl_equal(stack[0], V641) ? lisp_true : nil);
    { popv(10); return onevalue(V641); }

V485:
    V641 = stack[-6];
    fn = elt(env, 11); /* CONSP */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    if (V641 == nil) goto V535;
    V641 = stack[-6];
    V642 = qcar(V641);
    V641 = elt(env, 8); /* BOOT::|call| */
    if (!(V642 == V641)) goto V535;
    V641 = stack[-6];
    V641 = qcdr(V641);
    stack[0] = V641;
    V641 = stack[0];
    fn = elt(env, 11); /* CONSP */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    if (V641 == nil) goto V553;
    V641 = stack[0];
    V642 = qcar(V641);
    V641 = elt(env, 9); /* LENGTH */
    if (V642 == V641) goto V569;
    V641 = nil;
    goto V552;

V552:
    if (V641 == nil) goto V535;
    stack[0] = stack[-7];
    V642 = stack[-4];
    V641 = stack[-1];
    fn = elt(env, 17); /* ELT */
    V641 = (*qfn2(fn))(qenv(fn), V642, V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    fn = elt(env, 12); /* VMLISP:SIZE */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    V641 = (cl_equal(stack[0], V641) ? lisp_true : nil);
    { popv(10); return onevalue(V641); }

V535:
    V641 = lisp_true;
    if (V641 == nil) goto V607;
    V641 = nil;
    { popv(10); return onevalue(V641); }

V607:
    V641 = nil;
    { popv(10); return onevalue(V641); }

V569:
    V641 = stack[0];
    V641 = qcdr(V641);
    stack[0] = V641;
    V641 = stack[0];
    fn = elt(env, 11); /* CONSP */
    V641 = (*qfn1(fn))(qenv(fn), V641);
    nil = C_nil;
    if (exception_pending()) goto V656;
    env = stack[-9];
    if (V641 == nil) goto V575;
    V641 = stack[0];
    V641 = qcdr(V641);
    if (V641 == nil) goto V585;
    V641 = nil;
    goto V552;

V585:
    V641 = stack[0];
    V641 = qcar(V641);
    stack[-1] = V641;
    V641 = lisp_true;
    goto V552;

V575:
    V641 = nil;
    goto V552;

V553:
    V641 = nil;
    goto V552;

V513:
    V641 = stack[0];
    V641 = qcar(V641);
    stack[-1] = V641;
    V641 = lisp_true;
    goto V502;

V503:
    V641 = nil;
    goto V502;

V469:
    V641 = stack[0];
    V642 = qcar(V641);
    V641 = stack[-7];
    V641 = (cl_equal(V642, V641) ? lisp_true : nil);
    goto V456;

V457:
    V641 = nil;
    goto V456;
/* error exit handlers */
V661:
    popv(10);
    return error(1, err_bad_cdr, V642);
V660:
    popv(10);
    return error(1, err_bad_car, V643);
V659:
    popv(10);
    return error(1, err_bad_cdr, V643);
V658:
    popv(10);
    return error(1, err_bad_cdr, V641);
V657:
    popv(10);
    return error(1, err_bad_car, V641);
V656:
    popv(10);
    return nil;
}

/*
(DEFUN |SUB-WRITE| (OBJECT)
   (LET ((|PRINT-OBJECTS| NIL) (|PRINT-INDEX| NIL))
      (IF |*PRINT-CIRCLE*| (|PRINT-SCAN| OBJECT 1))
      (SETQ |PRINT-OBJECTS| 0)
      (IF |*PRINT-PRETTY*|
         (|SUB-WRITE-PRETTY| OBJECT 1)
         (|SUB-WRITE-1| OBJECT 1))
      OBJECT))

*/



/* Code for SUB-WRITE */

static Lisp_Object CC_LISP__SUBKWRITE(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V47, V48;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering SUB-WRITE\n");
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
    V48 = nil;
    V47 = nil;
    stack[-2] = qvalue(elt(env, 1)); /* PRINT-INDEX */
    qvalue(elt(env, 1)) = V48; /* PRINT-INDEX */
    stack[0] = qvalue(elt(env, 2)); /* PRINT-OBJECTS */
    qvalue(elt(env, 2)) = V47; /* PRINT-OBJECTS */
    V47 = qvalue(elt(env, 3)); /* *PRINT-CIRCLE* */
    if (V47 == nil) goto V11;
    V48 = stack[-1];
    V47 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 5); /* PRINT-SCAN */
    V47 = (*qfn2(fn))(qenv(fn), V48, V47);
    nil = C_nil;
    if (exception_pending()) goto V52;
    env = stack[-3];
    goto V11;

V11:
    V47 = (Lisp_Object)1; /* 0 */
    qvalue(elt(env, 2)) = V47; /* PRINT-OBJECTS */
    V47 = qvalue(elt(env, 4)); /* *PRINT-PRETTY* */
    if (V47 == nil) goto V39;
    V48 = stack[-1];
    V47 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 6); /* SUB-WRITE-PRETTY */
    V47 = (*qfn2(fn))(qenv(fn), V48, V47);
    nil = C_nil;
    if (exception_pending()) goto V52;
    env = stack[-3];
    goto V26;

V26:
    V47 = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* PRINT-OBJECTS */
    qvalue(elt(env, 1)) = stack[-2]; /* PRINT-INDEX */
    { popv(4); return onevalue(V47); }

V39:
    V48 = stack[-1];
    V47 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 7); /* SUB-WRITE-1 */
    V47 = (*qfn2(fn))(qenv(fn), V48, V47);
    nil = C_nil;
    if (exception_pending()) goto V52;
    env = stack[-3];
    goto V26;
/* error exit handlers */
V52:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[0]; /* PRINT-OBJECTS */
    qvalue(elt(env, 1)) = stack[-2]; /* PRINT-INDEX */
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|IFARRAY;growAndFill| (|r| |b| |x| |$|)
   (PROG (|n|)
      (RETURN
         (SEQ
            (COND
               ((NULL
                   (|<|
                      (VMLISP:QVELT |r| 0)
                      (VMLISP:QSETVELT
                         |r|
                         1
                         (|+| (VMLISP:QVELT |r| 1) |b|))))
                  |r|)
               ('T
                  (SEQ
                     (BOOT::LETT
                        |n|
                        (|+|
                           (|+|
                              (VMLISP:QVELT |r| 0)
                              (BOOT::QUOTIENT2 (VMLISP:QVELT |r| 0) 2))
                           1)
                        BOOT::|IFARRAY;growAndFill|)
                     (COND
                        ((|<| |n| (VMLISP:QVELT |r| 1))
                           (BOOT::LETT
                              |n|
                              (VMLISP:QVELT |r| 1)
                              BOOT::|IFARRAY;growAndFill|)))
                     (EXIT
                        (BOOT::|IFARRAY;growWith|
                           |r|
                           |n|
                           |x|
                           |$|)))) ))) ))

*/



/* Code for BOOT::|IFARRAY;growAndFill| */

static Lisp_Object MS_CDECL CC_BOOT__IFARRAYUgrowAndFill(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V136, V137, V138, V139;
    Lisp_Object fn;
    argcheck(nargs, 4, "IFARRAY;growAndFill");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IFARRAY;growAndFill|\n");
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
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-2] = V5;
    stack[-3] = V4;
    stack[-4] = V3;
    stack[-5] = V2;
/* end of prologue */
    V137 = stack[-5];
    V136 = (Lisp_Object)1; /* 0 */
    stack[-6] = Lgetv(nil, V137, V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    stack[-1] = stack[-5];
    stack[0] = (Lisp_Object)17; /* 1 */
    V137 = stack[-5];
    V136 = (Lisp_Object)17; /* 1 */
    V137 = Lgetv(nil, V137, V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    V136 = stack[-4];
    V136 = plus2(V137, V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    V136 = Lputv(nil, 3, stack[-1], stack[0], V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    V136 = (Lisp_Object)lessp2(stack[-6], V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    V136 = V136 ? lisp_true : nil;
    env = stack[-7];
    if (V136 == nil) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    V136 = lisp_true;
    if (V136 == nil) goto V59;
    V137 = stack[-5];
    V136 = (Lisp_Object)1; /* 0 */
    stack[0] = Lgetv(nil, V137, V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    V137 = stack[-5];
    V136 = (Lisp_Object)1; /* 0 */
    V137 = Lgetv(nil, V137, V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    V136 = (Lisp_Object)33; /* 2 */
    fn = elt(env, 1); /* BOOT::QUOTIENT2 */
    V136 = (*qfn2(fn))(qenv(fn), V137, V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    V136 = plus2(stack[0], V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    V136 = add1(V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    stack[-1] = V136;
    stack[0] = stack[-1];
    V137 = stack[-5];
    V136 = (Lisp_Object)17; /* 1 */
    V136 = Lgetv(nil, V137, V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    V136 = (Lisp_Object)lessp2(stack[0], V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    V136 = V136 ? lisp_true : nil;
    env = stack[-7];
    if (V136 == nil) goto V121;
    V137 = stack[-5];
    V136 = (Lisp_Object)17; /* 1 */
    V136 = Lgetv(nil, V137, V136);
    nil = C_nil;
    if (exception_pending()) goto V147;
    env = stack[-7];
    stack[-1] = V136;
    goto V121;

V121:
    V139 = stack[-5];
    V138 = stack[-1];
    V137 = stack[-3];
    V136 = stack[-2];
    {
        popv(8);
        fn = elt(env, 2); /* BOOT::|IFARRAY;growWith| */
        return (*qfnn(fn))(qenv(fn), 4, V139, V138, V137, V136);
    }

V59:
    V136 = nil;
    { popv(8); return onevalue(V136); }
/* error exit handlers */
V147:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|ABELGRP-;*;Nni2S;3| (|n| |x| |$|)
   (BOOT:SPADCALL |n| |x| (VMLISP:QREFELT |$| 14)))

*/



/* Code for BOOT::|ABELGRP-;*;Nni2S;3| */

static Lisp_Object MS_CDECL CC_BOOT__ABELGRPKUHUNni2SU3(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "ABELGRP-;*;Nni2S;3");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ABELGRP-;*;Nni2S;3|\n");
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
    V35 = (Lisp_Object)225; /* 14 */
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
(DEFUN BOOT::|stopTimingProcess| (BOOT::|name|)
   (COND
      ((AND
          (BOOT:NEQUAL BOOT::|name| (BOOT::|peekTimedName|))
          (NULL BOOT:|$InteractiveMode|))
         (BOOT::|keyedSystemError|
            'BOOT::S2GL0015
            (CONS BOOT::|name| (CONS (BOOT::|peekTimedName|) NIL))))
      ('T
         (BOOT::|updateTimedName| (BOOT::|peekTimedName|))
         (BOOT::|popTimedName|))))

*/



/* Code for BOOT::|stopTimingProcess| */

static Lisp_Object CC_BOOT__stopTimingProcess(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V46, V47;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|stopTimingProcess|\n");
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
    fn = elt(env, 3); /* BOOT::|peekTimedName| */
    V46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V50;
    env = stack[-2];
    V46 = (cl_equal(stack[-1], V46) ? lisp_true : nil);
    V46 = (V46 == nil ? lisp_true : nil);
    if (V46 == nil) goto V9;
    V46 = qvalue(elt(env, 1)); /* BOOT::|$InteractiveMode| */
    if (!(V46 == nil)) goto V9;
    stack[-1] = elt(env, 2); /* BOOT::S2GL0015 */
    fn = elt(env, 3); /* BOOT::|peekTimedName| */
    V47 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V50;
    env = stack[-2];
    V46 = nil;
    V46 = list2star(stack[0], V47, V46);
    nil = C_nil;
    if (exception_pending()) goto V50;
    env = stack[-2];
    {
        Lisp_Object V51 = stack[-1];
        popv(3);
        fn = elt(env, 4); /* BOOT::|keyedSystemError| */
        return (*qfn2(fn))(qenv(fn), V51, V46);
    }

V9:
    V46 = lisp_true;
    if (V46 == nil) goto V41;
    fn = elt(env, 3); /* BOOT::|peekTimedName| */
    V46 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V50;
    env = stack[-2];
    fn = elt(env, 5); /* BOOT::|updateTimedName| */
    V46 = (*qfn1(fn))(qenv(fn), V46);
    nil = C_nil;
    if (exception_pending()) goto V50;
    env = stack[-2];
    {
        popv(3);
        fn = elt(env, 6); /* BOOT::|popTimedName| */
        return (*qfnn(fn))(qenv(fn), 0);
    }

V41:
    V46 = nil;
    { popv(3); return onevalue(V46); }
/* error exit handlers */
V50:
    popv(3);
    return nil;
}

/*
(DEFUN BOOT::|ABELMON-;*;Pi2S;2| (|n| |x| |$|)
   (BOOT:SPADCALL |n| |x| (VMLISP:QREFELT |$| 12)))

*/



/* Code for BOOT::|ABELMON-;*;Pi2S;2| */

static Lisp_Object MS_CDECL CC_BOOT__ABELMONKUHUPi2SU2(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V35, V36, V37, V38;
    argcheck(nargs, 3, "ABELMON-;*;Pi2S;2");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ABELMON-;*;Pi2S;2|\n");
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
    V35 = (Lisp_Object)193; /* 12 */
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
(DEFUN BOOT::|FIELD-;inv;2S;4| (|x| |$|)
   (PROG (|u|)
      (RETURN
         (SEQ
            (BOOT::LETT
               |u|
               (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 17))
               BOOT::|FIELD-;inv;2S;4|)
            (EXIT
               (COND
                  ((BOOT::QEQCAR |u| 1) (BOOT::|error| "not invertible"))
                  ('T (QCDR |u|)))) ))) )

*/



/* Code for BOOT::|FIELD-;inv;2S;4| */

static Lisp_Object CC_BOOT__FIELDKUinvU2SU4(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V57, V58, V59;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FIELD-;inv;2S;4|\n");
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
    V57 = V3;
    stack[0] = V2;
/* end of prologue */
    V58 = V57;
    V57 = (Lisp_Object)273; /* 17 */
    V57 = Lgetv(nil, V58, V57);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-1];
    V58 = V57;
    if (!car_legal(V58)) goto V62;
    V59 = qcar(V58);
    V58 = stack[0];
    if (!car_legal(V57)) goto V63;
    V57 = qcdr(V57);
    V57 = Lapply2(nil, 3, V59, V58, V57);
    nil = C_nil;
    if (exception_pending()) goto V61;
    env = stack[-1];
    V59 = V57;
    V57 = V59;
    V58 = qcar(V57);
    V57 = (Lisp_Object)17; /* 1 */
    V57 = Leql(nil, V58, V57);
    env = stack[-1];
    if (V57 == nil) goto V39;
    V57 = elt(env, 1); /* "not invertible" */
    {
        popv(2);
        fn = elt(env, 2); /* BOOT::|error| */
        return (*qfn1(fn))(qenv(fn), V57);
    }

V39:
    V57 = lisp_true;
    if (V57 == nil) goto V52;
    V57 = V59;
    V57 = qcdr(V57);
    { popv(2); return onevalue(V57); }

V52:
    V57 = nil;
    { popv(2); return onevalue(V57); }
/* error exit handlers */
V63:
    popv(2);
    return error(1, err_bad_cdr, V57);
V62:
    popv(2);
    return error(1, err_bad_car, V58);
V61:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|MDDFACT;reduction| (|u| |p| |$|)
   (COND
      ((ZEROP |p|) |u|)
      ('T
         (BOOT:SPADCALL
            (CONS (FUNCTION BOOT::|MDDFACT;reduction!0|) (VECTOR |$| |p|))
            |u|
            (VMLISP:QREFELT |$| 10)))) )

*/



/* Code for BOOT::|MDDFACT;reduction| */

static Lisp_Object MS_CDECL CC_BOOT__MDDFACTUreduction(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V59, V60, V61;
    Lisp_Object fn;
    argcheck(nargs, 3, "MDDFACT;reduction");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|MDDFACT;reduction|\n");
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
    V59 = stack[-3];
    V59 = (Lisp_Object)zerop(V59);
    V59 = V59 ? lisp_true : nil;
    env = stack[-6];
    if (!(V59 == nil)) { Lisp_Object res = stack[-4]; popv(7); return onevalue(res); }
    V59 = lisp_true;
    if (V59 == nil) goto V16;
    V60 = stack[-2];
    V59 = (Lisp_Object)161; /* 10 */
    V59 = Lgetv(nil, V60, V59);
    nil = C_nil;
    if (exception_pending()) goto V68;
    env = stack[-6];
    stack[-5] = V59;
    V59 = stack[-5];
    if (!car_legal(V59)) goto V69;
    stack[-1] = qcar(V59);
    stack[0] = elt(env, 1); /* BOOT::|MDDFACT;reduction!0| */
    V60 = stack[-2];
    V59 = stack[-3];
    fn = elt(env, 2); /* VECTOR */
    V59 = (*qfn2(fn))(qenv(fn), V60, V59);
    nil = C_nil;
    if (exception_pending()) goto V68;
    env = stack[-6];
    V61 = cons(stack[0], V59);
    nil = C_nil;
    if (exception_pending()) goto V68;
    V60 = stack[-4];
    V59 = stack[-5];
    if (!car_legal(V59)) goto V70;
    V59 = qcdr(V59);
    {
        Lisp_Object V71 = stack[-1];
        popv(7);
        return Lapply3(nil, 4, V71, V61, V60, V59);
    }

V16:
    V59 = nil;
    { popv(7); return onevalue(V59); }
/* error exit handlers */
V70:
    popv(7);
    return error(1, err_bad_cdr, V59);
V69:
    popv(7);
    return error(1, err_bad_car, V59);
V68:
    popv(7);
    return nil;
}

/*
(DEFUN BOOT::DIVIDE2 (X Y) (APPLY (FUNCTION CONS) (DIVIDE X Y)))

*/



/* Code for BOOT::DIVIDE2 */

static Lisp_Object CC_BOOT__DIVIDE2(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V22, V23;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::DIVIDE2\n");
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
    V22 = V3;
    V23 = V2;
/* end of prologue */
    stack[0] = elt(env, 1); /* CONS */
    fn = elt(env, 2); /* DIVIDE */
    V22 = (*qfn2(fn))(qenv(fn), V23, V22);
    nil = C_nil;
    if (exception_pending()) goto V25;
    env = stack[-1];
    {
        Lisp_Object V26 = stack[0];
        popv(2);
        fn = elt(env, 3); /* APPLY */
        return (*qfn2(fn))(qenv(fn), V26, V22);
    }
/* error exit handlers */
V25:
    popv(2);
    return nil;
}

/*
(DEFUN BOOT::|EXPR;-;2$;8| (|x| |$|)
   (BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 27)))

*/



/* Code for BOOT::|EXPR;-;2$;8| */

static Lisp_Object CC_BOOT__EXPRUKU2DU8(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V31, V32, V33;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|EXPR;-;2$;8|\n");
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
    V31 = (Lisp_Object)433; /* 27 */
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
(DEFUN BOOT::|ILIST;member?;S$B;24| (|s| |x| |$|)
   (PROG (#:G102052)
      (RETURN
         (SEQ
            (EXIT
               (SEQ
                  (SEQ
                     BOOT::G190
                     (COND
                        ((NULL (COND ((NULL |x|) 'NIL) ('T 'T)))
                           (GO BOOT::G191)))
                     (SEQ
                        (EXIT
                           (COND
                              ((BOOT:SPADCALL
                                  |s|
                                  (QCAR |x|)
                                  (VMLISP:QREFELT |$| 46))
                                 (PROGN
                                    (BOOT::LETT
                                       #:G102052
                                       'T
                                       BOOT::|ILIST;member?;S$B;24|)
                                    (GO #:G102052)))
                              ('T
                                 (BOOT::LETT
                                    |x|
                                    (QCDR |x|)
                                    BOOT::|ILIST;member?;S$B;24|)))) )
                     NIL
                     (GO BOOT::G190)
                     BOOT::G191
                     (EXIT NIL))
                  (EXIT 'NIL)))
            #:G102052
            (EXIT #:G102052)))) )

*/



/* Code for BOOT::|ILIST;member?;S$B;24| */

static Lisp_Object MS_CDECL CC_BOOT__ILISTUmemberWUSDBU24(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V82, V83, V84, V85;
    argcheck(nargs, 3, "ILIST;member?;S$B;24");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;member?;S$B;24|\n");
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

V18:
    V82 = stack[-1];
    if (V82 == nil) goto V26;
    V82 = lisp_true;
    if (V82 == nil) goto V31;
    V82 = lisp_true;
    goto V25;

V25:
    if (V82 == nil) goto V17;
    V83 = stack[0];
    V82 = (Lisp_Object)737; /* 46 */
    V82 = Lgetv(nil, V83, V82);
    nil = C_nil;
    if (exception_pending()) goto V89;
    env = stack[-3];
    V83 = V82;
    if (!car_legal(V83)) goto V90;
    V85 = qcar(V83);
    V84 = stack[-2];
    V83 = stack[-1];
    V83 = qcar(V83);
    if (!car_legal(V82)) goto V91;
    V82 = qcdr(V82);
    V82 = Lapply3(nil, 4, V85, V84, V83, V82);
    nil = C_nil;
    if (exception_pending()) goto V89;
    env = stack[-3];
    if (V82 == nil) goto V39;
    V82 = lisp_true;
    { popv(4); return onevalue(V82); }

V39:
    V82 = lisp_true;
    if (V82 == nil) goto V18;
    V82 = stack[-1];
    V82 = qcdr(V82);
    stack[-1] = V82;
    goto V18;

V17:
    V82 = nil;
    { popv(4); return onevalue(V82); }

V31:
    V82 = nil;
    goto V25;

V26:
    V82 = nil;
    goto V25;
/* error exit handlers */
V91:
    popv(4);
    return error(1, err_bad_cdr, V82);
V90:
    popv(4);
    return error(1, err_bad_car, V83);
V89:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|ILIST;rest;$Nni$;19| (|x| |n| |$|)
   (PROG (|i|)
      (RETURN
         (SEQ
            (SEQ
               (BOOT::LETT |i| 1 BOOT::|ILIST;rest;$Nni$;19|)
               BOOT::G190
               (COND ((VMLISP:QSGREATERP |i| |n|) (GO BOOT::G191)))
               (SEQ
                  (COND ((NULL |x|) (BOOT::|error| "index out of range")))
                  (EXIT
                     (BOOT::LETT
                        |x|
                        (QCDR |x|)
                        BOOT::|ILIST;rest;$Nni$;19|)))
               (BOOT::LETT
                  |i|
                  (VMLISP:QSADD1 |i|)
                  BOOT::|ILIST;rest;$Nni$;19|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT |x|)))) )

*/



/* Code for BOOT::|ILIST;rest;$Nni$;19| */

static Lisp_Object MS_CDECL CC_BOOT__ILISTUrestUDNniDU19(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V48, V49;
    Lisp_Object fn;
    argcheck(nargs, 3, "ILIST;rest;$Nni$;19");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|ILIST;rest;$Nni$;19|\n");
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
    V48 = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V48 = (Lisp_Object)17; /* 1 */
    stack[-2] = V48;
    goto V23;

V23:
    V49 = stack[-2];
    V48 = stack[0];
    V48 = (Lisp_Object)greaterp2(V49, V48);
    nil = C_nil;
    if (exception_pending()) goto V53;
    V48 = V48 ? lisp_true : nil;
    env = stack[-3];
    if (!(V48 == nil)) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    V48 = stack[-1];
    if (!(V48 == nil)) goto V33;
    V48 = elt(env, 1); /* "index out of range" */
    fn = elt(env, 2); /* BOOT::|error| */
    V48 = (*qfn1(fn))(qenv(fn), V48);
    nil = C_nil;
    if (exception_pending()) goto V53;
    env = stack[-3];
    goto V33;

V33:
    V48 = stack[-1];
    V48 = qcdr(V48);
    stack[-1] = V48;
    V48 = stack[-2];
    V48 = add1(V48);
    nil = C_nil;
    if (exception_pending()) goto V53;
    env = stack[-3];
    stack[-2] = V48;
    goto V23;
/* error exit handlers */
V53:
    popv(4);
    return nil;
}

/*
(DEFUN BOOT::|replaceGoGetSlot| (BOOT::|env|)
   (PROG (BOOT::|thisDomain|
         BOOT::|op|
         BOOT::|thisDomainForm|
         BOOT::|bytevec|
         BOOT::|numOfArgs|
         BOOT::|goGetDomainSlotIndex|
         BOOT::|goGetDomain|
         BOOT::|index|
         BOOT::|sig|
         BOOT::|thisSlot|
         BOOT::|slot|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET BOOT::|thisDomain| (CAR BOOT::|env|))
               (BOOT:SPADLET BOOT::|index| (CADR BOOT::|env|))
               (BOOT:SPADLET BOOT::|op| (CDDR BOOT::|env|))
               (BOOT:SPADLET
                  BOOT::|thisDomainForm|
                  (BOOT::|devaluate| BOOT::|thisDomain|))
               (BOOT:SPADLET
                  BOOT::|bytevec|
                  (BOOT::|getDomainByteVector| BOOT::|thisDomain|))
               (BOOT:SPADLET
                  BOOT::|numOfArgs|
                  (ELT BOOT::|bytevec| BOOT::|index|))
               (BOOT:SPADLET
                  BOOT::|goGetDomainSlotIndex|
                  (ELT
                     BOOT::|bytevec|
                     (BOOT:SPADLET
                        BOOT::|index|
                        (VMLISP:QSADD1 BOOT::|index|))))
               (BOOT:SPADLET
                  BOOT::|goGetDomain|
                  (COND
                     ((EQL BOOT::|goGetDomainSlotIndex| 0)
                        BOOT::|thisDomain|)
                     ('T
                        (ELT
                           BOOT::|thisDomain|
                           BOOT::|goGetDomainSlotIndex|))))
               (COND
                  ((AND
                      (PAIRP BOOT::|goGetDomain|)
                      (SYMBOLP (CAR BOOT::|goGetDomain|)))
                     (BOOT:SPADLET
                        BOOT::|goGetDomain|
                        (BOOT::|lazyDomainSet|
                           BOOT::|goGetDomain|
                           BOOT::|thisDomain|
                           BOOT::|goGetDomainSlotIndex|))))
               (BOOT:SPADLET
                  BOOT::|sig|
                  (PROG (#:G18901)
                     (BOOT:SPADLET #:G18901 NIL)
                     (RETURN
                        (DO ((|i| 0 (VMLISP:QSADD1 |i|)))
                           ((VMLISP:QSGREATERP |i| BOOT::|numOfArgs|)
                              (NREVERSE0 #:G18901))
                           (SEQ
                              (EXIT
                                 (SETQ #:G18901
                                    (CONS
                                       (BOOT::|newExpandTypeSlot|
                                          (ELT
                                             BOOT::|bytevec|
                                             (BOOT:SPADLET
                                                BOOT::|index|
                                                (VMLISP:QSADD1
                                                   BOOT::|index|)))
                                          BOOT::|thisDomain|
                                          BOOT::|thisDomain|)
                                       #:G18901)))) ))) )
               (BOOT:SPADLET
                  BOOT::|thisSlot|
                  (ELT BOOT::|bytevec| (VMLISP:QSADD1 BOOT::|index|)))
               (COND
                  (BOOT::|$monitorNewWorld|
                     (BOOT::|sayLooking|
                        (BOOT::|concat|
                           (VMLISP:MAKESTRING "%l")
                           (INTERN ".." "BOOT")
                           (BOOT::|form2String| BOOT::|thisDomainForm|)
                           (VMLISP:MAKESTRING " wants")
                           (VMLISP:MAKESTRING "%l")
                           (VMLISP:MAKESTRING "  "))
                        BOOT::|op|
                        BOOT::|sig|
                        BOOT::|goGetDomain|)))
               (BOOT:SPADLET
                  BOOT::|slot|
                  (BOOT::|basicLookup|
                     BOOT::|op|
                     BOOT::|sig|
                     BOOT::|goGetDomain|
                     BOOT::|goGetDomain|))
               (COND
                  ((NULL BOOT::|slot|)
                     (COND
                        ((BOOT:|BOOT-EQUAL|
                            BOOT::|$returnNowhereFromGoGet|
                            'T)
                           (CONS 'BOOT::|nowhere| BOOT::|goGetDomain|))
                        ('T
                           (BOOT:|sayBrightly|
                              (BOOT::|concat|
                                 (VMLISP:MAKESTRING "Function: ")
                                 (BOOT::|formatOpSignature|
                                    BOOT::|op|
                                    BOOT::|sig|)
                                 (VMLISP:MAKESTRING
                                    " is missing from domain: ")
                                 (BOOT::|form2String|
                                    (ELT BOOT::|goGetDomain| 0))))
                           (BOOT::|keyedSystemError|
                              'BOOT::S2NR0001
                              (CONS
                                 BOOT::|op|
                                 (CONS
                                    BOOT::|sig|
                                    (CONS
                                       (ELT BOOT::|goGetDomain| 0)
                                       NIL)))) )))
                  ('T
                     (COND
                        (BOOT::|$monitorNewWorld|
                           (BOOT::|sayLooking1|
                              (CONS
                                 (VMLISP:MAKESTRING "goget stuffing slot")
                                 (APPEND
                                    (BOOT::|bright| BOOT::|thisSlot|)
                                    (CONS (VMLISP:MAKESTRING "of ") NIL)))
                              BOOT::|thisDomain|)))
                     (SETELT
                        BOOT::|thisDomain|
                        BOOT::|thisSlot|
                        BOOT::|slot|)
                     (COND
                        (BOOT::|$monitorNewWorld|
                           (BOOT::|sayLooking1|
                              (VMLISP:MAKESTRING "<------")
                              (CONS
                                 (CAR BOOT::|slot|)
                                 (BOOT::|devaluate|
                                    (CDR BOOT::|slot|)))) ))
                     BOOT::|slot|)))) )))

*/



/* Code for BOOT::|replaceGoGetSlot| */

static Lisp_Object CC_BOOT__replaceGoGetSlot(Lisp_Object env,
                         Lisp_Object V2)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V391, V392, V393, V394;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|replaceGoGetSlot|\n");
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
    V392 = V2;
/* end of prologue */
    V391 = V392;
    if (!car_legal(V391)) goto V405;
    V391 = qcar(V391);
    stack[-9] = V391;
    V391 = V392;
    if (!car_legal(V391)) goto V406;
    V391 = qcdr(V391);
    if (!car_legal(V391)) goto V405;
    V391 = qcar(V391);
    stack[-3] = V391;
    V391 = V392;
    if (!car_legal(V391)) goto V406;
    V391 = qcdr(V391);
    if (!car_legal(V391)) goto V406;
    V391 = qcdr(V391);
    stack[-8] = V391;
    V391 = stack[-9];
    fn = elt(env, 15); /* BOOT::|devaluate| */
    V391 = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[-7] = V391;
    V391 = stack[-9];
    fn = elt(env, 16); /* BOOT::|getDomainByteVector| */
    V391 = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[-6] = V391;
    V392 = stack[-6];
    V391 = stack[-3];
    fn = elt(env, 17); /* ELT */
    V391 = (*qfn2(fn))(qenv(fn), V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[-5] = V391;
    stack[0] = stack[-6];
    V391 = stack[-3];
    V391 = add1(V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[-3] = V391;
    fn = elt(env, 17); /* ELT */
    V391 = (*qfn2(fn))(qenv(fn), stack[0], V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[0] = V391;
    V392 = stack[0];
    V391 = (Lisp_Object)1; /* 0 */
    V391 = Leql(nil, V392, V391);
    env = stack[-10];
    if (V391 == nil) goto V53;
    V391 = stack[-9];
    goto V51;

V51:
    stack[-4] = V391;
    V391 = stack[-4];
    fn = elt(env, 18); /* CONSP */
    V391 = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    if (V391 == nil) goto V75;
    V391 = stack[-4];
    if (!car_legal(V391)) goto V405;
    V391 = qcar(V391);
    fn = elt(env, 19); /* SYMBOLP */
    V391 = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    if (V391 == nil) goto V75;
    V393 = stack[-4];
    V392 = stack[-9];
    V391 = stack[0];
    fn = elt(env, 20); /* BOOT::|lazyDomainSet| */
    V391 = (*qfnn(fn))(qenv(fn), 3, V393, V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[-4] = V391;
    goto V75;

V75:
    V391 = nil;
    stack[-2] = V391;
    V391 = (Lisp_Object)1; /* 0 */
    stack[-1] = V391;
    goto V112;

V112:
    V392 = stack[-1];
    V391 = stack[-5];
    V391 = (Lisp_Object)greaterp2(V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    V391 = V391 ? lisp_true : nil;
    env = stack[-10];
    if (V391 == nil) goto V139;
    V391 = stack[-2];
    fn = elt(env, 21); /* NREVERSE0 */
    V391 = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[-1] = V391;
    stack[0] = stack[-6];
    V391 = stack[-3];
    V391 = add1(V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    fn = elt(env, 17); /* ELT */
    V391 = (*qfn2(fn))(qenv(fn), stack[0], V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[-3] = V391;
    V391 = qvalue(elt(env, 1)); /* BOOT::|$monitorNewWorld| */
    if (V391 == nil) goto V214;
    stack[-2] = elt(env, 2); /* "%l" */
    V392 = elt(env, 3); /* ".." */
    V391 = elt(env, 4); /* "BOOT" */
    fn = elt(env, 22); /* INTERN */
    stack[0] = (*qfn2(fn))(qenv(fn), V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V391 = stack[-7];
    fn = elt(env, 23); /* BOOT::|form2String| */
    V394 = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V393 = elt(env, 5); /* " wants" */
    V392 = elt(env, 2); /* "%l" */
    V391 = elt(env, 6); /* "  " */
    fn = elt(env, 24); /* BOOT::|concat| */
    V394 = (*qfnn(fn))(qenv(fn), 6, stack[-2], stack[0], V394, V393, V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V393 = stack[-8];
    V392 = stack[-1];
    V391 = stack[-4];
    fn = elt(env, 25); /* BOOT::|sayLooking| */
    V391 = (*qfnn(fn))(qenv(fn), 4, V394, V393, V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    goto V214;

V214:
    V394 = stack[-8];
    V393 = stack[-1];
    V392 = stack[-4];
    V391 = stack[-4];
    fn = elt(env, 26); /* BOOT::|basicLookup| */
    V391 = (*qfnn(fn))(qenv(fn), 4, V394, V393, V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[0] = V391;
    V391 = stack[0];
    if (V391 == nil) goto V240;
    V391 = lisp_true;
    if (V391 == nil) goto V324;
    V391 = qvalue(elt(env, 1)); /* BOOT::|$monitorNewWorld| */
    if (V391 == nil) goto V356;
    stack[-2] = elt(env, 12); /* "goget stuffing slot" */
    V391 = stack[-3];
    fn = elt(env, 27); /* BOOT::|bright| */
    stack[-1] = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V391 = elt(env, 13); /* "of " */
    V391 = ncons(V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    fn = elt(env, 28); /* APPEND */
    V391 = (*qfn2(fn))(qenv(fn), stack[-1], V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V392 = cons(stack[-2], V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V391 = stack[-9];
    fn = elt(env, 29); /* BOOT::|sayLooking1| */
    V391 = (*qfn2(fn))(qenv(fn), V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    goto V356;

V356:
    V393 = stack[-9];
    V392 = stack[-3];
    V391 = stack[0];
    fn = elt(env, 30); /* SETELT */
    V391 = (*qfnn(fn))(qenv(fn), 3, V393, V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V391 = qvalue(elt(env, 1)); /* BOOT::|$monitorNewWorld| */
    if (V391 == nil) { Lisp_Object res = stack[0]; popv(11); return onevalue(res); }
    stack[-2] = elt(env, 14); /* "<------" */
    V391 = stack[0];
    if (!car_legal(V391)) goto V405;
    stack[-1] = qcar(V391);
    V391 = stack[0];
    if (!car_legal(V391)) goto V406;
    V391 = qcdr(V391);
    fn = elt(env, 15); /* BOOT::|devaluate| */
    V391 = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V391 = cons(stack[-1], V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    fn = elt(env, 29); /* BOOT::|sayLooking1| */
    V391 = (*qfn2(fn))(qenv(fn), stack[-2], V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    { Lisp_Object res = stack[0]; popv(11); return onevalue(res); }

V324:
    V391 = nil;
    { popv(11); return onevalue(V391); }

V240:
    V392 = qvalue(elt(env, 7)); /* BOOT::|$returnNowhereFromGoGet| */
    V391 = lisp_true;
    V391 = Leql(nil, V392, V391);
    env = stack[-10];
    if (!(V391 == nil)) goto V237;
    stack[0] = qvalue(elt(env, 7)); /* BOOT::|$returnNowhereFromGoGet| */
    V391 = lisp_true;
    fn = elt(env, 31); /* CHARACTER */
    V391 = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V391 = Leql(nil, stack[0], V391);
    env = stack[-10];
    goto V237;

V237:
    if (V391 == nil) goto V235;
    V392 = elt(env, 8); /* BOOT::|nowhere| */
    V391 = stack[-4];
    popv(11);
    { Lisp_Object retVal = cons(V392, V391);
    errexit();
    return onevalue(retVal); }

V235:
    V391 = lisp_true;
    if (V391 == nil) goto V265;
    stack[-3] = elt(env, 9); /* "Function: " */
    V392 = stack[-8];
    V391 = stack[-1];
    fn = elt(env, 32); /* BOOT::|formatOpSignature| */
    stack[-2] = (*qfn2(fn))(qenv(fn), V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[0] = elt(env, 10); /* " is missing from domain: " */
    V392 = stack[-4];
    V391 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 17); /* ELT */
    V391 = (*qfn2(fn))(qenv(fn), V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    fn = elt(env, 23); /* BOOT::|form2String| */
    V391 = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    fn = elt(env, 24); /* BOOT::|concat| */
    V391 = (*qfnn(fn))(qenv(fn), 4, stack[-3], stack[-2], stack[0], V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    fn = elt(env, 33); /* BOOT:|sayBrightly| */
    V391 = (*qfn1(fn))(qenv(fn), V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[0] = elt(env, 11); /* BOOT::S2NR0001 */
    stack[-2] = stack[-8];
    V392 = stack[-4];
    V391 = (Lisp_Object)1; /* 0 */
    fn = elt(env, 17); /* ELT */
    V391 = (*qfn2(fn))(qenv(fn), V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V391 = ncons(V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V391 = list2star(stack[-2], stack[-1], V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    {
        Lisp_Object V408 = stack[0];
        popv(11);
        fn = elt(env, 34); /* BOOT::|keyedSystemError| */
        return (*qfn2(fn))(qenv(fn), V408, V391);
    }

V265:
    V391 = nil;
    { popv(11); return onevalue(V391); }

V139:
    stack[0] = stack[-6];
    V391 = stack[-3];
    V391 = add1(V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[-3] = V391;
    fn = elt(env, 17); /* ELT */
    V393 = (*qfn2(fn))(qenv(fn), stack[0], V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V392 = stack[-9];
    V391 = stack[-9];
    fn = elt(env, 35); /* BOOT::|newExpandTypeSlot| */
    V392 = (*qfnn(fn))(qenv(fn), 3, V393, V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    V391 = stack[-2];
    V391 = cons(V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[-2] = V391;
    V391 = stack[-1];
    V391 = add1(V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    stack[-1] = V391;
    goto V112;

V53:
    V391 = lisp_true;
    if (V391 == nil) goto V64;
    V392 = stack[-9];
    V391 = stack[0];
    fn = elt(env, 17); /* ELT */
    V391 = (*qfn2(fn))(qenv(fn), V392, V391);
    nil = C_nil;
    if (exception_pending()) goto V407;
    env = stack[-10];
    goto V51;

V64:
    V391 = nil;
    goto V51;
/* error exit handlers */
V407:
    popv(11);
    return nil;
V406:
    popv(11);
    return error(1, err_bad_cdr, V391);
V405:
    popv(11);
    return error(1, err_bad_car, V391);
}

/*
(DEFUN BOOT::|IDPAG;-;2$;1| (|x| |$|)
   (PROG (#:G83040 |u| #:G83041)
      (RETURN
         (SEQ
            (PROGN
               (BOOT::LETT #:G83040 NIL BOOT::|IDPAG;-;2$;1|)
               (SEQ
                  (BOOT::LETT |u| NIL BOOT::|IDPAG;-;2$;1|)
                  (BOOT::LETT #:G83041 |x| BOOT::|IDPAG;-;2$;1|)
                  BOOT::G190
                  (COND
                     ((OR
                         (ATOM #:G83041)
                         (PROGN
                            (BOOT::LETT
                               |u|
                               (CAR #:G83041)
                               BOOT::|IDPAG;-;2$;1|)
                            NIL))
                        (GO BOOT::G191)))
                  (SEQ
                     (EXIT
                        (BOOT::LETT
                           #:G83040
                           (CONS
                              (CONS
                                 (QCAR |u|)
                                 (BOOT:SPADCALL
                                    (QCDR |u|)
                                    (VMLISP:QREFELT |$| 10)))
                              #:G83040)
                           BOOT::|IDPAG;-;2$;1|)))
                  (BOOT::LETT #:G83041 (CDR #:G83041) BOOT::|IDPAG;-;2$;1|)
                  (GO BOOT::G190)
                  BOOT::G191
                  (EXIT (NREVERSE0 #:G83040)))) ))) )

*/



/* Code for BOOT::|IDPAG;-;2$;1| */

static Lisp_Object CC_BOOT__IDPAGUKU2DU1(Lisp_Object env,
                         Lisp_Object V2, Lisp_Object V3)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V76, V77, V78;
    Lisp_Object fn;
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|IDPAG;-;2$;1|\n");
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
    V77 = V2;
/* end of prologue */
    V76 = nil;
    stack[-4] = V76;
    V76 = V77;
    stack[-1] = V76;
    goto V17;

V17:
    V76 = stack[-1];
    if (!consp(V76)) goto V18;
    V76 = stack[-1];
    if (!car_legal(V76)) goto V84;
    V76 = qcar(V76);
    stack[-2] = V76;
    V76 = nil;
    if (!(V76 == nil)) goto V18;
    V76 = stack[-2];
    stack[0] = qcar(V76);
    V77 = stack[-3];
    V76 = (Lisp_Object)161; /* 10 */
    V76 = Lgetv(nil, V77, V76);
    nil = C_nil;
    if (exception_pending()) goto V85;
    env = stack[-5];
    V77 = V76;
    if (!car_legal(V77)) goto V86;
    V78 = qcar(V77);
    V77 = stack[-2];
    V77 = qcdr(V77);
    if (!car_legal(V76)) goto V87;
    V76 = qcdr(V76);
    V76 = Lapply2(nil, 3, V78, V77, V76);
    nil = C_nil;
    if (exception_pending()) goto V85;
    env = stack[-5];
    V77 = V76;
    V76 = stack[-4];
    V76 = acons(stack[0], V77, V76);
    nil = C_nil;
    if (exception_pending()) goto V85;
    env = stack[-5];
    stack[-4] = V76;
    V76 = stack[-1];
    if (!car_legal(V76)) goto V87;
    V76 = qcdr(V76);
    stack[-1] = V76;
    goto V17;

V18:
    V76 = stack[-4];
    {
        popv(6);
        fn = elt(env, 1); /* NREVERSE0 */
        return (*qfn1(fn))(qenv(fn), V76);
    }
/* error exit handlers */
V87:
    popv(6);
    return error(1, err_bad_cdr, V76);
V86:
    popv(6);
    return error(1, err_bad_car, V77);
V85:
    popv(6);
    return nil;
V84:
    popv(6);
    return error(1, err_bad_car, V76);
}

/*
(DEFUN BOOT::|FRAC;+;3$;21| (|x| |y| |$|)
   (PROG (|z| |d| |g|)
      (RETURN
         (SEQ
            (COND
               ((BOOT:SPADCALL |y| (VMLISP:QREFELT |$| 13)) |x|)
               ((BOOT:SPADCALL |x| (VMLISP:QREFELT |$| 13)) |y|)
               ('T
                  (SEQ
                     (BOOT::LETT
                        |z|
                        (CONS (QCDR |x|) (QCDR |y|))
                        BOOT::|FRAC;+;3$;21|)
                     (BOOT::LETT
                        |d|
                        (BOOT::|FRAC;cancelGcd| |z| |$|)
                        BOOT::|FRAC;+;3$;21|)
                     (BOOT::LETT
                        |g|
                        (CONS
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL
                                 (QCDR |z|)
                                 (QCAR |x|)
                                 (VMLISP:QREFELT |$| 49))
                              (BOOT:SPADCALL
                                 (QCAR |z|)
                                 (QCAR |y|)
                                 (VMLISP:QREFELT |$| 49))
                              (VMLISP:QREFELT |$| 29))
                           |d|)
                        BOOT::|FRAC;+;3$;21|)
                     (BOOT::|FRAC;cancelGcd| |g| |$|)
                     (PROGN
                        (RPLACD
                           |g|
                           (BOOT:SPADCALL
                              (BOOT:SPADCALL
                                 (QCDR |g|)
                                 (QCAR |z|)
                                 (VMLISP:QREFELT |$| 49))
                              (QCDR |z|)
                              (VMLISP:QREFELT |$| 49)))
                        (QCDR |g|))
                     (EXIT (BOOT::|FRAC;normalize| |g| |$|)))) ))) ))

*/



/* Code for BOOT::|FRAC;+;3$;21| */

static Lisp_Object MS_CDECL CC_BOOT__FRACULU3DU21(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V267, V268, V269, V270;
    Lisp_Object fn;
    argcheck(nargs, 3, "FRAC;+;3$;21");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|FRAC;+;3$;21|\n");
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
    V268 = stack[-3];
    V267 = (Lisp_Object)209; /* 13 */
    V267 = Lgetv(nil, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    V268 = V267;
    if (!car_legal(V268)) goto V279;
    V269 = qcar(V268);
    V268 = stack[-4];
    if (!car_legal(V267)) goto V280;
    V267 = qcdr(V267);
    V267 = Lapply2(nil, 3, V269, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    if (!(V267 == nil)) { Lisp_Object res = stack[-5]; popv(8); return onevalue(res); }
    V268 = stack[-3];
    V267 = (Lisp_Object)209; /* 13 */
    V267 = Lgetv(nil, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    V268 = V267;
    if (!car_legal(V268)) goto V279;
    V269 = qcar(V268);
    V268 = stack[-5];
    if (!car_legal(V267)) goto V280;
    V267 = qcdr(V267);
    V267 = Lapply2(nil, 3, V269, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    if (!(V267 == nil)) { Lisp_Object res = stack[-4]; popv(8); return onevalue(res); }
    V267 = lisp_true;
    if (V267 == nil) goto V72;
    V267 = stack[-5];
    V268 = qcdr(V267);
    V267 = stack[-4];
    V267 = qcdr(V267);
    V267 = cons(V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    stack[-6] = V267;
    V268 = stack[-6];
    V267 = stack[-3];
    fn = elt(env, 1); /* BOOT::|FRAC;cancelGcd| */
    V267 = (*qfn2(fn))(qenv(fn), V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    stack[-2] = V267;
    V268 = stack[-3];
    V267 = (Lisp_Object)465; /* 29 */
    V267 = Lgetv(nil, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    stack[-1] = V267;
    V267 = stack[-1];
    if (!car_legal(V267)) goto V281;
    stack[0] = qcar(V267);
    V268 = stack[-3];
    V267 = (Lisp_Object)785; /* 49 */
    V267 = Lgetv(nil, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    V268 = V267;
    if (!car_legal(V268)) goto V279;
    V270 = qcar(V268);
    V268 = stack[-6];
    V269 = qcdr(V268);
    V268 = stack[-5];
    V268 = qcar(V268);
    if (!car_legal(V267)) goto V280;
    V267 = qcdr(V267);
    V267 = Lapply3(nil, 4, V270, V269, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    stack[-5] = V267;
    V268 = stack[-3];
    V267 = (Lisp_Object)785; /* 49 */
    V267 = Lgetv(nil, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    V268 = V267;
    if (!car_legal(V268)) goto V279;
    V270 = qcar(V268);
    V268 = stack[-6];
    V269 = qcar(V268);
    V268 = stack[-4];
    V268 = qcar(V268);
    if (!car_legal(V267)) goto V280;
    V267 = qcdr(V267);
    V267 = Lapply3(nil, 4, V270, V269, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    V268 = V267;
    V267 = stack[-1];
    if (!car_legal(V267)) goto V280;
    V267 = qcdr(V267);
    V267 = Lapply3(nil, 4, stack[0], stack[-5], V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    V268 = V267;
    V267 = stack[-2];
    V267 = cons(V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    stack[-4] = V267;
    V268 = stack[-4];
    V267 = stack[-3];
    fn = elt(env, 1); /* BOOT::|FRAC;cancelGcd| */
    V267 = (*qfn2(fn))(qenv(fn), V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    stack[-2] = stack[-4];
    V268 = stack[-3];
    V267 = (Lisp_Object)785; /* 49 */
    V267 = Lgetv(nil, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    stack[-1] = V267;
    V267 = stack[-1];
    if (!car_legal(V267)) goto V281;
    stack[0] = qcar(V267);
    V268 = stack[-3];
    V267 = (Lisp_Object)785; /* 49 */
    V267 = Lgetv(nil, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    V268 = V267;
    if (!car_legal(V268)) goto V279;
    V270 = qcar(V268);
    V268 = stack[-4];
    V269 = qcdr(V268);
    V268 = stack[-6];
    V268 = qcar(V268);
    if (!car_legal(V267)) goto V280;
    V267 = qcdr(V267);
    V267 = Lapply3(nil, 4, V270, V269, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    V269 = V267;
    V267 = stack[-6];
    V268 = qcdr(V267);
    V267 = stack[-1];
    if (!car_legal(V267)) goto V280;
    V267 = qcdr(V267);
    V267 = Lapply3(nil, 4, stack[0], V269, V268, V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    V267 = Lrplacd(nil, stack[-2], V267);
    nil = C_nil;
    if (exception_pending()) goto V278;
    env = stack[-7];
    V268 = stack[-4];
    V267 = stack[-3];
    {
        popv(8);
        fn = elt(env, 2); /* BOOT::|FRAC;normalize| */
        return (*qfn2(fn))(qenv(fn), V268, V267);
    }

V72:
    V267 = nil;
    { popv(8); return onevalue(V267); }
/* error exit handlers */
V281:
    popv(8);
    return error(1, err_bad_car, V267);
V280:
    popv(8);
    return error(1, err_bad_cdr, V267);
V279:
    popv(8);
    return error(1, err_bad_car, V268);
V278:
    popv(8);
    return nil;
}

/*
(DEFUN BOOT::|PGCD;gcdTermList| (BOOT::|p1| BOOT::|p2| |$|)
   (PROG (#:G82469 BOOT::|termList| #:G82475 BOOT::|term| #:G82474 |q|)
      (RETURN
         (SEQ
            (BOOT::LETT
               BOOT::|termList|
               (BOOT:SPADCALL
                  (CONS (BOOT:|function| BOOT::|PGCD;better|) |$|)
                  (CONS
                     BOOT::|p1|
                     (BOOT:SPADCALL
                        (BOOT:SPADCALL
                           BOOT::|p2|
                           (PROG2
                              (BOOT::LETT
                                 #:G82469
                                 (BOOT:SPADCALL
                                    BOOT::|p2|
                                    (VMLISP:QREFELT |$| 78))
                                 BOOT::|PGCD;gcdTermList|)
                              (QCDR #:G82469)
                              (BOOT::|check-union|
                                 (BOOT::QEQCAR #:G82469 0)
                                 (VMLISP:QREFELT |$| 7)
                                 #:G82469))
                           (VMLISP:QREFELT |$| 81))
                        (VMLISP:QREFELT |$| 72)))
                  (VMLISP:QREFELT |$| 74))
               BOOT::|PGCD;gcdTermList|)
            (BOOT::LETT
               |q|
               (BOOT::|SPADfirst| BOOT::|termList|)
               BOOT::|PGCD;gcdTermList|)
            (SEQ
               (BOOT::LETT #:G82475 NIL BOOT::|PGCD;gcdTermList|)
               (BOOT::LETT BOOT::|term| NIL BOOT::|PGCD;gcdTermList|)
               (BOOT::LETT
                  #:G82474
                  (CDR BOOT::|termList|)
                  BOOT::|PGCD;gcdTermList|)
               BOOT::G190
               (COND
                  ((OR
                      (ATOM #:G82474)
                      (PROGN
                         (BOOT::LETT
                            BOOT::|term|
                            (CAR #:G82474)
                            BOOT::|PGCD;gcdTermList|)
                         NIL)
                      #:G82475)
                     (GO BOOT::G191)))
               (SEQ
                  (EXIT
                     (BOOT::LETT
                        |q|
                        (BOOT:SPADCALL
                           |q|
                           BOOT::|term|
                           (VMLISP:QREFELT |$| 82))
                        BOOT::|PGCD;gcdTermList|)))
               (BOOT::LETT
                  #:G82474
                  (PROG1
                     (CDR #:G82474)
                     (BOOT::LETT
                        #:G82475
                        (BOOT:SPADCALL
                           |q|
                           (BOOT::|spadConstant| |$| 40)
                           (VMLISP:QREFELT |$| 83))
                        BOOT::|PGCD;gcdTermList|))
                  BOOT::|PGCD;gcdTermList|)
               (GO BOOT::G190)
               BOOT::G191
               (EXIT NIL))
            (EXIT |q|)))) )

*/



/* Code for BOOT::|PGCD;gcdTermList| */

static Lisp_Object MS_CDECL CC_BOOT__PGCDUgcdTermList(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V288, V289, V290, V291;
    Lisp_Object fn;
    argcheck(nargs, 3, "PGCD;gcdTermList");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|PGCD;gcdTermList|\n");
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
    stack[-10] = V4;
    stack[0] = V3;
    stack[-1] = V2;
/* end of prologue */
    V289 = stack[-10];
    V288 = (Lisp_Object)1185; /* 74 */
    V288 = Lgetv(nil, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    stack[-11] = V288;
    V288 = stack[-11];
    if (!car_legal(V288)) goto V305;
    stack[-9] = qcar(V288);
    V289 = elt(env, 1); /* BOOT::|PGCD;better| */
    V288 = stack[-10];
    stack[-8] = cons(V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    stack[-7] = stack[-1];
    V289 = stack[-10];
    V288 = (Lisp_Object)1153; /* 72 */
    V288 = Lgetv(nil, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    stack[-6] = V288;
    V288 = stack[-6];
    if (!car_legal(V288)) goto V305;
    stack[-5] = qcar(V288);
    V289 = stack[-10];
    V288 = (Lisp_Object)1297; /* 81 */
    V288 = Lgetv(nil, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    stack[-4] = V288;
    V288 = stack[-4];
    if (!car_legal(V288)) goto V305;
    stack[-3] = qcar(V288);
    stack[-2] = stack[0];
    V289 = stack[-10];
    V288 = (Lisp_Object)1249; /* 78 */
    V288 = Lgetv(nil, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    V289 = V288;
    if (!car_legal(V289)) goto V306;
    V290 = qcar(V289);
    V289 = stack[0];
    if (!car_legal(V288)) goto V307;
    V288 = qcdr(V288);
    V288 = Lapply2(nil, 3, V290, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    V290 = V288;
    V288 = V290;
    V288 = qcdr(V288);
    stack[-1] = V288;
    V288 = V290;
    V289 = qcar(V288);
    V288 = (Lisp_Object)1; /* 0 */
    V288 = Leql(nil, V289, V288);
    env = stack[-12];
    if (!(V288 == nil)) goto V132;
    stack[0] = V290;
    V289 = stack[-10];
    V288 = (Lisp_Object)113; /* 7 */
    V288 = Lgetv(nil, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    fn = elt(env, 2); /* BOOT::COERCE-FAILURE-MSG */
    V288 = (*qfn2(fn))(qenv(fn), stack[0], V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    fn = elt(env, 3); /* BOOT::|error| */
    V288 = (*qfn1(fn))(qenv(fn), V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    goto V132;

V132:
    V288 = stack[-1];
    V289 = V288;
    V288 = stack[-4];
    if (!car_legal(V288)) goto V307;
    V288 = qcdr(V288);
    V288 = Lapply3(nil, 4, stack[-3], stack[-2], V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    V289 = V288;
    V288 = stack[-6];
    if (!car_legal(V288)) goto V307;
    V288 = qcdr(V288);
    V288 = Lapply2(nil, 3, stack[-5], V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    V289 = cons(stack[-7], V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    V288 = stack[-11];
    if (!car_legal(V288)) goto V307;
    V288 = qcdr(V288);
    V288 = Lapply3(nil, 4, stack[-9], stack[-8], V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    stack[0] = V288;
    V288 = stack[0];
    V289 = V288;
    V288 = V289;
    if (V288 == nil) goto V175;
    V288 = V289;
    if (!car_legal(V288)) goto V305;
    V288 = qcar(V288);
    goto V170;

V170:
    stack[-4] = V288;
    V288 = nil;
    V289 = V288;
    V288 = stack[0];
    if (!car_legal(V288)) goto V307;
    V288 = qcdr(V288);
    stack[0] = V288;
    goto V182;

V182:
    V288 = stack[0];
    if (!consp(V288)) { Lisp_Object res = stack[-4]; popv(13); return onevalue(res); }
    V288 = stack[0];
    if (!car_legal(V288)) goto V305;
    V288 = qcar(V288);
    stack[-1] = V288;
    V288 = nil;
    if (!(V288 == nil)) { Lisp_Object res = stack[-4]; popv(13); return onevalue(res); }
    V288 = V289;
    if (!(V288 == nil)) { Lisp_Object res = stack[-4]; popv(13); return onevalue(res); }
    V289 = stack[-10];
    V288 = (Lisp_Object)1313; /* 82 */
    V288 = Lgetv(nil, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    V289 = V288;
    if (!car_legal(V289)) goto V306;
    V291 = qcar(V289);
    V290 = stack[-4];
    V289 = stack[-1];
    if (!car_legal(V288)) goto V307;
    V288 = qcdr(V288);
    V288 = Lapply3(nil, 4, V291, V290, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    stack[-4] = V288;
    V288 = stack[0];
    if (!car_legal(V288)) goto V307;
    V288 = qcdr(V288);
    stack[-3] = V288;
    V289 = stack[-10];
    V288 = (Lisp_Object)1329; /* 83 */
    V288 = Lgetv(nil, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    stack[-2] = V288;
    V288 = stack[-2];
    if (!car_legal(V288)) goto V305;
    stack[-1] = qcar(V288);
    stack[0] = stack[-4];
    V289 = stack[-10];
    V288 = (Lisp_Object)641; /* 40 */
    V288 = Lgetv(nil, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    V289 = V288;
    if (!car_legal(V289)) goto V306;
    V289 = qcar(V289);
    if (!car_legal(V288)) goto V307;
    V288 = qcdr(V288);
    V288 = Lapply1(nil, V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    V289 = V288;
    V288 = stack[-2];
    if (!car_legal(V288)) goto V307;
    V288 = qcdr(V288);
    V288 = Lapply3(nil, 4, stack[-1], stack[0], V289, V288);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    V289 = V288;
    V288 = stack[-3];
    stack[0] = V288;
    goto V182;

V175:
    fn = elt(env, 4); /* BOOT::FIRST-ERROR */
    V288 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto V304;
    env = stack[-12];
    goto V170;
/* error exit handlers */
V307:
    popv(13);
    return error(1, err_bad_cdr, V288);
V306:
    popv(13);
    return error(1, err_bad_car, V289);
V305:
    popv(13);
    return error(1, err_bad_car, V288);
V304:
    popv(13);
    return nil;
}

/*
(DEFUN BOOT::|matchMmSig| (BOOT::|mm|
      BOOT::|tar|
      BOOT::|args1|
      BOOT::|args2|)
   (PROG (BOOT::|sig| BOOT::|arg| BOOT::|x1| BOOT::|x2| |a| |y| |x|
         BOOT::|ISTMP#1| |v| BOOT::|rtc| |b|)
      (RETURN
         (SEQ
            (PROGN
               (BOOT:SPADLET BOOT::|sig| (CAR BOOT::|mm|))
               (COND
                  ((CONTAINED '|#| BOOT::|sig|)
                     (BOOT:SPADLET
                        BOOT::|sig|
                        (PROG (#:G18947)
                           (BOOT:SPADLET #:G18947 NIL)
                           (RETURN
                              (DO ((#:G18948 BOOT::|sig| (CDR #:G18948))
                                    (|t| NIL))
                                 ((OR
                                     (ATOM #:G18948)
                                     (PROGN (SETQ |t| (CAR #:G18948)) NIL))
                                    (NREVERSE0 #:G18947))
                                 (SEQ
                                    (EXIT
                                       (SETQ #:G18947
                                          (CONS
                                             (BOOT::|replaceSharpCalls|
                                                (COPY |t|))
                                             #:G18947)))) ))) )))
               (COND
                  ((NULL BOOT::|args1|)
                     (BOOT::|matchMmSigTar| BOOT::|tar| (CAR BOOT::|sig|)))
                  ('T
                     (BOOT:SPADLET |a| (CDR BOOT::|sig|))
                     (BOOT:SPADLET BOOT::|arg| NIL)
                     (DO ((|i| 1 (VMLISP:QSADD1 |i|))
                           (#:G18946 NIL (NULL |b|)))
                        ((OR
                            (NULL (AND BOOT::|args1| BOOT::|args2| |a|))
                            #:G18946)
                           NIL)
                        (SEQ
                           (EXIT
                              (PROGN
                                 (BOOT:SPADLET
                                    BOOT::|x1|
                                    (CAR BOOT::|args1|))
                                 (BOOT:SPADLET
                                    BOOT::|args1|
                                    (CDR BOOT::|args1|))
                                 (BOOT:SPADLET
                                    BOOT::|x2|
                                    (CAR BOOT::|args2|))
                                 (BOOT:SPADLET
                                    BOOT::|args2|
                                    (CDR BOOT::|args2|))
                                 (BOOT:SPADLET |x| (CAR |a|))
                                 (BOOT:SPADLET |a| (CDR |a|))
                                 (BOOT:SPADLET BOOT::|rtc| NIL)
                                 (COND
                                    ((AND
                                        (PAIRP |x|)
                                        (EQ (QCAR |x|) 'BOOT::|SubDomain|)
                                        (PROGN
                                           (BOOT:SPADLET
                                              BOOT::|ISTMP#1|
                                              (QCDR |x|))
                                           (AND
                                              (PAIRP BOOT::|ISTMP#1|)
                                              (PROGN
                                                 (BOOT:SPADLET
                                                    |y|
                                                    (QCAR BOOT::|ISTMP#1|))
                                                 'T))))
                                       (BOOT:SPADLET |x| |y|)))
                                 (BOOT:SPADLET
                                    |b|
                                    (OR
                                       (BOOT::|isEqualOrSubDomain|
                                          BOOT::|x1|
                                          |x|)
                                       (AND
                                          (STRINGP |x|)
                                          (PAIRP BOOT::|x1|)
                                          (EQ
                                             (QCAR BOOT::|x1|)
                                             'BOOT::|Variable|)
                                          (PROGN
                                             (BOOT:SPADLET
                                                BOOT::|ISTMP#1|
                                                (QCDR BOOT::|x1|))
                                             (AND
                                                (PAIRP BOOT::|ISTMP#1|)
                                                (EQ
                                                   (QCDR BOOT::|ISTMP#1|)
                                                   NIL)
                                                (PROGN
                                                   (BOOT:SPADLET
                                                      |v|
        (QCAR BOOT::|ISTMP#1|))
                                                   'T)))
                                          (BOOT:|BOOT-EQUAL|
                                             |x|
                                             (SYSTEM::PNAME |v|)))
                                       (COND
                                          ((AND
                                              BOOT::|$SubDom|
                                              (BOOT::|isSubDomain|
                                                 |x|
                                                 BOOT::|x1|))
                                             (BOOT:SPADLET BOOT::|rtc| 'T))
                                          (BOOT::|$Coerce|
                                             (OR
                                                (BOOT:|BOOT-EQUAL|
                                                   BOOT::|x2|
                                                   |x|)
                                                (BOOT::|canCoerceFrom|
                                                   BOOT::|x1|
                                                   |x|)))
                                          ('T
                                             (AND
                                                (PAIRP BOOT::|x1|)
                                                (EQ
                                                   (QCAR BOOT::|x1|)
                                                   'BOOT::|Variable|)
                                                (BOOT:|BOOT-EQUAL|
                                                   |x|
                                                   '(BOOT::|Symbol|)))) )))
                                 (BOOT:SPADLET
                                    BOOT::|$RTC|
                                    (CONS BOOT::|rtc| BOOT::|$RTC|)))) ))
                     (AND
                        (NULL BOOT::|args1|)
                        (NULL |a|)
                        |b|
                        (BOOT::|matchMmSigTar|
                           BOOT::|tar|
                           (CAR BOOT::|sig|)))) ))) )))

*/



/* Code for BOOT::|matchMmSig| */

static Lisp_Object MS_CDECL CC_BOOT__matchMmSig(Lisp_Object env, int nargs,
                         Lisp_Object V2, Lisp_Object V3,
                         Lisp_Object V4, Lisp_Object V5, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object V356, V357;
    Lisp_Object fn;
    argcheck(nargs, 4, "matchMmSig");
#ifdef DEBUG_U_FILES
    err_printf("Entering BOOT::|matchMmSig|\n");
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
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-9] = V5;
    stack[-10] = V4;
    stack[-11] = V3;
    V356 = V2;
/* end of prologue */
    stack[-5] = nil;
    stack[-3] = nil;
    stack[0] = nil;
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    stack[-12] = V356;
    V357 = elt(env, 1); /* BOOT::# */
    V356 = stack[-12];
    fn = elt(env, 8); /* CONTAINED */
    V356 = (*qfn2(fn))(qenv(fn), V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    if (V356 == nil) goto V27;
    V356 = nil;
    stack[-1] = V356;
    V356 = stack[-12];
    stack[-2] = V356;
    goto V48;

V48:
    V356 = stack[-2];
    if (!consp(V356)) goto V51;
    V356 = stack[-2];
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    V357 = V356;
    V356 = nil;
    if (!(V356 == nil)) goto V51;
    V356 = V357;
    fn = elt(env, 9); /* COPY */
    V356 = (*qfn1(fn))(qenv(fn), V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    fn = elt(env, 10); /* BOOT::|replaceSharpCalls| */
    V357 = (*qfn1(fn))(qenv(fn), V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    V356 = stack[-1];
    V356 = cons(V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    stack[-1] = V356;
    V356 = stack[-2];
    if (!car_legal(V356)) goto V373;
    V356 = qcdr(V356);
    stack[-2] = V356;
    goto V48;

V51:
    V356 = stack[-1];
    fn = elt(env, 11); /* NREVERSE0 */
    V356 = (*qfn1(fn))(qenv(fn), V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    stack[-12] = V356;
    goto V27;

V27:
    V356 = stack[-10];
    if (V356 == nil) goto V88;
    V356 = lisp_true;
    if (V356 == nil) goto V97;
    V356 = stack[-12];
    if (!car_legal(V356)) goto V373;
    V356 = qcdr(V356);
    stack[-6] = V356;
    V357 = nil;
    V356 = (Lisp_Object)17; /* 1 */
    stack[-1] = V356;
    goto V108;

V108:
    V356 = stack[-10];
    if (V356 == nil) goto V103;
    V356 = stack[-9];
    if (V356 == nil) goto V103;
    V356 = stack[-6];
    if (V356 == nil) goto V103;
    V356 = V357;
    if (!(V356 == nil)) goto V103;
    V356 = stack[-10];
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    stack[-8] = V356;
    V356 = stack[-10];
    if (!car_legal(V356)) goto V373;
    V356 = qcdr(V356);
    stack[-10] = V356;
    V356 = stack[-9];
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    stack[-7] = V356;
    V356 = stack[-9];
    if (!car_legal(V356)) goto V373;
    V356 = qcdr(V356);
    stack[-9] = V356;
    V356 = stack[-6];
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    stack[-4] = V356;
    V356 = stack[-6];
    if (!car_legal(V356)) goto V373;
    V356 = qcdr(V356);
    stack[-6] = V356;
    V356 = nil;
    stack[-2] = V356;
    V356 = stack[-4];
    fn = elt(env, 12); /* CONSP */
    V356 = (*qfn1(fn))(qenv(fn), V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    if (V356 == nil) goto V175;
    V356 = stack[-4];
    V357 = qcar(V356);
    V356 = elt(env, 2); /* BOOT::|SubDomain| */
    if (!(V357 == V356)) goto V175;
    V356 = stack[-4];
    V356 = qcdr(V356);
    stack[0] = V356;
    V356 = stack[0];
    fn = elt(env, 12); /* CONSP */
    V356 = (*qfn1(fn))(qenv(fn), V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    if (V356 == nil) goto V160;
    V356 = stack[0];
    V356 = qcar(V356);
    stack[-5] = V356;
    V356 = lisp_true;
    goto V159;

V159:
    if (V356 == nil) goto V175;
    V356 = stack[-5];
    stack[-4] = V356;
    goto V175;

V175:
    V357 = stack[-8];
    V356 = stack[-4];
    fn = elt(env, 13); /* BOOT::|isEqualOrSubDomain| */
    V356 = (*qfn2(fn))(qenv(fn), V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    if (!(V356 == nil)) goto V172;
    V356 = stack[-4];
    V356 = Lstringp(nil, V356);
    env = stack[-13];
    if (V356 == nil) goto V185;
    V356 = stack[-8];
    fn = elt(env, 12); /* CONSP */
    V356 = (*qfn1(fn))(qenv(fn), V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    if (V356 == nil) goto V190;
    V356 = stack[-8];
    V357 = qcar(V356);
    V356 = elt(env, 3); /* BOOT::|Variable| */
    if (V357 == V356) goto V196;
    V356 = nil;
    goto V184;

V184:
    if (!(V356 == nil)) goto V172;
    V356 = qvalue(elt(env, 4)); /* BOOT::|$SubDom| */
    if (V356 == nil) goto V242;
    V357 = stack[-4];
    V356 = stack[-8];
    fn = elt(env, 14); /* BOOT::|isSubDomain| */
    V356 = (*qfn2(fn))(qenv(fn), V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    if (V356 == nil) goto V242;
    V356 = lisp_true;
    stack[-2] = V356;
    goto V172;

V172:
    stack[0] = V356;
    V357 = stack[-2];
    V356 = qvalue(elt(env, 7)); /* BOOT::$RTC */
    V356 = cons(V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    qvalue(elt(env, 7)) = V356; /* BOOT::$RTC */
    V356 = stack[-1];
    V356 = add1(V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    V357 = stack[0];
    V357 = (V357 == nil ? lisp_true : nil);
    stack[-1] = V356;
    V356 = V357;
    V357 = V356;
    goto V108;

V242:
    V356 = qvalue(elt(env, 5)); /* BOOT::|$Coerce| */
    if (V356 == nil) goto V256;
    V357 = stack[-7];
    V356 = stack[-4];
    V356 = (cl_equal(V357, V356) ? lisp_true : nil);
    if (!(V356 == nil)) goto V172;
    V357 = stack[-8];
    V356 = stack[-4];
    fn = elt(env, 15); /* BOOT::|canCoerceFrom| */
    V356 = (*qfn2(fn))(qenv(fn), V357, V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    goto V172;

V256:
    V356 = lisp_true;
    if (V356 == nil) goto V278;
    V356 = stack[-8];
    fn = elt(env, 12); /* CONSP */
    V356 = (*qfn1(fn))(qenv(fn), V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    if (V356 == nil) goto V282;
    V356 = stack[-8];
    V357 = qcar(V356);
    V356 = elt(env, 3); /* BOOT::|Variable| */
    if (V357 == V356) goto V300;
    V356 = nil;
    goto V172;

V300:
    V357 = stack[-4];
    V356 = elt(env, 6); /* (BOOT::|Symbol|) */
    V356 = (cl_equal(V357, V356) ? lisp_true : nil);
    goto V172;

V282:
    V356 = nil;
    goto V172;

V278:
    V356 = nil;
    goto V172;

V196:
    V356 = stack[-8];
    V356 = qcdr(V356);
    stack[0] = V356;
    V356 = stack[0];
    fn = elt(env, 12); /* CONSP */
    V356 = (*qfn1(fn))(qenv(fn), V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    if (V356 == nil) goto V212;
    V356 = stack[0];
    V356 = qcdr(V356);
    if (V356 == nil) goto V222;
    V356 = nil;
    goto V211;

V211:
    if (V356 == nil) goto V206;
    stack[0] = stack[-4];
    V356 = stack[-3];
    fn = elt(env, 16); /* SYSTEM::PNAME */
    V356 = (*qfn1(fn))(qenv(fn), V356);
    nil = C_nil;
    if (exception_pending()) goto V372;
    env = stack[-13];
    V356 = (cl_equal(stack[0], V356) ? lisp_true : nil);
    goto V184;

V206:
    V356 = nil;
    goto V184;

V222:
    V356 = stack[0];
    V356 = qcar(V356);
    stack[-3] = V356;
    V356 = lisp_true;
    goto V211;

V212:
    V356 = nil;
    goto V211;

V190:
    V356 = nil;
    goto V184;

V185:
    V356 = nil;
    goto V184;

V160:
    V356 = nil;
    goto V159;

V103:
    V356 = stack[-10];
    if (V356 == nil) goto V333;
    V356 = nil;
    { popv(14); return onevalue(V356); }

V333:
    V356 = stack[-6];
    if (V356 == nil) goto V337;
    V356 = nil;
    { popv(14); return onevalue(V356); }

V337:
    V356 = stack[0];
    if (V356 == nil) goto V340;
    V357 = stack[-11];
    V356 = stack[-12];
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    {
        popv(14);
        fn = elt(env, 17); /* BOOT::|matchMmSigTar| */
        return (*qfn2(fn))(qenv(fn), V357, V356);
    }

V340:
    V356 = nil;
    { popv(14); return onevalue(V356); }

V97:
    V356 = nil;
    { popv(14); return onevalue(V356); }

V88:
    V357 = stack[-11];
    V356 = stack[-12];
    if (!car_legal(V356)) goto V371;
    V356 = qcar(V356);
    {
        popv(14);
        fn = elt(env, 17); /* BOOT::|matchMmSigTar| */
        return (*qfn2(fn))(qenv(fn), V357, V356);
    }
/* error exit handlers */
V373:
    popv(14);
    return error(1, err_bad_cdr, V356);
V372:
    popv(14);
    return nil;
V371:
    popv(14);
    return error(1, err_bad_car, V356);
}



setup_type const u11_setup[] =
{
    {"BOOT@@resolveTM1@@Builtin",too_few_2,     CC_BOOT__resolveTM1,wrong_no_2},
    {"BOOT@@lazyMatch@@Builtin",wrong_no_na,    wrong_no_nb,   (n_args *)CC_BOOT__lazyMatch},
    {"LISP@@SUB-WRITE@@Builtin",CC_LISP__SUBKWRITE,too_many_1, wrong_no_1},
    {"BOOT@@IFARRAY;growAndFill@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__IFARRAYUgrowAndFill},
    {"BOOT@@ABELGRP-;*;Nni2S;3@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__ABELGRPKUHUNni2SU3},
    {"BOOT@@stopTimingProcess@@Builtin",CC_BOOT__stopTimingProcess,too_many_1,wrong_no_1},
    {"BOOT@@ABELMON-;*;Pi2S;2@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__ABELMONKUHUPi2SU2},
    {"BOOT@@FIELD-;inv;2S;4@@Builtin",too_few_2,CC_BOOT__FIELDKUinvU2SU4,wrong_no_2},
    {"BOOT@@MDDFACT;reduction@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__MDDFACTUreduction},
    {"BOOT@@DIVIDE2@@Builtin",  too_few_2,      CC_BOOT__DIVIDE2,wrong_no_2},
    {"BOOT@@EXPR;-;2$;8@@Builtin",too_few_2,    CC_BOOT__EXPRUKU2DU8,wrong_no_2},
    {"BOOT@@ILIST;member?;S$B;24@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__ILISTUmemberWUSDBU24},
    {"BOOT@@ILIST;rest;$Nni$;19@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__ILISTUrestUDNniDU19},
    {"BOOT@@replaceGoGetSlot@@Builtin",CC_BOOT__replaceGoGetSlot,too_many_1,wrong_no_1},
    {"BOOT@@IDPAG;-;2$;1@@Builtin",too_few_2,   CC_BOOT__IDPAGUKU2DU1,wrong_no_2},
    {"BOOT@@FRAC;+;3$;21@@Builtin",wrong_no_na, wrong_no_nb,   (n_args *)CC_BOOT__FRACULU3DU21},
    {"BOOT@@PGCD;gcdTermList@@Builtin",wrong_no_na,wrong_no_nb,(n_args *)CC_BOOT__PGCDUgcdTermList},
    {"BOOT@@matchMmSig@@Builtin",wrong_no_na,   wrong_no_nb,   (n_args *)CC_BOOT__matchMmSig},
    {NULL,                      0, 0, 0}
};

/* end of generated code */
