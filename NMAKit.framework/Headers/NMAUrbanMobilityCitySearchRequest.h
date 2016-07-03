/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilitySearchRequest.h"
#import <Foundation/Foundation.h>
@class NMAUrbanMobilityCitySearchResult;

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * \class NMAUrbanMobilityCitySearchRequest NMAUrbanMobilityCitySearchRequest.h "NMAUrbanMobilityCitySearchRequest.h"
 *
 * \brief Represents a request used for search for public transit coverage by city.
 *
 * NMAUrbanMobilityCitySearchRequest assembles and issues requests to the HERE backend server
 * by providing a query string and configuration flag for China.
 *
 * The HERE backend server responds with either a list of %NMACity or NSError if something goes wrong.
 * Use %NMAUrbanMobilityCitySearchCompletionBlock to capture the response.
 *
 * \sa NMAUrbanMobilityCitySearchCompletionBlock
 * \sa NMACity
 */

typedef void (^NMAUrbanMobilityCitySearchCompletionBlock)(NMAUrbanMobilityCitySearchResult *searchResult, NSError *error);


@interface NMAUrbanMobilityCitySearchRequest : NMAUrbanMobilitySearchRequest

/**
 * Optional parameter. Enables Pop (population of a city) and array of %NMAUrbanMobilityOperator in the %NMAUrbanMobilityCity list. Otherwise, the %NMAUrbanMobilityCity doesn't contain that informations.
 * Only applicable for the cities list, the nearby list never contains details
 * NO = disabled, YES = enabled
 * The default is YES.
 * Parameter is added to request only if user sets value.
 */
@property (nonatomic, getter = isRequestCityDetailsEnabled) BOOL requestCityDetailsEnabled;

/**
 * Optional parameter. Limits the number of cities the response can contain. Default value is 0. Parameter is added to request if it's value is greater than 0.
 */
@property (nonatomic) NSInteger maximumResults;

/**
 * Creates a new %NMAUrbanMobilityCitySearchRequest represents a request used for search public transit coverage by city
 *
 * \param cityName specifies the search text for the city name.
 *
 */
- (instancetype)initWithSearchText:(NSString *)cityName;

/**
 * Sends the request to retrieve a public transit coverage by city.
 * Request processing is performed asynchronously: %NMAUrbanMobilityCitySearchCompletionBlock is used to pass the response.
 *
 * \param completion %NMAUrbanMobilityCitySearchCompletionBlock which is used to pass the response.
 * \return YES if the request was triggered successfully, NO otherwise.
 *
 * \note %NMAUrbanMobilityCitySearchCompletionBlock is called on the main queue.
 *
 * \sa NMAUrbanMobilityCitySearchCompletionBlock
 */
- (BOOL)startWithCompletionBlock:(NMAUrbanMobilityCitySearchCompletionBlock)completion;

@end
/** @}  */
