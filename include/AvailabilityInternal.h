/* $MidnightBSD$ */
/*
 * Copyright (c) 2007-2012 by Apple Inc.. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/*
    File:       AvailabilityInternal.h
 
    Contains:   implementation details of __OSX_AVAILABLE_* macros from <Availability.h>

*/
#ifndef __AVAILABILITY_INTERNAL__
#define __AVAILABILITY_INTERNAL__



#ifndef __IPHONE_OS_VERSION_MIN_REQUIRED
    #ifdef __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
        /* compiler sets __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ when -miphoneos-version-min is used */
        #define __IPHONE_OS_VERSION_MIN_REQUIRED __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
    #endif
#endif

#define __AVAILABILITY_INTERNAL_DEPRECATED            __attribute__((deprecated))
#ifdef __has_feature
    #if __has_feature(attribute_deprecated_with_message)
        #define __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)  __attribute__((deprecated(_msg)))
    #else
        #define __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)  __attribute__((deprecated))
    #endif
#elif defined(__GNUC__) && ((__GNUC__ >= 5) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 5)))
    #define __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)  __attribute__((deprecated(_msg)))
#else
    #define __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)  __attribute__((deprecated))
#endif
#define __AVAILABILITY_INTERNAL_UNAVAILABLE           __attribute__((unavailable))
#define __AVAILABILITY_INTERNAL_WEAK_IMPORT           __attribute__((weak_import))
#define __AVAILABILITY_INTERNAL_REGULAR            

