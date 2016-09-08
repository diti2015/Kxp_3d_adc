 /*
 * Copyright (C) 2006 LIQING CO.,LTD
*/

#include <c8051f350.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "3d_adc_uart.h"
#include "3d_adc_stucts.h"


void UART0_ISR (void) interrupt 4
{
	if(RI0)
	{
		RI0 = 0;
	}

	if(TI0)
	{	
		TI0 = 0;
		if(UartSendLen > 0) 
		{
			SBUF0 = UartSendBuf[UartSendCount-UartSendLen];
			UartSendLen--;
		}		
	}
}

void SendData(void)
{
	unsigned char i,j;

	i = sprintf(UartSendBuf,",%6d,%6d,%6d,",fmagx,fmagy,-fmagz);
	j = sprintf(UartSendBuf+i,"%6u,%6u,%3d\r\n",(unsigned int)fradc,(unsigned int)fpadc,tmp);

	i = i+j;
	Uart_Send(i,'#');
}

//启动串口数据发送
//输入参数为需要发送的数据的长度
void Uart_Send(unsigned char SendLen,char class)
{
	UartSendLen = SendLen;
	UartSendCount = SendLen;

	TI0 = 0;
	SBUF0 = class;	
}
