/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 * @{
 */

/**
 * This enum defines the possible values that can be set by the optional flags in a search request.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilitySearchOptionalFlag) {
    /* \brief Flag value is not set (unspecified) */
    NMAUrbanMobilitySearchOptionalFlagUnset = 0,
    /* \brief Flag value is set to Yes */
    NMAUrbanMobilitySearchOptionalFlagYes,
    /* \brief Flag value is set to No */
    NMAUrbanMobilitySearchOptionalFlagNo
};


/**
 * \class NMAUrbanMobilitySearchRequest NMAUrbanMobilitySearchRequest.h "NMAUrbanMobilitySearchRequest.h"
 *
 * \brief Defines an Urban Mobility request to the HERE backend servers.
 *
 * NMAUrbanMobilitySearchRequest defines properties which are available for every request being made to the HERE backend servers.
 * Actual Urban Mobility requests are defined in %NMAUrbanMobilityStationSearchRequest and %NMAUrbanMobilityDepartureBoardRequest
 *
 * \sa NMAUrbanMobilityStationSearchRequest
 * \sa NMAUrbanMobilityDepartureBoardRequest
 */
@interface NMAUrbanMobilitySearchRequest : NSObject

/**
 * Describes whether or not additional transit information, such as lines and operators, are in the response.
 *
 * \note The default value is %NMAUrbanMobilitySearchOptionalFlagUnset which means that it is up to the HERE backend server to decide.
 */
@property (nonatomic) NMAUrbanMobilitySearchOptionalFlag extraTransitInfo;

/**
 * Limits number of results (inclusively) returned by the HERE backend server.
 *
 * \note The default value is 0 which means that it is up to the HERE backend server to decide.
 */
@property (nonatomic) NSInteger resultLimit;


@end
/** @}  */
