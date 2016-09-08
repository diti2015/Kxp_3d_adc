/*
 * Copyright (C) 2006 LIQING CO.,LTD
 *	
*/

#include <stdio.h>
#include <c8051f350.h>
#include <math.h>
#define OS_GLOBALS
#include "3d_adc_stucts.h"
#undef  OS_GLOBALS
#include "3d_adc_pin.h"
#include "3d_adc_init.h"
#include "3d_adc_uart.h"
#include "3d_adc_adc.h"
#include "3d_adc_spi.h"

unsigned char idata lc;
long averagefilter(long * buffer,unsigned char * len,long compassdata,int  filter,long *filtdata)
{
	unsigned char idata tmplen;
	long idata redata;
	unsigned char idata tlen;
	tlen = *len;
	
	redata = compassdata - *(buffer+tlen);
	if(redata < 0) redata = -redata;

	if((redata > filter)  || (*filtdata == 0))
	{
		for(tmplen=0;tmplen<lc;tmplen++)
		{
			*(buffer+tmplen) = compassdata;
		}
		*filtdata = compassdata*lc;
		tlen = 0;
		redata = compassdata;
	}
	else
	{		
		if(tlen >= lc-1)  tlen = 0;
		else tlen++;		
		*filtdata = *filtdata - *(buffer+tlen);
		*(buffer+tlen) = compassdata;
		*filtdata = *filtdata + compassdata;
		redata = (long)((float)(*filtdata)/(float)lc);
	}
 
	*len = tlen;

	
	return redata;
}

void main(void)
{	
	Init_Device();
	flagadc = 0;

	rdax();
	rdai = 0;

	while(1)
	{
		getrda();
		getmag();
		if(flagprint == 1)
		{				 
			flagprint = 0;				

			padc = rdayp - 204800;
			radc = rdaxp - 204800;	
			
			tmp = (rdatp/200.0 -197.0)/-1.083;		

			lc = 20;
			fpadc = averagefilter(bufp,&lenp,padc,150,&filtdatap);
			fradc = averagefilter(bufr,&lenr,radc,150,&filtdatar);
			
			fpadc = fpadc /6;
			fradc = fradc /6;

			fpadc = fpadc + 21845;
			fradc = fradc + 21845;
 
			fmagx = (int)averagefilter(bufx,&lenx,(x0 - x1),150,&filtdatax);
			fmagy = (int)averagefilter(bufy,&leny,(y0 - y1),150,&filtdatay);
			fmagz = (int)averagefilter(bufz,&lenz,(z0 - z1),150,&filtdataz);
	 
			SendData();
		}
	}
}				 