/*  sysaxlnk.c                     Copyright (C) 1989-95 Codemist Ltd */

/*
 * Windows NT support, using MFC via the "cwin" package.
 */

/* Signature: 7772145d 23-May-1995 */
/* For garbage that appears to expect a console */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#ifdef __cplusplus
#include <afxwin.h>
#else
#include <windows.h>
#endif

#undef CSL_IGNOER

#ifdef __WATCOMC__
#include <float.h>
#endif

#include "machine.h"
#include "tags.h"
#include "externs.h"
#include "read.h"
#include "cslerror.h"
#include "sys.h"

#include <errno.h>
#include <io.h>
#include <dos.h>
#include <direct.h>
#include <sys\stat.h>

/*
 * Changes:
 * 12-12-96: Removed SOFTWARE_TICKS crap.
 */

#include "axiom.h"

static bool ticker_active = NO;

void add_ticker(void)
{
    if (ticker_active) return;
    countdown = SOFTWARE_TICKS;
    ticker_active = YES;
}

void MS_CDECL remove_ticker(void)
{
    if (!ticker_active) return;
    ticker_active = NO;
}

/*
 * void poll_for_attn()
 * {
 *    kbhit();   // causes ^C to be noticed!
 * }
 */

static clock_t prev_clock = 0;

void accept_tick(void)
{
/*
 * This is where I can put things that need to be done regularly. At
 * In particular I can poll the window manager here.
 */
/*
 * Around once per 2 seconds I update the clock display on the menu bar -
 * the intent of this is to give a bit of feedback to the user that
 * things are happening.
 */
    clock_t t0 = clock();
    if (prev_clock == 0 || t0 > prev_clock + 2*CLOCKS_PER_SEC)
    {   long int t, gct;
        Lisp_Object nil;
        ensure_screen(); nil = C_nil;
        if (exception_pending()) return;
        t0 = clock();
        if (clock_stack == &consolidated_time[0])
        {   consolidated_time[0] +=
                (double)(t0 - base_time)/(double)CLOCKS_PER_SEC;
            base_time = t0;
        }
        t = (long int)(100.0 * consolidated_time[0]);
        gct = (long int)(100.0 * gc_time);
        report_time(t, gct);
        prev_clock = t0;
    }

    axPollForMessages();
    if (!interrupt_pending && axGetInterrupt()) {
      Lisp_Object nil = C_nil;
      interrupt_pending = YES;
      if (exception_pending())
	nil =  (Lisp_Object)((int32)nil ^ 1);
    }  
    axResetInterrupt();
}

void putc_stdout(int c)
{
}

void pause_for_user()
{
}

int pipes_today = 0;
int win32s = 0;

void flush_screen()
{
}

void start_up_window_manager(int use_wimp)
{
}

int wimpget(char *buf)
{
    return 0;
}


/*
 * Slightly optional jollies re GC statistics...
 */
 
static char time_string[32], space_string[32];

void report_time(int32 t, int32 gct)
{
    sprintf(time_string, "%ld.%.2ld+%ld.%.2ld secs  ",
        t/100L, t%100L, gct/100L, gct%100L);
    /* !!! BUG!!! Do Something!!! */
    /* [CWin changes the title-bar] */
}

void report_space(int n, double percent)
{
    sprintf(space_string, "[GC %d]:%.2f%%", n, percent);
    /* !!! BUG!!! Do Something!!! */
    /* [CWin changes the title-bar] */
}

/*
 * End of the worst of the window-manager aware code
 */

#undef exit
#define exit(a) my_exit(a)

#include "fileops.c"
#include "scandir.c"

/*
 * To the extent that I believe that versions of Windows that support long
 * file names are now readily available, and that compatibility with older
 * systems is ridiculous, I disable the conversion to 8+3 format shown
 * here. The particular bit of sample code that convinced me was attempting
 * to create files with names like xxx.html where each file contained the
 * names of other files in the set. And truncation to xxx.htm meant that the
 * cross-references failed. Ugh.
 */

#ifdef EIGHT_PLUS_THREE

