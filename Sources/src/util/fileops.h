/*
 * fileops.h                 Copyright (C) Codemist Ltd 1994
 *
 *      cross-platform support for filenames etc
 *
 *                            A C Norman
 */

/* Signature: 299ee2cc 08-Sep-1995 */

extern int Cmkdir(char *s);

extern int truncate_file(FILE *f, long int where);

extern void adjust_file_name(char *filename, char *old);

extern void unadjust_file_name(char *filename, char *old);

/*
 * datestamps that I put in archives have given me significant
 * trouble with regard to portability - so now I deal with times by
 * talking to the system in terms of broken down local time (struct tm).
 * I then pack things up for myself to get 32-bit timestamps. The
 * encoding I use aims at simplicity - it treats all months as 31 days
 * and thus does not have to worry about leap years etc.  NOTE this means
 * that timestamps in previously created CAR archives will be decoded
 * in a wrong-minded way by the new version.  Tough luck.
 */

extern void unpack_date(unsigned32 r,
                        int *year, int *mon, int *day,
                        int *hour, int *min, int *sec);

extern unsigned32 pack_date(int year, int mon, int day,
                            int hour, int min, int sec);

typedef struct date_and_type
{
    unsigned32 date;
    unsigned32 type;
} date_and_type;

/* Reinstate date and filetype... */
extern void set_filedate(char *name, unsigned32 datestamp, unsigned32 ftype);

extern void put_fileinfo(date_and_type *p, char *name);

/* End of fileops.h */
