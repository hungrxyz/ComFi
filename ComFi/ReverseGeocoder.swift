//
//  Geocoder.swift
//  ComFi
//
//  Created by Zel Marko on 7/3/16.
//  Copyright © 2016 Zel Marko. All rights reserved.
//

import Foundation
import CoreLocation

class ReverseGeocoder {
	
	func reverseGeocodeLocation(location: CLLocation, placemark: CLPlacemark? -> ()){
		CLGeocoder().reverseGeocodeLocation(location) { (placemarks, error) in
			guard let placemarks = placemarks else {
				print(error)
				return
			}
			placemark(placemarks.first!)
		}
		placemark(nil)
	}
}
