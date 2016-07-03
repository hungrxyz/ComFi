/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;


/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * \class NMAUrbanMobilityAccessPoint NMAUrbanMobilityAccessPoint.h "NMAUrbanMobilityAccessPoint.h"
 *
 * Access point of a transit station.
 *
 * \sa NMAUrbanMobilityTransitStation
 */
@interface NMAUrbanMobilityAccessPoint : NSObject

/**
 * Unique ID of the access point.
 */
@property (nonatomic, readonly) NSString *accessPointId;

/**
 * Name of the access point.
 */
@property (nonatomic, readonly)  NSString *name;

/**
 * Geo coordinates of the access point.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

@end
/** @}  */
