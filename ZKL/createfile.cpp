#include "createfile.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>
#include <QGraphicsPixmapItem>

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>



CreateFile::CreateFile(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->addStretch(1); // addStretch() вставляем между виджетами промежуток динамического размера

    // Формы для заполнения
    // Левый столбец содержит метки, а правый столбец содержит виджеты ввода (однострочные редакторы, счетчики и т.д.).
    QFormLayout *formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter); // устанавливаем выравнивание виджетов-меток

    QLineEdit *nameEdit = new QLineEdit(this);
    formLayout->addRow("Имя:", nameEdit);

    QLineEdit *pathEdit = new QLineEdit(this);
    formLayout->addRow("Путь:", pathEdit);
    vbox->addLayout(formLayout);


    // Кнопки Ок и Отмена
    QHBoxLayout *hbox = new QHBoxLayout();
    QPushButton *okbtn = new QPushButton("Ок", this);
    hbox->addWidget(okbtn, 1, Qt::AlignRight);
    QPushButton *cancelbtn = new QPushButton("Отмена", this);
    connect(cancelbtn, &QPushButton::clicked, this, &QApplication::quit);
    hbox->addWidget(cancelbtn,0);

    vbox->addLayout(hbox); //Затем добавляем менеджер горизонтальной компоновки внутрь менеджера вертикальной компоновки

    setLayout(vbox);
}

