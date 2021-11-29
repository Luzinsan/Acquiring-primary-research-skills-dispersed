#include "mainwindow.h"
#include <QApplication>
#include <QMenu>
#include <QToolBar>
#include <QStatusBar>
#include <QMenuBar>
#include <QSpinBox>
#include <QColorDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      canvas(new Canvas(this)) // Инициализируем графическую сцену
{
    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);
    
    /****************************МЕНЮ -> ФАЙЛ***************************/
    
    QMenu *file;
    file = menuBar()->addMenu("&Файл");
    
    /***СОЗДАТЬ*********************************************************/
    
    QPixmap newpix("Icons/icons8-new-64.png");
    QAction *newa = new QAction(newpix, "&Создать", this);
    newa->setShortcut(tr("Ctrl+N"));
    file->addAction(newa);
    connect(newa, &QAction::triggered, this, &MainWindow::createFile);
    
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
    
    /**********************************МЕНЮ -> ВИД*****************************/
    
    QMenu *sideb;
    sideb = menuBar()->addMenu("&Вид");
    
    /****ЛИНЕЙКИ***************************************************************/
    
    QPixmap backgroundpix("Icons/icons8-paint-roller-64.png");
    QAction *background = new QAction(backgroundpix, "&Задний фон", this);
    background->setShortcut(tr("Ctrl+B"));
    background->setCheckable(true);
    sideb->addAction(background);
    connect(background, &QAction::triggered, canvas, &Canvas::setBackground);
    
    /*******************ЛИНИИ СЕТКИ********************************************/
    
    QPixmap gridLinespix("Icons/icons8-line-width-64.png");
    QAction *gridLines = new QAction(gridLinespix, "&Разлиновка", this);
    gridLines->setShortcut(tr("Ctrl+G"));
    gridLines->setCheckable(true);
    sideb->addAction(gridLines);
    connect(gridLines, &QAction::triggered, canvas, &Canvas::drawGridLines);

    /****************************МЕНЮ -> СВЕДЕНИЯ***********************/

    QMenu *info;
    info = menuBar()->addMenu("&Сведения");

    /********СВОЙСТВА***************************************************/

    QPixmap propertiespix("Icons/icons8-user-manual-64.png");
    QAction *manualp = new QAction(propertiespix, "&Мануал", this);
    manualp->setShortcut(tr("Ctrl+M"));
    info->addAction(manualp);
    connect(manualp, &QAction::triggered, this, &MainWindow::openManualWindow);

    /***********************FEEDBACK************************************/

    QPixmap feedbackpix("Icons/icons8-feedback-64.png");
    QAction *feedbackp = new QAction(feedbackpix, "&Оставить отзыв", this);
    feedbackp->setShortcut(tr("Ctrl+F"));
    info->addAction(feedbackp);
    connect(feedbackp, &QAction::triggered, this, &MainWindow::openFeedbackWindow);
    
    
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
    
    /*********************************************************************************ШИРОКИЙ ПУНКТИР*/
    
    QPixmap cusromlinepix("Icons/icons8-dashed-line-50.png");
    QAction *cusromline = dashoffset->addAction(QIcon(cusromlinepix), "&Широкий пунктир");
    cusromline->setCheckable(false);
    connect(cusromline, &QAction::triggered, canvas, &Canvas::setCustomLine);
    
    
    /***********************ПАНЕЛЬ ИНСТРУМЕНТОВ -> ОСНОВНАЯ************************/
    
    QToolBar *toolbar = addToolBar("&Панель инструментов");
    
    /*КИСТЬ************************************************************************/

    QPixmap brushpix("Icons/icons8-paint-64.png");
    QAction *brush = toolbar->addAction(QIcon(brushpix), "&Кисть");
    brush->setShortcut(tr("Ctrl+P"));
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
    palette->setShortcut(tr("Ctrl+C"));
    palette->setCheckable(false);
    connect(palette, &QAction::triggered, this, &MainWindow::setColor);
    
    /*****************ГРАДИЕНТ*****************************************************/

    QPixmap gradientpix("Icons/icons8-gradient-64.png");
    QAction *gradient = toolbar->addAction(QIcon(gradientpix), "&Градиент");
    gradient->setShortcut(tr("Ctrl+>"));
    gradient->setCheckable(true);
    connect(gradient, &QAction::triggered, canvas, &Canvas::setGradient);

    /*****************ЗАПОЛНЕНИЕ ФИГУР*****************************************************/

    QPixmap fillpix("Icons/icons8-fill-color-64.png");
    QAction *fill = toolbar->addAction(QIcon(fillpix), "&Заполнение");
    fill->setShortcut(tr("Ctrl+<"));
    fill->setCheckable(true);
    connect(fill, &QAction::triggered, canvas, &Canvas::setFillFigure);


    /*************************ЛАСТИК***********************************************/
    
    QPixmap eraserpix("Icons/icons8-eraser-64.png");
    QAction *eraser = toolbar->addAction(QIcon(eraserpix), "&Ластик");
    eraser->setShortcut(tr("Ctrl+E"));
    eraser->setCheckable(false);
    connect(eraser, &QAction::triggered, canvas, &Canvas::setToolEraser);
    
    /*******************************УДАЛИТЬ ВСЁ************************************/
    
    QPixmap deleteallpix("Icons/icons8-clean-64.png");
    QAction *deleteall = toolbar->addAction(QIcon(deleteallpix), "&Удалить всё");
    deleteall->setShortcut(tr("Ctrl+D"));
    deleteall->setCheckable(false);
    connect(deleteall, &QAction::triggered, canvas, &Canvas::deleteAll);
    
    /*****************************************ТЕКСТ********************************/
    
    QPixmap textpix("Icons/icons8-text-box-64.png");
    QAction *text = toolbar->addAction(QIcon(textpix), "&Текст");
    text->setShortcut(tr("Ctrl+T"));
    text->setCheckable(false);
    connect(text, &QAction::triggered, canvas, &Canvas::setToolText);
    
    /***********************************************ДУБЛИРОВАНИЕ*******************/
    
    QPixmap duplicationpix("Icons/icons8-geometric-flowers-64.png");
    QAction *duplication = toolbar->addAction(QIcon(duplicationpix), "&Дублирование");
    duplication->setShortcut(tr("Ctrl+W"));
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
    
    /**************ОКРУЖНОСТЬ**********************************************************************/
    
    QPixmap circlepix("Icons/icons8-circle-64.png");
    QAction *circle = figures->addAction( QIcon(circlepix), "&Окружность");
    circle->setShortcut(tr("Ctrl+O"));
    circle->setCheckable(false);
    connect(circle, &QAction::triggered, this, &MainWindow::setFigureCircle);
    
    /******************ПРОИЗВОЛЬНЫЙ ТРЕУГОЛЬНИК***************************************************/

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
    
    
    /**********НИЖНЯЯ ПАНЕЛЬ**********/
    setCentralWidget(viewer);
    statusBar()->showMessage("Готово");
}


void MainWindow::toggleStatusbar()
{
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
        canvas->gradient = false;
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

void MainWindow::createFile()
{
    saveFile();
    canvas->deleteAll();
}

void MainWindow::openManualWindow()
{
    manualWindow->show();
}

void MainWindow::openFeedbackWindow()
{
    feedbackWindow->show();
}
