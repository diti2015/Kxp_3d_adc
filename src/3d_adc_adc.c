 /*
 * Copyright (C) 2006 LIQING CO.,LTD	
*/

#include <c8051f350.h>
#include "3d_adc_stucts.h"
#include "3d_adc_adc.h"

sbit 	SET = P1^2;

union
{	
	 unsigned char c[2];
	 unsigned int  i;
}res;


void adc0(void) interrupt 10
{
	
	AD0INT = 0;

	res.c[0] = ADC0H;
	res.c[1] = ADC0M;

	adcmag = res.i;
   	flagadc = 1;
}

void getmag(void)
{
	if(flagadc == 1)
	{
		flagadc = 0;

		if(adccho == 0) {SET = 0;x0 = adcmag;adccho = 1;ADC0MUX = CHY;}
		else if(adccho == 1) {SET = 0;y0 = adcmag;adccho = 2;ADC0MUX = CHZ;}
		else if(adccho == 2) {SET = 1;z0 = adcmag;adccho = 3;ADC0MUX = CHX;}
		else if(adccho == 3) {SET = 1;x1 = adcmag;adccho = 4;ADC0MUX = CHY;}
		else if(adccho == 4) {SET = 1;y1 = adcmag;adccho = 5;ADC0MUX = CHZ;}
		else if(adccho == 5) {SET = 0;flagprint = 1;z1 = adcmag;adccho = 0;ADC0MUX = CHX;}	
	
		ADC0MD = 0x82;
	}
}