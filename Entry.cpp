#include "Entry.h"

Entry::Entry()
{
    quantity = 0;
    item = "";
}

void Entry::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

void Entry::setItem(QString newItem)
{
    item = newItem;
}

int Entry::getQuantity()
{
    return quantity;
}

QString Entry::getItem()
{
    return item;
}
