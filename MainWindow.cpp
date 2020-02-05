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
#include <QList>
#include <QMessageBox>
#include <QDir>

#include <iostream>

#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "Ticket.h"
#include "SettingsWindow.h"
#include "TicketsTableWindow.h"
#include "SalesReportWindow.h"
#include "FoodMenuWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), settings("plainoldprogrammer", "pos")
{
    totalAmount = 0;
    singleFoodEntry = "";
    entry = NULL;

    ui->setupUi(this);
    this->setWindowTitle("Point Of Sales (POS)");

    /*
     * Setup hand cursor for the ui buttons
     */
    ui->pushButtonSalesReport->setCursor(Qt::PointingHandCursor);
    ui->pushButtonSettings->setCursor(Qt::PointingHandCursor);
    ui->pushButtonTicketsTable->setCursor(Qt::PointingHandCursor);
    ui->pushButtonExit->setCursor(Qt::PointingHandCursor);
    ui->pushButtonClear->setCursor(Qt::PointingHandCursor);
    ui->pushButtonClearEntry->setCursor(Qt::PointingHandCursor);
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
    ui->pushButtonMenu_0_0->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_0_1->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_0_2->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_0_3->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_0_4->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_0_5->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_1_0->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_1_1->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_1_2->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_1_3->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_1_4->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_1_5->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_2_0->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_2_1->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_2_2->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_2_3->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_2_4->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_2_5->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_3_0->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_3_1->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_3_2->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_3_3->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_3_4->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMenu_3_5->setCursor(Qt::PointingHandCursor);
    ui->pushButtonPreviousTicket->setCursor(Qt::PointingHandCursor);
    ui->pushButtonNextTicket->setCursor(Qt::PointingHandCursor);
    ui->pushButtonDeleteCurrentTicket->setCursor(Qt::PointingHandCursor);
    ui->pushButtonCreateNewTicket->setCursor(Qt::PointingHandCursor);
    ui->pushButtonFoodMenu->setCursor(Qt::PointingHandCursor);

    /*
     * Registry of all of the menu buttons to be accessed in a generic way
     */
    foodMenuButtons.push_back(ui->pushButtonMenu_0_0);
    foodMenuButtons.push_back(ui->pushButtonMenu_0_1);
    foodMenuButtons.push_back(ui->pushButtonMenu_0_2);
    foodMenuButtons.push_back(ui->pushButtonMenu_0_3);
    foodMenuButtons.push_back(ui->pushButtonMenu_0_4);
    foodMenuButtons.push_back(ui->pushButtonMenu_0_5);
    foodMenuButtons.push_back(ui->pushButtonMenu_1_0);
    foodMenuButtons.push_back(ui->pushButtonMenu_1_1);
    foodMenuButtons.push_back(ui->pushButtonMenu_1_2);
    foodMenuButtons.push_back(ui->pushButtonMenu_1_3);
    foodMenuButtons.push_back(ui->pushButtonMenu_1_4);
    foodMenuButtons.push_back(ui->pushButtonMenu_1_5);
    foodMenuButtons.push_back(ui->pushButtonMenu_2_0);
    foodMenuButtons.push_back(ui->pushButtonMenu_2_1);
    foodMenuButtons.push_back(ui->pushButtonMenu_2_2);
    foodMenuButtons.push_back(ui->pushButtonMenu_2_3);
    foodMenuButtons.push_back(ui->pushButtonMenu_2_4);
    foodMenuButtons.push_back(ui->pushButtonMenu_2_5);
    foodMenuButtons.push_back(ui->pushButtonMenu_3_0);
    foodMenuButtons.push_back(ui->pushButtonMenu_3_1);
    foodMenuButtons.push_back(ui->pushButtonMenu_3_2);
    foodMenuButtons.push_back(ui->pushButtonMenu_3_3);
    foodMenuButtons.push_back(ui->pushButtonMenu_3_4);
    foodMenuButtons.push_back(ui->pushButtonMenu_3_5);

    /*
     * Setup the push buttons style
     */
    ui->pushButtonMenu_0_0->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_0_1->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_0_2->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_0_3->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_0_4->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_0_5->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_1_0->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_1_1->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_1_2->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_1_3->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_1_4->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_1_5->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_2_0->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_2_1->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_2_2->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_2_3->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_2_4->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_2_5->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_3_0->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_3_1->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_3_2->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_3_3->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_3_4->setStyleSheet("QPushButton { background-color: #99d6ff } ");
    ui->pushButtonMenu_3_5->setStyleSheet("QPushButton { background-color: #99d6ff } " );
    ui->pushButtonTicketsTable->setStyleSheet("QPushButton { background-color: #f5d742 } ");
    ui->pushButtonSalesReport->setStyleSheet("QPushButton { background-color: #f5d742 } ");
    ui->pushButtonSettings->setStyleSheet("QPushButton { background-color: #f5d742 } ");
    ui->pushButtonFoodMenu->setStyleSheet("QPushButton { background-color: #f5d742 } ");

    ui->pushButtonPreviousTicket->setStyleSheet("QPushButton { background-color: #808080 } ");
    ui->pushButtonPreviousTicket->setIcon(QIcon(":/images/icons/leftarrow.ico"));
    ui->pushButtonPreviousTicket->setIconSize(QSize(85, 85));
    ui->pushButtonPreviousTicket->setShortcut(QKeySequence(Qt::Key_Left));

    ui->pushButtonNextTicket->setStyleSheet("QPushButton { background-color: #808080 } ");
    ui->pushButtonNextTicket->setIcon(QIcon(":/images/icons/rightarrow.ico"));
    ui->pushButtonNextTicket->setIconSize(QSize(80, 80));
    ui->pushButtonNextTicket->setShortcut(QKeySequence(Qt::Key_Right));

    ui->pushButtonDeleteCurrentTicket->setStyleSheet("QPushButton { background-color: #808080 } ");
    ui->pushButtonDeleteCurrentTicket->setIcon(QIcon(":/images/icons/delete.png"));
    ui->pushButtonDeleteCurrentTicket->setIconSize(QSize(80, 80));
    ui->pushButtonDeleteCurrentTicket->setShortcut(QKeySequence(Qt::Key_Delete));

    ui->pushButtonCreateNewTicket->setStyleSheet("QPushButton{ background-color: #808080 } ");
    ui->pushButtonCreateNewTicket->setIcon(QIcon(":/images/icons/new-ticket.png"));
    ui->pushButtonCreateNewTicket->setIconSize(QSize(80, 80));
    ui->pushButtonCreateNewTicket->setToolTip("Save current ticket and create a new one");
    ui->pushButtonCreateNewTicket->setShortcut(QKeySequence(Qt::Key_Return));

    ui->pushButtonClear->setIcon(QIcon(":/images/icons/trash.png"));
    ui->pushButtonClear->setIconSize(QSize(145, 145));
    ui->pushButtonClear->setToolTip("Clear current ticket");

    ui->pushButtonClearEntry->setIcon(QIcon(":/images/icons/eraser.png"));
    ui->pushButtonClearEntry->setIconSize(QSize(145, 145));
    ui->pushButtonClearEntry->setToolTip("Clear last entry");

    ui->pushButtonSettings->setIcon(QIcon(":/images/icons/settings.png"));
    ui->pushButtonSettings->setIconSize(QSize(145, 145));
    ui->pushButtonSettings->setToolTip("Settings");

    ui->pushButtonTicketsTable->setIcon(QIcon(":/images/icons/table.png"));
    ui->pushButtonTicketsTable->setIconSize(QSize(145, 145));
    ui->pushButtonTicketsTable->setToolTip("Show all tickets on a table");

    ui->pushButtonSalesReport->setIcon(QIcon(":/images/icons/report.png"));
    ui->pushButtonSalesReport->setIconSize(QSize(145, 145));
    ui->pushButtonSalesReport->setToolTip("Show a sales report");

    ui->pushButtonFoodMenu->setIcon(QIcon(":/images/icons/menu.png"));
    ui->pushButtonFoodMenu->setIconSize(QSize(145, 145));
    ui->pushButtonSalesReport->setToolTip("View and edit menu details");

    /*
     * Setup the ticket ui based on the stored settings
     */
    ui->ticketHeader->setStyleSheet("QLabel {background-color: white; color: blue} ");
    ui->ticketHeader->clear();
    QString restaurantName = settings.value("restaurantName").toString();
    QString restaurantAddress = settings.value("restaurantAddress").toString();
    characterTicketSectionSeparator = (settings.value("characterTicketSectionSeparator").toString().toStdString())[0];
    ui->ticketHeader->setText(restaurantName + "\n" + restaurantAddress + "\n" + getTicketSectionLineSeparator(characterTicketSectionSeparator));
    ui->orderDisplay->setStyleSheet("QLabel { background-color: white; color: blue }");
    ui->orderDisplay->clear();
    ui->totalAmountDisplay->setStyleSheet("QLabel { background-color: white }");
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));
    ui->ticketFooter->setStyleSheet("QLabel { background-color: white; color: blue } ");
    QString footer = settings.value("footerMessage").toString();
    ui->ticketFooter->setText(getTicketSectionLineSeparator(characterTicketSectionSeparator) + "\n" + footer);

    // Load the ticket char color saved on the machine
    QString savedRgbTicketCharColor = settings.value("ticketCharColor").toString();
    if (!savedRgbTicketCharColor.isEmpty())
    {
        QList <QString> rgb = savedRgbTicketCharColor.split(" ");
        QString ticketStyle = "QLabel {background-color: white; color: rgb(";
        ticketStyle.append(rgb.at(0));
        ticketStyle.append(",");
        ticketStyle.append(rgb.at(1));
        ticketStyle.append(",");
        ticketStyle.append(rgb.at(2));
        ticketStyle.append(")}");
        ui->ticketHeader->setStyleSheet(ticketStyle);
        ui->ticketFooter->setStyleSheet(ticketStyle);
    }

    if (settings.value("fullscreen").toBool())
    {
        QTimer::singleShot(0, this, SLOT(showFullScreen()));
    }
    else
    {
        QTimer::singleShot(0, this, SLOT(showMaximizedScreen()));
    }

    ui->mainToolBar->hide();

    /*
     * Initialize the inner settings window
     */
    settingsWindow = new SettingsWindow();
    settingsWindow->setFixedSize(settingsWindow->size());
    settingsWindow->setWindowTitle("Settings");

    /*
     * Initialize the inner window to show a table with all the tickets
     */
    ticketsTableWindow = new TicketsTableWindow();
    ticketsTableWindow->setWindowTitle("All Tickets");

    /*
     * Initialize the inner window to show a sales report
     */
    salesReportWindow = new SalesReportWindow();
    salesReportWindow->setFixedSize(salesReportWindow->size());
    salesReportWindow->setWindowTitle("Sales Report");

    /*
     * Initialize the inner window to show a food menu details
     */
    foodMenuWindow = new FoodMenuWindow();
    foodMenuWindow->setFixedSize(foodMenuWindow->size());
    foodMenuWindow->setWindowTitle("Food Menu");

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

    /*
     * Initialize the menu content from the database information
     */
    initializeMenu();
}

