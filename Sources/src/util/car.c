/*
 * "car.c"
 *
 *                       Compacting archiver.
 *
 * Use:
 *
 *      car <destination> -a/-b [<source-dir>/<source-file>]*
 * and
 *      excar <archive file>
 *
 * OR   car <destination> @ <response_file>
 *          where the response file contains a list of file and
 *          directory names (whitespace separated), plus -a or -b flags.
 *
 * If the set of source files is big this will create a sequence
 * of output files, with names obtained by modifying the given
 * destination name.
 * Because single files from the source are usually not
 * split the size of the separate archive files will not all match,
 * but my target is to make them all about 200 Kbytes long.
 * This size can be modified by putting a switch of the form
 * -<number> on the command-line (or in the response file), e.g.
 * if you are prepared to have megabyte archive files then specify
 * -1000000.  If you specify -0 this has a special meaning: the
 * size of archive files is not limited at all, and all the source
 * files are packed into a single file.  If this is specified as
 * the very first item on the command line then the destination file-name
 * will be used unaltered (i.e. without an appended sequence number) -
 * if given anywhere else it serves to direct that all remaining
 * sources should be packed into the current file.
 * The flags -a and -b can be interleaved among the specification of
 * files to be dumped, and select ascii/binary processing.  This is
 * not very relevant on systems where there is no difference between
 * the two sorts of files but is vital for (e.g.) MSDOS.
 *
 * Actually the argument decoding handles a sequence of items,
 * where each item can be one of:
 *          -a          select ASCII (text) mode for further files
 *          -b          select binary mode for further files
 *          <file>      dump that file
 *          <directory> dump entire contents of given directory
 *          -o<file>      ) omit that file or directory from
 *          -o<directory> ) the dump.
 *          @<file>     read items from response file & process
 *          @           next arg is name of response file
 * [thus both "@resp" and "@ resp" are permitted]
 *          -<number>   archive file size limit control
 *
 * A list of "omitted" (via "-o") files indicated on the command line
 * is collected before any other file processing happens. Thus the order
 * of "-o" and file-name arguments is immaterial on the command line. However
 * in response files any "-o" requests must be given before a file indication
 * that is to be overridden.  Thus
 *    car archive.car directory -odirectory\*.tmp
 * is OK, but
 *    car archive.var @temp
 * temp:     -odirectory\*.tmp
 *           directory
 * is needed.
 *
 * The extraction program is called excar, and is used:
 *
 *      excar <archive>         Extract files from archive
 *      excar -t <archive>      Just list contents of archive
 *      excar -c <archive>      Compare with files existing on disc
 *
 * [Note: at present the "-c" option will not work with files that have
 *  been split across two or more archive files...]
 *
 * It is made by compiling this file with EXTRACT defined.
 * Ie. something like      "cc -DEXTRACT=1 -o excar car.c"
 *
 *                  A C Norman,  1991-94
 *                  good ideas about file compression provided by D J Wheeler
 */

/* Signature: 37f6ceb9 30-Dec-1995 */


#include "sys.h"
#include "patmatch.h"

#ifdef THINK_C /* Macintosh - tested on Mac LC with 4 Mbytes and system 7 */
#define EXTRACT 1    /* Extract-only system here... at least for now */
#endif

#ifndef EXTRACT

static int32 ideal_archive_size;

#define MAX_OMISSIONS 64
static char *omitted_files[MAX_OMISSIONS];
static int n_omitted_files;
static int omitting;

#endif /* !EXTRACT */

static FILE *archive_file;
static unsigned32 CRC;

/*
 * Bits to go in the compression-mode flag...
 */
#define BINARY_FILE     1       /* Create restored file in "wb" mode       */
#define SPARE_BIT       2       /* Spare just for the moment.              */
#define NO_PREDICT      4       /* No character prediction compression     */
#define FLAT_STATS      8       /* All characters roughly equally probable */
#define EXPLICIT_STATS  0x10    /* Sending 256 bytes char frequency table  */
#define USE_CURRENT     0x20    /* Use current frequency distribution      */
#define SPLIT_FILE      0x40    /* Used for very large files               */
#define FINAL_BLOCK     0x80    /* Last block of a segment or file         */

#ifdef EXTRACT

static enum { excar_x, excar_t, excar_c } just_list_contents;
static bool skip_errors;

#else /* EXTRACT */

static char *archive_file_name;
static int archive_file_number, current_archive_count;
static int32 current_archive_size, current_raw_size;
static int32 total_bulk;
static bool binary_mode;

/*
 * I compress files in chunks of size BLOCK_SIZE, re-evaluating statistics
 * etc that often - there is thus a trade-off between using a small block
 * size for an agile code and using a large one to obtain a better
 * amortization of overheads.
 */
#define BLOCK_SIZE     0xf000U

static unsigned char *look_ahead_buffer;
static int32 look_ahead_count;
static unsigned char *prediction1a, *prediction2a; /* shadow arrays */

#endif /* EXTRACT */

FILE *err_file;

/*
 * The table that follows gives a default set of predicted relative
 * frequencies of characters - it was constructed by scanning a selection
 * of files, mostly C and REDUCE sources,   The counts are scaled so that
 * the sum of all counts is 0x01000000 (roughly).
 */

static unsigned32 default_frequencies[257] =
{
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      709U,    412298U, 0U,      17U,     0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    1510472U,111588U, 86716U,  29547U,  22377U,  72235U,  26885U,  64855U,
    286386U, 349289U, 139192U, 42031U,  324356U, 106773U, 208110U, 79922U,
    98657U,  154049U, 101695U, 54244U,  34756U,  27279U,  28505U,  25362U,
    32506U,  28531U,  142545U, 294922U, 48133U,  130490U, 61484U,  7677U,
    5559U,   81664U,  32532U,  74660U,  42408U,  71334U,  41121U,  27166U,
    21379U,  73916U,  19566U,  11696U,  78574U,  41515U,  61502U,  46873U,
    49517U,  5270U,   67692U,  78915U,  88913U,  30239U,  26273U,  14252U,
    16388U,  18665U,  8115U,   11337U,  48501U,  16003U,  5699U,   100513U,
    4141U,   772627U, 268229U, 511988U, 399148U, 836572U, 374109U, 185584U,
    200213U, 845747U, 19750U,  63340U,  458610U, 310331U, 600132U, 624155U,
    402466U, 63069U,  632524U, 728775U, 760528U, 340701U, 213599U, 165833U,
    141678U, 142668U, 40569U,  95418U,  19374U,  89526U,  3414U,   0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U,      0U,      0U,      0U,      0U,      0U,      0U,      0U,
    0U       /* Item 256 is for EOF */
};

static int32 current_frequencies[257];

/*
 * The following three arrays are of size 2*CODE_SIZE, and are used
 * as a "heap" when sorting character codes by frequency and building
 * an encoding tree.  The arrays are only used while I am in the process
 * of constructing a Huffman code.
 */
static int   *char_being_coded;       /* original character code */
static int32 *number_of_occurences;   /* frequency count/backpointer */
static int   *character_index;
/*
 * The next two arrays represent a Huffman code - the entries at
 * position i give the string of bits to be send to represent code i.
 * huffman_coded_bits[i] holds the bits, starting in the 0x80000000
 * position and running down length_of_code[i] bits.
 * These arrays only need to be CODE_SIZE long.
 */
static char       *length_of_code;     /* number of bits for this code */
static unsigned32 *huffman_coded_bits; /* up to 32 bits of output code */
/*
 * The final collection of arrays relate to decoding Huffman codes -
 * first I have a list of codestrings in numerically ascending order,
 * and attached to it a vector of the decoded bytes.  From a decoded byte
 * I can use length_of_code[] to find how many bits were actually used.
 */
static unsigned32 *sorted_huffman_codes;      /* CODE_SIZE long */
static int        *corresponding_character;

#ifdef EXTRACT
/*
 * I allow for decoding strings of up to N bits especially rapidly by
 * having a table of length 2^N that contains (packed) a decoded character
 * and its length (if <= N), or a value > N if more bits have to be
 * inspected. (N is FAST_DECODE_LIMIT and gives a space/speed tradeoff,
 * but should never alter the validity of an unpacking).
 */
#define FAST_DECODE_LIMIT       11
#define FAST_DECODE_TABLESIZE   (((unsigned32)1) << FAST_DECODE_LIMIT)
static int32 *fast_decode_table;
#endif

#define huffman_back_pointer number_of_occurences /* Share 1 array for these */

#define PREDICTION_SHIFT    5
#define PREDICTION_SIZE     (((unsigned32)1) << (3*PREDICTION_SHIFT))
#define PREDICTION_MASK     (PREDICTION_SIZE-1)

