#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H

#include <QMainWindow>
#include "canvas.h"

namespace Ui {
class PaintWindow;
}

/*QT_BEGIN_NAMESPACE
namespace Ui { class PaintWindow; }
QT_END_NAMESPACE */

class PaintWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PaintWindow(QWidget *parent = nullptr);
    ~PaintWindow();
    int counter = 0;
    void SetLabel();
    Canvas *canvas;  // Объявляем кастомную графическую сцену

private:
    Ui::PaintWindow *ui;
    QTimer *timer;

    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();

};

#endif // PAINTWINDOW_H
