#include <QWidget>
#include <QDebug>
#include <QApplication>
#include <QComboBox>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

	QWidget w;
	w.setGeometry(50, 50, 500, 500);

	QComboBox cBox;
	cBox.setParent(&w);
	cBox.setGeometry(50, 50, 100, 20);

	cBox.addItem("aaa");
	cBox.addItem("bbb");
	cBox.addItem("ccc");

	qDebug() << "curText:" << cBox.currentText() ;
	qDebug() << "curIndex:" << cBox.currentIndex();

	w.show();


	app.exec();
}