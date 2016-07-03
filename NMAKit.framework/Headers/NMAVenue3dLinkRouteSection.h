/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dRouteSection.h"

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */


/**
 * \class NMAVenue3dLinkRouteSection "NMAVenue3dLinkRouteSection.h"
 *
 * \brief Represents a link section of the route. Indoor route can contain
 *        sections that are inside venue, outside venue, and link sections
 *        that typically connects indoor and outdoor locations.
 *
 * \sa    NMAVenue3dVenueRouteSection
 * \sa    NMAVenue3dOutdoorRouteSection
 */
@interface NMAVenue3dLinkRouteSection : NMAVenue3dRouteSection

/**
 * The geolocation of the start point of the link route.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *from;

/**
 * The geolocation of the end point of the link route.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *to;

@end
/** @} */
