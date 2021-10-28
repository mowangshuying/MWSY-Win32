#pragma once


#include<QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

class QFindFriendItemWnd :public  QWidget {
	Q_OBJECT
public:
	QFindFriendItemWnd(QWidget* p);
	QFindFriendItemWnd(QWidget* p, const char* headUrl, const char* name);
public:
	QHBoxLayout* m_hLayout;
	//��ϵ��ͷ��
	QLabel* m_headUrl;
	//��ϵ������
	QLabel* m_name;
	//������Ѱ�ť
	QPushButton* m_addFriendBtn;
};