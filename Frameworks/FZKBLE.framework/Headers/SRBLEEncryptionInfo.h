//
//  SRBLEEncryptionInfo.h
//  Mizward
//
//  Created by zhangjunbo on 15/9/10.
//  Copyright (c) 2015年 Mizward. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
@interface SRBLEEncryptionInfo : NSObject

@property (nonatomic, copy) NSString *idStr;
@property (nonatomic, copy) NSString *keyCRC;

- (instancetype)initWithParameters:(NSArray *)parameters;

- (BOOL)isIdStrCorrect:(NSString *)idStr;
- (BOOL)isKeyCorrect:(NSString *)keyStr;

@end
