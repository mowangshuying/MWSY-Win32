#pragma once

#include <afxwin.h>
#include <afxcmn.h>

#include "CDebugDlg.h"
#include "COutDlg.h"

class CMyDlg : public CDialog
{
public:
	CMyDlg();

	virtual void DoDataExchange(CDataExchange* pDx);

	virtual BOOL OnInitDialog();

	afx_msg void OnTcnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab;
	CDebugDlg m_DebugDlg;
	COutDlg m_OutDlg;
	CDialog* m_pDlg[2];
	int m_CurSelTab;
};