/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import "NMAProxyObject.h"

@class NMATrafficEvent;

/**
 * \addtogroup NMA_Common  NMA Common Group
 * @{
 */


/**
 * \brief Visually represents a traffic incident with an SDK view such as
 * NMAMapView.
 * <p>
 * Traffic objects are automatically created and displayed by the SDK (if
 * traffic is currently enabled for the view in question). They can be
 * obtained by selecting view objects; for example, by calling objectsAtPoint:
 * in NMAMapView or a tap gesture from the user.
 * </p>
 * <p>
 * Traffic objects are purely a visual representation. The actual information
 * about the traffic incident is accessed via the trafficEvent property.
 *
 * @product nlp-hybrid-plus nlp-plus
 */
@interface NMATrafficObject : NMAProxyObject

/**
 * The NMATrafficEvent represented by this NMATrafficObject.
 */
@property (nonatomic, readonly) NMATrafficEvent *trafficEvent;

@end

/** @}  */
