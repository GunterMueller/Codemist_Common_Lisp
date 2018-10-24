/*
 *  "sys.h"                         Copyright (C) Codemist Ltd 1994/5
 *
 *              Set configuration based on host machine, and
 *              define interface to file system routines that
 *              I use in this code...
 */

/* Signature: 1b04c5ab 30-Dec-1995 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>


#define LONGEST_LEGAL_FILENAME  256

extern int Cmkdir(char *s);

extern int truncate_file(FILE *f, long int where);

extern void adjust_file_name(char *filename, char *old);

extern void unadjust_file_name(char *filename, char *old);

/*
 * datestamps that I put in archives have given me significant
 * trouble with regard to portability - so now I deal with times by
 * talking to the system in terms of broken down local time (struct tm).
 * I then pack things up for myself to get 32-bit timestamps. The
 * encoding I use aims at simplicity - it treats all months as 31 days
 * and thus does not have to worry about leap years etc.  NOTE this means
 * that timestamps in previously created CAR archives will be decoded
 * in a wrong-minded way by the new version.  Tough luck.
 */

extern void unpack_date(unsigned long int r,
                        int *year, int *mon, int *day,
                        int *hour, int *min, int *sec);

extern unsigned long int  pack_date(int year, int mon, int day,
                                    int hour, int min, int sec);

typedef struct date_and_type
{
    unsigned long int date;
    unsigned long int type;
} date_and_type;

/* Reinstate date and filetype... */

extern void set_filedate(char *name, unsigned long int datestamp,
                                     unsigned long int ftype);

extern void put_fileinfo(date_and_type *p, char *name);

/*
 * If I am to process directories I need a set of routines that will
 * scan sub-directories for me. The specification I want is:
 *       int scan_directory(char *dir,
 *                    void (*proc)(char *name, int why, int32 size));
 *
 * This is called with a file- or directory-name as its first argument
 * and a function as its second.
 * It calls the function for every directory and every file that can be found
 * rooted from the given place.  If the file to scan is specified as NULL
 * the current directory is processed.
 * When a simple file is found the procedure is called with the name of the
 * file, why=0, and the length (in bytes) of the file.  For a directory
 * the function is called with why=1, then the contents of the directory are
 * processed. For directories the size information will be 0.  There is no
 * guarantee of useful behaviour if some of the files to be scanned are
 * flagged as  "invisible" or "not readable" or if they are otherwise special.
 * The value returned is the number of characters that should be removed
 * the start of file-names returned to get rid of any initial directory
 * specified.  If dir is passed as NULL this will be zero and names will
 * come back plain, otherwise it will be 1+strlen(dir)
 */

#define SCAN_FILE       0
#define SCAN_STARTDIR   1
#define SCAN_ENDDIR     2

extern void scan_directory(char *dir,
                           void (*proc)(char *name, int why, long int size));

/*
 * When scan_directory calls the procedure it has been passed, it will have
 * set scan_leafstart to the offset in the passed filename where the
 * original directory ended and the new information starts. Thus if the
 * original string was (say) "/usr/users/acn/xxx" then files in that directory
 * will have names like "/usr/users/acn/xxx/subdir/subfile.ext" and
 * (name+scan_leafstart) will be the string "subdir/subfile.ext" being
 * relative the to name of the directory originally specified.
 */

extern int scan_leafstart;

/*
 * scan_files() is just like scan_directory() except that it does not
 * recurse into sub-directories.
 */

extern void scan_files(char *dir,
                       void (*proc)(char *name, int why, long int size));

/*
 * What follows is concerned with detecting the compiler that is being used
 * and the associated operating system.
 */


#ifdef DOS16RM                      /* Intel 80286 family (16 bit mode)     */
                                    /* For use with Zortech Mode Z extender */
#  define MS_DOS                1
#  define SIXTEEN_BIT           1
#endif

#ifdef DOS386                       /* Zortech 32-bit mode 386 */
#  define MS_DOS                1
#endif

#ifdef DOS86                       /* Zortech 16-bit modes (use -mci please) */
#  define MS_DOS                1
#  define SIXTEEN_BIT           1
#endif

#ifdef GCC386                      /* GCC for the 386 */
#  define MS_DOS                1
#endif

#ifdef __WATCOMC__                 /* Watcom C 10.5/10.6 */
#  define MS_DOS                1
#include <sys\utime.h>
#include <dos.h>
#include <direct.h>
#include <windows.h>               /* For FindFirstFile etc */
#endif

#ifdef ATARI                       /* Lattice C for all STs */
#  define SIXTEEN_BIT           1
#endif

#ifdef THINK_C     /* Development on a Mac LC System 7 and Think C 5.0 */
#  define SIXTEEN_BIT           1
#include <memory.h>
#define malloc(n) NewPtr(n)
#define free(p)   DisposPtr((Ptr)(p))
#endif

#ifdef arm                          /* Old RISCIX compiler... */
#  define __arm                 1
#endif

