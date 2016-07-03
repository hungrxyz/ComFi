/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
@class NMAGeoCoordinates;
@class NMAUrbanMobilityMissingCoverage;

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */


/**
 * \class NMAUrbanMobilityCity NMAUrbanMobilityCity.h "NMAUrbanMobilityCity.h"
 *
 * \brief  contains all available information about a city.
 */

@interface NMAUrbanMobilityCity : NSObject

/*
 * Name of the city. It's the localized name.
 */
@property (nonatomic, readonly) NSString *name;

/*
 * Giving hint how name, state and contry could be displayed in screen. There is no guarantee that this hint would actually be correct. Nil if not available.
 */
@property (nonatomic, readonly) NSString *displayName;

/*
 * Name of the country that city belongs to. It's the localized name.
 */
@property (nonatomic, readonly) NSString *country;

/*
 * Name of the state that city belongs to. It's the localized name.
 */
@property (nonatomic, readonly) NSString *state;

/**
 * Geo coordinates of place which is being requested.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

/*
 * Date when information about the city was created.
 */
@property (nonatomic, readonly) NSDate *created;

/*
 * Date when information about the city was updated.
 */
@property (nonatomic, readonly) NSDate *updated;

/*
 * Is value 0..1 putting weight how relevant some city should be for user when user is in some specifig location.
 * This will mostly give correct results but it cannot be guaranteed. -1 if not available.
 */
@property (nonatomic, readonly) double relevancy;

/*
 * Distance to be used when user coordinates are known. -1 if not available.
 */
@property (nonatomic, readonly) NSInteger distance;

/*
 * Array of %NMAUrbanMobilityOperator serving city. Nil if not available.
 */
@property (nonatomic, readonly) NSArray *operators;

/*
 * City population. -1 if not available.
 */
@property (nonatomic, readonly) NSInteger population;

/*
 * Array of coverage data %%NMAUrbanMobilityProvider. Nil if not available.
 */
@property (nonatomic, readonly) NSArray *providers;


/*
 * Detailed coverage information: the percentage of the city coverage in between 0.0 (nothing covered)
 * and 1.0 (completely covered). -1 if not available.
 */
@property (nonatomic, readonly) float quality;

/*
 * Detailed coverage information: number of lines found inside city. -1 if not available.
 */
@property (nonatomic, readonly) NSInteger linesCount;

/*
 * Detailed coverage information: number of stops found inside city. -1 if not available.
 */
@property (nonatomic, readonly) NSInteger stopsCount;

/*
 * %NMAUrbanMobilityMissingCoverage contains information about if operators, lines or time tables are missing. Nil if not available.
 */
@property (nonatomic, readonly) NMAUrbanMobilityMissingCoverage *missingCoverage;

@end
/** @}  */
