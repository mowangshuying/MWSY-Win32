#include "QCreateGroupWnd.h"
#include "QSimpleSplit.h"

QCreateGroupWnd::QCreateGroupWnd(QWidget* p /*= nullptr*/)
	: QWidget(p)
{
	m_hLayout = new QHBoxLayout();
	setLayout(m_hLayout);
	setFixedSize(600, 400);

	m_vLayout1 = new QVBoxLayout();
	m_serchEdit = new QLineEdit();
	m_listWnd1 = new QListWidget();

	m_serchEdit->setFixedWidth(280);

	m_vLayout1->addWidget(m_serchEdit);
	m_vLayout1->addWidget(m_listWnd1);
	m_hLayout->addLayout(m_vLayout1);

	QSimpleSplit* sp = new QSimpleSplit(nullptr, QSimpleSplit::QSimpleSplit_direction_h);
	m_hLayout->addWidget(sp);

	m_vLayout2 = new QVBoxLayout();
	m_hasSelLabel = new QLabel();
	m_listWnd2 = new QListWidget();
	m_groupNameEdit = new QLineEdit();
	
	m_hasSelLabel->setText(QString::fromLocal8Bit("已选联系人：1"));
	m_listWnd2->setFixedHeight(300);


	m_hLayout1 = new QHBoxLayout();
	m_comfirmBtn = new QPushButton();
	
	m_comfirmBtn->setText(QString::fromLocal8Bit("确认"));

	m_hLayout1->addStretch();
	m_hLayout1->addWidget(m_comfirmBtn);

	m_vLayout2->addWidget(m_hasSelLabel);
	m_vLayout2->addWidget(m_listWnd2);
	m_vLayout2->addStretch();
	m_vLayout2->addWidget(m_groupNameEdit);
	m_vLayout2->addLayout(m_hLayout1);

	m_hLayout->addLayout(m_vLayout2);
}

