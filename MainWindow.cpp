#include <QTimer>
#include <QCursor>
#include <QKeyEvent>
#include <QDebug>
#include <QList>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

#include <iostream>

#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "Ticket.h"
#include "SettingsWindow.h"
#include "TicketsTableWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), settings("plainoldprogrammer", "pos")
{
    totalAmount = 0;
    singleFoodEntry = "";

    ui->setupUi(this);

    /*
     * Setup hand cursor for the ui buttons
     */
    ui->pushButtonReport->setCursor(Qt::PointingHandCursor);
    ui->pushButtonSettings->setCursor(Qt::PointingHandCursor);
    ui->pushButtonTicketsTable->setCursor(Qt::PointingHandCursor);
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
    ui->pushButtonPollo->setCursor(Qt::PointingHandCursor);
    ui->pushButtonChicharron->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMole->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMilanesa->setCursor(Qt::PointingHandCursor);
    ui->pushButtonAlbondigas->setCursor(Qt::PointingHandCursor);
    ui->pushButtonCarneDeshebrada->setCursor(Qt::PointingHandCursor);
    ui->pushButtonHuevos->setCursor(Qt::PointingHandCursor);
    ui->pushButtonChilaquiles->setCursor(Qt::PointingHandCursor);
    ui->pushButtonSincronizada->setCursor(Qt::PointingHandCursor);
    ui->pushButtonBurritos->setCursor(Qt::PointingHandCursor);
    ui->pushButtonQuesadillaCombinada->setCursor(Qt::PointingHandCursor);
    ui->pushButtonQuesadillaChica->setCursor(Qt::PointingHandCursor);
    ui->pushButtonRefresco->setCursor(Qt::PointingHandCursor);
    ui->pushButtonJugo->setCursor(Qt::PointingHandCursor);
    ui->pushButtonQuesadilla->setCursor(Qt::PointingHandCursor);
    ui->pushButtonTacoChico->setCursor(Qt::PointingHandCursor);
    ui->pushButtonAguaFresca->setCursor(Qt::PointingHandCursor);
    ui->pushButtonLicuado->setCursor(Qt::PointingHandCursor);
    ui->pushButtonAguaDeBotella->setCursor(Qt::PointingHandCursor);
    ui->pushButtonCafe->setCursor(Qt::PointingHandCursor);
    ui->pushButtonTe->setCursor(Qt::PointingHandCursor);
    ui->pushButtonTortillas->setCursor(Qt::PointingHandCursor);
    ui->pushButtonPreviousTicket->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNextTicket->setCursor(Qt::PointingHandCursor);
    ui->pushButtonDeleteCurrentTicket->setCursor(Qt::PointingHandCursor);
    ui->pushButtonCreateNewTicket->setCursor(Qt::PointingHandCursor);

    /*
     * Setup  the push buttons style
     */
    ui->pushButtonPechuga->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonBistec->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonPollo->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonChicharron->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMole->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMilanesa->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonAlbondigas->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonCarneDeshebrada->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonHuevos->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonChilaquiles->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonSincronizada->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonBurritos->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonQuesadillaCombinada->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonQuesadillaChica->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonRefresco->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonJugo->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonQuesadilla->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonTacoChico->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonAguaFresca->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonLicuado->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonAguaDeBotella->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonCafe->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonTe->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonTortillas->setStyleSheet("QPushButton { background-color: #99d6ff } ");

    ui->pushButtonPreviousTicket->setStyleSheet("QPushButton { background-color: #808080 } ");
    ui->pushButtonPreviousTicket->setIcon(QIcon("icons/leftarrow.ico"));
    ui->pushButtonPreviousTicket->setIconSize(QSize(85, 85));
    ui->pushButtonPreviousTicket->setShortcut(QKeySequence(Qt::Key_Left));

    ui->pushButtonNextTicket->setStyleSheet("QPushButton { background-color: #808080 } ");
    ui->pushButtonNextTicket->setIcon(QIcon("icons/rightarrow.ico"));
    ui->pushButtonNextTicket->setIconSize(QSize(80, 80));
    ui->pushButtonNextTicket->setShortcut(QKeySequence(Qt::Key_Right));

    ui->pushButtonDeleteCurrentTicket->setStyleSheet("QPushButton { background-color: #808080 } ");
    ui->pushButtonDeleteCurrentTicket->setIcon(QIcon("icons/delete.png"));
    ui->pushButtonDeleteCurrentTicket->setIconSize(QSize(80, 80));

    ui->pushButtonCreateNewTicket->setStyleSheet("QPushButton{ background-color: #808080 } ");
    ui->pushButtonCreateNewTicket->setIcon(QIcon("icons/new-ticket.png"));
    ui->pushButtonCreateNewTicket->setIconSize(QSize(80, 80));
    ui->pushButtonCreateNewTicket->setToolTip("Save current ticket and create a new one");

    ui->pushButtonClear->setIcon(QIcon("icons/eraser.png"));
    ui->pushButtonClear->setIconSize(QSize(145, 145));
    ui->pushButtonClear->setToolTip("Clear current ticket");

    ui->pushButtonSettings->setIcon(QIcon("icons/settings.png"));
    ui->pushButtonSettings->setIconSize(QSize(145, 145));
    ui->pushButtonSettings->setToolTip("Settings");

    ui->pushButtonTicketsTable->setIcon(QIcon("icons/table.png"));
    ui->pushButtonTicketsTable->setIconSize(QSize(145, 145));
    ui->pushButtonTicketsTable->setToolTip("Display all tickets on a table");

    ui->pushButtonReport->setIcon(QIcon("icons/report.png"));
    ui->pushButtonReport->setIconSize(QSize(145, 145));
    ui->pushButtonReport->setToolTip("Display sells report");

    /*
     * Setup the ticket ui based on the stored settings
     */
    ui->ticketHeader->setStyleSheet("QLabel {background-color: white; color: blue} ");
    ui->ticketHeader->clear();
    QString restaurantName = settings.value("restaurantName").toString();
    QString restaurantAddress = settings.value("restaurantAddress").toString();
    characterTicketSectionSeparator = settings.value("characterTicketSectionSeparator").toChar();
    ui->ticketHeader->setText(restaurantName + "\n" + restaurantAddress + "\n" + getTicketSectionLineSeparator(characterTicketSectionSeparator));
    ui->orderDisplay->setStyleSheet("QLabel { background-color: white; color: blue }");
    ui->orderDisplay->clear();
    ui->totalAmountDisplay->setStyleSheet("QLabel { background-color: white }");
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));
    ui->ticketFooter->setStyleSheet("QLabel { background-color: white; color: blue } ");
    QString footer = settings.value("footerMessage").toString();
    ui->ticketFooter->setText(getTicketSectionLineSeparator(characterTicketSectionSeparator) + "\n" + footer);

    if (settings.value("fullscreen").toBool())
    {
        QTimer::singleShot(0, this, SLOT(showFullScreen()));
    }
    else
    {
        QTimer::singleShot(0, this, SLOT(showMaximizedScreen()));
    }

    /*
     * Initialize the inner settings window
     */
    settingsWindow = new SettingsWindow();
    settingsWindow->setFixedSize(settingsWindow->size());
    settingsWindow->setWindowTitle("Settings");

    /*
     * Initialize the inner window to display a table with all the tickets
     */
    ticketsTableWindow = new TicketsTableWindow();
    ticketsTableWindow->setWindowTitle("All Tickets");

    /*
     * Initialize the connection with the database
     */
    createDBConnection();


    if (isTicketsTableFromDbEmpty())
    {
        /*
         * Create a new ticket when the program starts
         */
        currentTicketIndex = tickets.size();
        ticket = new Ticket();
        tickets.push_back(ticket);
        ui->pushButtonPreviousTicket->setEnabled(false);
        ui->pushButtonNextTicket->setEnabled(false);
        ui->pushButtonDeleteCurrentTicket->setEnabled(false);
        ui->lineEditCurrentTicket->setText(QString::number(currentTicketIndex + 1));
        ui->lineEditTotalTickets->setText(QString::number(tickets.size()));
    }
    else
    {
        /*
         * Load tickets from the database
         */

         // Create a dummy ticket that is necesary to dont get an empty QVector.
         // This will be removed inmediately in the next 'loadTicketsFromDb()' call.
         // Without this dummy element at the container, the compiler generate an assertion
         // and didn't start the program.
        tickets.push_back(new Ticket());

        loadTicketsFromDb();
    }
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

