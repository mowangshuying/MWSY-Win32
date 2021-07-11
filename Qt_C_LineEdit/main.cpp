#include <QtWidgets/QApplication>
#include<QtWidgets/QWidget>
#include <QCompleter>
#include <QLineEdit>
#include <QDebug>


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	QWidget w;
	w.setWindowTitle("LineEdit");
	//w.setFixedSize(500, 500);
	w.setGeometry(50, 50, 500, 500);

	QLineEdit edit;
	edit.show();
	edit.setParent(&w);
	edit.setGeometry(50, 50, 150, 20);

	// 输入密码
	//edit.setEchoMode(QLineEdit::Password);
	//edit.text();
	edit.setPlaceholderText("Please input text:");

	//设置匹配
	//QCompleter cp(QStringList()<<"aab"<<"123"<<"998");
	//cp.setFilterMode(Qt::MatchContains);
	//edit.setCompleter(&cp);

	//设置输入框内文本
	edit.setText("xxxxxxx");

	//打印输入框内的文本
	qDebug() << edit.text();

	w.show();

	app.exec();
}

