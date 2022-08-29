#include<stdio.h>

int ResultCheck() {
	unsigned short x;
	x = Choice(); //执行选择并检测返回值
	if (x == 2) {
		system("cls"); printf("\033[47;31mError! 功能尚未支持，Debugcode 0x0002\033[0m");
	}
	else if (x == 1) {  //else if 和 if 需要加上括号
		system("cls"); printf("\033[47;31mError! 输入错误或已退出！,Debugcode 0x0001\033[0m");
	}
	else
		return 0;
}