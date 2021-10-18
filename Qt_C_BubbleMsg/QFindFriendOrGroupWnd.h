#pragma once

#include <QWidget>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class QFindFriendOrGroupWnd : public QWidget {
	Q_OBJECT
public:
	QFindFriendOrGroupWnd(QWidget* p = nullptr);

	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
public:
	QVBoxLayout* m_vLayout;
	QHBoxLayout* m_hLayout1;
	QHBoxLayout* m_hLayout2;
	QHBoxLayout* m_hLayout3;

	//第1行
	QLabel* m_titleLabel;
	QPushButton* m_minBtn;
	QPushButton* m_closeBtn;

	//第2行
	QPushButton* m_findPersonBtn;
	QPushButton* m_findGroupBtn;

	//第3行
	QLineEdit* m_searchEdit;
	QPushButton* m_searchBtn;

	bool m_bPress = false;
	QPoint m_poPress;

};