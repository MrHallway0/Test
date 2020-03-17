/*-
 * SPDX-License-Identifier: BSD-2-Clause OR GPL-2.0
 *
 * Copyright (c) 2014 Intel Corporation.  All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * $FreeBSD: stable/11/sys/ofed/drivers/infiniband/core/opa_smi.h 331772 2018-03-30 18:17:33Z hselasky $
 */

#ifndef __OPA_SMI_H_
#define __OPA_SMI_H_

#include <rdma/ib_smi.h>
#include <rdma/opa_smi.h>

#include "smi.h"

enum smi_action opa_smi_handle_dr_smp_recv(struct opa_smp *smp, bool is_switch,
				       int port_num, int phys_port_cnt);
int opa_smi_get_fwd_port(struct opa_smp *smp);
extern enum smi_forward_action opa_smi_check_forward_dr_smp(struct opa_smp *smp);
extern enum smi_action opa_smi_handle_dr_smp_send(struct opa_smp *smp,
					      bool is_switch, int port_num);

/*
 * Return IB_SMI_HANDLE if the SMP should be handled by the local SMA/SM
 * via process_mad
 */
static inline enum smi_action opa_smi_check_local_smp(struct opa_smp *smp,
						      struct ib_device *device)
{
	/* C14-9:3 -- We're at the end of the DR segment of path */
	/* C14-9:4 -- Hop Pointer = Hop Count + 1 -> give to SMA/SM */
	return (device->process_mad &&
		!opa_get_smp_direction(smp) &&
		(smp->hop_ptr == smp->hop_cnt + 1)) ?
		IB_SMI_HANDLE : IB_SMI_DISCARD;
}

/*
 * Return IB_SMI_HANDLE if the SMP should be handled by the local SMA/SM
 * via process_mad
 */
static inline enum smi_action opa_smi_check_local_returning_smp(struct opa_smp *smp,
								struct ib_device *device)
{
	/* C14-13:3 -- We're at the end of the DR segment of path */
	/* C14-13:4 -- Hop Pointer == 0 -> give to SM */
	return (device->process_mad &&
		opa_get_smp_direction(smp) &&
		!smp->hop_ptr) ? IB_SMI_HANDLE : IB_SMI_DISCARD;
}

#endif	/* __OPA_SMI_H_ */
