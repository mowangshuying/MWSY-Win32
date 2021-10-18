#include "QFindFriendOrGroupWnd.h"

#include <QMouseEvent>

QFindFriendOrGroupWnd::QFindFriendOrGroupWnd(QWidget* p /*= nullptr*/) 
	: QWidget(p)
{
	m_vLayout = new QVBoxLayout(this);
	m_vLayout->setContentsMargins(0, 0, 0, 0);
	setLayout(m_vLayout);
	setWindowFlags(Qt::FramelessWindowHint);
	setFixedSize(600, 400);
	
	m_hLayout1 = new QHBoxLayout();
	m_titleLabel = new QLabel(this);
	m_minBtn = new QPushButton(this);
	m_closeBtn = new QPushButton(this);

	m_hLayout1->addSpacing(15);
	m_hLayout1->addWidget(m_titleLabel);
	m_titleLabel->setText(QString::fromLocal8Bit("查找"));
	m_hLayout1->addStretch();
	m_hLayout1->addWidget(m_minBtn);
	m_hLayout1->addWidget(m_closeBtn);

	m_minBtn->setIcon(QPixmap("./img/minWnd.png"));
	m_minBtn->setIconSize(QSize(20, 20));
	m_minBtn->setFixedSize(20, 20);

	m_closeBtn->setIcon(QPixmap("./img/closeWnd.png"));
	m_closeBtn->setIconSize(QSize(20, 20));
	m_closeBtn->setFixedSize(20, 20);

	m_vLayout->addLayout(m_hLayout1);


	m_hLayout2 = new QHBoxLayout();
	m_findPersonBtn = new QPushButton();
	m_findGroupBtn = new QPushButton();

	m_findPersonBtn->setFixedSize(100, 40);
	m_findGroupBtn->setFixedSize(100,40);

	m_hLayout2->addStretch();
	m_hLayout2->addWidget(m_findPersonBtn);
	m_hLayout2->addWidget(m_findGroupBtn);
	m_hLayout2->addStretch();

	m_findPersonBtn->setText(QString::fromLocal8Bit("找人"));
	m_findGroupBtn->setText(QString::fromLocal8Bit("找群"));

	m_findPersonBtn->setStyleSheet("background-color:#1aad19;border-style: none;");
	m_findGroupBtn->setStyleSheet("background-color:#1aad19;border-style: none;");

	m_vLayout->addLayout(m_hLayout2);

	m_hLayout3 = new QHBoxLayout();
	m_searchEdit = new QLineEdit();
	m_searchBtn = new QPushButton();
	m_hLayout3->addWidget(m_searchEdit);
	m_hLayout3->addWidget(m_searchBtn);

	//m_searchBtn->setFixedHeight(30);
	m_searchEdit->setFixedHeight(30);
	m_searchBtn->setText(QString::fromLocal8Bit("查找"));
	m_searchBtn->setFixedSize(100, 40);
	m_searchBtn->setStyleSheet("background-color:#1aad19;border-style: none;");

	m_vLayout->addLayout(m_hLayout3);

	m_vLayout->addStretch();
}

void QFindFriendOrGroupWnd::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bPress)
	{
		move(event->pos() - m_poPress + pos());
	}
}

void QFindFriendOrGroupWnd::mousePressEvent(QMouseEvent* event)
{
	m_bPress = true;
	m_poPress = event->pos();
}

void QFindFriendOrGroupWnd::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	m_bPress = false;
}

