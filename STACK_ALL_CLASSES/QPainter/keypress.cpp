#include "keypress.h"
#include <QKeyEvent>
#include <QApplication>


KeyPress::KeyPress(QWidget *parent): QWidget(parent)
{}

void KeyPress::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
           qApp->quit();
}
