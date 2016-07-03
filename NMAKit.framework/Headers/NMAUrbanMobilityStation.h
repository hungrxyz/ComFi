/*
 * Copyright © 2015-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobility.h"

@class NMAGeoCoordinates;
@class NMAAddress;


/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * \class NMAUrbanMobilityStation NMAUrbanMobilityStation.h "NMAUrbanMobilityStation.h"
 *
 * Public transit station which serves transit lines.
 *
 * \sa NMAUrbanMobilityLine
 * \sa NMAUrbanMobilityTransitMode
 * \sa NMAUrbanMobilityDepartureBoard
 */
@interface NMAUrbanMobilityStation : NSObject

/**
 * Unique ID of the station.
 */
@property (nonatomic, readonly) NSString *stationId;

/**
 * Name of the station.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * Geo coordinates of the station.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

/**
 * Address information for the station.
 */
@property (nonatomic, readonly) NMAAddress *address;

/**
 * Describes whether or not the blind guidance is available at the station.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFeatureAvailability blindguideAvailability;

/**
 * Describes whether or not the elevator is available at the station.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFeatureAvailability elevatorAvailability;

/**
 * Describes whether or not the escalator is available at the station.
 */
@property (nonatomic, readonly) NMAUrbanMobilityFeatureAvailability escalatorAvailability;

/**
 * Transit lines which run through this station (an array of %NMAUrbanMobilityLines).
 *
 * \sa NMAUrbanMobilityLine
 */
@property (nonatomic, readonly) NSArray *lines;

/**
 * Transit modes which are served by the station (a set of %NMAUrbanMobilityTransitModes).
 *
 * \sa NMAUrbanMobilityTransitMode
 */
@property (nonatomic, readonly) NSSet *transitModes;

/**
 * Distance (in meters) between the station and current location.
 */
@property (nonatomic, readonly) NSUInteger distanceFromCurrentLocation;

/**
 * YES if the departure board is available for this station.
 *
 * \sa NMAUrbanMobilityDepartureBoard
 */
@property (nonatomic, readonly, getter = isDepartureBoardAvailable) BOOL departureBoardAvailable;

@end
/** @}  */
