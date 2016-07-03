/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAClusterStyle.h"

@class NMAImage;
@class UIImage;

/**
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 */

  
/**
 * \class NMAImageClusterStyle NMAImageClusterStyle.h "NMAImageClusterStyle.h"
 *
 * Implementation of %NMAClusterStyle that uses %NMAImage for specific cluster density.
 * Density represents the number of markers inside a cluster.
 */
@interface NMAImageClusterStyle : NMAClusterStyle

/**
 * Constructs a %NMAImageClusterStyle with the given image.
 *
 * \param image %NMAImage instance to be used for this style.
 */
+ (instancetype)styleWithImage:(NMAImage *)image;

/**
 * Constructs a %NMAImageClusterStyle with the given image.
 *
 * \param image %UIImage instance to be used for this style.
 */
+ (instancetype)styleWithUIImage:(UIImage *)image;

/**
 * Initializes a %NMAImageClusterStyle instance with the given image.
 *
 * \param image %NMAImage instance to be used for this style.
 */
- (instancetype)initWithImage:(NMAImage *)image;

/**
 * Initializes a %NMAImageClusterStyle instance with the given image.
 *
 * \param image %UIImage instance to be used for this style.
 */
- (instancetype)initWithUIImage:(UIImage *)image;

@end
/** @}  */
