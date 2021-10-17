#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>

/*
* ���ұ߹���������
*/
class QToolWnd : public QWidget 
{
	//�����Ϣӳ��֧��
	Q_OBJECT
public:
	//����������
	QToolWnd(QWidget* p = nullptr);
signals:
	void signal_toolWndPageChanged(int num);
public slots:
	void onClickMsgBtn();
	void onClickContactsBtn();
public:
	//QMainWnd* m_mainWnd;
	QVBoxLayout* m_vBoxLayout;
	QPushButton *m_msgBtn;
	QPushButton* m_contactsBtn;
	QLabel* m_headUrlLabel;

	QVector<QPushButton*> m_btnVct;
	int m_selectIndex;
};