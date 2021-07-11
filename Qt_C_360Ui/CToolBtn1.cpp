#include <QPalette>
#include <QColor>
#include <QFont>

#include "CToolBtn1.h"


CToolBtn1::CToolBtn1(const QString& strImage,const  QString& strInfo)
{
	//设置文本颜色
	QPalette objPalette = palette();
	objPalette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
	setPalette(objPalette);

	//文本粗体显示
	QFont& objFont = const_cast<QFont&>(font());
	objFont.setWeight(QFont::Bold);

	//样式
	setStyleSheet("QToolButton{border:0px;}");

	//大小
	setIconSize(QSize(ToolBtn1_Icon_WH, ToolBtn1_Icon_WH));
	this->setFixedSize(ToolBtn1_W,ToolBtn1_H);
	setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	//设置图像文本
	setIcon(QPixmap(strImage));
	setText(strInfo);
}

