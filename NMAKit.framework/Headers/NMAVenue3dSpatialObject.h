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
 * \class NMAVenue3dSpatialObject "NMAVenue3dSpatialObject.h"
 *
 * \brief Represents a physical space in a map. This space is defined by a unique identifier of the space.
 *
 * \sa NMAVenue3dArea
 * \sa NMAVenue3dOuterArea
 * \sa NMAVenue3dSpace
 * \sa NMAVenue3dVenue
 */
@interface NMAVenue3dSpatialObject : NSObject

/**
 * The string which uniquely identifies this NMAVenue3dSpatialObject.
 */
@property (nonatomic, readonly) NSString *uniqueId;

@end
/** @} */
