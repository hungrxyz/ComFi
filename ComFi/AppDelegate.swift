//
//  AppDelegate.swift
//  ComFi
//
//  Created by Zel Marko on 7/3/16.
//  Copyright © 2016 Zel Marko. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

	var window: UIWindow?


	func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
		
		NMAApplicationContext.setAppId("2Ne6RtAFpczsbvwY0aCe", appCode: "LWFIttIyuB7wIKJ0q6Z_GQ", licenseKey: "TPSoNdfTyBhaCChl5JXaaEQigcRBt6jCWcohfCzS6+sfljHfzQsY622D/v16ib6w8imNBryG4eQoT/fZgkualzgKxa/KIE3MbEBcaqezgURaxFY7Z1WY9Pxn/+VNbFWoP/5pX/wDIAbl7QYwYlH6c46VgSkACpkR5WGKUAEQYRI3E0jhhpl9lOr48jj1+idvjaS4VOb/LgzwoWVQibu6ChO1kiD/jIn47fkw4Ny6Tjyc3OS9qitMO+WM5WULjptk6X/pl0a61/BHBkW35hIWEK2f6yr00w9qYhNsr31ux/fCWyQunlS3I1T4rVuqle8RsX7w3FYtTvnPpLHbm+FMKVYQqcI7daV+5HCE7HaYLOzVyX5MIlT1B9+/jhPkCqmtqHjepo9AAwi+2ZX+qqJ7I1P9arxCtS330T2eaFMw+R2fez7iQc9sgnvmhrJSzmKgafB2V3Re1VWiu7uZyFVmIVxeNWJFQDkNYhNAUYFOzCCDgPQMQNBTW2/zUcjJMVG/sY1vQsAoAAz5F9ctk85VHYopl0ygzrPTPxmE7ua9Qqu+n5g3ta7+z9/0y4Dl4NBEbiTQWPLAYYBjcpcKkjzwmC45xhSSzLRtSaAO5hKP35scwQDs/GcFVftiqOMhCGft3iweXGD2+WLBv2VZtzJT8ZqJqh0D9N9xdq78s4nsz6c=")
		
		return true
	}

	func applicationWillResignActive(application: UIApplication) {
		// Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
		// Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
	}

	func applicationDidEnterBackground(application: UIApplication) {
		// Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
		// If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
	}

	func applicationWillEnterForeground(application: UIApplication) {
		// Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
	}

	func applicationDidBecomeActive(application: UIApplication) {
		// Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
	}

	func applicationWillTerminate(application: UIApplication) {
		// Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
	}


}

