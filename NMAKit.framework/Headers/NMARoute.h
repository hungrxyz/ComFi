/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMARoutingMode.h"
#import "NMARouteTta.h"
#import "NMADynamicPenalty.h"

@class NMAGeoBoundingBox;
@class NMAWaypoint;
@class NMAManeuver;
@class NMAMapPolyline;

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
* \brief A constant used to indicate the whole route should be used in route leg selection.
*/
 FOUNDATION_EXPORT const NSInteger NMARouteSublegWhole;


/**
 * \class NMARoute NMARoute.h "NMARoute.h"
 *
 * \brief Represents a path (a collection of maneuvers) connecting two or more waypoints.
 *
 * Waypoints may be thought of as the input to a route calculation whereas maneuvers are
 * the results of calculating a route.
 */
@interface NMARoute : NSObject

/**
 * \brief The starting NMAWaypoint for the %NMARoute.
 */
@property (nonatomic, readonly, weak) NMAWaypoint *start;

/**
 *  The destination NMAWaypoint for the %NMARoute.
 */
@property (nonatomic, readonly, weak) NMAWaypoint *destination;

/**
 *  Array of NMAWaypoint for all waypoints of the %NMARoute.
 */
@property (nonatomic, readonly, strong) NSArray *waypoints;

/**
 * The length of the %NMARoute, in meters. This is the actual distance
 * covered if you were to travel the route.
 */
@property (nonatomic, readonly) NSUInteger length;

/**
 *  Returns the number of sub-legs the route has
 * a subleg is the part of a route between two stop waypoints.
 */
@property (nonatomic, readonly) NSUInteger sublegCount;

/**
 * The NMARouteTta object of traveling the whole NMARoute.
 *
 * \note The object returned will not include any delays due to traffic.
 */
@property (nonatomic, readonly) NMARouteTta *tta;


/**
 * \brief The NMARouteTta object of traveling the specified subLeg of the NMARoute
 *
 * \param subleg The index of the subleg on the NMARoute to be used for this calculation. If
 * NMARouteSublegWhole is provided, it is the same as tta property.
 *
 * \note The object returned will not include any delays due to traffic.
 */
- (NMARouteTta *)ttaForSubleg:(NSUInteger)subleg;


/**
 * The smallest NMAGeoBoundingBox that contains the entire %NMARoute.
 */
@property (nonatomic, readonly, strong) NMAGeoBoundingBox *boundingBox;

/**
 * Array of NMAManeuver to represent all the maneuvers that travelers will
 * encounter along the %NMARoute.
 * In case of calculation %NMAUrbanMobilityRoute, this returns nil.
 * Instead, you can find array of %NMAUrbanMobilityManeuver in every %NMAUrbanMobilityRoute::NMAUrbanMobilityRouteSectionWalk.
 */
@property (nonatomic, readonly, strong) NSArray *maneuvers;

/**
 *  The NMAMapPolyline representation of the route.
 */
@property (nonatomic, readonly, strong) NMAMapPolyline *mapPolyline;

/**
 * The NMARoutingMode for the %NMARoute.
 */
@property (nonatomic, readonly, strong) NMARoutingMode *routingMode;

/**
 * A user-defined tag to identify the %NMARoute
 *
 * \note The default value for userTag is empty string.
 */
@property (nonatomic, strong) NSString *userTag;

/**
 * \brief The NMARouteTta object of traveling the the whole NMARoute with traffic consideration if
 * traffic information is available.
 *
 * This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * To ensure ttaWithTraffic considers traffic for the ENTIRE route do either of the following:
 *
 * (1) If you calculate your route with traffic, i.e. by specifying a traffic dynamic penalty via
 *     NMARoutingManager, then simply call ttaWithTraffic.
 *     IMPORTANT: In this case the returned NMARouteTta may indicate the route is not blocked even
 *     if it is. Always check NMARouteViolatedOption in the [NMARouteManagerDelegate didCalculateRoutes:]
 *     callback.
 *
 * (2) If you calculate your route without traffic, but you are still interested in duration and
 *     details for your route with traffic, then you need to:
 *      a. Request traffic for the entire route, see "requestTrafficOnRoute:" in NMATrafficManager
 *      b. Wait for the callback "trafficDataDidFinish" to ensure the traffic data has been downloaded
 *      c. Get the duration with traffic by calling ttaWithTraffic.
 *
 * In both of the above cases you must be online!
 *
 * Please note that enabling traffic on NMAMapView (using any of the traffic related methods) will cause
 * traffic data to be downloaded and hence considered by ttaWithTraffic. This can lead to situations
 * in which ttaWithTraffic will only consider traffic for the visible part of the route if (1) or (2)
 * above were not performed.
 *
 * \param mode NMATrafficPenaltyMode to be used for this calculation.
 */
- (NMARouteTta *)ttaWithTraffic:(NMATrafficPenaltyMode)mode;