/*
 * Windows 95 can support long file names, but Windows 3.x and DOS do not.
 * This is in fact a potential cause of big mess. What I do here is to
 * truncate all file-names to 8+3 format. The effect will be that if files
 * have been set up for use with Windows 3.x they will still work, and files
 * created by and used ONLY by this system will be OK. But if a Windows-95
 * utility is used to create a file with a long name then I will not be able
 * to use that name to access it.  Users beware!
 */

static void eight_plus_three(char *s)
{
    int c, i=0;
    char *p=s;
    while ((c=*p++)!=0 && c!='.' && c!='\\' && c!=':') i++;
    if (c==':') return;
    if (i>8)
    {   char *q=s+8;
        p--;
        while ((*q++=*p++)!=0);
        p=s+9;
    }
    if (c!='.') return;
    i=0;
    s=p;
    while ((c=*p++)!=0 && c!='\\') i++;
    if (i>3)
    {   char *q=s+3;
        p--;
        while ((*q++=*p++)!=0);
    }
}

#endif

static void process_file_name(char *filename, char *old, size_t n)
/*
 * This procedure maps filenames by expanding some environment
 * variables.  It is very thoroughly system specific, which is why it
 * is in this file.  See also LONGEST_LEGAL_FILENAME in "tags.h" for a
 * limit on the permitted size of an expanded filename.
 * The input (old) is not necessarily properly terminated as a C string,
 * so n says how many characters to inspect.  Build a converted name
 * in filename.
 * At present the expansions I allow are only recognized at the start
 * of a name, and are
 *    $xxx   (terminated by '.', '/' or '\' and at least one char x)
 *    ${xxx} (self-terminating)
 *           These inspect the environment variable xxx and dump its
 *           value into the output.  If the variable is unset I look
 *           for a global variable @xxx. Failing that a null
 *           string is inserted.
 *    ~      followed by '.', '/' or '\'
 *    ~xxx
 *           On Unix these try to find home directories using
 *           getpwuid(getuid()) for '~' and getpwnam() for ~xxx.
 *           If that fails ~ expands into nothing at all.
 * On other systems there is no guarantee that I will support any of these
 * expansions at all, but I will make an attempt to map Unix-like
 * file-names of the form aaa/bbb/ccc.ddd into something acceptable to
 * the system being used, even though this may result in native file
 * titles that include '/' characters becoming unavailable.
 *
 * mode is something like "r" or "w" or "rb", as needed by fopen(),
 * and old_file is NULL normally, but can be a FILE * to indicate
 * the use of freopen rather than fopen.
 */
{
    int32 j;
    int c;
    char *o, *tail;
    if (n == 0)
    {   *filename = 0;
        return;    /* deem zero-length name to be illegal */
    }
    o = filename;
    c = *old;
    if (c == '~')
    {   tail = old+1;
        for (j=(int32)n-1; j!=0; j--)
        {   c = *tail;
            if (c == '.' || c == '/' || c == '\\') break;
            tail++;
            *o++ = c;
        }
        *o = 0;
        if (o == filename)  /* '~' on its own */
        {   get_home_directory(filename, LONGEST_LEGAL_FILENAME);
            o = filename + strlen(filename);
        }
        else
        {   get_users_home_directory(filename, LONGEST_LEGAL_FILENAME);
            o = filename + strlen(filename);
        }
        for (;j!=0; j--) *o++ = *tail++;
        *o = 0;
    }
    else if (c == '$' && n > 1 &&
             /* $ on its own, or $/... etc stay unaltered */
             (c = old[1]) != '.' && c != '/' && c != '\\')
    {   char *w;
        if (c == '{')
        {   tail = old+2;
            for (j=(int32)n-2; j!=0; j--)
            {   c = *tail++;
                if (c == '}') break;
                *o++ = c;
            }
        }
        else
        {   tail = old+1;
            for (j=(int32)n-1; j!=0; j--)
            {   c = *tail;
                if (c == '.' || c == '/' || c == '\\') break;
                tail++;
                *o++ = c;
            }
        }
        *o = 0;
        w = my_getenv(filename);
        if (w != NULL)
        {   strcpy(filename, w);
            o = filename + strlen(filename);
        }
        else
        {   Lisp_Object nil, var;
            int i = strlen(filename) + 2;
            while (i-- != 0) filename[i] = filename[i-1];
            filename[0] = '@';
            var = make_undefined_symbol(filename);
            nil = C_nil;
            if (exception_pending()) 
            {   flip_exception();
                *filename = 0;
                return;
            }
            if (qvalue(var) == unset_var) o = filename;
            else
            {   Header h;
                int32 len;
                var = qvalue(var);
#ifdef COMMON
                if (complex_stringp(var))
                {   var = simplify_string(var);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        *filename = 0;
                        return;
                    }
                }
#endif
                if (symbolp(var))
                {   var = get_pname(var);
                    nil = C_nil;
                    if (exception_pending())
                    {   flip_exception();
                        *filename = 0;
                        return;
                    }
                    h = vechdr(var);
                }
                else if (!is_vector(var) ||
                     type_of_header(h = vechdr(var)) != TYPE_STRING)
                {   *filename = 0;
                    return;
                }
                len = length_of_header(h) - 4;
                memcpy(filename, (char *)var + (4L- TAG_VECTOR), (size_t)len);
                o = filename + len;
            }
        }
        for (;j!=0; j--) *o++ = *tail++;
        *o = 0;
    }
    else
    {   memcpy(filename, old, n);
        filename[n] = 0;
    }
