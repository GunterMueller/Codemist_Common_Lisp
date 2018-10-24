
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
#include "machine.h"
#include "tags.h"
#include "externs.h"
#include "cslerror.h"

#ifdef OPENMATH

extern Lisp_Object om_read(Lisp_Object, Lisp_Object);
extern Lisp_Object om_supportsCD(Lisp_Object, Lisp_Object);
extern Lisp_Object om_supportsSymbol(Lisp_Object, Lisp_Object, Lisp_Object);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object, int, ...);
extern Lisp_Object om_listSymbols(Lisp_Object, Lisp_Object);
extern Lisp_Object om_whichCDs(Lisp_Object, Lisp_Object);


setup_type const om_parse_setup[] = {
	/* LISP Name */			/* Unary */		/* Binary */		/* Nary */
	{"om-read",				om_read,		too_many_1,			wrong_no_1},
	{"om-supportsCD",		om_supportsCD,	too_many_1,			wrong_no_1},
	{"om-supportsSymbol",	too_few_2,		om_supportsSymbol,	wrong_no_2},
	{"om-listCDs",			wrong_no_0a,	wrong_no_0b,		om_listCDs},
	{"om-listSymbols",		om_listSymbols,	too_many_1,			wrong_no_1},
	{"om-whichCDs",			om_whichCDs,	too_many_1,			wrong_no_1},

	{NULL,	0,	0,	0}
};

#endif
