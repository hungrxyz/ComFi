/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <Foundation/Foundation.h>

@class NMAMapPolyline;
@class NMALineAttributes;

/**
 * \addtogroup NMA_AR NMA LiveSight Group
 * @{
 */


/**
 * \class NMAARPolylineObject NMAARPolylineObject.h "NMAARPolylineObject.h"
 *
 * \brief Represent a ARPolyline that users can add to a %NMAARController. This class also provide
 * features to customize polyline attributes such as width of line, color and so on.
 *
 */
@interface NMAARPolylineObject : NSObject

/**
 * Create NMAARPolylineObject from NMAMapPolyline.
 *
 * \param mapPolyline NMAMapPolyline rendered by this NMAARPolylineObject.
 *
 */
- (id)initWithPolyline:(NMAMapPolyline *)mapPolyline;

/**
 * Create NMAARPolylineObject with a NMAMapPolyline and a NMALineAttributes.
 *
 * @param mapPolyline NMAMapPolyline rendered by this NMAARPolylineObject.
 *
 * @param lineAttributes attributes (such as width, color, line end cap style) to use when the line is rendered.
 *
 */
- (id)initWithPolyline:(NMAMapPolyline *)mapPolyline
        lineAttributes:(NMALineAttributes *)lineAttributes;

/**
 * The unique ID of the NMAARPolylineObject.
 *
 * \note This value will be consistent for the lifetime of the object.
 */
@property (nonatomic, readonly) NSUInteger uniqueId;

/**
 * NMAMapPolyline rendered by this NMAARPolylineObject.
 */
@property (nonatomic, readwrite) NMAMapPolyline *polyline;

/**
 * NMALineAttributes rendered by this NMAARPolylineObject.
 */
@property (nonatomic, readwrite) NMALineAttributes *lineAttributes;

@end

/** @}  */
