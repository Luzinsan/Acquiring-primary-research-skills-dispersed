#include "verticalbox.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QPushButton>
#include <QApplication>

VerticalBox::VerticalBox(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->setSpacing(10);
    vbox->addStretch(1);

    QHBoxLayout *hbox = new QHBoxLayout(this);
    hbox->setSpacing(1);

    QListWidget *lw = new QListWidget(this);
    lw->addItem("The Omen");
    lw->addItem("The Exorcist");
    lw->addItem("Notes on a scandal");
    lw->addItem("Fargo");
    lw->addItem("Capote");
    hbox->addWidget(lw);

    QPushButton *add = new QPushButton("Добавить", this);
    vbox->addWidget(add);

    QPushButton *rename = new QPushButton("Переименовать", this);
    vbox->addWidget(rename);

    QPushButton *remove = new QPushButton("Удалить", this);
    vbox->addWidget(remove);

    QPushButton *removeall = new QPushButton("Удалить всё", this);
    vbox->addWidget(removeall);

    vbox->addStretch(1); // addStretch() вставляем между виджетами промежуток динамического размера

    QHBoxLayout *hboxbtn = new QHBoxLayout(this);
    QPushButton *okbtn = new QPushButton("Ок", this);
    // Установив коэффициент растяжения равным 1 для кнопки OK,
    // виджет не будет растягиваться на все выделенное ему пространство,
    // тем самым остается свободное место от левой до правой стороны окна.
    // Наконец, константа Qt::AlignRight выравнивает виджет по правому краю
    hboxbtn->addWidget(okbtn, 1, Qt::AlignRight); //

    QPushButton *cancelbtn = new QPushButton("Отмена", this);
    connect(cancelbtn, &QPushButton::clicked, this, &QApplication::quit);
    hboxbtn->addWidget(cancelbtn,0);

    vbox->addLayout(hboxbtn); //Затем добавляем менеджер горизонтальной компоновки внутрь менеджера вертикальной компоновки

    hbox->addSpacing(15);
    hbox->addLayout(vbox); // Метод addLayout() используется для вложения одной компоновки в другую

    setLayout(hbox);

}
