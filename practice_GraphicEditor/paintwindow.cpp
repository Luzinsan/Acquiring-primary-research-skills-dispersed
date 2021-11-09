#include "paintwindow.h"
#include "ui_paintwindow.h"

PaintWindow::PaintWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaintWindow)
{
    ui->setupUi(this);
    this->resize(860, 640);

    canvas = new Canvas();       // Инициализируем графическую сцену
    ui->graphicsView->setScene(canvas);  // Устанавливаем графическую сцену
    ui->graphicsView->setFixedSize(840, 620);

    //timer = new QTimer();       // Инициализируем таймер
   // timer->setInterval(1000);
    //connect(timer, &QTimer::timeout, this, &PaintWindow::timerUpdate);
    //connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
   // timer->start(100);          // Запускаем таймер

    //timer = new QTimer(this);
        //connect(timer, &QTimer::timeout, this, QOverload<>::of(&PaintWindow::update));
        //timer->start(1000);
}

PaintWindow::~PaintWindow()
{
    delete ui;
}
