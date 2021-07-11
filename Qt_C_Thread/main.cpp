#include <QApplication>

#include "MyWidget.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	MyWidget w;

	w.show();

	app.exec();


	return 0;
}