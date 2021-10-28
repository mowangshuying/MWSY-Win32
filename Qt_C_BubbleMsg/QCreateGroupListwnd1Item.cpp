#include "QCreateGroupListwnd1Item.h"

#include <QDebug>

QCreateGroupListwnd1Item::QCreateGroupListwnd1Item(QWidget* p /*= nullptr*/)
	:QWidget(p)
{
	m_hLayout = new QHBoxLayout();
	setLayout(m_hLayout);

	m_headImage = new QLabel();
	m_nickName = new QLabel();
	m_roleName = new QLabel();
	m_selRBtn = new QRadioButton();

	m_nickName->setText(" nickname ");
	m_roleName->setText(" (0123456) ");

	m_hLayout->addWidget(m_headImage);
	m_hLayout->addWidget(m_nickName);
	m_hLayout->addWidget(m_roleName);
	m_hLayout->addWidget(m_selRBtn);
}

QCreateGroupListwnd1Item::QCreateGroupListwnd1Item(QWidget* p,const char* headimg, const char* nickname, const char* rolename)
	: QWidget(p)
{

	m_hLayout = new QHBoxLayout();
	m_hLayout->setAlignment(Qt::AlignHCenter);
	setLayout(m_hLayout);
	setFixedSize(275, 30);
	setWindowFlags(Qt::FramelessWindowHint);
	setContentsMargins(0, 0, 0, 0);

	m_headImage = new QLabel();
	m_nickName = new QLabel();
	m_roleName = new QLabel();
	m_selRBtn = new QRadioButton();

	m_nickName->setText(QString::fromLocal8Bit(nickname));
	m_roleName->setText(QString::fromLocal8Bit(rolename));

	m_headImgStr = headimg;
	QPixmap pixmap1 = QPixmap(headimg);
	QPixmap pixmap2 = pixmap1.scaled(25,25, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	m_headImage->setPixmap(QPixmap(headimg));
	m_headImage->setFixedSize(25,25);



	m_hLayout->addWidget(m_headImage);
	m_hLayout->addWidget(m_nickName);
	m_hLayout->addWidget(m_roleName);
	m_hLayout->addStretch();
	m_hLayout->addWidget(m_selRBtn);

	connect(m_selRBtn, SIGNAL(clicked(bool)), this, SLOT(slot_clickedSelBtn(bool)));
}

void QCreateGroupListwnd1Item::slot_clickedSelBtn(bool isSel/* = false*/)
{
	qDebug() << "isSel"<<isSel;

	QMap<QString, QString> sMap;

	sMap["headimg"] = m_headImgStr;
	sMap["nickname"] = m_nickName->text();
	sMap["rolename"] = m_roleName->text();
	if (isSel) {
		sMap["isSel"] = "true";
	}
	else {
		sMap["isSel"] = "false";
	}
	emit signal_selRBtnClick(sMap);
}

