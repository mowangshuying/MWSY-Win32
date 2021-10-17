#pragma once

#include <map>
#include <QWidget>
#include <QHBoxLayout>
#include <QStackedLayout>

#include "QToolWnd.h"
#include "QCommListWnd.h"
#include "QSessionWnd.h"
#include "QCommContactInfo.h"

class QMainWnd : public QWidget
{
	//添加消息映射支持
	Q_OBJECT
public:
	//会话窗口
	QMainWnd(QWidget* p = nullptr);

public slots:
	void closeWnd();
	void minWnd();
	void maxWnd();

	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

	void slot_sesIdToIndex(int sesid);
	void slot_createSesAndSelect(QMap<QString, QString> infoMap);
	void slot_toolWndPageChanged(int page);
public:
	QHBoxLayout* m_hLayout;
	QToolWnd* m_toolWnd;

	QCommListWnd* m_commMsgListWnd;
	QCommListWnd* m_commContactsListWnd;
	
	QCommContactInfo* m_commContactInfo;

	QSessionWnd* m_sessionWnd;
	QStackedLayout *m_sLayout1;
	QStackedLayout* m_sLayout2;

	int m_lastSesId = -1;
	int m_lastContactId = -1;

	int m_currentSesId = 0;

	bool m_bPress = false;
	QPoint m_poPress;
};