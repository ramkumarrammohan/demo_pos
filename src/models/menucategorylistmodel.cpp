#include "menucategorylistmodel.h"
#include "menucategory.h"

MenuCategoryListModel::MenuCategoryListModel(QObject *parent)
    : ListModel(parent)
{

}

void MenuCategoryListModel::sync(const QVariant &category)
{
    beginResetModel();
    foreach (const QVariant itemdata, category.value<QVariantList>()) {
        m_items << new MenuCategory(itemdata);
    }
    endResetModel();
}
