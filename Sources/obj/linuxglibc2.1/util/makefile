?? This Makefile contains loads of abolute paths that need review.
?? Also note that this is somewhat out of date (not that that matters
?? very much). See http://gauguin.trin.cam.ac.uk/util for the current
?? state.


###########################################################################
#                                                                         #
# makefile for Codemist Utilities                                         #
#                                                                         #
###########################################################################




###########################################################################

# Generic Unix with GCC. Note that if you use this you should review
# the file "machine.h" to ensure that CSL knows what name to report for
# your system. Also if the system you are running on needs

CC        = gcc
CFLAGS    = -c -O2 -ansi
LIBS      = -lm -lc

###########################################################################




###########################################################################

SHELL     = /bin/sh
LINK      = $(CC)
LFLAGS    =
OUT       = -o
OUTOBJ    = -o
RM        = rm
MKDIR     = mkdir
COPY      = cp
STRIP     = strip

###########################################################################




CBIN    = /home/red5/axiom/ccl/obj/linuxglib2/tools
BIN     = /home/red5/axiom/ccl/obj/linuxglib2/tools

ALL     = car excar filesign \
	makemake checksum \
	xport

all:	$(ALL)

install:	$(BIN)/car $(BIN)/excar \
		$(BIN)/filesign \
		$(BIN)/makemake $(BIN)/checksum \
		$(BIN)/xport


#
# CAR: the Codemist ARchiver
#     Usage:    car archivefile [-a] [-b] [-<size>] files
#               -a for test file, -b for binary
#

car.o:	car.c sys.h
	$(CC) $(CFLAGS) car.c

scandir.o:	scandir.c sys.h
	$(CC) $(CFLAGS) scandir.c

fileops.o:	fileops.c sys.h
	$(CC) $(CFLAGS) fileops.c

car:	car.o scandir.o fileops.o patmatch.o
	$(LINK) $(LFLAGS) $(OUT) car car.o scandir.o \
		fileops.o patmatch.o $(LIBS1)
	$(STRIP) car

$(BIN)/car:      car
	$(COPY) car      $(BIN)/car

#
# EXCAR: extraction program to accompany CAR
#
#     Usage:    excar -flags  archivefile
#               -t test archive
#               compare files in archive against current disc contents
#

excar.o:	car.c sys.h
	$(CC) $(CFLAGS) $(OUTOBJ) excar.o -DEXTRACT=1 car.c

sfileops.o:	fileops.c sys.h
	$(CC) $(CFLAGS) $(OUTOBJ) sfileops.o fileops.c

excar:	excar.o sfileops.o
	$(LINK) $(LFLAGS) $(OUT) excar excar.o sfileops.o $(LIBS)
	$(STRIP) excar

$(BIN)/excar:    excar
	$(COPY) excar    $(BIN)/excar

#
# FILESIGN: add checksum and datestamp to file
#     Usage:   filesign <files>       just check files
#              filesign -u one-file   update existing stamp in that file
#              filesign -u from to    update or add time stamp
#

filesign.o:	filesign.c sys.h
	$(CC) $(CFLAGS) filesign.c

filesign:	filesign.o scandir.o fileops.o
	$(LINK) $(LFLAGS) $(OUT) filesign filesign.o \
		scandir.o $(LIBS1)
	$(STRIP) filesign

$(BIN)/filesign: filesign
	$(COPY) filesign $(BIN)/filesign


#
# MAKEMAKE: allow a single generic makefile to serve for many systems
#     Usage:   makemake [-f <basefile>] [-o <destination>] target
#
# basefile defaults to makebase, destination to makenew
# see comments in source file for format in the base file.
#

makemake.o:	makemake.c
	$(CC) $(CFLAGS) makemake.c

makemake:	makemake.o
	$(LINK) $(LFLAGS) $(OUT) makemake makemake.o $(LIBS)
	$(STRIP) makemake

$(BIN)/makemake: makemake
	$(COPY) makemake $(BIN)/makemake

#
# CHECKSUM: computes a file checksum and displays it
#     Usage:   checksum [-b] file
#     if -b is specified the file is read in binary mode.
#

checksum.o:	checksum.c
	$(CC) $(CFLAGS) checksum.c

checksum:	checksum.o
	$(LINK) $(LFLAGS) $(OUT) checksum checksum.o $(LIBS)
	$(STRIP) checksum

$(BIN)/checksum: checksum
	$(COPY) checksum $(BIN)/checksum

#
# XPORT: help export and import directories
#     Usage:   xport -sign
#              xport -check
#

xport.o:	xport.c sys.h
	$(CC) $(CFLAGS) xport.c

patmatch.o:	patmatch.c patmatch.h sys.h
	$(CC) $(CFLAGS) patmatch.c

xport:	xport.o scandir.o fileops.o patmatch.o
	$(LINK) $(LFLAGS) $(OUT) xport xport.o scandir.o \
		fileops.o patmatch.o $(LIBS1)
	$(STRIP) xport

$(BIN)/xport: xport
	$(COPY) xport $(BIN)/xport


# end of makefile