void MainWindow::on_pushButtonSettings_clicked()
{
    // Load the current configuration
    settingsWindow->setRestaurantName(settings.value("restaurantName").toString());
    settingsWindow->setRestaurantAddress(settings.value("restaurantAddress").toString());
    settingsWindow->setFooterMessage(settings.value("footerMessage").toString());
    settingsWindow->setTicketSectionCharSeparator(settings.value("characterTicketSectionSeparator").toChar());
    settingsWindow->setFullScreen(settings.value("fullscreen").toBool());

    // Applying the configuration
    if (settingsWindow->exec() == QDialog::Accepted)
    {
        qDebug() << "Applying new settings";

        QString ticketSectionSeparator = getTicketSectionLineSeparator(settingsWindow->getTicketSectionCharSeparator());
        ui->ticketHeader->setText(settingsWindow->getRestaurantName() + "\n" + settingsWindow->getRestaurantAddress() + "\n" + ticketSectionSeparator);
        ui->ticketFooter->setText(ticketSectionSeparator + "\n" + settingsWindow->getFooterMessage());

        if (settingsWindow->isFullScreen())
        {
            QTimer::singleShot(0, this, SLOT(showFullScreen()));
        }
        else
        {
            QTimer::singleShot(0, this, SLOT(showMaximized()));
        }

        // Making settings persistent on the machine
        settings.setValue("restaurantName", settingsWindow->getRestaurantName());
        settings.setValue("restaurantAddress", settingsWindow->getRestaurantAddress());
        settings.setValue("footerMessage", settingsWindow->getFooterMessage());
        settings.setValue("characterTicketSectionSeparator", settingsWindow->getTicketSectionCharSeparator());
        settings.setValue("fullscreen", settingsWindow->isFullScreen());
    }
}

