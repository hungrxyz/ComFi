/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Streetlevel NMA Street Level Group
 * @{
 */

/**
 * Defines the possible outcomes of a street level coverage check
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMAStreetLevelCoverage) {
    /** \brief Street level coverage available */
    NMAStreetLevelCoverageAvailable = 0,
    /** \brief Street level coverage not available */
    NMAStreetLevelCoverageUnavailable,
    /** \brief Street level coverage could not be determined due to an error. See NMAStreetLevelCoverageError */
    NMAStreetLevelCoverageFailed
};

/**
 * Defines the Street level coverage error domain name
 *
 * @product nlp-hybrid-plus nlp-plus
 */
FOUNDATION_EXPORT NSString *const NMAStreetLevelCoverageErrorDomain;

/**
 * Defines the errors possible when performing a street level coverage check
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMAStreetLevelCoverageError) {
    /** \brief No error */
    NMAStreetLevelCoverageErrorNone = 0,
    /** \brief Invalid NMAGeoCoordinates object passed to request */
    NMAStreetLevelCoverageErrorInvalidGeoCoordinates,
    /** \brief Failed due to network error */
    NMAStreetLevelCoverageErrorNetworkFailure,
    /** \brief Access to this operation is denied. Contact your HERE representative for more information */
    NMAStreetLevelCoverageErrorOperationNotAllowed
};


/*!
 * The result of a street level coverage check
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMAStreetLevelCoverageResult : NSObject

/**
 * Street level coverage.
 *
 * \note A Result of NMAStreetLevelCoverageFailed means coverage could not be determined. It does not necessarily mean
 *       coverage is not available. See error property for failure reasons.
 */
@property (nonatomic, readonly) NMAStreetLevelCoverage coverage;

/**
 * Street level coverage request error.
 *
 * Contains nil if coverage was checked successfully, otherwise contains an error code describing the reason
 * for the failure. The most common failure scenario is a bad, or non existent, network connection.
 *
 * See also \link NMAStreetLevelCoverageError\endlink for error codes.
 *
 * \note No error (nil) does not mean coverage is available. See coverage property for actual coverage result.
 */
@property (nonatomic, readonly) NSError *error;

/**
 * Original coordinates with which the coverage request was made.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *requestCoordinates;

/**
 * Original search radius with which the request was made.
 */
@property (nonatomic, readonly) float requestRadius;

@end

/**  @}  */
