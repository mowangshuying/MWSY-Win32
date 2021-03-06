#include <windows.h>

HINSTANCE g_hInst = NULL;

HWND g_hMyWnd1 = NULL;
HWND g_hMyWnd2 = NULL;

void OnCommand(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	default:
		break;
	}
}

void OnCreate(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	g_hMyWnd2 = CreateWindow("MyWnd2", "HelloWnd", WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 100,200, 100, hWnd, HMENU(1001), g_hInst, NULL);
	//int errcode = SetDlgItemText(hWnd, 1001, "self-winchild");
	//char pBuf[20];
	//_itoa_s(errcode, pBuf, 10);
	//MessageBox(NULL, pBuf, "msgbox", MB_OK);
	//UpdateWindow(hMyWnd2);
	
	//SetWindowText(hWnd, "hMyWnd2");

	//TextOut()
}

LRESULT CALLBACK WindowProc1(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
	case WM_KEYDOWN:
		MessageBox(NULL, " windowproc1 keydown", "msgbox", MB_OK);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(NULL, "wnd1-lbtn-down", "msgbox", MB_OK);
		break;
	case WM_RBUTTONDOWN:
		MessageBox(NULL, "wnd1-rbtn-down", "msgbox", MB_OK);
		break;

	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK WindowProc2(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
		{
			MessageBox(NULL, "windowproc2 create", "msgbox", MB_OK);
			break;
		}
		case WM_COMMAND:
		{
			MessageBox(NULL, " windowproc2 commod", "msgbox", MB_OK);
			break;
		}
		case WM_DESTROY:
		{
			MessageBox(NULL, " windowproc2 destroy", "msgbox", MB_OK);
			break;
		}
		case WM_KEYDOWN:
		{
			//MessageBox(NULL, " windowproc2 keydown", "msgbox", MB_OK);
			break;
		}
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			char pBuf1[128] = "wnd2-painting-line-1";
			//Rectangle(hdc, 0, 0, 25, 50);
			//COLORREF color1 = RGB(0, 255, 0);
			//COLORREF color2 = RGB(255, 0, 0);
			//::SetTextColor(hdc, color1);
			//::SetBkColor(hdc, color2);
			TextOut(hdc, 0, 0, pBuf1, strlen(pBuf1));
			//��ȡdc���ַ����
			TEXTMETRIC textMetric;
			//
			GetTextMetrics(hdc, &textMetric);
			//
			int h = textMetric.tmHeight;
			//
			char pBuf2[128] = "wnd2-painting-line-2";
			TextOut(hdc, 0, 0 + h, pBuf2,strlen(pBuf2));

			EndPaint(hWnd, &ps);

			//����ѭ��
			break;
		}
		case WM_LBUTTONDOWN:
		{
			//MessageBox(NULL, "wnd2-lbtn-down", "msgbox", MB_OK);
			SetFocus(hWnd);
			break;
		}
		case WM_RBUTTONDOWN:
		{
			//MessageBox(NULL, "wnd2-rbtn-down", "msgbox", MB_OK);
			break;
		}
		default:
		{
			break;
		}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

BOOL MyRegister(LPCSTR pszClassName,WNDPROC wndProc,int br = COLOR_BTNFACE)
{
	WNDCLASS wc = { 0 };
	ATOM  nAtom = 0;

	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = wndProc;
	wc.cbClsExtra = 0;//�����฽������
	wc.cbWndExtra = 0;//���ڸ�������
	wc.hInstance = g_hInst;//����ʵ�����
	//wc.hIcon = NULL;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	//wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE);//���ڻ�ˢ
	wc.hbrBackground = (HBRUSH)(br);
	wc.lpszMenuName = MAKEINTRESOURCE(101);
	wc.lpszClassName = pszClassName;

	nAtom = RegisterClass(&wc);
	if (0 == nAtom)
	{
		MessageBox(NULL, "Register Failed", "Error", MB_OK | MB_ICONWARNING);
		return FALSE;
	}
	return TRUE;
}

HWND MyCreate(LPCSTR pszClassName)
{
	HWND hWnd = CreateWindow(pszClassName, "HelloWnd", WS_OVERLAPPEDWINDOW , 100, 100, 500, 500, NULL,NULL, g_hInst, NULL);
	if (NULL == hWnd)
	{
		MessageBox(NULL, "CreateWnd Failed", "Error", MB_OK);
		return NULL;
	}
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
		//ת����Ϣ
		TranslateMessage(&msg);
		if (msg.message == WM_KEYDOWN /*|| msg.message == WM_LBUTTONDOWN*/)
		{
			//
			HWND hWnd = msg.hwnd;
		}
		//�ɷ���Ϣ
		DispatchMessage(&msg);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//ע�ᴰ����1
	MyRegister("MyWnd1",WindowProc1);
	//ע�ᴰ����2
	MyRegister("MyWnd2", WindowProc2, COLOR_BTNFACE+1);
	//��������1��Ϊ������
	g_hMyWnd1 = MyCreate("MyWnd1");
	//��ʾ����
	DisplayWnd(g_hMyWnd1);
	//��Ϣѭ��
	Message();
	//����ֵΪ��
	return 0;
}