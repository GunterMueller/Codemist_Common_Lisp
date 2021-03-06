/*  sysstmac.c                       Copyright (C) 1989-2002 Codemist Ltd */

/*
 * Macintosh system-specific stuff
 */

/* This is a better sysstmac.c.  I still need to deal with the help
 * system, but the dialogs are greatly improved in this version.
 */


/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */


/* Signature: 0aa59571 08-Apr-2002 */

#include "machine.h"

#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#include "tags.h"
#include "externs.h"

#include <unix.h>
#include <files.h>
#include <unix.h>
#include <retrace.h>
#include <timer.h>
#include <ansi_private.h>
#include "macwin.h"
#include <Dialogs.h>

#undef nil          /* #define'd by Think C headers but not wanted (by me) */

int get_home_directory(char *b, int length);
int get_users_home_directory(char *b, int length);

#include "filename.c"


/*
 * This is a dummy definition of get_truename, here so that everything
 * will link. Both the calling convention used here and the exact
 * meaning and implementation may be under gentle review!
 */

char *get_truename(char *filename, char *old, size_t n)
{
    char *w;
    process_file_name(filename, old, n);
    if (*filename == 0)
    {   aerror("truename");
        return NULL;
    }
    w = (char *)(*malloc_hook)(1+strlen(filename));
    if (w == NULL) return w;
    strcpy(w, filename);
    return w;
}

CSLbool file_exists(char *filename, char *old, size_t n, char *tt)
{
        FileParam pb;
        char buf[FILENAME_MAX];

        process_file_name(filename, old, n);
        pb.ioNamePtr = __c2p((const char*)filename, buf);
        pb.ioFRefNum = 0;
        pb.ioFVersNum = 0;
        pb.ioFDirIndex = 0;
        if (PBGetFInfo((ParmBlkPtr)&pb, 0) != noErr) return NO;
        strcpy(tt, ctime(&(pb.ioFlMdDat)));
        return YES;
}

char *my_getenv(char *s)
{
    return getenv(s);
}

int
myexec(char *filename, ...)
{
        int                                i;
        short                        ans;
        EventRecord                event;
#if 1 /* __powerc */
        FSSpec fsp;
        LaunchParamBlockRec lpb;

        C2PStr(filename);
        ans = FSMakeFSSpec( 0,0,(unsigned char*)filename,&fsp);
        P2CStr((unsigned char*)filename);
        if (!ans) {
                lpb.launchBlockID = extendedBlock;
                lpb.launchEPBLength = extendedBlockLen;
                lpb.launchFileFlags = 0;
                lpb.launchControlFlags = launchContinue + launchNoFileFlags;
                lpb.launchAppSpec = &fsp;
                lpb.launchAppParameters = 0;
                ans = LaunchApplication(&lpb);
        }
#else
        static struct {
                unsigned char *name;
            short                         memuse;
            char                    lc[2];
            long                         extBlocLen;
            short                        fFlags;
            long                         launchFlags;
        } buf;
        unsigned char pname[255];
        extern void _Launch();

        buf.name = __c2p(filename, (char *)pname);
        buf.memuse = 0;
        buf.lc[0] = 'L';  buf.lc[1] = 'C';
        buf.extBlocLen = 6;
        buf.fFlags = 128;        /* RO */
        buf.launchFlags = 0xC0000000;
        asm {
                lea                buf,a0
                dc.w        _Launch
                move.w        d0,ans;
        }
#endif
        if (ans==0)
          for (i=0; i<20; i++) WaitNextEvent(everyEvent, &event, 10, 0L);
        return ans;
}

int my_system(char *s)
{
    return myexec(s);
}

void my_pclose(FILE *a)
{
    return;
}

int create_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename==0) return 1;
/* /* */
    return 1;        /* Unfinished */
}

int delete_file(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename==0) return 1;
    return remove(filename);
}

int get_home_directory(char *b, int length)
{
    char *w = my_getenv("home");
    if (w != NULL) strcpy(b, w);
    else
    strcpy(b, ":");     /* Not satisfactory */
    return strlen(b);
}

static int get_users_home_directory(char *b, int length)
{
    char *w, h[LONGEST_LEGAL_FILENAME];
    sprintf(h, "home$%s", b);
    w = my_getenv(h);
    if (w != NULL) strcpy(b, w);
    else
    strcpy(b, ":");     /* Not satisfactory */
    return strlen(b);
}

int batchp(void)
{
    return !isatty(fileno(stdin));
}

/*static char CurApName[64];*/

/*
 * The next procedure is responsible for establishing information about
 * where the main checkpoint image should be recovered from, and where
 * and fasl files should come from.
 */
char *find_image_directory(int argc, char *argv[])
{
    char image[LONGEST_LEGAL_FILENAME];
    char pgmname[LONGEST_LEGAL_FILENAME];
    char *w;
/*
 * For the Macintosh I use the data fork of the application image as
 * a place to store useful stuff.
 */
    WDPBRec pb1;
    CInfoPBRec pb2;
    int i, j, r, p = LONGEST_LEGAL_FILENAME;
    long id;
    pgmname[--p] = 0;

    sprintf(image, "%#s", LMGetCurApName()); /* name of current application */
    strcpy(program_name, image);
    i = strlen(image);
    strcpy(image+i, " Image");
    i += 6;
    p -= i;
    memcpy(&pgmname[p], image, i);          /* copy to the end of a buffer */
    pb1.ioNamePtr = (unsigned char *)image;
    PBHGetVolSync(&pb1);        /* find current working dir/volume */
    id = pb1.ioWDDirID;         /* working directory identifier */
    while (id != 0) {
        pb2.dirInfo.ioFDirIndex = -1; /* use dir ID, not file name/index    */
        pb2.dirInfo.ioVRefNum = pb1.ioVRefNum;  /* look in this volume      */
        pb2.dirInfo.ioDrDirID = id; /* get info about this directory        */
        pb2.dirInfo.ioNamePtr = (unsigned char *)image;
        r = PBGetCatInfoSync(&pb2); /* Read catalogue - find name & parent  */
        if (r != 0) break;          /* failed - must be at top of tree      */
        id = pb2.dirInfo.ioDrParID; /* go on up to parent directory         */
        i = image[0] & 0xff;        /* length of name of this directory     */
        pgmname[--p] = ':';
        p -= i;
        if (p < 10) {
          fprintf(stderr, "\nPlease re-install this package nearer the top of\n");
          fprintf(stderr, "your directory hierarchy.  It will not work this far down\n");
          abort();
        }
        memcpy(&pgmname[p], &image[1], i);  /* stick names together with ':'s */
    }
    strcpy(image, &pgmname[p]); /* Put complete name in convenient place */

/*
 * I copy from local vectors into malloc'd space to hand my
 * answer back.
 */
    w = (char *)(*malloc_hook)(1+strlen(&pgmname[p]));
/*
 * The error exit here seem unsatisfactory...
 */
    if (w == NULL)
    {   fprintf(stderr, "\n+++ Panic - run out of space\n");
        exit(EXIT_FAILURE);
    }
    strcpy(w, &pgmname[p]);
    return w;
}

int truncate_file(FILE *f, long int where)
{
        short a;
        short ff = f->refnum;
    if (fflush(f) != 0) return 1;
    a = SetEOF(ff, where);  /* Returns zero if successs */
    return (int)a;
}

static CSLbool ticker_active = NO;
int32 software_ticks = INITIAL_SOFTWARE_TICKS;
int32 software_tick_count = 0, prev_software_tick_count = 0;

void add_ticker(void)
{
    if (ticker_active) return;
    if (countdown<0) countdown = SOFTWARE_TICKS; /* Reset if expired */
    ticker_active = YES;
}

void remove_ticker(void)
{
  /*    if (!ticker_active) return; */
    ticker_active = NO;
}

int file_readable(char *filename, char *old, size_t n)
{
    FILE *fp;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    /* The "correct" way to do this is via stat, but this is much simpler! */
    fp = fopen(filename,"r");
    if (fp == NULL) return 0;
    else
    {   fclose(fp);
        return 1;
    }
}

int file_writeable(char *filename, char *old, size_t n)
{
    FILE *fp;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    fp = fopen(filename,"a");
    if (fp == NULL) return 0;
    else
    {   fclose(fp);
        return 1;
    }
}

