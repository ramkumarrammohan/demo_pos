#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>

class ListModel : public QAbstractListModel
{
public:
    enum Roles
    {
        ItemRole = Qt::UserRole + 1
    };

    explicit ListModel(QObject *parent = 0);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;

    const QList<QObject *> &items() const
    {
        return m_items;
    }
    int size() const
    {
        return m_items.size();
    }
    void add(QObject *object);
    void clear();

protected:
    QList<QObject *> m_items;

};

#endif // LISTMODEL_H
