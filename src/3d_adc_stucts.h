/*
 * Copyright (C) 2006 LIQING CO.,LTD	
*/


#ifdef   OS_GLOBALS             
	#define  OS_EXT
#else
	#define  OS_EXT extern
 #endif

//uart
OS_EXT unsigned char UartSendCount;	  //发送数据串的总数
OS_EXT unsigned char xdata UartSendBuf[50]; //发送串口数据的缓冲区
OS_EXT unsigned char UartSendLen;	  //发送数据串的当前个数

//adc param
OS_EXT unsigned char flagadc;	 //磁阻ADC中断采集标志量
OS_EXT unsigned char adccho;	 //磁阻采集状态，共需要完成x,y,z正向以及反向六次操作，获得一组磁阻信息
OS_EXT int xdata x1,y1,z1,x0,y0,z0,adcmag;	//磁阻的原始值共六个参数

//spi
OS_EXT unsigned char spistate;
OS_EXT unsigned int spidata;
OS_EXT unsigned char angleflag,rdaflag;
OS_EXT float rdaxdata,rdaydata,rdatdata;
OS_EXT long idata rdaxp,rdayp,rdatp,rdatp;
OS_EXT unsigned char rdai;

OS_EXT unsigned char flagprint;		   

OS_EXT long  idata padc,radc,fpadc,fradc;
OS_EXT int  idata fmagx,fmagy,fmagz,tmp,tix;
OS_EXT long xdata bufp[20],bufr[20];
OS_EXT long xdata bufx[20],bufy[20],bufz[20];
OS_EXT unsigned char idata lenp,lenr,lenx,leny,lenz;
OS_EXT long idata filtdatap,filtdatar,filtdatax,filtdatay,filtdataz;
