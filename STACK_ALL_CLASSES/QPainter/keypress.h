#ifndef KEYPRESS_H
#define KEYPRESS_H
#include <QWidget>

class KeyPress: public QWidget
{
public:
    KeyPress(QWidget *parent = 0);

protected:
   void keyPressEvent(QKeyEvent *event);
};

#endif // KEYPRESS_H
