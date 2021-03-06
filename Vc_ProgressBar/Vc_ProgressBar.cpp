#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <CommCtrl.h>

HINSTANCE g_hInst = NULL;
HWND g_hPbWnd = NULL;
HWND g_hStatic = NULL;

//定时器消息
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	SendMessage(g_hPbWnd, PBM_STEPIT, 0, 0);
	int pos = SendMessage(g_hPbWnd, PBM_GETPOS, 0, 0);
	char pBuf[20];
	_itoa_s(pos, pBuf, 10);
	strcat(pBuf, "%");
	SetDlgItemText(hWnd, 1001, pBuf);
}

//2-1-处理菜单命令
VOID OnCommand(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	default:
		break;
	}
}

//2-1 处理窗口创建命令
VOID OnCreate(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//创建滚动条
	g_hPbWnd = CreateWindowEx(NULL, PROGRESS_CLASS,NULL, WS_CHILD | WS_VISIBLE | PBS_SMOOTH, 50, 50, 200, 20,hWnd,NULL, g_hInst, NULL);

	g_hStatic = CreateWindow("STATIC", "",WS_CHILD | WS_VISIBLE | SS_SUNKEN | SS_SIMPLE | SS_NOTIFY,250, 50, 30, 20, hWnd, (HMENU)1001,g_hInst, NULL);

	//设置滚动条范围
	SendMessage(g_hPbWnd, PBM_SETRANGE, 0, MAKELPARAM(0,100));

	//设置滚动条前进步数大小
	SendMessage(g_hPbWnd, PBM_SETSTEP, (WPARAM)1, 0);


	//for (int i = 0; i < 50; i++)
	//{
		//SendMessage(hPbWnd, PBM_STEPIT, 0, 0);
	//}
	//
	//DestroyWindow(hPbWnd);

	SetTimer(hWnd, 1001, 1000, TIMERPROC(TimeProc));
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
	{
		KillTimer(hWnd, 1001);
		DestroyWindow(g_hPbWnd);
		PostQuitMessage(0);
		break;
	}
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
		TranslateMessage(&msg);
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