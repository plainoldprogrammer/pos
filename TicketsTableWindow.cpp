#include "TicketsTableWindow.h"
#include "ui_ticketstablewindow.h"

TicketsTableWindow::TicketsTableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TicketsTableWindow)
{
    ui->setupUi(this);
}

TicketsTableWindow::~TicketsTableWindow()
{
    delete ui;
}
