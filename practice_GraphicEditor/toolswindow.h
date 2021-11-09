#ifndef TOOLSWINDOW_H
#define TOOLSWINDOW_H

#include <QMainWindow>
#include "paintwindow.h"
//#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class ToolsWindow; }
QT_END_NAMESPACE

class ToolsWindow : public QMainWindow
{
    Q_OBJECT

public:
    ToolsWindow(QWidget *parent = nullptr);
    ~ToolsWindow();
    void SetPaintWindow(PaintWindow* pw);

private:
    Ui::ToolsWindow *ui;
    PaintWindow* paintWindow;
    QTimer *timer = new QTimer();

private slots:
    void timerUpdate();
};
#endif // TOOLSWINDOW_H
