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
	bar.setOrientation(Qt::Horizontal);  // 水平方向
	bar.setMinimum(0);  // 最小值
	bar.setMaximum(100);  // 最大值
	bar.setValue(50);  // 当前进度
	bar.setGeometry(50, 50, 200, 8);//设置进度条位置

	/*设置样式表*/
	//bar.setStyleSheet("QProgressBar{border: none;color: white;text - align: center;background: rgb(68, 69, 73);} \
			//QProgressBar::chunk{border: none;background: rgb(0, 160, 230)};");

	w.show();

	app.exec();
}