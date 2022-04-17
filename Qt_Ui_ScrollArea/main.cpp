#include "Qt_Ui_ScrollArea.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_Ui_ScrollArea w;
    w.show();
    return a.exec();
}
