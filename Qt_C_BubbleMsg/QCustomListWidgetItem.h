#pragma once

#include <QListWidget>

class QCustomListWidgetItem : public QListWidgetItem
{
public:
	explicit QCustomListWidgetItem(QListWidget* view = nullptr, int type = Type);
	int sesId() const;
	void setSesId(int sesid);
private:
	//���һЩ��������ݣ���Ựid��
	int m_sesId;
};