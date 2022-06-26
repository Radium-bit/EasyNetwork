#define _CRT_SECURE_NO_WARNINGS //用于消除不安全函数警告
#include <stdio.h>
#include<stdlib.h>
//#include<Windows.h>

int main() {
	int x;
	x = 0;
	int Hello(), Guide(), Choice();
	Hello();
	Guide();
	x = Choice(); //执行选择并检测返回值
	if (x == 2) {
		system("cls"); printf("\033[47;31mError! 功能尚未支持，Debugcode 0x0002\033[0m");
	}
	else if (x == 1) {  //else if 和 if 需要加上括号
		system("cls"); printf("\033[47;31mError! 输入错误！,Debugcode 0x0001\033[0m");
	}
	else
	return 0;
}
int Hello() {
	printf("欢迎使用EasyNetwork网络管理程序！");
	system("pause");
	system("cls");
	printf("\033[47;31mWARNING\n你需要管理员权限来执行此程序！\n现在检查权限，并确认进行下一步\n\033[0m");
	printf("你目前的用户组为:");
	system("whoami");
	system("pause");
	system("cls");
	return 0;
}
int Guide() {
	printf("请输入要执行的操作数字代号...\n\n");
	printf("1. 清除DNS缓存\t\t2. 重置网络设定\n\n3. 防火墙设定\t\t");
	printf("4. 打开安全策略\n\n5. 打开网卡适配器面板\t6. 打开证书面板\n\n");
	printf("7. Hosts文件相关\t8. 关于本项目\n\n");
	printf("按空格键退出\n");
	return 0;
}

int Choice() {
	int ch;
	int clearDNS(),resetNetwork(),FWC(),SecurityControl(),NetworkManager(),Crtmgr(),AboutHosts(),AboutProject();
	ch = getchar();
	switch(ch) 
	{
	case '1':clearDNS(); return 0; break;
	case '2':resetNetwork(); /*return 0 */ ; break;
	case '3':FWC(); return 0; break; //Jump to Firewall Control
	case '4':SecurityControl(); return 0; break; // Jump to Local Security gpedit
	case '5':NetworkManager(); return 0; break;
	case '6':Crtmgr(); return 0; break;
	case '7':AboutHosts(); break;
	case '8':AboutProject(); break;
	default: return 1; // Value "1" Means Type Error
	}
}
int clearDNS() {
	system("ipconfig /flushdns");
	return 0;
}
int FWC() {  //Firewall Control Submenu
	int ch;
	int OnFirewall(), OffFirewall(), AdvancedFW();
	system("cls");
	printf("请输入要执行的操作数字代号...\n\n");
	printf("1. 启动防火墙\n\n2. 关闭防火墙\n\n3. 启动防火墙设定面板\n");
	getchar(); //因为上面的“回车确认”会被当作下一个函数输入，因此先使用一次getchar消除掉回车键的影响。
	ch = getchar();
	switch (ch)
	{
	case '1': OnFirewall(); break;
	case '2': OffFirewall(); break;
	case '3': AdvancedFW(); return 0; break;
	default: return 1;
		break;
	}
}
int AboutHosts() {     //Hosts Modify part
	int ch;
	int OpenHFile(), resetHosts(), backupHosts();
	system("cls");
	printf("请输入要执行的操作数字代号...\n\n");
	printf("1. 打开Hosts文件\n\n2. 重置Hosts文件\n\n3. 备份Hosts文件\n");
	getchar(); //因为上面的“回车确认”会被当作下一个函数输入，因此先使用一次getchar消除掉回车键的影响。
	ch = getchar();
	switch (ch)
	{
	case '1': OpenHFile(); break;
	case '2': resetHosts(); break;
	case '3': backupHosts(); break;
	default: return 1;
		break;
	}
}
// Network Cofing Reset
int resetNetwork() {
	system("netsh winsock reset");
	return 0;
}
//Local Security gpedit panel
int SecurityControl() {
	system("secpol.msc");
	return 0;
}
int NetworkManager() {
	system("ncpa.cpl");
	return 0;
}
int Crtmgr() {
	system("certmgr.msc");
	return 0;
}
// Firewall Control Part
int OnFirewall() {
	system("netsh advfirewall set allprofiles state on");
	printf("Windows防火墙已开启");
	system("pause");
	return 0;
}
int OffFirewall() {
	system("netsh advfirewall set allprofiles state off");
	system("Windows防火墙已关闭");
	system("pause");
	return 0;
}
int AdvancedFW() {
	system("control.exe /name Microsoft.WindowsFirewall");
	return 0;
}
//Hosts Modify part
int OpenHFile() {
	system("notepad %systemroot%/system32/drivers/etc/hosts");
	return 0;
}
int resetHosts() {
	;
	return 2;
}
int backupHosts() {
	return 2; //未开放
	char *path,str[50],command[100];
	path = str;
	printf("请输入想要备份Hosts文件到的路径。");
	printf("例如：C:\\Users\\Public\n");
	scanf("%s", path);
	sprintf(command, "echo %%hsystemroot%%h/system32/drivers/etc/hosts %s",str);
	return 0;
}
//About Project
int AboutProject() {
	system("start https://github.com/Radium-bit/EasyNetwork");
	return 0;
}