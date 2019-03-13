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
    ui->pushButtonPechuga->setCursor(Qt::PointingHandCursor);
    ui->pushButtonQuesadilla->setCursor(Qt::PointingHandCursor);
    ui->pushButtonAguaFresca->setCursor(Qt::PointingHandCursor);
    ui->pushButtonRefresco->setCursor(Qt::PointingHandCursor);

    ui->pushButtonPreviousTicket->setStyleSheet("QPushButton { background-color: #808080 } ");
    ui->pushButtonPreviousTicket->setIcon(QIcon("icons/leftarrow.ico"));
    ui->pushButtonPreviousTicket->setIconSize(QSize(85, 85));

    ui->pushButtonNextTicket->setStyleSheet("QPushButton { background-color: #808080 } ");
    ui->pushButtonNextTicket->setIcon(QIcon("icons/rightarrow.ico"));
    ui->pushButtonNextTicket->setIconSize(QSize(80, 80));

    ui->pushButtonClear->setIcon(QIcon("icons/eraser.png"));
    ui->pushButtonClear->setIconSize(QSize(145, 145));

    ui->orderDisplay->setStyleSheet("QLabel { background-color: white; color: blue }");
    ui->orderDisplay->clear();
    ui->totalAmountDisplay->setStyleSheet("QLabel { background-color: white }");
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
    ui->totalAmountDisplay->clear();
    ui->totalAmountDisplay->setText("TOTAL $ 0");
    totalAmount = 0;
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

void MainWindow::on_pushButtonPechuga_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " PECHUGA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " PECHUGA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "PECHUGA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonQuesadilla_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " QUESADILLA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " QUESADILLA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "QUESADILLA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonAguaFresca_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " AGUA_FRESCA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " AGUA FRESCA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "AGUA_FRESCA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonRefresco_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " REFRESCO";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " REFRESCO\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "REFRESCO");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

int MainWindow::calculateAmount(int quantity, QString food)
{
    std::cout << "calculateAmount(" << quantity << ", " << food.toStdString().c_str() << ") " << std::endl;

    if ((QString::compare(food, "PECHUGA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(pechuga)";
        return quantity * 50;
    }
    else if ((QString::compare(food, "QUESADILLA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(quesadilla)";
        return quantity *20;
    }
    else if ((QString::compare(food, "AGUA_FRESCA", Qt::CaseSensitive)) == 0)
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
