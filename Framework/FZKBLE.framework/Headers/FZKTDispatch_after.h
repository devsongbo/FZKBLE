//
//  FZKTDispatch_after.h
//  Connector
//
//  Created by czl on 2017/5/20.
//  Copyright © 2017年 chinapke. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FZKTDispatch_after : NSObject




/**
 延迟操作，如果在延迟时间timer内的操作就忽略，否则就执行
 
 @param timer 延迟操作
 @param block 回调
 */
- (void)runDispatch_after:(NSTimeInterval)timer block:(dispatch_block_t)block;

@end