#ifdef __arm
#endif  /* __arm */

#ifdef __mips
#  ifndef __mips__
#     define __mips__
#  endif
#endif

#ifdef __mips__
#  define NO_BINARY_FOPEN    1
#  define UNIX               1
#endif

#ifdef __linux__
#  define UNIX               1
#endif

#ifdef vax
#  ifdef vms
      /* this allows me to compile under VAX/VMS directly */
#     define __vmsvax__
#  endif
#endif

#ifdef __vax__
#  define NO_BINARY_FOPEN       1
#  define UNIX                  1
#endif

#ifdef __vmsvax__
#endif

#ifdef _rs6000
#  define UNIX                  1
#endif

#ifdef __clipper
#  define UNIX                  1
#endif

#ifdef __alpha
#  define UNIX                  1
#  define _POSIX_SOURCE         1
#  define _XOPEN_SOURCE         1
#endif

#ifdef __hp9000s300
#  define UNIX                  1
#endif

#ifdef __hp9000s800
#  define UNIX                  1
#endif

#ifdef __APOLLO__
#  define UNIX                  1
#endif

#ifdef __ibm370
#endif

#ifdef __m88k__
#  define UNIX                  1
#endif

#ifdef __sparc__
#  ifdef sun
      typedef char *VoidStar;
#  endif
#  define UNIX                  1
#endif

#ifdef __sparc
#  define UNIX                  1
#  define NO_BINARY_FOPEN       1   /* probably not needed */
#endif

#ifdef __kcm                    /* The ICL "Knowledge Crunching Machine */
#endif

#ifdef SIXTEEN_BIT
typedef long int            int32;
typedef unsigned long int   unsigned32;
#else
typedef int                 int32;
typedef unsigned int        unsigned32;
#endif
typedef int                 bool;
#define TRUE                1
#define FALSE               0

/*
 * DEC/Ultrix (at least) fails to support modes "wb" and "rb" for fopen(),
 * and faults attempts to use them - on such systems use just "w" and "r",
 * which is probably reasonable on Unix anyway.
 */

#ifdef NO_BINARY_FOPEN
#  define RB_MODE           "r"
#  define WB_MODE           "w"
#endif

#ifndef RB_MODE
#  define RB_MODE           "rb"
#  define WB_MODE           "wb"
#endif

/*
 * The next few lines are because some sets of header files do not
 * define all the symbols that ANSI say they should (this seems to be
 * notably a Sun problem, but others are not blameless). I provide
 * at least some sort of default values here. Override by -Dxxx=yyy in
 * CFLAGS if needbe.
 */

#ifndef SEEK_SET
#  define SEEK_SET       0
#endif

#ifndef CLOCKS_PER_SEC
#  define CLOCKS_PER_SEC 1000000
#endif

#ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS   0
#endif

#ifndef EXIT_FAILURE
#  define EXIT_FAILURE   1
#endif

/**************************************************************************/
 
#ifdef macintosh

#include <console.h>
#define DIRECTORY_CHAR ':'

#else /* macintosh */

#ifdef ATARI
/*
 * This version is NCC M68K C running under TOS
 */
#define DIRECTORY_CHAR    '\\'

struct FILEINFO
{
  char  resv[21];               /* reserved */
  char  attr;                   /* actual file attribute */
  long  time;                   /* file time and date */
  long  size;                   /* file size in bytes */
  char  name[14];               /* file name */
};

/* #include <dos.h> */
int dfind(struct FILEINFO *, const char *, int);
int dnext(struct FILEINFO *);

/* #include <osbind.h> */
#include <sys/types.h>
#include <sys/stat.h>

#define FA_DIREC        (1<<4)

#else /* ATARI */

#ifdef __arm
/*
 * This option is for the Acorn Archimedes running RISC-OS
 */
#define DIRECTORY_CHAR    '.'

#include "os.h"

#else /* __arm */


#ifdef WINDOWS_NT
/*
 * This version is for Windows NT 3.1 with Microsoft VC++
 */

#define DIRECTORY_CHAR    '\\'
#include <windows.h>
#include <io.h>
#include <sys/stat.h>

#else /* WINDOWS_NT */


#ifdef MS_DOS

/*
 * This version has been tested with Zortech C -- support for GCC/386 is
 * uncertain at present.
 */

#define DIRECTORY_CHAR    '\\'
#include <dos.h>
#include <io.h>
#include <direct.h>
#include <sys\stat.h>

#ifdef __WATCOMC__
/*
 * The following few definitions bring Watcom and Zortech into alignment
 * for directory scanning code.
 */
#define FIND      find_t
#define FA_DIREC  _A_SUBDIR
#define attribute attrib
#endif

#else /* NS_DOS */

#ifdef UNIX
#include "unix.h"
#endif /* UNIX */
#endif /* MS_DOS */
#endif /* WINDOWS_NT */
#endif /* __arm */
#endif /* ATARI */
#endif /* macintosh */


/* end of sys.h */

