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

class Canvas : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit Canvas(QObject *parent = 0);
    ~Canvas();
    QPen pen;
    Canvas *canvas;  // Объявляем кастомную графическую сцену
    void setChosenInstrument(int id);
    void loadPicture(QString path);
    //void copySceneAsIMG();

private:
    QPointF previousPoint;      // Координаты предыдущей точки

    QImage canvasCopy;

    int chosenInstrument = 0;

    int mouseOnPressXPosition = 0;
    int mouseOnPressYPosition = 0;

    int mouseOnStartMoveXPosition = -1;
    int mouseOnStartMoveYPosition = -1;

    QRubberBand* rubberBand;
    QPointF origin;

private:

    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void drawLine(int x, int y);


};

#endif // CANVAS_H
