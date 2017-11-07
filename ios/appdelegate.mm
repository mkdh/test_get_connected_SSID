#import "UIKit/UIKit.h"
#include <QtCore>
#include "ios/cls_system_dispatcher.h"
#import <SystemConfiguration/CaptiveNetwork.h>

@interface QIOSApplicationDelegate
@end

@interface QIOSApplicationDelegate(AppDelegate)
@end

@implementation QIOSApplicationDelegate (AppDelegate)

// It just demonstrate how to override QIOSApplicationDelegate to get
// launch options via didFinishLaunchingWithOptions.
// QuickIOS do not bundle this code since it may conflict with
// other framework whose need this piece of information

- (BOOL)application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    Q_UNUSED(application);

    NSLog(@"didFinishLaunchingWithOptions: %@", [launchOptions description]);

    clsSystemDispatcher* dispatcher = clsSystemDispatcher::instance();
//    dispatcher->addListener("activityIndicatorStartAnimation",pop_up_wifi_setting_page);
    dispatcher->addListener("ios_get_ssid",ios_get_ssid);

    return YES;
}
static bool pop_up_wifi_setting_page(QVariantMap& data) {
    Q_UNUSED(data);
    if ([[UIApplication sharedApplication] canOpenURL:[NSURL URLWithString:@"prefs:root=WIFI"]]) {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"prefs:root=WIFI"]];
    } else {
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"App-Prefs:root=WIFI"]];
    }
    return true;
}

static bool ios_get_ssid(QVariantMap& data) {
    Q_UNUSED(data);
    //https://stackoverflow.com/questions/31555640/how-to-get-wifi-ssid-in-ios9-after-captivenetwork-is-deprecated-and-calls-for-wi
        NSString *wifiName = nil;
        NSArray *ifs = (__bridge_transfer id)CNCopySupportedInterfaces();
        for (NSString *ifnam in ifs) {
            NSDictionary *info = (__bridge_transfer id)CNCopyCurrentNetworkInfo((__bridge CFStringRef)ifnam);
            if (info[@"SSID"]) {
                wifiName = info[@"SSID"];
                break;
            }
        }
        NSLog( @"Here is a test message: '%@'", wifiName );
        //https://stackoverflow.com/questions/5198716/iphone-get-ssid-without-private-library
    return true;
}


@end



