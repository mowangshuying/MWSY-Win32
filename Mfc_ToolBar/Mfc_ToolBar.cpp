#include <afxwin.h>
#include <afxext.h>
#include "resource.h"

class CMyFrameWnd : public CFrameWnd
{
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnExit();
	afx_msg void OnAbount();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnShowTB();
	afx_msg void OnExitTB();
public:
	CToolBar m_ToolBar;
};

BOOL CMyFrameWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	CFrameWnd::PreCreateWindow(cs);

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;

	return TRUE;
}

void CMyFrameWnd::OnExit()
{
	PostQuitMessage(0);
}

void CMyFrameWnd::OnAbount()
{
	AfxMessageBox("工具栏使用!");
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CFrameWnd::OnCreate(lpCreateStruct);

	//创建toolbar
	m_ToolBar.CreateEx(this);

	//加载工具栏资源
	m_ToolBar.LoadToolBar(IDR_TOOLBAR);

	//工具栏支持停靠
	m_ToolBar.EnableDocking(CBRS_ALIGN_TOP);

	//框架支持停靠
	this->EnableDocking(CBRS_ALIGN_TOP);

	//停靠窗口
	DockControlBar(&m_ToolBar);

	return 0;
}

void CMyFrameWnd::OnShowTB()
{
	//显示工具栏
	this->ShowControlBar(&m_ToolBar, TRUE, TRUE);
}

void CMyFrameWnd::OnExitTB()
{
	//关闭工具栏
	this->ShowControlBar(&m_ToolBar, FALSE, FALSE);
}

BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	//on_command 处理菜单，工具栏，按钮消息
	ON_COMMAND(ID_Exit,OnExit)
	ON_COMMAND(ID_About, OnAbount)
	ON_COMMAND(ID_ShowTB, OnShowTB)
	ON_COMMAND(ID_ExitTB, OnExitTB)
	ON_WM_CREATE()
END_MESSAGE_MAP()


class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

BOOL CMyApp::InitInstance()
{
	CMyFrameWnd* pWnd = new CMyFrameWnd();

	pWnd->Create(NULL, "CMyFrameWnd", WS_OVERLAPPEDWINDOW,
		CFrameWnd::rectDefault, NULL, MAKEINTRESOURCE(IDR_MENU));

	pWnd->ShowWindow(SW_SHOW);

	pWnd->UpdateWindow();

	m_pMainWnd = pWnd;

	m_pMainWnd->MoveWindow(50, 50, 500, 500);

	return TRUE;
}

CMyApp theApp;