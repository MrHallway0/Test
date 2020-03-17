/*-
 * Copyright (c) 2016 Adrian Chadd <adrian@FreeBSD.org>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer,
 *    without modification.
 * 2. Redistributions in binary form must reproduce at minimum a disclaimer
 *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any
 *    redistribution must be conditioned upon including a substantially
 *    similar Disclaimer requirement for further binary redistribution.
 *
 * NO WARRANTY
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGES.
 *
 * $FreeBSD: stable/11/sys/dev/bwn/if_bwn_chipid.h 299754 2016-05-14 20:03:24Z adrian $
 */
#ifndef	__IF_BWN_CHIPID_H__
#define	__IF_BWN_CHIPID_H__

/*
 * BCMA chip identifiers.
 */
#define	BCMA_CHIP_ID_BCM4313		0x4313
#define	BCMA_CHIP_ID_BCM43142		43142
#define	BCMA_CHIP_ID_BCM43131		43131
#define	BCMA_CHIP_ID_BCM43217		43217
#define	BCMA_CHIP_ID_BCM43222		43222
#define	BCMA_CHIP_ID_BCM43224		43224
#define	 BCMA_PKG_ID_BCM43224_FAB_CSM	0x8
#define	 BCMA_PKG_ID_BCM43224_FAB_SMIC	0xa
#define	BCMA_CHIP_ID_BCM43225		43225
#define	BCMA_CHIP_ID_BCM43227		43227
#define	BCMA_CHIP_ID_BCM43228		43228
#define	BCMA_CHIP_ID_BCM43421		43421
#define	BCMA_CHIP_ID_BCM43428		43428
#define	BCMA_CHIP_ID_BCM43431		43431
#define	BCMA_CHIP_ID_BCM43460		43460
#define	BCMA_CHIP_ID_BCM4331		0x4331
#define	BCMA_CHIP_ID_BCM6362		0x6362
#define	BCMA_CHIP_ID_BCM4360		0x4360
#define	BCMA_CHIP_ID_BCM4352		0x4352
#define	BCMA_CHIP_ID_BCM4706		0x5300
#define	BCMA_CHIP_ID_BCM4716		0x4716
#define	BCMA_CHIP_ID_BCM47162		47162
#define	BCMA_CHIP_ID_BCM4748		0x4748
#define	BCMA_CHIP_ID_BCM4749		0x4749
#define	BCMA_CHIP_ID_BCM5356		0x5356
#define	BCMA_CHIP_ID_BCM5357		0x5357
#define	BCMA_CHIP_ID_BCM53572		53572
#define	BCMA_CHIP_ID_BCM4707		53010
#define	BCMA_CHIP_ID_BCM47094		53030
#define	BCMA_CHIP_ID_BCM53018		53018

#define	BCMA_BOARD_TYPE_BCM943224M93		0x008B
#define	BCMA_BOARD_TYPE_BCM943224M93A		0x0090

#endif	/* __IF_BWN_CHIPID_H__ */
