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
	//添加文本信息
	edit.insertPlainText("\nzzz");
	//清除文本信息
	//edit.clear();

	//隐藏
	edit.hide();
	//显示
	edit.show();

	w.show();

	app.exec();
}
