#ifndef MENUITEMFILTERLISTMODEL_H
#define MENUITEMFILTERLISTMODEL_H

#include <QSortFilterProxyModel>

class MenuItemFilterListModel : public QSortFilterProxyModel
{
public:
    MenuItemFilterListModel(QObject *parent = nullptr);
    void setCategoryId(const int &id);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
    int _categoryId = -1;
};

#endif // MENUITEMFILTERLISTMODEL_H
