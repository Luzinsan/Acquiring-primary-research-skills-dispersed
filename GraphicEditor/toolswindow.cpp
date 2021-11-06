#include "toolswindow.h"
#include "ui_toolswindow.h"

ToolsWindow::ToolsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolsWindow)
{
    paintWindow = nullptr;
    ui->setupUi(this);
}

ToolsWindow::~ToolsWindow()
{
    delete ui;
}

void ToolsWindow::SetPaintWindow(PaintWindow* pw)
{
    paintWindow = pw;
}

void ToolsWindow::on_counter_clicked()
{
    if (brushSize < 10) {
       brushSize++;
       paintWindow->canvas->pen.setWidth(brushSize);
    }
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
