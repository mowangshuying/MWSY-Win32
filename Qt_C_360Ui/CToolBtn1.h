#pragma once

#include <QToolButton>

#define ToolBtn1_Icon_WH 42
#define ToolBtn1_W 83
#define ToolBtn1_H 90

class CToolBtn1 : public QToolButton
{
	Q_OBJECT
public:
	CToolBtn1(const QString& strImage,const QString& strInfo);

};

