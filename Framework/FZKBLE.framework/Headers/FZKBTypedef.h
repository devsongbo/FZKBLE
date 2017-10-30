//
//  FZKBTypedef.h
//  Pods
//
//  Created by work on 2017/9/14.
//
//

#ifndef FZKBTypedef_h
#define FZKBTypedef_h
#import "SRBLEReceivedData.h"
typedef void (^CompleteBlock) (NSError *error, id responseObject);
typedef void (^QueryBlock) (NSError *error, NSArray* items);
typedef BOOL (^MsgBlock) (NSError *error, SRBLEReceivedData* items);
typedef void (^VoidBlock) ();

#endif /* FZKBTypedef_h */
