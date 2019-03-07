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
    void on_pushButtonClear_clicked();
    void on_pushButtonNum0_clicked();
    void on_pushButtonNum1_clicked();
    void on_pushButtonNum2_clicked();
    void on_pushButtonNum3_clicked();
    void on_pushButtonNum4_clicked();
    void on_pushButtonNum5_clicked();
    void on_pushButtonNum6_clicked();
    void on_pushButtonNum7_clicked();
    void on_pushButtonNum8_clicked();
    void on_pushButtonNum9_clicked();

    void on_pushButtonComida_clicked();
    void on_pushButtonQuesadilla_clicked();
    void on_pushButtonAgua_clicked();
    void on_pushButtonRefresco_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
