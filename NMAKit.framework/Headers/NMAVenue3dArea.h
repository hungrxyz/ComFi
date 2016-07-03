/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVenue3dSpatialObject.h"

@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */


/**
 * \class NMAVenue3dArea NMAVenue3dArea.h "NMAVenue3dArea.h"
 *
 * \brief An NMAVenue3dArea object conceptually represents a physical area within a NMAVenue3dVenue.

 * The area can be of either NMAVenue3dOuterArea or NMAVenue3dSpace type, which both have a bounding box and
 * center coordinates. The NMAVenue3dArea class encapsulates these parameters.
 * <p>
 * This class can not be instantiated directly. Subclasses NMAVenue3dOuterArea and NMAVenue3dSpace can be
 * obtained by methods of NMAVenue3dLevel.
 * </p>
 *
 * \sa NMAVenue3dVenue
 * \sa NMAVenue3dLevel
 * \sa NMAVenue3dOuterArea
 * \sa NMAVenue3dSpace
 */
@interface NMAVenue3dArea : NMAVenue3dSpatialObject

/**
 * The NMAGeoCoordinates representing the center of the bounding box of the NMAVenue3dArea.
 *
 * \sa NMAGeoCoordinates
 */
@property (nonatomic, readonly) NMAGeoCoordinates *geoCenter;

/**
 * The NMAGeoBoundingBox representing the area of the NMAVenue3dArea.
 *
 * \sa NMAGeoBoundingBox
 */
@property (nonatomic, readonly) NMAGeoBoundingBox *boundingBox;

/**
 * The NSString representing the human-readable name related to the holder
 * of the spatial area. This can be, for example, the name of a shop.
 */
@property (nonatomic, readonly) NSString *name;

@end
/** @} */
