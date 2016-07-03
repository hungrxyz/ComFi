/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dBaseLocation.h"

@class NMAVenue3dSpace;
@class NMAVenue3dController;


/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */

/**
 * \class NMAVenue3dSpaceLocation "NMAVenue3dSpaceLocation.h"
 *
 * \brief Defines an indoor location used as either start- or endpoint in indoor routing.
 *
 * \sa NMAVenue3dSpaceLocation
 * \sa NMAVenue3dOutdoorLocation
 * \sa NMAVenue3dRoutingController
 */

@interface NMAVenue3dSpaceLocation : NMAVenue3dBaseLocation

/**
 * Constructs a NMASpaceLocation with the specified indoor space and venue controller
 * of the venue the space is located.
 *
 * \param space A space object
 * \param venue A venue controller object
 */
+ (instancetype)spaceLocationWithSpace:(NMAVenue3dSpace *)space
                               inVenue:(NMAVenue3dController *)venue;

@end
/** @} */
