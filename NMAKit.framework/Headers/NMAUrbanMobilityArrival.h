/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityStation;
@class NMAUrbanMobilityAddress;
@class NMAUrbanMobilityAccessPoint;
@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */


/**
 * \class NMAUrbanMobilityArrival NMAUrbanMobilityArrival.h "NMAUrbanMobilityArrival.h"
 *
 * Defines an arrival at a transit station.
 *
 * \sa NMAUrbanMobilityStation
 */
@interface NMAUrbanMobilityArrival : NSObject

/**
 * Transit station which hosts the arrival.
 */
@property (nonatomic, readonly) NMAUrbanMobilityStation *station;

/**
 * Access point which can be used to access the transit station which hosts this arrival.
 */
@property (nonatomic, readonly) NMAUrbanMobilityAccessPoint *accessPoint;

/**
 * Geo coordinates of this arrival.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

/**
 * Address information for this arrival (might not be available).
 */
@property (nonatomic, readonly) NMAUrbanMobilityAddress *address;

/**
 * Scheduled arrival time.
 */
@property (nonatomic, readonly) NSDate *scheduledTime;

/**
 * Scheduled arrival platform.
 */
@property (nonatomic, readonly) NSString *scheduledPlatform;

/**
 * Actual arrival time (might not be available).
 */
@property (nonatomic, readonly) NSDate *actualTime;

/**
 * Actual arrival platform (might not be available).
 */
@property (nonatomic, readonly) NSString *actualPlatform;

@end
/** @}  */
