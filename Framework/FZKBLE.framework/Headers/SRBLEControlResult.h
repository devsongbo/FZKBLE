//
//  SRBLEControlResult.h
//  Mizward
//
//  Created by zhangjunbo on 15/9/10.
//  Copyright (c) 2015年 Mizward. All rights reserved.
//


#import "SRBLEEnum.h"

@interface SRBLEControlResult : NSObject

@property (nonatomic, assign) SRBLEInstruction instruction;
@property (nonatomic, assign) SRBLEControlResultCode resultCode;

- (instancetype)initWithParameters:(NSArray *)parameters;

- (BOOL)isSuccess;

- (NSString *)resultString;

@end