static unsigned char *prediction1, *prediction2;   /* main prediction arrays */

static int32 last_three;

#define INITIAL_LAST_THREE \
      (((((((unsigned32)'\n')<<PREDICTION_SHIFT) + \
             '\n')<<PREDICTION_SHIFT)+'\n') & PREDICTION_MASK)

static void update_CRC(int ch)
{
    unsigned32 CRCtemp;
/*
 * This is my favourite hash function at present - it cycles a 31-bit shift
 * register with maximum period.  As used here the item mixed in (ch) will
 * always have been masked with 0xff.
 */
    CRCtemp = (CRC << 7);
    CRC = ((CRC >> 25) ^      /* NB logical (not arithmetic) shift here */
           (CRCtemp >> 1) ^
           (CRCtemp >> 4) ^
           (unsigned32)ch) & 0x7fffffff;
}

/*
 * I use Huffman-coding as part of the file-compression, and while
 * building codes I use heaps as datastructures - here are some procedures
 * related to keeping the "heap" property of an array valid.
 */

static void swop(int a, int b)
/* Exchance two items in the heap */
{
    int haa = char_being_coded[a], hab = char_being_coded[b];
    int32 hba = number_of_occurences[a], hbb = number_of_occurences[b];
    char_being_coded[a] = hab, char_being_coded[b] = haa;
    number_of_occurences[a] = hbb, number_of_occurences[b] = hba;
}

static void flip3(int i, int heapsize)
/* Force heap property to hold at position i in the array */
{
    int j = 2*i+1;
    int k = j + 1;
    if (j >= heapsize) return;
    if (k >= heapsize)
    {   if (number_of_occurences[i] > number_of_occurences[j]) swop(i, j);
        return;
    }
    if (number_of_occurences[j] > number_of_occurences[k])
    {   if (number_of_occurences[i] > number_of_occurences[k])
        {   swop(i, k);
            flip3(k, heapsize);
        }
    }
    else if (number_of_occurences[i] > number_of_occurences[j])
    {   swop(i, j);
        flip3(j, heapsize);
    }
}

/*
 * This starts by giving myself an alphabet of 256 codes plus an EOF
 * marker, and then takes three copies of this (to allow for combinations of
 * a predicted character followed by some other character.  Finally I have
 * six special codes that are to allow compact treatment of runs of
 * predicted characters.
 */

#define HUFF_EOF            256
#define PREDICT_1           257
#define PREDICT_2           514
#define PREDICT_11          771
#define PREDICT_1111        772
#define PREDICT_11111111    773
#define PREDICT_22          774
#define PREDICT_12          775
#define PREDICT_21          776
#define CODE_SIZE           777     /* Total number of characters in code */

static void huffman()
{
    int i, heapsize = CODE_SIZE;
/*
 * Form list of characters into a heap, so that least frequent char
 * is easy to spot.
 */
    for (i=(heapsize/2)-1; i>=0; i--) flip3(i, heapsize);
/*
 * Now the array is structured as a heap.  Repeatedly pick off the two
 * least-frequent characters and combine them into one new code.
 */
    for (i=0; i<CODE_SIZE-1; i++)
    {
        swop(0, CODE_SIZE-i-1);
        heapsize--;
        flip3(0, heapsize);
        if (number_of_occurences[CODE_SIZE-i-1] == 0)
        {   char_being_coded[CODE_SIZE+i] = CODE_SIZE+i;
            huffman_back_pointer[CODE_SIZE+i] = 0; /* Must leave table tidy */
            continue;                              /* Ignore unused codes */
        }
        char_being_coded[CODE_SIZE+i] = char_being_coded[0];
        number_of_occurences[CODE_SIZE+i] = number_of_occurences[0];
        char_being_coded[0] = CODE_SIZE+i;
        number_of_occurences[0] =
            number_of_occurences[CODE_SIZE-i-1] +
            number_of_occurences[CODE_SIZE+i];             /* combine counts */
        huffman_back_pointer[CODE_SIZE-i-1] =
            huffman_back_pointer[CODE_SIZE+i] = CODE_SIZE+(int32)i;
                                                             /* back-pointer */
        flip3(0, heapsize);
    }
    huffman_back_pointer[0] = 0;  /* terminate back-pointer chains */
/*
 * Now the array is sorted, with Huffman-codes implicit in a bunch of
 * back-pointers.  Scan and build a table of codes-lengths.
 */
    for (i=0; i<2*CODE_SIZE-1; i++)
    {   int c = char_being_coded[i];
        character_index[c] = i;
    }
    {   int maxlen = 0, p;
        unsigned32 next_code, bit;
        for (i=0; i<CODE_SIZE; i++) length_of_code[i] = 0;
        for (i=0; i<2*CODE_SIZE-1; i++)
        {   int len = 0, p, c = char_being_coded[i];
            if (c >= CODE_SIZE || huffman_back_pointer[i] == 0) continue;
            for (p=i; p!=0; p=character_index[huffman_back_pointer[p]]) len++;
            if (len > maxlen) maxlen = len;
/*
 * The length for a code is given by its depth in the tree, and I find
 * this by following the back-pointers.
 */
            length_of_code[c] = len;
        }
/*
 * Both when coding and decoding I collect data in a 32-bit word and
 * transfer it between this word and the archive file in 8-bit bytes.
 * The effect is that I may sometimes need to waste 7 bits in the 32-bit
 * buffer - hence I can handle 25-bit codes.
 */
        if (maxlen > 25)
        {   fprintf(err_file, "Error: maximum code-length (%d) > 25\n", maxlen);
            exit(EXIT_FAILURE);
        }
/*
 * Now I allocate concrete bit-patterns to codes, and leave things packed so
 * that code-lengths are in the least significant byte of the output array,
 * while the bit-patterns themselves start from the top.
 */
#ifdef EXTRACT
        for (i=0; i<FAST_DECODE_TABLESIZE; i++) fast_decode_table[i] = 0;
#endif
        p = 0;
        next_code = 0;
        bit = ((unsigned32)1) << (32-maxlen);
        while (maxlen!=0)
        {   for (i=0; i<CODE_SIZE; i++)
            {   if (length_of_code[i] == maxlen)
                {   huffman_coded_bits[i] = next_code;
                    sorted_huffman_codes[p] = next_code;
                    corresponding_character[p++] = i;
#ifdef EXTRACT
                    fast_decode_table[next_code>>(32-FAST_DECODE_LIMIT)] =
                        (((int32)i)<<16) | maxlen;
#endif
                    next_code += bit;
                }
            }
            if ((next_code & bit) != 0) next_code += bit;
            maxlen--;
            bit = bit<<1;
        }
        while (p < CODE_SIZE) sorted_huffman_codes[p++] = 0xffffffffU;
#ifdef EXTRACT
/*
 * Replicate entries in the fast decoding table to allow for short codes.
 */
        {   int32 prev = fast_decode_table[0];
            for (i=1; i<FAST_DECODE_TABLESIZE; i++)
            {   int32 w = fast_decode_table[i];
                if (w == 0) fast_decode_table[i] = prev;
                else prev = w;
            }
        }
#endif
/*
 * The decoder will over-run if the EOF marker is coded as less than 17
 * bits, so I check specially here to avoid creating unreadable archives.
 */
        if (length_of_code[HUFF_EOF] < 17)
            length_of_code[HUFF_EOF] = 17;
        if (length_of_code[HUFF_EOF+PREDICT_1] < 17)
            length_of_code[HUFF_EOF+PREDICT_1] = 17;
        if (length_of_code[HUFF_EOF+PREDICT_2] < 17)
            length_of_code[HUFF_EOF+PREDICT_2] = 17;
    }
}

static int exp_table[16] =
/* This table gived 256*2^(n/16) to help me log-code frequencies */
{
    256, 267, 279, 292, 304, 318, 332, 347,
    362, 378, 395, 412, 431, 450, 470, 490
};

static int32 expscale(int n)
{
    int r = exp_table[n & 0xf];
    return ((int32)r) << ((n >> 4) & 0xf);
}

static int32 scaleby(int32 a, int32 b)
/* Compute (a*b)/0x01000000 */
{
    int32 al = a & 0xfff, bl = b & 0xfff;
    int32 ah = (a - al) >> 12, bh = (b - bl) >> 12;
    int32 rh = ah*bh, rm = ah*bl + al*bh, rl = al*bl;
    rm += (rl >> 12);
    rh += (rm + 0x800) >> 12;
    return rh;
}

