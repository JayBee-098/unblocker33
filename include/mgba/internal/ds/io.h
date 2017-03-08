/* Copyright (c) 2013-2017 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef DS_IO_H
#define DS_IO_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba/core/log.h>

enum DSIORegisters {
	// Video
	DS_REG_DISPSTAT = 0x004,
	DS_REG_VCOUNT = 0x006,

	// DMA
	DS_REG_DMA0SAD_LO = 0x0B0,
	DS_REG_DMA0SAD_HI = 0x0B2,
	DS_REG_DMA0DAD_LO = 0x0B4,
	DS_REG_DMA0DAD_HI = 0x0B6,
	DS_REG_DMA0CNT_LO = 0x0B8,
	DS_REG_DMA0CNT_HI = 0x0BA,
	DS_REG_DMA1SAD_LO = 0x0BC,
	DS_REG_DMA1SAD_HI = 0x0BE,
	DS_REG_DMA1DAD_LO = 0x0C0,
	DS_REG_DMA1DAD_HI = 0x0C2,
	DS_REG_DMA1CNT_LO = 0x0C4,
	DS_REG_DMA1CNT_HI = 0x0C6,
	DS_REG_DMA2SAD_LO = 0x0C8,
	DS_REG_DMA2SAD_HI = 0x0CA,
	DS_REG_DMA2DAD_LO = 0x0CC,
	DS_REG_DMA2DAD_HI = 0x0CE,
	DS_REG_DMA2CNT_LO = 0x0D0,
	DS_REG_DMA2CNT_HI = 0x0D2,
	DS_REG_DMA3SAD_LO = 0x0D4,
	DS_REG_DMA3SAD_HI = 0x0D6,
	DS_REG_DMA3DAD_LO = 0x0D8,
	DS_REG_DMA3DAD_HI = 0x0DA,
	DS_REG_DMA3CNT_LO = 0x0DC,
	DS_REG_DMA3CNT_HI = 0x0DE,
	DS_REG_DMA0FILL_LO = 0x0E0,
	DS_REG_DMA0FILL_HI = 0x0E2,
	DS_REG_DMA1FILL_LO = 0x0E4,
	DS_REG_DMA1FILL_HI = 0x0E6,
	DS_REG_DMA2FILL_LO = 0x0E8,
	DS_REG_DMA2FILL_HI = 0x0EA,
	DS_REG_DMA3FILL_LO = 0x0EC,
	DS_REG_DMA3FILL_HI = 0x0EE,

	// Timers
	DS_REG_TM0CNT_LO = 0x100,
	DS_REG_TM0CNT_HI = 0x102,
	DS_REG_TM1CNT_LO = 0x104,
	DS_REG_TM1CNT_HI = 0x106,
	DS_REG_TM2CNT_LO = 0x108,
	DS_REG_TM2CNT_HI = 0x10A,
	DS_REG_TM3CNT_LO = 0x10C,
	DS_REG_TM3CNT_HI = 0x10E,

	// Keypad
	DS_REG_KEYINPUT = 0x130,
	DS_REG_KEYCNT = 0x132,

	// IPC
	DS_REG_IPCSYNC = 0x180,
	DS_REG_IPCFIFOCNT = 0x184,
	DS_REG_IPCFIFOSEND_LO = 0x188,
	DS_REG_IPCFIFOSEND_HI = 0x18A,
	DS_REG_IPCFIFORECV_LO = 0x100000,
	DS_REG_IPCFIFORECV_HI = 0x100002,

	// Game card
	DS_REG_AUXSPICNT = 0x1A0,
	DS_REG_AUXSPIDATA = 0x1A2,
	DS_REG_ROMCNT_LO = 0x1A4,
	DS_REG_ROMCNT_HI = 0x1A6,
	DS_REG_ROMCMD_0 = 0x1A8,
	DS_REG_ROMCMD_1 = 0x1A9,
	DS_REG_ROMCMD_2 = 0x1AA,
	DS_REG_ROMCMD_3 = 0x1AB,
	DS_REG_ROMCMD_4 = 0x1AC,
	DS_REG_ROMCMD_5 = 0x1AD,
	DS_REG_ROMCMD_6 = 0x1AE,
	DS_REG_ROMCMD_7 = 0x1AF,
	DS_REG_ROMDATA_0 = 0x100010,
	DS_REG_ROMDATA_1 = 0x100011,
	DS_REG_ROMDATA_2 = 0x100012,
	DS_REG_ROMDATA_3 = 0x100013,

	// Interrupts
	DS_REG_IME = 0x208,
	DS_REG_IE_LO = 0x210,
	DS_REG_IE_HI = 0x212,
	DS_REG_IF_LO = 0x214,
	DS_REG_IF_HI = 0x216,

	DS_REG_POSTFLG = 0x300,
};

enum DS7IORegisters {
	// Keypad
	DS7_REG_EXTKEYIN = 0x136,
	DS7_REG_RTC = 0x138,

	// SPI
	DS7_REG_SPICNT = 0x1C0,
	DS7_REG_SPIDATA = 0x1C2,

	// Etc
	DS7_REG_EXMEMSTAT = 0x204,

	// Memory control
	DS7_REG_VRAMSTAT = 0x240,
	DS7_REG_WRAMSTAT = 0x241,
	DS7_REG_HALTCNT = 0x301,
	DS7_REG_POWCNT2 = 0x304,
	DS7_REG_BIOSPROT_LO = 0x308,
	DS7_REG_BIOSPROT_HI = 0x30A,

	// Audio
	DS7_REG_SOUND0CNT_LO = 0x400,
	DS7_REG_SOUND0CNT_HI = 0x402,
	DS7_REG_SOUND0SAD_LO = 0x404,
	DS7_REG_SOUND0SAD_HI = 0x406,
	DS7_REG_SOUND0TMR    = 0x408,
	DS7_REG_SOUND0PNT    = 0x40A,
	DS7_REG_SOUND0LEN_LO = 0x40C,
	DS7_REG_SOUND0LEN_HI = 0x40E,
	DS7_REG_SOUND1CNT_LO = 0x410,
	DS7_REG_SOUND1CNT_HI = 0x412,
	DS7_REG_SOUND1SAD_LO = 0x414,
	DS7_REG_SOUND1SAD_HI = 0x416,
	DS7_REG_SOUND1TMR    = 0x418,
	DS7_REG_SOUND1PNT    = 0x41A,
	DS7_REG_SOUND1LEN_LO = 0x41C,
	DS7_REG_SOUND1LEN_HI = 0x41E,
	DS7_REG_SOUND2CNT_LO = 0x420,
	DS7_REG_SOUND2CNT_HI = 0x422,
	DS7_REG_SOUND2SAD_LO = 0x424,
	DS7_REG_SOUND2SAD_HI = 0x426,
	DS7_REG_SOUND2TMR    = 0x428,
	DS7_REG_SOUND2PNT    = 0x42A,
	DS7_REG_SOUND2LEN_LO = 0x42C,
	DS7_REG_SOUND2LEN_HI = 0x42E,
	DS7_REG_SOUND3CNT_LO = 0x430,
	DS7_REG_SOUND3CNT_HI = 0x432,
	DS7_REG_SOUND3SAD_LO = 0x434,
	DS7_REG_SOUND3SAD_HI = 0x436,
	DS7_REG_SOUND3TMR    = 0x438,
	DS7_REG_SOUND3PNT    = 0x43A,
	DS7_REG_SOUND3LEN_LO = 0x43C,
	DS7_REG_SOUND3LEN_HI = 0x43E,
	DS7_REG_SOUND4CNT_LO = 0x440,
	DS7_REG_SOUND4CNT_HI = 0x442,
	DS7_REG_SOUND4SAD_LO = 0x444,
	DS7_REG_SOUND4SAD_HI = 0x446,
	DS7_REG_SOUND4TMR    = 0x448,
	DS7_REG_SOUND4PNT    = 0x44A,
	DS7_REG_SOUND4LEN_LO = 0x44C,
	DS7_REG_SOUND4LEN_HI = 0x44E,
	DS7_REG_SOUND5CNT_LO = 0x450,
	DS7_REG_SOUND5CNT_HI = 0x452,
	DS7_REG_SOUND5SAD_LO = 0x454,
	DS7_REG_SOUND5SAD_HI = 0x456,
	DS7_REG_SOUND5TMR    = 0x458,
	DS7_REG_SOUND5PNT    = 0x45A,
	DS7_REG_SOUND5LEN_LO = 0x45C,
	DS7_REG_SOUND5LEN_HI = 0x45E,
	DS7_REG_SOUND6CNT_LO = 0x460,
	DS7_REG_SOUND6CNT_HI = 0x462,
	DS7_REG_SOUND6SAD_LO = 0x464,
	DS7_REG_SOUND6SAD_HI = 0x466,
	DS7_REG_SOUND6TMR    = 0x468,
	DS7_REG_SOUND6PNT    = 0x46A,
	DS7_REG_SOUND6LEN_LO = 0x46C,
	DS7_REG_SOUND6LEN_HI = 0x46E,
	DS7_REG_SOUND7CNT_LO = 0x470,
	DS7_REG_SOUND7CNT_HI = 0x472,
	DS7_REG_SOUND7SAD_LO = 0x474,
	DS7_REG_SOUND7SAD_HI = 0x476,
	DS7_REG_SOUND7TMR    = 0x478,
	DS7_REG_SOUND7PNT    = 0x47A,
	DS7_REG_SOUND7LEN_LO = 0x47C,
	DS7_REG_SOUND7LEN_HI = 0x47E,
	DS7_REG_SOUND8CNT_LO = 0x480,
	DS7_REG_SOUND8CNT_HI = 0x482,
	DS7_REG_SOUND8SAD_LO = 0x484,
	DS7_REG_SOUND8SAD_HI = 0x486,
	DS7_REG_SOUND8TMR    = 0x488,
	DS7_REG_SOUND8PNT    = 0x48A,
	DS7_REG_SOUND8LEN_LO = 0x48C,
	DS7_REG_SOUND8LEN_HI = 0x48E,
	DS7_REG_SOUND9CNT_LO = 0x490,
	DS7_REG_SOUND9CNT_HI = 0x492,
	DS7_REG_SOUND9SAD_LO = 0x494,
	DS7_REG_SOUND9SAD_HI = 0x496,
	DS7_REG_SOUND9TMR    = 0x498,
	DS7_REG_SOUND9PNT    = 0x49A,
	DS7_REG_SOUND9LEN_LO = 0x49C,
	DS7_REG_SOUND9LEN_HI = 0x49E,
	DS7_REG_SOUNDACNT_LO = 0x4A0,
	DS7_REG_SOUNDACNT_HI = 0x4A2,
	DS7_REG_SOUNDASAD_LO = 0x4A4,
	DS7_REG_SOUNDASAD_HI = 0x4A6,
	DS7_REG_SOUNDATMR    = 0x4A8,
	DS7_REG_SOUNDAPNT    = 0x4AA,
	DS7_REG_SOUNDALEN_LO = 0x4AC,
	DS7_REG_SOUNDALEN_HI = 0x4AE,
	DS7_REG_SOUNDBCNT_LO = 0x4B0,
	DS7_REG_SOUNDBCNT_HI = 0x4B2,
	DS7_REG_SOUNDBSAD_LO = 0x4B4,
	DS7_REG_SOUNDBSAD_HI = 0x4B6,
	DS7_REG_SOUNDBTMR    = 0x4B8,
	DS7_REG_SOUNDBPNT    = 0x4BA,
	DS7_REG_SOUNDBLEN_LO = 0x4BC,
	DS7_REG_SOUNDBLEN_HI = 0x4BE,
	DS7_REG_SOUNDCCNT_LO = 0x4C0,
	DS7_REG_SOUNDCCNT_HI = 0x4C2,
	DS7_REG_SOUNDCSAD_LO = 0x4C4,
	DS7_REG_SOUNDCSAD_HI = 0x4C6,
	DS7_REG_SOUNDCTMR    = 0x4C8,
	DS7_REG_SOUNDCPNT    = 0x4CA,
	DS7_REG_SOUNDCLEN_LO = 0x4CC,
	DS7_REG_SOUNDCLEN_HI = 0x4CE,
	DS7_REG_SOUNDDCNT_LO = 0x4D0,
	DS7_REG_SOUNDDCNT_HI = 0x4D2,
	DS7_REG_SOUNDDSAD_LO = 0x4D4,
	DS7_REG_SOUNDDSAD_HI = 0x4D6,
	DS7_REG_SOUNDDTMR    = 0x4D8,
	DS7_REG_SOUNDDPNT    = 0x4DA,
	DS7_REG_SOUNDDLEN_LO = 0x4DC,
	DS7_REG_SOUNDDLEN_HI = 0x4DE,
	DS7_REG_SOUNDECNT_LO = 0x4E0,
	DS7_REG_SOUNDECNT_HI = 0x4E2,
	DS7_REG_SOUNDESAD_LO = 0x4E4,
	DS7_REG_SOUNDESAD_HI = 0x4E6,
	DS7_REG_SOUNDETMR    = 0x4E8,
	DS7_REG_SOUNDEPNT    = 0x4EA,
	DS7_REG_SOUNDELEN_LO = 0x4EC,
	DS7_REG_SOUNDELEN_HI = 0x4EE,
	DS7_REG_SOUNDFCNT_LO = 0x4F0,
	DS7_REG_SOUNDFCNT_HI = 0x4F2,
	DS7_REG_SOUNDFSAD_LO = 0x4F4,
	DS7_REG_SOUNDFSAD_HI = 0x4F6,
	DS7_REG_SOUNDFTMR    = 0x4F8,
	DS7_REG_SOUNDFPNT    = 0x4FA,
	DS7_REG_SOUNDFLEN_LO = 0x4FC,
	DS7_REG_SOUNDFLEN_HI = 0x4FE,
	DS7_REG_SOUNDCNT = 0x500,
	DS7_REG_SOUNDBIAS = 0x504,

	DS7_REG_MAX = 0x51E,

	DS7_IO_BASE_WIFI = 0x800000,
	DS7_IO_END_WIFI = 0x810000,
};

enum DS9IORegisters {
	// Video
	DS9_REG_A_DISPCNT_LO = 0x000,
	DS9_REG_A_DISPCNT_HI = 0x002,
	DS9_REG_A_BG0CNT = 0x008,
	DS9_REG_A_BG1CNT = 0x00A,
	DS9_REG_A_BG2CNT = 0x00C,
	DS9_REG_A_BG3CNT = 0x00E,
	DS9_REG_A_BG0HOFS = 0x010,
	DS9_REG_A_BG0VOFS = 0x012,
	DS9_REG_A_BG1HOFS = 0x014,
	DS9_REG_A_BG1VOFS = 0x016,
	DS9_REG_A_BG2HOFS = 0x018,
	DS9_REG_A_BG2VOFS = 0x01A,
	DS9_REG_A_BG3HOFS = 0x01C,
	DS9_REG_A_BG3VOFS = 0x01E,
	DS9_REG_A_BG2PA = 0x020,
	DS9_REG_A_BG2PB = 0x022,
	DS9_REG_A_BG2PC = 0x024,
	DS9_REG_A_BG2PD = 0x026,
	DS9_REG_A_BG2X_LO = 0x028,
	DS9_REG_A_BG2X_HI = 0x02A,
	DS9_REG_A_BG2Y_LO = 0x02C,
	DS9_REG_A_BG2Y_HI = 0x02E,
	DS9_REG_A_BG3PA = 0x030,
	DS9_REG_A_BG3PB = 0x032,
	DS9_REG_A_BG3PC = 0x034,
	DS9_REG_A_BG3PD = 0x036,
	DS9_REG_A_BG3X_LO = 0x038,
	DS9_REG_A_BG3X_HI = 0x03A,
	DS9_REG_A_BG3Y_LO = 0x03C,
	DS9_REG_A_BG3Y_HI = 0x03E,
	DS9_REG_A_WIN0H = 0x040,
	DS9_REG_A_WIN1H = 0x042,
	DS9_REG_A_WIN0V = 0x044,
	DS9_REG_A_WIN1V = 0x046,
	DS9_REG_A_WININ = 0x048,
	DS9_REG_A_WINOUT = 0x04A,
	DS9_REG_A_MOSAIC = 0x04C,
	DS9_REG_A_BLDCNT = 0x050,
	DS9_REG_A_BLDALPHA = 0x052,
	DS9_REG_A_BLDY = 0x054,
	DS9_REG_DISPCAPCNT_LO = 0x064,
	DS9_REG_DISPCAPCNT_HI = 0x066,
	DS9_REG_DISP_MMEM_FIFO_LO = 0x068,
	DS9_REG_DISP_MMEM_FIFO_HI = 0x06A,
	DS9_REG_A_MASTER_BRIGHT = 0x06C,

	DS9_REG_B_DISPCNT_LO = 0x1000,
	DS9_REG_B_DISPCNT_HI = 0x1002,
	DS9_REG_B_BG0CNT = 0x1008,
	DS9_REG_B_BG1CNT = 0x100A,
	DS9_REG_B_BG2CNT = 0x100C,
	DS9_REG_B_BG3CNT = 0x100E,
	DS9_REG_B_BG0HOFS = 0x1010,
	DS9_REG_B_BG0VOFS = 0x1012,
	DS9_REG_B_BG1HOFS = 0x1014,
	DS9_REG_B_BG1VOFS = 0x1016,
	DS9_REG_B_BG2HOFS = 0x1018,
	DS9_REG_B_BG2VOFS = 0x101A,
	DS9_REG_B_BG3HOFS = 0x101C,
	DS9_REG_B_BG3VOFS = 0x101E,
	DS9_REG_B_BG2PA = 0x1020,
	DS9_REG_B_BG2PB = 0x1022,
	DS9_REG_B_BG2PC = 0x1024,
	DS9_REG_B_BG2PD = 0x1026,
	DS9_REG_B_BG2X_LO = 0x1028,
	DS9_REG_B_BG2X_HI = 0x102A,
	DS9_REG_B_BG2Y_LO = 0x102C,
	DS9_REG_B_BG2Y_HI = 0x102E,
	DS9_REG_B_BG3PA = 0x1030,
	DS9_REG_B_BG3PB = 0x1032,
	DS9_REG_B_BG3PC = 0x1034,
	DS9_REG_B_BG3PD = 0x1036,
	DS9_REG_B_BG3X_LO = 0x1038,
	DS9_REG_B_BG3X_HI = 0x103A,
	DS9_REG_B_BG3Y_LO = 0x103C,
	DS9_REG_B_BG3Y_HI = 0x103E,
	DS9_REG_B_WIN0H = 0x1040,
	DS9_REG_B_WIN1H = 0x1042,
	DS9_REG_B_WIN0V = 0x1044,
	DS9_REG_B_WIN1V = 0x1046,
	DS9_REG_B_WININ = 0x1048,
	DS9_REG_B_WINOUT = 0x104A,
	DS9_REG_B_MOSAIC = 0x104C,
	DS9_REG_B_BLDCNT = 0x1050,
	DS9_REG_B_BLDALPHA = 0x1052,
	DS9_REG_B_BLDY = 0x1054,
	DS9_REG_B_MASTER_BRIGHT = 0x106C,

	// Etc
	DS9_REG_EXMEMCNT = 0x204,

	// Memory control
	DS9_REG_VRAMCNT_A = 0x240,
	DS9_REG_VRAMCNT_B = 0x241,
	DS9_REG_VRAMCNT_C = 0x242,
	DS9_REG_VRAMCNT_D = 0x243,
	DS9_REG_VRAMCNT_E = 0x244,
	DS9_REG_VRAMCNT_F = 0x245,
	DS9_REG_VRAMCNT_G = 0x246,
	DS9_REG_WRAMCNT = 0x247,
	DS9_REG_VRAMCNT_H = 0x248,
	DS9_REG_VRAMCNT_I = 0x249,

	// Math
	DS9_REG_DIVCNT = 0x280,
	DS9_REG_DIV_NUMER_0 = 0x290,
	DS9_REG_DIV_NUMER_1 = 0x292,
	DS9_REG_DIV_NUMER_2 = 0x294,
	DS9_REG_DIV_NUMER_3 = 0x296,
	DS9_REG_DIV_DENOM_0 = 0x298,
	DS9_REG_DIV_DENOM_1 = 0x29A,
	DS9_REG_DIV_DENOM_2 = 0x29C,
	DS9_REG_DIV_DENOM_3 = 0x29E,
	DS9_REG_DIV_RESULT_0 = 0x2A0,
	DS9_REG_DIV_RESULT_1 = 0x2A2,
	DS9_REG_DIV_RESULT_2 = 0x2A4,
	DS9_REG_DIV_RESULT_3 = 0x2A6,
	DS9_REG_DIVREM_RESULT_0 = 0x2A8,
	DS9_REG_DIVREM_RESULT_1 = 0x2AA,
	DS9_REG_DIVREM_RESULT_2 = 0x2AC,
	DS9_REG_DIVREM_RESULT_3 = 0x2AE,
	DS9_REG_SQRTCNT = 0x2B0,
	DS9_REG_SQRT_RESULT_LO = 0x2B4,
	DS9_REG_SQRT_RESULT_HI = 0x2B6,
	DS9_REG_SQRT_PARAM_0 = 0x2B8,
	DS9_REG_SQRT_PARAM_1 = 0x2BA,
	DS9_REG_SQRT_PARAM_2 = 0x2BC,
	DS9_REG_SQRT_PARAM_3 = 0x2BE,

	// GX
	DS9_REG_DISP3DCNT = 0x060,
	DS9_REG_RDLINES_COUNT = 0x320,
	DS9_REG_EDGE_COLOR_0 = 0x330,
	DS9_REG_EDGE_COLOR_1 = 0x332,
	DS9_REG_EDGE_COLOR_2 = 0x334,
	DS9_REG_EDGE_COLOR_3 = 0x336,
	DS9_REG_EDGE_COLOR_4 = 0x338,
	DS9_REG_EDGE_COLOR_5 = 0x33A,
	DS9_REG_EDGE_COLOR_6 = 0x33C,
	DS9_REG_EDGE_COLOR_7 = 0x33E,
	DS9_REG_ALPHA_TEST_REF = 0x340,
	DS9_REG_CLEAR_COLOR_LO = 0x350,
	DS9_REG_CLEAR_COLOR_HI = 0x352,
	DS9_REG_CLEAR_DEPTH = 0x354,
	DS9_REG_CLRIMAGE_OFFSET = 0x356,
	DS9_REG_FOG_COLOR_LO = 0x358,
	DS9_REG_FOG_COLOR_HI = 0x35A,
	DS9_REG_FOG_OFFSET = 0x35C,
	DS9_REG_FOG_TABLE_0 = 0x360,
	DS9_REG_FOG_TABLE_1 = 0x362,
	DS9_REG_FOG_TABLE_2 = 0x364,
	DS9_REG_FOG_TABLE_3 = 0x366,
	DS9_REG_FOG_TABLE_4 = 0x368,
	DS9_REG_FOG_TABLE_5 = 0x36A,
	DS9_REG_FOG_TABLE_6 = 0x36C,
	DS9_REG_FOG_TABLE_7 = 0x36E,
	DS9_REG_FOG_TABLE_8 = 0x370,
	DS9_REG_FOG_TABLE_9 = 0x372,
	DS9_REG_FOG_TABLE_A = 0x374,
	DS9_REG_FOG_TABLE_B = 0x376,
	DS9_REG_FOG_TABLE_C = 0x378,
	DS9_REG_FOG_TABLE_D = 0x37A,
	DS9_REG_FOG_TABLE_E = 0x37C,
	DS9_REG_FOG_TABLE_F = 0x37E,
	DS9_REG_TOON_TABLE_00 = 0x380,
	DS9_REG_TOON_TABLE_01 = 0x382,
	DS9_REG_TOON_TABLE_02 = 0x384,
	DS9_REG_TOON_TABLE_03 = 0x386,
	DS9_REG_TOON_TABLE_04 = 0x388,
	DS9_REG_TOON_TABLE_05 = 0x38A,
	DS9_REG_TOON_TABLE_06 = 0x38C,
	DS9_REG_TOON_TABLE_07 = 0x38E,
	DS9_REG_TOON_TABLE_08 = 0x390,
	DS9_REG_TOON_TABLE_09 = 0x392,
	DS9_REG_TOON_TABLE_0A = 0x394,
	DS9_REG_TOON_TABLE_0B = 0x396,
	DS9_REG_TOON_TABLE_0C = 0x398,
	DS9_REG_TOON_TABLE_0D = 0x39A,
	DS9_REG_TOON_TABLE_0E = 0x39C,
	DS9_REG_TOON_TABLE_0F = 0x39E,
	DS9_REG_TOON_TABLE_10 = 0x3A0,
	DS9_REG_TOON_TABLE_11 = 0x3A2,
	DS9_REG_TOON_TABLE_12 = 0x3A4,
	DS9_REG_TOON_TABLE_13 = 0x3A6,
	DS9_REG_TOON_TABLE_14 = 0x3A8,
	DS9_REG_TOON_TABLE_15 = 0x3AA,
	DS9_REG_TOON_TABLE_16 = 0x3AC,
	DS9_REG_TOON_TABLE_17 = 0x3AE,
	DS9_REG_TOON_TABLE_18 = 0x3B0,
	DS9_REG_TOON_TABLE_19 = 0x3B2,
	DS9_REG_TOON_TABLE_1A = 0x3B4,
	DS9_REG_TOON_TABLE_1B = 0x3B6,
	DS9_REG_TOON_TABLE_1C = 0x3B8,
	DS9_REG_TOON_TABLE_1D = 0x3BA,
	DS9_REG_TOON_TABLE_1E = 0x3BC,
	DS9_REG_TOON_TABLE_1F = 0x3BE,
	DS9_REG_GXFIFO_00 = 0x400,
	DS9_REG_GXFIFO_01 = 0x402,
	DS9_REG_GXFIFO_02 = 0x404,
	DS9_REG_GXFIFO_03 = 0x406,
	DS9_REG_GXFIFO_04 = 0x408,
	DS9_REG_GXFIFO_05 = 0x40A,
	DS9_REG_GXFIFO_06 = 0x40C,
	DS9_REG_GXFIFO_07 = 0x40E,
	DS9_REG_GXFIFO_08 = 0x410,
	DS9_REG_GXFIFO_09 = 0x412,
	DS9_REG_GXFIFO_0A = 0x414,
	DS9_REG_GXFIFO_0B = 0x416,
	DS9_REG_GXFIFO_0C = 0x418,
	DS9_REG_GXFIFO_0D = 0x41A,
	DS9_REG_GXFIFO_0E = 0x41C,
	DS9_REG_GXFIFO_0F = 0x41E,
	DS9_REG_GXFIFO_10 = 0x420,
	DS9_REG_GXFIFO_11 = 0x422,
	DS9_REG_GXFIFO_12 = 0x424,
	DS9_REG_GXFIFO_13 = 0x426,
	DS9_REG_GXFIFO_14 = 0x428,
	DS9_REG_GXFIFO_15 = 0x42A,
	DS9_REG_GXFIFO_16 = 0x42C,
	DS9_REG_GXFIFO_17 = 0x42E,
	DS9_REG_GXFIFO_18 = 0x430,
	DS9_REG_GXFIFO_19 = 0x432,
	DS9_REG_GXFIFO_1A = 0x434,
	DS9_REG_GXFIFO_1B = 0x436,
	DS9_REG_GXFIFO_1C = 0x438,
	DS9_REG_GXFIFO_1D = 0x43A,
	DS9_REG_GXFIFO_1E = 0x43C,
	DS9_REG_GXFIFO_1F = 0x43E,
	DS9_REG_GXSTAT_LO = 0x600,
	DS9_REG_GXSTAT_HI = 0x602,
	DS9_REG_RAM_COUNT_LO = 0x604,
	DS9_REG_RAM_COUNT_HI = 0x606,
	DS9_REG_DISP_1DOT_DEPTH = 0x610,
	DS9_REG_POS_RESULT_0 = 0x620,
	DS9_REG_POS_RESULT_1 = 0x622,
	DS9_REG_POS_RESULT_2 = 0x624,
	DS9_REG_POS_RESULT_3 = 0x626,
	DS9_REG_POS_RESULT_4 = 0x628,
	DS9_REG_POS_RESULT_5 = 0x62A,
	DS9_REG_POS_RESULT_6 = 0x62C,
	DS9_REG_POS_RESULT_7 = 0x62E,
	DS9_REG_VEC_RESULT_0 = 0x630,
	DS9_REG_VEC_RESULT_1 = 0x632,
	DS9_REG_VEC_RESULT_2 = 0x634,
	DS9_REG_CLIPMTX_RESULT_00 = 0x640,
	DS9_REG_CLIPMTX_RESULT_01 = 0x642,
	DS9_REG_CLIPMTX_RESULT_02 = 0x644,
	DS9_REG_CLIPMTX_RESULT_03 = 0x646,
	DS9_REG_CLIPMTX_RESULT_04 = 0x648,
	DS9_REG_CLIPMTX_RESULT_05 = 0x64A,
	DS9_REG_CLIPMTX_RESULT_06 = 0x64C,
	DS9_REG_CLIPMTX_RESULT_07 = 0x64E,
	DS9_REG_CLIPMTX_RESULT_08 = 0x650,
	DS9_REG_CLIPMTX_RESULT_09 = 0x652,
	DS9_REG_CLIPMTX_RESULT_0A = 0x654,
	DS9_REG_CLIPMTX_RESULT_0B = 0x656,
	DS9_REG_CLIPMTX_RESULT_0C = 0x658,
	DS9_REG_CLIPMTX_RESULT_0D = 0x65A,
	DS9_REG_CLIPMTX_RESULT_0E = 0x65C,
	DS9_REG_CLIPMTX_RESULT_0F = 0x65E,
	DS9_REG_CLIPMTX_RESULT_10 = 0x660,
	DS9_REG_CLIPMTX_RESULT_11 = 0x662,
	DS9_REG_CLIPMTX_RESULT_12 = 0x664,
	DS9_REG_CLIPMTX_RESULT_13 = 0x666,
	DS9_REG_CLIPMTX_RESULT_14 = 0x668,
	DS9_REG_CLIPMTX_RESULT_15 = 0x66A,
	DS9_REG_CLIPMTX_RESULT_16 = 0x66C,
	DS9_REG_CLIPMTX_RESULT_17 = 0x66E,
	DS9_REG_CLIPMTX_RESULT_18 = 0x670,
	DS9_REG_CLIPMTX_RESULT_19 = 0x672,
	DS9_REG_CLIPMTX_RESULT_1A = 0x674,
	DS9_REG_CLIPMTX_RESULT_1B = 0x676,
	DS9_REG_CLIPMTX_RESULT_1C = 0x678,
	DS9_REG_CLIPMTX_RESULT_1D = 0x67A,
	DS9_REG_CLIPMTX_RESULT_1E = 0x67C,
	DS9_REG_CLIPMTX_RESULT_1F = 0x67E,
	DS9_REG_VECMTX_RESULT_00 = 0x680,
	DS9_REG_VECMTX_RESULT_01 = 0x682,
	DS9_REG_VECMTX_RESULT_02 = 0x684,
	DS9_REG_VECMTX_RESULT_03 = 0x686,
	DS9_REG_VECMTX_RESULT_04 = 0x688,
	DS9_REG_VECMTX_RESULT_05 = 0x68A,
	DS9_REG_VECMTX_RESULT_06 = 0x68C,
	DS9_REG_VECMTX_RESULT_07 = 0x68E,
	DS9_REG_VECMTX_RESULT_08 = 0x690,
	DS9_REG_VECMTX_RESULT_09 = 0x692,
	DS9_REG_VECMTX_RESULT_0A = 0x694,
	DS9_REG_VECMTX_RESULT_0B = 0x696,
	DS9_REG_VECMTX_RESULT_0C = 0x698,
	DS9_REG_VECMTX_RESULT_0D = 0x69A,
	DS9_REG_VECMTX_RESULT_0E = 0x69C,
	DS9_REG_VECMTX_RESULT_0F = 0x69E,
	DS9_REG_VECMTX_RESULT_10 = 0x6A0,
	DS9_REG_VECMTX_RESULT_11 = 0x6A2,
	DS9_REG_VECMTX_RESULT_12 = 0x6A4,

	DS9_REG_MAX = 0x106E,

	DS9_REG_POWCNT1 = 0x304,
};

mLOG_DECLARE_CATEGORY(DS_IO);

extern const char* const DS7IORegisterNames[];
extern const char* const DS9IORegisterNames[];

struct DS;
void DS7IOInit(struct DS* ds);
void DS7IOWrite(struct DS* ds, uint32_t address, uint16_t value);
void DS7IOWrite8(struct DS* ds, uint32_t address, uint8_t value);
void DS7IOWrite32(struct DS* ds, uint32_t address, uint32_t value);
uint16_t DS7IORead(struct DS* ds, uint32_t address);
uint32_t DS7IORead32(struct DS* ds, uint32_t address);

void DS9IOInit(struct DS* ds);
void DS9IOWrite(struct DS* ds, uint32_t address, uint16_t value);
void DS9IOWrite8(struct DS* ds, uint32_t address, uint8_t value);
void DS9IOWrite32(struct DS* ds, uint32_t address, uint32_t value);
uint16_t DS9IORead(struct DS* ds, uint32_t address);
uint32_t DS9IORead32(struct DS* ds, uint32_t address);

CXX_GUARD_END

#endif
