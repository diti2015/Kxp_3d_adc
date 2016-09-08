/*
 * Copyright (C) 2006 LIQING CO.,LTD
 *
 * file name: 3d_adc_pin.h
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

#ifndef _3D_ADC_PIN_H__
#define _3D_ADC_PIN_H__

sbit	IN1 = P0^0;
sbit	IN2 = P0^2;
sbit	IN3 = P0^7;
sbit	OUT1 = P0^1;
sbit	OUT2 = P0^6;		 

#define ON 0
#define OFF 1

#endif