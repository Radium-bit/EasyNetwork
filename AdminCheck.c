#include<stdio.h>
#include<Windows.h>

BOOL AdminEven() {
	BOOL fIsAdmin = FALSE;
	HANDLE hTokenToCheck = NULL;
	DWORD lastErr;
	DWORD sidLen = SECURITY_MAX_SID_SIZE;
	BYTE localAdminsGroupSid[SECURITY_MAX_SID_SIZE];

	if (!CreateWellKnownSid(WinBuiltinAdministratorsSid, NULL, localAdminsGroupSid, &sidLen))
	{
		goto CLEANUP;

	}
	if (CheckTokenMembership(hTokenToCheck, localAdminsGroupSid, &fIsAdmin))
	{
		lastErr = ERROR_SUCCESS;
	}
CLEANUP:
	if (hTokenToCheck)
	{
		CloseHandle(hTokenToCheck);
		hTokenToCheck = NULL;
	}
	return (fIsAdmin);
}

int PermissionCheck() {
	unsigned short c;
	c = AdminEven();
	if (c == 0)
	{
		printf("你没有管理员权限\n");
	}
	else
	return 0;
}