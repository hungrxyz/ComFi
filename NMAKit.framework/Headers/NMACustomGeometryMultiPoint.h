/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMACustomGeometry.h"

/**
 * \addtogroup NMA_CLE NMA Custom Location Group
 * @{
 */


/**
 * Represents a multipoint custom geometry created and accessed through the
 * Custom Location Extension.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMACustomGeometryMultiPoint : NMACustomGeometry

/**
 * Array of %NMAGeoCoordinates of this geometry.
 */
@property (nonatomic, readonly) NSArray *coordinates;

@end

/**  @}  */
