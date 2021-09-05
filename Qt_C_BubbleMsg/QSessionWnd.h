#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget> //窗口列表

#include "QSessionTopWnd.h"

class QSessionWnd : public QWidget 
{
	//添加消息映射支持
	Q_OBJECT
public:
	//会话窗口
	QSessionWnd(QWidget* p = nullptr);
public slots:
	void onSendTextBtnClick();
	//void onMsgListItemClicked(QListWidgetItem* item);
public:
	//窗口布局管理
	QVBoxLayout *m_vLayout;
	QSessionTopWnd* m_sesTopWnd;
	//窗口列表信息
	QListWidget* m_MsgWndList;
	//需要发送的文字
	QTextEdit* m_sendTextEdit;
	//用于发送文字的按钮
	QPushButton* m_sendTextBtn;
};