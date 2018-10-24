;;; -*- Mode:Lisp; Package:Boot  -*-


(IN-PACKAGE "BOOT" )

;-- Copyright The Numerical Algorithms Group Limited 1991, 1992, 1993.
;
;
;--% Top Level Interpreter Code
;
;-- This file contains the top-most code for receiving parser output,
;-- calling the analysis routines and printing the result output. It
;-- also contains several flavors of routines that start the interpreter
;-- from LISP.
;
;-- When $SpadServer is true Scratchpad acts as a remote server
;SETANDFILEQ($SpadServer, NIL)

(SETANDFILEQ |$SpadServer| NIL) 
;-- When $QuiteCommand is true Spad will not produce any output from
;--  a top level command
;SETANDFILEQ($QuietCommand, NIL)

(SETANDFILEQ |$QuietCommand| NIL) 
;-- When $ProcessInteractiveValue is true, we don't want the value printed
;-- or recorded.
;SETANDFILEQ($ProcessInteractiveValue, NIL)

(SETANDFILEQ |$ProcessInteractiveValue| NIL) 
;SETANDFILEQ($HTCompanionWindowID, NIL)

(SETANDFILEQ |$HTCompanionWindowID| NIL) 
;
;--% Starting the interpreter from LISP
;
;spadpo() ==
;  -- starts the interpreter but only displays parsed input
;  $PrintOnly: local:= true
;  spad()

(DEFUN |spadpo| NIL (PROG (|$PrintOnly|) (DECLARE (SPECIAL |$PrintOnly|)) (RETURN (PROGN (SPADLET |$PrintOnly| (QUOTE T)) (|spad|))))) 
;
;spad() ==
;  -- starts the interpreter but does not read in profiles, etc.
;  $PrintCompilerMessageIfTrue: local
;  $inLispVM : local := nil
;  setOutputAlgebra "%initialize%"
;  runspad()
;  'EndOfSpad

