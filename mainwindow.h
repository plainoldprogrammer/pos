#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_17_clicked();
    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
