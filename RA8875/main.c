#include <string.h>
#include <math.h>
#include "ht32.h"
#include "ht32_board.h"
#include "sdio_sd.c"
#include "./FatFS/tff.h"
#include "RA8875.h"
#include "Keypad.h"
#include "DisplayDefs.h"
#include "TimerManager.h"

#if 0
u8 rabit[1500] =
{
	0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X01,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X03,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X03,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,
	0XEF,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XC1,
	0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XC0,0X7C,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XC0,0X3E,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XE1,0XC0,0X1F,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XE0,0X07,0X80,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XE0,0X03,0XC0,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0E,0X7F,0XF0,0X01,0XE0,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X0E,0X03,0XF0,0X00,0XE0,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X0E,0X00,0X78,0X00,0X70,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X0E,0X00,0X1E,0X00,0X38,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X07,0X02,0X07,0X00,0X1C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X07,0X07,0XC1,0XC0,0X1E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X07,0X80,0XF8,0X60,0X0F,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,
	0XE3,0X80,0X0E,0X38,0X07,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,
	0XC0,0X03,0X9C,0X03,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XFF,0XC0,
	0X01,0XC6,0X03,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFF,0XE0,0X00,
	0X73,0X01,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0XE0,0X1F,0XE0,0X00,0X39,
	0X81,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XFE,0X00,0X03,0XF0,0X03,0X9C,0XC0,
	0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XF0,0X00,0X00,0XF8,0X01,0XFE,0X60,0X70,
	0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XC0,0X00,0X00,0X3C,0X00,0X7F,0X30,0X78,0X00,
	0X00,0X00,0X00,0X00,0X00,0X7F,0X00,0X00,0X00,0X0E,0X00,0X01,0X98,0X3C,0X00,0X00,
	0X00,0X00,0X00,0X00,0XFE,0X00,0X00,0X00,0X07,0X00,0X00,0X8C,0X3C,0X00,0X00,0X00,
	0X00,0X00,0X01,0XF8,0X00,0X00,0X00,0X01,0XC1,0XC0,0XC6,0X1E,0X00,0X00,0X00,0X00,
	0X00,0X03,0XF0,0X00,0X00,0X00,0X00,0XF0,0XFF,0XC7,0X0E,0X00,0X00,0X00,0X00,0X00,
	0X07,0XE0,0X00,0X00,0X00,0X00,0X3C,0X1F,0XE3,0XCF,0X80,0X00,0X00,0X00,0X00,0X0F,
	0X80,0X00,0X00,0X00,0X00,0X0F,0X80,0X61,0XFF,0XC0,0X00,0X00,0X00,0X00,0X0F,0X00,
	0X00,0X00,0X00,0X00,0X01,0XF0,0X40,0X3F,0XF0,0X00,0X00,0X00,0X00,0X1E,0X00,0X00,
	0X00,0X00,0X00,0X00,0X3C,0X00,0X01,0XFC,0X00,0X00,0X00,0X00,0X3C,0X00,0X00,0X00,
	0X00,0X00,0X00,0X07,0X80,0X00,0X7F,0X00,0X00,0X00,0X00,0X78,0X00,0X00,0X00,0X00,
	0X00,0X00,0X01,0XF8,0X00,0X1F,0X80,0X00,0X00,0X00,0X70,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X3C,0X00,0X07,0XE0,0X00,0X00,0X00,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X01,0XF0,0X00,0X00,0X01,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X78,0X00,0X00,0X03,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X3C,0X00,0X00,0X03,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X40,0X1E,0X00,0X00,0X07,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XF0,
	0X0E,0X00,0X00,0X07,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X02,0XF8,0X0F,
	0X00,0X00,0X0E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XF8,0X07,0X00,
	0X00,0X0E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0X80,0X00,
	0X1E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0X80,0X00,0X1C,
	0X00,0X00,0X00,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X80,0X00,0X1C,0X00,
	0X00,0X00,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X80,0X00,0X1C,0X00,0X00,
	0X00,0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X80,0X00,0X38,0X00,0X00,0X00,
	0X30,0X00,0X00,0X00,0X04,0X40,0X00,0X00,0X03,0X80,0X00,0X38,0X00,0X00,0X00,0X30,
	0X00,0X00,0X00,0X0E,0X40,0X00,0X00,0X03,0X80,0X00,0X38,0X00,0X00,0X00,0X10,0X00,
	0X00,0X00,0X07,0X60,0X00,0X00,0X03,0X80,0X00,0X70,0X00,0X00,0X00,0X18,0X00,0X00,
	0X00,0X03,0X20,0X00,0X00,0X13,0X80,0X00,0X70,0X00,0X00,0X00,0X08,0X00,0X00,0X00,
	0X01,0XB0,0X00,0X00,0X1F,0X00,0X00,0X70,0X00,0X00,0X00,0X08,0X00,0X00,0X00,0X01,
	0X98,0X00,0X00,0X07,0X80,0X00,0XF0,0X00,0X00,0X00,0X0C,0X00,0X00,0X00,0X00,0X8C,
	0X00,0X00,0X8F,0X80,0X00,0XE0,0X00,0X00,0X00,0X0C,0X00,0X00,0X00,0X00,0X86,0X00,
	0X00,0XFF,0X00,0X01,0XE1,0X80,0X00,0X00,0X0C,0X00,0X00,0X00,0X00,0XC3,0X80,0X00,
	0X7E,0X00,0X01,0XC1,0X80,0X00,0X00,0X0C,0X00,0X00,0X00,0X00,0XC1,0XF0,0XFC,0XFC,
	0X00,0X03,0XC1,0X00,0X00,0X00,0X08,0X00,0X00,0X00,0X00,0XC0,0X7F,0XFF,0XF0,0X00,
	0X03,0X83,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,0X40,0X07,0XFF,0XE0,0X00,0X07,
	0X83,0X00,0X00,0X00,0X18,0X00,0X00,0X00,0X00,0X44,0X07,0XE0,0X00,0X00,0X0F,0X03,
	0X00,0X00,0X00,0X30,0X00,0X00,0X00,0X00,0X43,0XFF,0XC0,0X00,0X00,0X0F,0X03,0X80,
	0X00,0X00,0X30,0X00,0X00,0X00,0X00,0XC0,0XFF,0X00,0X00,0X00,0X1F,0X8F,0X98,0X00,
	0X00,0X60,0X00,0X00,0X00,0X00,0XC0,0X1E,0X00,0X00,0X00,0X3F,0XFF,0X98,0X00,0X00,
	0X60,0X00,0X00,0X00,0X00,0X80,0X3E,0X00,0X00,0X00,0X3F,0XFF,0XD8,0X00,0X00,0XC0,
	0X00,0X00,0X00,0X00,0X80,0X7C,0X00,0X00,0X00,0X0F,0XFF,0XF0,0X00,0X01,0X80,0X00,
	0X03,0X00,0X01,0X80,0XF8,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,0X03,0X00,0X00,0X03,
	0X00,0X01,0X07,0XF0,0X00,0X00,0X00,0X00,0X03,0XC0,0X00,0X07,0X00,0X00,0X03,0X00,
	0X03,0XFF,0XF0,0X00,0X00,0X00,0X00,0X03,0XC0,0X00,0X1F,0X00,0X00,0X03,0X00,0X07,
	0XFF,0XF0,0X00,0X00,0X00,0X00,0X07,0X80,0X00,0X3F,0X80,0X00,0X07,0X80,0X0F,0X83,
	0XF8,0X00,0X00,0X00,0X00,0X07,0X80,0X01,0XFF,0XF0,0X00,0X0F,0X80,0X0F,0XE0,0X7C,
	0X00,0X00,0X00,0X00,0X03,0X80,0X0F,0XFF,0XFF,0X00,0XFF,0X80,0X00,0XFC,0X1C,0X00,
	0X00,0X00,0X00,0X03,0XC0,0X03,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X0F,0X0E,0X00,0X00,
	0X00,0X00,0X03,0XE0,0X00,0X1F,0XFF,0XFF,0XFF,0XF8,0X00,0X03,0X8F,0X00,0X00,0X00,
	0X00,0X01,0XFC,0X00,0X01,0XFF,0XFF,0XF0,0XFF,0XC0,0X00,0XC7,0X00,0X00,0X00,0X00,
	0X00,0XFF,0XC0,0X00,0X3F,0X00,0X00,0X3F,0XF8,0X02,0X73,0X00,0X00,0X00,0X00,0X00,
	0X3F,0XFC,0X00,0X0F,0X00,0X00,0X07,0XFE,0X00,0X33,0X00,0X00,0X00,0X00,0X00,0X07,
	0XFF,0X80,0X27,0X80,0X00,0X00,0XFF,0X80,0X5F,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,
	0XF0,0X0B,0X80,0X00,0X00,0X1F,0XE0,0X1F,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFE,
	0X01,0X80,0X00,0X00,0X03,0XF8,0X0F,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XC3,
	0X80,0X00,0X00,0X00,0XFE,0X1E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0XF3,0X80,
	0X00,0X00,0X00,0X3F,0XBE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XFF,0X80,0X00,
	0X00,0X00,0X0F,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0X80,0X00,0X00,
	0X00,0X03,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X3F,0X00,0X00,0X00,0X00,
	0X01,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1E,0X00,0X00,0X00,0X00,0X00,
	0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X20,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
	0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};


