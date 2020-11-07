#include "orderitem.h"
#include "menuitem.h"


OrderItem::OrderItem(QObject *parent) : QObject(parent)
{
}

OrderItem::OrderItem(MenuItem *menuItem)
{
    if(!menuItem)
        return;

    a_name = menuItem->name();
    a_price = menuItem->price();
    a_quantity = 1;
}

OrderItem *OrderItem::clone()
{
    OrderItem *orderItemClone = new OrderItem;
    orderItemClone->a_name = a_name;
    orderItemClone->a_price = a_price;
    orderItemClone->a_quantity = a_quantity;

    return orderItemClone;
}
