/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>


/**
 * \addtogroup NMA_Search NMA Search Group
 * @{
 * \class NMAPlaceTransitLineStyle NMAPlaceTransitLineStyle.h "NMAPlaceTransitLineStyle.h"
 * \brief Represents the styling guideline information for the public transport
 * line. All colors are in hex format
 */
@interface NMAPlaceTransitLineStyle : NSObject

/**
 * \brief Gets the color value assigned to a line (hex format).
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *color;

/**
 * \brief Gets the text color that should get used when the line color is used
 * as background color (hex format).
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *textColor;

/**
 * \brief Gets the color of the border around the line name (hex format).
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *outlineColor;

/**
 * Gets the shape style identifying the icon for the line (for example, a rectangle).
 *
 * \note Attempts to read this property could return nil.
 */
@property (nonatomic, readonly, strong) NSString *iconShape;

@end
/** @} */
