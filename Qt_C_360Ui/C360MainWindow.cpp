#include "C360MainWindow.h"
#include "CTopWindow.h"

C360MainWindow::C360MainWindow(QWidget* p) : QWidget(p)
{
	m_bPress = false;
	m_poPress = QPoint(0, 0);
	setFixedSize(920, 580);
	setWindowFlags(Qt::FramelessWindowHint);

	m_pTopWindow = new CTopWindow(this);
	m_pPage1 = new CPageWindow1(this); 
	m_pPage2 = new CPageWindow2(this);

	m_pSLayout = new QStackedLayout();
	m_pSLayout->addWidget(m_pPage1);
	m_pSLayout->addWidget(m_pPage2);

	m_pVLayout = new QVBoxLayout(this);
	m_pVLayout->addWidget(m_pTopWindow);
	m_pVLayout->addLayout(m_pSLayout);

	m_pVLayout->setContentsMargins(0, 0, 0, 0);
	m_pVLayout->setSpacing(0);

	connect(m_pTopWindow->m_pBtnClose, SIGNAL(clicked()), this, SLOT(close()));
	connect(m_pTopWindow->m_pBtnMin, SIGNAL(clicked()), this, SLOT(min()));
	connect(m_pTopWindow, SIGNAL(pageChanged(int)), m_pSLayout, SLOT(setCurrentIndex(int)));

}

void C360MainWindow::close()
{
	qApp->quit();
}

void C360MainWindow::min()
{
	showMinimized();
}



void C360MainWindow::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bPress)
	{
		move(event->pos() - m_poPress + pos());
	}
}

void C360MainWindow::mousePressEvent(QMouseEvent* event)
{
	m_bPress = true;
	m_poPress = event->pos();
}

void C360MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	m_bPress = false;
}

