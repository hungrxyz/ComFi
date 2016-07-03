/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAMedia.h"

/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 */


/**
 * \class NMAMediaImage NMAMediaImage.h "NMAMediaImage.h"
 *
 * Represents an image associated with an NMAPlace. Images are uploaded by
 * the HERE user community.
 *
 * \sa NMAMediaEditorial
 * \sa NMAMediaReview
 * \sa NMAMediaRating
 */
@interface NMAMediaImage : NMAMedia

/**
 * The external URL of the image source.
 *
 * \return The %NSString
 */
@property (nonatomic, readonly, strong) NSString *imageSource;

/**
 * The unique identifier of the image.
 *
 * \note An ID for an image is optional. Attempts to read this property
 * could return empty string.
 *
 * \return The ID (could be empty string)
 */
@property (nonatomic, readonly, strong) NSString *uniqueId;

/**
 * The details of the user who contributed the image.
 *
 * \note A user-contributor for an image is optional. Attempts to read
 * this property could return nil.
 *
 * \return NMALink (could be nil)
 */
@property (nonatomic, readonly, strong) NMALink *user;

/**
 * Gets a URL for an image with specific width-height dimensions.
 *
 * The provided width-height are used as upper boundaries
 * for the dimensions of the returned images. The solution will
 * never scale up small images and will maintain the aspect ratio
 * of the original image.
 * </p>
 * <p>
 * A URL of image with specific width-height dimensions will not
 * be returned if it has not been queried with NMARequest:addImageSizeWithWidth:height
 * </p>
 * <p>
 * For example:
 * </p>
 * \code
 * image_dimensions=w32-h32,w64-h64
 * image_dimensions=w32-h32,w300
 * image_dimensions=h200
 * \endcode
 *
 * \param width The image width.
 * \param height The image height.
 *
 * \return The URL to retrieve the image with the specified width-height
 *         dimensions. Can be nil if an image with the specified
 *         dimensions is unavailable.
 */
- (NSString *)URLForImageWithWidth:(NSInteger)width height:(NSInteger)height;

@end

/** @} */
