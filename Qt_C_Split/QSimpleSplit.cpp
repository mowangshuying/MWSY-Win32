#include "QSimpleSplit.h"

QSimpleSplit::QSimpleSplit(QWidget* p /*= nullptr*/)
{
	setAttribute(Qt::WA_StyledBackground);
	//����һЩ��ʽ
	//�޽���
	setFocusPolicy(Qt::NoFocus);
	//���ø߶�Ϊ2
	setFixedHeight(20);
	//���÷ָ��ߵ���ɫ
	setStyleSheet("background-color:blue;border: 1px solid red");
}

