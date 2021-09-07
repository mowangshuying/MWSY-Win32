#pragma once

#include<QWidget>
#include <QLabel>
#include <QHBoxLayout>
class QCommContactItemWnd : public QWidget
{
public:
	QCommContactItemWnd(QWidget* p);

	QCommContactItemWnd(QWidget* p, const char* headUrl, const char* name);
public:
	QHBoxLayout* m_hLayout;
	//联系人头像
	QLabel* m_headUrl;
	//联系人名字
	QLabel* m_name;
};