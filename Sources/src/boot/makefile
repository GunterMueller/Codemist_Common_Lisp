.SUFFIXES: .o .lisp .clisp .boot
 
############################################################################
# notes for understanding this makefile:
 
# there is a directory called IN that contains the boot, clisp and lisp
# code. This code gets copied into the intermediate directory ${INT}/boot
# so that the compiler has a writeable directory to change. This intermediate
# code is then compiled into the ${OUT} directory (which is in the object
# directory for the type of machine code we are constructing (rt, ps2, rios))
# then, when all of the .o files are produced we construct a lisp image that
# contains the boot translator, called bootsys, which lives in the mnt/sys/bin
# directory. this bootsys image is critical for the rest of the makefiles to
# succeed.
 
# there are two halves of this file. the first half compiles the .lisp files
# that live in the src/boot directory. the second half compiles the .clisp
# files (which are generated from the .boot files). It is important that
# the .clisp files are kept in the src/boot directory for the boot translator
# as they cannot be recreated without a boot translator (a bootstrap problem).
 
# an important subtlety is that files in the boot translator depend on the
# file npextras. there are 3 macros in npextras that must be in the lisp
# workspace (|shoeOpenInputFile| |shoeOpenOutputFile| memq). 
############################################################################
 
# src/boot
 
# this is where we are compiling from
IN=     ${SRC}/boot
 
# this is the intermediate place (for system-independent sources)
MID=    ${INT}/boot
 
# this is where we place the binaries
OUT=    ${OBJ}/${SYS}/boot
 
# this is the lisp image we will use to compile the files
LISPSYS= ${OBJ}/${SYS}/bin/lisp
 
# this is the image that we need to run to translate .boot to .clisp
BOOTSYS= ${OBJ}/${SYS}/bin/bootsys
 
# this is the image that we need to load the final files into
LOADSYS= ${OBJ}/${SYS}/bin/lisp
 
# this is the name of the image we will save
SAVESYS= ${OBJ}/${SYS}/bin/bootsys
 
 
# this is a list of all of the files that must be loaded to construct the
# boot translator image. note that the order is important.
OBJS1=	"${OUT}/boothdr.${O}" "${OUT}/exports.${O}" \
	"${OUT}/npextras.${O}" "${OUT}/ptyout.${O}" \
	"${OUT}/btincl2.${O}" "${OUT}/btscan2.${O}" \
	"${OUT}/typrops.${O}" "${OUT}/btpile2.${O}" \
	"${OUT}/typars.${O}" "${OUT}/tyextra.${O}" \
	"${OUT}/tytree1.${O}"
OBJS=	${OUT}/boothdr.${O} ${OUT}/exports.${O} \
	${OUT}/npextras.${O} ${OUT}/ptyout.${O} \
	${OUT}/btincl2.${O} ${OUT}/btscan2.${O} \
	${OUT}/typrops.${O} ${OUT}/btpile2.${O} \
	${OUT}/typars.${O} ${OUT}/tyextra.${O} \
	${OUT}/tytree1.${O}
 
# this is a lisp form that will load the files that contain macros used
# in other files. it should not contain the ' symbol.
DEPS=   (load (string-downcase (quote ${IN}/npextras.lisp)))
 
# this is a lisp form that will load the final object files and save the
# system into the BOOTSYS location. it should not contain the ' symbol.
CMD0=	(progn (mapcar (function (lambda (x) (load  x))) (quote (${OBJS1}))) (system::save-system "${SAVESYS}"))
 
 
# this stanza will create the final bootsys image
 
${SAVESYS}:	${OBJS} ${LOADSYS}
	@ echo invoking make in `pwd` with parms:
	@ echo SYS= ${SYS} 
	@ echo LSP= ${LSP} 
	@ echo PART= ${PART} 
	@ echo SPAD= ${SPAD} 
	@ echo SRC= ${SRC} 
	@ echo INT= ${INT}
	@ echo OBJ= ${OBJ} 
	@ echo MNT= ${MNT}
	 (cd ${OBJ}/${SYS}/bin ; echo '${CMD0}' | ${LOADSYS} >/tmp/console )
	@ echo ${SAVESYS} created
 
############################################################################
# the next three stanza come in pairs
#   
#   print a message
#   change to the /tmp directory (so gazonk is writeable)
#   compile the .lisp from the intermediate place to the object place
#
#   print a message
#   copy the .lisp from source to the intermediate place
############################################################################
 
