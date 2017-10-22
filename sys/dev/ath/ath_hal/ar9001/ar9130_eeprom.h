/*
 * Copyright (c) 2010 Adrian Chadd, Xenion Pty Ltd
 * Copyright (c) 2010 Atheros Communications, Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * $FreeBSD: stable/9/sys/dev/ath/ath_hal/ar9001/ar9130_eeprom.h 221163 2011-04-28 12:47:40Z adrian $
 */
#ifndef	__AR9130_EEPROM_H__
#define	__AR9130_EEPROM_H__

extern	HAL_BOOL ar9130EepromRead(struct ath_hal *ah, u_int off, uint16_t *data);

#endif
