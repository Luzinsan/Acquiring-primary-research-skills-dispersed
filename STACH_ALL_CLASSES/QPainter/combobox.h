#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>

class ComboBox : public QWidget {

  Q_OBJECT

  public:
    ComboBox(QWidget *parent = 0);

  private:
    QComboBox *combo;
    QLabel *label;
};

#endif // COMBOBOX_H
