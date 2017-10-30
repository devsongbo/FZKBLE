//
//  SRBLEVehicleStatus.h
//  Mizward
//
//  Created by zhangjunbo on 15/8/27.
//  Copyright (c) 2015年 Mizward. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SRBLEVehicleStatus : NSObject

@property (nonatomic, assign) NSInteger acc;
@property (nonatomic, assign) NSInteger on;
@property (nonatomic, assign) NSInteger engine;
@property (nonatomic, assign) NSInteger run;
@property (nonatomic, assign) NSInteger doorLF;
@property (nonatomic, assign) NSInteger doorRF;
@property (nonatomic, assign) NSInteger doorLB;
@property (nonatomic, assign) NSInteger doorRB;
@property (nonatomic, assign) NSInteger trunkDoor;
@property (nonatomic, assign) NSInteger doorLockLF;
@property (nonatomic, assign) NSInteger doorLockRF;
@property (nonatomic, assign) NSInteger doorLockLB;
@property (nonatomic, assign) NSInteger doorLockRB;
@property (nonatomic, assign) NSInteger windowLF;
@property (nonatomic, assign) NSInteger windowRF;
@property (nonatomic, assign) NSInteger windowLB;
@property (nonatomic, assign) NSInteger windowRB;
@property (nonatomic, assign) NSInteger windowSky;
@property (nonatomic, assign) NSInteger lightBig;
@property (nonatomic, assign) NSInteger lightSmall;

- (instancetype)initWithParameters:(NSArray *)parameters;

- (NSInteger)lock;

- (NSInteger)door;

@end
