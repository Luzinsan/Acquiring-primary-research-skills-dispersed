#ifndef CANVAS_H
#define CANVAS_H
#include "figure.h"
#include <QGraphicsScene>
#include <QColor>
#include <QPolygon>
#include <QLine>
#include <QString>
#include <QLinearGradient>

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

    Figure *figure = new Figure();
    Figure *background = nullptr;

    bool wasEraser = false;
    bool duplication = false;
    bool fillFigure = false;
    bool gradient = false;

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
    void setFillFigure();
    void setGradient();

    void setToolFigure();
    void setToolEraser();
    void setToolText();
    void drawGridLines();

    void setLine();//1
    void setRectangle();//2
    void setCircle();//3
    void setTriangle();//4
    void setTriangleRectangular();//5
    void setRhomb();//6
    void setTrapezoid();//7
    void setPentagon();//8
    void setBackground();//9

    void loadPicture(QString path);
    void savePicture(QString path);
private:
    void drawRectangle();
    void drawCircle();
    void drawTriangle();
    void drawTriangleRectangular();
    void drawRhomb();
    void drawTrapezoid();
    void drawPentagon();

    qreal x1=0, y1=0, x2=this->width(), y2=this->height();
    qreal widthGrid = 1;


    int chosenInstrument = 0;
    int chosenFigure = 0;
public:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};
#endif // CANVAS_H
