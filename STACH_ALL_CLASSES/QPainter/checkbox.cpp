#include <QCheckBox>
#include <QHBoxLayout>
#include "checkbox.h"

CheckBox::CheckBox(QWidget *parent)
    : QWidget(parent) {

  QHBoxLayout *hbox = new QHBoxLayout(this);

  QCheckBox *cb = new QCheckBox("Show Title", this);
  cb->setCheckState(Qt::Checked);
  hbox->addWidget(cb, 0, Qt::AlignLeft | Qt::AlignTop);

  connect(cb, &QCheckBox::stateChanged, this, &CheckBox::showTitle);
}

void CheckBox::showTitle(int state) {

  if (state == Qt::Checked) {
    setWindowTitle("QCheckBox");
  } else {
    setWindowTitle(" ");
  }
}
