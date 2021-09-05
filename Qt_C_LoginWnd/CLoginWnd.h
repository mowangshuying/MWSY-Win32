#pragma once

#include<Qwidget>

#include<QHBoxLayout>
#include<QVBoxLayout>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class CLoginWnd : public QWidget
{
public:
	//���캯��
	CLoginWnd(QWidget* p = nullptr);
	//��ֱ����
public:
	QVBoxLayout* m_vLayout;
	QHBoxLayout* m_hLayout1;
	QHBoxLayout* m_hLayout2;
	QHBoxLayout* m_hLayout3;

	QLabel* m_AccountLable;
	QLineEdit* m_AccountEdit;

	QLabel* m_PasswordLable;
	QLineEdit* m_PasswordEdit;

	QPushButton* m_pRegBtn;
	QPushButton* m_pLoginBtn;
};