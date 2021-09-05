#include "CLoginWnd.h"


CLoginWnd::CLoginWnd(QWidget* p /*= nullptr*/) : QWidget(p)
{
	m_vLayout = new QVBoxLayout(this);
	m_hLayout1 = new QHBoxLayout(this);
	m_hLayout2 = new QHBoxLayout(this);
	m_hLayout3 = new QHBoxLayout(this);

	m_vLayout->addLayout(m_hLayout1);
	m_vLayout->addLayout(m_hLayout2);
	m_vLayout->addLayout(m_hLayout3);

	m_AccountLable = new QLabel(QString::fromLocal8Bit("ÕËºÅ:"));
	m_AccountEdit = new QLineEdit();
	m_hLayout1->addWidget(m_AccountLable);
	m_hLayout1->addWidget(m_AccountEdit);

	m_PasswordLable = new QLabel(QString::fromLocal8Bit("ÕËºÅ:"));
	m_PasswordEdit = new QLineEdit();
	m_hLayout2->addWidget(m_PasswordLable);
	m_hLayout2->addWidget(m_PasswordEdit);

	m_pRegBtn = new QPushButton(QString::fromLocal8Bit("×¢²á"));
	m_pLoginBtn = new QPushButton(QString::fromLocal8Bit("µÇÂ¼"));
	m_hLayout3->addWidget(m_pRegBtn);
	m_hLayout3->addWidget(m_pLoginBtn);

	this->setWindowTitle(QString::fromLocal8Bit("µÇÂ¼´°¿Ú"));
}

