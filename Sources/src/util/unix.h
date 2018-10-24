#define DIRECTORY_CHAR    '/'

#include <sys/types.h>
/* #include <sys/dir.h> */

#include <sys/stat.h>

#if defined (__sun) &&  (defined (__SUNPRO_C) || defined (__GNUC__))
#include <dirent.h>
#define direct dirent
#endif

#if defined ( __alpha) || defined (__sgi) ||defined(__hpux)
#include <dirent.h>
#define direct dirent
#endif

#ifdef _rs6000
#include <dirent.h>
#define direct dirent
#endif

#include <utime.h> /* For utimbuf - may need adjustment across Unix variants */

