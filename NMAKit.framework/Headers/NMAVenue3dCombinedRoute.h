/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */


/**
 * \class NMAVenue3dCombinedRoute "NMAVenue3dCombinedRoute.h"
 *
 * \brief Describes route from start to end point. The route is splitted to one or more route sections.
 *
 * \sa NMAVenue3dRoutingController
 */
@interface NMAVenue3dCombinedRoute : NSObject

/**
 * The array of NMAVenue3dRouteSection objects for this route.
 *
 * This information can be used to check type of turn-by-turn information available for each route
 * sections of the combined route.
 *
 */
@property (nonatomic, readonly) NSArray *routeSections;

@end
/** @} */
