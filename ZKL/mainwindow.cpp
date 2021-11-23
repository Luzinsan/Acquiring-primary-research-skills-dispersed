#include "mainwindow.h"
#include "canvas.h"
#include "figure.h"
#include "createfile.h"

#include <QFileDialog>

#include <QColorDialog>

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
#include "figure.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      canvas(new Canvas(this)) // Инициализируем графическую сцену
{
    // В некоторых средах значки меню по умолчанию не отображаются,
    // поэтому мы можем попробовать отключить атрибут Qt::AA_DontShowIconsInMenus
    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);


    /**************/
    QMenu *file;
    file = menuBar()->addMenu("&Файл");
    /**************/
    QPixmap newpix("Icons/icons8-file-64.png");
    QAction *newa = new QAction(newpix, "&Создать", this);
    newa->setShortcut(tr("Ctrl+N"));
    file->addAction(newa);
    connect(newa, &QAction::triggered, newFile, &CreateFile::createFile);

    QPixmap openpix("Icons/icons8-document-64.png");
    QAction *open = new QAction(openpix, "&Открыть", this);
    open->setShortcut(tr("Ctrl+O"));
    file->addAction(open);
    connect(open, &QAction::triggered, this, &MainWindow::openFile);

    QPixmap savepix("U:/ProjectQt/ZKL/Icons/icons8-folder-64.png");
    QAction *save = new QAction(savepix, "&Сохранить", this);
    save->setShortcut(tr("Ctrl+S"));
    file->addAction(save);
    file->addSeparator();

    QPixmap quitpix("Icons/icons8-cancel-64.png");
    QAction *quit = new QAction(quitpix, "&Выход", this);
    quit->setShortcut(tr("Ctrl+Q"));
    file->addAction(quit);
    // connect(отправитель, сигнал_отправителя, получатель, слот_получателя).
    connect(quit, &QAction::triggered, this, &QApplication::quit);

    /**************/
    QMenu *mainb;
    mainb = menuBar()->addMenu("&Главная");
    /**************/
    QPixmap histpix("Icons/icons8-search-64.png");
    QAction *hist = new QAction(histpix, "&История", this);
    hist->setShortcut(tr("Ctrl+H"));
    mainb->addAction(hist);

    QPixmap layerspix("Icons/icons8-plus-+-64.png");
    QAction *layers = new QAction(layerspix, "&Слои", this);
    layers->setShortcut(tr("Ctrl+L"));
    mainb->addAction(layers);

    /*************/
    QMenu *sideb;
    sideb = menuBar()->addMenu("&Вид");
    /**************/

    QPixmap rulerspix("Icons/icons8-ruler-64.png");
    QAction *rulers = new QAction(rulerspix, "&Линейки", this);
    rulers->setShortcut(tr("Ctrl+L"));
    rulers->setCheckable(true);
    sideb->addAction(rulers);
    connect(rulers, &QAction::triggered, this, &MainWindow::toggleStatusbar);

    QPixmap gridLinespix("Icons/icons8-table-40.png");
    QAction *gridLines = new QAction(gridLinespix, "&Линии сетки", this);
    gridLines->setShortcut(tr("Ctrl+G"));
    gridLines->setCheckable(true);
    sideb->addAction(gridLines);
    connect(gridLines, &QAction::triggered, this, &MainWindow::toggleStatusbar);


    /*************/
    viewer = new QGraphicsView(this);
    canvas->setSceneRect(0,0,1400,780);
    viewer->setFixedSize(1410,790);
    viewer->setScene(canvas);


    QToolBar *toolbar = addToolBar("&Панель инструментов");


    QPixmap brushpix("Icons/icons8-paint-64.png");
    QAction *brush = toolbar->addAction(QIcon(brushpix), "&Кисть");
    brush->setShortcut(tr("Ctrl+B"));
    brush->setCheckable(true);
    connect(brush, &QAction::triggered, canvas, &Canvas::setToolLine);



    QSpinBox *spinbox = new QSpinBox(this);

    toolbar->addWidget(spinbox);
    connect(spinbox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            canvas, static_cast<void (Canvas::*)(int)>(&Canvas::setSize));
    toolbar->addSeparator();


    QPixmap palettepix("Icons/icons8-paint-palette-64.png");
    QAction *palette = toolbar->addAction(QIcon(palettepix), "&Палитра");
    palette->setShortcut(tr("Ctrl+P"));
    palette->setCheckable(true);
    connect(palette, &QAction::triggered, this, &MainWindow::setColor);

    QAction *duplication = toolbar->addAction( "&Дублирование");
    duplication->setShortcut(tr("Ctrl+D"));
    duplication->setCheckable(true);
    connect(duplication, &QAction::triggered, canvas, &Canvas::setToolDuplication);


    QPixmap fillpix("Icons/icons8-fill-color-64.png");
    toolbar->addAction(QIcon(fillpix), "&Заливка");

    // Figure *figure = new Figure(canvas);

    QAction *line = toolbar->addAction( "&Прямая");
    line->setShortcut(tr("Ctrl+L"));
    line->setCheckable(true);
    //connect(line, &QAction::triggered, canvas, &Canvas::setToolLine);


    QPixmap rectpix("Icons/icons8-rectangle-64.png");
    QAction *rect = toolbar->addAction(QIcon(rectpix), "&Квадрат");
    rect->setShortcut(tr("Ctrl+R"));
    rect->setCheckable(true);
    connect(rect, &QAction::triggered, this, &MainWindow::setFigureRectangle);

    QPixmap circlefillpix("Icons/icons8-filled-circle-64.png");
    QAction *circlefill = toolbar->addAction( QIcon(circlefillpix), "&Круг");
    circlefill->setShortcut(tr("Ctrl+C"));
    circlefill->setCheckable(true);
    //Figure *figure = new Figure(canvas);
    connect(circlefill, &QAction::triggered, this, &MainWindow::setFigureCircle);

    //QPixmap circlepix("U:/ProjectQt/ZKL/Icons/icons8-circle-64.png");
    //QAction *circle = toolbar->addAction(QIcon(circlepix), "&Окружность");
    //circle->setShortcut(tr("Ctrl+Shift+C"));
    //circle->setCheckable(true);
    //Figure *figure = new Figure(canvas);
    //connect(circle, &QAction::triggered, figure,  &Figure::setFigureCircle);

    QPixmap trianglepix("Icons/icons8-triangle-64.png"); //  треугольник
    QAction *triangle = toolbar->addAction( QIcon(trianglepix),"&Треугольник");
    triangle->setShortcut(tr("Ctrl+T"));
    triangle->setCheckable(true);
    //Figure *figure = new Figure(canvas);
    connect(triangle, &QAction::triggered, this, &MainWindow::setFigureTriangle);

    QPixmap trianglerectpix("Icons/icons8-triangle-64.png"); // пока что равносторонний треугольник
    QAction *trianglerect = toolbar->addAction( QIcon(trianglerectpix),"&Прямоугольный треугольник");
    trianglerect->setShortcut(tr("Ctrl+T+R"));
    trianglerect->setCheckable(true);
    //Figure *figure = new Figure(canvas);
    connect(trianglerect, &QAction::triggered, this, &MainWindow::setFigureTriangleRectangular);

    QPixmap rhombpix("Icons/icons8-rhomboid-shape-64.png");
    QAction *rhomb = toolbar->addAction(QIcon(rhombpix), "&Ромб");
    rhomb->setShortcut(tr("Ctrl+Shift+R"));
    rhomb->setCheckable(true);
    //Figure *figure = new Figure(canvas);
    connect(rhomb, &QAction::triggered, this, &MainWindow::setFigureRhomb);

    QPixmap trapezoidpix("Icons/icons8-rhomboid-shape-64.png"); // Тоже найти иконку
    QAction *trapezoid = toolbar->addAction(QIcon(trapezoidpix),  "&Трапеция");
    trapezoid->setShortcut(tr("Ctrl+Shift+T"));
    trapezoid->setCheckable(true);
    //Figure *figure = new Figure(canvas);
    connect(trapezoid, &QAction::triggered, this, &MainWindow::setFigureTrapezoid);

    QPixmap pentagonpix("Icons/icons8-rhomboid-shape-64.png"); // Тоже найти иконку
    QAction *pentagon = toolbar->addAction(QIcon(pentagonpix),  "&Пятиугольник");
    pentagon->setShortcut(tr("Ctrl+Shift+T"));
    pentagon->setCheckable(true);
    //Figure *figure = new Figure(canvas);
    connect(pentagon, &QAction::triggered, this, &MainWindow::setFigurePentagon);


    QPixmap textpix("Icons/icons8-text-box-64.png");
    toolbar->addAction(QIcon(textpix), "&Текст");

    QPixmap eraserpix("Icons/icons8-eraser-64.png");
    QAction *eraser = toolbar->addAction(QIcon(eraserpix), "&Ластик");
    eraser->setShortcut(tr("Ctrl+E"));
    eraser->setCheckable(true);
    connect(eraser, &QAction::triggered, canvas, &Canvas::setToolEraser);


    /*************/
    QToolBar *explorer = addToolBar("Проводник");

    QPixmap projectspix("Icons/icons8-picture-64.png");
    explorer->addAction(QIcon(projectspix), "Проекты");
    explorer->addSeparator();

    QPixmap propertiespix("Icons/icons8-settings-64.png");
    explorer->addAction(QIcon(propertiespix), "Свойства");

    QPixmap resourcespix("Icons/icons8-categorize-64.png");
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


void MainWindow::setColor()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Палитра");
    if(color.isValid())   
    {
        canvas->pen.setBrush(color);
        canvas->currentColor = color;
    }
    else canvas->pen.setBrush(canvas->currentColor);
}

void MainWindow::setFigureRectangle()
{
    canvas->setToolFigure();
    canvas->setRectangle();
}
void MainWindow::setFigureCircle()
{
    canvas->setToolFigure();
    canvas->setCircle();
}
void MainWindow::setFigureTriangle()
{
    canvas->setToolFigure();
    canvas->setTriangle();
}
void MainWindow::setFigureTriangleRectangular()
{
    canvas->setToolFigure();
    canvas->setTriangleRectangular();
}
void MainWindow::setFigureRhomb()
{
    canvas->setToolFigure();
    canvas->setRhomb();
}
void MainWindow::setFigureTrapezoid()
{
    canvas->setToolFigure();
    canvas->setTrapezoid();
}
void MainWindow::setFigurePentagon()
{
    canvas->setToolFigure();
    canvas->setPentagon();
}
void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Открыть файл"),
                                                    "C://",
                                                    "Images (*.png, *.jpg)");
    canvas->loadPicture(fileName);
}
