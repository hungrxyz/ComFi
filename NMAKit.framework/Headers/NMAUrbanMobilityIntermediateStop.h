/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityStation;


@interface NMAUrbanMobilityIntermediateStop : NSObject

/**
 * The station object.
 */
@property (nonatomic, readonly)  NMAUrbanMobilityStation *station;

/**
 * The departure time from the intermediate station.
 */
@property (nonatomic, readonly) NSDate *scheduledDepartureTime;

/**
 * The arrival in the intermediate station.
 */
@property (nonatomic, readonly) NSDate *scheduledArrivalTime;

/**
 * Actual departure time from the intermediate station if real time information is avaialble.
 */
@property (nonatomic, readonly) NSDate *actualDepartureTime;

/**
 * Actual arrival time in the intermediate station if real time information is avaialble.
 */
@property (nonatomic, readonly) NSDate *actualArrivalTime;


@end
