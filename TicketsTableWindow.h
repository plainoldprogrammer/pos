#ifndef TICKETSTABLEWINDOW_H
#define TICKETSTABLEWINDOW_H

#include <QDialog>

namespace Ui {
class TicketsTableWindow;
}

class TicketsTableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TicketsTableWindow(QWidget *parent = nullptr);
    ~TicketsTableWindow();

private:
    Ui::TicketsTableWindow *ui;
};

#endif // TICKETSTABLEWINDOW_H
