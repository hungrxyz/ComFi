/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */

/**
 * \class NMAPlaceTransitDeparture NMAPlaceTransitDeparture.h "NMAPlaceTransitDeparture.h"
 * \brief Represents information about a single departure. All times use <a
 * href="http://tools.ietf.org/html/rfc3339#section-5.6">RFC 3339 date-time</a>
 * format with timezone offset.
 */

/**
 * \brief Key name to retrieve departure time
 */
FOUNDATION_EXPORT NSString *const NMADepartureTimeKeyName;
/**
 * \brief Key name to retrieve the departure platform information.
 */
FOUNDATION_EXPORT NSString *const NMADeparturePlatformKeyName;

/**
 * \brief Departure has been redirected.
 */
FOUNDATION_EXPORT NSString *const NMAExceptionEventRedirected;
/**
 * \brief Departure has been replaced.
 */
FOUNDATION_EXPORT NSString *const NMAExceptionEventReplaced;
/**
 * \brief Departure has been cancelled.
 */
FOUNDATION_EXPORT NSString *const NMAExceptionEventCancelled;
/**
 * \brief Additional departure information provided.
 */
FOUNDATION_EXPORT NSString *const NMAExceptionEventAdditional;


@interface NMAPlaceTransitDeparture : NSObject

/**
 * \brief Reference to the line in transit lines directory.
 */
@property (nonatomic, readonly, strong) NSString *line;

/**
 * \brief The NSDictionary of the originally scheduled departure time information.
 *
 * Known key identifier values are:
 * <ul>
 * <li>NMADepartureTimeKeyName - %NSString of scheduled departure time (RFC 3339 date-time with timezone offset)</li>
 * <li>NMADeparturePlatformKeyName - %NSString of scheduled departure platform (optional)</li>
 * </ul>
 */
@property (nonatomic, readonly, strong) NSDictionary *scheduledTimeInfo;

/**
 * \brief Direction of the departure on its line.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *direction;

/**
 * An indicator for some exceptional event happened to this departure.
 * Possible values are:
 * <code>NMAExceptionEventRedirected</code>, <code>NMAExceptionEventReplaced</code>,
 * <code>NMAExceptionEventCancelled</code> and <code>NMAExceptionEventAdditional</code>.
 *
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *exception;

/**
 * \brief The %NSString of reference to the operator in the operators collection information.
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *transitOperator;

/**
 * The NSDictionary of the real (actual) departure time information. The
 * departure key represents the departure time.
 *
 * Known key identifier values are:
 * <ul>
 * <li>NMADepartureTimeKeyName - %NSString of real-time departure time (RFC 3339 date-time with timezone offset)</li>
 * <li>NMADeparturePlatformKeyName - %NSString of real-time departure platform (optional)</li>
 * </ul>
 *
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSDictionary *realTimeInfo;

/**
 * An NSArray of NMAExtendedAttribute features of departure. Supported keys are
 * bikeAllowed and barrierFree.
 *
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSArray *extendedAttributes;

@end
/** @} */
