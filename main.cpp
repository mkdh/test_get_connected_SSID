#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "get_ssid.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QQmlContext* ctext = engine.rootContext();
    GetSSID cls_get_ssid;
    ctext->setContextProperty("cls_get_ssid", &cls_get_ssid);
    ctext->setContextProperty("app", &app);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
