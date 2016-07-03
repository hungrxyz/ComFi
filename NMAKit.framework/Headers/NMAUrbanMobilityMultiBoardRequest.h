/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
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
 * \brief Defines a callback which is triggered on the completion of a Multi Departure Board request.
 * The resulting callback contains an array of %NMAUrbanMobilityStationWithDepartureBoard, an array of %NMAUrbanMobilityLine or %NSError.
 *
 * NMAUrbanMobilityMultiDepartureBoardCompletionBlock is used with
 * \link NMAUrbanMobilityMultiBoardRequest::startWithCompletionBlock:(NMAUrbanMobilityMultiBoardCompletionBlock) \endlink
 * to provide a callback for capturing responses from the HERE backend server.
 *
 * \param stations Array of %NMAUrbanMobilityStationWithDepartureBoard returned by the HERE backend server.
 * \param lines Array of %NMAUrbanMobilityLine returned by the HERE backend server.
 * \param error An error which occurred when searching for transit stations. Error codes are defined in %NMAUrbanMobilityError.
 *
 * \sa NMAUrbanMobilityMultiBoardRequest::startWithCompletionBlock:(NMAUrbanMobilityMultiBoardCompletionBlock)
 * \sa NMAUrbanMobilityStationWithDepartureBoard
 * \sa NMAUrbanMobilityLine
 * \sa NMAUrbanMobilityError
 */
typedef void (^NMAUrbanMobilityMultiBoardCompletionBlock)(NSArray *stations, NSArray *lines, NSError *error);


/**
 * \class NMAUrbanMobilityMultiBoardRequest NMAUrbanMobilityMultiBoardRequest.h "NMAUrbanMobilityMultiBoardRequest.h"
 *
 * \brief Represents a request to retrieve a multi departure board for the given location.
 *
 * NMAUrbanMobilityMultiDepartureBoardRequest assembles and issues requests to the HERE backend server
 * by providing a geo location.
 *
 * The HERE backend server responds with either a list of %NMAUrbanMobilityStationWithDepartureBoard objects or NSError if something goes wrong.
 * Use %NMAUrbanMobilityMultiDepartureBoardCompletionBlock to capture the response.
 *
 * \sa NMAUrbanMobilityMultiDepartureBoardCompletionBlock
 * \sa NMAUrbanMobilityStationWithDepartureBoard
 */
@interface NMAUrbanMobilityMultiBoardRequest : NSObject

/**
 * Creates a new %NMAUrbanMobilityMultiBoardRequest for a multi departure board at a transit station with a given geo coordinates.
 *
 * \param location Geo coordinates of the transit station.
 *
 * \note Geo coordinates are required to identify a transit station unambiguously.
 */
- (instancetype)initWithLocation:(NMAGeoCoordinates *)location;

/**
 * Sends the request to retrieve a multi departure board from the HERE backend server.
 * Request processing is performed asynchronously: %NMAUrbanMobilityMultiBoardCompletionBlock is used to pass the response.
 *
 * \param completion %NMAUrbanMobilityMultiBoardCompletionBlock which is used to pass the response.
 * \return YES if the request was triggered successfully, NO otherwise.
 *
 * \note %NMAUrbanMobilityMultiBoardCompletionBlock is called on the main queue.
 *
 * \sa NMAUrbanMobilityMultiDepartureBoardCompletionBlock
 */
- (BOOL)startWithCompletionBlock:(NMAUrbanMobilityMultiBoardCompletionBlock)completion;

/**
 * Geo coordinates of the location which multi departure board is being requested.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

/**
 * Time which is used as a start point for the multi departure board being requested.
 * All entries in the departure board are the earliest possible departures after the specified time.
 *
 * \note If this property is not set then the current timestamp is used.
 */
@property (nonatomic) NSDate *departureTime;

/**
 * Optional. Specifies if the real time information will be included in the response. The possible values are:
 * NO – do not include real time information
 * YES – include real time information
 * The default is NO.
 */
@property (nonatomic, getter = isRealTimeInfoEnabled) BOOL realTimeInfoEnabled;

/**
 * Optional. Specifies a radius in meters that when combined with a centerpoint defines the area of the search.
 * The default value is 500m. The minimum value is 0. If client will set value < 0, parameter will be not added to
 * request and default radius(500m) will be used by backend server.
 * If it will be set to 0 or greater, then parameter will be added to request.
 */
@property (nonatomic) NSInteger radius;

/**
 * Optional. Specifies a list of station ids.
 * Sets the station IDs for which departures will be returned.
 * It is not set by default - all stations in the range.
 */
@property (nonatomic) NSArray *stationIds;

/**
 * Optional. Specifies the transit type filter used to determine which types of transit to include
 * in the response (a set of %NMAUrbanMobilityTransitModes).
 * If not set, default values on backend server will be used.
 * \sa NMAUrbanMobilityTransitMode
 */
@property (nonatomic) NSSet *transitModes;

/**
 * Optional. Specifies the maximum number of next departures per station the response should include.
 * Must be greater than 0.
 */
@property (nonatomic) NSUInteger maxDeparturesPerStation;

/**
 * Optional. Specifies the maximum number of stations the response should include.
 * Must be greater than 0.
 */
@property (nonatomic) NSUInteger maximumResults;

@end
/** @}  */