/*
 * Now the filename has had $ and ~ prefix things expanded - I "just"
 * need to deal with sub-directory representation issues.
 */

/*
 * I map / characters in MSDOS filenames into \s, so that users
 * can give file names with Unix-like slashes as separators if they want.
 * People who WANT to use filenames with '/' in them will be hurt.
 */
    tail = filename;
    while ((j = *tail) != 0)
    {   if (j == '/') *tail = '\\';
        tail++;
    }

/*
 * stat and friends do not like directories referred to as "\foo\", so check
 * for a trailing slash, being careful to respect directories with names
 * like "\" and "a:\".
 */
   j = strlen(filename);
   if (j > 0 && j != 1 && !(j == 3 && *(filename+1) == ':')) {
     if ( (*(tail - 1) == '\\')) *(tail - 1) = 0;
   }

#ifdef __WATCOMC__
/*
 * There is a bug in the stat function under Watcom, where:
 *  stat("\\foo\\..", ...);
 * fails with errno=-1.  So we delete trailing ".." segments.
 */
   if (filename[0] == '\\' || filename[1] == ':') {
     j = strlen(filename);
     while (filename[j-1] == '.' && filename[j-2] == '.') {
       tail = strrchr(filename, '\\');
       if (tail == NULL)
         aerror0("Unexpected pathname - this error should never happen");
       else
         *tail='\0';
       tail = strrchr(filename, '\\');
       if (tail == NULL)
         aerror0("Unexpected pathname - this error should never happen");
       else
         *tail='\0';
       j = strlen(filename);
     }

     /* Make sure we don't have an empty string or just a drive */
     if (j == 0)
       strcpy(filename,"\\");
     else if (j==2 && filename[1] == ':')
       strcat(filename,"\\");
   }
#endif

/*
 * A *NASTY* hack here. I will explcitly truncate the name down to
 * and 8+3 format to keep as much DOS compatibility as I (in)conveniently can.
 * This is done here because if a user attempts to open a file with a long
 * name Windows 95 will try to honour the request and will then get confused
 * if old-style W3.x or DOS utilities made the file with a truncated name.
 */
    tail = filename;
#ifdef EIGHT_PLUS_THREE
    eight_plus_three(tail);
    while ((j=*tail++)!=0) if (j=='\\' || j==':') eight_plus_three(tail);
#endif
/*    term_printf("Converted filename \"%s\" -> \"%s\"\n", old, filename); */
}

FILE *open_file(char *filename, char *old, size_t n,
                char *mode, FILE *old_file)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return NULL;
    if (old_file == NULL) return fopen(filename, mode);
    else return freopen(filename, mode, old_file);
}

int change_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
#ifdef _MSC_VER
    if (_chdir(filename))
