
/*
  Copyright (c) 1991-2002, The Numerical Algorithms Group Ltd.
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:
  
      - Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
  
      - Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in
        the documentation and/or other materials provided with the
        distribution.
  
      - Neither the name of The Numerical ALgorithms Group Ltd. nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES-- LOSS OF USE, DATA, OR
  PROFITS-- OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*  sockets.c                                 Copyright (C) 1995 NAG Ltd */

/*
 * Functions to support operations on sockets for AXIOM: basically just
 * interfaces to some of the functions in libspad.a (sockio-c.c).  We
 * assume that all integers returned as Lisp objects can be represented
 * as CCL fixnums, i.e. do not lie in the range +/-(2^28 .. 2^32-1).
 *
 * Version 1.0   September 1995
 *
 * Author: Mike Dewar
 *
 */

/* Signature: 5828091f 03-Sep-2002 */


#include <stdarg.h>
#include <sys/types.h>
#include <string.h>
#ifdef __WATCOMC__
#include <dos.h>
#endif

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "arith.h"

#if defined(UNIX) && !defined(NoSockets)
#define RealSockets
#endif

#ifdef FLEX
/* we don't use timers; we call timnag in gc.c explicitly for UNIX */
static int got_license    =0;

void init_lm()
{
  extern void glnag(char *prod_code, char *user_opts);
  extern void rlnag();

  /* If glnag fails it calls displmmsg and exits */
  if (got_license == 0) {
#if defined(__alpha)
    glnag("AXDAU21NA","");
#elif defined(__SVR4) && defined(__sparc)
#if defined(__GNUC__)
    glnag("AXSOL21NB","");
#else
    glnag("AXSOL21NA","");
#endif
#elif (defined(sparc) || defined(__sparc)) && !defined(__SVR4)
    glnag("AXSU421NA","");
#elif defined(__hp9000s800)
    glnag("AXH9721NA","");
#elif defined(__sgi) &&  defined(__mips) && __mips==1
    glnag("AXSG521NA","");
#elif defined(__sgi) &&  defined(__mips) && __mips==3
    glnag("AXSG621NA","");
#elif defined(_AIX)
    glnag("AXIB621NA","");
#elif defined(__linux__)
    glnag("AXLUX21NA","");
#elif defined(WINDOWS_NT)
    glnag("AXW3222NA","");
#ifndef CWIN
#endif
     rlnag();
#endif
    got_license = 1;
  }
}

void close_lm()
{
#ifdef WINDOWS_NT
  extern void rlnag();
  if (got_license) {
    	rlnag();
	got_license = 0;
  }
#endif
}

Lisp_Object Linit_lm(Lisp_Object nil, Lisp_Object dummy)
{
  init_lm();
  return onevalue(fixnum_of_int(1));
}

#ifdef CWIN
#undef exit
#endif

void displmmsg(int unlicensed, char *message)
{
  /* term_printf only handles strings less than 256 characters long */
  if (strlen(message) > 255) {
    char *line;
    line = strtok(message,"\n");
    term_printf("%s\n",line);
    while ((line=strtok(NULL,"\n")) != NULL) term_printf("%s\n",line);
  }
  else
    term_printf("%s\n",message);
#ifdef CWIN
  ensure_screen();
#endif
  if (unlicensed > 0) {
    term_printf("+++ This copy of AXIOM is unlicensed ... exiting.\n");
#ifdef CWIN
    ensure_screen();
#endif
    sleep(10);
    my_exit(2);
  }
}

Lisp_Object MS_CDECL Lclose_lm(Lisp_Object nil, int32 nargs, ...)
{
  argcheck(nargs,0,"close-lm");
  close_lm();
  return nil;
}
#else

Lisp_Object Linit_lm(Lisp_Object nil, Lisp_Object dummy)
{
  return onevalue(fixnum_of_int(1));
}

Lisp_Object MS_CDECL Lclose_lm(Lisp_Object nil, int32 nargs, ...)
{
  argcheck(nargs,0,"close-lm");
  return nil;
}

#endif

#ifdef RealSockets

/* These are all in sockio-c.c */
extern int32  open_server(char *server_name);
extern int32  sock_get_int(int32 purpose);
extern int32  sock_send_int(int32 purpose, int32 val);
extern char  *sock_get_string_buf(int32 purpose, char *buf, int32 buf_len);
extern int32  sock_send_string_len(int32 purpose, char *str, int32 len);
extern double sock_get_float(int32 purpose);
extern int32  sock_send_float(int32 purpose, double num);
extern int32  sock_send_wakeup(int32 purpose);
extern int32  server_switch();
extern int32  flush_stdout();
extern int32  sock_send_signal(int purpose, int sig);
extern int32  print_line(char *s);

/* Utility function to test for CCL integers and turn them into C ints */
int32 ccl2int(Lisp_Object i, char *fcn)
{ if (is_fixnum(i))
    return (int_of_fixnum(i));
  else if (is_numbers(i) && is_bignum(i) )
    return (thirty_two_bits(i));
  else 
    return aerror(fcn);
}

