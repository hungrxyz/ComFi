/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import "NMAUrbanMobilityCitySearchResult.h"

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */


/**
 * \class NMAUrbanMobilityCityCoverageResult NMAUrbanMobilityCityCoverageResult.h "NMAUrbanMobilityCityCoverageResult.h"
 *
 * \brief Lists of %NMAUrbanMobilityCity where were have transit coverage, as well as list of transit operators,
 * from a given location, within a certain radius. Used in %NMAUrbanMobilityCitySearchRequest.
 */

@interface NMAUrbanMobilityCityCoverageResult : NMAUrbanMobilityCitySearchResult

/**
 * List of %NMAUrbanMobilityCity
 */
@property (nonatomic, readonly) NSArray *nearbyCities;


@end
/** @}  */
