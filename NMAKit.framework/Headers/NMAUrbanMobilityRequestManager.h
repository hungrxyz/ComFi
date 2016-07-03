/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAUrbanMobilityStationSearchRequest;
@class NMAUrbanMobilityDepartureBoardRequest;
@class NMAUrbanMobilityMultiBoardRequest;
@class NMAUrbanMobilityStation;
@class NMAGeoCoordinates;
@class NMAUrbanMobilityCitySearchRequest;
@class NMAUrbanMobilityCityCoverageRequest;
@class NMAUrbanMobilityNearbyCoverageRequest;

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */


/**
 * \class NMAUrbanMobilityRequestManager NMAUrbanMobilityRequestManager.h "NMAUrbanMobilityRequestManager.h"
 *
 * \brief Defines a singleton which manages creation of requests to the HERE backend servers.
 *
 * %NMAUrbanMobilityRequestManager is a singleton which provides convenient shortcuts for creation of %NMAUrbanMobilitySearchRequest instances:
 * %NMAUrbanMobilityStationSearchRequest to search for transit stations and %NMAUrbanMobilityDepartureBoardRequest to request departure boards.
 *
 * \sa NMAUrbanMobilitySearchRequest
 * \sa NMAUrbanMobilityStationSearchRequest
 * \sa NMAUrbanMobilityDepartureBoardRequest
 */
@interface NMAUrbanMobilityRequestManager : NSObject

/**
 * Returns the shared instance of %NMAUrbanMobilityRequestManager.
 * No other instances should be created.
 */
+ (NMAUrbanMobilityRequestManager *)sharedRequestManager;

/**
 * Creates a new %NMAUrbanMobilityStationSearchRequest to search for transit stations around a given location.
 *
 * Use optional properties to fine tune the search: searchRange, stationName, nameMatchingMethod
 *
 * \param location Geo coordinates to search for nearby transit stations around.
 * \return %NMAUrbanMobilityStationSearchRequest which is ready to be executed.
 *
 * \sa NMAUrbanMobilityStationSearchRequest::startWithCompletionBlock:
 */
- (NMAUrbanMobilityStationSearchRequest *)createStationSearchRequestWithLocation:(NMAGeoCoordinates *)location;

/**
 * Creates a new %NMAUrbanMobilityStationSearchRequest to search for transit stations with given IDs.
 *
 * \param stationIds Array of transit station IDs to search for.
 * \return %NMAUrbanMobilityStationSearchRequest which is ready to be executed.
 *
 * \sa NMAUrbanMobilityStationSearchRequest::startWithCompletionBlock:
 */
- (NMAUrbanMobilityStationSearchRequest *)createStationSearchRequestWithIds:(NSArray *)stationIds;

/**
 * Creates a new %NMAUrbanMobilityDepartureBoardRequest for a departure board at a given transit station.
 *
 * \param station Transit station to request a departure board for.
 * \return %NMAUrbanMobilityDepartureBoardRequest which is ready to be executed.
 *
 * \sa NMAUrbanMobilityDepartureBoardRequest::startWithCompletionBlock:
 */
- (NMAUrbanMobilityDepartureBoardRequest *)createDepartureBoardRequestWithStation:(NMAUrbanMobilityStation *)station;


/**
 * Creates a new %NMAUrbanMobilityMultiBoardRequest for a multi departure board from given location.
 *
 * \param location Geo coordinates to search all stations around.
 * \return %NMAUrbanMobilityMultiBoardRequest which is ready to be executed.
 *
 * \sa NMAUrbanMobilityMultiBoardRequest::startWithCompletionBlock:
 */
- (NMAUrbanMobilityMultiBoardRequest *)createMultiBoardRequestWithLocation:(NMAGeoCoordinates *)location;

/**
 * Creates a new %NMAUrbanMobilityDepartureBoardRequest for a departure board at a transit station with a given ID and given geo coordinates.
 *
 * \param stationId Transit station ID.
 * \param location Geo coordinates of the transit station.
 * \return %NMAUrbanMobilityDepartureBoardRequest which is ready to be executed.
 *
 * \note Both station ID and geo coordinates are required to identify a transit station unambiguously.
 *
 * \sa NMAUrbanMobilityDepartureBoardRequest::startWithCompletionBlock:
 */
- (NMAUrbanMobilityDepartureBoardRequest *)createDepartureBoardRequestWithStationId:(NSString *)stationId
                                                                           location:(NMAGeoCoordinates *)location;

/**
 * Creates a new %NMAUrbanMobilityCitySearchRequest for search for public transit coverage by city.
 *
 * \param cityName - string used to search.
 * \return %NMAUrbanMobilityCitySearchRequest which is ready to be executed.
 *
 * \sa NMAUrbanMobilityCitySearchRequest::startWithCompletionBlock:
 */
- (NMAUrbanMobilityCitySearchRequest *)createCitySearchRequestWithSearchText:(NSString *)cityName;

/**
 * Creates a new %NMAUrbanMobilityCityCoverageRequest used to get a list of cities where were have transit coverage,
 * as well as list of transit operators, from a given location, within a certain radius.
 *
 * \return %NMAUrbanMobilityCityCoverageRequest which is ready to be executed.
 *
 * \sa NMAUrbanMobilityCityCoverageRequest::startWithCompletionBlock:
 */
- (NMAUrbanMobilityCityCoverageRequest *)createCityCoverageRequest;

/**
 * Creates a new %NMAUrbanMobilityNearbyCoverageRequest used for retrieve coverage information about nearby cities.
 *
  * \param location Geo coordinates of the entry point used to search.
 * \return %NMAUrbanMobilityNearbyCoverageRequest which is ready to be executed.
 *
 * \sa NMAUrbanMobilityNearbyCoverageRequest::startWithCompletionBlock:
 */
- (NMAUrbanMobilityNearbyCoverageRequest *)createNearbyCoverageRequestForLocation:(NMAGeoCoordinates *)location;

@end
/** @}  */
