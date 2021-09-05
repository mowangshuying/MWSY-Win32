#include "QChatMsgWnd.h"

#include <QPainter>
#include <QDateTime>
#include <QDebug>

QChatMsgWnd::QChatMsgWnd(QWidget* p /*= nullptr*/)
	: QWidget(p)
{
	//设置窗体的字体大小
	QFont font = this->font();
	font.setFamily("MicrosoftYaHei");
	font.setPointSize(10);
	setFont(font);

	//
	m_leftPixmap = QPixmap("./res/img/owner.png");
	m_rightPixmap = QPixmap("./res/img/other.png");
	m_loadingMovie = new QMovie(this);
	m_loadingMovie->setFileName("./res/gif/loading.gif");
	
	
	m_loadingLable = new QLabel(this);
	m_loadingLable->setMovie(m_loadingMovie);
	m_loadingLable->resize(16, 16);
	//设置窗口背景：透明
	m_loadingLable->setAttribute(Qt::WA_TranslucentBackground, true);
	//关闭自动填充窗口背景
	m_loadingLable->setAutoFillBackground(false);

	//setStyleSheet("");
}

QSize QChatMsgWnd::fontRect(QString str)
{
	m_msg = str;

	int minH = 30;			//消息的最小高度为30
	int iconWH = 30;	    //头像的大小
	int iconSpaceW = 20;
	int iconRectW = 5;
	int iconTMPH = 10;
	int triangleW = 6;
	int outerFrameW = 20;
	int textSpaceRect = 12;

	m_outerFrameWidth = this->width() - outerFrameW - 2 * (iconWH + iconTMPH + iconSpaceW);
	m_textWidth = m_outerFrameWidth - 2 * textSpaceRect;

	m_spaceWidth = this->width() - textSpaceRect;

	m_iconLeftRect = QRect(iconSpaceW, iconTMPH, iconWH, iconWH);
	m_iconRightRect = QRect(this->width() - iconSpaceW - iconWH, iconTMPH, iconWH, iconWH);
	QSize msgSize = getRealStringSize(str);
	qDebug() << "fontRect size = " << msgSize;
	int height = msgSize.height() > minH ? msgSize.height() : minH;
	qDebug() << "QChatMsgWnd::fontRect height = " << height;
	m_triangleLeftRect = QRect(iconWH + iconSpaceW + iconRectW, m_lineHeight / 2, 
		triangleW,5);

	m_triangleRightRect = QRect(this->width() - iconRectW - iconWH - iconSpaceW - triangleW, m_lineHeight / 2,
		triangleW,5);

	if (msgSize.width() < (m_textWidth + m_spaceWidth)) {
		m_outerFrameLeftRect.setRect(m_triangleLeftRect.x() + m_triangleLeftRect.width(), m_lineHeight / 4 * 3,
			msgSize.width() - m_spaceWidth + 2 * textSpaceRect, height-m_lineHeight);
		

		m_outerFrameRightRect.setRect(this->width() - msgSize.width() + m_spaceWidth - 2 * textSpaceRect - iconWH - iconSpaceW - iconRectW - triangleW,
			m_lineHeight / 4 * 3, msgSize.width() - m_spaceWidth + 2 * textSpaceRect, height-m_lineHeight);
	}
	else {
		m_outerFrameLeftRect.setRect(m_triangleLeftRect.x() + m_triangleLeftRect.width(), m_lineHeight / 4 * 3, 
			m_outerFrameWidth, height-m_lineHeight);

		m_outerFrameRightRect.setRect(iconWH +  + iconSpaceW + iconRectW - triangleW, m_lineHeight / 4 * 3,
			m_outerFrameWidth, height-m_lineHeight);
	}


	m_textLeftRect.setRect(m_outerFrameLeftRect.x() + textSpaceRect, m_outerFrameLeftRect.y() + iconTMPH,
		m_outerFrameLeftRect.width() - 2 * textSpaceRect, m_outerFrameLeftRect.height() - 2 * iconTMPH + 2);

	m_textRigtRect.setRect(m_outerFrameRightRect.x() + textSpaceRect, m_outerFrameRightRect.y() + iconTMPH,
		m_outerFrameRightRect.width() - 2 * textSpaceRect, m_outerFrameRightRect.height() - 2 * iconTMPH +2);

	return QSize(msgSize.width(), height);

}

