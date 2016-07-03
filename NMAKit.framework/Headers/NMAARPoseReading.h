/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_AR NMA LiveSight Group
 * @{
 */


/**
 * \class NMAARPoseReading NMAARPoseReading.h "NMAARPoseReading.h"
 *
 * \brief A model class comprised of the latitude, longitude, altitude, pitch,
 * heading, roll and time stamp for the current LiveSight pose.
 *
 * The pose is a representation of the device position and orientation.
 **/
@interface NMAARPoseReading : NSObject

/**
 * The location (lattitude, longitude, altitude) of the device according to
 * NMAPositionManager.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

/**
 * The x-axis rotation (pitch) of the device in degrees.
 *
 * To facilitate direction of movement calculations the value can be outside of
 * the range [0, 360).
 */
@property (nonatomic, readonly) float pitch;

/**
 * The y-axis rotation (heading or yaw) of the device in degrees.
 *
 * To facilitate direction of movement calculations the value can be outside of
 * the range [0, 360).
 */
@property (nonatomic, readonly) float heading;

/**
 * The z-axis rotation (roll) of the device in degrees.
 *
 * To facilitate direction of movement calculations the value can be outside of
 * the range [0, 360).
 */
@property (nonatomic, readonly) float roll;

/**
 * The timestamp, in seconds since device reboot, at which the pose reading was
 * taken.
 */
@property (nonatomic, readonly) NSTimeInterval timestamp;

@end

/** @}  */
