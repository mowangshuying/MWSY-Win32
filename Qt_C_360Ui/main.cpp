#include <vld.h>
#include <QApplication>
#include "C360MainWindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc,argv);

	C360MainWindow w;

	w.show();

	app.exec();
}