Lisp_Object LopenServer(Lisp_Object nil, Lisp_Object server)
{ 
  if (!(is_vector(server) && type_of_header(vechdr(server)) == TYPE_STRING) )
    return aerror("open_server");
  else 
    return onevalue(fixnum_of_int(open_server(&celt(server,0))));
}

Lisp_Object LsockGetInt(Lisp_Object nil, Lisp_Object purpose)
{
  return onevalue(fixnum_of_int(sock_get_int(ccl2int(purpose,"sock_get_int"))));
}

Lisp_Object LsockSendInt(Lisp_Object nil, Lisp_Object purpose, Lisp_Object val)
{
  return onevalue(fixnum_of_int(
    sock_send_int(ccl2int(purpose,"sock_send_int"),
                  ccl2int(val,"sock_send_int"))));
}

Lisp_Object MS_CDECL LsockGetStringBuf(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object purpose, buf, buf_length;
  argcheck(nargs,3,"sock_get_string_buf");
  va_start(args,nargs);
  purpose    = va_arg(args, Lisp_Object);
  buf        = va_arg(args, Lisp_Object);
  buf_length = va_arg(args, Lisp_Object);
  va_end(args);
  if (!(is_vector(buf) && type_of_header(vechdr(buf)) == TYPE_STRING) )
    aerror("sock_get_string_buf");
  else
    sock_get_string_buf(ccl2int(purpose,"sock_get_string_buf"),
                        &celt(buf,0),
                        ccl2int(buf_length,"sock_get_string_buf") );

  /* AXIOM always ignores the return value */
  return buf;
}

Lisp_Object MS_CDECL LsockSendStringLen(Lisp_Object nil, int nargs, ...)
{
  va_list args;
  Lisp_Object purpose, buf, buf_length;
  argcheck(nargs,3,"sock_send_string_len");
  va_start(args,nargs);
  purpose    = va_arg(args, Lisp_Object);
  buf        = va_arg(args, Lisp_Object);
  buf_length = va_arg(args, Lisp_Object);
  va_end(args);
  if (!(is_vector(buf) && type_of_header(vechdr(buf)) == TYPE_STRING) )
    return aerror("sock_send_string_len");
  else
    return onevalue(fixnum_of_int(
      sock_send_string_len(ccl2int(purpose,"sock_send_string_len"),
                           &celt(buf,0),
                           ccl2int(buf_length,"sock_send_string_len") )));

}

Lisp_Object LsockGetFloat(Lisp_Object nil, Lisp_Object purpose)
{
  return onevalue(make_boxfloat(sock_get_float(
    ccl2int(purpose,"sock_get_float")), TYPE_DOUBLE_FLOAT) );
}

Lisp_Object LsockSendFloat(Lisp_Object nil, Lisp_Object purpose, Lisp_Object val)
{
  if (!is_number(val)) aerror("sock_send_float");

  return onevalue(fixnum_of_int(sock_send_float(
                                             ccl2int(purpose,"sock_send_float"),
                                             float_of_number(val) )));
}

Lisp_Object LsockSendWakeup(Lisp_Object nil, Lisp_Object purpose)
{
  return onevalue(fixnum_of_int(sock_send_wakeup(ccl2int(purpose,
                                                       "sock_send_wakeup"))));
}

Lisp_Object MS_CDECL LserverSwitch(Lisp_Object nil, int nargs, ...)
{
  argcheck(nargs, 0, "server_switch");
  return onevalue(fixnum_of_int(server_switch()));
}

Lisp_Object MS_CDECL LflushStdout(Lisp_Object nil, int nargs, ...)
{
  argcheck(nargs, 0, "flush_stdout");
  return onevalue(fixnum_of_int(flush_stdout()));
}

Lisp_Object LsockSendSignal(Lisp_Object nil,Lisp_Object purpose,Lisp_Object sig)
{
  return onevalue(fixnum_of_int(sock_send_signal(
                                            ccl2int(purpose,"sock_send_signal"),
                                            ccl2int(sig,"sock_send_signal"))));
}

Lisp_Object LprintLine(Lisp_Object nil, Lisp_Object buf)
{ 
  if (!(is_vector(buf) && type_of_header(vechdr(buf)) == TYPE_STRING) )
    return aerror("print_line");
  else 
    return onevalue(fixnum_of_int(print_line(&celt(buf,0))));
}

#endif /* UNIX */

#if defined(__i386__) || defined(__i486__)|| defined(__i386)||defined(__i586)
static unsigned char plus_infinity[8]=  {0x0,0x0,0x0,0x0,0x0,0x0,0xf0,0x7f},
             minus_infinity[8]={0x0,0x0,0x0,0x0,0x0,0x0,0xf0,0xff},
             NANQ[8]=          {0x0,0x0,0x0,0x0,0x0,0x0,0xf8,0xff};
