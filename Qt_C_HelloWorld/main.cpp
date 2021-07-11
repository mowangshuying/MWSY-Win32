#include <QtWidgets/QApplication>
#include <QDebug>
#include <QtWidgets/QWidget>
/*
* 新建空的qt项目，并命名
* 
* 设置环境：添加模块支持 widget core gui
* 
* 添加头文件:如QDebug 或者QtWidgets/QWidget
* 
* 调试模式下：输出窗口中会输出 hello world
*/
int main(int argc, char* argv[])
{
	QApplication app(argc,argv);
	QWidget w;
	w.show();
	//只在调试状态下才会输出
	qDebug()<< "hello,world";
	app.exec();
}