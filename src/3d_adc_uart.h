/*
 * Copyright (C) 2006 LIQING CO.,LTD	
*/

#ifndef _3D_ADC_UART_H__
#define _3D_ADC_UART_H__

//�ж��Ƿ���Ը��·������ݻ��������Ƿ���Է�������
//����ֵΪ1����ʾ���Է�������
unsigned char Uart_Send_If();
//�����������ݷ���
//�������Ϊ��Ҫ���͵����ݵĳ���
void Uart_Send(unsigned char SendLen,char class);
void SendData(void);

#endif