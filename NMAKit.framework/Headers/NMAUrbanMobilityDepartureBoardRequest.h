/*
 * Copyright © 2015-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAUrbanMobilitySearchRequest.h"

@class NMAUrbanMobilityStation;
@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * \brief Defines a callback that is triggered upon the completion of a departure board request.
 *        The resulting completion block contains a list of %NMAUrbanMobilityDeparture or %NSError.
 *
 * NMAUrbanMobilityDepartureBoardCompletionBlock is used with
 * \link NMAUrbanMobilityDepartureBoardRequest::startWithCompletionBlock:(NMAUrbanMobilityDepartureBoardCompletionBlock)\endlink
 * to provide a callback for capturing responses from the HERE backend server.
 *
 * \param departures List of %NMAUrbanMobilityDeparture returned by the HERE backend server.
 * \param error An error which occurred when requesting a departure board. Error codes are defined in %NMAUrbanMobilityError.
 *
 * \sa NMAUrbanMobilityDepartureBoardRequest::startWithCompletionBlock:(NMAUrbanMobilityDepartureBoardCompletionBlock):
 * \sa NMAUrbanMobilityDeparture
 * \sa NMAUrbanMobilityError
 */
typedef void (^NMAUrbanMobilityDepartureBoardCompletionBlock)(NSArray *departures, NSError *error);


/**
 * \class NMAUrbanMobilityDepartureBoardRequest NMAUrbanMobilityDepartureBoardRequest.h "NMAUrbanMobilityDepartureBoardRequest.h"
 *
 * \brief Represents a request to retrieve a departure board for the given transit station.
 *
 * NMAUrbanMobilityDepartureBoardRequest assembles and issues requests to the HERE backend server
 * by providing a station ID, a geo location and some optional properties (such as whether to do a fuzzy search).
 *
 * The HERE backend server responds with either a list of %NMAUrbanMobilityDeparture objects or NSError if something goes wrong.
 * Use %NMAUrbanMobilityDepartureBoardCompletionBlock to capture the response.
 *
 * \sa NMAUrbanMobilityDepartureBoardCompletionBlock
 * \sa NMAUrbanMobilityDeparture
 */
@interface NMAUrbanMobilityDepartureBoardRequest : NMAUrbanMobilitySearchRequest

/**
 * Creates a new %NMAUrbanMobilityDepartureBoardRequest for a departure board at a given transit station.
 *
 * \param station Transit station to request a departure board for.
 */
- (instancetype)initWithStation:(NMAUrbanMobilityStation *)station;

/**
 * Creates a new %NMAUrbanMobilityDepartureBoardRequest for a departure board at a transit station with a given ID and given geo coordinates.
 *
 * \param stationId The unique ID of the transit station.
 * \param location Geo coordinates of the transit station.
 *
 * \note Both station ID and geo coordinates are required to identify a transit station unambiguously.
 */
- (instancetype)initWithStationId:(NSString *)stationId location:(NMAGeoCoordinates *)location;

/**
 * Sends the request to retrieve a departure board to the HERE backend server.
 * Request processing is performed asynchronously: %NMAUrbanMobilityDepartureBoardCompletionBlock is used to pass the response.
 *
 * \param completion %NMAUrbanMobilityDepartureBoardCompletionBlock which is used to pass the response.
 * \return YES if the request was triggered successfully, NO otherwise.
 *
 * \note %NMAUrbanMobilityDepartureBoardCompletionBlock is called on the main queue.
 *
 * \sa NMAUrbanMobilityDepartureBoardCompletionBlock
 */
- (BOOL)startWithCompletionBlock:(NMAUrbanMobilityDepartureBoardCompletionBlock)completion;

/**
 * The unique ID of the transit station where the departure board is being requested.
 */
@property (nonatomic, readonly) NSString *stationId;

/**
 * Geo coordinates of the station which departure board is being requested.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

/**
 * Time which is used as a start point for the departure board being requested.
 * All entries in the departure board are the earliest possible departures after the specified time.
 *
 * \note If this property is not set then the current timestamp is used.
 */
@property (nonatomic) NSDate *departureTime;

/**
 * If set to %NMAUrbanMobilitySearchOptionalFlagNo departures from the nearby stations will also be included in the response.
 *
 * \note The default value is %NMAUrbanMobilitySearchOptionalFlagUnset which means that it is up to the HERE backend server to decide.
 */
@property (nonatomic) NMAUrbanMobilitySearchOptionalFlag strictSearch;

@end
/** @}  */
