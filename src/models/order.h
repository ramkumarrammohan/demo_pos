#ifndef ORDER_H
#define ORDER_H

#include "../propertyhelper.h"
#include <QObject>
#include <QHash>

class OrderItem;
class ListModel;
class Order : public QObject
{
    Q_OBJECT

    AUTO_PROPERTY(QString, totalAmount)
    Q_PROPERTY(QObject* orderItems READ orderItems CONSTANT)

public:
    explicit Order(QObject *parent = nullptr);

    Q_INVOKABLE void addOrderItem(QObject *itemObj);
    Order *clone();
    void clearOrder();
    QObject* orderItems() const
    {
        return (QObject*)_orderItems;
    }

private:
    QHash<QString, QObject*> _orderItemHash;
    ListModel *_orderItems = nullptr;
};

#endif // ORDER_H
