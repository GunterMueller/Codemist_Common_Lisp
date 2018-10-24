
#include <stdio.h>

/* Signature: 3f87be22 23-Aug-1994 */

int main(int argc, char *argv[])
{
    FILE *in, *out;
    int c, i, lines = 1, toolong = 0, longest = -1;
    if (argc < 3)
    {   fprintf(stderr, "Usage: longline <source> <destination>\n");
        return 1;
    }
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    if (in == NULL)
    {   fprintf(stderr, "Input %s could not be accessed\n", argv[1]);
        return 1;
    }
    if ( out == NULL)
    {   fprintf(stderr, "Output %s cound not be accessed\n", argv[2]);
        return 1;
    }
    i = 0;
    while ((c = getc(in)) != EOF)
    {   if (c == '\n')
        {   if (i > longest) longest = i;
            i = 0;
            lines++;
        }
        else if (i == 80) putc('@', out), i++, toolong++;
        else i++;
        putc(c, out);
    }
    fclose(in);
    fclose(out);
    fprintf(stderr, "%d lines, %d overlong, longest = %d\n",
                    lines, toolong, longest);
    return 0;
}


