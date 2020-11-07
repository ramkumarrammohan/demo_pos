#ifndef MENUCATEGORYLISTMODEL_H
#define MENUCATEGORYLISTMODEL_H

#include "listmodel.h"

class MenuCategoryListModel : public ListModel
{
public:
    MenuCategoryListModel(QObject *parent = nullptr);
    void sync(const QVariant &category);
};

#endif // MENUCATEGORYLISTMODEL_H
