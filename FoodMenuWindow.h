#ifndef FOODMENUWINDOW_H
#define FOODMENUWINDOW_H

#include <QDialog>

namespace Ui {
class FoodMenuWindow;
}

class FoodMenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit FoodMenuWindow(QWidget *parent = nullptr);
    ~FoodMenuWindow();

private:
    Ui::FoodMenuWindow *ui;
};

#endif // FOODMENUWINDOW_H
