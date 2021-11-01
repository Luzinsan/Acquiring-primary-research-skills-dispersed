#include "paintingcanvas.h"
#include "ui_paintingcanvas.h"

PaintingCanvas::PaintingCanvas() //конструктор
{
    //определяем свойства окна
    this->resize(1000,600);
    this->move(100,100);
    this->setWindowTitle("Graphic Editor by Pavel Kuminov");
    QPalette pl; //объект палитра необходим для задания фона окна
    pl.setColor(QPalette::Window, QColor(255, 255, 255)); //Определить цвет
    this->setAutoFillBackground(true);//фон окна заливается автоматически
    this->setPalette(pl); //Устанавливаем фон окна
    this ->setMouseTracking(true); //отслеживаем движение мыши
    f = 0;
}

void PaintingCanvas::paintEvent(QPaintEvent *event) //обработка события перерисования окна
{
        Q_UNUSED(event);
        QPainter p(this);
        switch (flagforcolor) {
            case 0:
                p.setPen (QPen(Qt::white, Qt::SolidLine));
                break;
            case 1:
                p.setPen (QPen(Qt::blue, Qt::SolidLine));
                break;
        }
        for (int i = 1; i < vcp.size(); i++)
        {
            if(vcp[i-1].fl == 1) continue; //от этой координаты не рисуем
            //проводим линию
            p.drawLine(vcp[i-1].pos.x(), vcp[i-1].pos.y(), vcp[i].pos.x(), vcp[i].pos.y());
        }
}

void PaintingCanvas::mouseMoveEvent(QMouseEvent *event) //обработка движения мыши
{
    if(!f)return; //запрет на рисование
    this->pos = event->pos();//положение курсора
    qp qp1;
    qp1.pos = this->pos;
    qp1.fl = 0;
    vcp.append(qp1); //добавили в массив для рисования
    this->update(); // обновить экран
}

void PaintingCanvas::mousePressEvent(QMouseEvent *event) //нажатие кнопки мыши
{
    //кнопка нажата и при движении рисуется линиия
    if(event->button() == Qt::LeftButton) f = 1;
}

void PaintingCanvas::mouseReleaseEvent(QMouseEvent *event) //отпускание кнопки мыши
{
    if(event->button() == Qt::LeftButton)
    {
        f = 0;
        //установили флаг запрета рисования
        if(vcp.size()>0)vcp[vcp.size()-1].fl = 1;
    }
    if(event->button() == Qt::RightButton)
    {
        //удалить последний элемент линии
        if(vcp.size()>0)vcp.remove(vcp.size()-1);
        //от последней точки линия не проводится
        if(vcp.size()>0)vcp[vcp.size() - 1].fl = 1;
        //обновить экран
        this->update();
    }
}
