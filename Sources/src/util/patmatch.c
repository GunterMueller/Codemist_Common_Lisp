/*
 * patmatch.c                 Copyright (C) Codemist Ltd 1994
 *
 *      Matching of file-names against wild-card patterns
 *
 *                            A C Norman
 */

/* Signature: 573e6834 08-Nov-1995 */

#include "sys.h"
#include "patmatch.h"

/*
 * wildmatch(pattern, string) allows the pattern to contain '*' characters
 * which will match an arbitrary string of characters from the target
 * string, but NOT a directory separator character. Note that when this
 * is used filenames may be in Unix format so I can use "/" as a directory
 * separator, or they may be in DOS format with '\'.
 */

int wildmatch(char *pattern, char *filename)
{
    while (*pattern == *filename)
    {   if (*pattern == 0) return 1;
        pattern++;
        filename++;
    }
/*
 * I allow a pattern that is the name of a directory to match all
 * files in that directory.
 */
    if (*pattern == 0)
        return (*filename == 0 || *filename == '/' || *filename == '\\');
    if (*pattern == '*')
    {   while (*filename != 0 && *filename != '/' && *filename != '\\')
        {   if (wildmatch(pattern+1, filename+1)) return 1;
            filename++;
        }
        return 0;
    }
    return 0;
}

/*
 * casefold_match copies a name into the string (outname), and reports
 * if the pattern and the filename match in a case-insensitive manner.
 * If they do then then outname will end up with case filled in from
 * the pattern where possible, and 1 will be returned.
 */

int casefold_match(char *outname, char *pattern, char *filename)
{
    while (tolower(*pattern) == tolower(*filename))
    {   *outname++ = *pattern++;
        if (*filename++ == 0) return 1;
    }
/*
 * I allow a pattern that is the name of a directory to match all
 * files in that directory.
 */
    if (*pattern == 0)
    {   if (*filename != '/') return 0;
        strcpy(outname, filename);
        return 1;
    }
    if (*pattern == '*')
    {   while (*filename != 0 && *filename != '/')
        {   if (casefold_match(outname, pattern+1, filename)) return 1;
            *outname++ = *filename++;
        }
        return 0;
    }
    return 0;
}

/* End of patmatch.c */

