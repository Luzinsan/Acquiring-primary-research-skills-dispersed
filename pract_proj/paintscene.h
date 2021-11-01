#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки

    // ЭТИ ПЕРЕМЕННЫЕ ПЕРЕМЕСТИТЬ В TOOLBAR
    int chosenInstrument = 0;
    int brushSize = 1;
    Qt::GlobalColor brushColor = Qt::black;
    // ПЕРЕМЕННЫЕ ВЫШЕ ПЕРЕМЕСТИТЬ В TOOLBAR

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void drawLine(int x, int y);

};

#endif // PAINTSCENE_H
