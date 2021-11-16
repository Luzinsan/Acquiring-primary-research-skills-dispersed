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

class Canvas : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Canvas(QObject *parent = 0);
    ~Canvas();
    QPen *pen = new QPen(Qt::black, 2, Qt::SolidLine);
    QColor previusColor = QColor(Qt::black);
    QPolygon *pointsOfLine = new QPolygon(); // вектор точек для линий (всех)
    QLine *current_line = new QLine();
    QList<QLine> *polyline = new QList<QLine>(); // лист, состоящий из линий - образует кривую
    QList<QList<QLine>> *figures = new QList<QList<QLine>>(); // лист, содержащий все объекты на холсте

    void loadPicture(QString path);

    //void copySceneAsIMG();

public slots:
    void setSize(int size);
    void setToolLine();
    void setToolRays();
    void setToolFigure();

    void setRectangle();
    void setCircle();
    void setTriangle();
    void setTriangleRectangular();
    void setRhomb();
    void setTrapezoid();
    void setPentagon();

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

    QPointF previousPoint;      // Координаты предыдущей точки

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
    void drawLine(QPoint start_p, QPoint end_p);
};

#endif // CANVAS_H
