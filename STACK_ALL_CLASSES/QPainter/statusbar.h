#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QMainWindow>
#include <QPushButton>

class Statusbar : public QMainWindow {

  Q_OBJECT

  public:
    Statusbar(QWidget *parent = 0);

  private slots:
    void OnOkPressed();
    void OnApplyPressed();

  private:
    QPushButton *okBtn;
    QPushButton *aplBtn;
};
#endif // STATUSBAR_H
