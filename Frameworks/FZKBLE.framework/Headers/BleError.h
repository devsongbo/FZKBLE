//
//  BleError.h
//  Pods
//
//  Created by 马宁 on 2017/8/28.
//
//

#import <Foundation/Foundation.h>

extern NSError * BLE_NOTE_CONNECTED; // 蓝牙未连接
extern NSError * BLE_NOT_READY;      // 连接发送消息未就绪
extern NSError * BLE_NOT_RESPONSE;   // 消息无应答
extern NSError * BLE_NOT_SUPPORTTAG; // 不支持TAG


@interface BleError : NSObject

+(void) setup;

@end
