#ifndef ORDERITEM_H
#define ORDERITEM_H

#include "../propertyhelper.h"
#include <QObject>

class MenuItem;
class OrderItem : public QObject
{
    Q_OBJECT

    AUTO_PROPERTY(QString, name)
    AUTO_PROPERTY(float, price)
    AUTO_PROPERTY(int, quantity)

public:
    explicit OrderItem(QObject *parent = nullptr);
    OrderItem(MenuItem* menuItem);
    OrderItem *clone();

};

#endif // ORDERITEM_H
