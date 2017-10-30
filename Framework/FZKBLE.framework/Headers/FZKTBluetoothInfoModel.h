//
//  FZKTBluetoothInfoModel.h
//  Connector
//
//  Created by czl on 2017/5/15.
//  Copyright © 2017年 chinapke. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FZKTBluetoothInfoModel : NSObject<NSCoding>

@property (nonatomic,copy) NSString *key;

@property (nonatomic,copy) NSString *mac;

@property (nonatomic,copy) NSString *bluetoothID;

@property (nonatomic,copy) NSString *uuid;

@property (nonatomic,assign) BOOL hasBluetooth;

@property (nonatomic,assign) NSInteger carId;

@end
