#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QList>
#include <QPair>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlError>
#include <QTimer>
#include <QCursor>
#include <QKeyEvent>
#include <QDebug>
#include <QSettings>
#include <QMessageBox>
#include <QDir>

#include "Ticket.h"
#include "SettingsWindow.h"
#include "TicketsTableWindow.h"
#include "SalesReportWindow.h"
#include "FoodMenuWindow.h"
#include "Entry.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString singleFoodEntry;
    int selectedQuantity;
    int totalAmount;
    int currentTicketIndex;
    QVector<Ticket *> tickets;
    Ticket *ticket;
    SettingsWindow *settingsWindow;
    QChar characterTicketSectionSeparator;
    QSettings settings;
    QSqlDatabase db;
    TicketsTableWindow *ticketsTableWindow;
    SalesReportWindow *salesReportWindow;
    int calculateAmount(int, QString);
    void keyPressEvent(QKeyEvent *);
    void writeOnTicket(Ticket *);
    QString getTicketSectionLineSeparator(QChar c);
    void createDBConnection();
    void loadTicketsFromDb();
    bool isTicketsTableFromDbEmpty();
    FoodMenuWindow *foodMenuWindow;
    Entry *entry;
    QVector<Entry *> entries;
    void printEntriesOnTicket();
    void processQuantityInput(int);
    void processItemSelected(QString);
    void initializeMenu();
    QVector<QPushButton *> foodMenuButtons;
    QList<QPair<QString, int>> foodMenu;

private slots:
    /*
     * Features and settings slots
     */
    void on_pushButtonFoodMenu_clicked();
    void on_pushButtonSettings_clicked();
    void on_pushButtonTicketsTable_clicked();
    void on_pushButtonSalesReport_clicked();

    /*
     * Numeric pad slots
     */
    void on_pushButtonClear_clicked();
    void on_pushButtonClearEntry_clicked();
    void on_pushButtonNum0_clicked();
    void on_pushButtonNum1_clicked();
    void on_pushButtonNum2_clicked();
    void on_pushButtonNum3_clicked();
    void on_pushButtonNum4_clicked();
    void on_pushButtonNum5_clicked();
    void on_pushButtonNum6_clicked();
    void on_pushButtonNum7_clicked();
    void on_pushButtonNum8_clicked();
    void on_pushButtonNum9_clicked();

    /*
     * Food menu item slots
     */
    void on_pushButtonMenu_0_0_clicked();
    void on_pushButtonMenu_0_1_clicked();
    void on_pushButtonMenu_0_2_clicked();
    void on_pushButtonMenu_0_3_clicked();
    void on_pushButtonMenu_0_4_clicked();
    void on_pushButtonMenu_0_5_clicked();
    void on_pushButtonMenu_1_0_clicked();
    void on_pushButtonMenu_1_1_clicked();
    void on_pushButtonMenu_1_2_clicked();
    void on_pushButtonMenu_1_3_clicked();
    void on_pushButtonMenu_1_4_clicked();
    void on_pushButtonMenu_1_5_clicked();
    void on_pushButtonMenu_2_0_clicked();
    void on_pushButtonMenu_2_1_clicked();
    void on_pushButtonMenu_2_2_clicked();
    void on_pushButtonMenu_2_3_clicked();
    void on_pushButtonMenu_2_4_clicked();
    void on_pushButtonMenu_2_5_clicked();
    void on_pushButtonMenu_3_0_clicked();
    void on_pushButtonMenu_3_1_clicked();
    void on_pushButtonMenu_3_2_clicked();
    void on_pushButtonMenu_3_3_clicked();
    void on_pushButtonMenu_3_4_clicked();
    void on_pushButtonMenu_3_5_clicked();

    /*
     * Ticket options slots
     */
    void on_pushButtonPreviousTicket_clicked();
    void on_pushButtonNextTicket_clicked();
    void on_pushButtonDeleteCurrentTicket_clicked();
    void on_pushButtonCreateNewTicket_clicked();

    /*
      * Other
      */
    void on_pushButtonExit_clicked();
};

#endif // MAINWINDOW_H
