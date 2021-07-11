#include "CTopWindow.h"
#include "CToolBtn1.h"
#include <QPainter>

CTopWindow::CTopWindow(QWidget* p) : QWidget(p)
{
	setWindowFlags(Qt::FramelessWindowHint);
	setFixedSize(920, 120);

	m_pVLayout = new QVBoxLayout(this);
	m_pHBigLayout = new QHBoxLayout();
	m_pHSmallLayout = new QHBoxLayout();
	m_pVLayout->addLayout(m_pHSmallLayout);
	m_pVLayout->addLayout(m_pHBigLayout);

	m_strTopToolBtnStringVct << QString::fromLocal8Bit("电脑体检") << QString::fromLocal8Bit("木马查杀") << QString::fromLocal8Bit("电脑清理") << 
		QString::fromLocal8Bit("系统修复") << QString::fromLocal8Bit("优化加速")<< QString::fromLocal8Bit("功能大全") <<
		QString::fromLocal8Bit("小金库") << QString::fromLocal8Bit( "软件管家") << QString::fromLocal8Bit( "游戏管家");

	for (int i = 0; i < m_strTopToolBtnStringVct.size(); i++)
	{
		QString strImage = QString(":image/tBtn%1.png").arg(i+1);
		CToolBtn1 *pBtn = new CToolBtn1(strImage, m_strTopToolBtnStringVct[i]);
		m_topToolBtnVct.push_back(pBtn);
		m_pHBigLayout->addWidget(pBtn);
	}

	m_pHBigLayout->addStretch();
	m_pHBigLayout->setSpacing(0);
	m_pHBigLayout->setContentsMargins(20, 0, 0, 0);

	m_pBtn360 = new QPushButton();
	m_pBtn360->setIconSize(QSize(16, 16));
	m_pBtn360->setIcon(QPixmap(":/image/360Icon.png"));
	m_pBtn360->setStyleSheet("QPushButton{border:0px;}");

	m_ps360Lable = new QLabel();
	m_ps360Lable->setText(QString::fromLocal8Bit("360安全卫士"));
	m_ps360Lable->setStyleSheet("QLabel{color:rgb(255,255,255)}");

	m_pBtnUp = new QPushButton();
	m_pBtnUp->setIconSize(QSize(16, 16));
	m_pBtnUp->setIcon(QPixmap(":/image/up.png"));
	m_pBtnUp->setStyleSheet("QPushButton{border:0px;}");

	m_pBtnColoth = new QPushButton();
	m_pBtnColoth->setIconSize(QSize(16, 16));
	m_pBtnColoth->setIcon(QPixmap(":/image/coloth.png"));
	m_pBtnColoth->setStyleSheet("QPushButton{border:0px;}");

	m_pBtnMuti = new QPushButton();
	m_pBtnMuti->setIconSize(QSize(16, 16));
	m_pBtnMuti->setIcon(QPixmap(":/image/muti.png"));
	m_pBtnMuti->setStyleSheet("QPushButton{border:0px;}");

	m_pBtnMin = new QPushButton();
	m_pBtnMin->setIconSize(QSize(16, 16));
	m_pBtnMin->setIcon(QPixmap(":/image/min.png"));
	m_pBtnMin->setStyleSheet("QPushButton{border:0px;}");

	m_pBtnClose = new QPushButton();
	m_pBtnClose->setIconSize(QSize(16, 16));
	m_pBtnClose->setIcon(QPixmap(":/image/close.png"));
	m_pBtnClose->setStyleSheet("QPushButton{border:0px;}");

	m_pHSmallLayout->addWidget(m_pBtn360);
	m_pHSmallLayout->addWidget(m_ps360Lable);
	m_pHSmallLayout->addWidget(m_pBtnUp);
	m_pHSmallLayout->addStretch();
	m_pHSmallLayout->addWidget(m_pBtnColoth);
	m_pHSmallLayout->addSpacing(10);
	m_pHSmallLayout->addWidget(m_pBtnMuti);
	m_pHSmallLayout->addSpacing(10);
	m_pHSmallLayout->addWidget(m_pBtnMin);
	m_pHSmallLayout->addSpacing(10);
	m_pHSmallLayout->addWidget(m_pBtnClose);
	m_pHSmallLayout->setContentsMargins(0, 0, 0, 0);





	m_pBtnStar = new QPushButton(this);
	m_pBtnStar->setIconSize(QSize(20, 30));
	m_pBtnStar->setIcon(QPixmap("://image/star.png"));
	m_pBtnStar->setStyleSheet("QPushButton{border:0px;}");

	m_pBtn360BigIcon = new QPushButton(this);
	m_pBtn360BigIcon->setIconSize(QSize(42, 42));
	m_pBtn360BigIcon->setIcon(QPixmap("://image/360bigIcon.png"));
	m_pBtn360BigIcon->setStyleSheet("QPushButton{border:0px;}");

	m_pBtn360BigNum = new QPushButton(this);
	m_pBtn360BigNum->setIconSize(QSize(60, 20));
	m_pBtn360BigNum->setIcon(QPixmap("://image/btn360BigNumber.png"));
	m_pBtn360BigNum->setStyleSheet("QPushButton{border:0px;}");

	m_pBtnLogin = new QPushButton(this);
	m_pBtnLogin->setIconSize(QSize(60, 15));
	m_pBtnLogin->setIcon(QPixmap("://image/tBtn360BigLogin.png"));
	m_pBtnLogin->setStyleSheet("QPushButton{border:0px;}");

	//指定位置
	m_pBtnStar->setGeometry(760, 0, 20, 30);
	m_pBtn360BigNum->setGeometry(780, 50, 60, 20);
	m_pBtnLogin->setGeometry(780, 80, 60, 15);
	m_pBtn360BigIcon->setGeometry(855, 45, 42, 42);

	connect(m_topToolBtnVct[0], SIGNAL(clicked()), this, SLOT(onToolBtn0()));
	connect(m_topToolBtnVct[1], SIGNAL(clicked()), this, SLOT(onToolBtn1()));
}

void CTopWindow::onToolBtn0()
{
	emit pageChanged(0);
}

void CTopWindow::onToolBtn1()
{
	emit pageChanged(1);
}

void CTopWindow::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);
	QPainter p(this);
	p.setPen(Qt::NoPen);
	p.setBrush(QColor(34, 203, 100));
	p.drawRect(rect());
}

