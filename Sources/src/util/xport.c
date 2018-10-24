/*
 * "export.c"                     Copyright (C) 1994, Codemist Ltd
 */

/* Signature: 4d6c2e03 08-Nov-1995 */

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

#include "sys.h"
#include "patmatch.h"

#include <stdarg.h>

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

void fatal_error(char *fmt, ...)
{
    va_list a;
    printf("\nFatal error: ");
    va_start(a, fmt);
    vfprintf(stdout, fmt, a);
    va_end(a);
    exit(EXIT_FAILURE);
}

void *Xmalloc(size_t n)
{
    void *p = malloc(n);
    if (p == NULL) fatal_error("no store");
    return p;
}

char today[16];
char timeofday[16];

static void get_todays_date()
{
    time_t t0 = time(NULL);
    char *b = ctime(&t0);
/*
 * I format the date as "31-Mar-1992" and the time as "01:21:59"
 */
    sprintf(today, "%.2s-%.3s-%.4s", b+8, b+4, b+20);
    sprintf(timeofday, "%.8s", b+11);
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

typedef struct stringlist
{
    char *name;
    struct stringlist *next;
} stringlist;

typedef struct patternlist
{
    int flag;
    stringlist *p;
    struct patternlist *next;
} patternlist;

stringlist *include, *omit, *text, *binary, *mixedcase;
patternlist *includeomit, *textbinary;

int should_omit(char *name)
{
    patternlist *p, *plast = NULL;
    for (p=includeomit; p!=NULL; p=p->next)
    {   stringlist *s;
        for (s=p->p; s!=NULL; s=s->next)
           if (wildmatch(s->name, name)) return (p->flag<0);
        plast = p;
    }
    return (plast!=NULL && plast->flag>=0);
}

int is_binary(char *name)
{
    patternlist *p;
    for (p=textbinary; p!=NULL; p=p->next)
    {   stringlist *s;
        for (s=p->p; s!=NULL; s=s->next)
           if (wildmatch(s->name, name)) return (p->flag<0);
    }
    return 0;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

char *localfilename(char *n)
{
    char name[LONGEST_LEGAL_FILENAME], *w;
    unadjust_file_name(name, n);
    w = (char *)Xmalloc(strlen(name)+1);
    strcpy(w, name);
    return w;
}

char *unixfilename(char *n)
{
    stringlist *s;
    char name[LONGEST_LEGAL_FILENAME], casename[LONGEST_LEGAL_FILENAME], *w;
    adjust_file_name(name, n);
/*
 * If I have listed some names as belonging in mixed case I apply that
 * transformation here.
 */
    for (s=mixedcase; s!=NULL; s=s->next)
    {   if (casefold_match(casename, s->name, name))
        {   strcpy(name, casename);
            break;
        }
    }
    w = (char *)Xmalloc(strlen(name)+1);
    strcpy(w, name);
    return w;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

static unsigned32 CRC;

static void update_CRC(int ch)
{
    unsigned32 CRCtemp = ((CRC & 0x01ffffff) << 7);
/*
 * This is my favourite hash function at present - it cycles a 31-bit shift
 * register with maximum period.  As used here the item mixed in (ch) will
 * always have been masked with 0xff.
 */
    CRC = ((CRC >> 25) ^      /* NB logical (not arithmetic) shift here */
           (CRCtemp >> 1) ^
           (CRCtemp >> 4) ^
           (unsigned32)ch) & 0x7fffffff;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

typedef struct list_of_files
{
    char *filename;
    char *unixname;
    int dirp;
    int binaryp;
    int newp;         /* +1 if new, -1 if deleted, 0 in standard case */
    long int size;
    int32 datestamp;
    int32 checksum;
    struct list_of_files *next;
} list_of_files;

list_of_files *previous = NULL, *current = NULL;
int how_many = 0;

list_of_files *reverse_list_of_files(list_of_files *p)
{
    list_of_files *r = NULL;
    while (p != NULL)
    {   list_of_files *p1 = p->next;
        p->next = r;
        r = p;
        p = p1;
    }
    return r;
}

/*
 * sortlist is a merge sort that destructively sorts the list of files
 * on the basis of their "unixname" fields. The order used is alphabetic
 * case insensitive, so that warnings can easily be generated for files
 * whose names only differ in case.
 */

int nameorder(char *n1, char *n2)
{
    for (;;)
    {   int c1 = *n1++, c2 = *n2++;
        if (c1 == 0) return 1;
        else if (c2 == 0) return 0;
        c1 = tolower(c1);
        c2 = tolower(c2);
        if (c1 != c2) return (c1 < c2);
    }
}

list_of_files *sortlist(list_of_files *p)
{
    list_of_files *p1 = NULL, *p2 = NULL, *w;
/* A base condition for the recursion */
    if (p == NULL || p->next == NULL) return p;
/* First I split the input list into two (almost) equally sized parts. */
    for (;;)
    {   if (p == NULL) break;
        w = p; p = p->next; w->next = p1; p1 = w;
        if (p == NULL) break;
        w = p; p = p->next; w->next = p2; p2 = w;
    }
/* Sort each of these */
    p1 = sortlist(p1);
    p2 = sortlist(p2);
/* Merge to make one ordered list */
    while (p1 != NULL && p2 != NULL)
    {   if (nameorder(p1->unixname, p2->unixname))
        {   w = p1; p1 = p1->next; w->next = p; p = w;
        }
        else
        {   w = p2; p2 = p2->next; w->next = p; p = w;
        }
    }
/* At the end I have built most of my output in reverse order, so fix it */
    if (p1 == NULL) p1 = p2;
    while (p != NULL)
    {   w = p; p = p->next; w->next = p1; p1 = w;
    }
    return p1;
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

int commandp(char *buffer, char *word)
{
    int c1, c2;
    while ((c2 = *word++) != 0)
    {   c1 = *buffer++;
        if (c1 == 0) return 0;
        c1 = tolower(c1);
        if (c1 != c2) return 0;
    }
    c1 = *buffer;
    return (c1 == ' ' || c1 == '\t' || c1 == 0);
}

stringlist *readnames(stringlist *l, char *b)
{
    int i, c = *b++;
    char name[LONGEST_LEGAL_FILENAME], *s;
    stringlist *w;
    while (c != 0)
    {   while (c == ' ' || c == '\t' || c == ',' || c == ';') c = *b++;
        i = 0;
        while (c != ' ' && c != '\t' && c != ',' && c != ';' && c != 0)
        {   name[i++] = c;
            c = *b++;
        }
        if (i == 0) continue;
        name[i] = 0;
        s = (char *)Xmalloc(i+1);
        strcpy(s, name);
        w = (stringlist *)Xmalloc(sizeof(stringlist));
        w->name = s;
        w->next = l;
        l = w;
    }
    return l;
}

void make_filename(char *buffer, char *where, char *leaf)
{
    if (where == NULL) strcpy(buffer, leaf);
    else sprintf(buffer, "%s%c%s", where, DIRECTORY_CHAR, leaf);
}

void read_patterns_file(char *where)
{
    char fname[LONGEST_LEGAL_FILENAME], line[LONGEST_LEGAL_FILENAME+16];
    int c;
    FILE *f1;
    include = omit = text = binary = mixedcase = NULL;
    includeomit = textbinary = NULL;
    make_filename(fname, where, "export.pat");
    f1 = fopen(fname, "r");
    if (f1 == NULL)
    {   printf("Warning - no file \"%s\" found\n", fname);
        return;
    }
    for (;;)
    {   int i = 0;
        for (;;)
        {   c = getc(f1);
            if (c == EOF || c == '\n')
            {   line[i] = 0;
                break;
            }
            else if (i == 0 && (c == ' ' || c == '\t')) continue;
            else if (i < sizeof(line)-1) line[i++] = c;
        }
        if (commandp(line, "include"))
        {   if (omit != NULL)
            {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
                p->flag = -1;
                p->p = omit;
                p->next = includeomit;
                includeomit = p;
                omit = NULL;
            }
            include = readnames(include, &line[7]);
        }
        else if (commandp(line, "omit"))
        {   if (include != NULL)
            {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
                p->flag = 1;
                p->p = include;
                p->next = includeomit;
                includeomit = p;
                include = NULL;
            }
            omit = readnames(omit, &line[4]);
        }
        else if (commandp(line, "text"))
        {   if (binary != NULL)
            {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
                p->flag = -1;
                p->p = binary;
                p->next = textbinary;
                textbinary = p;
                binary = NULL;
            }
            text = readnames(text, &line[4]);
        }
        else if (commandp(line, "binary"))
        {   if (text != NULL)
            {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
                p->flag = 1;
                p->p = text;
                p->next = textbinary;
                textbinary = p;
                text = NULL;
            }
            binary = readnames(binary, &line[6]);
        }
        else if (commandp(line, "mixedcase"))
            mixedcase = readnames(mixedcase, &line[9]);
        else if (i != 0 && line[0] != '#')
        {   strcpy(&line[32], "...");  /* truncate it for the message */
            printf("Unrecognized pattern line \"%s\"\n", line);
        }
        if (c == EOF) break;
    }
    fclose(f1);
    if (omit != NULL)
    {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
        p->flag = -1;
        p->p = omit;
        p->next = includeomit;
        includeomit = p;
    }
    if (include != NULL)
    {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
        p->flag = 1;
        p->p = include;
        p->next = includeomit;
        includeomit = p;
    }
    if (binary != NULL)
    {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
        p->flag = -1;
        p->p = binary;
        p->next = textbinary;
        textbinary = p;
    }
    if (text != NULL)
    {   patternlist *p = (patternlist *)Xmalloc(sizeof(patternlist));
        p->flag = 1;
        p->p = text;
        p->next = textbinary;
        textbinary = p;
    }
#ifdef DEBUG
    {   patternlist *pp;
        stringlist *ss;
        for (pp=includeomit; pp!=NULL; pp=pp->next)
        {   printf("Files to %s:\n", pp->flag > 0 ? "include" : "omit");
            for (ss=pp->p; ss!=NULL; ss=ss->next)
                printf("    %s\n", ss->name);
        }
        for (pp=textbinary; pp!=NULL; pp=pp->next)
        {   printf("Files in %s mode:\n", pp->flag > 0 ? "text" : "binary");
            for (ss=pp->p; ss!=NULL; ss=ss->next)
                printf("    %s\n", ss->name);
        }
        printf("Files with mixed case names:\n");
        for (ss=mixedcase; ss!=NULL; ss=ss->next)
            printf("    %s\n", ss->name);
    }
#endif
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

void read_list_of_old_files(char *explicit_filename, char *where)
{
    char fname[LONGEST_LEGAL_FILENAME];
    char headline[64];
    char *sample = "EXPORT: Signatures 10:45:18.12-Sep-1994 <@@DBBCEHKNBE>\n";
    FILE *f1;
    int i, dstamp, csum, dirp, binp;
    previous = NULL;
    if (explicit_filename) strcpy(fname, explicit_filename);
    else make_filename(fname, where, "export.chk");
    f1 = fopen(fname, "r");
    if (f1 == NULL)
    {   printf("Warning - no file \"%s\" found\n", fname);
        return;
    }
    for (i=0; i<60;)
    {   int c = getc(f1);
        headline[i++] = c;
        if (c == '\n') break;
    }
    headline[i] = 0; 
    if (i != strlen(sample) ||
        strncmp(headline, sample, 19) != 0)
    {   printf("File \"%s\" does not have correct header line\n", fname);
        fclose(f1);
        printf("%d vs %d\n", i, strlen(sample));
        return;
    }
    while (fscanf(f1, "%x %x %d %d %s\n", &dstamp, &csum, &dirp, &binp, fname) == 5)
    {   char *name1 = (char *)Xmalloc(strlen(fname)+1);
        list_of_files *list1 = (list_of_files *)Xmalloc(sizeof(list_of_files));
        strcpy(name1, fname);
        list1->unixname = name1;
        list1->filename = localfilename(name1);
        list1->dirp = dirp;
        list1->binaryp = binp;
        list1->newp = 0;
        list1->size = 0;
        list1->datestamp = dstamp;
        list1->checksum = csum;
        list1->next = previous;
        previous = list1;
    }
    fclose(f1);
    previous = reverse_list_of_files(previous);
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

/*
 * When scanning files I may have an extended path name that contains
 * a route to the directory that is being processed. I do not want to
 * include this part of the name in the lists I create. scan_leafstart
 * indicates how many characters are in this unwanted part -- see "scandir.h"
 */

/*
 * This gets called, with dirp a code to tell me if I have a directory or
 * a regular file to handle.  The size will be an APPROXIMATION to the
 * bulk of the file but will not be portable across systems (eg because
 * of the representation of end-of-line in text files).
 */

void record_one_file(char *name, int dirp, long int size)
{
    char *name1, *name2, *relname = name+scan_leafstart;
    char *unixname;
    list_of_files *list1;
    int newp = 0, w;
    date_and_type datestamp;
    if (strlen(name) <= scan_leafstart) return;
    unixname = unixfilename(relname);
    if (should_omit(unixname)) return;
    switch (dirp)
    {
case 0: how_many++;  /* I only count FILES not directories here */
case 1: name1 = (char *)Xmalloc(strlen(relname) + 1);
        name2 = unixname;
        list1 = (list_of_files *)Xmalloc(sizeof(list_of_files));
        strcpy(name1, relname);
        strcpy(name2, unixname);
        list1->filename = name1;
        list1->unixname = name2;
        list1->dirp = dirp;
        list1->binaryp = is_binary(unixname);
        list1->newp = 0;
        list1->size = size;
        put_fileinfo(&datestamp, name1);
        list1->datestamp = datestamp.date;
        list1->checksum = 0;
        list1->next = current;
        current = list1;
        break;
default:
        break;
    }
}

void find_existing_files(char *dir)
{
    current = NULL;
    scan_directory(dir, record_one_file);
    current = sortlist(current);
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

void compute_checksums(char *where, list_of_files *filep)
{
    list_of_files *fp;
    char filename[LONGEST_LEGAL_FILENAME];
    for (fp=filep; fp!=NULL;)
    {   char *mode = fp->binaryp ? RB_MODE : "r";
        FILE *f;
        char line[50], old_date[16];
        unsigned32 old_checksum, save_CRC;
        int found, n;
        make_filename(filename, where, fp->filename);
        if (fp->dirp) fp->checksum = 0;
        else 
        {   f = fopen(filename, mode);
            if (f == NULL) fp->checksum = 0;
            else
            {   int c;
                save_CRC = CRC = 1;
                found = 0;
                n = 0;
/*
 * If I find a character with a dodgy code I mark the file as being "binary".
 * This is not a guaranteed recipe for success, especially since if a
 * binary file was being read in text mode I may not see all the data in
 * it (consider an MSDOS file with first byte matching the code '^Z').
 * But maybe it is better than nothing. Also if in text mode I detect any
 * line constatint of the text that I use to mark file signatures, and I both
 * check at the end that the signature matches, and ignore the signature line
 * itself in the checksum calculation
 */
                while ((c = getc(f)) != EOF) 
                {   if ((c<7 || ((c & 0x80)!=0 && c!=0xa9 && c!=0xb8)) &&
                        !fp->binaryp) break;
                    update_CRC(c & 0xff);
                    if (!fp->binaryp && !found)
                    {   if (c == '\n')
                        {   line[n] = 0;
                            if (n == 37 &&
                                sscanf(line, "/* Signature: %lx %11s */",
                                       &old_checksum, old_date) == 2)
                                found = 1, CRC = save_CRC;
                            save_CRC = CRC;
                            n = 0;
                        }
                        else if (n < 40) line[n++] = c;
                    }
                }
                if (c != EOF)
                {   fp->binaryp = 1;
                    fclose(f);
                    printf("\"%s\" will be handled in binary mode\n",
                           fp->filename);
                    continue;  /* try again in binary mode */
                }
                fclose(f);
                if (found && CRC != old_checksum)
                    printf("File \"%s\" has checksum %.8x but is signed %.8x\n",
                           filename, CRC, old_checksum);
                fp->checksum = CRC;
            }
        }
        fp = fp->next;
    }
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

/*
 * This prints a 48-bit number using radix 32, with letters @ABC...
 * as digits. The intent of these is that the bit-pattern in the
 * representation mirrors that in the number. This rather assumes
 * ASCII code, but what is really required here is that 16 consecutive
 * character codes starting at ('A'-1) are all printable.
 */
 
void put_bits(char *bb, unsigned32 bit, unsigned32 bit1)
{
    int i;
    *bb++ = '<';
    for (i=0; i<12; i++)
    {   int n = (bit1 >> 12) & 0xf;
        *bb++ = 'A' + n - 1;
        bit1 = ((bit1 & 0xfff) << 4) | ((bit >> 28) & 0xf);
        bit = (bit & 0x0fffffff) << 4;
    }
    *bb++ = '>';
    *bb = 0;
}

void write_the_signatures(FILE *sigfile)
{
    char line[LONGEST_LEGAL_FILENAME+24], bb[20];
    unsigned32 basecheck, bitsin[49], bitsin1[49], bitsout[49], bit, bit1;
    int i, done[48];
    list_of_files *fp;
/*
 * Now I want to arrange that the overall checksum of this file is a fixed
 * value. I achieve this by working out the (linear) way that the checksum
 * depends on characters in a 12-place field, and then adjusting those
 * characters to make the overall checksum come out as I want it.
 */
    for (i=0; i<49; i++)
    {   char *p;
        int c;
        CRC = 1;
        bit = bit1 = 0;
        if (i < 32) bit = (1 << i);
        else if (i < 48) bit1 = (1 << (i-32));
        put_bits(bb, bit, bit1);
        bitsin[i] = bit, bitsin1[i] = bit1;
        sprintf(line, "EXPORT: Signatures %s.%s %s\n", today, timeofday, bb);
        p = line;
        while ((c = *p++) != 0) update_CRC(c & 0xff);
        for (fp=current; fp!=NULL; fp=fp->next)
        {   sprintf(line, "%.8x %.8x %d %d %s\n",
                    fp->datestamp, fp->checksum,
                    fp->dirp, fp->binaryp,
                    fp->unixname);
            p = line;
            while ((c = *p++) != 0) update_CRC(c & 0xff);
        }
        bitsout[i] = CRC;
    }
    basecheck = bitsout[48];
    for (i=0; i<48; i++)
    {   bitsout[i] ^= basecheck;
        done[i] = -1;
    }
    for (i=0; i<31; i++)  /* NB bit 31 of checksum == 0 always */
    {   int j, k;
        bit = (1 << i);
        for (j=0; j<48; j++)
            if ((bitsout[j] & bit) && done[j]<0) break;
        if (j == 48)
        {   printf("Bit %d not adjustable\n", i);
            continue;  /* This bit uncontrollable - WORRY */
        }
        done[j] = i;
        for (k=0; k<48; k++)
            if (k!=j && (bitsout[k] & bit))
            {   bitsin[k]  ^= bitsin[j];
                bitsin1[k] ^= bitsin1[j];
                bitsout[k] ^= bitsout[j];
            }
    }
    basecheck ^= 0x11111111;   /* The desired checksum */
    bit = bit1 = 0;
    for (i=0; i<32; i++)
    {   unsigned32 bit2 = (1 << i);
        int j;
        if ((basecheck & bit2) == 0) continue;
        for (j=0; j<48; j++)
            if (done[j] >= 0 && bitsout[j] == bit2) break;
        if (j == 48)
        {   printf("failed to force checksum of zero\n");
            exit(EXIT_FAILURE);
        }
        basecheck ^= bit2;
        bit  ^= bitsin[j];
        bit1 ^= bitsin1[j];
    }
    put_bits(bb, bit, bit1);
    fprintf(sigfile, "EXPORT: Signatures %s.%s %s\n", today, timeofday, bb);
    for (fp=current; fp!=NULL; fp=fp->next)
    {   fprintf(sigfile, "%.8x %.8x %d %d %s\n",
                fp->datestamp, fp->checksum,
                fp->dirp, fp->binaryp,
                fp->unixname);
    }
}

void make_signature_file(char *file, char *where)
{
    char signame[LONGEST_LEGAL_FILENAME];
    FILE *sigfile;
    read_patterns_file(where);
    find_existing_files(where);
    compute_checksums(where, current);
    if (file == NULL)
        make_filename(signame, where, "export.chk");
    else strcpy(signame, file);
    sigfile = fopen(signame, "w");
    if (sigfile == NULL)
    {   printf("Unable to write to \"%s\"\n", signame);
        exit(EXIT_FAILURE);
    }
    get_todays_date();
    write_the_signatures(sigfile);
    fclose(sigfile);
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

/*
 * previous and current are lists of files to compare.
 */

void report_differences()
{
    list_of_files *newfile = NULL, *lostfile = NULL, *changedfile = NULL;
    list_of_files *p = previous, *c = current;
    while (p && c)
    {   char *pn = p->unixname, *cn = c->unixname;
        if (strcmp(pn, cn) == 0)
        {   if (p->binaryp != c->binaryp)
                printf("Binary/text status changed for %s (now %s)\n", cn,
                       c->binaryp ? "binary" : "text");
            else if (p->checksum != c->checksum)
                printf("Changed %s\n", cn);
            p = p->next;
            c = c->next;
            continue;
        }
        if (nameorder(pn, cn))
        {   printf("Missing %s\n", pn);
            p = p->next;
        }
        else
        {   printf("Unwanted %s\n", cn);
            c = c->next;
        }
    }
    while (p)
    {   printf("Missing %s\n", p->unixname);
        p = p->next;
    }
    while (c)
    {   printf("Unwanted %s\n", c->unixname);
        c = c->next;
    }
}

void report_date_differences()
{
    list_of_files *newfile = NULL, *lostfile = NULL, *changedfile = NULL;
    list_of_files *p = previous, *c = current;
    while (p && c)
    {   char *pn = p->unixname, *cn = c->unixname;
        if (strcmp(pn, cn) == 0)
        {   if (p->binaryp != c->binaryp)
                printf("Binary/text status changed for %s (now %s)\n", cn,
                       c->binaryp ? "binary" : "text");
            else if (p->datestamp != c->datestamp)
                printf("Changed %s (%.8x %.8x)\n", cn, p->datestamp, c->datestamp);
            p = p->next;
            c = c->next;
            continue;
        }
        if (nameorder(pn, cn))
        {   printf("Missing %s\n", pn);
            p = p->next;
        }
        else
        {   printf("Unwanted %s\n", cn);
            c = c->next;
        }
    }
    while (p)
    {   printf("Missing %s\n", p->unixname);
        p = p->next;
    }
    while (c)
    {   printf("Unwanted %s\n", c->unixname);
        c = c->next;
    }
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

void send_archive_header(FILE *fp)
{
    get_todays_date();
    fprintf(fp, "\n");
    fprintf(fp, "# This is a shell archive.  Remove anything before this line, then\n");
    fprintf(fp, "# unpack it by saving it in a file and type \"sh file\". (Files\n");
    fprintf(fp, "# unpacked will be owned by you and have default permissions.)\n");
    fprintf(fp, "# [made by Codemist \"export\" package on %s at %s]\n",
                today, timeofday);
    fprintf(fp, "#\n");
}

void send_new_file(FILE *fp, char *unixname, char *filename, int binary)
{
    FILE *fp1 = fopen(filename, "r");
    int c0 = '\n', c;
    if (fp1 == NULL)
    {   printf("Unable to export \"%s\"\n", filename);
        return;
    }
    fprintf(fp, "echo x - %s\n", unixname);
    fprintf(fp, "if [ -f %s ]\n", unixname);
    fprintf(fp, "   then\n");
    fprintf(fp, "    mv %s \\\n", unixname);
    fprintf(fp, "       %s.old\n", unixname);
    fprintf(fp, "  else\n");
    fprintf(fp, "    echo  \"*** New file %s created\"\n", unixname);
    fprintf(fp, "fi\n");
    fprintf(fp, "cat > \"%s\" \\\n", unixname);
    fprintf(fp, "    << '//E*O*F %s//'\n", unixname);
    while ((c = getc(fp1)) != EOF) putc(c, fp), c0 = c;
    fclose(fp1);
    if (c0 != '\n') putc('\n', fp);
    fprintf(fp, "//E*O*F %s//\n\n", unixname);
}

void send_update_to(FILE *fp, char *unixname, char *filename, int binary)
{
    send_new_file(fp, unixname, filename, binary);
}

void send_delete(FILE *fp, char *unixname)
{
    fprintf(fp, "echo d - %s\n", unixname);
    fprintf(fp, "if [ -f %s ]\n", unixname);
    fprintf(fp, "   then\n");
    fprintf(fp, "    mv %s \\\n", unixname);
    fprintf(fp, "       %s.old\n", unixname);
    fprintf(fp, "  else\n");
    fprintf(fp, "    echo  \"*** File %s already deleted\"\n", unixname);
    fprintf(fp, "fi\n");
}

void send_new_signatures(FILE *fp)
{
    char *unixname = "export.chk";
    fprintf(fp, "echo x - %s\n", unixname);
    fprintf(fp, "if [ -f %s ]\n", unixname);
    fprintf(fp, "   then\n");
    fprintf(fp, "    mv %s \\\n", unixname);
    fprintf(fp, "       %s.old\n", unixname);
    fprintf(fp, "  else\n");
    fprintf(fp, "    echo  \"*** New file %s created\"\n", unixname);
    fprintf(fp, "fi\n");
    fprintf(fp, "cat > \"%s\" \\\n", unixname);
    fprintf(fp, "    << '//E*O*F %s//'\n", unixname);
    write_the_signatures(fp);
    fprintf(fp, "//E*O*F %s//\n\n", unixname);
}

void end_archive_file(FILE *fp)
{
    fprintf(fp, "exit 0\n");
    fclose(fp);
}

void ship_differences(char *filename)
{
    list_of_files *newfile = NULL, *lostfile = NULL, *changedfile = NULL;
    list_of_files *p = previous, *c = current;
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {   printf("File \"%s\" could not be opened\n", filename);
        exit(EXIT_FAILURE);
    }
    send_archive_header(fp);
    while (p && c)
    {   char *pn = p->unixname, *cn = c->unixname;
        if (strcmp(pn, cn) == 0)
        {   if (p->checksum != c->checksum ||
                p->binaryp != c->binaryp)
                send_update_to(fp, pn, c->filename, c->binaryp);
            p = p->next;
            c = c->next;
            continue;
        }
        if (nameorder(pn, cn))
        {   send_delete(fp, pn);
            p = p->next;
        }
        else
        {   send_new_file(fp, pn, c->filename, c->binaryp);
            c = c->next;
        }
    }
    while (p)
    {   send_delete(fp, p->unixname);
        p = p->next;
    }
    while (c)
    {   send_new_file(fp, c->unixname, c->filename, c->binaryp);
        c = c->next;
    }
    send_new_signatures(fp);
    end_archive_file(fp);
}

/*****************************************************************************
 *                                                                           *
 *****************************************************************************/

static void usage(void)
{
    printf("Usage:  export -key [file [directory]]\n");
    printf("  keys:    -sign     create signature file\n");
    printf("           -check    check against signature file\n");
    printf("           -dates    check only dates against sigantures\n");
    printf("           -ship     prepare update file for distribution\n");
}

#define ACT_SIGN   0
#define ACT_CHECK  1
#define ACT_DATES  2
#define ACT_SHIP   3

int main(int argc, char *argv[])
{
    char *key = "-check";
    char *file = NULL;
    char *where = NULL;
    int action;
/* I have come across silly systems that pad a NULL where it should not be */
    if (argv[argc-1] == NULL || argv[argc-1][0] == 0) argv--;
    switch (argc)
    {
case 4: where = argv[3];
case 3: file  = argv[2];
case 2: key   = argv[1];
case 1: break;
default:usage();
        exit(EXIT_FAILURE);
    }
    if (strcmp(key, "-check") == 0) action = ACT_CHECK;
    else if (strcmp(key, "-sign") == 0) action = ACT_SIGN;
    else if (strcmp(key, "-dates") == 0) action = ACT_DATES;
    else if (strcmp(key, "-ship") == 0) action = ACT_SHIP;
    else
    {   usage();
        exit(EXIT_FAILURE);
    }
    switch (action)
    {
case ACT_SIGN:
        make_signature_file(file, where);
        break;
case ACT_CHECK:
        read_list_of_old_files(file, where);
        read_patterns_file(where);
        find_existing_files(where);
        compute_checksums(where, current);
        report_differences();
        break;
case ACT_DATES:
        read_list_of_old_files(file, where);
        read_patterns_file(where);
        find_existing_files(where);
        report_date_differences();
        break;
case ACT_SHIP:
        /* NB -ship always compares against "export.chk" in the directory */
        read_list_of_old_files(NULL, where);
        read_patterns_file(where);
        find_existing_files(where);
        compute_checksums(where, current);
        ship_differences(file);
        break;
    }
    return 0;
}

/* end of export.c */