MainWindow::~MainWindow()
{
    delete ui;

    while (!entries.isEmpty())
    {
        Entry * entry = entries.takeFirst();
        delete entry;
    }
}

void MainWindow::on_pushButtonClear_clicked()
{
    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(this, "Exit", "Are you sure you want to erase all the ticket entry?", QMessageBox::Yes | QMessageBox::No);

    if (confirm == QMessageBox::Yes)
    {
        ui->orderDisplay->clear();
        ui->totalAmountDisplay->clear();
        ui->totalAmountDisplay->setText("TOTAL $ 0");
        totalAmount = 0;
        entries.clear();
    }
    else
    {
        qDebug() << "Cancel the clear";
    }
}

void MainWindow::on_pushButtonClearEntry_clicked()
{
    qDebug() << "Clear entry";

    Entry * lastEntry = entries.takeLast();;
    int singleFoodEntryAmount = calculateAmount(lastEntry->getQuantity(), lastEntry->getItem());
    totalAmount -= singleFoodEntryAmount;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    printEntriesOnTicket();

    delete lastEntry;
}

void MainWindow::on_pushButtonFoodMenu_clicked()
{
    qDebug() << "Display and edit the menu";
    foodMenuWindow->setFoodMenu(foodMenu);
    foodMenuWindow->exec();
}

