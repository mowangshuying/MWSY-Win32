#include "QCreateGroupWnd.h"
#include "QSimpleSplit.h"

#include "QCreateGroupListwnd1Item.h"
#include "QCreateGroupListwnd2Item.h"

#include <QMouseEvent>
#include <QDebug>
#include <QScrollBar>

QCreateGroupWnd::QCreateGroupWnd(QWidget* p /*= nullptr*/)
	: QWidget(p)
{
	m_vLayout = new QVBoxLayout(this);
	setLayout(m_vLayout);
	setFixedSize(600, 400);
	setWindowFlags(Qt::FramelessWindowHint);

	m_hLayout1 = new QHBoxLayout();
	m_titleLabel = new QLabel(this);
	m_minBtn = new QPushButton(this);
	m_closeBtn = new QPushButton(this);
	m_titleLabel->setText(QString::fromLocal8Bit("创建群聊"));
	m_minBtn->setIcon(QPixmap("./img/minWnd.png"));
	m_minBtn->setIconSize(QSize(20, 20));
	m_minBtn->setFixedSize(20, 20);
	m_closeBtn->setIcon(QPixmap("./img/closeWnd.png"));
	m_closeBtn->setIconSize(QSize(20, 20));
	m_closeBtn->setFixedSize(20, 20);
	m_hLayout1->addWidget(m_titleLabel);
	m_hLayout1->addStretch();
	m_hLayout1->addWidget(m_minBtn);
	m_hLayout1->addWidget(m_closeBtn);

	m_vLayout->addLayout(m_hLayout1);


	m_hLayout2 = new QHBoxLayout();
	m_vLayout1 = new QVBoxLayout();
	m_serchEdit = new QLineEdit();
	m_listWnd1 = new QListWidget();

	m_listWnd1->setContentsMargins(0, 0, 0, 0);
	m_listWnd1->setFixedHeight(300);

	m_serchEdit->setFixedWidth(280);
	m_serchEdit->setPlaceholderText(QString::fromLocal8Bit("输入查找关键字`-`"));

	m_vLayout1->addWidget(m_serchEdit);
	m_vLayout1->addWidget(m_listWnd1);
	m_hLayout2->addLayout(m_vLayout1);

	QSimpleSplit* sp = new QSimpleSplit(nullptr, QSimpleSplit::QSimpleSplit_direction_h);
	m_hLayout2->addWidget(sp);

	m_vLayout2 = new QVBoxLayout();
	m_hasSelLabel = new QLabel();
	m_listWnd2 = new QListWidget();
	m_groupNameEdit = new QLineEdit();
	
	m_hasSelLabel->setText(QString::fromLocal8Bit("已选联系人:0"));
	m_listWnd2->setFixedHeight(280);

	m_groupNameEdit->setPlaceholderText(QString::fromLocal8Bit("请输入群名称`-`"));

	m_hLayout3 = new QHBoxLayout();
	m_comfirmBtn = new QPushButton();
	
	m_comfirmBtn->setText(QString::fromLocal8Bit("确认"));

	m_hLayout3->addStretch();
	m_hLayout3->addWidget(m_comfirmBtn);

	m_vLayout2->addWidget(m_hasSelLabel);
	m_vLayout2->addWidget(m_listWnd2);
	m_vLayout2->addStretch();
	m_vLayout2->addWidget(m_groupNameEdit);
	m_vLayout2->addLayout(m_hLayout3);

	m_hLayout2->addLayout(m_vLayout2);
	m_vLayout->addLayout(m_hLayout2);

	///
	for (int i = 0; i < 5; i++) {
		QString str1 = QString(QString::fromLocal8Bit("角色%1号")).arg(i);
		//QString str1 = QString(QString::fromLocal8Bit("添加新的朋友%1号")).arg(i);
		QString str2 = QString(QString::fromLocal8Bit("0000000%1")).arg(i);
		addListWnd1Item("./img/head2.png", str1.toLocal8Bit().data(),str2.toLocal8Bit().data());
	}


	connect(m_minBtn, SIGNAL(clicked()), this, SLOT(minWnd()));
	connect(m_closeBtn, SIGNAL(clicked()), this, SLOT(closeWnd()));


	////设置滚动条的样式
	m_listWnd1->verticalScrollBar()->setStyleSheet("QScrollBar:vertical"
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


	m_listWnd1->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal"
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

	////设置滚动条的样式
	m_listWnd2->verticalScrollBar()->setStyleSheet("QScrollBar:vertical"
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


	m_listWnd2->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal"
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

void QCreateGroupWnd::mouseMoveEvent(QMouseEvent* event)
{
	if (m_bPress)
	{
		move(event->pos() - m_poPress + pos());
	}
}

void QCreateGroupWnd::mousePressEvent(QMouseEvent* event)
{
	m_bPress = true;
	m_poPress = event->pos();
}

void QCreateGroupWnd::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	m_bPress = false;
}

void QCreateGroupWnd::addListWnd1Item(const char* headUrl, const char* nickname, const char* rolename)
{
	QCreateGroupListwnd1Item* pListwnd1Item = new QCreateGroupListwnd1Item(m_listWnd1, headUrl, nickname,rolename);
	QListWidgetItem* pListItem = new QListWidgetItem(m_listWnd1);
    pListItem->setSizeHint(QSize(275,35));
	m_listWnd1->setItemWidget(pListItem, pListwnd1Item);

	connect(pListwnd1Item, SIGNAL(signal_selRBtnClick(QMap<QString,QString>)), 
		this, SLOT(slot_selRBtnClick(QMap<QString,QString>)));
}

void QCreateGroupWnd::addListWnd2Item(const char* headUrl, const char* nickname, const char* rolename)
{
	QCreateGroupListwnd2Item* pListwnd2Item = new QCreateGroupListwnd2Item(m_listWnd2, headUrl, nickname, rolename);
	QListWidgetItem* pListItem = new QListWidgetItem(m_listWnd2);
	pListItem->setSizeHint(QSize(275, 35));
	m_listWnd2->setItemWidget(pListItem, pListwnd2Item);
}

bool QCreateGroupWnd::hasThisWndByRolename(QString rolename,QListWidget* listWnd)
{
	bool bHas = false;
	if (listWnd == nullptr) {
		return bHas;
	}

	for (int i = 0; i < listWnd->count(); i++) {
		QListWidgetItem *item = listWnd->item(i);
		if (listWnd == m_listWnd1) {
			QCreateGroupListwnd1Item* wnd = dynamic_cast<QCreateGroupListwnd1Item*>(listWnd->itemWidget(item));
			if (wnd->m_roleName->text() == rolename) {
				bHas = true;
				break;
			}
		}

		if (listWnd == m_listWnd2) {
			QCreateGroupListwnd2Item* wnd = dynamic_cast<QCreateGroupListwnd2Item*>(listWnd->itemWidget(item));
			if (wnd->m_roleName->text() == rolename) {
				bHas = true;
				break;
			}
		}
	}
	return bHas;
}

void QCreateGroupWnd::delThisWndByRolename(QString rolename, QListWidget* listWnd)
{
	for (int i = 0; i < listWnd->count(); i++) {
		QListWidgetItem* item = listWnd->item(i);
		if (listWnd == m_listWnd1) {
			QCreateGroupListwnd1Item* wnd = dynamic_cast<QCreateGroupListwnd1Item*>(listWnd->itemWidget(item));
			if (wnd->m_roleName->text() == rolename) {
				listWnd->takeItem(i);
				break;
			}
		}

		if (listWnd == m_listWnd2) {
			QCreateGroupListwnd2Item* wnd = dynamic_cast<QCreateGroupListwnd2Item*>(listWnd->itemWidget(item));
			if (wnd->m_roleName->text() == rolename) {
				//listWnd->removeItemWidget(item);
				listWnd->takeItem(i);
				break;
			}
		}
	}
}

void QCreateGroupWnd::closeWnd()
{
	hide();
}

void QCreateGroupWnd::minWnd()
{
	showMinimized();
}

void QCreateGroupWnd::slot_selRBtnClick(QMap<QString, QString> map)
{
	//qDebug() << "map" << map;
	if (map["isSel"] == "true") {
		if (hasThisWndByRolename(map["rolename"], m_listWnd2) == false) {
			addListWnd2Item(map["headimg"].toLocal8Bit().data(),
				map["nickname"].toLocal8Bit().data(), map["rolename"].toLocal8Bit().data());
		}
	}
	else {
		delThisWndByRolename(map["rolename"], m_listWnd2);
	}

	//获取m_listwnd2中含有的项目数量，修改lable中的内容
	QString str = QString(QString::fromLocal8Bit("已选联系人:%1")).arg(m_listWnd2->count());
	m_hasSelLabel->setText(str);
}





