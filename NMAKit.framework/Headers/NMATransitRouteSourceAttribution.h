/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */


/**
 * \class NMATransitRouteSourceAttribution NMATransitRouteSourceAttribution.h "NMATransitRouteSourceAttribution.h"
 *
 * Contains copyright notices that must be displayed to the end user when using
 * transit routing.
 *
 * Source attribution must be displayed together with a route. This requirement forms
 * part of the terms and conditions of the SDK.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMATransitRouteSourceAttribution : NSObject

/**
 * The source attribution information as an HTML-formatted string.
 */
@property (nonatomic) NSString *attribution;

/**
 * The suppliers of the transit information, represented as NMATransitRouteSupplier.
 *
 * \sa NMATransitRouteSupplier.
 */
@property (nonatomic) NSArray *suppliers;

@end

/** @}  */
