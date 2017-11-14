//
//  SRBLEEnum.h
//  Mizward
//
//  Created by zhangjunbo on 15/8/26.
//  Copyright (c) 2015年 Mizward. All rights reserved.
//

#ifndef Mizward_SRBLEEnum_h
#define Mizward_SRBLEEnum_h

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, SRCharacteristicType) {
    SRCharacteristic_Read_BLE = 1,
    SRCharacteristic_Write_BLE = 2,
    SRCharacteristic_Read_Terminal = 3,
    SRCharacteristic_Write_Terminal = 4,
    SRCharacteristic_Unknown = 0,
};

typedef struct _CONTROL_COMMAND_FORMAT
{
    UInt8 data[8];
}__attribute__((packed)) CONTROL_COMMAND_FORMAT;


static NSString * const SRUUID_Characteristic_Read_Terminals = @"FFF6";
static NSString * const SRUUID_Characteristic_Write_BLEs = @"FFF3";
static NSString * const SRUUID_Characteristic_Write_Terminals = @"FFF5";
static NSString * const SRUUID_Peripheral_services = @"FFF0";
static NSString * const kBTUAuths = @"2i0L1o5V0f8u2z9ik-@~";
static const NSInteger kBLERetryTimes = 3; //重试次数
static const NSInteger kMaxBLEPacketLengths = 60;//数据分包最大长度
static const NSInteger kMaxBLESendLengths = 20; //发送数据包最大长度
static const NSTimeInterval kBLEAckTimeouts = 10; //指令响应超时10s
static const NSTimeInterval kBLEConnectTimeouts = 5;//外设连接超时时间
static const NSTimeInterval kBLEExecuteTimeouts = 30; //指令执行超时30s
static const NSTimeInterval kBLEScanNearbyTimes = 5;//扫描周边外设时间10s
static const NSTimeInterval kBLEScanTimeouts = 15; //蓝牙扫描30s
static const NSTimeInterval kBLESendDataMinIntervals = 50; //发送数据最小间隔时间 50ms


static const NSString *kBleStateNotifacations = @"kBleStateNotifacation";//蓝牙连接状态改变通知


#pragma mark - SRBLEPacketFlag

typedef NS_ENUM(UInt8, SRBLEPacketFlag) {
    SRBLEPacketFlag_Start_End   = 0,
    SRBLEPacketFlag_Start       = 1,
    SRBLEPacketFlag_Middle      = 2,
    SRBLEPacketFlag_End         = 3,
};

#pragma mark - TCP HTTP 控制指令
typedef NS_ENUM(NSUInteger, FZKTLVTag_Instruction) {
    //控制
    SRTLVTag_Instruction_Lock        = 0x501, //1281 上锁
    SRTLVTag_Instruction_Unlock      = 0x503, //1283 解锁
    SRTLVTag_Instruction_EngineOn    = 0x505, //1285 引擎开
    SRTLVTag_Instruction_EngineOff   = 0x506, //1286 引擎关
    SRTLVTag_Instruction_OilOn       = 0x507, //1287 油路开
    SRTLVTag_Instruction_OilBreak    = 0x508, //1288 油路关
    SRTLVTag_Instruction_Call        = 0x50a, //1290 寻车
    
    SRTLVTag_Instruction_Silence     = 0x514, //1300 静音
    SRTLVTag_Instruction_WindowClose = 0x517, //1303 关窗
    SRTLVTag_Instruction_WindowOpen  = 0x518, //1304 开窗
    SRTLVTag_Instruction_SkyClose    = 0x519, //1305 关天窗
    SRTLVTag_Instruction_SkyOpen     = 0x51a, //1306 开天窗
    
    SRTLVTag_Instruction_GPSWeak     = 0x604, //1540 唤醒GPS
    
    SRTLVTag_Instruction_Defence     = 0x5005, //20485 设防
    SRTLVTag_Instruction_Undefence   = 0x5006, //20486 撤防
};




#pragma mark - SRBLEInstruction



