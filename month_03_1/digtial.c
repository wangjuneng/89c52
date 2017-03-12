#include<reg52.h>

#define uint unsigned int
#define uchar unsigned char

#define LED P0

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;
sbit BUZZ = P1 ^ 6;

void delay(uint nms);

void main(){
	unsigned char LedChar[16] = {
	    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
	    0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
	};
	
	unsigned char LedBuff[] = {
	     0x00,  0x00, 0x00, 0x00, 0x00, 0x00
	};


	uint index=0,sec=0;
	

	ENLED = 0;
	ADDR3 = 1;

	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;
	

	while(1){
		 BUZZ = 0;
		if(index % 1000 == 0){
			 sec++;
			 LedBuff[0]= LedChar[sec % 10] ;
			 LedBuff[1]= LedChar[sec/10 % 10] ;
			 LedBuff[2]= LedChar[sec/100 % 10] ;
			 LedBuff[3]= LedChar[sec/1000 % 10] ;
			 LedBuff[4]= LedChar[sec/10000 % 10] ;
			 LedBuff[5]= LedChar[sec/100000 % 10] ;
			 
		}
	    
		ENLED = 1;
		switch(index++%6){
			case 0 :  ADDR2 = 0;ADDR1 = 0;ADDR0 = 0; LED = LedBuff[0];	break;
			case 1 :  ADDR2 = 0;ADDR1 = 0;ADDR0 = 1; LED = LedBuff[1];	break;
			case 2 :  ADDR2 = 0;ADDR1 = 1;ADDR0 = 0; LED = LedBuff[2];	break;
			case 3 :  ADDR2 = 0;ADDR1 = 1;ADDR0 = 1; LED = LedBuff[3];	break;
			case 4 :  ADDR2 = 1;ADDR1 = 0;ADDR0 = 0; LED = LedBuff[4];	break;
			case 5 :  ADDR2 = 1;ADDR1 = 0;ADDR0 = 1; LED = LedBuff[5];	break;
			default:
				break;
		
		}

		ENLED = 0;
		delay(1);
	}

	
}

 
void delay(uint nms){
	uint i,j = 0;
	//…Ë÷√TMOD ƒ£ Ω
	TMOD = 0x01;
	TH0 = 0xFC;
	TL0 = 0x67;	
	TR0 = 1;  
	for(i=0;i<nms;i++){
		do{
			if(TF0 == 1){
			  	TF0 = 0;
				TH0 = 0xFC;
				TL0 = 0x67;
				j++;
			}
		}		
		while(j<1);	
	}  
}