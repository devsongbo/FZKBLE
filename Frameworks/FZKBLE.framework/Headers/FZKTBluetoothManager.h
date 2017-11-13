//
//  FZKTBluetoothManager.h
//  Connector
//
//  Created by czl on 2017/5/15.
//  Copyright © 2017年 chinapke. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SRBLEEnum.h"
#import "FZKBTypedef.h"
#import "FZKTBluetoothInfoModel.h"
#import "SRBLEReceivedData.h"
#import "StatusItem.h"
#import "BleStatusManager.h"
#import <CoreBluetooth/CoreBluetooth.h>
@protocol FZKBLEParseDelegate <NSObject>

@optional

- (void)receiveBleStatus:(SRBLEVehicleStatus *)vehicleStatus;
- (void)receiveOtherStatus:(NSArray*)items;
- (void)bleConnectStatus:(FZKBLEConnectStatus)state;//蓝牙连接状态
@end


@interface FZKTBluetoothManager : NSObject
/**
 单利
 
 */
+ (instancetype)instanceShare;

@property(nonatomic,strong)CBCentralManager *centralManager;
@property (nonatomic,strong) BleStatusManager* statusManager;

//共享车模式，上锁断油路
@property BOOL lockThenCloseMode;

@property (nonatomic,weak) id<FZKBLEParseDelegate> delegate;

/**
 当前车辆id
 */
@property (nonatomic,readonly) NSInteger carId;

/**
 连接 指定蓝牙
 param mac 蓝牙mac地址
 param callBack 连接成功与失败的回调
 */
- (void)connection:(FZKTBluetoothInfoModel *) bleInfo;


/**
 判断是否可以发送蓝牙控制连接
 */
- (BOOL)connectionState;


/**
 蓝牙是否打开
 */
- (BOOL)canUserBle;

/**
 断开连接
 */
- (void)disConnection;

/**
 根据TAG查询设备状态
 */

-(void)queryStatusByTags:(NSArray*)tags callbakc:(QueryBlock)callback;

-(void)queryStatusByTag:(SRBLEOperationInstruction)tag callback:(QueryBlock)callback;

//发送控制指令
- (void)sendCommand:(SRBLEInstruction)command callback:(CompleteBlock)callback;


//查询状态
- (void)queryStatus;



@end
