#include <QPainter>
#include "colours.h"

Colours::Colours(QWidget *parent)
    : QWidget(parent)
{ }

void Colours::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e);

  doPainting();
}

void Colours::doPainting() {

  QPainter painter(this);



  QPen pen(QColor("#882255"), 5, Qt::DotLine);
  QVector<qreal> dashes;
  qreal space = 4;

  dashes << 1 << space << 5 << space;

  pen.setStyle(Qt::CustomDashLine);
  pen.setDashPattern(dashes);

  painter.setPen(pen);

  painter.setBrush(QBrush("#c56c00"));
  painter.drawChord(0, 0, 100,100,400,180*10);
  //painter.drawRect(10, 15, 90, 60);

  painter.setBrush(QBrush("#1ac500"));
  painter.drawRect(130, 15, 90, 60);

  painter.setBrush(QBrush("#539e47"));
  painter.drawArc(250, 15, 250+90, 15+60, 30*30, 120*30);
  //painter.drawRect(250, 15, 90, 60);

  painter.setBrush(QBrush("#004fc5"));
  painter.drawRect(10, 105, 90, 60);

  painter.setBrush(QBrush("#c50024"));
  painter.drawRect(130, 105, 90, 60);

  painter.setBrush(QBrush("#9e4757"));
  painter.drawRect(250, 105, 90, 60);

  painter.setBrush(QBrush("#5f3b00"));
  painter.drawRect(10, 195, 90, 60);

  painter.setBrush(QBrush("#4c4c4c"));
  painter.drawRect(130, 195, 90, 60);

  painter.setBrush(QBrush("#785f36"));
  painter.drawRect(250, 195, 90, 60);
}
