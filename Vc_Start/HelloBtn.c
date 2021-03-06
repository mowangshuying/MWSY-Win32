#include <windows.h>


HINSTANCE g_hInst = NULL;

//2 ���ڴ�����
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

//3 ע�ᴰ������
//BOOL MyRegister(LPSTR pszClassName)
//{
//	WNDCLASS wc = { 0 };
//	ATOM  nAtom = 0;
//
//	wc.style = CS_VREDRAW | CS_HREDRAW;
//	wc.lpfnWndProc = WindowProc;
//	wc.cbClsExtra = 0;//�����฽������
//	wc.cbWndExtra = 0;//���ڸ�������
//	wc.hInstance = g_hInst;//����ʵ�����
//	//wc.hIcon = NULL;
//	wc.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(100));
//	wc.hCursor = NULL;
//	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE);//���ڻ�ˢ
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

//4 ���ڴ���
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

//5 ��ʾ����
void DisplayWnd(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
}

//6 ��Ϣ����
void Message()
{
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}
}

//1 ��ں���
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
* 1������ico�ļ�
* 2�������ű��ļ�
*/