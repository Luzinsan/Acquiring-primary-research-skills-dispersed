#ifndef FEEDBACK_H
#define FEEDBACK_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>


class Feedback: public QWidget
{
public:
    Feedback(QWidget *parent = 0);

private:
    QLabel *name, *email, *review;
    QLineEdit *nameline, *emailline;
    QTextEdit *reviewline;
private slots:
    void close();
    void logging();
};
#endif // FEEDBACK_H
