#pragma once

#include "CPageWindow.h"

class CPageWindow2 : public CPageWindow
{
public:
	CPageWindow2(QWidget* p = nullptr);


	void paintEvent(QPaintEvent* event);
};