#ifndef CANVAS_H
#define CANVAS_H


#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QRubberBand>
#include <QPixmap>
#include <QString>
#include <QPicture>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QLine>
#include "figure.h"

class Canvas : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Canvas(QObject *parent = 0);
    ~Canvas();
    QPen pen = QPen(Qt::black, 2, Qt::SolidLine);
    QColor currentColor = QColor(Qt::black);
    QPolygon *pointsOfLine = new QPolygon(); // вектор точек для линий (всех)
    QLine *current_line = new QLine;
    QList<QLine> *polyline = new QList<QLine>; // лист, состоящий из линий - образует кривую
    QList<QList<QLine>> *polylines = new QList<QList<QLine>>; // лист, содержащий все объекты на холсте
    QList<Figure*> figures;
    Figure *figure = nullptr;
    bool wasEraser = false;
    bool duplication = false;
    void loadPicture(QString path);

    //void copySceneAsIMG();

public slots:
    void setSolidLine();
    void setDashLine();
    void setDotLine();
    void setDashDotLine();
    void setDashDotDotLine();
    void setCustomLine();

    void deleteAll();

    void setSize(int size);
    void setToolLine();
    void setToolDuplication();
    void setToolFigure();
    void setToolEraser();
    void setToolText();

    void setLine();//1
    void setRectangle();//2
    void setCircle();//3
    void setTriangle();//4
    void setTriangleRectangular();//5
    void setRhomb();//6
    void setTrapezoid();//7
    void setPentagon();//8

private:

    void drawRectangle();
    void drawCircle();
    void drawTriangle();
    void drawTriangleRectangular();
    void drawRhomb();
    void drawTrapezoid();
    void drawPentagon();

    qreal x1, y1, x2, y2;

    int mouseOnEndPressXPosition = -2,
    mouseOnEndPressYPosition = -2;

    QImage canvasCopy;

    int chosenInstrument = 0;
    int chosenFigure = 0;

    QRubberBand* rubberBand;
    QPointF origin;

public:

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CANVAS_H