int rename_file(char *from_name, char *from_old, size_t from_size,
                char *to_name, char *to_old, size_t to_size)
{
    process_file_name(from_name, from_old, from_size);
    process_file_name(to_name, to_old, to_size);
    if (*from_name == 0 || *to_name == 0) return 0;
    return rename(from_name,to_name);
}

int change_directory(char *filename, char *old, size_t n)
{
        WDPBRec P;
        Str255 pname;
        process_file_name(filename, old, n);
        if (*filename==0) return 1;
        strcpy((char*)pname, filename);
        C2PStr((char*)pname);
        P.ioNamePtr = pname;
        return PBHSetVol(&P, 0);
}

int directoryp(char *filename, char *old, size_t n)
{
        struct stat statrec;
        process_file_name(filename, old, n);
        stat(filename, &statrec);
        return S_ISDIR(statrec.st_mode);
}

int get_current_directory(char *s, int n)
{
        return 0;
}

#include "scandir.c"

void list_directory_members(char *filename, char *old,
                            size_t n, directory_callback *fn)
{
    process_file_name(filename, old, n);
    scan_files(filename, fn);
}

/* ************************************************************ */
/* ********** StdWin Interface ******************************** */
/* ************************************************************ */
/* ************************************************************ */

#include "stdwin.h"
#include "tools.h"
#include "editwin.h"
#include "text.h"               /* Rather a cheat as I need to look
                                 * low down in here */

static WINDOW *CSL_window;
static EDITWIN *CSL_ew;
static EDITWIN *help_ew;
int max_nlines = 250;

#ifndef HELP_DATA
#define HELP_DATA "help.data"
#endif
#ifndef HELP_INDEX
#define HELP_INDEX "help.index"
#endif

static MENU *adminmenu;
static MENU *editmenu;
static MENU *loadmenu;
static MENU *libmenu;
static MENU *switchmenu;
static MENU *helpmenu;
/* static MENU *fontmenu; */
/* static MENU *sizemenu; */

#define ADMIN_MENU (1001)
#define MMFile    0
#define MMSaveas  1
#define MMHelp    2 /* main window menu items */
#define MMHelpSel 3
#define MMHelpAsk 4
#define MMInt     5
#define MMAbort   6
#define MMPause   7
#define MMDummy   8
#define MMTime    9
#define MMSpace   10
#define MMOTime   11

#define EDIT_MENU (1002)
#define MMCut     0
#define MMCopy    1
#define MMPaste   2
#define MMClear   3
#define MMSelAll  4

#define HELP_LEN (36)
#define HELP_MENU (1003)
static struct hlp {
  char name[HELP_LEN];
  long offset;
  int  length;
} *hlp;
int help_length;
int helpstamp;

#define LOAD_MENU (1004)

static char *loads[] = {
  (char*)NULL};


#define LIB_MENU (1005)

static char *libraries[] = {
  (char*)NULL};

#define SWITCH_MENU (1006)
static struct sw {
  char *name;
  int state;
} switches[] = {
  {(char*)NULL, 0}};

/* #define FONT_MENU (1007) */
/* static char *fonts[] = { "Monaco", "Courier", NULL}; */
/* static current_font = 0; */

/* #define SIZE_MENU (1008) */
/* static char *sizes[] = { "8", "9", "10", "11", "12", NULL}; */
/* static current_size = 1; */

 get_full_name(char *name, FSSpec *spec)
{
  char nn[LONGEST_LEGAL_FILENAME];
  char mm[LONGEST_LEGAL_FILENAME];
  char *w;
  int i, r;
  int p = LONGEST_LEGAL_FILENAME;
  long id;
  CInfoPBRec pb2;

  nn[--p] = 0;
  i = spec->name[0];
  p -= i;
  memcpy(&nn[p], &(spec->name[1]), i); /* Copy base name */
  id = spec->parID;
  while (id != 0) {
    pb2.dirInfo.ioFDirIndex = -1; /* use dirID, not file name/index */
    pb2.dirInfo.ioVRefNum = spec->vRefNum;  /* look in this volume  */
    pb2.dirInfo.ioDrDirID = id;             /* get info about this directory */
    pb2.dirInfo.ioNamePtr = (unsigned char *)mm;
    if (PBGetCatInfoSync(&pb2)) break; /* Read catalogue - find name & parent*/
                                /* Fail at top of tree? */
    id = pb2.dirInfo.ioDrParID; /* go on up to parent directory          */
    i = mm[0] & 0xff;           /* length of name of this directory      */
    nn[--p] = ':';
    p -= i;
    if (p < 10) {
      fprintf(stderr, "\nCannot access file so far from root\n");
      strcpy(name, "");
      return FALSE;
    }
    memcpy(&nn[p], &mm[1], i);  /* stick names together with ':'s        */
  }
  strcpy(name, &nn[p]);
  return TRUE;
}

static void menusetup(void)
{
    MENU *mp;
    int i;

    adminmenu= mp= wmenucreate(ADMIN_MENU, "Admin");

    wmenuadditem(mp, "Input file...", 'F');
    wmenuadditem(mp, "Saveas...", -1);
    wmenuadditem(mp, "Help Window", 'H');
    wmenuadditem(mp, "Help Selection", 'S');
    wmenuadditem(mp, "Help Topic...", -1);
    wmenuadditem(mp, "Interrupt", 'I');
    wmenuadditem(mp, "Quit", 'Q');
    wmenuadditem(mp, "Pause", 'P');
    wmenuadditem(mp, "---------", -1);
    wmenuadditem(mp, "0.00", -1);
    wmenuadditem(mp, "[GC 0]", -1);
    wmenuadditem(mp, "", -1);
    wmenuadditem(mp, "", -1);

    wmenuenable(mp, MMDummy, NO);
    wmenuenable(mp, MMTime, NO);
    wmenuenable(mp, MMSpace, NO);
    wmenuenable(mp, MMOTime, NO);

    editmenu= mp= wmenucreate(EDIT_MENU, "Edit");
    wmenuadditem(mp, "Cut", 'X');
    wmenuadditem(mp, "Copy", 'C');
    wmenuadditem(mp, "Paste", 'V');
    wmenuadditem(mp, "Clear", 'B');
    wmenuadditem(mp, "Select All", 'A');

/*         fontmenu= mp= wmenucreate(FONT_MENU, "Font"); */
/*         for (i=0; fonts[i]!= NULL; i++) wmenuadditem(mp, fonts[i], -1); */
/*         wmenucheck(mp, current_font, YES); */

/*         sizemenu= mp= wmenucreate(SIZE_MENU, "FontSize"); */
/*         for (i=0; sizes[i]!= NULL; i++) wmenuadditem(mp, sizes[i], -1); */
/*         wmenucheck(mp, current_size, YES); */

/*    helpmenu= mp= wmenucreate(HELP_MENU, "Help"); */
    helpmenu = mp = (MENU*)GetMenu(HELP_MENU);
    if (mp != 0)        /* This checks against problems */
    InsertMenu((MenuHandle)mp, 0); DrawMenuBar();
    {
      FILE* hlpindx = fopen(HELP_INDEX, "r");
      if (hlpindx != NULL) {
        fscanf(hlpindx, "%d\n", &helpstamp);
        fscanf(hlpindx, "%d", &help_length);
        hlp = (struct hlp*) (*malloc_hook)(1+help_length, sizeof(struct hlp));
        if (hlp == NULL) {
          help_length = 0;
          goto loader;          /* Insufficient memory */
        }
        for (i=0; i<help_length; i++) {
          int ch, p=0;
          fscanf(hlpindx, "%d %d ", &(hlp[i].offset), &(hlp[i].length));
          while (p<HELP_LEN-1) {
            ch = getc(hlpindx);
            if (ch == '\n') break;
            hlp[i].name[p++] = ch; /* Was toupper here */
          }
          while (ch != '\n') ch = getc(hlpindx);
          hlp[i].name[p] = '\0';
          /*wmenuadditem(mp, hlp[i].name, -1);*/
        }
        fclose(hlpindx);
      }
      else {
        help_length = 0;
        strcpy(hlp[0].name, "No help");
        hlp[0].offset = -1;
        hlp[0].length = 0;
      }
    }

loader:
    loadmenu= mp= wmenucreate(LOAD_MENU, "Load");
    for (i=0; loads[i]!= NULL; i++)
      wmenuadditem(mp, loads[i], -1);

    libmenu= mp= wmenucreate(LIB_MENU, "Library");
    for (i=0; libraries[i]!= NULL; i++)
      wmenuadditem(mp, libraries[i], -1);

    switchmenu= mp= wmenucreate(SWITCH_MENU, "Switch");
    for (i=0; switches[i].name!= NULL; i++) {
      wmenuadditem(mp, switches[i].name, -1);
      wmenucheck(mp, i, switches[i].state);
    }
}

