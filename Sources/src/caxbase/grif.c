
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
 * Implementation of graphic communication primitives
 */

#include <windows.h>
#include <assert.h>
#include <stdio.h>

#include "grif.h"

#ifdef TESTLEAKS
#undef MessageBox
#define MessageBox(a,b,c,d)
#endif

typedef HANDLE HMem;

#define UseSwapFile (HANDLE) 0xFFFFFFFF

typedef struct {
	int sz;
} GDataHdr;

static void gcmEnsureMemArea(DataHandle h, int nMore);
static int namec = 0;

DataHandle
gcmGetMemArea(int sz)
{
	HMem 	 mem;
	GDataHdr *hdr;
	DataHandle h = malloc(sizeof(*h));
	char *pMem;

	sprintf(h->name, "GMem:%d", namec);
	namec++;
	h->sz = sz;
	sz += sizeof(GDataHdr);

	mem = CreateFileMapping(UseSwapFile,
				NULL,           /* Security  */
				PAGE_READWRITE, /* Protection*/
				0, 		        /* MaxSZHigh */
				sz,       	    /* MaxSZLow  */
				h->name       	/* Map Name  */
				);
	if (mem == NULL) {
		int err = GetLastError(); 
		CloseHandle(mem);
		h->mem = 0;
		h->sz = err;
		return h;
	}

	pMem = (char *) MapViewOfFile(mem,              /* Map Object  */
				      FILE_MAP_WRITE,   /* access      */
				      0,                /* high offset */
				      0,                /* low offset  */
				      sz                /* nToMap      */
				      );
	if (pMem == NULL) {
		int err = GetLastError();
	  	CloseHandle(mem);
		h->mem  = 0;
		h->sz   = err;
		return h;
	}

	hdr = (GDataHdr*) pMem;
	hdr->sz = sz;
	pMem += sizeof(GDataHdr);
	h->data = pMem;
	h->pos  = pMem;
	h->mem  = mem;
	return h;
}

DataHandle
gcmFindMemArea(const char *name)
{
	DataHandle h = (DataHandle) malloc(sizeof(*h));
	HMem mem;
	char *pmem;
	GDataHdr *hdr;

	mem = OpenFileMapping(FILE_MAP_WRITE, /* Mode		*/
			      FALSE,                  /* Inheritance	*/
			      name                    /*Name of mapping */
			      );

	if (mem == NULL) {
		int err = GetLastError();
		h->mem = 0;
		h->sz  = err;
		return h;
	}

	pmem = (char *)
	       MapViewOfFile(mem,              /* Map Object	*/
			     FILE_MAP_WRITE,   /* access	*/
			     0,                /* high offset	*/
			     0,                /* low offset	*/
			     sizeof(int)       /* nToMap     	*/
			     );
	if (pmem == NULL) {
		int err = GetLastError();
		CloseHandle(mem);
		h->mem = 0;
		h->sz  = err;
		return h;
	}

	hdr = (GDataHdr*) pmem;
	assert(hdr->sz != 0);
	h->sz = hdr->sz;
	if (!UnmapViewOfFile(pmem)) {
		int err = GetLastError();
		CloseHandle(mem);
		h->mem = 0;
		h->sz  = err;
		return NULL;
	}

	pmem = (char *)MapViewOfFile(mem,              /* Map Object  */
				      FILE_MAP_WRITE,   /* access      */
				      0,                /* high offset */
				      0,                /* low offset  */
				      h->sz    		/* nToMap      */
				      );

	if (pmem == NULL) {
		int err = GetLastError();
		h->mem = 0;
		h->sz  = err;
		return h;
	}

	pmem += sizeof(*hdr);

	h->data = pmem;
	h->mem  = mem;
	h->pos  = h->data;
	return h;
}

BOOL
gcmDetachMemArea(DataHandle h)
{
	char *start = (char*) h->data - sizeof(GDataHdr);
	if (!UnmapViewOfFile(start)) {
		CloseHandle(h->mem);
		free(h);
		return FALSE;
	}
	CloseHandle(h->mem);
	free(h);
	return TRUE;
}

static void
gcmEnsureMemArea(DataHandle h, int nMore)
{
  DataHandle new;
  if (h->pos + nMore > h->data + h->sz) {
    int nchars = h->pos - h->data;
    new = gcmGetMemArea(h->sz+nMore + 1024);
    if (!new->data) *(int *) 0 = 0;
    UnmapViewOfFile((char *) h->data - sizeof(GDataHdr));
    CloseHandle( h->mem );
    h->data = new->data;
    h->sz   = new->sz;
    h->mem  = new->mem;
    h->pos  = new->pos;
    strcpy(h->name, new->name);
    memcpy(new->pos, h->data, nchars);
    h->pos += nchars;
  }
}

/****************************************
 *
 * :: Data manipulation
 *
 ****************************************/

void
gcmResetData(DataHandle h)
{
	h->pos = h->data;
}

void
gcmPutInt(DataHandle h, int i)
{
  gcmEnsureMemArea(h, 1+ sizeof(int));
  	*(h->pos++) = DTAG_Int;
	memcpy(h->pos, &i, sizeof(int));
	h->pos += sizeof(int);
}

