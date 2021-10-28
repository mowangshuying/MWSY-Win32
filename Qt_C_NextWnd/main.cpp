#include <QApplication>

#include "QNextWnd.h"


int main(int argc,char** argv)
{
	QApplication app(argc, argv);

	QNextWnd w;
	w.show();

	app.exec();
}