/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */


/**
 * \class NMAZoomRange NMAZoomRange.h "NMAZoomRange.h"
 *
 * Represents a Zoom Range. Used to specify at which zoom level(s) a property customization
 * is to be applied.
 */
@interface NMAZoomRange : NSObject
@property (nonatomic) float min;
@property (nonatomic) float max;

/**
 * Helper initializer for a %NMAZoomRange.
 *
 * \note If minimum and/or maximum exceeds the available range, the value will be clipped.
 */
- (id)initWithMinZoomLevel:(float)minimum maxZoomLevel:(float)maximum;
@end
/** @}  */
