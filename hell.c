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
		//piLock(0);//上锁
		cmdCounter = cmdCounter;
		state = (cmd & 0x00ff0000) >> 24;
		//piUnLock(0);//去锁
		if (cmdCounter > 0) {
			cmdCounter--;
			if (state == 0x46) {
				//进入主菜单
				guiFlag = 1;
			}
		}
		else {
			guiFlag = 0;
			state = 0xff;//生产的命令消耗完，进入空闲状态
		}

		if (guiFlag == 1) {
			//只有在进入菜单后才能修改数据
			switch (state)
			{
			case 0x46:
				//绘制主菜单
				break;
			case 0x45:
				//菜单回退-绘制菜单
				break;
			case 0x44:
				//菜单项选择——上
				break;
			case 0x43:
				//菜单项选择——下
				break;
			case 0x42:
				//菜单项修改——加-修改设备数据
				break;
			case 0x41:
				//菜单项修改——减-修改设备数据
				break;
			default:
				break;
			}
		}
		//控制设备
		//setLed(ledR);
		//setLed(ledG);
		//setLed(ledB);
		if (ledSOld != ledS) {
			//避免PWM重复修改
			ledSOld = ledS;
			//setSteer(ledS);
		}
	}


}

