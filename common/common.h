#include<reg52.h>

#ifndef TYPE
	#define TYPE __TYPE__
	#define uint unsigned int
	#define uchar unsigned char
#endif

#ifndef LEDCHAR
	#define LEDCHAR _LEDCHAR_;
	
#endif

#ifndef DIGITAL
	#define DIGITAL P0
	unsigned char DigitalLedChar[16] = {
	    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
	    0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
	};

	unsigned char DigitalLedBuff[] = {
     0x00,  0x00, 0x00, 0x00, 0x00, 0x00
	};

	uint digitalNum = 0;
#endif

 

typedef  void (*CallBackType)();
//et0中断回调函数
CallBackType callBackType0 = 0 ;

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

sbit LED0 = P0 ^ 0;
sbit LED1 = P0 ^ 1;
sbit LED2 = P0 ^ 2;
sbit LED3 = P0 ^ 3;
sbit LED4 = P0 ^ 4;
sbit LED5 = P0 ^ 5;
sbit LED6 = P0 ^ 6;
sbit LED7 = P0 ^ 7;


sbit KEYIN4 = P2 ^ 7;
sbit KEYIN3 = P2 ^ 6;
sbit KEYIN2 = P2 ^ 5;
sbit KEYIN1 = P2 ^ 4;

sbit KEYOUT1 = P2 ^ 3;
sbit KEYOUT2 = P2 ^ 2;
sbit KEYOUT3 = P2 ^ 1;
sbit KEYOUT4 = P2 ^ 0;

//定时器设置1毫秒
void set1MilliSecond();

//延时功能 单位毫秒
void delay(uint ms){
	uint i = 0;
	//设置tmod 定时器模式 01
	TMOD = 0x01;
	//设置tcon 0号定时器为软件清零
	TR0 = 1;
    //设置1ms时钟周期

	while(i<ms){
		if(TF0 ==1){
			 TF0 = 0;
			 TH0 = 0xFC;
			 TL0 = 0x66;
			 i++;
		}
	}
}

/**
*1ms 中断 打开ET0号中断
*/
void openInterrupteET0(){
	//设置tmod 定时器模式 01
	TMOD = 0x01;
	//设置tcon 0号定时器为软件清零
	TR0 = 1;
    //设置1s时钟周期
	set1MilliSecond();
	//打开ET0号中断
	EA = 1;
	//打开定时0中断
	ET0 = 1;
}

void set1MilliSecond(){
   	TH0 = 0xFC;
	TL0 = 0X66;
}

void showDigital(uint num){
	  static uchar index  = 0;
	  DigitalLedBuff[0] = DigitalLedChar[num % 10];
	  DigitalLedBuff[1] = DigitalLedChar[num / 10 % 10];
	  DigitalLedBuff[2] = DigitalLedChar[num / 100 % 10];
	  DigitalLedBuff[3] = DigitalLedChar[num / 1000 % 10];
	  DigitalLedBuff[4] = DigitalLedChar[num / 10000 % 10];
	  DigitalLedBuff[5] = DigitalLedChar[num / 100000 % 10];
	   
	  switch(index++%6){
		case 0 :  ADDR2 = 0;ADDR1 = 0;ADDR0 = 0; DIGITAL = DigitalLedBuff[0];	break;
		case 1 :  ADDR2 = 0;ADDR1 = 0;ADDR0 = 1; DIGITAL = DigitalLedBuff[1];	break;
		case 2 :  ADDR2 = 0;ADDR1 = 1;ADDR0 = 0; DIGITAL = DigitalLedBuff[2];	break;
		case 3 :  ADDR2 = 0;ADDR1 = 1;ADDR0 = 1; DIGITAL = DigitalLedBuff[3];	break;
		case 4 :  ADDR2 = 1;ADDR1 = 0;ADDR0 = 0; DIGITAL = DigitalLedBuff[4];	break;
		case 5 :  ADDR2 = 1;ADDR1 = 0;ADDR0 = 1; DIGITAL = DigitalLedBuff[5];	break;
		default:
			break;
	 }
}
