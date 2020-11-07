#include "menuitem.h"

#include <QVariantMap>

MenuItem::MenuItem(QObject *parent) : QObject(parent)
{
}

MenuItem::MenuItem(const QVariant &variant)
{
    QVariantMap map = variant.value<QVariantMap>();
    a_categoryId = map["category_id"].toInt();
    a_name = map["name"].toString();
    a_price = map["price"].toFloat();
}

MenuItem::MenuItem(const MenuItem *copy)
{
    if(!copy)
        return;

    a_name = copy->name();
    a_price = copy->price();
    a_categoryId = copy->categoryId();
}