static void fixmenus(void)
{
    CSLbool focus;

    focus= (CSL_ew->tp->foclen != 0);
    wmenuenable(editmenu, MMCut, focus);
    wmenuenable(editmenu, MMCopy, focus);
    wmenuenable(editmenu, MMClear, focus);
    wmenuenable(adminmenu, MMHelpSel, focus);
/*  wmenuenable(editmenu, MMPaste, YES); */

    if (help_ew != NULL) {
      focus= (help_ew->tp->foclen != 0);
      if (focus) {
        wmenuenable(editmenu, MMCut, focus);
        wmenuenable(editmenu, MMCopy, focus);
        wmenuenable(editmenu, MMClear, focus);
        wmenuenable(adminmenu, MMHelpSel, focus);
      }
    }
}

#define TTYBUF_SIZE 256
static char tty_buff[TTYBUF_SIZE];
static int tty_index = 0;
static CSLbool tty_ready = NO;
static int tty_nnl = 0;
static int tty_offset;

#define STDOUT_BUFSIZE 1024
#define LONGEST_PRINTF 120

static char stdout_buffer[STDOUT_BUFSIZE];
static char *stdout_p;
static int stdout_n;
extern int _w_font;

void start_up_window_manager(int use_wimp)
{
    int CSL_width, CSL_height;
    _w_font = 4;  /* Font family */
    menusetup();
    wsetdefwinsize(82*wcharwidth('0'), 25*wlineheight());
    CSL_ew = ewcreate(NULL);
    CSL_window = CSL_ew->win;
    wsettitle(CSL_window, "Reduce 3.7");
    fixmenus();
/*  wmenudetach(CSL_window, helpmenu); */
    wmenuenable(editmenu, MMTime, NO); /* These are not selectable */
    wmenuenable(editmenu, MMOTime, NO); /* These are not selectable */
    wmenuenable(editmenu, MMSpace, NO);
    wmenudetach(CSL_window, loadmenu); /* These are only valid when reading */
    wmenudetach(CSL_window, libmenu);
    wmenudetach(CSL_window, switchmenu);
/*  wmessage("Welcome to X-Reduce\n\n"); */
    stdout_n = 0;
    stdout_p = stdout_buffer;
    help_ew = NULL;
}

static char *help_buff;
CSLbool
helpwindow(int index)
{
    FILE* help = fopen(HELP_DATA, "r");
    int ch;
    int width, height;
    int size = hlp[index].length;

    if (help == NULL) return FALSE;
    fscanf(help, "%d\n", &ch);
    if (ch != helpstamp) return FALSE;        /* not  same generation */
/*  fprintf(stderr, "Help on index %d offset=%d size=%d\n",
          index, hlp[index].offset, hlp[index].length); */
    fseek(help, hlp[index].offset, SEEK_SET);
    if (help_ew) {
      (*free_hook)(help_buff);
      tesetfocus(help_ew->tp, 0, tegetlen(help_ew->tp));
      ewreplace(help_ew, "");
    }
    else {
      help_ew = ewcreate(NULL);
      wsettitle(help_ew->win, "Help for Reduce 3.7");
    }
    help_buff = (*malloc_hook)(size+1);
    if (help_buff == NULL) {
      dprintf("Insufficient memory");
      wfleep();
      return FALSE;
    }
/*  fprintf(stderr, "reading %d bytes to buffer\n", size); */
    fread(help_buff, size, 1, help);
/*  fprintf(stderr, "help starts as %.100s\n", help_buff); */
    help_buff[size] = '\0';
    wmenudetach(help_ew->win, loadmenu);
    wmenudetach(help_ew->win, libmenu);
    wmenudetach(help_ew->win, switchmenu);
/*  wmenudetach(help_ew->win, adminmenu); */
    ewreplace(help_ew, help_buff);
    tesetfocus(help_ew->tp, 0, 0);
    fclose(help);
    return TRUE;
}

void help_buffer(char *buf, int len)
{
    int i;
    for (i=0; i<help_length; i++) {
      /* fprintf(stderr, "Check against %s\n", hlp[i].name); */
      if (strncmp(hlp[i].name, buf, len) == 0) {
        helpwindow(i);
        break;
      }
    }
    if (i == help_length) wfleep();
}

void help_selection(EDITWIN *ew)
{
    int i;
    char *text;
    TEXTEDIT *tp = ew->tp;
    if (tp->foclen == 0) {
      wfleep();
      return;
    }
    text= tegettext(tp);
    help_buffer(text+tp->foc, tp->foclen);
}

