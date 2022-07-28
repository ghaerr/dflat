#-------------------------------------------------------------------
#        D - F L A T   M A K E F I L E  -  GCC
#-------------------------------------------------------------------

AR = ar

PRGS = memopad huffc fixhelp memopad.hlp
LIBS = libdflat.a

all: $(LIBS) $(PRGS)

clean:
	rm -f *.o *.a memopad huffc fixhelp memopad.hlp

#  Delete the TESTING macro to eliminate the Reload
#  Help file selection on the Help menu.
#TESTING = -DTESTING_DFLAT

#  This macro builds the full D-Flat system with all options enabled.
#  Comment it out for a minimum system or selectively
#  comment out the #defines at the top of dflat.h.
FULL = -DBUILD_FULL_DFLAT

#------------------------------------------------
CFLAGS += $(TESTING) $(FULL) -DUNIX=1 -DMACOS=1 -c -g
CFLAGS += -Wno-pointer-sign
CFLAGS += -Wno-compare-distinct-pointer-types
CFLAGS += -Wno-invalid-source-encoding
#------------------------------------------------

OBJS = memopad.o dialogs.o menus.o

memopad: $(OBJS) $(LIBS)
	$(CC) $(LDFLAGS) -o memopad $(OBJS) $(LDFLAGS) -L. -ldflat

CONSOBJS = cons.o runes.o kcp437.o
cons: $(CONSOBJS)
	$(CC) $(LDFLAGS) -o cons $(CONSOBJS) $(LDFLAGS)

TTYOBJS = ttyinfo.o runes.o unikey.o tty.o
ttyinfo: $(TTYOBJS)
	$(CC) $(LDFLAGS) -o ttyinfo $(TTYOBJS) $(LDFLAGS)

TESTOBJS = test.o
test: $(TESTOBJS)
	$(CC) $(LDFLAGS) -o test $(TESTOBJS) $(LDFLAGS)

DFLATOBJS = \
    window.o textbox.o listbox.o                    \
    normal.o config.o menu.o menubar.o popdown.o    \
    rect.o applicat.o keys.o sysmenu.o editbox.o    \
    dialbox.o button.o fileopen.o msgbox.o          \
    helpbox.o log.o lists.o statbar.o decomp.o      \
    combobox.o pictbox.o calendar.o barchart.o      \
    clipbord.o search.o dfalloc.o checkbox.o        \
    text.o radio.o box.o spinbutt.o  watch.o        \
    slidebox.o direct.o editor.o message.o

DFLATOBJS += \
    video.o events-unix.o mouse-ansi.o console-unix.o \
    kcp437.o runes.o unikey.o tty.o

$(LIBS): $(DFLATOBJS)
	$(AR) rcs $(LIBS) $(DFLATOBJS)

HUFFOBJS = huffc.o htree.o
huffc: $(HUFFOBJS)
	$(CC) $(LDFLAGS) -o $@ $(HUFFOBJS)

FIXHOBJS = fixhelp.o decomp.o
fixhelp: $(FIXHOBJS)
	$(CC) $(LDFLAGS) -o $@ $(FIXHOBJS)

memopad.hlp: memopad.txt huffc fixhelp
	./huffc memopad.txt memopad.hlp
	./fixhelp memopad