/*
 * Copyright © 2011-2016 HERE Global B.V. and its affiliate(s).
 * All rights reserved.
 * The use of this software is conditional upon having a separate agreement
 * with a HERE company for the use or utilization of this software. In the
 * absence of such agreement, the use of the software is not allowed.
 */

#import <UIKit/UIColor.h>

#import "NMAMapObject.h"

@class NMAGeoCoordinates;


/*!
 * \addtogroup NMA_Map NMA Mapping Group
 * @{
 * \class NMAMapPolygon NMAMapPolygon.h "NMAMapPolygon.h"
 * Represents a NMAMapObject in the shape of a polygon. In comparison to a
 * NMAMapPolyline, it is assumed that the last coordinates within the path is
 * connected with the first coordinates, thereby constructing an enclosed geometry.</p>
 *
 * \note The NMAViewObject location property for an NMAMapPolygon returns the
 * coordinates of the first vertex (if available).
 */
@interface NMAMapPolygon : NMAMapObject

/*!
 * A convenience method for constructing an NMAMapPolygon.
 *
 * \param vertices An array of NMAGeoCoordinates which define the polygon
 */
+ (id)mapPolygonWithVertices:(NSArray *)vertices;

/**
 * The fill color for the %NMAMapPolygon.
 */
@property (nonatomic, strong)  UIColor *fillColor;

/**
 * The %NSArray of %NMAGeoCoordinates objects comprising the path that
 * defines the %NMAMapPolygon shape.
 */
@property (nonatomic, readonly, weak) NSArray *vertices;

/**
 * The color for the %NMAMapPolygon border line.
 *
 * \note Attempts to set this property to nil are ignored.
 */
@property (nonatomic, strong) UIColor *lineColor;

/**
 * The line width, in pixels, for the %NMAMapPolygon border.
 *
 * The line width must be in the range [0, 100]. The default width is 1 pixel.
 */
@property (nonatomic) NSUInteger lineWidth;

/**
 * Indicates whether to render the %NMAMapPolygon with depth test.
 *
 * \note Rendering with depth test should be used if map object altitude
 * is relevant in your application. Rendering objects with different
 * heights while disabling depth test may cause object occlusion.
 */
@property (nonatomic) BOOL depthTestEnabled;

/*!
 * Initializes a %NMAMapPolygon instance with the specified %NSArray of
 * NMAGeoCoordinates objects.
 *
 * \param vertices A %NSArray of %NMAGeoCoordinates points defining the
 *                    %NMAMapPolygon shape
 * \return The %NMAMapPolygon
 */
- (id)initWithVertices:(NSArray *)vertices;

/*!
 * Removes all vertices from the NMAMapPolygon's path.
 */
- (void)clearVertices;

/*!
 * Insert a %NMAGeoCoordinates point at the specified index of the %NMAMapPolygon path.
 *
 * \param vertex A %NMAGeoCoordinates path point to add.
 * \param index Position to insert. Index starts with 0.
 *
 * \note If index is equal or greater than the total number of vertices, the vertex will be
 * appended to the end of the polygon path.
 */
- (void)addVertex:(NMAGeoCoordinates *)vertex atIndex:(NSUInteger)index;

/*!
 * Append a %NMAGeoCoordinates path point to the end of the %NMAMapPolygon.
 *
 * \param vertex A %NMAGeoCoordinates path point to append
 */
- (void)appendVertex:(NMAGeoCoordinates *)vertex;

/*!
 * Remove the last %NMAGeoCoordinates point of the %NMAMapPolygon
 */
- (void)removeLastVertex;

/*!
 * Remove a %NMAGeoCoordinates point at the specified index of the %NMAMapPolygon path.
 *
 * \param index Position to remove. Index starts with 0 and must be smaller than the total number
 * of vertices.
 */
- (void)removeVertexAtIndex:(NSUInteger)index;

/*!
 * Determines whether the %NMAMapPolygon object is valid. A polygon is valid as long
 * as it does not self-intersect and all vertices have the same altitude.
 *
 * \return YES if the %NMAMapPolygon is valid, NO otherwise
 */
- (BOOL)isValid;

/*!
 * Determines if the %NMAMapPolygon contains the input %NMAGeoCoordinates.
 *  Points at the peaks or corners of the polygon are considered outside the polygon.
 *
 *  @param coordinates %NMAGeoCoordinates to test. The altitude is ignored.
 *
 * \return YES if the %NMAGeoCoordinates is inside the %NMAMapPolygon, NO otherwise
 */
- (BOOL)containsGeoCoordinates:(NMAGeoCoordinates *)coordinates;

@end
/** @}  */
