#pragma once


#include <QWidget>
#include <QHBoxLayout>
#include <QStackedLayout>

#include "QToolWnd.h"
#include "QCommListWnd.h"
#include "QSessionWnd.h"

class QMainWnd : public QWidget
{
	//�����Ϣӳ��֧��
	Q_OBJECT
public:
	//�Ự����
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
	QCommListWnd* m_commMsgListWnd;
	QCommListWnd* m_commContactsListWnd;
	QSessionWnd* m_sessionWnd;

	QStackedLayout *m_sLayout1;
	QStackedLayout* m_sLayout2;

	bool m_bPress = false;
	QPoint m_poPress;
};