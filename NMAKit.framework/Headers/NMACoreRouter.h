/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMARouter.h"
#import "NMARouteManager.h"

@class NMARouteResult;
@class NMARoutingMode;

/**
 * \brief A completion block used to handle the result of a route request.
 *
 * \param routeResult The result of the routing calculation (can be nil if %NMARoutingError
 * error param is not %NMARoutingErrorNone)
 *
 * \param error A routing calculation error.
 * See %NMARoutingError for possible error codes. If
 * %NMARoutingErrorRouteUseDisabledRoads is returned then
 * \p violatedOptions is not empty (the returned NMARoute is valid
 * and can be used for navigation although it uses roads which were
 * disabled in the original NMARoutingMode::routingOptions options).
 */
typedef void(^NMACalculateResultBlock)(NMARouteResult *routeResult, NMARoutingError error);


/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * Route calculation executor handling core routing types (Car, Truck, Pedestrian). Defines
 * concrete calculation method and response listener for core routing types.
 *
 * <p>NMACoreRouter requires valid authentication credentials to be set via
 * NMAApplicationContext. If valid credentials are not present the API may not
 * function correctly or may stop functioning correctly in the future when server
 * side configurations change.</p>
 *
 * <p>Routing within China is supported, but routes may not cross the Chinese border.
 * Thus, any route calculation which begins, ends, or passes through China and involves
 * one or more other countries will fail.</p>
 *
 * \note It is possible for an NMACoreRouter request to return a route that can't be
 * followed; for example, a route that is blocked by a traffic accident or construction
 * work. These conditions will likely be reported if the traffic feature is available
 * and enabled for routing, but they may not be in all cases. Appropriate caution should
 * always be exercised when using routes provided by NMACoreRouter.
 */
@interface NMACoreRouter : NMARouter

/**
 * \brief Starts a route calculation with the given stop list and %NMARoutingMode.
 *
 * <p>This method returns nil and a route will not be calculated if access to this
 * operation is denied. Contact your HERE representative for more information.</p>
 *
 * <p>
 * The array of stops used to calculate the route must have at least two items. Any of
 * the following may be included in any combination:
 * <ol>
 * <li> NMAPlace
 * <li> NMAPlaceLocation
 * <li> NMAWaypoint
 * </ol>
 * </p>
 *
 * \param stops A list of stops to route between, maximum 32 stops. If the first stop or
 * the last stop is of %NMAWaypoint, their waypointType must be of %NMAStopWaypoint type.
 *
 * \param mode The %NMARoutingMode to use for route calculation.
 *
 * \param completion The %NMACalculateResultBlock used to handle the result of a route request.
 *
 * \return %NSProgress if route calculation is successfully started, nil otherwise.
 */
- (NSProgress *)calculateRouteWithStops:(NSArray *)stops routingMode:(NMARoutingMode *)mode completionBlock:(NMACalculateResultBlock)completion;

/**
 * Indicate the dynamic penalty that should be applied to route calculations. Penalties can be
 * applied in the form of restricting roads, areas and setting different traffic modes.
 *
 * \note For the route calculation to consider traffic you must set an %NMADynamicPenalty that
 * specifies an %NMATrafficPenaltyMode. Traffic-based routing requires an internet connection.
 */
@property (nonatomic) NMADynamicPenalty *dynamicPenalty;

@end
/** @}  */
