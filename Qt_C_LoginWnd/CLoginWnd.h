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
	//构造函数
	CLoginWnd(QWidget* p = nullptr);
	//垂直布局
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