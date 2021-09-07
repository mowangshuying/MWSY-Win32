#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
class QCommMsgItemWnd : public QWidget
{
public:
	QCommMsgItemWnd(QWidget* p);
	QCommMsgItemWnd(QWidget* p, const char* headUrl, const char* name, const char* msg);

	QVBoxLayout* m_vLayout;
	QHBoxLayout* m_hLayout;
	QLabel* m_headurl;
	QLabel* m_name;
	QLabel* m_msg;
};