/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilityDeparture.h"
#import "NMAUrbanMobilityArrival.h"

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * \class NMAUrbanMobilityRouteSection NMAUrbanMobilityRouteSection.h "NMAUrbanMobilityRouteSection.h"
 * Represents information about a single section/segment of a %NMAUrbanMobilityRoute, which is covered
 * by a single %NMAUrbanMobilityRouteSectionTransit section or is a pedestrian %NMAUrbanMobilityRouteSectionWalk section.
 */

@interface NMAUrbanMobilityRouteSection : NSObject

/**
 * A unique id for this section.
 */
@property (nonatomic, readonly) NSString *sectionId;

/**
 * Array of%NMAGeoCoordinates representing the geometry of this section.
 */
@property (nonatomic, readonly) NSArray *geometry;

/**
 * Array of %NMAUrbanMobilityDeparture containing relevant departure object.
 */
@property (nonatomic, readonly) NMAUrbanMobilityDeparture *departure;

/**
 * Array of %NMAUrbanMobilityArrival containing relevant departure object.
 */
@property (nonatomic, readonly) NMAUrbanMobilityArrival *arrival;

/**
 * Distance in meters to cover by this section.
 */
@property (nonatomic, readonly) NSUInteger distanceMeters;

/**
 * Expected duration in seconds to cover that distance.
 */
@property (nonatomic, readonly) NSUInteger durationSeconds;

/**
 * This can be used in some cases to inform about which kind of routing were used and which kind of routing would be available
 * if we would have correct data. Attribute takes XX/XX values. Currently SR/SR value is used in some regions to tell
 * that simple routing where used and that simple routing is also best what is available for that region.
 */
@property (nonatomic, readonly) NSString *quality;

/**
 * The times specified a number of minutes of uncertainly.
 */
@property (nonatomic, readonly) NSUInteger uncertainity;

/**
 * Array of %NMAUrbanMobilityManeuver for this section.
 */
@property (nonatomic, readonly) NSArray *maneuvers;

/**
 * Array of %NMAUrbanMobilityOperatorDisclaimer related to this section.
 */
@property (nonatomic, readonly) NSArray *operatorDisclaimers;

/**
 * Array of associated %NMAUrbanMobilityAlert.
 */
@property (nonatomic, readonly) NSArray *alerts;

@end

/** @}  */
