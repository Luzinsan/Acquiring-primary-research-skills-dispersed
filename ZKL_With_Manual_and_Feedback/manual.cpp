#include "manual.h"
#include "ui_manual.h"

#include <QMainWindow>
//#include <QApplication>

Manual::Manual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manual)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("Icons/icons8-show-property-64.png"));
    this->setWindowTitle("Мануал");
    this->setFixedSize(860, 640);

   // QVBoxLayout *vbox = new QVBoxLayout(this);
    QGridLayout *grid = new QGridLayout();
    grid->setVerticalSpacing(5);
    grid->setHorizontalSpacing(5);

    QTextBrowser* textBrowser = new QTextBrowser(this);
    grid->addWidget(textBrowser, 0, 0, 0, 0);
    const QString &page = "Manual/About.html";
    textBrowser->resize(840, 620);
    textBrowser->setSource(page);
}

Manual::~Manual()
{
    delete ui;
}

