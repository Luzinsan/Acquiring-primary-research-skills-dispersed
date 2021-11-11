#include "toolbar.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>

Toolbar::Toolbar(QWidget *parent): QMainWindow(parent)
{
    QToolBar *toolbar = addToolBar("main toolbar");

    toolbar->addAction("New File"); // добавляем действие "New File" на панель инструментов
    toolbar->addAction("Open File"); // добавляем действие "Open File" на панель инструментов
    toolbar->addSeparator(); // добавляем разделитель на панель инструментов
    QAction *quit = toolbar->addAction("Quit Application"); // добавляем действие "Quit" на панель инструментов

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);


}
