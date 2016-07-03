/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilityRouteSection.h"


@interface NMAUrbanMobilityRouteSectionTransit : NMAUrbanMobilityRouteSection

/**
 * The list of %NMAUrbanMobilityTicket required for this particular segment.
 */
@property (nonatomic, readonly) NSArray *tickets;

/**
 * The list of %NMAUrbanMobilityIntermediateStop that are part of this transit stop.
 */
@property (nonatomic, readonly) NSArray *stops;

@end
