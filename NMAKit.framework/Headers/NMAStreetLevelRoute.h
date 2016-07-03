/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAStreetLevelObject.h"
#import "NMATypes.h"
#import <UIKit/UIKit.h>


/**
 * \addtogroup NMA_Streetlevel NMA Street Level Group
 * @{
 */

@class NMARoute;


/**
 * \class NMAStreetLevelRoute NMAStreetLevelRoute.h "NMAStreetLevelRoute.h"
 *
 * NMAStreetLevelRoute provides a visual representation of an NMARoute
 * inside an NMAStreetLevelView.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMAStreetLevelRoute : NMAStreetLevelObject

/**
 * A convenience method to construct an NMAStreetLevelRoute from an NMARoute.
 *
 * \param route The NMARoute from which to create the NMAStreetLevelRoute.
 */
+ (id)streetLevelRouteWithRoute:(NMARoute *)route;

/**
 * The NMARoute object represented by the NMAStreetLevelRoute.
 */
@property (nonatomic) NMARoute *route;

/**
 * The NMARouteDisplayType of the NMAStreetLevelRoute.
 */
@property (nonatomic) NMARouteDisplayType displayType;

/**
 * The color of the NMAStreetLevelRoute. If the color is changed, the
 * displayType of the route will be set to NMARouteDisplayTypeUserDefined.
 */
@property (nonatomic) UIColor *color;

/**
 * Initializes an %NMAStreetLevelRoute instance with the
 * specified %NMARoute.
 *
 * \param route The %NMARoute to be displayed in a %NMAStreetLevelView
 * \return The %NMAStreetLevelRoute
 */
- (id)initWithRoute:(NMARoute *)route;

@end
/**  @}  */
