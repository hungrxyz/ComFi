/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMARoute.h"

@class NMATransitRouteSourceAttribution;

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

/**
 * Represents a path (a collection of maneuvers) connecting two or more
 * waypoints for public transport.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMARoute (NMATransitRoute)

/**
 * \brief The transit information source attribution for the route.
 *
 * In certain cases, data provided by Transit Agencies cannot be used without displaying
 * copyright notices to the end user. The copyright information is provided in the source
 * attribution objects and must be displayed together with a route. This requirement forms part
 * of the terms and conditions of the API.
 *
 * \note Source attribution may not be available in all cases.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic, readonly) NMATransitRouteSourceAttribution *sourceAttribution;

@end
/** @}  */
