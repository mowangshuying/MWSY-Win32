#include "CPageWindow2.h"

#include <Qpainter>

CPageWindow2::CPageWindow2(QWidget* p /*= nullptr*/) : CPageWindow(p)
{

}

void CPageWindow2::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);
	QPainter p(this);
	p.setPen(Qt::NoPen);
	p.setBrush(Qt::white);
	p.drawRect(rect());
	p.drawPixmap(84, 80, 230, 220, QPixmap(":/image/circlepage2.png"));
}

