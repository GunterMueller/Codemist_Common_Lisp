?? Note absolute pathnames present in this Makefile.

# standard directories
TOOLDIR = $(OBJ)/$(SYS)/tools
BINDIR  = $(MNT)/$(SYS)/bin
IMGDIR  = $(SHARE)/images
WIN32DAASE = /users/axiom/development/int/lib/win32

# Extensions
IMG = .img
LIB = .lib

# programs
CCL = $(BINDIR)/ccl

# Abbreviations
I=$(IMGDIR)

# by default:
# NB: SUBPART=axiom.img prevents the building of axiom.lib

PCTARGETS= $(I)/axiom-win32.lib $(I)/axiom-win32.img $(I)/saturn.img
UNIXTARGETS= $(I)/ccl-axiom0$(IMG) $(I)/ccl-axiom$(IMG) $(I)/ccl-lmaxiom$(IMG) $(I)/ccl-axiom$(LIB) $(I)/ccl-axiomaut$(LIB) $(I)/ccl-axiom-unix$(LIB)

all: $(SUBPART)

clean-win32:
	rm -f $(PCTARGETS)

win32bits: $(PCTARGETS)

clean-unix:
	rm -f $(UNIXTARGETS)

# the order is defined by the sequence of cclwhereis*.lsp files
unixbits:
	@ $(MAKE) ccl-makelibs-common.lsp 
	@ $(MAKE) ccl-makelibs-unix.lsp 
	@ $(MAKE) ccl-axiom0$(IMG) 
	@ $(MAKE) ccl-axiom$(LIB)
	@ $(MAKE) ccl-axiom-unix$(LIB) 
	@ $(MAKE) ccl-axiomaut$(LIB) 
	@ $(MAKE) ccl-axiom$(IMG)
	@ $(MAKE) ccl-lmaxiom$(IMG)

slowunixbits:
	@ $(MAKE) ccl-makelibs-common.lsp 
	@ $(MAKE) ccl-makelibs-unix.lsp 
	@ $(MAKE) ccl-axiom0$(IMG) 
	@ $(MAKE) ccl-axiom$(LIB)
	@ $(MAKE) ccl-axiom-unix$(LIB) 
	@ $(MAKE) ccl-axiomaut$(LIB) 
	@ $(MAKE) slow

uniximg: ccl-axiom0$(IMG) ccl-axiom$(IMG) ccl-lmaxiom$(IMG) slow

clean-unixbits:
	$(MAKE) clean-unix
	$(MAKE) unixbits

everything: unixbits win32bits



# These are  the targets to be made in the new way (using int/cclboot)

ccl-axiom0$(IMG):     $(I)/ccl-axiom0$(IMG)
ccl-axiom$(IMG):      $(I)/ccl-axiom$(IMG)
ccl-lmaxiom$(IMG):    $(I)/ccl-lmaxiom$(IMG)
ccl-axiom$(LIB):      $(I)/ccl-axiom$(LIB)
ccl-axiomaut$(LIB):   $(I)/ccl-axiomaut$(LIB)
ccl-axiom-unix$(LIB): $(I)/ccl-axiom-unix$(LIB)

# These are the targets we used to make
# disabled for now

#axiom0$(IMG):         $(I)/axiom0$(IMG)
#axiom$(IMG):          $(I)/axiom$(IMG)
#lmaxiom$(IMG):        $(I)/lmaxiom$(IMG)
#axiom$(LIB):          $(I)/axiom$(LIB)
#axiomaut$(LIB):       $(I)/axiomaut$(LIB)
#axiom-unix$(LIB):     $(I)/axiom-unix$(LIB)


# These are PC targets

saturn$(IMG):         $(I)/saturn$(IMG)
axiom-win32$(IMG):    $(I)/axiom-win32$(IMG)
axiom-win32$(LIB):    $(I)/axiom-win32$(LIB)


# These are other targets

axiom-nou$(IMG):      $(I)/axiom-nou$(IMG)
test$(LIB):    $(I)/test$(LIB)
try: 	      $(I)/try$(IMG)


#
# RULES
#

##########################################################################
##############            The new style rules       ######################
##########################################################################

