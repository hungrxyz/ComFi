/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

@class NMAClusterStyle;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */

  
/**
 * \class NMAClusterTheme NMAClusterTheme.h "NMAClusterTheme.h"
 *
 * This class contains information about styles for given density ranges.
 * Density represents the number of markers inside a cluster.
 */
@interface NMAClusterTheme : NSObject

/**
 * Constructs an empty %NMAClusterTheme.
 */
+ (instancetype)clusterTheme;

/**
 * Adds an array of markers to this layer.
 *
 * \param style Style that should be used for given range.
 * \param range Density range, minimum allowed start location is 2.
 *
 * \return YES if valid range and style was provided, NO otherwise.
 */
- (BOOL)setStyle:(NMAClusterStyle *)style forDensityRange:(NSRange)range;

@end
/** @}  */
