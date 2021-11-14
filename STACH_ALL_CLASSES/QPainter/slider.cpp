#include <QHBoxLayout>
#include "slider.h"

Slider::Slider(QWidget *parent)
    : QWidget(parent) {

  QHBoxLayout *hbox = new QHBoxLayout(this);

  slider = new QSlider(Qt::Horizontal , this);
  hbox->addWidget(slider);

  label = new QLabel("0", this);
  hbox->addWidget(label);

  connect(slider, &QSlider::valueChanged, label,
    static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
}
