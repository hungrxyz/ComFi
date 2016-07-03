/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dArea.h"

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */


/**
 * \class NMAVenue3dOuterArea NMAVenue3dOuterArea.h "NMAVenue3dOuterArea.h"
 *
 * \brief The NMAVenue3dOuterArea represents the physical outer area of the NMAVenue3dLevel in the NMAVenue3dVenue.
 *
 * There may be several outer areas for the level, depending on the physical appearance of the building.
 * This class can be used to get NMAVenue3dSpace objects related to this
 * outer area.
 * <p>
 * NMAVenue3dOuterArea cannot be instantiated directly. Instead, it can be obtained by calling \link NMAVenue3dLevel::outerAreas\endlink.
 * </p>
 *
 * \sa NMAVenue3dVenue
 * \sa NMAVenue3dLevel
 * \sa NMAVenue3dSpace
 * \sa NMAVenue3dVenue
 */
@interface NMAVenue3dOuterArea : NMAVenue3dArea

/**
 * The array of NMAVenue3dSpace objects for this NMAVenue3dOuterArea.
 */
@property (nonatomic, readonly) NSArray *spaces;

@end
/** @} */
