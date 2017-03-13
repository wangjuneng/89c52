#include<reg52.h>

#ifndef TYPE
	#define TYPE __TYPE__
	#define uint unsigned int
	#define uchar unsigned char
#endif

typedef  void (*CallBackType)();

CallBackType callBackType0 = 0 ;

//定时器设置1毫秒
void set1Ms();

//延时功能 单位毫秒
void delay(uint ms){
	uint i = 0;

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
	set1Ms();
	//打开ET0号中断
	EA = 1;
	//打开定时0中断
	ET0 = 1;
}

void set1Ms(){
   	TH0 = 0xFC;
	TL0 = 0X66;
}
