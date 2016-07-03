/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAMapObject.h"

@class NMAGeoCoordinates;
@class UIColor;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */


/**
 * \class NMAMapCircle NMAMapCircle.h "NMAMapCircle.h"
 * Represents a NMAMapObject in the shape of a circle. %NMAMapCircle is helper
 * class for creating and updating a NMAMapPolygon representing a circle.
 */
@interface NMAMapCircle : NMAMapObject

/**
 * A convenience method to construct a NMAMapCircle at specified coordinates.
 *
 * \param coordinates The location of the map circle center
 */
+ (id)mapCircleWithGeoCoordinates:(NMAGeoCoordinates *)coordinates;

/**
 * A convenience method to construct a NMAMapCircle at specified coordinates
 * and with a given radius.
 *
 * \param coordinates The location of the map circle center
 * \param radius The radius (in meters) of the map circle
 */
+ (id)mapCircleWithGeoCoordinates:(NMAGeoCoordinates *)coordinates radius:(double)radius;

/**
 * The %NMAGeoCoordinates representing the center of the %NMAMapCircle.
 *
 * \note The NMAViewObject location property will return the same coordinates.
 */
@property (nonatomic, strong) NMAGeoCoordinates *center;

/**
 * The radius of the %NMAMapCircle, in meters.
 *
 * \note The default value is 1 meter
 */
@property (nonatomic) double radius;

/**
 * The line color for the %NMAMapCircle.
 *
 * \note The default value (in RGBA) is 0xC00066AA
 */
@property (nonatomic, strong) UIColor *lineColor;

/**
 * The fill color for the %NMAMapCircle.
 *
 * \note The default value (in RGBA) is 0x00498A55
 */
@property (nonatomic, strong) UIColor *fillColor;

/**
 * The line width, in pixels, for the %NMAMapCircle border. The supported
 * value range is [1..100].
 *
 * \note The default value is 0 pixels
 */
@property (nonatomic) NSUInteger lineWidth;

/**
 * Indicates whether to render the %NMAMapCircle with depth test.
 *
 * \note Rendering with depth test should be used if map object altitude
 * is relevant in your application. Rendering objects with different
 * heights while disabling depth test may cause object occlusion.
 */
@property (nonatomic) BOOL depthTestEnabled;

/**
 * Initializes a %NMAMapCircle instance with the specified %NMAGeoCoordinates
 * as the center and a radius of 1 meter.
 *
 * \param coordinates A %NMAGeoCoordinates representing the %NMAMapCircle center
 * \return The %NMAMapCircle
 */
- (id)initWithGeoCoordinates:(NMAGeoCoordinates *)coordinates;

/**
 * Initializes a %NMAMapCircle instance with the specified %NMAGeoCoordinates
 * as the center and the specified \p double as the radius (in meters).
 *
 * \param coordinates  A %NMAGeoCoordinates representing the %NMAMapCircle center
 * \param radius The radius of the circle
 * \return The %NMAMapCircle
 */
- (id)initWithGeoCoordinates:(NMAGeoCoordinates *)coordinates radius:(double)radius;

@end
/** @}  */
