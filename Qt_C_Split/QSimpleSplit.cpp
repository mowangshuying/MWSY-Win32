#include "QSimpleSplit.h"

QSimpleSplit::QSimpleSplit(QWidget* p /*= nullptr*/)
{
	setAttribute(Qt::WA_StyledBackground);
	//设置一些样式
	//无焦点
	setFocusPolicy(Qt::NoFocus);
	//设置高度为2
	setFixedHeight(1);
	//设置分割线的颜色
	setStyleSheet("background-color:blue");
}

