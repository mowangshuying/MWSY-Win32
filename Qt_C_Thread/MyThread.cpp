#include "MyThread.h"



void MyThread::run()
{
	qsrand(QTime::currentTime().msec());

	while (!m_bExit)
	{
		if (!m_bPause)
		{
			if (m_mutex.try_lock())
			{
				m_nDiceValue = qrand() % 6;
				m_nSeq++;
				m_mutex.unlock();
				emit valueChanged(m_nSeq, m_nDiceValue);
			}
		}
		sleep(1);
	}
	quit();
}

MyThread::MyThread()
{
	m_nSeq = 0;
	m_nDiceValue = -1;
	m_bPause = false;
	m_bExit = false;
}

void MyThread::diceStart()
{
	m_bPause = false;
}

void MyThread::dicePause()
{
	m_bPause = true;
}

void MyThread::exit()
{
	m_bExit = true;
}

bool MyThread::readValue(int* seq, int* diceValue)
{
	if (m_mutex.try_lock())
	{
		*seq = m_nSeq;
		*diceValue = m_nDiceValue;
		m_mutex.unlock();
		return true;
	}

	return false;
}
