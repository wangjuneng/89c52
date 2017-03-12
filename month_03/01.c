

/********************************************************
***********************************************       
LCD1602液晶显示实验
说明:     用杜邦线: 1.将P0口与LCD的D0-D7连接起来
          2.将P2.0  接到 
                  P2.1 P2.2 分别与RS  WR  E分别连接


********************************************************/
#include<reg52.h>
#include <math.h>
#define uchar unsigned char
#define uint  unsigned int

#define  LED  P0        //
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;
 

void nus_delay(uint nus);
void nms_delay(uint nms);
void delay(uint nms);
 

 

/****************************************************
函数名称:main
功能描述:主函数
输　入: 无
输　出: 无
*****************************************************/
void main1(void)
{
	uint num = 0;
	uint index = 0;
	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;
	//设置TMOD 模式
	TMOD = 0x01;
	TH0 = 0xB8;
	TL0 = 0x00;

    while(1){
		
	  //0 0000 0000	  1111 1111		
	  //1 0000 0001	  1111 1111		1111 1110
	  //2 0000 0011   1111 1111	    1111 1100
  	  delay(1);
	  if(index > 8){
	  	 index = 0;
		 num = 0;
	  }

	  num = pow(2,index++);
	  LED = ~num;
	  delay(1);
    }
}
 
void delay(uint nms){
	uint i,j = 0;

	//设置TMOD 模式
	TMOD = 0x01;
	TH0 = 0xB8;
	TL0 = 0x00;	
	TR0 = 1;  
	
	for(i=0;i<nms;i++){
		do{
			if(TF0 == 1){
			  	TF0 = 0;
				TH0 = 0xB8;
				TL0 = 0x00;
				j++;
			}
		}		
		while(j<=50);
		
	}
	  
}

/****************************************************
函数名称:nus_delay
功能描述:微秒级延时子程序
输　入: 无
输　出: 无
说明:   
晶振为11.0592M时  

*****************************************************/
void nus_delay(uint nus)
{
    int j=10;
    while(nus--)
    {
       while(j--);
           j=10;
    }
}
/****************************************************
函数名称:nms_delay
功能描述:毫秒级延时子程序
输　入: 无
输　出: 无
说明:   
晶振为11.0592M时            
*****************************************************/
void nms_delay(uint nms)
{
        while(nms--)
        nus_delay(30);
}