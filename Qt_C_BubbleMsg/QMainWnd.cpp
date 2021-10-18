#include "QMainWnd.h"
#include "QSimpleSplit.h"

#include <QApplication>

#include <QMouseEvent>
#include <QDebug>

QMainWnd::QMainWnd(QWidget* p /*= nullptr*/)
	: QWidget(p)
{
	m_hLayout = new QHBoxLayout(this);
	m_toolWnd = new QToolWnd(this);
	
	m_commMsgListWnd = new QCommListWnd(this,QCommListWnd::QCommListWndEnum::QCommMsgItemWnd_Tpye);
	m_commContactsListWnd = new QCommListWnd(this, QCommListWnd::QCommListWndEnum::QCommContactItemWnd_Type);

	m_commContactInfo = new QCommContactInfo(this);

	//会话窗口
	//m_sessionWnd = new QSessionWnd(this);

	m_hLayout->setContentsMargins(0, 0, 0, 0);
	m_hLayout->setSpacing(0);

	m_sLayout1 = new QStackedLayout();
	//消息窗口
	m_sLayout1->addWidget(m_commMsgListWnd);
	//联系人窗口
	m_sLayout1->addWidget(m_commContactsListWnd);
	m_sLayout1->setContentsMargins(0, 0, 0, 0);

	m_sLayout2 = new QStackedLayout();
	m_sLayout2->setContentsMargins(0, 0, 0, 0);

	//m_sLayout2->setCurrentIndex(4);

	//联系人详情页位于位置0永远不变.联系人详情页面只有一个
	m_sLayout2->addWidget(m_commContactInfo);
	
	{
		connect(m_commContactInfo->m_closeBtn, SIGNAL(clicked()), this, SLOT(closeWnd()));
		connect(m_commContactInfo->m_maxBtn, SIGNAL(clicked()), this, SLOT(maxWnd()));
		connect(m_commContactInfo->m_minBtn, SIGNAL(clicked()), this, SLOT(minWnd()));
	}

	//
	m_currentSesId = 1;
	for (int i = 1; i <=10; i++)
	{
		m_sessionWnd = new QSessionWnd();
		QString str = m_sessionWnd->m_sesTopWnd->m_titleLabel->text();
		str += QString(QString::fromLocal8Bit("%1xxxx")).arg(i);
		m_sessionWnd->m_sesTopWnd->m_titleLabel->setText(str);
		//模拟一个sesid;
		m_sessionWnd->m_sesId = m_currentSesId++;
		connect(m_sessionWnd->m_sesTopWnd->m_closeBtn, SIGNAL(clicked()), this, SLOT(closeWnd()));
		connect(m_sessionWnd->m_sesTopWnd->m_maxBtn, SIGNAL(clicked()), this, SLOT(maxWnd()));
		connect(m_sessionWnd->m_sesTopWnd->m_minBtn, SIGNAL(clicked()), this, SLOT(minWnd()));
		m_sLayout2->addWidget(m_sessionWnd);
	}

	

	for (int i = 1; i <=10; i++){
		
		QString str1 = QString(QString::fromLocal8Bit("%1号信息窗口")).arg(i);
		QString str2 = QString(QString::fromLocal8Bit("[2条]_小鑫鑫: [小程序] %1号...")).arg(i);
		m_commMsgListWnd->addMsgItem("./img/head1.png", str1.toLocal8Bit().data(), "[2条]_小鑫鑫:[小程序] 0号...",i);
	}

	for (int i = 0; i < 10; i++){
		//if (i == 0) {
		//	m_commContactsListWnd->addContactsItem("./img/head2.png", "新的朋友0号");
		//}
		//else {
		//	m_commContactsListWnd->addContactsItem("./img/head2.png", "新的朋友1号");
		//}

		QString str1 = QString(QString::fromLocal8Bit("新的朋友%1号")).arg(i);
		m_commContactsListWnd->addContactsItem("./img/head2.png", str1.toLocal8Bit().data());
	}

	m_hLayout->addWidget(m_toolWnd);

	{
		/*添加分割线的示例代码*/
		QSimpleSplit* sp = new QSimpleSplit(this,QSimpleSplit::QSimpleSplit_direction_h);
		m_hLayout->addWidget(sp);
	}

	m_hLayout->addLayout(m_sLayout1);


	{
		/*添加分割线的示例代码*/
		QSimpleSplit* sp = new QSimpleSplit(this, QSimpleSplit::QSimpleSplit_direction_h);
		m_hLayout->addWidget(sp);
	}

	m_hLayout->addLayout(m_sLayout2);

	setLayout(m_hLayout);
	setWindowFlags(Qt::FramelessWindowHint);
	connect(m_toolWnd, SIGNAL(signal_toolWndPageChanged(int)), this, SLOT(slot_toolWndPageChanged(int)));

	connect(m_commMsgListWnd, SIGNAL(commListChanged(int)), this, SLOT(slot_sesIdToIndex(int)));
    connect(m_commContactsListWnd, SIGNAL(commListChanged(int)), this, SLOT(slot_sesIdToIndex(int)));
	
	//
	connect(m_commContactsListWnd, SIGNAL(signal_commListChangedAndSendInfo(QMap<QString, QString>)),
		m_commContactInfo, SLOT(slot_commListChangedAndSendInfo(QMap< QString, QString>)));

	connect(m_commContactInfo, SIGNAL(signal_sendMsgBtnClick(QMap<QString, QString>)),
		this, SLOT(slot_createSesAndSelect(QMap<QString, QString>)));

}

