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
    this->setWindowIcon(QIcon("Icons/icons8-layers-64.png"));
    this->setWindowTitle("Оставить отзыв");
    QVBoxLayout *vbox = new QVBoxLayout(this);
    QGridLayout *grid = new QGridLayout();
    grid->setVerticalSpacing(5);
    grid->setHorizontalSpacing(5);

    QLabel *title = new QLabel("Обратная связь", this);
    title->setFont(QFont("Times New Roman", 20));
    title->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    grid->addWidget(title, 0, 0, 1, 2);


    name = new QLabel("Имя:", this);
    // следующие два параметра — это строка и столбец в сетке компоновки, куда мы помещаем наш виджет;
    // последние параметры определяют, сколько строк будет занимать текущий виджет
    // (в нашем случае метка будет охватывать только один столбец и одну строку).
    name->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    grid->addWidget(name, 1, 0, 1, 1);


    nameline = new QLineEdit(this);
    grid->addWidget(nameline, 1, 1, 1, 1);

    email = new QLabel("Email:", this);
    email->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    grid->addWidget(email, 2, 0, 1, 1);


    emailline = new QLineEdit(this);
    grid->addWidget(emailline, 2, 1, 1, 1);

    review = new QLabel("Сообщение:", this);
    review->setAlignment(Qt::AlignRight | Qt::AlignTop);
    grid->addWidget(review, 3, 0, 1, 1);


    reviewline = new QTextEdit(this);
    grid->addWidget(reviewline, 3, 1, 3, 1);

    vbox->addLayout(grid);
    vbox->addStretch(1);

    // Кнопки Ок и Отмена
    QHBoxLayout *hbox = new QHBoxLayout();

    QPushButton *okbtn = new QPushButton("Ок", this);
    connect(okbtn, &QPushButton::clicked, this, &Feedback::logging);
    hbox->addWidget(okbtn, 0, Qt::AlignRight);

    QPushButton *quitbtn = new QPushButton("Отмена", this);
    connect(quitbtn, &QPushButton::clicked, this, &Feedback::close);
    hbox->addWidget(quitbtn, 0, Qt::AlignLeft);


    vbox->addLayout(hbox);

    setLayout(vbox);
}

void Feedback::close()
{
    this->hide();
}

void Feedback::logging()
{
      QFile file("logs.txt");

        if(file.open(QIODevice::Append)) {
            QTextStream stream(&file);
            stream << name->text() << " " << nameline->text() << "\n\n" <<
                      email->text() << " " << emailline->text() << "\n\n" <<
                      review->text() << "\n" << reviewline->toPlainText() <<
                      "\n---------\n";
            file.close();
         }
        close();
}
