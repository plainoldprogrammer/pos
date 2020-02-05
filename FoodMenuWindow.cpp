#include "FoodMenuWindow.h"
#include "ui_foodmenuwindow.h"

FoodMenuWindow::FoodMenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FoodMenuWindow)
{
    ui->setupUi(this);
}

FoodMenuWindow::~FoodMenuWindow()
{
    delete ui;
}

void FoodMenuWindow::setFoodMenu(QMap<QString, int> foodMenu)
{
    qDebug() << foodMenu;
}
