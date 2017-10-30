//
//  SRBLEReceivedData.h
//  Mizward
//
//  Created by zhangjunbo on 15/8/27.
//  Copyright (c) 2015年 Mizward. All rights reserved.
//

#import "SRBLEData.h"
#import <UIKit/UIKit.h>
@class SRBLEVehicleStatus, SRBLEEncryptionInfo, SRBLEControlResult, SRBLEBluetoothInfo;

@interface SRBLEReceivedData : SRBLEData


@property (nonatomic, assign) NSInteger carId;

- (instancetype)initWithData:(NSData *)data;



- (SRBLEVehicleStatus *)vehicleStatus;
- (SRBLEControlResult *)controlResult;
- (SRBLEEncryptionInfo *)encryptionInfo;

- (SRBLEBluetoothInfo *)bluetoothInfo;

- (NSInteger)controlNumber;

@end
