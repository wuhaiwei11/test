// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	return 0;
}

unsigned int cmd;
unsigned int cmd;
unsigned int cmdCounter;
unsigned int ledR = 0;
unsigned int ledG = 0;
unsigned int ledB = 0;
unsigned int ledS = 0;
unsigned int ledSOld = 0;
unsigned int state = 0;
unsigned int guiFlag = 0;

void guiLoop() {

	while (true) {
		//piLock(0);//����
		cmdCounter = cmdCounter;
		state = (cmd & 0x00ff0000) >> 24;
		//piUnLock(0);//ȥ��
		if (cmdCounter > 0) {
			cmdCounter--;
			if (state == 0x46) {
				//�������˵�
				guiFlag = 1;
			}
		}
		else {
			guiFlag = 0;
			state = 0xff;//���������������꣬�������״̬
		}

		if (guiFlag == 1) {
			//ֻ���ڽ���˵�������޸�����
			switch (state)
			{
			case 0x46:
				//�������˵�
				break;
			case 0x45:
				//�˵�����-���Ʋ˵�
				break;
			case 0x44:
				//�˵���ѡ�񡪡���
				break;
			case 0x43:
				//�˵���ѡ�񡪡���
				break;
			case 0x42:
				//�˵����޸ġ�����-�޸��豸����
				break;
			case 0x41:
				//�˵����޸ġ�����-�޸��豸����
				break;
			default:
				break;
			}
		}
		//�����豸
		//setLed(ledR);
		//setLed(ledG);
		//setLed(ledB);
		if (ledSOld != ledS) {
			//����PWM�ظ��޸�
			ledSOld = ledS;
			//setSteer(ledS);
		}
	}


}

