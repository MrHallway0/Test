/*
 * Copyright (c) 1997 - 2001 Kungliga Tekniska H�gskolan
 * (Royal Institute of Technology, Stockholm, Sweden). 
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 *
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 *
 * 3. Neither the name of the Institute nor the names of its contributors 
 *    may be used to endorse or promote products derived from this software 
 *    without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
 * SUCH DAMAGE. 
 */

/* $Id: gen_locl.h,v 1.1.1.2 2006-02-25 02:34:19 laffer1 Exp $ */

#ifndef __GEN_LOCL_H__
#define __GEN_LOCL_H__

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <err.h>
#include <roken.h>
#include "hash.h"
#include "symbol.h"

void generate_type (const Symbol *);
void generate_constant (const Symbol *);
void generate_type_encode (const Symbol *s);
void generate_type_decode (const Symbol *s);
void generate_seq_type_decode (const Symbol *s);
void generate_type_free (const Symbol *s);
void generate_type_length (const Symbol *s);
void generate_type_copy (const Symbol *s);
void generate_type_maybe (const Symbol *s);
void generate_glue (const Symbol *s);

void init_generate (const char *filename, const char *basename);
const char *filename (void);
void close_generate(void);
void add_import(const char *module);
int yyparse(void);

extern FILE *headerfile, *codefile, *logfile;

#endif /* __GEN_LOCL_H__ */
