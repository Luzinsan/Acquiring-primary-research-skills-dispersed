#include <QFrame>
#include <QSplitter>
#include <QHBoxLayout>
#include "splitter.h"

Splitter::Splitter(QWidget *parent)
    : QWidget(parent) {

  QHBoxLayout *hbox = new QHBoxLayout(this);

  QFrame *topleft = new QFrame(this);
  topleft->setFrameShape(QFrame::StyledPanel);

  QFrame *topright = new QFrame(this);
  topright->setFrameShape(QFrame::StyledPanel);

  QSplitter *splitter1 = new QSplitter(Qt::Horizontal, this);
  splitter1->addWidget(topleft);
  splitter1->addWidget(topright);

  QFrame *bottom = new QFrame(this);
  bottom->setFrameShape(QFrame::StyledPanel);

  QSplitter *splitter2 = new QSplitter(Qt::Vertical, this);
  splitter2->addWidget(splitter1);
  splitter2->addWidget(bottom);

  QList<int> sizes({50, 100});
  splitter2->setSizes(sizes);

  hbox->addWidget(splitter2);
}
