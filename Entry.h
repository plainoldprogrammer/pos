#ifndef ENTRY_H
#define ENTRY_H

#include <QString>

class Entry
{
public:
    Entry();

    void setQuantity(int);
    void setItem(QString);
    int getQuantity();
    QString getItem();
private:
    int quantity;
    QString item;
};

#endif // ENTRY_H
