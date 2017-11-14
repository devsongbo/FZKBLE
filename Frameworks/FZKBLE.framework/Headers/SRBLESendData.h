//
//  SRBLESendData.h
//  Mizward
//
//  Created by zhangjunbo on 15/8/27.
//  Copyright (c) 2015年 Mizward. All rights reserved.
//

#import "SRBLEData.h"
#import "SRBLEEnum.h"

//控制、查询采用广播形式
//ACK采用单播

@interface SRBLESendData : SRBLEData

//心跳数据
+ (SRBLESendData *)buildHeart;


//蓝牙认证数据查询
+ (SRBLESendData *)queryBleAuthData;

//蓝牙认证
+ (SRBLESendData *)bleAuthDataWithID:(NSInteger)idNumber;

//大数据申请
+ (SRBLESendData *)bleBigDataRequest;

//设备连接状态
+ (SRBLESendData *)terminalConnectionStatus;

//查询ID及密钥
+ (SRBLESendData *)queryEncryptionInfo;

//根据Tag查询状态
+ (SRBLESendData *)queryStatus:(SRBLEOperationInstruction)tag;

//设置ID及密钥
+ (SRBLESendData *)configDataWithID:(NSString *)idStr
                             andKey:(NSString *)keyStr;

//查询控制滚动码
+ (SRBLESendData *)queryControlNumber;
//控制
+ (SRBLESendData *)dataWithControlInstruction:(SRBLEInstruction)instruction
                                controlNumber:(UInt16)controlNumber
                                          key:(NSString *)keyStr
                                        idStr:(NSString *)idStr;

//状态查询
+ (SRBLESendData *)dataWithQueryStatus;

//终端基本信息查询
+ (SRBLESendData *)queryTerminalBasicInfo;

//回复
+ (SRBLESendData *)dataWithAckTerminalType:(SRBLETerminalType)terminalType
                      operationInstruction:(SRBLEOperationInstruction)operationInstruction;

//升级固件回应
//+ (SRBLESendData *)datawith
//升级分片回应

//通用
+ (SRBLESendData *)dataWithTerminalType:(SRBLETerminalType)terminalType
                   operationMessageType:(SRBLEMessageType)operationMessageType
                   operationInstruction:(SRBLEOperationInstruction)operationInstruction
         operationInstructionParamenter:(NSString *)operationInstructionParamenter;



- (BOOL)needAck;
- (NSData *)dataValue;

@end
