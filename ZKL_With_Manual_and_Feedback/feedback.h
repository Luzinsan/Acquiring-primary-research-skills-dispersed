#ifndef FEEDBACK_H
#define FEEDBACK_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QFile>

class Feedback: public QWidget
{
public:
    Feedback(QWidget *parent = 0);

private:
    QLabel *name;
    QLineEdit *nameline;
    QLabel *email;
    QLineEdit *emailline;
    QLabel *review;
    QTextEdit *reviewline;



private slots:
    void close();
    void logging();
};

#endif // FEEDBACK_H
