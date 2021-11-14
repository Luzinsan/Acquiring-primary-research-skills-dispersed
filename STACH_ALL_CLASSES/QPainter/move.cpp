#include "move.h"
#include <QMoveEvent>
#include <QStatusBar>

Move::Move(QMainWindow *parent) : QMainWindow(parent)
{

}

void Move::moveEvent(QMoveEvent *event)
{

    int x = event->pos().x();
    int y = event->pos().y();

    QString text = QString::number(x) + "," + QString::number(y);

    setWindowTitle(text);
    statusBar()->showMessage(text);


}