${OUT}/boothdr.${O}: ${MID}/boothdr.lisp
	@ echo making ${OUT}/boothdr.${O} from ${MID}/boothdr.lisp
	@ ( cd /tmp ; \
	   echo '(progn  (compile-file "${MID}/boothdr.lisp" :output-file "${OUT}/boothdr.${O}") (${BYE}))' | ${LISPSYS}  )
 
${MID}/boothdr.lisp:	${IN}/boothdr.lisp
	@ echo making ${MID}/boothdr.lisp from ${IN}/boothdr.lisp
	@ cp ${IN}/boothdr.lisp ${MID}/boothdr.lisp

${OUT}/exports.${O}: ${MID}/exports.lisp
	@ echo making ${OUT}/exports.${O} from ${MID}/exports.lisp
	@ ( cd /tmp ; \
	   echo '(progn  (compile-file "${MID}/exports.lisp" :output-file "${OUT}/exports.${O}") (${BYE}))' | ${LISPSYS}  )
 
${MID}/exports.lisp:	${IN}/exports.lisp
	@ echo making ${MID}/exports.lisp from ${IN}/exports.lisp
	@ cp ${IN}/exports.lisp ${MID}/exports.lisp
 
${OUT}/npextras.${O}: ${MID}/npextras.lisp
	@ echo making ${OUT}/npextras.${O} from ${MID}/npextras.lisp
	@ ( cd /tmp ; \
	   echo '(progn  (compile-file "${MID}/npextras.lisp" :output-file "${OUT}/npextras.${O}") (${BYE}))' | ${LISPSYS}  )
 
${MID}/npextras.lisp:	${IN}/npextras.lisp
	@ echo making ${MID}/npextras.lisp from ${IN}/npextras.lisp
	@ cp ${IN}/npextras.lisp ${MID}/npextras.lisp
 
############################################################################
# the rest of the stanzas come in pairs, one for the .clisp -> .o and one
# for the .boot -> .clisp files.
#
# the .clisp -> .o stanzas are of the form:
#   print a message
#   compile the .clisp from the intermediate place to the object place
#
# the .boot -> .clisp stanzas are of the form:
#   print a message
#   copy the .boot to the intermediate place
#   translate the .boot to the .clisp
#   erase the .boot
#   copy the .clisp back to the src/boot directory
############################################################################
 
${OUT}/ptyout.${O}: ${MID}/ptyout.clisp 
	@ echo making ptyout.${O} from ${MID}/ptyout.clisp
	@ (cd ${MID} ; \
	   echo '(progn ${DEPS} (compile-file "ptyout.clisp" :output-file "${OUT}/ptyout.${O}") (${BYE}))' | ${LISPSYS}  )
 
${MID}/ptyout.clisp: ${IN}/ptyout.boot
	@ echo making ptyout.clisp from ${IN}/ptyout.boot
	@ (cp ${IN}/ptyout.boot ${MID} ; \
	   cd ${MID} ; \
	   echo '(progn (boottran::boottocl "ptyout.boot") (${BYE}))' | ${BOOTSYS}  ; \
	   rm ${MID}/ptyout.boot ; \
	   cp ${MID}/ptyout.clisp ${IN}/ptyout.clisp  )
 
${OUT}/btincl2.${O}: ${MID}/btincl2.clisp  
	@ echo making btincl2.${O} from ${MID}/btincl2.clisp
	@ (cd ${MID} ; \
	   echo '(progn ${DEPS} (compile-file "btincl2.clisp" :output-file "${OUT}/btincl2.${O}") (${BYE}))' | ${LISPSYS}  )
 
${MID}/btincl2.clisp: ${IN}/btincl2.boot
	@ echo making btincl2.clisp from ${IN}/btincl2.boot
	@ (cp ${IN}/btincl2.boot ${MID} ; \
	   cd ${MID} ; \
	   echo '(progn (boottran::boottocl "btincl2.boot") (${BYE}))' | ${BOOTSYS}  ; \
	   rm ${MID}/btincl2.boot ; \
	   cp ${MID}/btincl2.clisp ${IN}/btincl2.clisp  )
 
${OUT}/btscan2.${O}: ${MID}/btscan2.clisp  
	@ echo making btscan2.${O} from ${MID}/btscan2.clisp
	@ (cd ${MID} ; \
	   echo '(progn ${DEPS} (compile-file "btscan2.clisp" :output-file "${OUT}/btscan2.${O}") (${BYE}))' | ${LISPSYS}  )
 
${MID}/btscan2.clisp: ${IN}/btscan2.boot
	@ echo making btscan2.clisp from ${IN}/btscan2.boot
	@ (cp ${IN}/btscan2.boot ${MID} ; \
	   cd ${MID} ; \
	   echo '(progn (boottran::boottocl "btscan2.boot") (${BYE}))' | ${BOOTSYS}  ; \
	   rm ${MID}/btscan2.boot ; \
	   cp ${MID}/btscan2.clisp ${IN}/btscan2.clisp  )
 
