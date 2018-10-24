
/* uuencode.c */

/*
 * Arthur's own "uuencoder" so that files can be encoded on MSDOS
 * and other non-Unix systems.
 * It seems that "uuencode" format has a number of variations.  The
 * version used here uses '`' rather than ' ' in the body of the file
 * to avoid trailing-blank difficulties.  Some variants on the format add
 * checksums to each line - I do not.
 *
 *   Use:   uuencode src dest {recorded-name}
 * where the recorded name defaults to the same as the source filename.
 */

/* Signature: 024f374b 07-May-1995 */

#ifdef DOS16RM                      /* Intel 80286 family (16 bit mode)     */
                                    /* For use with Zortech Mode Z extender */
#  define MS_DOS                1
#  define ZORTECH_C             1
#endif

#ifdef DOS386                       /* Zortech 32-bit mode 386 */
#  define MS_DOS                1
#  define ZORTECH_C             1
#endif

#ifdef DOS86                       /* Zortech virtual mode */
#  define MS_DOS                1
#  define ZORTECH_C             1
#endif

#ifdef ATARI                       /* Lattice C for all STs */
#  define LATTICE_C             1
#endif

#ifdef THINK_C     /* Development on a Mac LC with 4 Mbytes, System 7 and Think C 5.0 */
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
#  ifdef sun              /* For Sparcstation with sub-standard C library */
                          /* You may need to adjust this for your sun     */
/*
 * These symbols should have been defined by standard #include files
 */
#     define CLOCKS_PER_SEC 1000000
#     define EXIT_SUCCESS 0
#     define EXIT_FAILURE 1
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

#include <stdio.h>      /* almost everybody needs this               */
#include <time.h>       /* so I can declare base_time etc as clock_t */

#ifndef CLOCKS_PER_SEC
#  ifndef CLK_TCK
      #error "please predefine CLOCKS_PER_SEC for this machine"
#     define CLK_TCK 1000000    /* Utterly spurious value - I know no better */
#  endif
#  define CLOCKS_PER_SEC (CLK_TCK)
#endif

typedef long int            int32;
typedef unsigned long int   unsigned32;
typedef int                 bool;
#define TRUE                1
#define FALSE               0

#ifdef NO_BINARY_FOPEN
#  define RB_MODE           "r"
#  define WB_MODE           "w"
#endif

#ifndef RB_MODE
#  define RB_MODE           "rb"
#  define WB_MODE           "wb"
#endif

#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *src, *dest, *name;
    FILE *f1, *f2;
    char line[48+4];
    int c, linep;
    switch (argc)
    {
case 3:
        src = name = argv[1];
        dest = argv[2];
        break;
case 4:
        src = argv[1];
        dest = argv[2];
        name = argv[3];
        break;
default:
        fprintf(stderr, "Usage:  uuencode <src> <dest> {<name>}\n");
        exit(EXIT_SUCCESS);
    }
    f1 = fopen(src, RB_MODE);
    if (f1 == NULL)
    {   fprintf(stderr, "Unable to access \"%s\"\n", src);
        exit(EXIT_FAILURE);
    }
    f2 = fopen(dest, "w");
    if (f2 == NULL)
    {   fprintf(stderr, "Unable to access \"%s\"\n", dest);
        fclose(f1);
        exit(EXIT_FAILURE);
    }
    fprintf(f2, "begin 644 %s\n", name);
    do
    {   int i;
        linep = 0;
        while (linep < 45 && ((c = getc(f1)) != EOF)) line[linep++] = c;
        line[linep] = line[linep+1] = 0;
        putc(' ' + linep, f2);		   /* character count */
        if (linep == 0) putc('.', f2); /* Fudge wrt trailing blanks */
        for (i=0; i<linep; i+=3)
        {   int b1 = line[i], b2 = line[i+1], b3 = line[i+2];
            int c1, c2, c3, c4;
            b1 &= 0xff; b2 &= 0xff; b3 &= 0xff;
            c1 = b3;
            c2 = (b3 >> 6) | (b2 << 2);
            c3 = (b2 >> 4) | (b1 << 4);
            c4 = b1 >> 2;
            c1 &= 0x3f; c2 &= 0x3f; c3 &= 0x3f; c4 &= 0x3f;
            if (c1 == 0) c1 = '`'; else c1 += ' ';
            if (c2 == 0) c2 = '`'; else c2 += ' ';
            if (c3 == 0) c3 = '`'; else c3 += ' ';
            if (c4 == 0) c4 = '`'; else c4 += ' ';
            putc(c4, f2);
            putc(c3, f2);
            putc(c2, f2);
            putc(c1, f2);
        }
        putc('\n', f2);
    } while (c != EOF);
    if (linep != 0)
       fprintf(f2, " .\n");		/* line with zero count, to mark the end */
    fprintf(f2, "end\n");
    fclose(f1);
    fclose(f2);
    return 0;
}

/* end of uuencode.c */

