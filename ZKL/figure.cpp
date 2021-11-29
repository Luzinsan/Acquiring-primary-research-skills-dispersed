#include "figure.h"
#include <QLinearGradient>
#include <QBrush>
#include <iostream>

Figure::Figure(qreal _x1, qreal _y1, qreal _x2, qreal _y2, int _chosenFigure, QPen _pen, bool _gradient, bool _fillPath)
    : x1{_x1}, y1{_y1}, x2{_x2}, y2{_y2}, chosenFigure{_chosenFigure}, pen{_pen}, gradient{_gradient}, fillPath{_fillPath} {}
Figure::~Figure(){}

QRectF Figure::boundingRect() const
{
    qreal penWidth = this->pen.widthF()+3;
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


void Figure::swap(qreal *a, qreal *b)
{
    qreal temp = *a;
    *a = *b;
    *b = temp;
}

void Figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(gradient)
    {
        linearGrad = QLinearGradient(x1,y1,x2,y2);
        linearGrad.setColorAt(0, QColor(0,255,255,100));
        linearGrad.setColorAt(0.5, QColor(120,60,255,150));
        linearGrad.setColorAt(1, QColor(17,127,200,255));
        linearGrad.setSpread(QGradient::ReflectSpread);
    }
    //if(chosenFigure == 1)
      //  fillPath = false;

    if(fillPath)
        if(gradient)
        {
            painter->setBrush(linearGrad);
           // painter->setPen(Qt::black);
            painter->setPen(QPen(QBrush(linearGrad), pen.width(), pen.style(), pen.capStyle() ));
        }
        else
        {
            painter->setBrush(pen.brush());
            painter->setPen(pen);
        }
    else
        if(gradient) painter->setPen(QPen(QBrush(linearGrad), pen.width(), pen.style(), pen.capStyle() ));
        else         painter->setPen(pen);

    switch(chosenFigure)
    {
    case 1:// линия
        painter->drawLine(x1, y1, x2, y2);
        break;
    case 2: // прямоугольник
        painter->drawRect(x1, y1, x2-x1, y2-y1);
        //painter->fillRect(rect, pen.color());
        break;
    case 3: // круг/окружность
        painter->drawEllipse(x1, y1, x2-x1, y2-y1);
        break;
    case 4:// треугольник
    {
        QPointF points[3] = {QPoint(x1,y2), QPoint((x1 + x2) / 2, y1), QPoint(x2, y2)};
        painter->drawPolygon(points, 3);
        break;
    }
    case 5:// прямоугольный треугольник
    {
        QPointF points[3] = {QPoint(x1, y1), QPoint(x1, y2), QPoint(x2, y2)};
        painter->drawPolygon(points, 3);
        break;
    }
    case 6:// ромб
    {
        if (x2 < x1 && y2 < y1)
        {
            swap(&x1, &x2);
            swap(&y1, &y2);
        }
        else if (x2 < x1)
            swap(&x1, &x2);
        else if (y2 < y1)
            swap(&y2, &y1);

        qreal cW, cH;
        if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
            cW = abs((abs(x1) + abs(x2))) / 2 + x1;
        else
            cW = abs((abs(x2) - abs(x1))) / 2 + x1;
        if ((y1 >= 0  && y2 <= 0) || (y1 <= 0 && y2 >= 0))
            cH = abs((abs(y1) + abs(y2))) / 2 + y1;
        else
            cH = abs((abs(y2) - abs(y1))) / 2 + y1;

        QPointF points[4] = {QPoint(x1, cH), QPoint(cW, y1), QPoint(x2, cH), QPoint(cW, y2)};
        painter->drawPolygon(points, 4);
        break;
    }
    case 7: // трапеция
    {
        qreal len, coeff = 0.25;
        if ((x1 >= 0  && x2 <= 0) || (x1 <= 0 && x2 >= 0))
            len = (abs(x1)+abs(x2)) * coeff;
        else
            len = (abs(x2) - abs(x1)) * coeff;

        QPointF points[4] = {QPoint(x1, y2), QPoint(x1 + len, y1), QPoint(x2 - len, y1), QPoint(x2, y2)};
        painter->drawPolygon(points, 4);
        break;
    }
    case 8: // пятиугольник
    {
        if (x2 < x1 && y2 < y1)
        {
            swap(&x1, &x2);
            swap(&y1, &y2);
        }
        else if (x2 < x1)
            swap(&x1, &x2);
        else if (y2 < y1)
            swap(&y2, &y1);

        qreal shift, uShift, coeff = 0.25, uCoeff = 0.35, cW;

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

        QPointF points[5] = {QPoint(x1 + shift, y2), QPoint(x2 - shift, y2), QPoint(x2, y1 + uShift),
                             QPoint(cW, y1), QPoint(x1, y1 + uShift)};
        painter->drawPolygon(points, 5);

        break;
    }
    }
}