static void initialise_code_tables(int mode, int p1, int p2,
                                   int p11, int p12,
                                   int p21, int p22,
                                   int p1111, int p11111111)
{
    int i;
    int32 sp1 = expscale(p1),
          sp2 = expscale(p2),
          sp11 = expscale(p11),
          sp12 = expscale(p12),
          sp21 = expscale(p21),
          sp22 = expscale(p22),
          sp1111 = expscale(p1111),
          sp11111111 = expscale(p11111111);
    int32 raw = 0x01000000 - sp1-sp2-sp11-sp12-sp21-sp22-sp1111-sp11111111;
    for (i=0; i<CODE_SIZE; i++) char_being_coded[i] = i;
    if (mode & FLAT_STATS)
    {   for (i=0; i<257; i++)
        {   number_of_occurences[i] = scaleby(raw,  0x01000000/257);
            number_of_occurences[PREDICT_1+i] = scaleby(p1,  0x01000000/257);
            number_of_occurences[PREDICT_2+i] = scaleby(p2,  0x01000000/257);
        }
        number_of_occurences[0]++;      /* Very slightly favour chars 0/ff */
        number_of_occurences[0xff]++;
    }
    else
        for (i=0; i<257; i++)
        {   number_of_occurences[i] = scaleby(raw, current_frequencies[i]);
            number_of_occurences[PREDICT_1+i] =
                                      scaleby(sp1, current_frequencies[i]);
            number_of_occurences[PREDICT_2+i] =
                                      scaleby(sp2, current_frequencies[i]);
        }
    number_of_occurences[PREDICT_11]       = sp11;
    number_of_occurences[PREDICT_12]       = sp12;
    number_of_occurences[PREDICT_21]       = sp21;
    number_of_occurences[PREDICT_22]       = sp22;
    number_of_occurences[PREDICT_1111]     = sp1111;
    number_of_occurences[PREDICT_11111111] = sp11111111;

    for (i=0; i<CODE_SIZE; i++)
        if (number_of_occurences[i] < 1)
            number_of_occurences[i] = 1;

    huffman();
    last_three = INITIAL_LAST_THREE;

}

static void initialise_no_prediction(int mode)
{
    int i;
    for (i=0; i<CODE_SIZE; i++)
    {   char_being_coded[i] = i;
        number_of_occurences[i] = 0;
    }
    for (i=0; i<257; i++)
        number_of_occurences[i] =
            (mode & FLAT_STATS) ? (0x01000000/257) :
                                  current_frequencies[i];

    for (i=0; i<PREDICT_1; i++)
        if (number_of_occurences[i] < 1)
            number_of_occurences[i] = 1;

    huffman();
}

#ifdef EXTRACT

static int eofcount = 0;

static int getcx()
{
    int c = getc(archive_file);
    if (c == EOF && ++eofcount > 4)
    {
#ifdef INSTALL
#ifdef __arm
        werr(1, "Corrupted archive file");
#else
        fprintf(err_file, "\nCorrupted archive file\n");
#endif
#else
        fprintf(err_file, "\nCorrupted archive file\n");
#endif
        exit(EXIT_FAILURE);
    }
    return c & 0xff;
}

static int32 get4()
/* See put4() */
{
    int32 w;
    int c = getcx();
    w = (int32)c;
    update_CRC(c);
    c = getcx();
    w = (w<<8) | (int32)c;
    update_CRC(c);
    c = getcx();
    w = (w<<8) | (int32)c;
    update_CRC(c);
    c = getcx();
    w = (w<<8) | (int32)c;
    update_CRC(c);
    return w;
}

#ifdef INSTALL

static int32 show_blip(int32 next_blip, int32 blip_pos)
{
    char blips[64];
#ifdef __ZTC__
    int bk;
    if (blip_pos > 63) blip_pos = 63; /* Just in case! */
    for (bk=0; bk<blip_pos; bk++) blips[bk] = '.';
    blips[blip_pos] = '\n';
    blips[blip_pos+1] = 0;
    show_txt(11, 16, blips);
    disp_move(11, 16+blip_pos);
    disp_flush();
    if (next_blip < 4096) next_blip += 512;
    else next_blip = (20*next_blip)/17;
#endif
#ifdef __arm
    sprintf(blips, "%ldK", (long)next_blip/1024);
    dbox_setfield(window, 13, blips);
    event_setmask(0);   /* permits null events to show up */
    event_process();
    next_blip += 1024;
#endif
    return next_blip;
}

#endif

#ifdef __ZTC__
static int msgpos;
#endif

static int junknumber = 0;

static FILE *openoutput(char *name, int mode_flag, long int previous_position)
{
    char *openmode;
    FILE *output_file;
#ifdef NO_BINARY_FOPEN
    mode_flag &= ~BINARY_FILE;
#endif
    switch (mode_flag & (BINARY_FILE|SPLIT_FILE))
    {
default:
case 0: openmode = "w";
        break;
case BINARY_FILE:
        openmode = "wb";
        break;
case SPLIT_FILE:
        openmode = "r+";
        break;
case BINARY_FILE|SPLIT_FILE:
        openmode = "r+b";
        break;
    }
#ifdef INSTALL
#ifdef __arm
/*
 * I expand the archive filename to be a fully-rooted path using the
 * directory as selected by the install utility.  At present ACN has
 * forgotten what this was for, but is leaving the code in in case he
 * remembers sometime later on.
 */
    {   char temp[LONGEST_LEGAL_FILENAME];
        strcpy(temp, name);
        if (temp[0] == '^' && temp[1] == '.')
            sprintf(name, "%s.%s", ins_filename, &temp[2]);
        else sprintf(name, "%s.cslarm.%s", ins_filename, temp);
    }
#endif
#endif
    output_file = fopen(name, openmode);
/*
 * If I failed to open the file on my first attempt I will have a go at
 * directory creation on all initial substrings of the complete file-name
 * that I am working on.
 */
    if (output_file == NULL)
    {   char *p = name;
        int dc;
        while ((dc = *p) != 0)
        {   if (dc == DIRECTORY_CHAR)
            {   int r;
                *p = 0;
                fprintf(err_file, "\nAttempting to create directory \"%s\"\n", name);
                r = Cmkdir(name);
                *p = dc;
            }
            p++;
        }
/*
 * Furthermore if I first tried to open the file in "r+" mode (so I could
 * update it, expecting there to be (perhaps) some data already in the file,
 * then on the second try I just use "w" mode to create a new file.
 */
        if (mode_flag & BINARY_FILE) openmode = "wb";
        else openmode = "w";
        output_file = fopen(name, openmode);
    }
    if (output_file == NULL)
    {
#ifdef INSTALL
#ifdef __arm
        werr(1, "Unable to create \"%s\"", name);
#else
        fprintf(err_file, "Unable to create \"%s\"\n", name);
#endif
#else
        fprintf(err_file, "Unable to create %s\n", name);
#endif
        if (!skip_errors) exit(EXIT_FAILURE);
        else
        {   char junkname[32];
            sprintf(junkname, "Junk%04d.tmp", junknumber++);
            output_file = fopen(junkname, openmode);
            if (output_file != NULL)
                fprintf(err_file, "\nPutting file in \"%s\"", junkname);
        }
    }
    if (mode_flag & SPLIT_FILE)
        fseek(output_file, previous_position, SEEK_SET);
    return output_file;
}

#ifndef INSTALL
#define N_LIMIT 50
#define N_COUNT 100

static int new_files_n = 0, changed_files_n = 0;
static char new_files[N_COUNT][N_LIMIT];
static char changed_files[N_COUNT][N_LIMIT];
#endif

