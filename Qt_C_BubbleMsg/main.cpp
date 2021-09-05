
#include <QApplication>
#include "QMainWnd.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	QMainWnd w;
	w.show();
	app.exec();
}