(GLOBAL '(S::C_NAME S::C_FILE S::LISP_NAME S::LISP_FILE))


(DM C::PRINTF (U &OPTIONAL ~MACROENVIRONMENT~)
   (BLOCK C::PRINTF (LIST 'C::PRINTF1 (CADR U) (CONS 'LIST (CDDR U)))) )


(DE C::PRINTF1 (FMT ARGS)
   (PROG (A C)
      (SETQ FMT (EXPLODE2 FMT))
      (PROG NIL
   #:G3672
         (COND ((NOT FMT) (RETURN NIL)))
         (PROGN
            (SETQ C (CAR FMT))
            (SETQ FMT (CDR FMT))
            (COND
               ((AND (EQUAL C '|\\|) (EQUAL (CAR FMT) '|n|))
                  (PROGN (TERPRI) (SETQ FMT (CDR FMT))))
               ((AND (EQUAL C '|\\|) (EQUAL (CAR FMT) '|q|))
                  (PROGN (PRINC '|"|) (SETQ FMT (CDR FMT))))
               ((EQUAL C '%)
                  (PROGN
                     (SETQ C (CAR FMT))
                     (SETQ FMT (CDR FMT))
                     (SETQ A (CAR ARGS))
                     (SETQ ARGS (CDR ARGS))
                     (COND
                        ((EQUAL C '|v|)
                           (COND
                              ((FLAGP A 'C::LIVE_ACROSS_CALL)
                                 (PROGN
                                    (PRINC "stack[")
                                    (PRINC (MINUS (GET A 'C::LOCATION)))
                                    (PRINC "]")))
                              (T (PRINC A))))
                        ((EQUAL C '|a|) (PRIN A))
                        ((EQUAL C '|t|) (TTAB A))
                        (T (PRINC A)))) )
               (T (PRINC C))))
         (GO #:G3672))))


(DE OPEN_OUTPUT (NAME) (OPEN NAME :DIRECTION :OUTPUT))


(DE S::CSTART (MODULE_NAME)
   (PROG (W)
      (VERBOS NIL)
      (PRINC "Start of compilation into C for ")
      (PRIN MODULE_NAME)
      (TERPRI)
      (SETQ W (CONS '|"| (EXPLODEC MODULE_NAME)))
      (SETQ S::C_NAME (COMPRESS (APPEND W '(|.| |c| |"|))))
      (SETQ S::LISP_NAME (COMPRESS (APPEND W '(|.| |l| |s| |p| |"|))))
      (SETQ S::C_FILE (OPEN_OUTPUT S::C_NAME))
      (SETQ S::LISP_FILE (OPEN_OUTPUT S::LISP_NAME))
      (COND ((AND S::C_FILE S::LISP_FILE) (RETURN T)))
      (COND (S::C_FILE (CLOSE S::C_FILE)))
      (COND (S::LISP_FILE (CLOSE S::LISP_FILE)))
      (RETURN NIL)))


(DE S::CINIT (U)
   (PROG (O)
      (SETQ O (WRS S::LISP_FILE))
      (PRINC "Initform: ")
      (PRINL U)
      (TERPRI)
      (WRS O)))


(DE S::CEND NIL
   (PROG NIL
      (CLOSE S::C_FILE)
      (SETQ S::C_FILE NIL)
      (CLOSE S::LISP_FILE)
      (SETQ S::LISP_FILE NIL)
      (RETURN NIL)))


(DE S::CGEN (NAME NARGS BODY ENV)
   (PROG (W FGG)
      (PRINC "Cgen:  ")
      (PRIN NAME)
      (TERPRI)
      (PRINC "nargs: ")
      (PRIN NARGS)
      (TERPRI)
      (COND
         ((GREATERP NARGS 10)
            (PROGN
               (TERPRI)
               (PRINC "++++++ Functions with > 10 args or &optional, &rest")
               (TERPRI)
               (PRINC "       arge can not be compiled into C")
               (TERPRI)
               (RETURN 'FAILED))))
      (PROG (L)
         (SETQ L (REVERSE BODY))
   LAB   (COND ((NULL L) (RETURN NIL)))
         ((LAMBDA (L)
             (PROGN
                (PRIN (CAR L))
                (PRINC ": ")
                (SETQ W (REVERSE (CDDDR L)))
                (COND ((AND (NOT FGG) (GREATERP NARGS 3)) (SETQ W (CDDR W))))
                (SETQ FGG T)
                (PROG (X)
                   (SETQ X W)
             LAB   (COND ((NULL X) (RETURN NIL)))
                   ((LAMBDA (X) (PROGN (PRINC " ") (PRIN X))) (CAR X))
                   (SETQ X (CDR X))
                   (GO LAB))
                (PRINC "  ")
                (PRIN (CADR L))
                (TERPRI)))
            (CAR L))
         (SETQ L (CDR L))
         (GO LAB))))


