#include "CMyApp.h"
#include "CMyDlg.h"

BOOL CMyApp::InitInstance()
{
	//定义对话框
	CMyDlg dlg;
	//保存为主窗口
	m_pMainWnd = &dlg;
	//模态显示
	dlg.DoModal();
	//添加返回值
	return TRUE;
}