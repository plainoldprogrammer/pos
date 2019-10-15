#ifndef TICKET_H
#define TICKET_H

#include <QString>

class Ticket
{
public:
	Ticket();
	
	void setHeader(QString);
	void setBody(QString);
	void setFooter(QString);
	void setTicketTotalAmount(int);
	QString getHeader();
	QString getBody();
	QString getFooter();
	int getTicketTotalAmount();
private:
	QString header;
	QString body;
	QString footer;
	int ticketTotalAmount;
};

#endif // TICKET_H
