#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QWidget>

class CheckBox : public QWidget {

  Q_OBJECT

  public:
    CheckBox(QWidget *parent = 0);

  private slots:
    void showTitle(int);
};

#endif // CHECKBOX_H
