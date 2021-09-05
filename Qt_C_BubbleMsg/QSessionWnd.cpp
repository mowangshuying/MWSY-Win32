#include <QDateTime>

#include "QSessionWnd.h"
#include "QChatMsgWnd.h"
#include "QSessionTopWnd.h"

QSessionWnd::QSessionWnd(QWidget* p /*= nullptr*/)
	: QWidget(p)
{

	setMinimumSize(450,600);
	setWindowTitle(QString::fromLocal8Bit("会话窗口"));
	setStyleSheet("border-left:0px");


	m_vLayout = new QVBoxLayout(this);

	m_vLayout->setContentsMargins(0, 0, 0, 0);
	m_vLayout->setSpacing(0);

	m_sesTopWnd = new QSessionTopWnd(this);
	m_MsgWndList = new QListWidget(this);
	m_sendTextEdit = new QTextEdit(this);
	m_sendTextBtn = new QPushButton(this);
	m_sendTextBtn->setFixedSize(70, 30);
	m_sendTextBtn->setText(QString::fromLocal8Bit("发送(S)"));

	
	m_vLayout->addWidget(m_sesTopWnd);
	m_vLayout->addWidget(m_MsgWndList,2);
	m_vLayout->addWidget(m_sendTextEdit,1);


	m_MsgWndList->setStyleSheet("border-left:0px;border-top:1px solid gray;");
	m_sendTextEdit->setStyleSheet("border-left:0px;border-top:1px solid gray;");

	//设置会话窗口大小
	m_sendTextBtn->setGeometry(350, 550, 80, 20); 

	m_MsgWndList->setSelectionMode(QAbstractItemView::NoSelection);
	//m_MsgWndList->setStyleSheet("QListWidget::focus{outline:none;}");
	m_MsgWndList->setFocusPolicy(Qt::NoFocus);
	//按钮点击时候发送消息
	connect(m_sendTextBtn, SIGNAL(clicked()), this, SLOT(onSendTextBtnClick()));
	//connect(m_MsgWndList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onMsgListItemClicked(QListWidgetItem*)));
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

//void QSessionWnd::onMsgListItemClicked(QListWidgetItem* item)
//{
//	
//}