#endif

u8				gImage_p16x16_2[512] =
{ /* 0X10,0X10,0X00,0X10,0X00,0X10,0X01,0X1B, */

	0XFF,0XBF,0XFF,0X9F,0XFF,0XFC,0XFF,0XD7,0XFF,0XD1,0XF6,0XE9,0XFF,0X46,0XFE,0XE3,
	0XFF,0X03,0XFF,0X24,0XFF,0X27,0XFF,0XF0,0XFF,0XB5,0XFF,0XBA,0XFF,0XBF,0XFF,0X9F,
	0XFF,0XBF,0XFF,0XFD,0XFF,0X56,0XF7,0X30,0XFF,0X4D,0XFF,0X29,0XF6,0XC6,0XFF,0X89,
	0XFF,0X26,0XF7,0X05,0XE6,0XA4,0XF7,0X29,0XF7,0X2E,0XFF,0XF7,0XFF,0XFD,0XFF,0XBF,
	0XFF,0XF9,0XFF,0XF6,0XEF,0X2C,0XEF,0X28,0XF7,0X67,0XFF,0X68,0XFF,0X0C,0XFF,0X6F,
	0XFF,0X4D,0XFF,0X4B,0XF7,0X45,0XEF,0X44,0XDE,0XC4,0XF7,0X8C,0XF7,0X73,0XFF,0XD9,
	0XFF,0XF4,0XE6,0XCC,0XFF,0X89,0XF7,0X66,0XFF,0XA8,0XFF,0X6B,0XFF,0XF4,0XFF,0X74,
	0XFF,0X73,0XFF,0X6F,0XF7,0X68,0XF7,0XA5,0XE7,0X22,0XE7,0X26,0XEE,0XEB,0XFF,0XF4,
	0XFF,0XEF,0XDE,0X67,0XF7,0X48,0XEF,0X08,0XFF,0X8D,0XFF,0XB1,0XFF,0X76,0XFF,0XDA,
	0XFF,0X98,0XFF,0XF6,0XF7,0X6D,0XF7,0X48,0XEF,0X25,0XF7,0X26,0XE6,0XA6,0XFF,0XEC,
	0XEE,0XA6,0XFF,0X07,0XEE,0XC6,0XF7,0X29,0XFF,0X8F,0XFF,0XB3,0X83,0X47,0XEE,0XD7,
	0X9C,0X4C,0XFF,0XB6,0XFF,0XD0,0XF7,0X49,0XF7,0X26,0XF7,0X04,0XDE,0X42,0XDE,0X22,
	0XE5,0XE2,0XFF,0X06,0XFE,0XE6,0XFF,0X28,0XFF,0X8D,0XFF,0X91,0X30,0XE0,0XE6,0X73,
	0X28,0XA0,0XE6,0X8F,0XFF,0X6D,0XFF,0X68,0XFF,0X45,0XFF,0X03,0XF6,0XC3,0XE6,0X00,
	0XFE,0X64,0XEE,0X22,0XFF,0X26,0XFE,0XE6,0XFF,0X2A,0XFF,0X6F,0X51,0XC0,0XFF,0XD6,
	0X41,0X80,0XF7,0X0F,0XF7,0X09,0XFF,0X26,0XFF,0X64,0XF6,0XA1,0XF6,0X61,0XDD,0XA0,
	0XF6,0X03,0XF6,0X23,0XFF,0X26,0XFE,0XC5,0XFF,0X28,0XFF,0X8D,0XFF,0X2E,0XFF,0X51,
	0XFF,0X70,0XFF,0X0C,0XFF,0X48,0XFF,0X04,0XFF,0X02,0XFE,0XE2,0XED,0XE0,0XED,0XE0,
	0XED,0XC3,0XEE,0X03,0XFE,0X84,0XFE,0XA4,0X7A,0XC0,0XDD,0XC4,0XE5,0XE8,0XFF,0X2E,
	0XFF,0X0D,0XF6,0X88,0X72,0XA0,0XEE,0X61,0XFF,0X23,0XFE,0XC2,0XF6,0X63,0XE5,0X81,
	0XD5,0X42,0XEE,0X25,0XFE,0XC5,0XF6,0X84,0XD5,0X60,0X7A,0X80,0X9B,0X60,0X93,0X40,
	0X9B,0X60,0X82,0XC0,0XEE,0X42,0XFF,0X65,0XFE,0XC2,0XE6,0X21,0XDD,0XC2,0XCD,0X01,
	0XFF,0XF0,0XC5,0X22,0XDE,0X02,0XEE,0X82,0XFF,0X25,0XFE,0XC5,0XA3,0X60,0XFE,0X49,
	0X92,0XE0,0XFE,0XE8,0XFE,0XC3,0XFF,0X02,0XF6,0XA1,0XE6,0X42,0XD5,0XC5,0XFF,0XF1,
	0XFF,0XF4,0XAC,0XE4,0XDE,0X63,0XE6,0X80,0XFF,0X21,0XFE,0XE3,0XAB,0XA0,0X9B,0X00,
	0XB3,0XA0,0XFE,0XC6,0XF6,0X80,0XFE,0XE0,0XEE,0XC0,0XD6,0X02,0XBD,0X47,0XFF,0XD5,
	0XFF,0XB8,0XFF,0XF6,0XBD,0X84,0XCD,0XC1,0XD5,0XA0,0XF6,0X41,0XFE,0X45,0XC4,0X20,
	0XFE,0X26,0XFE,0X85,0XFE,0X81,0XF6,0XA1,0XC5,0X80,0XB5,0X44,0XFF,0XF7,0XFF,0XFB,
	0XFF,0XDD,0XFF,0XFC,0XFF,0XF7,0XAC,0XE6,0XFF,0X0B,0XE5,0X83,0XFE,0X05,0XFD,0XC4,
	0XFE,0X04,0XF5,0XE3,0XDD,0X82,0XD5,0X84,0XC5,0X89,0XFF,0XF8,0XE6,0XFA,0XFF,0XFF,
	0XFF,0XFF,0XFF,0XFE,0XFF,0X99,0XFF,0XF7,0XFF,0X71,0XDD,0X65,0XE5,0X22,0XF5,0X82,
	0XE5,0X40,0XED,0X82,0XD5,0X23,0XFF,0XB1,0XFF,0XF7,0XFF,0X7A,0XFF,0XFF,0XFF,0XDF,
};


