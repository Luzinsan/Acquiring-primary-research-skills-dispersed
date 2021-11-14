#include <QHBoxLayout>
#include <QLabel>
#include "spinbox.h"

SpinBox::SpinBox(QWidget *parent)
    : QWidget(parent) {

  QHBoxLayout *hbox = new QHBoxLayout(this);
  hbox->setSpacing(15);

  spinbox = new QSpinBox(this);
  QLabel *lbl = new QLabel("0", this);

  hbox->addWidget(spinbox);
  hbox->addWidget(lbl);

  connect(spinbox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
    lbl, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
}
