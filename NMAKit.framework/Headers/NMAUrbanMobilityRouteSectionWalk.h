/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilityRouteSection.h"


@interface NMAUrbanMobilityRouteSectionWalk : NMAUrbanMobilityRouteSection

/**
 * Maybe used to find Maneuver element from Maneuvers list for more details about this section.
 */
@property (nonatomic, readonly) NSString *maneuversId;

/**
 * Indicates if the distance/duration provided can be trusted.
 * This means that the walk duration and distance we are giving has been collected by the agency,
 * and any walk calculation the client will do may not match this time. Default is true.
 */
@property (nonatomic, readonly, getter = isGuide) BOOL guide;

/**
 * Indicates if elevator is present at the {@link NMAUrbanMobilityStation} you're walking to.
 */
@property (nonatomic, readonly, getter = hasElevator) BOOL elevator;

/**
 * Indicates if escalator is present at the {@link NMAUrbanMobilityStation} you're walking to.
 */
@property (nonatomic, readonly, getter = hasEscalator) BOOL escalator;

@end
