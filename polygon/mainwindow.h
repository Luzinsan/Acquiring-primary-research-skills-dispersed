#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QList>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QPushButton>
#include <QMainWindow>
#include <QTimer>
struct polygonal{
    QVector<QPoint> topsList;
    QPen pen;
    QBrush brush;
};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    polygonal *Polygonal;
    void mousePressEvent(QMouseEvent *event);

private:
    QGraphicsScene *sceneLb;
    Ui::MainWindow *ui;
};

void polygonFillingScanLine(polygonal *pol, QGraphicsScene *scene);
#endif // MAINWINDOW_H
