?? Comment from ACN, Sept 2002
?? This Makefile has a load of absolute pathnames in it which need
?? adapting. It also requires things like ${HOME}/development/... to
?? contain libspad.a which is clearly built using some different
?? Makefile.


###########################################################################
#                                                                         #
# makefile for CCL (Codemist Common Lisp)                                 #
#                                                                         #
###########################################################################
###########################################################################

# Generic Unix with GCC. Note that if you use this you should review
# the file "machine.h" to ensure that CSL knows what name to report for
# your system. Also if the system you are running on needs

CC        = gcc
OPTFLAGS  = -O3
#OPTFLAGS  = -g
CFLAGS    = -c $(OPTFLAGS) -I$(CSLBASE) -DCOMMON=1 -DNAG=1 -I/usr/include/ncurses 
LIBS      = -L${HOME}/development/obj/linuxglibc2.1/lib -lspad -lncurses -lcrypt -lm -lc

###########################################################################




###########################################################################

SHELL     = /bin/sh
LINK      = $(CC)
LFLAGS    =
OUT       = -o
ASM       = $(CC)
ASMFLAGS  = $(CFLAGS)
ASMSRC    =
ASMOBJ    =
ASMOBJDEP = notused.obj
SYS       = sysunix
#STRIP     = strip
STRIP     = echo

###########################################################################




#
# Codemist Common Lisp
#

#
# I need TWO versions of the directory names here - one for direct use
# with MSDOS, and the other for use via Lisp where "\" may be treated as
# an escape character even if I do not want that to happen!
#



UCAXBASE   = /home/mcd/OpenAxiom/ccl/src/caxbase
CAXBASE    = /home/mcd/OpenAxiom/ccl/src/caxbase

UCSLBASE   = /home/mcd/OpenAxiom/ccl/src/cslbase
CSLBASE    = /home/mcd/OpenAxiom/ccl/src/cslbase

UCCLBASE   = /home/mcd/OpenAxiom/ccl/src/cclbase
CCLBASE    = /home/mcd/OpenAxiom/ccl/src/cclbase

UCUBASE    = /home/mcd/OpenAxiom/ccl/src/axbase
CUCUBASE   = /home/mcd/OpenAxiom/ccl/src/axbase


AXDLL = axiomole.dll
AXLIB = axiomole.lib

###########################################################################
###########################################################################
#                                                                         #
# This is the main bulk of the "makefile" for building CCL                #
# on MSDOS, Windows and Unix.  This part of the file expects a number of  #
# symbols to have been defined:                                           #
#                                                                         #
# CSLBASE   = file-path for CSLBASE directory                             #
# CC        = The C compiler to use                                       #
# CFLAGS    = Flags for C compiler when compiling CSL                     #
# LINK      = Linker to use                                               #
# LFLAGS    = Flags for linker                                            #
# LIBS      = Libraries to quote to linker                                #
# OUT       = "-o" or "-out:"   See link commands                         #
# ASM       = The assembler to use                                        #
# ASMFLAGS  = Flags for the assembler                                     #
# ASMSRC    = Assembly code source file to use                            #
# ASMOBJ    = Object file for above (or NULL if no assembly used)         #
# ASMOBJDEP = Ditto, but may not be NULL                                  #
# SYS       = name of system-cpecific file (sysdos or sysnt)              #
# STRIP     = echo for DOS, = strip for Unix                              #
# WX        = start /w for Windows 95, null in all other cases            #
#                                                                         #
# The master version of this file is called "makebase" and is used to     #
# create both DOS and Unix makefiles.  Use the Codemist "makemake"        #
# program to perform the conversion - eg                                  #
#     makemake -f makebase -o makemake.386 dos watcom                     #
#     makemake -f makebase -o Makefile.sgi unix sgi                       #
# Just "makemake -f makebase" gives list of systems supported             #
###########################################################################
###########################################################################


C         = $(CSLBASE)
D         = $(CCLBASE)
A         = $(CUCUBASE)
X         = $(CAXBASE)

