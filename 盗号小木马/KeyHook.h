#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<stdio.h>

HHOOK hHook;

LRESULT CALLBACK hookProc(int code, WPARAM wParam, LPARAM lParam);

extern "C" _declspec(dllexport) bool installHook();//��װ����

extern "C" _declspec(dllexport) bool uninstallHook();//ж�ع���
