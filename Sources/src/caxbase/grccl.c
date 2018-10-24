
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

#include <stdarg.h>

#if defined(WINDOWS_NT) && !defined(CWIN)
#define USE_SHAREDMEM
#endif

#ifdef USE_SHAREDMEM
#include <windows.h>
#undef IGNORE
#endif
#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "entries.h"
#include "arith.h"

#ifdef USE_SHAREDMEM
#include "AoExport.h"
#include "grif.h"
#include "axiom.h"
#endif

#define is_string(a) \
	((is_vector(a)) || type_of_header(vechdr(a)) != TYPE_STRING)

static Lisp_Object
LgetMemArea(Lisp_Object nil, int sz)
{
#ifdef USE_SHAREDMEM
  DataHandle data;
  Lisp_Object ldata;
  int i = 0;

  do {
    data = gcmGetMemArea(sz);
    i++;
    if (data->mem == 0) {
      Lprint(C_nil, fixnum_of_int(data->sz));
    }
  } while (data->mem == 0 && i<10);
  
  if (i==10) 
    return nil;

  ldata = Lsmkvect(nil, fixnum_of_int(sizeof(DataHandle)));
  memcpy(&celt(ldata,0), &data, sizeof(DataHandle));
  
  return ldata;
#else
  aerror0("Attempt to use AXIOM graphics outside Saturn Environment");
  return nil;
#endif
}

static Lisp_Object
LdestroyMemArea(Lisp_Object nil, Lisp_Object lmem)
{
#ifdef USE_SHAREDMEM
  DataHandle h;
  /* Either a string, float or integer */
  if (!is_vector(lmem)) 
    return aerror("destroyMemArea: Not a handle");

  memcpy(&h, &celt(lmem,0), sizeof(DataHandle));
  
  if (gcmDetachMemArea(h))
	  return lmem;
  else {
	  term_printf("Warning: Couldn't release shared area");
	  return nil;
  }
#else
  return nil;
#endif
}

static Lisp_Object
LputItem(Lisp_Object nil, Lisp_Object lmem, Lisp_Object lItem)
{
#ifdef USE_SHAREDMEM
  DataHandle h;
  /* Either a string, float or integer */
  if (!is_vector(lmem)) 
    return aerror("putItem: Not a handle");

  memcpy(&h, &celt(lmem,0), sizeof(DataHandle));
  if (is_fixnum(lItem))
    gcmPutInt(h, int_of_fixnum(lItem));
  else if (is_float(lItem))
    gcmPutFloat(h, float_of_number(lItem));
  else if (is_string(lItem))
    gcmPutString(h, &celt(lItem,0), length_of_header(vechdr(lItem)) - 4);
  else
    return aerror("putItem: Wrong flavour item");
#endif	 
  return nil;
}

static Lisp_Object
LputLStart(Lisp_Object nil, Lisp_Object lmem)
{
#ifdef USE_SHAREDMEM
  DataHandle h;

  if (!is_vector(lmem)) 
    return aerror("putLStart: Not a handle");
  memcpy(&h, &celt(lmem,0), sizeof(DataHandle));

  gcmPutLstStart(h);
#endif
  return nil;
}

static Lisp_Object
LputLEnd(Lisp_Object nil, Lisp_Object lmem)
{ 
#ifdef USE_SHAREDMEM
  DataHandle h;
  if (!is_vector(lmem)) 
    return aerror("putLEnd: Not a handle");
  memcpy(&h, &celt(lmem,0), sizeof(DataHandle));

  gcmPutLstEnd(h);
#endif
  return nil;
}

static Lisp_Object
LputVector(Lisp_Object nil, Lisp_Object lmem, Lisp_Object lvect)
{
#if 0
  int sz;
  DataHandle h;

  return aerror("putVector: Broken");

  if (!is_vector(lmem)) 
    return aerror("putVector: Not a handle");

  memcpy(&h, &celt(lmem,0), sizeof(DataHandle));

  sz = 0 /*vectorLength(lvect);*/
  if (sz==0)
    return aerror("put-vector");

  gcmPutIntVect(h, sz, /*lvect->argv[i]*/ 0);
#endif
  return nil;
}

static Lisp_Object
LinitVector(Lisp_Object nil, int nargs, ...)
{
#ifdef USE_SHAREDMEM
  Lisp_Object lmem, lsz, ltype;
  DataHandle  h;
  DTag 	      tag;
  int32 sz;
  va_list args;
  
  argcheck(nargs, 3, "start-vector");
  va_start(args, nargs);
  lmem  = va_arg(args, Lisp_Object);
  ltype = va_arg(args, Lisp_Object);
  lsz   = va_arg(args, Lisp_Object);
  va_end(args);

  if (!is_vector(lmem)) 
    return aerror("start-vector: Not a handle");
  memcpy(&h, &celt(lmem,0), sizeof(DataHandle));

  sz = int_of_fixnum(lsz);
  if (sz == 0)
    return aerror("start-vector: zero length vector");

  if (!is_symbol(ltype))
    return aerror("start-vector: non-symbolic type");
  
  if (celt(qpname(ltype),0) == 'i')
    tag = DTAG_Int;
  else 
    tag = DTAG_Float;
  
  gcmStartVect(h, sz, tag);
#endif  
  return nil;
}

