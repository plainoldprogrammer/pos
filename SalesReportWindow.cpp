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

QPlainTextEdit * SalesReportWindow::getPlainTextEdit()
{
	return ui->plainTextEdit;
}
