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
	
	@IBOutlet weak var blurView: UIVisualEffectView!
	@IBOutlet weak var startAddressTextField: UITextField!
	@IBOutlet weak var destinationAddressTextField: UITextField!
	@IBOutlet weak var goButton: UIButton!
	
	override func viewDidLoad() {
		super.viewDidLoad()
		
		LocationManager.sharedManager.viewController = self
		LocationManager.sharedManager.getCurrentLocation()
		
		view.addGestureRecognizer(UITapGestureRecognizer(target: self, action: #selector(resignFirstResponder)))
	}
	
	override func resignFirstResponder() -> Bool {
		return true
	}
	
	override func viewWillAppear(animated: Bool) {
		super.viewWillAppear(animated)
		
//		var coordinates: NMAGeoCoordinates
//		coordinates = NMAGeoCoordinates(latitude: 49.258867, longitude: -123.008046)
//		mapView.zoomLevel = 13.2
//		mapView.setGeoCenter(coordinates, withAnimation: .Linear)
//		mapView.copyrightLogoPosition = .BottomCenter
		
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
		performSegueWithIdentifier("transitSegue", sender: self)
	}
}

extension ViewController: UITextFieldDelegate {
	func textFieldDidEndEditing(textField: UITextField) {
		textField.resignFirstResponder()
		
		if textField == startAddressTextField {
			// Nothing
		} else {
			Geocoder().geocode(textField.text!, placemark: { (placemark) in
				if let placemark = placemark {
					LocationManager.sharedManager.destinationAddress = placemark
					print(placemark)
				}
			})
		}
	}
}

