//
//  StatusItem.h
//  Pods
//
//  Created by 马宁 on 2017/8/28.
//
//

#import <Foundation/Foundation.h>
#import "SRBLEEnum.h"

@interface StatusItem : NSObject

@property (nonatomic,assign) BLEStatusKey key;
@property (nonatomic,assign) NSInteger status;
@property (nonatomic,copy)   NSString* value;


-(BOOL) isValid;

+(StatusItem*) build:(BLEStatusKey)key  hexValue:(NSString*)value;

+(StatusItem*) build:(BLEStatusKey)key  StatusAndhexValue:(NSArray*)array;

-(NSInteger) getIntValue;

-(double)  getDoubleValue;


@end
