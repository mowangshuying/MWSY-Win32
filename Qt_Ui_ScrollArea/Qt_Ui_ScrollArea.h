#pragma once

#include <QtWidgets/QWidget>
#include "ui_Qt_Ui_ScrollArea.h"

class Qt_Ui_ScrollArea : public QWidget
{
    Q_OBJECT

public:
    Qt_Ui_ScrollArea(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt_Ui_ScrollAreaClass ui;
};
