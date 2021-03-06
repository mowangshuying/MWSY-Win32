#include <afxwin.h>

//��ܴ�����
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

//Ӧ�ó�����
class CMyApp : public CWinApp
{
public:
	CMyApp();
	virtual BOOL InitInstance()
	{
		//AfxMessageBox("Hello App");

	//���崰�ڶ���
		CMyFrameWnd* pWnd = new CMyFrameWnd();

		//��������
		pWnd->Create(NULL, "Mfc_First");

		//��ʾ����
		pWnd->ShowWindow(SW_SHOW);

		//����������
		m_pMainWnd = pWnd;

		//����ֵΪ��
		return TRUE;
	}
};

CMyApp::CMyApp()
{

}

//����CMyApp��ȫ�ֱ���
CMyApp theApp;