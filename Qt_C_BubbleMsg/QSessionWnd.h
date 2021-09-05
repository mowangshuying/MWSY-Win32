#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget> //�����б�

#include "QSessionTopWnd.h"

class QSessionWnd : public QWidget 
{
	//�����Ϣӳ��֧��
	Q_OBJECT
public:
	//�Ự����
	QSessionWnd(QWidget* p = nullptr);
public slots:
	void onSendTextBtnClick();
	//void onMsgListItemClicked(QListWidgetItem* item);
public:
	//���ڲ��ֹ���
	QVBoxLayout *m_vLayout;
	QSessionTopWnd* m_sesTopWnd;
	//�����б���Ϣ
	QListWidget* m_MsgWndList;
	//��Ҫ���͵�����
	QTextEdit* m_sendTextEdit;
	//���ڷ������ֵİ�ť
	QPushButton* m_sendTextBtn;
};