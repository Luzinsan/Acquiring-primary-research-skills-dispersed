#ifndef PLUSMINUS_H
#define PLUSMINUS_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class PlusMinus: public QWidget
{
    Q_OBJECT // этот макрос должен включаться в классы, которые объявляют свои собственные сигналы и слоты
public:
    PlusMinus(QWidget *parent = 0);
private slots: // Слот — это метод, который реагирует на сигнал
    void OnPlus();
    void OnMinus();
private:
    QLabel *lbl;
};

#endif // PLUSMINUS_H
