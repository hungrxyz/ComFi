//
//  ViewController.swift
//  ComFi
//
//  Created by Zel Marko on 7/3/16.
//  Copyright © 2016 Zel Marko. All rights reserved.
//

import UIKit
import Alamofire
import SwiftyJSON

class ViewController: UIViewController {

	@IBOutlet weak var mapView: NMAMapView!
	
	var mapCircle: NMAMapObject!
	
	@IBOutlet weak var blurView: UIVisualEffectView!
	@IBOutlet weak var startAddressTextField: UITextField!
	@IBOutlet weak var destinationAddressTextField: UITextField!
	@IBOutlet weak var goButton: UIButton!
	
	override func viewDidLoad() {
		super.viewDidLoad()
		
		LocationManager.sharedManager.getCurrentLocation()
	}
	
	override func viewWillAppear(animated: Bool) {
		super.viewWillAppear(animated)
		
//		var coordinates: NMAGeoCoordinates
//		coordinates = NMAGeoCoordinates(latitude: 49.258867, longitude: -123.008046)
//		mapView.zoomLevel = 13.2
//		mapView.setGeoCenter(coordinates, withAnimation: .Linear)
//		mapView.copyrightLogoPosition = .BottomCenter
		addMapCircle()
		
//		Alamofire.request(.GET,
//			"https://cit.transit.api.here.com/metarouter/rest/routeservice/v2/route.json?app_id=2Ne6RtAFpczsbvwY0aCe&app_code=LWFIttIyuB7wIKJ0q6Z_GQ&routing=all&graph=0&startX=-74.04716491699219&startY=40.74413568925235&destX=-74.03789520263672&destY=40.73906330729812&time=2016-09-22T14:21:24&forward=1&details=0",
//			parameters: nil,
//			encoding: .JSON).responseJSON { response in
//				guard let value = response.result.value else {
//					print(response.result.error!)
//					return
//				}
//				
//				let json = JSON(value)
//				print(json)
//		}
	}
	@IBAction func goButtonTapped(sender: AnyObject) {
	}

	func addMapCircle() {
		if mapCircle == nil {
			let coordinates: NMAGeoCoordinates = NMAGeoCoordinates(latitude: 49.258867, longitude: -123.008046)
			mapCircle = NMAMapCircle(geoCoordinates: coordinates, radius: 50)
			mapView.addMapObject(mapCircle)
		}
		NMARouteManager.sharedRouteManager().delegate = self
		print(NMARouteManager.sharedRouteManager().calculateRouteWithStops([NMAGeoCoordinates(latitude: 52.506566, longitude: 13.450109), NMAGeoCoordinates(latitude: 52.546563, longitude: 13.514349)]))
	}
}

extension ViewController: NMARouteManagerDelegate {
	func routeManager(routeManager: NMARouteManager!, didCalculateRoutes routes: [AnyObject]!, withError error: NMARouteManagerError, violatedOptions: [AnyObject]!) {
//		print(routes)
		if routes != nil && !routes.isEmpty {
			mapView.mapScheme = NMAMapSchemeNormalDayWithTraffic
			mapView.setBoundingBox((routes.first as! NMARoute).boundingBox, withAnimation: .Bow)
		} else {
			print("No routes")
		}
	}
}

