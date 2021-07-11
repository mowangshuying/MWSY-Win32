#include <windows.h>

HINSTANCE g_hInst = NULL;


//2-1-�����˵�����
VOID OnCommand(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
		case 1001:
		{
			MessageBox(NULL, "����", "messgaebox", MB_OK);
			break;
		}
		case 1002:
		{
			PostQuitMessage(0);
			break;
		}
	default:
		break;
	}
}

//2-1 �������ڴ�������
VOID OnCreate(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

}

void OnRButtonUp(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// ��������ʽ�˵�
	HMENU hPopMenu = CreatePopupMenu();
	// ���Ӳ˵���
	AppendMenu(hPopMenu, MF_STRING, 1001, "����1");
	AppendMenu(hPopMenu, MF_SEPARATOR, 0, NULL);//
	AppendMenu(hPopMenu, MF_STRING, 1002, "�˳�");
	// ��ȡ�˵�λ��
	POINT point = { 0 };
	point.x = LOWORD(lParam);
	point.y = HIWORD(lParam);
	ClientToScreen(hWnd, &point);
	// ��ʾ�˵�
	TrackPopupMenu(hPopMenu, TPM_LEFTALIGN,
		point.x, point.y, 0, hWnd, NULL);
}


//2 ���ڴ�������
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
	case WM_RBUTTONUP:
		OnRButtonUp(hWnd, uMsg, wParam, lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//3 ע�ᴰ������
BOOL MyRegister(LPCSTR pszClassName)
{
	WNDCLASS wc = { 0 };
	ATOM  nAtom = 0;

	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.cbClsExtra = 0;//�����฽������
	wc.cbWndExtra = 0;//���ڸ�������
	wc.hInstance = g_hInst;//����ʵ�����
	//wc.hIcon = NULL;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE);//���ڻ�ˢ
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

//4 ���ڴ���
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
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	HWND hWnd = NULL;
	MyRegister("MyWnd");
	hWnd = MyCreate("MyWnd");
	DisplayWnd(hWnd);
	Message();
	return 0;
}