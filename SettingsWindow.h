#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QColor>

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();
    QString getRestaurantName();
    QString getRestaurantAddress();
    QString getFooterMessage();
    QChar getTicketSectionCharSeparator();
    void setRestaurantName(QString);
    void setRestaurantAddress(QString);
    void setFooterMessage(QString);
    void setTicketSectionCharSeparator(QChar);
    bool isFullScreen();
    void setFullScreen(bool);
    QColor getTicketCharColor();
    void setTicketCharColor(QColor);

private:
    Ui::SettingsWindow *ui;
    QColor ticketCharColor;

private slots:
     /*
      * Settings option slots
      */
      void on_checkBoxFullScreen_stateChanged(int);
      void on_pushButtonTicketCharColor_clicked();
};

#endif // SETTINGSWINDOW_H
