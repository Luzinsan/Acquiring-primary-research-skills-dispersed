#include "paintscene.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
    //rubberBand = nullptr;
    rubberBand = new QRubberBand(QRubberBand::Rectangle);
}

paintScene::~paintScene()
{

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

void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    mouseOnStartMoveXPosition = -1;
    mouseOnStartMoveYPosition = -1;
    //rubberBand->hide();
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    mouseOnPressXPosition = event->screenPos().x();
    mouseOnPressYPosition = event->screenPos().y();

    printf("x = %d, y = %d\n", mouseOnPressXPosition, mouseOnPressYPosition);

    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               1,
               1,
               QPen(Qt::NoPen),
               QBrush(brushColor));
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();

   origin = event->pos();
        //if (!rubberBand)
        //    rubberBand = new QRubberBand(QRubberBand::Rectangle);
        rubberBand->setGeometry(1, 1, 1, 1); // QRect(origin.toPoint(), QSize())
        rubberBand->show();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (mouseOnStartMoveXPosition == -1 && mouseOnStartMoveYPosition == -1) {
        mouseOnStartMoveXPosition = event->screenPos().x();
        mouseOnStartMoveYPosition = event->screenPos().y();
    }
    switch (chosenInstrument)
    {
        case 0: // Рисование
            drawLine(event->scenePos().x(), event->scenePos().y());
            break;
        case 1: // Ластик
            break;
        case 2: // Прямоугольное выделение объекта
            rubberBand->setGeometry(mouseOnStartMoveXPosition, mouseOnStartMoveYPosition,
                                    event->screenPos().x() - mouseOnStartMoveXPosition,
                                    event->screenPos().y() - mouseOnStartMoveYPosition); //QRect(origin.toPoint(), event->scenePos().toPoint()).normalized()
            break;
        default: // выбран какой-то другой инструмент
            break;
    }


    // Обновляем данные о предыдущей координате
    previousPoint = event->scenePos();
}
