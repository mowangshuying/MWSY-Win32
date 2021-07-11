#pragma once

#include <QThread>
#include <QTime>
#include <QMutex>

class MyThread : public QThread
{
	Q_OBJECT

protected:
	virtual void run();

public:
	MyThread();

	void diceStart();

	void dicePause();

	void exit();

	bool readValue(int* seq, int* diceValue);

signals:
	void valueChanged(int seq, int diceValue);
public:
	QMutex m_mutex;
	int m_nSeq;
	int m_nDiceValue;
	bool m_bPause;
	bool m_bExit;

};