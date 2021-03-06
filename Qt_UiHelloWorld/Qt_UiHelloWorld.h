#pragma once

#include <QtWidgets/QWidget>
#include "ui_Qt_UiHelloWorld.h"

class Qt_UiHelloWorld : public QWidget
{
    Q_OBJECT

public:
    Qt_UiHelloWorld(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt_UiHelloWorldClass ui;
};
