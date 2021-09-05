#include "QCommListWnd.h"

QCommListWnd::QCommListWnd(QWidget* p /*= nullptr*/) 
	: QWidget(p)
{
	m_vLayout = new QVBoxLayout();
	m_vLayout->setContentsMargins(1, 0, 0, 0);
	m_vLayout->setSpacing(0);
	setLayout(m_vLayout);
	
	m_hLayout = new QHBoxLayout(this);
	m_searchEdit = new QLineEdit(this);
	m_startGroupBtn = new QPushButton(this);
	m_searchEdit->setFixedHeight(25);
	m_startGroupBtn->setFixedSize(25,25);
	m_startGroupBtn->setIcon(QPixmap("./img/startGroupBtn.png"));
	m_startGroupBtn->setIconSize(QSize(25, 25));

	m_hLayout->addSpacing(10);
	m_hLayout->addWidget(m_searchEdit);
	m_hLayout->addSpacing(10);
	m_hLayout->addWidget(m_startGroupBtn);
	m_hLayout->addSpacing(10);

	//m_hLayout->setSpacing(15);
	m_vLayout->addSpacing(25);
	m_vLayout->addLayout(m_hLayout);
	m_vLayout->setContentsMargins(0, 0, 0, 0);

	m_vLayout->addSpacing(15);
	
	
	m_listWidget = new QListWidget();
	m_listWidget->setAttribute(Qt::WA_StyledBackground);
	m_listWidget->setStyleSheet("border-left:0px ;");
	m_vLayout->addWidget(m_listWidget);

	setFixedWidth(250);
	setStyleSheet("border-right:1px solid gray;background-color:white;");
	setAttribute(Qt::WA_StyledBackground);

	//m_listWidget->setStyleSheet("border-left:0px ;");
}

