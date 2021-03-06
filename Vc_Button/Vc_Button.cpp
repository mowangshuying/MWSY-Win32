#include <windows.h>

HINSTANCE g_hInst = NULL;


//2-1-处理菜单命令
VOID OnCommand(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nNotifyCode = HIWORD(wParam);
	int nEventId = LOWORD(wParam);
	switch (nEventId)
	{
	case 1001:
		switch (nNotifyCode)
		{
		case BN_CLICKED:
			MessageBox(NULL, "PushButton Clicked!", "Info", MB_OK);
			break;
		}
		break;
	default:
		break;
	}
}

//2-1 处理窗口创建命令
VOID OnCreate(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	CreateWindow("BUTTON", "单选按钮", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		90, 100, 300, 50, hWnd, HMENU(1002), g_hInst, NULL);

	CreateWindow("BUTTON", "PushButton", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		100, 120, 200, 20, hWnd, HMENU(1001), g_hInst, NULL);

	CreateWindow("BUTTON", "复选框", WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		90, 150, 150,200, hWnd, HMENU(1002), g_hInst, NULL);

	CreateWindow("BUTTON", "选项一", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX ,
		100, 200, 100, 30,hWnd,HMENU(1003),g_hInst,NULL);

	CreateWindow("BUTTON", "选项二", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		100, 250, 100, 30, hWnd, HMENU(1004), g_hInst, NULL);

	CreateWindow("BUTTON", "选项三", WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		100, 300, 100, 30, hWnd, HMENU(1005), g_hInst, NULL);

	CreateWindow("BUTTON", "单选框", WS_CHILD | WS_VISIBLE | BS_GROUPBOX ,
		240, 150, 150, 200, hWnd, HMENU(1002), g_hInst, NULL);

	CreateWindow("BUTTON", "A", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		250, 200, 100, 30, hWnd, HMENU(1006), g_hInst, NULL);
	CreateWindow("BUTTON", "B", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON ,
		250, 250, 100, 30, hWnd, HMENU(1007), g_hInst, NULL);
	CreateWindow("BUTTON", "C", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON ,
		250, 300, 100, 30, hWnd, HMENU(1008), g_hInst, NULL);

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