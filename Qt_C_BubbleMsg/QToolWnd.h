#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QVector>

/*
* 最右边工具栏窗口
*/
class QToolWnd : public QWidget 
{
	//添加消息映射支持
	Q_OBJECT
public:
	//工具栏窗口
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