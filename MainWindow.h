#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQuery>

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
    void on_pushButtonBistec_clicked();
    void on_pushButtonPollo_clicked();
    void on_pushButtonChicharron_clicked();
    void on_pushButtonMole_clicked();
    void on_pushButtonMilanesa_clicked();
    void on_pushButtonAlbondigas_clicked();
    void on_pushButtonCarneDeshebrada_clicked();
    void on_pushButtonHuevos_clicked();
    void on_pushButtonChilaquiles_clicked();
    void on_pushButtonSincronizada_clicked();
    void on_pushButtonBurritos_clicked();
    void on_pushButtonQuesadillaCombinada_clicked();
    void on_pushButtonQuesadillaChica_clicked();
    void on_pushButtonRefresco_clicked();
    void on_pushButtonJugo_clicked();
    void on_pushButtonQuesadilla_clicked();
    void on_pushButtonTacoChico_clicked();
    void on_pushButtonAguaFresca_clicked();
    void on_pushButtonLicuado_clicked();
    void on_pushButtonAguaDeBotella_clicked();
    void on_pushButtonCafe_clicked();
    void on_pushButtonTe_clicked();
    void on_pushButtonTortillas_clicked();

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
