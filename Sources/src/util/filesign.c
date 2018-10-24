/*
 * "filesign.c"                     Copyright (C) 1991, Codemist Ltd
 *
 * Code to look after "signatures" (i.e. checksums) kept in files
 * of C source code.  Such a signature follows...
 */

/* Signature: 1a2f508f 08-Nov-1995 */

/*
 *  filesign <file1> <file2> ...    check signatures in given files.
 *  filesign -u <from> <to>         copy, updating signature.
 *  filesign -u <file>              update signature in place.
 */

#include "sys.h"

/*
 * I use the following to compute checksums...
 */

static unsigned32 CRC;

static void update_CRC(int ch)
{
    unsigned32 CRCtemp;
/*
 * This is my favourite hash function at present - it cycles a 31-bit shift
 * register with maximum period.  As used here the item mixed in (ch) will
 * always have been masked with 0xff.
 */
    CRCtemp = (CRC << 7);
    CRC = ((CRC >> 25) ^      /* NB logical (not arithmetic) shift here */
           (CRCtemp >> 1) ^
           (CRCtemp >> 4) ^
           (unsigned32)ch) & 0x7fffffff;
}

static bool found, undated_signature;
static long int position;
static FILE *f1;

static unsigned32 find_signature(char *file, char *mode)
{
    unsigned32 save, fileCRC = 0;
    char line[80], date[16];
    int linep, c;
    strcpy(date, "  <date>   ");
    f1 = fopen(file, mode);
    save = CRC = 1;
    found = FALSE;
    if (f1 == NULL) return 0;
    linep = 0;
    position = ftell(f1);
    while ((c = getc(f1)) != EOF)
    {   if (c == '\n')
        {   update_CRC(c & 0xff);
            if (!found)
            {   strcpy(date, " <unknown> ");
                line[linep] = 0;
/*
 * Here I demand that the CRC be displayed with exactly 8 digits.  Well
 * what I impose is that the complete signature record be a line that is
 * 37 characters long, and this is good because if I update it in place I
 * will re-write just that amount.
 */
                if (linep == 37 &&
                    sscanf(line, "/* Signature: %lx %11s */",
                                 &fileCRC, date) == 2)
                    found = TRUE, CRC = save;
                else if (linep == 25 &&
                    sscanf(line, "/* Signature: %lx */", &fileCRC) == 1)
                    undated_signature = TRUE, found = TRUE, CRC = save;
                else position = ftell(f1);
            }
            save = CRC;
            linep = 0;
        }
        else
        {   if (linep < 79) line[linep++] = c;
            update_CRC(c & 0xff);
        }
    }
    printf("%-24s: %.08lx (%s)", file, (long)(unsigned32)CRC, date);
    if (!found) printf(", no signature in file\n");
    else if (fileCRC != CRC)
        printf(", stored signature: %.08lx\n",
                        (long)(unsigned32)fileCRC);
    else printf("\n");
    return fileCRC;
}

static void verify_signature(char *name, int dirp, long int size)
{
    if (dirp != SCAN_FILE) return;
    find_signature(name, "r");
    if (f1 != NULL) fclose(f1);
}

static char today[16];

static void update_in_place(char *src)
{
    undated_signature = FALSE;
    find_signature(src, "r+");
    if (f1 == NULL)
    {   printf("File \"%s\" could not be opened for updating\n", src);
        exit(EXIT_FAILURE);
    }
    if (!found)
    {   printf("No signature record to update in \"%s\"\n", src);
        exit(EXIT_FAILURE);
    }
    if (undated_signature)
    {   printf("Existing signature in \"%s\" is not dated\n", src);
        printf("so can not be updated in place.  Use filesign -u src dest\n");
        exit(EXIT_FAILURE);
    }
    fseek(f1, position, SEEK_SET);
    fprintf(f1, "/* Signature: %.08lx %.11s */", (long)(unsigned32)CRC, today);
    fclose(f1);
}

