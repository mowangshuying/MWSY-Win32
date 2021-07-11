#include <QApplication>
#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QDebug>

int main(int argc, char* argv[])
{
	QApplication app(argc,argv);

	QWidget w;
	w.setGeometry(50, 50, 500, 500);

	//按钮
	QPushButton btn;
	btn.setText("button");
	btn.setParent(&w);
	btn.setGeometry(30, 30, 100, 30);
	//信号与槽机制
	QObject::connect(&btn, SIGNAL(clicked()), &w, SLOT(close()));


	//单选按钮
	QRadioButton rBtn1;
	rBtn1.setText("rBtn1");
	rBtn1.setParent(&w);
	rBtn1.setGeometry(30, 80, 50, 30);

	QRadioButton rBtn2;
	rBtn2.setText("rBtn2");
	rBtn2.setParent(&w);
	rBtn2.setGeometry(30, 100, 50, 30);

	QRadioButton rBtn3;
	rBtn3.setText("rBtn3");
	rBtn3.setParent(&w);
	rBtn3.setGeometry(30, 120, 50, 30);

	QButtonGroup btnGroup;
	btnGroup.setParent(&w);
	btnGroup.addButton(&rBtn1);
	btnGroup.addButton(&rBtn2);
	btnGroup.addButton(&rBtn3);

	//指针转换
	void (QButtonGroup:: * pfnBtnClicked)(QAbstractButton*) = &QButtonGroup::buttonClicked;
	QObject::connect(&btnGroup,pfnBtnClicked, [&](QAbstractButton* pbtn) {
		qDebug()<<pbtn->text();
		//
		QList<QAbstractButton*> btnList = btnGroup.buttons();
		foreach (QAbstractButton *pBtn,btnList)
		{
			QString strStatus = pBtn->isChecked() ? "Checked" : "Unchecked";
			qDebug() << QString("Button : %1 is %2").arg(pbtn->text()).arg(strStatus);
		}
	});

	//QObject::connect(&rBtn1, &QRadioButton::clicked, [](bool v) {
	//	qDebug() << v;
	//	});

	QCheckBox cBtn1;
	cBtn1.setText("cBtn1");
	cBtn1.setParent(&w);
	cBtn1.setGeometry(30, 150, 50, 30);

	QCheckBox cBtn2;
	cBtn2.setText("cBtn2");
	cBtn2.setParent(&w);
	cBtn2.setGeometry(30, 170, 50, 30);

	QCheckBox cBtn3;
	cBtn3.setText("cBtn1");
	cBtn3.setParent(&w);
	cBtn3.setGeometry(30, 190, 50, 30);

	QButtonGroup btnGroup1;
	btnGroup1.setExclusive(false);
	btnGroup1.setParent(&w);
	btnGroup1.addButton(&cBtn1);
	btnGroup1.addButton(&cBtn2);
	btnGroup1.addButton(&cBtn3);

	QObject::connect(&btnGroup1, pfnBtnClicked, [&](QAbstractButton* pbtn) {
		qDebug() << pbtn->text();
		//获取按钮列表
		QList<QAbstractButton*> btnList = btnGroup1.buttons();
		foreach(QAbstractButton * pBtn, btnList)
		{
			QString strStatus = pBtn->isChecked() ? "Checked" : "Unchecked";
			qDebug() << QString("Button : %1 is %2").arg(pbtn->text()).arg(strStatus);
		}
		});



	w.show();

	app.exec();
}