typedef NS_ENUM(UInt8, SRBLEInstruction) {
    SRBLEInstruction_NULL = 0,  //无效
    SRBLEInstruction_Lock = 1,  //关锁
    SRBLEInstruction_Unlock = 2,  //开锁
    SRBLEInstruction_Call = 3,  //寻车
    SRBLEInstruction_Silence = 4,   //静音
    SRBLEInstruction_EngineOn = 5,  //点火
    SRBLEInstruction_EngineOff = 6, //熄火
    SRBLEInstruction_WindowClose = 7,   //关门窗
    SRBLEInstruction_WindowOpen = 8,    //开门窗
    SRBLEInstruction_SkyClose = 9,  //关天窗
    SRBLEInstruction_SkyOpen = 10,  //开天窗
    SRBLEInstruction_OilOn = 11,    //通油
    SRBLEInstruction_OilBreak = 12, //停车断油
    SRBLEInstruction_OilBreakNow = 13,  //立即断油
    
    SRBLEInstruction_Reserved = 14
};




#pragma mark - SRBLETerminalType

typedef NS_ENUM(UInt8, SRBLETerminalType) {
    SRBLETerminalType_Broadcast = 0,
    SRBLETerminalType_OstV2 = 1,
    SRBLETerminalType_Otu = 2,
    SRBLETerminalType_Dig = 3,
    SRBLETerminalType_Pzjc = 4,
    SRBLETerminalType_Rfm = 5,
    SRBLETerminalType_Lcu = 6,
    SRBLETerminalType_Ostv3 = 7,
    
    SRBLETerminalType_Ble = 8,
};

#pragma mark - SRBLETerminalType

typedef NS_ENUM(UInt8, SRBLEMessageType) {
    SRBLEMessageType_Query = 1,
    SRBLEMessageType_Query_Ack = 2,
    SRBLEMessageType_Config = 3,
    SRBLEMessageType_Config_Ack = 4,
    SRBLEMessageType_Execute = 5,
    SRBLEMessageType_Na = 6,
    SRBLEMessageType_Publish = 7,
    SRBLEMessageType_Publish_Confirm = 8
};

#pragma mark - 状态Key

typedef NS_ENUM(UInt16, BLEStatusKey)
{
    SK_ACC,         //ACC档位
    SK_ON,          //ON档位
    SK_Engine,     //引擎
    SK_Lock,       //锁
    SK_Door,       //门边
    SK_TrunckDoor, //后备箱
    SK_Window,      //窗
    SK_SkyWindow,   //天窗
    SK_Mileage,     //里程
    SK_Leftoil,     //剩余油量百分比
    SK_Leftelec,    //剩余电量百分比
    SK_Voatge,      //电压值
    
};


#pragma mark - SRBLEOperationInstruction

