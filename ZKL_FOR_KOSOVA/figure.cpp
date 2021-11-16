#include "figure.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include "canvas.h"
#include <QPen>

// =============== ТРЕУГОЛЬНИК ===================
/*
 * addLine(x1, y2, (x1 + x2) / 2, y1, *pen);
   addLine(x2, y2, (x1 + x2) / 2, y1, *pen);
   addLine(x1, y2, x2, y2, *pen);
 */


// =============== ПРЯМОУГОЛЬНЫЙ ТРЕУГОЛЬНИК ===================
/*
 * addLine(x1, y2, x1, y1, *pen);
   addLine(x1, y2, x2, y2, *pen);
   addLine(x1, y1, x2, y2, *pen);
 */


// =============== ТРАПЕЦИЯ ===================
/*
 * qreal len;
            if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
                len = (abs(x1)+abs(x2)) * coeff;
            else
                len = (abs(x2) - abs(x1)) * coeff;
            addLine(x1, y2, x2, y2, *pen);
            addLine(x1, y2, x1 + len, y1, *pen);
            addLine(x1 + len, y1, x2 - len, y1, *pen);
            addLine(x2 - len, y1, x2, y2, *pen);
 */


// =============== РОМБ ===================
/*
 * qreal cW, cH;
            if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
                cW = abs((abs(x1) + abs(x2))) / 2 + x1;
            else
                cW = abs((abs(x2) - abs(x1))) / 2 + x1;
            if ((y1 >= 0  && y2 <= 0) || (y1 <= 0 && y2 >= 0))
                cH = abs((abs(y1) + abs(y2))) / 2 + y1;
            else
                cH = abs((abs(y2) - abs(y1))) / 2 + y1;
            addLine(x1, cH, cW, y1, *pen);
            addLine(cW, y1, x2, cH, *pen);
            addLine(x2, cH, cW, y2, *pen);
            addLine(cW, y2, x1, cH, *pen);
 */

/*
Figure::Figure(QObject *parent, Canvas *canvas) :
    QObject(), QGraphicsItem(), Canvas(canvas)
{
}

Figure::~Figure(){}

QRectF Figure::boundingRect() const
{
    qreal penWidth = this->pen->widthF();
    /*switch(chosenFigure)
    {
    case 1: case 2: case 3: case 4: case 5:
        // квадрат


    case 2: // круг
        return QRectF(0, 0,  0, 0);

    case 3: // прямоугольный треугольник
        return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,   20 + penWidth, 20 + penWidth);

   case 4: // ромб
        return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);

    case 5: // трапеция
        return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);

    default:
        return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth, 20 + penWidth);

    }*/
    //return QRectF(this->topLevelItem()->x() - penWidth, this->topLevelItem()->y() - penWidth,
     //             this->width() +  penWidth * 2,        this->height() + penWidth * 2);
    /*return QRectF(0,0,1000,1000);
}



void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);

    pen->setWidth(5);
    pen->setCapStyle(Qt::SquareCap);
    painter->setPen(*pen);
  //  painter->setPen(Qt::black);
   // painter->setBrush(Qt::transparent);


    painter->brushOrigin();
    painter->drawLine(0,0,500,550);


    switch(chosenFigure)
    {
    case 1: // квадрат
        painter->drawRect(0, 0, 1000, 1000);
        addRect(0, 0, 100, 100, *pen);
        break;
    case 2: // круг
        addEllipse(x1, y1, x2  - x1, y2  - y1, *pen);
        break;
    case 3: // прямоугольный треугольник
        addLine(x1, y2, (x1 + x2) / 2, y1, *pen);
        addLine(x2, y2, (x1 + x2) / 2, y1, *pen);
        addLine(x1, y2, x2, y2, *pen);
        break;
   case 4: // ромб
        qreal cW, cH;
        if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
            cW = abs((abs(x1) + abs(x2))) / 2 + x1;
        else
            cW = abs((abs(x2) - abs(x1))) / 2 + x1;
        if ((y1 >= 0  && y2 <= 0) || (y1 <= 0 && y2 >= 0))
            cH = abs((abs(y1) + abs(y2))) / 2 + y1;
        else
            cH = abs((abs(y2) - abs(y1))) / 2 + y1;
        addLine(x1, cH, cW, y1, *pen);
        addLine(cW, y1, x2, cH, *pen);
        addLine(x2, cH, cW, y2, *pen);
        addLine(cW, y2, x1, cH, *pen);
        break;
    case 5: // трапеция
        qreal len, coeff = 1;
        if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
            len = (abs(x1)+abs(x2)) * coeff;
        else
            len = (abs(x2) - abs(x1)) * coeff;
        addLine(x1, y2, x2, y2, *pen);
        addLine(x1, y2, x1 + len, y1, *pen);
        addLine(x1 + len, y1, x2 - len, y1, *pen);
        addLine(x2 - len, y1, x2, y2, *pen);
        break;

    }
}

void Figure::setFigureRectangle()
{
    chosenFigure = 1;
}
void Figure::setFigureCircle()
{
    chosenFigure = 2;
}
void Figure::setFigureTriangleRectangular()
{
    chosenFigure = 3;
}
void Figure::setFigureRhomb()
{
   chosenFigure = 4;
}
void Figure::setFigureTrapezoid()
{
    chosenFigure = 5;
}




void Figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!wasPressed)
    {
        x1 = event->scenePos().toPoint().x();
        y1 = event->scenePos().toPoint().y();
        wasPressed = true;
    } else {
        x2 = event->scenePos().toPoint().x();
        y2 = event->scenePos().toPoint().y();
        this->setPos(mapToScene(event->scenePos()));
        item->setCursor(QCursor(Qt::ClosedHandCursor));
        wasPressed = false;
    }
}
*/