void MainWindow::on_pushButtonSettings_clicked()
{
    // Load the current configuration
    settingsWindow->setRestaurantName(settings.value("restaurantName").toString());
    settingsWindow->setRestaurantAddress(settings.value("restaurantAddress").toString());
    settingsWindow->setFooterMessage(settings.value("footerMessage").toString());
    settingsWindow->setTicketSectionCharSeparator((settings.value("characterTicketSectionSeparator").toString().toStdString())[0]);
    settingsWindow->setFullScreen(settings.value("fullscreen").toBool());

    // Load the saved ticket char color
    QString savedRgbTicketCharColor = settings.value("ticketCharColor").toString();
    if (!savedRgbTicketCharColor.isEmpty())
    {
        QList <QString> rgb = savedRgbTicketCharColor.split(" ");
        if (!rgb.isEmpty())
            settingsWindow->setTicketCharColor(QColor(rgb.at(0).toInt(), rgb.at(1).toInt(), rgb.at(2).toInt()));
    }

    // Applying the configuration
    if (settingsWindow->exec() == QDialog::Accepted)
    {
        qDebug() << "Applying new settings";

        QString ticketSectionSeparator = getTicketSectionLineSeparator(settingsWindow->getTicketSectionCharSeparator());
        ui->ticketHeader->setText(settingsWindow->getRestaurantName() + "\n" + settingsWindow->getRestaurantAddress() + "\n" + ticketSectionSeparator);
        ui->ticketFooter->setText(ticketSectionSeparator + "\n" + settingsWindow->getFooterMessage());

        QString ticketStyle = "QLabel {background-color: white; color:  rgb(";
        ticketStyle.append(QString::number(settingsWindow->getTicketCharColor().red()));
        ticketStyle.append(",");
        ticketStyle.append(QString::number(settingsWindow->getTicketCharColor().green()));
        ticketStyle.append(",");
        ticketStyle.append(QString::number(settingsWindow->getTicketCharColor().blue()));
        ticketStyle.append(")}");

        ui->ticketHeader->setStyleSheet(ticketStyle);
        ui->ticketFooter->setStyleSheet(ticketStyle);

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
        settings.setValue("characterTicketSectionSeparator", QString(settingsWindow->getTicketSectionCharSeparator()));
        settings.setValue("fullscreen", settingsWindow->isFullScreen());

        // Making ticket char color persistent on the machine
        QString rgbTicketCharColor;
        rgbTicketCharColor.append(QString::number(settingsWindow->getTicketCharColor().red()));
        rgbTicketCharColor.append(" ");
        rgbTicketCharColor.append(QString::number(settingsWindow->getTicketCharColor().green()));
        rgbTicketCharColor.append(" ");
        rgbTicketCharColor.append(QString::number(settingsWindow->getTicketCharColor().blue()));
        settings.setValue("ticketCharColor", rgbTicketCharColor);
        qDebug() << "tichetCharColor persistent is: " << rgbTicketCharColor;
    }
}

