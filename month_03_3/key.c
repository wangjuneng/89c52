#include<reg52.h>
#include<common.h>

//�����жϻص�����
void keyPressInterrputHandler();


void main(){
	//bit keyStatus[4][2] ={{1,1},{1,1},{1,1},{1,1}}; 
 	unsigned char keyStatus = 0x00;
	bit keyIn1Status = 1;
	uchar cnt = 0;
	//ʵʼ��74HC138������
	ENLED = 0;
	ADDR3 = 1;
	ADDR0 = 0;
 	ADDR1 = 0;
	ADDR2 = 0;

	//����key
	P2 = 0XF7;

	callBackType0 = &keyPressInterrputHandler; 
	//��ETO�ж�
	openInterrupteET0();
	

	while(1){
		 
		 
		 if(KEYIN1 == 0){
		 	 delay(100);
		 	 if(keyIn1Status){
				keyIn1Status = 0;
			 }else{
			 	keyIn1Status = 1;
			 }
		 }

		// LED0 = keyIn1Status;
		  
		
		 if(KEYIN4 == 0){
		  	delay(10);
			cnt++; 
			delay(10);
		 
		 } 

		 digitalNum = cnt;
		 //LED0 = keyStatus ^ 0x01; 
		 //LED1 = KEYIN2;
		 //LED2 = KEYIN3;
		// LED3 = KEYIN4;

		 
	}
}

//�����жϻص�����
void keyPressInterrputHandler(){
	showDigital(digitalNum);
}

void interruptTime0() interrupt 1 {
	set1MilliSecond();
	if(callBackType0){
	   (*callBackType0)();
	}
}