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
 * \addtogroup NMA_Search  NMA Search Group
 * @{
 */


/**
 * \class NMANavigationPosition NMANavigationPosition.h "NMANavigationPosition.h"
 *
 * Represents a position that should be used when calculating routes for navigation.
 */
@interface NMANavigationPosition : NSObject

/**
 * The access type of the NMANavigationPosition.
 *
 * The access type "road" is used for car routing.
 *
 * \note It is important to match the accessType with the type of routing you are performing.
 * For example, use objects with an accessType of "road" for car routing
 * Please see https://developer.here.com/rest-apis/documentation/places/topics_api/object-link.html#access-point for possible values.
 */
@property (nonatomic, strong) NSString *accessType;

/**
 * The NMAGeoCoordinates of the NMANavigationPosition.
 *
 * This position should be used as navigablePosition of a NMAWaypoint when calculating
 * route.
 */
@property (nonatomic, strong) NMAGeoCoordinates *position;

@end
/** @}  */
