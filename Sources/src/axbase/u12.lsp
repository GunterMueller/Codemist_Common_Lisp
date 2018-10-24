
;;;  u12.lsp             Machine generated Lisp  Thu Oct 26 09:49:35 2000

(in-package lisp)

(c::install '|BOOT@@isHomogeneousList@@Builtin| 'BOOT::|isHomogeneousList| '
(BOOT::|isHomogeneousList| CONSP))

(c::install '|BOOT@@LO;-;2$;3@@Builtin| 'BOOT::|LO;-;2$;3| '(BOOT::|LO;-;2$;3|
))

(c::install '|BOOT@@EUCDOM-;gcd;3S;5@@Builtin| 'BOOT::|EUCDOM-;gcd;3S;5| '
(BOOT::|EUCDOM-;gcd;3S;5|))

(c::install '|BOOT@@newLookupInAddChain@@Builtin| 'BOOT::|newLookupInAddChain| '
(BOOT::|newLookupInAddChain| BOOT::|$monitorNewWorld|
"looking up add-chain: " "<----add-chain function found for " "<----"
BOOT::|sayLooking1| BOOT::|newLookupInDomain| BOOT::|devaluate| BOOT::|form2String|
BOOT::|concat|))

(c::install '|BOOT@@LO;=;2$B;4@@Builtin| 'BOOT::|LO;=;2$B;4| '(BOOT::|LO;=;2$B;4|
))

(c::install '|BOOT@@newLookupInDomain@@Builtin| 'BOOT::|newLookupInDomain| '
(BOOT::|newLookupInDomain| ELT SIMPLE-VECTOR-P BOOT::|lazyDomainSet| BOOT::|lookupInDomainVector|
))

(c::install '|BOOT@@atom2String@@Builtin| 'BOOT::|atom2String| '(BOOT::|atom2String|
SYMBOLP SYSTEM::PNAME BOOT::|stringer|))

(c::install '|BOOT@@IARRAY1;elt;$IS;16@@Builtin| 'BOOT::|IARRAY1;elt;$IS;16| '
(BOOT::|IARRAY1;elt;$IS;16| "index out of range" ELT BOOT::|error|))

(c::install '|BOOT@@EXPR;+;3$;12@@Builtin| 'BOOT::|EXPR;+;3$;12| '(BOOT::|EXPR;+;3$;12|
BOOT::|EXPR;commonk| BOOT::|EXPR;reduc|))

(c::install '|BOOT@@COMPCAT-;rem;3S;53@@Builtin| 'BOOT::|COMPCAT-;rem;3S;53| '
(BOOT::|COMPCAT-;rem;3S;53|))

(c::install '|BOOT@@FIELD-;/;3S;11@@Builtin| 'BOOT::|FIELD-;/;3S;11| '(
BOOT::|FIELD-;/;3S;11| "catdef: division by zero" BOOT::|error|))

(c::install '|BOOT@@SMP;univariate;$VarSetSup;13@@Builtin| 'BOOT::|SMP;univariate;$VarSetSup;13| '
(BOOT::|SMP;univariate;$VarSetSup;13| FUNCALL* BOOT::|SMP;red|))

(c::install '|BOOT@@hasCate@@Builtin| 'BOOT::|hasCate| '(BOOT::|hasCate|
BOOT::|$EmptyMode| BOOT::|failed| BOOT::|$Subst| BOOT::|$hope| BOOT::|isPatternVar|
BOOT::|hasCate1| BOOT::|hasCateSpecial| BOOT::|containsVariables|
NREVERSE0 BOOT::|subCopy| BOOT::|hasCaty|))

(c::install '|BOOT@@URAGG-;tail;2A;16@@Builtin| 'BOOT::|URAGG-;tail;2A;16| '
(BOOT::|URAGG-;tail;2A;16| "empty list" "cyclic list" BOOT::|error|))

(c::install '|BOOT@@npInfGeneric@@Builtin| 'BOOT::|npInfGeneric| '(BOOT::|npInfGeneric|
BOOT::BACKSET BOOT::|npDDInfKey| BOOT::|npEqKey|))

(c::install '|BOOT@@FACUTIL;lowerPolynomial;SupSup;1@@Builtin| 'BOOT::|FACUTIL;lowerPolynomial;SupSup;1| '
(BOOT::|FACUTIL;lowerPolynomial;SupSup;1|))

