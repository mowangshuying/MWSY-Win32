#include <QDateTime>

#include <QSplitter>
#include <QListWidget>
#include <QScrollBar>

#include "QSessionWnd.h"
#include "QChatMsgWnd.h"
#include "QSessionTopWnd.h"

#include "QSimpleSplit.h"

QSessionWnd::QSessionWnd(QWidget* p /*= nullptr*/)
	: QWidget(p)
{

	setMinimumSize(450,600);
	setWindowTitle(QString::fromLocal8Bit("会话窗口"));
	//setStyleSheet("background-color:white;");
	//setStyleSheet("border-left:0px");


	m_vLayout = new QVBoxLayout(this);

	m_vLayout->setContentsMargins(0, 0, 0, 0);
	m_vLayout->setSpacing(0);

	m_sesTopWnd = new QSessionTopWnd(this);
	
	m_MsgWndList = new QListWidget(this);
	m_MsgWndList->setMinimumWidth(this->width());
	m_sendTextEdit = new QTextEdit(this);
	m_sendTextEdit->setStyleSheet("border:0px");

	m_sendTextBtn = new QPushButton(this);
	m_sendTextBtn->setFixedSize(70, 30);
	m_sendTextBtn->setText(QString::fromLocal8Bit("发送(S)"));

	
	m_vLayout->addWidget(m_sesTopWnd);

	{
		/*添加分割线的示例代码*/
		QSimpleSplit* sp = new QSimpleSplit(this);
		m_vLayout->addWidget(sp);
	}

	m_vLayout->addWidget(m_MsgWndList,2);

	/*添加分割线的示例代码*/
	QSimpleSplit* sp = new QSimpleSplit(this);
	m_vLayout->addWidget(sp);

	m_vLayout->addWidget(m_sendTextEdit,1);

	//{
		/*添加分割线的示例代码*/
	//	QSimpleSplit* sp = new QSimpleSplit(this);
	//	m_vLayout->addWidget(sp);
	//}

	m_hLayout = new QHBoxLayout();
	m_hLayout->addStretch();
	m_hLayout->addWidget(m_sendTextBtn);
	//m_hLayout->addSpacing(30);
	m_hLayout->setContentsMargins(0, 0, 15,10);
	m_vLayout->addLayout(m_hLayout);


	//m_MsgWndList->setStyleSheet("border-left:0px;border-top:1px solid gray;");
	//m_sendTextEdit->setStyleSheet("border-left:0px;border-top:1px solid gray;");

	//设置会话窗口大小
	//m_sendTextBtn->setGeometry(350, 550, 80, 20); 

	m_MsgWndList->setSelectionMode(QAbstractItemView::NoSelection);
	//m_MsgWndList->setStyleSheet("QListWidget::focus{outline:none;}");
	m_MsgWndList->setFocusPolicy(Qt::NoFocus);
	//按钮点击时候发送消息
	connect(m_sendTextBtn, SIGNAL(clicked()), this, SLOT(onSendTextBtnClick()));
	//connect(m_MsgWndList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onMsgListItemClicked(QListWidgetItem*)));
	m_sendTextBtn->setStyleSheet("background-color:#1aad19;border-style: none;");

	setAttribute(Qt::WA_StyledBackground);
	setStyleSheet("background-color:white");


	////设置滚动条的样式
	m_MsgWndList->verticalScrollBar()->setStyleSheet("QScrollBar:vertical"
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

	m_MsgWndList->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal"
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

void QSessionWnd::onSendTextBtnClick()
{
	QString msgText = m_sendTextEdit->toPlainText();
	
	//如果不含任何内容不允许发送
	if (msgText == "") {
		return;
	}

	m_sendTextEdit->setText("");
	QString time = QString::number(QDateTime::currentDateTime().toTime_t());
	QChatMsgWnd* msgWnd = new QChatMsgWnd(m_MsgWndList);
	QListWidgetItem* msgItem = new QListWidgetItem(m_MsgWndList);

	msgWnd->setFixedWidth(this->width());
	QSize msgSize = msgWnd->fontRect(msgText);
	msgItem->setSizeHint(msgSize);


	//会设置消息并调用相应的
	msgWnd->setText(msgText, time,msgSize, QChatMsgWnd::ChatMsg_Owner);

	//关联项与窗口
	m_MsgWndList->setItemWidget(msgItem, msgWnd);
}