u8				tick = 0;
bool			click = FALSE;
u32 			uSpeedCount;

/* Global variables ----------------------------------------------------------------------------------------*/
FATFS			fs; /* File system object																	*/
FIL 			fsrc; /* File object																		*/
DIR 			dir; /* Directory object																	*/
FILINFO 		fno; /* File info object																	*/
UINT			dcnt = 0;
FRESULT 		result = FR_NOT_READY;
u8				SD_ReadBuf[51200]; //2017/09/25

void EX1( void );
void BTE_Ex3( void );
void BTE_Ex1( void );
void BTE_SMILE( void );
void BTE_Example2( void );

const unsigned char bw[2048] =
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x3c,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x0c,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0xe0,0x7a,0x00,0x00,0x3e,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xfe,0x00,
	0x00,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x01,0xa8,0xce,0x00,0x00,0x56,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xf9,
	0xde,0x00,0x00,0xde,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0xdd,0xda,0x00,0x00,0xee,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,
	0x01,0xdd,0x5c,0x00,0x00,0x7a,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3c,0x00,0x00,0x01,0x9d,0xfc,0x00,
	0x00,0xcc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3e,
	0x00,0x10,0x01,0xf7,0xb8,0x01,0xc1,0xbc,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x7b,0x00,0x18,0x01,0xef,
	0xd0,0x01,0x50,0xb8,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x77,0x00,0x38,0x00,0xbc,0x60,0x01,0xf8,0x90,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x80,0x38,
	0x38,0xcc,0xcf,0xe1,0xbc,0xe0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x76,0x81,0xf8,0x2e,0x64,0x3b,0xe0,
	0xdc,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x75,
	0x87,0xef,0x3b,0x2d,0x7e,0xc1,0xd4,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x7b,0x83,0xef,0xb3,0x98,
	0xb3,0x40,0xe6,0x80,0x00,0x07,0x80,0x00,0x00,0x00,
	0x00,0x6f,0x80,0x3f,0x3b,0x8b,0xbf,0x80,0xfe,0x80,
	0x00,0x18,0x20,0x00,0x00,0x00,0x00,0x3f,0x00,0x30,
	0x2b,0x47,0xcf,0x80,0x56,0x80,0x00,0x23,0x10,0x00,
	0x00,0x00,0x00,0x39,0x00,0x70,0x3d,0xc7,0x7f,0x00,
	0x3e,0x80,0x00,0x4f,0xc8,0x00,0x00,0x00,0x1f,0xdb,
	0x0e,0x32,0x1e,0xe6,0x7c,0x00,0x1a,0x03,0xc0,0x58,
	0x24,0x00,0x00,0x00,0x3f,0xea,0x1e,0x21,0x1e,0xeb,
	0xf0,0x40,0x07,0x07,0xfc,0xd7,0xb4,0x00,0x00,0x00,
	0xd7,0xf8,0x3e,0x01,0x0d,0xa8,0x00,0x40,0x01,0x0f,
	0xfc,0x96,0x94,0x00,0x00,0x00,0x7f,0xb8,0x76,0x01,
	0x07,0x38,0x78,0x40,0x01,0x0f,0xfe,0x92,0x94,0x00,
	0x00,0x00,0x17,0xe0,0xee,0x01,0x03,0xf1,0xf8,0x43,
	0xf2,0x0f,0xfe,0x4d,0x28,0x00,0x00,0x00,0x03,0x00,
	0xfe,0x00,0x80,0xf3,0xe0,0x4f,0xa6,0x0f,0xfc,0x60,
	0x28,0x00,0x00,0x00,0x00,0x02,0xcc,0x00,0x80,0x13,
	0xf0,0x5f,0x24,0x67,0xfc,0x30,0xd0,0x00,0x00,0x00,
	0x00,0x02,0xb8,0x3d,0x00,0x2b,0xf0,0x5d,0xec,0x07,
	0xfc,0x1f,0xe0,0x80,0x00,0x00,0x00,0x02,0xf8,0xfd,
	0x00,0x2b,0xe0,0xfb,0xc8,0x03,0xf8,0x00,0x0f,0x80,
	0x00,0x00,0x3f,0xc2,0x61,0xf9,0x00,0x2b,0xc0,0xe7,
	0x98,0x07,0xff,0x00,0x2f,0x80,0x00,0x00,0x7e,0xf3,
	0x83,0xf9,0x00,0x3f,0x80,0xbf,0x34,0x01,0xff,0x80,
	0x7f,0x80,0x00,0x01,0x87,0xe9,0x05,0xfb,0x00,0x3f,
	0x01,0xfc,0xea,0x00,0x7f,0x80,0xf8,0x00,0x00,0x00,
	0x7d,0x1d,0x05,0xf2,0x04,0x30,0x03,0x01,0xde,0x00,
	0x1e,0x01,0xff,0x00,0x03,0x00,0x37,0xbc,0x85,0xf2,
	0x0e,0x60,0x03,0x07,0xbb,0x0c,0x00,0x03,0xef,0x00,
	0x0f,0x00,0x1f,0xf0,0x8f,0xc2,0x1a,0x68,0x06,0x1e,
	0x2f,0x4c,0x80,0x03,0xfe,0x00,0x1f,0xc0,0x03,0x80,
	0x4b,0x82,0x1b,0x6c,0x0c,0x3c,0x77,0x6d,0x81,0x83,
	0x8e,0x00,0x0f,0xff,0xf1,0xfe,0x6c,0x06,0x3b,0x7e,
	0x18,0xf0,0x74,0x3f,0x03,0xc3,0xfc,0x00,0x01,0xff,
	0xf3,0x83,0x30,0x06,0x2b,0xfb,0x19,0xe0,0x56,0x1a,
	0x06,0xc6,0xf8,0x00,0x01,0xfc,0x64,0x00,0xd8,0x06,
	0x3b,0xff,0x37,0x98,0x6f,0xf7,0xee,0x45,0xe0,0x00,
	0x07,0xfc,0x18,0xfc,0x66,0x06,0x3e,0xf9,0x6f,0x3c,
	0x6c,0xd7,0x1b,0xc7,0x00,0x00,0x0f,0xe6,0x19,0xc6,
	0x23,0x06,0x3d,0xf3,0x7c,0x3e,0x29,0x3f,0x1d,0xc0,
	0x7d,0x80,0x3f,0xc0,0x33,0x01,0x11,0xc2,0x3b,0x6b,
	0xf8,0x36,0x3c,0x6d,0x8f,0xc9,0xbb,0xe0,0x7f,0x00,
	0x22,0x71,0x90,0x63,0x27,0x64,0xf0,0x36,0x08,0x4c,
	0xaa,0x83,0x77,0xb0,0xf0,0x00,0x26,0xc8,0x90,0x1b,
	0x37,0x63,0xe0,0x35,0x10,0x0c,0x1f,0x97,0xc2,0xe0,
	0x00,0x00,0x26,0xe4,0x90,0x0f,0xb2,0x61,0xe0,0x3b,
	0x23,0xf0,0x17,0x2f,0xdf,0xc0,0x00,0x00,0x26,0x6c,
	0x90,0x03,0xd4,0x61,0xc0,0x3f,0x4f,0xe0,0x17,0x6e,
	0xff,0x80,0x00,0x00,0x33,0x0a,0x90,0x01,0xec,0x21,
	0xc0,0x36,0xdf,0x60,0x1c,0xc3,0xfe,0x00,0x00,0x00,
	0x31,0xf9,0xa0,0x00,0xf8,0x23,0xb0,0x1c,0xbe,0x20,
	0x19,0x80,0x30,0x00,0x00,0x00,0x18,0x43,0xa4,0x00,
	0x38,0x33,0xbc,0x0b,0xfb,0xc0,0x0e,0x00,0x00,0x00,
	0x00,0x00,0x1c,0x03,0xc4,0x00,0x1c,0x33,0xaf,0x05,
	0x57,0xc0,0x3c,0x00,0x00,0x00,0x00,0x00,0x07,0x1c,
	0xc2,0x00,0x06,0x33,0x37,0x83,0xcc,0x87,0xe0,0x00,
	0x3f,0x00,0x00,0x00,0x03,0xff,0x62,0x0f,0xf3,0x13,
	0xbb,0xc2,0xbf,0x7d,0xe0,0x00,0x40,0xc0,0x00,0x00,
	0x00,0x7c,0x22,0x37,0xfd,0x9b,0xbb,0xc2,0x1f,0xef,
	0xdc,0x00,0x8e,0x60,0x00,0x00,0x06,0x00,0x31,0x6b,
	0xfa,0xdb,0x8f,0xa3,0xe7,0x98,0xff,0x01,0x31,0xa0,
	0x00,0x00,0x06,0x00,0x11,0xfc,0x1f,0x7b,0xb1,0xe6,
	0x0e,0x0f,0x7b,0x81,0x20,0x80,0x00,0x00,0x36,0x60,
	0x10,0x9d,0xf7,0xbf,0xbf,0x76,0x18,0x05,0xa7,0xc3,
	0x5a,0x50,0x00,0x00,0x3a,0xc0,0x10,0x4b,0xde,0x3f,
	0xde,0xf6,0x3b,0xc3,0xfd,0xc2,0x56,0x50,0x00,0x00,
	0x1b,0x80,0x10,0x23,0xb8,0x1f,0xdf,0xf6,0x67,0xe1,
	0xdd,0xe3,0x6a,0x50,0x00,0x00,0xf4,0xf0,0x18,0x18,
	0x00,0x0f,0xcd,0x74,0xe7,0x18,0x7f,0xc1,0x3c,0x80,
	0x00,0x00,0xfb,0xf8,0x18,0x4c,0x00,0x07,0xc7,0x14,
	0xc7,0x00,0x0e,0x01,0x91,0xa0,0x00,0x00,0x0f,0x80,
	0x08,0x63,0x80,0x07,0xe3,0xd5,0xc3,0x80,0x01,0xbc,
	0xf3,0x40,0x00,0x00,0x1a,0xc0,0x88,0xf0,0xe0,0x07,
	0xe1,0xd5,0x83,0xc0,0x03,0xf4,0x3f,0x80,0x00,0x00,
	0x36,0xe1,0xc8,0xf8,0x3c,0x03,0xf0,0x75,0x87,0xe0,
	0x07,0x5c,0x40,0x00,0x00,0x00,0x26,0x63,0x69,0xd8,
	0x07,0x81,0xf0,0x07,0x0f,0xf0,0x0b,0x78,0xc0,0x00,
	0x00,0x00,0x06,0x01,0x69,0xdc,0x01,0xc1,0xf8,0x07,
	0x1f,0xf0,0x1f,0xf9,0x9f,0xc0,0x00,0x00,0x00,0x82,
	0x6d,0xd4,0x1f,0x31,0xf8,0x0f,0x1f,0xf0,0x1b,0x33,
	0xfd,0xf0,0x00,0x00,0x00,0x87,0xed,0xdc,0x7d,0xcc,
	0xfc,0x0f,0x1f,0xf0,0x2f,0xee,0x47,0xf8,0x00,0x03,
	0xfc,0x47,0xa6,0x7d,0xdf,0xf6,0xfc,0x0e,0x0f,0xe0,
	0x3f,0xb8,0x2c,0xbc,0x00,0x07,0xef,0x45,0x66,0xbd,
	0x0e,0xfb,0xfe,0x0e,0x00,0x40,0x07,0xe0,0x3f,0x9e,
	0x00,0x18,0x76,0xa3,0xe6,0x50,0xfb,0x0d,0xff,0x0e,
	0x02,0x47,0xfe,0x00,0x0e,0xeb,0x00,0x07,0xd9,0xd3,
	0xc3,0x68,0x6f,0xf8,0xff,0x0e,0x01,0xfe,0x00,0x70,
	0x07,0xf7,0x00,0x03,0x7b,0xdb,0xc3,0xa8,0x1e,0xf0,
	0x7f,0x1c,0x0f,0xc0,0x00,0x7a,0x01,0xfc,0x00,0x01,
	0xf7,0x0c,0x81,0xd0,0x02,0x0e,0x7f,0x9c,0x38,0x00,
	0x00,0x7c,0x00,0x00,0x00,0x00,0x38,0x06,0x00,0xe0,
	0x00,0x0b,0x3f,0x9c,0xf0,0x00,0x00,0x7e,0x00,0x00,
	0x00,0x00,0x00,0x03,0x80,0x70,0x00,0x0f,0xbf,0xd9,
	0xc7,0xc0,0x00,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,
	0xe0,0x3c,0x00,0x1d,0xff,0xdb,0x9f,0xc0,0x00,0x3f,
	0xe0,0x00,0x00,0x00,0x00,0x00,0x3c,0x1f,0x00,0x05,
	0xdf,0xfe,0x6f,0x80,0x00,0x3f,0xf0,0x00,0x00,0x00,
	0x00,0x00,0x07,0xe7,0xc0,0x0d,0x5f,0xfc,0xef,0x80,
	0x00,0xff,0xf0,0x00,0x00,0x00,0x00,0x03,0xfe,0xff,
	0xf8,0x0f,0x7f,0xf9,0xf8,0x80,0x00,0xef,0xe0,0x00,
	0x00,0x00,0x00,0x0f,0xf7,0x83,0xfe,0x0e,0xff,0xf9,
	0xf7,0x80,0x00,0x1c,0x00,0x00,0x00,0x00,0x00,0x1e,
	0xf9,0x00,0x7f,0x85,0xff,0xf2,0xef,0x00,0x00,0x1c,
	0x00,0x00,0x00,0x00,0x00,0x7f,0x86,0x00,0x07,0xf6,
	0xbf,0xe2,0xdf,0x00,0x00,0x18,0x00,0x00,0x00,0x00,
	0x00,0x5f,0x6e,0x00,0x00,0xfb,0x5f,0xe6,0x82,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf2,0xfc,0x00,
	0x00,0x3f,0xdf,0xe6,0x7c,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x01,0xbd,0xd8,0x00,0x00,0x0f,0x5f,0xe7,
	0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xff,
	0xe0,0x00,0x00,0x07,0x9f,0xe4,0x70,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x7f,0x80,0x00,0x00,0x01,
	0xdf,0xe7,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xe6,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xe0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x3f,0xe0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x3f,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xe0,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x1f,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xe0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x3f,0xe0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x3f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xc0,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x3f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3f,0xc0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x3f,0xc0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x7f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xc0,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x7f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0xc0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x7f,0xc0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x7f,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xc0,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xc0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xff,0xc0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xc0,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x01,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xc0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x01,0xff,0xc0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
	0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xc0,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x03,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xff,0xe0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x03,0xff,0xe0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,
	0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x07,0xff,0xe0,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x07,0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0xe0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0f,0xff,0xe0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,
	0xff,0xe0,0x00,0x00,0x00,0x00,0x00,0x00,
};


