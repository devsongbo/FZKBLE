//
//  FZKTBleControlCallBack.h
//  Connector
//
//  Created by czl on 2017/5/19.
//  Copyright © 2017年 chinapke. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FZKBTypedef.h"

@interface FZKTBleControlCallBack : NSObject


@property (nonatomic,copy) CompleteBlock serialNumber502;//502流水号操作

@property (nonatomic,copy) CompleteBlock control402; //402控制操作回调

@property (nonatomic,copy) CompleteBlock timeOutFail;//超时操作回调

@property (nonatomic,assign) BOOL isRun502; //是否已经执行502

@property (nonatomic,assign) BOOL isRun402; //是否已经执行402

@end
