# Bootstrap of ccl utility commands

# in order to make life easy, we build all platform's makefile from
# a single make

# 
SHELL = /bin/sh

# All known systems. Remember to update names.sh
SYSTEMS = axposf1v3 axposf1v4 hp9 hp10 rs6000aix3 rs6000aix4 linux linuxglib2  sun sun4os55c sun4os55g irixmips3 irixmips1

TOOLDIR = $(OBJ)/$(SYS)/util
ALLOBJS = $(OBJ)

all: ${SUBPART}

everything: makefiles tools
	
makefiles: $(TOOLDIR)/makemake
	for i in $(SYSTEMS) ;do  \
		name=`sh ./names.sh $$i`;	\
		rm -f /tmp/respfile;		\
	 	echo "$(ALLOBJS)/$$i/tools" >> /tmp/respfile; \
		echo "$(SRC)/util"         >> /tmp/respfile; \
		$(TOOLDIR)/makemake $$name -o $(ALLOBJS)/$$i/util/Makefile < \
			/tmp/respfile;			    \
	done

$(TOOLDIR)/makemake: $(SRC)/util/makemake.c
	$(CC) $(SRC)/util/makemake.c -o $(TOOLDIR)/makemake

tools: $(TOOLDIR)/Makefile
	echo "Building tools..."
	( if test ! -d $(TOOLDIR) ; then mkdir $(TOOLDIR) ; fi ; )
	( cd $(SRC)/util ; $(MAKE) -f $(TOOLDIR)/Makefile install)

# end of Makefile

