#ifndef GET_SSID_H
#define GET_SSID_H


#if __ANDROID__

#include <QtAndroidExtras>
#include <QAndroidJniObject>
#include "jni.h"

#endif
#include <QDebug>

class GetSSID: public QObject
{
    Q_OBJECT
public:
    GetSSID();
    virtual ~GetSSID();
private:
#if defined(Q_OS_ANDROID)

#endif

public slots:
    QString slot_get_ssid();
};

#endif // GET_SSID_H
