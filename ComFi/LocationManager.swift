//
//  LocationManager.swift
//  ComFi
//
//  Created by Zel Marko on 7/3/16.
//  Copyright © 2016 Zel Marko. All rights reserved.
//

import Foundation
import CoreLocation

class LocationManager: NSObject, CurrentLocationProtocol, CLLocationManagerDelegate {
	
	static let sharedManager = LocationManager()
	
	var locationManager: CLLocationManager!
	
	override init() {
		super.init()
		self.locationManager = CLLocationManager()
		self.locationManager.delegate = self
	}

	func getCurrentLocation() {
		switch CLLocationManager.authorizationStatus() {
		case .AuthorizedAlways, .AuthorizedWhenInUse:
			locationManager.requestLocation()
		default:
			locationManager.requestWhenInUseAuthorization()
		}
  }
	
	@objc func locationManager(manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
		print(locations)
	}
	
	func locationManager(manager: CLLocationManager, didChangeAuthorizationStatus status: CLAuthorizationStatus) {
		if status == .AuthorizedWhenInUse || status == .AuthorizedAlways {
			locationManager.requestLocation()
		}
	}
	
	func locationManager(manager: CLLocationManager, didFailWithError error: NSError) {
		print(error)
	}
}
