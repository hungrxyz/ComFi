/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIColor.h>

#import "NMAMapObject.h"

@class NMARoute;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */


/**
 * \class NMAMapRoute NMAMapRoute.h "NMAMapRoute.h"
 *
 * \brief Represents a NMAMapObject in the shape of a route that can be displayed on a map.
 *
 * In order to display the route object on the map, the route object needs to be added to
 * an NMAMapView by calling addMapObject:.
 *
 * The NMAViewObject location property for a NMAMapRoute returns the coordinates of the
 * first waypoint.
 *
 * \sa NMARoute
 */
@interface NMAMapRoute : NMAMapObject

/**
 * A convenience constructor for NMAMapRoute.
 *
 * This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * \param route The route object from which to construct the NMAMapRoute.
 */
+ (instancetype)mapRouteWithRoute:(NMARoute *)route;

/**
 * Use mapRouteWithRoute to instantiate a NMAMapRoute.
 */
- (instancetype)init UNAVAILABLE_ATTRIBUTE;

/**
 * Indicates whether the maneuver number is displayed on the %NMAMapRoute.
 */
@property (nonatomic) BOOL maneuverNumberDisplayed;

/**
 * The %UIColor representing the color of the %NMAMapRoute.
 *
 * \note Alpha-value transparency is supported and will also be set when setting this
 * property.
 *
 * \return The user-defined route color if user has set route color. Otherwise,
 * the default color for %NMAMapRoute.
 */
@property (nonatomic, strong) UIColor *color;

/**
 * The NMARoute represented by the NMAMapRoute.
 */
@property (nonatomic, strong) NMARoute *route;

/*
 * Indicates whether the route object is displaying traffic information.
 *
 * YES will display traffic if the following are set: [NMAMapView setTrafficVisible:YES] and
 * [NMAMapView showTrafficLayers:NMATrafficLayerOnRoute]. NO will hide traffic on route rendering
 * for this route. By default traffic on route is disabled.
 *
 * \note Truck routes and public transport timetable routes are not supported.
 */
@property (nonatomic, getter = isTrafficEnabled) BOOL trafficEnabled;

@end

/** @}  */
