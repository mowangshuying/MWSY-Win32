#include "CMyApp.h"
#include "CMyDlg.h"

BOOL CMyApp::InitInstance()
{
	//����Ի���
	CMyDlg dlg;
	//����Ϊ������
	m_pMainWnd = &dlg;
	//ģ̬��ʾ
	dlg.DoModal();
	//��ӷ���ֵ
	return TRUE;
}