extern int pause_set = 0;
void event_loop(void)
{
    for (;;) {                    /* Loop while there are events */
      EVENT e;
      EDITWIN *ew;
      CSLbool closed;

      wgetevent(&e);
    /*    fprintf(stderr, "Event: type=%d win=%p data=%d\n", e.type, e.window, e.u.command);  */
      ew= ewfind(e.window);
      if (ew == CSL_ew) {
        switch (e.type) {
        case WE_CHAR:
          switch(e.u.character) {
          case 'A'-'@':         /* ^A == beginning of line */
            {
              TEXTEDIT* tp = CSL_ew->tp;
              tesetfocus(tp,
                         zsubgap(tp->start[tewhichline(tp,
                                                       zaddgap(tp->foc),
                                                       tp->focprev)]),
                         -1);
              break;
            }
          case 'B'-'@':         /* ^B back a character */
            tearrow(CSL_ew->tp, WC_LEFT);
            break;
          case 127:             /* Delete character */
          case 'D'-'@':         /* ^D delete at cursor */
            {
              TEXTEDIT* tp = CSL_ew->tp;
              tearrow(tp, WC_RIGHT);
              {
                int f1 = tp->foc;
                int i;
                int ss = tp->start[tp->nlines-tty_nnl];
                int ee = ss + tty_offset;
                if (ss <= f1 && f1 < ee) {
                  if (tty_offset>0) tty_offset--;
                }
                e.type = WE_COMMAND;
                e.u.command = WC_BACKSPACE;
                ewevent(ew,&e, NULL);
                break;
              }
            }
          case 'E'-'@':         /* ^E end of line */
            {
              TEXTEDIT* tp = CSL_ew->tp;
              int line = tewhichline(tp, zaddgap(tp->foc), tp->focprev);
              int xxx = zsubgap(tetextround(tp, line, tp->right));
              tesetfocus(tp, xxx, -1);
              break;
            }
          case 'F'-'@':         /* ^F forward a character */
            tearrow(CSL_ew->tp, WC_RIGHT);
            break;
          case 'K'-'@':         /* ^K kill to end of line */
            {                   /* This does not take notice of offset */
              TEXTEDIT* tp = CSL_ew->tp;
              int f1;
              int i;
              int ss;
              int ee;
              tesetfocus(tp,
                         tp->foc,
                         zsubgap(tetextround(tp,
                                             tewhichline(tp, zaddgap(tp->foc),
                                                             tp->focprev),
                                             tp->right)));
              f1 = tp->foc;
              ss = tp->start[tp->nlines-tty_nnl];
              ee = ss + tty_offset;
              for (i=0; i<tp->foclen; i++)
                if (ss <= f1+i && f1+i < ee) {
                  if (tty_offset>0) tty_offset--;
                }
              ewreplace(ew, "");
              break;
            }
          case 'N'-'@':         /* ^N next line */
            tearrow(CSL_ew->tp, WC_DOWN);
            break;
          case 'P'-'@':         /* ^P previous line */
            tearrow(CSL_ew->tp, WC_UP);
            break;
          case 'Z'-'@':         /* ^Z move to end of buffer */
            {
              TEXTEDIT* tp = CSL_ew->tp;
              tesetfocus(tp, tp->buflen - tp->gaplen, -1);
              break;
            }
          default:
            ewevent(ew, &e, &closed);
            if (tty_ready == YES && !pause_set) return;
          }
          break;
        case WE_COMMAND:
          switch (e.u.command) {
          case WC_CANCEL:
            interrupt_pending = YES;
            break;
          case WC_CLOSE:
            pause_for_user();
            exit(1);
          case WC_RETURN:
            {
              TEXTEDIT* tp = CSL_ew->tp;
              int f1 = zaddgap(tp->foc);
              int ee = tp->start[tp->nlines-tty_nnl] + tty_offset;
/* printf("f1=%d ee=%d offset=%d\n", f1, ee, tty_offset); */
              if (f1 >= ee) {
                tty_nnl++;
                if (f1 == tp->buflen) {
                  ewevent(ew, &e, &closed);
                  tty_ready = YES;
                  if (!pause_set) return;
                }
              }
            }
            break;
          case WC_DEL:
          case WC_BACKSPACE:
                                /* Need to check to see if we are deleting
                                 * in the offset area */
            {
              TEXTEDIT* tp = CSL_ew->tp;
              int f1 = tp->foc;
              int i;
              int ss = tp->start[tp->nlines-tty_nnl];
              int ee = ss + tty_offset;
              if (tp->foclen == 0) {
                if (ss < f1 && f1 <= ee && tty_offset>0) tty_offset--;
              }
              else {
                for (i=0; i<tp->foclen; i++) {
                  if (ss <= f1+i && f1+i < ee && tty_offset>0) tty_offset--;
                }
              }
            }
            break;
          case WC_LEFT:
          case WC_RIGHT:
          default:
            break;
          }
          ewevent(ew, &e, &closed);
          break;
        case WE_MENU:
          switch (e.u.m.id) {
          case ADMIN_MENU:
            switch (e.u.m.item) {
            case MMFile:
              {
                short wd;
                TEXTEDIT *tp = CSL_ew->tp;
                struct StandardFileReply sfr;
                StandardGetFile(NULL, -1, NULL, &sfr);
                if (sfr.sfGood && !sfr.sfIsFolder && !sfr.sfIsVolume) {
                  char name[256];
                  if (!get_full_name(name, &(sfr.sfFile))) break;
                  tesetfocus(tp, tp->buflen - tp->gaplen, -1);
                  ewreplace(CSL_ew, "in \"");
                  ewreplace(CSL_ew, name);
                  ewreplace(CSL_ew, "\"");
                  /*tetoend(tp); */
                }
                break;
              }
            case MMSaveas:
              ewsaveas(CSL_ew);
              break;
            case MMHelp:
              helpwindow(0);
              break;
            case MMHelpSel:
              help_selection(ew);
              break;
          case MMHelpAsk:
            {
              char buf[40];
              int len;
              if (waskstr("Help on topic", buf, 40)) {
                len = strlen(buf);
                help_buffer(buf, len);
              }
            }
            break;
            case MMAbort:
              pause_for_user();
              exit(1);
            case MMInt:
              interrupt_pending = YES;
              return;
            case MMPause:
              pause_set = !pause_set;
              wmenucheck(adminmenu, MMPause, pause_set);
              if (pause_set) wsettitle(CSL_window, "<Paused> Reduce 3.7");
              else           wsettitle(CSL_window, "Reduce 3.7");
              break;
            }
            break;
          case EDIT_MENU:
            switch (e.u.m.item) {
            case MMCopy:
              ewcopy(ew);
              break;
            case MMPaste:
              {
                char* text = wgetclip();
                char* tt = text;
                int valid = YES;

                if (text == NULL) wfleep();
                else {
                  TEXTEDIT *tp = CSL_ew->tp;
                  tesetfocus(tp, tp->buflen - tp->gaplen, -1);
                  while (*tt != '\0')
                    if (*tt++=='\n') valid = NO;
                  if (valid) ewreplace(ew, text);
                  else /*wmessage("Cannot Paste text including new line"); */
                          Alert(129, NULL);
                }
              }
              break;
            case MMCut:
              ewcopy(ew);
            case MMClear:
                                /* Need to check to see if we are deleting
                                 * in the offset area */
              {
                TEXTEDIT* tp = CSL_ew->tp;
                int f1 = tp->foc;
                int i;
                int ss = tp->start[tp->nlines-tty_nnl];
                int ee = ss + tty_offset;
                for (i=0; i<tp->foclen; i++)
                  if (ss <= f1+i && f1+i < ee) {
                    if (tty_offset>0) tty_offset--;
                  }
              }
              ewreplace(ew, "");
              break;
            case MMSelAll:
              tesetfocus(ew->tp, 0, tegetlen(ew->tp));
              break;
            }
            break;
          case LOAD_MENU:
            {
              char *load = "load_package ";
              char *tt = loads[e.u.m.item];
              TEXTEDIT *tp = CSL_ew->tp;
              tesetfocus(tp, tp->buflen - tp->gaplen, -1);
              tp->aim= UNDEF;
              tp->focprev= FALSE;
              ewreplace(CSL_ew, load);
              ewreplace(CSL_ew, tt);
              tty_ready = YES;
              ewreplace(CSL_ew, ";\n");
              tty_nnl++;
              wmenuenable(loadmenu, e.u.m.item, NO);
              return;
            }
          case LIB_MENU:
            {
              char *load = "load_package ";
              char *tt = libraries[e.u.m.item];
              TEXTEDIT *tp = CSL_ew->tp;
              tesetfocus(tp, tp->buflen - tp->gaplen, -1);
              tp->aim= UNDEF;
              tp->focprev= FALSE;
              ewreplace(CSL_ew, load);
              ewreplace(CSL_ew, tt);
              tty_ready = YES;
              ewreplace(CSL_ew, ";\n");
              tty_nnl++;
              wmenuenable(loadmenu, e.u.m.item, NO);
              return;
            }
          case SWITCH_MENU:
            {
              char *load = (switches[e.u.m.item].state ? "off " : "on ");
              char *tt = switches[e.u.m.item].name;
              TEXTEDIT *tp = CSL_ew->tp;
              tesetfocus(tp, tp->buflen - tp->gaplen, -1);
              ewreplace(CSL_ew, load);
              ewreplace(CSL_ew, tt);
              tty_ready = YES;
              ewreplace(CSL_ew, ";\n");
              tty_nnl++;
              switches[e.u.m.item].state = ~ switches[e.u.m.item].state;
              wmenucheck(switchmenu, e.u.m.item, switches[e.u.m.item].state);
              return;
            }
          case HELP_MENU:
            helpwindow(e.u.m.item);
            break;
/*       case FONT_MENU: */
/*         if (ew == NULL) { */
/*           wfleep(); */
/*           break; */
/*         } */
/*         { */
/*           int f = wsetfont(fonts[e.u.m.item]); */
/*           if (f) { */
/*             TEXTATTR attr; */
/*             extern void getinfo_(); */
/*             wgetwintextattr(CSL_window, &attr); */
/*             attr.font = f; */
/*             wsetwintextattr(CSL_window, &attr); */
/*             getfinfo_(); */
/*             wmenucheck(fontmenu, current_font, NO); */
/*             wmenucheck(fontmenu, current_font = e.u.m.item, YES); */
/*           } */
/*         } */
/*         break; */
/*       case SIZE_MENU: */
/*         if (ew == NULL) { */
/*           wfleep(); */
/*           break; */
/*         } */
/*         wsetsize(atoi(sizes[e.u.m.item])); */
/*         { */
/*           TEXTATTR attr; */
/*           extern void getinfo_(); */
/*           wgetwintextattr(CSL_window, &attr); */
/*           attr.size = atoi(sizes[e.u.m.item]); */
/*           wsetwintextattr(CSL_window, &attr); */
/*           getfinfo_(); */
/*         } */
/*         wmenucheck(sizemenu, current_size, NO); */
/*         wmenucheck(sizemenu, current_size = e.u.m.item, YES); */
/*         break; */
          }
          break;
        case WE_CLOSE:
          pause_for_user();
          exit(1);
        default:
          ewevent(ew, &e, &closed);
          break;
        }
      }
      else if (ew == help_ew) {
        /* printf("%d %d\n", e.type, e.u.character); */
        switch (e.type) {
        case WE_MOUSE_UP:         /* Extend to a word on single click */
          if (!ew->tp->mdown) break;
          ew->tp->mdown= FALSE;
          if (e.u.where.clicks > 1) {
            teclicknew(ew->tp, e.u.where.h, e.u.where.v, FALSE, TRUE);
            help_selection(ew);
          }
          break;
        case WE_CHAR:
          switch(e.u.character) {
          case 'A'-'@':         /* ^A == beginning of line */
            {
              TEXTEDIT* tp = help_ew->tp;
              tesetfocus(tp,
                         zsubgap(tp->start[tewhichline(tp,
                                                       zaddgap(tp->foc),
                                                       tp->focprev)]),
                         -1);
              break;
            }
          case 'B'-'@':         /* ^B back a character */
            tearrow(help_ew->tp, WC_LEFT);
            break;
          case 'E'-'@':         /* ^E end of line */
            {
              TEXTEDIT* tp = help_ew->tp;
              int line = tewhichline(tp, zaddgap(tp->foc), tp->focprev);
              int xxx = zsubgap(tetextround(tp, line, tp->right));
              tesetfocus(tp, xxx, -1);
              break;
            }
          case 'F'-'@':         /* ^F forward a character */
            tearrow(help_ew->tp, WC_RIGHT);
            break;
          case 'K'-'@':         /* ^K is Page up */
            {
              int i;
              int j;
              wgetdefwinsize(&i, &j);
              j = j/wlineheight() -1;
              for (i=0; i<j; i++) tearrow(help_ew->tp, WC_UP);
              break;
          }
          case 'N'-'@':         /* ^N next line */
            tearrow(help_ew->tp, WC_DOWN);
            break;
          case 'P'-'@':         /* ^P previous line */
            tearrow(help_ew->tp, WC_UP);
            break;
          case 'Z'-'@':         /* ^Z move to end of buffer */
            {
              TEXTEDIT* tp = help_ew->tp;
              tesetfocus(tp, tp->buflen - tp->gaplen, -1);
              break;
            }
          case 'V'-'@':         /* ^V page down */
          case ' ':
          case 'L'-'@':         /* ^L is Page down */
            {
              int i;
              int j;
              wgetdefwinsize(&i, &j);
              j = j/wlineheight() -1;
              for (i=0; i<j; i++) tearrow(help_ew->tp, WC_DOWN);
              break;
          }
          case 'i':
          case 'I':
            {
              char buf[40];
              int len;
              if (waskstr("Help on topic", buf, 40)) {
                len = strlen(buf);
                help_buffer(buf, len);
              }
          break;
            }
          case 'n':
          case 'N':
            {
              extern char *strstr(const char*, const char*);
              char *p = strstr((const char*)help_buff, (const char*)"Next: ");
              int i = 0;
              if (p == NULL) {
                wfleep(); break;
              }
              p += 6;
              while (p[i]!= ',') i++;
              help_buffer(p,i);
              break;
            }
          case 'p':
          case 'P':
            {
              extern char *strstr(const char*, const char*);
              char *p = strstr((const char*)help_buff, "Prev: ");
              int i = 0;
              if (p == NULL) {
                wfleep(); break;
              }
              p += 6;
              while (p[i]!= ',') i++;
              help_buffer(p,i);
              break;
            }
          case 'q':
          case 'Q':
            help_ew->saved = TRUE; /* Fake it */
            (*free_hook)(help_buff);
            ewclose(help_ew);
            help_ew = 0;
            break;
          case 'u':
          case 'U':
            {
              extern char *strstr(const char*, const char*);
              char *p = strstr((const char*)help_buff, "Up: ");
              int i = 0;
              if (p == NULL) {
                wfleep(); break;
              }
              p += 4;
              while (p[i]!= '\n') i++;
              help_buffer(p,i);
              break;
            }
          }
          break;
        case WE_MENU:
          switch (e.u.m.id) {
          case ADMIN_MENU:
            switch (e.u.m.item) {
            case MMSaveas:
              ewsaveas(help_ew);
              break;
            case MMHelp:
              if (help_length) helpwindow(0);
              break;
            case MMHelpSel:
              help_selection(ew);
              break;
            case MMHelpAsk:
              {
                char buf[40];
                int len;
                if (waskstr("Help on topic", buf, 40)) {
                  len = strlen(buf);
                  help_buffer(buf, len);
                }
                break;
              }
            case MMAbort:
              help_ew->saved = TRUE; /* Fake it */
              (*free_hook)(help_buff);
              ewclose(help_ew);
              help_ew = 0;
              break;
            }
            break;
          case EDIT_MENU:
            switch (e.u.m.item) {
            case MMCopy:
              ewcopy(ew);
              break;
            case MMSelAll:
              tesetfocus(ew->tp, 0, tegetlen(ew->tp));
              break;
            }
            break;
          case HELP_MENU:
            helpwindow(e.u.m.item);
            break;
          }
          break;
        case WE_COMMAND:
          switch (e.u.command) {
          case WC_CANCEL:
            interrupt_pending=YES;
            break;
          case WC_RETURN:
            help_selection(ew);
            break;
          case WC_DEL:
          case WC_BACKSPACE:
            helpwindow(0);
            break;
          default:
            ewevent(ew, &e, &closed);
            break;
          }
          if (e.u.command != WC_CLOSE) {
            break;
          }
        case WE_CLOSE:
          help_ew->saved = TRUE; /* Fake it */
          (*free_hook)(help_buff);
          ewclose(help_ew);
          help_ew = 0;
          break;
        default:
          ewevent(ew, &e, &closed);
          if (closed) {
            help_ew->saved = TRUE;        /* Fake it */
            (*free_hook)(help_buff);
            ewclose(help_ew);
            help_ew = 0;
          }
          break;
        }
      }
      else if (ew != NULL) ewevent(ew, &e, &closed);
      else wfleep();
      fixmenus();
    }
}

