#include "QFindFriendItemWnd.h"

QFindFriendItemWnd::QFindFriendItemWnd(QWidget* p)
	: QWidget(p)
{

}

QFindFriendItemWnd::QFindFriendItemWnd(QWidget* p, const char* headUrl, const char* name)
	: QWidget(p)
{
	m_hLayout = new QHBoxLayout(this);
	//m_hLayout->setContentsMargins(0, 10, 0, 10);
	m_hLayout->setSpacing(0);
	setLayout(m_hLayout);
	m_headUrl = new QLabel();
	//m_headUrl->setPixmap(QPixmap("./img/head2.png"));
	m_headUrl->setPixmap(QPixmap(headUrl));
	m_headUrl->setFixedSize(40, 40);
	m_name = new QLabel();
	//m_name->setText(QString::fromLocal8Bit("ÐÂµÄÅóÓÑ"));
	m_name->setText(QString::fromLocal8Bit(name));
	
	m_hLayout->addSpacing(50);
	m_hLayout->addWidget(m_headUrl);
	m_hLayout->addWidget(m_name);

	m_hLayout->addStretch();
	m_addFriendBtn = new QPushButton();
	m_addFriendBtn->setText(QString::fromLocal8Bit("+ ºÃÓÑ"));
	m_addFriendBtn->setFixedSize(60,30);
	m_hLayout->addWidget(m_addFriendBtn);
	m_hLayout->addSpacing(80); 


	//m_nextWnd = new QNextWnd();
	//m_nextWnd->hide();

	m_addFriendBtn->setStyleSheet("background-color:#1aad19;border-style: none;");

	setFixedHeight(65);
	setObjectName("QCommContactItemWnd");
	setStyleSheet("#QCommContactItemWnd{border-bottom:1px solid red;}");

	connect(m_addFriendBtn, SIGNAL(clicked()), this, SLOT(slot_addFriendBtnClick()));

}

void QFindFriendItemWnd::slot_addFriendBtnClick()
{
	m_nextWnd = new QNextWnd();
	m_nextWnd->show();
}

