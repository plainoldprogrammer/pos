#ifndef SALESREPORTWINDOW_H
#define SALESREPORTWINDOW_H

#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class SalesReportWindow;
}

class SalesReportWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SalesReportWindow(QWidget *parent = nullptr);
    ~SalesReportWindow();
    QPlainTextEdit * getPlainTextEdit();

private:
    Ui::SalesReportWindow *ui;
};

#endif // SALESREPORTWINDOW_H
