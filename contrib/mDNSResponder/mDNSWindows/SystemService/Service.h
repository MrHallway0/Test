/* -*- Mode: C; tab-width: 4 -*-
 *
 * Copyright (c) 2002-2004 Apple Computer, Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.

    Change History (most recent first):
    
$Log: not supported by cvs2svn $
Revision 1.1  2009/07/09 21:34:15  herscher
<rdar://problem/3775717> SDK: Port mDNSNetMonitor to Windows. Refactor the system service slightly by removing the main() function from Service.c so that mDNSNetMonitor can link to functions defined in Service.c


 */

#ifndef	__MDNS_SERVICE_H__
#define	__MDNS_SERVICE_H__


#include <windows.h>


extern int	RunDirect( int argc, LPTSTR argv[] );
extern int	Main( int argc, LPTSTR argv[] );


#endif

