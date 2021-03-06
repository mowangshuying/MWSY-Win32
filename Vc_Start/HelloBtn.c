#include <windows.h>


HINSTANCE g_hInst = NULL;

//2 窗口处理函数
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//3 注册窗口类型
//BOOL MyRegister(LPSTR pszClassName)
//{
//	WNDCLASS wc = { 0 };
//	ATOM  nAtom = 0;
//
//	wc.style = CS_VREDRAW | CS_HREDRAW;
//	wc.lpfnWndProc = WindowProc;
//	wc.cbClsExtra = 0;//窗口类附加数据
//	wc.cbWndExtra = 0;//窗口附加数据
//	wc.hInstance = g_hInst;//窗口实例句柄
//	//wc.hIcon = NULL;
//	wc.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(100));
//	wc.hCursor = NULL;
//	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE);//窗口画刷
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = pszClassName;
//
//	nAtom = RegisterClass(&wc);
//	if (0 == nAtom)
//	{
//		MessageBox(NULL, "Register Failed", "Error", MB_OK | MB_ICONWARNING);
//		return FALSE;
//	}
//	//else
//	//{
//	//	MessageBox(NULL, "Register Successed","Successed", MB_OK);
//	//}
//	return TRUE;
//}

//4 窗口创建
HWND MyCreate(LPSTR pszClassName)
{
	HWND hWnd = NULL;
	hWnd = CreateWindow(pszClassName, "HelloWnd", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500, NULL, NULL, g_hInst, NULL);
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
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
	HWND hWnd = NULL;
	//MyRegister("MyWnd");
	hWnd = MyCreate("BUTTON");
	DisplayWnd(hWnd);
	Message();
	return 0;
}

/*
* 1、拷贝ico文件
* 2、建立脚本文件
*/