(DEFUN |spad| NIL (PROG (|$PrintCompilerMessageIfTrue| |$inLispVM|) (DECLARE (SPECIAL |$PrintCompilerMessageIfTrue| |$inLispVM|)) (RETURN (PROGN (SPADLET |$PrintCompilerMessageIfTrue| NIL) (SPADLET |$inLispVM| NIL) (|setOutputAlgebra| (QUOTE |%initialize%|)) (|runspad|) (QUOTE |EndOfSpad|))))) 
;
;runspad() ==
;  mode:='restart
;  while mode='restart repeat
;    resetStackLimits()
;    CATCH($quitTag, CATCH('coerceFailure,
;                  mode:=CATCH('top__level, ncTopLevel())))

(DEFUN |runspad| NIL (PROG (|mode|) (RETURN (SEQ (PROGN (SPADLET |mode| (QUOTE |restart|)) (DO NIL ((NULL (|BOOT-EQUAL| |mode| (QUOTE |restart|))) NIL) (SEQ (EXIT (PROGN (|resetStackLimits|) (CATCH |$quitTag| (CATCH (QUOTE |coerceFailure|) (SPADLET |mode| (CATCH (QUOTE |top_level|) (|ncTopLevel|)))))))))))))) 
;
;start(:l) ==
;  -- The function  start  begins the interpreter process, reading in
;  -- the profile and printing start-up messages.
;  $PrintCompilerMessageIfTrue: local
;  $inLispVM : local := nil
;  if $displayStartMsgs then sayKeyedMsg("S2IZ0053",['"interpreter"])
;  initializeTimedNames($interpreterTimedNames,$interpreterTimedClasses)
;  statisticsInitialization()
;  $InteractiveFrame := makeInitialModemapFrame()
;  initializeSystemCommands()
;  initializeInterpreterFrameRing()
;  SETQ(ERROROUTSTREAM,
;    DEFIOSTREAM('((DEVICE . CONSOLE)(MODE . OUTPUT)),80,0))
;  setOutputAlgebra "%initialize%"
;  loadExposureGroupData()
;  if $displayStartMsgs then sayKeyedMsg("S2IZ0053",['"database"])
;  mkLowerCaseConTable()
;  if not $ruleSetsInitialized then initializeRuleSets()
;  if $displayStartMsgs then sayKeyedMsg("S2IZ0053",['"constructors"])
;  makeConstructorsAutoLoad()
;  GCMSG(NIL)
;  SETQ($IOindex,1)
;  if $displayStartMsgs then sayKeyedMsg("S2IZ0053",['"history"])
;  initHist()
;  if functionp 'addtopath then addtopath CONCAT($SPADROOT,'"bin")
;  SETQ($CURRENT_-DIRECTORY,_*DEFAULT_-PATHNAME_-DEFAULTS_*)
;  if null(l) then
;    if $displayStartMsgs then
;      sayKeyedMsg("S2IZ0053",[namestring ['axiom,'input]])
;    readSpadProfileIfThere()
;  if $displayStartMsgs then spadStartUpMsgs()
;  if $OLDLINE then
;    SAY fillerSpaces($LINELENGTH,'"=")
;    sayKeyedMsg("S2IZ0050",[namestring ['axiom,'input]])
;    if $OLDLINE ^= 'END__UNIT
;      then
;        centerAndHighlight($OLDLINE,$LINELENGTH,'" ")
;        sayKeyedMsg("S2IZ0051",NIL)
;      else sayKeyedMsg("S2IZ0052",NIL)
;    SAY fillerSpaces($LINELENGTH,'"=")
;    TERPRI()
;    $OLDLINE := NIL
;  $superHash := MAKE_-HASHTABLE('UEQUAL)
;  if null l then runspad()
;  'EndOfSpad

(DEFUN |start| (|&REST| #1=#:G18857 |&AUX| |l|) (DSETQ |l| #1#) (PROG (|$PrintCompilerMessageIfTrue| |$inLispVM|) (DECLARE (SPECIAL |$PrintCompilerMessageIfTrue| |$inLispVM|)) (RETURN (PROGN (SPADLET |$PrintCompilerMessageIfTrue| NIL) (SPADLET |$inLispVM| NIL) (COND (|$displayStartMsgs| (|sayKeyedMsg| (QUOTE S2IZ0053) (CONS (MAKESTRING "interpreter") NIL)))) (|initializeTimedNames| |$interpreterTimedNames| |$interpreterTimedClasses|) (|statisticsInitialization|) (SPADLET |$InteractiveFrame| (|makeInitialModemapFrame|)) (|initializeSystemCommands|) (|initializeInterpreterFrameRing|) (SETQ ERROROUTSTREAM (DEFIOSTREAM (QUOTE ((DEVICE . CONSOLE) (MODE . OUTPUT))) 80 0)) (|setOutputAlgebra| (QUOTE |%initialize%|)) (|loadExposureGroupData|) (COND (|$displayStartMsgs| (|sayKeyedMsg| (QUOTE S2IZ0053) (CONS (MAKESTRING "database") NIL)))) (|mkLowerCaseConTable|) (COND ((NULL |$ruleSetsInitialized|) (|initializeRuleSets|))) (COND (|$displayStartMsgs| (|sayKeyedMsg| (QUOTE S2IZ0053) (CONS (MAKESTRING "constructors") NIL)))) (|makeConstructorsAutoLoad|) (GCMSG NIL) (SETQ |$IOindex| 1) (COND (|$displayStartMsgs| (|sayKeyedMsg| (QUOTE S2IZ0053) (CONS (MAKESTRING "history") NIL)))) (|initHist|) (COND ((|functionp| (QUOTE |addtopath|)) (|addtopath| (CONCAT |$SPADROOT| (MAKESTRING "bin"))))) (SETQ |$CURRENT-DIRECTORY| |*DEFAULT-PATHNAME-DEFAULTS*|) (COND ((NULL |l|) (COND (|$displayStartMsgs| (|sayKeyedMsg| (QUOTE S2IZ0053) (CONS (|namestring| (CONS (QUOTE |axiom|) (CONS (QUOTE |input|) NIL))) NIL)))) (|readSpadProfileIfThere|))) (COND (|$displayStartMsgs| (|spadStartUpMsgs|))) (COND (|$OLDLINE| (SAY (|fillerSpaces| |$LINELENGTH| (MAKESTRING "="))) (|sayKeyedMsg| (QUOTE S2IZ0050) (CONS (|namestring| (CONS (QUOTE |axiom|) (CONS (QUOTE |input|) NIL))) NIL)) (COND ((NEQUAL |$OLDLINE| (QUOTE |END_UNIT|)) (|centerAndHighlight| |$OLDLINE| |$LINELENGTH| (MAKESTRING " ")) (|sayKeyedMsg| (QUOTE S2IZ0051) NIL)) ((QUOTE T) (|sayKeyedMsg| (QUOTE S2IZ0052) NIL))) (SAY (|fillerSpaces| |$LINELENGTH| (MAKESTRING "="))) (TERPRI) (SPADLET |$OLDLINE| NIL))) (SPADLET |$superHash| (|MAKE-HASHTABLE| (QUOTE UEQUAL))) (COND ((NULL |l|) (|runspad|))) (QUOTE |EndOfSpad|))))) 
;
;readSpadProfileIfThere() ==
;  -- reads SPADPROF INPUT if it exists
;  file := ['axiom,'input]
;  MAKE_-INPUT_-FILENAME file =>
;    SETQ(_/EDITFILE,file)
;    _/RQ ()
;  NIL

(DEFUN |readSpadProfileIfThere| NIL (PROG (|file|) (RETURN (PROGN (SPADLET |file| (CONS (QUOTE |axiom|) (CONS (QUOTE |input|) NIL))) (COND ((|MAKE-INPUT-FILENAME| |file|) (SETQ |/EDITFILE| |file|) (|/RQ|)) ((QUOTE T) NIL)))))) 
;
;--% Parser Output --> Interpreter
;
;processInteractive(form, posnForm) ==
;  --  Top-level dispatcher for the interpreter.  It sets local variables
;  --  and then calls processInteractive1 to do most of the work.
;  --  This function receives the output from the parser.
;
;  initializeTimedNames($interpreterTimedNames,$interpreterTimedClasses)
;
;  $op: local:= (form is [op,:.] => op; form) --name of operator
;  $Coerce: local := NIL
;  $compErrorMessageStack:local
;  $freeVars : local := NIL
;  $mapList:local := NIL            --list of maps being type analyzed
;  $compilingMap:local:= NIL        --true when compiling a map
;  $compilingLoop:local:= NIL       --true when compiling a loop body
;  $interpOnly: local := NIL        --true when in interpret only mode
;  $whereCacheList: local := NIL    --maps compiled because of where
;  $timeGlobalName: local := '$compTimeSum  --see incrementTimeSum
;  $StreamFrame: local := nil       --used in printing streams
;  $declaredMode: local := NIL      --Weak type propagation for symbols
;  $localVars:local := NIL          --list of local variables in function
;  $analyzingMapList:local := NIL   --names of maps currently being
;                                   --analyzed
;  $lastLineInSEQ: local := true    --see evalIF and friends
;  $instantCoerceCount: local := 0
;  $instantCanCoerceCount: local := 0
;  $instantMmCondCount: local := 0
;  $defaultFortVar:= 'X             --default FORTRAN variable name
;  $fortVar : local :=              --variable name for FORTRAN output
;     $defaultFortVar
;  $minivector: local := NIL
;  $minivectorCode: local := NIL
;  $minivectorNames: local := NIL
;  $domPvar: local := NIL
;  $inRetract: local := NIL
;  object := processInteractive1(form, posnForm)
;  --object := ERRORSET(LIST('processInteractive1,LIST('QUOTE,form),LIST('QUOTE,posnForm)),'t,'t)
;  if not($ProcessInteractiveValue) then
;    if $reportInstantiations = true then
;      reportInstantiations()
;      CLRHASH $instantRecord
;    writeHistModesAndValues()
;    updateHist()
;  object

(DEFUN |processInteractive| (|form| |posnForm|) (PROG (|$op| |$Coerce| |$compErrorMessageStack| |$freeVars| |$mapList| |$compilingMap| |$compilingLoop| |$interpOnly| |$whereCacheList| |$timeGlobalName| |$StreamFrame| |$declaredMode| |$localVars| |$analyzingMapList| |$lastLineInSEQ| |$instantCoerceCount| |$instantCanCoerceCount| |$instantMmCondCount| |$fortVar| |$minivector| |$minivectorCode| |$minivectorNames| |$domPvar| |$inRetract| |op| |object|) (DECLARE (SPECIAL |$op| |$Coerce| |$compErrorMessageStack| |$freeVars| |$mapList| |$compilingMap| |$compilingLoop| |$interpOnly| |$whereCacheList| |$timeGlobalName| |$StreamFrame| |$declaredMode| |$localVars| |$analyzingMapList| |$lastLineInSEQ| |$instantCoerceCount| |$instantCanCoerceCount| |$instantMmCondCount| |$fortVar| |$minivector| |$minivectorCode| |$minivectorNames| |$domPvar| |$inRetract|)) (RETURN (PROGN (|initializeTimedNames| |$interpreterTimedNames| |$interpreterTimedClasses|) (SPADLET |$op| (COND ((AND (PAIRP |form|) (PROGN (SPADLET |op| (QCAR |form|)) (QUOTE T))) |op|) ((QUOTE T) |form|))) (SPADLET |$Coerce| NIL) (SPADLET |$compErrorMessageStack| NIL) (SPADLET |$freeVars| NIL) (SPADLET |$mapList| NIL) (SPADLET |$compilingMap| NIL) (SPADLET |$compilingLoop| NIL) (SPADLET |$interpOnly| NIL) (SPADLET |$whereCacheList| NIL) (SPADLET |$timeGlobalName| (QUOTE |$compTimeSum|)) (SPADLET |$StreamFrame| NIL) (SPADLET |$declaredMode| NIL) (SPADLET |$localVars| NIL) (SPADLET |$analyzingMapList| NIL) (SPADLET |$lastLineInSEQ| (QUOTE T)) (SPADLET |$instantCoerceCount| 0) (SPADLET |$instantCanCoerceCount| 0) (SPADLET |$instantMmCondCount| 0) (SPADLET |$defaultFortVar| (QUOTE X)) (SPADLET |$fortVar| |$defaultFortVar|) (SPADLET |$minivector| NIL) (SPADLET |$minivectorCode| NIL) (SPADLET |$minivectorNames| NIL) (SPADLET |$domPvar| NIL) (SPADLET |$inRetract| NIL) (SPADLET |object| (|processInteractive1| |form| |posnForm|)) (COND ((NULL |$ProcessInteractiveValue|) (COND ((|BOOT-EQUAL| |$reportInstantiations| (QUOTE T)) (|reportInstantiations|) (CLRHASH |$instantRecord|))) (|writeHistModesAndValues|) (|updateHist|))) |object|)))) 
;
;processInteractive1(form, posnForm) ==
;  -- calls the analysis and output printing routines
;  $e : local := $InteractiveFrame
;  recordFrame 'system
;
;  startTimingProcess 'analysis
;  object   := interpretTopLevel(form, posnForm)
;  stopTimingProcess 'analysis
;
;  startTimingProcess 'print
;  if not($ProcessInteractiveValue) then
;    recordAndPrint(objValUnwrap object,objMode object)
;  recordFrame 'normal
;  stopTimingProcess 'print
;
;--spadtestValueHook(objValUnwrap object, objMode object)
;
;  object

(DEFUN |processInteractive1| (|form| |posnForm|) (PROG (|$e| |object|) (DECLARE (SPECIAL |$e|)) (RETURN (PROGN (SPADLET |$e| |$InteractiveFrame|) (|recordFrame| (QUOTE |system|)) (|startTimingProcess| (QUOTE |analysis|)) (SPADLET |object| (|interpretTopLevel| |form| |posnForm|)) (|stopTimingProcess| (QUOTE |analysis|)) (|startTimingProcess| (QUOTE |print|)) (COND ((NULL |$ProcessInteractiveValue|) (|recordAndPrint| (|objValUnwrap| |object|) (|objMode| |object|)))) (|recordFrame| (QUOTE |normal|)) (|stopTimingProcess| (QUOTE |print|)) |object|)))) 
;
;--% Result Output Printing
;
;recordAndPrint(x,md) ==
;  --  Prints out the value x which is of type m, and records the changes
;  --  in environment $e into $InteractiveFrame
;  --  $printAnyIfTrue  is documented in setvart.boot. controlled with )se me any
;  if md = '(Any) and $printAnyIfTrue  then
;    md' := first  x
;    x' := rest x
;  else
;    x' := x
;    md' := md
;  $outputMode: local := md   --used by DEMO BOOT
;  mode:= (md=$EmptyMode => quadSch(); md)
;  if (md ^= $Void) or $printVoidIfTrue then
;    if null $collectOutput then TERPRI $algebraOutputStream
;    if $QuietCommand = false then
;      output(x',md')
;  putHist('%,'value,objNewWrap(x,md),$e)
;  if $printTimeIfTrue or $printTypeIfTrue then printTypeAndTime(x',md')
;  if $printStorageIfTrue then printStorage()
;  if $printStatisticsSummaryIfTrue then printStatisticsSummary()
;  if FIXP $HTCompanionWindowID then mkCompanionPage md
;  $mkTestFlag = true => recordAndPrintTest md
;  $runTestFlag =>
;    $mkTestOutputType := md
;    'done
;  'done

(DEFUN |recordAndPrint| (|x| |md|) (PROG (|$outputMode| |x'| |md'| |mode|) (DECLARE (SPECIAL |$outputMode|)) (RETURN (PROGN (COND ((AND (|BOOT-EQUAL| |md| (QUOTE (|Any|))) |$printAnyIfTrue|) (SPADLET |md'| (CAR |x|)) (SPADLET |x'| (CDR |x|))) ((QUOTE T) (SPADLET |x'| |x|) (SPADLET |md'| |md|))) (SPADLET |$outputMode| |md|) (SPADLET |mode| (COND ((|BOOT-EQUAL| |md| |$EmptyMode|) (|quadSch|)) ((QUOTE T) |md|))) (COND ((OR (NEQUAL |md| |$Void|) |$printVoidIfTrue|) (COND ((NULL |$collectOutput|) (TERPRI |$algebraOutputStream|))) (COND ((NULL |$QuietCommand|) (|output| |x'| |md'|)) ((QUOTE T) NIL)))) (|putHist| (QUOTE |%|) (QUOTE |value|) (|objNewWrap| |x| |md|) |$e|) (COND ((OR |$printTimeIfTrue| |$printTypeIfTrue|) (|printTypeAndTime| |x'| |md'|))) (COND (|$printStorageIfTrue| (|printStorage|))) (COND (|$printStatisticsSummaryIfTrue| (|printStatisticsSummary|))) (COND ((FIXP |$HTCompanionWindowID|) (|mkCompanionPage| |md|))) (COND ((|BOOT-EQUAL| |$mkTestFlag| (QUOTE T)) (|recordAndPrintTest| |md|)) (|$runTestFlag| (SPADLET |$mkTestOutputType| |md|) (QUOTE |done|)) ((QUOTE T) (QUOTE |done|))))))) 
;
;printTypeAndTime(x,m) ==  --m is the mode/type of the result
;  $saturn => printTypeAndTimeSaturn(x, m)
;  printTypeAndTimeNormal(x, m)

(DEFUN |printTypeAndTime| (|x| |m|) (COND (|$saturn| (|printTypeAndTimeSaturn| |x| |m|)) ((QUOTE T) (|printTypeAndTimeNormal| |x| |m|)))) 
;
;printTypeAndTimeNormal(x,m) ==
;  -- called only if either type or time is to be displayed
;  if m is ['Union, :argl] then
;    x' := retract(objNewWrap(x,m))
;    m' := objMode x'
;    m := ['Union, :[arg for arg in argl | sameUnionBranch(arg, m')], '"..."]
;  if $printTimeIfTrue then
;    timeString := makeLongTimeString($interpreterTimedNames,
;      $interpreterTimedClasses)
;  $printTimeIfTrue and $printTypeIfTrue =>
;    $collectOutput =>
;      $outputLines := [msgText("S2GL0012", [m]), :$outputLines]
;    sayKeyedMsg("S2GL0014",[m,timeString])
;  $printTimeIfTrue =>
;    $collectOutput => nil
;    sayKeyedMsg("S2GL0013",[timeString])
;  $printTypeIfTrue =>
;    $collectOutput =>
;      $outputLines := [justifyMyType msgText("S2GL0012", [m]), :$outputLines]
;    sayKeyedMsg("S2GL0012",[m])

(DEFUN |printTypeAndTimeNormal| (|x| |m|) (PROG (|argl| |x'| |m'| |timeString|) (RETURN (SEQ (PROGN (COND ((AND (PAIRP |m|) (EQ (QCAR |m|) (QUOTE |Union|)) (PROGN (SPADLET |argl| (QCDR |m|)) (QUOTE T))) (SPADLET |x'| (|retract| (|objNewWrap| |x| |m|))) (SPADLET |m'| (|objMode| |x'|)) (SPADLET |m| (CONS (QUOTE |Union|) (APPEND (PROG (#1=#:G18858) (SPADLET #1# NIL) (RETURN (DO ((#2=#:G18859 |argl| (CDR #2#)) (|arg| NIL)) ((OR (ATOM #2#) (PROGN (SETQ |arg| (CAR #2#)) NIL)) (NREVERSE0 #1#)) (SEQ (EXIT (COND ((|sameUnionBranch| |arg| |m'|) (SETQ #1# (CONS |arg| #1#))))))))) (CONS (MAKESTRING "...") NIL)))))) (COND (|$printTimeIfTrue| (SPADLET |timeString| (|makeLongTimeString| |$interpreterTimedNames| |$interpreterTimedClasses|)))) (COND ((AND |$printTimeIfTrue| |$printTypeIfTrue|) (COND (|$collectOutput| (SPADLET |$outputLines| (CONS (|msgText| (QUOTE S2GL0012) (CONS |m| NIL)) |$outputLines|))) ((QUOTE T) (|sayKeyedMsg| (QUOTE S2GL0014) (CONS |m| (CONS |timeString| NIL)))))) (|$printTimeIfTrue| (COND (|$collectOutput| NIL) ((QUOTE T) (|sayKeyedMsg| (QUOTE S2GL0013) (CONS |timeString| NIL))))) (|$printTypeIfTrue| (COND (|$collectOutput| (SPADLET |$outputLines| (CONS (|justifyMyType| (|msgText| (QUOTE S2GL0012) (CONS |m| NIL))) |$outputLines|))) ((QUOTE T) (|sayKeyedMsg| (QUOTE S2GL0012) (CONS |m| NIL))))))))))) 
;
;printTypeAndTimeSaturn(x, m) ==
;  -- header
;  if $printTimeIfTrue then
;    timeString := makeLongTimeString($interpreterTimedNames,
;      $interpreterTimedClasses)
;  else
;    timeString := '""
;  if $printTypeIfTrue then
;    typeString := form2StringAsTeX devaluate m
;  else
;    typeString := '""
;  if $printTypeIfTrue then
;    printAsTeX('"\axPrintType{")
;    if CONSP typeString then
;      MAPC(FUNCTION printAsTeX, typeString)
;    else
;      printAsTeX(typeString)
;    printAsTeX('"}")
;  if $printTimeIfTrue then
;    printAsTeX('"\axPrintTime{")
;    printAsTeX(timeString)
;    printAsTeX('"}")

(DEFUN |printTypeAndTimeSaturn| (|x| |m|) (PROG (|timeString| |typeString|) (RETURN (PROGN (COND (|$printTimeIfTrue| (SPADLET |timeString| (|makeLongTimeString| |$interpreterTimedNames| |$interpreterTimedClasses|))) ((QUOTE T) (SPADLET |timeString| (MAKESTRING "")))) (COND (|$printTypeIfTrue| (SPADLET |typeString| (|form2StringAsTeX| (|devaluate| |m|)))) ((QUOTE T) (SPADLET |typeString| (MAKESTRING "")))) (COND (|$printTypeIfTrue| (|printAsTeX| (MAKESTRING "\\axPrintType{")) (COND ((CONSP |typeString|) (MAPC (FUNCTION |printAsTeX|) |typeString|)) ((QUOTE T) (|printAsTeX| |typeString|))) (|printAsTeX| (MAKESTRING "}")))) (COND (|$printTimeIfTrue| (|printAsTeX| (MAKESTRING "\\axPrintTime{")) (|printAsTeX| |timeString|) (|printAsTeX| (MAKESTRING "}"))) ((QUOTE T) NIL)))))) 
;
;printAsTeX(x) == PRINC(x, $texOutputStream)

(DEFUN |printAsTeX| (|x|) (PRINC |x| |$texOutputStream|)) 
;
;sameUnionBranch(uArg, m) ==
;  uArg is [":", ., t] => t = m
;  uArg = m

(DEFUN |sameUnionBranch| (|uArg| |m|) (PROG (|ISTMP#1| |ISTMP#2| |t|) (RETURN (COND ((AND (PAIRP |uArg|) (EQ (QCAR |uArg|) (QUOTE |:|)) (PROGN (SPADLET |ISTMP#1| (QCDR |uArg|)) (AND (PAIRP |ISTMP#1|) (PROGN (SPADLET |ISTMP#2| (QCDR |ISTMP#1|)) (AND (PAIRP |ISTMP#2|) (EQ (QCDR |ISTMP#2|) NIL) (PROGN (SPADLET |t| (QCAR |ISTMP#2|)) (QUOTE T))))))) (|BOOT-EQUAL| |t| |m|)) ((QUOTE T) (|BOOT-EQUAL| |uArg| |m|)))))) 
;
;msgText(key, args) ==
;  msg := segmentKeyedMsg getKeyedMsg key
;  msg := substituteSegmentedMsg(msg,args)
;  msg := flowSegmentedMsg(msg,$LINELENGTH,$MARGIN)
;  APPLY(function CONCAT, [STRINGIMAGE x for x in CDAR msg])

(DEFUN |msgText| (|key| |args|) (PROG (|msg|) (RETURN (SEQ (PROGN (SPADLET |msg| (|segmentKeyedMsg| (|getKeyedMsg| |key|))) (SPADLET |msg| (|substituteSegmentedMsg| |msg| |args|)) (SPADLET |msg| (|flowSegmentedMsg| |msg| |$LINELENGTH| |$MARGIN|)) (APPLY (|function| CONCAT) (PROG (#1=#:G18860) (SPADLET #1# NIL) (RETURN (DO ((#2=#:G18861 (CDAR |msg|) (CDR #2#)) (|x| NIL)) ((OR (ATOM #2#) (PROGN (SETQ |x| (CAR #2#)) NIL)) (NREVERSE0 #1#)) (SEQ (EXIT (SETQ #1# (CONS (STRINGIMAGE |x|) #1#))))))))))))) 
;
;justifyMyType(t) ==
;  len := #t
;  len > $LINELENGTH => t
;  CONCAT(fillerSpaces($LINELENGTH-len), t)

(DEFUN |justifyMyType| (|t|) (PROG (|len|) (RETURN (PROGN (SPADLET |len| (|#| |t|)) (COND ((|>| |len| |$LINELENGTH|) |t|) ((QUOTE T) (CONCAT (|fillerSpaces| (SPADDIFFERENCE |$LINELENGTH| |len|)) |t|))))))) 
;
;typeTimePrin x ==
;  $highlightDelta: local:= 0
;  maprinSpecial(x,0,79)

(DEFUN |typeTimePrin| (|x|) (PROG (|$highlightDelta|) (DECLARE (SPECIAL |$highlightDelta|)) (RETURN (PROGN (SPADLET |$highlightDelta| 0) (|maprinSpecial| |x| 0 79))))) 
;
;printStorage() ==
;  $collectOutput => nil
;  storeString :=
;    makeLongSpaceString($interpreterTimedNames, $interpreterTimedClasses)
;  sayKeyedMsg("S2GL0016",[storeString])

(DEFUN |printStorage| NIL (PROG (|storeString|) (RETURN (COND (|$collectOutput| NIL) ((QUOTE T) (SPADLET |storeString| (|makeLongSpaceString| |$interpreterTimedNames| |$interpreterTimedClasses|)) (|sayKeyedMsg| (QUOTE S2GL0016) (CONS |storeString| NIL))))))) 
;
;printStatisticsSummary() ==
;  $collectOutput => nil
;  summary := statisticsSummary()
;  sayKeyedMsg("S2GL0017",[summary])

(DEFUN |printStatisticsSummary| NIL (PROG (|summary|) (RETURN (COND (|$collectOutput| NIL) ((QUOTE T) (SPADLET |summary| (|statisticsSummary|)) (|sayKeyedMsg| (QUOTE S2GL0017) (CONS |summary| NIL))))))) 
;
;--%  Interpreter Middle-Level Driver + Utilities
;
;interpretTopLevel(x, posnForm) ==
;  --  Top level entry point from processInteractive1.  Sets up catch
;  --  for a thrown result
;  savedTimerStack := COPY $timedNameStack
;  c := CATCH('interpreter,interpret(x, posnForm))
;  while savedTimerStack ^= $timedNameStack repeat
;    stopTimingProcess peekTimedName()
;  c = 'tryAgain => interpretTopLevel(x, posnForm)
;  c

(DEFUN |interpretTopLevel| (|x| |posnForm|) (PROG (|savedTimerStack| |c|) (RETURN (SEQ (PROGN (SPADLET |savedTimerStack| (COPY |$timedNameStack|)) (SPADLET |c| (CATCH (QUOTE |interpreter|) (|interpret| |x| |posnForm|))) (DO NIL ((NULL (NEQUAL |savedTimerStack| |$timedNameStack|)) NIL) (SEQ (EXIT (|stopTimingProcess| (|peekTimedName|))))) (COND ((|BOOT-EQUAL| |c| (QUOTE |tryAgain|)) (|interpretTopLevel| |x| |posnForm|)) ((QUOTE T) |c|))))))) 
;
;interpret(x, :restargs) ==
;  posnForm := if PAIRP restargs then CAR restargs else restargs
;  --type analyzes and evaluates expression x, returns object
;  $env:local := [[NIL]]
;  $eval:local := true           --generate code-- don't just type analyze
;  $genValue:local := true       --evaluate all generated code
;  interpret1(x,nil,posnForm)

(DEFUN |interpret| (|&REST| #1=#:G18862 |&AUX| |restargs| |x|) (DSETQ (|x| . |restargs|) #1#) (PROG (|$env| |$eval| |$genValue| |posnForm|) (DECLARE (SPECIAL |$env| |$eval| |$genValue|)) (RETURN (PROGN (SPADLET |posnForm| (COND ((PAIRP |restargs|) (CAR |restargs|)) ((QUOTE T) |restargs|))) (SPADLET |$env| (CONS (CONS NIL NIL) NIL)) (SPADLET |$eval| (QUOTE T)) (SPADLET |$genValue| (QUOTE T)) (|interpret1| |x| NIL |posnForm|))))) 
;
;interpret1(x,rootMode,posnForm) ==
;  -- dispatcher for the type analysis routines.  type analyzes and
;  -- evaluates the expression x in the rootMode (if non-nil)
;  -- which may be $EmptyMode.  returns an object if evaluating, and a
;  -- modeset otherwise
;
;  -- create the attributed tree
;
;  node := mkAtreeWithSrcPos(x, posnForm)
;  if rootMode then putTarget(node,rootMode)
;
;  -- do type analysis and evaluation of expression.  The real guts
;
;  modeSet:= bottomUp node
;  not $eval => modeSet
;  newRootMode := (null rootMode => first modeSet ; rootMode)
;  argVal := getArgValue(node, newRootMode)
;  argVal and not $genValue => objNew(argVal, newRootMode)
;  argVal and (val:=getValue node) => interpret2(val,newRootMode,posnForm)
;  keyedSystemError("S2IS0053",[x])

(DEFUN |interpret1| (|x| |rootMode| |posnForm|) (PROG (|node| |modeSet| |newRootMode| |argVal| |val|) (RETURN (PROGN (SPADLET |node| (|mkAtreeWithSrcPos| |x| |posnForm|)) (COND (|rootMode| (|putTarget| |node| |rootMode|))) (SPADLET |modeSet| (|bottomUp| |node|)) (COND ((NULL |$eval|) |modeSet|) ((QUOTE T) (SPADLET |newRootMode| (COND ((NULL |rootMode|) (CAR |modeSet|)) ((QUOTE T) |rootMode|))) (SPADLET |argVal| (|getArgValue| |node| |newRootMode|)) (COND ((AND |argVal| (NULL |$genValue|)) (|objNew| |argVal| |newRootMode|)) ((AND |argVal| (SPADLET |val| (|getValue| |node|))) (|interpret2| |val| |newRootMode| |posnForm|)) ((QUOTE T) (|keyedSystemError| (QUOTE S2IS0053) (CONS |x| NIL)))))))))) 
;
;interpret2(object,m1,posnForm) ==
;  -- this is the late interpretCoerce. I removed the call to
;  -- coerceInteractive, so it only does the JENKS cases    ALBI
;  m1=$ThrowAwayMode => object
;  x := objVal object
;  m := objMode object
;  m=$EmptyMode =>
;    x is [op,:.]  and op in '(MAP STREAM) => objNew(x,m1)
;    m1 = $EmptyMode => objNew(x,m)
;    systemErrorHere '"interpret2"
;  m1 =>
;    if (ans := coerceInteractive(object,m1)) then ans
;    else throwKeyedMsgCannotCoerceWithValue(x,m,m1)
;  object

(DEFUN |interpret2| (|object| |m1| |posnForm|) (PROG (|x| |m| |op| |ans|) (RETURN (COND ((|BOOT-EQUAL| |m1| |$ThrowAwayMode|) |object|) ((QUOTE T) (SPADLET |x| (|objVal| |object|)) (SPADLET |m| (|objMode| |object|)) (COND ((|BOOT-EQUAL| |m| |$EmptyMode|) (COND ((AND (PAIRP |x|) (PROGN (SPADLET |op| (QCAR |x|)) (QUOTE T)) (|member| |op| (QUOTE (MAP STREAM)))) (|objNew| |x| |m1|)) ((|BOOT-EQUAL| |m1| |$EmptyMode|) (|objNew| |x| |m|)) ((QUOTE T) (|systemErrorHere| (MAKESTRING "interpret2"))))) (|m1| (COND ((SPADLET |ans| (|coerceInteractive| |object| |m1|)) |ans|) ((QUOTE T) (|throwKeyedMsgCannotCoerceWithValue| |x| |m| |m1|)))) ((QUOTE T) |object|))))))) 
;;;Boot translation finished for i-toplev.boot
