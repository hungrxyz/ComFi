/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAProxyObject.h"
#import "NMAVector3d.h"

/**
 * \addtogroup NMA_Streetlevel NMA Street Level Group
 * @{
 */


/**
 * \class NMAStreetLevelBuilding NMAStreetLevelBuilding.h "NMAStreetLevelBuilding.h"
 *
 * NMAStreetLevelBuilding represents a building inside an NMAStreetLevelView.
 *
 * \note The building geo coordinates can be obtained from the
 * \link NMAViewObject::location\endlink property
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMAStreetLevelBuilding : NMAProxyObject

/**
 * Unique consistent identifier for the building represented by this NMAStreetLevelBuilding
 * instance.
 *
 * \note The identifier value is consistent across application sessions for the same building.
 */
@property (nonatomic, readonly) NSString *buildingId;

/**
 * Highlight intensity for this NMAStreetLevelBuilding.
 *
 * \note The valid range is from 0.0 to 1.0, where 0.0 represents no highlighting. Invalid
 * values will be clamped to this range.
 */
@property (nonatomic) float highlight;

/**
 * Finds the closest position on the surface of the building to the specified geocoordinates.
 *
 * \param coordinates The NMAGeoCoordinates to find the closest position to.
 * \param distanceLimit The maximum distance to consider when searching positions. A negative value denotes no limit.
 * \return The NMAGeoCoordinates representing the surface position closest to the specified geocoordinates, or nil
 * if a position could not be found within the distance limit.
 */
- (NMAGeoCoordinates *)closestPositionToGeoCoordinates:(NMAGeoCoordinates *)coordinates withDistanceLimit:(float)distanceLimit;

@end
/**  @}  */
