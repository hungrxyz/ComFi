/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIColor.h>

@class NMAGeoCoordinates;


/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * \class NMATransitRouteStop NMATransitRouteStop.h "NMATransitRouteStop.h"
 *
 * Represents a transit stop for some form of public transport.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMATransitRouteStop : NSObject

/**
 * The id of the transit stop for future use. Identifier is not supported for
 * public transport timetable route stops.
 */
@property (nonatomic, readonly, strong) NSString *identifier;

/**
 * The name of the transit stop.
 *
 * \note  It is localized to the locale of the region.
 */
@property (nonatomic, readonly, strong) NSString *name;

/**
 * The geo coordinates of the transit stop.
 */
@property (nonatomic, readonly, strong) NMAGeoCoordinates *coordinates;

@end
/** @}  */
