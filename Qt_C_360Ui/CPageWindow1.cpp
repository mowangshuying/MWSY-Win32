#include "CPageWindow1.h"

#include <QPainter>

CPageWindow1::CPageWindow1(QWidget* p /*= nullptr*/) : CPageWindow(p)
{

}

void CPageWindow1::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);
	QPainter p(this);
	p.setPen(Qt::NoPen);
	p.setBrush(Qt::white);
	p.drawRect(rect());
	p.drawPixmap(84, 80, 230, 220, QPixmap(":/image/box.png"));
	p.drawPixmap(350, 100, 510, 100, QPixmap(":/image/String.png"));
}