#else
    if (chdir(filename))
#endif
    {   char err_buf[LONGEST_LEGAL_FILENAME+100];
        switch (errno)
        {
    case ENOENT:  
          sprintf(err_buf,"The directory %s does not exist.",filename);
          break;
        default:
          sprintf(err_buf,"Cannot change directory to %s.",filename);
            break;
      }
      aerror0(err_buf);
        return 1;
    }
    else return 0;
}

int create_directory(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
#ifdef _MSC_VER
    return _mkdir(filename);
#else
    return mkdir(filename);
#endif
}

bool file_exists(char *filename, char *old, size_t n, char *tt)
{
#ifdef _MSC_VER
    struct _stat statbuff;
#else
    struct stat statbuff;
#endif
    process_file_name(filename, old, n);
    if (*filename == 0) return NO;
#ifdef _MSC_VER
    if (_stat(filename, &statbuff) != 0) return NO;
#else
    if (stat(filename, &statbuff) != 0) return NO;
#endif
    strcpy(tt, ctime(&(statbuff.st_ctime)));
    return YES;
}

static void remove_files(char *name, int dirp, long int size)
/*
 * Remove a file, or a directory and all its contents. This function
 * can still misbehave if you do not have write access to all the files
 * involved.
 */
{
    switch (dirp)
    {
case SCAN_ENDDIR:
#ifdef _MSC_VER
        _rmdir(name);  return;
#else
        rmdir(name);   return;
#endif
case SCAN_FILE:
        remove(name);  return;
    }
}

int delete_file(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 1;
    scan_directory(filename, remove_files);
    return 0;
}

int directoryp(char *filename, char *old, size_t n)
{
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    return (GetFileAttributes(filename) & FILE_ATTRIBUTE_DIRECTORY);
}

extern char *get_truename(char *filename, char *old, size_t n)
{
  struct stat buf;
  char *temp, *fn, *dir, *pwd;

  process_file_name(filename, old, n);
  if (*filename == 0) aerror("truename");

  /* Find out whether we have a file or a directory.  Be careful in case
     the first two characters define a drive. */
  if (0 /*strlen(filename) > 2 && *(filename+1) == ':' */) {
    if (stat(filename+2,&buf) == -1) aerror0("truename: cannot stat file");
  }
  else {
    if (stat(filename,&buf) == -1) aerror0("truename: cannot stat file");
  }

  /* Store current directory */
  if ((pwd = (char *)getcwd((char *)NULL,LONGEST_LEGAL_FILENAME)) == NULL)
    aerror0("truename: cannot get current working directory");

  if ((buf.st_mode & S_IFMT) == S_IFDIR) {
    char *dir = (char*) malloc(LONGEST_LEGAL_FILENAME);
    /* We have a directory */
    if (chdir(filename) != 0) 
      aerror0("truename: cannot change directory");
    if (getcwd(dir ,LONGEST_LEGAL_FILENAME) == NULL)
      aerror0("truename: cannot get current working directory");
    if (chdir(pwd) != 0)
      aerror0("truename: cannot change directory");
    free(pwd);

    /* 
     * This is an axiom-specific hack --- it expects that truname
     * preserves trailing directory charaters.
     */
    if ((old[n-1] == '\\' || old[n-1] == '/') && dir[strlen(dir)-1] != '\\') {
      n = strlen(dir);
      dir[n] = '\\';
      dir[n+1] = '\0';
    }
    return dir;
  }
  else {
    /* Assume we have some kind of file */
    temp = strrchr(filename,'\\');
    if (temp) { /* Found a directory component */
      fn   = strdup(temp);
      *temp = '\0';
      /* fn is now "\file" and filename is the directory */

      if (chdir(filename) != 0)
        aerror0("truename: cannot change directory");
      if ((temp = (char *)getcwd((char *)NULL,LONGEST_LEGAL_FILENAME)) == NULL) 
        aerror0("truename: cannot get current working directory");
      if (chdir(pwd) != 0)
        aerror0("truename: cannot change directory");
      dir = (char *)malloc((strlen(temp) + strlen(fn) + 1)*sizeof(char));
      strcpy(dir,temp);
      free(temp);
      strcat(dir,fn);
      free(pwd);
      free(fn);
      return(dir);
    }
    else {
      dir = (char *)malloc((strlen(pwd) + strlen(filename) + 2)*sizeof(char));
      strcpy(dir,pwd);
      strcat(dir,"\\");
      strcat(dir,filename);
      free(pwd);
      return(dir);
    }
  }
}