static bool extract_files()
/*
 * returns FALSE when the end of the archive is reached.
 */
{
    char name[LONGEST_LEGAL_FILENAME],
         unixname[LONGEST_LEGAL_FILENAME],
         *msg = just_list_contents == excar_c ? "Comparing" :
                just_list_contents == excar_t ? "Would unpack" : "Unpacking";
    int c, n, mode_flag;
    int32 filetype, file_size, cl;
    unsigned32 datestamp, w;
    long int previous_position = -1;
    FILE *output_file;
#ifdef INSTALL
    int32 next_blip = 0, blip_pos = 0;
#else
    FILE *cmp_file = NULL;
    int cmp_res = 0;
#endif
/*
 * The archive of an individual file starts with its name, which is
 * stored as a string of characters terminated by a zero.
 */
    n = 0;
    while ((c = getc(archive_file)) != 0)
    {
        if (c == EOF) return FALSE; /* Probably corrupted archive file */
        unixname[n++] = c;
/*
 * The CRC check that I compute includes the Unix-like form of the
 * file-name, since that does not change across machines.
 */
        update_CRC(c & 0xff);
    }
    if (n == 0) return FALSE; /* empty name denotes end of archive */
    unixname[n] = 0;
    adjust_file_name(name, unixname);
#ifdef INSTALL
    {   char buf[64];
        sprintf(buf, "%s %s ...\n", msg, name);
#ifdef __ZTC__
        msgpos = strlen(buf) - 4;
        show_txt(10, 16, buf);
#endif
#ifdef __arm
        dbox_setfield(window, 12, buf);
#endif
    }
#else
    fprintf(err_file, "%s %s:", msg, name);
#endif

/*
 * I then have 8 bytes of date and filetype information
 */
    datestamp = get4();
    filetype = get4();
/* And one byte to tell me about the packing mode that was used */
    mode_flag = getcx();
    update_CRC(mode_flag);
    if (mode_flag & SPLIT_FILE) previous_position = (long int)get4();

#ifndef INSTALL
    if (just_list_contents == excar_c)
    {   cmp_file = fopen(name, (mode_flag & BINARY_FILE) ? RB_MODE : "r");
        cmp_res = cmp_file == NULL ? 1 : 2;
    }
#endif
    if (just_list_contents == excar_x)
        output_file = openoutput(name, mode_flag, previous_position);
    else output_file = NULL;
/*
 * Now decode the contents of the file...
 */
    file_size = 0;
    for (;;)  /* Iteration across blocks in the file */
    {
        if ((mode_flag & (USE_CURRENT|FLAT_STATS)) == 0)
        {   if (mode_flag & EXPLICIT_STATS)
            {   int i;
                for (i=0; i<256; i++)
                {   int c = getcx();
                    update_CRC(c);
                    current_frequencies[i] = expscale(c);
                }
                current_frequencies[256] = 0;
            }
            else memcpy(current_frequencies, default_frequencies,
                        sizeof(default_frequencies));
        }

        if (mode_flag & NO_PREDICT) initialise_no_prediction(mode_flag);
        else
        {   int p1 = getcx();
            int p2 = getcx();
            int p11 = getcx();
            int p12 = getcx();
            int p21 = getcx();
            int p22 = getcx();
            int p1111 = getcx();
            int p11111111 = getcx();
            update_CRC(p1); update_CRC(p2);
            update_CRC(p11); update_CRC(p12);
            update_CRC(p21); update_CRC(p22);
            update_CRC(p1111); update_CRC(p11111111);
            initialise_code_tables(mode_flag, p1, p2,
                                   p11, p12, p21, p22, p1111, p11111111);
        }

        n = 0;      /* Number of bits valid in the input buffer */
        w = 0;      /* input buffer                             */
        for (;;)
        {   int l;
             int32 run = 0;
/*
 * I read bytes from the archive until I have at least 25 bits
 * collected in my buffer (the word w).
 */
            while (n<=24)
            {   c = getcx();
                w |= ((int32)c) << (24-n);
                n += 8;
            }
/*
 * If the Huffman code was short enough I can decode with just a table
 * look-up - otherwise I do a search.
 */
            cl = fast_decode_table[w >> (32-FAST_DECODE_LIMIT)];
            l = (int)(cl & 0xffffU);
            if (l <= FAST_DECODE_LIMIT) c = (int)(cl >> 16);
                                        /* Short code: do rapidly */
            else
            {   if (w >= sorted_huffman_codes[CODE_SIZE-1]) c = CODE_SIZE-1;
                else
                {   int low = 0, high = CODE_SIZE-1;
                    while (high != low+1)
                    {   int mid = (high+low)/2;
                        unsigned32 v = sorted_huffman_codes[mid];
                        if (w >= v) low = mid;
                        else high = mid;
                    }
                    c = low;
                }
                c = corresponding_character[c];
                l = length_of_code[c];
            }
/*
 * Shift the buffer to remove the code I have just processed.
 */
            w = w << l;
            n -= l;
            switch (c)
            {
        case PREDICT_11:
                run = 1;
                c = prediction1[last_three];
                break;
        case PREDICT_12:
                run = -1;
                c = prediction1[last_three];
                break;
        case PREDICT_21:
                run = 1;
                c = prediction2[last_three];
                break;
        case PREDICT_22:
                run = -1;
                c = prediction2[last_three];
                break;
        case PREDICT_1111:
                run = 3;
                c = prediction1[last_three];
                break;
        case PREDICT_11111111:
                run = 7;
                c = prediction1[last_three];
                break;
        default:
                if (c >= PREDICT_2)
                {   int c1 = prediction2[last_three];
                    c -= PREDICT_2;
                    prediction2[last_three] = prediction1[last_three];
                    prediction1[last_three] = c1;
                    last_three = ((last_three << PREDICTION_SHIFT) + c1) &
                                 PREDICTION_MASK;
/*
 * The code here relies on the fact that the EOF marker can never have been
 * predicted: "NOBODY expects the ..."!
 */
                    if (output_file) putc(c1, output_file);
#ifndef INSTALL
                    if (cmp_file && c1 != getc(cmp_file) & 0xff) cmp_res = 3;
#endif
                    update_CRC(c1);
#ifdef INSTALL
                    if (file_size >= next_blip)
                        next_blip = show_blip(next_blip, blip_pos++);
#endif
                    file_size++;
                }
                else if (c >= PREDICT_1)
                {   int c1 = prediction1[last_three];
                    c -= PREDICT_1;
                    last_three = ((last_three << PREDICTION_SHIFT) + c1) &
                                 PREDICTION_MASK;
                    if (output_file) putc(c1, output_file);
#ifndef INSTALL
                    if (cmp_file && c1 != getc(cmp_file) & 0xff) cmp_res = 3;
#endif
                    update_CRC(c1);
                    file_size++;
#ifdef INSTALL
                    if (file_size >= next_blip)
                        next_blip = show_blip(next_blip, blip_pos++);
#endif
                }
                run = 0;
                break;
            }
            for (;;)
            {   if (c == HUFF_EOF) break;
                else if ((mode_flag & NO_PREDICT) == 0)
                {   if (c != prediction1[last_three])
                    {   prediction2[last_three] = prediction1[last_three];
                        prediction1[last_three] = c;
                    }
                    last_three = ((last_three << PREDICTION_SHIFT) + c) &
                                 PREDICTION_MASK;
                }
                if (output_file) putc(c, output_file);
#ifndef INSTALL
                if (cmp_file && c != getc(cmp_file) & 0xff) cmp_res = 3;
#endif
                update_CRC(c);
                file_size++;
#ifdef INSTALL
                if (file_size >= next_blip)
                    next_blip = show_blip(next_blip, blip_pos++);
#endif
                if (run == 0) break;
                else if (run > 0) run--, c = prediction1[last_three];
                else run++, c = prediction2[last_three];
            }
#ifdef INSTALL
#ifdef __arm
            if (please_stop) break;
#endif
#endif
            if (c == HUFF_EOF) break;
        }

/*
 * Note that I may have read a byte or two ahead of myself here.
 * If HUFF_EOF is at least a 17-bit code then I know I can have at worst
 * one character to push back, and that I can do with ungetc.
 */
        if (n >= 8) ungetc((int)(w >> (32-n)), archive_file);
        if (mode_flag & FINAL_BLOCK) break;
#ifdef INSTALL
#ifdef __arm
        if (please_stop) break;
#endif
#endif
        mode_flag = getcx();
        update_CRC(mode_flag);
    }

    if (output_file)
    {   if (mode_flag & SPLIT_FILE)
            truncate_file(output_file, ftell(output_file));
/* If I just processed the last segment of a split file truncate it here */
        fclose(output_file); /* check for write-errors? */
    }
#ifndef INSTALL
    if (cmp_file)
    {   if (getc(cmp_file) != EOF && cmp_res == 2) cmp_res = 4;
        fclose(cmp_file);
    }
#endif
    if (just_list_contents == excar_x)
        set_filedate(name, datestamp, filetype);
    {   char *cmp_str = "";
#ifndef INSTALL
        switch (cmp_res)
        {
    case 0:  cmp_str = "";
             break;
    case 1:  cmp_str = " (missing)";
             if (new_files_n < N_COUNT)
                 sprintf(&new_files[new_files_n++][0], "%.*s",
                         N_LIMIT-1, name);
             break;
    case 2:  cmp_str = " (equal)";
             break;
    case 4:  cmp_str = " (truncated)";
             if (changed_files_n < N_COUNT)
                 sprintf(&changed_files[changed_files_n++][0], "%.*s",
                         N_LIMIT-1, name);
             break;
    default: cmp_str = " (differs)";
             if (changed_files_n < N_COUNT)
                 sprintf(&changed_files[changed_files_n++][0], "%.*s",
                         N_LIMIT-1, name);
             break;
        }
#endif
#ifdef INSTALL
#ifdef __ZTC__
        {   char buf[64];
            sprintf(buf, " %ld bytes%s\n", (long)file_size, cmp_str);
            show_txt(10, msgpos+16, buf);
        }
#endif
#else
        fprintf(err_file, " %ld bytes%s\n", (long)file_size, cmp_str);
    }
#endif
#ifdef INSTALL
#ifdef __arm
    if (please_stop) return FALSE;
#endif
#endif
    return TRUE;
}

