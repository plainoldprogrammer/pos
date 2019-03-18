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
    ui->pushButtonBistec->setCursor(Qt::PointingHandCursor);
    ui->pushButtonQuesadilla->setCursor(Qt::PointingHandCursor);
    ui->pushButtonAguaFresca->setCursor(Qt::PointingHandCursor);
    ui->pushButtonRefresco->setCursor(Qt::PointingHandCursor);

    ui->pushButtonPechuga->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonBistec->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonPollo->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonChicharron->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonMole->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonMilanesa->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonAlbondigas->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonCarneDeshebrada->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonHuevos->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonChilaquiles->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonSincronizada->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonBurritos->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonQuesadillaCombinada->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonQuesadillaChica->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonRefresco->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonJugo->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonQuesadilla->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonTacoChico->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonAguaFresca->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonLicuado->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonAguaDeBotella->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonCafe->setStyleSheet("QPushButton { background-color: #0099ff } ");
    ui->pushButtonTe->setStyleSheet("QPushButton { background-color: #0099ff } ");

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

void MainWindow::on_pushButtonBistec_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " BISTEC";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " BISTEC\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "BISTEC");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonPollo_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " POLLO";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " POLLO\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "POLLO");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonChicharron_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " CHICHARRON";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " CHICHARRON\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "CHICHARRON");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonMole_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " CHICHARRON";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " CHICHARRON\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "CHICHARRON");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonMilanesa_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " MILANESA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " MILANESA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "MILANESA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonAlbondigas_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " ALBONDIGAS";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " ALBONDIGAS\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "ALBONDIGAS");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonCarneDeshebrada_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " CARNE_DESHEBRADA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " CARNE_DESHEBRADA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "CARNE_DESHEBRADA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonHuevos_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " HUEVOS";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " HUEVOS\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "HUEVOS");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonChilaquiles_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " CHILAQUILES";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " CHILAQUILES\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "CHILAQUILES");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonSincronizada_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " SINCRONIZADA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " SINCRONIZADA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "SINCRONIZADA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
}

void MainWindow::on_pushButtonBurritos_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " BURRITOS";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " BURRITOS\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "BURRITOS");
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
    else if ((QString::compare(food, "BISTEC", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(bistec)";
        return quantity * 45;
    }
    else if ((QString::compare(food, "POLLO", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(pollo)";
        return quantity * 45;
    }
    else if((QString::compare(food, "CHICHARRON", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(chicharron)";
        return quantity * 45;
    }
    else if ((QString::compare(food, "MOLE", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(mole)";
        return quantity * 45;
    }
    else if ((QString::compare(food, "MILANESA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(milanesa)";
        return quantity * 45;
    }
    else if ((QString::compare(food, "ALBONDIGAS", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(albondigas)";
        return quantity * 45;
    }
    else if ((QString::compare(food, "CARNE_DESHEBRADA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(carne_deshebrada)";
        return quantity * 45;
    }
    else if ((QString::compare(food, "HUEVOS", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(huevos)";
        return quantity * 35;
    }
    else if ((QString::compare(food, "CHILAQUILES", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(chilaquiles)";
        return quantity * 35;
    }
    else if ((QString::compare(food, "SINCRONIZADA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(sincronizada)";
        return quantity * 35;
    }
    else if ((QString::compare(food, "BURRITOS", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(burritos)";
        return quantity * 35;
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
