#include "QCommMsgItemWnd.h"

#include <string>

QCommMsgItemWnd::QCommMsgItemWnd(QWidget* p) 
	: QWidget(p)
{
	//m_vLayout = new QVBoxLayout();

	//m_hLayout= new QHBoxLayout();
	//m_name = new QLabel();
	//m_msg = new QLabel();

	////m_name->setAttribute(Qt::WA_StyledBackground);

	//m_name->setText(QString::fromLocal8Bit("苏果超市便民服务..."));
	//m_msg->setText(QString::fromLocal8Bit("[2条]_小鑫鑫:[小程序]..."));
	//m_msg->setStyleSheet("border-bottom:1px solid gray;");
	//m_vLayout->addWidget(m_name);
	//m_vLayout->addWidget(m_msg);
	//
	//m_headurl = new QLabel();
	//m_headurl->setFixedSize(40, 40);
	//m_headurl->setPixmap(QPixmap("./img/head1.png"));

	////m_headurl->setStyleSheet("border-left:0px;");

	//m_hLayout->addWidget(m_headurl);
	//m_hLayout->addLayout(m_vLayout);

	//m_vLayout->setContentsMargins(0, 0, 0, 0);
	//m_vLayout->setSpacing(0);

	//m_hLayout->setContentsMargins(0, 0, 0, 0);
	//m_hLayout->setSpacing(0);

	//setLayout(m_hLayout);
	//setFixedHeight(65);
	//setObjectName("QCommMsgItemWnd");
	//setStyleSheet("#QCommMsgItemWnd{border-bottom:1px solid gray;}");
}

QCommMsgItemWnd::QCommMsgItemWnd(QWidget* p,const char*  headUrl, const char* name, const char* msg)
{
	m_vLayout = new QVBoxLayout();
	m_hLayout = new QHBoxLayout();
	m_name = new QLabel();
	m_msg = new QLabel();

	m_name->setText(QString::fromLocal8Bit(name));
	m_msg->setText(QString::fromLocal8Bit(msg));
	m_msg->setStyleSheet("border-bottom:1px solid gray;");

	//m_msg->setStyleSheet("border:1px solid gray;");
	//m_name->setStyleSheet("border:1px solid gray;");

	m_vLayout->addSpacing(10);
	m_vLayout->addWidget(m_name);
	m_vLayout->addWidget(m_msg);
	m_vLayout->addSpacing(10);

	m_headurl = new QLabel();
	m_headurl->setFixedSize(40, 40);
	m_headurl->setPixmap(QPixmap(headUrl));

	//m_headurl->setStyleSheet("border-left:0px;");

	m_hLayout->addWidget(m_headurl);
	m_hLayout->addLayout(m_vLayout);

	m_vLayout->setContentsMargins(5, 0, 0, 0);
	m_vLayout->setSpacing(0);

	m_hLayout->setContentsMargins(0, 0, 0, 0);
	m_hLayout->setSpacing(0);

	setLayout(m_hLayout);
	setFixedHeight(65);
	setObjectName("QCommMsgItemWnd");
	setStyleSheet("#QCommMsgItemWnd{border-bottom:1px solid red;}");
	//setStyleSheet("#QCommMsgItemWnd{border:1px solid red;}");
}

