#ifndef FIGURE_H
#define FIGURE_H
#include "canvas.h"
#include <QObject>
#include <QWidget>
#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QRectF>
#include <QList>
#include <QStyleOptionGraphicsItem>
/*
class Figure :  public QGraphicsItem, public Canvas
{
    Q_OBJECT
public:
    explicit Figure(QObject *parent = 0, Canvas *canvas = 0);
     QRectF boundingRect() const override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    ~Figure();

signals:

private:
    int chosenFigure = 0; // 1 - Квадрат; 2 - Круг; 3 - Прямоугольный треугольник; 4 - Ромб; 5 - Трапеция
    int x1,x2,y1,y2;

    bool wasPressed = false;
    QGraphicsItem *item;
    QList<QGraphicsItem> *list_items;

public:

    void setFigureRectangle();
    void setFigureCircle();
    void setFigureTriangleRectangular();
    void setFigureRhomb();
    void setFigureTrapezoid();

private slots:


    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    //void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

};
*/
#endif // FIGURE_H
