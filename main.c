#include <stdio.h>


int main(void) {

	printf("hello\n");
	return 0;
}


unsigned int data = 0;//����������4�ֽ�����
unsigned int dataOld = 0;//�������ڸ�GUI����data
unsigned int dataCounter = 0;//��ǰdata�������Ч��
unsigned int oldTime = 0;
unsigned int riseTime = 0;
/*����ʱ�����߼�ʱ�䳤�Ƚ���ֵ�������ý���״̬*/
int getCode(unsigned int diffTime,int * state) {
	if (diffTime<2500 && diffTime>1500){
		*state = 0;
		return 1;//����1
	}
	else if (diffTime<1500 && diffTime>500){
		*state = 0;
		return 0;//����0
	}
	else if (diffTime<14000 && diffTime>13000) {
		*state = 1;
		return 9;//��ʼ��
	}
	else if (diffTime<110000 && diffTime>100000) {
		*state = 2;
		return 10;//�ظ���1
	}
	else if (diffTime<12000 && diffTime>10000) {
		*state = 2;
		return 10;//�ظ���2
	}
	else if (diffTime<55000 && diffTime>50000) {
		*state = 3;
		return 11;//ֹͣ��
	}

	return -1;
}
/*���뺯������Ҫѭ��ִ�У��ȴ��½���*/
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
			case 0://����
				if (resultCode == 1) data = (data | 0x80000000) >> 1;
				else data = data >> 1;
				counter++;
				if (counter>=32){
					dataOld = data;
					dataCounter = 1;
				}
				break;

			case 1://��ʼ��
				data = 0��
				dataCounter = 0;
				break;

			case 2://�ظ���
				dataCounter += 1;
				break;

			default:
				break;
			}
		}

	}


}
