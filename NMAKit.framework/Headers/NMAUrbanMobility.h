/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_UrbanMobility NMA Urban Mobility Group
 *
 * The Urban Mobility group provides classes, callbacks, and enumerations
 * that can be used to enable Urban Mobility functionality such as 
 * searching for nearby transit stations and requesting departure boards.
 *
 * Key classes in this group are:
 * {@link NMAUrbanMobilityRequestManager},
 * {@link NMAUrbanMobilityStationSearchRequest},
 * {@link NMAUrbanMobilityDepartureBoardRequest}
 *
 * @{
 */

/**
 * \brief This enum defines Urban Mobility transit modes (means of transport).
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityTransitMode) {
    /** \brief Highspeed train */
    NMAUrbanMobilityTransitModeHighspeedTrain      = 0,
    
    /** \brief Intercity train */
    NMAUrbanMobilityTransitModeIntercityTrain      = 1,
    
    /** \brief Interregional train */
    NMAUrbanMobilityTransitModeInterregionalTrain  = 2,
    
    /** \brief Regional train */
    NMAUrbanMobilityTransitModeRegionalTrain       = 3,
    
    /** \brief City train */
    NMAUrbanMobilityTransitModeCityTrain           = 4,
    
    /** \brief Bus */
    NMAUrbanMobilityTransitModeBus                 = 5,
    
    /** \brief Ferry */
    NMAUrbanMobilityTransitModeFerry               = 6,
    
    /** \brief Subway */
    NMAUrbanMobilityTransitModeSubway              = 7,
    
    /** \brief Tram */
    NMAUrbanMobilityTransitModeTram                = 8,
    
    /** \brief Taxi */
    NMAUrbanMobilityTransitModeTaxi                = 9,
    
    /** \brief Inclined */
    NMAUrbanMobilityTransitModeInclined            = 10,
    
    /** \brief Aerial */
    NMAUrbanMobilityTransitModeAerial              = 11,
    
    /** \brief Express bus */
    NMAUrbanMobilityTransitModeExpressBus          = 12,
    
    /** \brief Monorail */
    NMAUrbanMobilityTransitModeMonorail            = 13,

    /** \brief Airplane */
    NMAUrbanMobilityTransitModeAirplane            = 14,
    
    /** \brief Unknown */
    NMAUrbanMobilityTransitModeUnknown             = 15
};


/**
 * \brief This enum defines Urban Mobility operation errors.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityError) {
    /** \brief No error. */
    NMAUrbanMobilityErrorNone = 0,
    
    /** \brief Application is currently offline. */
    NMAUrbanMobilityErrorOffline,
    
    /** \brief Backend returned bad HTTP response. */
    NMAUrbanMobilityErrorBadResponseCode,
    
    /** \brief Backend returned malformed response. */
    NMAUrbanMobilityErrorMalformedResponse,
    
    /** \brief Unknown error occurred. */
    NMAUrbanMobilityErrorUnknown,
    
    /** \brief Credentials which were sent to the backend server were not recognised as valid. */
    NMAUrbanMobilityErrorUnauthorized,
    
    /** \brief No coverage in this region/area. */
    NMAUrbanMobilityErrorNoCoverage,

    /** \brief Backend did not return any response. */
    NMAUrbanMobilityErrorNoResponse,
    
    /** \brief No search matches were found. */
    NMAUrbanMobilityErrorNotFound,
    
    /** \brief Invalid request parameters were provided. */
    NMAUrbanMobilityErrorInvalidParameters,

    /** \brief Unexpected error occurred. */
    NMAUrbanMobilityErrorUnexpected,

    /** \brief API is not available in this region/area. */
    NMAUrbanMobilityErrorUnavailableAPI
};

/**
 * \brief This enum defines availability options of a transit feature.
 */
typedef NS_ENUM(NSUInteger, NMAUrbanMobilityFeatureAvailability) {
    /** \brief Feature availability is unknown. */
    NMAUrbanMobilityFeatureAvailabilityUnknown = 0,

    /** \brief Feature is available. */
    NMAUrbanMobilityFeatureAvailable,

    /** \brief Feature is not available. */
    NMAUrbanMobilityFeatureNotAvailable
};
/** @}  */
