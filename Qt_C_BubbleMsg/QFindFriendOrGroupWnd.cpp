#include "QSimpleSplit.h"
#include "QFindFriendItemWnd.h"
#include "QFindFriendOrGroupWnd.h"

#include <QMouseEvent>
#include <QListWidgetItem>
#include <QScrollBar>


QFindFriendOrGroupWnd::QFindFriendOrGroupWnd(QWidget* p /*= nullptr*/) 
	: QWidget(p)
{
	m_vLayout = new QVBoxLayout(this);
	m_vLayout->setContentsMargins(5, 5, 5, 5);
	setLayout(m_vLayout);
	setWindowFlags(Qt::FramelessWindowHint);
	setFixedSize(600, 400);
	
	m_vLayout->addSpacing(5);

	m_hLayout1 = new QHBoxLayout();
	m_titleLabel = new QLabel(this);
	m_minBtn = new QPushButton(this);
	m_closeBtn = new QPushButton(this);

	//m_hLayout1->addSpacing(5);
	m_hLayout1->addWidget(m_titleLabel);
	m_titleLabel->setText(QString::fromLocal8Bit("查找"));
	m_hLayout1->addStretch();
	m_hLayout1->addWidget(m_minBtn);
	m_hLayout1->addWidget(m_closeBtn);

	m_minBtn->setIcon(QPixmap("./img/minWnd.png"));
	m_minBtn->setIconSize(QSize(20, 20));
	m_minBtn->setFixedSize(20, 20);

	m_closeBtn->setIcon(QPixmap("./img/closeWnd.png"));
	m_closeBtn->setIconSize(QSize(20, 20));
	m_closeBtn->setFixedSize(20, 20);

	//m_hLayout1->addSpacing(5);
	m_vLayout->addLayout(m_hLayout1);

	QSimpleSplit* pSplitWnd1 = new QSimpleSplit(this);
	m_vLayout->addWidget(pSplitWnd1);

	//m_hLayout2 = new QHBoxLayout();
	//m_findPersonBtn = new QPushButton();
	//m_findGroupBtn = new QPushButton();

	//m_findPersonBtn->setFixedSize(100,30);
	//m_findGroupBtn->setFixedSize(100,30);

	//m_hLayout2->addStretch();
	//m_hLayout2->addWidget(m_findPersonBtn);
	//m_hLayout2->addWidget(m_findGroupBtn);
	//m_hLayout2->addStretch();

	//m_findPersonBtn->setText(QString::fromLocal8Bit("找人"));
	//m_findGroupBtn->setText(QString::fromLocal8Bit("找群"));

	//m_findPersonBtn->setStyleSheet("background-color:#1aad19;border-style: none;");
	//m_findGroupBtn->setStyleSheet("background-color:#1aad19;border-style: none;");

	//m_vLayout->addLayout(m_hLayout2);

	m_hLayout2 = new QHBoxLayout();
	m_searchEdit = new QLineEdit();
	m_findPersonChx = new QCheckBox();
	m_findPersonChx->setText(QString::fromLocal8Bit("找人"));
	m_findGroupChx = new QCheckBox();
	m_findGroupChx->setText(QString::fromLocal8Bit("找群"));
	m_searchBtn = new QPushButton();

	m_searchEdit->setFixedSize(350, 30);

	m_hLayout2->addWidget(m_searchEdit);
	//m_hLayout3->addSpacing(100);
	m_hLayout2->addWidget(m_findPersonChx);
	m_hLayout2->addWidget(m_findGroupChx);

	m_hLayout2->addSpacing(15);

	m_hLayout2->addWidget(m_searchBtn);

	m_hLayout2->addStretch();

	//m_searchBtn->setFixedHeight(30);
	//m_searchEdit->setFixedHeight(30);
	m_searchBtn->setText(QString::fromLocal8Bit("查找"));
	m_searchBtn->setFixedSize(100, 30);
	m_searchBtn->setStyleSheet("background-color:#1aad19;border-style: none;");

	m_vLayout->addLayout(m_hLayout2);

	QSimpleSplit* pSplitWnd2 = new QSimpleSplit(this);
	m_vLayout->addWidget(pSplitWnd2);
	
	m_listWidget = new QListWidget(this);
	m_listWidget->setFixedHeight(330);
	m_listWidget->setStyleSheet("border:0px");
	m_vLayout->addWidget(m_listWidget);

	for (int i = 0; i < 10; i++) {
		QString str1 = QString(QString::fromLocal8Bit("添加新的朋友%1号")).arg(i);
		addFriendItem("./img/head2.png", str1.toLocal8Bit().data());
	}

	m_vLayout->addStretch();


	connect(m_minBtn, SIGNAL(clicked()), this, SLOT(minWnd()));
	connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(closeWnd()));

	////设置滚动条的样式
	m_listWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,0%);"
		"margin:0px,0px,0px,0px;"
		"padding-top:9px;"
		"padding-bottom:9px;"
		"}"
		"QScrollBar::handle:vertical"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,25%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::handle:vertical:hover"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,50%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::add-line:vertical"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/3.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/1.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-line:vertical:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/4.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/2.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical"
		"{"
		"background:rgba(0,0,0,10%);"
		"border-radius:4px;"
		"}"
	);


	m_listWidget->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,0%);"
		"margin:0px,0px,0px,0px;"
		"padding-top:9px;"
		"padding-bottom:9px;"
		"}"
		"QScrollBar::handle:horizontal"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,25%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::handle:horizontal:hover"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,50%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::add-line:horizontal"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/3.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:horizontal"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/1.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-line:horizontal:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/4.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:horizontal:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a/2.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal"
		"{"
		"background:rgba(0,0,0,10%);"
		"border-radius:4px;"
		"}"
	);

}

void QFindFriendOrGroupWnd::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bPress)
	{
		move(event->pos() - m_poPress + pos());
	}
}

void QFindFriendOrGroupWnd::mousePressEvent(QMouseEvent* event)
{
	m_bPress = true;
	m_poPress = event->pos();
}

void QFindFriendOrGroupWnd::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	m_bPress = false;
}

void QFindFriendOrGroupWnd::addFriendItem(const char* headUrl, const char* name)
{
	//添加好友
	QFindFriendItemWnd* pMsgItem = new QFindFriendItemWnd(m_listWidget, headUrl, name);
	QListWidgetItem* pListItem = new QListWidgetItem(m_listWidget);
	pMsgItem->setFixedWidth(this->width() - 5);
	pListItem->setSizeHint(QSize(this->width() - 5, 65));
	m_listWidget->setItemWidget(pListItem, pMsgItem);
}

void QFindFriendOrGroupWnd::closeWnd()
{
	hide();
}

void QFindFriendOrGroupWnd::minWnd()
{
	showMinimized();
}

