#include <vld.h>
#include <QApplication>
#include "CLoginWnd.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	CLoginWnd w;

	w.show();

	app.exec();
}