#else /* EXTRACT */

static int32 squot(int32 p, int32 q)
/* Compute 0x01000000*p/q (roughly) given that p <= q */
{
    while ((q & 0x20000000) == 0) p = 2*p, q = 2*q;
    q = q >> 16;
    p = p/q;
    return (p << 8);    /* 14 or 15 bits good, I guess */
}

static int logscale(int32 p, int32 q)
/*
 * When I write frequencies into the archive (to allow me to establish
 * my decoding tables) I put them in log-scaled as 8-bit values.  This
 * code performs the encoding, while expscale() performs the inverse
 * mapping.  Ultimate accuracy is not vital here.
 * My representation is a fixed point fraction with 4 bits before and
 * 4 after the point, with the number representing a logarithm base 2.
 * Do all calculations here in integers so that floating point C library
 * does not have to be loaded.
 */
{
    unsigned32 r;
    int v = 256;
    if (p == 0) p = 1;
    if (q == 0) q = 1;
    if (p >= q) return 255;
    while ((q & 0x20000000) == 0) p = 2*p, q = 2*q;
    while ((r = 2*p) < (unsigned32)q) p = r, v -= 0x10;
    r = p / (q >> 16);
    r = (r * (unsigned32)0xfa84U) >> 16;
    if (r < 0x8000U) v -= 0x10, r = 2*r;
    if (r < 0xb505U) v -= 0x08, r = (r << 16) / 0xb505U;
    if (r < 0xd745U) v -= 0x04, r = (r << 16) / 0xd745U;
    if (r < 0xeac1U) v -= 0x02, r = (r << 16) / 0xeac1U;
    if (r < 0xf529U) v -= 0x01; r = (r << 16) / 0xf529U;
    if (v > 255) return 255;
    else if (v < 0) return 0;
    else return v;
}

static void put4(int32 n)
{
    int c1 = (int)(n >> 24),
        c2 = (int)(n >> 16),
        c3 = (int)(n >> 8),
        c4 = (int)n;
    update_CRC(c1 &= 0xff);
    update_CRC(c2 &= 0xff);
    update_CRC(c3 &= 0xff);
    update_CRC(c4 &= 0xff);
    putc(c1, archive_file);
    putc(c2, archive_file);
    putc(c3, archive_file);
    putc(c4, archive_file);
    current_archive_size += 4;
}

static void write_fileinfo(char *name)
{
    date_and_type x;
    unsigned32 dd, tt;
    put_fileinfo(&x, name);
    dd = x.date, tt = x.type;
    put4(dd);
    put4(tt);
}

static void put_string(char *s)
{
    int c;
    while ((c = *s++) != 0)
    {   putc(c, archive_file);
        update_CRC(c & 0xff);
        current_archive_size++;
    }
    putc(0, archive_file);
    current_archive_size++;
}

static void terminate_archive_file()
{
    if (archive_file != NULL)
    {   int32 r;
        int w, w1;
        putc(0, archive_file);
        put4(CRC);
        fclose(archive_file); /* Should I check for errors here? */
        archive_file = NULL;
        if (current_raw_size == 0) current_raw_size = 1;
        if (current_raw_size < 10000)
            w = (int)((10000*current_archive_size)/current_raw_size);
        else
        {   r = current_raw_size/100;
            w = (int)((100*current_archive_size)/r);
        }
        w1 = w % 100;
        fprintf(err_file, "Compacted archive is %d.%d%d%% of input size\n",
                        w/100, w1/10, w1%10);
    }
}

