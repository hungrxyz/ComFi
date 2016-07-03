/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

@class UIImage;


/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 * \class NMAImage NMAImage.h "NMAImage.h"
 *
 * Encapsulates an image file.
 * <p>
 * Notes on %NMAImage objects:
 * <ul>
 * <li>BMP, SVG, JPEG and PNG data formats are supported</li>
 * <li>SVG Tiny 1.1 is supported</li>
 * <li>BMP data format support is limited to either standard BMP v3 with 24/32
 * bits per pixel (without compression) or BMP v4/v5 (newer BMP formats) with
 * 24/32 bits per pixel plus bitfields compression and A8R8G8B8 pixel formatting</li>
 * <li>Only basic parsing of the BMP header is done, while gamma correction and
 * color profile information is ignored</li></ul></p>
 *
 * \note PNG compression may be enabled by default in Xcode; files compressed this
 * way cannot be loaded into an NMAImage through raw data or URL. These files may
 * be first loaded into a UIImage and then used to create an NMAImage.
 */
@interface NMAImage : NSObject

/**
 * \brief Constructs a NMAImage from a UIImage.
 *
 * When converting a UIImage to an NMAImage, the scale of the original image is compared
 * against the scale of the device. If they are different, the image is resized so that
 * the scale of the final image is the same as the device scale.
 *
 * For example, if a 100x100 pixel UIImage with a scale of 2x is converted to an NMAImage
 * on a 3x scale device, the NMAImage will have dimensions of 150x150 (and an implicit
 * scale of 3x to match the device).
 */
+ (id)imageWithUIImage:(UIImage *)image;

/**
 * Constructs a NMAImage from raw data; see the class description for supported
 * file types.
 */
+ (id)imageWithData:(NSData *)data;

/**
 * Constructs a NMAImage from a local image file URL; the path may be absolute
 * or relative to the main bundle.
 */
+ (id)imageWithURL:(NSString *)url;

/**
 * The BOOL indicating whether the %NMAImage contains a valid image.
 */
@property (nonatomic, readonly, getter = isValid) BOOL valid;

/**
 * The size of the NMAImage in points.
 */
@property (nonatomic, readonly) CGSize size;

/**
 * Provides a UIImage representation of the NMAImage.
 *
 * \note Will return nil if the image could not be converted.
 */
- (UIImage *)UIImageRepresentation;

@end
/** @}  */
