//
//  Cell.swift
//  ComFi
//
//  Created by Zel Marko on 7/3/16.
//  Copyright © 2016 Zel Marko. All rights reserved.
//

import UIKit

class Cell: UITableViewCell {
	
	@IBOutlet weak var statusLabel: UILabel!
	@IBOutlet weak var tempLabel: UILabel!
	@IBOutlet weak var temperatureImageView: UIImageView!
	@IBOutlet weak var soundImageView: UIImageView!
	
	override func awakeFromNib() {
		super.awakeFromNib()
		// Initialization code
	}
	
	override func setSelected(selected: Bool, animated: Bool) {
		super.setSelected(selected, animated: animated)
		
		// Configure the view for the selected state
	}
	
}
