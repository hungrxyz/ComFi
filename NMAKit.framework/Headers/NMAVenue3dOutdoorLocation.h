/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dBaseLocation.h"

@class NMAGeoCoordinates;


/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * \class NMAVenue3dOutdoorLocation "NMAVenue3dOutdoorLocation.h"
 *
 * \brief Defines an outdoor location used as either start- or endpoint in indoor routing.
 *
 * \sa NMAVenue3dSpaceLocation
 * \sa NMAVenue3dOutdoorLocation
 * \sa NMAVenue3dRoutingController
 */
@interface NMAVenue3dOutdoorLocation : NMAVenue3dBaseLocation

/**
 * Constructs a NMAOutdoorLocation with the specified geocoordinates.
 *
 * \param geoCoordinates A geocoordinate object
 */
+ (instancetype)outdoorLocationWithGeoCoordinates:(NMAGeoCoordinates *)geoCoordinates;

@end
/** @} */
