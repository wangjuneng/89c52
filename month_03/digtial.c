#include<reg52.h>
#include "01.c" 

#define uint  unsigned int
#define uchar unsigned char





void main(){

	uint i,j,k,cnt=0;
	uchar digtialLedChar[] ={
		0x06,0x5d,0x5f,0x66,0x6d,0x7d,0x07,0x7f
	};
		

	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 0;
	ADDR1 = 0;
	ADDR0 = 0;
	
	while(1){
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				for(k=0;k<2;k++){
					ADDR2 = i;
					ADDR1 = j;
					ADDR0 = k;
					P0 = 0x00;
				}
			}
		}
	}
}
