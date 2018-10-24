/*
 * scandir.c              Copyright (C) Codemist Ltd., 1994-96
 *
 *
 * Directory scanning code for use in CSL-related utilities.
 *
 *                        A C Norman
 */


/* Signature: 0a8ca40b 12-Jun-1996 */

#include "sys.h"

/*
 * If I am to process directories I need a set of routines that will
 * scan sub-directories for me.  This is (necessarily?) dependent on
 * the operating system I am running under, hence the conditional compilation
 * here.  The specification I want is:
 *       void scan_directory(char *dir,
 *                    void (*proc)(char *name, int why, long int size));
 *
 * This is called with a file- or directory-name as its first argument
 * and a function as its second.
 * It calls the function for every directory and every file that can be found
 * rooted from the given place.  If the file to scan is specified as NULL
 * the current directory is processed. I also arrange that an input string
 * "." (on Windows, DOS and Unix) or "@" (Archimedes) is treated as a request
 * to scan the whole of the current directory.
 * When a simple file is found the procedure is called with the name of the
 * file, why=0, and the length (in bytes) of the file.  For a directory
 * the function is called with why=1, then the contents of the directory are
 * processed. For directories the size information will be 0.  There is no
 * guarantee of useful behaviour if some of the files to be scanned are
 * flagged as  "invisible" or "not readable" or if they are otherwise special.
 *
 * I also provide a similar function scan_files() with the same arguments that
 * does just the same except that it does not recurse into sub-directories,
 * but if the name originally passed is that of a directory then all the
 * files in it will be scanned.
 */

/*
 * When scan_directory calls the procedure it has been passed, it will have
 * set scan_leafstart to the offset in the passed filename where the
 * original directory ended and the new information starts.
 */

int scan_leafstart = 0;

/* #define SCAN_FILE       0 */  /* In scandir.h - listed here for emphasis */
/* #define SCAN_STARTDIR   1 */
/* #define SCAN_ENDDIR     2 */

/*
 * I use a (static) flag to indicate how sub-directories should be
 * handled.
 */

static int recursive_scan;

void *
realloc_wnull(void *p, int len)
{
  if (!p) return malloc(len);
  return realloc(p, len);
}


#ifdef WINDOWS_NT

/*
 * Note that I put the test for WINDOWS_NT before the test for MS_DOS
 * so that if it happens that the symbol MS_DOS is defined that fact will
 * not cause too much confusion.
 */

static char filename[LONGEST_LEGAL_FILENAME];

static WIN32_FIND_DATA *found_files = NULL;
static int n_found_files = 0, max_found_files = 0;

#define TABLE_INCREMENT 50

static int more_files()
{
    if (n_found_files > max_found_files - 5)
    {   WIN32_FIND_DATA *fnew = (WIN32_FIND_DATA *)
            realloc_wnull((void *)found_files,
                    sizeof(WIN32_FIND_DATA)*
                           (max_found_files + TABLE_INCREMENT));
        if (fnew == NULL) return 1;  /* failure flag */
        found_files = fnew;
        max_found_files += TABLE_INCREMENT;
    }
    return 0;
}

int alphasort_files(const void *a, const void *b)
{
    const WIN32_FIND_DATA *fa = (const WIN32_FIND_DATA *)a,
                          *fb = (const WIN32_FIND_DATA *)b;
    return strncmp(fb->cFileName, fa->cFileName, sizeof(fa->cFileName));
}

static void exall(int namelength,
                  void (*proc)(char *name, int why, long int size))
