/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

/**
 * \addtogroup NMA_Route NMA Routing Group
 * @{
 */

#import <Foundation/Foundation.h>


/**
 * \brief Localized signpost information used for navigation (both audible and
 * graphical/textual) and map display.
   (
 * In Europe, the label text is most relevant for guidance, while in the North
 * America, both route name and direction information are most relevant.
 */
@interface NMASignpostLocalizedLabel : NSObject

/**
 *  The three letter MARC code for the label language.
 */
@property (nonatomic, readonly) NSString *language;

/**
 * \brief Auxiliary information for the label.
 *
 * Typically the auxiliary information contains a destination name such as a city or
 * a characteristic place (e.g. "airport").
 */
@property (nonatomic, readonly) NSString *text;

/**
 * \brief The route name/number of the label.
 *
 * Since the origin data is not always consistent it is recommended to concatenate the
 * route name and route direction fields. For example, in some cases the direction is
 * already contained in the route name and in others it is not.
 */
@property (nonatomic, readonly) NSString *routeName;

/**
 *  The cardinal direction for the label.
 */
@property (nonatomic, readonly) NSString *routeDirection;

@end

/** @} */
