/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilitySearchRequest.h"

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * \brief Name matching mode which is used when searching for transit stations.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilitySearchNameMatchingMethod) {
    /** \brief Search mode is not specified: up to the HERE backend server to decide. */
    NMAUrbanMobilitySearchNameMatchingMethodUnspecified = 0,

    /** \brief Strict name match mode: names should be strictly equal. */
    NMAUrbanMobilitySearchNameMatchingMethodStrict,

    /** \brief Fuzzy name match mode: names are allowed to be slightly different. */
    NMAUrbanMobilitySearchNameMatchingMethodFuzzy
};

/**
 * \brief Defines a callback which is triggered on the completion of a station search request.
 * The resulting callback contains an array of %NMAUrbanMobilityStation or %NSError.
 *
 * NMAUrbanMobilityStationSearchCompletionBlock is used with
 * \link NMAUrbanMobilityStationSearchRequest::startWithCompletionBlock:(NMAUrbanMobilityStationSearchCompletionBlock)\endlink
 * to provide a callback for capturing responses from the HERE backend server.
 *
 * \param stations Array of %NMAUrbanMobilityStation returned by the HERE backend server.
 * \param error An error which occurred when searching for transit stations. Error codes are defined in %NMAUrbanMobilityError.
 *
 * \sa NMAUrbanMobilityStationSearchRequest::startWithCompletionBlock:(NMAUrbanMobilityStationSearchCompletionBlock)
 * \sa NMAUrbanMobilityStation
 * \sa NMAUrbanMobilityError
 */
typedef void (^NMAUrbanMobilityStationSearchCompletionBlock)(NSArray *stations, NSError *error);


/**
 * \class NMAUrbanMobilityStationSearchRequest NMAUrbanMobilityStationSearchRequest.h "NMAUrbanMobilityStationSearchRequest.h"
 *
 * \brief Represents a request to search for transit station nearby a given location.
 *
 * NMAUrbanMobilityStationSearchRequest assembles and issues requests to the HERE backend server
 * by providing either a location (with some extra optional properties) or an array of specific station IDs which needs to be found.
 *
 * The HERE backend server responds with either an array of %NMAUrbanMobilityStation objects or %NSError if something goes wrong.
 * Use %NMAUrbanMobilityStationSearchCompletionBlock to capture the response.
 *
 * \sa NMAUrbanMobilityStationSearchCompletionBlock
 * \sa NMAUrbanMobilityStation
 * \sa NMAUrbanMobilityError
 */
@interface NMAUrbanMobilityStationSearchRequest : NMAUrbanMobilitySearchRequest

/**
 * Creates a new %NMAUrbanMobilityStationSearchRequest to search for transit stations around a given location.
 *
 * Use optional properties to fine tune the search: searchRange, stationName, nameMatchingMethod
 *
 * \param location Geo coordinates to search for nearby transit stations around.
 */
- (instancetype)initWithLocation:(NMAGeoCoordinates *)location;

/**
 * Creates a new %NMAUrbanMobilityStationSearchRequest to search for transit stations with given IDs.
 *
 * \param stationIds Array of transit station IDs to search for.
 */
- (instancetype)initWithStationIds:(NSArray *)stationIds;

/**
 * Sends the request to search for transit stations to the HERE backend server.
 * Request processing is performed asynchronously: %NMAUrbanMobilityStationSearchCompletionBlock is used to pass the response.
 *
 * \param completion %NMAUrbanMobilityStationSearchCompletionBlock which is used to pass the response.
 * \return YES if the request was triggered successfully, NO otherwise.
 *
 * \note %NMAUrbanMobilityStationSearchCompletionBlock is called on the main queue.
 *
 * \sa NMAUrbanMobilityStationSearchCompletionBlock
 */
- (BOOL)startWithCompletionBlock:(NMAUrbanMobilityStationSearchCompletionBlock)completion;

/**
 * Array of transit station IDs to search for.
 *
 * \note If station ID array is specified then all other request options (e.g. location) will have no effect.
 */
@property (nonatomic, readonly) NSArray *stationIds;

/**
 * Geo coordinates to search for nearby stations around.
 *
 * \note Search range is controlled with searchRange property.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

/**
 * Range in meters which is used to search for nearby transit stations around a given location.
 *
 * \note Default value is 0 which means the HERE backend server default.
 */
@property (nonatomic) NSUInteger searchRange;

/**
 * Name which is used to match nearby station names.
 * Matching strictness is controlled by nameMatchingMethod property.
 *
 * \note Default value is the empty string which means that station names are not accounted during the search.
 */
@property (nonatomic) NSString *stationName;

/**
 * Name matching method defines the fuzziness of the name matching.
 * %NMAUrbanMobilitySearchNameMatchingMethodStrict means that names must be strictly equal to get matched.
 * %NMAUrbanMobilitySearchNameMatchingMethodFuzzy allows some difference between names being matched.
 *
 * \note Default value is NMAUrbanMobilitySearchNameMatchingMethodUnspecified which means that it is up to the HERE backend server to decide.
 */
@property (nonatomic) NMAUrbanMobilitySearchNameMatchingMethod nameMatchingMethod;

@end
/** @}  */
