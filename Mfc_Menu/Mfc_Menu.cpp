#include <afxwin.h>
#include "resource.h"
//框架窗口类
class CMyFrameWnd : public CFrameWnd
{
public:
	afx_msg void OnExit();
public:
	DECLARE_MESSAGE_MAP();
};

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_COMMAND(ID_Exit,OnExit)
END_MESSAGE_MAP()

void CMyFrameWnd::OnExit()
{
	//AfxMessageBox("OnExit");
	PostQuitMessage(0);
}

//应用程序类
class CMyApp : public CWinApp
{
public:
	CMyApp();
	virtual BOOL InitInstance()
	{
		//AfxMessageBox("Hello App");

	//定义窗口对象
		CMyFrameWnd* pWnd = new CMyFrameWnd();

		//创建窗口
		pWnd->Create(NULL, "Mfc_Menu",WS_OVERLAPPEDWINDOW,
			CFrameWnd::rectDefault,NULL,MAKEINTRESOURCE(IDR_MENU));

		//显示窗口
		pWnd->ShowWindow(SW_SHOW);

		//设置主窗口
		m_pMainWnd = pWnd;

		m_pMainWnd->MoveWindow(50, 50, 500, 500);

		//返回值为真
		return TRUE;
	}
};

CMyApp::CMyApp()
{

}

//定义CMyApp的全局变量
CMyApp theApp;