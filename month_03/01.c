

/********************************************************
***********************************************       
LCD1602Һ����ʾʵ��
˵��:     �öŰ���: 1.��P0����LCD��D0-D7��������
          2.��P2.0  �ӵ� 
                  P2.1 P2.2 �ֱ���RS  WR  E�ֱ�����


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
��������:main
��������:������
�䡡��: ��
�䡡��: ��
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
	//����TMOD ģʽ
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

	//����TMOD ģʽ
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
��������:nus_delay
��������:΢�뼶��ʱ�ӳ���
�䡡��: ��
�䡡��: ��
˵��:   
����Ϊ11.0592Mʱ  

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
��������:nms_delay
��������:���뼶��ʱ�ӳ���
�䡡��: ��
�䡡��: ��
˵��:   
����Ϊ11.0592Mʱ            
*****************************************************/
void nms_delay(uint nms)
{
        while(nms--)
        nus_delay(30);
}