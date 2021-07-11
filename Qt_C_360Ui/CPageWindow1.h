#pragma once

#include "CPageWindow.h"

class CPageWindow1 : public CPageWindow
{
	Q_OBJECT
public:
	CPageWindow1(QWidget* p = nullptr);

	void paintEvent(QPaintEvent* event);
};