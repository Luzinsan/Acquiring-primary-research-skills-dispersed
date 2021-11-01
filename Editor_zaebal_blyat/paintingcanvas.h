#ifndef PAINTINGCANVAS_H
#define PAINTINGCANVAS_H

#include <QMainWindow>
#include <QPainter>
#include <QtMath>
#include <QtWidgets>

struct qp //структура для хранения координаты при рисовании
{
   QPoint pos;
   int fl;
};

namespace Ui { class PaintingCanvas; }

class PaintingCanvas : public QMainWindow
{
    Q_OBJECT

public:
    explicit PaintingCanvas();
    void paintEvent( QPaintEvent *event);
    QPoint pos; //координаты точки для рисования
    void mouseMoveEvent(QMouseEvent *event);
    QVector<qp> vcp; //массив (вектор) для хранения рисунка
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    int f;
    int flagforcolor = 1;

private:
    Ui::PaintingCanvas *ui;
};

#endif // PAINTINGCANVAS_H
