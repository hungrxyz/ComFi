/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARoute.h"
#import "NMAUrbanMobilityArrival.h"
#import "NMAUrbanMobilityDeparture.h"

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * Represents a wrapper of type NMARoute over the NMAUrbanMobilityRoute object.
 */
@interface NMARoute (NMAUrbanMobilityRoute)

/**
 * A unique id for this route.
 */
@property (nonatomic, readonly) NSString *routeId;

/**
 * The number of times a line change is done on this route.
 */
@property (nonatomic, readonly) NSUInteger changes;

/**
 * The duration in minutes of the route.
 */
@property (nonatomic, readonly) double duration;

/**
 * Information about arrival, see %NMAUrbanMobilityArrival class for details.
 */
@property (nonatomic, readonly) NMAUrbanMobilityArrival *arrival;

/**
 * Information about departure, see %NMAUrbanMobilityDeparture class for details.
 */
@property (nonatomic, readonly) NMAUrbanMobilityDeparture *departure;

/**
 * The %NMAUrbanMobilityRouteSection of the route. Can be a walking section or a line section.
 */
@property (nonatomic, readonly) NSArray *sections;

/**
 * List of %NMAUrbanMobilityTariff representing different options you can purchase for just one route.
 */
@property (nonatomic, readonly) NSArray *tariffOptions;

@end
/** @}  */
