#include "mainwindow.h"
#include "canvas.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QTextEdit>
#include <QSpinBox>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      canvas (new Canvas(this)) // Инициализируем графическую сцену
{
    // В некоторых средах значки меню по умолчанию не отображаются,
    // поэтому мы можем попробовать отключить атрибут Qt::AA_DontShowIconsInMenus
    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);





    /**************/
    QMenu *file;
    file = menuBar()->addMenu("&Файл");
    /**************/
    QPixmap newpix("U:/ProjectQt/ZKL/Icons/icons8-file-64.png");
    QAction *newa = new QAction(newpix, "&Создать", this);
    newa->setShortcut(tr("Ctrl+N"));
    file->addAction(newa);

    QPixmap openpix("U:/ProjectQt/ZKL/Icons/icons8-document-64.png");
    QAction *open = new QAction(openpix, "&Открыть", this);
    open->setShortcut(tr("Ctrl+O"));
    file->addAction(open);

    QPixmap savepix("U:/ProjectQt/ZKL/Icons/icons8-folder-64.png");
    QAction *save = new QAction(savepix, "&Сохранить", this);
    save->setShortcut(tr("Ctrl+S"));
    file->addAction(save);
    file->addSeparator();

    QPixmap quitpix("U:/ProjectQt/ZKL/Icons/icons8-cancel-64.png");
    QAction *quit = new QAction(quitpix, "&Выход", this);
    quit->setShortcut(tr("Ctrl+Q"));
    file->addAction(quit);
    // connect(отправитель, сигнал_отправителя, получатель, слот_получателя).
    connect(quit, &QAction::triggered, this, &QApplication::quit);

    /**************/
    QMenu *mainb;
    mainb = menuBar()->addMenu("&Главная");
    /**************/
    QPixmap histpix("U:/ProjectQt/ZKL/Icons/icons8-search-64.png");
    QAction *hist = new QAction(histpix, "&История", this);
    hist->setShortcut(tr("Ctrl+H"));
    mainb->addAction(hist);

    QPixmap layerspix("U:/ProjectQt/ZKL/Icons/icons8-plus-+-64.png");
    QAction *layers = new QAction(layerspix, "&Слои", this);
    layers->setShortcut(tr("Ctrl+L"));
    mainb->addAction(layers);

    /*************/
    QMenu *sideb;
    sideb = menuBar()->addMenu("&Вид");
    /**************/

    QPixmap rulerspix("U:/ProjectQt/ZKL/Icons/icons8-ruler-64.png");
    QAction *rulers = new QAction(rulerspix, "&Линейки", this);
    rulers->setShortcut(tr("Ctrl+L"));
    rulers->setCheckable(true);
    sideb->addAction(rulers);
    connect(rulers, &QAction::triggered, this, &MainWindow::toggleStatusbar);

    QPixmap gridLinespix("U:/ProjectQt/ZKL/Icons/icons8-table-40.png");
    QAction *gridLines = new QAction(gridLinespix, "&Линии сетки", this);
    gridLines->setShortcut(tr("Ctrl+G"));
    gridLines->setCheckable(true);
    sideb->addAction(gridLines);
    connect(gridLines, &QAction::triggered, this, &MainWindow::toggleStatusbar);


    /*************/
    QToolBar *toolbar = addToolBar("Панель инструментов");

    QPixmap brushpix("U:/ProjectQt/ZKL/Icons/icons8-paint-64.png");
    QAction *brush = toolbar->addAction(QIcon(brushpix), "Кисть");
    viewer = new QGraphicsView(this);
    canvas->setSceneRect(0,0, 500, 500);
    viewer->setFixedSize(600,600);
    viewer->setScene(canvas);

    QSpinBox *spinbox = new QSpinBox(this);

    toolbar->addWidget(spinbox);
    connect(spinbox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            canvas, static_cast<void (Canvas::*)(int)>(&Canvas::setSize));
    toolbar->addSeparator();

    connect(brush, &QAction::triggered, canvas, &Canvas::setSize);


    QPixmap fillpix("U:/ProjectQt/ZKL/Icons/icons8-fill-color-64.png");
    toolbar->addAction(QIcon(fillpix), "Заливка");

    QPixmap textpix("U:/ProjectQt/ZKL/Icons/icons8-text-box-64.png");
    toolbar->addAction(QIcon(textpix), "Текст");

    QPixmap eraserpix("U:/ProjectQt/ZKL/Icons/icons8-eraser-64.png");
    toolbar->addAction(QIcon(eraserpix), "Ластик");

    QPixmap palettepix("U:/ProjectQt/ZKL/Icons/icons8-paint-palette-64.png");
    toolbar->addAction(QIcon(palettepix), "Палитра");


    /*************/
    QToolBar *explorer = addToolBar("Проводник");

    QPixmap projectspix("U:/ProjectQt/ZKL/Icons/icons8-picture-64.png");
    explorer->addAction(QIcon(projectspix), "Проекты");
    explorer->addSeparator();

    QPixmap propertiespix("U:/ProjectQt/ZKL/Icons/icons8-settings-64.png");
    explorer->addAction(QIcon(propertiespix), "Свойства");

    QPixmap resourcespix("U:/ProjectQt/ZKL/Icons/icons8-categorize-64.png");
    explorer->addAction(QIcon(resourcespix), "Ресурсы");

    /*************/



    setCentralWidget(viewer);
    statusBar()->showMessage("Готово");
}


void MainWindow::toggleStatusbar()
{
    // Определяем, установлен ли флажок для элемента меню, и, исходя из этого, скрываем или показываем строку состояния
      if (viewst->isChecked())
           statusBar()->show();
      else statusBar()->hide();
}


