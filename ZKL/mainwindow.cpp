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
#include <QLayout>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      canvas(new Canvas(this)) // Инициализируем графическую сцену
{
    // В некоторых средах значки меню по умолчанию не отображаются,
    // поэтому мы можем попробовать отключить атрибут Qt::AA_DontShowIconsInMenus
    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);


    /****************************МЕНЮ -> ФАЙЛ***************************/

    QMenu *file;
    file = menuBar()->addMenu("&Файл");

    /***СОЗДАТЬ*********************************************************/

    QPixmap newpix("Icons/icons8-new-64.png");
    QAction *newa = new QAction(newpix, "&Создать", this);
    newa->setShortcut(tr("Ctrl+N"));
    file->addAction(newa);
    connect(newa, &QAction::triggered, newFile, &CreateFile::createFile);

    /*************ОТКРЫТЬ***********************************************/

    QPixmap openpix("Icons/icons8-image-file-64.png");
    QAction *open = new QAction(openpix, "&Открыть", this);
    open->setShortcut(tr("Ctrl+O"));
    file->addAction(open);
    connect(open, &QAction::triggered, this, &MainWindow::openFile);

    /************************СОХРАНИТЬ**********************************/

    QPixmap savepix("Icons/icons8-save-64.png");
    QAction *save = new QAction(savepix, "&Сохранить", this);
    save->setShortcut(tr("Ctrl+S"));
    file->addAction(save);
    connect(save, &QAction::triggered, this, &MainWindow::saveFile);
    file->addSeparator();

    /***********************************************************ВЫХОД***/

    QPixmap quitpix("Icons/icons8-shutdown-64.png");
    QAction *quit = new QAction(quitpix, "&Выход", this);
    quit->setShortcut(tr("Ctrl+Q"));
    file->addAction(quit);
    connect(quit, &QAction::triggered, this, &QApplication::quit);


    /*********************МЕНЮ -> ГЛАВНАЯ*******************/

    QMenu *mainb;
    mainb = menuBar()->addMenu("&Главная");

    /****ИСТОРИЯ********************************************/

    QPixmap histpix("Icons/icons8-time-machine-64.png");
    QAction *hist = new QAction(histpix, "&История", this);
    hist->setShortcut(tr("Ctrl+H"));
    mainb->addAction(hist);

    /*****************СЛОИ**********************************/

    QPixmap layerspix("Icons/icons8-layers-64.png");
    QAction *layers = new QAction(layerspix, "&Слои", this);
    layers->setShortcut(tr("Ctrl+L"));
    mainb->addAction(layers);

    /**********************************МЕНЮ -> ВИД*****************************/

    QMenu *sideb;
    sideb = menuBar()->addMenu("&Вид");

    /****ЛИНЕЙКИ***************************************************************/

    QPixmap rulerspix("Icons/icons8-ruler-64.png");
    QAction *rulers = new QAction(rulerspix, "&Линейки", this);
    rulers->setShortcut(tr("Ctrl+L"));
    rulers->setCheckable(true);
    sideb->addAction(rulers);
    //connect(rulers, &QAction::triggered, this, &MainWindow::toggleStatusbar);

    /*******************ЛИНИИ СЕТКИ********************************************/

    QPixmap gridLinespix("Icons/icons8-prison-64.png");
    QAction *gridLines = new QAction(gridLinespix, "&Линии сетки", this);
    gridLines->setShortcut(tr("Ctrl+G"));
    gridLines->setCheckable(true);
    sideb->addAction(gridLines);
    connect(gridLines, &QAction::triggered, canvas, &Canvas::drowGridLines);


    /********************************************ГРАФИЧЕСКАЯ СЦЕНА************************************************/

    viewer = new QGraphicsView(this);
    canvas->setSceneRect(0,0,1400,780);
    viewer->setFixedSize(1410,790);

    viewer->setScene(canvas);

    /***********************ПАНЕЛЬ ИНСТРУМЕНТОВ -> СТИЛЬ ШТРИХА**********************************************/

    QToolBar *dashoffset = addToolBar("&Стиль штриха");

    /*ПРЯМАЯ ЛИНИЯ*******************************************************************************************/

    QPixmap solidlinepix("Icons/icons8-horizontal-line-64.png");
    QAction *solidline = dashoffset->addAction(QIcon(solidlinepix), "&Прямая линия");
    solidline->setCheckable(false);
    connect(solidline, &QAction::triggered, canvas, &Canvas::setSolidLine);


    /*************ПУНКТИРНАЯ ЛИНИЯ***************************************************************************/

    QPixmap dashlinepix("Icons/icons8-dashed-line-64.png");
    QAction *dashline = dashoffset->addAction(QIcon(dashlinepix), "&Пунктирная линия");
    dashline->setCheckable(false);
    connect(dashline, &QAction::triggered, canvas, &Canvas::setDashLine);

    /*****************************ТОЧЕЧНАЯ ЛИНИЯ*************************************************************/

    QPixmap dotlinepix("Icons/icons8-dashed-line-80.png");
    QAction *dotline = dashoffset->addAction(QIcon(dotlinepix), "&Точечная линия");
    dotline->setCheckable(false);
    connect(dotline, &QAction::triggered, canvas, &Canvas::setDotLine);

    /*******************************************ЛИНИЯ ТИРЕ-ТОЧКА*********************************************/

    QPixmap dashdotlinepix("Icons/icons8-dashed-line-100.png");
    QAction *dashdotline = dashoffset->addAction(QIcon(dashdotlinepix), "&Линия тире-точка");
    dashdotline->setCheckable(false);
    connect(dashdotline, &QAction::triggered, canvas, &Canvas::setDashDotLine);

     /**********************************************************ЛИНИЯ ТИРЕ-ТОЧКА-ТОЧКА***********************/

    QPixmap dashdotdotlinepix("Icons/icons8-dashed-line-65.png");
    QAction *dashdotdotline = dashoffset->addAction(QIcon(dashdotdotlinepix), "&Линия тире-точка-точка");
    dashdotdotline->setCheckable(false);
    connect(dashdotdotline, &QAction::triggered, canvas, &Canvas::setDashDotDotLine);

    /*********************************************************************************ПОЛЬЗОВАТЕЛЬСКАЯ ЛИНИЯ*/

    QPixmap cusromlinepix("Icons/icons8-dashed-line-50.png");
    QAction *cusromline = dashoffset->addAction(QIcon(cusromlinepix), "&Пользовательская линия");
    cusromline->setCheckable(false);
    connect(cusromline, &QAction::triggered, canvas, &Canvas::setCustomLine);


    /***********************ПАНЕЛЬ ИНСТРУМЕНТОВ -> ОСНОВНАЯ************************/

    QToolBar *toolbar = addToolBar("&Панель инструментов");

    /*КИСТЬ************************************************************************/
    QPixmap brushpix("Icons/icons8-paint-64.png");
    QAction *brush = toolbar->addAction(QIcon(brushpix), "&Кисть");
    brush->setShortcut(tr("Ctrl+B"));
    brush->setCheckable(false);
    connect(brush, &QAction::triggered, canvas, &Canvas::setToolLine);

     /*****ШИРИНА ЛИНИИ************************************************************/
    QSpinBox *spinbox = new QSpinBox(this);
    toolbar->addWidget(spinbox);
    connect(spinbox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            canvas, static_cast<void (Canvas::*)(int)>(&Canvas::setSize));
    toolbar->addSeparator();

     /*****************ПАЛИТРА*****************************************************/

    QPixmap palettepix("Icons/icons8-color-palette-64.png");
    QAction *palette = toolbar->addAction(QIcon(palettepix), "&Палитра");
    palette->setShortcut(tr("Ctrl+P"));
    palette->setCheckable(false);
    connect(palette, &QAction::triggered, this, &MainWindow::setColor);

    /*************************ЛАСТИК***********************************************/

    QPixmap eraserpix("Icons/icons8-eraser-64.png");
    QAction *eraser = toolbar->addAction(QIcon(eraserpix), "&Ластик");
    eraser->setShortcut(tr("Ctrl+E"));
    eraser->setCheckable(false);
    connect(eraser, &QAction::triggered, canvas, &Canvas::setToolEraser);


    /*******************************ЗАЛИВКА*****************************************/

    QPixmap fillpix("Icons/icons8-fill-color-64.png");
    toolbar->addAction(QIcon(fillpix), "&Заливка");

    QPixmap deleteallpix("Icons/icons8-clean-64.png");
    QAction *deleteall = toolbar->addAction(QIcon(deleteallpix), "&Удалить всё");
    deleteall->setShortcut(tr("Ctrl+D"));
    deleteall->setCheckable(false);
    connect(deleteall, &QAction::triggered, canvas, &Canvas::deleteAll);

     /*************************************ТЕКСТ************************************/

    QPixmap textpix("Icons/icons8-text-box-64.png");
    QAction *text = toolbar->addAction(QIcon(textpix), "&Текст");
    text->setShortcut(tr("Ctrl+T"));
    text->setCheckable(false);
    connect(text, &QAction::triggered, canvas, &Canvas::setToolText);

    /*******************************************ДУБЛИРОВАНИЕ************************/

    QPixmap duplicationpix("Icons/icons8-geometric-flowers-64.png");
    QAction *duplication = toolbar->addAction(QIcon(duplicationpix), "&Дублирование");
    duplication->setShortcut(tr("Ctrl+D"));
    duplication->setCheckable(true);
    connect(duplication, &QAction::triggered, canvas, &Canvas::setToolDuplication);


    /***********************ПАНЕЛЬ ИНСТРУМЕНТОВ -> ФИГУРЫ******************************************/

     QToolBar *figures = addToolBar("Фигуры");

    /*ПРЯМАЯ***************************************************************************************/

    QPixmap linepix("Icons/icons8-vertical-line-64.png");
    QAction *line = figures->addAction(QIcon(linepix), "&Прямая");
    line->setShortcut(tr("Ctrl+L"));
    line->setCheckable(false);
    connect(line, &QAction::triggered, this, &MainWindow::setFigureLine);

    /*******КВАДРАТ********************************************************************************/

    QPixmap rectpix("Icons/icons8-rectangular-64.png");
    QAction *rect = figures->addAction(QIcon(rectpix), "&Квадрат");
    rect->setShortcut(tr("Ctrl+R"));
    rect->setCheckable(false);
    connect(rect, &QAction::triggered, this, &MainWindow::setFigureRectangle);

    /**************КРУГ****************************************************************************/

    QPixmap circlepix("Icons/icons8-circle-64.png");
    QAction *circle = figures->addAction( QIcon(circlepix), "&Окружность");
    circle->setShortcut(tr("Ctrl+C"));
    circle->setCheckable(false);
    connect(circle, &QAction::triggered, this, &MainWindow::setFigureCircle);

    //QPixmap circlepix("U:/ProjectQt/ZKL/Icons/icons8-circle-64.png");
    //QAction *circle = toolbar->addAction(QIcon(circlepix), "&Окружность");
    //circle->setShortcut(tr("Ctrl+Shift+C"));
    //circle->setCheckable(true);
    //Figure *figure = new Figure(canvas);
    //connect(circle, &QAction::triggered, figure,  &Figure::setFigureCircle);

    /******************РАВНОСТОРОННИЙ ТРЕУГОЛЬНИК***************************************************/

    QPixmap trianglepix("Icons/icons8-triangle-64.png");
    QAction *triangle = figures->addAction( QIcon(trianglepix),"&Треугольник");
    triangle->setShortcut(tr("Ctrl+T"));
    triangle->setCheckable(false);
    connect(triangle, &QAction::triggered, this, &MainWindow::setFigureTriangle);

     /*******************************************ПРЯМОУГОЛЬНЫЙ ТРЕУГОЛЬНИК**************************/

    QPixmap trianglerectpix("Icons/icons8-trigonometry-64.png");
    QAction *trianglerect = figures->addAction( QIcon(trianglerectpix),"&Прямоугольный треугольник");
    trianglerect->setShortcut(tr("Ctrl+T+R"));
    trianglerect->setCheckable(false);
    connect(trianglerect, &QAction::triggered, this, &MainWindow::setFigureTriangleRectangular);

    /*********************************************************************РОМБ**********************/

    QPixmap rhombpix("Icons/icons8-rhomboid-shape-64.png");
    QAction *rhomb = figures->addAction(QIcon(rhombpix), "&Ромб");
    rhomb->setShortcut(tr("Ctrl+Shift+R"));
    rhomb->setCheckable(false);
    connect(rhomb, &QAction::triggered, this, &MainWindow::setFigureRhomb);

    /*************************************************************************ТРАПЕЦИЯ**************/

    QPixmap trapezoidpix("Icons/icons8-irregular-quadrilateral-64.png");
    QAction *trapezoid = figures->addAction(QIcon(trapezoidpix),  "&Трапеция");
    trapezoid->setShortcut(tr("Ctrl+Shift+T"));
    trapezoid->setCheckable(false);
    connect(trapezoid, &QAction::triggered, this, &MainWindow::setFigureTrapezoid);

    /*********************************************************************************ПЯТИУГОЛЬНИК**/

    QPixmap pentagonpix("Icons/icons8-pentagon-64.png"); // Тоже найти иконку
    QAction *pentagon = figures->addAction(QIcon(pentagonpix),  "&Пятиугольник");
    pentagon->setShortcut(tr("Ctrl+Shift+T"));
    pentagon->setCheckable(false);
    connect(pentagon, &QAction::triggered, this, &MainWindow::setFigurePentagon);


    /********ПАНЕЛЬ ИНСТРУМЕНТОВ -> ПРОВОДНИК*************/
    QToolBar *explorer = addToolBar("Проводник");

    /*ПРОЕКТЫ*********************************************/

    QPixmap projectspix("Icons/icons8-group-of-projects-64.png");
    explorer->addAction(QIcon(projectspix), "Проекты");
    explorer->addSeparator();

    /********СВОЙСТВА*************************************/

    QPixmap propertiespix("Icons/icons8-show-property-64.png");
    explorer->addAction(QIcon(propertiespix), "Свойства");

    /****************РЕСУРСЫ******************************/

    QPixmap resourcespix("Icons/icons8-categorize-64.png");
    explorer->addAction(QIcon(resourcespix), "Ресурсы");


    /**********НИЖНЯЯ ПАНЕЛЬ**********/
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



void MainWindow::setFigureLine()
{
    canvas->setToolFigure();
    canvas->setLine();
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


void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"),
                                                    QDir::homePath(),
                                                    "Images (*.png, *.jpg)");

    canvas->savePicture(fileName);
}
