#ifndef COLORPALETTE_H
#define COLORPALETTE_H
#include "mainwindow.h"
#include "canvas.h"
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

class ColorPalette : public QLabel
{
    Q_OBJECT
public:
    explicit ColorPalette(MainWindow *parent=0);


signals:
    void Color(QColor color);

public slots:

protected:
    void openPalette();
    virtual void mousePressEvent(QMouseEvent *e);

};

#endif // COLORPALETTE_H
