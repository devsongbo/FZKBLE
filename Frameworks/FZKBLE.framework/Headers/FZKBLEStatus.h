//
//  SRBLENewVehicleStatus.h
//  FZKBLEDemo
//
//  Created by songbo on 29/08/2017.
//  Copyright © 2017 SONG. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FZKBLEStatus : NSObject


@property (nonatomic, assign) NSInteger acc;       //ACC档位
@property (nonatomic, assign) NSInteger on;        //ON档位
@property (nonatomic, assign) NSInteger engine;    //引擎
@property (nonatomic, assign) NSInteger lock;      //锁
@property (nonatomic, assign) NSInteger door;      //门边
@property (nonatomic, assign) NSInteger trunckDoor;//后备箱
@property (nonatomic, assign) NSInteger window;    //窗
@property (nonatomic, assign) NSInteger skyWindow; //天窗
@property (nonatomic,   copy) NSString *mileage;   //里程
@property (nonatomic,   copy) NSString *leftoil;   //剩余油量百分比
@property (nonatomic,   copy) NSString *leftelec;  //剩余电量百分比
@property (nonatomic,   copy) NSString *voatge;    //电压值


-(void)initWithStatusArray:(NSArray *)arr;





@end
