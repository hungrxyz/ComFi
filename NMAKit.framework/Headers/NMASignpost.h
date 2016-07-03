/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

#import <UIKit/UIKit.h>

@class NMAImage;


/**
 * \class NMASignpost NMASignpost.h "NMASignpost.h"
 *
 *  Represents a signpost information for navigation (both audible and
 * graphical/textual navigation) and map display.
 */
@interface NMASignpost : NSObject

/**
 *  The foreground/text color of the exit icon for the signpost.
 */
@property (nonatomic, readonly) UIColor *foregroundColor;

/**
 *  The background color of the exit icon for the signpost
 */
@property (nonatomic, readonly) UIColor *backgroundColor;

/**
 *  An array of exit directions applicable to the signpost, defined
 * as NMASignpostLocalizedLabel objects.
 *
 * \sa NMASignpostLocalizedLabel
 */
@property (nonatomic, readonly) NSArray *exitDirections;

/**
 *  The exit icon of the signpost.
 */
@property (nonatomic, readonly) NMAImage *exitIcon;

/**
 *  The exit number of the signpost.
 */
@property (nonatomic, readonly) NSString *exitNumber;

/**
 *  The exit text of the signpost.
 */
@property (nonatomic, readonly) NSString *exitText;

@end

/** @} */
