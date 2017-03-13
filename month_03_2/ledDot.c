#include "common.h"



sbit ENLED = P1 ^ 4;
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;

void showLedNot();
uint cnt = 0;
void main(){

	 uint i=0,sec = 0;
	 ENLED = 0;
	 ADDR3 = 0;
	 ADDR0 = 0;
	 ADDR1 = 0;
	 ADDR2 = 0;

	 P0 = 0x00;

	 //设置ET0号中断回调函数showLedNot;
	 callBackType0 = &showLedNot;

	//打开时间中断0
	 openInterrupteET0();

	 while(1){
	 	  
	 }

}

void showLedNot(){
	switch(cnt++ /1000 % 8){
	 	case 0: ADDR2 = 0;ADDR1 =0;ADDR0=0; break;
		case 1: ADDR2 = 0;ADDR1 =0;ADDR0=1; break;
		case 2: ADDR2 = 0;ADDR1 =1;ADDR0=0; break;
		case 3: ADDR2 = 0;ADDR1 =1;ADDR0=1; break;
		case 4: ADDR2 = 1;ADDR1 =0;ADDR0=0; break;
		case 5: ADDR2 = 1;ADDR1 =0;ADDR0=1; break;
		case 6: ADDR2 = 1;ADDR1 =1;ADDR0=0; break;
	    case 7: ADDR2 = 1;ADDR1 =1;ADDR0=1; break;
		default: break;
	}
}

/*
	定义1s
*/
void timeInterrupt() interrupt 1 
{
	set1Ms();
	if(callBackType0){
	   (*callBackType0)();
	}
}
