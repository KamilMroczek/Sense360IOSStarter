//
//  EnteredRestaurantCallback.m
//  Sense360Starter
//
//  Created by dan bright on 6/4/15.
//  Copyright (c) 2015 Sense360. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EnteredRestaurantCallback.h"
@import SenseSdk;

@interface EnteredRestaurantCallback ()
@end

@implementation EnteredRestaurantCallback
- (void)onTriggerFired:(TriggerFiredArgs*) args {
    //Your user has entered a restaurant!//
    NSLog(@"Recipe %@ fired at %@.", [[args recipe] name], [args timestamp]);
}
@end