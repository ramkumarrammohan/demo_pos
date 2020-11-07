#include "menuitemlistmodel.h"
#include "menuitem.h"


MenuItemListModel::MenuItemListModel(QObject *parent)
    : ListModel(parent)
{

}

void MenuItemListModel::sync(const QVariant &item)
{
    beginResetModel();
    foreach (const QVariant itemdata, item.value<QVariantList>()) {
        m_items << new MenuItem(itemdata);
    }
    endResetModel();
}
