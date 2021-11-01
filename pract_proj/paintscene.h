#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QRubberBand>

class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки

    // ПЕРЕМЕННЫЕ НИЖЕ ПЕРЕМЕСТИТЬ В TOOLBAR
    int chosenInstrument = 0;
    int brushSize = 1;
    Qt::GlobalColor brushColor = Qt::black;
    // ПЕРЕМЕННЫЕ ВЫШЕ ПЕРЕМЕСТИТЬ В TOOLBAR

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

#endif // PAINTSCENE_H
