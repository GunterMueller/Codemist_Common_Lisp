
;; This file MUST be run from the AXBASE directory. It creates a bunch of
;; files u01.c to u12.c and u01.lsp to u12.lsp
;;
;; The files u01.c to u12.c must be copied (by hand) into the directory where
;; CCL is built, and "fastccl" should be built to incorporate them.

(in-package 'lisp)

(load-module 'ccomp)

(defun listsize (x n)
   (cond
      ((null x) n)
      ((atom x) (1+ n))
      (t (listsize (cdr x) (listsize (car x) n)))))

(setq fnames '("u01" "u02" "u03" "u04" "u05"
               "u06" "u07" "u08" "u09" "u10"
               "u11" "u12"))


;; The size_per_file limit is an attempt to control the size of each
;; generated file of C code. It gives an approximate sort of guidance, based
;; on the size of the Lisp before it is macro-expanded.

(setq size_per_file 1700) 

(verbos nil)

(null (setq targets '(
;; added by TTT
;;    BOOT::|removeZeroOne|
    BOOT::|SUP;pomopo!;$RNni2$;13|
    BOOT::|OVAR;<;2$B;10|
    BOOT::|NSMP;mvar;$VarSet;5|
    BOOT::|SUP;ground?;$B;7|
    BOOT::|PR;addm!|
    BOOT::|SMP;+;3$;27|
    BOOT::|PR;times!0|
    BOOT::|PR;termTimes|
;; Added/promoted by MCD
    BOOT::|IIARRAY2;qsetelt!;$2I2R;12|
    BOOT::|IIARRAY2;elt;$2IR;11|
    BOOT::|IIARRAY2;nrows;$Nni;8|
    BOOT::|IIARRAY2;empty?;$B;1|
    BOOT::|IIARRAY2;maxRowIndex;$I;6|
    BOOT::|IIARRAY2;maxColIndex;$I;7|
    BOOT::|IIARRAY2;ncols;$Nni;9|
    BOOT::|IARRAY1;setelt;$I2S;17|
    BOOT::|IARRAY1;new;NniS$;5|
    BOOT::|IARRAY1;qsetelt!;$I2S;15|
    BOOT::|IARRAY1;minIndex;$I;3|
    BOOT::|IARRAY1;maxIndex;$I;13|
    BOOT::|IARRAY1;#;$Nni;1|
    BOOT::|AGG-;empty?;SB;3|
    BOOT::|STREAM;setfrst!|
    BOOT::|STREAM;setrst!|
    BOOT::|STREAM;lazyEval|
    BOOT::|STREAM;empty;$;33|
    BOOT::|PRTITION;<;2$B;5|
    BOOT::|ILIST;minIndex;$I;18|
    BOOT::|STREAM2;mapp!0|
    BOOT::|STREAM2;mapp|
    BOOT::|STREAM2;map;MSS;2|
    BOOT::|STTAYLOR;+;3S;2|
    BOOT::|ZMOD;*;3$;30|
    BOOT::|ZMOD;+;3$;32|
    BOOT::|ZMOD;-;3$;33|
    BOOT::|ZMOD;-;2$;36|
    BOOT::|FFP;*;3$;21|
    BOOT::|FFP;+;3$;22|
    BOOT::|FFP;=;2$B;24|
    BOOT::|FFP;-;3$;23|
    BOOT::|SAE;reduce;UP$;11|
    BOOT::|SAE;*;3$;15|
    BOOT::|SAE;+;3$;13|
    BOOT::|SAE;=;2$B;12|
    BOOT::|SAE;-;2$;14|
    BOOT::|SUP;monicDivide;2$R;36|
    BOOT::|ABELMON-;zero?;SB;1|
    BOOT::|ABELGRP-;-;3S;1|
    BOOT::|MATCAT-;*;S2Col;32|
    BOOT::|ARR2CAT-;copy;2S;10|
    BOOT::|IMATLIN;rowEchelon;2M;3|
    BOOT::|MATCAT-;*;3S;29|
    BOOT::|SINT;zero?;$B;38|
    BOOT::|DIRPROD;<;2$B;18|
    BOOT::|DIRPROD;subtractIfCan;2$U;14|
    BOOT::|A1AGG-;copy;2A;19|
    BOOT::|GDMP;univariate;$OvlSup;21|
    VMLISP::SIZE
    BOOT::|IARRAY1;map;M3$;8|
    BOOT::|AGG-;size?;SNniB;6|
    BOOT::|PERMGRP;times|
    BOOT::|PERMGRP;inv|
    BOOT::|PERMGRP;orbitWithSvc|
    BOOT::|PERMGRP;testIdentity|
    BOOT::|STAGG-;elt;AIS;5|
    BOOT::|PRIMARR;#;$Nni;1|
;; Remains of Arthur's original list
    BOOT::|termMatch|
    BOOT::|IFARRAY;elt;$IS;17|
    BOOT::|ILIST;empty;$;6|
    BOOT::GETALIST
    BOOT::|opOf|
    BOOT::|BOP;name;$S;2|
    BOOT::|INT;one?;$B;7|
    BOOT::|isPatternVar|
    BOOT::|ILIST;copy;2$;20|
    BOOT::|IFARRAY;setelt;$I2S;18|
    BOOT::|ALIST;search;Key$U;15|
    BOOT::|getOpCode|
    BOOT::|SMP;zero?;$B;3|
    BOOT::|ELTAGG-;qelt;SDomIm;1|
    BOOT::|SMP;one?;$B;4|
    BOOT::|ELAGG-;removeDuplicates;2A;12|
    BOOT::|SMP;=;2$B;29|
    BOOT::|PR;reductum;2$;8|
    BOOT::|SMP;variables;$L;62|
    BOOT::|isDomain|
    BOOT::|PR;leadingCoefficient;$R;6|
    BOOT::|KERNEL;position;$Nni;7|
    BOOT::|lazyMatchArg|
    BOOT::|containsVars1|
    BOOT::|subCopy|
    BOOT::|isFreeFunctionFromMmCond|
    BOOT::|ILIST;first;$S;4|
    BOOT::|ELTAGG-;qsetelt!;SDom2Im;2|
    BOOT::|isFreeFunctionFromMm|
    BOOT::|BOP;property;$SU;7|
    BOOT::|EXPR;numer;$Smp;22|
    BOOT::|EXPR;numer;$Smp;126|
    BOOT::|KERNEL;B2Z|
    BOOT::|EXPR;denom;$Smp;23|
    BOOT::|ILIST;sort!;M2$;27|
    BOOT::|SMP;*;R2$;26|
    BOOT::|getDomainFromMm|
    BOOT::|FRAC;zero?;$B;2|
    BOOT::|POLYCATQ;variables;FL;5|
    BOOT::|INTDOM-;unitCanonical;2S;2|
    BOOT::|STAGG-;concat;3A;7|
    BOOT::|PR;degree;$E;4|
    BOOT::|FS-;kernels;SL;60|
    BOOT::QUOTIENT2
    VMLISP:CGREATERP
    BOOT::|IARRAY1;qelt;$IS;14|
    BOOT::|COMPCAT-;=;2SB;15|
    VMLISP:GETL
    BOOT::|IDPO;=;2$B;1|
    BOOT::|ILIST;removeDuplicates!;2$;26|
    BOOT::UNSQUEEZE
    BOOT::|EXPR;algkernels|
    BOOT::|BOP;weight;$Nni;28|
    BOOT::|isExposedConstructor|
    BOOT::|SMP;ground?;$B;16|
    BOOT::|containsVars|
    BOOT:QLASSQ
    BOOT::|IFARRAY;removeDuplicates!;2$;30|
    BOOT::|ISTRING;<;2$B;6|
    BOOT::|SMP;unitNormal;$R;35|
    BOOT::|INT;unitNormal;$R;52|
    BOOT::|devaluate|
    VMLISP:|member|
    BOOT::|domainVal|
    BOOT::|SMP;*;3$;30|
    BOOT::|ILIST;concat!;3$;25|
    VMLISP::STRING-EQUAL-TEST
    BOOT::|INT;exquo;2$U;49|
    BOOT::|constructor?|
    BOOT::|COMPLEX;zero?;$B;8|
    BOOT::|destructT|
    BOOT::|augmentSub|
    BOOT::|FLAGG-;sort;M2A;6|
    BOOT::|KERNEL;operator;$Bo;5|
    BOOT::|IFARRAY;minIndex;$I;7|
    BOOT::|term1RW|
    BOOT::|lazyMatchAssocV|
    SYSTEM::PNAME
    BOOT::|evalMmStackInner|
    VMLISP:IVECP
    BOOT::|CONTAINEDisDomain|
    BOOT::|evalMmDom|
    QUOTIENT
    BOOT::|FAMR-;coefficients;SL;6|
    BOOT::|LSAGG-;select!;M2A;5|
    BOOT::|LSAGG-;<;2AB;25|
    BOOT::|isSubDomain|
    BOOT::|KERNEL;=;2$B;13|
    BOOT::|CDRwithIncrement|
    BOOT::|lookupInDomainVector|
    BOOT::|KERNEL;<;2$B;14|
    BOOT::|FRAC;cancelGcd|
    BOOT::|KERNEL;triage|
    BOOT::|isPartialMode|
    BOOT::|ILIST;mergeSort|
    BOOT::|getDomainByteVector|
    BOOT::|isFunctor|
    BOOT::|SMP;leadingCoefficient;$R;77|
    BOOT::|EXPR;commonk|
    BOOT::|SMP;retract;$R;59|
    BOOT::|IDPAM;monomial;AS$;6|
    BOOT::|PRIMARR;fill!;$S$;9|
    BOOT::|IFARRAY;maxIndex;$I;6|
    BOOT::|lookupComplete|
    BOOT::|FRAC;one?;$B;28|
    BOOT::|getSystemModemaps|
    BOOT::|stuffSlot|
    BOOT::|IDPAM;+;3$;4|
    BOOT::|FRAC;normalize|
    BOOT::|COMPLEX;coerce;R$;10|
    BOOT::|BOP;has?;$SB;9|
    BOOT::|tokPart|
    BOOT::|newCompareSig|
    BOOT::|lazyMatchArg2|
    BOOT::|KDAGG-;key?;KeySB;1|
    BOOT::|EXPR;=;2$B;21|
    BOOT::|COMPCAT-;recip;SU;48|
    BOOT::|SMP;mainVariable;$U;63|
    BOOT::|SCACHE;enterInCache;SMS;5|
    BOOT::|SMP;coerce;R$;21|
    BOOT::|COMPLEX;exquo;2$U;16|
    BOOT::|get|
    BOOT::|SMP;exquo;2$U;39|
    BOOT::|SMP;exquo;2$U;40|
    BOOT::|KERNEL;argument;$L;6|
    BOOT::|isNewWorldDomain|
    BOOT::|computeElapsedTime|
    BOOT::|IIARRAY2;minColIndex;$I;5|
    BOOT::|IIARRAY2;minRowIndex;$I;4|
    BOOT::|FRAC;=;2$B;27|
    BOOT::|BOP;=;2$B;27|
    BOOT::|SET;construct;L$;19|
    BOOT::|FLASORT;QuickSort|
    BOOT::|EXPR;algkernels!0|
    BOOT::|pfAbSynOp?|
    BOOT::|COMPLEX;*;3$;15|
    BOOT::|selectMmsGen,exact?|
    VMLISP:|last|
    BOOT::|evalMmCond0|
    BOOT::|COMPCAT-;exquo;SRU;46|
    BOOT::|FLASORT;partition|
    BOOT::|FM;*;R2$;1|
    BOOT::|newExpandTypeSlot|
    BOOT::|FRAC;*;3$;23|
    BOOT::|matchTypes|
    BOOT::|term1RWall|
    BOOT::|testBitVector|
    BOOT::|PRIMARR;new;NniS$;4|
    BOOT::|SMP;gcd;3$;45|
    BOOT::|SMP;gcd;3$;48|
    BOOT::|SMP;gcd;3$;52|
    BOOT::|SMP;gcd;3$;55|
    BOOT::|PGCD;gcd;3P;15|
    BOOT::|filterModemapsFromPackages|
    BOOT::|selectMmsGen,matchMms|
    BOOT::|BOP;<;2$B;29|
    BOOT::|evalMmStack|
    BOOT::|EXPR;commonk0|
    BOOT::|get0|
    BOOT::|sigDomainVal|
    BOOT::|FSAGG-;brace;LA;3|
    BOOT::|MONOID-;one?;SB;2|
    BOOT::|STAGG-;c2|
    BOOT::|IFARRAY;#;$Nni;4|
    BOOT::|IDPAM;map;M2$;7|
    BOOT::|resolveTMEq|
    BOOT::|COMPCAT-;unitNormal;SR;49|
    BOOT::|FLASORT;quickSort;M2V;1|
    BOOT::|NNI;subtractIfCan;2$U;3|
    BOOT::|SMP;-;2$;24|
    BOOT::|SUP;fmecg;$NniR2$;29|
    BOOT::|evalMm|
    BOOT::|COMPLEX;one?;$B;9|
    BOOT::|FLAGG-;sort!;2A;8|
    BOOT::|object2String|
    BOOT::|FRAC;coerce;S$;1|
    BOOT::|COMPCAT-;*;R2S;18|
    BOOT::|EXPR;*;3$;11|
    BOOT::|IIARRAY2;qelt;$2IR;10|
    BOOT::|ALIST;keys;$L;6|
    BOOT::|isEqualOrSubDomain|
    BOOT::|hashString|
    BOOT::|EXPR;reduc|
    BOOT:ELEMN
    BOOT::|MDDFACT;reduction!0|
    BOOT::|HDP;<;2$B;1|
    BOOT::|stuffDomainSlots|
    BOOT::|subspan|
    BOOT::|deconstructT|
    BOOT::|SUP;exquo;2$U;27|
    BOOT::|SUP;exquo;2$U;28|
    BOOT::|PR;coerce;R$;12|
    BOOT::|REPSQ;expt;SPiS;1|
    VMLISP:QENUM
    VMLISP:GGREATERP
    BOOT::|startTimingProcess|
    BOOT::|domainEqualList|
    BOOT::|newExpandLocalType|
    BOOT::|isDefaultPackageForm?|
    BOOT::|A1AGG-;=;2AB;28|
    BOOT::|EXPR;coerce;Smp$;24|
    BOOT::|PR;*;3$;21|
    BOOT::|superspan|
    BOOT::|SET;empty;$;4|
    BOOT::|A1AGG-;sort!;M2A;2|
    SUB-WRITE-STRING
    BOOT::|hasCat|
    BOOT::|ncAlist|
    BOOT::|INS-;symmetricRemainder;3S;27|
    BOOT::|FM;*;$R$;3|
    BOOT::|FM;*;$R$;4|
    BOOT::|IFARRAY;new;NniS$;8|
    BOOT::|BOP;properties;$Al;3|
    BOOT::|PGCD;better|
;;    VECTOR-SUBSEQ*
    BOOT::|INT;positiveRemainder;3$;28|
    BOOT::|SGROUP-;**;SPiS;1|
    BOOT::|IFARRAY;empty;$;3|
    WRITE-TO-STRING-1
    BOOT::|resolveTM1|
    BOOT::|lazyMatch|
    SUB-WRITE
    BOOT::|IFARRAY;growAndFill|
    BOOT::|ABELGRP-;*;Nni2S;3|
    BOOT::|stopTimingProcess|
;;    LISP::DIVIDE
    BOOT::|ABELMON-;*;Pi2S;2|
    BOOT::|FIELD-;inv;2S;4|
    BOOT::|MDDFACT;reduction|
    BOOT::DIVIDE2
    BOOT::|EXPR;-;2$;8|
    BOOT::|ILIST;member?;S$B;24|
    BOOT::|ILIST;rest;$Nni$;19|
    BOOT::|replaceGoGetSlot|
    BOOT::|IDPAG;-;2$;1|
    BOOT::|FRAC;+;3$;21|
    BOOT::|PGCD;gcdTermList|
    BOOT::|matchMmSig|
    BOOT::|isHomogeneousList|
    BOOT::|LO;-;2$;3|
    BOOT::|EUCDOM-;gcd;3S;5|
    BOOT::|newLookupInAddChain|
    BOOT::|LO;=;2$B;4|
    BOOT::|newLookupInDomain|
    BOOT::|atom2String|
;;    BOOT::|SMP;variables;$L;51!0|
;;    VMLISP::CONCAT
    BOOT::|IARRAY1;elt;$IS;16|
;;    BOOT::|newGoGet|
    BOOT::|EXPR;+;3$;12|
    BOOT::|COMPCAT-;rem;3S;53|
    BOOT::|FIELD-;/;3S;11|
    BOOT::|SMP;univariate;$VarSetSup;13|
;;    BOOT::|npInfKey|
    BOOT::|hasCate|
    BOOT::|URAGG-;tail;2A;16|
    BOOT::|npInfGeneric|
    BOOT::|FACUTIL;lowerPolynomial;SupSup;1|
    BOOT::|underDomainOf|
    BOOT::|SMP;degree;$Ie;71|
    BOOT::|FAMR-;ground;SR;4|
    BOOT::|STAGG-;first;ANniA;3|
    BOOT::|FRAC;recip;$U;30|
    BOOT::|allOrMatchingMms|
    BOOT::|IARRAY1;fill!;$S$;2|
    BOOT::|IFARRAY;concat!;$S$;21|
    BOOT::|BOP;is?;$SB;1|
    BOOT::|FRAC;*;I2$;24|
    BOOT::|IFARRAY;growWith|
    BOOT::|loadIfNecessary|
    BOOT::|EXPR;coerce;I$;10|
    BOOT::|typeIsASmallInteger|
    BOOT::|ILIST;split!;$I$;29|
    BOOT::|EUCDOM-;unitNormalizeIdealElt|
    BOOT::|IDPAG;-;3$;4|
    BOOT::|RING-;coerce;IS;1|
    BOOT::|deepSubCopy|
    BOOT::|constructSubst|
    BOOT::|keyp|
    BOOT::|lookupIncomplete|
;;    SUB-WRITE-BASED
;;    SUB-WRITE-BASED-LEADING
;;    SUB-WRITE-BASED-INNER
    BOOT::|LSAGG-;reduce;MA2S;16|
;;    BOOT::|INT;coerce;I$;12|
    BOOT::|COMPLEX;+;3$;14|
    BOOT::|EXPR;/;3$;14|
    BOOT::|SMP;coerce;VarSet$;7|
    BOOT::|mkDomPvar|
    BOOT::|resolveTMEq1|
    BOOT::|MODRING;zero?;$B;10|
    BOOT::|orderMmCatStack|
    BOOT::|EXPR;zero?;$B;7|
    LIST-DELETE-DUPLICATES*-1
;;    CONCATENATE
    BOOT::|buildPredVector,fn|
    BOOT::|COMPCAT-;-;2S;17|
    BOOT::|PR;exquo;$RU;31|
    BOOT::|SMP;degree;$VarSetNni;69|
    BOOT::|MODRING;reduce;RMod$;6|
    BOOT::|hasCaty|
    BOOT::|FS-;coerce;KS;19|
    LIST-TO-VECTOR*
;; end
    BOOT::|basicLookup|
    BOOT::|URAGG-;last;AS;7|
    BOOT::|unifyStruct|
    BOOT::|ILIST;merge!;M3$;28|
    BOOT::|argCouldBelongToSubdomain|
    BOOT::|deepSubCopyOrNil|
    BOOT::|UPOLYC2;map;MPRPS;1|
;;    BOOT::|isLegitimateMode|
;;    BOOT::|npEnclosed|
;;    BOOT::|newLookupInCategories|
    BOOT::|LIST;setUnion;3$;5|
;;    BOOT::|newType?|
;;    BOOT::|isSharpVar|
;;    BOOT::|lassocShiftWithFunction|
;;    BOOT::|isValidType|
;;    VMLISP:CHARP
    BOOT::|EUCDOM-;extendedEuclidean;2SR;7|
;;    FUNCTIONP
    BOOT::|COMPCAT-;norm;SR;9|
    BOOT::|SYMBOL;coerce;S$;3|
;;    BOOT::|mmCatComp|
;;    MAKE-SEQUENCE-OF-TYPE
;;    BOOT:MKQ
;;    BOOT::|transferPropsToNode,transfer|
;;    BOOT::|deepSubCopy0|
;;    BOOT::|getOpBindingPower|
    BOOT::|COMPCAT-;conjugate;2S;12|
;;    BOOT::|npDDInfKey|
;;    BOOT::|isWrapped|
;;    BOOT::|ncTag|
    BOOT::|DIRPROD;subtractIfCan;2$U;14|
;;    BOOT::|npEqPeek|
;;    BOOT::|eqType|
    BOOT::|PR;minimumDegree;$E;5|
    BOOT::|SET;=;2$B;16|
    BOOT::|SET;union;3$;27|
;;    BOOT::WIDTH
;;    BOOT::|findFunctionInDomain|
;;    BOOT::|resolveTMSpecial|
    BOOT::|INT;convert;$I;13|
;;    BOOT::|search|
    BOOT::|SET;parts;$L;6|
;;    STRING-TRIM1
    BOOT::|ES-;listk|
;;    BOOT::|containsVariables|
;;    BOOT::|newHasCategory|
;;    BOOT::|getValue|
    BOOT::|ES-;tower;SL;5|
;;    BOOT::|hasCate1|
;;    BOOT::|infixArgNeedsParens|
;;    BOOT::|symEqual|
    BOOT::|A1AGG-;parts;AL;1|
;;    BOOT::|npParenthesize|
;;    BOOT::APP
    BOOT::|POLYLIFT;map;MMPS;1|
;;    BOOT::|pfNoPosition?|
;;    BOOT::|poNoPosition?|
;;    BOOT::|objValUnwrap|
;;    BOOT::|equiType|
;;    BOOT::|ncPutQ|
;;    BOOT::|pfId?|
    BOOT::|SMP;-;3$;26|
;;    BOOT::|getBindingPowerOf|
;;    BOOT::|searchCurrentEnv|
;;    BOOT::|loadLib|
;;    VMLISP:RPLACSTR
    BOOT::|ES-;allk|
;;    BOOT::|evalMmCat|
    BOOT::|FACUTIL;variables;SupL;5|
;;    BOOT::|apphor|
    BOOT::|ILIST;=;2$B;22|
;;    BOOT::|npPush|
;;    BOOT::|voidValue|
;;    BOOT::|npLeftAssoc|
    BOOT::|ES-;allKernels|
;;    BOOT::|getAtree|
;;    BOOT::|putWidth|
;;    BOOT::|tokPosn|
    BOOT::|PGCD;gcd;LP;16|
;;    BOOT::|unwrap|
;;    BOOT::|domArg2|
;;    BOOT::|addConsDB|
;;    BOOT::|appChar|
;;    BOOT::|npAnyNo|
    BOOT::|FRAC;/;2S$;15|
;;    BOOT::|pfAbSynOp|
;;    BOOT::|npPDefinition|
;;    BOOT::|loadLibIfNecessary|
;;    BOOT::|keyword|
;;    BOOT::|npParenthesized|
    BOOT::|KERNEL;is?;$SB;1|
;;    BOOT::|wrap|
;;    BOOT::|evalMmCat1|
;;    BOOT::|putAtree|
;;    BOOT::|leftBindingPowerOf|
;;    BOOT::|npAngleBared|
    BOOT::|PGCD;monomContent|
;;    BOOT::|compiledLookup|
;;    BOOT::|getTarget|
;;    BOOT::|newExpandLocalTypeForm|
    BOOT::|FS-;mainKernel;SU;75|
    BOOT::|IDPOAM;<;2$B;1|
;;    BOOT::|getUnname1|
;;    REPORT-KEYWORDS
    BOOT::|MATRIX;minColIndex;$I;2|
    BOOT::|FIELD-;exquo;2SU;5|
    BOOT::|SMP;evalSortedVarlist!0|
;;    SUB-WRITE-1
;;    BOOT::|getUnname|
    BOOT::|FAMR-;ground?;SB;1|
;;    BOOT::|diffAlist|
;;    BOOT::|objNewWrap|
    BOOT::|IXAGG-;swap!;S2IndexV;10|
    BOOT::|DIRPROD;=;2$B;6|
    BOOT::|GENEEZ;reduction;BPRBP;4!0|
    BOOT::|FRAC;retract;$F;28|
    BOOT::|EXPR;retract;$F;99|
;;    BOOT::|tokConstruct|
;;    BOOT::|mkEvalable|
    BOOT::|KERNEL;is?;$BoB;2|
;;    BOOT::|pfApplication?|
;;    BOOT::|NRTgetOperationAlistFromLisplib|
;;    BOOT::|pfSymbol?|
;;    POSITION
;;    BOOT::|rightBindingPowerOf|
;;    BOOT::|putHist|
;;    BOOT::|decomposeTypeIntoTower|
;;    BOOT::|pfLambda?|
;;    BOOT::|pfWhere?|
;;    BOOT::|pfMacro?|
;;    BOOT::|HasCategory|
;;    BOOT::|insertShortAlist|
    BOOT::|ES-;retractIfCan;SU;35|
;;    SUB-WRITE-INTEGER
;;    BOOT::|pfIdSymbol|
;;    VECTOR-PUSH-EXTEND
;;    BOOT::|StreamNull|
    BOOT::|KERNEL;setPosition;$NniV;8|
;;    BOOT::|npPop1|
    BOOT::|SYMBOL;<;2$B;5|
    BOOT::|QFCAT-;<;2AB;12|
    BOOT::|FACUTIL;raisePolynomial;SupSup;2|
;;    BOOT::|npParened|
    BOOT::|EXPR;noalg?|
;;    BOOT::|npBracked|
;;    BOOT::|npBraced|
    BOOT::|EXPR;one?;$B;6|
    BOOT::|EMR;rem;3$;2|
    BOOT::|POLYCATQ;mainVariable;FU;9|
;;    BOOT::|stringer|
;;    BOOT::|evalDomain|
    BOOT::|EXPR;belong?;BoB;1|
    BOOT::|FRAC;-;3$;17|
    BOOT::|STREAM;lazy?;$B;2|
    BOOT::|MATRIX;minRowIndex;$I;1|
    BOOT::|EMR;unitCanonical;2$;5|
;;    BOOT::|hashCombine|
    BOOT::|EXPR;<;2$B;16|
    BOOT::|EXPR;-;3$;13|
;;    SUB-WRITE-SYMBOL
;;    BOOT::|punctuation?|
;;    BOOT::|packageTran|
    BOOT::|SMP;retractIfCan;$U;50|
;;    BOOT::|pfNothing?|
;;    BOOT::|evalSlotDomain|
;;    BOOT::|Delay|
    BOOT::|FRAC;*;S2$;20|
;;    BOOT::|pfParts|
;;    BOOT::|height|
    VMLISP::HPUT
;;    BOOT::|noSharpCallsHere|
    BOOT::|KERNEL;symbolIfCan;$U;12|
    BOOT::|SMP;evalSortedVarlist|
    BOOT::|POLYCAT-;<;2SB;38|
;;    BOOT::|getMode|
;;    BOOT::|recordNewValue|
    BOOT::|MONOID-;**;SNniS;5|
;;    BOOT::|transferPropsToNode|
;;    BOOT::|pfLiteral?|
    BOOT::|MODULE-;*;SRS;1|
;;    BOOT::|npTypedForm|
;;    VECTOR-POSITION*
;;    LIST-REMOVE-DUPLICATES*-1
;;    BOOT::|hasCateSpecial|
    BOOT::|HEUGCD;lintgcd;LI;6!0|
    BOOT::|PGCD;gcdMonom|
;;    BOOT::|getConstructorModemap|
    BOOT::|SUP;gcd;3$;30|
;;    BOOT::|domArg|
    BOOT::|ES-;height;SNni;8|
;;    BOOT::|getBasicMode|
    BOOT::|INS-;euclideanSize;SNni;9|
;;    BOOT::|npNext|
    BOOT::|BOP;arity;$U;25|
;;    BOOT::|lnExtraBlanks|
;;    BOOT::|recordOldValue|
    BOOT::|GENEEZ;reduction;BPRBP;4|
;;    SORT-LIST
    BOOT::|SCACHE;cache;L;1|
    BOOT::|PR;retractIfCan;$U;9|
;;    BOOT::|npBackTrack|
    BOOT::|STREAM;explicitlyEmpty?;$B;1|
;;    BOOT::|npBDefinition|
;;    BOOT::|dqAppend|
    BOOT::|GCDDOM-;lcm;3S;1|
;;    COMPILED-FUNCTION-P
    BOOT::|MDDFACT;merge|
;;    BOOT::|defaultTypeForCategory|
;;    BOOT::|dqUnit|
    BOOT::|PR;coefficient;$ER;10|
;;    BOOT::|wordFrom|
    BOOT::|FRAC;retract;$S;3|
    BOOT::|SMP;multivariate;SupVarSet$;13|
    BOOT::|ES-;is?;SBoB;37|
;;    BOOT::|pfMapParts|
;;    BOOT::|listTruncate|
;;    DELETE-DUPLICATES-1
;;    BOOT::|hasCateSpecialNew|
    BOOT::|MODRING;newmodulo|
    BOOT::|URAGG-;second;AS;4|
    BOOT::|SMP;eval;$LL$;57|
    BOOT::|PGCD;gcd;3Sup;11|
;;    BOOT::|pfLeaf?|
;;    BOOT::|pfTree|
;;    SORT-2
;;    BOOT::|npName|
    BOOT::|SUP;content;$R;28|
    BOOT::|INTDOM-;recip;SU;3|
    BOOT::|FS-;smpeval!3|
    BOOT::|SUP;elt;$2R;22|
    BOOT::|HEUGCD;lintgcd;LI;6|
;;    BOOT::|constoken|
;;    BOOT::|isQuotient|
    BOOT::|LGROBP;reduceRow|
;;    BOOT::|fixUpTypeArgs|
;;    BOOT::|hashType|
;;    BOOT::|optimize|
;;    FLOAT-STRING
;;    VMLISP:LIST2VEC
;;    BOOT::|makeStatString|
;;    BOOT::|npDotted|
;;    BOOT::|macExpand|
;;    PRINC
;;    BOOT::|startsNegComment?|
    BOOT::|SMP;**;$Nni$;29|
;;    BOOT::|isInterpMacro|
    BOOT::|FS-;retract;SR;88|
;;    BOOT::|startsComment?|
    BOOT::|STREAM;delay;M$;56|
;;    BOOT::|constructT|
;;    BOOT::|recordNewValue0|
;;    BOOT::|npBracketed|
;;    BOOT::|recordOldValue0|
;;    BOOT::|NRTevalDomain|
    BOOT::|KERNEL;kernel;BoLNni$;15|
    BOOT::|FLAGG-;position;SAI;1|
    BOOT::|LSAGG-;position;SA2I;23|
;;    BOOT::|scanToken|
;;    REMOVE-DUPLICATES-1
;;    BOOT::|npEncAp|
    BOOT::|MODRING;*;3$;17|
    BOOT::|SUP2;map;MSupSup;1|
;;    BOOT::|devaluateList|
;;    BOOT::|getModemapsFromDatabase|
;;    BOOT::|newExpandLocalTypeArgs|
    BOOT::|STREAM;empty?;$B;36|
    BOOT::|GBINTERN;redPo;DpolLR;13|
;;    BOOT::|buildPredVector|
;;    BOOT::|putIntSymTab|
;;    BOOT::|tokType|
;;    ALPHANUMERICP
)))