void MainWindow::on_pushButtonTicketsTable_clicked()
{
    qDebug() << "Display a table with all the tickets";

    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    if(query.exec("SELECT id AS ID, item AS ITEM, amount AS AMOUNT, datetime(dateandtime, 'localtime') AS 'DATE' FROM 'tickets';"))
    {
        qDebug() << "All tickets from db has been selected";

        model->setQuery(query);
        QTableView *tableView = ticketsTableWindow->getTableView();
        tableView->setModel(model);
    }

    ticketsTableWindow->exec();
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
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);

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
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
}

void MainWindow::on_pushButtonCarneDeshebrada_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " CARNE_DESHEBRADA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " CARNE DESHEBRADA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "CARNE_DESHEBRADA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
}

void MainWindow::on_pushButtonQuesadillaCombinada_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " QUESADILLA_COMBINADA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " QUESADILLA COMBINADA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "QUESADILLA_COMBINADA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    writeOnTicket(ticket);
}

void MainWindow::on_pushButtonQuesadillaChica_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " QUESADILLA_CHICHA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " QUESADILLA CHICA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "QUESADILLA_CHICA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
}


void MainWindow::on_pushButtonJugo_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " JUGO";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " JUGO\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "JUGO");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
}

void MainWindow::on_pushButtonTacoChico_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " TACO_CHICO";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " TACO CHICO\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "TACO_CHICO");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    writeOnTicket(ticket);
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
    writeOnTicket(ticket);
}

void MainWindow::on_pushButtonLicuado_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " LICUADO";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " LICUADO\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "LICUADO");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    writeOnTicket(ticket);
}

void MainWindow::on_pushButtonAguaDeBotella_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " AGUA_DE_BOTELLA";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " AGUA DE BOTELLA\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "AGUA_DE_BOTELLA");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    writeOnTicket(ticket);
}

void MainWindow::on_pushButtonCafe_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " CAFE";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " CAFE\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "CAFE");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    writeOnTicket(ticket);
}