void MainWindow::on_pushButtonTicketsTable_clicked()
{
    qDebug() << "Show a table with all the tickets";

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

void MainWindow::on_pushButtonSalesReport_clicked()
{
    qDebug() << "Show a sales report";
    QSqlQuery query;
    QString report;

    if (query.exec("SELECT SUM(amount) AS TOTAL FROM tickets;"))
    {
        query.next();
        int total = query.value(0).toInt();
        report = "Total: " + QString::number(total);
    }
    if (query.exec("SELECT COUNT(*) AS TICKETS_QTY FROM tickets;"))
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
    if (query.exec("SELECT MIN(amount) FROM tickets;"))
    {
        query.next();
        int min = query.value(0).toInt();
        report.append("\nMin sale: " + QString::number(min));
    }
    if (query.exec("SELECT MIN(dateandtime) FROM tickets;"))
    {
        query.next();
        QString date = query.value(0).toString();
        report.append("\nFirst sale: " + date);
    }
    if (query.exec("SELECT MAX(dateandtime) FROM tickets;"))
    {
        query.next();
        QString date = query.value(0).toString();
        report.append("\nLast sale: " + date);
    }

    salesReportWindow->getPlainTextEdit()->setPlainText(report);
    salesReportWindow->exec();
}

void MainWindow::on_pushButtonNum0_clicked()
{
    processQuantityInput(0);
}

void MainWindow::on_pushButtonNum1_clicked()
{
    processQuantityInput(1);
}

void MainWindow::on_pushButtonNum2_clicked()
{
    processQuantityInput(2);
}

void MainWindow::on_pushButtonNum3_clicked()
{
    processQuantityInput(3);
}

void MainWindow::on_pushButtonNum4_clicked()
{
    processQuantityInput(4);
}

void MainWindow::on_pushButtonNum5_clicked()
{
    processQuantityInput(5);
}

void MainWindow::on_pushButtonNum6_clicked()
{
    processQuantityInput(6);
}

void MainWindow::on_pushButtonNum7_clicked()
{
    processQuantityInput(7);
}

void MainWindow::on_pushButtonNum8_clicked()
{
    processQuantityInput(8);
}

void MainWindow::on_pushButtonNum9_clicked()
{
    processQuantityInput(9);
}

void MainWindow::on_pushButtonMenu_0_0_clicked()
{
    processItemSelected(ui->pushButtonMenu_0_0->text());
}

void MainWindow::on_pushButtonMenu_0_1_clicked()
{
    processItemSelected(ui->pushButtonMenu_0_1->text());
}

void MainWindow::on_pushButtonMenu_0_2_clicked()
{
    processItemSelected(ui->pushButtonMenu_0_2->text());
}

void MainWindow::on_pushButtonMenu_0_3_clicked()
{
    processItemSelected(ui->pushButtonMenu_0_3->text());
}

void MainWindow::on_pushButtonMenu_0_4_clicked()
{
    processItemSelected(ui->pushButtonMenu_0_4->text());
}

void MainWindow::on_pushButtonMenu_0_5_clicked()
{
    processItemSelected(ui->pushButtonMenu_0_5->text());
}

void MainWindow::on_pushButtonMenu_1_0_clicked()
{
    processItemSelected(ui->pushButtonMenu_1_0->text());
}

void MainWindow::on_pushButtonMenu_1_1_clicked()
{
    processItemSelected(ui->pushButtonMenu_1_0->text());
}

void MainWindow::on_pushButtonMenu_1_2_clicked()
{
    processItemSelected(ui->pushButtonMenu_1_2->text());
}

void MainWindow::on_pushButtonMenu_1_3_clicked()
{
    processItemSelected(ui->pushButtonMenu_1_3->text());
}

void MainWindow::on_pushButtonMenu_1_4_clicked()
{
    processItemSelected(ui->pushButtonMenu_1_4->text());
}

void MainWindow::on_pushButtonMenu_1_5_clicked()
{
    processItemSelected(ui->pushButtonMenu_1_5->text());
}

void MainWindow::on_pushButtonMenu_2_0_clicked()
{
    processItemSelected(ui->pushButtonMenu_2_0->text());
}

void MainWindow::on_pushButtonMenu_2_1_clicked()
{
    processItemSelected(ui->pushButtonMenu_2_1->text());
}

void MainWindow::on_pushButtonMenu_2_2_clicked()
{
    processItemSelected(ui->pushButtonMenu_2_2->text());
}

void MainWindow::on_pushButtonMenu_2_3_clicked()
{
    processItemSelected(ui->pushButtonMenu_2_3->text());
}

void MainWindow::on_pushButtonMenu_2_4_clicked()
{
    processItemSelected(ui->pushButtonMenu_2_4->text());
}

void MainWindow::on_pushButtonMenu_2_5_clicked()
{
    processItemSelected(ui->pushButtonMenu_2_5->text());
}

void MainWindow::on_pushButtonMenu_3_0_clicked()
{
    processItemSelected(ui->pushButtonMenu_3_0->text());
}

void MainWindow::on_pushButtonMenu_3_1_clicked()
{
    processItemSelected(ui->pushButtonMenu_3_1->text());
}

void MainWindow::on_pushButtonMenu_3_2_clicked()
{
    processItemSelected(ui->pushButtonMenu_3_2->text());
}

void MainWindow::on_pushButtonMenu_3_3_clicked()
{
    processItemSelected(ui->pushButtonMenu_3_3->text());
}

void MainWindow::on_pushButtonMenu_3_4_clicked()
{
    processItemSelected(ui->pushButtonMenu_3_4->text());
}

void MainWindow::on_pushButtonMenu_3_5_clicked()
{
    processItemSelected(ui->pushButtonMenu_3_5->text());
}

int MainWindow::calculateAmount(int quantity, QString food)
{
   qDebug() << "calculateAmount(" << quantity + ", " << food.toStdString().c_str() << ") ";

    for (int i = 0; i < foodMenu.size(); i++)
    {
        QPair<QString, int> itemAndPrice = foodMenu.at(i);

        if ((QString::compare(itemAndPrice.first, food, Qt::CaseSensitive)) == 0)
        {
            return itemAndPrice.second * quantity;
        }
    }

    // If the food is not found
    return -1;
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
    qDebug() << "Delete ticket #" << currentTicketIndex << "(zero index based)";

    //	NOTE:	The the id of each ticket register in the database could be different
    //			from the index of each element of the tickets vector.
    int ticketIdInDb = tickets.at(currentTicketIndex)->getId();
    qDebug() << "ticked removed with and id" << ticketIdInDb << "in the database";

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
        ui->orderDisplay->setText("");
        ui->totalAmountDisplay->setText("TOTAL $ ");
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

    QSqlQuery sqlQuery("DELETE FROM tickets WHERE id=" + QString::number(ticketIdInDb) + ";");
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


    // Clearing the entries to start a new fresh ticket
    while (!entries.isEmpty())
    {
        Entry * entry = entries.takeFirst();
        delete entry;
    }
}

void MainWindow::on_pushButtonExit_clicked()
{
    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(this, "Exit", "Exit from the Point Of Sales?", QMessageBox::Yes | QMessageBox::No);

    if (confirm == QMessageBox::Yes)
    {
        close();
    }
    else
    {
        qDebug() << "Cancel the exit";
    }
}

void MainWindow::writeOnTicket(Ticket * ticketToWrite)
{
    qDebug() << "\n";
    qDebug() << "Call to writeOnTicket() on currentTicketIndex: " << currentTicketIndex ;
    ticketToWrite->setBody(ui->orderDisplay->text());
    ticketToWrite->setTicketTotalAmount(totalAmount);
    qDebug() << "WriteOnTicket";
    qDebug() << "\t" << ticketToWrite->getBody();
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

    QString dbFolder = "C:\\plainoldprogrammer\\dev\\databases\\";
    QDir dbDirectory(dbFolder);
    QString sqliteFileName = "pos.db";
    QString dbURI = dbFolder + sqliteFileName;

    db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(dbURI);

    if (!dbDirectory.exists())
    {
        dbDirectory.mkdir(".");

        QMessageBox::StandardButton notification;
        notification = QMessageBox::information(this, "New Database Created", "A new directory and a new database\nhas been created");
    }

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
            ticket->setId(query.value(0).toInt());
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

void MainWindow::printEntriesOnTicket()
{
    qDebug() << "Printing the entries on ticket...";

    for (int i = 0; i < entries.size(); i++)
    {
        qDebug() << "\t" << (entries.at(i))->getQuantity() << "\t" << (entries.at(i)->getItem());
    }

    ui->orderDisplay->clear();

    for (int i = 0; i < entries.size(); i++)
    {
        ui->orderDisplay->setText(ui->orderDisplay->text() + QString::number(entries.at(i)->getQuantity()) + " " + entries.at(i)->getItem() + "\n");
    }
}

void MainWindow::processQuantityInput(int digit)
{
    if (entry == NULL)
    {
        entry = new Entry();
        entries.push_back(entry);
    }

    entry->setQuantity((entry->getQuantity() * 10) + digit);
    singleFoodEntry += QString::number(digit);
    printEntriesOnTicket();
}

void MainWindow::processItemSelected(QString item)
{
    if (entry)
    {
        entry->setItem(item);
    }

    std::cout << std::endl;

    singleFoodEntry = singleFoodEntry + " " + item;

    QStringList pieces = singleFoodEntry.split(" ");
    int quantity = pieces.value(0).toInt();
    int singleFoodEntryAmount = calculateAmount(quantity, item);
    std::cout << "\nsingleFoodEntry: " << singleFoodEntryAmount << std::endl;

    totalAmount += singleFoodEntryAmount;
    std::cout << "totalAmount: " << totalAmount << std::endl;
    ui->totalAmountDisplay->setText("TOTAL $ " + QString::number(totalAmount));

    singleFoodEntry = "";
    printEntriesOnTicket();
    writeOnTicket(ticket);
    entry = NULL;
}

void MainWindow::initializeMenu()
{
    QSqlQuery query;
    int rowsCount = -1;

    if (query.exec("SELECT COUNT(*) from 'menu';"))
    {
        query.next();
        rowsCount = query.value(0).toInt();
        qDebug() << "Table menu has " << rowsCount << " rows";
    }

    // Retrieve menu from the database if exist
    if (rowsCount > 0)
    {
        if (query.exec("SELECT * FROM menu;"))
        {
            for (int i = 0; i < rowsCount; i++)
            {
                query.next();
                (foodMenuButtons.at(i))->setText(query.value(1).toString());
                // foodMenu.insert(query.value(1).toString(), query.value(2).toInt());
                QPair<QString, int> itemAndPrice;
                itemAndPrice.first = query.value(1).toString();
                itemAndPrice.second = query.value(2).toInt();
                foodMenu.push_back(itemAndPrice);
                qDebug() << "\t" << query.value(1).toString();
            }
        }
        else
        {
            qWarning() << "Can't read the menu from the database";
        }
    }
    else
    {
        // ToDo: Auto fill on the fly
    }
}