/*
 * This procedure scans a directory-full of files, calling the given procedure
 * to process each one it finds.
 */
{
    WIN32_FIND_DATA found;
    int rootlen = namelength, first = n_found_files;
    HANDLE hSearch = FindFirstFile(filename, &found);
    if (hSearch == INVALID_HANDLE_VALUE) return;  /* No files found at all */
    for (;;)
    {   if (more_files()) break;
        found_files[n_found_files++] = found;
        if (!FindNextFile(hSearch, &found)) break;
    }
    FindClose(hSearch);
    qsort((void *)&found_files[first],
          n_found_files-first,
          sizeof(WIN32_FIND_DATA),
          alphasort_files);
    while (rootlen>=0 && filename[rootlen]!='\\') rootlen--;
    while (n_found_files != first)
    {   char *p = (char *)&found_files[--n_found_files].cFileName;
        int c;
/*
 * Fill out filename with the actual name I grabbed, i.e. with
 * wildcards expanded.
 */
        namelength = rootlen+1;
/*
 * I fold DOS filenames into lower case because it does not matter much
 * to DOS and I think it looks better - furthermore it helps when I move
 * archives to other systems.  So I do the same on NT.
 */
        while ((c = *p++) != 0)
        {   if (isupper(c)) c = tolower(c);
            filename[namelength++] = c;
        }
        filename[namelength] = 0;
        if (found_files[n_found_files].dwFileAttributes &
            FILE_ATTRIBUTE_DIRECTORY)
        {   if (found_files[n_found_files].cFileName[0] != '.')
/*
 * I filter out directory names that start with '.'.
 * This is to avoid calamity with recursion though chains such as .\.\.\.....
 */
            {   proc(filename, SCAN_STARTDIR, 0);
                if (!recursive_scan) continue;

                strcpy(&filename[namelength], "\\*.*");
/*
 * Append "\*.*" to the directory-name and try again, thereby scanning
 * its contents.
 */
                exall(namelength+4, proc);
                filename[namelength] = 0;
                proc(filename, SCAN_ENDDIR, 0);
            }
        }
        else proc(filename, SCAN_FILE,
                  found_files[n_found_files].nFileSizeLow);
    }
    return;
}

void scan_directory(char *dir,
                    void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 1;
    if (dir==NULL || strcmp(dir,".")==0)
    {   dir = "*.*";
        scan_leafstart = 0;
    }
    else scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    exall(strlen(filename), proc);
}

void scan_files(char *dir,
                void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 0;
    if (dir==NULL || strcmp(dir,".")==0)
    {   strcpy(filename, "*.*");
        scan_leafstart = 0;
    }
    else 
    {   scan_leafstart = strlen(dir);
        strcpy(filename, dir);
        if (filename[scan_leafstart-1] == '\\'){
	    /* Root directory */
            strcpy(filename+scan_leafstart, "*.*");
	    --scan_leafstart;
	}
        else
            strcpy(filename+scan_leafstart, "\\*.*");
        scan_leafstart++;
    }
    exall(strlen(filename), proc);
}

#define SCANDIR_KNOWN 1

#else  /* WINDOWS_NT */

#ifdef MS_DOS

/*
 * This will be OK for Watcom C in dos4gw mode. It will need
 * adjustment for use with other C compilers.
 */

static char filename[LONGEST_LEGAL_FILENAME];

static struct find_t *found_files = NULL;
static int n_found_files = 0, max_found_files = 0;

#define TABLE_INCREMENT 50

static int more_files()
{
    if (n_found_files > max_found_files - 5)
    {   struct find_t *fnew = (struct find_t *)
            realloc_wnull((void *)found_files,
                    sizeof(struct find_t)*(max_found_files + TABLE_INCREMENT));
        if (fnew == NULL) return 1; /* failure flag */
        found_files = fnew;
        max_found_files += TABLE_INCREMENT;
    }
    return 0;
}

int alphasort_files(const void *a, const void *b)
{
    const struct find_t *fa = (const struct find_t *)a,
                      *fb = (const struct find_t *)b;
    return strncmp(fb->name, fa->name, sizeof(fa->name));
}

static void exall(int namelength,
                  void (*proc)(char *name, int why, long int size))
