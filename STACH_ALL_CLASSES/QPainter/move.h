#ifndef MOVE_H
#define MOVE_H
#include <QMainWindow>

class Move: public QMainWindow
{
    Q_OBJECT
public:
    Move(QMainWindow *parent = 0);
protected:
    void moveEvent(QMoveEvent *event);
};

#endif // MOVE_H
