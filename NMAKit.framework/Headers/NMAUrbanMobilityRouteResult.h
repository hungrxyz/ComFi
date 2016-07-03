/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilityOperator.h"

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */


/**
 * \class NMAUrbanMobilityRouteResult NMAUrbanMobilityRouteResult.h "NMAUrbanMobilityRouteResult.h"
 * The Urban Mobility Route Result containing a result for a query.
 * Array of %NMAUrbanMobilityOperator, %NMAUrbanMobilityOperatorDisclaimer are related to
 * calculated array of %NMAUrbanMobilityRoute.
 */
@interface NMAUrbanMobilityRouteResult : NSObject

/**
 * Array of possible %NMAUrbanMobilityRoute.
 */
@property (nonatomic, readonly) NSArray *routes;

/**
 * Array of %NMAUrbanMobilityOperator which helped supply all calculated routes.
 * It's common array of unique %NMAUrbanMobilityOperator that supply public transport for all calculated routes.
 * To find the operator for a particular %NMAUrbanMobilityRoute, please see %NMAUrbanMobilityDeparture::NMAUrbanMobilityLine::transitOperator.
 */
@property (nonatomic, readonly) NSArray *operators;

/**
 * Array of associated %NMAUrbanMobilityOperatorDisclaimer.
 * It's a array of %NMAUrbanMobilityOperatorDisclaimer that are available for all calculated routes.
 * To find the disclaimers for a particular %NMAUrbanMobilityRouteSection, please see %NMAUrbanMobilityRoute::sections::operatorDisclaimers.
 */
@property (nonatomic, readonly) NSArray *operatorDisclaimers;

/**
 * Get alerts and disruptions associated with all calculated routes.
 * To find the alerts for a particular %NMAUrbanMobilityRouteSection, please see %NMAUrbanMobilityRoute::sections::alerts.
 * \return an array of %NMAUrbanMobilityAlert.
 */
@property (nonatomic, readonly) NSArray *alerts;

/**
 * Indicates if it's possible to calculate subsequent route for given result.
 * Return YES if result can be used to calculate subsequent routes, NO otherwise.
 *
 * /see %NMAUrbanMobilityRouter.
 */
@property (nonatomic, readonly, getter = isSubsequentRouteSupported) BOOL subsequentRouteSupported;

@end
/** @}  */
