//
//  SRBLEData.h
//  Mizward
//
//  Created by zhangjunbo on 15/8/26.
//  Copyright (c) 2015年 Mizward. All rights reserved.
//


#import "SRBLEEnum.h"

/**
 *      *校验#设备ID#消息类型#标签1,参数…#
 *      *crc #terminalType#operationMessageType#operationInstruction,XX,XX#
 *
 *      蓝牙认证:(收)*02#f#5#a605,2659#
 *              (发)*67#f#5#a606,5a11390959173e13580e41325a22422693d5493b#
 *
 *      设备连接状态:(发)B304 BTU              *f9#f#1#b304#
 *                 (收)B304
 *
 *      查询ID及密钥状态:(发)B203               *c7#0#7#b203#
 *                     (收)B203 B443         *f2#7#8#B203,123456,123456789012##
 *
 *      配置ID及密钥:(发)B203                  *c4#0#3#b203,123456,123456789012#
 *                  (收)B203 B443            *02#0#4#B203,123456,123456789012##
 *
 *      控制:(发)B502              *93#0#7#b502,12345602d279f740#
 *           (ACK)B502 B443       *f4#7#8#b502##
 *           (执行结果收)B402       *50#7#7#b402,2##
 *           (ACK)B402            *d0#7#8#b402#
 *
 *      状态查询:(发)B301          *c0#0#1#b301#
 *              (收)B301 B443     *77#7#2#b301,0220,22000,0000,00000,00,00,0##
 *                                            acc           on          engine      run,   1:开
 *                                            doorLF        doorRF      doorLB      doorRB      trunkDoor,
 *                                            doorLockLF    doorLockRF  doorLockLB  doorLockRB,
 *                                            windowLF      windowRF    windowLB    windowRB    windowSky,
 *                                            lightBig      lightSmall,
 *      版本信息查询:(发)B101  *be#0#1#b101#
 *                  (收)     *bc#7#2#b101,ost.base.103b,030001e2.debug,c1.f.1,base.toyota##
 *
 *      在线升级:
 *      在线调试:
 *
 */

@interface SRBLEData : NSObject

//发送   需要ACK确认：SRBLEMessageType_Publish
//      不需要ACK确认：SRBLEMessageType_Execute
//      ACK:SRBLEMessageType_Publish_Confirm
//      查询：SRBLEMessageType_Query
//接收   需要ACK确认：SRBLEMessageType_Publish
//      ACK:SRBLEMessageType_Publish_Confirm
@property (nonatomic, assign) SRBLETerminalType terminalType;
@property (nonatomic, assign) SRBLEMessageType operationMessageType;
//控制：SRBLEOperationInstruction_B502 查询：SRBLEOperationInstruction_B301
@property (nonatomic, assign) SRBLEOperationInstruction operationInstruction;
@property (nonatomic, copy) NSString *operationInstructionParamenter;

+ (NSString *)transferEndFlagString;
+ (NSData *)transferEndFlagData;

@end






