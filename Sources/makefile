# Top-level makefile for ccl-based axiom
#need DAASE
#DAASE=${HOME}/development/mnt/sun

# We build into the following directories:
# int: intermediate, system independent files
# obj/$(SYS): intermediate, system dependent files
# obj/$(SYS)/toolbin: Programs for internal consumption
# mnt/$(SYS)/bin: Binaries
# mnt/$(SYS)/bin:   Programs run by the end-user
# mnt/$(SYS)/lib:   Library files
# mnt/$(SYS)/exec:  Programs run as subprograms

# When running make below this point, it is useful
# to have PATH "$CCLAXIOM/bin:$AXIOM/../`basename $CCLAXIOM`:$PATH"

#HOME=/home/mcd/OpenAxiom
#CCLAXIOM=${HOME}/ccl/mnt/linuxglibc2.1
#AXIOM=${CCLAXIOM}

SYS=	`basename ${CCLAXIOM}`
SPD=	${HOME}/ccl
SRC=	${SPD}/src
INT=	${SPD}/int
OBJ=	${SPD}/obj
MNT=	${SPD}/mnt
INC=	${SPD}/src/include
SHARE=  ${SPD}/share

TOOLS=  ${OBJ}/${SYS}/toolbin

PART=	caxbase

SUBPART=everything

ENV=	SYS=${SYS} PART=${PART} SRC=${SRC} INT=${INT} OBJ=${OBJ} \
	MNT=${MNT} INC=${INC} SPD=${SPD} TESTSYS=${TESTSYS}      \
	SUBPART=${SUBPART} FLEXDIR=${FLEXDIR} AXIOM=${AXIOM} \
	SHARE=${SHARE} HOME=${HOME} CCLAXIOM=${CCLAXIOM}

all:
	(cd ${SPD}/src ; env ${ENV} $(MAKE) ${PART}dir )

