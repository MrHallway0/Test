/* $MidnightBSD$ */
/******************************************************************************
 *
 * Module Name: aslmessages.h - Compiler error/warning messages
 *
 *****************************************************************************/

/*
 * Copyright (C) 2000 - 2016, Intel Corp.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, and the following disclaimer,
 *    without modification.
 * 2. Redistributions in binary form must reproduce at minimum a disclaimer
 *    substantially similar to the "NO WARRANTY" disclaimer below
 *    ("Disclaimer") and any redistribution must be conditioned upon
 *    including a substantially similar Disclaimer requirement for further
 *    binary redistribution.
 * 3. Neither the names of the above-listed copyright holders nor the names
 *    of any contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * Alternatively, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") version 2 as published by the Free
 * Software Foundation.
 *
 * NO WARRANTY
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 */

#ifndef __ASLMESSAGES_H
#define __ASLMESSAGES_H


/* These values must match error type string tables in aslmessages.c */

typedef enum
{
    ASL_OPTIMIZATION = 0,
    ASL_REMARK,
    ASL_WARNING,
    ASL_WARNING2,
    ASL_WARNING3,
    ASL_ERROR,
    ASL_NUM_REPORT_LEVELS

} ASL_MESSAGE_TYPES;


#define ASL_ERROR_LEVEL_LENGTH          8 /* Length of strings for types above */

/*
 * Exception code blocks, 0 - 999
 * Available for new exception blocks: 600 - 999
 */
#define ASL_MSG_MAIN_COMPILER           0       /* 0 - 299 */
#define ASL_MSG_MAIN_COMPILER_END       299

#define ASL_MSG_TABLE_COMPILER          300     /* 300 - 499 */
#define ASL_MSG_TABLE_COMPILER_END      499

#define ASL_MSG_PREPROCESSOR            500     /* 500 - 599 */
#define ASL_MSG_PREPROCESSOR_END        599


/*
 * Values (message IDs) for all compiler messages. There are currently
 * three distinct blocks of error messages (so that they can be expanded
 * individually):
 *      Main ASL compiler
 *      Data Table compiler
 *      Preprocessor
 *
 * NOTE1: This list must match the tables of message strings in the file
 * aslmessages.c exactly.
 *
 * NOTE2: With the introduction of the -vw option to disable specific
 * messages, new messages should only be added to the end of these
 * lists, so that values for existing messages are not disturbed.
 */
