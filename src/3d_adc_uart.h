/*
 * Copyright (C) 2006 LIQING CO.,LTD	
*/

#ifndef _3D_ADC_UART_H__
#define _3D_ADC_UART_H__

//判断是否可以更新发送数据缓冲区，是否可以发送数据
//返回值为1，表示可以发送数据
unsigned char Uart_Send_If();
//启动串口数据发送
//输入参数为需要发送的数据的长度
void Uart_Send(unsigned char SendLen,char class);
void SendData(void);

#endif