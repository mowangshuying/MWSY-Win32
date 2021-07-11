#include "Qt_Example.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_Example w;
    w.show();
    return a.exec();
}
