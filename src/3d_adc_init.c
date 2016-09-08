/*
 * Copyright (C) 2006 LIQING CO.,LTD
*/

#include <c8051f350.h>
#include "3d_adc_init.h"
#include "3d_adc_adc.h"

#define FLBYTE	    0x1DFF

void ADCInital(void)
{
	ADC0MD = 0x00;
	ADC0DEC = 0x1FF;

	ADC0CN = 0x17;
	ADC0CF = 0x00;

	ADC0MUX = CHX;
	ADC0MD = 0x81;
	ADC0MD = 0x82;
} 

// Peripheral specific initialization functions,
// Called from the Init_Device() function
void PCA_Init()
{
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;
}

void Timer_Init()
{
    TCON      = 0x40;
    TMOD      = 0x20;
    CKCON     = 0x08;
    TH1       = 0x60;
}

void UART_Init()
{
    SCON0     = 0x10;
}

void Port_IO_Init()
{
	P0MDOUT   = 0x0F;  
	P1MDOUT   = 0x04;
    P0SKIP    = 0xC0;
    P1SKIP    = 0xFB;
    XBR0      = 0x03;
    XBR1      = 0x40;
}

void SPI_Init()
{
    SPI0CFG   = 0x40;
    SPI0CN    = 0x01;		 
    SPI0CKR   = 0x04;	   
}

void Oscillator_Init()
{
 //   OSCICN    = 0x83;
}

void Interrupts_Init()
{
    IP        = 0x40;
    EIE1      = 0x08;
    IE        = 0xd0;
}


 void FLASH_LOCK(void)
{ 	
	unsigned char xdata * data fp;
	VDM0CN = 0x80;
	PSCTL = 0x01;
	fp = FLBYTE;
	FLKEY =0xA5;
	FLKEY =0xF1;
	*fp = 0xFF;	
	PSCTL  =0;  
}

// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
	PCA_Init();	 
	
    Timer_Init();
    UART_Init();
    Port_IO_Init();
	FLASH_LOCK();
	SPI_Init();
    Oscillator_Init();
    Interrupts_Init();
	ADCInital();	
}