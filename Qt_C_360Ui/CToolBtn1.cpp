#include <QPalette>
#include <QColor>
#include <QFont>

#include "CToolBtn1.h"


CToolBtn1::CToolBtn1(const QString& strImage,const  QString& strInfo)
{
	//�����ı���ɫ
	QPalette objPalette = palette();
	objPalette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
	setPalette(objPalette);

	//�ı�������ʾ
	QFont& objFont = const_cast<QFont&>(font());
	objFont.setWeight(QFont::Bold);

	//��ʽ
	setStyleSheet("QToolButton{border:0px;}");

	//��С
	setIconSize(QSize(ToolBtn1_Icon_WH, ToolBtn1_Icon_WH));
	this->setFixedSize(ToolBtn1_W,ToolBtn1_H);
	setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	//����ͼ���ı�
	setIcon(QPixmap(strImage));
	setText(strInfo);
}