void MainWindow::on_pushButtonTe_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " TE";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " TE\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "TE");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    writeOnTicket(ticket);
}

void MainWindow::on_pushButtonTortillas_clicked()
{
    std::cout << std::endl;
    singleFoodEntry = singleFoodEntry + " TORTILLAS";
    ui->orderDisplay->setText(ui->orderDisplay->text() + " TORTILLAS\n");

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, "TORTILLAS");
    std::cout << "singleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    writeOnTicket(ticket);
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
    else if ((QString::compare(food, "QUESADILLA_COMBINADA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(quesadilla_combinada);";
        return quantity * 22;
    }
    else if ((QString::compare(food, "QUESADILLA_CHICA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(quesadilla_chica)";
        return quantity * 11;
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
    else if ((QString::compare(food, "JUGO", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(jugo)";
        return quantity * 16;
    }
    else if ((QString::compare(food, "TACO_CHICO", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(taco_chico)";
        return quantity * 11;
    }
    else if ((QString::compare(food, "LICUADO", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(licuado)";
        return quantity * 16;
    }
    else if ((QString::compare(food, "AGUA_DE_BOTELLA", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(agua_de_botella)";
        return quantity * 12;
    }
    else if ((QString::compare(food, "CAFE", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(cafe)";
        return quantity * 12;
    }
    else if ((QString::compare(food, "TE", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(te)";
        return quantity * 12;
    }
    else if ((QString::compare(food, "TORTILLAS", Qt::CaseSensitive)) == 0)
    {
        std::cout << "compare(tortillas)";
        return quantity * 6;
    }
    else
    {
        return -1;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_0)
    {
        on_pushButtonNum0_clicked();
    }
    if (event->key() == Qt::Key_1)
    {
        on_pushButtonNum1_clicked();
    }
    else if (event->key() == Qt::Key_2)
    {
        on_pushButtonNum2_clicked();
    }
    else if (event->key() == Qt::Key_3)
    {
        on_pushButtonNum3_clicked();
    }
    else if (event->key() == Qt::Key_4)
    {
        on_pushButtonNum4_clicked();
    }
    else if (event->key() == Qt::Key_5)
    {
        on_pushButtonNum5_clicked();
    }
    else if (event->key() == Qt::Key_6)
    {
        on_pushButtonNum6_clicked();
    }
    else if (event->key() == Qt::Key_7)
    {
        on_pushButtonNum7_clicked();
    }
    else if (event->key() == Qt::Key_8)
    {
        on_pushButtonNum8_clicked();
    }
    else if (event->key() == Qt::Key_9)
    {
        on_pushButtonNum9_clicked();
    }
}

void MainWindow::on_pushButtonPreviousTicket_clicked()
{
    qDebug() << "pushButtonPreviousTicket clicked";

    if (currentTicketIndex > 0)
    {
        currentTicketIndex--;
        Ticket *ticket = tickets.at(currentTicketIndex);
        ui->orderDisplay->setText(ticket->getBody());
        ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(ticket->getTicketTotalAmount()));
        ui->lineEditCurrentTicket->setText(QString::number(currentTicketIndex + 1));

        if (currentTicketIndex == 0)
        {
           ui->pushButtonPreviousTicket->setEnabled(false);
        }
    }

    if (currentTicketIndex < tickets.size())
    {
        ui->pushButtonNextTicket->setEnabled(true);
    }

    qDebug() << "At the end of the on_pushButtonPreviousTicket_clicked() call the currentTicketIndex is: " << currentTicketIndex;
}

void MainWindow::on_pushButtonNextTicket_clicked()
{
    qDebug() << "\n";
    qDebug() << "pushButtonNextTicket clicked";
    qDebug() << "tickets.size(): " << QString::number(tickets.size());
    qDebug() << "currentTicketIndex: " << QString::number(currentTicketIndex);

    currentTicketIndex++;

    if (currentTicketIndex < tickets.size())
    {
        Ticket *ticket = tickets.at(currentTicketIndex);
        ui->orderDisplay->setText(ticket->getBody());
        ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(ticket->getTicketTotalAmount()));
        ui->lineEditCurrentTicket->setText(QString::number(currentTicketIndex + 1));
    }

    // Detect if the current ticket is the last ticket
    if ((currentTicketIndex + 1) == tickets.size())
    {
        ui->pushButtonNextTicket->setEnabled(false);
    }

    if (currentTicketIndex > 0)
    {
        ui->pushButtonPreviousTicket->setEnabled(true);
    }

    qDebug() << "At the end of the on_pushButtonNextTicket_clicked() call the currentTicketIndex is: " << currentTicketIndex;
}

void MainWindow::on_pushButtonDeleteCurrentTicket_clicked()
{
    qDebug() << "pushButtonDeleteCurrentTicket clicked";
    qDebug() << "Delete ticket #" << currentTicketIndex ;

    if ( (currentTicketIndex == 0) && (tickets.size() > 1) )
    {
        tickets.remove(currentTicketIndex);
        ui->lineEditTotalTickets->setText(QString::number(tickets.size()));

        Ticket *ticket = tickets.at(0);
        ui->orderDisplay->setText(ticket->getBody());
        ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(ticket->getTicketTotalAmount()));
    }
    else if ( (currentTicketIndex == 0) && (tickets.size() == 1) )
    {
        ui->pushButtonDeleteCurrentTicket->setEnabled(false);
        ui->pushButtonNextTicket->setEnabled(false);
    }
    else if ( (currentTicketIndex + 1) == tickets.size())
    {

        tickets.remove(currentTicketIndex);
        ui->lineEditCurrentTicket->setText(QString::number(tickets.size()));
        ui->lineEditTotalTickets->setText(QString::number(tickets.size()));

        currentTicketIndex--;
        Ticket *ticket = tickets.at(currentTicketIndex);
        ui->orderDisplay->setText(ticket->getBody());
        ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(ticket->getTicketTotalAmount()));

        if (tickets.size() == 1)
        {
            ui->pushButtonPreviousTicket->setEnabled(false);
            ui->pushButtonDeleteCurrentTicket->setEnabled(false);
        }
    }
    else
    {
        /*
         *  Show the next most recent ticket of the deleted
         */

        tickets.remove(currentTicketIndex);
        ui->lineEditTotalTickets->setText(QString::number(tickets.size()));

        Ticket *ticket = tickets.at(currentTicketIndex);
        ui->orderDisplay->setText(ticket->getBody());
        ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(ticket->getTicketTotalAmount()));
    }

}

void MainWindow::on_pushButtonCreateNewTicket_clicked()
{
    qDebug() << "pushButtonCreateNewTicket clicked" ;

    /*
     * Store the current ticket in the db before create a new one
     */
     if (currentTicketIndex == (tickets.size() - 1))
     {
        QString ticketItem = ticket->getBody();
        int ticketAmount = ticket->getTicketTotalAmount();
        QSqlQuery sqlQuery;

        if (sqlQuery.exec("INSERT INTO 'tickets' ('id', 'item', 'amount') VALUES (NULL, '" + ticketItem + "', '" + QString::number(ticketAmount) + "');"))
        {
            qDebug() << "New ticket inserted in table tickets";
        }
        else
        {
            qWarning() << "Can't insert a new ticket in table tickets";
        }
    }

    /*
     * Create empty ticket
     */
    ticket = new Ticket();
    tickets.push_back(ticket);

    ticket->setHeader(ui->ticketHeader->text());

    ui->orderDisplay->clear();
    ticket->setBody(ui->orderDisplay->text());

    totalAmount = 0;
    ui->totalAmountDisplay->setText("TOTAL $ 0");
    ticket->setTicketTotalAmount(totalAmount);

    ticket->setFooter(ui->ticketFooter->text());

    ui->pushButtonPreviousTicket->setEnabled(true);
    ui->pushButtonDeleteCurrentTicket->setEnabled(true);

    // If the ticket showed was the last (NOTE: tickets.size() increase 1)
    if (currentTicketIndex == (tickets.size() - 2))
    {
        currentTicketIndex++;
    }
    else
    {
        currentTicketIndex = tickets.size() - 1;
    }

    ui->lineEditCurrentTicket->setText(QString::number(tickets.size()));
    ui->lineEditTotalTickets->setText(QString::number(tickets.size()));
}

void MainWindow::writeOnTicket(Ticket * ticketToWrite)
{
    qDebug() << "\n";
    qDebug() << "Call to writeOnTicket() on currentTicketIndex: " << currentTicketIndex ;
    ticketToWrite->setBody(ui->orderDisplay->text());
    ticketToWrite->setTicketTotalAmount(totalAmount);
}

QString MainWindow::getTicketSectionLineSeparator(QChar c)
{
    QString line = "";

    for (int i = 0; i < 43; i++)
    {
        line.append(c);
    }

    return line;
}

void MainWindow::createDBConnection()
{
    /*
     * Initialize sqlite to get working with Qt
     */
     const QString DRIVER("QSQLITE");

     if (QSqlDatabase::isDriverAvailable(DRIVER))
     {
        qDebug() << "QSQLITE driver is available";
     }

     db = QSqlDatabase::addDatabase(DRIVER);
     db.setDatabaseName("C:\\tmp\\database.db");

    if (db.open())
    {
        qDebug() << "The db has been opened";
    }
    else
    {
        qWarning() << "Can't open db";
    }

    QSqlQuery sqlQuery;
    if (sqlQuery.exec("CREATE TABLE IF NOT EXISTS 'tickets' ( 'id'	INTEGER PRIMARY KEY AUTOINCREMENT, 'item'	TEXT, 'amount'	INTEGER, 'dateandtime' DATETIME DEFAULT CURRENT_TIMESTAMP);"))
    {
        qDebug() << "Table tickets has been created";
    }
    else
    {
        qWarning() <<"Can't create table tickets" ;
    }
}

void MainWindow::loadTicketsFromDb()
{
    QSqlQuery query;

    if (query.exec("SELECT * FROM 'tickets';"))
    {
        qDebug() << "Tickets data has been retrieved from the database";
        qDebug() << "At the init tickets has " << tickets.size() << " elements" << tickets.last()->getBody();

        tickets.remove(0);

        while (query.next())
        {
           // qDebug() << query.value(1).toString();

            ticket = new Ticket();
            tickets.push_back(ticket);

            ticket->setHeader(ui->ticketHeader->text());
            ticket->setBody(query.value(1).toString());
            ticket->setTicketTotalAmount(query.value(2).toInt());
            ticket->setFooter(ui->ticketFooter->text());
        }

        qDebug() << tickets.size() << " tickets loaded from database to memory";

        // Create and empty ticket
        ticket = new Ticket();
        ticket->setHeader(ui->ticketHeader->text());
        ticket->setBody("");
        ticket->setTicketTotalAmount(0);
        ticket->setFooter(ui->ticketFooter->text());
        tickets.push_back(ticket);

        // Put the new ticket over all the loeaded tickets
        ui->orderDisplay->setText((tickets[tickets.size() - 1])->getBody());
        ui->totalAmountDisplay->setText("TOTAL $ " + QString::number((tickets[tickets.size() - 1])->getTicketTotalAmount()));
        ui->lineEditCurrentTicket->setText(QString::number(tickets.size()));
        ui->lineEditTotalTickets->setText(QString::number(tickets.size()));
        ui->pushButtonNextTicket->setEnabled(false);
        ui->pushButtonPreviousTicket->setEnabled(true);
        currentTicketIndex = tickets.size() - 1;
    }
    else
    {
        qWarning() << "Can't load tickets data from the database";
    }
}

bool MainWindow::isTicketsTableFromDbEmpty()
{
    QSqlQuery query;
    int rowsCount = -1;

    if (query.exec("SELECT COUNT(*) FROM 'tickets';"))
    {
        query.next();
        rowsCount = query.value(0).toInt();
        qDebug() << "Table tickets has " << rowsCount << " rows";
    }

    if (rowsCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void MainWindow::on_pushButtonReport_clicked()
{
    qDebug() << "Generating a report...";
}
