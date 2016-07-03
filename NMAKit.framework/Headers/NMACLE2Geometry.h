/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

NS_ASSUME_NONNULL_BEGIN

@class NMAGeoCoordinates;

/**
 * \addtogroup NMA_CLE2 NMA Custom Location Extension 2 Group
 * @{
 */

/**
 * \class NMACLE2Geometry NMACLE2Geometry.h "NMACLE2Geometry.h"
 *
 * Represents a user defined geometry.
 *
 * See %NMACLE2GeometryPoint, %NMACLE2GeometryMultiPoint.
 * Geometries can be obtained from %NMACLE2Result objects.
 */
@interface NMACLE2Geometry : NSObject

/*!
 * Returns %NSDictionary with the available attributes for this geometry.
 * The keys represent the customer fields, with their respective values.
 *
 * \note All keys and values are of %NSString type.
 */
@property (nonatomic, readonly) NSDictionary<NSString *, NSString *> *attributes;

@end

/**  @}  */

NS_ASSUME_NONNULL_END
