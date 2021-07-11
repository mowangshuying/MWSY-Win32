// CDebugDlg.cpp: 实现文件
//

#include <afxwin.h>
#include "CDebugDlg.h"
#include "resource.h"

// CDebugDlg 对话框

IMPLEMENT_DYNAMIC(CDebugDlg, CDialog)

CDebugDlg::CDebugDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DebugDlg, pParent)
{

}

CDebugDlg::~CDebugDlg()
{
}

void CDebugDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DebugSTIC, m_DebugStaic);
}


void CDebugDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	//
	CWnd* pWnd = this->GetDlgItem(IDC_DebugSTIC);
	//
	if (pWnd != NULL)
	{
		CRect sR;
		//m_DebugStaic.GetClientRect(sR);
		pWnd->GetClientRect(sR);
		//
		CRect sD;
		GetClientRect(sD);
		//
		pWnd->MoveWindow(sD.CenterPoint().x, sD.CenterPoint().y, sR.Width(), sR.Height());
	}
}

BOOL CDebugDlg::OnInitDialog()
{
	if (CDialog::OnInitDialog() == FALSE)
	{
		return FALSE;
	}
	//CRect rc(50, 50, 100, 100);
	//if (m_DebugStaic.m_hWnd != NULL)
	//{
	//	m_DebugStaic.Create("", WS_CHILD | WS_VISIBLE, rc, this);
	//}
	return TRUE;
}

BEGIN_MESSAGE_MAP(CDebugDlg, CDialog)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDebugDlg 消息处理程序


