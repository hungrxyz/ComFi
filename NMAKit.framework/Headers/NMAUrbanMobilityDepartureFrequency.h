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


/**
 * \class NMAUrbanMobilityDepartureFrequency NMAUrbanMobilityDepartureFrequency.h "NMAUrbanMobilityDepartureFrequency.h"
 *
 * Frequency information for a transit departure.
 *
 * \sa NMAUrbanMobilityDeparture
 *
 */
@interface NMAUrbanMobilityDepartureFrequency : NSObject

/**
 * The scheduled maximum interval in minutes.
 */
@property (nonatomic, readonly) NSNumber *scheduledMaxInterval;

/**
 * The scheduled minimum interval in minutes.
 */
@property (nonatomic, readonly) NSNumber *scheduledMinInterval;

/**
 * The actual maximum interval in minutes.
 */
@property (nonatomic, readonly) NSNumber *actualMaxInterval;

/**
 * The actual minimum interval in minutes.
 */
@property (nonatomic, readonly) NSNumber *actualMinInterval;

@end
/** @}  */
