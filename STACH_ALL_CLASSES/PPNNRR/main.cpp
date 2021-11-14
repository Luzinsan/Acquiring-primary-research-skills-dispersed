#include "mainwindow.h"
#include "lines.h"
#include "colours.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Lines line;
    line.resize(500,500);
    line.setWindowTitle("Lines!!!");
    line.setToolTip("This is a line!!!");
    line.show();


    Colours colours;
    colours.resize(500,500);
    colours.setWindowTitle("Colours!!!");
    colours.setToolTip("This is a colours!!!");
    colours.show();


    return app.exec();
}
