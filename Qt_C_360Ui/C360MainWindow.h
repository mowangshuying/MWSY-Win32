#pragma once

#include <QKeyEvent>
#include <QMouseEvent>
#include <QWidget>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QPoint>

#include <QApplication>

#include "CTopWindow.h"
#include "CPageWindow.h"
#include "CPageWindow1.h"
#include "CPageWindow2.h"


class C360MainWindow : public QWidget
{
	Q_OBJECT

public:
	C360MainWindow(QWidget* p = nullptr);
public slots:
	void close();
	void min();
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
public:
	CTopWindow *m_pTopWindow;
	QStackedLayout *m_pSLayout;
	QVBoxLayout *m_pVLayout;
	QPoint m_poPress;
	CPageWindow* m_pPage1;
	CPageWindow* m_pPage2;
	bool m_bPress;
};