#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QComboBox>
#include "canvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QGraphicsView *viewer;
    Canvas *canvas;  // Объявляем кастомную графическую сцену
    QComboBox *combo;
private slots:
    void toggleStatusbar();
private:
    QAction *viewst;


};
#endif // MAINWINDOW_H
