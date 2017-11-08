#include "cls_get_ssid.h"

#include "ios/cls_system_dispatcher.h"

ClsGetSSID::ClsGetSSID()
{
#if defined(Q_OS_ANDROID)
#endif
}

ClsGetSSID::~ClsGetSSID()
{

}

QString ClsGetSSID::slot_get_ssid()
{
    QString currentSsid = "";

#if defined(Q_OS_ANDROID)
    //https://github.com/Mogara/QSanguosha/blob/master/src/util/wifimanager.cpp
    QAndroidJniObject activity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative", "activity", "()Landroid/app/Activity;");
    if ( activity.isValid() )
    {
        QAndroidJniObject serviceName = QAndroidJniObject::getStaticObjectField<jstring>("android/content/Context","WIFI_SERVICE");
        if ( serviceName.isValid() )
        {
            QAndroidJniObject powerMgr = activity.callObjectMethod("getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;",serviceName.object<jobject>());
            if ( powerMgr.isValid() )
            {
                QAndroidJniObject currentConnection = powerMgr.callObjectMethod("getConnectionInfo", "()Landroid/net/wifi/WifiInfo;");
                currentSsid = currentConnection.callObjectMethod("getSSID", "()Ljava/lang/String;").toString();
            }
        }
    }


#endif


#if defined(Q_OS_IOS)
    qDebug()<<"Q_OS_IOS";
    /*
    QVariantMap map;
    map["style"] = 2;

    clsSystemDispatcher::instance()->dispatch("ios_get_ssid",map);
    */
    currentSsid = wifiName();
#else//OS
    qDebug()<<"OS";
#endif
    qDebug() << currentSsid << "<-----" << __func__;
    return currentSsid;
}
