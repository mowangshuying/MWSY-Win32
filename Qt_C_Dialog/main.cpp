#include <QApplication>
#include <QDialog>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QDialog w;
	w.show();

	app.exec();
}