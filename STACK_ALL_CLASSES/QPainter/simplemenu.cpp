#include "simplemenu.h"
#include <QMenu>
#include <QMenuBar>
#include "plusminus.h"


SimpleMenu::SimpleMenu(QWidget *parent): QMainWindow(parent)
{

/*
    Класс QAction представляет собой абстрактное действие пользовательского интерфейса,
    которое может быть вставлено в виджеты.
    В приложениях множество общих команд может быть вызвано через меню,
    инструментов и сочетания горячих клавиш. Поскольку пользователь ожидает,
    что каждая команда будет выполняться одним и тем же способом,
    независимо от используемого пользовательского интерфейса,
    то полезно представить каждую команду как действие.
    При этом каждый объект класса QMenu может иметь один или несколько объектов действия.

*/
    QMenu *file;
    file = menuBar()->addMenu("&File");

    QPixmap openpix("icons8-open-60.png");
    QAction *open = new QAction(openpix, "&Open", this);
    QAction *quit = new QAction(openpix, "&Quit", this);

    file->addAction(open);
    file->addSeparator();
    file->addAction(quit);


    quit->setShortcut(tr("CTRL+Q"));
    // В некоторых средах значки меню по умолчанию не отображаются,
    // поэтому мы можем попробовать отключить атрибут Qt::AA_DontShowIconsInMenus
    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);


    connect(quit, &QAction::triggered, qApp, &QApplication::quit);


}