int get_current_directory(char *s, int n)
{
    int n1 = GetCurrentDirectory(n, s);
    if (n1 == 0)
    {   aerror0("cannot get current directory name");
        return 0;
    }
    else if (n1 >= n)
    {   aerror("the pathname of the current directory is too long");
        return 0;
    }
    else return n1;
}

#ifdef NAG_VERSION

#define MAX_NUMBER_OF_FILES 2048

int list_directory_members(char *filename, char *old, char **filelist[],
                           size_t n)
{   WIN32_FIND_DATA fileData;
    HANDLE fileHandle;
    int32 number_of_entries = 1;
    char **files;

    process_file_name(filename, old, n);

    if (*filename == 0) strcpy(filename,"*.*");
    else if (filename[strlen(filename)-1] != '\\')
        filename=strcat(filename,"\\*.*");
    else filename=strcat(filename,"*.*");
    
    fileHandle = FindFirstFile(filename,&fileData);
    
    if (fileHandle == INVALID_HANDLE_VALUE) return 0;

/*
 * The fixed allocation size here seems unsatisfactory, but I will leave it
 * like that for the moment because altering things to behave better would
 * probably involve redesigning the interface to this function.
 */
    files=(char **)malloc(MAX_NUMBER_OF_FILES*sizeof(char *));
    files[0]=strdup(fileData.cFileName);

    while(FindNextFile(fileHandle,&fileData))
    {   files[number_of_entries] = strdup(fileData.cFileName);
        number_of_entries++;
    }

    FindClose(fileHandle);

    *filelist = files;

    return number_of_entries;
}

#else

void list_directory_members(char *filename, char *old,
                            size_t n, directory_callback *fn)
{
    process_file_name(filename, old, n);
    scan_files(filename, fn);
}


#endif

int file_readable(char *filename, char *old, size_t n)
{
    struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1)
      return 0; /* File probably does not exist */
    else
        return (buf.st_mode & S_IRUSR);
}

int file_writeable(char *filename, char *old, size_t n)
{
    struct stat buf;
    process_file_name(filename, old, n);
    if (*filename == 0) return 0;
    if (stat(filename,&buf) == -1)
      return 0; /* Should we check to see if the directory is writeable? */
    else
        return (buf.st_mode & S_IWUSR);
}

int rename_file(char *from_name, char *from_old, size_t from_size,
                char *to_name, char *to_old, size_t to_size)
{
    process_file_name(from_name, from_old, from_size);
    process_file_name(to_name, to_old, to_size);
    if (*from_name == 0 || *to_name == 0) return NULL;
    return rename(from_name,to_name);
}

/*
 * It appears to me that "system" as provided by the Windows NT SDK
 * libraries is a real mess.  This is perhaps because executing a
 * command might want to generate terminal output, so when one invokes
 * "system" it first pops up a console window running the command
 * interpreter, then loads the thing you wanted executed, and then
 * closes everything down - probably before you have had any real
 * chance to observe any output that was generated.  I might therefore
 * want to invent a version of my own... as in here using CreateProcess.
 * The issues about Win32 vs Win32s incompatibilities here are HORRID.
 */
static HANDLE osRunRedirect(char *cmd, BOOL wait, HANDLE hin, HANDLE hout, HANDLE herr);
static HANDLE osMakeReadPipe(char *cmd, HANDLE *);
static char *osMangleCommand(char *s);