u8 mBuff2[256] = "test";

// Define a keyboard layout as a calculator-like keypad
// 789 /(
// 456 *)
// 123 -
// 00. +=
const char numberkeys[] =
{
    5,0x01, 10,'7',10,'8',10,'9', 5,0x01, 10,'/',10,'(', 0,0,
    5,0x01, 10,'4',10,'5',10,'6', 5,0x01, 10,'*',10,')', 0,0,
    5,0x01, 10,'1',10,'2',10,'3', 5,0x01, 10,'-',10,KYBD_SYM_BS, 0,0,
    5,0x01, 20,'0',       10,'.', 5,0x01, 10,'+',10,'=', 0,0,
    0,0
};

// Define the implementation of that keyboard
const keyboard_t altkeyboard =
{
    100,        // x=100; left edge
    0,          // y=0; computed from bottom up
    240,        // width=240
    0,          // height=0; bottom of screen justified
    4,          // rows
    6,          // columns
    numberkeys, // pointer to the keypad
    numberkeys
};


_KEYPAD *kp;
_RA8875 *lcd;


void CalibrateTS(void)
{
    FIL *fh;
    tpMatrix_t matrix;
    RetCode_t r;

    // r = lcd->TouchPanelCalibrate( "\r\nCalibrate the touch panel", &matrix, 15 );

    lcd->printf( "TouchPanelCalibrate returned error code %d\r\n" );

    lcd->printf( "TouchPanelCalibrate returned error code %d\r\n", r );

    if ( r == noerror )
    {
    	/*
        fh = fopen("/local/tpcal.cfg", "wb");

        if ( fh )
        {
            fwrite(&matrix, sizeof(tpMatrix_t), 1, fh);
            fclose(fh);
        }
        else
        {
            lcd.printf( "Cannot save calibration in /local/tpcal.cfg\r\n" );
            wait_ms(1000);
        }
        */
    }
    else
    {
        lcd->printf( "TouchPanelCalibrate returned error code %d\r\n", r );

       	wait_ms( 2000 );
    }

}

