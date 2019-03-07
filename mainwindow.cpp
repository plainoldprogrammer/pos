#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->orderDisplay->clear();
}


void MainWindow::on_pushButton_11_clicked()
{
    ui->orderDisplay->setText("1");
}