int my_system(char *s)
{
        HANDLE h, hproc;
        DWORD  retCode;
	char buf[256];
	char *os;
	DWORD nread;
	BOOL done = FALSE;
	
	os = s;
	s = osMangleCommand(s);
        h = osMakeReadPipe(s, &hproc);
	if (s != os) free(s);
	if (h==NULL) {
	  term_printf("Failed: %d\n", GetLastError());
	  CloseHandle(hproc);
	  return 0;
	}

	while (!done) {
                int i;
                BOOL res;
                res = ReadFile(h, (void*) buf, 256, &nread, NULL);
                if (res == TRUE && nread == 0 && 
		    GetExitCodeProcess(hproc, &retCode) != STILL_ACTIVE) {
                        done = TRUE;
		}
		else if (!res) {
                        int err = GetLastError();
                        if (GetExitCodeProcess(hproc, &retCode) == STILL_ACTIVE) {
                                term_printf("Error: %d\n", err);
                                CloseHandle(hproc);                                
                                CloseHandle(h);
                                return -1;
                        }
                        return retCode;
		}
		else {
                        for (i=0; i<nread; i++)
                                if (buf[i] != '\r') {
                                        stdout_printf("%c", buf[i]);
                                }
		}
	}
        GetExitCodeProcess(hproc, &retCode);
        return retCode;
}

static HANDLE
osMakeReadPipe(char *cmd, HANDLE *proc)
{
        HANDLE hwr, hwr2, hrd, hproc;
	SECURITY_ATTRIBUTES attribs;
	BOOL     ret;

	attribs.nLength = sizeof(attribs);
	attribs.lpSecurityDescriptor = NULL;
        attribs.bInheritHandle = TRUE;
        if (!CreatePipe( &hrd, /* address of variable for read handle */
                         &hwr,       /*address of variable for write handle  */
                         &attribs, /* Security sillyness */
			 0)) {
		return NULL;
	}
	hproc = GetCurrentProcess();
        ret = DuplicateHandle(hproc, hwr, 	// Source
			      hproc, &hwr2,	// Target
			      0,		// Desired access
			      TRUE,		// Inherit
			      DUPLICATE_SAME_ACCESS);
	if (!ret) {
	  CloseHandle(hrd);
	  CloseHandle(hwr);
	  return NULL;
	}
        
        hproc = osRunRedirect(cmd, FALSE, NULL, hwr, hwr2);
        CloseHandle(hwr);
	CloseHandle(hwr2);
	if (hproc == NULL) {
               return NULL;
	}
        *proc = hproc;
	return hrd;
}

static HANDLE
osRunRedirect(char *cmd, BOOL wait, HANDLE hin, 
	      HANDLE hout, HANDLE herr)
{
	static STARTUPINFO		si;
	static PROCESS_INFORMATION	pi;
	BOOL				rc;

	rc = TRUE;

	if (!rc)
	  term_printf("Ooops!");
	/* Create process. */
	memset(&si, 0, sizeof(si));
	si.cb		= sizeof(si);
	si.lpReserved	= NULL;
	si.lpDesktop	= NULL;
	si.lpTitle	= "!";
	si.cbReserved2	= 0;
	si.lpReserved2	= NULL;
	si.dwFlags	= STARTF_USESTDHANDLES;

	si.hStdInput  = hin;
	si.hStdOutput = hout;
	si.hStdError  = herr;

	rc = CreateProcess(NULL, cmd, NULL, NULL, 
			   TRUE,
                           DETACHED_PROCESS/*|NORMAL_PRIORITY_CLASS*/,
                           NULL, NULL, 
			   &si, &pi);
	if (rc == FALSE) return NULL;

	if (wait == TRUE) {
		rc = WaitForSingleObject(pi.hProcess, INFINITE);
		if (rc == WAIT_FAILED) return NULL;
	}

	return pi.hProcess;
}

/* Expand any environment variables inside s */
static char *
osFindEnvVar(char *s, int idx, int *new_idx)
{
  char *var, c;
  int j=idx;
  while (isalnum(s[j])) j++;
  if (j==idx) return NULL;
  c = s[j];
  s[j] = '\0';

  *new_idx = j;
  var = my_getenv(s+idx);
  s[j] = c;
  return var;
}

