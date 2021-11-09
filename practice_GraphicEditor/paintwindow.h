#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H

#include "canvas.h"

#include <QWidget>
#include <QTimer>
//#include <QTime>

namespace Ui {
class PaintWindow;
}

class PaintWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PaintWindow(QWidget *parent = nullptr);
    ~PaintWindow();
    Canvas *canvas;  // Объявляем кастомную графическую сцену
    void SetActiveInstrument(int instrumentId);
    void SetBrushSize(int size);
    void SetBrushColor(Qt::GlobalColor color);

private:
    Ui::PaintWindow *ui;
};

#endif // PAINTWINDOW_H