/*
 * This procedure scans a directory-full of files, calling the given procedure
 * to process each one it finds.
 */
{
    int rootlen = namelength;
    int code, first = n_found_files;
    struct find_t found;
    code = _dos_findfirst(filename, _A_SUBDIR, &found);
    while (code == 0)
    {   if (more_files()) break;
        found_files[n_found_files++] = found;
        code = _dos_findnext(&found);
    }
    qsort((void *)&found_files[first],
          n_found_files-first,
          sizeof(struct find_t),
          alphasort_files);
    while (rootlen>=0 && filename[rootlen]!='\\') rootlen--;
    while (n_found_files != first)
    {   char *p = (char *)&found_files[--n_found_files].name;
        int c;
/*
 * Fill out filename with the actual name I grabbed, i.e. with
 * wildcards expanded.
 */
        namelength = rootlen+1;
/*
 * I fold DOS filenames into lower case because it does not matter much
 * to DOS and I think it looks better - furthermore it helps when I move
 * archives to other systems.
 */
        while ((c = *p++) != 0)
        {   if (isupper(c)) c = tolower(c);
            filename[namelength++] = c;
        }
        filename[namelength] = 0;
        if (found_files[n_found_files].attrib & _A_SUBDIR)
        {   if (found_files[n_found_files].name[0] != '.')
/*
 * I filter out directory names that start with '.'.
 * This is to avoid calamity with recursion though chains such as .\.\.\.....
 */
            {   proc(filename, SCAN_STARTDIR, 0);
                if (!recursive_scan) continue;

                strcpy(&filename[namelength], "\\*.*");
/*
 * Append "\*.*" to the directory-name and try again, thereby scanning
 * its contents.
 */
                exall(namelength+4, proc);
                filename[namelength] = 0;
                proc(filename, SCAN_ENDDIR, 0);
            }
        }
        else proc(filename, SCAN_FILE, found_files[n_found_files].size);
    }
    return;
}

void scan_directory(char *dir,
                    void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 1;
    if (dir==NULL || strcmp(dir,".")==0)
    {   dir = "*.*";
        scan_leafstart = 0;
    }
    else scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    exall(strlen(filename), proc);
}

void scan_files(char *dir,
                void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 0;
    if (dir==NULL || strcmp(dir,".")==0)
    {   strcpy(filename, "*.*");
        scan_leafstart = 0;
    }
    else 
    {   scan_leafstart = strlen(dir);
        strcpy(filename, dir);
        strcpy(filename+scan_leafstart, "\\*.*");
        scan_leafstart++;
    }
    exall(strlen(filename), proc);
}

#define SCANDIR_KNOWN 1

#else  /* MS_DOS */

#ifdef UNIX

static char filename[LONGEST_LEGAL_FILENAME];

/*
 * The code here uses opendir, readdir and closedir and as such ought to
 * be Posix compatible. The macro USE_DIRECT_H can cause an older variant
 * on this idea to be used. BUt it may need adjustment for different
 * systems.
 */

#ifdef USE_DIRECT_H
#include <sys/types.h>
#include <sys/dir.h>
#else
#include <dirent.h>
#endif

static char **found_files = NULL;

int n_found_files = 0, max_found_files = 0;

#define TABLE_INCREMENT 50

static int more_files()
{
    if (n_found_files > max_found_files - 5)
    {   char **fnew = (char **)
            realloc_wnull((void *)found_files,
                    sizeof(char *)*(max_found_files + TABLE_INCREMENT));
        if (fnew == NULL) return 1;  /* failure flag */
        found_files = fnew;
        max_found_files += TABLE_INCREMENT;
    }
    return 0;
}

int alphasort_files(const void *a, const void *b)
{
    const char *fa = *(const char **)a,
               *fb = *(const char **)b;
    return strcmp(fb, fa);
}

extern int stat(const char *, struct stat*);
static void scan_file(int namelength,
                      void (*proc)(char *name, int why, long int size));

