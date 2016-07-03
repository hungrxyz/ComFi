//
//  Geocoder.swift
//  ComFi
//
//  Created by Zel Marko on 7/3/16.
//  Copyright © 2016 Zel Marko. All rights reserved.
//

import Foundation
import CoreLocation

class Geocoder {
	
	func geocode(address: String, placemark: CLPlacemark? -> ()) {
		CLGeocoder().geocodeAddressString(address) { (placemarks, error) in
			guard let placemarks = placemarks else {
				print(error)
				placemark(nil)
				return
			}
			
			placemark(placemarks.first!)
		}
	}
}