#elif defined(__alpha)
static unsigned char plus_infinity[8]=  {0x0,0x0,0x0,0x0,0x0,0x0,0xf0,0x7f},
             minus_infinity[8]={0x0,0x0,0x0,0x0,0x0,0x0,0xf0,0xff},
             NANQ[8]=          {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7f};

#else
static unsigned char plus_infinity[8]=  {0x7f,0xf0,0x0,0x0,0x0,0x0,0x0,0x0},
             minus_infinity[8]={0xff,0xf0,0x0,0x0,0x0,0x0,0x0,0x0},
             NANQ[8]=          {0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

#endif
Lisp_Object MS_CDECL LplusInfinity(Lisp_Object nil, int nargs, ...)
{
  argcheck(nargs, 0, "plus_infinity");
  return onevalue(make_boxfloat(*(double *)plus_infinity,TYPE_DOUBLE_FLOAT));
}

Lisp_Object MS_CDECL LminusInfinity(Lisp_Object nil, int nargs, ...)
{
  argcheck(nargs, 0, "minus_infinity");
  return onevalue(make_boxfloat(*(double *)minus_infinity,TYPE_DOUBLE_FLOAT));
}

Lisp_Object MS_CDECL Lnanq(Lisp_Object nil, int nargs, ...)
{
  argcheck(nargs, 0, "NANQ");
  return onevalue(make_boxfloat(*(double *)NANQ,TYPE_DOUBLE_FLOAT));
}

Lisp_Object sock_error1(Lisp_Object nil, Lisp_Object arg)
{
  return aerror0("Attempt to call socket function on non-unix platform");
}

Lisp_Object sock_error2(Lisp_Object nil, Lisp_Object arg1, Lisp_Object arg2)
{
  return aerror0("Attempt to call socket function on non-unix platform");
}

Lisp_Object MS_CDECL sock_error0(Lisp_Object nil, int nargs, ...)
{
  return aerror0("Attempt to call socket function on non-unix platform");
}

setup_type const socket_setup[] =
{
#ifdef FLEX
 {"init-lm",              Linit_lm,        too_many_1,      wrong_no_1},
 {"close-lm",             wrong_no_0a,     wrong_no_0b,     Lclose_lm},
#else
 {"init-lm",              Linit_lm,        too_many_1,      wrong_no_1},
 {"close-lm",             sock_error1,     sock_error2,     sock_error0},
#endif
#ifdef RealSockets
 {"open_server",          LopenServer,     too_many_1,      wrong_no_1},
 {"sock_get_int",         LsockGetInt,     too_many_1,      wrong_no_1},
 {"sock_send_int",        too_few_2,       LsockSendInt,    wrong_no_2},
 {"sock_get_string_buf",  wrong_no_na,     wrong_no_nb,     LsockGetStringBuf},
 {"sock_send_string_len", wrong_no_na,     wrong_no_nb,     LsockSendStringLen},
 {"sock_get_float",       LsockGetFloat,   too_many_1,      wrong_no_1},
 {"sock_send_float",      too_few_2,       LsockSendFloat,  wrong_no_2},
 {"sock_send_wakeup",     LsockSendWakeup, too_many_1,      wrong_no_1},
 {"server_switch",        wrong_no_0a,     wrong_no_0b,     LserverSwitch},
 {"flush_stdout",         wrong_no_0a,     wrong_no_0b,     LflushStdout},
 {"sock_send_signal",     too_few_2,       LsockSendSignal, wrong_no_2},
 {"print_line",           LprintLine,      too_many_1,      wrong_no_1},
#else
 {"open_server",          sock_error1,     sock_error2,     sock_error0},
 {"sock_get_int",         sock_error1,     sock_error2,     sock_error0},
 {"sock_send_int",        sock_error1,     sock_error2,     sock_error0},
 {"sock_get_string_buf",  sock_error1,     sock_error2,     sock_error0},
 {"sock_send_string_len", sock_error1,     sock_error2,     sock_error0},
 {"sock_get_float",       sock_error1,     sock_error2,     sock_error0},
 {"sock_send_float",      sock_error1,     sock_error2,     sock_error0},
 {"sock_send_wakeup",     sock_error1,     sock_error2,     sock_error0},
 {"server_switch",        sock_error1,     sock_error2,     sock_error0},
 {"flush_stdout",         sock_error1,     sock_error2,     sock_error0},
 {"sock_send_signal",     sock_error1,     sock_error2,     sock_error0},
 {"print_line",           sock_error1,     sock_error2,     sock_error0},
#endif
 {"plus_infinity",        wrong_no_0a,     wrong_no_0b,     LplusInfinity},
 {"minus_infinity",       wrong_no_0a,     wrong_no_0b,     LminusInfinity},
 {"NANQ",                 wrong_no_0a,     wrong_no_0b,     Lnanq},
 {NULL,                   0,               0,               0}
};

