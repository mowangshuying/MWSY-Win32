#include <afxwin.h>

//框架窗口类
class CMyFrameWnd : public CFrameWnd
{
public:
	///*virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
	//{
	//	switch (message)
	//	{
	//	case WM_CREATE:
	//		AfxMessageBox("Create...");
	//		break;
	//	case WM_PAINT:
	//		{
	//			PAINTSTRUCT ps = { 0 };
	//			HDC hDC = ::BeginPaint(m_hWnd, &ps);
	//			
	//			CHAR szText[] = "Hello,World";
	//			TextOut(hDC, 100, 100,szText, strlen(szText));

	//			::EndPaint(m_hWnd, &ps);
	//		}
	//		break;
	//	default:
	//		break;
	//	}
	//	return CFrameWnd::WindowProc(message, wParam, lParam);
	//}*/
public:
	afx_msg LRESULT OnPaint(WPARAM wParam, LPARAM lParam);
public:
	DECLARE_MESSAGE_MAP();
};

LRESULT CMyFrameWnd::OnPaint(WPARAM wParam,LPARAM lParam)
{
	PAINTSTRUCT ps = { 0 };
	HDC hDC = ::BeginPaint(m_hWnd, &ps);
	CHAR szText[] = "Hello,World";
	TextOut(hDC, 100, 100,szText, strlen(szText));
	::EndPaint(m_hWnd, &ps);
	return 0;
}

BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_MESSAGE(WM_PAINT,OnPaint)
END_MESSAGE_MAP()

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
		pWnd->Create(NULL, "Mfc_First");

		//显示窗口
		pWnd->ShowWindow(SW_SHOW);

		//设置主窗口
		m_pMainWnd = pWnd;

		//返回值为真
		return TRUE;
	}
};

CMyApp::CMyApp()
{

}

//定义CMyApp的全局变量
CMyApp theApp;