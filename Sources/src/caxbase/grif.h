
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

/*
 * This file is the interface between CCL and the 
 * graphics world.
 *
 * Types:
 *  DataHandle --- shared data object. I assume (for the moment)
 *		   that these are short-lived.
 *  ViewPort --- handle on a foreign process. 
 *
 * Exports:
 *  Servers:
 *   ViewPort   gcmCreateViewPort	(const char *)
 *   void	gcmAddViewData		(ViewPort, DataHandle)
 *   void	gcmReleaseViewPort	(ViewPort)
 *
 *
 *  Memory management:
 */
#ifndef _GRIF_H
#define _GRIF_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _DataHandle {
	char   *data;
	int    sz;
  	HANDLE mem;
	char  *pos;
	char   name[40];
}  *DataHandle;

typedef enum { 
	DTAG_Int,
	DTAG_Float,
	DTAG_Vect,
	DTAG_String,
	DTAG_LstStart,
	DTAG_LstEnd
} DTag;
extern DataHandle gcmGetMemArea     (int sz);
extern BOOL       gcmDetachMemArea  (DataHandle);
extern DataHandle gcmFindMemArea    (const char *);

extern void gcmResetData(DataHandle h);

extern void gcmPutFloat		(DataHandle h, float f);
extern void gcmPutInt		(DataHandle h, int i);
extern void gcmPutVectItemInt	(DataHandle h, int data);
extern void gcmPutVectItemFloat (DataHandle h, float data);
/* Put string allows non-null terminated strings... */
extern void gcmPutString	(DataHandle h, char *str, int len);
extern void gcmStartVect	(DataHandle h, int sz, DTag tag);
extern void gcmPutIntVect	(DataHandle h, int sz, int data[]);
extern void gcmPutFloatVect	(DataHandle h, int sz, float data[]);
extern void gcmPutLstStart	(DataHandle);
extern void gcmPutLstEnd	(DataHandle);

extern DTag  gcmPeekTag		(DataHandle h);
extern void  gcmGetLstStart	(DataHandle h);
extern void  gcmGetLstEnd	(DataHandle h);
extern float gcmGetFloat	(DataHandle h);
extern int   gcmGetInt		(DataHandle h);
extern char* gcmGetStaticString	(DataHandle h);
extern char* gcmGetString	(DataHandle h);
extern float*gcmGetVectFloat    (DataHandle h, int *);
extern int*  gcmGetVectInt	(DataHandle h, int *);

#ifdef __cplusplus
}
#endif

#endif