static void transmit_file(char *name, int dirp, long int size)
/*
 * This is called once for every file that is to be dumped.  It packs
 * the named file into the archive.
 */
{
    int mode_flag, binary_flag = binary_mode;
    int32 previous_bulk;
    char unixname[LONGEST_LEGAL_FILENAME];
    long int previous_position = -1;
    FILE *input_file;
    bool true_eof = FALSE, first_block, will_not_fit;
    int i;
    for (i=0; i<n_omitted_files; i++)
    {   if (wildmatch(omitted_files[i], name))
        {   fprintf(err_file, "Omitting \"%s\"\n", name);
            switch (dirp)
            {
        case SCAN_FILE:     return; /* just drop this one */
        case SCAN_STARTDIR: omitting++; return;
        case SCAN_ENDDIR:   omitting--; return;
            }
        }
    }
    if (dirp != SCAN_FILE || omitting) return;
    if (!binary_mode)
    {   int i, c;
        input_file = fopen(name, RB_MODE);
        if (input_file == NULL)
        {   fprintf(err_file, "Failed to open \"%s\"\n", name);
            exit(EXIT_FAILURE);
        }
        for (i=0; i<4096; i++)
        {   c = getc(input_file);
            if (c == EOF) break;
/*
 * Here if the file contains a code under 7 or over 127 I handle it as
 * a binary file. I just scan the first 4K of the file to look for such
 * funny characters, but hope and expect that in most cases this will be
 * pretty reliable. People who really care should use "-a" and "-b" flags
 * for themselves. Note that even after a flag "-a" I will handle files
 * that contain odd characters in binary. Observe that CR, LF, TAB, FF
 * and the ^Z that DOS sometimes uses for EOF do NOT trigger binary
 * treatment. I also make an exception for the two codes that stand for
 * the Copyright Symbol in different PC code pages.
 */
            if (c < 7 || ((c & 0x80)!=0 && c!=0xa9 && c!=0xb8))
            {   binary_mode = 1;
                fprintf(err_file, "Will handle %s in binary mode\n", name);
                break;
            }
        }
        fclose(input_file);
    }
    input_file = fopen(name, binary_mode ? RB_MODE : "r");
    if (input_file == NULL)
    {   fprintf(err_file, "Failed to open \"%s\"\n", name);
        exit(EXIT_FAILURE);
    }
    for (;;)  /* For all the segments that make up this file... */
    {
        int32 bytes_handled = 0;
/*
 * If there is a current archive with at least one file stored in it already
 * and if the new file would (with a very rough estimate about compression
 * ratios) make it grow to be bigger than ideal_archive_size then terminate
 * the archive (with a zero byte) and arrange that a new one will be opened
 * in its stead.  The compression estimate I use is based on what has happened
 * so far in the present archive.  If ideal_archive_size is specified as zero
 * then I write everything to just one file.  And in that case I do not add
 * sequence numbers to the name of the archive file that I send stuff to.
 */
        {   int32 w1 = size/10000U;
            int32 w2 = current_archive_size/10000U;
            int32 w3, size_guess;
            will_not_fit = FALSE;
            if (w1 == 0) w1 = 1;
            if (w2 == 0) w2 = 1;
            w3 = current_raw_size/(w1*w2);
            if (w3 == 0) w3 = 1;
/*
 * Fun here performing a scale calculation in fixed point arithmetic.
 * I "guess" that the next file will compress at the same ratio as has
 * been achieved overall so far, and include it in this volume of the
 * archive if that will not cause overflow beyond the "ideal" size.  Note that
 * this does not guarantee to keep individual volumes within the size
 * guide.  I also only terminate the archive if I have already made it at
 * least 3/4 of the ideal size.  The aim here is to allow me to split
 * very large files into chunks if I have to.  I will also avoid tring to
 * split files that are smaller than BLOCK_SIZE since that would lead to
 * over-use of the header bits that I use to discriminate between start
 * and stop segments in the archive.
 */
            if (current_archive_size < 30000) size_guess = size/2;
            else size_guess = ((size/w1)*(current_archive_size/w2))/w3;
            if (ideal_archive_size != 0 && binary_mode &&
                size_guess > ideal_archive_size) will_not_fit = TRUE;
            if (ideal_archive_size != 0 &&
                archive_file != NULL &&
                current_archive_count != 0 &&
                (current_archive_size + size_guess) > ideal_archive_size)
            {   if (current_archive_size >
                            ideal_archive_size - ideal_archive_size/4 ||
                    !binary_mode ||
                    size < BLOCK_SIZE+100)
                    terminate_archive_file();
                else will_not_fit = TRUE;
            }
            if (will_not_fit && previous_position == -1) previous_position = 0;
        }
/*
 * If an output file is not already open then open one here.
 * Construct name for archive file and open it.
 */
        if (archive_file == NULL)
        {   int32 i;
            archive_file_number++;
            if (ideal_archive_size == 0)
                sprintf(unixname, "%s", archive_file_name);
            else sprintf(unixname, "%s%d", archive_file_name,
                                           archive_file_number);
            archive_file = fopen(unixname, WB_MODE);
            if (archive_file == NULL)
            {   fprintf(err_file, "Unable to open %s for output\n", unixname);
                exit(EXIT_FAILURE);
            }
            fprintf(err_file, "========== Create:  %s\n", unixname);
            current_archive_size = current_raw_size =
                                   current_archive_count = 0;
            CRC = 1;
/*
 * A fresh archive file can not properly make use of information left over
 * from previous ones in the same series...
 */
            for (i=0; i<PREDICTION_SIZE; i++)
            {   prediction1[i] = ' ';
                prediction2[i] = '\n';
            }
            memcpy(current_frequencies, default_frequencies,
                   sizeof(default_frequencies));
        }
/*
 * In the name of having portable archives I will write the name into
 * the archive file converted to look the way it would under Unix.
 */
        fprintf(err_file, "%s:  ", name);
        unadjust_file_name(unixname, name);
/*
 * I insert the name of the file uncompressed, and an empty name would
 * indicate the end of the archive.
 */
        put_string(unixname);
/*
 * Now I dump 8 bytes of directory information - first a timestamp given
 * as a time, measured in seconds, since 1970.  This seems to be what Unix
 * uses in (e.g.) tar files.  Then I put out 4 bytes of "filetype" information,
 * and I admit that this will not be very portable.  For Acorn machines it will
 * hold just what its name suggests - for Unix it could hold uid and gid info.
 * If unused it should contain zero.
 */
        write_fileinfo(name);
        first_block = TRUE;
        previous_bulk = current_archive_size;
        current_archive_count++;

        do  /* Loop doing a sequence of blocks... */
        {
/*
 * Read up to BLOCK_SIZE characters into a buffer that can be used
 * when deciding what compression mode to use.
 */
            {   unsigned char *look_ahead_p = look_ahead_buffer;
                int c = EOF;
                look_ahead_count = 0;
/*
 * I read either until I fill the buffer or until I reach the
 * end of the source file. Note that there is no real guarantee
 * that the size I was told about for the file will be accurate -
 * e.g. it may be the size on disc where newline is represented
 * by the character-pair CR/LF, while C reads it as just '\n'.
 */
                while (look_ahead_count < BLOCK_SIZE &&
                       (c = getc(input_file)) != EOF)
                {   *look_ahead_p++ = c;
                    look_ahead_count++;
                }
                if (will_not_fit && c == EOF)
                {   ungetc(c, input_file);
                    c = '\n';
                }
                will_not_fit = FALSE;
                bytes_handled = look_ahead_count;
                total_bulk += look_ahead_count;
                current_raw_size += look_ahead_count;
                mode_flag = 0;
                if (binary_mode) mode_flag |= BINARY_FILE;
                if (c == EOF)
                {   mode_flag |= FINAL_BLOCK;
                    if (previous_position != -1) mode_flag |= SPLIT_FILE;
                    true_eof = TRUE;
                }
            }
            if (previous_position != -1 && first_block)
                mode_flag |= SPLIT_FILE;
/*
 * I do NOT split non-binary files, since fseek/ftell are not very reliable
 * as ways of re-positioning myself when trying to reconstruct a split-up
 * text file.
 */
            if (binary_mode && ideal_archive_size != 0 &&
                (current_archive_size >=
                 ideal_archive_size - look_ahead_count/2))
                mode_flag |= FINAL_BLOCK;
/*
 * Here I select an encoding scheme based on the sample I
 * have just taken.
 */
            if (look_ahead_count < 40) /* Very short/empty file case */
            {   mode_flag |= NO_PREDICT|FLAT_STATS; /* do not compress */
                initialise_no_prediction(mode_flag);
            }
            else
            {   int32 i;
                int32 run = 0;
                unsigned char *look_ahead_p = look_ahead_buffer;

                for (i=0; i<CODE_SIZE; i++) number_of_occurences[i] = 0;
/*
 * What follows is a copy of the prediction-coder, but the results from it
 * are just used to collect statistics of character-frequencies, and not to
 * send any bytes to the archive.  Note that I use copies of the prediction
 * arrays - this allows prediction information built up while compressing
 * one file to help with the next.
 */
                memcpy(prediction1a, prediction1, (size_t)PREDICTION_SIZE);
                memcpy(prediction2a, prediction2, (size_t)PREDICTION_SIZE);
                last_three = INITIAL_LAST_THREE;

                for (i=0; i<look_ahead_count; i++)
                {   int c = *look_ahead_p++;
                    {   int c1 = c & 0xff;
                        if (c1 == prediction1a[last_three]) c = PREDICT_1;
                        else
                        {   if (c1 == prediction2a[last_three]) c = PREDICT_2;
                            else c = c1;
                            prediction2a[last_three] =
                                             prediction1a[last_three];
                            prediction1a[last_three] = c1;
                        }
                        last_three = ((last_three << PREDICTION_SHIFT) + c1) &
                                     PREDICTION_MASK;
                    }
                    if (c == PREDICT_1)
                    {   while (run <= -2)
                        {   run += 2;
                            number_of_occurences[PREDICT_22]++;
                        }
                        if (run >= 0)
                        {   run++;
                            continue;
                        }
                        else if (run == -1)
                        {   run = 0;
                            c = PREDICT_21;
                        }
                    }
                    else if (c == PREDICT_2)
                    {   while (run >= 8)
                        {   run -= 8;
                            number_of_occurences[PREDICT_11111111]++;
                        }
                        while (run >= 4)
                        {   run -= 4;
                            number_of_occurences[PREDICT_1111]++;
                        }
                        while (run >= 2)
                        {   run -= 2;
                            number_of_occurences[PREDICT_11]++;
                        }
                        if (run <= 0)
                        {   run--;
                            continue;
                        }
                        if (run == 1)
                        {   run = 0;
                            c = PREDICT_12;
                        }
                    }
                    else
                    {   while (run >= 8)
                        {   run -= 8;
                            number_of_occurences[PREDICT_11111111]++;
                        }
                        while (run >= 4)
                        {   run -= 4;
                            number_of_occurences[PREDICT_1111]++;
                        }
                        while (run >= 2)
                        {   run -= 2;
                            number_of_occurences[PREDICT_11]++;
                        }
                        while (run <= -2)
                        {   run += 2;
                            number_of_occurences[PREDICT_22]++;
                        }
                        if (run > 0) c += PREDICT_1;
                        else if (run < 0) c += PREDICT_2;
                        run = 0;
                    }
                    number_of_occurences[c]++;
                }
            }
/*
 * Now I have proper counts that relate to BLOCK_SIZE characters in
 * the source file.  Based on that I must establish a set of Huffman
 * code tables.
 */
            {   int i;
                int32 total=0, p1=0, p2=0,
                    p11=number_of_occurences[PREDICT_11],
                    p12=number_of_occurences[PREDICT_12],
                    p21=number_of_occurences[PREDICT_21],
                    p22=number_of_occurences[PREDICT_22],
                    p1111=number_of_occurences[PREDICT_1111],
                    p11111111=number_of_occurences[PREDICT_11111111];
                for (i=0; i<256; i++)
                {   total += number_of_occurences[i];
                    total += number_of_occurences[PREDICT_1+i];
                    p1    += number_of_occurences[PREDICT_1+i];
                    total += number_of_occurences[PREDICT_2+i];
                    p2    += number_of_occurences[PREDICT_2+i];
                    number_of_occurences[i] +=
                        number_of_occurences[PREDICT_1+i] +
                        number_of_occurences[PREDICT_2+i];
                }
/*
 * I now have a byte that gives information about the compression mode that I
 * am using and the ascii/binary status of the file.
 */
                if (32*(p1+p2) < total) mode_flag |= NO_PREDICT;
/*
 * I will try to estimate the size of the compressed file using several
 * possible Huffman-tables, and choose the one that will work best
 * for me.
 */
                {   int32 eight = ((int32)8)<<24,
                          eight_bit = 0,
                          ideal = 0,
                          alpha_freq = 0,
                          current = 0;
                    if ((mode_flag & NO_PREDICT) == 0)
                    {   int32 raw = total - p1 - p2;
/*
 * If I was not doing any prediction then each byte would be sent in
 * just 8 bits - however if prediction is enabled I have roughly
 * three times as many codes to discriminate between, and the
 * following calculation estimates the average number of bits per code
 * that will be used.
 */
                        int32 dt = total == 0 ? 1 : total,
                              dr = raw == 0 ? 1 : raw,
                              dp1 = p1 == 0 ? 1 : p1,
                              dp2 = p2 == 0 ? 1 : p2;
#define log2(a, b) ((0x100 - (int32)logscale(b, a)) << 20)
                        eight += scaleby(log2(dt, dr), squot(dr, dt));
                        eight += scaleby(log2(dt, dp1), squot(dp1, dt));
                        eight += scaleby(log2(dt, dp2), squot(dp2, dt));
                    }
                    for (i=0; i<256; i++)
                    {   int32 f1 = number_of_occurences[i];
                        int32 f2 = default_frequencies[i];
                        int32 f3 = current_frequencies[i];
                        if (f1 == 0) f1 = 1;
                        if (f2 == 0) f2 = 1;
                        if (f3 == 0) f3 = 1;
                        eight_bit += scaleby(eight, f1);
                        ideal += scaleby(log2(total, f1), f1);
                        alpha_freq += scaleby(log2(0x01000000, f2), f1);
                        current += scaleby(log2(0x01000000, f3), f1);
                    }
#define OVERHEAD 4000    /* Controls when explicit frequency table is used */
                    if ((ideal+OVERHEAD) < eight_bit &&
                        (ideal+OVERHEAD) < alpha_freq &&
                        (ideal+OVERHEAD) < current)
                        mode_flag |= EXPLICIT_STATS;
                    else if (eight_bit < alpha_freq &&
                             eight_bit < current)
                        mode_flag |= FLAT_STATS;
                    else if (current <= alpha_freq)
                        mode_flag |= USE_CURRENT;
                }

                putc(mode_flag, archive_file);
                current_archive_size++;
                update_CRC(mode_flag);
                if (previous_position != -1 && first_block)
                    put4((int32)previous_position), first_block = FALSE;
/*
 * In some cases I find it worth-while to send 256 bytes of character-
 * frequency information to define the Huffman code that will be used.  This
 * is only done if it seems that the overhead at the start of the file will
 * be recovered because of the better compaction later on.  If both are
 * present the 256 bytes occure before 8 bytes that give frequencies of
 * special prediction codes.
 */
                if (mode_flag & EXPLICIT_STATS)
                {   for (i=0; i<256; i++)
                    {   int f = logscale(number_of_occurences[i], total);
                        putc(f, archive_file);
                        update_CRC(f);
                        current_frequencies[i] = expscale(f);
                    }
                    current_frequencies[256] = 0;
                    current_archive_size += 256;
                }
                else if ((mode_flag & (USE_CURRENT|FLAT_STATS)) == 0)
                    memcpy(current_frequencies, default_frequencies,
                           sizeof(default_frequencies));

/*
 * Now frequencies are ready - set up Huffman tables.
 */
                if (mode_flag & NO_PREDICT)
                    initialise_no_prediction(mode_flag);
                else
                {   total += p11+p12+p21+p22+p1111+p11111111;
                    p1  = logscale(p1,  total);
                    p2  = logscale(p2,  total);
                    p11 = logscale(p11, total);
                    p12 = logscale(p12, total);
                    p21 = logscale(p21, total);
                    p22 = logscale(p22, total);
                    p1111 = logscale(p1111, total);
                    p11111111 = logscale(p11111111, total);
/*
 * If I use prediction at all I will send 8 bytes giving the frequencies
 * that I associate with various prediction modes.
 */
                    putc((int)p1, archive_file);
                    putc((int)p2, archive_file);
                    putc((int)p11, archive_file);
                    putc((int)p12, archive_file);
                    putc((int)p21, archive_file);
                    putc((int)p22, archive_file);
                    putc((int)p1111, archive_file);
                    putc((int)p11111111, archive_file);
                    update_CRC((int)p1 & 0xff);
                    update_CRC((int)p2 & 0xff);
                    update_CRC((int)p11 & 0xff);
                    update_CRC((int)p12 & 0xff);
                    update_CRC((int)p21 & 0xff);
                    update_CRC((int)p22 & 0xff);
                    update_CRC((int)p1111 & 0xff);
                    update_CRC((int)p11111111 & 0xff);
                    current_archive_size += 8;
                    initialise_code_tables(mode_flag, (int)p1, (int)p2,
                                           (int)p11, (int)p12, (int)p21,
                                           (int)p22, (int)p1111,
                                           (int)p11111111);
                }
            }

/*
 * Finally, the actual file-compresion code.
 */
            {   int32 w = 0, z = 0;
                int n = 0, c;
                int32 run = 0;
                unsigned char *look_ahead_p = look_ahead_buffer;
                do
                {   unsigned32 k;
                    int l;
#define out_bitstring(cc) { k = (unsigned32)huffman_coded_bits[cc];     \
                            l = length_of_code[cc];                     \
                            w |= (k >> n);                              \
                            n += l;                                     \
                            while (n >= 8)                              \
                            {   putc((int)(w >> 24), archive_file);     \
                                z++;                                    \
                                w = w << 8;                             \
                                n -= 8;                                 \
                            }                                           \
                          }
/*
 * If the character I want to process next was buffered retrieve it from
 * the buffer, otherwise read it from the file.
 */
                    if (look_ahead_count != 0)
                    {   c = (*look_ahead_p++) & 0xff;
/*
 * Since I have made the look-ahead buffer an array of unsigned characters
 * the value retrieved here will be in the range 0-0xff, and I really hope
 * that that avoids confusion with EOF.  In particular if I used signed
 * characters on a machine where EOF is represented by (-1) then a byte
 * 0xff in the (binary?) file could look like a (premature) end of file
 * marker.
 */
                        look_ahead_count--;
                        update_CRC(c);
                        if ((mode_flag & NO_PREDICT) == 0)
                        {   int c1 = c;
                            if (c == prediction1[last_three]) c = PREDICT_1;
                            else
                            {   if (c == prediction2[last_three])
                                    c = PREDICT_2;
                                prediction2[last_three] =
                                    prediction1[last_three];
                                prediction1[last_three] = c1;
                            }
                            last_three = ((last_three << PREDICTION_SHIFT) + c1) &
                                         PREDICTION_MASK;
                        }
                    }
                    else c = HUFF_EOF;

                    if (c == PREDICT_1)
                    {   while (run <= -2)
                        {   run += 2;
                            out_bitstring(PREDICT_22);
                        }
                        if (run >= 0)
                        {   run++;
                            continue;
                        }
                        else if (run == -1)
                        {   run = 0;
                            c = PREDICT_21;
                        }
                    }
                    else if (c == PREDICT_2)
                    {   while (run >= 8)
                        {   run -= 8;
                            out_bitstring(PREDICT_11111111);
                        }
                        while (run >= 4)
                        {   run -= 4;
                            out_bitstring(PREDICT_1111);
                        }
                        while (run >= 2)
                        {   run -= 2;
                            out_bitstring(PREDICT_11);
                        }
                        if (run <= 0)
                        {   run--;
                            continue;
                        }
                        if (run == 1)
                        {   run = 0;
                            c = PREDICT_12;
                        }
                    }
                    else
                    {   while (run >= 8)
                        {   run -= 8;
                            out_bitstring(PREDICT_11111111);
                        }
                        while (run >= 4)
                        {   run -= 4;
                            out_bitstring(PREDICT_1111);
                        }
                        while (run >= 2)
                        {   run -= 2;
                            out_bitstring(PREDICT_11);
                        }
                        while (run <= -2)
                        {   run += 2;
                            out_bitstring(PREDICT_22);
                        }
                        if (run > 0) c += PREDICT_1;
                        else if (run < 0) c += PREDICT_2;
                        run = 0;
                    }
                    out_bitstring(c);

                } while (c != HUFF_EOF &&
                         c != (HUFF_EOF+PREDICT_1) &&
                         c != (HUFF_EOF+PREDICT_2));

/*
 * I can have a partially-filled byte left over here - put it out to
 * complete to packed file.
 */
                if (n != 0)
                {   putc((int)(w >> 24), archive_file);
                    z++;
                }
                current_archive_size += z;
            }
        } while ((mode_flag & FINAL_BLOCK) == 0);
        if (true_eof) break;
        previous_position = ftell(input_file);
        size -= bytes_handled;
        fprintf(err_file,"%ld -> %ld bytes (PART ONLY)\n", (long)bytes_handled,
                (long)current_archive_size - (long)previous_bulk);
    }
    fclose(input_file);
    fprintf(err_file,"%ld -> %ld bytes\n", (long)size,
            (long)current_archive_size - (long)previous_bulk);
    binary_mode = binary_flag;
}

