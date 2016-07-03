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

@class NMAUrbanMobilityRouteResult;
@class NMARoutingMode;
@class NMAUrbanMobilityCalculateResult;

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * Represents values for set direction used to looking for earlier/later routes
 * The possible values are F (Forward) and B (Backward).
 */
typedef NS_ENUM(NSUInteger, NMASubsequentRouteType) {
    /** \brief uses F (Forward) value in request */
    NMASubsequentRouteTypeForward = 0,
    /** \brief uses B (Backward) value in request */
    NMASubsequentRouteTypeBackward
};

/**
 * \brief A completion block used to handle the result of an Urban Mobility route request.
 *
 * \param routeResult The result of the Urban Mobility routing calculation (can be nil if %NMARoutingError
 * error param is not %NMARoutingErrorNone)
 *
 * \param error A routing calculation error.
 * See %NMARoutingError for possible error codes. If
 * %NMARoutingErrorRouteUseDisabledRoads is returned then
 * \p violatedOptions is not empty (the returned NMARoute is valid
 * and can be used for navigation although it uses roads which were
 * disabled in the original NMARoutingMode::routingOptions options).
 */
typedef void(^NMAUrbanMobilityCalculateResultBlock)(NMAUrbanMobilityRouteResult *routeResult, NMARoutingError error);


/**
 * Urban Mobility-specific route calculation executor. Defines Urban Mobility specific calculation
 * methods and response listener.
 * <p>
 * Urban Mobility provides Inter-modal and Multi-modal routes including Public Transit.
 * </p>
 */
@interface NMAUrbanMobilityRouter : NMARouter

/**
 * Starts a %NMAUrbanMobilityRoute calculation with the given stop list.
 *
 * <p>This method returns nil and a route will not be calculated if access to this
 * operation is denied. Contact your HERE representative for more information.</p>
 *
 * <p>
 * The array of stops used to calculate the route must have at least two items. The stops must be of
 * %NMAWaypoint type.
 * </p>
 *
 * \param stops A list of stops to route between, maximum 32 stops. The first stop and
 * the last stop must be of %NMAStopWaypoint type.
 * 
 * \note Urban Mobility supports only 2 waypoints. If %NMAUrbanMobilityRouter is used, then adding
 * more than 2 waypoints  will result in getting an estimated Public Transport routes.
 *
 * \param mode The %NMARoutingMode to use for route calculation
 *
 * \param completion The %NMAUrbanMobilityCalculateResultBlock used to handle the result of a route request
 *
 * \return %NSProgress if route calculation is successfully started, nil otherwise
 */
- (NSProgress *)calculateRouteWithStops:(NSArray *)stops routingMode:(NMARoutingMode *)mode completionBlock:(NMAUrbanMobilityCalculateResultBlock)completion;

/**
 * Starts a earlier or later route calculation, based on service parameters included in %NMAUrbanMobilityRouteResult
 *
 * <p>This method returns nil and a route will not be calculated if access to this
 * operation is denied. Contact your HERE representative for more information.</p>
 *
 * \param routeResult of type %NMAUrbanMobilityRouteResult contains parameters (serviceUrl and context) obtained from response of requested route
 *
 * \param subsequentRouteType The NMASubsequentRouteType parameter to force searching earlier or later routes
 *
 * \param routeCount Number of desired route. Given number is just suggestion and the number of
 * route returned is not guaranteed. Allowed range is [1, 6]. Using unsupported value will result error response in route calculation.
 *
 * \param completion The %NMAUrbanMobilityCalculateResultBlock used to handle the result of a route request
 *
 * \return NSProgress if route calculation is successfully started, nil otherwise
 */
- (NSProgress *)calculateSubsequentRouteWithRouteResult:(NMAUrbanMobilityRouteResult *)routeResult
                                withSubsequentRouteType:(NMASubsequentRouteType)subsequentRouteType
                                         withRouteCount:(NSUInteger)routeCount
                                        completionBlock:(NMAUrbanMobilityCalculateResultBlock)completion;

@end
/** @}  */
