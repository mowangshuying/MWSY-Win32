#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>

class QCommListWnd : public QWidget
{
	//添加消息映射支持
	Q_OBJECT
public:
	QCommListWnd(QWidget* p = nullptr);
public:
	QVBoxLayout* m_vLayout;
	QHBoxLayout* m_hLayout;
	
	QLineEdit* m_searchEdit;
	QPushButton* m_startGroupBtn;

	QListWidget* m_listWidget;
};