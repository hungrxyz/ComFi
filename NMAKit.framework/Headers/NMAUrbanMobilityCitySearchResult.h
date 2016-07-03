/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */


/**
 * \class NMAUrbanMobilityCitySearchResult NMAUrbanMobilityCitySearchResult.h "NMAUrbanMobilityCitySearchResult.h"
 *
 * \brief Lists of %NMAUrbanMobilityCity where were have transit coverage, as well as list of transit operators,
 * from a given location, within a certain radius. Used in %NMAUrbanMobilityCityCoverageRequest.
 */

@interface NMAUrbanMobilityCitySearchResult : NSObject

/**
 * List of %NMAUrbanMobilityCity
 */
@property (nonatomic, readonly) NSArray *cities;

/**
 * Total count of timetable supported cities.
 */
@property (nonatomic, readonly) NSInteger timeTableCount;

/**
 * Total count of simple routing supported cities.
 */
@property (nonatomic, readonly) NSInteger simpleRoutingCount;

/**
 * Total count of realtime (which are connected directly to 3rd-party api) supported cities.
 */
@property (nonatomic, readonly) NSInteger realTimeCount;

/**
 * This reflects to most updated available coverage data. Client can save this and when checking new updates set time-parameter as given here.
 */
@property (nonatomic, readonly) NSDate *refTime;

@end
/** @}  */
