#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>

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

private:
    Ui::SettingsWindow *ui;

private slots:
     /*
      * Settings option slots
      */
      void on_checkBoxFullScreen_stateChanged(int);
};

#endif // SETTINGSWINDOW_H
