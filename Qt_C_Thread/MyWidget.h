#pragma once

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>

#include "MyThread.h"

class MyWidget : public QWidget
{
	//Q_OBJECT
	Q_OBJECT

public:
	//设置界面为垂直布局
	MyWidget();

	virtual ~MyWidget();
public slots:
	void  onStartThread();

	void  onExitThread();

	void onStart();

	void  onPause();

	void onValueChange(int seq, int diceValue);

	void onTimerOut();

public:
	QVBoxLayout *m_mainVLayOut;
	QHBoxLayout* m_topHLayOut;
	QTextEdit* m_edit;
	QPushButton* m_btnStartThread;
	QPushButton* m_btnStart;
	QPushButton* m_btnPause;
	QPushButton* m_btnExitThread;
	MyThread* m_myThread;

	QTimer *m_Timer;
	int m_seq;
	//int m_diceValue;
};