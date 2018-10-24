
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
 * Simple buffer
 */

#include <stdlib.h>
#include <string.h>

#include "buf.h"

#define BUF_MINSZ 64
#define BUF_INC   64

Buffer
bufNew(int sz, GetCharsFn fn)
{
  Buffer buf = (Buffer) malloc(sizeof(*buf));
  if (sz < BUF_MINSZ) sz = BUF_MINSZ;
  buf->chars = (char *) malloc(sz);
  buf->len    = sz;
  buf->pos   = 0;
  buf->rdpos = 0;
  buf->getChars = fn;

  return buf;
}

void
bufFree(Buffer buf)
{
  free((char*)buf->chars);
  free((char*)buf);
}

void
bufAddChar(Buffer buf, char c)
{
  if (buf->pos == buf->len) {
    int newlen = buf->len + BUF_INC;
    char *arr = (char*) malloc(newlen);
    strncpy(arr, buf->chars, buf->pos);
    free(buf->chars);
    buf->chars = arr;
    buf->len = newlen;
  }
  buf->chars[buf->pos] = c;
  buf->pos++;
}

void
bufAddTab(Buffer buf)
{
  while (buf->len % 8 != 0)
    bufAddChar(buf, ' ');
}


void bufAddStr(Buffer buf, int len, char *str)
{
  int newlen = buf->len;
  while (buf->pos + len >= buf->len) 
    newlen += BUF_INC;
  
  if (newlen != buf->len) {
    char *arr = (char *) malloc(newlen);
    strncpy(arr, buf->chars, buf->pos -1);
    free(buf->chars);
    buf->chars = arr;
    buf->len   = newlen;
  }
    
  strncpy(buf->chars + buf->pos, str, len);
  buf->pos += len;
	  
}

void
bufReset(Buffer buf)
{
  buf->pos   = 0;
  buf->rdpos = 0;
}

int
bufGetc(Buffer buf)
{
  int char;
  while (buf->rdpos == buf->pos) {
    bufReset(buf);
    (buf->getChars)(buf);
  }
  return buf->chars[buf->rdpos++];
}

