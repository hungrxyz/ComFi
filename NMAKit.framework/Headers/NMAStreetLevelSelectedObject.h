/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import "NMAVector3d.h"

/**
 * \addtogroup NMA_Streetlevel NMA Street Level Group
 * @{
 */

@class NMAGeoCoordinates;
@class NMAViewObject;


/**
 * \class NMAStreetLevelSelectedObject NMAStreetLevelSelectedObject.h "NMAStreetLevelSelectedObject.h"
 *
 * NMAStreetLevelSelectedObject represents a street level object selected by
 * a tap gesture (i.e.: NMAStreetLevelViewDelegate#didSelectObject)
 * or NMAStreetLevelView#streetLevelObjectsAtScreenPoint.
 *
 * \note Not all object types will have valid values for all properties.
 *
 * @product nlp-hybrid-plus nlp-plus
 */

@interface NMAStreetLevelSelectedObject : NSObject

/**
 * The geographical location at which the NMAStreetLevelSelectedObject was selected.
 *
 * \note The same object (building, billboard, etc.) will give different position values
 * if it is selected or tapped in different places.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *position;

/**
 * The normal vector of the NMAStreetLevelSelectedObject.
 */
@property (nonatomic, readonly) NMAVector3d normalVector;

/**
 * The texture coordinates of the selected point of the NMAStreetLevelSelectedObject.
 * For example, if the object was tapped at its center, the texture coordinates would be
 * (0.5, 0.5).
 */
@property (nonatomic, readonly) CGPoint textureCoordinates;

/**
 * The NMAViewObject associated with this NMAStreetLevelSelectedObject. Possible object
 * types are: NMAStreetLevelBillboard, NMAStreetLevelBuilding, NMAStreetLevelIcon,
 * NMAStreetLevelLink and NMAStreetLevelRoute.
 */
@property (nonatomic, readonly) NMAViewObject *streetLevelObject;

@end
/**  @}  */
