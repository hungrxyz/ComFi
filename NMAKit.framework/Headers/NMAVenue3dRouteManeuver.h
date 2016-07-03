/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAManeuver.h"

@class NMAVenue3dSpace;
@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * \brief Represents values that describe the possible enter/exit actions.
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dRouteActionType) {
    /**
     * No action.
     */
    NMAVenue3dRouteActionTypeNone,
    /**
     * Enter action.
     */
    NMAVenue3dRouteActionTypeEnter,

    /**
     * Exit action.
     */
    NMAVenue3dRouteActionTypeExit
};

/**
 * \brief Represents values that describe a connector type from one space to other.
 *
 */
typedef NS_ENUM(NSUInteger, NMAVenue3dRouteConnectorType) {
    /**
     * An elevator.
     */
    NMAVenue3dRouteConnectorTypeElevator,

    /**
     * An escalator.
     */
    NMAVenue3dRouteConnectorTypeEscalator,

    /**
     * Stairs.
     */
    NMAVenue3dRouteConnectorTypeStairs,

    /**
     * A skywalk.
     */
    NMAVenue3dRouteConnectorTypeSkywalk,

    /**
     * A Shuttle.
     */
    NMAVenue3dRouteConnectorTypeShuttle,

    /**
     * A Moving sidewak.
     */
    NMAVenue3dRouteConnectorTypeMovingSidewalk,

    /**
     * A Ramp.
     */
    NMAVenue3dRouteConnectorTypeRamp,

    /**
     * An other category.
     */
    NMAVenue3dRouteConnectorTypeOtherCategory,

    /**
     * Not a connector.
     */
    NMAVenue3dRouteConnectorTypeNotConnector
};


/**
 * \class NMAVenue3dRouteManeuver "NMAVenue3dRouteManeuver.h"
 *
 * \brief Describes a single route maneuver of indoor route section.
 *
 * \sa NMAVenue3dVenueRouteSection
 */
@interface NMAVenue3dRouteManeuver : NSObject

/**
 * NMAVenue3dRouteActionType for this NMAVenue3dRouteManeuver object.
 *
 */
@property (nonatomic, readwrite) NMAVenue3dRouteActionType routeActionType;

/**
 * The %NMAManeuverTurn to take for the maneuver.
 *
 * \note If the turn for the maneuver is undefined, attempts to read this
 * property will return NMAManeuverTurnUndefined.
 */
@property (nonatomic, readonly) NMAManeuverTurn turn;

/**
 * NMAVenue3dRouteConnectorType for this NMAVenue3dRouteManeuver object.
 *
 */
@property (nonatomic, readwrite) NMAVenue3dRouteConnectorType routeConnectorType;

/**
 * NMAVenue3dSpace object related to this NMAVenue3dRouteManeuver object.
 */
@property (nonatomic, readwrite) NMAVenue3dSpace *space;

/**
 * Geocoordinates of the maneuver.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *geoCoordinates;

/**
 * Distance of the maneuver from the start of the route.
 */
@property (nonatomic, readonly) NSInteger distanceFromStart;

/**
 * Distance of the maneuver from the previous maneuver.
 */
@property (nonatomic, readonly) NSInteger distanceFromPreviousManeuver;

/**
 * Distance from this maneuver to the next maneuver.
 */
@property (nonatomic, readonly) NSInteger distanceToNextManeuver;

/**
 * Floor index of the location of the maneuver.
 */
@property (nonatomic, readonly) NSInteger floorIndex;

/**
 * The angle in degrees from end of the start road to the start of the end road. Angle has a value
 * from -180 to 180, a returned value of zero represents the end road that continues in the same
 * direction as the start road.
 */
@property (nonatomic, readonly) NSInteger angle;

/**
 * The angle (from north) at the start of the maneuver, in degrees.
 *
 * \note Zero represents true-north, with increasing
 * values representing a clockwise progression of map orientation.
 */
@property (nonatomic, readonly) NSInteger mapOrientation;

@end
/** @} */
