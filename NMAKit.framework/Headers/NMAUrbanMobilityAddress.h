/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;
@class NMAAddress;


/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * \class NMAUrbanMobilityAddress NMAUrbanMobilityAddress.h "NMAUrbanMobilityAddress.h"
 *
 * Geo coordinates and address information of a geographic location.
 *
 * \note Address information might not be available.
 *
 * \sa NMAAddress
 */
@interface NMAUrbanMobilityAddress : NSObject

/**
 * Address information for the geographic location.
 */
@property (nonatomic, readonly) NMAAddress *address;

/**
 * Geo coordinates of the geographic location.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

@end
/** @}  */
