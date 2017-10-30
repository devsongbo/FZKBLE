//
//  BleRequest.h
//  Pods
//
//  Created by 马宁 on 2017/8/28.
//
//

#import <Foundation/Foundation.h>
#import "SRBLESendData.h"
#import "SRBLEReceivedData.h"
#import "FZKBTypedef.h"

@interface BleRequest : NSObject


@property MsgBlock callback;
@property BOOL isFinished;

-(void) handleMsg:(SRBLEReceivedData*)msg error:(NSError*)error;

-(void) iniWithCallback:(MsgBlock)callback  timeOut:(NSTimeInterval)timeOut;

@end