static char *
osMangleCommand(char *s)
{
  char *var, *res;
  int  i, j, o, len;

  len = strlen(s);

  o = i = 0; res = s; 
  while (s[i] != '\0') {
    int new_i;
    if (s[i] == '$' && (var = osFindEnvVar(s, i+1, &new_i)) != NULL) {
      /* Get new space */
      int lv = strlen(var);
      char *nres = (char *) malloc(o + lv + len - i + 1);
      for (j=0; j<o; j++) nres[j] = res[j];
      if (res != s) free(res);
      res = nres;
      for (j=0; j<lv; j++) res[o++] = var[j];
      i = new_i;
    } 
    else if (res != s) {
      res[o++] = s[i++];
    }
    else {
      i++; o++;
    }
  }
  if (res != s) res[o] = s[i];

  return res;
}

HWND gnuplot_handle = 0;

BOOL CALLBACK find_text(HWND h, LPARAM x)
{
    char buffer[24];
    GetClassName(h, buffer, 20);
    if (strcmp(buffer, "wgnuplot_text") != 0) return TRUE;
    gnuplot_handle = h;
    return FALSE;
}

FILE *my_popen(char *command, char *direction)
{
#if 0
/*
 * Here I take a pretty shameless direction and spot the special case of
 * opening an output pipe to gnuplot... and hook in a behind-the-scenes
 * way.
 */
    int i = 0, j;
    for (;;)
    {   char *name = "gnuplot";
        j = i;
        while (*name && tolower(command[j++]) == *name) name++;
        if (*name == 0)
        {   HWND parent;
#ifdef OLD_API
            if (WinExec(command, SW_SHOWMINIMIZED) <= 32) return 0;
#else
/*
 * Win32 would rather I used the following long-winded version, which provides
 * a pile of generality that is irrelevant here!
 */
            STARTUPINFO startup;
            PROCESS_INFORMATION process;
            clock_t t0, t1;
            memset(&startup, 0, sizeof(STARTUPINFO));
            startup.cb = sizeof(startup);
            startup.lpReserved = NULL;
            startup.lpDesktop = NULL;
            startup.lpTitle = NULL;
            startup.dwFlags = STARTF_USESHOWWINDOW;
            startup.wShowWindow = SW_SHOWMINIMIZED;
            startup.cbReserved2 = 0;
            startup.lpReserved2 = NULL;
            if (!CreateProcess(NULL, command, NULL, NULL, FALSE,
                               0, NULL, NULL, &startup, &process)) return 0;
#endif
            gnuplot_handle = 0;
            t0 = clock();
            for (i=0; i<25; i++)  /* Give it 5 seconds to appear */
            {   parent = FindWindow((LPSTR)"wgnuplot_parent",
                                    (LPSTR)"gnuplot");
                if (parent != 0) break;
                t0 += CLOCKS_PER_SEC/5;
                while ((t1 = clock()) < t0) cwin_poll_window_manager();
                t0 = t1;
            }
            if (parent != 0)
            {   for (i=0; i<10; i++)   /* 2 more seconds for the child */
                {   EnumChildWindows(parent, find_text, 0);
                    if (gnuplot_handle != 0) break;
                    t0 += CLOCKS_PER_SEC/5;
                    while ((t1 = clock()) < t0) cwin_poll_window_manager();
                    t0 = t1;
                }
            }
            return (FILE *)-1;  // special handle for the gnuplot pipe
        }
        i++;
        if (command[i] == 0) break;
    }
#ifdef __WATCOMC__
    CSL_IGNORE(command); CSL_IGNORE(direction);
    return 0;
#else
    return _popen(command, direction);    
#endif
#endif
    return 0;
}

#if 0
int my_pipe_putc(int c, FILE *f)
{
    if (f == (FILE *)(-1))
    {   if (gnuplot_handle == 0) return EOF;
        if (c == '\n') c = '\r';
        SendMessage(gnuplot_handle, WM_CHAR, c, 1L);
        return c;
    }
    else return putc(c, f);
}

int my_pipe_flush(FILE *f)
{
    if (f != (FILE *)(-1)) return fflush(f);
    return 0;
}
#endif

