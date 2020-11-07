#include "menuitemfilterlistmodel.h"
#include "listmodel.h"
#include "menuitem.h"

MenuItemFilterListModel::MenuItemFilterListModel(QObject *parent)
    :QSortFilterProxyModel(parent)
{
    sort(0, Qt::AscendingOrder);
}

void MenuItemFilterListModel::setCategoryId(const int &id)
{
    if(_categoryId == id)
        return;
    _categoryId = id;
    invalidateFilter();
}

bool MenuItemFilterListModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if(_categoryId < 0)
        return false;

    QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
    MenuItem *item = sourceModel()->data(index, ListModel::Roles::ItemRole).value<MenuItem*>();

    if(!item)
        return false;

    if(item->categoryId() == _categoryId)
        return true;
    else
        return false;
}

bool MenuItemFilterListModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    QVariant leftVariant = sourceModel()->data(left, ListModel::Roles::ItemRole);
    QVariant rightVariant = sourceModel()->data(right, ListModel::Roles::ItemRole);
    MenuItem *leftData = qvariant_cast<MenuItem*>(leftVariant);
    MenuItem *rightData = qvariant_cast<MenuItem*>(rightVariant);

    if(!leftData || !rightData)
        return false;

    return leftData->name() < rightData->name();
}
