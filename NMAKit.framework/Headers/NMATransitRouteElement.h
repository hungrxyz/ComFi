/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMATransitRouteStop;

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */


/**
 * \class NMATransitRouteElement NMATransitRouteElement.h "NMATransitRouteElement.h"
 *
 * Represents the leg of a transit journey from one stop to the next along a
 * NMATransitManeuver.
 * </p>
 * <p>
 * A NMATransitManeuver is composed of one or more NMATransitRouteElement.
 * </p>
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMATransitRouteElement : NSObject

/**
 * The duration, in seconds, for the NMATransitRouteElement.
 *
 * It is the estimated travel time from the departure stop to the arrival stop of
 * the NMATransitRouteElement.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 * The departure stop for the NMATransitRouteElement.
 */
@property (nonatomic, readonly, strong) NMATransitRouteStop *departureStop;

/**
 * The arrival stop for the NMATransitRouteElement.
 */
@property (nonatomic, readonly, strong) NMATransitRouteStop *arrivalStop;


@end
/** @}  */
