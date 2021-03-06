// WinTimer.cpp : Defines the entry point for the application.
//
#define  _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>

HINSTANCE g_hInst = NULL;
HANDLE    g_hStdOut = NULL;
UINT      g_nTimerID1 = 0;

void CALLBACK TimerProc1(HWND hWnd,
	UINT nMsg,
	UINT_PTR idEvent,
	DWORD dwTime)
{
	CHAR szText[] = "TimerProc1: Hello Timer\n";
	WriteConsole(g_hStdOut, szText,
		strlen(szText), NULL, NULL);
}

void OnCreate(HWND hWnd, UINT nMsg,
	WPARAM wParam, LPARAM lParam)
{
	//使用窗口处理函数，创建2个定时器
	SetTimer(hWnd, 1000, 3 * 1000, NULL);
	SetTimer(hWnd, 1001, 5 * 1000, NULL);
	//使用窗口处理函数, 未指明定时器ID
	g_nTimerID1 = SetTimer(hWnd, 0,
		1 * 1000, NULL);
	//使用TimerProc处理函数创建定时器
	SetTimer(hWnd, 1002, 7 * 1000, TimerProc1);
}

void OnTimer(HWND hWnd, UINT nMsg,
	WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case 1000:
	{
		CHAR szText[] = "1000: Hello Timer\n";
		WriteConsole(g_hStdOut, szText,
			strlen(szText), NULL, NULL);
	}
	break;
	case 1001:
	{
		CHAR szText[] = "1001: Hello Timer\n";
		WriteConsole(g_hStdOut, szText,
			strlen(szText), NULL, NULL);
	}
	break;
	default:
	{
		CHAR szText[260] = { 0 };
		sprintf(szText, "%d: Hello Timer\n",
			g_nTimerID1);
		WriteConsole(g_hStdOut, szText,
			strlen(szText), NULL, NULL);
	}
	break;
	}
}

LRESULT CALLBACK WndProc(HWND hWnd,
	UINT nMsg,
	WPARAM wParam,
	LPARAM lParam)
{
	switch (nMsg)
	{
	case WM_CREATE:
		OnCreate(hWnd, nMsg, wParam, lParam);
		break;
	case WM_TIMER:
		OnTimer(hWnd, nMsg, wParam, lParam);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, 1000);
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, nMsg,
		wParam, lParam);
}

BOOL RegisterWnd(LPCSTR pszClassName)
{
	WNDCLASSEX wce = { 0 };
	wce.cbSize = sizeof(wce);
	wce.cbClsExtra = 0;
	wce.cbWndExtra = 0;
	wce.hbrBackground = HBRUSH(COLOR_WINDOW);
	wce.hCursor = NULL;
	wce.hIcon = NULL;
	wce.hIconSm = NULL;
	wce.hInstance = g_hInst;
	wce.lpfnWndProc = WndProc;
	wce.lpszClassName = pszClassName;
	wce.lpszMenuName = NULL;
	wce.style = CS_VREDRAW | CS_HREDRAW;

	ATOM nAtom = RegisterClassEx(&wce);
	if (0 == nAtom)
	{
		return FALSE;
	}
	return TRUE;
}

HWND CreateWnd(LPCSTR pszClassName)
{
	HWND hWnd = CreateWindowEx(0,pszClassName, "MyWnd",WS_OVERLAPPEDWINDOW, 
		0,0,500,500, NULL, NULL,g_hInst, 0);
	return hWnd;
}

void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}

void Message()
{
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

void NewConsole()
{
	AllocConsole();
	g_hStdOut =GetStdHandle(STD_OUTPUT_HANDLE);
}

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	NewConsole();
	g_hInst = hInstance;
	RegisterWnd("MYWND");
	HWND hWnd = CreateWnd("MYWND");
	DisplayWnd(hWnd);
	Message();
	return 0;
}