typedef enum
{
    ASL_MSG_RESERVED = ASL_MSG_MAIN_COMPILER,

    ASL_MSG_ALIGNMENT,
    ASL_MSG_ALPHANUMERIC_STRING,
    ASL_MSG_AML_NOT_IMPLEMENTED,
    ASL_MSG_ARG_COUNT_HI,
    ASL_MSG_ARG_COUNT_LO,
    ASL_MSG_ARG_INIT,
    ASL_MSG_BACKWARDS_OFFSET,
    ASL_MSG_BUFFER_LENGTH,
    ASL_MSG_CLOSE,
    ASL_MSG_COMPILER_INTERNAL,
    ASL_MSG_COMPILER_RESERVED,
    ASL_MSG_CONNECTION_MISSING,
    ASL_MSG_CONNECTION_INVALID,
    ASL_MSG_CONSTANT_EVALUATION,
    ASL_MSG_CONSTANT_FOLDED,
    ASL_MSG_CORE_EXCEPTION,
    ASL_MSG_DEBUG_FILE_OPEN,
    ASL_MSG_DEBUG_FILENAME,
    ASL_MSG_DEPENDENT_NESTING,
    ASL_MSG_DMA_CHANNEL,
    ASL_MSG_DMA_LIST,
    ASL_MSG_DUPLICATE_CASE,
    ASL_MSG_DUPLICATE_ITEM,
    ASL_MSG_EARLY_EOF,
    ASL_MSG_ENCODING_LENGTH,
    ASL_MSG_EX_INTERRUPT_LIST,
    ASL_MSG_EX_INTERRUPT_LIST_MIN,
    ASL_MSG_EX_INTERRUPT_NUMBER,
    ASL_MSG_FIELD_ACCESS_WIDTH,
    ASL_MSG_FIELD_UNIT_ACCESS_WIDTH,
    ASL_MSG_FIELD_UNIT_OFFSET,
    ASL_MSG_GPE_NAME_CONFLICT,
    ASL_MSG_HID_LENGTH,
    ASL_MSG_HID_PREFIX,
    ASL_MSG_HID_SUFFIX,
    ASL_MSG_INCLUDE_FILE_OPEN,
    ASL_MSG_INPUT_FILE_OPEN,
    ASL_MSG_INTEGER_LENGTH,
    ASL_MSG_INTEGER_OPTIMIZATION,
    ASL_MSG_INTERRUPT_LIST,
    ASL_MSG_INTERRUPT_NUMBER,
    ASL_MSG_INVALID_ACCESS_SIZE,
    ASL_MSG_INVALID_ADDR_FLAGS,
    ASL_MSG_INVALID_CONSTANT_OP,
    ASL_MSG_INVALID_EISAID,
    ASL_MSG_INVALID_ESCAPE,
    ASL_MSG_INVALID_GRAN_FIXED,
    ASL_MSG_INVALID_GRANULARITY,
    ASL_MSG_INVALID_LENGTH,
    ASL_MSG_INVALID_LENGTH_FIXED,
    ASL_MSG_INVALID_MIN_MAX,
    ASL_MSG_INVALID_OPERAND,
    ASL_MSG_INVALID_PERFORMANCE,
    ASL_MSG_INVALID_PRIORITY,
    ASL_MSG_INVALID_STRING,
    ASL_MSG_INVALID_TARGET,
    ASL_MSG_INVALID_TIME,
    ASL_MSG_INVALID_TYPE,
    ASL_MSG_INVALID_UUID,
    ASL_MSG_ISA_ADDRESS,
    ASL_MSG_LEADING_ASTERISK,
    ASL_MSG_LIST_LENGTH_LONG,
    ASL_MSG_LIST_LENGTH_SHORT,
    ASL_MSG_LISTING_FILE_OPEN,
    ASL_MSG_LISTING_FILENAME,
    ASL_MSG_LOCAL_INIT,
    ASL_MSG_LOCAL_OUTSIDE_METHOD,
    ASL_MSG_LONG_LINE,
    ASL_MSG_MEMORY_ALLOCATION,
    ASL_MSG_MISSING_ENDDEPENDENT,
    ASL_MSG_MISSING_STARTDEPENDENT,
    ASL_MSG_MULTIPLE_DEFAULT,
    ASL_MSG_MULTIPLE_TYPES,
    ASL_MSG_NAME_EXISTS,
    ASL_MSG_NAME_OPTIMIZATION,
    ASL_MSG_NAMED_OBJECT_IN_WHILE,
    ASL_MSG_NESTED_COMMENT,
    ASL_MSG_NO_CASES,
    ASL_MSG_NO_REGION,
    ASL_MSG_NO_RETVAL,
    ASL_MSG_NO_WHILE,
    ASL_MSG_NON_ASCII,
    ASL_MSG_NON_ZERO,
    ASL_MSG_NOT_EXIST,
    ASL_MSG_NOT_FOUND,
    ASL_MSG_NOT_METHOD,
    ASL_MSG_NOT_PARAMETER,
    ASL_MSG_NOT_REACHABLE,
    ASL_MSG_NOT_REFERENCED,
    ASL_MSG_NULL_DESCRIPTOR,
    ASL_MSG_NULL_STRING,
    ASL_MSG_OPEN,
    ASL_MSG_OUTPUT_FILE_OPEN,
    ASL_MSG_OUTPUT_FILENAME,
    ASL_MSG_PACKAGE_LENGTH,
    ASL_MSG_PREPROCESSOR_FILENAME,
    ASL_MSG_READ,
    ASL_MSG_RECURSION,
    ASL_MSG_REGION_BUFFER_ACCESS,
    ASL_MSG_REGION_BYTE_ACCESS,
    ASL_MSG_RESERVED_ARG_COUNT_HI,
    ASL_MSG_RESERVED_ARG_COUNT_LO,
    ASL_MSG_RESERVED_METHOD,
    ASL_MSG_RESERVED_NO_RETURN_VAL,
    ASL_MSG_RESERVED_OPERAND_TYPE,
    ASL_MSG_RESERVED_PACKAGE_LENGTH,
    ASL_MSG_RESERVED_RETURN_VALUE,
    ASL_MSG_RESERVED_USE,
    ASL_MSG_RESERVED_WORD,
    ASL_MSG_RESOURCE_FIELD,
    ASL_MSG_RESOURCE_INDEX,
    ASL_MSG_RESOURCE_LIST,
    ASL_MSG_RESOURCE_SOURCE,
    ASL_MSG_RESULT_NOT_USED,
    ASL_MSG_RETURN_TYPES,
    ASL_MSG_SCOPE_FWD_REF,
    ASL_MSG_SCOPE_TYPE,
    ASL_MSG_SEEK,
    ASL_MSG_SERIALIZED,
    ASL_MSG_SERIALIZED_REQUIRED,
    ASL_MSG_SINGLE_NAME_OPTIMIZATION,
    ASL_MSG_SOME_NO_RETVAL,
    ASL_MSG_STRING_LENGTH,
    ASL_MSG_SWITCH_TYPE,
    ASL_MSG_SYNC_LEVEL,
    ASL_MSG_SYNTAX,
    ASL_MSG_TABLE_SIGNATURE,
    ASL_MSG_TAG_LARGER,
    ASL_MSG_TAG_SMALLER,
    ASL_MSG_TIMEOUT,
    ASL_MSG_TOO_MANY_TEMPS,
    ASL_MSG_TRUNCATION,
    ASL_MSG_UNKNOWN_RESERVED_NAME,
    ASL_MSG_UNREACHABLE_CODE,
    ASL_MSG_UNSUPPORTED,
    ASL_MSG_UPPER_CASE,
    ASL_MSG_VENDOR_LIST,
    ASL_MSG_WRITE,
    ASL_MSG_RANGE,
    ASL_MSG_BUFFER_ALLOCATION,
    ASL_MSG_MISSING_DEPENDENCY,
    ASL_MSG_ILLEGAL_FORWARD_REF,
    ASL_MSG_ILLEGAL_METHOD_REF,
    ASL_MSG_LOCAL_NOT_USED,
    ASL_MSG_ARG_AS_LOCAL_NOT_USED,
    ASL_MSG_ARG_NOT_USED,
    ASL_MSG_CONSTANT_REQUIRED,
    ASL_MSG_CROSS_TABLE_SCOPE,

    /* These messages are used by the Data Table compiler only */

    ASL_MSG_BUFFER_ELEMENT = ASL_MSG_TABLE_COMPILER,
    ASL_MSG_DIVIDE_BY_ZERO,
    ASL_MSG_FLAG_VALUE,
    ASL_MSG_INTEGER_SIZE,
    ASL_MSG_INVALID_EXPRESSION,
    ASL_MSG_INVALID_FIELD_NAME,
    ASL_MSG_INVALID_HEX_INTEGER,
    ASL_MSG_OEM_TABLE,
    ASL_MSG_RESERVED_VALUE,
    ASL_MSG_UNKNOWN_LABEL,
    ASL_MSG_UNKNOWN_SUBTABLE,
    ASL_MSG_UNKNOWN_TABLE,
    ASL_MSG_ZERO_VALUE,

    /* These messages are used by the Preprocessor only */

    ASL_MSG_DIRECTIVE_SYNTAX = ASL_MSG_PREPROCESSOR,
    ASL_MSG_ENDIF_MISMATCH,
    ASL_MSG_ERROR_DIRECTIVE,
    ASL_MSG_EXISTING_NAME,
    ASL_MSG_INVALID_INVOCATION,
    ASL_MSG_MACRO_SYNTAX,
    ASL_MSG_TOO_MANY_ARGUMENTS,
    ASL_MSG_UNKNOWN_DIRECTIVE,
    ASL_MSG_UNKNOWN_PRAGMA,
    ASL_MSG_WARNING_DIRECTIVE,
    ASL_MSG_INCLUDE_FILE

} ASL_MESSAGE_IDS;


#endif  /* __ASLMESSAGES_H */
