#include <QTextStream>
#include <QCheckBox>
#include <QHBoxLayout>
#include "disconnect.h"

Disconnect::Disconnect(QWidget *parent)
    : QWidget(parent) {

  QHBoxLayout *hbox = new QHBoxLayout(this);
  hbox->setSpacing(5);

  clickBtn = new QPushButton("Click", this);
  hbox->addWidget(clickBtn, 0, Qt::AlignLeft | Qt::AlignTop);

  QCheckBox *cb = new QCheckBox("Connect", this);
  cb->setCheckState(Qt::Checked);
  hbox->addWidget(cb, 0, Qt::AlignLeft | Qt::AlignTop);

  connect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
  connect(cb, &QCheckBox::stateChanged, this, &Disconnect::onCheck);
}

void Disconnect::onClick() {

  QTextStream out(stdout);
  out << "Button clicked" << endl;
}

void Disconnect::onCheck(int state) {

  if (state == Qt::Checked)
    connect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);
  else
    disconnect(clickBtn, &QPushButton::clicked, this, &Disconnect::onClick);

}
