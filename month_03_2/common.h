#include<reg52.h>

#ifndef TYPE
	#define TYPE __TYPE__
	#define uint unsigned int
	#define uchar unsigned char
#endif

typedef  void (*CallBackType)();

CallBackType callBackType0 = 0 ;

//��ʱ������1����
void set1Ms();

//��ʱ���� ��λ����
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
*1ms �ж� ��ET0���ж�
*/
void openInterrupteET0(){
	//����tmod ��ʱ��ģʽ 01
	TMOD = 0x01;
	//����tcon 0�Ŷ�ʱ��Ϊ�������
	TR0 = 1;
    //����1sʱ������
	set1Ms();
	//��ET0���ж�
	EA = 1;
	//�򿪶�ʱ0�ж�
	ET0 = 1;
}

void set1Ms(){
   	TH0 = 0xFC;
	TL0 = 0X66;
}
