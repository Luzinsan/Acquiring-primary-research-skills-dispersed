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
   // Figure *f = new Figure();
    QList<Figure*> figures;
    Figure *figure = nullptr;
    bool wasEraser = false;
    bool duplication = false;
    void loadPicture(QString path);

    //void copySceneAsIMG();

public slots:
    void setSize(int size);
    void setToolLine();
    void setToolDuplication();
    void setToolFigure();
    void setToolEraser();

    void setRectangle();//1
    void setCircle();//2
    void setTriangle();//3
    void setTriangleRectangular();//4
    void setRhomb();//5
    void setTrapezoid();//6
    void setPentagon();//7

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

    int chosenInstrument = 0; // 1 - Прямая линия;
    int chosenFigure = 0;

    QRubberBand* rubberBand;
    QPointF origin;

public:

    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // CANVAS_H
