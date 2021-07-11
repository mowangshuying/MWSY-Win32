#pragma once

#include <QtWidgets/QWidget>
#include "ui_Qt_Ui_DockWidget.h"

class Qt_Ui_DockWidget : public QWidget
{
    Q_OBJECT

public:
    Qt_Ui_DockWidget(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt_Ui_DockWidgetClass ui;
};