/**
 * \brief The NMARouteTta object of traveling the the whole NMARoute with traffic consideration if
 * traffic information is available.
 *
 * This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * To ensure ttaWithTraffic considers traffic for the ENTIRE route do either of the following:
 *
 * (1) If you calculate your route with traffic, i.e. by specifying a traffic dynamic penalty via
 *     NMARoutingManager, then simply call ttaWithTraffic.
 *     IMPORTANT: In this case the returned NMARouteTta may indicate the route is not blocked even
 *     if it is. Always check NMARouteViolatedOption in the [NMARouteManagerDelegate didCalculateRoutes:]
 *     callback.
 *
 * (2) If you calculate your route without traffic, but you are still interested in duration and
 *     details for your route with traffic, then you need to:
 *      a. Request traffic for the entire route, see "requestTrafficOnRoute:" in NMATrafficManager
 *      b. Wait for the callback "trafficDataDidFinish" to ensure the traffic data has been downloaded
 *      c. Get the duration with traffic by calling ttaWithTraffic.
 *
 * In both of the above cases you must be online!
 *
 * Please note that enabling traffic on NMAMapView (using any of the traffic related methods) will cause
 * traffic data to be downloaded and hence considered by ttaWithTraffic. This can lead to situations
 * in which ttaWithTraffic will only consider traffic for the visible part of the route if (1) or (2)
 * above were not performed.
 *
 * \param mode NMATrafficPenaltyMode to be used for this calculation.
 * \param subleg The index of the subleg on the NMARoute to be used for this calculation. If
 * NMARouteSublegWhole is provided, it is the same as ttaWithTraffic property.
 */
- (NMARouteTta *)ttaWithTraffic:(NMATrafficPenaltyMode)mode forSubleg:(NSUInteger)subleg;

#pragma mark - DEPRECATED
/**
 * \brief The NMARouteTta object of traveling the the whole NMARoute with traffic consideration if
 * traffic information is available.
 *
 * This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * To ensure ttaWithTraffic considers traffic for the ENTIRE route do either of the following:
 *
 * (1) If you calculate your route with traffic, i.e "routingMode.trafficUsed = YES" then simply
 *     call ttaWithTraffic.
 *     IMPORTANT: In this case the returned NMARouteTta may indicate the route is not blocked even
 *     if it is. Always check NMARouteViolatedOption in the [NMARouteManagerDelegate didCalculateRoutes:]
 *     callback.
 *
 * (2) If you calculate your route without traffic, but you are still interested in duration and
 *     details for your route with traffic, then you need to:
 *      a. Request traffic for the entire route, see "requestTrafficOnRoute:" in NMATrafficManager
 *      b. Wait for the callback "trafficDataDidFinish" to ensure the traffic data has been downloaded
 *      c. Get the duration with traffic by calling ttaWithTraffic.
 *
 * In both of the above cases you must be online!
 *
 * Please note that enabling traffic on NMAMapView (using any of the traffic related methods) will cause
 * traffic data to be downloaded and hence considered by ttaWithTraffic. This can lead to situations
 * in which ttaWithTraffic will only consider traffic for the visible part of the route if (1) or (2)
 * above were not performed.
 *
 * \deprecated This property is deprecated as of NMA SDK 3.1 and is the equivalent of calling
 * ttaWithTraffic:NMATrafficPenaltyModeOptimal
 */
@property (nonatomic, readonly) NMARouteTta *ttaWithTraffic DEPRECATED_ATTRIBUTE;

/**
 * \brief The NMARouteTta object of traveling the the whole NMARoute with traffic consideration if
 * traffic information is available.
 *
 * This method returns a nil object if access to this operation is denied.
 * Contact your HERE representative for more information.
 *
 * To ensure ttaWithTraffic considers traffic for the ENTIRE route do either of the following:
 *
 * (1) If you calculate your route with traffic, i.e "routingMode.trafficUsed = YES" then simply
 *     call ttaWithTraffic.
 *     IMPORTANT: In this case the returned NMARouteTta may indicate the route is not blocked even
 *     if it is. Always check NMARouteViolatedOption in the [NMARouteManagerDelegate didCalculateRoutes:]
 *     callback.
 *
 * (2) If you calculate your route without traffic, but you are still interested in duration and
 *     details for your route with traffic, then you need to:
 *      a. Request traffic for the entire route, see "requestTrafficOnRoute:" in NMATrafficManager
 *      b. Wait for the callback "trafficDataDidFinish" to ensure the traffic data has been downloaded
 *      c. Get the duration with traffic by calling ttaWithTraffic.
 *
 * In both of the above cases you must be online!
 *
 * Please note that enabling traffic on NMAMapView (using any of the traffic related methods) will cause
 * traffic data to be downloaded and hence considered by ttaWithTraffic. This can lead to situations
 * in which ttaWithTraffic will only consider traffic for the visible part of the route if (1) or (2)
 * above were not performed.
 *
 * \deprecated This property is deprecated as of NMA SDK 3.1 and is the equivalent of calling
 * ttaWithTraffic:NMATrafficPenaltyModeOptimal forSubleg:
 *
 * \param subleg The index of the subleg on the NMARoute to be used for this calculation. If
 * NMARouteSublegWhole is provided, it is the same as ttaWithTraffic property.
 */
- (NMARouteTta *)ttaWithTrafficForSubleg:(NSUInteger)subleg DEPRECATED_ATTRIBUTE;

@end

/**  @}  */
