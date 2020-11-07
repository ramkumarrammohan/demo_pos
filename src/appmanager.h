#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QQmlApplicationEngine>

class ActionCenter;
class AppManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(AppStatus status READ status WRITE setStatus NOTIFY statusChanged)

public:
    enum AppStatus {
        Unknown = -1,
        Idle,
        Ready
    };
    Q_ENUM(AppStatus)
    explicit AppManager(QQmlApplicationEngine *engine, QObject *parent = nullptr);

    bool run();
    Q_INVOKABLE void startupDone();

    // getter & setters
    AppStatus status() const
    {
        return _status;
    }
    void setStatus(const AppStatus &status);

signals:
    void statusChanged(AppStatus status);

private:
    AppStatus _status = AppStatus::Unknown;
    ActionCenter *_actionCenter = nullptr;
    QQmlApplicationEngine *_engine = nullptr;
    bool _qmlStartupDone = false;
    bool _backendInitDone = false;

    bool launch();
    void registerQmlTypes();
    void registerContextObjects();
};

#endif // APPMANAGER_H
