#include "resource.h"

#include "CMyDlg.h"

CMyDlg::CMyDlg() : CDialog(IDD_Dlg)
{

}

void CMyDlg::DoDataExchange(CDataExchange* pDx)
{
	CDialog::DoDataExchange(pDx);

	DDX_Control(pDx, IDC_TAB, m_Tab);
}

BOOL CMyDlg::OnInitDialog()
{
	if (CDialog::OnInitDialog() == FALSE)
	{
		return FALSE;
	}

	m_Tab.InsertItem(0, "调试");
	m_Tab.InsertItem(1, "输出");

	m_DebugDlg.Create(IDD_DebugDlg, &m_Tab);
	m_OutDlg.Create(IDD_OutDlg, &m_Tab);

	CRect rc;
	m_Tab.GetClientRect(rc);
	//rc.top += 30;
	//rc.left += 30;
	//rc.right -= 30;
	rc.bottom -= 30;

	m_DebugDlg.MoveWindow(&rc);
	m_OutDlg.MoveWindow(&rc);

	m_pDlg[0] = &m_DebugDlg;
	m_pDlg[1] = &m_OutDlg;

	m_pDlg[0]->ShowWindow(SW_SHOW);
	m_pDlg[1]->ShowWindow(SW_HIDE);

	m_CurSelTab = 0;

	return TRUE;
}


void CMyDlg::OnTcnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult)
{//实现窗口切换
	int curSel = m_Tab.GetCurSel();
	switch (curSel)
	{
	case 0:
	{
		m_pDlg[0]->ShowWindow(SW_SHOW);
		m_pDlg[1]->ShowWindow(SW_HIDE);
	}
	break;
	case 1:
	{
		m_pDlg[0]->ShowWindow(SW_HIDE);
		m_pDlg[1]->ShowWindow(SW_SHOW);
	}
	break;
	default:
		break;
	}
}

BEGIN_MESSAGE_MAP(CMyDlg,CDialog)
	ON_NOTIFY(TCN_SELCHANGE,IDC_TAB,OnTcnSelchangeTab)
END_MESSAGE_MAP()