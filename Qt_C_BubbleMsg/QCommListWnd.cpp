#include "QCommListWnd.h"

#include "QCommMsgItemWnd.h"
#include "QCommContactItemWnd.h"

#include <QDebug>

QCommListWnd::QCommListWnd(QWidget* p /*= nullptr*/, QCommListWndEnum wndType/*QCommMsgItemWnd_Tpye*/)
	: QWidget(p),m_WndType(wndType)
{
	m_vLayout = new QVBoxLayout();
	m_vLayout->setContentsMargins(1, 0, 0, 0);
	m_vLayout->setSpacing(0);
	setLayout(m_vLayout);
	
	m_hLayout = new QHBoxLayout(this);
	m_hLayout->setContentsMargins(0, 0, 0, 0);
	m_hLayout->setSpacing(0);
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
	m_vLayout->addSpacing(25);
	m_vLayout->addLayout(m_hLayout);
	m_vLayout->addSpacing(15);
	
	m_listWidget = new QListWidget();
	m_listWidget->setFixedWidth(250);
	m_listWidget->setAttribute(Qt::WA_StyledBackground);
	m_listWidget->setStyleSheet("border-left:0px ;");
	m_vLayout->addWidget(m_listWidget);



	setFixedWidth(250);
	setObjectName("QCommListWnd");
	setStyleSheet("#QCommListWnd{border-right:1px solid gray;background-color:white;}");
	setAttribute(Qt::WA_StyledBackground);
	setWindowFlags(Qt::FramelessWindowHint);
}

void QCommListWnd::addMsgItem(const char* headUrl, const char* name, const char*  msg)
{

	QCommMsgItemWnd* pMsgItem = new QCommMsgItemWnd(m_listWidget,headUrl,name,msg);
	QListWidgetItem* pListItem = new QListWidgetItem(m_listWidget);

	pMsgItem->setFixedWidth(this->width()-5);
	pListItem->setSizeHint(QSize(this->width()-5, 65));
	m_listWidget->setItemWidget(pListItem, pMsgItem);

	/*void (QListWidget:: * pfnItemClicked)(QListWidgetItem*) = &QListWidget::itemClicked;
	QObject::connect(m_listWidget, pfnItemClicked, [&](QListWidgetItem* item) {
		QCommMsgItemWnd* pw = dynamic_cast<QCommMsgItemWnd*> (m_listWidget->itemWidget(item));
		qDebug() << pw->m_msg->text();
		});*/
}

void QCommListWnd::addContactsItem(const char* headUrl, const char*  name)
{
	QCommContactItemWnd* pMsgItem = new QCommContactItemWnd(m_listWidget,headUrl,name);
	QListWidgetItem* pListItem = new QListWidgetItem(m_listWidget);

	pMsgItem->setFixedWidth(this->width()-5);
	pListItem->setSizeHint(QSize(this->width()-5, 65));
	m_listWidget->setItemWidget(pListItem, pMsgItem);
}

