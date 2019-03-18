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

    void on_pushButtonPechuga_clicked();
    void on_pushButtonBistec_clicked();
    void on_pushButtonPollo_clicked();
    void on_pushButtonChicharron_clicked();
    void on_pushButtonMole_clicked();
    void on_pushButtonMilanesa_clicked();
    void on_pushButtonAlbondigas_clicked();
    void on_pushButtonCarneDeshebrada_clicked();
    void on_pushButtonHuevos_clicked();
    void on_pushButtonChilaquiles_clicked();
    void on_pushButtonSincronizada_clicked();
    void on_pushButtonBurritos_clicked();
    void on_pushButtonQuesadilla_clicked();
    void on_pushButtonAguaFresca_clicked();
    void on_pushButtonRefresco_clicked();

private:
    Ui::MainWindow *ui;
    int calculateAmount(int, QString);
    QString singleFoodEntry;
    int selectedQuantity;
    int totalAmount;
};

#endif // MAINWINDOW_H
