#include "colorpalette.h"


#include <QImage>
#include <QDebug>
#include <QBitmap>

ColorPalette::ColorPalette(MainWindow *parent) :
    MainWindow(parent)
{
    setAutoFillBackground(true);
    QPalette pal;
    QPixmap pix("Icons/palette.png");
    setMask(pix.mask());
    pal.setBrush(backgroundRole(), QBrush(pix));
    resize(pix.size());
}

void ColorPalette::mousePressEvent(QMouseEvent *e)
{
    QRect onePixRect(e->pos(), QSize(1,1));
    QPixmap pix = QPixmap::grabWidget(this, onePixRect);
    QImage img = pix.toImage();
    QColor color(img.pixel(0, 0));
    emit Color(color);
}


void ColorPalette::openPalette()
{

    palette = new ColorPalette(this);

    setPalette(QColor("#24178b"));
    resize(500, 500);
    setWindowTitle("ColorPalette!!!");
    show();
}
