#include <windows.h>
#include "resource.h"

HINSTANCE g_hInst = NULL;

//7 对话框窗口处理函数
INT_PTR CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SYSCOMMAND:
	{
		switch (wParam)
		{
		case SC_CLOSE:
			//关闭对话框并返回1
			EndDialog(hWnd, 1);
			break;
		}
	}
	break;
	}
	//return DefDlgProc( hWnd, nMsg,
	//	wParam, lParam );
	return 0;
}

//2-1-处理菜单命令
VOID OnCommand(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case ID_EXIT:
	{
		PostQuitMessage(0);
		break;
	}
	case ID_FIND:
	{
		//创建对话框
		int nRet = DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DLG), hWnd, DialogProc);
		//根据返回值做不同处理
		if (1 == nRet)
		{
			MessageBox(NULL, "取消配置", "WinDlg", MB_OK);
		}
		else
		{
			MessageBox(NULL, "应用配置", "WinDlg", MB_OK);
		}
		break;
	}
	default:
		break;
	}
}

//2 窗口处理函数
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
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
	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE);//窗口画刷
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
	HMENU hMenu = LoadMenu(g_hInst, MAKEINTRESOURCE(IDR_MAIN));
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