static void exall(int namelength,
                  void (*proc)(char *name, int why, long int size))
{
    DIR *d;
#ifdef USE_DIRECT_H
    struct direct *dd;
#else
    struct dirent *dd;
#endif
    int i, j;
    int rootlen = namelength, first = n_found_files;
    proc(filename, SCAN_STARTDIR, 0);
    d = opendir(filename);
    if (d != NULL)
    {   while ((dd = readdir(d)) != NULL)
        {   char *leafname = dd->d_name; 
            char *copyname;
/*
 * readdir hands back both "." and ".." but I had better not recurse
 * into either!
 */
            if (strcmp(leafname, ".") == 0 ||
                strcmp(leafname, "..") == 0) continue;
            if (more_files()) break;
            copyname = (char *)malloc(1+strlen(leafname));
            if (copyname == NULL) break;
            strcpy(copyname, leafname);
            found_files[n_found_files++] = copyname;
        }
    }

    qsort((void *)&found_files[first],
          n_found_files-first,
          sizeof(char *),
          alphasort_files);

    filename[rootlen] = '/';
    while (n_found_files != first)
    {   char *p = found_files[--n_found_files];
        int c;
        namelength = rootlen+1;
        while ((c = *p++) != 0) filename[namelength++] = c;
        free((void *)found_files[n_found_files]);
        filename[namelength] = 0;
        scan_file(namelength, proc);
    }

    filename[rootlen] = 0;
    proc(filename, SCAN_ENDDIR, 0);
}

static void scan_file(int namelength,
                      void (*proc)(char *name, int why, long int size))
{
    struct stat buf;
    stat(filename, &buf);
    if ((buf.st_mode & S_IFMT) == S_IFDIR)
    {   if (!recursive_scan) proc(filename, SCAN_STARTDIR, 0);
        else exall(namelength, proc);
    }
    else if ((buf.st_mode & S_IFMT) == S_IFREG)
        proc(filename, SCAN_FILE, buf.st_size);
/*  else fprintf(stderr, "Mode of %s is %o\n", filename, buf.st_mode); */
}

void scan_directory(char *dir,
                    void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 1;
    if (dir==NULL || strcmp(dir, ".")==0) dir = ".";
    scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    scan_file(scan_leafstart-1, proc);
}

void scan_files(char *dir,
                void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 0;
    if (dir==NULL || strcmp(dir, ".")==0) dir = ".";
    scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    exall(scan_leafstart-1, proc);
}

#define SCANDIR_KNOWN 1

#else /* UNIX */

#ifdef __arm

/*
 * I want to be able to find the currently-selected directory - if
 * only so I can restore it at the end of processing.  Yes I do know
 * that RISCOS is moving away from the concept of a current directory,
 * but this is a command-line utility at present, at least.
 */

static void find_current_directory(char dir[])
{
    os_gbpbstr block;
    char drivename[64];
    char name[32];
/*
 * osgbpb(5) reads the name of the current disc - which I need as the first
 * part of a full-rooted file-path.
 */
    block.action = 5;
    block.file_handle = 0;
    block.data_addr = drivename;
    os_gbpb(&block);
    for (;;)
    {   int len;
/*
 * osgbpb(6) reads the name of the currently selected directory - but just
 * the trailing component.
 */
        block.action = 6;
        block.file_handle = 0;
        block.data_addr = name;
        os_gbpb(&block);
        len = name[1];
        /* Here I trim trailing blanks from the name */
        while (name[len + 1] == ' ' && len > 0) len--;
        if (dir[0] == 0)
        {   memcpy(dir, &name[2], len);
            dir[len] = 0;
        }
        else
        {   memmove(&dir[1 + len], dir, strlen(dir) + 1);
            memcpy(dir, &name[2], len);
            dir[len] = '.';
        }
/*
 * When I find that the director name is '$' I conclude that I must be
 * at the top of the tree, and I exit.
 */
        if (len == 1 && name[2] == '$')
        {   len = drivename[0];
            memmove(&dir[2 + len], dir, strlen(dir) + 1);
            memcpy(&dir[1], &drivename[1], len);
            dir[0] = ':';
            dir[len+1] = '.';
            return;
        }
/*
 * Mostly I select the parent directory, and by reading names of
 * successive parents I build up a complete name.
 */
        system("dir ^");
    }
}

#define AT_ONCE                 80
#define NAME_LENGTH             12

static char filename[LONGEST_LEGAL_FILENAME];
static char dirsave[LONGEST_LEGAL_FILENAME+4];
            /* Original directory the user had selected */

static void exall(int namelength,
                  void (*proc)(char *name, int why, long int size))
