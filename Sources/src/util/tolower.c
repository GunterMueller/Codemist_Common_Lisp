
/*
 * Convert upper case to lower in a file
 * Also expands tabs
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* Signature: 00877b95 23-Aug-1994 */

int main(int argc, char *argv[])
{
    FILE *from, *to = stdout;
    int pos = 0;
    int ch;
    switch (argc)
    {
default:
        fprintf(stderr, "\nUsage:   tolower file [destination]\n");
        exit(1);
case 3:
        to = fopen(argv[2], "w");
        if (to == NULL)
        {   fprintf(stderr, "\nFile \'%s\' can not be opened\n", argv[2]);
            exit(1);
        }
        /* Drop through */
case 2:
        from = fopen(argv[1], "r");
        if (from == NULL)
        {   fprintf(stderr, "\nFile \'%s\' can not be opened\n", argv[1]);
            fclose(to);
            exit(1);
        }
        break;
    }

    while ((ch = getc(from)) != EOF)
    {   if (ch == '\t')
        {   do putc(' ', to), pos++; while ((pos & 7) != 0);
        }
        else
        {   if (ch == '\n') pos = 0;
            else pos++;
            putc(tolower(ch), to);
        }
    }

    fclose(from);
    fclose(to);
    return 0;
}

/* End of tolower.c */

