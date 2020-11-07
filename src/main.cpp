#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "appmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    AppManager appManager(&engine);
    if(!appManager.run())
        return -1;

    return app.exec();
}
