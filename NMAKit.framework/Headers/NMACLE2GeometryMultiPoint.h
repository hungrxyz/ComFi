/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

#import "NMACLE2Geometry.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * \addtogroup NMA_CLE2 NMA Custom Location Extension 2 Group
 * @{
 */

/**
 * Represents a multipoint custom geometry created and accessed through the
 * Custom Location Extension 2.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMACLE2GeometryMultiPoint : NMACLE2Geometry

/**
 * Array of %NMAGeoCoordinates of this geometry.
 */
@property (nonatomic, readonly) NSArray<NMAGeoCoordinates *> *coordinatesArray;

@end

/**  @}  */

NS_ASSUME_NONNULL_END
