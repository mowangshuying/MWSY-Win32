#include "QSimpleSplit.h"

QSimpleSplit::QSimpleSplit(QWidget* p /*= nullptr*/)
{
	setAttribute(Qt::WA_StyledBackground);
	//����һЩ��ʽ
	//�޽���
	setFocusPolicy(Qt::NoFocus);
	//���ø߶�Ϊ2
	setFixedHeight(1);
	//���÷ָ��ߵ���ɫ
	setStyleSheet("background-color:blue");
}

