#pragma once

#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QMap>

class QCreateGroupListwnd1Item : public QWidget {
	Q_OBJECT
public:
	QCreateGroupListwnd1Item(QWidget* p = nullptr);
	QCreateGroupListwnd1Item(QWidget* p, const char* headimg, const char* nickname, const char* rolename);
signals:
	void signal_selRBtnClick(QMap<QString,QString> map);
public slots:
	void slot_clickedSelBtn(bool isSel = false);
public:
	QHBoxLayout* m_hLayout;
	QLabel* m_headImage;
	QLabel* m_nickName;
	QLabel* m_roleName;
	QString m_headImgStr;
	
	QRadioButton* m_selRBtn;
};