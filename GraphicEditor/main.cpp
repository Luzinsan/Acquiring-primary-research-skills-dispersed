//#include "toolswindow.h"
//#include "paintwindow.h"
#include "intermediate.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Intermediate intermdiate;

    std::cout << "Everything is OK";

    return a.exec();
}
