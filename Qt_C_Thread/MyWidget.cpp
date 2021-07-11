#include "MyWidget.h"

MyWidget::MyWidget()
{
	//this->setLayout()
	setGeometry(50, 50, 500, 500);

	m_mainVLayOut = new QVBoxLayout(this);
	m_topHLayOut = new QHBoxLayout(this);
	m_edit = new QTextEdit(this);
	m_btnStartThread = new QPushButton("start thread", this);
	m_btnPause = new QPushButton("pause", this);
	m_btnExitThread = new QPushButton("exit thread", this);
	m_btnStart = new QPushButton("start", this);

	m_topHLayOut->addWidget(m_btnStartThread);
	m_topHLayOut->addWidget(m_btnExitThread);
	m_topHLayOut->addWidget(m_btnStart);
	m_topHLayOut->addWidget(m_btnPause);
	m_mainVLayOut->addLayout(m_topHLayOut);
	m_mainVLayOut->addWidget(m_edit);

	m_myThread = new MyThread();

	m_Timer = new QTimer();

	connect(m_myThread, SIGNAL(valueChanged(int, int)),
		this, SLOT(onValueChange(int, int)));

	connect(m_btnStartThread, SIGNAL(clicked()),
		this, SLOT(onStartThread()));

	connect(m_btnExitThread, SIGNAL(clicked()),
		this, SLOT(onExitThread()));

	connect(m_btnStart, SIGNAL(clicked()),
		this, SLOT(onStart()));

	connect(m_btnPause, SIGNAL(clicked()),
		this, SLOT(onPause()));

	connect(m_Timer, SIGNAL(timeout()),
		this, SLOT(onTimerOut()));
}

MyWidget::~MyWidget()
{
	m_myThread->exit();
	m_myThread->quit();
	m_myThread->wait();
	delete(m_myThread);

	m_Timer->stop();
	delete(m_Timer);

	delete(m_edit);
	delete(m_btnStartThread);
	delete(m_btnExitThread);
	delete(m_btnPause);
	delete(m_btnStart);
	delete(m_topHLayOut);
	delete(m_mainVLayOut);
}

void MyWidget::onStartThread()
{
	m_seq = 0;
	m_myThread->start();
	m_myThread->m_bExit = false;
	m_myThread->m_bPause = true;
}

void MyWidget::onExitThread()
{
	m_myThread->exit();
}

void MyWidget::onStart()
{
   	m_Timer->start(100);
	m_myThread->diceStart();
}

void MyWidget::onPause()
{
	m_myThread->dicePause();
	m_Timer->stop();
}

void MyWidget::onValueChange(int seq, int diceValue)
{
	QString  str = QString::asprintf("<1>the %d roll,num is:%d", seq, diceValue);
	m_edit->append(str);
}

void MyWidget::onTimerOut()
{
	int tempSeq = 0,tempDiceValue = 0;

	bool valid = m_myThread->readValue(&tempSeq, &tempDiceValue);

	if (valid && tempSeq != m_seq)
	{
		QString  str = QString::asprintf("<2>the %d roll,num is:%d", tempSeq, tempDiceValue);
		m_edit->append(str);
		m_seq = tempSeq;
	}

}
