#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMap>
#include <QString>

#include "QSelectWnd1.h"

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

signals:
	void commListChanged(int num);
	void signal_commListChangedAndSendInfo(QMap<QString,QString> infoMap);
	//void signal_test();
public slots:
	void onCurrentItemClicked(QListWidgetItem* item);
	//如果点击那个按钮的话
	void onStartGroupBtnClicked();
public:
	QListWidgetItem* addMsgItem(const char* headUrl, const char* name, const char* msg,qint64 sesid);
	void addContactsItem(const char* headUrl, const char* name);


	QVBoxLayout* m_vLayout;
	QHBoxLayout* m_hLayout;

	//搜索框
	QLineEdit* m_searchEdit;
	//开始的那个按钮
	QPushButton* m_startGroupBtn;

	QSelectWnd1* m_selectWnd1;

	QListWidget* m_listWidget;
	//窗口类型
	QCommListWndEnum m_WndType;
};