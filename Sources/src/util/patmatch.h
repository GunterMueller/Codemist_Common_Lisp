/*
 * patmatch.h                 Copyright (C) Codemist Ltd 1994
 *
 *      Matching of file-names against wild-card patterns
 *
 *                            A C Norman
 */

/* Signature: 03cfbfee 14-Sep-1994 */

extern int wildmatch(char *pattern, char *filename);

extern int casefold_match(char *outname, char *pattern, char *filename);

/* End of patmatch.h */

