#pragma once

#include <afxwin.h>

// CDebugDlg 对话框

class CDebugDlg : public CDialog
{
	DECLARE_DYNAMIC(CDebugDlg)

public:
	CDebugDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDebugDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DebugDlg };
#endif

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void OnSize(UINT nType, int cx, int cy);

	virtual BOOL OnInitDialog();

	CStatic m_DebugStaic;
};
