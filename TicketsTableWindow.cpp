#include <QDebug>

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

void TicketsTableWindow::resizeEvent(QResizeEvent *event)
{
    qDebug() << "Resizing the table window";
    ui->tableView->resize(this->size().width() - 20, this->size().height() - 20);
    ui->tableView->setColumnWidth(0, (this->width() / 4) - 10);
    ui->tableView->setColumnWidth(1, (this->width() / 4) - 10);
    ui->tableView->setColumnWidth(2, (this->width() / 4) - 10);
    ui->tableView->setColumnWidth(3, (this->width() / 4) - 10);
}