static void process_switch(char *a)
{
    int32 v;
    char *w;
    switch(a[1])
    {
case 'a':
case 'A':   binary_mode = FALSE;
            break;
case 'b':
case 'B':   binary_mode = TRUE;
            break;
case 'o':
case 'O':   if (n_omitted_files>=MAX_OMISSIONS)
            {   fprintf(err_file, 
                        "Too many \"-O\" requests: ignore this one\n");
                break;
            }
            v = strlen(a);
            w = (char *)malloc(v);
            if (w==NULL)
            {   fprintf(err_file, "no memory for -O, quitting\n");
                exit(EXIT_FAILURE);
            }
            strcpy(w, a+2);
            omitted_files[n_omitted_files++] = w;
            break;
case '0': case '1': case '2': case '3': case '4':
case '5': case '6': case '7': case '8': case '9':
            {   if (sscanf(a, "-%ld", &v) != 1)
                {   fprintf(err_file, "-<number> specifies archive size\n");
                    fprintf(err_file, "Error: previous size retained\n");
                }
                else ideal_archive_size = v;
            }
            break;
default:    fprintf(err_file, "Flag '%s' ignored\n", a);
            break;
    }
}

static void process_indirect_file(char *fname)
{
/*
 * Read a response-file, splitting its contents into whitespace-separated
 * words, and process each as if it had been an argument.
 */
    FILE *ifile = fopen(fname, "r");
    char arg[LONGEST_LEGAL_FILENAME];
    int i, c = ' ';
    if (ifile == NULL)
    {   fprintf(err_file, "Indirect file not found\n");
        return;
    }
    for (;;)
    {   while (c != EOF && isspace(c)) c = getc(ifile);
        if (c == EOF) break;
        i = 0;
        do
        {   arg[i++] = c;
            c = getc(ifile);
        } while (c != EOF && !isspace(c));
        arg[i] = 0;
        if (arg[0] == '-') process_switch(arg);
        else scan_directory(arg, transmit_file);
    }
    fclose(ifile);
}

