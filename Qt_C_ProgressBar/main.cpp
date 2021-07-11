#include <QDebug>
#include <QStyle>
#include <QWidget>
#include <QApplication>
#include <QProgressBar>

int main(int argc, char** argv)
{
	QApplication app(argc,argv);

	QWidget w;
	w.setWindowTitle("ProgressBar");
	w.setGeometry(50, 50, 500, 500);

	QProgressBar bar;
	bar.setParent(&w);
	bar.setOrientation(Qt::Horizontal);  // ˮƽ����
	bar.setMinimum(0);  // ��Сֵ
	bar.setMaximum(100);  // ���ֵ
	bar.setValue(50);  // ��ǰ����
	bar.setGeometry(50, 50, 200, 8);//���ý�����λ��

	/*������ʽ��*/
	//bar.setStyleSheet("QProgressBar{border: none;color: white;text - align: center;background: rgb(68, 69, 73);} \
			//QProgressBar::chunk{border: none;background: rgb(0, 160, 230)};");

	w.show();

	app.exec();
}