#ifndef ACTIONCENTER_H
#define ACTIONCENTER_H

#include <QObject>

struct ActionCenterData;
class ActionCenter : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QObject* categories READ categories CONSTANT)
    Q_PROPERTY(QObject* items READ items CONSTANT)
    Q_PROPERTY(QObject* newOrder READ newOrder)

public:
    explicit ActionCenter(QObject *parent = nullptr);
    void init();

    // getters
    QObject *categories() const;
    QObject *items() const;
    QObject *newOrder() const;

    // Invokables
    Q_INVOKABLE void selectedCategory(const int &categoryId);
    Q_INVOKABLE void checkout();

private:
    ActionCenterData *d = nullptr;

    void loadDummyData(const QString &filename);
};

#endif // ACTIONCENTER_H
