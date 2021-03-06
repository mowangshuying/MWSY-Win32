#define  _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <windowsx.h>

HINSTANCE g_hInst = NULL;
HWND g_hEdit = NULL;

//2-1-处理菜单命令
VOID OnCommand(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nNotifyCode = HIWORD(wParam);
	int nEventID = LOWORD(wParam);
	switch (nEventID)
	{
		case 1001:
		{
			switch (nNotifyCode)
			{
				case EN_CHANGE:
					//MessageBox( NULL, "EN_CHANGE",
					//	"WinEdit", MB_OK );
					break;
				case EN_UPDATE:
				{
					//char pBuf[1024];
					//Edit_GetText(g_hEdit, pBuf, 1024);
					break;
				}
			}
		}
		break;
	}
}

//2-1 处理窗口创建命令
VOID OnCreate(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	g_hEdit = CreateWindow("EDIT", "MyEdit", WS_BORDER | WS_CHILD | WS_VISIBLE | WS_VSCROLL |
		ES_MULTILINE | ES_AUTOVSCROLL | WS_HSCROLL | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_WANTRETURN,
		50, 50, 400, 400, hWnd, HMENU(1001), g_hInst, NULL);

	//设置edit中文字
	//SetDlgItemText(hWnd, 1001, "abc\r\nccc");
	//
	//SetDlgItemText(hWnd, 1001, "abcd\r\ndddd");
	//Edit_SetText(g_hEdit,"abcd\r\ndddd");
	//char pBuf[1024];
	//Edit_GetText(g_hEdit, pBuf, 1024);
	//strcat(pBuf, "\r\nkkkk");
	//Edit_SetText(g_hEdit, pBuf);
}

void OnKeyDown(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_RETURN:
		MessageBox(NULL, "Enter...", "info", MB_OK);
		break;
	default:
		break;
	}
}

void OnSize(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nWidth = LOWORD(lParam);
	int nHight = HIWORD(lParam);

	if (g_hEdit)
	{
		MoveWindow(g_hEdit, 0, 0, nWidth, nHight, true);
	}
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
	case WM_SIZE:
		OnSize(hWnd, uMsg, wParam, lParam);
		break;
	case WM_KEYDOWN:
		OnKeyDown(hWnd, uMsg, wParam, lParam);
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