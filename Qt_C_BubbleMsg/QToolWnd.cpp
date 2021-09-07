#include "QToolWnd.h"

QToolWnd::QToolWnd(QWidget* p /*= nullptr*/)
	: QWidget(p)
{
	setFixedWidth(55);
	setWindowFlags(Qt::FramelessWindowHint);
	//setObjectName("QToolWnd");
	setStyleSheet("background-color:#2E2E2E;");
	//脱离父窗口的样式控制
	setAttribute(Qt::WA_StyledBackground);

	m_vBoxLayout = new QVBoxLayout(this);
	m_headUrlLabel = new QLabel(QString::fromLocal8Bit("头像"));
	m_headUrlLabel->setFixedSize(40, 40);
	m_headUrlLabel->setStyleSheet("background-color:white;");
	
	m_msgBtn = new QPushButton(this);
	m_msgBtn->setFixedSize(30, 30);
	m_msgBtn->setIconSize(QSize(30, 30));
	m_msgBtn->setIcon(QPixmap("./img/msgBtnNormal.png"));

	m_contactsBtn = new QPushButton(this);
	m_contactsBtn->setFixedSize(30, 30);
	m_contactsBtn->setIconSize(QSize(30, 30));
	m_contactsBtn->setIcon(QPixmap("./img/contactsBtnNomal.png"));
	
	m_vBoxLayout->setAlignment(Qt::AlignCenter);
	m_vBoxLayout->setContentsMargins(0, 20, 0, 0);
	m_vBoxLayout->addWidget(m_headUrlLabel);
	m_vBoxLayout->addSpacing(15);
	m_vBoxLayout->addWidget(m_msgBtn);
	m_vBoxLayout->addSpacing(15);
	m_vBoxLayout->addWidget(m_contactsBtn);
	m_vBoxLayout->addStretch();

	setLayout(m_vBoxLayout);


	m_btnVct.push_back(m_msgBtn);
	m_btnVct.push_back(m_contactsBtn);
	m_selectIndex = 0;

	connect(m_msgBtn, SIGNAL(clicked()), this, SLOT(onClickMsgBtn()));
	connect(m_contactsBtn, SIGNAL(clicked()), this, SLOT(onClickContactsBtn()));
}

void QToolWnd::onClickMsgBtn()
{
	m_selectIndex = 0;
	m_msgBtn->setIcon(QPixmap("./img/msgBtnClicked.png"));
	m_contactsBtn->setIcon(QPixmap("./img/contactsBtnNomal.png"));
	
	//发出信号
	signal_toolWndPageChanged(0);
}

void QToolWnd::onClickContactsBtn()
{
	m_selectIndex = 0;
	m_msgBtn->setIcon(QPixmap("./img/msgBtnNormal.png"));
	m_contactsBtn->setIcon(QPixmap("./img/contactsBtnClicked.png"));
	signal_toolWndPageChanged(1);
}

