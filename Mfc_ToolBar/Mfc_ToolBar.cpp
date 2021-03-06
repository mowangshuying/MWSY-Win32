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
	AfxMessageBox("������ʹ��!");
}

int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	CFrameWnd::OnCreate(lpCreateStruct);

	//����toolbar
	m_ToolBar.CreateEx(this);

	//���ع�������Դ
	m_ToolBar.LoadToolBar(IDR_TOOLBAR);

	//������֧��ͣ��
	m_ToolBar.EnableDocking(CBRS_ALIGN_TOP);

	//���֧��ͣ��
	this->EnableDocking(CBRS_ALIGN_TOP);

	//ͣ������
	DockControlBar(&m_ToolBar);

	return 0;
}

void CMyFrameWnd::OnShowTB()
{
	//��ʾ������
	this->ShowControlBar(&m_ToolBar, TRUE, TRUE);
}

void CMyFrameWnd::OnExitTB()
{
	//�رչ�����
	this->ShowControlBar(&m_ToolBar, FALSE, FALSE);
}

BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	//on_command ����˵�������������ť��Ϣ
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