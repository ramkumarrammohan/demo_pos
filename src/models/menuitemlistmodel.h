#ifndef MENUITEMLISTMODEL_H
#define MENUITEMLISTMODEL_H

#include "listmodel.h"

class MenuItemListModel : public ListModel
{
public:
    MenuItemListModel(QObject *parent = nullptr);
    void sync(const QVariant &item);
};

#endif // MENUITEMLISTMODEL_H
