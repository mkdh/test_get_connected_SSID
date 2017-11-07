import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: btn_ssid
        text: ""
        width: parent.width
        onClicked: {
           btn_ssid.text = cls_get_ssid.slot_get_ssid()
        }
    }

}