void poll_for_attn(void)
{
  for (;;) {                    /* Loop while there are events */
    EVENT e;
    EDITWIN *ew;
    CSLbool closed;

    if (!pause_set) {
        if (!wpollevent(&e)) return;
    }
    else wgetevent(&e);
    /*    fprintf(stderr, "Event: type=%d win=%p data=%d\n", e.type, e.window, e.u.command);  */
    ew= ewfind(e.window);
    if (ew == CSL_ew) {
      switch (e.type) {
      case WE_CHAR:
        switch(e.u.character) {
          case 'A'-'@':         /* ^A == beginning of line */
          {
            TEXTEDIT* tp = CSL_ew->tp;
            tesetfocus(tp,
              zsubgap(tp->start[tewhichline(tp,
                                            zaddgap(tp->foc),
                                            tp->focprev)]),
                       -1);
            break;
          }
          case 'B'-'@':         /* ^B back a character */
          tearrow(CSL_ew->tp, WC_LEFT);
          break;
          case 'D'-'@':         /* ^D delete at cursor */
          {
            TEXTEDIT* tp = CSL_ew->tp;
            tearrow(tp, WC_RIGHT);
            e.type = WE_COMMAND;
            e.u.command = WC_BACKSPACE;
            ewevent(ew,&e, NULL);
            break;
          }
          case 'E'-'@':         /* ^E end of line */
          {
            TEXTEDIT* tp = CSL_ew->tp;
            int line = tewhichline(tp, zaddgap(tp->foc), tp->focprev);
            int xxx = zsubgap(tetextround(tp, line, tp->right));
            tesetfocus(tp, xxx, -1);
            break;
          }
          case 'F'-'@':         /* ^F forward a character */
          tearrow(CSL_ew->tp, WC_RIGHT);
          break;
          case 'K'-'@':         /* ^K kill all type ahead */
          tty_index = 0;
          break;
          case 'N'-'@':         /* ^N next line */
          tearrow(CSL_ew->tp, WC_DOWN);
          break;
          case 'P'-'@':         /* ^P previous line */
          tearrow(CSL_ew->tp, WC_UP);
          break;
          case 'Z'-'@':         /* ^Z move to end of buffer */
          {
            TEXTEDIT* tp = CSL_ew->tp;
            tesetfocus(tp, tp->buflen - tp->gaplen, -1);
            break;
          }
          case 'V'-'@':                /* ^V page down */
          case ' ':
            {
              int i;
              int j;
              wgetdefwinsize(&i, &j);
              j = j/wlineheight() -1;
              for (i=0; i<j; i++) tearrow(help_ew->tp, WC_DOWN);
              break;
            }
        default:
          if (tty_index > TTYBUF_SIZE-2) wfleep();
          else tty_buff[tty_index++] = e.u.character;
          break;
        }
        break;
      case WE_COMMAND:
        switch (e.u.command) {
        case WC_CANCEL:
          interrupt_pending = YES;
          break;
        case WC_CLOSE:
          pause_for_user();
          exit(1);
        case WC_RETURN:
          if (tty_index > TTYBUF_SIZE-2) wfleep();
          else tty_buff[tty_index++] = '\n';
          break;
        case WC_TAB:
          if (tty_index > TTYBUF_SIZE-2) wfleep();
          else tty_buff[tty_index++] = '\t';
          break;
        case WC_DEL:
        case WC_BACKSPACE:
          if (tty_index>0) tty_index--;
          break;
        }
        break;
      case WE_MENU:
        switch (e.u.m.id) {
        case ADMIN_MENU:
          switch (e.u.m.item) {
          case MMHelp:
            helpwindow(0);
            break;
          case MMHelpSel:
            help_selection(ew);
            break;
          case MMAbort:
            pause_for_user();
            exit(1);
          case MMInt:
            interrupt_pending = YES;
            return;
          case MMPause:
            pause_set = !pause_set;
            wmenucheck(adminmenu, MMPause, pause_set);
            if (pause_set) wsettitle(CSL_window, "<Paused> Reduce 3.7");
            else           wsettitle(CSL_window, "Reduce 3.7");
            break;
          }
          break;
        case EDIT_MENU:
          switch (e.u.m.item) {
          case MMCopy:
            ewcopy(ew);
            break;
          case MMPaste:
            break;
          case MMCut:
            ewcopy(ew);
          case MMClear:
            ewreplace(ew, "");
            break;
          case MMSelAll:
              tesetfocus(ew->tp, 0, tegetlen(ew->tp));
            break;
          }
          break;
        case HELP_MENU:
          helpwindow(e.u.m.item);
          break;
        }
        break;
      case WE_CLOSE:
        pause_for_user();
        exit(1);
      default:
        ewevent(ew, &e, &closed);
        break;
      }
    }
    else if (ew == help_ew) {
      switch (e.type) {
      case WE_MOUSE_UP:         /* Extend to a word on single click */
        if (!ew->tp->mdown)
          break;
        ew->tp->mdown= FALSE;
          if (e.u.where.clicks > 1) {
            teclicknew(ew->tp, e.u.where.h, e.u.where.v, FALSE, TRUE);
            help_selection(ew);
          }
        break;
      case WE_CHAR:
/*           fprintf(stderr, "WE_CHAR %d(%c)\n", e.u.character,e.u.character); */
        switch(e.u.character) {
          case 'A'-'@':         /* ^A == beginning of line */
          {
            TEXTEDIT* tp = help_ew->tp;
            tesetfocus(tp,
              zsubgap(tp->start[tewhichline(tp,
                                            zaddgap(tp->foc),
                                            tp->focprev)]),
                       -1);
            break;
          }
          case 'B'-'@':         /* ^B back a character */
          tearrow(help_ew->tp, WC_LEFT);
          break;
          case 'E'-'@':         /* ^E end of line */
          {
            TEXTEDIT* tp = help_ew->tp;
            int line = tewhichline(tp, zaddgap(tp->foc), tp->focprev);
            int xxx = zsubgap(tetextround(tp, line, tp->right));
            tesetfocus(tp, xxx, -1);
            break;
          }
          case 'F'-'@':         /* ^F forward a character */
          tearrow(help_ew->tp, WC_RIGHT);
          break;
          case 'N'-'@':         /* ^N next line */
          tearrow(help_ew->tp, WC_DOWN);
          break;
          case 'P'-'@':         /* ^P previous line */
          tearrow(help_ew->tp, WC_UP);
          break;
          case 'Z'-'@':         /* ^Z move to end of buffer */
          {
            TEXTEDIT* tp = help_ew->tp;
            tesetfocus(tp, tp->buflen - tp->gaplen, -1);
            break;
          }
          case 'L'-'@':         /* ^L is PgDn */
          case 'V'-'@':         /* ^V page down */
          case ' ':
            {
              int i;
              int j;
              wgetdefwinsize(&i, &j);
              j = j/wlineheight() -1;
              for (i=0; i<j; i++) tearrow(help_ew->tp, WC_DOWN);
              break;
            }
          case 'K'-'@':         /* ^K is PgUp */
            {
              int i;
              int j;
              wgetdefwinsize(&i, &j);
              j = j/wlineheight() -1;
              for (i=0; i<j; i++) tearrow(help_ew->tp, WC_UP);
              break;
            }
        }
        break;
      case WE_MENU:
        switch (e.u.m.id) {
        case ADMIN_MENU:
          switch (e.u.m.item) {
          case MMHelp:
            if (help_length) helpwindow(0);
            break;
          case MMHelpSel:
            help_selection(ew);
            break;
          }
          break;
        case EDIT_MENU:
          switch (e.u.m.item) {
          case MMCopy:
            ewcopy(ew);
            break;
          case MMSelAll:
            tesetfocus(ew->tp, 0,
                       tegetlen(ew->tp));
            break;
          }
          break;
        case HELP_MENU:
          helpwindow(e.u.m.item);
          break;
        }
        break;
      case WE_COMMAND:
        switch (e.u.command) {
        case WC_CANCEL:
          interrupt_pending = YES;
          break;
        case WC_RETURN:
          help_selection(ew);
          break;
        case WC_DEL:
        case WC_BACKSPACE:
          helpwindow(0);
          break;
        default:
          ewevent(ew, &e, &closed);
          break;
        }
        if (e.u.command != WC_CLOSE) {
          break;
        }
      case WE_CLOSE:
        help_ew->saved = TRUE;  /* Fake it */
        (*free_hook)(help_buff);
        ewclose(help_ew);
        help_ew = 0;
        break;
      default:
        ewevent(ew, &e, &closed);
        if (closed) {
          help_ew->saved = TRUE;        /* Fake it */
          (*free_hook)(help_buff);
          ewclose(help_ew);
          help_ew = 0;
        }
        break;
      }
    }
    else if (ew != NULL) ewevent(ew, &e, &closed);
    else wfleep();
    fixmenus();
  }
}

