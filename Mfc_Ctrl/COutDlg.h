#pragma once

#include <afxwin.h>

// COutDlg 对话框

class COutDlg : public CDialog
{
	DECLARE_DYNAMIC(COutDlg)

public:
	COutDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~COutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OutDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
