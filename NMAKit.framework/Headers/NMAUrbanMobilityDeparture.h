/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobility.h"
#import "NMAUrbanMobilityArrival.h"

@class NMAUrbanMobilityLine;
@class NMAUrbanMobilityOperator;
@class NMAUrbanMobilityDepartureFrequency;

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * This enum defines Urban Mobility transit departure deviations.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityDepartureDeviation) {
    /** \brief No deviation (scheduled operation). */
    NMAUrbanMobilityDepartureNoDeviation = 0,

    /** \brief The transit line's station sequence was changed. */
    NMAUrbanMobilityDepartureRedirected,

    /** \brief The transit service was replaced. */
    NMAUrbanMobilityDepartureReplaced,

    /** \brief The transit service was cancelled. */
    NMAUrbanMobilityDepartureCancelled,

    /** \brief An additional transit service was provided. */
    NMAUrbanMobilityDepartureAdditional
};


/**
 * \class NMAUrbanMobilityDeparture NMAUrbanMobilityDeparture.h "NMAUrbanMobilityDeparture.h"
 *
 * Defines a departure from a transit station.
 *
 * \sa NMAUrbanMobilityArrival
 * \sa NMAUrbanMobilityStation
 */
@interface NMAUrbanMobilityDeparture : NSObject

/**
 * Transit line which serves the departure.
 */
@property (nonatomic, readonly) NMAUrbanMobilityLine *line;

/**
 * Means of transport which servers the departure (Bus, Tram, Train, etc)
 */
@property (nonatomic, readonly) NMAUrbanMobilityTransitMode transitMode;

/**
 * Transit operator which serves the departure.
 */
@property (nonatomic, readonly) NMAUrbanMobilityOperator *transitOperator;

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

/**
 * Deviation of the departure.
 */
@property (nonatomic, readonly) NMAUrbanMobilityDepartureDeviation deviation;

/**
 * Frequency of the departure (might not be available).
 */
@property (nonatomic, readonly) NMAUrbanMobilityDepartureFrequency *frequency;

/**
 * Geo coordinates of this arrival.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

/**
 * Transit station which hosts the departure.
 */
@property (nonatomic, readonly) NMAUrbanMobilityStation *station;

/**
 * Access point which can be used to access the transit station which hosts this departure. 
 * Information about a station access point (entrance/exit).
 */
@property (nonatomic, readonly) NMAUrbanMobilityAccessPoint *accessPoint;

/**
 * Address information for this departure (might not be available).
 */
@property (nonatomic, readonly) NMAUrbanMobilityAddress *address;

@end
/** @}  */
