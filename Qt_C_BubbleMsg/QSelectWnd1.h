#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QEvent>

#include "QFindFriendOrGroupWnd.h"
#include "QCreateGroupWnd.h"

class QSelectWnd1 : public QWidget {
	Q_OBJECT
protected:
	bool event(QEvent* event);
public:
	QSelectWnd1(QWidget* p);

public slots:
	void slot_addContactsOrGroupBtnClick();
	void slot_createGroup();
public:
	QVBoxLayout* m_vLayout;
	QPushButton* m_addContactsOrGroupBtn;
	QPushButton* m_createGroupBtn;
	QFindFriendOrGroupWnd* m_findFriendOrGroupWnd;
	QCreateGroupWnd* m_crateGroupWnd;
};