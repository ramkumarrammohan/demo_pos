#ifndef MENUCATEGORY_H
#define MENUCATEGORY_H

#include <QObject>
#include "../propertyhelper.h"

class MenuCategory : public QObject
{
    Q_OBJECT

    AUTO_PROPERTY(int, id)
    AUTO_PROPERTY(QString, name)

public:
    explicit MenuCategory(QObject *parent = nullptr);
    MenuCategory(const QVariant &variant);
};

#endif // MENUCATEGORY_H
