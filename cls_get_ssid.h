#ifndef CLS_GET_SSID_H
#define CLS_GET_SSID_H


#if __ANDROID__

#include <QtAndroidExtras>
#include <QAndroidJniObject>
#include "jni.h"

#endif
#include <QDebug>
QString wifiName();

class ClsGetSSID: public QObject
{
    Q_OBJECT
public:
    ClsGetSSID();
    virtual ~ClsGetSSID();
private:
#if defined(Q_OS_ANDROID)

#endif

public slots:
    QString slot_get_ssid();
};

#endif // CLS_GET_SSID_H
