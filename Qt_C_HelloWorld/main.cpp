#include <QtWidgets/QApplication>
#include <QDebug>
#include <QtWidgets/QWidget>
/*
* �½��յ�qt��Ŀ��������
* 
* ���û��������ģ��֧�� widget core gui
* 
* ���ͷ�ļ�:��QDebug ����QtWidgets/QWidget
* 
* ����ģʽ�£���������л���� hello world
*/
int main(int argc, char* argv[])
{
	QApplication app(argc,argv);
	QWidget w;
	w.show();
	//ֻ�ڵ���״̬�²Ż����
	qDebug()<< "hello,world";
	app.exec();
}