U         = $(UCSLBASE)
V         = $(UCCLBASE)
W         = $(UAXBASE)
Y         = $(UCAXBASE)

SYSDIR = $(C)

OBJS =	 	csl.o fasl.o fns1.o fns2.o fns3.o arith01.o arith02.o \
		arith03.o arith04.o arith05.o arith06.o arith07.o \
		arith08.o arith09.o arith10.o arith11.o arith12.o \
		eval3.o eval1.o eval2.o restart.o gc.o print.o read.o \
		openmath.o ompsetup.o cslmpi.o \
		char.o bytes1.o eval4.o $(SYS).o preserve.o \
		u01.o u02.o u03.o u04.o u05.o u06.o \
		u07.o u08.o u09.o u10.o u11.o u12.o \
                nag.o asps.o sockets.o xdrfuns.o grep.o grep2.o axfns.o grccl.o\
		$(ASMOBJ)


COBJS = 	csl.o,fasl.o,fns1.o,fns2.o,fns3.o,arith01.o,arith02.o,\
		arith03.o,arith04.o,arith05.o,arith06.o,arith07.o,\
		arith08.o,arith09.o,arith10.o,arith11.o,arith12.o,\
		eval3.o,eval1.o,eval2.o,restart.o,gc.o,print.o,read.o,\
		openmath.o, ompsetup.o, cslmpi.o, \
		char.o,bytes1.o,eval4.o,$(SYS).o,preserve.o,\
		u01.o,u02.o,u03.o,u04.o,u05.o,u06.o,\
		u07.o,u08.o,u09.o,u10.o,u11.o,u12.o,\
		nag.o,asps.o,sockets.o,xdrfuns.o,grep.o,grep2.o,axfns.o,grccl.o,\
		$(ASMOBJ)

ccl:	$(OBJS) $(CCLRES)
	$(LINK) $(LFLAGS) $(OBJS) $(CCLRES) $(LIBS) $(OUT) ccl $(TAIL)
	$(STRIP) ccl

ccl.img:	./ccl
		./ccl -z -v $(D)/build.lsp -D@CCLBASE=\"$(V)\" -l build.log



axiomole.lib: $(AXDLL)
	del axiomole.lib
	wlib axiomole +$(axdll)


axiom.img:
		./ccl -v -i- -o axiom.img axiom.lsp -l axiom.log

try:
		./ccl -v -i axiom.img try.lsp -l try.log

#
#

#
# Now rules for re-compiling the main collection of CCL source files. I
# write each case out individually since that makes the makefile less
# delicate than one that relies on setting up general rules - and I want this
# file to work on several different systems.
#

$(ASMOBJDEP):	$(C)/$(ASMSRC)
	$(ASM) $(ASMFLAGS) -o $(ASMOBJ) $(C)/$(ASMSRC)

arith01.o:	$(C)/arith01.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o arith01.o \
		$(C)/arith01.c

arith02.o:	$(C)/arith02.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o arith02.o \
		$(C)/arith02.c

arith03.o:	$(C)/arith03.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o arith03.o \
		$(C)/arith03.c

arith04.o:	$(C)/arith04.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o arith04.o \
		$(C)/arith04.c

arith05.o:	$(C)/arith05.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o arith05.o \
		$(C)/arith05.c

arith06.o:	$(C)/arith06.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o arith06.o \
		$(C)/arith06.c

arith07.o:	$(C)/arith07.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o arith07.o \
		$(C)/arith07.c

arith08.o:	$(C)/arith08.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o arith08.o \
		$(C)/arith08.c

arith09.o:	$(C)/arith09.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o arith09.o \
		$(C)/arith09.c

arith10.o:	$(C)/arith10.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o arith10.o \
		$(C)/arith10.c

arith11.o:	$(C)/arith11.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o arith11.o \
		$(C)/arith11.c

arith12.o:	$(C)/arith12.c $(C)/arith.h $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o arith12.o \
		$(C)/arith12.c

