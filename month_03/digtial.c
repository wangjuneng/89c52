#include<reg52.h>


#define uint  unsigned int
#define uchar unsigned char;


sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

void main(){

	uint i,j,k;	

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
					P0 = ~0x06;
				}
			}
		}
	}
}
