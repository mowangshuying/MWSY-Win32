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
	//��ϵ��ͷ��
	QLabel* m_headUrl;
	//��ϵ������
	QLabel* m_name;
};