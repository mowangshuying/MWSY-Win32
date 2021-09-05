#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>
class QToolWnd : public QWidget 
{
	//�����Ϣӳ��֧��
	Q_OBJECT
public:
	//�Ự����
	QToolWnd(QWidget* p = nullptr);
public slots:
	void onClickMsgBtn();
	void onClickContactsBtn();
public:
	QVBoxLayout* m_vBoxLayout;
	QPushButton *m_msgBtn;
	QPushButton* m_contactsBtn;
	QLabel* m_headUrlLabel;

	QVector<QPushButton*> m_btnVct;
	int m_selectIndex;
};