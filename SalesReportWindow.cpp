#include "SalesReportWindow.h"
#include "ui_salesreportwindow.h"

SalesReportWindow::SalesReportWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SalesReportWindow)
{
    ui->setupUi(this);
    ui->buttonBox->hide();
}

SalesReportWindow::~SalesReportWindow()
{
    delete ui;
}

void SalesReportWindow::showReport()
{
    QSqlQuery query;
    QString report;

    if (query.exec("SELECT SUM(amount) AS TOTAL FROM 'tickets';"))
    {
        query.next();
        int total = query.value(0).toInt();
        report = "Total: " + QString::number(total);
    }
    if (query.exec("SELECT COUNT(*) AS TICKETS_QTY FROM 'tickets';"))
    {
        query.next();
        int quantity = query.value(0).toInt();
        report.append("\nSales quantity: " + QString::number(quantity));
    }
    if (query.exec("SELECT MAX(amount) FROM tickets;"))
    {
        query.next();
        int max = query.value(0).toInt();
        report.append("\nMax sale: " + QString::number(max));
    }
    if (query.exec("SELECT MIN(amount) FROM 'tickets';"))
    {
        query.next();
        int min = query.value(0).toInt();
        report.append("\nMin sale: " + QString::number(min));
    }
    if (query.exec("SELECT MIN(dateandtime) FROM 'tickets';"))
    {
        query.next();
        QString date = query.value(0).toString();
        report.append("\nFirst sale: " + date);
    }
    if (query.exec("SELECT MAX(dateandtime) FROM 'tickets';"))
    {
        query.next();
        QString date = query.value(0).toString();
        report.append("\nLast sale: " + date);
    }

    ui->plainTextEdit->setPlainText(report);
    this->exec();
}
