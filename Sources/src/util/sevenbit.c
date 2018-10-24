
/*
 * Strips chars to just 7 bits.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* Signature: 23c20d83 18-Sep-1995 */

int main(int argc, char *argv[])
{
    FILE *from, *to = stdout;
    int pos = 0;
    int ch;
    switch (argc)
    {
default:
        fprintf(stderr, "\nUsage:   savenbit file [destination]\n");
        exit(1);
case 3:
        to = fopen(argv[2], "w");
        if (to == NULL)
        {   fprintf(stderr, "\nFile \'%s\' can not be opened\n", argv[2]);
            exit(1);
        }
        /* Drop through */
case 2:
        from = fopen(argv[1], "rb");
        if (from == NULL)
        {   fprintf(stderr, "\nFile \'%s\' can not be opened\n", argv[1]);
            fclose(to);
            exit(1);
        }
        break;
    }

    while ((ch = getc(from)) != EOF)
    {   ch &= 0x7f;
        if (ch == 0xa || ch == 0xd) pos = 0; else pos++;
        if (pos > 128) putc('\n', to), pos = 0;
        if (ch == 0x7f) ch = '#';
        else if (ch < 0x20)
        {   if (ch != 0xa && ch != 0xd && ch != 0x9) ch = ' ';
        }
        putc(ch, to);
    }
    fclose(from);
    fclose(to);
    return 0;
}

/* End of sevenbit.c */

