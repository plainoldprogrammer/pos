#include <iostream>

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

void MainWindow::on_pushButtonClear_clicked()
{
    ui->orderDisplay->clear();
}


void MainWindow::on_pushButtonNum1_clicked()
{
    std::cout << "Button #1 cliecked" << std::endl;
    ui->orderDisplay->setText(ui->orderDisplay->text() + "1");
}
