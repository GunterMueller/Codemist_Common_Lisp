
;;;  u08.lsp             Machine generated Lisp  Thu Oct 26 09:49:24 2000

(in-package lisp)

(c::install '|BOOT@@PGCD;gcd;3P;15@@Builtin| 'BOOT::|PGCD;gcd;3P;15| '(
BOOT::|PGCD;gcd;3P;15| BOOT::|PGCD;gcdTermList| BOOT::COERCE-FAILURE-MSG
BOOT::|error|))

(c::install '|BOOT@@filterModemapsFromPackages@@Builtin| 'BOOT::|filterModemapsFromPackages| '
(BOOT::|filterModemapsFromPackages| ("Polynomial"
"MultivariatePolynomial" "DistributedMultivariatePolynomial"
"HomogeneousDistributedMultivariatePolynomial") ("MFactorize"
"MRationalFactorize") BOOT::CONSTRUCTORKIND BOOT::|category| BOOT::|factor|
BOOT::|isFreeFunctionFromMm| BOOT::|getDomainFromMm| CONSP BOOT::GETDATABASE
BOOT::|object2String| VMLISP:STRPOS VMLISP:|member|))

(c::install '|BOOT@@selectMmsGen,matchMms@@Builtin| 'BOOT::|selectMmsGen,matchMms| '
(BOOT::|selectMmsGen,matchMms| BOOT::|$Subst| BOOT::|failed| BOOT::|isPartialMode|
VMLISP:|member| BOOT::|matchTypes| BOOT::|evalMm|))

(c::install '|BOOT@@BOP;<;2$B;29@@Builtin| 'BOOT::|BOP;<;2$B;29| '(BOOT::|BOP;<;2$B;29|
"%less?" "%equal?" VMLISP:GGREATERP VMLISP:CGREATERP))

(c::install '|BOOT@@evalMmStack@@Builtin| 'BOOT::|evalMmStack| '(BOOT::|evalMmStack|
AND OR BOOT::|partial| BOOT::|ofCategory| BOOT::|Join| BOOT::|ofType|
BOOT::|has| (BOOT::ATTRIBUTE BOOT::SIGNATURE) BOOT::CATEGORY BOOT::|unknown|
CONSP BOOT::|evalMmStackInner| APPEND NREVERSE0))

(c::install '|BOOT@@EXPR;commonk0@@Builtin| 'BOOT::|EXPR;commonk0| '(
BOOT::|EXPR;commonk0| NREVERSE))

(c::install '|BOOT@@get0@@Builtin| 'BOOT::|get0| '(BOOT::|get0| BOOT::|get|
BOOT:QLASSQ BOOT::|fastSearchCurrentEnv|))

(c::install '|BOOT@@sigDomainVal@@Builtin| 'BOOT::|sigDomainVal| '(BOOT::|sigDomainVal|
BOOT::$ ELT))

(c::install '|BOOT@@FSAGG-;brace;LA;3@@Builtin| 'BOOT::|FSAGG-;brace;LA;3| '
(BOOT::|FSAGG-;brace;LA;3|))

(c::install '|BOOT@@MONOID-;one?;SB;2@@Builtin| 'BOOT::|MONOID-;one?;SB;2| '
(BOOT::|MONOID-;one?;SB;2|))

(c::install '|BOOT@@STAGG-;c2@@Builtin| 'BOOT::|STAGG-;c2| '(BOOT::|STAGG-;c2|
"Index out of range" BOOT::|error|))

(c::install '|BOOT@@IFARRAY;#;$Nni;4@@Builtin| 'BOOT::|IFARRAY;#;$Nni;4| '
(BOOT::|IFARRAY;#;$Nni;4| (BOOT:|NonNegativeInteger|) >= BOOT::COERCE-FAILURE-MSG
BOOT::|error|))

(c::install '|BOOT@@IDPAM;map;M2$;7@@Builtin| 'BOOT::|IDPAM;map;M2$;7| '
(BOOT::|IDPAM;map;M2$;7| NREVERSE0))

(c::install '|BOOT@@resolveTMEq@@Builtin| 'BOOT::|resolveTMEq| '(BOOT::|resolveTMEq|
BOOT::|failed| BOOT::|$Subst| BOOT::|resolveTMSpecial| BOOT::|deconstructT|
BOOT::|containsVars| BOOT::|resolveTMEq2| BOOT::|augmentSub| BOOT::|resolveTMEq1|
VMLISP:|last|))


;;; End of generated Lisp code

