#include "QSimpleSplit.h"

QSimpleSplit::QSimpleSplit(QWidget* p /*= nullptr*/, QSimpleSplit_direction d/* = QSimpleSplit_direction_v*/)
{
	setAttribute(Qt::WA_StyledBackground);
	//����һЩ��ʽ
	//�޽���
	setFocusPolicy(Qt::NoFocus);
	if (d == QSimpleSplit_direction_v) {
		//���ø߶�Ϊ2
		setFixedHeight(2);
	}
	else {
		setFixedWidth(2);
	}
	//���÷ָ��ߵ���ɫ
	setStyleSheet("background-color:red;border:none");
}

