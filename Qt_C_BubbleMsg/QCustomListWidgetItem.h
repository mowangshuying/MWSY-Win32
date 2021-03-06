#pragma once

#include <QListWidget>

class QCustomListWidgetItem : public QListWidgetItem
{
public:
	explicit QCustomListWidgetItem(QListWidget* view = nullptr, int type = Type);
	int sesId() const;
	void setSesId(int sesid);
private:
	//添加一些额外的数据，如会话id；
	int m_sesId;
};