/*-
 * Copyright (c) 2007-2011 Broadcom Corporation. All rights reserved.
 *
 *    Gary Zambrano <zambrano@broadcom.com>
 *    David Christensen <davidch@broadcom.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of Broadcom Corporation nor the name of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written consent.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

 /*$MidnightBSD$*/

uint32_t regs_count_e1=319;

struct reg_addr reg_addrs_e1[319] = {
	{0x00002000,341}, {0x00002800,103}, {0x00003000,287}, {0x00003800,331},
	{0x00008800,6}, {0x0000a000,223}, {0x0000a388,1}, {0x0000a398,1},
	{0x0000a400,69}, {0x0000a518,1}, {0x0000a520,1}, {0x0000a528,1},
	{0x0000a530,1}, {0x0000a538,1}, {0x0000a540,1}, {0x0000a548,1},
	{0x0000a550,1}, {0x0000a558,1}, {0x0000a560,1}, {0x0000a568,1},
	{0x0000a570,1}, {0x0000a580,1}, {0x0000a590,1}, {0x0000a5a0,1},
	{0x0000a5c0,1}, {0x0000c000,35}, {0x0000c098,1}, {0x0000c0a8,1},
	{0x0000c100,11}, {0x0000c130,2}, {0x0000c140,2}, {0x0000c160,4},
	{0x0000c180,4}, {0x0000c1a0,4}, {0x0000c800,4}, {0x00010000,236},
	{0x000103bc,1}, {0x000103cc,1}, {0x000103dc,1}, {0x00010400,57},
	{0x000104e8,2}, {0x000104f4,2}, {0x00010500,146}, {0x00010750,2},
	{0x00010760,2}, {0x00010770,2}, {0x00010780,2}, {0x00010790,2},
	{0x000107a0,2}, {0x000107b0,2}, {0x000107c0,2}, {0x000107d0,2},
	{0x000107e0,2}, {0x00010880,2}, {0x00010900,2}, {0x00010c00,2},
	{0x00011000,2}, {0x00012000,1}, {0x00014000,1}, {0x00020000,170},
	{0x000202b4,1}, {0x000202c4,1}, {0x00020400,2}, {0x0002040c,8},
	{0x00020480,1}, {0x00020500,1}, {0x00020600,1}, {0x00028000,24674},
	{0x00040194,1}, {0x000401a4,1}, {0x00040200,4}, {0x00040400,43},
	{0x000404b8,1}, {0x000404c8,1}, {0x00040500,2}, {0x00040510,2},
	{0x00040520,2}, {0x00040530,2}, {0x00040540,2}, {0x00042000,164},
	{0x0004229c,1}, {0x000422ac,1}, {0x000422bc,1}, {0x00042400,49},
	{0x000424c8,38}, {0x00042568,2}, {0x00042800,1}, {0x00050000,116},
	{0x000501dc,1}, {0x000501ec,1}, {0x00050200,2}, {0x0005020c,7},
	{0x00050240,1}, {0x00050280,1}, {0x00052000,1}, {0x00054000,3328},
	{0x00058000,8263}, {0x00060128,1}, {0x00060138,1}, {0x00060200,1},
	{0x00061000,512}, {0x00070000,32768}, {0x000a0000,16384},
	{0x000c1000,7}, {0x000c1028,1}, {0x000c1038,1}, {0x000c1800,2},
	{0x000c2000,164}, {0x000c229c,1}, {0x000c22ac,1}, {0x000c22bc,1},
	{0x000c2400,49}, {0x000c24c8,38}, {0x000c2568,2}, {0x000c2600,1},
	{0x000c4000,165}, {0x000c42a0,1}, {0x000c42b0,1}, {0x000c42c0,1},
	{0x000c4400,51}, {0x000c44d0,38}, {0x000c4570,2}, {0x000c4600,1},
	{0x000d0000,118}, {0x000d01e4,1}, {0x000d01f4,1}, {0x000d0200,2},
	{0x000d020c,7}, {0x000d0280,1}, {0x000d0300,1}, {0x000d0400,1},
	{0x000d4000,2560}, {0x000d8000,8306}, {0x000e01d4,1}, {0x000e01e4,1},
	{0x000e0200,2}, {0x000e020c,8}, {0x000e0280,1}, {0x000e0300,1},
	{0x000e1000,1}, {0x000e2000,2048}, {0x000f0000,16384}, {0x00101000,12},
	{0x0010103c,1}, {0x0010104c,1}, {0x00101100,1}, {0x00101800,8},
	{0x00102000,18}, {0x00102054,1}, {0x00102064,1}, {0x00102080,17},
	{0x00102400,1}, {0x00103000,26}, {0x00103074,1}, {0x00103084,1},
	{0x00103094,1}, {0x00103800,8}, {0x00104000,63}, {0x00104108,1},
	{0x00104118,1}, {0x00104200,17}, {0x00104400,512}, {0x00105000,1024},
	{0x00108000,33}, {0x00108090,1}, {0x001080a0,1}, {0x00108100,5},
	{0x00108120,5}, {0x00108200,74}, {0x00108400,74}, {0x00108800,152},
	{0x00109000,1}, {0x00120000,347}, {0x00120578,1}, {0x00120588,1},
	{0x00120598,1}, {0x0012080c,65}, {0x00120a00,2}, {0x00122000,2},
	{0x00140000,114}, {0x001401d4,1}, {0x001401e4,1}, {0x00140200,6},
	{0x00144000,4}, {0x00148000,4}, {0x0014c000,4}, {0x00150000,4},
	{0x00154000,4}, {0x00158000,4}, {0x00161000,7}, {0x00161028,1},
	{0x00161038,1}, {0x00161800,2}, {0x00164000,60}, {0x001640fc,1},
	{0x0016410c,1}, {0x00164200,1}, {0x00164208,1}, {0x00164210,1},
	{0x00164218,1}, {0x00164220,1}, {0x00164228,1}, {0x00164230,1},
	{0x00164238,1}, {0x00164240,1}, {0x00164248,1}, {0x00164250,1},
	{0x00164258,1}, {0x00164260,1}, {0x00164270,2}, {0x00164280,2},
	{0x00164800,2}, {0x00165000,2}, {0x00166000,164}, {0x0016629c,1},
	{0x001662ac,1}, {0x001662bc,1}, {0x00166400,49}, {0x001664c8,38},
	{0x00166568,2}, {0x00166800,1}, {0x00168000,270}, {0x00168444,1},
	{0x00168454,1}, {0x00168800,19}, {0x00168900,1}, {0x00168a00,128},
	{0x0016a000,1536}, {0x0016c000,1536}, {0x00170000,93}, {0x00170180,1},
	{0x00170190,1}, {0x00170200,4}, {0x00170214,1}, {0x00178000,1},
	{0x00180000,61}, {0x00180100,1}, {0x00180110,1}, {0x00180120,1},
	{0x00180130,1}, {0x00180200,58}, {0x00180340,4}, {0x00180400,1},
	{0x00181000,1024}, {0x001a0000,5632}, {0x001a8000,64},
	{0x001b1800,128}, {0x001b1c00,128}, {0x001b2000,1}, {0x001b8200,1},
	{0x001b8240,1}, {0x001b8280,1}, {0x001b82c0,1}, {0x001b8a00,1},
	{0x001b8a80,1}, {0x001c0000,2}, {0x00200000,65}, {0x00200110,1},
	{0x00200120,1}, {0x00200130,1}, {0x00200140,1}, {0x00200200,58},
	{0x00200340,4}, {0x00200400,1}, {0x00202000,2048}, {0x00220000,5632},
	{0x00228000,64}, {0x00231800,128}, {0x00231c00,128}, {0x00232000,1},
	{0x00238200,1}, {0x00238240,1}, {0x00238280,1}, {0x002382c0,1},
	{0x00238a00,1}, {0x00238a80,1}, {0x00240000,2}, {0x00280000,65},
	{0x00280110,1}, {0x00280120,1}, {0x00280130,1}, {0x00280140,1},
	{0x00280200,58}, {0x00280340,4}, {0x00280400,1}, {0x00282000,2048},
	{0x002a0000,5632}, {0x002a8000,64}, {0x002b1800,128}, {0x002b1c00,128},
	{0x002b2000,1}, {0x002b8200,1}, {0x002b8240,1}, {0x002b8280,1},
	{0x002b82c0,1}, {0x002b8a00,1}, {0x002b8a80,1}, {0x002c0000,2},
	{0x00300000,65}, {0x00300110,1}, {0x00300120,1}, {0x00300130,1},
	{0x00300140,1}, {0x00300200,58}, {0x00300340,4}, {0x00300400,1},
	{0x00302000,2048}, {0x00320000,5632}, {0x00328000,64},
	{0x00331800,128}, {0x00331c00,128}, {0x00332000,1}, {0x00338200,1},
	{0x00338240,1}, {0x00338280,1}, {0x003382c0,1}, {0x00338a00,1},
	{0x00338a80,1}, {0x00340000,2}};



uint32_t wregs_count_e1=1;

static uint32_t const_reg0_e1[1] = {0x001b1000};


struct wreg_addr wreg_addrs_e1[1] = {{0x001b0c00, 192, 1, const_reg0_e1}};


struct hd_param hd_param_e1={0x497e2e43, 0x00040802, 0x0000001f};

