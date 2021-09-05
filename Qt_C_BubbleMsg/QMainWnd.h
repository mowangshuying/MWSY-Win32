#pragma once


#include <QWidget>
#include <QHBoxLayout>

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
	QCommListWnd* m_commListWnd;
	QSessionWnd* m_sessionWnd;

	bool m_bPress = false;
	QPoint m_poPress;
};