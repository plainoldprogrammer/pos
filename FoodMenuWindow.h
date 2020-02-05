#ifndef FOODMENUWINDOW_H
#define FOODMENUWINDOW_H

#include <QDialog>
#include <QMap>
#include <QDebug>

namespace Ui {
class FoodMenuWindow;
}

class FoodMenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FoodMenuWindow(QWidget *parent = nullptr);
    ~FoodMenuWindow();
    void setFoodMenu(QMap<QString, int>);

private:
    Ui::FoodMenuWindow *ui;
};

#endif // FOODMENUWINDOW_H
