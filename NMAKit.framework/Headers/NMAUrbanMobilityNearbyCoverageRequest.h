/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilitySearchRequest.h"
#import <Foundation/Foundation.h>

@class NMAUrbanMobilityCityCoverageResult;
@class NMAUrbanMobilityNearbyCoverageResult;




/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

typedef void (^NMAUrbanMobilityNearbyCoverageRequestCompletionBlock)(NMAUrbanMobilityNearbyCoverageResult *nearbyCoverageResult, NSError *error);


/**
 * \class NMAUrbanMobilityNearbyCoverageRequest NMAUrbanMobilityNearbyCoverageRequest.h "NMAUrbanMobilityNearbyCoverageRequest.h"
 *
 * \brief Represents a request used for retrieve coverage information about nearby cities.
 *
 * NMAUrbanMobilityNearbyCoverageRequest assembles and issues requests to the HERE backend server.
 *
 * The HERE backend server responds with  %NMAUrbanMobilityNearbyCoverageResult or NSError if something goes wrong.
 * Use %NMAUrbanMobilityNearbyCoverageRequestCompletionBlock to capture the response.
 *
 * \sa NMAUrbanMobilityNearbyCoverageRequestCompletionBlock
 * \sa NMAUrbanMobilityNearbyCoverageResult
 */

@interface NMAUrbanMobilityNearbyCoverageRequest : NMAUrbanMobilitySearchRequest

/**
 * Optional parameter. Enables Pop (population of a city) and array of %NMAUrbanMobilityOperator in the %NMAUrbanMobilityCity list. Otherwise, the %NMAUrbanMobilityCity doesn't contain that informations.
 * Only applicable for the cities list, the nearby list never contains details
 * NO = disabled, YES = enabled
 * The default is YES.
 * Parameter is added to request only if user sets value.
 */
@property (nonatomic, getter = isRequestCityDetailsEnabled) BOOL requestCityDetailsEnabled;

/**
 * Creates a new %NMAUrbanMobilityNearbyCoverageRequest for searching nearest coverage with a given geo coordinates.
 *
 * \param location Geo coordinates of the location.
 *
 */
- (instancetype)initWithLocation:(NMAGeoCoordinates *)location;

/**
 * Sends the request to the HERE backend server to retrieve a nearby coverage data.
 * Request processing is performed asynchronously: %NMAUrbanMobilityNearbyCoverageRequestCompletionBlock is used to pass the response.
 *
 * \param completion %NMAUrbanMobilityNearbyCoverageRequestCompletionBlock which is used to pass the response.
 * \return YES if the request was triggered successfully, NO otherwise.
 *
 * \note %NMAUrbanMobilityNearbyCoverageRequestCompletionBlock is called on the main queue.
 *
 * \sa NMAUrbanMobilityNearbyCoverageRequestCompletionBlock
 */
- (BOOL)startWithCompletionBlock:(NMAUrbanMobilityNearbyCoverageRequestCompletionBlock)completion;

@end
/** @}  */
