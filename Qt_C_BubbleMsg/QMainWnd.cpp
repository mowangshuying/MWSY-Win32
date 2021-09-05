#include "QMainWnd.h"

#include <QApplication>

#include <QMouseEvent>

QMainWnd::QMainWnd(QWidget* p /*= nullptr*/)
	: QWidget(p)
{
	m_hLayout = new QHBoxLayout(this);
	m_toolWnd = new QToolWnd(this);
	m_commListWnd = new QCommListWnd(this);
	m_sessionWnd = new QSessionWnd(this);

	m_hLayout->setContentsMargins(0, 0, 0, 0);
	m_hLayout->setSpacing(0);

	m_hLayout->addWidget(m_toolWnd);
	//m_toolWnd->setStyleSheet("background-color:black;border:2px solid #014F84;");
	m_hLayout->addWidget(m_commListWnd);
	m_hLayout->addWidget(m_sessionWnd);

	setLayout(m_hLayout);
	setWindowFlags(Qt::FramelessWindowHint);
	//setObjectName("QMainWnd");
	//setStyleSheet("border-radius: 15px;");

	connect(m_sessionWnd->m_sesTopWnd->m_closeBtn, SIGNAL(clicked()), this, SLOT(closeWnd()));
	connect(m_sessionWnd->m_sesTopWnd->m_maxBtn, SIGNAL(clicked()), this, SLOT(maxWnd()));
	connect(m_sessionWnd->m_sesTopWnd->m_minBtn, SIGNAL(clicked()), this, SLOT(minWnd()));
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

