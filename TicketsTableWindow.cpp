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

void TicketsTableWindow::resizeEvent(QResizeEvent *event)
{
    ui->tableView->resize(this->size().width() - 20, this->size().height() - 20);
    ui->tableView->setColumnWidth(1, (this->width() / 3) + 18);
    ui->tableView->setColumnWidth(2, (this->width() / 3) + 18);
    ui->tableView->setColumnWidth(3, (this->width() / 3) + 18);
}

void TicketsTableWindow::showTickets()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    if(query.exec("SELECT item AS ITEM, amount AS AMOUNT, datetime(dateandtime, 'localtime') AS 'DATE' FROM 'tickets';"))
    {
        model->setQuery(std::move(query));
        ui->tableView->setModel(model);
    }

    this->exec();
}
