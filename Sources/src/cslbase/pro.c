/*  pro.c                            Copyright (C) 1989-2002 Codemist Ltd */

/* Watcom C stack checking code */

/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */


/* Signature: 7c40872e 08-Apr-2002 */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#include "machine.h"

#include "tags.h"
#include "externs.h"
#include "arith.h"
#include "read.h"
#include "stream.h"
#include "entries.h"
#include "version.h"
#include "cslerror.h"


static int spset = 0;
static int32 spbase = 0, spmin;

static FILE *stack_log = NULL;

#pragma aux __PRO modify [];

#pragma aux __PRO "__PRO";

extern int pusha(void);
#pragma aux pusha = "push eax" "push ecx" "push edx" value [eax] modify [];
extern int popa(void);
#pragma aux popa = "pop edx" "pop ecx" "pop eax" value [eax] modify [eax ecx edx];

void __PRO()
{
    int32 temp;
    pusha();
    temp = (int32)&temp;
    if (!spset)
    {   spbase = spmin = temp;
        spset = 1;
    }
    if (stack_log == NULL) stack_log = fopen("stack.log", "w");
    if (temp <= spmin-64)  /* Only check at granularity of 64 bytes */
    {
        fprintf(stack_log, "Stack depth %d\n", spbase-temp);
        spmin = temp;
    }
    popa();
    return;
}

/* End of pro.c */
