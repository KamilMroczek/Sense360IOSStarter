//
//  ViewController.m
//  Sense360StarterObjC
//
//  Created by dan bright on 6/4/15.
//  Copyright (c) 2015 Sense360. All rights reserved.
//

#import "ViewController.h"
#import "NotificationSender.h"
@import SenseSdk;

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UIButton *btnTrigger;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)triggerPressed:(UIButton *)sender {
    //Create a fake restaurant

    PoiPlace* poiPlace = [[PoiPlace alloc] initWithLatitude:34.111
                             longitude:-118.111
                                radius:50
                                  name:@"Big Restaurant"
                                    id:@"id1"
                                  type: PoiTypeRestaurant];
    SenseSdkErrorPointer* errorPtr = [SenseSdkErrorPointer create];
    
    // This method should only be used for testing
    NSArray* places = [[NSArray alloc] initWithObjects:poiPlace, nil];
    [SenseSdkTestUtility fireTriggerFromRecipe:@"ArrivedAtRestaurant"
                               confidenceLevel:ConfidenceLevelMedium
                                        places:places
                                      errorPtr:errorPtr];
    if(errorPtr.error != nil) {
        [NotificationSender send:@"Error sending trigger"];
    }
}

@end
