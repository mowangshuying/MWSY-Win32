#include "QMainWnd.h"

#include <QApplication>

#include <QMouseEvent>
#include <QDebug>

QMainWnd::QMainWnd(QWidget* p /*= nullptr*/)
	: QWidget(p)
{
	m_hLayout = new QHBoxLayout(this);
	m_toolWnd = new QToolWnd(this);
	
	m_commMsgListWnd = new QCommListWnd(this,QCommListWnd::QCommListWndEnum::QCommMsgItemWnd_Tpye);
	m_commContactsListWnd = new QCommListWnd(this, QCommListWnd::QCommListWndEnum::QCommContactItemWnd_Type);

	m_sessionWnd = new QSessionWnd(this);

	m_hLayout->setContentsMargins(0, 0, 0, 0);
	m_hLayout->setSpacing(0);

	m_sLayout1 = new QStackedLayout();
	m_sLayout1->addWidget(m_commMsgListWnd);
	m_sLayout1->addWidget(m_commContactsListWnd);

	for (int i = 0; i < 2; i++)
	{
		m_commMsgListWnd->addMsgItem("./img/head1.png", "苏果超市便民服务...", "[2条]_小鑫鑫:[小程序]...");
	}

	for (int i = 0; i < 2; i++)
	{
		m_commContactsListWnd->addContactsItem("./img/head2.png", "新的朋友");
	}

	QSize size = m_sLayout1->sizeHint();
	qDebug() << size;


	m_hLayout->addWidget(m_toolWnd);
	m_hLayout->addLayout(m_sLayout1);
	m_hLayout->addWidget(m_sessionWnd);

	setLayout(m_hLayout);
	setWindowFlags(Qt::FramelessWindowHint);

	connect(m_sessionWnd->m_sesTopWnd->m_closeBtn, SIGNAL(clicked()), this, SLOT(closeWnd()));
	connect(m_sessionWnd->m_sesTopWnd->m_maxBtn, SIGNAL(clicked()), this, SLOT(maxWnd()));
	connect(m_sessionWnd->m_sesTopWnd->m_minBtn, SIGNAL(clicked()), this, SLOT(minWnd()));
	connect(m_toolWnd, SIGNAL(pageChanged(int)), m_sLayout1, SLOT(setCurrentIndex(int)));
}

void QMainWnd::closeWnd()
{
	qApp->quit();
}

void QMainWnd::minWnd()
{
	showMinimized();
}

void QMainWnd::maxWnd()
{
	showMaximized();
}

void QMainWnd::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bPress)
	{
		move(event->pos() - m_poPress + pos());
	}
}

void QMainWnd::mousePressEvent(QMouseEvent* event)
{
	m_bPress = true;
	m_poPress = event->pos();
}

void QMainWnd::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	m_bPress = false;
}

