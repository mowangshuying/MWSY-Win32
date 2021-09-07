#include "QCommContactItemWnd.h"

QCommContactItemWnd::QCommContactItemWnd(QWidget* p)
	: QWidget(p)
{
	
}

QCommContactItemWnd::QCommContactItemWnd(QWidget* p, const char* headUrl, const char* name)
	:QWidget(p)
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
	m_hLayout->addWidget(m_headUrl);
	m_hLayout->addWidget(m_name);

	setFixedHeight(65);
	setObjectName("QCommContactItemWnd");
	setStyleSheet("#QCommContactItemWnd{border-bottom:1px solid red;}");
}

