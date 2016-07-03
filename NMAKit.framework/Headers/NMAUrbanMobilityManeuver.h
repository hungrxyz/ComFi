/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */
@class NMAGeoBoundingBox;

#import "NMAManeuver.h"

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * Defines types of direction for a NMAUrbanMobilityManeuver.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityManeuverDirection) {
    /** \brief An undefined direction. */
    NMAUrbanMobilityManeuverDirectionUndefined = 0,
    /** \brief Direction forward. */
    NMAUrbanMobilityManeuverDirectionForward,
    /** \brief Direction right. */
    NMAUrbanMobilityManeuverDirectionRight,
    /** \brief Direction left. */
    NMAUrbanMobilityManeuverDirectionLeft,
    /** \brief Direction bear right. */
    NMAUrbanMobilityManeuverDirectionBearRight,
    /** \brief Direction light right. */
    NMAUrbanMobilityManeuverDirectionLightRight,
    /** \brief Direction hard right. */
    NMAUrbanMobilityManeuverDirectionHardRight,
    /** \brief Direction uturn right. */
    NMAUrbanMobilityManeuverDirectionUturnRight,
    /** \brief Direction uturn left. */
    NMAUrbanMobilityManeuverDirectionUturnLeft,
    /** \brief Direction hard left. */
    NMAUrbanMobilityManeuverDirectionHardLeft,
    /** \brief Direction light left. */
    NMAUrbanMobilityManeuverDirectionLightLeft,
    /** \brief Direction bear left. */
    NMAUrbanMobilityManeuverDirectionBearLeft
};


/**
 * \class NMAUrbanMobilityManeuver NMAUrbanMobilityManeuver.h "NMAUrbanMobilityManeuver.h"
 *
 * \brief  contains all information about walk maneuver, which is a part of journey.
 */
@interface NMAUrbanMobilityManeuver : NSObject

/**
 * Gets maneuver direction hint. Can be used to display the appropriate arrow icon for the
 * maneuver.
 * \return #NMAUrbanMobilityManeuverDirection  hint.
 */
@property (nonatomic, readonly) NMAUrbanMobilityManeuverDirection direction;

/**
 * Name of the next road in the route that the maneuver is heading toward.
 * nil if not available.
 *
 * \note  It is localized to the locale of the region.
 * If given language is not supported English version is returned.
 */
@property (nonatomic, readonly) NSString *nextRoadName;

/**
 * Number of the road (such as A5, B49, etc.) towards which the maneuver is heading.
 * nil if not available.
 *
 * \note  It is localized to the locale of the region.
 * If given language is not supported English version is returned.
 */
@property (nonatomic, readonly) NSString *nextRoadNumber;

/**
 * Gets verbal description of maneuver.
 *
 * \note  It is localized to the locale of the region.
 * If given language is not supported English version is returned.
 */
@property (nonatomic, readonly) NSString *instruction;

/**
 * Gets the action for this maneuver. Does not always indicate a direction.
 * \return #NMAManeuverAction to be taken.
 */
@property (nonatomic, readonly) NMAManeuverAction action;

/**
 * Gets duration - the amount of time in seconds for a single maneuver.
 * \return duration in seconds.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 * The distance from the start of the route to the maneuver, in meters.
 */
@property (nonatomic, readonly) NSUInteger distance;

/**
 * Array of %NMAGeoCoordinates representing the geometry of this section.
 */
@property (nonatomic, readonly) NSArray *geometry;

/**
 * Gets the %NMAGeoBoundingBox of the maneuver - the smallest rectangle that contains
 * maneuver geometry.
 * \return %NMAGeoBoundingBox that contains maneuver geometry.
 */
@property (nonatomic, readonly) NMAGeoBoundingBox *boundingBox;

@end
/** @}  */