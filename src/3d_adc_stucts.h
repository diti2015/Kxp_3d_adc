/*
 * Copyright (C) 2006 LIQING CO.,LTD	
*/


#ifdef   OS_GLOBALS             
	#define  OS_EXT
#else
	#define  OS_EXT extern
 #endif

//uart
OS_EXT unsigned char UartSendCount;	  //�������ݴ�������
OS_EXT unsigned char xdata UartSendBuf[50]; //���ʹ������ݵĻ�����
OS_EXT unsigned char UartSendLen;	  //�������ݴ��ĵ�ǰ����

//adc param
OS_EXT unsigned char flagadc;	 //����ADC�жϲɼ���־��
OS_EXT unsigned char adccho;	 //����ɼ�״̬������Ҫ���x,y,z�����Լ��������β��������һ�������Ϣ
OS_EXT int xdata x1,y1,z1,x0,y0,z0,adcmag;	//�����ԭʼֵ����������

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
