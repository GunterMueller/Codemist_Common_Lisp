# Build file for ccl executable
.PREFIXES:

# standard directories
BINDIR  = $(MNT)/$(SYS)/bin
IMGDIR  = $(INT)/images

# programs
CCL	 = $(BINDIR)/ccl

# build by default

all: $(SUBPART)

everything: $(BINDIR)/cclaxiom

# real targets
$(BINDIR)/cclaxiom: cclaxiom
	cp cclaxiom $(BINDIR)/cclaxiom
	chmod 755 $(BINDIR)/cclaxiom
