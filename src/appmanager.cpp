#include "appmanager.h"
#include "actioncenter.h"

#include <QQmlContext>


AppManager::AppManager(QQmlApplicationEngine *engine, QObject *parent)
    : QObject(parent),
      _status(AppStatus::Idle),
      _actionCenter(new ActionCenter),
      _engine(engine)
{
}

bool AppManager::run()
{
    registerQmlTypes();
    registerContextObjects();
    bool ret = launch();
    if(!ret)
    {
        return false;
    }

    _actionCenter->init();
    _engine->rootContext()->setContextProperty("newOrder", _actionCenter->newOrder());
    _backendInitDone = true;
    if(_backendInitDone && _qmlStartupDone)
        setStatus(AppStatus::Ready);
    return true;
}

void AppManager::startupDone()
{
    _qmlStartupDone = true;
    if(_backendInitDone && _qmlStartupDone)
        setStatus(AppStatus::Ready);
}

void AppManager::setStatus(const AppManager::AppStatus &status)
{
    if(_status == status)
        return;
    _status = status;
    emit statusChanged(status);
}

bool AppManager::launch()
{
    _engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (_engine->rootObjects().isEmpty())
        return false;

    return true;
}

void AppManager::registerQmlTypes()
{
    QString unCreateWarn = "Unable to create object for AppManager from Qml";
    qmlRegisterUncreatableType<AppManager>("QMLEnums", 1, 0, "AppStatus", unCreateWarn);
    qmlRegisterSingletonType(QUrl("qrc:/themes/Theme.qml"), "Theme", 1, 0, "Theme");
}

void AppManager::registerContextObjects()
{
    _engine->rootContext()->setContextProperty("appmanager", this);
    _engine->rootContext()->setContextProperty("actionCenter", _actionCenter);
}
