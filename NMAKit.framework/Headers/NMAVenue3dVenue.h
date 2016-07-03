/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <CoreGraphics/CoreGraphics.h>
#import "NMAVenue3dSpatialObject.h"

@class NMAGeoCoordinates;
@class NMAGeoBoundingBox;
@class NMAVenue3dAnimationParameters;
@class NMAVenue3dContent;
@class NMAVenue3dLevel;
@class NMAVenue3dSpace;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 *
 * The Venue Maps 3D group provides classes, protocols, and enumerations
 * for representing a group of public buildings in a map.
 *
 * @{
 */


/**
 * \class NMAVenue3dVenue NMAVenue3dVenue.h "NMAVenue3dVenue.h"
 *
 * \brief NMAVenue3dVenue represents a public building or a group of public buildings in a map.
 *
 * Examples of public buildings are shopping malls and airports. Venues are displayed or hidden depending on map location.
 * <p>
 * A NMAVenue3dVenue object consists of one or more NMAVenue3dLevel objects. NMAVenue3dLevel, in turn,
 * consists of one or more NMAVenue3dOuterArea objects. NMAVenue3dOuterArea represents a physical form of
 * an outer area of certain level in the building. An NMAVenue3dOuterArea typically contains NMAVenue3dSpace
 * objects that represent, for example, single shops inside the venue.
 * </p>
 *
 * \note NMAVenue3dVenue cannot be instantiated directly. Instead, it can be obtained by calling
 * \link NMAVenue3dController::venue\endlink or
 * \link NMAVenue3dServiceListener::venueService:didGetVenue:\endlink
 * callback.
 *
 * \sa NMAVenue3dLevel
 * \sa NMAVenue3dOuterArea
 * \sa NMAVenue3dSpace
 * \sa NMAVenue3dController
 */
@interface NMAVenue3dVenue : NMAVenue3dSpatialObject

/**
 * The center of the NMAVenue3dVenue bounding box.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *geoCenter;

/**
 * The bounding box of this <code>NMAVenue3dVenue</code>.
 */
@property (nonatomic, readonly) NMAGeoBoundingBox *boundingBox;

/**
 * The current floor number. For ground floor it's 0. For underground floors:
 * -1, -2, -3... For above ground floors: 1, 2, 3...
 */
@property (nonatomic, readonly) NSInteger floorNumber;

/**
 * The ground floor number.
 */
@property (nonatomic, readonly) NSInteger groundFloorNumber;

/**
 * The array of NMAVenue3dLevel objects of this NMAVenue3dVenue.
 */
@property (nonatomic, readonly) NSArray *levels;

/**
 * The alphabetically level-wise ordered array of NMAVenue3dSpace objects for this NMAVenue3dVenue.
 */
@property (nonatomic, readonly) NSArray *spaces;

/**
 * The NMAVenues3dContent object this NMAVenue3dVenue.
 */
@property (nonatomic, readonly) NMAVenue3dContent *content;

/**
 * Return the space or the facility as the NMAVenue3dSpace object based on the given identifier
 * inside this NMAVenue3dVenue.
 *
 * @param  spaceId The NMAVenue3dSpace identifier
 *
 * @return The {@link NMAVenue3dSpace} object or nil if there is no {@link NMAVenue3dSpace} with this identifier.
 */
- (NMAVenue3dSpace *)spaceWithId:(NSString *)spaceId;

@end
/** @} */
