#include "QCommListWnd.h"

#include "QCommMsgItemWnd.h"
#include "QCommContactItemWnd.h"
#include "QCustomListWidgetItem.h"
#include "QSimpleSplit.h"

#include <QDebug>

#include <QScrollBar>

QCommListWnd::QCommListWnd(QWidget* p /*= nullptr*/, QCommListWndEnum wndType/*QCommMsgItemWnd_Tpye*/)
	: QWidget(p),m_WndType(wndType)
{
	m_vLayout = new QVBoxLayout();
	m_vLayout->setContentsMargins(0, 0, 0, 0);
	m_vLayout->setSpacing(0);
	setLayout(m_vLayout);
	setFixedWidth(250);
	
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

	{
		/*添加分割线的示例代码*/
		QSimpleSplit* sp = new QSimpleSplit(this);
		m_vLayout->addWidget(sp);
	}
	
	m_listWidget = new QListWidget();
	m_listWidget->setFixedWidth(250);
	m_listWidget->setAttribute(Qt::WA_StyledBackground);
	//m_listWidget->setStyleSheet("border-left:0px ;");
	m_vLayout->addWidget(m_listWidget);



	setFixedWidth(250);
	setObjectName("QCommListWnd");
	setStyleSheet("#QCommListWnd{background-color:white;}");
	setAttribute(Qt::WA_StyledBackground);
	setWindowFlags(Qt::FramelessWindowHint);
	connect(m_listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onCurrentItemClicked(QListWidgetItem*)));


	////设置滚动条的样式
	m_listWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,0%);"
		"margin:0px,0px,0px,0px;"
		"padding-top:9px;"
		"padding-bottom:9px;"
		"}"
		"QScrollBar::handle:vertical"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,25%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::handle:vertical:hover"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,50%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::add-line:vertical"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/3.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/1.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-line:vertical:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/4.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/2.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical"
		"{"
		"background:rgba(0,0,0,10%);"
		"border-radius:4px;"
		"}"
	);


	m_listWidget->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,0%);"
		"margin:0px,0px,0px,0px;"
		"padding-top:9px;"
		"padding-bottom:9px;"
		"}"
		"QScrollBar::handle:horizontal"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,25%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::handle:horizontal:hover"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,50%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::add-line:horizontal"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/3.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:horizontal"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/1.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-line:horizontal:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/4.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:horizontal:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/2.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal"
		"{"
		"background:rgba(0,0,0,10%);"
		"border-radius:4px;"
		"}"
	);


}

void QCommListWnd::onCurrentItemClicked(QListWidgetItem* item)
{
	QCustomListWidgetItem* pCustItem = dynamic_cast<QCustomListWidgetItem*>(item);
	qDebug() << "sesid == " << pCustItem->sesId();
	if (m_WndType == QCommContactItemWnd_Type) {
		commListChanged(0);

		QCommContactItemWnd* wnd = dynamic_cast<QCommContactItemWnd*>(m_listWidget->itemWidget(pCustItem));

		//修改栈内信息
		QMap<QString, QString> infoMap;
		infoMap["name"] = wnd->m_name->text();
		//emit signal_commListChangedAndSendInfo(infoMap);
		//emit infoMap;
		emit signal_commListChangedAndSendInfo(infoMap);
		//emit signal_test();
	}
	else {
		QCommMsgItemWnd* wnd = dynamic_cast<QCommMsgItemWnd*>(m_listWidget->itemWidget(pCustItem));
		qint64 sesid = wnd->m_sesId;

		//获取stacklayout中的sesid；

		//遍历stackLayout判断对应的窗口sesid
		commListChanged(sesid);
	}
}

QListWidgetItem* QCommListWnd::addMsgItem(const char* headUrl, const char* name, const char*  msg,qint64 sesid)
{

	QCommMsgItemWnd* pMsgItem = new QCommMsgItemWnd(m_listWidget,headUrl,name,msg,sesid);
	QListWidgetItem* pListItem = new QCustomListWidgetItem(m_listWidget);

	pMsgItem->setFixedWidth(this->width()-5);
	pListItem->setSizeHint(QSize(this->width()-5, 65));
	m_listWidget->setItemWidget(pListItem, pMsgItem);

	/*void (QListWidget:: * pfnItemClicked)(QListWidgetItem*) = &QListWidget::itemClicked;
	QObject::connect(m_listWidget, pfnItemClicked, [&](QListWidgetItem* item) {
		QCommMsgItemWnd* pw = dynamic_cast<QCommMsgItemWnd*> (m_listWidget->itemWidget(item));
		qDebug() << pw->m_msg->text();
		});*/

	return pListItem;
}

void QCommListWnd::addContactsItem(const char* headUrl, const char*  name)
{
	QCommContactItemWnd* pMsgItem = new QCommContactItemWnd(m_listWidget,headUrl,name);
	QListWidgetItem* pListItem = new QCustomListWidgetItem(m_listWidget);

	pMsgItem->setFixedWidth(this->width()-5);
	pListItem->setSizeHint(QSize(this->width()-5, 65));
	m_listWidget->setItemWidget(pListItem, pMsgItem);
}

