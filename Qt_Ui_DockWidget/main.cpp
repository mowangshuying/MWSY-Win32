#include "Qt_Ui_DockWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_Ui_DockWidget w;
    w.show();
    return a.exec();
}
