#include<stdio.h>

int ResultCheck() {
	unsigned short x;
	x = Choice(); //ִ��ѡ�񲢼�ⷵ��ֵ
	if (x == 2) {
		system("cls"); printf("\033[47;31mError! ������δ֧�֣�Debugcode 0x0002\033[0m");
	}
	else if (x == 1) {  //else if �� if ��Ҫ��������
		system("cls"); printf("\033[47;31mError! �����������˳���,Debugcode 0x0001\033[0m");
	}
	else
		return 0;
}