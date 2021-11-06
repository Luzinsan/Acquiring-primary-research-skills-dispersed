#include "paintwindow.h"
#include "ui_paintwindow.h"
#include <iostream>

PaintWindow::PaintWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PaintWindow)
{
    ui->setupUi(this);

    this->resize(860, 640);

    canvas = new Canvas();       // Инициализируем графическую сцену
    ui->graphicsView->setScene(canvas);  // Устанавливаем графическую сцену

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &PaintWindow::slotTimer);
    timer->start(100);          // Запускаем таймер
}


PaintWindow::~PaintWindow()
{
    delete ui;
}

void PaintWindow::SetLabel()
{
    ui->counterLabel->setText(QString::number(counter));
}

void PaintWindow::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    printf("\nENTERED THE SLOT_TIMER\n");
    timer->stop();
    //canvas->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    //printf("\n%d ----- %d\n", ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    //ui->graphicsView->setSceneRect(0,0, this->width() - 20, this->height() - 20);
    canvas->setSceneRect(0,0, this->width() - 40, this->height() - 40);
    ui->graphicsView->setFixedSize(this->width() - 20, this->height() - 20);
    //ui->graphicsView->setSceneRect()
    printf("\n%d ----- %d\n", this->width() - 20, this->height() - 20);


}

void PaintWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
    QWidget::resizeEvent(event);
}
