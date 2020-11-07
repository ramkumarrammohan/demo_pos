#include "listmodel.h"

ListModel::ListModel(QObject *parent): QAbstractListModel(parent)
{

}

int ListModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : m_items.size();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if ((index.row() >= 0 || index.row() < m_items.count()) &&
        role == ItemRole) {
        return QVariant::fromValue(m_items[index.row()]);
    }
    return QVariant();
}

QHash<int, QByteArray> ListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ItemRole] = "item";
    return roles;
}

void ListModel::add(QObject *object)
{
    if(!object)
        return;

    const int index = m_items.size();
    beginInsertRows(QModelIndex(), index, (index));
    m_items.append(object);
    endInsertRows();
}

void ListModel::clear()
{
    beginResetModel();
    foreach (auto obj, m_items) {
        obj->deleteLater();
    }
    m_items.clear();
    endResetModel();
}