$(I)/ccl-axiom0$(IMG): ccl-axiom0.lsp $(I)/ccl.img
	@ echo making $(I)/ccl-axiom0$(IMG)
	 ( cd ../cclbase ; $(CCL) -i $(I)/ccl.img makewhere.lsp >/dev/null) 
	 $(CCL) -v -i $(I)/ccl.img \
	            -o /tmp/ccl-axiom0$(IMG) \
	            -l $(I)/ccl-axiom0.log \
	            ccl-axiom0.lsp >/dev/null
	@ mv /tmp/ccl-axiom0$(IMG) $(I)/ccl-axiom0$(IMG)
	            

slow:  $(I)/ccl-axiom0$(IMG) slow-axiom.lsp $(I)/ccl-axiom$(LIB) autoload.lsp
	@ echo making $(I)/ccl-axiomslow$(IMG)
	 env AXIOM=$(AXIOM) $(CCL) -i $(I)/ccl-axiom0$(IMG) \
	                            -i $(I)/ccl-axiom$(LIB) \
	                            -o $(I)/ccl-axiomslow$(IMG) \
	                            -l $(I)/ccl-axiomslow.log \
	                            slow-axiom.lsp > /dev/null

$(I)/ccl-axiom$(IMG):  $(I)/ccl-axiom0$(IMG) ccl-axiom.lsp $(I)/ccl-axiom$(LIB) autoload.lsp
	@ echo making $(I)/ccl-axiom$(IMG)
	 env AXIOM=$(AXIOM) $(CCL) -i $(I)/ccl-axiom0$(IMG) \
	                            -i $(I)/ccl-axiom$(LIB) \
	                            -o /tmp/ccl-axiom$(IMG) \
	                            -l $(I)/ccl-axiom.log \
	                            ccl-axiom.lsp > /dev/null
	@ mv /tmp/ccl-axiom$(IMG) $(I)/ccl-axiom$(IMG)

$(I)/ccl-lmaxiom$(IMG):  $(I)/ccl-axiom0$(IMG) ccl-lmaxiom.lsp $(I)/ccl-axiom$(LIB) autoload.lsp
	@ echo making $(I)/ccl-lmaxiom$(IMG)
	 env AXIOM=$(AXIOM) $(CCL) -i $(I)/ccl-axiom0$(IMG) \
	                            -i $(I)/ccl-axiom$(LIB) \
	                            -o /tmp/ccl-lmaxiom$(IMG) \
                                    -l $(I)/ccl-lmaxiom.log \
	                            ccl-lmaxiom.lsp >/dev/null
	@ mv /tmp/ccl-lmaxiom$(IMG) $(I)/ccl-lmaxiom$(IMG) 

$(I)/ccl-axiom$(LIB): ccl-makelibs-common.lsp
	@ echo making  $(I)/ccl-axiom$(LIB)
	 $(CCL) -v -i $(I)/ccl-axiom0$(IMG) \
	            -o $(I)/ccl-axiom$(LIB) \
	            -l $(I)/ccl-makelibs-common.log \
	            ccl-makelibs-common.lsp >/dev/null

$(I)/ccl-axiom-unix$(LIB): ccl-makelibs-unix.lsp
	@ echo making $(I)/ccl-axiom-unix$(LIB)
	 $(CCL) -v -i $(I)/ccl-axiom0$(IMG) \
	            -o $(I)/ccl-axiom-unix$(LIB) \
	            -l $(I)/ccl-makelibs-unix.log \
	            ccl-makelibs-unix.lsp >/dev/null

$(I)/ccl-axiomaut$(LIB): ccl-makeauto.lsp 
	@ echo making $(I)/ccl-axiomaut$(LIB)
	 $(CCL) -v -i $(I)/ccl-axiom0$(IMG) \
	            -o $(I)/ccl-axiomaut$(LIB) \
	            -l $(I)/ccl-makeauto.log \
	            ccl-makeauto.lsp >/dev/null


ccl-makelibs-common.lsp ccl-makelibs-unix.lsp makelibs-win32.lsp : ccl-makelib
	@ echo creating library building files
	@ sh ccl-makelib

##########################################################################
##############            The old style rules       ######################
##########################################################################

$(I)/axiom0$(IMG): axiom0.lsp $(I)/ccl.img
		$(CCL) -v -i $(I)/ccl.img -o $(I)/axiom0$(IMG) axiom0.lsp -l $(I)/axiom0.log