/*
 * This procedure scans a directory-full of files, calling the given procedure
 * to process each one it finds.
 */
{
    os_filestr file_status;
/*
 * osfile(5) reads information about a file - in particular it allows me to
 * tell if I have a simple file or a directory.
 */
    file_status.action = 5;
    file_status.name = filename;
    if (os_file(&file_status) != NULL) file_status.action = 99;
    switch (file_status.action)
    {
default:
/*      fprintf(stderr, "\nBad return code from osfile\n");    */
        return;
/* case 0: fprintf(stderr, "\nFile %s not found\n", filename); */
/*         exit(EXIT_FAILURE);                                 */
case 0xff:                                                /* Protected file */
case 1: proc(filename, SCAN_FILE, file_status.start);     /* Simple file */
        return;
case 2: /* Here we have a directory to scan */
        proc(filename, SCAN_STARTDIR, 0);
        if (!recursive_scan) return;

        {   char workvec[NAME_LENGTH*AT_ONCE];
            os_gbpbstr block;
            block.seq_point = 0;
            for (;;)
            {   char *p = workvec;
                block.action = 9;
                block.file_handle = (int)filename;/* Scan given directory */
                block.data_addr = workvec;
                block.number = AT_ONCE;
                block.buf_len = NAME_LENGTH*AT_ONCE;
                block.wild_fld = "*";
                filename[namelength] = 0;
/*
 * osgbpb(9) reads (several) file-names from the specified directory.
 */
                os_gbpb(&block);
                if (block.number == 0) break;     /* Nothing transfered */
                while (block.number != 0)
                {   int len = strlen(p);
                    filename[namelength] = '.';
                    strcpy(&filename[namelength+1], p);
                    p += len + 1;
/*
 * I concatenate the name of the new directory on the end of my current path
 * and recurse into it.
 */
                    exall(namelength + len + 1, proc);
                    block.number--;
                }
                if (block.seq_point == -1) break;
            }

            filename[namelength] = 0;
        }
        proc(filename, SCAN_ENDDIR, 0);
        return;
    }
}

void scan_directory(char *dir,
                    void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 1;
    strcpy(dirsave, "dir ");
    find_current_directory(dirsave+4);  /* Find initial directory */
    system(dirsave);                    /* Restore initial directory */
    strcpy(filename, dir==NULL ? "@" : dir);
    scan_leafstart = strcmp(dir, "@")==0 ? 2 : 0;
    exall(strlen(filename), proc);
    system(dirsave);                    /* Restore initial directory */
}

void scan_files(char *dir,
                void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 0;
    strcpy(dirsave, "dir ");
    find_current_directory(dirsave+4);  /* Find initial directory */
    system(dirsave);                    /* Restore initial directory */
    strcpy(filename, dir==NULL ? "@" : dir);
    scan_leafstart = strcmp(dir, "@")==0 ? 2 : 0;
    exall(strlen(filename), proc);
    system(dirsave);                    /* Restore initial directory */
}

#define SCANDIR_KNOWN 1

#else /* __arm */

#ifdef ATARI

static char filename[LONGEST_LEGAL_FILENAME];

static void exall(int32 namelength,
                  void (*proc)(char *name, int why, long int size))
/*
 * This procedure scans a directory-full of files, calling the given procedure
 * to process each one it finds.
 */
{
    int32 rootlen = namelength;
    int code;
    struct FILEINFO found;

    code = dfind(&found, filename, FA_DIREC);
    while (rootlen>=0 && filename[rootlen]!='\\') rootlen--;
/*
 * If I used _dos_findfirst I could allow recursion here,
 * and if I call findfirst(filename, FA_DIREC) then directories can
 * be found as well as just files.
 */
    while (code == 0)
    {   char *p = (char *)&found.name;
        int c;
/*
 * Fill out filename with the actual name I grabbed, i.e. with
 * wildcards expanded.
 */
        namelength = rootlen+1;
/*
 * I fold Atari filenames into lower case because it does not matter much
 * to Atari and I think it looks better - furthermore it helps when I move
 * archives to other systems.
 */
        while ((c = *p++) != 0) filename[namelength++] = tolower(c);
        filename[namelength] = 0;
        if (found.attr & FA_DIREC)
        {   if (found.name[0]!='.')
/*
 * I filter out directory names that start with '.'.
 * This is to avoid calamity with recursion though chains such as .\.\.\.....
 */
            {   proc(filename, SCAN_STARTDIR, 0);
                if (!recursive_scan) continue;

                strcpy(&filename[namelength], "\\*.*");
/*
 * Append "\*.*" to the directory-name and try again, thereby scanning
 * its contents.
 */
                exall(namelength+4, proc);
                filename[namelength] = 0;
                proc(filename, SCAN_ENDDIR, 0);
            }
        }
        else proc(filename, SCAN_FILE, found.size);
        code = dnext(&found);
    }
    return;
}