void flush_screen(void)
{
    TEXTEDIT* tp = CSL_ew->tp;
    if (stdout_n != 0) {
    /*     fprintf(stderr, stdout_buffer);  */
      ewreplace(CSL_ew, stdout_buffer);
      stdout_n = 0; stdout_p = stdout_buffer;
    }
    if (tp->nlines > max_nlines+5) { /* Allow a five line slop */
      techangefocus(tp, 0, zsubgap(tp->start[tp->nlines-max_nlines]));
      tp->aim= UNDEF;
      tp->focprev= FALSE;
/*    ewreplace(CSL_ew, ""); */
      tereplace(tp, "");
    /*    fprintf(stderr, "-> %d\n", tp->nlines); */
    /* focus to end */
      tesetfocus(tp, tp->buflen - tp->gaplen, -1);
    }
    wupdate(CSL_window);
}

static clock_t prev_clock = 0;

void accept_tick(void)
{
    clock_t t0 = clock();
#ifdef SOFTWARE_TICKS_PER_SECOND
    software_tick_count++;
#endif
#ifdef SOFTWARE_TICKS_PER_SECOND
        if (prev_clock != 0)
        {   double t1 = (double)(t0-prev_clock)/(double)CLOCKS_PER_SEC;
            double ratio =
               (double)(software_tick_count - prev_software_tick_count)/t1;
            int32 w;
/*
 * t1 is how long since I was last here, ratio is the number of
 * ticks per second over that time-span.
 */
            ratio = ratio / (double)SOFTWARE_TICKS_PER_SECOND;
            prev_software_tick_count = software_tick_count;
/*
 * Now ratio is the extent by which I was taking ticks too fast.
 * To dampen out my correction I will scale software_ticks by the
 * square root of this.
 */
            ratio = sqrt(ratio);
            w = (int)(1000.0 * ratio);
/*
 * I clamp the correction fator so I never adjust my clock rate by
 * a factor of more than (about) 3.
 */
            if (w > 3000) w = 3000;
            else if (w < 300) w = 300;
/*
 * Furthermore I attempt to keep software_ticks within integer range.
 */
            if (software_ticks < (0x7fffffff/3000) &&
                software_ticks > 50)
                software_ticks = (w*software_ticks)/1000;
        }
#endif
/*
 * This is where I can put things that need to be done regularly.
 * This will need to involve prodding the window manager etc etc.
 * At present I do NOTHING...
 */
    t0 = clock();
    remove_ticker();

    if (t0 > prev_clock + CLOCKS_PER_SEC) {
/*
 * Time spent doing all of this is counted as "overhead" or "system time"
 * and not included in the times that I will report to my users...
 */
      if (clock_stack == &consolidated_time[0]) {
        consolidated_time[0] +=
          ((double)(clock_t)(t0 - base_time))/((double)CLOCKS_PER_SEC);
        base_time = clock();
      }
      report_time((int32)(100.0*consolidated_time[0]), (int32)(100.0*gc_time));
    }
    push_clock();
    wupdate(CSL_window);
    poll_for_attn();
    polltick_pending = NO;
    ensure_screen();
    add_ticker();
    pop_clock();
    return;
}

