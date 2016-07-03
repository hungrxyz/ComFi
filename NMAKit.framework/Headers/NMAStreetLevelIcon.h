/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAStreetLevelIconBase.h"

/**
 * \addtogroup NMA_Streetlevel NMA Street Level Group
 * @{
 */


/**
 * \class NMAStreetLevelIcon NMAStreetLevelIcon.h "NMAStreetLevelIcon.h"
 *
 * NMAStreetLevelIcon is a concrete implementation of NMAStreetLevelIconBase used
 * to place images in an NMAStreetLevelView.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMAStreetLevelIcon : NMAStreetLevelIconBase

/**
 * A convenience method to construct an NMAStreetLevelIcon at the specified
 * coordinates and with an NMAImage icon.
 * \param coordinates The NMAGeoCoordinates at which to create the NMAStreetLevelIcon.
 * \param icon The NMAImage to be displayed by the icon.
 */
+ (id)streetLevelIconWithGeoCoordinates:(NMAGeoCoordinates *)coordinates icon:(NMAImage *)icon;

/**
 * A convenience method to construct an NMAStreetLevelIcon at the specified
 * coordinates and with a UIImage icon.
 * \param coordinates The NMAGeoCoordinates at which to create the NMAStreetLevelIcon.
 * \param image The UIImage to be displayed by the icon.
 */
+ (id)streetLevelIconWithGeoCoordinates:(NMAGeoCoordinates *)coordinates image:(UIImage *)image;

/**
 * Initializes a %NMAStreetLevelIcon instance with the specified %NMAGeoCoordinates
 * and %NMAImage for the displayed icon.
 *
 * \param coordinates A %NMAGeoCoordinates representing the map coordinates for displaying
 *               the %NMAStreetLevelIcon
 * \param icon A %NMAImage representing the icon for the %NMAStreetLevelIcon
 * \return The %NMAStreetLevelIcon. Nil if %NMAImage for the displayed icon is nil.
 */
- (id)initWithGeoCoordinates:(NMAGeoCoordinates *)coordinates icon:(NMAImage *)icon;

/**
 * Initializes a %NMAStreetLevelIcon instance with the specified %NMAGeoCoordinates
 * and UImage for the displayed icon.
 *
 * \param coordinates A %NMAGeoCoordinates representing the map coordinates for displaying
 *               the %NMAStreetLevelIcon
 * \param image A UIImage to use to create the NMAImage marker of the icon.
 * \return The %NMAStreetLevelIcon Nil if UImage for the displayed icon is nil.
 */
- (id)initWithGeoCoordinates:(NMAGeoCoordinates *)coordinates image:(UIImage *)image;

@end
/**  @}  */
