/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAARModelObject.h"
#import "NMAFloatMesh.h"
#import "NMAVector3d.h"
#import "NMAGeoCoordinates.h"

/**
 * \addtogroup NMA_AR NMA LiveSight Group
 * @{
 */


/**
 * \class NMAARMeshObject NMAARMeshObject.h "NMAARMeshObject.h"
 *
 * \brief A LiveSight 3D mesh object.
 *
 * Three types of mesh object are supported:
 *  - Geo positioned mesh object
 *  - Locally positioned mesh object
 *  - Locally positioned mesh object with additional geo direction
 */
@interface NMAARMeshObject : NMAARModelObject

/**
 * Creates a mesh object with a local position, mesh, and texture.
 *
 * \param localPosition The position of the center of the mesh relative to the camera,
 *                 in meters.
 * \param mesh The object's 3D mesh.
 * \param texture The object's texture.
 */
- (id)initWithLocalPosition:(NMAVector3d)localPosition
                       mesh:(NMAFloatMesh *)mesh
                    texture:(NMAImage *)texture;

/**
 * Creates a mesh object with a geo location, mesh, and texture.
 *
 * \param geoPosition The geo coordinates of the center of the mesh.
 * \param mesh The object's 3D mesh.
 * \param texture The object's texture.
 */
- (id)initWithGeoCoordinates:(NMAGeoCoordinates *)geoPosition
                        mesh:(NMAFloatMesh *)mesh
                     texture:(NMAImage *)texture;

/**
 * Creates a mesh object with a local position, geo direction, mesh, and texture.
 *
 * \param localPosition The position of the center of the mesh relative to the camera,
 *                 in meters.
 * \param geoDirection The geo coordinates toward which the object will be oriented.
 * \param mesh The object's 3D mesh.
 * \param texture The object's texture.
 */
- (id)initWithLocalPosition:(NMAVector3d)localPosition
               geoDirection:(NMAGeoCoordinates *)geoDirection
                       mesh:(NMAFloatMesh *)mesh
                    texture:(NMAImage *)texture;

/**
 * The local position of the object relative to the camera, in meters.
 *
 * \note Valid only if the object is initialized with a local position.
 */
@property (nonatomic, readwrite) NMAVector3d localPosition;

/**
 * The geo coordinates of the object.
 *
 * \note Valid only if the object is initialized with a geo position.
 */
@property (nonatomic, readwrite) NMAGeoCoordinates *geoPosition;

/**
 * The geo direction of the object.
 *
 * When a geo direction is specified, the object will be reoriented to point
 * toward the geo coordinates as the camera moves.
 *
 * \note Valid only if the object is initialized with a local position and
 * direction.
 */
@property (nonatomic, readwrite) NMAGeoCoordinates *geoDirection;

/**
 * The 3D mesh of the object.
 */
@property (nonatomic, readwrite) NMAFloatMesh *mesh;

@end

/** @}  */
