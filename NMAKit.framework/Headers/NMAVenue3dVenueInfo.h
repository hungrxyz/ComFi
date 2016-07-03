/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dSpatialObject.h"

@class NMAGeoBoundingBox;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */


/**
 * \class NMAVenue3dVenueInfo NMAVenue3dVenueInfo.h "NMAVenue3dVenueInfo.h"
 *
 * \brief NMAVenue3dVenueInfo contains identification and location information for a venue.
 *
 * This class is returned by search methods
 * \link NMAVenue3dService::venuesInGeoBoundingBox:\endlink and
 * \link NMAVenue3dService::venueWithId:\endlink.
 * The NMAMapView can be centered based on geocoordinates of the venue returned by \link boundingBox\endlink.
 * A venue can be opened using the venue identifier returned by <code>uniqueId</code>.
 */
@interface NMAVenue3dVenueInfo : NMAVenue3dSpatialObject

/**
 * The {@link NMAGeoBoundingBox} of the venue. A NMAGeoBoundingBox is an area defined by minimum and
 * maximum longitudes and latitudes of the venue.
 */
@property (nonatomic, readonly) NMAGeoBoundingBox *boundingBox;

/**
 * The name of the venue.
 */
@property (nonatomic, readonly) NSString *name;

@end
/** @} */
