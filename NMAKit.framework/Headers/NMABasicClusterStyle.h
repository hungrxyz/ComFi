/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAClusterStyle.h"
#import <UIKit/UIColor.h>

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */


/**
 * \class NMABasicClusterStyle NMABasicClusterStyle.h "NMABasicClusterStyle.h"
 *
 * Basic implementation of %NMAClusterStyle. Use it if some customization needs be applied to
 * this style. Please see the API of this class for the list of customizable properties.
 */
@interface NMABasicClusterStyle : NMAClusterStyle

/**
 * Color of the font used for rendering cluster marker.
 */
@property (nonatomic) UIColor *fontColor;

/**
 * Fill color of cluster marker.
 */
@property (nonatomic) UIColor *fillColor;

/**
 * Stroke color of cluster marker.
 */
@property (nonatomic) UIColor *strokeColor;

/**
 * Constructs a %NMABasicClusterStyle with default values.
 */
+ (instancetype)style;

/**
 * Constructs a %NMABasicClusterStyle with the specified colors.
 *
 * \param stroke Stroke color of cluster marker.
 * \param fill Fill color of cluster marker.
 * \param font Color of the font used for rendering cluster marker.
 */
+ (instancetype)styleWithStrokeColor:(UIColor *)stroke fillColor:(UIColor *)fill fontColor:(UIColor *)font;

/**
 * Initializes a %NMABasicClusterStyle instance with the specified colors.
 *
 * \param stroke Stroke color of cluster marker.
 * \param fill Fill color of cluster marker.
 * \param font Color of the font used for rendering cluster marker.
 */
- (instancetype)initWithStrokeColor:(UIColor *)stroke fillColor:(UIColor *)fill fontColor:(UIColor *)font;

@end
/** @}  */
