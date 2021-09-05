#pragma once


#include <QWidget>
#include <QHBoxLayout>

#include "QToolWnd.h"
#include "QCommListWnd.h"
#include "QSessionWnd.h"

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
public:
	QHBoxLayout* m_hLayout;
	QToolWnd* m_toolWnd;
	QCommListWnd* m_commListWnd;
	QSessionWnd* m_sessionWnd;

	bool m_bPress = false;
	QPoint m_poPress;
};