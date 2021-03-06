

/* 应用程序抽象类 */
#include <QApplication>

/*窗口类*/
#include <QWidget>

/*标签*/
#include <QLabel>

/*按钮*/
#include <QPushButton>
#include <QLineEdit>

/*布局*/
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	/* 构造一个窗口*/
	QWidget w;

#if 0
	/* 按钮也是个窗口 */
	QPushButton button;
	button.setText("Button");
	/* 窗口对象的父子关系，影响显示位置 */
	/* 没有父窗口的窗口，我们称之为主窗口 */
 //   button.setParent(&w);
	button.show();

	QLineEdit edit;
	edit.setParent(&w);


	QHBoxLayout layout;
	layout.addStretch(1);//(总长度-100)/4
	layout.addWidget(&button, 1);
	layout.addSpacing(100);//
	layout.addWidget(&edit, 1);
	layout.addStretch(1);
#endif

	//QGridLayout layout;
	//layout.setColumnStretch(3, 1);
	//layout.setRowStretch(4, 1);
	//layout.setColumnStretch(0, 1);
	//layout.setRowStretch(0, 1);

	//layout.addWidget(&button, 1, 1);
	//layout.addWidget(&edit, 1, 2);
	//layout.addWidget(new QPushButton("1, 0"), 2, 1);
	//layout.addWidget(new QPushButton("1, 1"), 2, 2);

	//layout.addWidget(new QPushButton("aaa"), 3, 1, 1, 2);


	QGridLayout layout;

	QLineEdit* password;

	layout.setRowStretch(0, 1);//行码比列值
	//layout.setRowStretch(1, 2);
	//layout.setRowStretch(2, 1);
	//layout.setRowStretch(3, 1);
	layout.setRowStretch(4, 1);

	layout.setColumnStretch(0, 1);
	//layout.setColumnStretch(1, 1);
	//layout.setColumnStretch(2, 1);
	layout.setColumnStretch(3, 1);//列码-比例值

	//将窗口控件放入某个格子中
	layout.addWidget(new QLabel("Username:"), 1, 1);
	layout.addWidget(new QLineEdit(), 1, 2);
	layout.addWidget(new QLabel("Password:"), 2, 1);
	layout.addWidget(password = new QLineEdit(), 2, 2);

	//将水平布局控件放入网格布局控件中
	QHBoxLayout* hBox;
	layout.addLayout(hBox = new QHBoxLayout, 3, 2);
	hBox->addStretch(2);//空白地方填充数据
	hBox->addWidget(new QPushButton("Login"));
	hBox->addStretch(1);//空白地方填充数据
	password->setEchoMode(QLineEdit::Password);

	/*显示窗口*/
	w.show();
	w.setLayout(&layout);


	/* QT对C++的拓展 */
	// std::bind std::function
//    QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));

	w.setWindowTitle("Hello World");

	/*在exec中有一个消息循环*/
	return app.exec();
}