#endif /* EXTRACT */

#ifndef INSTALL

int main(int argc, char *argv[])
{
    int32 i;
    err_file = stderr;
#ifdef THINK_C
    argc = ccommand(&argv);        /* ask for command-line args */
#endif
#ifdef __ZTC__
    response_expand(&argc, &argv); /* Permits "@xxx" response files */
#endif
    prediction1 = (unsigned char *)malloc((size_t)PREDICTION_SIZE);
    prediction2 = (unsigned char *)malloc((size_t)PREDICTION_SIZE);
#ifdef EXTRACT
    fast_decode_table =
        (int32 *)malloc((size_t)(FAST_DECODE_TABLESIZE*sizeof(int32)));
#else
    look_ahead_buffer = (unsigned char *)malloc((size_t)BLOCK_SIZE);
    prediction1a = (unsigned char *)malloc((size_t)PREDICTION_SIZE);
    prediction2a = (unsigned char *)malloc((size_t)PREDICTION_SIZE);
#endif
    char_being_coded = (int *)malloc((size_t)(2*CODE_SIZE*sizeof(int)));
    number_of_occurences = 
        (int32 *)malloc((size_t)(2*CODE_SIZE*sizeof(int32)));
    character_index = (int *)malloc((size_t)(2*CODE_SIZE*sizeof(int)));
    corresponding_character = (int *)malloc((size_t)(CODE_SIZE*sizeof(int)));
    huffman_coded_bits =
        (unsigned32 *)malloc((size_t)(CODE_SIZE*sizeof(unsigned32)));
    length_of_code = (char *)malloc((size_t)CODE_SIZE);
/*
 * I re-use the double-length array character_index[] as one of the
 * arrays needed for decoding...
 */
    sorted_huffman_codes = (unsigned32 *)&character_index[0];
    if (prediction1 == NULL ||
        prediction2 == NULL ||
#ifdef EXTRACT
        fast_decode_table == NULL ||
#else
        look_ahead_buffer == NULL ||
        prediction1a == NULL ||
        prediction2a == NULL ||
#endif
        char_being_coded == NULL ||
        number_of_occurences == NULL ||
        character_index == NULL ||
        corresponding_character == NULL ||
        huffman_coded_bits == NULL ||
        length_of_code == NULL)
    {   fprintf(err_file, "Not enough memory\n");
        exit(EXIT_FAILURE);
    }

#ifdef EXTRACT
    if (argc < 2 || argc > 3)
    {   fprintf(err_file,
                "Usage:  excar [-t|-c|-f] <archive file>\n");
        exit(EXIT_SUCCESS);
    }

    just_list_contents = excar_x;
    skip_errors = 0;
    {   char *a = argv[1];
        if (a[0] == '-') switch (a[1])
        {
case 't': case 'T':
            just_list_contents = excar_t;
            goto check;
case 'c': case 'C':
            just_list_contents = excar_c;
            err_file = stdout;   /* In this case write to STDOUT */
            goto check;
case 'f': case 'F':
            skip_errors = 1;
            goto check;
check:
            if (argc == 3) { a = argv[2]; break; }
default:
            fprintf(err_file, "usage:  excar [-t|-c|-f] <archive-file>\n");
            exit(EXIT_FAILURE);
        }
        archive_file = fopen(a, RB_MODE);
        if (archive_file == NULL)
        {   fprintf(err_file, "File '%s' could not be accessed\n", a);
            exit(EXIT_FAILURE);
        }
    }

    for (i=0; i<PREDICTION_SIZE; i++)
    {   prediction1[i] = ' ';
        prediction2[i] = '\n';
    }
    memcpy(current_frequencies, default_frequencies,
           sizeof(default_frequencies));

    CRC = 1;
#ifndef INSTALL
    new_files_n = changed_files_n = 0;
#endif
    while (extract_files()) continue;

    {   unsigned32 calculated_CRC = CRC;
        unsigned32  stored_CRC = get4(); /* WARNING: get4() changes CRC! */
        if (calculated_CRC != stored_CRC)
            fprintf(err_file, "Warning: CRC failure - archive may be corrupt\n");
    }
    fclose(archive_file);

#ifndef INSTALL
    if (new_files_n > 0)
    {   int pos = 11;
        fprintf(err_file, "New files: ");
        for (i=0; i<new_files_n; i++)
        {   int l1 = strlen(new_files[i]);
            if (pos + l1 > 70)
            {   fprintf(err_file, "\n");
                pos = l1;
            }
            else pos += l1 + 1;
            fprintf(err_file, " %s", new_files[i]);
        }
        fprintf(err_file, "\n");
    }

    if (changed_files_n > 0)
    {   int pos = 15;
        fprintf(err_file, "Changed files: ");
        for (i=0; i<changed_files_n; i++)
        {   int l1 = strlen(changed_files[i]);
            if (pos + l1 > 70)
            {   fprintf(err_file, "\n");
                pos = l1;
            }
            else pos += l1 + 1;
            fprintf(err_file, " %s", changed_files[i]);
        }
        fprintf(err_file, "\n");
    }
#endif

#else /* EXTRACT */

#define destfile argv[1]

    if (argc < 3)
    {   fprintf(err_file,
        "Usage:  car <destination-file> [-a/-b] <source-directories/files>\n");
        exit(EXIT_SUCCESS);
    }

    n_omitted_files = 0;
    omitting = 0;
    total_bulk = 0;
    archive_file_name = destfile;
    archive_file = NULL;
    archive_file_number = 0;
    current_archive_size = current_raw_size = current_archive_count = 0;
    binary_mode = FALSE;

    for (i=0; i<PREDICTION_SIZE; i++)
    {   prediction1[i] = ' ';
        prediction2[i] = '\n';
    }
    memcpy(current_frequencies, default_frequencies,
           sizeof(default_frequencies));

    ideal_archive_size = 200000U;
    for (i=2; i<argc; i++)
    {   char *a = argv[i];
        if (a[0] == '-' &&
            (a[1] == 'o' || a[1] == 'O')) process_switch(a);
    }
    for (i=2; i<argc; i++)
    {   char *a = argv[i];
        if (a[0] == '-' &&
            !(a[1] == 'o' || a[1] == 'O')) process_switch(a);
        else if (a[0] == '@') /* indirect file specification */
        {   if (a[1] == 0)
                if (++i < argc) process_indirect_file(argv[i]);
                else
                {   fprintf(err_file, "'@' must be followed by a file name\n");
                    exit(EXIT_FAILURE);
                }
            else process_indirect_file(&a[1]);
        }
        else scan_directory(a, transmit_file);
    }
    terminate_archive_file();

    fprintf(err_file,
            "%d %s created, total uncompressed size %ld\n",
            archive_file_number,
            (archive_file_number == 1 ? "file" : "files"),
            (long)total_bulk);

#endif /* EXTRACT */

    return 0;
}

#endif

/* End of car.c/excar.c */

