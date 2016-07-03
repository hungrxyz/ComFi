/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilitySearchRequest.h"

@class NMAGeoCoordinates;
@class NMAUrbanMobilityCityCoverageResult;

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * ENUM values for \sa updatetype parameter.
 */
typedef NS_ENUM(NSUInteger, NMACoverageUpdateType) {
    /** \brief The resulting response contains only cities that are new (to HERE transit service) since the given date and time. */
    NMACoverageUpdateTypeNew = 0,  //0
    /** \brief The resulting response contains only cities with updated coverage information since the specified date and time. */
    NMACoverageUpdateTypeUpdated,  //1
    /** \brief The resulting response contains cities that are either updated or new since a given date and time. */
    NMACoverageUpdateTypeAll       //2
};


@interface NMAUrbanMobilityCityCoverageRequest : NMAUrbanMobilitySearchRequest

/**
 * \class NMAUrbanMobilityCityCoverageRequest NMAUrbanMobilityCityCoverageRequest.h "NMAUrbanMobilityCityCoverageRequest.h"
 *
 * \brief Represents a request used to get a list of cities where we have transit coverage,
 * as well as list of transit operators, from a given location, within a certain radius.
 *
 * NMAUrbanMobilityCityCoverageRequest assembles and issues requests to the HERE backend server.
 *
 * The HERE backend server responds with either a list of %NMACity or NSError if something goes wrong.
 * Use %NMAUrbanMobilityCitySearchCompletionBlock to capture the response.
 *
 * \sa NMAUrbanMobilityCitySearchCompletionBlock
 * \sa NMACity
 */

/**
 *
 * \brief test words here.
 *
 *
 * We should test and see what is happening here.
 *
 */


typedef void (^NMAUrbanMobilityCityCoverageRequestCompletionBlock)(NMAUrbanMobilityCityCoverageResult *coverageResult, NSError *error);

/**
 * Optional parameter. Enables Pop (population of a city) and array of %NMAUrbanMobilityOperator in the %NMAUrbanMobilityCity list. Otherwise, the %NMAUrbanMobilityCity doesn't contain that informations.
 * Only applicable for the cities list, the nearby list never contains details
 * NO = disabled, YES = enabled
 * The default is YES.
 * Parameter is added to request only if client sets value.
 */
@property (nonatomic, getter = isRequestCityDetailsEnabled) BOOL requestCityDetailsEnabled;

/**
 * Optional parameter.
 * Set maximum number of cities returned in a separate "nearby" list.
 * Enables a separate list for nearby cities. The resulting response contains a separate list of cities without any details.
 * Cities with zero relevancy are included in the nearby list. All cities with a relevancy greater than 0 are shown in the "main" cities list.
 */
@property (nonatomic) NSInteger nearbyMax;

/**
 * Optional parameter. Specifies a radius in meters that when combined with a user location (as specified by the parameter location ) defines
 * the area of search. The default value is 150000m.
 */
@property (nonatomic) NSInteger radius;

/**
 * Optional parameter. Specifies the location of the center point of your search
 */
@property (nonatomic) NMAGeoCoordinates *location;

/**
 * Optional parameter. Specifies the date and time to search.
 * If you specify this parameter in your request, the response contains information filtered by given date.
 * Use the %NMACoverageUpdateType parameter to specify filtering behavior.
 */
@property (nonatomic) NSDate *time;

/**
 * Optional parameter, used for filtering data. Used in conjunction with parameter \sa time.
 */
@property (nonatomic) NMACoverageUpdateType updateType;

/**
 * Optional parameter. Limits the number of cities the response can contain. Default value is 0. Parameter is added to request if it's value is greater than 0.
 */
@property (nonatomic) NSInteger maximumResults;


/**
 * Sends the request to retrieve public transit coverage by city.
 * Request processing is performed asynchronously: %NMAUrbanMobilityCityCoverageRequestCompletionBlock is used to pass the response.
 *
 * \param completion %NMAUrbanMobilityCityCoverageRequestCompletionBlock which is used to pass the response.
 * \return YES if the request was triggered successfully, NO otherwise.
 *
 * \note %NMAUrbanMobilityCityCoverageRequestCompletionBlock is called on the main queue.
 *
 * \sa NMAUrbanMobilityCityCoverageRequestCompletionBlock
 */
- (BOOL)startWithCompletionBlock:(NMAUrbanMobilityCityCoverageRequestCompletionBlock)completion;

@end
/** @}  */
