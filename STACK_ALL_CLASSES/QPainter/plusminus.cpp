#include "plusminus.h"
#include <QGridLayout>

PlusMinus::PlusMinus(QWidget *parent) : QWidget(parent)
{
    QPushButton *plsBtn = new QPushButton("+", this);
    QPushButton *minBtn = new QPushButton("-", this);
    lbl = new QLabel("0", this);

    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(plsBtn, 0, 0);
    grid->addWidget(minBtn, 0, 1);
    grid->addWidget(lbl, 1, 1);

    setLayout(grid);
    connect(plsBtn, &QPushButton::clicked, this, &PlusMinus::OnPlus);
    connect(minBtn, &QPushButton::clicked, this, &PlusMinus::OnMinus);


}


void PlusMinus::OnPlus()
{
    int val = lbl->text().toInt();// выполняем конвертацию в тип int
    val++;                        // выполняем инкремент значения
    lbl->setText(QString::number(val)); // конвертируем обратно в Qstring и устанавливаем новый текст для label
}


void PlusMinus::OnMinus()
{
    int val = lbl->text().toInt();
    val--;
    lbl->setText(QString::number(val));
}