$(I)/axiom$(IMG):  $(I)/axiom0$(IMG) axiom.lsp $(I)/axiom$(LIB) autoload.lsp
	env AXIOM=$(AXIOM) $(CCL) -i$(I)/axiom0$(IMG) -i$(I)/axiom$(LIB) \
		 -o $(I)/axiom$(IMG) axiom.lsp -l $(I)/axiom.log

$(I)/lmaxiom$(IMG):  $(I)/axiom0$(IMG) lmaxiom.lsp $(I)/axiom$(LIB) autoload.lsp
	env AXIOM=$(AXIOM) $(CCL) -i$(I)/axiom0$(IMG) -i$(I)/axiom$(LIB) \
		 -o $(I)/lmaxiom$(IMG) lmaxiom.lsp -l $(I)/lmaxiom.log

$(I)/axiom$(LIB): makelibs-common.lsp 
		$(CCL) -v -i$(I)/axiom0$(IMG) -o $(I)/axiom$(LIB) makelibs-common.lsp \
		       -l $(I)/makelibs-common.log

$(I)/axiom-unix$(LIB): makelibs-unix.lsp
		$(CCL) -v -i$(I)/axiom0$(IMG) -o $(I)/axiom-unix$(LIB) makelibs-unix.lsp \
		       -l $(I)/makelibs-unix.log

$(I)/axiomaut$(LIB): makeauto.lsp 
		$(CCL) -v -i$(I)/axiom0$(IMG) -o $(I)/axiomaut$(LIB) makeauto.lsp \
		       -l $(I)/makeauto.log

##########################################################################
##############            The PC rules              ######################
##########################################################################

$(I)/saturn$(IMG):  $(I)/ccl-axiom0$(IMG) saturn.lsp $(I)/ccl-axiom$(LIB)  
	@ echo making $(I)/saturn$(IMG)
	@ env DAASE=$(WIN32DAASE) AXIOM=$(AXIOM) \
	 $(CCL) -i $(I)/ccl-axiom0$(IMG) \
	        -i $(I)/ccl-axiom$(LIB) \
	        -o $(I)/saturn$(IMG) \
		-l $(I)/saturn.log \
	        saturn.lsp >/dev/null

$(I)/axiom-win32$(IMG):  $(I)/ccl-axiom0$(IMG) $(I)/ccl-axiom$(LIB) autoload.lsp
	@ echo making $(I)/axiom-win32$(IMG)
	@ env DAASE=$(WIN32DAASE) AXIOM=$(AXIOM) \
	$(CCL) -i $(I)/ccl-axiom0$(IMG) \
	       -i $(I)/ccl-axiom$(LIB) \
	       -o $(I)/axiom-win32$(IMG) \
               -l $(I)/axiom-win32.log \
	       ccl-axiom.lsp >/dev/null

$(I)/axiom-win32$(LIB):  $(I)/ccl-axiom0$(IMG)
	@ echo making $(I)/axiom-win32$(LIB)
	@ $(CCL) -v -i $(I)/ccl-axiom0$(IMG) \
	            -o $(I)/axiom-win32$(LIB) \
	            -l $(I)/makelibs-win32.log \
	            ccl-makelibs-win32.lsp >/dev/null
		    


##########################################################################
##############            The other rules           ######################
##########################################################################


$(I)/axiom-nou$(IMG):  $(I)/ccl-axiom0$(IMG) axiom-nou.lsp $(I)/ccl-axiom$(LIB) autoload.lsp
	env AXIOM=$(AXIOM) $(CCL) -i$(I)/ccl-axiom0$(IMG) -i$(I)/ccl-axiom$(LIB) \
		 -o $(I)/axiom-nou$(IMG) axiom-nou.lsp -l $(I)/axiom-nou.log

$(I)/test$(LIB): test_lib.lsp
		$(CCL) -v -i$(I)/axiom0$(IMG) -o $(I)/test$(LIB) test_lib.lsp \
		       -l $(I)/test_lib.log

$(I)/try:
		$(CCL) -v -i axiom$(IMG) try.lsp -l try.log


##########################################################################
##############            The fast (u*lsp) rules     #####################
##########################################################################

faster: faster.lsp
	@ $(WX) $(CCL) -i$(I)/ccl-axiom0$(IMG) -v faster.lsp -l faster.log >/dev/null