(c::install '|BOOT@@underDomainOf@@Builtin| 'BOOT::|underDomainOf| '(
BOOT::|underDomainOf| BOOT::|underDomainOf;AL| GETHASH BOOT::|CDRwithIncrement|
BOOT::|underDomainOf;| VMLISP::HPUT))

(c::install '|BOOT@@SMP;degree;$Ie;71@@Builtin| 'BOOT::|SMP;degree;$Ie;71| '
(BOOT::|SMP;degree;$Ie;71|))

(c::install '|BOOT@@FAMR-;ground;SR;4@@Builtin| 'BOOT::|FAMR-;ground;SR;4| '
(BOOT::|FAMR-;ground;SR;4|))

(c::install '|BOOT@@STAGG-;first;ANniA;3@@Builtin| 'BOOT::|STAGG-;first;ANniA;3| '
(BOOT::|STAGG-;first;ANniA;3| NREVERSE0 BOOT::|STAGG-;c2|))

(c::install '|BOOT@@FRAC;recip;$U;30@@Builtin| 'BOOT::|FRAC;recip;$U;30| '
(BOOT::|FRAC;recip;$U;30| "failed"))

(c::install '|BOOT@@allOrMatchingMms@@Builtin| 'BOOT::|allOrMatchingMms| '
(BOOT::|allOrMatchingMms| BOOT::$))

(c::install '|BOOT@@IARRAY1;fill!;$S$;2@@Builtin| 'BOOT::|IARRAY1;fill!;$S$;2| '
(BOOT::|IARRAY1;fill!;$S$;2| SETELT))

(c::install '|BOOT@@IFARRAY;concat!;$S$;21@@Builtin| 'BOOT::|IFARRAY;concat!;$S$;21| '
(BOOT::|IFARRAY;concat!;$S$;21| BOOT::|IFARRAY;growAndFill| SETELT))

(c::install '|BOOT@@BOP;is?;$SB;1@@Builtin| 'BOOT::|BOP;is?;$SB;1| '(
BOOT::|BOP;is?;$SB;1|))

(c::install '|BOOT@@FRAC;*;I2$;24@@Builtin| 'BOOT::|FRAC;*;I2$;24| '(
BOOT::|FRAC;*;I2$;24| BOOT::|FRAC;cancelGcd| BOOT::|FRAC;normalize|))

(c::install '|BOOT@@IFARRAY;growWith@@Builtin| 'BOOT::|IFARRAY;growWith| '
(BOOT::|IFARRAY;growWith| (BOOT:|NonNegativeInteger|) >= BOOT::COERCE-FAILURE-MSG
BOOT::|error| ELT SETELT))

(c::install '|BOOT@@loadIfNecessary@@Builtin| 'BOOT::|loadIfNecessary| '
(BOOT::|loadIfNecessary| BOOT::|loadLibIfNecessary|))

(c::install '|BOOT@@EXPR;coerce;I$;10@@Builtin| 'BOOT::|EXPR;coerce;I$;10| '
(BOOT::|EXPR;coerce;I$;10|))

(c::install '|BOOT@@typeIsASmallInteger@@Builtin| 'BOOT::|typeIsASmallInteger| '
(BOOT::|typeIsASmallInteger| BOOT::|$SingleInteger|))

(c::install '|BOOT@@ILIST;split!;$I$;29@@Builtin| 'BOOT::|ILIST;split!;$I$;29| '
(BOOT::|ILIST;split!;$I$;29| "index out of range" (BOOT:|NonNegativeInteger|
) BOOT::|error| >= BOOT::COERCE-FAILURE-MSG))

(c::install '|BOOT@@EUCDOM-;unitNormalizeIdealElt@@Builtin| 'BOOT::|EUCDOM-;unitNormalizeIdealElt| '
(BOOT::|EUCDOM-;unitNormalizeIdealElt| VECTOR))

(c::install '|BOOT@@IDPAG;-;3$;4@@Builtin| 'BOOT::|IDPAG;-;3$;4| '(BOOT::|IDPAG;-;3$;4|
BOOT::|IDPAG;qsetrest!| BOOT::FIRST-ERROR))

(c::install '|BOOT@@RING-;coerce;IS;1@@Builtin| 'BOOT::|RING-;coerce;IS;1| '
(BOOT::|RING-;coerce;IS;1|))

(c::install '|BOOT@@deepSubCopy@@Builtin| 'BOOT::|deepSubCopy| '(BOOT::|deepSubCopy|
BOOT::|deepSubCopy0|))


;;; End of generated Lisp code

