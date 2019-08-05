#include "SettingsWindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

QString SettingsWindow::getRestaurantName()
{
    return ui->lineEditRestaurantName->text();
}

QString SettingsWindow::getRestaurantAddress()
{
    return ui->lineEditRestaurantAddress->text();
}


QString SettingsWindow::getFooterMessage()
{
    return ui->lineEditFooterMessage->text();
}
