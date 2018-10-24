
;;;  u05.lsp             Machine generated Lisp  Thu Oct 26 09:49:16 2000

(in-package lisp)

(c::install '|BOOT@@evalMmDom@@Builtin| 'BOOT::|evalMmDom| '(BOOT::|evalMmDom|
BOOT::|isDomain| BOOT::|failed| BOOT::|isFreeFunction| CONSP BOOT::|subCopy|
BOOT::|augmentSub|))

(c::install '|LISP@@QUOTIENT@@Builtin| 'QUOTIENT '(QUOTIENT TRUNCATE /))

(c::install '|BOOT@@FAMR-;coefficients;SL;6@@Builtin| 'BOOT::|FAMR-;coefficients;SL;6| '
(BOOT::|FAMR-;coefficients;SL;6|))

(c::install '|BOOT@@LSAGG-;select!;M2A;5@@Builtin| 'BOOT::|LSAGG-;select!;M2A;5| '
(BOOT::|LSAGG-;select!;M2A;5|))

(c::install '|BOOT@@LSAGG-;<;2AB;25@@Builtin| 'BOOT::|LSAGG-;<;2AB;25| '
(BOOT::|LSAGG-;<;2AB;25|))

(c::install '|BOOT@@isSubDomain@@Builtin| 'BOOT::|isSubDomain| '(BOOT::|isSubDomain|
(BOOT:|Integer| BOOT:|NonNegativeInteger| BOOT:|PositiveInteger|)))

(c::install '|BOOT@@KERNEL;=;2$B;13@@Builtin| 'BOOT::|KERNEL;=;2$B;13| '
(BOOT::|KERNEL;=;2$B;13| BOOT::|KERNEL;triage|))

(c::install '|BOOT@@CDRwithIncrement@@Builtin| 'BOOT::|CDRwithIncrement| '
(BOOT::|CDRwithIncrement|))

(c::install '|BOOT@@lookupInDomainVector@@Builtin| 'BOOT::|lookupInDomainVector| '
(BOOT::|lookupInDomainVector| CONSP BOOT::|basicLookupCheckDefaults| ELT
FUNCALL*))

(c::install '|BOOT@@KERNEL;<;2$B;14@@Builtin| 'BOOT::|KERNEL;<;2$B;14| '
(BOOT::|KERNEL;<;2$B;14| BOOT::|KERNEL;triage|))

(c::install '|BOOT@@FRAC;cancelGcd@@Builtin| 'BOOT::|FRAC;cancelGcd| '(
BOOT::|FRAC;cancelGcd| "gcd not gcd in QF cancelGcd (numerator)"
"gcd not gcd in QF cancelGcd (denominator)" BOOT::|error|))

(c::install '|BOOT@@KERNEL;triage@@Builtin| 'BOOT::|KERNEL;triage| '(
BOOT::|KERNEL;triage| "%specialEqual" BOOT::|KERNEL;B2Z|))

(c::install '|BOOT@@isPartialMode@@Builtin| 'BOOT::|isPartialMode| '(
BOOT::|isPartialMode| BOOT::|$EmptyMode| CONTAINED))

(c::install '|BOOT@@ILIST;mergeSort@@Builtin| 'BOOT::|ILIST;mergeSort| '
(BOOT::|ILIST;mergeSort| (BOOT:|NonNegativeInteger|) BOOT::QUOTIENT2 >=
BOOT::COERCE-FAILURE-MSG BOOT::|error| FUNCALL*))

(c::install '|BOOT@@getDomainByteVector@@Builtin| 'BOOT::|getDomainByteVector| '
(BOOT::|getDomainByteVector| ELT))

(c::install '|BOOT@@isFunctor@@Builtin| 'BOOT::|isFunctor| '(BOOT::|isFunctor|
BOOT::|$InteractiveMode| (BOOT::|Union| BOOT::|SubDomain| BOOT::|Mapping|
BOOT::|Record|) BOOT::CONSTRUCTORKIND (BOOT::|domain| BOOT::|package|)
BOOT::|$CategoryFrame| (BOOT::|SubDomain| BOOT::|Union| BOOT::|Record|)
BOOT::|category| BOOT::|opOf| SYMBOLP BOOT::GETDATABASE BOOT::|get| BOOT::|constructor?|
BOOT::|updateCategoryFrameForCategory| BOOT::|updateCategoryFrameForConstructor|
))

(c::install '|BOOT@@SMP;leadingCoefficient;$R;77@@Builtin| 'BOOT::|SMP;leadingCoefficient;$R;77| '
(BOOT::|SMP;leadingCoefficient;$R;77|))

(c::install '|BOOT@@EXPR;commonk@@Builtin| 'BOOT::|EXPR;commonk| '(BOOT::|EXPR;commonk|
BOOT::|EXPR;algkernels| BOOT::|EXPR;commonk0|))

(c::install '|BOOT@@SMP;retract;$R;59@@Builtin| 'BOOT::|SMP;retract;$R;59| '
(BOOT::|SMP;retract;$R;59| "cannot retract nonconstant polynomial" BOOT::|error|
))

(c::install '|BOOT@@IDPAM;monomial;AS$;6@@Builtin| 'BOOT::|IDPAM;monomial;AS$;6| '
(BOOT::|IDPAM;monomial;AS$;6|))

(c::install '|BOOT@@PRIMARR;fill!;$S$;9@@Builtin| 'BOOT::|PRIMARR;fill!;$S$;9| '
(BOOT::|PRIMARR;fill!;$S$;9| SETELT))

(c::install '|BOOT@@IFARRAY;maxIndex;$I;6@@Builtin| 'BOOT::|IFARRAY;maxIndex;$I;6| '
(BOOT::|IFARRAY;maxIndex;$I;6|))

(c::install '|BOOT@@lookupComplete@@Builtin| 'BOOT::|lookupComplete| '(
BOOT::|lookupComplete| BOOT::|hashCode?| BOOT::|hashNewLookupInTable|
BOOT::|newLookupInTable|))

(c::install '|BOOT@@FRAC;one?;$B;28@@Builtin| 'BOOT::|FRAC;one?;$B;28| '
(BOOT::|FRAC;one?;$B;28|))

(c::install '|BOOT@@getSystemModemaps@@Builtin| 'BOOT::|getSystemModemaps| '
(BOOT::|getSystemModemaps| BOOT::OPERATION BOOT::|iterate| BOOT::|$getUnexposedOperations|
BOOT::GETDATABASE VMLISP:SIZE BOOT::|isFreeFunctionFromMm| BOOT::|getDomainFromMm|
BOOT::|isExposedConstructor|))

(c::install '|BOOT@@stuffSlot@@Builtin| 'BOOT::|stuffSlot| '(BOOT::|stuffSlot|
BOOT::|newGoGet| CONS FUNCALL BOOT::$ BOOT::|makeSpadConstant|
"Unexpected constant environment!!" CONSP SETELT CHARACTER BOOT::|eval|
BOOT:|sayBrightlyNT| BOOT::|devaluate| BOOT:|pp|))


;;; End of generated Lisp code

