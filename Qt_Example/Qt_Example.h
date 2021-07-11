#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_Example.h"

class Qt_Example : public QMainWindow
{
    Q_OBJECT

public:
    Qt_Example(QWidget *parent = Q_NULLPTR);

private:
    Ui::Qt_ExampleClass ui;
};
