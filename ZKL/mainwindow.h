#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
private slots:
    void toggleStatusbar();
private:
    QAction *viewst;

};
#endif // MAINWINDOW_H
