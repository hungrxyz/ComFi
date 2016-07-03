/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARoutingMode.h"

typedef NS_ENUM(NSUInteger, NMAUrbanMobilityRoutingTypeOption) {
    /**
     * Return all form of routing. Timetable if available,
     * and fall back to simple routing when not available.
     */
    NMAUrbanMobilityRoutingTypeAll = 0,
    /**
     * Return only time table type of results.
     */
    NMAUrbanMobilityRoutingTypeTimeTable = 1,
    /**
     * Return only simple routing results.
     */
    NMAUrbanMobilityRoutingTypeSimpleRouting = 2,
};

typedef NS_OPTIONS(NSUInteger, NMAUrbanMobilityOption) {
    /**
     * Use high speed trains.
     */
    NMAUrbanMobilityOptionHighSpeedTrains           = 1 << 0,
    /**
     * Use euro city trains.
     */
    NMAUrbanMobilityOptionIntercityEurocityTrains   = 1 << 1,
    /**
     * Use interregional fast trains.
     */
    NMAUrbanMobilityOptionInterregionalFastTrains   = 1 << 2,
    /**
     * Use regional trains.
     */
    NMAUrbanMobilityOptionRegionalTrains            = 1 << 3,
    /**
     * Use city trains.
     */
    NMAUrbanMobilityOptionCityTrains                = 1 << 4,
    /**
     * Use busses.
     */
    NMAUrbanMobilityOptionBusses                    = 1 << 5,
    /**
     * Use boat or ferries.
     */
    NMAUrbanMobilityOptionBoatFerries               = 1 << 6,
    /**
     * Use metro or subway.
     */
    NMAUrbanMobilityOptionMetroSubway               = 1 << 7,
    /**
     * Use trams.
     */
    NMAUrbanMobilityOptionTram                      = 1 << 8,
    /**
     * Use ordered service as taxi.
     */
    NMAUrbanMobilityOptionOrderedServiceTaxi        = 1 << 9,
    /**
     * Use inclined.
     */
    NMAUrbanMobilityOptionInclinedFunicular         = 1 << 10,
    /**
     * Use aerial cable car.
     */
    NMAUrbanMobilityOptionAerialCableCar            = 1 << 11,
    /**
     * Use rapid bus.
     */
    NMAUrbanMobilityOptionRapidBus                  = 1 << 12,
    /**
     * Use monorail.
     */
    NMAUrbanMobilityOptionMonorail                  = 1 << 13,
    /**
     * Use Airplane.
     */
    NMAUrbanMobilityOptionAirplane                  = 1 << 14,
    /**
     * Undefined.
     */
    NMAUrbanMobilityOptionUdefined                  = 1 << 15,
};


/**
 * Contains options used when calculating an urban mobility route.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMARoutingMode (NMAUrbanMobilityRoutingMode)

@property (nonatomic) NMAUrbanMobilityRoutingTypeOption urbanMobilityRoutingType;  // NMAUrbanMobilityRoutingOption

/**
 * The OR-ed #NMAUrbanMobilityOption values for the NMARoutingMode.
 *
 * \note The default value is 0 (no options selected).
 *
 */
@property (nonatomic) NSUInteger urbanMobilityRoutingOptions;

/**
 * The number of routes to be returned that are departing/arriving before the given time.
 *
 * \note The maximum is 6, minimum 0, but the sum of backward and forward routes cannot be more than 6.
 *
 */
@property (nonatomic) NSUInteger backward;

/**
 * The number of routes to be returned that are departing/arriving after the given time.
 *
 * \note The maximum is 6, minimum 0, but the sum of backward and forward routes cannot be more than 6.
 *
 */
@property (nonatomic) NSUInteger forward;

/**
 * The walking speed in m/h that the user is having.
 */
@property (nonatomic) NSUInteger walkSpeed;

/**
 * The maximum walking distance to cover on foot to the nearest station.
 */
@property (nonatomic) NSUInteger walkDistance;

/**
 * Specifies if the number of returned connections must be strict, regarding to backward/forward parameters.
 * YES if true, NO otherwise.
 */
@property (nonatomic, getter=isStrict) BOOL strict;

/**
 * The desired arrival time, used for route calculation. If it's nil, departure time is used for route calculation.
 */
@property (nonatomic) NSDate *arrivalTime;


@end
