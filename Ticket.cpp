#include "Ticket.h"

Ticket::Ticket()
{
    header = "";
    body = "";
    footer = "";
    ticketTotalAmount = 0;
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

void Ticket::setId(int id)
{
    this->id = id;
}

int Ticket::getId()
{
    return this->id;
}
