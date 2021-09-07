#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

/*
* 消息具体内容类：消息，头像，联系人名字等
*/
class QCommMsgItemWnd : public QWidget
{
public:
	QCommMsgItemWnd(QWidget* p);
	QCommMsgItemWnd(QWidget* p, const char* headUrl, const char* name, const char* msg,qint64 sesid);

	QVBoxLayout* m_vLayout;
	QHBoxLayout* m_hLayout;
	QLabel* m_headurl;
	QLabel* m_name;
	QLabel* m_msg;

	qint64 m_sesId;
};