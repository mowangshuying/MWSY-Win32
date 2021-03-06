#include <afxwin.h>

// 0x0400 - ox7FFF

UINT g_nRegMsg1 = RegisterWindowMessage("My_Reg_Msg1");
UINT g_nRegMsg2 = RegisterWindowMessage("My_Reg_Msg2");

class CMsgFrameWnd : public CFrameWnd
{
	//声名消息映射
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg LRESULT OnCreate(WPARAM wParam, LPARAM lParam);
	//afx_msg LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTest01();
	afx_msg void OnTest02_04(UINT nID);
	afx_msg void OnEnChange();
	//用户自定义消息
	afx_msg void OnTest05();
	afx_msg void OnTest06();
	afx_msg LRESULT OnResMsg1(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnResMsg2(WPARAM wParam, LPARAM lParam);
};

///本身窗口名称
BEGIN_MESSAGE_MAP(CMsgFrameWnd, CFrameWnd)
	//ON_MESSAGE(WM_CREATE, OnCreate)
	//ON_MESSAGE(WM_PAINT,OnPaint)
	ON_WM_CREATE()
	ON_COMMAND(1001,OnTest01)
	ON_COMMAND_RANGE(1002,1004,OnTest02_04)
	ON_EN_CHANGE(1005,OnEnChange)
	ON_REGISTERED_MESSAGE(g_nRegMsg1,OnResMsg1)
	ON_REGISTERED_MESSAGE(g_nRegMsg2, OnResMsg2)
	ON_COMMAND(1006,OnTest05)
	ON_COMMAND(1007, OnTest06)
END_MESSAGE_MAP()

int CMsgFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	//创建按钮
	CreateWindow("BUTTON", "TEST01", WS_CHILD | WS_VISIBLE, 50, 50, 200, 30,
		GetSafeHwnd(), HMENU(1001), AfxGetApp()->m_hInstance, NULL);

	///创建按钮
	CreateWindow("BUTTON", "TEST02", WS_CHILD | WS_VISIBLE, 50, 100, 200, 30,
		GetSafeHwnd(), HMENU(1002), AfxGetApp()->m_hInstance, NULL);
	CreateWindow("BUTTON", "TEST03", WS_CHILD | WS_VISIBLE, 50, 150, 200, 30,
		GetSafeHwnd(), HMENU(1003), AfxGetApp()->m_hInstance, NULL);
	CreateWindow("BUTTON", "TEST04", WS_CHILD | WS_VISIBLE, 50, 200, 200, 30,
		GetSafeHwnd(), HMENU(1004), AfxGetApp()->m_hInstance, NULL);

	//创建按钮
	CreateWindow("BUTTON", "TEST05", WS_CHILD | WS_VISIBLE, 50, 250, 200, 30,
		GetSafeHwnd(), HMENU(1006), AfxGetApp()->m_hInstance, NULL);

	CreateWindow("BUTTON", "TEST06", WS_CHILD | WS_VISIBLE, 50, 300, 200, 30,
		GetSafeHwnd(), HMENU(1007), AfxGetApp()->m_hInstance, NULL);

	//创建编辑框
	CreateWindow("EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER,300, 50, 200, 200,
		GetSafeHwnd(), HMENU(1005), AfxGetApp()->m_hInstance, NULL);

	return 1;
}

void CMsgFrameWnd::OnTest01()
{
	AfxMessageBox("OnTest01");
}

void CMsgFrameWnd::OnTest02_04(UINT nID)
{
	CString str;
	str.Format("Id = %d", nID);
	AfxMessageBox(str);
}

void CMsgFrameWnd::OnEnChange()
{
	//
	//AfxMessageBox("OnEnChange");
	CWnd* pWnd = GetDlgItem(1005);
	CString strText;
	pWnd->GetWindowText(strText);
	AfxMessageBox(strText);
}

void CMsgFrameWnd::OnTest05()
{
	//AfxMessageBox("OnTest05");
	SendMessage(g_nRegMsg1);
}

void CMsgFrameWnd::OnTest06()
{
	CString ws = "ws";
	CString ls = "ls";
	SendMessage(g_nRegMsg2, LPARAM(&ws), LPARAM(&ls));
	//ws = "ws_change";
}

LRESULT CMsgFrameWnd::OnResMsg1(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox("OnResMsg1");
	return 0;
}

LRESULT CMsgFrameWnd::OnResMsg2(WPARAM wParam, LPARAM lParam)
{
	//AfxMessageBox("OnResMsg");
	CString cs = *((CString*)(wParam));
	CString ls = *((CString*)(lParam));
	AfxMessageBox(cs + ls);
	return 0;
}

//LRESULT CMsgFrame::OnCreate(WPARAM wParam, LPARAM lParam)
//{
//	//AfxMessageBox("Create...");
//	return 0;
//}

//LRESULT CMsgFrame::OnPaint(WPARAM wParam, LPARAM lParam)
//{
//	//AfxMessageBox("Paint...");
//	PAINTSTRUCT ps = { 0 };
//	HDC hDC = ::BeginPaint(m_hWnd, &ps);
//	CHAR szText[] = "Hello,World";
//	TextOut(hDC, 100, 100, szText, strlen(szText));
//	::EndPaint(m_hWnd, &ps);
//	return 0;
//}

class CMsgApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

BOOL CMsgApp::InitInstance()
{
	//创建窗口
	CMsgFrameWnd* pWnd = new CMsgFrameWnd();
	
	pWnd->Create(NULL,"MsgApp");

	m_pMainWnd = pWnd;


	m_pMainWnd->MoveWindow(50, 50, 500, 500);

	//显示窗口
	m_pMainWnd->ShowWindow(SW_SHOW);

	//更新窗口
	m_pMainWnd->UpdateWindow();

	//返回值为真
	return TRUE;

}

//程序类
CMsgApp theApp;