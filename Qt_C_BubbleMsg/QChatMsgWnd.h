#pragma once

#include <QWidget>
#include <QLabel>
#include <QMovie>


class QChatMsgWnd : public QWidget 
{
	Q_OBJECT
public:
	//消息类型
	enum  ChatMsgTypeEnum {
		ChatMsg_System = 10,
		ChatMsg_Time,
		ChatMsg_Owner,
		ChatMsg_Other,
	};


public:
	//构造函数
	QChatMsgWnd(QWidget* p = nullptr);

	//根据str调整各个框的大小
	QSize fontRect(QString str);

	QSize getRealStringSize(QString str);

	void setText(QString text, QString time, QSize allSize, QChatMsgWnd::ChatMsgTypeEnum chatMsgType);

protected:
	//绘制
	void paintEvent(QPaintEvent* event);

public:
	QString m_msg;
	QString m_time;
	QString m_curTime;
	QSize m_allSize;

	ChatMsgTypeEnum m_chatMsgType = ChatMsg_System;

	int m_outerFrameWidth;
	int m_textWidth;
	int m_spaceWidth;
	int m_lineHeight;


	QRect m_iconLeftRect;
	QRect m_iconRightRect;
	//QRect m_sanJiaoLeftRect;
	QRect m_triangleLeftRect;
	QRect m_triangleRightRect;

	QRect m_outerFrameLeftRect;
	QRect m_outerFrameRightRect;

	//
	QRect m_textLeftRect;
	QRect m_textRigtRect;

	QPixmap m_leftPixmap;
	QPixmap m_rightPixmap;

	QLabel* m_loadingLable = nullptr;
	QMovie* m_loadingMovie = nullptr;

	//是否在发送中
	bool m_bSending = false;
};