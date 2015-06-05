//
//  AppDelegate.m
//  Sense360StarterObjC
//
//  Created by dan bright on 6/4/15.
//  Copyright (c) 2015 Sense360. All rights reserved.
//

#import "AppDelegate.h"
#import "EnteredRestaurantCallback.h"
@import SenseSdk;

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    [SenseSdk enableSdkWithKey:@"app_key_goes_here"];

    SenseSdkErrorPointer *errorPointer = [SenseSdkErrorPointer create];
    
    Trigger *restaurantTrigger = [FireTrigger whenEntersPoi:PoiTypeRestaurant errorPtr:errorPointer];
    
    if(restaurantTrigger != nil) {
        Recipe *recipe = [[Recipe alloc] initWithName: @"EnteredRestaurant"
                        trigger:restaurantTrigger
                        timeWindow: [TimeWindow allDay]
                        cooldown: [Cooldown defaultCooldown]];
        
        EnteredRestaurantCallback *callback = [EnteredRestaurantCallback alloc];
        [SenseSdk registerWithRecipe:recipe delegate:callback errorPtr:nil];
    }
    [self logErrors:errorPointer];
    
    //...Any other code that should run on launch...//
    
    return YES;
}

//Log any errors that occured during while registering your recipe//
- (void)logErrors:(SenseSdkErrorPointer *)pointer {
    if ([pointer error] != nil) {
        NSLog(@"%@", [[pointer error] message]);
    }
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end
