//
//  TransitViewController.swift
//  ComFi
//
//  Created by Zel Marko on 7/3/16.
//  Copyright © 2016 Zel Marko. All rights reserved.
//

import UIKit

class TransitViewController: UIViewController {
	
	@IBOutlet weak var tableView: UITableView!
	
	override func viewDidLoad() {
		super.viewDidLoad()
		
		// Do any additional setup after loading the view.
	}
	
	override func didReceiveMemoryWarning() {
		super.didReceiveMemoryWarning()
		// Dispose of any resources that can be recreated.
	}
	
	let arr = [["U6 -> 12", "22ºC", 1, 2], ["U2", "29ºC", 2, 1], ["248 -> U2", "32ºC", 2, 2]]
	
	
	/*
	// MARK: - Navigation
	
	// In a storyboard-based application, you will often want to do a little preparation before navigation
	override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
	// Get the new view controller using segue.destinationViewController.
	// Pass the selected object to the new view controller.
	}
	*/
	
}

extension TransitViewController: UITableViewDataSource {
	
	func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
		return arr.count
	}
	
	func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
		let cell = tableView.dequeueReusableCellWithIdentifier("Cell", forIndexPath: indexPath) as! Cell
		
		cell.statusLabel.text = arr[indexPath.row][0] as? String
		cell.tempLabel.text = arr[indexPath.row][1] as? String
		
		if arr[indexPath.row][2] == 1 {
			cell.temperatureImageView.image = UIImage(named: "cold")!
		} else {
			cell.temperatureImageView.image = UIImage(named: "hot")!
		}
		
		if arr[indexPath.row][3] == 1 {
			cell.soundImageView.image = UIImage(named: "silent")!
		} else {
			cell.soundImageView.image = UIImage(named: "noise")!
		}
		
		return cell
	}
}
