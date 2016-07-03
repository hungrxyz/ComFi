/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

NS_ASSUME_NONNULL_BEGIN

@class NMACLE2Geometry;

/**
 * \addtogroup NMA_CLE2 NMA Custom Location Extension 2 Group
 * @{
 */

/**
 * \class NMACLE2Result NMACLE2Result.h "NMACLE2Result.h"
 *
 * Contains the all the geometries (%NMACLE2Geometry) returned from an
 * %NMACLE2Request.
 */
@interface NMACLE2Result : NSObject

/*!
 * Returns an %NSArray containing all the geometries of this %NMACLE2Result.
 */
@property (nonatomic, readonly) NSArray<NMACLE2Geometry *> *geometriesArray;

@end

/**  @}  */

NS_ASSUME_NONNULL_END