void my_pclose(FILE *stream)
{
    if (stream == (FILE *)(-1))
    {   SendMessage(gnuplot_handle, WM_CHAR, 'q', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 'u', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 'i', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, 't', 1L);
        SendMessage(gnuplot_handle, WM_CHAR, '\r', 1L);
        return;
    }
#ifdef __WATCOMC__
    CSL_IGNORE(stream);
#else
    _pclose(stream);
#endif
}


char *my_getenv(char *s)
{
  return axGetEnv(s);
}

/*
 * MSDOS does not support the idea of home directories for
 * users, so in case anybody still wants to use the notation "~" that
 * would indicate a home directory under Unix I implement something
 * in terms of environment variables.
 */

int get_home_directory(char *b, int len)
/*
 * Worry about "len" here...
 */
{
    char *w = my_getenv("home");
    if (w != NULL) strcpy(b, w);
    else strcpy(b, ".");
    return strlen(b);
}

int get_users_home_directory(char *b, int len)
/*
 * Worry about "len" here...
 */
{
    char *w, h[LONGEST_LEGAL_FILENAME];
    sprintf(h, "home$%s", b);
    w = my_getenv(h);
    if (w != NULL) strcpy(b, w);
    else strcpy(b, ".");
    return strlen(b);
}

/*
 * The next bit of mess is jolly - I just want to see if stdin has been
 * redirected to come from a file, i.e. whether I am interactive in some
 * sense.  This may be used to decide what to do about error reports etc.
 * The IDEA seems generic across most systems, but the details vary in
 * frustrating ways.
 */


int batchp()
{
    return 0;   /* !isatty(stdin->_file); */
}

/*
 * The next procedure is responsible for establishing information about
 * where the main checkpoint image should be recovered from, and where
 * and fasl files should come from.
 */
char *find_image_directory(int argc, char *argv[])
{
    char *w;
    int i = 0;
    CSL_IGNORE(argc); CSL_IGNORE(argv);
/*
 * If the current program is called c:\aaa\xxx.exe, then I look
 * for a file c:\aaa\xxx.img
 */
    w = (char *)malloc(i+1);
    if (w == NULL)
    {   fprintf(stderr, "\n+++ Panic - run out of space\n");
        my_exit(EXIT_FAILURE);
    }
    w[i-3] = 'I';
    w[i-2] = 'M';
    w[i-1] = 'G';
    return w;
}

bool sigint_must_longjmp = NO;
jmp_buf sigint_buf;

void MS_CDECL sigint_handler(int code)
{
    CSL_IGNORE(code);
    interrupt_pending = 1;
    if (sigint_must_longjmp)
    {   sigint_must_longjmp = 0;
        longjmp(sigint_buf, 1);
    }
    return;
}

/*
 * The following function controls memory allocation policy
 */

int32 ok_to_grab_memory(int32 current)
{
    MEMORYSTATUS w;
    memset(&w, 0, sizeof(w));
    w.dwLength = sizeof(w);
    GlobalMemoryStatus(&w);
#ifdef NOT_CONFIDENT_ENOUGH_HIDE_THIS_TRASH
    term_printf("memStats %d %d %d %d %d %d %d %d\n",
       w.dwLength, 
       w.dwMemoryLoad, 
       w.dwTotalPhys,     w.dwAvailPhys,
       w.dwTotalPageFile, w.dwAvailPageFile, 
       w.dwTotalVirtual,  w.dwAvailVirtual);
#endif
    if (w.dwTotalPhys == 0)
    {
#ifdef COMMON
        return current;
#else
        return 3*current + 2;
#endif
    }
    else
/*
 * Here we seem to be running under win32 (not win32s) and can measure how
 * much memory is currently available for this process. I will grab space
 * until win32 is using all the physical memory there is. After that I will
 * tend to grow much more cautiously.
 */
    {   int32 freemem = w.dwAvailPhys / CSL_PAGE_SIZE;
        if (freemem == 0) return current / 2 + 1;
        if (freemem > 3*current + 2) freemem = 3*current + 2;
        return freemem;
    }
}

void sys_abort(int n)
{
  static char buf[50];
  sprintf(buf, "Error: %d", n); 
  axFatalError(buf);
}

/* end of sysaxlnk.c */

