 /*
 * Copyright (C) 2006 LIQING CO.,LTD
 *
 * file name: F31x_FlashPrimitives.h
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

#ifndef F31X_FLASHPRIMITIVES_H
#define F31X_FLASHPRIMITIVES_H


void FLASH_PageErase (unsigned int addr);
void FlashWriteInt(unsigned char ADDR,unsigned int EDAT);
unsigned int FlashReadInt(unsigned char ADDR);

void cxy_param_write();
void cxy_param_read();
/*

#define FLASH_PAGESIZE 512
#define FLASH_TEMP 0x01a00L
#define FLASH_LAST 0x01c00L

typedef unsigned int FLADDR;

// FLASH read/write/erase routines
extern void FLASH_ByteWrite (FLADDR addr, char byte);
extern unsigned char FLASH_ByteRead (FLADDR addr);
extern void FLASH_PageErase (FLADDR addr);
*/
#endif