void FloatingSmallQWERTYTest( loc_t x, loc_t y, dim_t w, dim_t h )
{
    keyboard_t tiny;

    char name1[ 10 ];

    kp->SetKeyboard( NULL, KYBD_SYM_ENTER, KYBD_SYM_ESCAPE );

    memcpy( &tiny, kp->GetKeyboard( ), sizeof( keyboard_t ) );

	tiny.x = x;
	tiny.y = y;
    tiny.width = w;
    tiny.height=h;

    printf( "\r\nFloatingSmallQWERTYTest" );

    // copy definition and then resize it
    // select the internal keyboard
    // now select this tiny keyboard
    kp->SetKeyboard( &tiny, KYBD_SYM_ENTER, KYBD_SYM_ESCAPE );

    kp->SetKeyboardFont( 0, 3 );

    if ( kp->GetString( name1, sizeof( name1 ), "Cprs:", FALSE, 0, FALSE ) )
    {
    	/*
        LCD.foreground(BrightRed);
        lcd.background(Black);
        lcd.cls();
        lcd.SetTextCursor(0,40);
        lcd.printf("Compressed: %s\r\n", name1);
        */
    }
}

void CalculatorKeypadTest(void)
{
    char name1[20];

    kp->SetKeyboard( &altkeyboard, '=', 0 );
    kp->SetKeyboardFont( 0, 4 );

    if( kp->GetString( name1, sizeof( name1 ), "Calc:", FALSE, 0, FALSE ) )
    {
    	/*
        lcd.foreground(BrightRed);
        lcd.background(Black);
        lcd.cls();
        lcd.SetTextCursor(0,40);

        lcd.printf( "Calculator: %s\r\n", name1 );
        */
    }
}


