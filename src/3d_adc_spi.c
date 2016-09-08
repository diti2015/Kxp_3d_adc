/*
 * Copyright (C) 2006 LIQING CO.,LTD
*/

#include <c8051f350.h>
#include <math.h>
#include "3d_adc_stucts.h"
#include "3d_adc_spi.h"

sbit  CSB = P0^3;

void spi0(void) interrupt 6
{
	unsigned char tmpspi;
	if(SPIF)
	{
		if(spistate == 0)
		{			
			SPI0DAT = 0x00;		//get high 8 bit 
			spistate = 1;
		}				 
		else if(spistate == 1)
		{
			spidata = SPI0DAT; 
			if(rdaflag == 0)
			{
				CSB =1;
				spistate = 0;
				angleflag = 1 ;	
			}
			else
			{
				SPI0DAT = 0x00;		//get low 8 bit
				spistate = 2;
			}
		}				
		else 
		{
			tmpspi = SPI0DAT;
			spidata = spidata << 8;
			spidata += tmpspi;
			spidata = spidata >> 5;
			CSB =1;
			spistate = 0;
			angleflag = 1 ;
		}
		SPIF = 0;
	}
}

void rdat(void)
{
	CSB = 0;
	SPI0DAT = 0x08;	
}

void rdax(void)
{
	CSB = 0;
	SPI0DAT = 0x10;	
}

void rday(void)
{
	CSB = 0;
	SPI0DAT = 0x11;	
}

void getrda(void)
{
	unsigned char i;
	if(angleflag == 1)
	{
		angleflag = 0;
		
		for(i=0;i<30;i++) i = i;
		if(rdaflag == 0) 
		{
			rdatdata += spidata;
			rday();
			rdaflag = 1;
		}
		else if(rdaflag == 1)
		{
			rdaydata += spidata;
			rdax();
			rdaflag = 2;		
		}
		else if(rdaflag == 2) 
		{			
			rdaxdata += spidata;
			rdai++;
			rdat();	
			rdaflag = 0;
		}
 
		if(rdai >= 200) 
		{				
			rdaxp = (long)rdaxdata;
			rdayp = (long)rdaydata;	
			rdatp = (long)rdatdata;

			rdai = 0;
			rdaxdata = 0;
			rdaydata = 0;
			rdatdata = 0;										
		}
	}
}		