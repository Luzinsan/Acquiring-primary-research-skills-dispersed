#ifndef FIGURE_H
#define FIGURE_H
//#include "canvas.h"
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>
#include <QPen>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QRectF>
#include <QList>
#include <QStyleOptionGraphicsItem>

class Figure :  public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

     Figure(int x1=0, int y1=0, int x2=0, int y2=0, int chosenFigure=0, QPen pen = QPen(Qt::black));
     QRectF boundingRect() const override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    ~Figure();

signals:

private:
    int chosenFigure = 0; // 1 - Квадрат; 2 - Круг; 3 - Прямоугольный треугольник; 4 - Ромб; 5 - Трапеция
    int x1=0,x2=1,y1=0,y2=1;

    QPen pen;
    bool wasPressed = false;

    QGraphicsItem *item;
    QList<QGraphicsItem> *list_items;

private slots:

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // FIGURE_H
