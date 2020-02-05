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
    void setFoodMenu(QList<QPair<QString, int>>);

private:
    Ui::FoodMenuWindow *ui;
    QVector<QLineEdit *> foodMenuItemNameLineEdits;
    QVector<QLineEdit *> foodMenuItemPriceLineEdits;;
};

#endif // FOODMENUWINDOW_H
