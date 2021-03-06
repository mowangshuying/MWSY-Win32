#include <windows.h>
#include <CommCtrl.h>

//#pragma comment(lib,"ComCtl32.lib") 

HINSTANCE g_hInst = NULL;

HWND g_hListViewWnd = NULL;

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
	//INITCOMMONCONTROLSEX icex;
	//icex.dwICC = ICC_LISTVIEW_CLASSES;
	//InitCommonControlsEx(&icex);

	//InitCommonControls();

	RECT rc;
	GetClientRect(hWnd, &rc);
	
	g_hListViewWnd = CreateWindow(WC_LISTVIEW, "", WS_CHILD | LVS_REPORT | LVS_EDITLABELS | WS_VISIBLE | WS_BORDER | LVS_AUTOARRANGE, 0, 0,
		rc.right - rc.left, rc.bottom - rc.top, hWnd, HMENU(9001), g_hInst, NULL);

	//添加列表项
	char pSzbuf1[10] = "list_0";
	for (int i = 0; i < 5; i++)
	{
		LVCOLUMN lvc;
		lvc.mask = LVCF_WIDTH | LVCF_FMT | LVCF_TEXT | LVCF_SUBITEM;
		lvc.iSubItem = i;
		pSzbuf1[5] += 1;
		lvc.pszText = pSzbuf1;
		lvc.cx = 100;
		lvc.fmt = LVCFMT_LEFT;
		if (-1 == ListView_InsertColumn(g_hListViewWnd, i, &lvc))
		{
			MessageBox(NULL, "ListView_InsertColumn Error!", "Error", MB_OK);
		}
	}

	//ListView_SetItemCount(hListViewWnd, 100);

	//设置当前项目
	char pSzBuf2[20] = "item=1";
	char pSzBuf3[20] = "item=1;column=1";
	LVITEM lvi = { 0 };
	lvi.iItem = 0;
	lvi.mask = LVCF_TEXT ;
	//lvi.pszText = pSzBuf2;
	if (-1 == ListView_InsertItem(g_hListViewWnd, &lvi))
	{
		MessageBox(NULL, "ListView_InsertItem Error!", "Error", MB_OK);
	}
	ListView_SetItemText(g_hListViewWnd, 0, 0, pSzBuf2);

	for (int i = 0; i < 4; i++)
	{
		pSzBuf3[14] += 1;
		//
		ListView_SetItemText(g_hListViewWnd, 0, i+1, pSzBuf3);
	}

}

void OnSize(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int nWidth = LOWORD(lParam);
	int nHight = HIWORD(lParam);

	if (g_hListViewWnd)
	{
		MoveWindow(g_hListViewWnd, 0, 0, nWidth, nHight, true);
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
	case WM_SIZE:
		OnSize(hWnd, uMsg, wParam, lParam);
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
	wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 3);//窗口画刷
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