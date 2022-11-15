## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = atelier

atelier_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	equip.c equip.h \
	fonction.c fonction.h \
	troupeaux.c troupeaux.h \
	nb.c nb.h \
	ouvrier.c ouvrier.h \
	abs.h abs.c \
	tree.h tree.c

atelier_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

