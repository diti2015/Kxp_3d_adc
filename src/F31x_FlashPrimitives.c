 /*
 * Copyright (C) 2006 LIQING CO.,LTD
 *
 * file name: F31x_FlashPrimitives.c
 * target mcu: silabs c8051f314
 * target os: none
 * build tools: keil 3 v3.23
 *
 * Created by Cruise.Dai
 * Description: 八字管显示的两点存储式，数据接收显示单元
 *
 * Modify 					Date            Version
 *	
*/ 

#include <c8051f350.h>
#include "F31x_FlashPrimitives.h"
#include "3d_adc_stucts.h"

# define FADDR  0x1D00

static union {
	unsigned char  c[2];              
 	signed   int   s; 
 	unsigned int   i; 
} res;

void FLASH_IntWrite (unsigned int addr, int EDAT)
{
   bit EA_SAVE = EA;                   // preserve EA
   char xdata * data pwrite;           // FLASH write pointer

   EA = 0;                             // disable interrupts  
   // change clock speed to slow, then restore later
   VDM0CN = 0x80;                      // enable VDD monitor
   RSTSRC = 0x02;                      // enable VDD monitor as a reset source
   
   res.i = EDAT;
   pwrite = (char xdata *) addr;

   FLKEY  = 0xA5;                      // Key Sequence 1
   FLKEY  = 0xF1;                      // Key Sequence 2
   PSCTL |= 0x01;                      // PSWE = 1


   VDM0CN = 0x80;                      // enable VDD monitor
   RSTSRC = 0x02;                      // enable VDD monitor as a reset source

	*pwrite = res.c[1];                     // write the byte

	FLKEY  = 0xA5;                      // Key Sequence 1
	FLKEY  = 0xF1;                      // Key Sequence 2

	*(pwrite+1) = res.c[0];                     // write the byte

   PSCTL &= ~0x01;                     // PSWE = 0

   EA = EA_SAVE;                       // restore interrupts
}

unsigned int FLASH_IntRead (unsigned int addr)
{
   bit EA_SAVE = EA;                   // preserve EA
   char code * data pread;             // FLASH read pointer
   EA = 0;                             // disable interrupts

   pread = (char code *) addr;

	res.c[1] = *pread; 	
	res.c[0] = *(pread+1); 
   EA = EA_SAVE;                       // restore interrupts

   return res.i;	
}

void FLASH_PageErase (unsigned int addr)
{
   bit EA_SAVE = EA;                   // preserve EA
   char xdata * data pwrite;           // FLASH write pointer

   EA = 0;                          // disable interrupts
   VDM0CN = 0x80;                      // enable VDD monitor


   RSTSRC = 0x02;                   // enable VDD monitor as a reset source

   pwrite = (char xdata *) addr;

   FLKEY  = 0xA5;                   // Key Sequence 1
   FLKEY  = 0xF1;                   // Key Sequence 2
   PSCTL |= 0x03;                   // PSWE = 1; PSEE = 1


   VDM0CN = 0x80;                      // enable VDD monitor


   RSTSRC = 0x02;                   // enable VDD monitor as a reset source
   *pwrite = 0;                     // initiate page erase

   PSCTL &= ~0x03;                  // PSWE = 0; PSEE = 0
   EA = EA_SAVE;                    // restore interrupts
}
	

void cxy_param_write()
{
	FLASH_PageErase(FADDR);

	FLASH_IntWrite(FADDR+2,s13hz);
	FLASH_IntWrite(FADDR+4,ssec);

}

void cxy_param_read()
{
	s13hz = FLASH_IntRead(FADDR+2);
	ssec = FLASH_IntRead(FADDR+4);
}


