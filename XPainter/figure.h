#ifndef FIGURE_H
#define FIGURE_H
#include <QObject>
#include <QGraphicsItem>
#include <QPen>
#include <QRectF>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QList>
#include <QGraphicsSceneMouseEvent>


class Figure :  public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

     Figure(qreal x1=0, qreal y1=0, qreal x2=0, qreal y2=0, int chosenFigure=0,QPen pen = QPen(Qt::black), bool gradient = false, bool fillPath = false);
     Q_INTERFACES(QGraphicsItem);
     QRectF boundingRect() const override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    ~Figure();
private:
    qreal x1=0,y1=0,x2=1,y2=1;
    int chosenFigure = 0;
    QPen pen;
    bool gradient, fillPath;

    void swap(qreal *a, qreal *b);
    QLinearGradient linearGrad;
};
#endif // FIGURE_H
