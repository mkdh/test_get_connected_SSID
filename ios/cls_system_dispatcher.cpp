#include <QCoreApplication>
#include <QPointer>
#include <QtCore>
#include "cls_system_dispatcher.h"

typedef bool (*handler)(QVariantMap& data);
static QMap<QString,handler> handlers;
static QPointer<clsSystemDispatcher> m_instance;

clsSystemDispatcher *clsSystemDispatcher::instance()
{
    if (!m_instance) {
        QCoreApplication* app = QCoreApplication::instance();
        m_instance = new clsSystemDispatcher(app);
    }
    return m_instance;
}

clsSystemDispatcher::clsSystemDispatcher(QObject *parent) : QObject(parent) {
}

bool clsSystemDispatcher::dispatch(QString type , QVariantMap message) {

    QMetaObject::invokeMethod(this,"dispatched",Qt::QueuedConnection,
                              Q_ARG(QString , type),
                              Q_ARG(QVariantMap,message));

    bool res = false;
    if (handlers.contains(type)) {
        res = handlers[type](message);
    }

    return res;
}

bool clsSystemDispatcher::addListener(QString name, bool (*func)(QVariantMap&))
{
    if (handlers.contains(name)) {
        qWarning() << QString("%s is already registered").arg(name);
        return false;
    }

    handlers[name] = func;
    return true;
}
