#include "Ticket.h"

Ticket::Ticket()
{
	header = "";
	body = "";
	footer = "";
	ticketTotalAmount;
}

void Ticket::setHeader(QString newHeader)
{
	header = newHeader;
}

void Ticket::setBody(QString newBody)
{
	body = newBody;
}

void Ticket::setFooter(QString newFooter)
{
	footer = newFooter;
}

void Ticket::setTicketTotalAmount(int newTicketTotalAmount)
{
	ticketTotalAmount = newTicketTotalAmount;
}

QString Ticket::getHeader()
{
	return header;
}

QString Ticket::getBody()
{
	return body;
}

QString Ticket::getFooter()
{
	return footer;
}

int Ticket::getTicketTotalAmount()
{
	return ticketTotalAmount;
}
