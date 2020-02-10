#ifndef TICKETSTABLEWINDOW_H
#define TICKETSTABLEWINDOW_H

#include <QDialog>
#include <QTableView>
#include <QResizeEvent>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

namespace Ui {
class TicketsTableWindow;
}

class TicketsTableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TicketsTableWindow(QWidget *parent = nullptr);
    ~TicketsTableWindow();
    void resizeEvent(QResizeEvent *);
    void showTickets();

private:
    Ui::TicketsTableWindow *ui;
};

#endif // TICKETSTABLEWINDOW_H