QSize QChatMsgWnd::getRealStringSize(QString str)
{
	//qDebug() << "getRealStringSize start------------------------------";
	QFontMetricsF fm(this->font());
	m_lineHeight = fm.lineSpacing();
	int nCount = str.count("\n");
	int nLineNum = 0;
	int nMaxWidth = 0;

	if (nCount == 0) {
		nMaxWidth = fm.width(str);
		QString value = str;
		if (nMaxWidth > m_textWidth) {
			nMaxWidth = m_textWidth;
			//获取每行的最大存放字符数量
			int size = m_textWidth/fm.width(" ");
			//计算含有几行
			int num = fm.width(value)/m_textWidth;
		
			nLineNum = num;
			if( fm.width(value)/m_textWidth-num>0) {
				nLineNum += 1;
			}
		}
		else {
			nLineNum += 1;
		}
	}
	else {
		for (int i = 0; i <= nCount; i++)
		{
			QString value = str.split("\n").at(i);
			int valueWidth = fm.width(value);
			
			if (valueWidth > nMaxWidth) {
				nMaxWidth = valueWidth;
			}

			if (nMaxWidth > m_textWidth) {
				nMaxWidth = m_textWidth;
				//获取每行的最大存放字符数量
				int size = m_textWidth / fm.width(" ");
				//计算含有几行
				int num = fm.width(value) / m_textWidth;

				nLineNum = num;
				if (fm.width(value) / m_textWidth - num > 0) {
					nLineNum += 1;
				}
			}
			
 		}
	}

	return QSize(nMaxWidth + m_spaceWidth, nLineNum * m_lineHeight + 2 * m_lineHeight);
}

void QChatMsgWnd::setText(QString text, QString time, QSize allSize, ChatMsgTypeEnum chatMsgType)
{
	m_msg = text;
	m_chatMsgType = chatMsgType;
	m_time = time;
	m_curTime = QDateTime::fromTime_t(time.toInt()).toString("dd:hh:mm");
	m_allSize = allSize;
	this->update();
}

void QChatMsgWnd::paintEvent(QPaintEvent* event)
{
	Q_UNUSED(event);

	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	painter.setPen(Qt::NoPen);
	painter.setBrush(QBrush(Qt::gray));


	if (m_chatMsgType == ChatMsgTypeEnum::ChatMsg_Owner) {
		//绘制玩家头像
		painter.drawPixmap(m_iconLeftRect, m_leftPixmap);
		
		//绘制外部边框
		QColor color = QColor(158, 234, 106);
		painter.setBrush(color);
		//painter.drawRoundedRect(m_outerFrameLeftRect.x() - 1, m_outerFrameLeftRect.y() - 1,
			//m_outerFrameLeftRect.width() + 2, m_outerFrameLeftRect.height() + 2, 4, 4);

		//painter.setBrush(Qt::red);
		painter.drawRoundedRect(m_outerFrameLeftRect, 4, 4);

		//
		QPointF points[3] = {
			QPointF(m_triangleLeftRect.x(),30),
			QPointF(m_triangleLeftRect.x() + m_triangleLeftRect.width(),25),
			QPointF(m_triangleLeftRect.x() + m_triangleLeftRect.width(),35)
		};

		painter.drawPolygon(points, 3);

		//painter.setBrush(Qt::red);
	//	painter.drawRoundedRect(m_textLeftRect, 0, 0);

		QPen penText;
		penText.setColor(QColor(51, 51, 51));
		painter.setPen(penText);
		QTextOption option(Qt::AlignLeft | Qt::AlignVCenter);
		option.setWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
		painter.setFont(this->font());
		painter.drawText(m_textLeftRect, m_msg, option);
	}

	if (m_chatMsgType == ChatMsgTypeEnum::ChatMsg_Other) {
		return;
	}

	if (m_chatMsgType == ChatMsgTypeEnum::ChatMsg_Time) {
		return;
	}
}


