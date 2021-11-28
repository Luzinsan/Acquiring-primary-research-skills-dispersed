#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QGraphicsScene>
#include <QComboBox>
#include "canvas.h"
#include "manual.h"
#include "feedback.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QGraphicsView *viewer;
    Canvas *canvas;  // Объявляем кастомную графическую сцену
    QComboBox *combo;
    Manual* manualWindow = new Manual();
    Feedback* feedbackWindow = new Feedback();


public slots:
    void toggleStatusbar();
    void setColor();

    void setFigureLine();
    void setFigureRectangle();
    void setFigureCircle();
    void setFigureTriangleRectangular();
    void setFigureTriangle();
    void setFigureRhomb();
    void setFigureTrapezoid();
    void setFigurePentagon();

    void openFile();
    void saveFile();
    void createFile();

    void openManualWindow();
    void openFeedbackWindow();

private:
    QAction *viewst;
};
#endif // MAINWINDOW_H