${OUT}/typrops.${O}: ${MID}/typrops.clisp 
	@ echo making typrops.${O} from ${MID}/typrops.clisp
	@ (cd ${MID} ; \
	   echo '(progn ${DEPS} (compile-file "typrops.clisp" :output-file "${OUT}/typrops.${O}") (${BYE}))' | ${LISPSYS}  )
 
${MID}/typrops.clisp: ${IN}/typrops.boot
	@ echo making typrops.clisp from ${IN}/typrops.boot
	@ (cp ${IN}/typrops.boot ${MID} ; \
	   cd ${MID} ; \
	   echo '(progn (boottran::boottocl "typrops.boot") (${BYE}))' | ${BOOTSYS}  ; \
	   rm ${MID}/typrops.boot ; \
	   cp ${MID}/typrops.clisp ${IN}/typrops.clisp  )
 
${OUT}/btpile2.${O}: ${MID}/btpile2.clisp  
	@ echo making btpile2.${O} from ${MID}/btpile2.clisp
	@ (cd ${MID} ; \
	   echo '(progn ${DEPS} (compile-file "btpile2.clisp" :output-file "${OUT}/btpile2.${O}") (${BYE}))' | ${LISPSYS}  )
 
${MID}/btpile2.clisp: ${IN}/btpile2.boot
	@ echo making btpile2.clisp from ${IN}/btpile2.boot
	@ (cp ${IN}/btpile2.boot ${MID} ; \
	   cd ${MID} ; \
	   echo '(progn (boottran::boottocl "btpile2.boot") (${BYE}))' | ${BOOTSYS}  ; \
	   rm ${MID}/btpile2.boot ; \
	   cp ${MID}/btpile2.clisp ${IN}/btpile2.clisp  )
 
${OUT}/typars.${O}: ${MID}/typars.clisp 
	@ echo making typars.${O} from ${MID}/typars.clisp
	@ (cd ${MID} ; \
	   echo '(progn ${DEPS} (compile-file "typars.clisp" :output-file "${OUT}/typars.${O}") (${BYE}))' | ${LISPSYS}   )
 
${MID}/typars.clisp: ${IN}/typars.boot
	@ echo making typars.clisp from ${IN}/typars.boot
	@ (cp ${IN}/typars.boot ${MID} ; \
	   cd ${MID} ; \
	   echo '(progn (boottran::boottocl "typars.boot") (${BYE}))' | ${BOOTSYS}  ; \
	   rm ${MID}/typars.boot ; \
	   cp ${MID}/typars.clisp ${IN}/typars.clisp  )
 
${OUT}/tyextra.${O}: ${MID}/tyextra.clisp 
	@ echo making tyextra.${O} from ${MID}/tyextra.clisp
	@ (cd ${MID} ; \
	   echo '(progn ${DEPS} (compile-file "tyextra.clisp" :output-file "${OUT}/tyextra.${O}") (${BYE}))' | ${LISPSYS}  )
 
${MID}/tyextra.clisp: ${IN}/tyextra.boot
	@ echo making tyextra.clisp from ${IN}/tyextra.boot
	@ (cp ${IN}/tyextra.boot ${MID} ; \
	   cd ${MID} ; \
	   echo '(progn (boottran::boottocl "tyextra.boot") (${BYE}))' | ${BOOTSYS}  ; \
	   rm ${MID}/tyextra.boot ; \
	   cp ${MID}/tyextra.clisp ${IN}/tyextra.clisp  )
 
${OUT}/tytree1.${O}: ${MID}/tytree1.clisp 
	@ echo making tytree1.${O} from ${MID}/tytree1.clisp
	@ (cd ${MID} ; \
	   echo '(progn ${DEPS} (compile-file "tytree1.clisp" :output-file "${OUT}/tytree1.${O}") (${BYE}))' | ${LISPSYS}  )
 
${MID}/tytree1.clisp: ${IN}/tytree1.boot
	@ echo making tytree1.clisp from ${IN}/tytree1.boot
	@ (cp ${IN}/tytree1.boot ${MID} ; \
	   cd ${MID} ; \
	   echo '(progn (boottran::boottocl "tytree1.boot") (${BYE}))' | ${BOOTSYS}  ; \
	   rm ${MID}/tytree1.boot ; \
	   cp ${MID}/tytree1.clisp ${IN}/tytree1.clisp  )
 
 
 
 
 
 
 
 
 
 
 
