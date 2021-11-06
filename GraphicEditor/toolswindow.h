#ifndef TOOLSWINDOW_H
#define TOOLSWINDOW_H

#include <paintwindow.h>

#include <QWidget>

namespace Ui {
class ToolsWindow;
}

class ToolsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ToolsWindow(QWidget *parent = nullptr);
    ~ToolsWindow();
    void SetPaintWindow(PaintWindow* pw);

private slots:
    void on_counter_clicked();

private:
    Ui::ToolsWindow *ui;
    PaintWindow* paintWindow;
    int brushSize = 1;
};

#endif // TOOLSWINDOW_H