static char time_string[32], space_string[32];

void report_time(int32 t, int32 gct)
{
    sprintf(time_string, "%d.%.2d secs", t/100, t%100);
    wmenusetitem(adminmenu, MMTime, time_string);
    sprintf(time_string, "+ %d.%.2d secs", gct/100, gct%100);
    wmenusetitem(adminmenu, MMOTime, time_string);
}

void report_space(int gc_count, double percent)
{
    sprintf(space_string, "[GC %d]:%.2f%%", gc_count, percent);
    wmenusetitem(adminmenu, MMSpace, space_string);
}

#ifndef HAVE_UNIVERSAL_HEADERS
#define ModalFilterUPP ProcPtr
#define NewModalFilterProc(x) ((ProcPtr)x)
#endif
extern pascal Boolean
    filter_addnl(DialogPtr, EventRecord, short *);

void pause_for_user(void)
/*
 * This is called at the end of a run so that the user gets a chance to read
 * the final screen-full of output.  It pops up a dialog box that will
 * wait for a button push.  I take the view that if output is going to a
 * file then the delay is not needed, since the user can always check for
 * messages there. This has the effect that non-interactive build sequences
 * will often run without the pause - a good thing!  Note however that this
 * mean that you MUST use the close box to exit from a wimp session. Just
 * "quit;" or "(stop 0)" will not do.
 */
{
    ModalFilterUPP filterupp = NewModalFilterProc(filter_addnl);
    remove_ticker();
    ensure_screen();
    CSL_ew->saved = TRUE;       /* Fake it */
    if (spool_file != NULL) return;
/*
 * Here I just loop handling events until the user hits the CLOSE box
 * on my window.
 */
/*    wmessage("Leaving Reduce 3.7"); */
        set_arrow();
        Alert(128, filterupp);
    ewclose(CSL_ew);
    wdone();
}

int wimpget(char *tty_buffer)
/*
 * This is the main call from the body of CSL into the window manager
 * to obtain input from the user.  It is expected to copy some input
 * characters into tty_buffer and return the number of characters
 * provided.  In this implementation I read the text back from the
 * stdwin textedit buffer, looking rather too low.
 *  Any type ahead is handled in here.
 */
{
    TEXTEDIT* tp = CSL_ew->tp;
    int i;
    int n;
    int lineno;
    tty_nnl = 1;                /* Offset from nlines */

    push_clock();
    remove_ticker();
    if (stdout_n != 0) flush_screen();
    wmenuattach(CSL_window, loadmenu);
    wmenuattach(CSL_window, libmenu);
    wmenuattach(CSL_window, switchmenu);
    lineno = tp->nlines-1;      /* Need to do this after the toend */
    tty_offset = tp->foc - tp->start[lineno];
    if (tty_offset<0) tty_offset += tp->gaplen;
    wmenuenable(adminmenu, MMPause, NO);
    if(tty_index>0) {
        int i = 0;
        for (; i<tty_index; i++)
          if (tty_buff[i] == '\n') tty_nnl++;
        tty_buff[tty_index] = '\0';
        ewreplace(CSL_ew, tty_buff);
        tty_index = 0;
    }
    event_loop();
    /*    fprintf(stderr, "Event loop ended\n");  */
    lineno = tp->nlines-tty_nnl;
    /*      fprintf(stderr, "Offset=%d Length=%d\n",
              tty_offset,
              tp->foc- tp->start[lineno]-tty_offset);
      for (i=0; i<tp->foc- tp->start[lineno]-tty_offset; i++) {
        fprintf(stderr, "%c",  *(tegettext(tp)+tp->start[lineno]+tty_offset+i));
      }
      fprintf(stderr, "\n"); */
    memcpy(tty_buffer, tegettext(tp)+tp->start[lineno]+tty_offset,
           tp->foc- tp->start[lineno]-tty_offset);
    wmenudetach(CSL_window, loadmenu);
    wmenudetach(CSL_window, libmenu);
    wmenudetach(CSL_window, switchmenu);
    wmenuenable(adminmenu, MMPause, YES);
    add_ticker();
    n = tp->foc- tp->start[lineno]-tty_offset;
    if (n<0) {
        n += tp->gaplen;
        fprintf(stderr, "N correction\n");
    }
    tty_ready = NO;
    pop_clock();
    return n;
}

int char_cnt = 0;
void putc_stdout(int c)
{
    *stdout_p++ = c;
    *stdout_p = 0;
    stdout_n++;
    char_cnt++;
    remove_ticker();
    if (c == '\n' || stdout_n > STDOUT_BUFSIZE - LONGEST_PRINTF) {
      push_clock(); flush_screen();
      if (char_cnt>200) {        /* Where 200 is a random number */
        poll_for_attn(); char_cnt = 0;
      }
      pop_clock();
    }
    if (polltick_pending) accept_tick();
    add_ticker();
}

void vfprintf_stdout(char *fmt, va_list a)
{
    int n;
/*
 * I have given myself LONGEST_PRINTF locations in the array for
 * this vsprintf to fill in.  If it overflows I am in big trouble!
 */
    n = vsprintf(stdout_p, fmt, a);
    stdout_p += n;
    stdout_n += n;
    char_cnt += n;
    remove_ticker();
    if (stdout_n > STDOUT_BUFSIZE - LONGEST_PRINTF) {
      push_clock(); flush_screen();
      if (char_cnt>200) {
        poll_for_attn(); char_cnt = 0;
      }
      pop_clock();
    }
    if (polltick_pending) accept_tick();
    add_ticker();
}

#define NARGS           25

static char *argv[NARGS+1];
static char argbuf[256];

/*
 *  init_command_line - prepare initial command line
 *
 *  The command line is preset to show the name of the program.
 *  The program name is quoted as necessary.
 *
 */

static char*
init_command_line(char *buf1, char *buf2)
{
    register char *s, *t = buf2;
    int c, space = 0, dquote = 0, squote = 0, quote = 0;

    sprintf(s = buf1, "%#s", LMGetCurApName());
    while (c = *s++) {
      if (c == ' ')
        space = 1;
      else if (c == '"')
        dquote = 1;
      else if (c == '\'')
        squote = 1;
    }
    if (space || dquote || squote)
      *t++ = quote = dquote && !squote ? '\'' : '"';
    for (s = buf1; c = *s++; *t++ = c) {
      if (c == quote || c == '\\')
        *t++ = '\\';
    }
    if (quote)
      *t++ = quote;
    *t++ = ' ';
    *t++ = 0;
    return t;
}


/*
 *  parse - divide command line into "words"
 *
 *  Words are delimited by one or more spaces.  Any characters within
 *  matching single (') or double (") quotes are taken literally.  Any
 *  character preceded by a backslash (\) is taken literally.
 *
 */

static int
parse(char *s, char *t)
{
    int c, quote = 0, argc = 0;

    while (c = *s++) {
      if (c == ' ')
        continue;
      if (argc < NARGS)
        argv[argc++] = t;
      do {
        if (c == '\\' && *s)
          c = *s++;
        else if (c == '"' || c == '\'') {
          if (!quote) {
            quote = c;
            continue;
          }
          if (c == quote) {
            quote = 0;
            continue;
          }
        }
        *t++ = c;
      } while (*s && ((c = *s++) != ' ' || quote));
      *t++ = 0;
    }
    return(argc);
}

