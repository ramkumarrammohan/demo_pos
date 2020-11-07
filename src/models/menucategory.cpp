#include "menucategory.h"

#include <QVariantMap>

MenuCategory::MenuCategory(QObject *parent) : QObject(parent)
{
}

MenuCategory::MenuCategory(const QVariant &variant)
{
    QVariantMap map = variant.value<QVariantMap>();
    a_id = map["id"].toInt();
    a_name = map["name"].toString();
}
