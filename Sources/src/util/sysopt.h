/*
 *  "sysopt.h"                      Copyright (C) Codemist Ltd 1994
 *
 *              Set configuration based on host machine
 */

/* Signature: 3d24b59d 11-May-1995 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

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

#ifdef __WATCOMC__                 /* Watcom C 10.0 */
#  define MS_DOS                1
#include <sys\utime.h>
#include <dos.h>
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
 
#ifdef THINK_C /* Macintosh - tested on Mac LC with 4 Mbytes and system 7 */
#include <console.h>
#define DIRECTORY_CHAR ':'
#endif

/**************************************************************************/


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

#endif /* ATARI */


/**************************************************************************/


#ifdef __arm
/*
 * This option is for the Acorn Archimedes running RISC-OS
 */
#define DIRECTORY_CHAR    '.'

#include "os.h"

#endif /* __arm */


/**************************************************************************/


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

#endif


/**************************************************************************/


#ifdef WINDOWS_NT
/*
 * This version is for Windows NT 3.1 with Microsoft VC++
 */

#define DIRECTORY_CHAR    '\\'
#include <windows.h>
#include <io.h>
#include <sys/stat.h>

#endif


/**************************************************************************/


#ifdef UNIX
#include "unix.h"
#endif

/**************************************************************************/

#define LONGEST_LEGAL_FILENAME  256

/* end of sysopt.h */