#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
    /* make sure a default max version is set */
    #ifndef __IPHONE_OS_VERSION_MAX_ALLOWED
        #define __IPHONE_OS_VERSION_MAX_ALLOWED     __IPHONE_8_0
    #endif
    /* make sure a valid min is set */
    #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_0
        #undef __IPHONE_OS_VERSION_MIN_REQUIRED
        #define __IPHONE_OS_VERSION_MIN_REQUIRED    __IPHONE_2_0 
    #endif

    #if defined(__has_attribute) && defined(__has_feature)
        #if __has_attribute(availability)
            /* use better attributes if possible */
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0                    __attribute__((availability(ios,introduced=2.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_0    __attribute__((availability(ios,introduced=2.0,deprecated=2.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=2.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=2.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_1    __attribute__((availability(ios,introduced=2.0,deprecated=2.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=2.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=2.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2    __attribute__((availability(ios,introduced=2.0,deprecated=2.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=2.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=2.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0    __attribute__((availability(ios,introduced=2.0,deprecated=3.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=3.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=3.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1    __attribute__((availability(ios,introduced=2.0,deprecated=3.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=3.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=3.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2    __attribute__((availability(ios,introduced=2.0,deprecated=3.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=3.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=3.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0    __attribute__((availability(ios,introduced=2.0,deprecated=4.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=4.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=4.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1    __attribute__((availability(ios,introduced=2.0,deprecated=4.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=4.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=4.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2    __attribute__((availability(ios,introduced=2.0,deprecated=4.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=4.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=4.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3    __attribute__((availability(ios,introduced=2.0,deprecated=4.3)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=4.3,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=4.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=2.0,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=2.0,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=2.0,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=2.0,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=2.0,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=2.0,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=2.0,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.0,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=2.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=2.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1                    __attribute__((availability(ios,introduced=2.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_1    __attribute__((availability(ios,introduced=2.1,deprecated=2.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=2.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=2.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2    __attribute__((availability(ios,introduced=2.1,deprecated=2.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=2.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=2.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0    __attribute__((availability(ios,introduced=2.1,deprecated=3.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=3.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=3.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1    __attribute__((availability(ios,introduced=2.1,deprecated=3.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=3.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=3.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2    __attribute__((availability(ios,introduced=2.1,deprecated=3.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=3.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=3.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0    __attribute__((availability(ios,introduced=2.1,deprecated=4.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=4.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=4.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1    __attribute__((availability(ios,introduced=2.1,deprecated=4.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=4.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=4.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2    __attribute__((availability(ios,introduced=2.1,deprecated=4.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=4.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=4.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3    __attribute__((availability(ios,introduced=2.1,deprecated=4.3)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=4.3,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=4.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=2.1,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=2.1,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=2.1,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=2.1,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=2.1,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=2.1,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=2.1,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.1,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=2.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=2.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2                    __attribute__((availability(ios,introduced=2.2)))
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2    __attribute__((availability(ios,introduced=2.2,deprecated=2.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=2.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=2.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0    __attribute__((availability(ios,introduced=2.2,deprecated=3.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=3.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=3.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1    __attribute__((availability(ios,introduced=2.2,deprecated=3.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=3.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=3.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2    __attribute__((availability(ios,introduced=2.2,deprecated=3.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=3.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=3.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0    __attribute__((availability(ios,introduced=2.2,deprecated=4.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=4.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=4.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1    __attribute__((availability(ios,introduced=2.2,deprecated=4.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=4.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=4.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2    __attribute__((availability(ios,introduced=2.2,deprecated=4.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=4.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=4.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3    __attribute__((availability(ios,introduced=2.2,deprecated=4.3)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=4.3,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=4.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=2.2,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=2.2,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=2.2,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=2.2,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=2.2,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=2.2,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=2.2,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=2.2,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=2.2)))
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=2.2)))
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0                    __attribute__((availability(ios,introduced=3.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0    __attribute__((availability(ios,introduced=3.0,deprecated=3.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=3.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=3.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1    __attribute__((availability(ios,introduced=3.0,deprecated=3.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=3.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=3.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2    __attribute__((availability(ios,introduced=3.0,deprecated=3.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=3.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=3.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0    __attribute__((availability(ios,introduced=3.0,deprecated=4.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=4.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=4.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1    __attribute__((availability(ios,introduced=3.0,deprecated=4.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=4.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=4.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2    __attribute__((availability(ios,introduced=3.0,deprecated=4.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=4.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=4.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3    __attribute__((availability(ios,introduced=3.0,deprecated=4.3)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=4.3,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=4.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=3.0,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=3.0,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=3.0,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=3.0,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=3.0,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=3.0,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=3.0,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.0,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=3.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=3.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1                    __attribute__((availability(ios,introduced=3.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1    __attribute__((availability(ios,introduced=3.1,deprecated=3.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=3.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=3.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2    __attribute__((availability(ios,introduced=3.1,deprecated=3.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=3.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=3.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0    __attribute__((availability(ios,introduced=3.1,deprecated=4.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=4.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=4.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1    __attribute__((availability(ios,introduced=3.1,deprecated=4.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=4.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=4.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2    __attribute__((availability(ios,introduced=3.1,deprecated=4.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=4.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=4.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3    __attribute__((availability(ios,introduced=3.1,deprecated=4.3)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=4.3,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=4.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=3.1,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=3.1,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=3.1,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=3.1,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=3.1,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=3.1,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=3.1,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.1,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=3.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=3.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2                    __attribute__((availability(ios,introduced=3.2)))
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2    __attribute__((availability(ios,introduced=3.2,deprecated=3.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=3.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=3.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0    __attribute__((availability(ios,introduced=3.2,deprecated=4.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=4.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=4.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1    __attribute__((availability(ios,introduced=3.2,deprecated=4.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=4.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=4.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2    __attribute__((availability(ios,introduced=3.2,deprecated=4.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=4.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=4.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3    __attribute__((availability(ios,introduced=3.2,deprecated=4.3)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=4.3,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=4.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=3.2,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=3.2,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=3.2,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=3.2,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=3.2,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=3.2,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=3.2,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=3.2,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=3.2)))
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=3.2)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0                    __attribute__((availability(ios,introduced=4.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0    __attribute__((availability(ios,introduced=4.0,deprecated=4.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=4.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=4.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1    __attribute__((availability(ios,introduced=4.0,deprecated=4.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=4.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=4.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2    __attribute__((availability(ios,introduced=4.0,deprecated=4.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=4.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=4.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3    __attribute__((availability(ios,introduced=4.0,deprecated=4.3)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=4.3,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=4.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=4.0,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=4.0,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=4.0,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=4.0,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=4.0,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=4.0,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=4.0,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.0,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=4.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=4.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1                    __attribute__((availability(ios,introduced=4.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1    __attribute__((availability(ios,introduced=4.1,deprecated=4.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=4.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=4.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2    __attribute__((availability(ios,introduced=4.1,deprecated=4.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=4.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=4.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3    __attribute__((availability(ios,introduced=4.1,deprecated=4.3)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=4.3,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=4.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=4.1,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=4.1,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=4.1,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=4.1,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=4.1,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=4.1,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=4.1,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.1,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=4.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=4.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2                    __attribute__((availability(ios,introduced=4.2)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2    __attribute__((availability(ios,introduced=4.2,deprecated=4.2)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=4.2,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=4.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3    __attribute__((availability(ios,introduced=4.2,deprecated=4.3)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=4.3,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=4.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=4.2,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=4.2,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=4.2,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=4.2,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=4.2,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=4.2,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=4.2,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.2,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=4.2)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=4.2)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3                    __attribute__((availability(ios,introduced=4.3)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3    __attribute__((availability(ios,introduced=4.3,deprecated=4.3)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=4.3,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=4.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=4.3,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=4.3,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=4.3,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=4.3,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=4.3,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=4.3,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=4.3,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=4.3,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=4.3)))
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=4.3)))
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0                    __attribute__((availability(ios,introduced=5.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0    __attribute__((availability(ios,introduced=5.0,deprecated=5.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=5.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=5.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=5.0,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=5.0,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=5.0,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=5.0,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=5.0,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=5.0,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.0,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=5.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=5.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1                    __attribute__((availability(ios,introduced=5.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1    __attribute__((availability(ios,introduced=5.1,deprecated=5.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=5.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=5.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=5.1,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=5.1,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=5.1,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=5.1,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=5.1,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=5.1,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=5.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=5.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0                    __attribute__((availability(ios,introduced=6.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0    __attribute__((availability(ios,introduced=6.0,deprecated=6.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=6.0,deprecated=6.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __attribute__((availability(ios,introduced=6.0,deprecated=6.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=6.0,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=6.0,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=6.0,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=6.0,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=6.0,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=6.0,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=6.0,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=6.0,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=6.0,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=6.0,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=6.0,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=6.0,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=6.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=6.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1                    __attribute__((availability(ios,introduced=6.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1    __attribute__((availability(ios,introduced=6.1,deprecated=6.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=6.1,deprecated=6.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __attribute__((availability(ios,introduced=6.1,deprecated=6.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=6.1,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=6.1,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=6.1,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=6.1,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=6.1,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=6.1,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=6.1,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=6.1,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=6.1,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=6.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=6.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0                    __attribute__((availability(ios,introduced=7.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0    __attribute__((availability(ios,introduced=7.0,deprecated=7.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=7.0,deprecated=7.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __attribute__((availability(ios,introduced=7.0,deprecated=7.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=7.0,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=7.0,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=7.0,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=7.0,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=7.0,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=7.0,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=7.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=7.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1                    __attribute__((availability(ios,introduced=7.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1    __attribute__((availability(ios,introduced=7.1,deprecated=7.1)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=7.1,deprecated=7.1,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __attribute__((availability(ios,introduced=7.1,deprecated=7.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=7.1,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=7.1,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=7.1,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=7.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=7.1)))
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0                    __attribute__((availability(ios,introduced=8.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0    __attribute__((availability(ios,introduced=8.0,deprecated=8.0)))
            #if __has_feature(attribute_availability_with_message)
                    #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=8.0,deprecated=8.0,message=_msg)))
            #else
                    #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __attribute__((availability(ios,introduced=8.0,deprecated=8.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_NA               __attribute__((availability(ios,introduced=8.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_NA_MSG(_msg)     __attribute__((availability(ios,introduced=8.0)))
            #define __AVAILABILITY_INTERNAL__IPHONE_NA                               __attribute__((availability(ios,unavailable)))
            #define __AVAILABILITY_INTERNAL__IPHONE_NA_DEP__IPHONE_NA                __attribute__((availability(ios,unavailable)))
            #define __AVAILABILITY_INTERNAL__IPHONE_NA_DEP__IPHONE_NA_MSG(_msg)      __attribute__((availability(ios,unavailable)))
        #endif
    #endif

    #ifndef __AVAILABILITY_INTERNAL__IPHONE_2_0
        /* set up old style internal macros (up to 2.0) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_2_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_2_0
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_2_0
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_0              __AVAILABILITY_INTERNAL_DEPRECATED
        #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        /* set up old style internal macros (up to 2.1) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_2_1
        #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_2_1
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 2.2) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_2_2
        #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_2_2
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_2_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_2_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_2_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 3.0) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_3_0
        #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_3_0
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 3.1) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_3_1
        #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_3_1
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 3.2) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_3_2
        #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_3_2
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_3_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 4.0) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_4_0
        #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_4_0
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 4.1) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_4_1
        #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_4_1
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 4.2) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_4_2
        #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_4_2
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 4.3) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_4_3
        #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_4_3
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_4_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 5.0) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_5_0
        #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_5_0
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 5.1) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_5_1
        #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_5_1
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_5_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 6.0) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_6_0
        #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_6_0
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 6.1) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_6_1
        #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_6_1
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_1
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_6_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 7.0) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_7_0
        #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_7_0
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL__IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_7_0
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 7.1) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_7_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_7_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_7_1
        #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_7_1
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_7_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_7_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL__IPHONE_7_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_7_1
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_7_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up old style internal macros (up to 8.0) */
        #if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_8_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0                      __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_8_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0                      __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0                      __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_NA           __AVAILABILITY_INTERNAL__IPHONE_8_0
        #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_NA_MSG(_msg) __AVAILABILITY_INTERNAL__IPHONE_8_0
        #if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_2_2
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_2_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_3_2
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_3_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_2
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_2
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_4_3
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_4_3
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_5_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_5_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_6_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_6_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_6_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_7_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_7_0
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_7_1
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_7_1
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_7_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_7_1
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_7_1
        #elif __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_8_0
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_REGULAR
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL__IPHONE_8_0
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL__IPHONE_8_0
        #else
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_2_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_3_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_2_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_4_3_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_5_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_6_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_6_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_7_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_7_1_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__IPHONE_8_0_DEP__IPHONE_8_0_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #endif
        /* set up internal macros (n/a) */
        #define __AVAILABILITY_INTERNAL__IPHONE_NA                               __AVAILABILITY_INTERNAL_UNAVAILABLE
        #define __AVAILABILITY_INTERNAL__IPHONE_NA_DEP__IPHONE_NA                __AVAILABILITY_INTERNAL_UNAVAILABLE
        #define __AVAILABILITY_INTERNAL__IPHONE_NA_DEP__IPHONE_NA_MSG(_msg)      __AVAILABILITY_INTERNAL_UNAVAILABLE
    #endif

#elif defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__)
    /* compiler for Mac OS X sets __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ */
    #define __MAC_OS_X_VERSION_MIN_REQUIRED __ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
    /* make sure a default max version is set */
    #ifndef __MAC_OS_X_VERSION_MAX_ALLOWED
        #define __MAC_OS_X_VERSION_MAX_ALLOWED __MAC_10_10
    #endif

    #if defined(__has_attribute) && defined(__has_feature)
        #if __has_attribute(availability)
            /* use better attributes if possible */
            #define __AVAILABILITY_INTERNAL__MAC_10_0                  __attribute__((availability(macosx,introduced=10.0)))
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_0    __attribute__((availability(macosx,introduced=10.0,deprecated=10.0)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_0_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.0,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_0_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.0)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1    __attribute__((availability(macosx,introduced=10.0,deprecated=10.1)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.1,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2    __attribute__((availability(macosx,introduced=10.0,deprecated=10.2)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.2,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3    __attribute__((availability(macosx,introduced=10.0,deprecated=10.3)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.3,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4    __attribute__((availability(macosx,introduced=10.0,deprecated=10.4)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.4,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.4)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5    __attribute__((availability(macosx,introduced=10.0,deprecated=10.5)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.5,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.5)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6    __attribute__((availability(macosx,introduced=10.0,deprecated=10.6)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.6,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.6)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7    __attribute__((availability(macosx,introduced=10.0,deprecated=10.7)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.7,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.7)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_8    __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.8,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_9    __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.9,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.0,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.0,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.0)))
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.0)))
            #define __AVAILABILITY_INTERNAL__MAC_10_1                  __attribute__((availability(macosx,introduced=10.1)))
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_1    __attribute__((availability(macosx,introduced=10.1,deprecated=10.1)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_1_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.1,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_1_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.1)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2    __attribute__((availability(macosx,introduced=10.1,deprecated=10.2)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.2,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3    __attribute__((availability(macosx,introduced=10.1,deprecated=10.3)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.3,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4    __attribute__((availability(macosx,introduced=10.1,deprecated=10.4)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.4,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.4)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5    __attribute__((availability(macosx,introduced=10.1,deprecated=10.5)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.5,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.5)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6    __attribute__((availability(macosx,introduced=10.1,deprecated=10.6)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.6,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.6)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7    __attribute__((availability(macosx,introduced=10.1,deprecated=10.7)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.7,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.7)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_8    __attribute__((availability(macosx,introduced=10.1,deprecated=10.8)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.8,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.8)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_9    __attribute__((availability(macosx,introduced=10.1,deprecated=10.9)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.9,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.9)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.1,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.1,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.1)))
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.1)))
            #define __AVAILABILITY_INTERNAL__MAC_10_2                  __attribute__((availability(macosx,introduced=10.2)))
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_2    __attribute__((availability(macosx,introduced=10.2,deprecated=10.2)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_2_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.2,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_2_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.2)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3    __attribute__((availability(macosx,introduced=10.2,deprecated=10.3)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.3,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4    __attribute__((availability(macosx,introduced=10.2,deprecated=10.4)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.4,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.4)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5    __attribute__((availability(macosx,introduced=10.2,deprecated=10.5)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.5,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.5)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6    __attribute__((availability(macosx,introduced=10.2,deprecated=10.6)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.6,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.6)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7    __attribute__((availability(macosx,introduced=10.2,deprecated=10.7)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.7,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.7)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_8    __attribute__((availability(macosx,introduced=10.2,deprecated=10.8)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.8,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.8)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_9    __attribute__((availability(macosx,introduced=10.2,deprecated=10.9)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.9,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.9)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.2,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.2,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.2)))
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.2)))
            #define __AVAILABILITY_INTERNAL__MAC_10_3                  __attribute__((availability(macosx,introduced=10.3)))
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_3    __attribute__((availability(macosx,introduced=10.3,deprecated=10.3)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_3_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.3,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_3_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.3)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4    __attribute__((availability(macosx,introduced=10.3,deprecated=10.4)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.4,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.4)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5    __attribute__((availability(macosx,introduced=10.3,deprecated=10.5)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.5,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.5)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6    __attribute__((availability(macosx,introduced=10.3,deprecated=10.6)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.6,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.6)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7    __attribute__((availability(macosx,introduced=10.3,deprecated=10.7)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.7,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.7)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_8    __attribute__((availability(macosx,introduced=10.3,deprecated=10.8)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.8,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.8)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_9    __attribute__((availability(macosx,introduced=10.3,deprecated=10.9)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.9,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.9)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.3,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.3,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.3)))
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.3)))
            #define __AVAILABILITY_INTERNAL__MAC_10_4                  __attribute__((availability(macosx,introduced=10.4)))
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_4    __attribute__((availability(macosx,introduced=10.4,deprecated=10.4)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_4_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.4,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_4_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.4)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5    __attribute__((availability(macosx,introduced=10.4,deprecated=10.5)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.5,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.5)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6    __attribute__((availability(macosx,introduced=10.4,deprecated=10.6)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.6,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.6)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7    __attribute__((availability(macosx,introduced=10.4,deprecated=10.7)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.7,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.7)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_8    __attribute__((availability(macosx,introduced=10.4,deprecated=10.8)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.8,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.8)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_9    __attribute__((availability(macosx,introduced=10.4,deprecated=10.9)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.9,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.9)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.4,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.4,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.4)))
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.4)))
            #define __AVAILABILITY_INTERNAL__MAC_10_5                  __attribute__((availability(macosx,introduced=10.5)))
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_5    __attribute__((availability(macosx,introduced=10.5,deprecated=10.5)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.5,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_5_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.5)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6    __attribute__((availability(macosx,introduced=10.5,deprecated=10.6)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.6,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.6)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7    __attribute__((availability(macosx,introduced=10.5,deprecated=10.7)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.7,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.7)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_8    __attribute__((availability(macosx,introduced=10.5,deprecated=10.8)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.8,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.8)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_9    __attribute__((availability(macosx,introduced=10.5,deprecated=10.9)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.9,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.9)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.5,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.5,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.5)))
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.5)))
            #define __AVAILABILITY_INTERNAL__MAC_10_6                  __attribute__((availability(macosx,introduced=10.6)))
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_6    __attribute__((availability(macosx,introduced=10.6,deprecated=10.6)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.6,deprecated=10.6,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_6_MSG(_msg)    __attribute__((availability(macosx,introduced=10.6,deprecated=10.6)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7    __attribute__((availability(macosx,introduced=10.6,deprecated=10.7)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.6,deprecated=10.7,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.6,deprecated=10.7)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_8    __attribute__((availability(macosx,introduced=10.6,deprecated=10.8)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.6,deprecated=10.8,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.6,deprecated=10.8)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_9    __attribute__((availability(macosx,introduced=10.6,deprecated=10.9)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.6,deprecated=10.9,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.6,deprecated=10.9)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.6,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.6,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.6,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.6)))
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.6)))
            #define __AVAILABILITY_INTERNAL__MAC_10_7                  __attribute__((availability(macosx,introduced=10.7)))
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_7    __attribute__((availability(macosx,introduced=10.7,deprecated=10.7)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.7,deprecated=10.7,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_7_MSG(_msg)    __attribute__((availability(macosx,introduced=10.7,deprecated=10.7)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_8    __attribute__((availability(macosx,introduced=10.7,deprecated=10.8)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.7,deprecated=10.8,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.7,deprecated=10.8)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_9    __attribute__((availability(macosx,introduced=10.7,deprecated=10.9)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.7,deprecated=10.9,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.7,deprecated=10.9)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.7,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.7,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.7,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.7)))
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.7)))
            #define __AVAILABILITY_INTERNAL__MAC_10_8                  __attribute__((availability(macosx,introduced=10.8)))
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_8    __attribute__((availability(macosx,introduced=10.8,deprecated=10.8)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.8,deprecated=10.8,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_8_MSG(_msg)    __attribute__((availability(macosx,introduced=10.8,deprecated=10.8)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_9    __attribute__((availability(macosx,introduced=10.8,deprecated=10.9)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.8,deprecated=10.9,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.8,deprecated=10.9)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.8,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.8,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.8,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.8)))
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.8)))
            #define __AVAILABILITY_INTERNAL__MAC_10_9                  __attribute__((availability(macosx,introduced=10.9)))
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_9    __attribute__((availability(macosx,introduced=10.9,deprecated=10.9)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.9,deprecated=10.9,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_9_MSG(_msg)    __attribute__((availability(macosx,introduced=10.9,deprecated=10.9)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.9,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.9,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.9,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.9)))
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.9)))
            #define __AVAILABILITY_INTERNAL__MAC_10_10                  __attribute__((availability(macosx,introduced=10.10)))
            #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10    __attribute__((availability(macosx,introduced=10.10,deprecated=10.10)))
            #if __has_feature(attribute_availability_with_message)
                #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.10,deprecated=10.10,message=_msg)))
            #else
                #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10_MSG(_msg)    __attribute__((availability(macosx,introduced=10.10,deprecated=10.10)))
            #endif
            #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_NA_MSG(_msg)      __attribute__((availability(macosx,introduced=10.10)))
            #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_NA                __attribute__((availability(macosx,introduced=10.10)))
            #define __AVAILABILITY_INTERNAL__MAC_NA                        __attribute__((availability(macosx,unavailable)))
            #define __AVAILABILITY_INTERNAL__MAC_NA_DEP__MAC_NA            __attribute__((availability(macosx,unavailable)))
            #define __AVAILABILITY_INTERNAL__MAC_NA_DEP__MAC_NA_MSG(_msg)  __attribute__((availability(macosx,unavailable)))
        #endif
    #endif

    #ifndef __AVAILABILITY_INTERNAL__MAC_10_0
        /* use old style attributes */
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_10
            #define __AVAILABILITY_INTERNAL__MAC_10_10        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_10
            #define __AVAILABILITY_INTERNAL__MAC_10_10        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_10        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_9
            #define __AVAILABILITY_INTERNAL__MAC_10_9        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_9
            #define __AVAILABILITY_INTERNAL__MAC_10_9        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_9        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_8
            #define __AVAILABILITY_INTERNAL__MAC_10_8        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_8
            #define __AVAILABILITY_INTERNAL__MAC_10_8        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_8        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_7
            #define __AVAILABILITY_INTERNAL__MAC_10_7        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_7
            #define __AVAILABILITY_INTERNAL__MAC_10_7        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_7        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_6        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_5        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_4        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_3        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_2        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_1        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #if __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_UNAVAILABLE
        #elif __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_WEAK_IMPORT
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0        __AVAILABILITY_INTERNAL_REGULAR
        #endif
        #define __AVAILABILITY_INTERNAL__MAC_NA             __AVAILABILITY_INTERNAL_UNAVAILABLE
        #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_1              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_1_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1              __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_1_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_1              __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_1_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_1
        #endif
        #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_2              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_2_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2              __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_2_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2              __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_2_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_2              __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_2_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_2
        #endif
        #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_3              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_3_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3              __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_3_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3              __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_3_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3              __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_3_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_3              __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_3_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_3
        #endif
        #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_4              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_4_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4              __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_4_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4              __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_4_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4              __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_4_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4              __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_4_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_4              __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_4_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_4
        #endif
        #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_5              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5              __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5              __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5              __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5              __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5              __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_5              __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_5_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_5
        #endif
        #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_6              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6              __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6              __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6              __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6              __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6              __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6              __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_6              __AVAILABILITY_INTERNAL__MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_6_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_6
        #endif
        #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_7
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_7              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7              __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7              __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7              __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7              __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7              __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7              __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7              __AVAILABILITY_INTERNAL__MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_7              __AVAILABILITY_INTERNAL__MAC_10_7
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_7_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_7
        #endif
        #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_8
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_8              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_8              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_8              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_8              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_8              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_8              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_8              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_8              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_8              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_8              __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_8              __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_8              __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_8              __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_8              __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_8              __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_8              __AVAILABILITY_INTERNAL__MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_8              __AVAILABILITY_INTERNAL__MAC_10_7
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_7
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_8              __AVAILABILITY_INTERNAL__MAC_10_8
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_8_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_8
        #endif
        #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_9
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_9              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_9              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_9              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_9              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_9              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_9              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_9              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_9              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_9              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_9              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_9              __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_9              __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_9              __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_9              __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_9              __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_9              __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_9              __AVAILABILITY_INTERNAL__MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_9              __AVAILABILITY_INTERNAL__MAC_10_7
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_7
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_9              __AVAILABILITY_INTERNAL__MAC_10_8
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_8
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_9              __AVAILABILITY_INTERNAL__MAC_10_9
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_9_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_9
        #endif
        #if __MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_10
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
            #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10              __AVAILABILITY_INTERNAL_DEPRECATED
            #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL_DEPRECATED_MSG(_msg)
        #else
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_0
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_1
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_2
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_3
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_4
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_5
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_6
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_7
            #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_7
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_8
            #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_8
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_9
            #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_9
            #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10              __AVAILABILITY_INTERNAL__MAC_10_10
            #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_10_10_MSG(_msg)    __AVAILABILITY_INTERNAL__MAC_10_10
        #endif
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_0_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_0
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_1_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_1
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_2_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_2
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_3_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_3
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_4_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_4
        #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_5
        #define __AVAILABILITY_INTERNAL__MAC_10_5_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_5
        #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_6
        #define __AVAILABILITY_INTERNAL__MAC_10_6_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_6
        #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_7
        #define __AVAILABILITY_INTERNAL__MAC_10_7_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_7
        #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_8
        #define __AVAILABILITY_INTERNAL__MAC_10_8_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_8
        #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_9
        #define __AVAILABILITY_INTERNAL__MAC_10_9_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_9
        #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_NA             __AVAILABILITY_INTERNAL__MAC_10_10
        #define __AVAILABILITY_INTERNAL__MAC_10_10_DEP__MAC_NA_MSG(_msg)   __AVAILABILITY_INTERNAL__MAC_10_10
        #define __AVAILABILITY_INTERNAL__MAC_NA_DEP__MAC_NA               __AVAILABILITY_INTERNAL_UNAVAILABLE
        #define __AVAILABILITY_INTERNAL__MAC_NA_DEP__MAC_NA_MSG(_msg)     __AVAILABILITY_INTERNAL_UNAVAILABLE
    #endif
#endif

#endif /* __AVAILABILITY_INTERNAL__ */
