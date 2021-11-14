#include "toolswindow.h"
#include "ui_toolswindow.h"

ToolsWindow::ToolsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ToolsWindow)
{
    ui->setupUi(this);

    //timer = new QTimer();       // Инициализируем таймер
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, &ToolsWindow::timerUpdate);
    timer->start();
}

ToolsWindow::~ToolsWindow()
{
    delete ui;
}


void ToolsWindow::SetPaintWindow(PaintWindow* pw)
{
    paintWindow = pw;
}

void ToolsWindow::timerUpdate()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    printf("\nENTERED THE SLOT_TIMER\n");
    //timer->stop();
    //canvas->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    //printf("\n%d ----- %d\n", ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    //ui->graphicsView->setSceneRect(0,0, this->width() - 20, this->height() - 20);
    paintWindow->canvas->setSceneRect(0,0, 820, 600);
    //paintWindow->ui->graphicsView->setFixedSize(this->width() - 20, this->height() - 20);
    //ui->graphicsView->setSceneRect()
    //printf("\n%d ----- %d\n", this->width() - 20, this->height() - 20);


}

/*
 * При установке инструмента в качестве активного менять chosenInstrument (paintWindow->canvas->SetChosenInstrument(НОМЕР_ИНСТРУМЕНТА)
 * Номера инструментов:
 *      0 - Кисть (pen)
 *      1 - Ластик (установить размер кисти ~5, цвет - белый)
 *      2 - Выделение области
 *      3 - Заливка
 * Обращение к свойству инструмента:
 *  paintWindow->canvas->НАЗВАНИЕ_ИНСТРУМЕНТА.ПОЛЕ_ИНСТРУМЕНТА(НОВОЕ_ЗНАЧЕНИЕ_ПОЛЯ);
 *
 *  инструмент pen:
 *      - setWidth (не меньше 1 и не больше 10)
 *      - setColor
 */
