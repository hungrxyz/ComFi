/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */


/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

@interface NMAUrbanMobilityDepartureBoard : NSObject

/**
 * Returns a list of  %NMAUrbanMobilityDeparture.
 */
@property (nonatomic, readonly) NSArray *departures;

/**
 * Returns a list of  %NMAUrbanMobilityLine, lines serving departures shown in current departure list .
 */
@property (nonatomic, readonly) NSArray *lines;

/**
 * Returns a list of  %NMAUrbanMobilityOperator, operators operating on this stop/station.
 */
@property (nonatomic, readonly) NSArray *operators;

@end
/** @}  */
