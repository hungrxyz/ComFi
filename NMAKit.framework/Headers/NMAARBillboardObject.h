/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAARModelObject.h"
#import "NMAVector3d.h"
#import "NMAGeoCoordinates.h"

/**
 * \addtogroup NMA_AR NMA LiveSight Group
 * @{
 */

/**
 * \brief Defines the orientation mode of {@link NMAARBillboardObject} object.
 */
typedef NS_ENUM(NSUInteger, NMAARBillboardObjectOrientation) {
    /**
     * \brief The orientation is fixed, set explicitly using the billboard's
     * normal and up vectors.
     */
    NMAARBillboardObjectOrientationFixed = 0,

    /**
     * \brief The billboard is oriented toward the camera.
     */
    NMAARBillboardObjectOrientationBillboard = 1
};


/**
 * \class NMAARBillboardObject NMAARBillboardObject.h "NMAARBillboardObject.h"
 *
 * \brief 3D LiveSight billboard object that users can add to a {@link NMAARController}.
 *
 * \note There are two type types of billboard objects supported:
 *
 *  - Locally positioned billboard.
 *  - Geo positioned billboard.
 *
 *  In a locally positioned billboard, the object has a fixed relative distance to the camera
 *  In a geo positioned billboard, the object is fixed at the specified geo coordinates.
 */
@interface NMAARBillboardObject : NMAARModelObject

/**
 * Creates a billboard object with a local position and texture.
 *
 * \param localPosition The center of the billboard, represented as a distance vector
 *                 in meters relative to the camera origin.
 * \param texture An optional texture image to display on the billboard.
 *
 */
- (id)initWithLocalPosition:(NMAVector3d)localPosition
                    texture:(NMAImage *)texture;

/**
 * Creates a billboard object with a geo position and texture.
 *
 * \param geoPosition The center of the billboard, represented as geo coordinates.
 * \param texture An optional texture image to display on the billboard.
 *
 */
- (id)initWithGeoCoordinates:(NMAGeoCoordinates *)geoPosition
                     texture:(NMAImage *)texture;

/**
 * The local position of the billboard center relative to the camera, in meters.
 *
 * \note Valid only if the object is initialized with a local position.
 */
@property (nonatomic, readwrite) NMAVector3d localPosition;

/**
 * The geo coordinates of the billboard center.
 *
 * \note Valid only if the object is initialized with a geo position.
 */
@property (nonatomic, readwrite) NMAGeoCoordinates *geoPosition;

/**
 * The orientation mode of the billboard.
 *
 * \note The default value is NMAARBillboardObjectOrientationBillboard.
 *
 * \sa NMAARBillboardObjectOrientation
 */
@property (nonatomic, readwrite) NMAARBillboardObjectOrientation orientation;

/**
 * The surface normal vector of the billboard.
 *
 * The normal vector defines the direction that the billboard is facing.
 *
 * \note Valid only with NMAARBillboardObjectOrientationFixed orientation mode.
 */
@property (nonatomic, readwrite) NMAVector3d surfaceNormal;

/**
 * The up direction vector of the billboard.
 *
 * The up vector defines the direction of the top of the billboard.
 *
 * \note Valid only with NMAARBillboardObjectOrientationFixed orientation mode.
 */
@property (nonatomic, readwrite) NMAVector3d upDirection;

/**
 * The spatial size of the billboard in meters.
 *
 * \note The default value is (1.0, 1.0).
 */
@property (nonatomic, readwrite) CGSize size;

@end

/** @}  */
