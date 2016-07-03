/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * Defines the value used to indicate routing may start in any direction
 */
FOUNDATION_EXPORT const float NMARoutingModeStartDirectionAny;

/**
 * Represents values describing different routing types.
 * <p>
 * Note: a NMARoutingType has no effect on
 * NMATransportModePedestrian or NMATransportModePublicTransport
 * transport modes, since they always use NMARoutingTypeFastest (if
 * NMARoutingTypeShortest is set as the NMARoutingType when one of these
 * NMATransportMode types is selected, it will
 * be reset to NMARoutingTypeFastest when a route is calculated).
 * </p>
 */
typedef NS_ENUM(NSUInteger, NMARoutingType) {
    /** \brief Search for the shortest route, taking road conditions and restrictions into account (minimizes travel distance). Car mode only*/
    NMARoutingTypeShortest = 0,
    /** \brief Search for the fastest route, taking road conditions and restrictions into account (minimizes travel time). */
    NMARoutingTypeFastest = 1,
    /** \brief \deprecated This routing type is deprecated as of NMA SDK 3.2. Please use NMARoutingTypeFastest instead. */
    NMARoutingTypeEconomic __attribute__((deprecated)) = 2,
    /** \brief Search for balanced route, some travel time may be sacrificed in order to reduce the distance traveled. It calculates the optimal route based on time and distance combination. Car mode only. */
    NMARoutingTypeBalanced = 3
};

/**
 * Represents values describing different transport modes, the mode of
 * transportation a person will be using to travel a route (e.g. a car).
 */
typedef NS_ENUM(NSUInteger, NMATransportMode) {
    /** \brief A car is being used as the mode of transportation. */
    NMATransportModeCar = 0,
    /** \brief Walking is being used as the mode of transportation. */
    NMATransportModePedestrian = 1,
    /** \brief Public transport is being used as the mode of transportation. */
    NMATransportModePublicTransport = 2,
    /** \brief Straight line connecting the waypoints of a route. */
    NMATransportModeTrack = 3,
    /** \brief A truck is being used as the mode of transportation. */
    NMATransportModeTruck = 5,
    /** \brief Urban Mobility includes ways to get around the city: transit, taxi, shared car/bikes. */
    NMATransportModeUrbanMobility = 6
};

/**
 * Represents values describing routing options that can be used to enforce
 * special conditions on a calculated route.
 */
typedef NS_OPTIONS(NSUInteger, NMARoutingOption) {
    /**
     * The routing engine will avoid links that are part of a boat ferry passage.
     */
    NMARoutingOptionAvoidBoatFerry          = 1 << 0,

    /**
     * The routing engine will avoid links that are part of a dirt road.
     */
    NMARoutingOptionAvoidDirtRoad           = 1 << 1,

    /**
     * The routing engine will avoid links that are part of a highway.
     *
     * \note Effective only when used with ::NMATransportModeCar.
     */
    NMARoutingOptionAvoidHighway            = 1 << 2,

    /**
     * The routing engine will avoid links that go through a park.
     *
     * \note Effective only when used with ::NMATransportModePedestrian.
     */
    NMARoutingOptionAvoidPark               = 1 << 3,

    /**
     * The routing engine will avoid links that are part of a toll road.
     *
     * \note Effective only when used with ::NMATransportModeCar.
     */
    NMARoutingOptionAvoidTollRoad           = 1 << 4,

    /**
     * The routing engine will avoid links that are part of a tunnel.
     *
     * \note Effective only when used with ::NMATransportModeCar.
     */
    NMARoutingOptionAvoidTunnel             = 1 << 5,

    /**
     * The routing engine will avoid links that are part of a motorail train or car shuttle train passage.
     */
    NMARoutingOptionAvoidCarShuttleTrain    = 1 << 6,

    /**
     * The routing engine will avoid HOV/Carpool roads.
     */
    NMARoutingOptionAvoidCarpool            = 1 << 7
};


/**
 * \class NMARoutingMode NMARoutingMode.h "NMARoutingMode.h"
 *
 * Represents a model of the parameters required for one route
 * calculation, encapsulating parameters such as:
 * <ul>
 * <li>The #NMARoutingType</li>
 * <li>The #NMATransportMode</li>
 * <li>The #NMARoutingOption (specify 0 for none)</li></ul>
 */
@interface NMARoutingMode : NSObject

/**
 * Initializes a %NMARoutingMode instance with default values.
 */
- (id)init;

/**
 * Initializes a %NMARoutingMode instance with the specified routing
 * parameters.
 *
 * \param routingType - A routing type (see #NMARoutingType)
 * \param transportMode - A transport mode (see #NMATransportMode)
 * \param routingOptions - An OR-ed combination of routing options (see #NMARoutingOption).
 * \return The %NMARoutingMode object, or nil if initialization failed
 */
- (id)initWithRoutingType:(NMARoutingType)routingType transportMode:(NMATransportMode)transportMode routingOptions:(NSUInteger)routingOptions;

/**
 * The %NMARoutingType for the %NMARoutingMode.
 *
 * \note The default value is NMARoutingTypeShortest.
 */
@property (nonatomic) NMARoutingType routingType;

/**
 * The %NMATransportMode for the %NMARoutingMode.
 *
 * \note The default value is NMATransportModeCar.
 */
@property (nonatomic) NMATransportMode transportMode;

/**
 * The OR-ed #NMARoutingOption values for the %NMARoutingMode.
 *
 * \note The default value is 0 (no options selected).
 */
@property (nonatomic) NSUInteger routingOptions;

/**
 * The desired departure time.
 */
@property (nonatomic, strong) NSDate *departureTime;

/**
 * The maximum number of alternative routes to calculate. The actual
 * number calculated may be less. The default value is 1.
 *
 * \note Only one result will be returned for routes with more than two waypoints.
 */
@property (nonatomic) NSUInteger resultLimit;

/**
 * The direction, in degrees, that routing should start in. Use values in range 0..359. If a value
 * greater than 359 is specified, the modulus of 360 is used. Values will be rounded to the nearest
 * integral value.
 *
 * Defaults to NMARoutingModeStartDirectionAny which means route in any direction in order to obtain
 * the shortest/fastest possible route.
 *
 * /note To route in the current direction of travel set this property to
 * [NMAPositioningManager sharedPositioningManager].currentPosition.course
 */
@property (nonatomic) float startDirection;

#pragma mark - DEPRECATED

/**
 * Determines whether or not traffic is taken into account when calculating a route.
 *
 * \note Traffic-based routing requires an internet connection.
 *
 * \deprecated This method is deprecated as of NMA SDK 3.1. Please use dynamicPenalty in NMARouteManager instead.
 * If you do set this property it is equivalent to setting NMARouteManager dynamicPenalty to use a penatly of
 * NMATrafficPenaltyModeOptimal but note that setting an explicit NMARouteManager dynamicPenalty will override
 * this.
 */
@property (nonatomic, getter = isTrafficUsed) BOOL trafficUsed DEPRECATED_ATTRIBUTE;

@end

/** @}  */
