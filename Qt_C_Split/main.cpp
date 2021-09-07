
#include <QApplication>

#include <QWidget>

#include <QVBoxLayout>
#include <QPushButton>

#include "QSimpleSplit.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QWidget w;

	w.setFixedSize(500, 500);

	QVBoxLayout* vLayout = new QVBoxLayout();
	w.setLayout(vLayout);

	w.setAttribute(Qt::WA_StyledBackground);

	QPushButton btn1;
	QPushButton btn2;
	QPushButton btn3;

	vLayout->addWidget(&btn1);

	vLayout->addWidget(new QSimpleSplit());

	vLayout->addWidget(&btn2);

	vLayout->addWidget(&btn3);

	w.show();
	app.exec();
}