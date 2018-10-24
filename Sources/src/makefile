?? ACN: As of September 2002 this and the Makefiles in lower parts
?? of this tree contain absolute paths and reliance on libraries
?? etc built elsewhere. So this is INDICATIVE for now.

# src directory makefile

# This is generally called from the parent directory.
# Typically it is called with 'make PART=<foo>dir'. 

# Targets:

# util.   Builds bootstrapping tools for ccl
# ccl.    Builds a new ccl.exe into $(MNT)/bin
# cclimg. Builds a new ccl.img into $(INT)/images
# interp. Builds new .clisp files
# image.  Builds new image files for the interpreter

ENV=    SYS=${SYS} LSP=${LSP} PART=${PART} SRC=${SRC} INT=${INT} OBJ=${OBJ} \
        MNT=${MNT} PLF="${PLF}" CCF="${CCF}" LDF="${LDF}" \
        INC=${INC} O=${O} SHARE=${SHARE} SUBPART=${SUBPART} \
        FLEXINC="${FLEXINC}" FLEXLIB="${FLEXLIB}"               \
        CCFLEX="${CCFLEX}" AXIOM=${AXIOM}

alldir: utildir caxbase axbasedir

utildir:
	@ echo making ccl tools, subpart: $(SUBPART)
	@ (cd util; $(MAKE))

caxbasedir:
	@ echo making ccl executables
	(cd caxbase; env ${ENV} $(MAKE))

axbasedir:
	@ echo entering axbase directory
	 (cd axbase; env ${ENV} $(MAKE))

scriptsdir:
	@ echo making axiom script
	@ (cd scripts; $(MAKE))

dirsdir:
	@echo making directories
	-mkdir ../obj/$(SYS)
	-mkdir ../obj/$(SYS)/tools
	-mkdir ../obj/$(SYS)/util
	-mkdir ../obj/$(SYS)/cclbase
	-mkdir ../mnt/$(SYS)
	-mkdir ../mnt/$(SYS)/bin

cleandir:
	@echo killing directories
	rm -rf ../obj/$(SYS)/tools
	rm -rf ../obj/$(SYS)/util
	rm -rf ../mnt/$(SYS)/bin
	rm -rf ../mnt/$(SYS)/cclbase

# end of Makefile

