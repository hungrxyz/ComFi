/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAARObject.h"

/**
 * \addtogroup NMA_AR NMA LiveSight Group
 * @{
 */


/**
 * \class NMAARIconObject NMAARIconObject.h "NMAARIconObject.h"
 *
 * \brief A concrete {@link NMAARObject} for displaying icons in a LiveSight
 * camera view.
 *
 * The NMAARIconObject may display separate images for the front plane, back
 * plane, map, and info icons.
 */
@interface NMAARIconObject : NMAARObject

/**
 * Creates an NMAARIconObject with a common image for front plane, back plane and
 * map icons.
 *
 * \param icon The image to use for the NMAARObject::frontPlaneIcon,
 *             NMAARObject::backPlaneIcon, and NMAARObject::mapIcon.
 * \param coordinates The location of the object.
 *
 * \note Icon images cannot be nil.
 */
+ (instancetype)iconObjectWithIcon:(NMAImage *)icon
                       coordinates:(NMAGeoCoordinates *)coordinates;

/**
 * Creates an NMAARIconObject with a common image for the front plane, back plane,
 * and map icons and a separate info image.
 *
 * \param icon The image to use for the NMAARObject::frontPlaneIcon,
 *             NMAARObject::backPlaneIcon, and NMAARObject::mapIcon.
 * \param infoImage The info image for the icon.
 * \param coordinates The location of the object.
 *
 * \note Icon images cannot be nil.
 */
+ (instancetype)iconObjectWithIcon:(NMAImage *)icon
                         infoImage:(NMAImage *)infoImage
                       coordinates:(NMAGeoCoordinates *)coordinates;

/**
 * Creates an NMAARIconObject with specific images for the front plane, back plane,
 * and map icons and the info image.
 *
 * \param frontPlaneIcon The image to use for the NMAARObject::frontPlaneIcon.
 * \param backPlaneIcon The image to use for the NMAARObject::backPlaneIcon.
 * \param mapIcon The image to use for the NMAARObject::mapIcon. Currently unused.
 * \param infoImage The image to be use for the NMAARObject::infoImage.
 * \param coordinates The location of the object.
 *
 * \note Icon images cannot be nil.
 */
+ (instancetype)iconObjectWithFrontPlaneIcon:(NMAImage *)frontPlaneIcon
                               backPlaneIcon:(NMAImage *)backPlaneIcon
                                     mapIcon:(NMAImage *)mapIcon
                                   infoImage:(NMAImage *)infoImage
                                 coordinates:(NMAGeoCoordinates *)coordinates;

@end

/** @}  */
