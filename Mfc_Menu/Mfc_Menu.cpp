#include <afxwin.h>
#include "resource.h"
//��ܴ�����
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
		pWnd->Create(NULL, "Mfc_Menu",WS_OVERLAPPEDWINDOW,
			CFrameWnd::rectDefault,NULL,MAKEINTRESOURCE(IDR_MENU));

		//��ʾ����
		pWnd->ShowWindow(SW_SHOW);

		//����������
		m_pMainWnd = pWnd;

		m_pMainWnd->MoveWindow(50, 50, 500, 500);

		//����ֵΪ��
		return TRUE;
	}
};

CMyApp::CMyApp()
{

}

//����CMyApp��ȫ�ֱ���
CMyApp theApp;