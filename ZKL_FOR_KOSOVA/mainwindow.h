#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QComboBox>
#include "canvas.h"
#include "createfile.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QGraphicsView *viewer;
    Canvas *canvas;  // Объявляем кастомную графическую сцену
    QComboBox *combo;
    CreateFile* newFile = new CreateFile();
    bool wasEraser = false;

public slots:
    void toggleStatusbar();
    void setColor();
    void eraser();
    void brush();

    void setFigureRectangle();
    void setFigureCircle();
    void setFigureTriangleRectangular();
    void setFigureTriangle();
    void setFigureRhomb();
    void setFigureTrapezoid();
    void setFigurePentagon();

    void openFile();

private:
    QAction *viewst;


};
#endif // MAINWINDOW_H