int main( void )
{
	// int i = 0;
	u8				tStr[] = "";
	u8				tStr2[9] = "";
	u16 			temp;
	u8				lsd,msd;
	int 			second;

	RETARGET_Configuration( );						//Retarget Related configuration
	printf( "\r\n========== Initial ==========" );

	HT32F_DVB_LEDInit( HT_LED1 );
	LCD_Init( );
	LCD_Config( );
	I2C_EEPROM_Init( );

	NVIC_EnableIRQ( SDIO_IRQn );
	NVIC_EnableIRQ( PDMACH6_IRQn ); 				// SDIO_RX
	NVIC_EnableIRQ( PDMACH7_IRQn ); 				// SDIO_TX
	f_mount( 0,&fs );

	/* SYSTICK configuration */
  	SYSTICK_ClockSourceConfig( SYSTICK_SRC_STCLK );       // Default : CK_SYS/8
  	SYSTICK_SetReloadValue( SystemCoreClock / 8 / 1000 ); // (CK_SYS/8/1000) = 1ms on chip
  	SYSTICK_IntConfig( ENABLE );                          // Enable SYSTICK Interrupt

	// Active_Window( 0, 16, 0, 16 );

	Write_Dir( 0x8E, 0x80 ); 						//Clean
	Chk_Busy();

	CmdWrite( 0x02 );
	openBMP3( "bg.dat" );

	Chk_Busy();

	kp = Keypad_CreateObj( Blue, White );

	lcd = RA8875_CreateObj( );

	CalibrateTS( );

	// FloatingSmallQWERTYTest( 50, 0, 200, 0 );
	FloatingSmallQWERTYTest( 75, 100, 0, 0 );

	// CalculatorKeypadTest( );
	// ---------------------------------------

	// DrawPictureFromSD( "file1.dat", SD_ReadBuf, 100, 0 );

    // DrawPictureFromSD( "meter.dat", SD_ReadBuf, 150, 100 );

    // DrawPictureFromSD( "test.dat", SD_ReadBuf, 500, 100 );

    // DrawPictureFromSD( "file1.dat", SD_ReadBuf, 200, 100 );

	/*
	DrawString(10,20,tStr2,0,0,FALSE,FALSE,Green,Red);
	DrawString(10,40,tStr2,1,1,FALSE,FALSE,Green,Red);
	DrawString(10,80,tStr2,2,2,FALSE,FALSE,Green,Red);

	DrawString(180,20,tStr2,0,0,FALSE,FALSE,Red,Black);
	DrawString(180,40,tStr2,1,1,FALSE,FALSE,Red,Black);
	DrawString(180,80,tStr2,2,2,FALSE,FALSE,Red,Black);

	DrawString(350,20,tStr2,0,3,FALSE,TRUE,Red,White);
	DrawString(350,40,tStr2,1,3,FALSE,TRUE,Red,White);
	DrawString(350,80,tStr2,2,3,FALSE,TRUE,Red,White);

	DrawRect(350,200,450,300,Red,Blue,TRUE);
	DrawRect(650,200,750,300,Red,Green,FALSE);
	DrawLine(50,250,50,250,Red,Yellow);
	DrawLine(250,450,250,50,Red,Green);
	DrawTri(400,500,600,400,450,400,Red,Purple,TRUE);
	DrawTri(100,200,300,400,450,400,Red,Purple,FALSE);
	DrawEllipse(50,300,30,50,White,Red,FALSE);
	DrawEllipse(150,300,30,50,White,Red,TRUE);

	DrawCircle(550,240,60,White,Red,TRUE);
	DrawCircle(400,240,60,White,Green,FALSE);

	DrawRoundRect(450,500,50,100,0,0,15,15,White,Red,FALSE);
	DrawRoundRect(450,500,120,170,0,0,10,10,White,Red,TRUE);

	DrawCurve(600,60,30,30,1,White,Yellow,FALSE);
	DrawCurve(680,60,30,15,1,White,Red,TRUE);

	DrawCurve(680,60,30,15,1,White,White,TRUE);
	DrawCurve(680,60,30,15,2,White,Blue,TRUE);
	DrawCurve(680,60,30,15,3,White,Yellow,TRUE);
	DrawCurve(680,60,30,15,4,White,Green,TRUE);
	Chk_Busy();

		//Write_Dir(0x10,0x0F);//16Bit

		Write_Dir(0x10,0x0c);//8Bit
		//Chk_Busy();

		//Write_Dir(0x10,0x0F);//16Bit
		Foreground_Color(Red);
		Background_color(Green);
		BTE_Source_Destination(0,250,0,250);
		BTE_Size_setting(120,100);
		BTE_ROP_Code(0x79);	//	set BTE color expansion with transparency
		//BTE_ROP_Code(0xF9);
		BTE_enable();
		CmdWrite(0x02);//MRWC

		//for(i=0;i<750;i++){
		//	temp = rabit[i*2];
		//	temp<<=8;
		//	temp&=0xff00;
		//	temp= temp | rabit[i*2+1];
		//	DataWrite(temp);
		//	Chk_Busy();
		//}
		for(i=0;i<1500;i++){
			DataWrite(rabit[i]);
			Chk_Busy();
		}
		//Chk_Busy();

		Chk_Busy_BTE();

		Write_Dir(0x10,0x0F);//16Bit
		Foreground_Color(Yellow);
		Background_color(Purple);
		BTE_Source_Destination(0,650,0,350);
		BTE_Size_setting(128,128);
		BTE_ROP_Code(0xF9); // set BTE color expansion
		BTE_enable();
		CmdWrite(0x02);//MRWC

	for(i=0;i<1024;i++){
		temp = bw[i*2];
		temp<<=8;
		temp&=0xff00;
		temp= temp | bw[i*2+1];
		DataWrite(temp);
		Chk_Busy();
	}
	*/
	//Write_Dir(0x10,0x0F);//16Bit
	//while(1){
	//Scroll(10,80,10,80);
	//}

	/*
	CmdWrite(0x02);
	Chk_Busy();
	 */

	//Write_Dir(0x8E,0x80);//Clean
	//CmdWrite(0x02);//MRWC
	printf( "\r\n=====Start=====\r\n" );

	//KeyBoard_Int();
	///*

	while ( 1 )
	{
		//I2C_EEPROM_BufferWrite(mBuff2,0,32);
		HT32F_DVB_LEDToggle( HT_LED1 );

		// I2C_BufferRead( mBuff2,0x68,0,8 );			//0x50

		//I2C_EEPROM_BufferRead(mBuff2,0, 8);
		//for(i=0;i<8;i++){
		//		printf("[0x%x],",mBuff2[i]);
		//}
		lsd 				= ( mBuff2[2] &0x0f );
		msd 				= ( mBuff2[2] &0x70 ) >> 4;
		tStr2[1]			= lsd + '0';
		tStr2[0]			= msd + '0';

		tStr2[2]			= ':';
		lsd 				= ( mBuff2[1] &0x0f );
		msd 				= ( mBuff2[1] &0x70 ) >> 4;
		tStr2[4]			= lsd + '0';
		tStr2[3]			= msd + '0';
		lsd 				= ( mBuff2[0] &0x0f );
		msd 				= ( mBuff2[0] &0x70 ) >> 4;
		tStr2[5]			= ':';
		tStr2[7]			= lsd + '0';
		tStr2[6]			= msd + '0';
		tStr2[8]			= '\0';

		//printf("\r\n%s\r\n",tStr2);

		/*
		for(i=0;i<8;i++){
			if( i%8==7)
				printf("[0x%x]\r\n",mBuff2[i]);
			else
				printf("[0x%x],",mBuff2[i]);
		}
		*/
		//tStr2[0] = 0x31;
		//tStr2[1] = 0x32;
		//tStr2[2] = 0x33;
		// Chk_Busy();

		// DrawString( 300,200,tStr2,3,3,FALSE,FALSE,White,Red );

		//DrawString(10,300,mBuff2[i],0,0,FALSE,FALSE,Green,Purple);
		//DrawString(10,20,tStr2,0,0,FALSE,FALSE,Green,Red);
		printf( "\r\n=====End=====" );

		///*
		wait_ms( 200 );

		//*/
	}
	//*/
}


