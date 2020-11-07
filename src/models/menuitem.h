#ifndef MENUITEM_H
#define MENUITEM_H

#include <QObject>
#include "../propertyhelper.h"

class MenuItem : public QObject
{
    Q_OBJECT

    AUTO_PROPERTY(int, categoryId)
    AUTO_PROPERTY(QString, name)
    AUTO_PROPERTY(float, price)

public:
    explicit MenuItem(QObject *parent = nullptr);
    MenuItem(const QVariant &variant);
    MenuItem(const MenuItem *copy);
};

#endif // MENUITEM_H
