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
	enum QCommListWndEnum
	{
		QCommMsgItemWnd_Tpye = 0,
		QCommContactItemWnd_Type
	};

	QCommListWnd(QWidget* p = nullptr, QCommListWndEnum wndType = QCommMsgItemWnd_Tpye);

public:
	void addMsgItem(const char* headUrl, const char* name, const char* msg);
	void addContactsItem(const char* headUrl, const char* name);

	QVBoxLayout* m_vLayout;
	QHBoxLayout* m_hLayout;

	QLineEdit* m_searchEdit;
	QPushButton* m_startGroupBtn;
	
	QListWidget* m_listWidget;

	QCommListWndEnum m_WndType;
};