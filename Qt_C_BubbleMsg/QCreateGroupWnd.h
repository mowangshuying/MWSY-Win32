#pragma once

#include <QWidget>

#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>

class QCreateGroupWnd : public QWidget {
	Q_OBJECT
public:
	QCreateGroupWnd(QWidget* p = nullptr);
public:
	QHBoxLayout* m_hLayout;
	
	QLineEdit* m_serchEdit;
	QListWidget* m_listWnd1;
	QVBoxLayout* m_vLayout1;

	QLabel* m_hasSelLabel;
	QListWidget* m_listWnd2;
	QLineEdit* m_groupNameEdit;
	QHBoxLayout* m_hLayout1;
	QPushButton* m_comfirmBtn;
	QVBoxLayout* m_vLayout2;


};