#ifndef PROGRESSBAREX_H
#define PROGRESSBAREX_H


#include <QWidget>
#include <QProgressBar>
#include <QPushButton>

class ProgressBarEx : public QWidget {

  Q_OBJECT

  public:
    ProgressBarEx(QWidget *parent = 0);

  private:
    int progress;
    QTimer *timer;
    QProgressBar *pbar;
    QPushButton *startBtn;
    QPushButton *stopBtn;
    static const int DELAY = 100000;
    static const int MAX_VALUE = 1000;

    void updateBar();
    void startMyTimer();
    void stopMyTimer();
};

#endif // PROGRESSBAREX_H
