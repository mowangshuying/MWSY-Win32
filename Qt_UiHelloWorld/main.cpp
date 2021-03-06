#include "Qt_UiHelloWorld.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_UiHelloWorld w;
    w.show();
    return a.exec();
}
