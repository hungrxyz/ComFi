/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilityStation.h"

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

@class NMAUrbanMobilityDepartureBoard;


/**
 * \class NMAUrbanMobilityStationWithDepartureBoard NMAUrbanMobilityStationWithDepartureBoard.h "NMAUrbanMobilityStationWithDepartureBoard.h"
 *
 * Extension for class NMAUrbanMobilityStation, used for Multi Departures Board.
 */
@interface NMAUrbanMobilityStationWithDepartureBoard : NMAUrbanMobilityStation

/**
 * Departure Board %NMAUrbanMobilityDepartureBoard is used for hold lists of objects parsed from response for %NMAUrbanMobilityMultiBoardRequest.
 */
@property (nonatomic, readonly) NMAUrbanMobilityDepartureBoard *departureBoard;

@end
/** @}  */
