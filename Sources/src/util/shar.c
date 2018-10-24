
/*
 * "shar.c"
 *
 *
 * Utility to convert contents of a directory into one sequential file
 * with unpacking info for use with Unix "sh" included
 *
 * Use:
 *
 *     shar <destination> <source-dirs/files>
 *
 * If the set of source files is big this will create a sequence
 * of output files, with names obtained by modifying the given
 * destination name. 
 * Destination file should be given as xxx, then files actually used will
 * be xxx1.shr, xxx2.shr, xxx3.shr etc.
 */

/* Signature: 2281e6f9 13-Sep-1994 */

#include "sysopt.h"
#include "scandir.h"


#define SHARLIMIT 250000    /* largest single shar file */

#define NAME_SIZE 10000
static char *name_buff, *name_buff_p;

static int32 largest_file, total_bulk;

static void unadjust1(char *filename, char *old, int n)
{
    while (n-- >= 0)
    {   int c = *old++;
        if (c == '\\') c = '/';
        *filename++ = c;
    }
}

static void unadjust_file_name(char *filename, char *old, size_t n)
{
    unadjust1(filename, old, n);
    filename[n] = 0;
    return;
}

static void dumpint(int32 n)
{
    *name_buff_p++ = n & 0xff; n = n >> 8;
    *name_buff_p++ = n & 0xff; n = n >> 8;
    *name_buff_p++ = n & 0xff; n = n >> 8;
    *name_buff_p++ = n & 0xff;
}

void dumpstring(char *s)
{
    int32 n = strlen(s);
    dumpint(n);
    while (n-- > 0) *name_buff_p++ = *s++;
}

static void report_file(char *name, int dirp, int32 size)
{
    char namebuf[LONGEST_LEGAL_FILENAME];
    if (dirp != 0) return;
    unadjust_file_name(namebuf, name, strlen(name));
    dumpint(size);
    dumpstring(name);
    dumpstring(namebuf);
    if (size > largest_file) largest_file = size;
    total_bulk += size;
}

static void xmit(char *name, char *uname, FILE *dest, int32 size)
{
    FILE *source;
    int32 i;
    int c;
    printf("%s archived as %s, %ld bytes\n", name, uname, (long)size);
    fprintf(dest, "echo x - %s\n", uname);
    fprintf(dest, "if [ -f %s ]\n", uname);
    fprintf(dest, "   then\n");
    fprintf(dest, "     mv %s %s.old\n", uname, uname);
    fprintf(dest, "   else\n");
    fprintf(dest, "     echo \"*** New file %s created\"\n", uname);
    fprintf(dest, "fi\n");
    fprintf(dest, "cat > %s << '//E*O*F %s//'\n", uname, uname);

    source = fopen(name, "r");
    for (i = 0; i < size; i++)
    {   c = getc(source);
        if (c == EOF) break;
        putc(c, dest);
    }
    fclose(source);

    if (c != '\n') putc('\n', dest);
    fprintf(dest, "//E*O*F %s//\n\n", uname);
}

static int32 grabint()
{
    int32 a1, a2, a3, a4;
    a1 = 0xff & *name_buff_p++;
    a2 = 0xff & *name_buff_p++;
    a3 = 0xff & *name_buff_p++;
    a4 = 0xff & *name_buff_p++;
    return a1 | (a2 << 8) | (a3 << 16) | (a4 << 24);
}

static void grabstring(char *s)
{
    int32 len = grabint();
    while (len-- > 0) *s++ = *name_buff_p++;
    *s = 0;
}

static int send_files(char *basename, int seqno)
{
    char name[LONGEST_LEGAL_FILENAME];
    char uname[LONGEST_LEGAL_FILENAME];
    FILE *dest;
    char *p;
    int32 size, bulk;
    sprintf(name, "%s%d.shr", basename, seqno);
    dest = fopen(name, "w");
    if (dest == NULL)
    {   fprintf(stderr, "Unable to open %s for output\n", name);
        exit(0);
    }

    printf("========== Create:  %s\n", name);

    fprintf(dest, "\n");
    fprintf(dest, "# This is a shell archive.  Remove anything before this line, then\n");
    fprintf(dest, "# unpack it by saving it in a file and type \"sh file\". (Files\n");
    fprintf(dest, "# unpacked will be owned by you and have default permissions.)\n");
    fprintf(dest, "#\n# This archive contains:\n");

    p = name_buff_p;

    bulk = grabint();
    if (bulk < 0) return 0;

    grabstring(name);
    grabstring(uname);
    fprintf(dest, "#     %s\n", uname);

    for (;;)
    {   size = grabint();
        if (size < 0 || (bulk+size) > SHARLIMIT) break;
        grabstring(name);
        grabstring(uname);
        fprintf(dest, "#     %s\n", uname);
        bulk += size;
    }
    fprintf(dest, "#\n\n");

    name_buff_p = p;

    bulk = grabint();
    grabstring(name);
    grabstring(uname);
    xmit(name, uname, dest, bulk);

    for (;;)
    {   size = grabint();
        if (size < 0 || (bulk+size) > SHARLIMIT) break;
        grabstring(name);
        grabstring(uname);
        xmit(name, uname, dest, size);
        bulk += size;
    }

    fprintf(dest, "exit 0\n");
    fclose(dest);

    name_buff_p -= 4;
    return (size >= 0);
}

int main(int argc, char *argv[])
{
    int i;
    
    name_buff = malloc(NAME_SIZE);
    name_buff_p = name_buff;
    if (name_buff == NULL)
    {   fprintf(stderr, "Insufficient memory\n");
        return 1;
    }

#define destfile argv[1]

    if (argc < 3)
    {   fprintf(stderr, "Usage:  shar <destination-file> <source-directory>\n");
        exit(0);
    }

    largest_file = total_bulk = 0;
    for (i=2; i<argc; i++)
      if (argv[i] != NULL)
        scan_directory(argv[i], report_file);
    dumpint(-1);    /* to mark the list */
    printf("About %ld bytes of data to be included in the archive\n",
           (long)total_bulk);

    i = 1;
    name_buff_p = name_buff;
    while (send_files(destfile, i)) i++;

    printf("%d files created, total size %ld, biggest sub-file %ld\n",
           i, (long)total_bulk, (long)largest_file);
    
    return 0;

}

/* End of shar.c */

