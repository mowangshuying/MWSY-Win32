#include<QApplication>
#include<QWidget>
#include<QTextEdit>


int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	QWidget w;
	w.setGeometry(50, 50, 500, 500);

	QTextEdit edit;
	edit.setReadOnly(true);
	edit.setGeometry(50, 50, 400, 400);
	//edit.show();
	edit.setParent(&w);
	edit.append("xxx");
	edit.append("yyy");
	//����ı���Ϣ
	edit.insertPlainText("\nzzz");
	//����ı���Ϣ
	//edit.clear();

	//����
	edit.hide();
	//��ʾ
	edit.show();

	w.show();

	app.exec();
}
