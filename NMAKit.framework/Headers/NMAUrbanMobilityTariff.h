/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


/**
 * \class NMAUrbanMobilityRouteTicket NMAUrbanMobilityTariff.h "NMAUrbanMobilityRouteTicket.h"
 *
 * Group of tickets which cover the whole journey.
 */
@interface NMAUrbanMobilityTariff : NSObject

/**
 * List of tickets that are required for one journey.
 * Array of NMAUrbanMobilityTicket.
 */
@property (nonatomic, readonly) NSArray *tickets;

@end

/** @}  */
