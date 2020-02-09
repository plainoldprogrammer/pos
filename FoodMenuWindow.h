#ifndef FOODMENUWINDOW_H
#define FOODMENUWINDOW_H

#include <QDialog>
#include <QDebug>
#include <QVector>
#include <QLineEdit>
#include <QPair>
#include <QList>

namespace Ui {
class FoodMenuWindow;
}

class FoodMenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FoodMenuWindow(QWidget *parent = nullptr);
    ~FoodMenuWindow();
    void setFoodMenu(QList<QPair<QString, int>> &);
    void updateItemsAndPrices();

private:
    Ui::FoodMenuWindow *ui;
    QVector<QLineEdit *> foodMenuItemNameLineEdits;
    QVector<QLineEdit *> foodMenuItemPriceLineEdits;;
    QList<QPair<QString, int>> * foodMenu;
};

#endif // FOODMENUWINDOW_H
