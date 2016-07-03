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
 * \class NMATransitAccess NMATransitAccess.h "NMATransitAccess.h"
 *
 * Represents an access point (entrance) to a public transit stop.
 *
 * Each access is associated with a unique NMATransitStop; the stop can be
 * determined through the stopId property.
 *
 * \note Some accesses may not have complete information available.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMATransitAccess : NSObject

/**
 * The unique identifying string of the access.
 */
@property (nonatomic, readonly) NSString *uniqueId;

/**
 * The name of the access.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The geographical location of the access.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *location;

/**
 * The uniqueId of NMATransitStop associated with this access.
 */
@property (nonatomic, readonly) NSString *stopId;

/**
 * Indicates whether the given NMATransitType is available from this access.
 */
- (BOOL)hasTransitType:(NMATransitType)type;

@end

/** @}  */
