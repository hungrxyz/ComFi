/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAAddress;
@class NMAGeoBoundingBox;
@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Search  NMA Search Group
 * @{
 */


/**
 * \class NMAPlaceLocation NMAPlaceLocation.h "NMAPlaceLocation.h"
 *
 * Represents a location on a map in terms of a street address and a geographical position.
 */
@interface NMAPlaceLocation : NSObject

/**
 * The NMAAddress for the NMAPlaceLocation.
 */
@property (nonatomic, strong) NMAAddress *address;

/**
 * The descriptive label for the NMAPlaceLocation.
 */
@property (nonatomic, strong) NSString *label;

/**
 * NMAGeoCoordinates for the NMAPlaceLocation if available.
 *
 * \note If you want to create a route to this location please use this property
 * for NMAWaypoint creation. This is referred to as originalPosition in NMAWaypoint.
 */
@property (nonatomic, strong) NMAGeoCoordinates *position;

/**
 * The bounding box of the place location if available.
 */
@property (nonatomic, strong) NMAGeoBoundingBox *boundingBox;

/**
 * An array of NMANavigationPosition objects representing access points to the location.
 * The NMANavigationPosition should be used as navigablePosition of a NMAWaypoint
 * when calculating route to the location.
 *
 * For example, An aiport might have road access point for car routing and public
 * transport access points for public transport routing.
 */
@property (nonatomic, strong, readonly) NSArray *accessPoints;

/**
 * The unique ID of the place location.
 */
@property (nonatomic, strong) NSString *locationId;

/*!
 * Get reference identifiers for a specific source. For example, a place
 * can have a reference to an extruded building object in the map. The
 * reference identifiers can be retrieved by calling this method with source
 * NMAPlacesSourceBuilding.
 *
 * Index 0 is the primary reference identifier for the place.
 *
 * \note A reference identifier will not be returned if it has not been queried
 * with the (see \link NMARequest::addSource:\endlink).
 *
 * \param source %NSString specifying the source.
 *
 * \return An NSArray of reference identifiers. Return nil if reference
 * identifier does not exist.
 */
- (NSArray *)referenceIdentifiersForSource:(NSString *)source;

@end
/** @}  */