bytes.o:	$(C)/bytes1.c $(C)/bytes.c $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h \
		$(C)/bytes.h $(C)/arith.h
	$(CC) $(CFLAGS) \
		-o bytes.o \
		$(C)/bytes.c

bytes1.o:	$(C)/bytes1.c $(C)/bytes.c $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h \
		$(C)/bytes.h $(C)/arith.h
	$(CC) $(CFLAGS) \
		-o bytes1.o \
		$(C)/bytes1.c

#
# The target "bytes1a.o" recompiles bytes1.c, but with the flag set that
# arranges that the number of GET operations performed and the associated
# indicators will be recorded, so that (bytecounts) will display statistics
# about it. This slows things down considerably, but can help when you are in
# the process of deciding which indicators are specified as "fast" ones.
#

bytes1a.o:	$(C)/bytes1.c $(C)/bytes.c $(C)/tags.h $(C)/machine.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h \
		$(C)/bytes.h $(C)/arith.h
	$(CC) $(CFLAGS) -DRECORD_GET=1 \
		-o bytes1.o \
		$(C)/bytes1.c

char.o:	$(C)/char.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o char.o \
		$(C)/char.c

csl.o:	$(C)/csl.c $(C)/tags.h $(C)/machine.h $(C)/externs.h $(C)/version.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o csl.o \
		$(C)/csl.c

