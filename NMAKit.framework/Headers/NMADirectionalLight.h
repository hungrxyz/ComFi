/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAVector3d.h"

#import "NMALight.h"

/**
 * \addtogroup NMA_Map  NMA Mapping Group
 * @{
 */


/**
 * \class NMADirectionalLight NMADirectionalLight.h "NMADirectionalLight.h"
 *
 * Represents a simple directional light source for use with 3D models.
 */
@interface NMADirectionalLight : NMALight

/**
 * Creates a directional light with the specified direction.
 *
 * \param direction The light source direction.
 */
+ (id)lightWithDirection:(NMAVector3d)direction;

/**
 * The direction of the light.
 */
@property (nonatomic) NMAVector3d direction;

@end



/** @} */
