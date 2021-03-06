#define  _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <CommCtrl.h>
#include "resource.h"

#pragma comment(lib,"ComCtl32.lib") 

HINSTANCE g_hInst = NULL;

HWND g_hwndTV = NULL;
HWND g_hWndMain = NULL;

HTREEITEM g_htItem = NULL;
  
int g_nOpen = 0;
int g_nClose = 0;

void InitImageList( )
{
	HIMAGELIST himl = NULL;
	HBITMAP hbmp = NULL;

	himl = ImageList_Create(16, 16, false, 2, 0);

	//加载位图
	hbmp = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_Open));
	g_nOpen = ImageList_Add(himl, hbmp, (HBITMAP)NULL);
	DeleteObject((HBITMAP)hbmp);
	hbmp = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_Close));
	g_nClose = ImageList_Add(himl, hbmp, (HBITMAP)NULL);
	DeleteObject((HBITMAP)hbmp);
	TreeView_SetImageList(g_hwndTV, himl, TVSIL_NORMAL);
}

void DisplayContextMenu(HWND hWnd, POINT point)
{
	HMENU hMenu = LoadMenu(g_hInst, MAKEINTRESOURCE(IDR_PopMenu));
	HMENU hPopMenu = GetSubMenu(hMenu, 0);
	TrackPopupMenuEx(hPopMenu, TPM_LEFTALIGN, point.x, point.y, hWnd, NULL);
	DestroyMenu(hMenu);
}

void OnRClickTree(LPNMHDR pNmhdr)
{
	POINT point;
	TVHITTESTINFO thti;
	//HTREEITEM htItem;

	GetCursorPos(&point);

	ScreenToClient(g_hwndTV, &point);
	thti.pt = point;
	thti.flags = TVHT_TORIGHT;

	g_htItem = TreeView_HitTest(g_hwndTV, &thti);
	if (g_htItem != NULL)
	{
		ClientToScreen(g_hwndTV,&point);
		TreeView_SelectItem(g_hwndTV, g_htItem);
		DisplayContextMenu(g_hWndMain,point);
	}

}

HTREEITEM AddItemToTree(HWND hwndTV,LPSTR lpszItem,HTREEITEM hParent)
{
	TVITEM tvi;
	TVINSERTSTRUCT tvins;
	HTREEITEM hme;
	//设置ITEM的参数
	tvi.mask = TVIF_TEXT | TVIF_IMAGE  | TVIF_PARAM | TVIF_SELECTEDIMAGE ;
	tvi.pszText = lpszItem;
	tvi.iImage = g_nClose;
	tvi.iSelectedImage = g_nOpen;
	tvi.cchTextMax = 20;
	//填充STRUCT结构
	tvins.item = tvi;
	tvins.hInsertAfter = TVI_ROOT;
	if (hParent == NULL)
	{
		tvins.hParent = TVI_ROOT;
	}
	else
	{
		tvins.hParent = hParent;
	}
	//调用关键的TreeView_InsertItem函数
	hme = TreeView_InsertItem(hwndTV, &tvins);
	return hme;
}

void OnCommand(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
			case ID_Add:
			{
				//MessageBox(NULL, "id_add", "mbox", MB_OK);
				char pBuf1[20] = "add child";
				AddItemToTree(g_hwndTV, pBuf1, g_htItem);
			}
			break;
			case ID_Del:
			{
				TreeView_DeleteItem(g_hwndTV, g_htItem);
			}
			break;
			case ID_Chx:
			{
				TVITEM tvitem;
				tvitem.mask = TVIF_TEXT /*| TVIF_IMAGE*/ | TVIF_PARAM;
				tvitem.hItem = g_htItem;
				TreeView_GetItem(g_hwndTV, &tvitem);
				char pBuf[120] = "chx";
				tvitem.pszText = pBuf;
				TreeView_SetItem(g_hwndTV, &tvitem);
				break;
			}
	default:
		break;
	}
}

void OnCreate(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	g_hwndTV = CreateWindowEx(0,WC_TREEVIEW,TEXT("Tree View"),WS_VISIBLE | WS_CHILD | WS_BORDER  | TVS_FULLROWSELECT /*| WS_SIZEBOX*/,
		0,0,200,400,hWnd,(HMENU)(1001),g_hInst,NULL);

	InitImageList();

	//添加根部节点
	char pBuf1[20] = "root";
	HTREEITEM hRoot = AddItemToTree(g_hwndTV,pBuf1, NULL);
	strcpy(pBuf1, "root1");
	auto hRoot1 = AddItemToTree(g_hwndTV, pBuf1, hRoot);
	strcpy(pBuf1, "root11");
	AddItemToTree(g_hwndTV, pBuf1, hRoot1);
	strcpy(pBuf1, "root12");
	AddItemToTree(g_hwndTV, pBuf1, hRoot1);
	strcpy(pBuf1, "root2");
	AddItemToTree(g_hwndTV, pBuf1, hRoot);
}

void OnNotify(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//MessageBox(NULL, "notify", "notify", MB_OK);
	LPNMHDR pNmhdr = (LPNMHDR)lParam;
	//
	if (pNmhdr == NULL)
	{
		return;
	}
	//
	if (pNmhdr->hwndFrom != g_hwndTV)
	{
		return;
	}

	switch (pNmhdr->code)
	{
	case NM_RCLICK:
		OnRClickTree(pNmhdr);
		break;
	default:
		break;
	}
}

void OnSize(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	///获取客户区的高度
	//int nWidth = LOWORD(lParam);
	int nHight = HIWORD(lParam);
	if (g_hwndTV)
	{
		MoveWindow(g_hwndTV, 0, 0, 150, nHight, true);
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
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_NOTIFY:
		OnNotify(hWnd, uMsg, wParam, lParam);
		break;
	case WM_SIZE:
		OnSize(hWnd, uMsg, wParam, lParam);
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
	//保存程序实例句柄
	g_hInst = hInstance;
	 g_hWndMain = NULL;
	MyRegister("MyWnd");
	g_hWndMain = MyCreate("MyWnd");
	DisplayWnd(g_hWndMain);
	Message();
	return 0;
}