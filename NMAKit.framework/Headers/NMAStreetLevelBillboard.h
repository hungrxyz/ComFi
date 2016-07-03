/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAStreetLevelIconBase.h"
#import "NMAVector3d.h"

/**
 * \addtogroup NMA_Streetlevel NMA Street Level Group
 * @{
 */

/**
 * Defines values for billboard orientation type
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMAStreetLevelBillboardOrientation) {
    /** \brief Orientation is fixed, set explicitly using normal and up vectors */
    NMAStreetLevelBillboardOrientationFixed,
    /** \brief The Billboard will pivot to face the camera; its up vector will remain aligned
       with the vertical axis of the street view */
    NMAStreetLevelBillboardOrientationFollowsCameraVerticalFixed,
    /** \brief The Billboard will rotate so that its normal vector is aligned with the look
       vector of the street view */
    NMAStreetLevelBillboardOrientationFollowsCamera
};


/**
 * \class NMAStreetLevelBillboard NMAStreetLevelBillboard.h "NMAStreetLevelBillboard.h"
 *
 * NMAStreetLevelBillboard is a concrete implementation of NMAStreetLevelIconBase used
 * to place billboards in an NMAStreetLevelView. NMAStreetLevelBillboard will scale along
 * with NMAStreetLevelView's zoom level; it can be oriented to any arbitrary direction in the
 * NMAStreetLevelView's 3D space by specfiying its normalVector and upVector properties.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMAStreetLevelBillboard : NMAStreetLevelIconBase

/**
 * A convenience method to construct an NMAStreetLevelBillboard at the specified
 * coordinates and with an NMAImage icon.
 * \param coordinates The NMAGeoCoordinates at which to create the billboard.
 * \param icon The NMAImage to be displayed by the billboard.
 */
+ (id)streetLevelBillboardWithGeoCoordinates:(NMAGeoCoordinates *)coordinates icon:(NMAImage *)icon;

/**
 * A convenience method to construct an NMAStreetLevelBillboard at the specified
 * coordinates and with a UIImage icon.
 * \param coordinates The NMAGeoCoordinates at which to create the billboard.
 * \param image The UIImage to be displayed by the billboard.
 */
+ (id)streetLevelBillboardWithGeoCoordinates:(NMAGeoCoordinates *)coordinates image:(UIImage *)image;

/**
 * The rendered size within an NMAStreetLevelView of the NMAStreetLevelBillboard.
 *
 * \note The size is specified in meters.
 */
@property (nonatomic) CGSize renderedSize;

/**
 * The orientation type of the NMAStreetLevelBillboard.
 */
@property (nonatomic) NMAStreetLevelBillboardOrientation orientation;

/**
 * The normal vector of the NMAStreetLevelBillboard. The normal vector is
 * perpendicular to the image surface of the billboard.
 */
@property (nonatomic) NMAVector3d normalVector;

/**
 * The up vector of the NMAStreetLevelBillboard. The up vector points from
 * the bottom to the top of the billboard image surface.
 */
@property (nonatomic) NMAVector3d upVector;

/**
 * Initializes a %NMAStreetLevelBillboard instance with the specified %NMAGeoCoordinates
 * and %NMAImage for the displayed icon.
 *
 * \param coordinates A %NMAGeoCoordinates representing the map coordinates for displaying
 *               the %NMAStreetLevelBillboard
 * \param icon A %NMAImage representing the icon for the %NMAStreetLevelBillboard
 * \return The %NMAStreetLevelBillboard
 */
- (id)initWithGeoCoordinates:(NMAGeoCoordinates *)coordinates icon:(NMAImage *)icon;

/**
 * Initializes a %NMAStreetLevelBillboard instance with the specified %NMAGeoCoordinates
 * and UImage for the displayed icon.
 *
 * \param coordinates A %NMAGeoCoordinates representing the map coordinates for displaying
 *               the %NMAStreetLevelBillboard
 * \param image A UIImage to use to create the NMAImage of the NMAStreetLevelBillboard.
 * \return The %NMAStreetLevelBillboard
 */
- (id)initWithGeoCoordinates:(NMAGeoCoordinates *)coordinates image:(UIImage *)image;

/**
 * Sets orientation information for the NMAStreetLevelBillboard.
 *
 * \param orientation Orientation type defined in NMAStreetLevelBillboardOrientation
 * \param normalVector Normal vector for orientation of this NMAStreetLevelBillboard
 * \param upVector Up vector for orientation of this NMAStreetLevelBillboard
 */
- (void)setOrientation:(NMAStreetLevelBillboardOrientation)orientation
          normalVector:(NMAVector3d)normalVector
              upVector:(NMAVector3d)upVector;

@end
/**  @}  */
