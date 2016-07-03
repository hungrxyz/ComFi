/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAVenue3dBaseLocation;
@class NMAVenue3dCombinedRoute;
@class NMAVenue3dRouteOptions;
@class NMAVenue3dRoutingController;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * \brief Represents a delegate to handle NMAVenue3dRoutingController route calculation completion.
 *
 * Methods of this protocol are called on the main queue.
 */
@protocol NMAVenue3dRoutingControllerObserver <NSObject>

@required
/*!
 *  Callback upon completion of route calculation.
 *
 * \param combinedRoute A NMAVenue3dCombined route object representing different
 *                   route sections including indoor part(s), possible outdoor part
 *                   and possible link section(s). The route can be shown on the map
 *                   using {@link NMAVenue3dRoutingController::showRoute:} message.
 *                   A NMAVenue3dCombined route object contains 0 route sections
 *                   in case if route calculation fails.
 */
- (void)didCalculateRoute:(NMAVenue3dCombinedRoute *)combinedRoute;

@end


/**
 * \class NMAVenue3dRoutingController NMAVenue3dRoutingController.h "NMAVenue3dRoutingController.h"
 *
 * \brief An NMAVenue3dRoutingController object encapsulates the routing functionality.

 * With NMAVenue3dRoutingController one can set route parameters like start end end locations and display the route.
 * Either end of the route need to be some space in a venue.
 * <p>
 * This class can not be instantiated directly, instead it is obtained from NMAVenueMapLayer for the given NMAVenue3dController object.
 * </p>
 *
 * \sa NMAVenue3dMapLayer
 * \sa NMAVenue3dController
 */
@interface NMAVenue3dRoutingController : NSObject

/**
 * Calculates route object from start to end location. Route calculation is done in asynchronous manner,
 * and is available for listeners of NMAVenue3dRoutingControllerDelegate upon completion.
 *
 * @param startLocation
              A start location object.
 * @param endLocation
 *            An end ocation object.
 * @param options
 *            An options used for route calculataion.
 */
- (void)calculateRouteFrom:(NMAVenue3dBaseLocation *)startLocation
                        to:(NMAVenue3dBaseLocation *)endLocation
                withParams:(NMAVenue3dRouteOptions *)options;

/**
 * \brief Add a NMAVenue3dRoutingControllerObserver
 *
 * \param observer to be added
 */
- (void)addObserver:(id<NMAVenue3dRoutingControllerObserver>)observer;

/**
 * \brief Remove a NMAVenue3dRoutingControllerObserver
 *
 * \param observer to be added
 */
- (void)removeObserver:(id<NMAVenue3dRoutingControllerObserver>)observer;

/**
 * Shows the route on the map. Only one route at a time can be shown.
 *
 * @param combinedRoute
 *            A route object. This object is obtained using calculateRouteFrom of this class.
 *            message. The route can be hided using hideRoute} message of this class.
 */
- (void)showRoute:(NMAVenue3dCombinedRoute *)combinedRoute;

/**
 * Hides the currently shown route.
 */
- (void)hideRoute;

@end
/** @} */
