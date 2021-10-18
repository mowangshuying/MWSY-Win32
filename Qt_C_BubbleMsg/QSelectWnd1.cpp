#include "QSelectWnd1.h"
#include "QFindFriendOrGroupWnd.h"

#include <QDebug>
#include <QApplication>

QSelectWnd1::QSelectWnd1(QWidget* p)
	: QWidget(p)
{
	setWindowFlags(Qt::FramelessWindowHint);
	setFixedWidth(100);
	m_vLayout = new QVBoxLayout(this);
	m_vLayout->setContentsMargins(0, 0, 0, 0);
	m_vLayout->setMargin(0);
	m_vLayout->setSpacing(0);
	m_addContactsOrGroupBtn = new QPushButton(QString::fromLocal8Bit("添加好友或群"),this);
	m_createGroupBtn = new QPushButton(QString::fromLocal8Bit("创建群聊"),this);
	
	//m_addContactsOrGroupBtn->setWindowFlags(Qt::FramelessWindowHint);
	//m_createGroupBtn->setWindowFlags(Qt::FramelessWindowHint);
	//m_addContactsOrGroupBtn->setContentsMargins(0, 0, 0, 0);
	//m_createGroupBtn->setContentsMargins(0, 0, 0, 0);

	m_vLayout->addWidget(m_addContactsOrGroupBtn);
	m_vLayout->addWidget(m_createGroupBtn);
	//
	//int h = m_createGroupBtn->height();
	setFixedHeight(m_createGroupBtn->height()+m_addContactsOrGroupBtn->height());
	setLayout(m_vLayout);

	connect(m_addContactsOrGroupBtn, SIGNAL(clicked()), this, SLOT(slot_addContactsOrGroupBtnClick()));
}

void QSelectWnd1::slot_addContactsOrGroupBtnClick()
{
	QFindFriendOrGroupWnd* pWnd = new QFindFriendOrGroupWnd();
	pWnd->show();
}

//void QSelectWnd1::mousePressEvent(QMouseEvent* event)
//{
//	//
//	qDebug() << "QSelectWnd1::mousePressEvent";
//}

bool QSelectWnd1::event(QEvent* event) {
	if (event->type() == QEvent::ActivationChange)
	{
		if (QApplication::activeWindow() != this)
		{
			this->hide();
		}
	}
	return QWidget::event(event);
}
