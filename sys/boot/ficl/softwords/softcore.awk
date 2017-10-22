#!/usr/bin/awk -f
#
# Convert forth source files to a giant C string
#
# Joe Abley <jabley@patho.gen.nz>, 12 January 1999
#
# 02-oct-1999:  Cleaned up awk slightly; added some additional logic
#               suggested by dcs to compress the stored forth program.
#
# Note! This script uses strftime() which is a gawk-ism, and the
# POSIX [[:space:]] character class.
#
# $FreeBSD: stable/9/sys/boot/ficl/softwords/softcore.awk 167850 2007-03-23 22:26:01Z jkim $

BEGIN \
{
  printf "/*******************************************************************\n";
  printf "** s o f t c o r e . c\n";
  printf "** Forth Inspired Command Language -\n";
  printf "** Words from CORE set written in FICL\n";
  printf "** Author: John Sadler (john_sadler@alum.mit.edu)\n";
  printf "** Created: 27 December 1997\n";
  printf "** Last update: %s\n", datestamp;
  printf "*******************************************************************/\n";
  printf "/*\n";
  printf "** DO NOT EDIT THIS FILE -- it is generated by softwords/softcore.awk\n";
  printf "** Make changes to the .fr files in ficl/softwords instead.\n";
  printf "** This file contains definitions that are compiled into the\n";
  printf "** system dictionary by the first virtual machine to be created.\n";
  printf "** Created automagically by ficl/softwords/softcore.awk\n";
  printf "*/\n";
  printf "/*\n";
  printf "** Copyright (c) 1997-2001 John Sadler (john_sadler@alum.mit.edu)\n";
  printf "** All rights reserved.\n";
  printf "**\n";
  printf "** Get the latest Ficl release at http://ficl.sourceforge.net\n";
  printf "**\n";
  printf "** I am interested in hearing from anyone who uses ficl. If you have\n";
  printf "** a problem, a success story, a defect, an enhancement request, or\n";
  printf "** if you would like to contribute to the ficl release, please send\n";
  printf "** contact me by email at the address above.\n";
  printf "**\n";
  printf "** L I C E N S E  and  D I S C L A I M E R\n";
  printf "** \n";
  printf "** Redistribution and use in source and binary forms, with or without\n";
  printf "** modification, are permitted provided that the following conditions\n";
  printf "** are met:\n";
  printf "** 1. Redistributions of source code must retain the above copyright\n";
  printf "**    notice, this list of conditions and the following disclaimer.\n";
  printf "** 2. Redistributions in binary form must reproduce the above copyright\n";
  printf "**    notice, this list of conditions and the following disclaimer in the\n";
  printf "**    documentation and/or other materials provided with the distribution.\n";
  printf "**\n";
  printf "** THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND\n";
  printf "** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE\n";
  printf "** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE\n";
  printf "** ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE\n";
  printf "** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL\n";
  printf "** DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS\n";
  printf "** OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)\n";
  printf "** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT\n";
  printf "** LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY\n";
  printf "** OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF\n";
  printf "** SUCH DAMAGE.\n";
  printf "*/\n";
  printf "\n";
  printf "\n#include \"ficl.h\"\n";
  printf "\nstatic char softWords[] =\n";
  printf "#if FICL_WANT_SOFTWORDS\n";

  commenting = 0;
}

# some general early substitutions
{
  gsub(/\t/, "    ");			# replace each tab with 4 spaces
  gsub(/\"/, "\\\"");			# escape quotes
  gsub(/\\[[:space:]]+$/, "");		# toss empty comments
}

# strip out empty lines
/^ *$/ \
{
  next;
}

# emit / ** lines as multi-line C comments
/^\\[[:space:]]\*\*/ \
{
  sub(/^\\[[:space:]]/, "");
  if (commenting == 0) printf "/*\n";
  printf "%s\n", $0;
  commenting = 1;
  next;
}

# strip blank lines
/^[[:space:]]*$/ \
{
  next;
}

# function to close a comment, used later
function end_comments()
{
  commenting = 0;
  printf "*/\n";
}

# pass commented preprocessor directives
/^\\[[:space:]]#/ \
{
  if (commenting) end_comments();
  sub(/^\\[[:space:]]/, "");
  printf "%s\n", $0;
  next;
}

# toss all other full-line \ comments
/^\\/ \
{
  if (commenting) end_comments();
  next;
}

# lop off trailing \ comments
/\\[[:space:]]+/ \
{
  sub(/\\[[:space:]]+.*$/, "");
}

# expunge ( ) comments
/[[:space:]]+\([[:space:]][^)]*\)/ \
{
  sub(/[[:space:]]+\([[:space:]][^)]*\)/, "");
}

# remove leading spaces
/^[[:space:]]+/ \
{
  sub(/^[[:space:]]+/, "");
}

# removing trailing spaces
/[[:space:]]+$/ \
{
  sub(/[[:space:]]+$/, "");
}

# strip out empty lines again (preceding rules may have generated some)
/^[[:space:]]*$/ \
{
  if (commenting) end_comments();
  next;
}

# emit all other lines as quoted string fragments
{
  if (commenting) end_comments();

  printf "    \"%s \"\n", $0;
  next;
}

END \
{
  if (commenting) end_comments();
  printf "#endif /* WANT_SOFTWORDS */\n";
  printf "    \"quit \";\n";
  printf "\n\nvoid ficlCompileSoftCore(FICL_SYSTEM *pSys)\n";
  printf "{\n";
  printf "    FICL_VM *pVM = pSys->vmList;\n";
  printf "    CELL id = pVM->sourceID;\n";
  printf "    int ret = sizeof (softWords);\n";
  printf "	  assert(pVM);\n";
  printf "    pVM->sourceID.i = -1;\n";
  printf "    ret = ficlExec(pVM, softWords);\n";
  printf "    pVM->sourceID = id;\n";
  printf "    if (ret == VM_ERREXIT)\n";
  printf "        assert(FALSE);\n";
  printf "    return;\n";
  printf "}\n";
}
