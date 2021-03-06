#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget> //窗口列表

#include "QSessionTopWnd.h"

/*
* 会话的窗口 sesId作用,右边信息栏的小窗口选项也有一个id，通过id关联彼此信息
* 来修改对应的窗口信息
*/

class QSessionWnd : public QWidget 
{
	//添加消息映射支持
	Q_OBJECT
public:
	//会话窗口
	QSessionWnd(QWidget* p = nullptr);
public slots:
	void onSendTextBtnClick();
public:
	//窗口布局管理
	QVBoxLayout *m_vLayout;
	//会话的上放窗口
	QSessionTopWnd* m_sesTopWnd;
	//窗口列表信息
	QListWidget* m_MsgWndList;
	//需要发送的文字
	QTextEdit* m_sendTextEdit;
	//用于发送文字的按钮
	QPushButton* m_sendTextBtn;
	//用于控制
	QHBoxLayout* m_hLayout;
	//会话id
	qint64 m_sesId;
	//会话名字
	QString m_name;
};