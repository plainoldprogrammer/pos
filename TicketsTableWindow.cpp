#include "TicketsTableWindow.h"
#include "ui_ticketstablewindow.h"

TicketsTableWindow::TicketsTableWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TicketsTableWindow)
{
    ui->setupUi(this);
    ui->buttonBox->hide();
}

TicketsTableWindow::~TicketsTableWindow()
{
    delete ui;
}

QTableView * TicketsTableWindow::getTableView()
{
    return ui->tableView;
}
