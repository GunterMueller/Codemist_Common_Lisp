
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
#include <string.h>
#include <ctype.h>

#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "read.h"
#include "stream.h"
#include "arith.h"
#include "entries.h"
#ifdef COMMON
#include "clsyms.h"
#endif

#ifdef WINDOWS_NT
#include "buf.h"
#endif
#define AX_INIT_BUF_SZ   1024

static int axfRetCode;
#ifdef WINDOWS_NT
static Buffer axfBuffer;
#endif

void
axfInitBuffer()
{
#ifdef WINDOWS_NT
  if (!axfBuffer) axfBuffer = bufNew(AX_INIT_BUF_SZ, NULL);
  bufReset(axfBuffer);
#endif
}

void
axfAddChars(int n, const char *str)
{
#ifdef WINDOWS_NT
	bufAddStr(axfBuffer, n, str);
#endif
}

int
axfGetReturnCode()
{
#ifdef WINDOWS_NT
	return axfRetCode;
#else
	return 0;
#endif
}

Lisp_Object MS_CDECL
LGetAxInt(Lisp_Object nil, Lisp_Object n)
{
	int32 idx;

#ifdef WINDOWS_NT
	if (!is_fixnum(n))
		return nil;
	idx = int_of_fixnum(n);

	return fixnum_of_int((int32) bufContents(axfBuffer)[idx]);
#else
	return fixnum_of_int(0);
#endif
}

Lisp_Object MS_CDECL
LSetAxRet(Lisp_Object nil, Lisp_Object n)
{
	axfRetCode = int_of_fixnum(n);
	return nil;
}

setup_type const axfns_setup[] = 
{
       {"get-ax-char", 		LGetAxInt, too_many_1, wrong_no_1  },
       {"set-ax-return-code", 	LSetAxRet, too_many_1, wrong_no_1  },
       { NULL, 0,0,0 }
};

#if 0
/***********************************************************************
 * 
 * Interface (mostly) for dll
 ***********************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

BOOL APIENTRY 
axFnsInit(AxiomExternalCommandHandler handler, int argc, char *argv[],
	  characterWriter axWrite)
{
	    // !! AXIOM 
    if (!InitializeAxiomOleDll( handler ))
	    return FALSE;

    // CCL
    cslstart(axCclNArgs, axCclArgs, axWrite);
}

axFnsDoCommand(const char *str, 
	       character_reader *rdr,
	       character_writer *wrtr)
{
	
}

axFnsTerminate

#ifdef __cplusplus
}
#endif
#endif
