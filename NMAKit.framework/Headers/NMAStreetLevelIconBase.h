/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAStreetLevelObject.h"
#import <UIKit/UIKit.h>

/**
 * \addtogroup NMA_Streetlevel NMA Street Level Group
 * @{
 */

@class NMAStreetLevelBuilding;
@class NMAGeoCoordinates;
@class NMAImage;

/**
 * Specifies the horizontal placement behavior of an NMAStreeLevelIconBase
 * subclass. The behavior influences the latitude and longitude properties of an
 * NMAStreetLevelIconBase object's position.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMAStreetLevelHorizontalPlacement) {
    /** \brief No automatic placement is performed */
    NMAStreetLevelHorizontalPlacementDefault,
    /** \brief Place on attached building centroid. The object will be positioned as if inside the
       building but will still be be visible. This placement can only only be used with
       NMAStreetLevelIcon objects. Specifying this placement for NMAStreetLevelBillboard objects
       will result in the NMAStreetLevelBillboard failing to render */
    NMAStreetLevelHorizontalPlacementCentroid,
    /** \brief Place on closest surface of an attached building */
    NMAStreetLevelHorizontalPlacementClosestSurface,
    /** \brief Place on facade (best surface) of an attached building */
    NMAStreetLevelHorizontalPlacementFacade,
};

/**
 * Specifies the vertical placement behavior of an NMAStreetLevelIconBase
 * subclass. The behavior influences the altitude property of an NMAStreetLevelIconBase
 * object's position.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
typedef NS_ENUM(NSUInteger, NMAStreetLevelVerticalPlacement) {
    /** \brief No automatic placement is performed */
    NMAStreetLevelVerticalPlacementDefault,
    /** \brief Calculate height from terrain. */
    NMAStreetLevelVerticalPlacementTerrain,
    /** \brief Calculate height from a facade */
    NMAStreetLevelVerticalPlacementFacade,
    /** \brief Calculate height from an attached building */
    NMAStreetLevelVerticalPlacementAttachment
};


/**
 * \class NMAStreetLevelIconBase NMAStreetLevelIconBase.h "NMAStreetLevelIconBase.h"
 *
 * NMAStreetLevelIconBase provides a base class for rendering custom icons
 * (NMAImage or UIImage instances) in an NMAStreetLevelView.
 *
 * \note NMAStreetLevelIconBase cannot be directly instantiated. Instead, an appropriate
 * derived class (NMAStreetLevelIcon or NMAStreetLevelBillboard) should be used.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMAStreetLevelIconBase : NMAStreetLevelObject

/**
 * The image displayed by the NMAStreetLevelIconBase.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic) NMAImage *image;

/**
 * The anchor point of the NMAStreetLevelIconBase, used to position the image
 * relative to the icon's geographical location.
 *
 * The anchor point specifies a fractional position inside the displayed image.
 * When the image is rendered inside a street level view, this point will coincide
 * with the geographical location of the NMAStreetLevelIconBase.
 *
 * \note The default value is (0.5, 0.5).
 *
 * \note The anchor point must be in the range ([0,1],[0,1]). Values outside this
 * range will be clamped.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic) CGPoint anchorPoint;

/**
 * The Geo position of the NMAStreetLevelIconBase.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic) NMAGeoCoordinates *position;

/**
 * The NMAStreetLevelBuilding to which the NMAStreetLevelIconBase is attached.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic) NMAStreetLevelBuilding *building;

/**
 * The horizontal placement behavior of the NMAStreetLevelIconBase.
 *
 * This property is set via setHorizontalPlacement:verticalPlacement:verticalPlacementParameter:
 *
 * The default value is NMAStreetLevelHorizontalPlacementDefault.
 *
 * Specifying NMAStreetLevelHorizontalPlacementCentroid for NMAStreetLevelBillboard objects
 * will result in the NMAStreetLevelBillboard failing to render.
 *
 * \sa NMAStreetLevelHorizontalPlacement
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic, readonly) NMAStreetLevelHorizontalPlacement horizontalPlacement;

/**
 * The vertical placement behavior of the NMAStreetLevelIconBase.
 *
 * This property is set via setHorizontalPlacement:verticalPlacement:verticalPlacementParameter:
 *
 * The default value is NMAStreetLevelVerticalPlacementDefault.
 *
 * \sa NMAStreetLevelVerticalPlacement
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic, readonly) NMAStreetLevelVerticalPlacement verticalPlacement;

/**
 * A parameter used to control the vertical placement behavior of the
 * NMAStreetLevelIconBase.
 *
 * The exact meaning of the parameter depends on the values of the horizontalPlacement
 * and verticalPlacement properties as follows:
 *
 * If the verticalPlacement is NMAStreetLevelVerticalPlacementTerrain, this parameter
 * is the desired height of the icon above the terrain, in meters.
 *
 * If the verticalPlacement is NMAStreetLevelVerticalPlacementFacade and the
 * horizontalPlacement is NMAStreetLevelHorizontalPlacementFacade, this parameter is
 * the minimum height above the terrain at which the icon can be placed.
 *
 * If the verticalPlacement is NMAStreetLevelVerticalPlacementFacade and the
 * horizontalPlacement is not NMAStreetLevelHorizontalPlacementFacade, this parameter
 * is the desired height of the icon above the terrain, in meters.
 *
 * If the verticalPlacement is NMAStreetLevelVerticalPlacementAttachment, this
 * parameter is the vertical position of the icon relative to the building it is
 * attached to. A value of 0 will place the icon at the base of the building, and a
 * value of 1 will place the icon at the top of the building. Values may be outside
 * the [0, 1] range.
 *
 * \note Set using the setHorizontalPlacement:verticalPlacement:verticalPlacementParameter:
 * method.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic, readonly) float verticalPlacementParameter;

/**
 * The transparency value of the NMAStreetLevelIconBase. Valid values range
 * from 0 (fully transparent) to 1 (fully opaque).
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@property (nonatomic) float alpha;

/**
 * Sets the horizontal placement behavior, vertical placement behavior, and
 * verticalPlacementParameter of the NMAStreetLevelIconBase.
 *
 * \note See the verticalPlacementParameter property of NMAStreetLevelIconBase for a
 * description of the parameter meanings.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
- (void)setHorizontalPlacement:(NMAStreetLevelHorizontalPlacement)horizontalPlacement
             verticalPlacement:(NMAStreetLevelVerticalPlacement)verticalPlacement
    verticalPlacementParameter:(float)verticalPlacementParameter;

@end
/**  @}  */
