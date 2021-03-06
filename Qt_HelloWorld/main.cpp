#include <QtCore/QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    //
    std::cout<<"hello world!"<<std::endl;
    //
    app.exec();
    
    return 0;
}
