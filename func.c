#define _CRT_SECURE_NO_WARNINGS //������������ȫ��������
#include <stdio.h>
#include <stdlib.h>

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
	printf("Windows����ǽ�ѿ���");
	system("pause");
	return 0;
}
int OffFirewall() {
	system("netsh advfirewall set allprofiles state off");
	system("Windows����ǽ�ѹر�");
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
	return 2;
}
int backupHosts() {
	char* path, str[50], command[100];
	path = str;
	printf("��������Ҫ����Hosts�ļ�����·����");
	printf("���磺C:\\Users\\Public\n");
	scanf("%s", path);
	sprintf(command, "copy C:\\Windows\\System32\\drivers\\etc\\hosts %s", str);
	system(command);
	return 0;
}
