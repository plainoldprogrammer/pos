#ifndef TICKETSTABLEWINDOW_H
#define TICKETSTABLEWINDOW_H

#include <QDialog>
#include <QTableView>
#include <QResizeEvent>

namespace Ui {
class TicketsTableWindow;
}

class TicketsTableWindow : public QDialog
{
	Q_OBJECT
	
public:
	explicit TicketsTableWindow(QWidget *parent = nullptr);
	~TicketsTableWindow();
	QTableView * getTableView();
	void resizeEvent(QResizeEvent *);
	
private:
	Ui::TicketsTableWindow *ui;
};

#endif // TICKETSTABLEWINDOW_H