void scan_directory(char *dir,
                    void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 1;
    if (dir==NULL || strcmp(dir,".")==0)
    {   dir = "*.*";
        scan_leafstart = 0;
    }
    else scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    exall(strlen(filename), proc);
}

void scan_files(char *dir,
                void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 0;
    if (dir==NULL || strcmp(dir,".")==0)
    {   dir = "*.*";
        scan_leafstart = 0;
    }
    else scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    exall(strlen(filename), proc);
}

#define SCANDIR_KNOWN 1

#else  /* ATARI */
#ifdef macintosh
/*
 * I have place-holder routines here, so that at some stage proper versions
 * can be written and installed. By leaving the Unix code in as comment I hope
 * to help whoever gets around to building the Macintosh-specific versions...
 */

static char filename[LONGEST_LEGAL_FILENAME];

#ifdef THIS_NEEDS_RE_WRITING_FOR_MACINTOSH
static int remove_dot(struct direct *name)
{
  if (strcmp(name->d_name, ".")==0 || strcmp(name->d_name, "..")==0) return 0;
  return 1;
}
#endif

/* int alphasort(struct direct **, struct direct **);  */
/* extern int stat(const char *, struct stat*);        */

static void scan_file(int namelength,
                      void (*proc)(char *name, int why, long int size));

static void exall(int namelength,
                  void (*proc)(char *name, int why, long int size))
{
#ifdef THIS_NEEDS_RE_WRITING_FOR_MACINTOSH
    struct direct **namelist;
    int i, j;
    proc(filename, SCAN_STARTDIR, 0);
    if (!recursive_scan) return;

    i = scandir(filename, &namelist, remove_dot, alphasort);
    for(j=0; j<i; j++)
    {   char *leafname = namelist[j]->d_name;
        filename[namelength] = '/';
        strcpy(&filename[namelength+1], leafname);
        scan_file(namelength+1+strlen(leafname), proc);
        free(namelist[j]);
    }
    free(namelist);
    filename[namelength] = 0;
    proc(filename, SCAN_ENDDIR, 0);
#endif
}

static void scan_file(int namelength,
                      void (*proc)(char *name, int why, long int size))
{
#ifdef THIS_NEEDS_RE_WRITING_FOR_MACINTOSH
    struct stat buf;
    stat(filename, &buf);
    if ((buf.st_mode & S_IFMT) == S_IFDIR) exall(namelength, proc);
    else if ((buf.st_mode & S_IFMT) == S_IFREG)
        proc(filename, SCAN_FILE, buf.st_size);
/*  else fprintf(stderr, "Mode of %s is %o\n", filename, buf.st_mode); */
#endif
}

void scan_directory(char *dir,
                    void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 1;
    if (dir==NULL || strcmp(dir, ".")==0) dir = ".";
    scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    scan_file(scan_leafstart-1, proc);
}

void scan_files(char *dir,
                void (*proc)(char *name, int why, long int size))
{
    recursive_scan = 0;
    if (dir==NULL || strcmp(dir, ".")==0) dir = ".";
    scan_leafstart = strlen(dir)+1;
    strcpy(filename, dir);
    scan_file(scan_leafstart-1, proc);
}

#define SCANDIR_KNOWN 1

#endif /* macintosh */
#endif /* ATARI */
#endif /* __arm */
#endif /* UNIX */
#endif /* MS_DOS */
#endif /* WINDOWS_NT */


#ifndef SCANDIR_KNOWN
#error "Directory scanning machine-specific code not present"
#endif

/* end of scandir.c */

