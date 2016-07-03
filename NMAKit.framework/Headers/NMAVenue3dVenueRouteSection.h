/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dRouteSection.h"

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */


/**
 * \class NMAVenue3dVenueRouteSection "NMAVenue3dVenueRouteSection.h"
 *
 * \brief Represents route section inside a venue. Indoor route can contain
 *        sections that are inside venue, outside venue, and link sections
 *        that typically connects indoor and outdoor locations.
 *
 * \sa    NMAVenue3dOutdoorRouteSection
 * \sa    NMAVenue3dLinkRouteSection
 */
@interface NMAVenue3dVenueRouteSection : NMAVenue3dRouteSection

/**
 * The array of NMAVenue3dRouteManeuver objects for this route section.
 */
@property (nonatomic, readonly) NSArray *routeManeuvers;

@end
/** @} */
