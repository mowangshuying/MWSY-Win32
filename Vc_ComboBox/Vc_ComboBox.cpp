
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <windowsx.h>
#include <stdlib.h>
#include "resource.h"


HINSTANCE g_hInst = NULL;

//2-1-处理菜单命令
VOID OnCommand(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	auto hCbWnd = GetDlgItem(hWnd, 1001);
	switch (wParam)
	{
	case ID_ADD:
		SendMessage(hCbWnd, CB_ADDSTRING, 0, LPARAM("列表项-add-1"));
		SendMessage(hCbWnd, CB_ADDSTRING, 0, LPARAM("列表项-add-2"));
		SendMessage(hCbWnd, CB_ADDSTRING, 0, LPARAM("列表项-add-3"));

		ComboBox_AddString(hCbWnd,"列表项-add-4");//控制宏
		break;
	case ID_FIND:
	{
		//wparam中填写-1为查找所有项 lparam为字符串指针
		LRESULT nRet = SendMessage(hCbWnd, CB_FINDSTRING, -1, LPARAM("列表项-add-3"));
		LRESULT nRetx = ComboBox_FindString(hCbWnd, -1, "列表项-add-4");
		if (nRet == CB_ERR)
		{
			MessageBox(NULL, "cb_err", "Error", MB_OK);
			break;
		}
		//查找成功并选择
		SendMessage(hCbWnd, CB_SETCURSEL, nRet, 0);
		break;
	}
	case ID_REMOVE:
	{
		//wparam为索引值 lparam暂时不会用到
		SendMessage(hCbWnd, CB_DELETESTRING, 0, 0);
		break;
	}
	case ID_GET:
	{
		LRESULT nRet = SendMessage(hCbWnd, CB_GETCURSEL, 0, 0);
		char pSzBuf1[32];
		char pSzBuf2[128];
		_itoa(nRet, pSzBuf1, 10);
		strcpy(pSzBuf2, "ID_GET-index:");
		strcat(pSzBuf2, pSzBuf1);
		MessageBox(NULL, pSzBuf2, "Info", MB_OK);
		break;
	}
	case ID_EXIT:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		break;
	}
}

//2-1 处理窗口创建命令
VOID OnCreate(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//创建组合框
	CreateWindow("COMBOBOX", "DropdownCbox", WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
		50, 50, 200, 200, hWnd, HMENU(1001), g_hInst, NULL);
}

//2 窗口处理函数
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		OnCreate(hWnd, uMsg, wParam, lParam);
		break;
	case WM_COMMAND:
		OnCommand(hWnd, uMsg, wParam, lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//3 注册窗口类型
BOOL MyRegister(LPCSTR pszClassName)
{
	WNDCLASS wc = { 0 };
	ATOM  nAtom = 0;

	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;//窗口类附加数据
	wc.cbWndExtra = 0;//窗口附加数据
	wc.hInstance = g_hInst;//窗口实例句柄
	//wc.hIcon = NULL;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE+3);//窗口画刷
	wc.lpszMenuName = MAKEINTRESOURCE(101);
	wc.lpszClassName = pszClassName;

	nAtom = RegisterClass(&wc);
	if (0 == nAtom)
	{
		MessageBox(NULL, "Register Failed", "Error", MB_OK | MB_ICONWARNING);
		return FALSE;
	}
	//else
	//{
	//	MessageBox(NULL, "Register Successed","Successed", MB_OK);
	//}
	return TRUE;
}

//4 窗口创建
HWND MyCreate(LPCSTR pszClassName)
{
	HMENU hMenu = NULL;
	HWND hWnd = NULL;
	hWnd = CreateWindow(pszClassName, "HelloWnd", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, hMenu, g_hInst, NULL);
	if (NULL == hWnd)
	{
		MessageBox(NULL, "CreateWnd Failed", "Error", MB_OK);
		return NULL;
	}
	//MessageBox(NULL, "CreateWnd Successed","Successed", MB_OK);
	return hWnd;
}

//5 显示窗口
void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}

//6 消息处理
void Message()
{
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}
}

//1 入口函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	HWND hWnd = NULL;
	MyRegister("MyWnd");
	hWnd = MyCreate("MyWnd");
	DisplayWnd(hWnd);
	Message();
	return 0;
}