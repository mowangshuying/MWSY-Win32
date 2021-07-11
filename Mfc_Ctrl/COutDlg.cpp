// COutDlg.cpp: 实现文件
//

#include <afxwin.h>
#include "COutDlg.h"
#include "resource.h"

// COutDlg 对话框

IMPLEMENT_DYNAMIC(COutDlg, CDialog)

COutDlg::COutDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_OutDlg, pParent)
{

}

COutDlg::~COutDlg()
{
}

void COutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COutDlg, CDialog)
END_MESSAGE_MAP()


// COutDlg 消息处理程序
