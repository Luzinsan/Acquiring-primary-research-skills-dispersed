#ifndef MANUAL_H
#define MANUAL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextBrowser>

namespace Ui {
class Manual;
}

class Manual : public QWidget
{
    Q_OBJECT

public:
    explicit Manual(QWidget *parent = nullptr);
    ~Manual();

private:
    Ui::Manual *ui;
};

#endif // MANUAL_H