;; The following are functions that at present crash the Lisp to C compiler..
;; The difficulty as of mid March is that they use DECLARE and the compiler
;; does not know how to handle that (yet).

(null (setq avoids '(
BOOT::|matchMmCond|
BOOT::|findFunctionInDomain1| ;; Added by MCD.
BOOT::|npEqKey|
BOOT::GETDATABASE
BOOT::|evalMmCond|
VMLISP:STRPOS
BOOT:LASSOC
BOOT::|npRestore|
BOOT::|newLookupInTable|
BOOT::|npState|
BOOT::|npFirstTok|
BOOT::|oldCompLookup|
DIVIDE
VMLISP:CONCAT
BOOT::|newGoGet|
BOOT::|npInfKey|

;; I do not know what is wrong with the following at present, but it seems
;; to break things for me...

;; Hah - Barry Trager spotted the problem - order of evaluation of args!

;;; BOOT::|STAGG-;first;ANniA;3|

)))


(load_source_database "cclwhereis.lsp")

(setq *print-array* t)

(setq failures nil)

(while fnames
   (let ((bulk 0))
   (princ "About to create ") (princ (car fnames)) (terpri)
   (c::ccompilestart (car fnames))
   (while (and (< bulk size_per_file) targets)
      (let* ((name (car targets))
             (pk (symbol-package name))
             (defn (if pk (package-name pk) nil))
             (nnn (symbol-name name))
             (location (gethash (list defn nnn) *where_defined*)))
        (when (member name avoids) (setq location nil))
        (when (null location)
            (princ "+++++ ") (prin name) (princ " not available") (terpri)
            (setq targets (cdr targets)))
        (when location
           (setq pk (open (car location) :direction :input))
           (when pk
              (file-position pk (cadr location))
              (let ((*package* (find-package (caddr location))))
                 (setq defn (read pk)))
              (close pk)
              (terpri) (princ "+++ ") (prin name) (ttab 30) 
              (prin location) (terpri)
              (setq bulk (listsize defn bulk))
              (when (< bulk size_per_file)
                  (prin name) (terpri)
;; I stick the Lisp code for each function into the C file as a comment. I
;; need to hope (ha ha) that the text of the Lisp code does not contain the
;; string "*/" (as for instance this function would!) since that would
;; terminate the C comment prematurely in an awkward manner!
                  (wrs C_file)
                  (princ "/*") (terpri)
                  (let ((w (linelength 80)))
                      (prettyprint defn)
                      (linelength w))
                  (terpri) (princ "*/") (terpri) (terpri)
                  (wrs O_file)
                  (when (atom (errorset (list 'c::ccmpout1 (mkquote defn)) t t))
                      (setq failures (cons name failures)))
                  (wrs O_file) ;; useful in case compiletion crashes.
                  (setq targets (cdr targets)))))))
   (c-end)
   (setq fnames (cdr fnames))))))


(wrs O_file)

(list 'failures (reverse failures))

(list 'remaining targets)

'done

