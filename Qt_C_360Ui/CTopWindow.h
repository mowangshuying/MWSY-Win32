#pragma once

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QLabel>

#include <QVBoxLayout>
#include <QHBoxLayout>

#include "CToolBtn1.h"

class CTopWindow : public QWidget
{
	Q_OBJECT
public:
	CTopWindow(QWidget* p = nullptr);

signals:
	void pageChanged(int num);
public slots:
	void onToolBtn0();
	void onToolBtn1();

public:
	void paintEvent(QPaintEvent* event);
public:
	//窗体总布局
	QVBoxLayout *m_pVLayout;
	//水平布局大
	QHBoxLayout *m_pHBigLayout;
	QVector<CToolBtn1*> m_topToolBtnVct;
	QVector<QString> m_strTopToolBtnStringVct;
	QLabel *m_pB360Lable;
	QPushButton *m_pBtn360BigIcon;
	QPushButton *m_pBtn360BigNum;
	QPushButton *m_pBtnLogin;

	//
	QHBoxLayout *m_pHSmallLayout;
	QPushButton *m_pBtn360;
	QLabel      *m_ps360Lable;
	QPushButton *m_pBtnUp;
	QPushButton* m_pBtnStar;
	QPushButton *m_pBtnColoth;
	QPushButton *m_pBtnMuti;
	QPushButton *m_pBtnMin;
	QPushButton *m_pBtnClose;
};