#ifdef OLD
int wgetargs(char ***av)
{
    short i, argc;
    char buf[256];
    char *t = init_command_line(buf, argbuf);

    if( !waskstr("       Arguments for REDUCE 3.7", t, 256)) exit(1);
    t[-1] = ' ';
    sprintf(buf, "%s", argbuf);
    argc = parse(buf, argbuf);
    *av = argv;
    /*     for(i=0;i<argc; i++) wmessage(argv[i]); */
    return(argc);
}
#else

enum {                /* Dialog names for main box */
    exDEF = 3,
    exLOG,
    exVER,
    exXTA
};

enum {                /* Dialog names for additional box */
    exBAT = 3,
    exBAC,
    exTRA,
    exCLD,
    exLAP,
    exQUI,
    exREC,
    exRED,
    exRAN,
    exSIZ,
    exOTH,
    exLGG,
    exDFF,
    exVBE
};

/*
 *  get_args - process "command line"
 *
 */

 /* Dialog numbers */
 #define START_1 (129)
 #define START_2 (128)

/*Rect bounds = {60, 20, 320, 220};
Rect boundx = {80, 30, 400, 500};
*/

int DoExtra(char ***av)
{
    DialogPtr dd;
    short i;
    int verbos = 0;
    int deflt = 0;
    int logging = 0;
    char buff[256];
    char name[256];
    char nams[256];
    Rect box;
    short type;
    Handle item;
    char *t = init_command_line(buff, argbuf);
    char *s = t-1;
    int argc;
         ModalFilterUPP filterupp = NewModalFilterProc(filter_addnl);
        int batch =0, back = 0, cold = 0, lap = 0, quiet = 0;
        int trap = 0, recover = 0, redirect = 0;
/*    ee = NewDialog(NULL, &boundx, "\p", 1, 1, (WindowPtr)-1, 0, 256L,
                         GetResource('DITL',132)); */
    dd = GetNewDialog(START_2, NULL, (WindowPtr)-1);
        GetDItem(dd, 1, &type, &item, &box);
        SetPort(dd);
        InsetRect(&box, -4, -4);
        PenSize(3, 3);
        FrameRoundRect(&box, 16, 16);
        set_arrow();
        do {                /*  engage in dialog  */
          ModalDialog(filterupp, &i);
          switch (i) {
            case cancel:
              DisposDialog(dd);
              exit(0);
            case exBAT:
              batch = !batch;
                GetDItem(dd, exBAT, &type, &item, &box);
                SetCtlValue((struct ControlRecord **)item, batch);
              break;
            case exBAC:
              back = !back;
                GetDItem(dd, exBAC, &type, &item, &box);
                SetCtlValue((struct ControlRecord **)item, back);
              break;
            case exTRA:
              trap = !trap;
                GetDItem(dd, exTRA, &type, &item, &box);
                SetCtlValue((struct ControlRecord **)item, trap);
              break;
            case exCLD:
              cold = !cold;
                GetDItem(dd, exCLD, &type, &item, &box);
                SetCtlValue((struct ControlRecord **)item, cold);
              break;
            case exLAP:
              lap = !lap;
                GetDItem(dd, exLAP, &type, &item, &box);
                SetCtlValue((struct ControlRecord **)item, lap);
              break;
            case exQUI:
              quiet = !quiet;
                GetDItem(dd, exQUI, &type, &item, &box);
                SetCtlValue((struct ControlRecord **)item, quiet);
              break;
            case exREC:
              recover = !recover;
                GetDItem(dd, exREC, &type, &item, &box);
          SetCtlValue((struct ControlRecord **)item, recover);
              break;
            case exRED:
              redirect = waskfile("Redirection File: ", nams, 256, 1);
              break;
            case exLGG:
                logging = waskfile("Log File: ", name, 256, 1);
              break;
        case exDFF:
              deflt = !deflt;
                GetDItem(dd, exDFF, &type, &item, &box);
                SetCtlValue((struct ControlRecord **)item, deflt);
                break;
        case exVBE:
          verbos = !verbos;
                GetDItem(dd, exVBE, &type, &item, &box);
                SetCtlValue((struct ControlRecord **)item, verbos);
                break;
            }
          } while (i != ok);
          if (batch) { strcpy(t, " -b"); t += 3; }
          if (back) { strcpy(t, " -g"); t += 3; }
          if (cold) { strcpy(t, " -z"); t += 3; }
          if (lap) { strcpy(t, " -s"); t += 3; }
          if (quiet) { strcpy(t, " -q"); t += 3; }
          if (recover) { strcpy(t, " -y"); t += 3; }
          if (trap) { strcpy(t, " -x"); t += 3; }
      if (verbos) { strcpy(t, " -v"); t += 3; }
      if (logging) { strcpy(t, " -l"); t += 3;
            strcpy(t, name); t += strlen(name);
      }
      if (redirect) { strcpy(t, " --"); t += 3;
            strcpy(t, nams); t += strlen(nams);
      }
          {
            char bb[256];
            GetDItem(dd, exRAN, &type, &item, &box);
            GetIText(item, (unsigned char *)bb);
#ifndef CLEVERGLUE
            P2CStr((unsigned char *)bb);
#endif
        if (bb[0]!='\0') {
              strcpy(t, " -r"); t += 3;
              strcpy(t, bb); t += strlen(bb);
            }
            GetDItem(dd, exSIZ, &type, &item, &box);
            GetIText(item, (unsigned char *)bb);
#ifndef CLEVERGLUE
            P2CStr((unsigned char *)bb);
#endif
            if (bb[0]!='\0') {
              strcpy(t, " -k"); t += 3;
              strcpy(t, bb); t += strlen(bb);
            }
            GetDItem(dd, exOTH, &type, &item, &box);
            GetIText(item, (unsigned char *)bb);
#ifndef CLEVERGLUE
            P2CStr((unsigned char *)bb);
#endif
            if (bb[0]!='\0') {
              strcpy(t, bb); t += strlen(bb);
            }
          }
        out:
          DisposDialog(dd);
    if (!deflt) *s = ' ';
    sprintf(buff, "%s", argbuf);
    argc = parse(buff, argbuf);
    *av = argv;
/*    for(i=0;i<argc; i++) wmessage(argv[i]); */
    return(argc);
}

int wgetargs(char ***av)
{
    DialogPtr dd;
    short i;
    int verbos = 0;
    int deflt = 0;
    int logging = 0;
    char buff[256];
    char name[256];
    char nams[256];
    int p = 0;
    Rect box;
    short type;
    Handle item;
    char *t = init_command_line(buff, argbuf);
    char *s = t-1;
    int argc;
         ModalFilterUPP filterupp = NewModalFilterProc(filter_addnl);

/*    dd = NewDialog(NULL, &bounds, "\p", 1, 1, (WindowPtr)-1, 0, 256L,
                   GetResource('DITL',131)); */
    dd = GetNewDialog(START_1, NULL, (WindowPtr)-1);
        GetDItem(dd, 1, &type, &item, &box);
        SetPort(dd);
        InsetRect(&box, -4, -4);
        PenSize(3, 3);
        FrameRoundRect(&box, 16, 16);
        set_arrow();
    do {                /*  engage in dialog  */
      ModalDialog(filterupp, &i);
      switch (i) {
      case cancel:
            DisposDialog(dd);
            exit(0);
      case exDEF:
            deflt = !deflt;
              break;
      case exVER:
              verbos = !verbos;
              GetDItem(dd, exVER, &type, &item, &box);
              SetCtlValue((struct ControlRecord **)item, verbos);
              break;
      case exLOG:
              logging = waskfile("Log File: ", name, 256, 1);
        break;
      case exXTA:
        set_watch();
              DisposDialog(dd);
              return DoExtra(av);
      }
    } while (i != ok);
        set_watch();
    {
      char aa[256];
      if (verbos) {
              strcpy(t, " -v");
              t += 3; }
      if (logging) {
        strcpy(t, " -l"); t += 3;
            strcpy(t, name); p += strlen(aa);
      }
    }
    if (!deflt) *s = ' ';
    DisposDialog(dd);
    sprintf(buff, "%s", argbuf);
    argc = parse(buff, argbuf);
    *av = argv;
/*    for(i=0;i<argc; i++) wmessage(argv[i]); */
    return(argc);
}
#endif

/* end of sysmac.c */

