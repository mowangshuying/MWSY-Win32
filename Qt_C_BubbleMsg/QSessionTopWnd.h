#pragma once

#include<QWidget>
#include<QVBoxLayout>
#include <QPushButton>
#include <QLabel>
class QSessionTopWnd : public QWidget 
{
	//������Ϣӳ��֧��
	Q_OBJECT
public:
	//�Ự����
	QSessionTopWnd(QWidget* p = nullptr);
public:
	QVBoxLayout* m_vLayout;
	QHBoxLayout* m_hLayout1;
	QHBoxLayout* m_hLayout2;

	QPushButton* m_minBtn;
	QPushButton* m_maxBtn;
	QPushButton* m_closeBtn;

	QLabel* m_titleLabel;
	QPushButton* m_moreBtn;
};