typedef NS_ENUM(UInt16, SRBLEOperationInstruction) {
    
    //BTU tag
    SRBLEOperationInstruction_HEART = 0xA608,    //APP和蓝牙心跳
    SRBLEOperationInstruction_A605 = 0xA605,    //蓝牙认证输入随机码
    SRBLEOperationInstruction_A606 = 0xA606,    //蓝牙认证输出激活字符串
    SRBLEOperationInstruction_A607 = 0xA607,    //蓝牙大数据传输申请
    SRBLEOperationInstruction_A304 = 0xA304,    //终端与蓝牙的会话状态
    
    SRBLEOperationInstruction_B101 = 0xB101,    //产品名称、软件信息、硬件信息、车型信息
    SRBLEOperationInstruction_B102 = 0xB102,    //软件版本
    SRBLEOperationInstruction_B103 = 0xB103,    //硬件信息
    SRBLEOperationInstruction_B104 = 0xB104,    //固件扇区
    SRBLEOperationInstruction_B105 = 0xB105,    //重启序号、重启原因
    
    //配置
    SRBLEOperationInstruction_B201 = 0xB201,    //蓝牙钥匙ID、密钥
    SRBLEOperationInstruction_B202 = 0xB202,    //蓝牙连接PIN码
    SRBLEOperationInstruction_B203 = 0xB203,    //配置蓝牙加密ID及密钥
    
    //状态
    //状态 acc+on+引擎+行驶,(门)左前+右前+左后+右后+后箱,(锁)左前+右前+左后+右后,(窗)左前+右前+左后+右后+天窗,大灯+小灯,设防+侵入,告警编码
    SRBLEOperationInstruction_B301 = 0xB301,
    
    VOTAGE_B310 = 0xB310,
    MILEAGE_B311 = 0xB311,
    LEFTOIL_B312 = 0xB312,
    LEFTELEC_B313 = 0xB313,
    
    SRBLEOperationInstruction_B302 = 0xB302,    //通信模块与网关的会话状态
    SRBLEOperationInstruction_B303 = 0xB303,    //蓝牙模块与手机的会话状态
    SRBLEOperationInstruction_B304 = 0xB304,    //终端与蓝牙的会话状态
    
    //事件
    SRBLEOperationInstruction_B401 = 0xB401,    //业务回应
    SRBLEOperationInstruction_B402 = 0xB402,    //蓝牙回应
    SRBLEOperationInstruction_B422 = 0xB422,    //升级回应
    INVALIDTAG_B443 = 0xB443,    //未知标签
    
    //业务
    SRBLEOperationInstruction_B501 = 0xB501,    //业务指令
    SRBLEOperationInstruction_B502 = 0xB502,    //蓝牙指令
    
    //指令
    SRBLEOperationInstruction_B601 = 0xB601,    //重启：立即
    SRBLEOperationInstruction_B602 = 0xB602,    //修改引导扇区编号并重启
    SRBLEOperationInstruction_B605 = 0xB605,    //同步OTU滚动码
    //会话
    SRBLEOperationInstruction_B701 = 0xB701,    //透传：命令行指令
    SRBLEOperationInstruction_B702 = 0xB702,    //透传：命令行回显
    SRBLEOperationInstruction_B703 = 0xB703,    //透传：日志使能
    SRBLEOperationInstruction_B704 = 0xB704,    //透传：日志回显
    SRBLEOperationInstruction_B705 = 0xB705,    //总线捕获请求
    SRBLEOperationInstruction_B706 = 0xB706,    //总线捕获回应
    SRBLEOperationInstruction_B707 = 0xB707,    //相邻总线，设备ID，设备回显
    SRBLEOperationInstruction_B708 = 0xB708,    //相邻总线，设备ID，设备回显
    
    //升级
    SRBLEOperationInstruction_B801 = 0xB801,    //启动升级
    SRBLEOperationInstruction_B802 = 0xB802,    //停止升级
    SRBLEOperationInstruction_B803 = 0xB803,    //固件请求，扇区编号、扇区当前软件版本、分片长度
    SRBLEOperationInstruction_B804 = 0xB804,    //固件回应，字节总数、分片总数、校验和
    SRBLEOperationInstruction_B805 = 0xB805,    //分片请求，编号
    SRBLEOperationInstruction_B806 = 0xB806,    //分片回应，编号、校验和、数据
};

#pragma mark - SRBLEControlResultCode

