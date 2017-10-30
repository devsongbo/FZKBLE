//
//  BleStatusManager.h
//  Pods
//
//  Created by 马宁 on 2017/8/29.
//
//

#import <Foundation/Foundation.h>
#import "SRBLEReceivedData.h"
#import "StatusItem.h"
@interface BleStatusManager : NSObject

@property (nonatomic,strong) NSMutableDictionary* statusDic;
@property (nonatomic,strong) NSMutableDictionary* sk2tagDic;

-(void) clear;

-(NSArray*) parseReceiveData:(SRBLEReceivedData*)msg;

-(StatusItem*) getFromKey:(BLEStatusKey)key;

-(NSArray*)    getFromTag:(SRBLEOperationInstruction)tag;

@end
