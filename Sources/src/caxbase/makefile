# Build file for ccl executable, and ccl.img
# 
# Default is to build executable
# SUBPART=ccl.img will promote new image into share/images
#
# standard directories
TOOLDIR = $(OBJ)/$(SYS)/tools
BINDIR  = $(MNT)/$(SYS)/bin
INTDIR  = $(OBJ)/$(SYS)/cclbase
IMGDIR  = $(SHARE)/images

CAXDIR = $(SRC)/caxbase
CSLDIR = $(SRC)/cslbase
CCLDIR = $(SRC)/cclbase
CUCDIR = $(SRC)/axbase

A = $(CAXDIR)
S = $(CSLDIR)
C = $(CCLDIR)

SRCA = $(A)/axfns.c         $(A)/buf.c          $(A)/grif.c 	\
	 $(A)/axiom.c         $(A)/grccl.c        $(A)/sysaxlnk.c 

SRCS = $(S)/arith.h         $(S)/doc.h           $(S)/read.c	 \
	$(S)/arith01.c       $(S)/dosinst.c       $(S)/read.h \
	$(S)/arith02.c       $(S)/entries.h       $(S)/restart.c \
	$(S)/arith03.c       $(S)/eval1.c         $(S)/scandir.c \
	$(S)/arith04.c       $(S)/eval2.c         \
	$(S)/arith05.c       $(S)/eval3.c         $(S)/showmem.c \
	$(S)/arith06.c       $(S)/eval4.c         $(S)/sockets.c \
	$(S)/arith07.c       $(S)/externs.h       $(S)/stream.h \
	$(S)/arith08.c       $(S)/fasl.c          $(S)/stubs.c \
	$(S)/arith09.c       $(S)/fileops.c       $(S)/sys.h \
	$(S)/arith10.c       $(S)/fns1.c          $(S)/sysarm.c \
	$(S)/arith11.c       $(S)/fns2.c          $(S)/syscwin.c \
	$(S)/arith12.c       $(S)/fns3.c          $(S)/sysdos.c \
	$(S)/asps.c          $(S)/gc.c            $(S)/sysmac.c \
	$(S)/bytes.c         $(S)/grep.c \
	$(S)/bytes.h         $(S)/grep2.c         $(S)/sysstmac.c \
	$(S)/bytes1.c        $(S)/install.c       $(S)/sysunix.c \
	$(S)/char.c          $(S)/machine.h       $(S)/sysvms.c \
	$(S)/clsyms.h        $(S)/makemake.c      $(S)/sysxwin.c \
	$(S)/csl.c           $(S)/nag.c           $(S)/tags.h \
	$(S)/cslerror.h      $(S)/opnames.c       $(S)/version.h \
	$(S)/cwin.h          $(S)/preserve.c      $(S)/xdrfuns.c \
	$(S)/cwinres.h       $(S)/print.c \
	$(S)/demo.c          $(S)/procl.c 

ALLSRC= $(SRCA) $(SRCS)

# programs
MAKEMAKE = $(TOOLDIR)/makemake -f $(CAXDIR)/makebase
CCL	 = $(BINDIR)/ccl

all: $(SUBPART)

makefile: $(INTDIR)/Makefile 

# build by default
everything: $(BINDIR)/ccl $(IMGDIR)/ccl.img

# generic targets
tst.img:  $(INTDIR)/ccl.img

slow: # $(INTDIR)/Makefile $(ALLSRC)
	@ (cd ${INTDIR} ; ${MAKE} slow )
	cp $(INTDIR)/ccl $(BINDIR)/ccl

ccl: # $(INTDIR)/Makefile $(ALLSRC)
	@ (cd ${INTDIR} ; ${MAKE} ccl )
	cp $(INTDIR)/ccl $(BINDIR)/ccl

$(INTDIR)/ccl.img: $(INTDIR)/ccl
	@ (cd ${INTDIR} ; ${MAKE} ccl.img )

ccl.img: $(INTDIR)/ccl.img
	cp $(INTDIR)/ccl.img $(IMGDIR)/ccl.img

$(IMGDIR)/ccl.img: $(BINDIR)/ccl
	@ echo Making ccl.img
	@ (cd ${INTDIR} ; ${MAKE} ccl.img )
	cp $(INTDIR)/ccl.img $(IMGDIR)/ccl.img

$(BINDIR)/ccl: $(INTDIR)/ccl
	cp $(INTDIR)/ccl $(BINDIR)/ccl

#ufiles=
ufiles=ufiles
$(INTDIR)/Makefile: makebase
	@ echo Making makefile
	rm -f /tmp/respfile
	echo $(CAXDIR) 	>> /tmp/respfile
	echo $(CSLDIR)	>> /tmp/respfile
	echo $(CCLDIR)	>> /tmp/respfile
	echo $(CUCDIR)	>> /tmp/respfile
	-mv -f $(INTDIR)/Makefile $(INTDIR)/Makefile.old
	$(MAKEMAKE) `sh ../util/names.sh $(SYS)` nag $(ufiles) \
		-o $(INTDIR)/Makefile < /tmp/respfile

$(INTDIR)/ccl: $(ALLSRC)
	@ echo "Making ccl (int)"
	@ (cd ${INTDIR} ; ${MAKE} ccl.img )	
	@ echo done