typedef NS_ENUM(NSInteger, SRBLEControlResultCode) {
    SRBLEControlResultCode_NULL                 = 0x00, //无效
    SRBLEControlResultCode_OK                   = 0x01, //成功
    SRBLEControlResultCode_EXE                  = 0x02, //正在执行
    SRBLEControlResultCode_Fail                 = 0x03, //失败（通用）
    SRBLEControlResultCode_Fail_CANCEL          = 0x04, //失败（取消）
    SRBLEControlResultCode_Fail_DELAY           = 0x05, //失败（延时执行）
    SRBLEControlResultCode_Fail_UNSUPPORT       = 0x06, //失败（设备不支持）
    SRBLEControlResultCode_Fail_TIMOUT          = 0x07, //失败（有效期超时）
    SRBLEControlResultCode_Fail_CONFIG          = 0x08, //失败（配置不支持）
    SRBLEControlResultCode_Fail_PARAM           = 0x09, //失败（参数非法）
    SRBLEControlResultCode_Fail_BUSY            = 0x0A, //失败（系统繁忙）
    SRBLEControlResultCode_Fail_STATE           = 0x0B, //失败（状态不支持）
    SRBLEControlResultCode_Fail_DUPCMD          = 0x0C, //失败（指令正在执行时再次接收相同指令）
    SRBLEControlResultCode_Fail_DUPSTATE        = 0x0D, //失败（状态已更新）
    SRBLEControlResultCode_Fail_START_ON        = 0x0E, //失败（启动检测到状态ON）
    SRBLEControlResultCode_Fail_START_OPEN      = 0x0F, //失败（启动检测到门开）
    SRBLEControlResultCode_Fail_START_WIN       = 0x10, //失败（启动检测到升窗）
    SRBLEControlResultCode_Fail_START_WASH      = 0x11, //失败（启动检测到洗车模式）
    SRBLEControlResultCode_Fail_STOP_ON         = 0x12, //失败（熄火检测到档位ON）
    SRBLEControlResultCode_Fail_STOP_DRIVE      = 0x13, //失败（熄火检测到行驶）
    SRBLEControlResultCode_Fail_PANIC_ON        = 0x14, //失败（寻车检测到状态ON）
    SRBLEControlResultCode_Fail_LOCK_OPEN       = 0x15, //失败（关锁检测到门开）
    SRBLEControlResultCode_Fail_START_UNLK      = 0x16, //失败（PPKE解锁禁止遥控启动）
    SRBLEControlResultCode_Fail_STOP_GERA       = 0x17, //失败（熄火检测到档位非P档）
    SRBLEControlResultCode_Fail_STOP_MANUAL     = 0x18, //失败（熄火检测到手动启动）
    SRBLEControlResultCode_Fail_BTK_ID          = 0x19, //失败（钥匙错误）
    SRBLEControlResultCode_Fail_BTK_SEQ         = 0x1A, //失败（滚动码错误）
    SRBLEControlResultCode_Fail_Vehicle_Unkown  = 0x1B, //失败（车型拨码错误）
    SRBLEControlResultCode_Fail_App_Unsupport   = 0x1C, //失败（业务不支持）
    SRBLEControlResultCode_Fail_STOP_LF_CLOSE   = 0x1D, //失败（熄火时必须打开主门）
    
    SRBLEControlResultCode_Fail_BTK_AUTH        = 0x1E, //失败:蓝牙签权错误
    SRBLEControlResultCode_Fail_PKE_OFF         = 0x1F, //失败:在off状态下遥控启动
    SRBLEControlResultCode_Fail_OTA_PAUSE       = 0x20, //失败:升级暂停
    SRBLEControlResultCode_Fail_CRC_ERROR       = 0x21, //失败:CRC错误
    SRBLEControlResultCode_Fail_FLASH_WRITE_ERR = 0x22, //失败:写FLASH失败
    SRBLEControlResultCode_Fail_RESET_1         = 0x23, //失败:升级期间重启
    SRBLEControlResultCode_Fail_RESTIMEOUT      = 0x24, //失败:接收超时达到最大次数
    SRBLEControlResultCode_Fail_CRC_ERROR_FRAG  = 0x25, //错误:B808返回的片校验与B806返回的片校验不一致
    SRBLEControlResultCode_Fail_CRC_DATA        = 0x26, //错误:上传将要写入的FLASH 的片校验
    SRBLEControlResultCode_Fail_RX_CRC          = 0x27, //错误:接收数据CRC错误
    SRBLEControlResultCode_Fail_SET             = 0x28, //错误:参数设置1
    SRBLEControlResultCode_Fail_RESET_2         = 0x29, //错误:参数清零
    SRBLEControlResultCode_Fail_UPDATE_ERR_ON   = 0x2A, //错误:在ON档在线升级
    SRBLEControlResultCode_Fail_BKOPEN_ON       = 0x2B, //错误:ON无法开启后备箱
    SRBLEControlResultCode_Fail_KEYFIND_OK      = 0x2C, //结果:找到遥控器
    SRBLEControlResultCode_Fail_KEYFIND_FAIL    = 0x2D, //结果:未找到遥控器
    SRBLEControlResultCode_Fail_BLOCK_ERASE_FINISHED    = 0x2E,//结果:块擦除完成
};



//蓝牙连接状态
typedef NS_ENUM(UInt16, FZKBLEConnectStatus) {
    FZKBLEConnectSuccess   = 0,
    FZKBLELoginSuccess     = 1,
    FZKBLEDisconnected     = 2,
};



#endif
