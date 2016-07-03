/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * \addtogroup NMA_CLE NMA Custom Location Group
 * @{
 */

/**
 * Represents an abstract custom geometry created and accessed through the
 * Custom Location Extension.
 *
 * \note See %NMACustomGeometryMultiPolygon, %NMACustomGeometryPolyline and %NMACustomGeometryPoint
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMACustomGeometry : NSObject

/**
 * An ID of this geometry specified by its owner.
 */
@property (nonatomic, readonly) NSUInteger geometryId;

/**
 * The name of the geometry.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * Additional custom attributes of this geometry.
 */
@property (nonatomic, readonly) NSDictionary *customAttributes;

/**
 * Feature ID of this geometry, usually this is a concatenation of geometry name and geometry ID.
 */
@property (nonatomic, readonly) NSString *featureId;

@end

/**  @}  */
