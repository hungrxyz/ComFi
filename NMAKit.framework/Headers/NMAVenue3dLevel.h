/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_VenueMaps3d NMA Venue Maps 3D Group
 * @{
 */


/**
 * \class NMAVenue3dLevel NMAVenue3dLevel.h "NMAVenue3dLevel.h"
 *
 * \brief Represents a storey in a venue.
 *
 * A NMAVenue3dVenue object consists of one or more NMAVenue3dLevel objects. The NMAVenue3dLevel object
 * in turn consist of one or more NMAVenue3dOuterArea objects.
 * <p>
 * NMAVenue3dLevel cannot be instantiated directly. Instead, it can be obtained by calling the
 * \link NMAVenue3dVenue::levels\endlink.
 * </p>
 *
 * \sa NMAVenue3dVenue
 * \sa NMAVenue3dOuterArea
 * \sa NMAVenue3dVenueController
 *
 */
@interface NMAVenue3dLevel : NSObject

/**
 * The array of NMAVenue3dOuterArea objects for this NMAVenue3dLevel.
 *
 * Depending on the physical appearance of the building, the NMAVenue3dLevel can consist of one or more separate
 * NMAVenue3dOuterArea objects. The NMAVenue3dOuterArea object can be used to get the NMAVenue3dSpace objects
 * related to the NMAVenue3dOuterArea objects.
 *
 */
@property (nonatomic, readonly) NSArray *outerAreas;

/**
 * The center of the NMAVenue3dLevel.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *geoCenter;

/**
 * The alphabetically ordered array of NMAVenue3dSpace objects for this NMAVenue3dLevel, excluding facilities.
 *
 * This method returns the requested NMAVenue3dSpace objects of all NMAVenue3dOuterArea objects of this
 * NMAVenue3dLevel object.
 *
 */
@property (nonatomic, readonly) NSArray *spaces;

/**
 * The alphabetically ordered array of NMAVenue3dSpace objects of all the NMAVenue3dOuterArea objects
 * of this NMAVenue3dLevel.
 */
@property (nonatomic, readonly) NSArray *spacesAndFacilities;

/**
 * The alphabetically-ordered array of NMAVenue3dSpace objects belonging to given category
 * for this NMAVenue3dLevel. This method returns matching NMAVenue3dSpace objects for all NMAVenue3dOuterArea
 * objects for this NMAVenue3dLevel object.
 */
- (NSArray *)spacesWithCategory:(NSString *)categoryName;

/**
 * The floor synonym, for example: 1, B, P1, MEZZ etc.
 */
@property (nonatomic, readonly) NSString *floorSynonym;

/**
 * The floor number. For ground floor it's 0. For underground floors: -1, -2, -3... For
 * above ground floors: 1, 2, 3...
 */
@property (nonatomic, readonly) NSInteger floorNumber;

@end
/** @} */
