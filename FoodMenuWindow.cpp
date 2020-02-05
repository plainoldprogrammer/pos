#include "FoodMenuWindow.h"
#include "ui_foodmenuwindow.h"

FoodMenuWindow::FoodMenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FoodMenuWindow)
{
    ui->setupUi(this);

    /*
     * Registry of all of the item name line edits to be accessed in a generic way
     */
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_0_0);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_0_1);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_0_2);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_0_3);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_0_4);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_0_5);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_1_0);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_1_1);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_1_2);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_1_3);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_1_4);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_1_5);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_2_0);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_2_1);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_2_2);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_2_3);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_2_4);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_2_5);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_3_0);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_3_1);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_3_2);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_3_3);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_3_4);
    foodMenuItemNameLineEdits.push_back(ui->lineEditItemName_3_5);

    /*
     * Registry of all of the item price line edits to be accessed in a generic way
     */
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_0_0);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_0_1);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_0_2);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_0_3);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_0_4);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_0_5);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_1_0);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_1_1);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_1_2);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_1_3);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_1_4);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_1_5);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_2_0);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_2_1);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_2_2);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_2_3);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_2_4);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_2_5);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_3_0);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_3_1);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_3_2);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_3_3);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_3_4);
    foodMenuItemPriceLineEdits.push_back(ui->lineEditItemPrice_3_5);
}

FoodMenuWindow::~FoodMenuWindow()
{
    delete ui;
}

void FoodMenuWindow::setFoodMenu(QList<QPair<QString, int>> foodMenu)
{
    qDebug() << foodMenu;

    for (int i = 0; i < foodMenu.size(); i++)
    {
        QPair<QString, int> itemAndPrice = foodMenu.at(i);
        (foodMenuItemNameLineEdits.at(i))->setText(itemAndPrice.first);
        (foodMenuItemPriceLineEdits.at(i))->setText(QString::number(itemAndPrice.second));
    }
}