static void update_signature(char *src, char *dest)
{
    unsigned32 fileCRC;
    FILE *f2;
    char line[80];
    int i, linep, c, c1, linecount, context;
    bool done, longline;
    fileCRC = find_signature(src, "r");
    if (f1 == NULL)
    {   printf("Failed to read file \"%s\"\n", src);
        exit(EXIT_FAILURE);
    }
    fseek(f1, 0, SEEK_SET);
    f2 = fopen(dest, "w");
    if (f2 == NULL)
    {   printf("Failed to read file \"%s\"\n", src);
        fclose(f1);
        exit(EXIT_FAILURE);
    }
    linep = 0;
    linecount = 1;
    done = !found;
    longline = FALSE;
/*
 * To avoid inserting a signature inside a string or another comment
 * I keep track of where I am just a bit...
 */
#define NORMAL 'x'
#define CHAR   '\''
#define STRING '"'
#define COMM   '*'
    context = NORMAL;
    c1 = '\n';
    while ((c = getc(f1)) != EOF)
    {   if (context == COMM)
        {   if (c1 == '*' && c == '/') context = NORMAL;
        }
        else if (context == CHAR)
        {   if (c == '\'' && c1 != '\\') context = NORMAL;
        }
        else if (context == STRING)
        {   if (c == '"' && c1 != '\\') context = NORMAL;
        }
        else if (c1 == '/' && c == '*') context = COMM;
        else if (c == '\'') context = CHAR;
        else if (c == '"') context = STRING;
        
        c1 = c;
        if (c == '\n')
        {   if (longline) putc('\n', f2);
            else
            {   if (!done && context == NORMAL)
                {   unsigned32 fileCRC;
                    char date[16];
                    line[linep] = 0;
                    if (linep == 37 &&
                        sscanf(line, "/* Signature: %lx %11s */",
                                     &fileCRC, date) == 2)
                        fprintf(f2, "/* Signature: %.08lx %.11s */\n",
                                    (long)(unsigned32)CRC, today),
                        done = TRUE;
                    else if (linep == 25 &&
                        sscanf(line, "/* Signature: %lx */", &fileCRC) == 1)
                        fprintf(f2, "/* Signature: %.08lx %.11s */\n",
                                    (long)(unsigned32)CRC, today),
                        done = TRUE;
                    else fprintf(f2, "%s\n", line);
                }
                else
                {   for (i=0; i<linep; i++) putc(line[i], f2);
                    putc('\n', f2);
                }
            }
            longline = FALSE;
            linep = 0;
            if (!found && context==NORMAL)
            {   fprintf(f2, "/* Signature: %.08lx %.11s */\n",
                            (long)(unsigned32)CRC, today);
                found = done = TRUE;
            }
            linecount++;
        }
        else
        {   if (longline) putc(c, f2);
            else if (linep < 80) line[linep++] = c;
            else
            {   for (i=0; i<linep; i++) putc(line[i], f2);
                putc(c, f2);
                longline = TRUE;
            }
        }
    }
    fclose(f1);
    fclose(f2);
}

static void usage(void)
{
  printf("Usage:  filesign <file1> <file2> ...      check\n");
  printf("or      filesign -u <from> <to>          update\n");
  printf("or      filesign -u <file>      update in place\n");
}

int main(int argc, char *argv[])
{
    int i;
    if (argc < 2 ||
        (argv[1][0] == '-' && ((argc != 3 && argc != 4) ||
                               tolower(argv[1][1]) != 'u')))
    {   usage();
        exit(EXIT_FAILURE);
    }
    if (argv[1][0] == '-')
    {
        time_t t0;
        char *b;
        if (argv[1][1] != 'u' || argv[1][2] != '\0')
        {   usage();
            exit(EXIT_FAILURE);
        }
        t0 = time(NULL);
        b = ctime(&t0);
/*
 * I format the date as "31-Mar-1992"
 */
        sprintf(today, "%.2s-%.3s-%.4s", b+8, b+4, b+20);
/*
 * My reading of the ANSI standard suggests that ctime should format
 * days of the month with leading zeros (if less than 10), but just in case
 * that is not how your C library does things I map a leading blank onto
 * an explicit zero here.
 */
        if (today[0] == ' ') today[0] = '0';
        if (argc == 3) update_in_place(argv[2]);
        else update_signature(argv[2], argv[3]);
    }
    else for (i=1; i<argc; i++) scan_directory(argv[i], verify_signature);

    return 0;
}

/* end of filesign.c */

