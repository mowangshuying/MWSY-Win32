

/* Ӧ�ó�������� */
#include <QApplication>

/*������*/
#include <QWidget>

/*��ǩ*/
#include <QLabel>

/*��ť*/
#include <QPushButton>
#include <QLineEdit>

/*����*/
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	/* ����һ������*/
	QWidget w;

#if 0
	/* ��ťҲ�Ǹ����� */
	QPushButton button;
	button.setText("Button");
	/* ���ڶ���ĸ��ӹ�ϵ��Ӱ����ʾλ�� */
	/* û�и����ڵĴ��ڣ����ǳ�֮Ϊ������ */
 //   button.setParent(&w);
	button.show();

	QLineEdit edit;
	edit.setParent(&w);


	QHBoxLayout layout;
	layout.addStretch(1);//(�ܳ���-100)/4
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

	layout.setRowStretch(0, 1);//�������ֵ
	//layout.setRowStretch(1, 2);
	//layout.setRowStretch(2, 1);
	//layout.setRowStretch(3, 1);
	layout.setRowStretch(4, 1);

	layout.setColumnStretch(0, 1);
	//layout.setColumnStretch(1, 1);
	//layout.setColumnStretch(2, 1);
	layout.setColumnStretch(3, 1);//����-����ֵ

	//�����ڿؼ�����ĳ��������
	layout.addWidget(new QLabel("Username:"), 1, 1);
	layout.addWidget(new QLineEdit(), 1, 2);
	layout.addWidget(new QLabel("Password:"), 2, 1);
	layout.addWidget(password = new QLineEdit(), 2, 2);

	//��ˮƽ���ֿؼ��������񲼾ֿؼ���
	QHBoxLayout* hBox;
	layout.addLayout(hBox = new QHBoxLayout, 3, 2);
	hBox->addStretch(2);//�հ׵ط��������
	hBox->addWidget(new QPushButton("Login"));
	hBox->addStretch(1);//�հ׵ط��������
	password->setEchoMode(QLineEdit::Password);

	/*��ʾ����*/
	w.show();
	w.setLayout(&layout);


	/* QT��C++����չ */
	// std::bind std::function
//    QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));

	w.setWindowTitle("Hello World");

	/*��exec����һ����Ϣѭ��*/
	return app.exec();
}

