#include <stdio.h>


int main(void) {

	printf("hello\n");
	return 0;
}


unsigned int data = 0;//解析出来的4字节数据
unsigned int dataOld = 0;//保存用于跟GUI共享data
unsigned int dataCounter = 0;//当前data命令的有效数
unsigned int oldTime = 0;
unsigned int riseTime = 0;
/*根据时间差返回逻辑时间长度近似值，并设置解码状态*/
int getCode(unsigned int diffTime,int * state) {
	if (diffTime<2500 && diffTime>1500){
		*state = 0;
		return 1;//数据1
	}
	else if (diffTime<1500 && diffTime>500){
		*state = 0;
		return 0;//数据0
	}
	else if (diffTime<14000 && diffTime>13000) {
		*state = 1;
		return 9;//起始码
	}
	else if (diffTime<110000 && diffTime>100000) {
		*state = 2;
		return 10;//重复码1
	}
	else if (diffTime<12000 && diffTime>10000) {
		*state = 2;
		return 10;//重复码2
	}
	else if (diffTime<55000 && diffTime>50000) {
		*state = 3;
		return 11;//停止码
	}

	return -1;
}
/*解码函数，需要循环执行，等待下降沿*/
void parseIrf(void) {
	int state;
	int counter = 0;
	while (true){
		while (riseFlag != 1);
		riseFlag = 0;
		diffTime = riseTime - oldTime;
		if (diffTime == 0)continue;
		oldTime = riseTime;
		int resultCode = getCode(diffTime,&state);
		if (resultCode != -1) {
			switch (state){
			case 0://数据
				if (resultCode == 1) data = (data | 0x80000000) >> 1;
				else data = data >> 1;
				counter++;
				if (counter>=32){
					dataOld = data;
					dataCounter = 1;
				}
				break;

			case 1://初始化
				data = 0；
				dataCounter = 0;
				break;

			case 2://重复码
				dataCounter += 1;
				break;

			default:
				break;
			}
		}

	}


}
