#include <afxwin.h>

#include "resource.h"

class CMyDlg : public CDialog
{
public:
	CMyDlg();
	///对化框数据交换函数
	virtual void DoDataExchange(CDataExchange* pDx);

	DECLARE_MESSAGE_MAP()

	afx_msg void OnButton1();

public:
	//用于与编辑框idc_edit绑定
	CString m_strText;
	//用于绑定窗口句柄
	CWnd m_WndButton1;
};

CMyDlg::CMyDlg() :
	CDialog(IDD_DIALOG1)
{
	m_strText = "Hell0 DDX!";
}

void CMyDlg::DoDataExchange(CDataExchange* pDx)
{
	//父类方法
	CDialog::DoDataExchange(pDx);
	//绑定
	DDX_Text(pDx, IDC_EDIT1, m_strText);
	//GetDlgItem()
	DDX_Control(pDx, IDC_BUTTON1, m_WndButton1);
}



void CMyDlg::OnButton1()
{
	UpdateData( TRUE );
	AfxMessageBox(m_strText);
	m_WndButton1.GetWindowText(m_strText);
	UpdateData(FALSE);
}

BEGIN_MESSAGE_MAP(CMyDlg,CDialog)
	ON_COMMAND(IDC_BUTTON1,OnButton1)
END_MESSAGE_MAP()

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

BOOL CMyApp::InitInstance()
{
	CMyDlg* pDlg = new CMyDlg();

	m_pMainWnd = pDlg;

	pDlg->DoModal();

	return TRUE;
}

CMyApp theApp;