void
gcmPutFloat(DataHandle h, float f)
{
  gcmEnsureMemArea(h, 1+sizeof(float));
	*(h->pos++) = DTAG_Float;
	memcpy(h->pos, &f, sizeof(float));
	h->pos += sizeof(float);
}

void
gcmPutFloatVect(DataHandle h, int sz, float data[])
{
  gcmEnsureMemArea(h, 2 + sizeof(int) + sz*sizeof(float));
	*(h->pos++) = DTAG_Vect;
	*(h->pos++) = DTAG_Float;
	memcpy(h->pos, &sz, sizeof(int));
	h->pos += sizeof(int);

	memcpy(h->pos, data, sz*sizeof(float));
	h->pos += sz*sizeof(float);
}

void
gcmPutIntVect(DataHandle h, int sz, int data[])
{
  gcmEnsureMemArea(h, 2 + sizeof(int) + sz*sizeof(int));
	*(h->pos++) = DTAG_Vect;
	*(h->pos++) = DTAG_Int;
	memcpy(h->pos, &sz, sizeof(int));
	h->pos += sizeof(int);

	memcpy(h->pos, data, sz*sizeof(int));
	h->pos += sz*sizeof(int);
}

void
gcmStartVect(DataHandle h, int sz, DTag tag)
{
  gcmEnsureMemArea(h, 2 + sizeof(int) + sz*sizeof(int));
	*(h->pos++) = DTAG_Vect;
	*(h->pos++) = tag;
	memcpy(h->pos, &sz, sizeof(int));
	h->pos += sizeof(int);
}

void
gcmPutVectItemInt(DataHandle h, int data)
{
	memcpy(h->pos, &data, sizeof(int));
	h->pos += sizeof(int);
}

void
gcmPutVectItemFloat(DataHandle h, float data)
{
	memcpy(h->pos, &data, sizeof(float));
	h->pos += sizeof(float);
}

void
gcmPutLstStart(DataHandle h)
{
  gcmEnsureMemArea(h, 1);
  	*h->pos = DTAG_LstStart;
	h->pos += 1;
}

void
gcmPutLstEnd(DataHandle h)
{
  gcmEnsureMemArea(h, 1);
  	*h->pos = DTAG_LstEnd;
	h->pos += 1;
}

void
gcmPutString(DataHandle h, char *str, int len)
{
  	// Terminationg '0'
        int sz = len+1;
	gcmEnsureMemArea(h, sz+1+sizeof(int));
	*(h->pos++) = (char) DTAG_String;
	memcpy(h->pos, &sz, sizeof(int));
	h->pos += sizeof(int);

	memcpy(h->pos, str, sz-1);
	h->pos[sz-1] = '\0';
	h->pos += sz;
}

DTag
gcmPeekTag(DataHandle h)
{
  return (DTag) *(h->pos);
}

void
gcmGetLstStart(DataHandle h)
{
  h->pos++;
}

void
gcmGetLstEnd(DataHandle h)
{
  h->pos++;
}

float
gcmGetFloat(DataHandle h)
{
  float f;
  if (gcmPeekTag(h) != DTAG_Float)
    MessageBox(NULL, "Expected a float", "", MB_OK);
  h->pos++;
  memcpy(&f, h->pos, sizeof(float));
  h->pos+=sizeof(int);
  return f;
}

int
gcmGetInt(DataHandle h)
{
  int i;
  if (gcmPeekTag(h) != DTAG_Int)
    MessageBox(NULL, "Expected an int", "", MB_OK);
  h->pos++;
  memcpy(&i, h->pos, sizeof(int));
  h->pos+=sizeof(int);
  return i;
}

static char gcmStrSpace[256];

char *
gcmGetStaticString(DataHandle h)
{
  int sz;
  if (gcmPeekTag(h) != DTAG_String)
    MessageBox(NULL, "Expected a string", "", MB_OK);
  h->pos++;
  memcpy(&sz, h->pos, sizeof(int));
  h->pos += sizeof(int);
  if (sz>256) *(int*) 0 = 212;
  memcpy(gcmStrSpace, h->pos, sz);
  h->pos += sz;
  return gcmStrSpace;
}

float *
gcmGetVectFloat(DataHandle h, int *psz)
{
  float *data;
  int sz;
  if (gcmPeekTag(h) != DTAG_Vect)
    MessageBox(NULL, "Expected a vector", "", MB_OK);
  h->pos++;
  if (gcmPeekTag(h) != DTAG_Float)
    MessageBox(NULL, "Expected a float", "", MB_OK);
  h->pos++;

  memcpy(&sz, h->pos, sizeof(int));
  h->pos += sizeof(int);
  
  data = (float *) malloc(sizeof(float) * sz);
  memcpy(data, h->pos, sizeof(float) * sz);
  h->pos += sizeof(float) * sz;

  *psz = sz;
  return data;
}

#ifdef TESTLEAKS

main(int argc, char *argv)
{
  int nl = 0;
  int i;
  for (i=0; i<100; i++) {
    char buf[40];
    DataHandle h;
    sprintf(buf, "GMem:%d", i);
    h = gcmFindMemArea(buf);
    if (!h) {
      printf(".");
      nl = 1;
    }
    else {
      if (nl)
	printf("\n");
      printf("Got: %s, sz = %d\n", buf, h->sz);
      gcmDetachMemArea(h);
      nl = 0;
    }
  }
}

#endif