void QMainWnd::closeWnd()
{
	qApp->quit();
}

void QMainWnd::minWnd()
{
	showMinimized();
}

void QMainWnd::maxWnd()
{
	showMaximized();
}

void QMainWnd::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bPress)
	{
		move(event->pos() - m_poPress + pos());
	}
}

void QMainWnd::mousePressEvent(QMouseEvent* event)
{
	m_bPress = true;
	m_poPress = event->pos();
	//当前添加好友或者添加群的窗口的打开的，直接隐藏
	//m_commMsgListWnd->m_selectWnd1->hide();
	//m_commContactsListWnd->m_selectWnd1->hide();
}

void QMainWnd::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	m_bPress = false;
}

void QMainWnd::slot_sesIdToIndex(int sesid)
{
	int layoutId = 0;

	if (sesid != 0) {
		int count = m_sLayout2->count();
		for (int i = 0; i < count; i++) {
			
			if (i == 0) {
				continue;
			}
			QLayoutItem* item = m_sLayout2->layout()->itemAt(i);
			QSessionWnd* sesWnd = dynamic_cast<QSessionWnd*>(item->widget());
			if (sesWnd->m_sesId == sesid) {
				layoutId = i;
				break;
			}
		}
	}
	if (sesid != 0) {
		m_lastSesId = layoutId;
	}
	//return layoutId;
	m_sLayout2->setCurrentIndex(layoutId);
}

void QMainWnd::slot_createSesAndSelect(QMap<QString, QString> infoMap)
{
	//某个玩家向某个玩家发送消息：

	//左边创建一个会话项
	//获取info中的信息
	QString str1 =  infoMap["name"];
	//创建一个会话项
	int sesid = m_currentSesId++;
	QListWidgetItem *pItem = m_commMsgListWnd->addMsgItem("./img/head1.png", str1.toLocal8Bit().data(), "",sesid);
	m_commMsgListWnd->m_listWidget->setCurrentItem(pItem);
	//创建一个会话窗口
	{
		//int i = 12;
		m_sessionWnd = new QSessionWnd();
		QString str = m_sessionWnd->m_sesTopWnd->m_titleLabel->text();
		str += QString(QString::fromLocal8Bit("%1xxxx")).arg(sesid);
		m_sessionWnd->m_sesTopWnd->m_titleLabel->setText(str);
		
		//模拟一个sesid;
		m_sessionWnd->m_sesId = sesid;
		m_lastSesId = sesid;

		connect(m_sessionWnd->m_sesTopWnd->m_closeBtn, SIGNAL(clicked()), this, SLOT(closeWnd()));
		connect(m_sessionWnd->m_sesTopWnd->m_maxBtn, SIGNAL(clicked()), this, SLOT(maxWnd()));
		connect(m_sessionWnd->m_sesTopWnd->m_minBtn, SIGNAL(clicked()), this, SLOT(minWnd()));
		m_sLayout2->addWidget(m_sessionWnd);
	}

	m_toolWnd->m_msgBtn->click();
	slot_sesIdToIndex(sesid);
}

void QMainWnd::slot_toolWndPageChanged(int page)
{
	m_sLayout1->setCurrentIndex(page);
	if (page == 0) {
		if (m_lastSesId != -1) {
			slot_sesIdToIndex(m_lastSesId);
		}
		else {
			//设置背景图片打开
			m_commContactInfo->showBgPng();
		}
	}
	else {
		m_commContactInfo->showBgPng();
		slot_sesIdToIndex(0);
	}
}

