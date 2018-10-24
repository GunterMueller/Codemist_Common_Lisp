
/* Checksums a file */

#include <stdio.h>

/*
 *   checksum [-b] <filename>
 *
 *    Prints a checksum value.
 *    If -b is specified the file is read in binary
 */

/* Signature: 514ba8fd 18-Sep-1995 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long int unsigned32;

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

int main(int argc, char *argv[])
{
    int c;
    char *file = NULL, *openmode = "r";
    char line[50], old_date[16];
    unsigned32 old_checksum, save_CRC;
    int found, n, binary = 0;
    if (argv[argc-1] == NULL || argv[argc-1][0] == 0) argc--;
    switch (argc)
    {
case 1: break;
case 2: file = argv[1];
        if (file[0] == 0)
        {   printf("checksum [-b] file\n");
            exit(0);
        }
        break;
case 3: if (strcmp(argv[1], "-b") == 0)
        {   openmode = "rb";
            binary = 1;
            file = argv[2];
            break;
        }
default:
        printf("checksum [-b] file\n");
        exit(0);
    }
    if (file)
    {   if (freopen(file, openmode, stdin) == NULL)
        {   printf("File \"%s\" could not be accessed\n", file);
            exit(0);
        }
    }
    else file = "<stdin>";
    for (;;)        /* In case it was a binary file and I had not said -b */
    {   save_CRC = CRC = 1;
        found = 0;
        n = 0;
        while ((c = getchar()) != EOF) 
        {   if ((c<7 || ((c&0x80)!=0 && c!=0xa9 && c!=0xb8)) && !binary) break;
            update_CRC(c & 0xff);
            if (!binary && !found)
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
        if (c == EOF) break;
        printf("File \"%s\" seems to contain binary\n", file);
        binary = 1;
        if (freopen(file, "rb", stdin) == NULL)
        {   printf("File \"%s\" could not be accessed\n", file);
            exit(0);
        }
    }
    if (found && CRC != old_checksum)
        printf("File \"%s\" has checksum %.8lx but is signed %.8lx\n",
               file, (unsigned long int)CRC, (unsigned long int)old_checksum);
    else printf("File \"%s\": %.8lx\n", file, (unsigned long int)CRC);
    return 0;
}

/* End of checksum.c */
