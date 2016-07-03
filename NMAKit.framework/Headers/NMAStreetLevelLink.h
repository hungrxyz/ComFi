/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAProxyObject.h"
#import "NMAStreetLevelOrientation.h"

/**
 * \addtogroup NMA_Streetlevel NMA Street Level Group
 * @{
 */

@class NMAGeoCoordinates;


/**
 * \class NMAStreetLevelLink NMAStreetLevelLink.h "NMAStreetLevelLink.h"
 *
 * \brief An NMAStreetLevelLink instance provides access to an adjacent street level
 * section from with the current section of an NMAStreetLevelView.
 *
 * NMAStreetLevelLink instances are represented visually in an NMAStreetLevelView by arrows.
 * They can be enabled or disabled using the NMAStreetLevelView#navigationArrowVisible property.
 * The visual appearance of the links can be changed with NMAStreetLevelView#setNavigationArrowImage.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMAStreetLevelLink : NMAProxyObject

/**
 * Orientation information for this NMAStreetLevelLink
 */
@property (nonatomic, readonly) NMAStreetLevelOrientation orientation;

/**
 * The geographical location of the linked street level section.
 */
@property (nonatomic, readonly) NMAGeoCoordinates *linkedLocation;

@end
/**  @}  */
