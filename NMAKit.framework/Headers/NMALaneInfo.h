/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
/**
 * \addtogroup NMA_Navigation NMA Navigation Group
 * @{
 */

#pragma mark - DEPRECATED

/**
 * \enum NMALaneInfoDirectionType
 * \brief The possible directions a road lane can lead.
 *
 * A combination of the NMALaneInfoDirectionType forms a direction bitmask.
 *
 * \sa NMALaneInfo
 *
 * @product nlp-hybrid-plus nlp-plus
 *
 * \deprecated This enum is deprecated as of NMA SDK 3.2. Please use NMALaneInformationDirection instead.
 */
typedef NS_OPTIONS(NSUInteger, NMALaneInfoDirectionType) {
    /** \brief Indicates that the direction is undefined. */
    NMALaneInfoDirectionTypeMaskUndefined       = 0x00,

    /** \brief Indicates that the direction of travel is straight ahead. */
    NMALaneInfoDirectionTypeMaskStraight        = 0x01,

    /** \brief Indicates a slight right turn. */
    NMALaneInfoDirectionTypeMaskSlightlyRight   = 0x02,

    /** \brief Indicates a right turn. */
    NMALaneInfoDirectionTypeMaskRight           = 0x04,

    /** \brief Indicates a sharp right turn. */
    NMALaneInfoDirectionTypeMaskSharpRight      = 0x08,

    /** \brief Indicates a left u-turn. */
    NMALaneInfoDirectionTypeMaskUTurnLeft       = 0x10,

    /** \brief Indicates a sharp left turn. */
    NMALaneInfoDirectionTypeMaskSharpLeft       = 0x20,

    /** \brief Indicates a left turn. */
    NMALaneInfoDirectionTypeMaskLeft            = 0x40,

    /** \brief Indicates a slight left turn. */
    NMALaneInfoDirectionTypeMaskSlightlyLeft    = 0x80,

    /** \brief Indicates a right u-turn. */
    NMALaneInfoDirectionTypeMaskUTurnRight      = 0x100
} DEPRECATED_ATTRIBUTE;

/**
 * \enum NMALaneInfoPositionType
 * \brief The position of the lane with respect to the current route.
 *
 * \sa NMALaneInfo
 *
 * @product nlp-hybrid-plus nlp-plus
 *
 * \deprecated This enum is deprecated as of NMA SDK 3.2. Please use
 * NMALaneInformationRecommendationState instead.
 */
typedef NS_ENUM(NSUInteger, NMALaneInfoPositionType) {
    /** \brief Lane is definitely not on the current route. */
    NMALaneInfoPositionOffRoute,

    /** \brief Lane is definitely on the current route. */
    NMALaneInfoPositionOnRoute,

    /** \brief It is unknown whether the lane is on the current route or not. */
    NMALaneInfoPositionUnknown
} DEPRECATED_ATTRIBUTE;


/**
 * \class NMALaneInfo NMALaneInfo.h "NMALaneInfo.h"
 * \brief Contains information about a single road lane, including lane directions and whether
 * or not the lane is on the current route.
 *
 * @product nlp-hybrid-plus nlp-plus
 *
 * \deprecated This class is deprecated as of NMA SDK 3.2. Please use NMALaneInformation instead.
 */
DEPRECATED_ATTRIBUTE
@interface NMALaneInfo : NSObject


/**
 * \property directions
 * \brief All possible directions in which the lane can lead.
 *
 * \deprecated This property is deprecated as of NMA SDK 3.2. Please use NMALaneInformation directions instead.
 */
@property (nonatomic, readonly) NSInteger directions DEPRECATED_ATTRIBUTE;

/**
 * \property position
 * \brief Gets the position of this lane with respect to the current route.
 *
 * \deprecated This property is deprecated as of NMA SDK 3.2. Please use NMALaneInformation
 * recommendationState instead.
 */
@property (nonatomic, readonly) NMALaneInfoPositionType position DEPRECATED_ATTRIBUTE;

/**
 * \property onRoute
 *
 * \deprecated This method is deprecated as of NMA SDK 2.1.1. Use position instead.
 *
 * Indicates whether the lane is on the route currently used for navigation.
 */
@property (nonatomic, readonly, getter = isOnRoute) BOOL onRoute DEPRECATED_ATTRIBUTE;

@end
/** @} */
