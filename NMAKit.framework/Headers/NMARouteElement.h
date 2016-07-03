/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

@class NMARoadElement;
@class NMATransitRouteElement;

/**
 * Defines types of route element.
 */
typedef NS_ENUM(NSInteger, NMARouteElementType) {
    /** Transit Route Element */
    NMARouteElementTransit = 0,
    /** Road Element */
    NMARouteElementRoad,
    /** invalid  */
    NMARouteElementInvalid
};


/**
 * \class NMARouteElement NMARouteElement.h "NMARouteElement.h"
 *
 * Represents a generic container for an element of a route.
 */
@interface NMARouteElement : NSObject

/**
 * The route element type.
 */
@property (nonatomic, readonly) NMARouteElementType type;

/**
 * Road element of the route element.
 *
 * \note nil if type of the route element is not %NMARouteElementRoad
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic, readonly) NMARoadElement *roadElement;

/**
 * NMATransitRouteElement of the route element.
 *
 * \note nil if route element type is not NMARouteElementTransit.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic, readonly) NMATransitRouteElement *transitRouteElement;

@end
/**  @}  */