cslmpi.o: $(C)/cslmpi.c $(C)/tags.h $(C)/machine.h $(C)/stream.h \
          $(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/read.h $(C)/version.h
	$(CC) $(CFLAGS) \
                -o cslmpi.o \
                $(C)/cslmpi.c

eval1.o:	$(C)/eval1.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/arith.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o eval1.o \
		$(C)/eval1.c

eval2.o:	$(C)/eval2.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/arith.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o eval2.o \
		$(C)/eval2.c

eval3.o:	$(C)/eval3.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o eval3.o \
		$(C)/eval3.c

eval4.o:	$(C)/eval4.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/arith.h
	$(CC) $(CFLAGS) \
		-o eval4.o \
		$(C)/eval4.c

fasl.o:	$(C)/fasl.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/arith.h
	$(CC) $(CFLAGS) \
		-o fasl.o \
		$(C)/fasl.c

fns1.o:	$(C)/fns1.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o fns1.o \
		$(C)/fns1.c

fns2.o:	$(C)/fns2.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/read.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o fns2.o \
		$(C)/fns2.c

fns3.o:	$(C)/fns3.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/read.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o fns3.o \
		$(C)/fns3.c

gc.o:	$(C)/gc.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o gc.o \
		$(C)/gc.c

openmath.o:	$(C)/openmath.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o openmath.o \
		$(C)/openmath.c

ompsetup.o:	$(C)/ompsetup.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o ompsetup.o \
		$(C)/ompsetup.c

$(C)/omparser.tab.c : $(C)/omparser.y
		(cd $(C) ; bison -o omparser.tab.c omparser.y )

omparser.tab.o:	$(C)/omparser.tab.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o omparser.tab.o \
		$(C)/omparser.tab.c

#
# For each major target I have one file that is system specific - eg
# sysdos.c, sysunix.c, ...
#

$(SYS).o:	$(SYSDIR)/$(SYS).c $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/fileops.c $(C)/scandir.c $(C)/version.h
	$(CC) $(CFLAGS) \
		-o $(SYS).o \
		$(SYSDIR)/$(SYS).c

preserve.o:	$(C)/preserve.c $(C)/tags.h $(C)/machine.h $(C)/stream.h \
		$(C)/externs.h $(C)/sys.h $(C)/cslerror.h $(C)/read.h $(C)/version.h
	$(CC) $(CFLAGS) \
		-o preserve.o \
		$(C)/preserve.c

print.o:	$(C)/print.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/read.h \
		$(C)/arith.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o print.o \
		$(C)/print.c

read.o:	$(C)/read.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/read.h \
		$(C)/arith.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o read.o \
		$(C)/read.c

restart.o:	$(C)/restart.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/sys.h $(C)/cslerror.h $(C)/read.h $(C)/version.h \
		$(C)/arith.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o restart.o \
		$(C)/restart.c

stubs.o:	$(C)/stubs.c $(C)/machine.h $(C)/externs.h $(C)/sys.h \
		$(C)/tags.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o stubs.o \
		$(C)/stubs.c

sockets.o:	$(C)/sockets.c $(C)/machine.h $(C)/externs.h $(C)/arith.h \
		$(C)/tags.h $(C)/cslerror.h
	$(CC) $(CFLAGS) \
		-o sockets.o \
		$(C)/sockets.c

xdrfuns.o:	$(C)/xdrfuns.c $(C)/machine.h $(C)/externs.h $(C)/arith.h \
		$(C)/tags.h $(C)/cslerror.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o xdrfuns.o \
		$(C)/xdrfuns.c

nag.o:		$(C)/nag.c $(C)/machine.h $(C)/externs.h $(C)/arith.h \
		$(C)/tags.h $(C)/cslerror.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o nag.o \
		$(C)/nag.c

asps.o:		$(C)/asps.c $(C)/machine.h $(C)/externs.h $(C)/arith.h \
		$(C)/tags.h $(C)/cslerror.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o asps.o \
		$(C)/asps.c

grep2.o:	$(C)/grep2.c $(C)/machine.h $(C)/externs.h $(C)/arith.h \
		$(C)/tags.h $(C)/cslerror.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o grep2.o \
		$(C)/grep2.c

grep.o:		$(C)/grep.c $(C)/machine.h $(C)/externs.h $(C)/arith.h \
		$(C)/tags.h $(C)/cslerror.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o grep.o \
		$(C)/grep.c

axfns.o:	$(X)/axfns.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h $(X)/axfns.h
	$(CC) $(CFLAGS) \
		-o axfns.o \
		$(X)/axfns.c

glnag.o:	$(X)/glnag.c
	$(CC) $(CFLAGS) \
		-o glnag.o \
		$(X)/glnag.c

grccl.o:	$(X)/grccl.c $(C)/machine.h $(C)/externs.h $(C)/arith.h \
		$(C)/tags.h $(C)/cslerror.h $(C)/entries.h $(C)/stream.h
	$(CC) $(CFLAGS) \
		-o grccl.o \
		$(X)/grccl.c

axiom.o:	$(X)/axiom.c $(X)/axiom.h $(C)/cslerror.h $(C)/entries.h $(C)/stream.h
	$(CPP) $(CPPFLAGS) \
		-o axiom.o \
		$(X)/axiom.c

buf.o:	$(X)/buf.c $(X)/buf.h
	$(CC) $(CFLAGS) \
		-o buf.o \
		$(X)/buf.c

grif.o:	$(X)/grif.c $(X)/grif.h
	$(CC) $(CFLAGS) \
		-o grif.o \
		$(X)/grif.c

###########################################################################
#

u01.o:	$(A)/u01.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u01.o \
		$(A)/u01.c

u02.o:	$(A)/u02.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u02.o \
		$(A)/u02.c

u03.o:	$(A)/u03.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u03.o \
		$(A)/u03.c

u04.o:	$(A)/u04.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u04.o \
		$(A)/u04.c

u05.o:	$(A)/u05.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u05.o \
		$(A)/u05.c

u06.o:	$(A)/u06.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u06.o \
		$(A)/u06.c

u07.o:	$(A)/u07.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u07.o \
		$(A)/u07.c

u08.o:	$(A)/u08.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u08.o \
		$(A)/u08.c

u09.o:	$(A)/u09.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u09.o \
		$(A)/u09.c

u10.o:	$(A)/u10.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u10.o \
		$(A)/u10.c

u11.o:	$(A)/u11.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u11.o \
		$(A)/u11.c

u12.o:	$(A)/u12.c $(C)/tags.h $(C)/machine.h $(C)/externs.h \
		$(C)/cslerror.h $(C)/entries.h
	$(CC) $(CFLAGS) \
		-o u12.o \
		$(A)/u12.c


# end of makefile
