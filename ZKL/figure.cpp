#include "figure.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include "canvas.h"
#include <QPen>
#include <QSize>
#include <QPainterPath>
#include <QTextOption>
#include <QInputDialog>


Figure::Figure(int _x1, int _y1, int _x2, int _y2, int _chosenFigure, QPen _pen) :
    QGraphicsItem(), chosenFigure{_chosenFigure}, x1{_x1}, y1{_y1}, x2{_x2}, y2{_y2}, pen{_pen}
{
    //setFlag(ItemIsMovable);
    //setFlag(ItemIsSelectable);
   // setFlag(ItemIsPanel);
    //setFlag(ItemIsFocusScope);

    //setFlag(ItemIsFocusable);

}
Figure::~Figure()
{
}

QRectF Figure::boundingRect() const
{
    qreal penWidth = this->pen.widthF();
    QRectF rect(x1, y1, x2-x1, y2-y1);
    if(rect.width()>0 && rect.height()>0)
        rect.setRect(x1-penWidth,
                     y1-penWidth,
                     x2-x1+2*penWidth,
                     y2-y1+2*penWidth);
    else if(rect.width()>0)
        rect.adjust(-penWidth, +penWidth, penWidth, -penWidth );
    else if(rect.height()>0)
        rect.adjust(penWidth, -penWidth, -penWidth, penWidth );
    else
        rect.adjust(penWidth, penWidth, -penWidth, -penWidth );
    return  rect.normalized();
}


void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pen);
    QRectF rect = boundingRect();
    switch(chosenFigure)
    {
       case 1://void Canvas::drawLine()
            painter->drawLine(x1, y1, x2, y2);
            break;
       case 2: //void Canvas::drawRectangle()
            painter->drawRect(rect);
            //painter->fillRect(rect, pen.color());
            break;
       case 3: //void Canvas::drawCircle()
            painter->drawEllipse(rect);
            break;
       case 4://void Canvas::drawTriangle()
            painter->drawLine(x1, y2, (x1 + x2) / 2, y1);
            painter->drawLine(x2, y2, (x1 + x2) / 2, y1);
            painter->drawLine(x1, y2, x2, y2);
            break;
       case 5://void Canvas::drawTriangleRectangular()
            painter->drawLine(x1, y2, x1, y1);
            painter->drawLine(x1, y2, x2, y2);
            painter->drawLine(x1, y1, x2, y2);
            break;
        case 6:// void Canvas::drawRhomb()
            qreal cW, cH;
            if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
                cW = abs((abs(x1) + abs(x2))) / 2 + x1;
            else
                cW = abs((abs(x2) - abs(x1))) / 2 + x1;
            if ((y1 >= 0  && y2 <= 0) || (y1 <= 0 && y2 >= 0))
                cH = abs((abs(y1) + abs(y2))) / 2 + y1;
            else
                cH = abs((abs(y2) - abs(y1))) / 2 + y1;
            painter->drawLine(x1, cH, cW, y1);
            painter->drawLine(cW, y1, x2, cH);
            painter->drawLine(x2, cH, cW, y2);
            painter->drawLine(cW, y2, x1, cH);
            break;
        case 7: //void Canvas::drawTrapezoid()
           { qreal len, coeff = 0.25;
            if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
                len = (abs(x1)+abs(x2)) * coeff;
            else
                len = (abs(x2) - abs(x1)) * coeff;
             painter->drawLine(x1, y2, x2, y2);
             painter->drawLine(x1, y2, x1 + len, y1);
             painter->drawLine(x1 + len, y1, x2 - len, y1);
             painter->drawLine(x2 - len, y1, x2, y2);
            break;
         }
        case 8: //void Canvas::drawPentagon()
         {
            qreal shift, uShift, coeff = 0.25, uCoeff = 0.35;
            qreal cW;

            if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
                cW = abs((abs(x1) + abs(x2))) / 2 + x1;
            else
                cW = abs((abs(x2) - abs(x1))) / 2 + x1;

            if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
                shift = ((abs(x1) + abs(x2))) * coeff;
            else shift = abs((abs(x2) - abs(x1))) * coeff;

            if ((y1 >= 0  && y2 <= 0) || (y1 <= 0 && y2 >= 0))
                uShift = abs((abs(y1) + abs(y2))) * uCoeff;
            else uShift = abs((abs(y2) - abs(y1))) * uCoeff;

            painter->drawLine(x1 + shift, y2, x2 - shift, y2);
            painter->drawLine(x2 - shift, y2, x2, y1 + uShift);
            painter->drawLine(x2, y1 + uShift, cW, y1);
            painter->drawLine(cW, y1, x1, y1 + uShift);
            painter->drawLine(x1, y1 + uShift, x1 + shift, y2);
        }
    }
}



void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    wasPressed = true;
    update();
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    QGraphicsItem::mousePressEvent(event);
}

void Figure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}

void Figure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    wasPressed = false;
    update();
    this->setCursor(QCursor(Qt::ArrowCursor));
    QGraphicsItem::mouseReleaseEvent(event);
}


