#include "toolstwindow.h"
#include "ui_toolstwindow.h"

ToolstWindow::ToolstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ToolstWindow)
{
    ui->setupUi(this);
}

ToolstWindow::~ToolstWindow()
{
    delete ui;
}

void ToolstWindow::on_toolOpenTheCanvas_clicked()
{
    holst.show();
}

void ToolstWindow::on_toolPen_clicked()
{
    holst.flagforcolor = 1;
}

void ToolstWindow::on_toolEraser_clicked()
{
    holst.flagforcolor = 0;
}

