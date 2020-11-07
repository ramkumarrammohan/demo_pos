#include "order.h"
#include "menuitem.h"
#include "orderitem.h"
#include "listmodel.h"


Order::Order(QObject *parent)
    : QObject(parent),
      _orderItems(new ListModel)
{
    a_totalAmount = "0.00";
}

void Order::addOrderItem(QObject *itemObj)
{
    MenuItem *item = static_cast<MenuItem*>(itemObj);
    if(!item)
        return;

    if(_orderItemHash.contains(item->name()))
    {
        QObject *object = _orderItemHash[item->name()];
        OrderItem *orderItem = static_cast<OrderItem*>(object);
        if(orderItem)
        {
            orderItem->quantity(orderItem->quantity() + 1);
            orderItem->price(orderItem->quantity() * item->price());
        }
    }
    else
    {
        OrderItem *orderItem = new OrderItem(item);
        _orderItems->add(orderItem);
        _orderItemHash.insert(orderItem->name(), orderItem);
    }

    // total calculation
    float total = 0.0;
    foreach (QObject *obj, _orderItems->items()) {
        OrderItem *orderItem = static_cast<OrderItem*>(obj);
        total += orderItem->price();
    }

    QString priceStr = QString::number(total, 'f', 2);
    totalAmount(priceStr);
}

Order *Order::clone()
{
    Order *orderClone = new Order;
    foreach (QObject *obj, _orderItems->items()) {
        OrderItem *orderItem = static_cast<OrderItem*>(obj);
        OrderItem *orderItemClone = orderItem->clone();
        orderClone->_orderItems->add(orderItemClone);
    }
    orderClone->a_totalAmount = a_totalAmount;

    return orderClone;
}

void Order::clearOrder()
{
    _orderItems->clear();
    _orderItemHash.clear();
    totalAmount("0.00");
}
