#ifndef TOOLSTWINDOW_H
#define TOOLSTWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include "paintingcanvas.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ToolstWindow; }
QT_END_NAMESPACE

class ToolstWindow : public QMainWindow
{
    Q_OBJECT

public:
    ToolstWindow(QWidget *parent = nullptr);
    ~ToolstWindow();

private slots:
    void on_toolOpenTheCanvas_clicked();

    void on_toolPen_clicked();

    void on_toolEraser_clicked();

private:
    Ui::ToolstWindow *ui;
    PaintingCanvas holst;
};
#endif // TOOLSTWINDOW_H
