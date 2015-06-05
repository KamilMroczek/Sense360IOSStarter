//
//  ViewController.swift
//  Sense360Starter
//
//  Created by Kamil M on 6/2/15.
//  Copyright (c) 2015 Sense360. All rights reserved.
//

import UIKit
import SenseSdk

class ViewController: UIViewController {

    @IBOutlet weak var triggerButton: UIButton!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    
    @IBAction func triggerPressed(sender: UIButton) {
        //Create a fake restaurant
        let place = PoiPlace(latitude: 34.111, longitude: -118.111, radius: 50, name: "Big Restaurant", id: "id1", types: [.Restaurant])

        let errorPointer = SenseSdkErrorPointer.create()
        // This method should only be used for testing
        SenseSdkTestUtility.fireTrigger(
            fromRecipe: "ArrivedAtRestaurant",
            confidenceLevel: ConfidenceLevel.Medium,
            places: [place],
            errorPtr: errorPointer
        )

        if errorPointer.error != nil {
            NotificationSender.send("Error sending trigger")
        }
    }
}

