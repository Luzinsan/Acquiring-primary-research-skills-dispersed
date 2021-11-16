#include "feedback.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QApplication>

Feedback::Feedback(QWidget *parent): QWidget(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout(this);
    QGridLayout *grid = new QGridLayout();
    grid->setVerticalSpacing(5);
    grid->setHorizontalSpacing(5);

    QLabel *title = new QLabel("Обратная связь", this);
    title->setFont(QFont("Times New Roman", 20));
    title->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    grid->addWidget(title, 0, 0, 1, 2);


    QLabel *name = new QLabel("Имя:", this);
    // следующие два параметра — это строка и столбец в сетке компоновки, куда мы помещаем наш виджет;
    // последние параметры определяют, сколько строк будет занимать текущий виджет
    // (в нашем случае метка будет охватывать только один столбец и одну строку).
    name->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    grid->addWidget(name, 1, 0, 1, 1);


    QLineEdit *nameline = new QLineEdit(this);
    grid->addWidget(nameline, 1, 1, 1, 1);

    QLabel *email = new QLabel("Email:", this);
    email->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    grid->addWidget(email, 2, 0, 1, 1);


    QLineEdit *emailline = new QLineEdit(this);
    grid->addWidget(emailline, 2, 1, 1, 1);

    QLabel *review = new QLabel("Сообщение:", this);
    review->setAlignment(Qt::AlignRight | Qt::AlignTop);
    grid->addWidget(review, 3, 0, 1, 1);


    QTextEdit *reviewline = new QTextEdit(this);
    grid->addWidget(reviewline, 3, 1, 3, 1);

    vbox->addLayout(grid);
    vbox->addStretch(1);

    // Кнопки Ок и Отмена
    QHBoxLayout *hbox = new QHBoxLayout();
    QPushButton *okbtn = new QPushButton("Ок", this);
    hbox->addWidget(okbtn, 0, Qt::AlignRight);
    QPushButton *quitbtn = new QPushButton("Отмена", this);
    connect(quitbtn, &QPushButton::clicked, qApp, &QApplication::quit);
    hbox->addWidget(quitbtn, 0, Qt::AlignLeft);


    vbox->addLayout(hbox);

    setLayout(vbox);
}
