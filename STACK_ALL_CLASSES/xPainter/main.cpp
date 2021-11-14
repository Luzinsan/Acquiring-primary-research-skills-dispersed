#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "Qt version: " << qVersion() << std::endl;

    return a.exec();
}