void openBMP3( const char * filename )
{
	UINT			t	= 0,j = 0;
	UINT			dcnt = 0;

	result	= f_open( &fsrc,( const char * ) filename,FA_OPEN_EXISTING | FA_READ );

	if ( result == FR_OK )
	{
		//printf("[Read File OK]\r\n");
	}
	else
	{
		printf( "[Read File Failed]\r\n" );
	}

	for ( t = 0; t < 15; t++ )
	{
		result				= f_read( &fsrc,SD_ReadBuf,51200,&dcnt );

		for ( j = 0; j < 25600; j++ )
		{
			EBI_LCD->EBI_LCD_RAM = SD_ReadBuf[j * 2 + 0] << 8 | SD_ReadBuf[j * 2 + 1];
		}
	}

	f_close( &fsrc );
}


u16 ToColor( u8 data1,u8 data2 )
{
	return data1 << 8 | data2;
}


void BTE_Example2( void )
{
	int 			i	= 0;

	Pattern_Set_16x16();
	Write_To_Pattern();
	Pattern_Set_number( 0 );
	Graphic_Mode();
	CmdWrite( 0x02 );

	for ( i = 0; i < 256; i++ )
	{
		DataWrite( ToColor( gImage_p16x16_2[i * 2 + 0],gImage_p16x16_2[i * 2 + 1] ) );
		Chk_Busy();
	}

	Chk_Busy();
	Write_To_Bank1and2();
	Write_To_Bank1();
	BTE_Source_Destination( 0,0,0,20 );
	Source_Layer1();
	Destination_Layer1();
	BTE_Size_setting( 800,16 );
	BTE_ROP_Code( 0xc6 );
	BTE_enable();
	Chk_Busy_BTE();

}


