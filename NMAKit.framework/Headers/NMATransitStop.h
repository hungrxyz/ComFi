/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMATransitManager.h"

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */


/**
 * \class NMATransitStop NMATransitStop.h "NMATransitStop.h"
 *
 * Represents a public transit stop.
 *
 * \note Some stops may not have complete information available.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMATransitStop : NSObject

/**
 * The unique identifying string of the stop.
 */
@property (nonatomic, readonly) NSString *uniqueId;

/**
 * The officially published name of the stop.
 */
@property (nonatomic, readonly) NSString *officialName;

/**
 * The local name of the stop, if available.
 */
@property (nonatomic, readonly) NSString *informalName;

/**
 * The geographical location of the stop.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

/**
 * A list of NSString objects representing the uniqueIds of all
 * NMATransitLines associated with this stop.
 */
@property (nonatomic, readonly) NSArray *lineIds;

/**
 * A list of NSString objects representing the uniqueIds of all
 * NMATransitSystems associated with this stop.
 */
@property (nonatomic, readonly) NSArray *systemIds;

/**
 * Indicates whether the given NMATransitType is available at this stop.
 */
- (BOOL)hasTransitType:(NMATransitType)type;

@end

/** @}  */