static Lisp_Object
LaddToVector(Lisp_Object nil, Lisp_Object lmem, Lisp_Object lItem)
{
#ifdef USE_SHAREDMEM
  DataHandle h;
  /* Either a string, float or integer */
  if (!is_vector(lmem)) 
    return aerror("addToVector: Not a handle");

  memcpy(&h, &celt(lmem,0), sizeof(DataHandle));

  if (is_fixnum(lItem))
    gcmPutVectItemInt(h, int_of_fixnum(lItem));
  else if (is_float(lItem))
    gcmPutVectItemFloat(h, float_of_number(lItem));
  else
    return aerror("put-vect-item: Wrong flavour item");
#endif  
  return nil;
}

static Lisp_Object 
LmakeView(Lisp_Object nil, Lisp_Object type)
{
#ifdef USE_SHAREDMEM
  Lisp_Object lobj;
  void *obj;

  obj = gphOpenGraphics(0, axGetCallHandle());
  if (obj == NULL)
    return nil;

  lobj= Lsmkvect(nil, fixnum_of_int(sizeof(void*)));
  memcpy(&celt(lobj,0), &obj, sizeof(void*));

  return lobj;
#else
  return nil;
#endif
}

static Lisp_Object 
LsetViewData(Lisp_Object nil, Lisp_Object lview, Lisp_Object lhandle)
{
#ifdef USE_SHAREDMEM
  DataHandle data;
  void 	     *view;

  if (!is_vector(lview)) 
    return aerror("setViewData: Not a view handle");
  if (!is_vector(lhandle)) 
    return aerror("setviewData: Not a data handle");

  memcpy((char *) &data, &celt(lhandle,0), sizeof(data));
  memcpy((char *) &view, &celt(lview,0),   sizeof(void *));

  if (gphSetGraphData(view, data))
    return lview; 
  else
    return nil;
#else
  return nil;
#endif
}


static Lisp_Object 
LgetProperty(Lisp_Object nil, Lisp_Object lview, Lisp_Object str)
{
#ifdef USE_SHAREDMEM
  void *h;
  const char *res;
  if (!is_vector(lview)) 
    return aerror("getProperty: Not a handle");
  if (!is_string(str))
    return aerror("getProperty: Not a string");
  
  memcpy(&h, &celt(lview,0), sizeof(void *));

  res = gphGetProperty(h, &celt(str, 0));
  
  if (res == NULL)
    return nil;
  
  return make_string(res);
#else
  return nil;
#endif
}

static Lisp_Object
LsetProperty(Lisp_Object nil, int nargs, ...)
{
#ifdef USE_SHAREDMEM
  Lisp_Object lview, lstr1, lstr2;
  void *h;
  short res;
  va_list args;
  
  argcheck(nargs, 3, "set-property");
  va_start(args, nargs);
  lview = va_arg(args, Lisp_Object);
  lstr1 = va_arg(args, Lisp_Object);
  lstr2   = va_arg(args, Lisp_Object);
  va_end(args);
  
  if (!is_vector(lview)) 
    return aerror("setProperty: Not a handle");
  if (!is_string(lstr1))
    return aerror("getProperty: Not a string");
  if (!is_string(lstr2))
    return aerror("getProperty: Not a string");

  memcpy(&h, &celt(lview,0), sizeof(void *));

  res = gphSetProperty(h, (const char *) &celt(lstr1,0), 
		       (const char *) &celt(lstr2,0));
  
  if (res)
    return lstr2;
  else
    return nil;
#else
  return nil;
#endif
}

setup_type const gr_setup[] = {
  /* Name      		unary  		binary   	n-ary */
  { "gr-get-mem-area",  LgetMemArea, 	too_many_1, 	wrong_no_2},
  { "gr-put-item",      wrong_no_na, 	LputItem,	wrong_no_2},
  { "gr-put-lstart",    LputLStart,     too_many_1,     wrong_no_2},
  { "gr-put-lend",      LputLEnd, 	too_many_1,	wrong_no_2},
  { "gr-kill-mem-area", LdestroyMemArea,too_many_1,	wrong_no_2},
  { "gr-init-vector",	wrong_no_na,	too_many_1,	LinitVector},
  { "gr-add-to-vector", too_few_2,	LaddToVector,	wrong_no_2},
  /**/
  { "gr-make-view",  	LmakeView, 	too_many_1,	wrong_no_2},
  { "gr-set-data",	too_few_2,      LsetViewData,   wrong_no_2},
  { "gr-get-property",	too_few_2,      LgetProperty,   wrong_no_2},
  { "gr-set-property",	wrong_no_na,     too_many_1,    LsetProperty},
  { NULL, 		0,		0,		0}
};

