#include "actioncenter.h"
#include "models/menucategorylistmodel.h"
#include "models/menuitemlistmodel.h"
#include "models/menuitemfilterlistmodel.h"
#include "models/order.h"

#include <QFile>
#include <QJsonDocument>
#include <QDebug>

struct ActionCenterData
{
    ActionCenterData()
    {
        mNewOrder = new Order;
        mOrders = new ListModel;
        mItem = new MenuItemListModel;
        mCategory = new MenuCategoryListModel;
        mItemsFilter = new MenuItemFilterListModel;
    }

    Order *mNewOrder = nullptr;
    ListModel *mOrders = nullptr;
    MenuItemListModel *mItem = nullptr;
    MenuCategoryListModel *mCategory = nullptr;
    MenuItemFilterListModel *mItemsFilter = nullptr;
};

ActionCenter::ActionCenter(QObject *parent) : QObject(parent)
{
}

void ActionCenter::init()
{
    d = new ActionCenterData;
    loadDummyData(":/demo_data/menucategory.json");
    loadDummyData(":/demo_data/menuitem.json");
    d->mItemsFilter->setSourceModel(d->mItem);
}

QObject *ActionCenter::categories() const
{
    return (QObject*)d->mCategory;
}

QObject *ActionCenter::items() const
{
    return (QObject*)d->mItemsFilter;
}

QObject *ActionCenter::newOrder() const
{
    return (QObject*)d->mNewOrder;
}

void ActionCenter::selectedCategory(const int &categoryId)
{
    d->mItemsFilter->setCategoryId(categoryId);
}

void ActionCenter::checkout()
{
    Order *order = d->mNewOrder->clone();
    if(order)
        d->mOrders->add(order);

    d->mNewOrder->clearOrder();
    d->mItemsFilter->setCategoryId(-1);
    qDebug() << "Orderlist: " << d->mOrders->size();
}

void ActionCenter::loadDummyData(const QString &filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
        return;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    QVariant variant = doc.toVariant();
    QVariant items = variant.value<QVariantMap>()["items"];
    QString menu = variant.value<QVariantMap>()["menu"].toString();

    if(menu == "menu_category")
    {
        d->mCategory->sync(items);
    }
    else if(menu == "menu_item")
    {
        d->mItem->sync(items);
    }
    else
    {
        qWarning() << "Unknown data found..";
    }
}
