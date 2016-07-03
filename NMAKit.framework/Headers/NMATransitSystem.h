/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */


/**
 * \class NMATransitSystem NMATransitSystem.h "NMATransitSystem.h"
 *
 * Represents a public transit system.
 *
 * \note Some systems may not have complete information available.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMATransitSystem : NSObject

/**
 * The unique identifying string of the access.
 */
@property (nonatomic, readonly) NSString *uniqueId;

/**
 * The officially published name of the system, if available.
 */
@property (nonatomic, readonly) NSString *officialName;

/**
 * The local name of the system, if available.
 */
@property (nonatomic, readonly) NSString *informalName;

/**
 * A short name for the system, if available.
 */
@property (nonatomic, readonly) NSString *shortName;

/**
 * The system website, if available.
 */
@property (nonatomic, readonly) NSString *website;

/**
 * The official name of the company operating the system.
 */
@property (nonatomic, readonly) NSString *companyOfficialName;

/**
 * The local name of the company operating the system, if available.
 */
@property (nonatomic, readonly) NSString *companyInformalName;

/**
 * A short name for the company operating the system, if available.
 */
@property (nonatomic, readonly) NSString *companyShortName;

/**
 * The website for the company operating the system, if available.
 */
@property (nonatomic, readonly) NSString *companyWebsite;

/**
 * The website used for planning routes on the system, if available.
 */
@property (nonatomic, readonly) NSString *companyRoutePlannerWebsite;

/**
 * The website used for looking up system schedules, if available.
 */
@property (nonatomic, readonly) NSString *companyScheduleWebsite;

/**
 * The phone number of the company operating the system, if available.
 */
@property (nonatomic, readonly) NSString *companyTelephoneNumber;

@end
/** @}  */
