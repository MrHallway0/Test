/*-
 * Copyright (c) 2014 Qualcomm Atheros.
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
 * $FreeBSD: stable/11/sys/dev/ath/if_ath_pci_devlist.h 272295 2014-09-30 05:50:34Z adrian $
 */

static const struct pci_device_id ath_pci_id_table[] = {
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x0023) }, /* PCI   */
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x0024) }, /* PCI-E */
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x0027) }, /* PCI   */
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x0029) }, /* PCI   */
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x002A) }, /* PCI-E */

	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x002A,
			 PCI_VENDOR_ID_AZWAVE,
			 0x1C71),
	  .driver_data = ATH_PCI_D3_L1_WAR },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x002A,
			 PCI_VENDOR_ID_FOXCONN,
			 0xE01F),
	  .driver_data = ATH_PCI_D3_L1_WAR },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x002A,
			 0x11AD, /* LITEON */
			 0x6632),
	  .driver_data = ATH_PCI_D3_L1_WAR },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x002A,
			 0x11AD, /* LITEON */
			 0x6642),
	  .driver_data = ATH_PCI_D3_L1_WAR },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x002A,
			 PCI_VENDOR_ID_QMI,
			 0x0306),
	  .driver_data = ATH_PCI_D3_L1_WAR },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x002A,
			 0x185F, /* WNC */
			 0x309D),
	  .driver_data = ATH_PCI_D3_L1_WAR },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x002A,
			 0x10CF, /* Fujitsu */
			 0x147C),
	  .driver_data = ATH_PCI_D3_L1_WAR },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x002A,
			 0x10CF, /* Fujitsu */
			 0x147D),
	  .driver_data = ATH_PCI_D3_L1_WAR },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x002A,
			 0x10CF, /* Fujitsu */
			 0x1536),
	  .driver_data = ATH_PCI_D3_L1_WAR },

	/* AR9285 card for Asus */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x002B,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2C37),
	  .driver_data = ATH_PCI_BT_ANT_DIV },

	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x002B) }, /* PCI-E */
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x002C) }, /* PCI-E 802.11n bonded out */
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x002D) }, /* PCI   */
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x002E) }, /* PCI-E */

	/* Killer Wireless (3x3) */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0030,
			 0x1A56,
			 0x2000),
	  .driver_data = ATH_PCI_KILLER },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0030,
			 0x1A56,
			 0x2001),
	  .driver_data = ATH_PCI_KILLER },

	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x0030) }, /* PCI-E  AR9300 */

	/* PCI-E CUS198 */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2086),
	  .driver_data = ATH_PCI_CUS198 | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x1237),
	  .driver_data = ATH_PCI_CUS198 | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2126),
	  .driver_data = ATH_PCI_CUS198 | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x126A),
	  .driver_data = ATH_PCI_CUS198 | ATH_PCI_BT_ANT_DIV },

	/* PCI-E CUS230 */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2152),
	  .driver_data = ATH_PCI_CUS230 | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_FOXCONN,
			 0xE075),
	  .driver_data = ATH_PCI_CUS230 | ATH_PCI_BT_ANT_DIV },

	/* WB225 */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_ATHEROS,
			 0x3119),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_ATHEROS,
			 0x3122),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 0x185F, /* WNC */
			 0x3119),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 0x185F, /* WNC */
			 0x3027),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_SAMSUNG,
			 0x4105),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_SAMSUNG,
			 0x4106),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_SAMSUNG,
			 0x410D),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_SAMSUNG,
			 0x410E),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_SAMSUNG,
			 0x410F),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_SAMSUNG,
			 0xC706),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_SAMSUNG,
			 0xC680),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_SAMSUNG,
			 0xC708),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_LENOVO,
			 0x3218),
	  .driver_data = ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_LENOVO,
			 0x3219),
	  .driver_data = ATH_PCI_BT_ANT_DIV },

	/* AR9485 cards with PLL power-save disabled by default. */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2C97),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2100),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 0x1C56, /* ASKEY */
			 0x4001),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 0x11AD, /* LITEON */
			 0x6627),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 0x11AD, /* LITEON */
			 0x6628),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_FOXCONN,
			 0xE04E),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_FOXCONN,
			 0xE04F),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 0x144F, /* ASKEY */
			 0x7197),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 0x1B9A, /* XAVI */
			 0x2000),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 0x1B9A, /* XAVI */
			 0x2001),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x1186),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x1F86),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x1195),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_AZWAVE,
			 0x1F95),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 0x1B9A, /* XAVI */
			 0x1C00),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 0x1B9A, /* XAVI */
			 0x1C01),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0032,
			 PCI_VENDOR_ID_ASUSTEK,
			 0x850D),
	  .driver_data = ATH_PCI_NO_PLL_PWRSAVE },

	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x0032) }, /* PCI-E  AR9485 */
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x0033) }, /* PCI-E  AR9580 */

	/* PCI-E CUS217 */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2116),
	  .driver_data = ATH_PCI_CUS217 },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 0x11AD, /* LITEON */
			 0x6661),
	  .driver_data = ATH_PCI_CUS217 },

	/* AR9462 with WoW support */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 PCI_VENDOR_ID_ATHEROS,
			 0x3117),
	  .driver_data = ATH_PCI_WOW },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 PCI_VENDOR_ID_LENOVO,
			 0x3214),
	  .driver_data = ATH_PCI_WOW },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 PCI_VENDOR_ID_ATTANSIC,
			 0x0091),
	  .driver_data = ATH_PCI_WOW },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2110),
	  .driver_data = ATH_PCI_WOW },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 PCI_VENDOR_ID_ASUSTEK,
			 0x850E),
	  .driver_data = ATH_PCI_WOW },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 0x11AD, /* LITEON */
			 0x6631),
	  .driver_data = ATH_PCI_WOW },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 0x11AD, /* LITEON */
			 0x6641),
	  .driver_data = ATH_PCI_WOW },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 PCI_VENDOR_ID_HP,
			 0x1864),
	  .driver_data = ATH_PCI_WOW },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 0x14CD, /* USI */
			 0x0063),
	  .driver_data = ATH_PCI_WOW },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 0x14CD, /* USI */
			 0x0064),
	  .driver_data = ATH_PCI_WOW },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0034,
			 0x10CF, /* Fujitsu */
			 0x1783),
	  .driver_data = ATH_PCI_WOW },

	/* Killer Wireless (2x2) */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0030,
			 0x1A56,
			 0x2003),
	  .driver_data = ATH_PCI_KILLER },

	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x0034) }, /* PCI-E  AR9462 */
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x0037) }, /* PCI-E  AR1111/AR9485 */

	/* CUS252 */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_ATHEROS,
			 0x3028),
	  .driver_data = ATH_PCI_CUS252 |
			 ATH_PCI_AR9565_2ANT |
			 ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2176),
	  .driver_data = ATH_PCI_CUS252 |
			 ATH_PCI_AR9565_2ANT |
			 ATH_PCI_BT_ANT_DIV },

	/* WB335 1-ANT */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_FOXCONN,
			 0xE068),
	  .driver_data = ATH_PCI_AR9565_1ANT },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x185F, /* WNC */
			 0xA119),
	  .driver_data = ATH_PCI_AR9565_1ANT },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0632),
	  .driver_data = ATH_PCI_AR9565_1ANT },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x06B2),
	  .driver_data = ATH_PCI_AR9565_1ANT },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0842),
	  .driver_data = ATH_PCI_AR9565_1ANT },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x6671),
	  .driver_data = ATH_PCI_AR9565_1ANT },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x1B9A, /* XAVI */
			 0x2811),
	  .driver_data = ATH_PCI_AR9565_1ANT },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x1B9A, /* XAVI */
			 0x2812),
	  .driver_data = ATH_PCI_AR9565_1ANT },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x1B9A, /* XAVI */
			 0x28A1),
	  .driver_data = ATH_PCI_AR9565_1ANT },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_AZWAVE,
			 0x218A),
	  .driver_data = ATH_PCI_AR9565_1ANT },

	/* WB335 1-ANT / Antenna Diversity */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_ATHEROS,
			 0x3025),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_ATHEROS,
			 0x3026),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_ATHEROS,
			 0x302B),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_FOXCONN,
			 0xE069),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x185F, /* WNC */
			 0x3028),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0622),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0672),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0662),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x06A2),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0682),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_AZWAVE,
			 0x213A),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_HP,
			 0x18E3),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_HP,
			 0x217F),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_HP,
			 0x2005),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_DELL,
			 0x020C),
	  .driver_data = ATH_PCI_AR9565_1ANT | ATH_PCI_BT_ANT_DIV },

	/* WB335 2-ANT / Antenna-Diversity */
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_SAMSUNG,
			 0x411A),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_SAMSUNG,
			 0x411B),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_SAMSUNG,
			 0x411C),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_SAMSUNG,
			 0x411D),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_SAMSUNG,
			 0x411E),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_ATHEROS,
			 0x3027),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_ATHEROS,
			 0x302C),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0642),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0652),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0612),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0832),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x11AD, /* LITEON */
			 0x0692),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2130),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_AZWAVE,
			 0x213B),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_AZWAVE,
			 0x2182),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x144F, /* ASKEY */
			 0x7202),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x1B9A, /* XAVI */
			 0x2810),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x1B9A, /* XAVI */
			 0x28A2),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x185F, /* WNC */
			 0x3027),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 0x185F, /* WNC */
			 0xA120),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_FOXCONN,
			 0xE07F),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_FOXCONN,
			 0xE081),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_LENOVO,
			 0x3026),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_LENOVO,
			 0x4026),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_ASUSTEK,
			 0x85F2),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },
	{ PCI_DEVICE_SUB(PCI_VENDOR_ID_ATHEROS,
			 0x0036,
			 PCI_VENDOR_ID_DELL,
			 0x020E),
	  .driver_data = ATH_PCI_AR9565_2ANT | ATH_PCI_BT_ANT_DIV },

	/* PCI-E AR9565 (WB335) */
	{ PCI_VDEVICE(PCI_VENDOR_ID_ATHEROS, 0x0036),
	  .driver_data = ATH_PCI_BT_ANT_DIV },

	{ 0 }
};

