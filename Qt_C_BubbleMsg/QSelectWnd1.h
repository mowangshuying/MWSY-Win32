#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QEvent>

class QSelectWnd1 : public QWidget {
	Q_OBJECT
protected:
	//添加鼠标的事件
	//void mousePressEvent(QMouseEvent* event);

	bool event(QEvent* event);
public:
	QSelectWnd1(QWidget* p);

public slots:
	void slot_addContactsOrGroupBtnClick();

public:
	QVBoxLayout* m_vLayout;
	QPushButton* m_addContactsOrGroupBtn;
	QPushButton* m_createGroupBtn;
};