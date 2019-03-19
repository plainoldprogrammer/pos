#include "ticket.h"

ticket::ticket()
{
    header = "";
    body = "";
    footer = "";
    ticketTotalAmount;
}

void ticket::setHeader(QString newHeader)
{
    header = newHeader;
}

void ticket::setBody(QString newBody)
{
    body = newBody;
}

void ticket::setFooter(QString newFooter)
{
    footer = newFooter;
}

void ticket::setTicketTotalAmount(int newTicketTotalAmount)
{
    ticketTotalAmount = newTicketTotalAmount;
}

QString ticket::getHeader()
{
    return header;
}

QString ticket::getBody()
{
    return body;
}

QString ticket::getFooter()
{
    return footer;
}

int ticket::getTicketTotalAmount()
{
    return ticketTotalAmount;
}
