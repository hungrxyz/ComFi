/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class CLLocation;
@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */

/**
 * Defines position sources.
 */
typedef NS_ENUM(NSUInteger, NMAGeoPositionSource) {
    /** \brief Position source is unknown. */
    NMAGeoPositionSourceUnknown = 0x0,
    /** \brief Position source is iOS location manager. */
    NMAGeoPositionSourceSystemLocation = 0x1,
    /** \brief Position source is indoor radio map. */
    NMAGeoPositionSourceIndoor = 0x2
};

/**
 * A constant used to indicate an unknown measurement value.
 */
FOUNDATION_EXPORT const double NMAGeoPositionUnknownValue;


/**
 * \class NMAGeoPosition
 * Represents position, speed, and course information as provided by a
 * positioning source for a distinct moment in time.
 */
@interface NMAGeoPosition : NSObject

/**
 * A convenience constructor for creating NMAGeoPosition instances with
 * specified coordinates, speed, course, and accuracy.
 *
 * \note The accuracy parameter will be used for all of latitudeAccuracy,
 * longitudeAccuracy, and altitudeAccuracy.
 *
 * \note The timestamp will be set to the current time.
 */
+ (id)geoPositionWithCoordinates:(NMAGeoCoordinates *)coordinates
                           speed:(double)speed
                          course:(double)course
                        accuracy:(double)accuracy;

/**
 * A convenience constructor for creating NMAGeoPosition instances with
 * specified coordinates, speed, course, and accuracy.
 *
 * \note The accuracy parameter will be used for all of latitudeAccuracy,
 * longitudeAccuracy, and altitudeAccuracy.
 */
+ (id)geoPositionWithCoordinates:(NMAGeoCoordinates *)coordinates
                           speed:(double)speed
                          course:(double)course
                        accuracy:(double)accuracy
                       timestamp:(NSDate *)timestamp;

/**
 * A convenience constructor for creating NMAGeoPosition instances with
 * specified coordinates, speed, course, latitudeAccuracy, longitudeAccuracy
 * and altitudeAccuracy.
 */
+ (id)geoPositionWithCoordinates:(NMAGeoCoordinates *)coordinates
                           speed:(double)speed
                          course:(double)course
                latitudeAccuracy:(double)latitudeAccuracy
               longitudeAccuracy:(double)longitudeAccuracy
                altitudeAccuracy:(double)altitudeAccuracy
                       timestamp:(NSDate *)timestamp;

/**
 * A convenience constructor for creating NMAGeoPosition instances with
 * the specified CLLocation.
 */
+ (id)geoPositionWithCLLocation:(CLLocation *)location;

/**
 * The geographical location of the position.
 */
@property (nonatomic, readonly, weak) NMAGeoCoordinates *coordinates;

/**
 * The accuracy of the latitude coordinate, in meters.
 *
 * \note Will be NMAGeoPositionUnknownValue if unknown.
 */
@property (nonatomic, readonly) double latitudeAccuracy;

/**
 * The accuracy of the longitude coordinate, in meters.
 *
 * \note Will be NMAGeoPositionUnknownValue if unknown.
 */
@property (nonatomic, readonly) double longitudeAccuracy;

/**
 * The accuracy of the altitude, in meters.
 *
 * \note Will be NMAGeoPositionUnknownValue if unknown.
 */
@property (nonatomic, readonly) double altitudeAccuracy;

/**
 * The movement speed of the position.
 *
 * \note Will be NMAGeoPositionUnknownValue if unknown.
 */
@property (nonatomic, readonly) double speed;

/**
 * \brief The course (direction of travel) of the position, in degrees.
 *
 * Valid course values are in the range [0, 360), with 0 degrees representing
 * north and values increasing clockwise. Thus, east is 90 degrees, south is
 * 180 degrees, and so on.
 *
 * \note Will be NMAGeoPositionUnknownValue if unknown.
 */
@property (nonatomic, readonly) double course;

/**
 * The time at which the position measurements were taken.
 */
@property (nonatomic, readonly, strong) NSDate *timestamp;

/**
 * \brief Building ID of this position.
 *
 * @return nil if building ID is not available.
 */
@property (nonatomic, readonly, strong) NSString *buildingId;

/*
 * \brief Building name in human readable format, e.g. "London Heathrow Airport".
 * There can be different buildings with the same name.
 *
 * @return nil if building name is not available
 */
@property (nonatomic, readonly, strong) NSString *buildingName;

/**
 * \brief FloorId is an integer identifying the floor level in the building.
 *
 * Floor id 0 specifies the floor that is considered the Main Level of the building.
 * In the case building has multiple levels that can be considered as Main Level,
 * the lowest level which can be considered as Main Level will be chosen.
 * Floors below the chosen Main Level will have negative integers
 * and floors above the chosen Main Level will have positive integers:
 * The floor above the Main Level has floor id 1 and the floor below the Main Level has floor id -1.
 *
 * @return nil if floor ID is not available.
 */
@property (nonatomic, readonly, strong) NSNumber* floorId;

/**
 * \brief Source of position.
 */
@property (nonatomic, readonly) NMAGeoPositionSource source;

/**
 * Indicates the validity of the %NMAGeoPosition. The position is valid
 * if its coordinates are valid.
 */
@property (nonatomic, readonly) BOOL isValid;

@end
/** @} */
