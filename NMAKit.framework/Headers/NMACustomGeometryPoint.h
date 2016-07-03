/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMACustomGeometry.h"

@class NMAGeoCoordinates;


/**
 * \addtogroup NMA_CLE NMA Custom Location Group
 * @{
 */

/**
 * Represents a point custom geometry created and accessed through the
 * Custom Location Extension.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMACustomGeometryPoint : NMACustomGeometry

/**
 * %NMAGeoCoordinates of this geometry.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *coordinate;

@end

/**  @}  */
