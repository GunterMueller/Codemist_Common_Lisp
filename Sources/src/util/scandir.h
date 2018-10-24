/*
 * scandir.h              Copyright (C) Codemist Ltd., 1994
 *
 *
 * Directory scanning code for use in CSL-related utilities.
 *
 *                        A C Norman
 */


/* Signature: 783648ba 16-Sep-1994 */


/*
 * If I am to process directories I need a set of routines that will
 * scan sub-directories for me. The specification I want is:
 *       int scan_directory(char *dir,
 *                    void (*proc)(char *name, int why, int32 size));
 *
 * This is called with a file- or directory-name as its first argument
 * and a function as its second.
 * It calls the function for every directory and every file that can be found
 * rooted from the given place.  If the file to scan is specified as NULL
 * the current directory is processed.
 * When a simple file is found the procedure is called with the name of the
 * file, why=0, and the length (in bytes) of the file.  For a directory
 * the function is called with why=1, then the contents of the directory are
 * processed. For directories the size information will be 0.  There is no
 * guarantee of useful behaviour if some of the files to be scanned are
 * flagged as  "invisible" or "not readable" or if they are otherwise special.
 * The value returned is the number of characters that should be removed
 * the start of file-names returned to get rid of any initial directory
 * specified.  If dir is passed as NULL this will be zero and names will
 * come back plain, otherwise it will be 1+strlen(dir)
 */

#define SCAN_FILE       0
#define SCAN_STARTDIR   1
#define SCAN_ENDDIR     2

extern void scan_directory(char *dir,
                           void (*proc)(char *name, int why, int32 size));

/*
 * When scan_directory calls the procedure it has been passed, it will have
 * set scan_leafstart to the offset in the passed filename where the
 * original direcytory ended and the new information starts.
 */

extern int scan_leafstart;

/* end of scandir.h */

