#include <QTimer>
#include <QCursor>

#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    totalAmount = 0;
    singleFoodEntry = "";

    ui->setupUi(this);
    ui->pushButtonClear->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNum0->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNum1->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNum2->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNum3->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNum4->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNum5->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNum6->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNum7->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNum8->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNum9->setCursor(Qt::PointingHandCursor);
    ui->pushButtonComida->setCursor(Qt::PointingHandCursor);
    ui->pushButtonQuesadilla->setCursor(Qt::PointingHandCursor);
    ui->pushButtonAgua->setCursor(Qt::PointingHandCursor);
    ui->pushButtonRefresco->setCursor(Qt::PointingHandCursor);

    ui->orderDisplay->clear();
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));
    QTimer::singleShot(0, this, SLOT(showFullScreen()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->orderDisplay->clear();
}

void MainWindow::on_pushButtonNum0_clicked()
{
    singleFoodEntry += "0";
    ui->orderDisplay->setText(ui->orderDisplay->text() + "0");
}

void MainWindow::on_pushButtonNum1_clicked()
{
    singleFoodEntry += "1";
    ui->orderDisplay->setText(ui->orderDisplay->text() + "1");
}

void MainWindow::on_pushButtonNum2_clicked()
{
    singleFoodEntry += "2";
    ui->orderDisplay->setText(ui->orderDisplay->text() + "2");
}

void MainWindow::on_pushButtonNum3_clicked()
{
    singleFoodEntry += "3";
    ui->orderDisplay->setText(ui->orderDisplay->text() + "3");
}

void MainWindow::on_pushButtonNum4_clicked()
{
    singleFoodEntry += "4";
    ui->orderDisplay->setText(ui->orderDisplay->text() + "4");
}

void MainWindow::on_pushButtonNum5_clicked()
{
    singleFoodEntry += "5";
    ui->orderDisplay->setText(ui->orderDisplay->text() + "5");
}

void MainWindow::on_pushButtonNum6_clicked()
{
    singleFoodEntry += "6";
    ui->orderDisplay->setText(ui->orderDisplay->text() + "6");
}

void MainWindow::on_pushButtonNum7_clicked()
{
    singleFoodEntry += "7";
    ui->orderDisplay->setText(ui->orderDisplay->text() + "7");
}

void MainWindow::on_pushButtonNum8_clicked()
{
    singleFoodEntry += "8";
    ui->orderDisplay->setText(ui->orderDisplay->text() + "8");
}

void MainWindow::on_pushButtonNum9_clicked()
{
    singleFoodEntry += "9";
    ui->orderDisplay->setText(ui->orderDisplay->text() + "9");
}

void MainWindow::on_pushButtonComida_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " COMIDA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " COMIDA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "COMIDA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonQuesadilla_clicked()
{
    ui->orderDisplay->setText(ui->orderDisplay->text() + " QUESADILLA\n");
}

void MainWindow::on_pushButtonAgua_clicked()
{
    ui->orderDisplay->setText(ui->orderDisplay->text() + " AGUA\n");
}

void MainWindow::on_pushButtonRefresco_clicked()
{
    ui->orderDisplay->setText(ui->orderDisplay->text() + " REFRESCO\n");
}

int MainWindow::calculateAmount(int quantity, QString food)
{
    std::cout << "calculateAmount(" << quantity << ", " << food.toStdString().c_str() << ") " << std::endl;

    if ((QString::compare(food, "COMIDA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(comida)";
        return quantity * 45;
    }
    else if ((QString::compare(food, "QUESADILLA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(quesadilla)";
        return quantity *20;
    }
    else if ((QString::compare(food, "AGUA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(agua)";
        return quantity * 12;
    }
    else if ((QString::compare(food, "REFRESCO", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(refresco)";
        return quantity * 16;
    }
    else
        return -1;
}
