#include "paintscene.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{

}

paintScene::~paintScene()
{

}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               1,
               1,
               QPen(Qt::NoPen),
               QBrush(brushColor));
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();
}

void paintScene::drawLine(int x, int y)
{
    // Отрисовываем линии с использованием предыдущей координаты
    addLine(previousPoint.x(),
            previousPoint.y(),
            x,
            y,
            QPen(brushColor, brushSize, Qt::SolidLine,Qt::RoundCap));
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    switch (chosenInstrument)
    {
        case 0: // Рисование
            drawLine(event->scenePos().x(), event->scenePos().y());
            break;
        case 1: // Ластик
            break;
        case 2: // Прямоугольное выделение объекта
            break;
        default: // выбран какой-то другой инструмент
            break;
    }


    // Обновляем данные о предыдущей координате
    previousPoint = event->scenePos();
}
