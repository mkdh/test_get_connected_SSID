#import <UIKit/UIKit.h>
#import <SystemConfiguration/CaptiveNetwork.h>
#include <QString>

QString wifiName()
{
NSString *wifiName = nil;
NSArray *ifs = (__bridge_transfer id)CNCopySupportedInterfaces();
for (NSString *ifnam in ifs) {
NSDictionary *info = (__bridge_transfer
id)CNCopyCurrentNetworkInfo((__bridge CFStringRef)ifnam);
if (info[@"SSID"]) {
wifiName = info[@"SSID"];
break;
}
}
return QString::fromNSString(wifiName);
}
