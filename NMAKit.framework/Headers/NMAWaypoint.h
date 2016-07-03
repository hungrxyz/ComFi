/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * Waypoint types
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMAWaypointType) {
    /**
     * A maneuver is generated for a STOP waypoint. After the
     * STOP waypoint, route is allowed to continue in the
     * opposite direction, i.e. to turn back.
     *
     * During Guidance, "You have reached your stop-over" will
     * be announced if supported by the selected voice skin.
     *
     * The first and the last waypoint to be used for route
     * calculation must be of NMAStopWaypoint type.
     */
    NMAStopWaypoint,

    /**
     * No maneuver is generated for a VIA waypoint. After the
     * VIA waypoint, route will continue in the same direction
     * as when it's approached.
     *
     * Via waypoints will "force" the route to pass through them,
     * but they will not cause any guidance, announcement or
     * maneuvers.
     *
     * At the moment VIA waypoints will not be used during Guidance
     * triggered re-routing. When a full re-routing is triggered,
     * these VIA waypoints might be "lost". This will be fixed in
     * the future release.
     *
     * This is only supported by NMATransportModeCar. It's ignored
     * for other transport modes.
     */
    NMAViaWaypoint
};


/**
 * \class NMAWaypoint NMAWaypoint.h "NMAWaypoint.h"
 *
 * \brief Waypoints define a route's stopovers, including its start point it's
 * destination point and any points in between.
 *
 * Each waypoint represents a position along an NMARoute, this includes:
 * <ul>
 * <li>The original (input) coordinates specified as part of a search request</li><br/>
 * and
 * <li>The navigable (input) coordinates representing the coordinates on the road</li>
 * </ul>
 */
@interface NMAWaypoint : NSObject

/**
 * The NMAGeoCoordinates representing the original position of the
 * NMAWaypoint - typically the exact coordinates of a building.
 *
 * By default, this is the same as the geocoordinates provided
 * during construction of this NMAWaypoint.
 *
 * Attempts to set the property to nil will be ignored.
 */
@property (nonatomic, strong) NMAGeoCoordinates *originalPosition;

/**
 * The NMAGeoCoordinates representing the suggested navigable position of the
 * NMAWaypoint - typically the coordinates on the road closest to
 * the original position - to be used in a route calculation.
 *
 * By default, this is the same as the geocoordinates provided
 * during construction of this NMAWaypoint. If this information
 * is available, it's recommended that you provide it for route
 * calculation, especially for determining the side of street
 * during arrival when there is a physical or logical lane divider
 * on the road.
 *
 * Attempts to set the property to nil will be ignored.
 */
@property (nonatomic, strong) NMAGeoCoordinates *navigablePosition;

/**
 * The NMAGeoCoordinates representing the mapped matched position
 * of the NMAWaypoint - the coordinates adjusted by the routing
 * engine so that they fall upon a road.
 *
 * This is different than the navigablePosition because this is a value that is
 * generated during the routing calculation.
 *
 * \note This is nil before route calculation. This is only available
 * after route calculation.
 */
@property (nonatomic, readonly, strong) NMAGeoCoordinates *mappedPosition;

/**
 * Determines the waypoint type.
 *
 * \note The default value is NMAStopWaypoint.
 *
 * \sa NMAWaypointType
 */
@property (nonatomic) NMAWaypointType waypointType;

/**
 * Initializes a STOP NMAWaypoint instance with specified geocoordinates.
 *
 * \param aPosition of a position, must not be nil
 * \return The NMAWaypoint instance, or nil if initialization failed
 */
- (instancetype)initWithGeoCoordinates:(NMAGeoCoordinates *)aPosition;

/**
 * Initializes a NMAWaypoint instance with specified geocoordinates and
 * type.
 *
 * \param aPosition of a position
 * \param type of this waypoint, must not be nil
 * \return The NMAWaypoint instance, or nil if initialization failed
 */
- (instancetype)initWithGeoCoordinates:(NMAGeoCoordinates *)aPosition
                          waypointType:(NMAWaypointType)type;

@end

/** @}  */
